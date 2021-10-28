#include "watchdog_timer.h"

WatchdogTimer::WatchdogTimer() {
  watchdogTimer->WDCLKSEL = WDSEL_PCLK;
  bit_set(watchdogTimer->WDMOD, RESET_MOD_BIT);
}

void WatchdogTimer::start(uint32_t resetValue) {
  watchdogTimer->WDTC = resetValue;
  bit_set(watchdogTimer->WDMOD, ENABLE_MOD_BIT);
  bit_set(watchdogTimer->WDMOD, RESET_MOD_BIT);
  bit_clear(watchdogTimer->WDMOD, TIMEOUT_BIT);
  feed();
}

void WatchdogTimer::feed() {
  watchdogTimer->WDFEED = FEED_CHAR0;
  watchdogTimer->WDFEED = FEED_CHAR1;
}