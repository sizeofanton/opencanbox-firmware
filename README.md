## Open CAN Box - Firmware repository

Firmware, written in C++ for the USB to CAN 2.0 adapter, that is based on LPC1764 MCU. This project was originally started by me and my pal for learning something about making a custom  device *from scratch*. IDE - Segger Embedded Studio, VS Code with plugin Cortex Debug also an option. The hardware description can be found [here](https://github.com/Digital-Ape/opencanbox-hardware).

### Characteristics of firmware

* 10Kbit/s, 20Kbit/s, 50Kbit/s, 100Kbit/s, 125Kbit/s, 250Kbit/s, 500Kbit/s, 1Mbit/s bitrates is supported

* 15 KBytes of FLASH used
* 8 KBytes of RAM used

### Structure

```
.
├── source
	└── data
		└── can_msg
		└── ring_buffer
		└── rx_table
		└── tx_table
		└── uart_protocol
		└── can_bitrate.h
	└── hal
		└── abstract
		└── can
		└── led
		└── system_tick_timer
		└── uart
		└── watchdog_timer
	└── util
		└── crc8
		└── bit_operations.h
	└── main.cpp
	└── main.h
	└── config.h
├── tests
├── LPC1700
```

