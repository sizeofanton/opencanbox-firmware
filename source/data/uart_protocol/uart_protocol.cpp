#include "uart_protocol.h"

uint32_t UartProtocol::msgRxCan(uint8_t channel, CanMsg msg, uint32_t period,  uint8_t *&res) {
  uint8_t buffer[23];
  uint8_t size = 0;
  
  buffer[size++] = HEADER_BYTES[0];
  buffer[size++] = HEADER_BYTES[1];
  buffer[size++] = HEADER_BYTES[2];
  buffer[size++] = HEADER_BYTES[3];

  buffer[size++] = OutputMsgType::RxCan;
  buffer[size++] = channel;
  buffer[size++] = (msg.id >> 8);
  buffer[size++] = msg.id;
  buffer[size++] = msg.dlc | ((uint8_t) msg.rtr << 4) | ((uint8_t) msg.extendedFrame << 5);
  for (int i=0; i<8; i++) {
    buffer[size++] = msg.data[i]; 
  }

  buffer[size++] = period >> 8;
  buffer[size++] = period; 

  uint8_t crc = crc8.calculate(0, &buffer[0], size);
  buffer[size++] = crc;
  

  res = (uint8_t *) buffer;
  return size;
}

uint32_t UartProtocol::msgDeviceInfo(uint8_t hardwareVersion, uint16_t firmwareVersion, uint8_t channelNumbers, uint8_t *&res) {
  uint8_t buffer[10];
  uint8_t size = 0;

  buffer[size++] = HEADER_BYTES[0];
  buffer[size++] = HEADER_BYTES[1];
  buffer[size++] = HEADER_BYTES[2];
  buffer[size++] = HEADER_BYTES[3];

  buffer[size++] = OutputMsgType::DeviceInfo;
  
  buffer[size++] = hardwareVersion;
  buffer[size++] = firmwareVersion >> 8;
  buffer[size++] = firmwareVersion;
  buffer[size++] = channelNumbers;

  buffer[size++] = crc8.calculate(0, &buffer[0], size);
  
  res = (uint8_t *) buffer;
  return size;
}

uint32_t UartProtocol::msgDataOverrunWarning(uint8_t channel, uint8_t *&res) {
  uint8_t buffer[10];
  uint8_t size = 0;

  buffer[size++] = HEADER_BYTES[0];
  buffer[size++] = HEADER_BYTES[1];
  buffer[size++] = HEADER_BYTES[2];
  buffer[size++] = HEADER_BYTES[3];

  buffer[size++] = OutputMsgType::WarningDataOverrun;
  buffer[size++] = channel;

  uint8_t crc = crc8.calculate(0, &buffer[0], size);
  buffer[size++] = crc;

  res = (uint8_t *) buffer;
  return size;

}

uint32_t UartProtocol::msgPassiveError(uint8_t channel, uint8_t *&res) {
  uint8_t buffer[7];
  uint8_t size = 0;

  buffer[size++] = HEADER_BYTES[0];
  buffer[size++] = HEADER_BYTES[1];
  buffer[size++] = HEADER_BYTES[2];
  buffer[size++] = HEADER_BYTES[3];

  buffer[size++] = OutputMsgType::ErrorPassive;
  buffer[size++] = channel;

  uint8_t crc = crc8.calculate(0, &buffer[0], size);
  buffer[size++] = crc;

  res = (uint8_t *) buffer;
  return size;
}

uint32_t UartProtocol::msgArbitrationLost(uint8_t channel, uint8_t *&res) {
  uint8_t buffer[7];
  uint8_t size = 0;

  buffer[size++] = HEADER_BYTES[0];
  buffer[size++] = HEADER_BYTES[1];
  buffer[size++] = HEADER_BYTES[2];
  buffer[size++] = HEADER_BYTES[3];

  buffer[size++] = OutputMsgType::ArbitrationLost;
  buffer[size++] = channel;

  uint8_t crc = crc8.calculate(0, &buffer[0], size);
  buffer[size++] = crc;

  res = (uint8_t *) buffer;
  return size;
}

