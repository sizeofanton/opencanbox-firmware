#include "main.h"

int main(void) {

  systemTickTimer.setReloadValue(Config::SYSTICK_TIMER_RELOAD_VALUE);
  systemTickTimer.start();
  
  ledCan1Err.turnOff();
  ledCan2Err.turnOff();
  ledCan1.turnOff();
  ledCan2.turnOff();

  ledGc.turnOn();

  while (!hardwareActivated) {
    if (uart.byteAvailable()) {
      auto byte = uart.uartRx();
      if (byte == UartProtocol::ACTIVATION_SYMBOL) codeCounter++;
      if (codeCounter >= UartProtocol::ACTIVATION_SYMBOL_NEEDED) hardwareActivated = true;
    }
  }
  
  #ifndef DEBUG
  watchdogTimer.start(Config::WATCHDOG_RELOAD_VALUE);
  #endif
  initCanInterfaces();
  while (true) {
    #ifndef DEBUG
    watchdogTimer.feed();
    #endif
    setErrorLeds();
    uartRoutine();
    auto errCan1 = can1TxTable.proceedMessages(systemTickTimer.globalTicks, &can1);
    if (errCan1 == TxTable::Success) ledCan1.toggle();
    auto errCan2 = can2TxTable.proceedMessages(systemTickTimer.globalTicks, &can2);
    if (errCan2 == TxTable::Success) ledCan2.toggle();
  }
}

void initCanInterfaces() {
  can1.setAcceptanceMode(Can::CanAcceptanceMode::BypassMode);
  can2.setAcceptanceMode(Can::CanAcceptanceMode::BypassMode);

  Can::CanInterrupt inEnStruct = (Can::CanInterrupt) {0};
  inEnStruct.ReceiveInterrupt = 1u;
  inEnStruct.ErrorWarningInterrupt = 1u;
  inEnStruct.DataOverrunInterrupt = 1u;
  inEnStruct.ErrorPassiveInterrupt = 1u;
  inEnStruct.ArbitrationLostInterrupt = 1u;
  inEnStruct.BusErrorInterrupt = 1u;
  can1.setEnabledInterrupts(inEnStruct);
  can2.setEnabledInterrupts(inEnStruct);
}

void setErrorLeds() {
  if (!errorWarningCan1 && !errorCan1) ledCan1Err.turnOff();
  else if (errorWarningCan1 && !errorCan1) ledCan1Err.toggle();
  else if (errorCan1) ledCan1Err.turnOn();

  if (!errorWarningCan2 && !errorCan2) ledCan2Err.turnOff();
  else if (errorWarningCan2 && !errorCan2) ledCan2Err.toggle();
  else if (errorCan2) ledCan2Err.turnOn();
}

inline void _delay_ms(unsigned int ms) {
  for (int i=0; i<ms; i++) 
    for (int j=0; j<10000; j++)
      __asm__ volatile ("mov r0, r0");
}

extern "C" void SysTick_Handler() {
  if (systemTickTimer.isRunning()) systemTickTimer.globalTicks++;
  if ( (systemTickTimer.globalTicks % 100 == 0) && hardwareActivated) ledGc.toggle();
  if (systemTickTimer.globalTicks % 500 == 0) ledCan1.turnOff();
  if (systemTickTimer.globalTicks % 500 == 0) ledCan2.turnOff();
}

extern "C" void UART0_IRQHandler() {
  uartRxBuffer.put(uart.uartRx());
}

extern "C" void CAN_IRQHandler() {
  auto can1Interrupts = can1.getInterruptSource();
  auto can2Interrupts = can2.getInterruptSource();

  if (can1Interrupts.ReceiveInterrupt) { canReceiveMsg(Can::Can1); } 
  else if (can1Interrupts.Transmit1Interrupt) {}
  else if (can1Interrupts.ErrorWarningInterrupt) {}
  else if (can1Interrupts.DataOverrunInterrupt) { canDataOverrun(Can::Can1); }
  else if (can1Interrupts.WakeupInterrupt) {}
  else if (can1Interrupts.ErrorPassiveInterrupt) { canErrorPassive(Can::Can1); }
  else if (can1Interrupts.ArbitrationLostInterrupt) { canArbitrationLost(Can::Can1); }
  else if (can1Interrupts.BusErrorInterrupt) { canBusError(Can::Can1); }
  else if (can1Interrupts.IdReadyInterrupt) {}
  else if (can1Interrupts.Transmit2Interrupt) {}
  else if (can1Interrupts.Transmit3Interrupt) {}

  if (can2Interrupts.ReceiveInterrupt) { canReceiveMsg(Can::Can2); } 
  else if (can2Interrupts.Transmit1Interrupt) {}
  else if (can2Interrupts.ErrorWarningInterrupt) {}
  else if (can2Interrupts.DataOverrunInterrupt) { canDataOverrun(Can::Can2); }
  else if (can2Interrupts.WakeupInterrupt) {}
  else if (can2Interrupts.ErrorPassiveInterrupt) { canErrorPassive(Can::Can2); }
  else if (can2Interrupts.ArbitrationLostInterrupt) { canArbitrationLost(Can::Can2); }
  else if (can2Interrupts.BusErrorInterrupt) { canBusError(Can::Can2); }
  else if (can2Interrupts.IdReadyInterrupt) {}
  else if (can2Interrupts.Transmit2Interrupt) {}
  else if (can2Interrupts.Transmit3Interrupt) {}
}

