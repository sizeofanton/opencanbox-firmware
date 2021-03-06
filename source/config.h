#pragma once

// OpenCANBox prototype
//#define OPEN_CAN_BOX_0 

// OpenCANBox 1
#define OPEN_CAN_BOX_1 

// OpenCANBox 1-M
//#define OPEN_CAN_BOX_2

// OpenCANBox 8CH
//#define OPEN_CAN_BOX_8CH

class Config {
  public:
    static const int        HARDWARE_CODE   = 1;
    static const int        VERSION_CODE    = 3;
    static constexpr char*  VERSION_NAME    = "0.3";
    static const int        CHANNELS_NUMBER = 2;

    static const int        UART_BAUDRATE               = 115200;
    static const int        SYSTICK_TIMER_RELOAD_VALUE  = 100000;
    static const int        WATCHDOG_RELOAD_VALUE       = 0xFFFFFF;
};