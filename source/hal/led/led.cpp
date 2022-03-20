#include "led.h"

Led::Led(Led::LED_INSTANCE instance) {
  this->instance = instance;
  switch (instance) {
    case LED_CAN1:
      bit_clear(pinConf->PINSEL7, 18u);
      bit_clear(pinConf->PINSEL7, 19u);
      bit_set(gpioConf3->FIODIR, 25u);
      controlValue = 1 << 25u;
      break;
    case LED_CAN1_ERROR:
      bit_clear(pinConf->PINSEL7, 20u);
      bit_clear(pinConf->PINSEL7, 21u);
      bit_set(gpioConf3->FIODIR, 26u);
      controlValue = 1 << 26u;
      break;
    case LED_CAN2:
      bit_clear(pinConf->PINSEL3, 4u);
      bit_clear(pinConf->PINSEL3, 5u);
      bit_set(gpioConf1->FIODIR, 18u);
      controlValue = 1u << 18;
      break;
    case LED_CAN2_ERROR:
      bit_clear(pinConf->PINSEL3, 6u);
      bit_clear(pinConf->PINSEL3, 7u);
      bit_set(gpioConf1->FIODIR, 19u);
      controlValue = 1u << 19;
      break;
    case LED_GC:
      bit_clear(pinConf->PINSEL3, 18u);
      bit_clear(pinConf->PINSEL3, 19u);
      bit_set(gpioConf1->FIODIR, 25u);
      controlValue = 1u << 25;
      break;
    default:
      break;
  }
}


void Led::turnOn() {
  if (instance == LED_GC || instance == LED_CAN2 || instance == LED_CAN2_ERROR) {
    gpioConf1->FIOCLR = controlValue;
  }
  else gpioConf3->FIOCLR = controlValue;
  status = true;
}

void Led::turnOff() {
  if (instance == LED_GC || instance == LED_CAN2 || instance == LED_CAN2_ERROR) {
    gpioConf1->FIOSET = controlValue;
  }
  else gpioConf3->FIOSET = controlValue;
  status = false;
}

void Led::toggle() {
  if (status) turnOff();
  else turnOn();
}

bool Led::isOn() {
  return status;
}