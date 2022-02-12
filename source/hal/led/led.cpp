#include "led.h"

Led::Led(Led::LED_INSTANCE instance) {
  this->instance = instance;
  switch (instance) {

    case LED_CAN1:
      #ifdef OPEN_CAN_BOX_0
      bit_set(pinConf->PINSEL2, 2);
      bit_set(pinConf->PINSEL2, 3);
      bit_set(gpioConf->FIODIR, 9);
      controlValue = 0x200;
      #endif
      #ifdef OPEN_CAN_BOX_1
      bit_clear(pinConf->PINSEL7, 18u);
      bit_clear(pinConf->PINSEL7, 19u);
      bit_set(gpioConf3->FIODIR, 25u);
      controlValue = 1 << 25u;
      #endif
      #ifdef OPEN_CAN_BOX_2
      bit_clear(pinConf->PINSEL7, 18u);
      bit_clear(pinConf->PINSEL7, 19u);
      bit_set(gpioConf3->FIODIR, 25u);
      controlValue = 1 << 25u;
      #endif
      #ifdef OPEN_CAN_BOX_8CH
      bit_clear(pinConf->PINSEL7, 18u);
      bit_clear(pinConf->PINSEL7, 19u);
      bit_set(gpioConf3->FIODIR, 25u);
      controlValue = 1 << 25u;
      #endif
      break;


    case LED_CAN1_ERROR:
      #ifdef OPEN_CAN_BOX_0
      bit_set(pinConf->PINSEL1, 4);
      bit_set(pinConf->PINSEL1, 5);
      bit_set(gpioConf->FIODIR, 10);
      controlValue = 0x400;
      #endif
      #ifdef OPEN_CAN_BOX_1
      bit_clear(pinConf->PINSEL7, 20u);
      bit_clear(pinConf->PINSEL7, 21u);
      bit_set(gpioConf3->FIODIR, 26u);
      controlValue = 1 << 26u;
      #endif
      #ifdef OPEN_CAN_BOX_2
      bit_clear(pinConf->PINSEL7, 20u);
      bit_clear(pinConf->PINSEL7, 21u);
      bit_set(gpioConf3->FIODIR, 26u);
      controlValue = 1 << 26u;
      #endif
      #ifdef OPEN_CAN_BOX_8CH
      bit_clear(pinConf->PINSEL7, 20u);
      bit_clear(pinConf->PINSEL7, 21u);
      bit_set(gpioConf3->FIODIR, 26u);
      controlValue = 1 << 26u;
      #endif
      break;


    case LED_CAN2:
      #ifdef OPEN_CAN_BOX_0
      bit_set(pinConf->PINSEL1, 1);
      bit_set(pinConf->PINSEL1, 2);
      bit_set(gpioConf->FIODIR, 8);
      controlValue = 0x100;
      #endif
      #ifdef OPEN_CAN_BOX_1
      bit_clear(pinConf->PINSEL3, 4u);
      bit_clear(pinConf->PINSEL3, 5u);
      bit_set(gpioConf1->FIODIR, 18u);
      controlValue = 1u << 18;
      #endif
      #ifdef OPEN_CAN_BOX_2
      bit_clear(pinConf->PINSEL3, 0u);
      bit_clear(pinConf->PINSEL2, 1u);
      bit_set(gpioConf1->FIODIR, 16u);
      controlValue = 1u << 16;
      #endif
      #ifdef OPEN_CAN_BOX_8CH
      bit_clear(pinConf->PINSEL3, 4u);
      bit_clear(pinConf->PINSEL3, 5u);
      bit_set(gpioConf1->FIODIR, 18u);
      controlValue = 1u << 18;
      #endif
      break;


    case LED_CAN2_ERROR:
      #ifdef OPEN_CAN_BOX_0
      bit_set(pinConf->PINSEL1, 6);
      bit_set(pinConf->PINSEL1, 7);
      bit_set(gpioConf->FIODIR, 11);
      controlValue = 0x800;
      #endif
      #ifdef OPEN_CAN_BOX_1
      bit_clear(pinConf->PINSEL3, 6u);
      bit_clear(pinConf->PINSEL3, 7u);
      bit_set(gpioConf1->FIODIR, 19u);
      controlValue = 1u << 19;
      #endif
      #ifdef OPEN_CAN_BOX_2
      bit_clear(pinConf->PINSEL2, 30u);
      bit_clear(pinConf->PINSEL2, 31u);
      bit_set(gpioConf1->FIODIR, 15u);
      controlValue = 1u << 15;
      #endif 
      #ifdef OPEN_CAN_BOX_8CH
      bit_clear(pinConf->PINSEL3, 6u);
      bit_clear(pinConf->PINSEL3, 7u);
      bit_set(gpioConf1->FIODIR, 19u);
      controlValue = 1u << 19;
      #endif
      break;


    case LED_GC:
      #ifdef OPEN_CAN_BOX_0
      bit_set(pinConf->PINSEL1, 6);
      bit_set(pinConf->PINSEL1, 7);
      bit_set(gpioConf->FIODIR, 7);
      controlValue = 0x80;
      #endif
      #ifdef OPEN_CAN_BOX_1
      bit_clear(pinConf->PINSEL3, 18u);
      bit_clear(pinConf->PINSEL3, 19u);
      bit_set(gpioConf1->FIODIR, 25u);
      controlValue = 1u << 25;
      #endif
      #ifdef OPEN_CAN_BOX_2
      bit_clear(pinConf->PINSEL2, 28u);
      bit_clear(pinConf->PINSEL2, 29u);
      bit_set(gpioConf1->FIODIR, 14u);
      controlValue = 1u << 14;
      #endif
      #ifdef OPEN_CAN_BOX_8CH
      bit_clear(pinConf->PINSEL3, 18u);
      bit_clear(pinConf->PINSEL3, 19u);
      bit_set(gpioConf1->FIODIR, 25u);
      controlValue = 1u << 25;
      #endif
      break;
      


    default:
      break;
  }
}


