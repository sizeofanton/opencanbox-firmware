#include "can232_uart_protocol.h"

Can232UartProtocol::Can232UartProtocol(Can* can1, Can* can2, Uart* uart) {
  this->can1 = can1;
  this->can2 = can2;
  this->uart = uart;
}

void Can232UartProtocol::uartRoutine(uint8_t rxByte) {
  if (rxByte != END_OF_COMMAND) command[commandPos++] = rxByte;
  else parseCommand();
}

void Can232UartProtocol::setChannelStatus(bool isOpen) {
  isChannelOpen = isOpen;
}

void Can232UartProtocol::addMessageToQueu(CanMsg msg) {
  pendingMessages.put(msg);
}

void Can232UartProtocol::parseCommand() {
  switch(command[0]) {
    
    case SETUP_CAN_BITRATE:
      setupBitrate();
      break;
    
    case SETUP_CAN_BTR0_BTR1:
      uart->uartTx(RET_ER);
      break;
    
    case OPEN_CAN_CHANNEL:
      if (isChannelOpen) {
        uart->uartTx(RET_ER);
      }
      break;
    
    case OPEN_CAN_LISTEN_ONLY:
      uart->uartTx(RET_ER);
      break;

    case CLOSE_CAN_CHANNEL:
      if (isChannelOpen) {
        isChannelOpen = false;
        uart->uartTx(RET_OK);
      } else {
        uart->uartTx(RET_ER);
      }
      break;

   case TRANSMIT_11BIT_MESSAGE:
      transmitFrame(false, false);
      uart->uartTx(RET_OK);
      break;

   case TRANSMIT_29BIT_MESSAGE:
      transmitFrame(true, false);
      uart->uartTx(RET_OK);
      break;

   case TRANSMIT_11BIT_RTR:
      transmitFrame(false, true);
      uart->uartTx(RET_OK);
      break;

   case TRANSMIT_29BIT_RTR:
      transmitFrame(true, true);
      uart->uartTx(RET_OK);
      break;

   case POLL_FIFO_SINGLE:
      pollFifoSingle();
      break;

   case POLL_FIFO_ALL:

      break;

   case READ_STATUS_FLAGS:

      break;

   case AUTO_POLL_MODE:
      uart->uartTx(RET_ER);
      break;

   case FILTER_MODE_SETTING:
      uart->uartTx(RET_ER);
      break;

   case SET_ACCEPTANCE_CODE:
      uart->uartTx(RET_ER);
      break;

   case SET_ACCEPTANCE_MASK:
      uart->uartTx(RET_ER);
      break;

   case SET_UP_BAUD:
      uart->uartTx(RET_ER);
      break;

   case GET_SOFT_HARD_VERSION:
      uart->uartTx(RET_ER);
      break;

   case GET_SERIAL:
      uart->uartTx(RET_ER);
      break;

   case SET_TIMESTAMP_MODE:
      uart->uartTx(RET_ER);
      break;

   case AUTO_STARTUP_MODE:
      uart->uartTx(RET_ER);
      break;

    default: break;
  }
  clearCommand();
}

void Can232UartProtocol::setupBitrate() {
  if (isChannelOpen) {
    uart->uartTx(RET_ER);
    return;
  }
  switch(command[1]) {
    case CAN_BITRATE_10KBIT:
      can1->setBaudRate(BaudRate::_10kbit);
      can2->setBaudRate(BaudRate::_10kbit);
      uart->uartTx(RET_OK);
      break;
    case CAN_BITRATE_20KBIT:
      can1->setBaudRate(BaudRate::_20kbit);
      can2->setBaudRate(BaudRate::_20kbit);
      uart->uartTx(RET_OK);
      break;
    case CAN_BITRATE_50KBIT:
      can1->setBaudRate(BaudRate::_50kbit);
      can2->setBaudRate(BaudRate::_50kbit);
      uart->uartTx(RET_OK);
      break;
    case CAN_BITRATE_100KBIT:
      can1->setBaudRate(BaudRate::_100kbit);
      can2->setBaudRate(BaudRate::_100kbit);
      uart->uartTx(RET_OK);
      break;
    case CAN_BITRATE_125KBIT:
      can1->setBaudRate(BaudRate::_125kbit);
      can2->setBaudRate(BaudRate::_125kbit);
      uart->uartTx(RET_OK);
      break;
    case CAN_BITRATE_250KBIT:
      can1->setBaudRate(BaudRate::_250kbit);
      can2->setBaudRate(BaudRate::_250kbit);
      uart->uartTx(RET_OK);
      break;
    case CAN_BITRATE_500KBIT:
      can1->setBaudRate(BaudRate::_500kbit);
      can2->setBaudRate(BaudRate::_500kbit);
      uart->uartTx(RET_OK);
      break;
    case CAN_BITRATE_800KBIT:
      uart->uartTx(RET_ER);
      break;
    case CAN_BITRATE_1MBIT:
      can1->setBaudRate(BaudRate::_1000kbit);
      can2->setBaudRate(BaudRate::_1000kbit);
      uart->uartTx(RET_OK);
      break;
    default: 
      uart->uartTx(RET_ER);
      break;
  }
}

void Can232UartProtocol::transmitFrame(bool extended, bool rtr) {
   char charId[3] = {command[1], command[2], command[3]};
   char charDlc = command[4];
   char data1[2] = {command[5], command[6]};
   char data2[2] = {command[7], command[8]};
   char data3[2] = {command[9], command[10]};
   char data4[2] = {command[11], command[12]};
   char data5[2] = {command[13], command[14]};
   char data6[2] = {command[15], command[16]};
   char data7[2] = {command[17], command[18]};
   char data8[2] = {command[19], command[20]};
   
   uint16_t id = (uint16_t) strtol((const char*)charId, NULL, 16);
   uint8_t dlc = (uint8_t) strtol((const char*)&charDlc, NULL, 10);
   uint8_t data[8];
   data[0] = (uint8_t) strtol((const char*)&data1, NULL, 16);
   data[1] = (uint8_t) strtol((const char*)&data2, NULL, 16);
   data[2] = (uint8_t) strtol((const char*)&data3, NULL, 16);
   data[3] = (uint8_t) strtol((const char*)&data4, NULL, 16);
   data[4] = (uint8_t) strtol((const char*)&data5, NULL, 16);
   data[5] = (uint8_t) strtol((const char*)&data6, NULL, 16);
   data[6] = (uint8_t) strtol((const char*)&data7, NULL, 16);
   data[7] = (uint8_t) strtol((const char*)&data8, NULL, 16);


   CanMsg msg;
   msg.id = id;
   msg.dlc = dlc;
   extended ? msg.extendedFrame = 1 : msg.extendedFrame = 0;
   rtr ? msg.rtr = 1 : msg.rtr = 0;
   msg.data[0] = data[0];
   msg.data[1] = data[1];
   msg.data[2] = data[2];
   msg.data[3] = data[3];
   msg.data[4] = data[4];
   msg.data[5] = data[5];
   msg.data[6] = data[6];
   msg.data[7] = data[7];
   can1->canSend(msg);
   can2->canSend(msg);
}

void Can232UartProtocol::pollFifoSingle() {

}

void Can232UartProtocol::clearCommand() {
  commandPos = 0;
  for (int i=0; i<50; i++) command[i] = 0x00;
}