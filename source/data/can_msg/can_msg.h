#pragma once
#include "stdint.h"

class CanMsg 
{
public:
  CanMsg(uint8_t dlc, bool rtr, bool extendedFrame, uint32_t id, uint8_t data[8]);
  CanMsg();

  uint8_t dlc;
  uint8_t rtr;
  uint8_t extendedFrame;
  uint32_t id;
  uint8_t data[8];
};