uint32_t UartProtocol::msgBusError(uint8_t channel, uint8_t *&res) {
  uint8_t buffer[7];
  uint8_t size = 0;

  buffer[size++] = HEADER_BYTES[0];
  buffer[size++] = HEADER_BYTES[1];
  buffer[size++] = HEADER_BYTES[2];
  buffer[size++] = HEADER_BYTES[3];

  buffer[size++] = OutputMsgType::BusError;
  buffer[size++] = channel;

  uint8_t crc = crc8.calculate(0, &buffer[0], size);
  buffer[size++] = crc;

  res = (uint8_t *) buffer;
  return size;

}

uint32_t UartProtocol::msgTxTableFull(uint8_t channel, uint8_t *&res) {
  uint8_t buffer[7];
  uint8_t size = 0;

  buffer[size++] = HEADER_BYTES[0];
  buffer[size++] = HEADER_BYTES[1];
  buffer[size++] = HEADER_BYTES[2];
  buffer[size++] = HEADER_BYTES[3];

  buffer[size++] = OutputMsgType::TxTableFull;
  buffer[size++] = channel;

  uint8_t crc = crc8.calculate(0, &buffer[0], size);
  buffer[size++] = crc;

  res = (uint8_t *) buffer;
  return size;
}

uint32_t UartProtocol::msgRxTableFull(uint8_t channel, uint8_t *&res) {
  uint8_t buffer[7];
  uint8_t size = 0;

  buffer[size++] = HEADER_BYTES[0];
  buffer[size++] = HEADER_BYTES[1];
  buffer[size++] = HEADER_BYTES[2];
  buffer[size++] = HEADER_BYTES[3];

  buffer[size++] = OutputMsgType::RxTableFull;
  buffer[size++] = channel;

  uint8_t crc = crc8.calculate(0, &buffer[0], size);
  buffer[size++] = crc;

  res = (uint8_t *) buffer;
  return size;
}

bool UartProtocol::validateHeader(uint8_t *header) {
   if ((header[0] == INPUT_HEADER_BYTES[0]) && 
        (header[1] == INPUT_HEADER_BYTES[1]) && 
        (header[2] == INPUT_HEADER_BYTES[2]) && 
        (header[3] == INPUT_HEADER_BYTES[3])) return  true;
   else return false;
}

uint8_t UartProtocol::validateMsgType(uint8_t msgType, uint32_t *payloadSize) {
  switch (msgType) {
    case InputMsgType::InfoRequest: {
      *payloadSize = INFO_REQUEST_PAYLOAD;
      return (uint8_t) InputMsgType::InfoRequest; break;
    }
    case InputMsgType::DeviceDeactivation: {
      *payloadSize = DEVICE_DEACTIVATION_PAYLOAD;
      return (uint8_t) InputMsgType::DeviceDeactivation; break;
    }
    case InputMsgType::SingleMessage: {
      *payloadSize = SINGLE_MESSAGE_PAYLOAD;
      return (uint8_t) InputMsgType::DeviceDeactivation; break;
    }
    case InputMsgType::PereodicMessage: {
      *payloadSize = PEREODIC_MESSAGE_PAYLOAD;
      return (uint8_t) InputMsgType::PereodicMessage; break;
    }
    case InputMsgType::PereodicMessageDelete: {
      *payloadSize = PEREODIC_MESSAGE_DELETE_PAYLOAD;
      return (uint8_t) InputMsgType::PereodicMessageDelete; break;
    }
    case InputMsgType::PereodicMessageEdit: {
      *payloadSize = PEREODIC_MESSAGE_EDIT_PAYLOAD; 
      return (uint8_t) InputMsgType::PereodicMessageEdit; break;
    }
    case InputMsgType::SetChannelBitrate: {
      *payloadSize = SET_CHANNEL_BITRATE_PAYLOAD;
      return (uint8_t) InputMsgType::SetChannelBitrate; break;
    }
    case InputMsgType::SetChannelFilter: {
      *payloadSize = SET_CHANNEL_FILTER_PAYLOAD; 
      return (uint8_t) InputMsgType::SetChannelFilter; break;
    }
    default: {
      *payloadSize = 0;
      return 0; break;
    }
  }
}