void Led::turnOn() {

  #ifdef  OPEN_CAN_BOX_0
  gpioConf->FIOCLR = controlValue;
  #endif


  #ifdef  OPEN_CAN_BOX_1
  if (instance == LED_GC || instance == LED_CAN2 || instance == LED_CAN2_ERROR) {
    gpioConf1->FIOCLR = controlValue;
  }
  else gpioConf3->FIOCLR = controlValue;
  #endif


  #ifdef OPEN_CAN_BOX_2
  if (instance == LED_GC) {
    gpioConf1->FIOCLR = controlValue;
  }
  if (instance == LED_CAN1) {
    gpioConf3->FIOSET = 1u << 25;
    gpioConf3->FIOCLR = 1u << 26;
  }
  if (instance == LED_CAN2) {
    gpioConf1->FIOCLR = 1u << 15;
    gpioConf1->FIOSET = 1u << 16;
  }
  if (instance == LED_CAN1_ERROR) {
    gpioConf3->FIOSET = 1u << 26;
    gpioConf3->FIOCLR = 1u << 25;
  }
  if (instance == LED_CAN2_ERROR) {
    gpioConf1->FIOCLR = 1u << 16;
    gpioConf1->FIOSET = 1u << 15;
  }
  #endif
  #ifdef OPEN_CAN_BOX_8CH
  if (instance == LED_GC) {
    gpioConf1->FIOCLR = controlValue;
  }
  if (instance == LED_CAN1) {
    gpioConf3->FIOCLR = 1u << 25;
    gpioConf3->FIOSET = 1u << 26;
  }
  if (instance == LED_CAN2) {
    gpioConf1->FIOCLR = 1u << 18;
    gpioConf1->FIOSET = 1u << 19;
  }
  if (instance == LED_CAN1_ERROR) {
    gpioConf3->FIOCLR = 1u << 26;
    gpioConf3->FIOSET = 1u << 25;
  }
  if (instance == LED_CAN2_ERROR) {
    gpioConf1->FIOCLR = 1u << 19;
    gpioConf1->FIOSET = 1u << 18;
  }
  #endif
  status = true;
}

void Led::turnOff() {

  #ifdef  OPEN_CAN_BOX_0
  gpioConf->FIOSET = controlValue;
  #endif


  #ifdef OPEN_CAN_BOX_1
  if (instance == LED_GC || instance == LED_CAN2 || instance == LED_CAN2_ERROR) {
    gpioConf1->FIOSET = controlValue;
  }
  else gpioConf3->FIOSET = controlValue;
  #endif 


  #ifdef OPEN_CAN_BOX_2
  if (instance == LED_GC) {
    gpioConf1->FIOSET = controlValue;
  }
  if (instance == LED_CAN1) {
    gpioConf3->FIOCLR = 1u << 25;
  }
  if (instance == LED_CAN1_ERROR) {
    gpioConf3->FIOCLR = 1u << 26;
  }
  if (instance == LED_CAN2) {
    gpioConf1->FIOCLR = 1u << 16;
  }
  if (instance == LED_CAN2_ERROR) {
    gpioConf1->FIOCLR = 1u << 15;
  }
  #endif

  #ifdef OPEN_CAN_BOX_8CH
  if (instance == LED_GC) {
    gpioConf1->FIOSET = controlValue;
  }
  if (instance == LED_CAN1) {
    gpioConf3->FIOSET = 1u << 26;
    gpioConf3->FIOSET = 1u << 25;
  }
  if (instance == LED_CAN2) {
    gpioConf1->FIOSET = 1u << 18;
    gpioConf1->FIOSET = 1u << 19;
  }
  if (instance == LED_CAN1_ERROR) {
    gpioConf3->FIOSET = 1u << 25;
    gpioConf3->FIOSET = 1u << 26;
  }
  if (instance == LED_CAN2_ERROR) {
    gpioConf1->FIOSET = 1u << 19;
    gpioConf1->FIOSET = 1u << 18;
  }
  #endif

  status = false;
}

void Led::toggle() {
  if (status) turnOff();
  else turnOn();
}

bool Led::isOn() {
  return status;
}