#pragma once 
#include "stdint.h"

template <typename T>
class RingBuffer 
{
  public:

    void put(T e) {
      if (writePtr == RING_BUFFER_SIZE - 1) writePtr = 0;
      elements[writePtr++] = e;
      bytesAvailable++;
    }

    T get() {
      uint8_t elem = elements[readPtr];
      readPtr = readPtr == RING_BUFFER_SIZE ? 0 : readPtr+1;
      bytesAvailable--;
      return elem;
    }

    bool available() {
      return bytesAvailable > 0;
    }

    uint32_t  getAvailableSize() {
      return bytesAvailable;
    }

  private:
    static const uint32_t RING_BUFFER_SIZE = 500;

    T        elements[RING_BUFFER_SIZE];
    uint32_t writePtr = 0;
    uint32_t readPtr = 0;
    uint32_t bytesAvailable = 0;
};