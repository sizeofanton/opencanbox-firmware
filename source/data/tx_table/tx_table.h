#include "cmath"
#include "../can_msg/can_msg.h"
#include "../../hal/can/can.h"

class TxTable {
public:
    enum RetCode {
      Success,
      NoSpace,
      NoSuchId,
      TxError,
      AlreadyExist,
      NothingToTransmit
    };

    TxTable();
    RetCode add(CanMsg msg, uint32_t period);
    RetCode remove(uint32_t id);
    RetCode edit(uint32_t id, CanMsg *msg, uint32_t period);
    RetCode proceedMessages(uint64_t systemTick, Can *can);

private:
    static const int TX_TABLE_SIZE = 50;

    CanMsg    messages[TX_TABLE_SIZE];
    uint32_t  periods[TX_TABLE_SIZE];
    bool      busy[TX_TABLE_SIZE];
    uint64_t  lastTxTime[TX_TABLE_SIZE];  
};