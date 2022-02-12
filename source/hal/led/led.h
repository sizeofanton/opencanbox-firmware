#pragma once
#include "../../util/bit_operations.h"
#include "LPC17xx.h"
#include "../../config.h"

class Led {

  private:
    bool status = false;
    #ifdef OPEN_CAN_BOX_0
    LPC_PINCON_TypeDef *pinConf = (LPC_PINCON_TypeDef*) LPC_PINCON;
    LPC_GPIO_TypeDef *gpioConf = (LPC_GPIO_TypeDef*) LPC_GPIO0;
    unsigned int controlValue = 0x200;
    #endif

    #ifdef OPEN_CAN_BOX_1
    LPC_PINCON_TypeDef *pinConf = (LPC_PINCON_TypeDef*) LPC_PINCON;
    LPC_GPIO_TypeDef *gpioConf1 = (LPC_GPIO_TypeDef*) LPC_GPIO1;
    LPC_GPIO_TypeDef *gpioConf3 = (LPC_GPIO_TypeDef*) LPC_GPIO3;
    unsigned int controlValue = 0;
    #endif

    #ifdef OPEN_CAN_BOX_2
    LPC_PINCON_TypeDef *pinConf = (LPC_PINCON_TypeDef*) LPC_PINCON;
    LPC_GPIO_TypeDef *gpioConf1 = (LPC_GPIO_TypeDef*) LPC_GPIO1;
    LPC_GPIO_TypeDef *gpioConf3 = (LPC_GPIO_TypeDef*) LPC_GPIO3;
    unsigned int controlValue = 0;
    #endif

    #ifdef OPEN_CAN_BOX_8CH
    LPC_PINCON_TypeDef *pinConf = (LPC_PINCON_TypeDef*) LPC_PINCON;
    LPC_GPIO_TypeDef *gpioConf1 = (LPC_GPIO_TypeDef*) LPC_GPIO1;
    LPC_GPIO_TypeDef *gpioConf3 = (LPC_GPIO_TypeDef*) LPC_GPIO3;
    unsigned int controlValue = 0;
    #endif


  public:

    enum LED_INSTANCE {
      LED_CAN1,
      LED_CAN1_ERROR,
      LED_CAN2,
      LED_CAN2_ERROR,
      LED_GC
    };
    
    Led(LED_INSTANCE instance);
    LED_INSTANCE instance;
    void turnOff();
    void turnOn();
    void toggle();
    bool isOn();

};