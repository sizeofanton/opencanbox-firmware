//#include "ring_buffer.h"

//void RingBuffer<T>::put(T e) {
//  if (writePtr == RING_BUFFER_SIZE - 1) writePtr = 0;
//  elements[writePtr++] = e;
//  bytesAvailable++;
//}

//T RingBuffer::get() {
//  uint8_t elem = elements[readPtr];
//  readPtr = readPtr == RING_BUFFER_SIZE ? 0 : readPtr+1;
//  bytesAvailable--;
//  return elem;
//}

//bool RingBuffer<T>::available() {
//  return bytesAvailable > 0;
//}

//uint32_t RingBuffer::getAvailableSize() {
//  return bytesAvailable;
//}