#include "rx_table.hpp"

RxTable::RxTable() {
  for (int i = 0; i < RX_TABLE_SIZE; i++) {
    busy[i] = false;
    periods[i] = 0;
  }
}

inline uint32_t RxTable::alreadyExist(uint32_t id) {
  uint32_t pos = -1;
  for (int i = 0; i < RX_TABLE_SIZE; i++) {
   if (ids[i] == id) pos = i;
  }
  return pos;
}

RxTable::RetCode RxTable::add(uint32_t id, uint32_t sysTick) {
  int pos = -1;
  pos = alreadyExist(id);
  if (pos == -1) {
    for (int i=0; i<RX_TABLE_SIZE; i++) {
      if (busy[i] == false) {
        pos = i;
        busy[i] = true;
        break;
      }
    }
  }
  if (pos == -1) return NoSpace;
  ids[pos] = id;
  periods[pos] = sysTick - periods[pos];
  return Success;
}

RxTable::RetCode RxTable::getPeriod(uint32_t id, uint32_t *period) {
  *period = 0;
  for (int i = 0; i < RX_TABLE_SIZE; i++) {
    if (ids[i] == id) *period = periods[i];
  }
  return *period == 0 ? NoSuchId : Success;
}