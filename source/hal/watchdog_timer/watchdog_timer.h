#include "LPC17xx.h"
#include "../../util/bit_operations.h"
#include "../abstract/abstract_watchdog_timer.h"

class WatchdogTimer: public AbstractWatchdogTimer {

  private:
    LPC_WDT_TypeDef *watchdogTimer = (LPC_WDT_TypeDef *) LPC_WDT;
    const uint32_t WDSEL_PCLK = 0x01;
    const uint8_t RESET_MOD_BIT = 1;
    const uint8_t ENABLE_MOD_BIT = 0;
    const uint8_t TIMEOUT_BIT = 2;
    

    const uint8_t FEED_CHAR0 = 0xAA;
    const uint8_t FEED_CHAR1 = 0x55;

  public:
    WatchdogTimer();
    void start(uint32_t resetValue);
    void feed();

};