void UartProtocol::uartRoutine(uint8_t rxByte) {
  lastByte = rxByte;
  if (!headerSynced) {
    syncOnHeader();
    return;
  } 
  if (!msgTypeSynced) {
    syncOnMsgType();
    return;
  }
  readPayload();
}

void UartProtocol::syncOnHeader() {
  header[headerReadPos] = lastByte;
  auto headerOk = validateHeader(header);
  if (!headerOk) {
    header[0] = header[1];
    header[1] = header[2];
    header[2] = header[3];
  } else {
    headerSynced = true;
    payloadBuffer[payloadPointer++] = header[0];
    payloadBuffer[payloadPointer++] = header[1];
    payloadBuffer[payloadPointer++] = header[2];
    payloadBuffer[payloadPointer++] = header[3];
    msgSize += 4;
  }
}

void UartProtocol::syncOnMsgType() {
  msgType = lastByte;
  uint32_t p;
  auto typeOk = validateMsgType(msgType, &p);
  if (typeOk != 0) {
    msgSize += 1;
    payloadSize = p;
    msgTypeSynced = true;
    payloadBuffer[payloadPointer++] = msgType;
  } else {
    msgTypeSynced = false;
    headerSynced = false;
  }
}

void UartProtocol::readPayload() {
  if (payloadSize > 0) {
    payloadBuffer[payloadPointer++] = lastByte;
    payloadSize--;
    if (payloadSize == 0) {
      payloadPointer = 0;
      msgTypeSynced = false;
      headerSynced = false;
      for (int i=0; i<4; i++) header[i] = 0x00;
      parseMessage();
    }
  }
}

void UartProtocol::parseMessage() {
  switch(msgType) {

    case InputMsgType::InfoRequest: {
      handleInfoRequest();
      break;
    }

    case InputMsgType::DeviceDeactivation: {
      handleDeviceDeactivation();
      break;
    }

    case InputMsgType::SingleMessage: {
      handleSingleMessage();
      break;
    }

    case InputMsgType::PereodicMessage: {
      handlePereodicMessage();
      break;
    }

    case InputMsgType::PereodicMessageDelete: {
      handlePereodicMessageDelete();
      break;
    }

    case InputMsgType::PereodicMessageEdit: {
      handlePereodicMessageEdit();
      break;
    }

    case InputMsgType::SetChannelBitrate: {
      handleSetChannelBitrate();
      break;
    }

    case InputMsgType::SetChannelFilter: {
      handleSetChannelFilter();
      break;
    }

    default: break;
  }
}

void UartProtocol::handleInfoRequest() {
  UartProtocolCallback_InfoRequest();
}

void UartProtocol::handleDeviceDeactivation() {
  int deactivationSymbols = 0;
  for (int i=5; i<15; i++) { 
    if (payloadBuffer[i] == 0x33) deactivationSymbols++;
  }
  if (deactivationSymbols == 10) UartProtocolCallback_DeviceDeactivation();
}

void UartProtocol::handleSingleMessage() {
  auto crc = crc8.calculate(0u, payloadBuffer, SINGLE_MESSAGE_PAYLOAD+4);
  if (crc != payloadBuffer[19]) return;
  CanMsg msg;
  msg.id = (payloadBuffer[5] << 24) | (payloadBuffer[6] << 16) | (payloadBuffer[7] << 8) | payloadBuffer[8];
  msg.dlc = (payloadBuffer[9] & 0x0F);
  msg.rtr = (payloadBuffer[9] >> 4) & 0x01;
  msg.extendedFrame = (payloadBuffer[9] >> 5) & 0x01;
  for (int i=0; i<8; i++) msg.data[i] = payloadBuffer[i+10];
  uint8_t channel = payloadBuffer[18];
  UartProtocolCallback_SingleMessage(msg, channel);
}