// TODO REFACTOR - TOO BIG FUNCTION
void canReceiveMsg(Can::CanInstance instance) {

  auto receivedMsg = instance == Can::Can1 ? can1.canRead() : can2.canRead();
  if (instance == Can::Can1) ledCan1.toggle();
  if (instance == Can::Can2) ledCan2.toggle();
  auto channel = instance == Can::Can1 ? UartProtocol::CAN_CHANNEL1 : UartProtocol::CAN_CHANNEL2;
  uint32_t period = 0;
  
  if (channel == UartProtocol::CAN_CHANNEL1) {
    auto ret = can1RxTable.getPeriod(receivedMsg.id, &period);
    if (ret == RxTable::NoSuchId) {
      if (can1RxTable.add(receivedMsg.id, systemTickTimer.globalTicks) == RxTable::NoSpace) {
        uint8_t *dataPointer = nullptr;
        auto size = uartProtocol.msgRxTableFull(channel, dataPointer);
        for (int i = 0; i < size; i++) uartTxBuffer.put(dataPointer[i]);
      }
      period = 0;
    } else {
      can1RxTable.getPeriod(receivedMsg.id, &period);
      can1RxTable.add(receivedMsg.id, systemTickTimer.globalTicks);
    }
  } else if (channel == UartProtocol::CAN_CHANNEL2) {
    auto ret = can2RxTable.getPeriod(receivedMsg.id, &period);
    if (ret == RxTable::NoSuchId) {
      if (can2RxTable.add(receivedMsg.id, systemTickTimer.globalTicks) == RxTable::NoSpace) {
        uint8_t *dataPointer = nullptr;
        auto size = uartProtocol.msgRxTableFull(channel, dataPointer);
        for (int i = 0; i < size; i++) uartTxBuffer.put(dataPointer[i]);
      }
      period = 0;
    } else {
      can2RxTable.getPeriod(receivedMsg.id, &period);
      can2RxTable.add(receivedMsg.id, systemTickTimer.globalTicks);
    }
  }

  uint8_t *dataPointer = nullptr;
  if (period != 0) period = period / 1000;
  auto size = uartProtocol.msgRxCan(channel, receivedMsg, period, dataPointer);
  for (int i=0; i<size; i++) uartTxBuffer.put(dataPointer[i]);

}


void canDataOverrun(Can::CanInstance instance) {
  instance == Can::Can1 ? errorWarningCan1 = true : errorWarningCan2 = true;
  uint8_t *dataPointer = nullptr;
  auto channel = instance == Can::Can1 ? UartProtocol::CAN_CHANNEL1 : UartProtocol::CAN_CHANNEL2;
  auto size = uartProtocol.msgDataOverrunWarning(channel, dataPointer);
  for (int i=0; i<size; i++) uartTxBuffer.put(dataPointer[i]);
}

void canErrorPassive(Can::CanInstance instance) {
  instance == Can::Can1 ? errorCan1 = true : errorCan2 = true;
  uint8_t *dataPointer = nullptr;
  auto channel = instance == Can::Can1 ? UartProtocol::CAN_CHANNEL1 : UartProtocol::CAN_CHANNEL2;
  auto size = uartProtocol.msgPassiveError(channel, dataPointer);
  for (int i = 0; i < size; i++) uartTxBuffer.put(dataPointer[i]);
}

void canArbitrationLost(Can::CanInstance instance) {
  instance == Can::Can1 ? errorCan1 = true : errorCan2 = true;
  uint8_t *dataPointer = nullptr;
  auto channel = instance == Can::Can1 ? UartProtocol::CAN_CHANNEL1 : UartProtocol::CAN_CHANNEL2;
  auto size = uartProtocol.msgArbitrationLost(channel, dataPointer);
  for (int i = 0; i < size; i++) uartTxBuffer.put(dataPointer[i]);
}

