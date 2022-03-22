#pragma once
#include <stdint.h>
#include <cmath>

class RxTable {
  public:

    enum RetCode {
      Success,
      NoSpace,
      NoSuchId
    };

    RxTable();
    RetCode   add(uint32_t id, uint32_t sysTick);
    RetCode   getPeriod(uint32_t id, uint32_t *period);

  private:
    inline uint32_t  alreadyExist(uint32_t id);

    static const int RX_TABLE_SIZE = 100;
    uint32_t ids[RX_TABLE_SIZE];
    uint32_t lastTimeReceived[RX_TABLE_SIZE];
    uint32_t periods[RX_TABLE_SIZE];
    uint32_t busy[RX_TABLE_SIZE];
};