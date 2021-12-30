#pragma once
#include <stdint.h>

#include "../../util/crc8/crc8.h"
#include "../../hal/uart/uart.h"
#include "../can_msg/can_msg.h"
#include "../../hal/can/can.h"
#include "../../hal/can/can_bitrate.h"

extern "C" void UartProtocolCallback_InfoRequest();
extern "C" void UartProtocolCallback_DeviceDeactivation();
extern "C" void UartProtocolCallback_SingleMessage(CanMsg msg, uint8_t channelId);
extern "C" void UartProtocolCallback_PereodicMessage(CanMsg msg, uint8_t channelId, uint16_t period);
extern "C" void UartProtocolCallback_PereodicMessageDelete(uint16_t id, uint8_t channelId);
extern "C" void UartProtocolCallback_PereodicMessageEdit(CanMsg msg, uint8_t channelId, uint16_t period);
extern "C" void UartProtocolCallback_SetChannelBitrate(uint8_t channelId, uint8_t bitRate);
extern "C" void UartProtocolCallback_SetChannelFilter(uint8_t channelId, uint32_t idLow, uint32_t idHigh);

class UartProtocol 
{

  public:
    enum InputMsgType 
    {
      Unknown                 = 0,
      InfoRequest             = 1,
      DeviceDeactivation      = 2,
      SingleMessage           = 3,
      PereodicMessage         = 4,
      PereodicMessageDelete   = 5,
      PereodicMessageEdit     = 6,
      SetChannelBitrate       = 7,
      SetChannelFilter        = 8
    };

    enum OutputMsgType {
      RxCan                     = 1, 
      WarningDataOverrun        = 2,
      ErrorPassive              = 3,
      ArbitrationLost           = 4,
      BusError                  = 5,
      DeviceInfo                = 6,
      TxTableFull               = 7,
      RxTableFull               = 8
    };

    uint32_t msgRxCan(uint8_t channel, CanMsg msg, uint32_t period, uint8_t *&res);
    uint32_t msgDeviceInfo(uint8_t hardwareVersion, uint16_t firmwareVersion, uint8_t channelNumbers, uint8_t *&res);
    uint32_t msgDataOverrunWarning(uint8_t channel, uint8_t *&res);
    uint32_t msgPassiveError(uint8_t channel, uint8_t *&res);
    uint32_t msgArbitrationLost(uint8_t channel, uint8_t *&res);
    uint32_t msgBusError(uint8_t channel, uint8_t *&res);
    uint32_t msgTxTableFull(uint8_t channel, uint8_t *&res);
    uint32_t msgRxTableFull(uint8_t channel, uint8_t *&res);

    bool validateHeader(uint8_t *header);
    uint8_t validateMsgType(uint8_t msgType, uint32_t *payloadSize);
    void uartRoutine(uint8_t rxByte);
    void syncOnHeader();
    void syncOnMsgType();
    void readPayload();
    void parseMessage();

    void handleInfoRequest();
    void handleDeviceDeactivation();
    void handleSingleMessage();
    void handlePereodicMessage();
    void handlePereodicMessageDelete();
    void handlePereodicMessageEdit();
    void handleSetChannelBitrate();
    void handleSetChannelFilter();

    static const uint8_t CAN_CHANNEL1 = 0x01;
    static const uint8_t CAN_CHANNEL2 = 0x02;

    static const uint8_t ACTIVATION_SYMBOL = 0x55;
    static const uint8_t ACTIVATION_SYMBOL_NEEDED = 10;


  private:
    CRC8 crc8;
    uint8_t lastByte = 0x00;
    uint8_t header[4];
    uint8_t headerReadPos = 3;
    uint8_t msgType = 0;
    uint8_t payloadBuffer[50];
    uint8_t payloadPointer = 0;
    uint32_t payloadSize = 0;
    uint32_t msgSize = 0;
    bool headerSynced = false;
    bool msgTypeSynced = false;

    static const uint8_t DEVICE_DEACTIVATION_SYMBOL     = 0x33;
    static const uint8_t DEACTIVATION_SYMBOOLS_NEEDED   = 10;  

    static const uint8_t INFO_REQUEST_PAYLOAD             = 1;
    static const uint8_t DEVICE_DEACTIVATION_PAYLOAD      = 10;
    static const uint8_t SINGLE_MESSAGE_PAYLOAD           = 15;
    static const uint8_t PEREODIC_MESSAGE_PAYLOAD         = 17;
    static const uint8_t PEREODIC_MESSAGE_DELETE_PAYLOAD  = 6;
    static const uint8_t PEREODIC_MESSAGE_EDIT_PAYLOAD    = 17;
    static const uint8_t SET_CHANNEL_BITRATE_PAYLOAD      = 3;
    static const uint8_t SET_CHANNEL_FILTER_PAYLOAD       = 6;

    static constexpr uint8_t HEADER_BYTES[4]        = {0xCA, 0xB0, 0xCA, 0xFE};
    static constexpr uint8_t INPUT_HEADER_BYTES[4]  = {0xCA, 0xB0, 0xBA, 0xBE};

};