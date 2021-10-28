HOST_CXX = clang++


all: \
  Output/Debug/Exe/OpenCanBoxFirmware.elf\

-include Output/Debug/Obj/OpenCanBoxFirmware/system_LPC17xx.d
Output/Debug/Obj/OpenCanBoxFirmware/system_LPC17xx.o:LPC1700/CMSIS/Device/Source/system_LPC17xx.c
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/cc1" -fmessage-length=0 -fno-diagnostics-show-caret -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb -mtp=soft -munaligned-access -nostdinc "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/segger-rtl/include" "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/include" -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include "-I/Users/antonsizov/Library/SEGGER/SEGGER Embedded Studio/v3/packages/CMSIS_5/CMSIS/Core/Include" -D__SIZEOF_WCHAR_T=4 -D__ARM_ARCH_7M__ -D__SES_ARM -D__HEAP_SIZE__=0 -D__SES_VERSION=53400 -D__SEGGER_LINKER -DDEBUG -DLPC175x_6x -D__LPC1700_FAMILY -D__LPC176x_SUBFAMILY -DARM_MATH_CM3 -MD /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/system_LPC17xx.d -MQ Output/Debug/Obj/OpenCanBoxFirmware/system_LPC17xx.o -quiet -std=gnu99 -g3 -gpubnames -fomit-frame-pointer -fno-dwarf2-cfi-asm -fno-builtin -ffunction-sections -fdata-sections -mtext=.init -mrodata=.init_rodata -fshort-enums -fno-common /Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Source/system_LPC17xx.c -o /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/system_LPC17xx.asm
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/as" --traditional-format -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/system_LPC17xx.asm -o Output/Debug/Obj/OpenCanBoxFirmware/system_LPC17xx.o
	"/Applications/SEGGER Embedded Studio for ARM 5.34/bin/rm" /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/system_LPC17xx.asm

-include Output/Debug/Obj/OpenCanBoxFirmware/can.d
Output/Debug/Obj/OpenCanBoxFirmware/can.o:source/hal/can/can.cpp
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/cc1plus" -fmessage-length=0 -fno-diagnostics-show-caret -fno-exceptions -fno-rtti -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb -mtp=soft -munaligned-access -nostdinc "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/segger-rtl/include" "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/include" -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include "-I/Users/antonsizov/Library/SEGGER/SEGGER Embedded Studio/v3/packages/CMSIS_5/CMSIS/Core/Include" -D__SIZEOF_WCHAR_T=4 -D__ARM_ARCH_7M__ -D__SES_ARM -D__HEAP_SIZE__=0 -D__SES_VERSION=53400 -D__SEGGER_LINKER -DDEBUG -DLPC175x_6x -D__LPC1700_FAMILY -D__LPC176x_SUBFAMILY -DARM_MATH_CM3 -MD /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/can.d -MQ Output/Debug/Obj/OpenCanBoxFirmware/can.o -quiet -std=gnu++11 -g3 -gpubnames -fomit-frame-pointer -fno-dwarf2-cfi-asm -fno-builtin -ffunction-sections -fdata-sections -fshort-enums -fno-common /Users/antonsizov/source/opencanbox-firmware/source/hal/can/can.cpp -o /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/can.asm
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/as" --traditional-format -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/can.asm -o Output/Debug/Obj/OpenCanBoxFirmware/can.o
	"/Applications/SEGGER Embedded Studio for ARM 5.34/bin/rm" /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/can.asm

