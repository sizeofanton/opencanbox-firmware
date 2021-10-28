#include "can.h"

Can::Can(Can::CAN_INSTANCE instance, BaudRate baud) {
  
  for (int i=26; i<32; i++) bit_clear(systemControl->PCLKSEL0, i);
 
  if (instance == CAN1) {
  bit_set(systemControl->PCONP, 13);
    for (int i=10; i< 14; i++) {
      bit_set(pinCon->PINSEL1, i);
    }
    can = (LPC_CAN_TypeDef *) LPC_CAN1;
    channel = 0u;
  } else {
    bit_set(systemControl->PCONP, 14);
    bit_clear(pinCon->PINSEL4, 17);
    bit_set(pinCon->PINSEL4, 16);
    bit_clear(pinCon->PINSEL4, 15);
    bit_set(pinCon->PINSEL4, 14);
    can = (LPC_CAN_TypeDef *) LPC_CAN2;
    channel = 1u;
  }

  bit_set(can->MOD, 0); 
  can->IER = 0; 
  can->GSR = 0; 
  setBaudRate(baud);
  can->GSR &= 0x0000FFFF;
  canCentral->CANRxSR = 0;
  bit_set(*ISER, ISE_CAN);
  can->RID = 0x0u;
  bit_clear(can->MOD, 0);
}

uint8_t Can::canSend(CanMsg msg) {
  if (canTxBuf1Available()) {
    can->TFI1 = (msg.dlc << 16) | (msg.rtr << 30) | (msg.extendedFrame << 31) & 0xC00F0000;
    can->TID1 = msg.id;
    can->TDA1 = msg.data[0] | msg.data[1] << 8 | msg.data[2] << 16 | msg.data[3] << 24;
    can->TDB1 = msg.data[4] | msg.data[5] << 8 | msg.data[6] << 16 | msg.data[7] << 24;
    can->CMR  = 0x21;
  } else if (canTxBuf2Available()) {
    can->TFI2 = (msg.dlc << 16) | (msg.rtr << 30) | (msg.extendedFrame << 31) & 0xC00F0000;
    can->TID2 = msg.id;
    can->TDA2 = msg.data[0] | msg.data[1] << 8 | msg.data[2] << 16 | msg.data[3] << 24;
    can->TDB2 = msg.data[4] | msg.data[5] << 8 | msg.data[6] << 16 | msg.data[7] << 24;
    can->CMR  = 0x41;
  } else if (canTxBuf3Available()) {
    can->TFI3 = (msg.dlc << 16) | (msg.rtr << 30) | (msg.extendedFrame << 31) & 0xC00F0000;
    can->TID3 = msg.id;
    can->TDA3 = msg.data[0] | msg.data[1] << 8 | msg.data[2] << 16 | msg.data[3] << 24;
    can->TDB3 = msg.data[4] | msg.data[5] << 8 | msg.data[6] << 16 | msg.data[7] << 24;
    can->CMR  = 0x81;
  } else return -1;
  return 0;
}

CanMsg Can::canRead() {
    CanMsg msg;
    msg.dlc = (can->RFS >> 16) & 0xF;
    msg.rtr = (can->RFS >> 30) & 0x01;
    msg.extendedFrame = (can->RFS >> 31) & 0x01;
    msg.id = msg.extendedFrame == 1 ? (can->RID) & 0x1FFFFFFF : (can->RID) & 0x7FF;
    uint8_t data[8];
    data[0] = (uint8_t) can->RDA;
    data[1] = (uint8_t) (can->RDA >> 8);
    data[2] = (uint8_t) (can->RDA >> 16);
    data[3] = (uint8_t) (can->RDA >> 24);
    data[4] = (uint8_t) can->RDB;
    data[5] = (uint8_t) (can->RDB >> 8);
    data[6] = (uint8_t) (can->RDB >> 16);
    data[7] = (uint8_t) (can->RDB >> 24);
    for (int i=0; i<msg.dlc; i++) msg.data[i] = data[i];
    releaseRxBuffer();
    return msg;
}

inline void Can::releaseRxBuffer() {
  can->CMR = 0x4; 
}

bool Can::canMsgAvailable() {
  return can->GSR & 0x1 ? true : false;
}

inline bool Can::canTxBuf1Available() {
  return can->SR & 0x00000004 ? true : false;
}

inline bool Can::canTxBuf2Available() {
  return can->SR & 0x00000400 ? true : false;
}

inline bool Can::canTxBuf3Available() {
  return can->SR & 0x00040000 ? true : false;
}

void Can::setBaudRate(BaudRate br) {
  switch (br) {
    case _5kbit: can->BTR = BITRATE_5_BTR; break;
    case _10kbit: can->BTR = BITRATE_10_BTR; break;
    case _20kbit: can->BTR = BITRATE_20_BTR; break;
    case _50kbit: can->BTR = BITRATE_50_BTR; break;
    case _100kbit: can->BTR = BITRATE_100_BTR; break;
    case _125kbit: can->BTR = BITRATE_125_BTR; break;
    case _250kbit: can->BTR = BITRATE_250_BTR; break;
    case _500kbit: can->BTR = BITRATE_500_BTR; break;
    case _1000kbit: can->BTR = BITRATE_1000_BTR; break;
    default: break;
  }
}

