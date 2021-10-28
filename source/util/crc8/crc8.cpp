#include "crc8.h"

uint8_t CRC8::calculate(uint8_t crc, void const* mem, uint32_t len) {
  uint8_t const *data = (uint8_t *) mem;
  if (data == nullptr) return 0xff;
  crc &= 0xff;
  while (len--) crc = crc8_table[crc ^ *data++];
  return crc;
}