-include Output/Debug/Obj/OpenCanBoxFirmware/led.d
Output/Debug/Obj/OpenCanBoxFirmware/led.o:source/hal/led/led.cpp
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/cc1plus" -fmessage-length=0 -fno-diagnostics-show-caret -fno-exceptions -fno-rtti -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb -mtp=soft -munaligned-access -nostdinc "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/segger-rtl/include" "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/include" -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include "-I/Users/antonsizov/Library/SEGGER/SEGGER Embedded Studio/v3/packages/CMSIS_5/CMSIS/Core/Include" -D__SIZEOF_WCHAR_T=4 -D__ARM_ARCH_7M__ -D__SES_ARM -D__HEAP_SIZE__=0 -D__SES_VERSION=53400 -D__SEGGER_LINKER -DDEBUG -DLPC175x_6x -D__LPC1700_FAMILY -D__LPC176x_SUBFAMILY -DARM_MATH_CM3 -MD /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/led.d -MQ Output/Debug/Obj/OpenCanBoxFirmware/led.o -quiet -std=gnu++11 -g3 -gpubnames -fomit-frame-pointer -fno-dwarf2-cfi-asm -fno-builtin -ffunction-sections -fdata-sections -fshort-enums -fno-common /Users/antonsizov/source/opencanbox-firmware/source/hal/led/led.cpp -o /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/led.asm
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/as" --traditional-format -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/led.asm -o Output/Debug/Obj/OpenCanBoxFirmware/led.o
	"/Applications/SEGGER Embedded Studio for ARM 5.34/bin/rm" /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/led.asm

-include Output/Debug/Obj/OpenCanBoxFirmware/system_tick_timer.d
Output/Debug/Obj/OpenCanBoxFirmware/system_tick_timer.o:source/hal/system_tick_timer/system_tick_timer.cpp
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/cc1plus" -fmessage-length=0 -fno-diagnostics-show-caret -fno-exceptions -fno-rtti -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb -mtp=soft -munaligned-access -nostdinc "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/segger-rtl/include" "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/include" -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include "-I/Users/antonsizov/Library/SEGGER/SEGGER Embedded Studio/v3/packages/CMSIS_5/CMSIS/Core/Include" -D__SIZEOF_WCHAR_T=4 -D__ARM_ARCH_7M__ -D__SES_ARM -D__HEAP_SIZE__=0 -D__SES_VERSION=53400 -D__SEGGER_LINKER -DDEBUG -DLPC175x_6x -D__LPC1700_FAMILY -D__LPC176x_SUBFAMILY -DARM_MATH_CM3 -MD /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/system_tick_timer.d -MQ Output/Debug/Obj/OpenCanBoxFirmware/system_tick_timer.o -quiet -std=gnu++11 -g3 -gpubnames -fomit-frame-pointer -fno-dwarf2-cfi-asm -fno-builtin -ffunction-sections -fdata-sections -fshort-enums -fno-common /Users/antonsizov/source/opencanbox-firmware/source/hal/system_tick_timer/system_tick_timer.cpp -o /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/system_tick_timer.asm
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/as" --traditional-format -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/system_tick_timer.asm -o Output/Debug/Obj/OpenCanBoxFirmware/system_tick_timer.o
	"/Applications/SEGGER Embedded Studio for ARM 5.34/bin/rm" /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/system_tick_timer.asm

-include Output/Debug/Obj/OpenCanBoxFirmware/uart.d
Output/Debug/Obj/OpenCanBoxFirmware/uart.o:source/hal/uart/uart.cpp
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/cc1plus" -fmessage-length=0 -fno-diagnostics-show-caret -fno-exceptions -fno-rtti -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb -mtp=soft -munaligned-access -nostdinc "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/segger-rtl/include" "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/include" -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include "-I/Users/antonsizov/Library/SEGGER/SEGGER Embedded Studio/v3/packages/CMSIS_5/CMSIS/Core/Include" -D__SIZEOF_WCHAR_T=4 -D__ARM_ARCH_7M__ -D__SES_ARM -D__HEAP_SIZE__=0 -D__SES_VERSION=53400 -D__SEGGER_LINKER -DDEBUG -DLPC175x_6x -D__LPC1700_FAMILY -D__LPC176x_SUBFAMILY -DARM_MATH_CM3 -MD /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/uart.d -MQ Output/Debug/Obj/OpenCanBoxFirmware/uart.o -quiet -std=gnu++11 -g3 -gpubnames -fomit-frame-pointer -fno-dwarf2-cfi-asm -fno-builtin -ffunction-sections -fdata-sections -fshort-enums -fno-common /Users/antonsizov/source/opencanbox-firmware/source/hal/uart/uart.cpp -o /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/uart.asm
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/as" --traditional-format -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/uart.asm -o Output/Debug/Obj/OpenCanBoxFirmware/uart.o
	"/Applications/SEGGER Embedded Studio for ARM 5.34/bin/rm" /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/uart.asm

