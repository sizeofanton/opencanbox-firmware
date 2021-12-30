#pragma once
#include <stdio.h>
#include <stdlib.h>

#include "hal/led/led.h"
#include "hal/system_tick_timer/system_tick_timer.h"
#include "hal/uart/uart.h"
#include "hal/can/can.h"
#include "hal/watchdog_timer/watchdog_timer.h"

#include "data/uart_protocol/uart_protocol.h"
#include "data/tx_table/tx_table.h"
#include "data/rx_table/rx_table.hpp"
#include "data/ring_buffer/ring_buffer.h"

#include "config.h"

int codeCounter = 0;
bool hardwareActivated = false;

uint32_t uartBytesAvailable = 0;

bool errorWarningCan1 = false;
bool errorCan1 = false;
bool errorWarningCan2 = false;
bool errorCan2 = false;

Led ledGc(Led::LED_GC);
Led ledCan1(Led::LED_CAN1);
Led ledCan1Err(Led::LED_CAN1_ERROR);
Led ledCan2(Led::LED_CAN2);
Led ledCan2Err(Led::LED_CAN2_ERROR); 
SystemTickTimer systemTickTimer;
Uart uart(Config::UART_BAUDRATE);
Can can1(Can::CAN1, _100kbit);
Can can2(Can::CAN2, _100kbit);
WatchdogTimer watchdogTimer;
UartProtocol uartProtocol;

TxTable can1TxTable;
TxTable can2TxTable;
RxTable can1RxTable;
RxTable can2RxTable;
RingBuffer uartTxBuffer;

void initCanInterfaces();
void setErrorLeds();

void canReceiveMsg(Can::CAN_INSTANCE instance);
void canWarning(Can::CAN_INSTANCE instance);
void canDataOverrun(Can::CAN_INSTANCE instance);
void canErrorPassive(Can::CAN_INSTANCE instance);
void canArbitrationLost(Can::CAN_INSTANCE instance);
void canBusError(Can::CAN_INSTANCE instance);

void uartRoutine();

void systemReset();

inline void _delay_ms(unsigned int ms);

Config config;
