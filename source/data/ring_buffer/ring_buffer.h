#pragma once 
#include "stdint.h"

#define  RING_BUFFER_SIZE 500

class RingBuffer 
{
  public:
    void put(uint8_t e);
    uint8_t get();
    bool available();

  private:
    uint8_t elements[RING_BUFFER_SIZE];
    uint32_t writePtr = 0;
    uint32_t readPtr = 0;
    uint32_t bytesAvailable = 0;
};