-include Output/Debug/Obj/OpenCanBoxFirmware/watchdog_timer.d
Output/Debug/Obj/OpenCanBoxFirmware/watchdog_timer.o:source/hal/watchdog_timer/watchdog_timer.cpp
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/cc1plus" -fmessage-length=0 -fno-diagnostics-show-caret -fno-exceptions -fno-rtti -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb -mtp=soft -munaligned-access -nostdinc "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/segger-rtl/include" "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/include" -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include "-I/Users/antonsizov/Library/SEGGER/SEGGER Embedded Studio/v3/packages/CMSIS_5/CMSIS/Core/Include" -D__SIZEOF_WCHAR_T=4 -D__ARM_ARCH_7M__ -D__SES_ARM -D__HEAP_SIZE__=0 -D__SES_VERSION=53400 -D__SEGGER_LINKER -DDEBUG -DLPC175x_6x -D__LPC1700_FAMILY -D__LPC176x_SUBFAMILY -DARM_MATH_CM3 -MD /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/watchdog_timer.d -MQ Output/Debug/Obj/OpenCanBoxFirmware/watchdog_timer.o -quiet -std=gnu++11 -g3 -gpubnames -fomit-frame-pointer -fno-dwarf2-cfi-asm -fno-builtin -ffunction-sections -fdata-sections -fshort-enums -fno-common /Users/antonsizov/source/opencanbox-firmware/source/hal/watchdog_timer/watchdog_timer.cpp -o /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/watchdog_timer.asm
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/as" --traditional-format -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/watchdog_timer.asm -o Output/Debug/Obj/OpenCanBoxFirmware/watchdog_timer.o
	"/Applications/SEGGER Embedded Studio for ARM 5.34/bin/rm" /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/watchdog_timer.asm

-include Output/Debug/Obj/OpenCanBoxFirmware/crc8.d
Output/Debug/Obj/OpenCanBoxFirmware/crc8.o:source/util/crc8/crc8.cpp
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/cc1plus" -fmessage-length=0 -fno-diagnostics-show-caret -fno-exceptions -fno-rtti -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb -mtp=soft -munaligned-access -nostdinc "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/segger-rtl/include" "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/include" -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include "-I/Users/antonsizov/Library/SEGGER/SEGGER Embedded Studio/v3/packages/CMSIS_5/CMSIS/Core/Include" -D__SIZEOF_WCHAR_T=4 -D__ARM_ARCH_7M__ -D__SES_ARM -D__HEAP_SIZE__=0 -D__SES_VERSION=53400 -D__SEGGER_LINKER -DDEBUG -DLPC175x_6x -D__LPC1700_FAMILY -D__LPC176x_SUBFAMILY -DARM_MATH_CM3 -MD /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/crc8.d -MQ Output/Debug/Obj/OpenCanBoxFirmware/crc8.o -quiet -std=gnu++11 -g3 -gpubnames -fomit-frame-pointer -fno-dwarf2-cfi-asm -fno-builtin -ffunction-sections -fdata-sections -fshort-enums -fno-common /Users/antonsizov/source/opencanbox-firmware/source/util/crc8/crc8.cpp -o /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/crc8.asm
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/as" --traditional-format -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/crc8.asm -o Output/Debug/Obj/OpenCanBoxFirmware/crc8.o
	"/Applications/SEGGER Embedded Studio for ARM 5.34/bin/rm" /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/crc8.asm

