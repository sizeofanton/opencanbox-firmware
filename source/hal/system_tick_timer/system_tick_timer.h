#include "LPC17xx.h"
#include "../../util/bit_operations.h"

class SystemTickTimer {

  private:
    bool running = false;
    unsigned long* STCRL    = (unsigned long *) 0xE000E010;
    unsigned long* STRELOAD = (unsigned long *) 0xE000E014;
    unsigned long* STCURR   = (unsigned long *) 0xE000E018;

    unsigned long* ISER     = (unsigned long *) 0xE000E100;

    const int STCTRL_ENABLE_BIT    = 0u;
    const int STCTRL_TICKINT_BIT   = 1u;
    const int STCTRL_CLKSOURCE_BIT = 2u;

    const int ISE_PLL0 = 16u;
  
  
  public:
    unsigned long globalTicks;
    void start();
    void stop();
    bool isRunning();
    void setReloadValue(unsigned long value);
    unsigned long getValue();
    void irqCallback();
    void delay(uint32_t ms);
};