void Can::changeBaudRate(BaudRate baudRate) {
  bit_set(can->MOD, 0);
  bit_clear(*ISER, ISE_CAN);
  setBaudRate(baudRate);
  bit_clear(can->MOD, 0);
  bit_set(*ISER, ISE_CAN);
}

void Can::setAcceptanceMode(CAN_ACCEPTANCE_MODE mode) {
  switch (mode) {
    case OFF_MODE:
      bit_set(canAcf->AFMR, AFMR_OFF_MODE);
      bit_clear(canAcf->AFMR, AFMR_BYMASS_MODE);
      break;
    case BYPASS_MODE:
      bit_set(canAcf->AFMR, AFMR_BYMASS_MODE);
      bit_clear(canAcf->AFMR, AFMR_OFF_MODE);
      break;
    case OPERATING_MODE:
      bit_clear(canAcf->AFMR, AFMR_BYMASS_MODE);
      bit_clear(canAcf->AFMR, AFMR_OFF_MODE);
      break;
    default: break;
  }
}

void Can::setEnabledInterrupts(CAN_INT enInt) {
  uint32_t ierValue = 0u;
  if (enInt.ReceiveInterrupt) bit_set(ierValue, RX_INTERRUPT_BIT);
  if (enInt.Transmit1Interrupt) bit_set(ierValue, TX_INTERRUPT_BIT);
  if (enInt.ErrorWarningInterrupt) bit_set(ierValue, ERROR_WARNING_INTERRUPT_BIT);
  if (enInt.DataOverrunInterrupt) bit_set(ierValue, DATA_OVERRUN_INTERRUPT_BIT);
  if (enInt.WakeupInterrupt) bit_set(ierValue, WAKEUP_INTERRUPT_BIT);
  if (enInt.ErrorPassiveInterrupt) bit_set(ierValue, ERROR_PASSIVE_INTERRUPT_BIT);
  if (enInt.ArbitrationLostInterrupt) bit_set(ierValue, ARBITRATION_LOST_INTERRUPT_BIT);
  if (enInt.BusErrorInterrupt) bit_set(ierValue, BUS_ERROR_INTERRUPT_BIT);
  if (enInt.IdReadyInterrupt) bit_set(ierValue, ID_READY_INTERRUPT_BIT);
  if (enInt.Transmit2Interrupt) bit_set(ierValue, TX2_INTERRUPT_BIT);
  if (enInt.Transmit3Interrupt) bit_set(ierValue, TX3_INTERRUPT_BIT);
  can->IER = ierValue;
}

Can::CAN_INT Can::getInterruptSource() {
  CAN_INT interruptSources = (CAN_INT){0};
  if (is_bit_set(can->ICR, 0)) interruptSources.ReceiveInterrupt = 1u;
  if (is_bit_set(can->ICR, 1)) interruptSources.Transmit1Interrupt = 1u;
  if (is_bit_set(can->ICR, 2)) interruptSources.ErrorWarningInterrupt = 1u;
  if (is_bit_set(can->ICR, 3)) interruptSources.DataOverrunInterrupt = 1u;
  if (is_bit_set(can->ICR, 4)) interruptSources.WakeupInterrupt = 1u;
  if (is_bit_set(can->ICR, 5)) interruptSources.ErrorPassiveInterrupt = 1u;
  if (is_bit_set(can->ICR, 6)) interruptSources.ArbitrationLostInterrupt = 1u;
  if (is_bit_set(can->ICR, 7)) interruptSources.BusErrorInterrupt = 1u;
  if (is_bit_set(can->ICR, 8)) interruptSources.IdReadyInterrupt = 1u;
  if (is_bit_set(can->ICR, 9)) interruptSources.Transmit2Interrupt = 1u;
  if (is_bit_set(can->ICR, 10)) interruptSources.Transmit3Interrupt = 1u;
  return interruptSources;
}


void Can::setFilterSf(uint32_t *idBuffer, uint32_t len) {
  uint32_t address = 0;
  uint32_t idHigh, idLow;
  uint32_t i = 0;
  canAcf->SFF_sa = address;
  while (i < len) {
    if (i % 2 == 0) {
      idLow = (channel << 29) | (*(idBuffer++) << 16);
    } else {
      idHigh = (channel << 13) | (*(idBuffer++));
      *((volatile uint32_t *)(LPC_CANAF_RAM_BASE + address)) = idLow | idHigh;
      address+=4;
    }
    i++;
  }
  canAcf->SFF_GRP_sa = address;
  address+=4;
  canAcf->EFF_sa = address;
  address+=4;
  canAcf->EFF_GRP_sa = address;
  address+=4;
  canAcf->ENDofTable = address;
}


void Can::setFilterRangeSf(uint32_t idStart, uint32_t idStop) {
  uint32_t address = 0;
  canAcf->SFF_sa = address;
  canAcf->SFF_GRP_sa = address;
  address += 4;
  canAcf->EFF_sa = address;
  *((volatile uint32_t *)(LPC_CANAF_RAM_BASE + address)) = (channel << 29) | (idStart << 16) | (channel << 12) | (idStop);
  canAcf->EFF_GRP_sa = address;
  canAcf->ENDofTable = address;
}