void UartProtocol::handlePereodicMessage() {
  auto crc = crc8.calculate(0u, payloadBuffer, PEREODIC_MESSAGE_PAYLOAD+4);
  if (crc != payloadBuffer[21]) return;
  CanMsg msg;
  msg.id = (payloadBuffer[5] << 24) | (payloadBuffer[6] << 16) | (payloadBuffer[7] << 8) | payloadBuffer[8];
  msg.dlc = (payloadBuffer[9] & 0x0F);
  msg.rtr = (payloadBuffer[9] >> 4) & 0x01;
  msg.extendedFrame = (payloadBuffer[9] >> 5) & 0x01;
  for (int i=0; i<8; i++) msg.data[i] = payloadBuffer[i+10];
  uint8_t channel = payloadBuffer[18];
  uint16_t period = (payloadBuffer[19] << 8) | payloadBuffer[20];
  UartProtocolCallback_PereodicMessage(msg, channel, period);
}


void UartProtocol::handlePereodicMessageDelete() {
  auto crc = crc8.calculate(0u, payloadBuffer, PEREODIC_MESSAGE_DELETE_PAYLOAD+4);
  if (crc != payloadBuffer[10]) return;
  uint16_t id = (payloadBuffer[5] << 24) | (payloadBuffer[6] << 16) | (payloadBuffer[7] << 8) | payloadBuffer[8];
  uint8_t channel = payloadBuffer[9];
  UartProtocolCallback_PereodicMessageDelete(id, channel);
}

void UartProtocol::handlePereodicMessageEdit() {
  auto crc = crc8.calculate(0u, payloadBuffer, PEREODIC_MESSAGE_EDIT_PAYLOAD+4);
  if (crc != payloadBuffer[21]) return;
  CanMsg msg;
  msg.id = (payloadBuffer[5] << 24) | (payloadBuffer[6] << 16) | (payloadBuffer[7] << 8) | payloadBuffer[8];
  msg.dlc = (payloadBuffer[9] & 0x0F);
  msg.rtr = (payloadBuffer[9] >> 4) & 0x01;
  msg.extendedFrame = (payloadBuffer[9] >> 5) & 0x01;
  for (int i=0; i<8; i++) msg.data[i] = payloadBuffer[i+10];
  uint8_t channel = payloadBuffer[18];
  uint16_t period = (payloadBuffer[19] << 8) | payloadBuffer[20];
  UartProtocolCallback_PereodicMessageEdit(msg, channel, period);
}


void UartProtocol::handleSetChannelBitrate() {
  auto crc = crc8.calculate(0u, payloadBuffer, SET_CHANNEL_BITRATE_PAYLOAD+4);
  auto receivedCrc = payloadBuffer[7];
  if (crc != receivedCrc) return;
  auto bitRateCode = payloadBuffer[6];
  if (bitRateCode == (uint8_t) BAUD_UNKNOWN) return;
  auto channel = payloadBuffer[5];
  UartProtocolCallback_SetChannelBitrate(channel, bitRateCode);
}


void UartProtocol::handleSetChannelFilter() {
  auto crc = crc8.calculate(0u, payloadBuffer, SET_CHANNEL_FILTER_PAYLOAD+4);
  if (crc != payloadBuffer[10]) return;
  auto channel = payloadBuffer[5];
  auto idLow = (payloadBuffer[6] << 8) | payloadBuffer[7];
  auto idHigh = (payloadBuffer[8] << 8) | payloadBuffer[9];
  UartProtocolCallback_SetChannelFilter(channel, idLow, idHigh);
}