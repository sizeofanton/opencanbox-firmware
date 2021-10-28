#include "tx_table.h"

TxTable::TxTable() {
  for (int i=0; i<TX_TABLE_SIZE; i++) {
    busy[i] = false;
    lastTxTime[i] = 0;
    messages[i].id = 0x900;
  }
}

TxTable::RetCode TxTable::add(CanMsg msg, uint32_t period) {
  auto freePosition = -1;
  for (int i=0; i<TX_TABLE_SIZE; i++) {
    if (busy[i] == false) {
      freePosition = i; 
      break;
    }
  }
  if (freePosition == -1) return NoSpace;
  else {
    messages[freePosition] = msg;
    periods[freePosition] = period;
    busy[freePosition] = true;
    return Success;
  }
}

TxTable::RetCode TxTable::remove(uint32_t id) {
  auto idPosition = -1;
  for (int i = 0; i < TX_TABLE_SIZE; i++) {
    if (messages[i].id == id) idPosition = i;
  }
  if (idPosition == -1) return NoSuchId;
  else {
    busy[idPosition] = false;
    return Success;
  }
}

TxTable::RetCode TxTable::edit(uint32_t id, CanMsg *msg, uint32_t period) {
  auto idToEdit = -1;
  for (int i = 0; i < TX_TABLE_SIZE; i++) {
    if (messages[i].id == id) idToEdit = i;
  }
  if (idToEdit == -1) return NoSuchId;
  else {
    messages[idToEdit].id = msg->id;
    messages[idToEdit].dlc = msg->dlc;
    messages[idToEdit].extendedFrame = msg->extendedFrame;
    messages[idToEdit].rtr = msg->rtr;
    for (int i=0; i<messages[idToEdit].dlc; i++) messages[idToEdit].data[i] = msg->data[i];
    periods[idToEdit] = period;
    return Success;
  }
}

TxTable::RetCode TxTable::proceedMessages(uint64_t systemTick, Can *can) {
  auto errors = 0;
  auto transmitted = 0;
  for (int i=0; i<TX_TABLE_SIZE; i++) {
    if (busy[i] == true) {
      if (std::fabs(systemTick - lastTxTime[i]) >= periods[i]) {
        auto ret = can->canSend(messages[i]);
        if (ret != 0) errors++;
        else transmitted++;
        lastTxTime[i] = systemTick;
      }
    }
  }
  if (transmitted == 0) return NothingToTransmit;
  return errors == 0 ? Success : TxError;
}
