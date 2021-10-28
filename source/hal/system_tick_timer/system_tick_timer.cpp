#include "system_tick_timer.h"

void SystemTickTimer::start() {
  bit_set(*STCRL, STCTRL_ENABLE_BIT);
  bit_set(*STCRL, STCTRL_TICKINT_BIT);
  bit_set(*STCRL, STCTRL_CLKSOURCE_BIT);

  running = true;
  globalTicks = 0;
}

void SystemTickTimer::stop() {
  bit_clear(*STCRL, STCTRL_ENABLE_BIT);
  bit_clear(*STCRL, STCTRL_TICKINT_BIT);
  bit_clear(*STCRL, STCTRL_CLKSOURCE_BIT);

  running = false;
}

bool SystemTickTimer::isRunning() {
  return running;
}

void SystemTickTimer::setReloadValue(unsigned long value) {
  *STRELOAD = value;
}

void SystemTickTimer::delay(uint32_t delay) {
  uint32_t currentTick = globalTicks;
  while ((delay + currentTick) < globalTicks) {}
}