-include Output/Debug/Obj/OpenCanBoxFirmware/md4.d
Output/Debug/Obj/OpenCanBoxFirmware/md4.o:source/util/md4/md4.c
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/cc1" -fmessage-length=0 -fno-diagnostics-show-caret -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb -mtp=soft -munaligned-access -nostdinc "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/segger-rtl/include" "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/include" -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include "-I/Users/antonsizov/Library/SEGGER/SEGGER Embedded Studio/v3/packages/CMSIS_5/CMSIS/Core/Include" -D__SIZEOF_WCHAR_T=4 -D__ARM_ARCH_7M__ -D__SES_ARM -D__HEAP_SIZE__=0 -D__SES_VERSION=53400 -D__SEGGER_LINKER -DDEBUG -DLPC175x_6x -D__LPC1700_FAMILY -D__LPC176x_SUBFAMILY -DARM_MATH_CM3 -MD /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/md4.d -MQ Output/Debug/Obj/OpenCanBoxFirmware/md4.o -quiet -std=gnu99 -g3 -gpubnames -fomit-frame-pointer -fno-dwarf2-cfi-asm -fno-builtin -ffunction-sections -fdata-sections -fshort-enums -fno-common /Users/antonsizov/source/opencanbox-firmware/source/util/md4/md4.c -o /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/md4.asm
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/as" --traditional-format -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/md4.asm -o Output/Debug/Obj/OpenCanBoxFirmware/md4.o
	"/Applications/SEGGER Embedded Studio for ARM 5.34/bin/rm" /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/md4.asm

-include Output/Debug/Obj/OpenCanBoxFirmware/can_msg.d
Output/Debug/Obj/OpenCanBoxFirmware/can_msg.o:source/data/can_msg/can_msg.cpp
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/cc1plus" -fmessage-length=0 -fno-diagnostics-show-caret -fno-exceptions -fno-rtti -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb -mtp=soft -munaligned-access -nostdinc "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/segger-rtl/include" "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/include" -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include "-I/Users/antonsizov/Library/SEGGER/SEGGER Embedded Studio/v3/packages/CMSIS_5/CMSIS/Core/Include" -D__SIZEOF_WCHAR_T=4 -D__ARM_ARCH_7M__ -D__SES_ARM -D__HEAP_SIZE__=0 -D__SES_VERSION=53400 -D__SEGGER_LINKER -DDEBUG -DLPC175x_6x -D__LPC1700_FAMILY -D__LPC176x_SUBFAMILY -DARM_MATH_CM3 -MD /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/can_msg.d -MQ Output/Debug/Obj/OpenCanBoxFirmware/can_msg.o -quiet -std=gnu++11 -g3 -gpubnames -fomit-frame-pointer -fno-dwarf2-cfi-asm -fno-builtin -ffunction-sections -fdata-sections -fshort-enums -fno-common /Users/antonsizov/source/opencanbox-firmware/source/data/can_msg/can_msg.cpp -o /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/can_msg.asm
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/as" --traditional-format -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/can_msg.asm -o Output/Debug/Obj/OpenCanBoxFirmware/can_msg.o
	"/Applications/SEGGER Embedded Studio for ARM 5.34/bin/rm" /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/can_msg.asm

-include Output/Debug/Obj/OpenCanBoxFirmware/ring_buffer.d
Output/Debug/Obj/OpenCanBoxFirmware/ring_buffer.o:source/data/ring_buffer/ring_buffer.cpp
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/cc1plus" -fmessage-length=0 -fno-diagnostics-show-caret -fno-exceptions -fno-rtti -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb -mtp=soft -munaligned-access -nostdinc "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/segger-rtl/include" "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/include" -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include "-I/Users/antonsizov/Library/SEGGER/SEGGER Embedded Studio/v3/packages/CMSIS_5/CMSIS/Core/Include" -D__SIZEOF_WCHAR_T=4 -D__ARM_ARCH_7M__ -D__SES_ARM -D__HEAP_SIZE__=0 -D__SES_VERSION=53400 -D__SEGGER_LINKER -DDEBUG -DLPC175x_6x -D__LPC1700_FAMILY -D__LPC176x_SUBFAMILY -DARM_MATH_CM3 -MD /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/ring_buffer.d -MQ Output/Debug/Obj/OpenCanBoxFirmware/ring_buffer.o -quiet -std=gnu++11 -g3 -gpubnames -fomit-frame-pointer -fno-dwarf2-cfi-asm -fno-builtin -ffunction-sections -fdata-sections -fshort-enums -fno-common /Users/antonsizov/source/opencanbox-firmware/source/data/ring_buffer/ring_buffer.cpp -o /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/ring_buffer.asm
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/as" --traditional-format -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/ring_buffer.asm -o Output/Debug/Obj/OpenCanBoxFirmware/ring_buffer.o
	"/Applications/SEGGER Embedded Studio for ARM 5.34/bin/rm" /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/ring_buffer.asm

