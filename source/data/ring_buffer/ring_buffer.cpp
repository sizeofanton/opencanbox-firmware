#include "ring_buffer.h"

void RingBuffer::put(uint8_t e) {
  if (writePtr == RING_BUFFER_SIZE - 1) writePtr = 0;
  elements[writePtr++] = e;
  bytesAvailable++;
}

uint8_t RingBuffer::get() {
  uint8_t elem = elements[readPtr];
  readPtr = readPtr == RING_BUFFER_SIZE ? 0 : readPtr+1;
  bytesAvailable--;
  return elem;
}

bool RingBuffer::available() {
  return bytesAvailable > 0;
}