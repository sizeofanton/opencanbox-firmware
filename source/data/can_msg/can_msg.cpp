#include "can_msg.h"

CanMsg::CanMsg(uint8_t dlc, bool rtr, bool extendedFrame, uint32_t id, uint8_t* data) {
  this->dlc = dlc;
  this->rtr = (uint8_t) rtr;
  this->extendedFrame = (uint8_t) extendedFrame;
  for (int i=0; i< dlc; i++) this->data[i] = data[i];
  this->id = id;
}

CanMsg::CanMsg() {}