-include Output/Debug/Obj/OpenCanBoxFirmware/rx_table.d
Output/Debug/Obj/OpenCanBoxFirmware/rx_table.o:source/data/rx_table/rx_table.cpp
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/cc1plus" -fmessage-length=0 -fno-diagnostics-show-caret -fno-exceptions -fno-rtti -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb -mtp=soft -munaligned-access -nostdinc "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/segger-rtl/include" "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/include" -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include "-I/Users/antonsizov/Library/SEGGER/SEGGER Embedded Studio/v3/packages/CMSIS_5/CMSIS/Core/Include" -D__SIZEOF_WCHAR_T=4 -D__ARM_ARCH_7M__ -D__SES_ARM -D__HEAP_SIZE__=0 -D__SES_VERSION=53400 -D__SEGGER_LINKER -DDEBUG -DLPC175x_6x -D__LPC1700_FAMILY -D__LPC176x_SUBFAMILY -DARM_MATH_CM3 -MD /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/rx_table.d -MQ Output/Debug/Obj/OpenCanBoxFirmware/rx_table.o -quiet -std=gnu++11 -g3 -gpubnames -fomit-frame-pointer -fno-dwarf2-cfi-asm -fno-builtin -ffunction-sections -fdata-sections -fshort-enums -fno-common /Users/antonsizov/source/opencanbox-firmware/source/data/rx_table/rx_table.cpp -o /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/rx_table.asm
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/as" --traditional-format -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/rx_table.asm -o Output/Debug/Obj/OpenCanBoxFirmware/rx_table.o
	"/Applications/SEGGER Embedded Studio for ARM 5.34/bin/rm" /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/rx_table.asm

-include Output/Debug/Obj/OpenCanBoxFirmware/tx_table.d
Output/Debug/Obj/OpenCanBoxFirmware/tx_table.o:source/data/tx_table/tx_table.cpp
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/cc1plus" -fmessage-length=0 -fno-diagnostics-show-caret -fno-exceptions -fno-rtti -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb -mtp=soft -munaligned-access -nostdinc "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/segger-rtl/include" "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/include" -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include "-I/Users/antonsizov/Library/SEGGER/SEGGER Embedded Studio/v3/packages/CMSIS_5/CMSIS/Core/Include" -D__SIZEOF_WCHAR_T=4 -D__ARM_ARCH_7M__ -D__SES_ARM -D__HEAP_SIZE__=0 -D__SES_VERSION=53400 -D__SEGGER_LINKER -DDEBUG -DLPC175x_6x -D__LPC1700_FAMILY -D__LPC176x_SUBFAMILY -DARM_MATH_CM3 -MD /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/tx_table.d -MQ Output/Debug/Obj/OpenCanBoxFirmware/tx_table.o -quiet -std=gnu++11 -g3 -gpubnames -fomit-frame-pointer -fno-dwarf2-cfi-asm -fno-builtin -ffunction-sections -fdata-sections -fshort-enums -fno-common /Users/antonsizov/source/opencanbox-firmware/source/data/tx_table/tx_table.cpp -o /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/tx_table.asm
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/as" --traditional-format -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/tx_table.asm -o Output/Debug/Obj/OpenCanBoxFirmware/tx_table.o
	"/Applications/SEGGER Embedded Studio for ARM 5.34/bin/rm" /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/tx_table.asm