void canBusError(Can::CanInstance instance) {
  instance == Can::Can1 ? errorCan1 = true : errorCan2 = true;
  uint8_t *dataPointer = nullptr;
  auto channel = instance == Can::Can1 ? UartProtocol::CAN_CHANNEL1 : UartProtocol::CAN_CHANNEL2;
  auto size = uartProtocol.msgBusError(channel, dataPointer);
  for (int i = 0; i < size; i++) uartTxBuffer.put(dataPointer[i]);
}

void uartRoutine() {
  uint32_t availableRx = uartRxBuffer.getAvailableSize();
  for (uint32_t i=0; i<availableRx; i++) uartProtocol.uartRoutine(uartRxBuffer.get());
  uint32_t availableTx = uartTxBuffer.getAvailableSize();
  for (uint32_t i=0; i<availableTx; i++) uart.uartTx(uartTxBuffer.get());
}

void systemReset() {
  NVIC_SystemReset();
}

extern "C" void UartProtocolCallback_InfoRequest() {
  uint8_t *dataPointer = nullptr;
  auto size = uartProtocol.msgDeviceInfo(config.HARDWARE_CODE, config.VERSION_CODE, config.CHANNELS_NUMBER, dataPointer);
  for (int i=0; i<size; i++) uartTxBuffer.put(dataPointer[i]);
}

extern "C" void UartProtocolCallback_DeviceDeactivation() {
  systemReset();
}

extern "C" void UartProtocolCallback_SingleMessage(CanMsg msg, uint8_t channelId) {
  uint8_t ret = -1;
  if (channelId == UartProtocol::CAN_CHANNEL1) {
    ret = can1.canSend(msg);
    if (ret == 0) ledCan1.toggle();
  } else if (channelId == UartProtocol::CAN_CHANNEL2) {
    ret = can2.canSend(msg);
    if (ret == 0) ledCan2.toggle();
  }
}

extern "C" void UartProtocolCallback_PereodicMessage(CanMsg msg, uint8_t channelId, uint16_t period) {
  if (channelId == UartProtocol::CAN_CHANNEL1) {
    auto ret = can1TxTable.add(msg, period);
    if (ret == TxTable::NoSpace) {
      uint8_t *dataPointer = nullptr;
      auto size = uartProtocol.msgTxTableFull(UartProtocol::CAN_CHANNEL1, dataPointer);
      for (int i = 0; i < size; i++) uartTxBuffer.put(dataPointer[i]);
    }
  } else if (channelId == UartProtocol::CAN_CHANNEL2) {
    auto ret = can2TxTable.add(msg, period);
    if (ret == TxTable::NoSpace) {
      uint8_t *dataPointer = nullptr;
      auto size = uartProtocol.msgTxTableFull(UartProtocol::CAN_CHANNEL2, dataPointer);
      for (int i = 0; i < size; i++) uartTxBuffer.put(dataPointer[i]);
    }
  }
}

extern "C" void UartProtocolCallback_PereodicMessageDelete(uint16_t id, uint8_t channelId) {
  if (channelId == UartProtocol::CAN_CHANNEL1) {
    can1TxTable.remove(id);
  } else if (channelId == UartProtocol::CAN_CHANNEL2) {
    can2TxTable.remove(id);
  }
}

extern "C" void UartProtocolCallback_PereodicMessageEdit(CanMsg msg, uint8_t channelId, uint16_t period) {
  if (channelId == UartProtocol::CAN_CHANNEL1) {
    can1TxTable.edit(msg.id, &msg, period);
  } else if (channelId == UartProtocol::CAN_CHANNEL2) {
    can2TxTable.edit(msg.id, &msg, period);
  }
}

extern "C" void UartProtocolCallback_SetChannelBitrate(uint8_t channelId, uint8_t bitRate) {
  if (channelId == UartProtocol::CAN_CHANNEL1) {
    can1.changeBaudRate((BaudRate) bitRate);
  } else if (channelId == UartProtocol::CAN_CHANNEL2) {
    can2.changeBaudRate((BaudRate) bitRate);
  }
}

extern "C" void UartProtocolCallback_SetChannelFilter(uint8_t channelId, uint32_t idLow, uint32_t idHigh) {
  if (channelId == UartProtocol::CAN_CHANNEL1) {
    can1.setFilterRangeSf(idLow, idHigh);
    can1.setAcceptanceMode(Can::CanAcceptanceMode::OperatingMode);
  } else if (channelId == UartProtocol::CAN_CHANNEL2) {
    can2.setFilterRangeSf(idLow, idHigh);
    can2.setAcceptanceMode(Can::CanAcceptanceMode::OperatingMode);
  }
}
