#pragma once
#include "../../data/can_msg/can_msg.h"
#include "../../data/can_bitrate.h"

class AbstractCan {
  public:
    virtual uint8_t canSend(CanMsg msg) = 0;
    virtual CanMsg canRead() = 0;
    virtual void setBaudRate(BaudRate baudRate) = 0;
};