-include Output/Debug/Obj/OpenCanBoxFirmware/uart_protocol.d
Output/Debug/Obj/OpenCanBoxFirmware/uart_protocol.o:source/data/uart_protocol/uart_protocol.cpp
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/cc1plus" -fmessage-length=0 -fno-diagnostics-show-caret -fno-exceptions -fno-rtti -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb -mtp=soft -munaligned-access -nostdinc "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/segger-rtl/include" "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/include" -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include "-I/Users/antonsizov/Library/SEGGER/SEGGER Embedded Studio/v3/packages/CMSIS_5/CMSIS/Core/Include" -D__SIZEOF_WCHAR_T=4 -D__ARM_ARCH_7M__ -D__SES_ARM -D__HEAP_SIZE__=0 -D__SES_VERSION=53400 -D__SEGGER_LINKER -DDEBUG -DLPC175x_6x -D__LPC1700_FAMILY -D__LPC176x_SUBFAMILY -DARM_MATH_CM3 -MD /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/uart_protocol.d -MQ Output/Debug/Obj/OpenCanBoxFirmware/uart_protocol.o -quiet -std=gnu++11 -g3 -gpubnames -fomit-frame-pointer -fno-dwarf2-cfi-asm -fno-builtin -ffunction-sections -fdata-sections -fshort-enums -fno-common /Users/antonsizov/source/opencanbox-firmware/source/data/uart_protocol/uart_protocol.cpp -o /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/uart_protocol.asm
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/as" --traditional-format -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/uart_protocol.asm -o Output/Debug/Obj/OpenCanBoxFirmware/uart_protocol.o
	"/Applications/SEGGER Embedded Studio for ARM 5.34/bin/rm" /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/uart_protocol.asm

-include Output/Debug/Obj/OpenCanBoxFirmware/main.d
Output/Debug/Obj/OpenCanBoxFirmware/main.o:source/main.cpp
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/cc1plus" -fmessage-length=0 -fno-diagnostics-show-caret -fno-exceptions -fno-rtti -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb -mtp=soft -munaligned-access -nostdinc "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/segger-rtl/include" "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/include" -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include "-I/Users/antonsizov/Library/SEGGER/SEGGER Embedded Studio/v3/packages/CMSIS_5/CMSIS/Core/Include" -D__SIZEOF_WCHAR_T=4 -D__ARM_ARCH_7M__ -D__SES_ARM -D__HEAP_SIZE__=0 -D__SES_VERSION=53400 -D__SEGGER_LINKER -DDEBUG -DLPC175x_6x -D__LPC1700_FAMILY -D__LPC176x_SUBFAMILY -DARM_MATH_CM3 -MD /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/main.d -MQ Output/Debug/Obj/OpenCanBoxFirmware/main.o -quiet -std=gnu++11 -g3 -gpubnames -fomit-frame-pointer -fno-dwarf2-cfi-asm -fno-builtin -ffunction-sections -fdata-sections -fshort-enums -fno-common /Users/antonsizov/source/opencanbox-firmware/source/main.cpp -o /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/main.asm
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/as" --traditional-format -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/main.asm -o Output/Debug/Obj/OpenCanBoxFirmware/main.o
	"/Applications/SEGGER Embedded Studio for ARM 5.34/bin/rm" /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/main.asm

-include Output/Debug/Obj/OpenCanBoxFirmware/SEGGER_THUMB_Startup.d
Output/Debug/Obj/OpenCanBoxFirmware/SEGGER_THUMB_Startup.o:SEGGER_THUMB_Startup.s
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/cc1" -fmessage-length=0 -fno-diagnostics-show-caret -E -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb -nostdinc "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/segger-rtl/include" "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/include" -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include "-I/Users/antonsizov/Library/SEGGER/SEGGER Embedded Studio/v3/packages/CMSIS_5/CMSIS/Core/Include" -D__SIZEOF_WCHAR_T=4 -D__ARM_ARCH_7M__ -D__SES_ARM -D__HEAP_SIZE__=0 -D__SES_VERSION=53400 -D__SEGGER_LINKER -DDEBUG -DLPC175x_6x -D__LPC1700_FAMILY -D__LPC176x_SUBFAMILY -DARM_MATH_CM3 -MD /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/SEGGER_THUMB_Startup.d -MQ Output/Debug/Obj/OpenCanBoxFirmware/SEGGER_THUMB_Startup.o -quiet -lang-asm /Users/antonsizov/source/opencanbox-firmware/SEGGER_THUMB_Startup.s -o /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/SEGGER_THUMB_Startup_PP.s
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/as" --traditional-format -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/SEGGER_THUMB_Startup_PP.s -o Output/Debug/Obj/OpenCanBoxFirmware/SEGGER_THUMB_Startup.o -g -gdwarf-4
	"/Applications/SEGGER Embedded Studio for ARM 5.34/bin/rm" /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/SEGGER_THUMB_Startup_PP.s

