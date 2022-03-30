#pragma once

class Config {
  public:
    static const int        HARDWARE_CODE   = 1;
    static const int        VERSION_CODE    = 3;
    static constexpr char*  VERSION_NAME    = "0.3";
    static const int        CHANNELS_NUMBER = 2;

    static const int        UART_BAUDRATE               = 500000;
    static const int        SYSTICK_TIMER_RELOAD_VALUE  = 100000;
    static const int        WATCHDOG_RELOAD_VALUE       = 0xFFFFFF;
};