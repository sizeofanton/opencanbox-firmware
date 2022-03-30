#pragma once
#include "stdint.h"
#include "stdlib.h"
#include "../../hal/can/can.h"
#include "../../hal/uart/uart.h"
#include "../ring_buffer/ring_buffer.h"


class Can232UartProtocol {
  public:
    Can232UartProtocol(Can* can1, Can* can2, Uart* uart);
    void uartRoutine(uint8_t rxByte);
    void setChannelStatus(bool isOpen);
    void addMessageToQueu(CanMsg msg);

  private:
    
    void clearCommand();
    void parseCommand();
    void setupBitrate();
    void transmitFrame(bool extended = false, bool rtr = false);
    void pollFifoSingle();
    


    Can* can1 = nullptr;
    Can* can2 = nullptr;
    Uart* uart = nullptr;
    uint8_t command[50];
    uint8_t commandPos = 0;
    RingBuffer<CanMsg> pendingMessages;
    bool isChannelOpen = false;
    

    static const uint8_t END_OF_COMMAND           = '\r';
    
    static const uint8_t SETUP_CAN_BITRATE        = 'S';
    static const uint8_t CAN_BITRATE_10KBIT       = '0';
    static const uint8_t CAN_BITRATE_20KBIT       = '1';
    static const uint8_t CAN_BITRATE_50KBIT       = '2';
    static const uint8_t CAN_BITRATE_100KBIT      = '3';
    static const uint8_t CAN_BITRATE_125KBIT      = '4';
    static const uint8_t CAN_BITRATE_250KBIT      = '5';
    static const uint8_t CAN_BITRATE_500KBIT      = '6';
    static const uint8_t CAN_BITRATE_800KBIT      = '7';
    static const uint8_t CAN_BITRATE_1MBIT        = '8';
    static const uint8_t SETUP_CAN_BTR0_BTR1      = 's';
    static const uint8_t OPEN_CAN_CHANNEL         = 'O';
    static const uint8_t OPEN_CAN_LISTEN_ONLY     = 'L';
    static const uint8_t CLOSE_CAN_CHANNEL        = 'C';
    static const uint8_t TRANSMIT_11BIT_MESSAGE   = 't';
    static const uint8_t TRANSMIT_29BIT_MESSAGE   = 'T';
    static const uint8_t TRANSMIT_11BIT_RTR       = 'r';
    static const uint8_t TRANSMIT_29BIT_RTR       = 'R';
    static const uint8_t POLL_FIFO_SINGLE         = 'P';
    static const uint8_t POLL_FIFO_ALL            = 'A';
    static const uint8_t READ_STATUS_FLAGS        = 'F';
    static const uint8_t AUTO_POLL_MODE           = 'X';
    static const uint8_t FILTER_MODE_SETTING      = 'W';
    static const uint8_t SET_ACCEPTANCE_CODE      = 'M';
    static const uint8_t SET_ACCEPTANCE_MASK      = 'm';
    static const uint8_t SET_UP_BAUD              = 'U';
    static const uint8_t GET_SOFT_HARD_VERSION    = 'V';
    static const uint8_t GET_SERIAL               = 'N';
    static const uint8_t SET_TIMESTAMP_MODE       = 'Z';
    static const uint8_t AUTO_STARTUP_MODE        = 'Q';


    static const uint8_t RET_OK = '\r';
    static const uint8_t RET_ER = 7;


};