-include Output/Debug/Obj/OpenCanBoxFirmware/LPC1700_Startup.d
Output/Debug/Obj/OpenCanBoxFirmware/LPC1700_Startup.o:LPC1700/Source/LPC1700_Startup.s
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/cc1" -fmessage-length=0 -fno-diagnostics-show-caret -E -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb -nostdinc "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/segger-rtl/include" "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/include" -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include "-I/Users/antonsizov/Library/SEGGER/SEGGER Embedded Studio/v3/packages/CMSIS_5/CMSIS/Core/Include" -D__SIZEOF_WCHAR_T=4 -D__ARM_ARCH_7M__ -D__SES_ARM -D__HEAP_SIZE__=0 -D__SES_VERSION=53400 -D__SEGGER_LINKER -DDEBUG -DLPC175x_6x -D__LPC1700_FAMILY -D__LPC176x_SUBFAMILY -DARM_MATH_CM3 -MD /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/LPC1700_Startup.d -MQ Output/Debug/Obj/OpenCanBoxFirmware/LPC1700_Startup.o -quiet -lang-asm /Users/antonsizov/source/opencanbox-firmware/LPC1700/Source/LPC1700_Startup.s -o /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/LPC1700_Startup_PP.s
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/as" --traditional-format -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/LPC1700_Startup_PP.s -o Output/Debug/Obj/OpenCanBoxFirmware/LPC1700_Startup.o -g -gdwarf-4
	"/Applications/SEGGER Embedded Studio for ARM 5.34/bin/rm" /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/LPC1700_Startup_PP.s

-include Output/Debug/Obj/OpenCanBoxFirmware/LPC176x5x_Vectors.d
Output/Debug/Obj/OpenCanBoxFirmware/LPC176x5x_Vectors.o:LPC1700/Source/LPC176x5x_Vectors.s
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/cc1" -fmessage-length=0 -fno-diagnostics-show-caret -E -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb -nostdinc "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/segger-rtl/include" "-isystem/Applications/SEGGER Embedded Studio for ARM 5.34/include" -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include "-I/Users/antonsizov/Library/SEGGER/SEGGER Embedded Studio/v3/packages/CMSIS_5/CMSIS/Core/Include" -D__SIZEOF_WCHAR_T=4 -D__ARM_ARCH_7M__ -D__SES_ARM -D__HEAP_SIZE__=0 -D__SES_VERSION=53400 -D__SEGGER_LINKER -DDEBUG -DLPC175x_6x -D__LPC1700_FAMILY -D__LPC176x_SUBFAMILY -DARM_MATH_CM3 -MD /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/LPC176x5x_Vectors.d -MQ Output/Debug/Obj/OpenCanBoxFirmware/LPC176x5x_Vectors.o -quiet -lang-asm /Users/antonsizov/source/opencanbox-firmware/LPC1700/Source/LPC176x5x_Vectors.s -o /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/LPC176x5x_Vectors_PP.s
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/as" --traditional-format -I/Users/antonsizov/source/opencanbox-firmware/LPC1700/CMSIS/Device/Include -mcpu=cortex-m3 -mlittle-endian -mfloat-abi=soft -mthumb /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/LPC176x5x_Vectors_PP.s -o Output/Debug/Obj/OpenCanBoxFirmware/LPC176x5x_Vectors.o -g -gdwarf-4
	"/Applications/SEGGER Embedded Studio for ARM 5.34/bin/rm" /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/LPC176x5x_Vectors_PP.s

Output/Debug/Exe/OpenCanBoxFirmware.elf:\
  Output/Debug/Obj/OpenCanBoxFirmware/system_LPC17xx.o\
  Output/Debug/Obj/OpenCanBoxFirmware/can.o\
  Output/Debug/Obj/OpenCanBoxFirmware/led.o\
  Output/Debug/Obj/OpenCanBoxFirmware/system_tick_timer.o\
  Output/Debug/Obj/OpenCanBoxFirmware/uart.o\
  Output/Debug/Obj/OpenCanBoxFirmware/watchdog_timer.o\
  Output/Debug/Obj/OpenCanBoxFirmware/crc8.o\
  Output/Debug/Obj/OpenCanBoxFirmware/md4.o\
  Output/Debug/Obj/OpenCanBoxFirmware/can_msg.o\
  Output/Debug/Obj/OpenCanBoxFirmware/ring_buffer.o\
  Output/Debug/Obj/OpenCanBoxFirmware/rx_table.o\
  Output/Debug/Obj/OpenCanBoxFirmware/tx_table.o\
  Output/Debug/Obj/OpenCanBoxFirmware/uart_protocol.o\
  Output/Debug/Obj/OpenCanBoxFirmware/main.o\
  Output/Debug/Obj/OpenCanBoxFirmware/SEGGER_THUMB_Startup.o\
  Output/Debug/Obj/OpenCanBoxFirmware/LPC1700_Startup.o\
  Output/Debug/Obj/OpenCanBoxFirmware/LPC176x5x_Vectors.o\
  /Users/antonsizov/source/opencanbox-firmware/LPC1700_Flash_Variant2.icf
	"/Applications/SEGGER Embedded Studio for ARM 5.34/bin/segger-ld" --add-region:FLASH1=0x00020000@0x00000000 --add-region:RAM1=0x00004000@0x10000000 --add-region:RAM2=0x00004000@0x2007c000 --defsym=__STACKSIZE__=2048 --defsym=__STACKSIZE_PROCESS__=0 --defsym=__HEAPSIZE__=0 --full-section-headers --merge-sections --merge-strings -eReset_Handler -EL -mcpu=7-M --defsym=__SEGGER_RTL_vfprintf=__SEGGER_RTL_vfprintf_int_nwp --defsym=__SEGGER_RTL_vfscanf=__SEGGER_RTL_vfscanf_int --defsym=getchar=getchar_rtt --defsym=putchar=putchar_rtt --defsym=gets=gets_rtt --defsym=puts=puts_rtt --defsym=printf=printf_rtt --defsym=scanf=scanf_rtt --defsym=vprintf=vprintf_rtt --defsym=vscanf=vscanf_rtt --silent --list-all-undefineds --fatal-warnings --gc-sections -T/Users/antonsizov/source/opencanbox-firmware/LPC1700_Flash_Variant2.icf --map-text --map-file=Output/Debug/Exe/OpenCanBoxFirmware.map --map-standard -u_vectors -o Output/Debug/Exe/OpenCanBoxFirmware.elf --emit-relocs --start-group @/Users/antonsizov/source/opencanbox-firmware/Output/Debug/Obj/OpenCanBoxFirmware/OpenCanBoxFirmware.ind --end-group
	"/Applications/SEGGER Embedded Studio for ARM 5.34/gcc/arm-none-eabi/bin/objcopy" Output/Debug/Exe/OpenCanBoxFirmware.elf /Users/antonsizov/source/opencanbox-firmware/Output/Debug/Exe/OpenCanBoxFirmware.bin -Obinary


tests: ring_buffer_test

ring_buffer_test:
	$(HOST_CXX) -lgtest -std=c++11 source/data/ring_buffer/ring_buffer.cpp tests/ring_buffer_test.cpp -o ring_buffer_test
	chmod +x ring_buffer_test
	./ring_buffer_test
	-rm ring_buffer_test
