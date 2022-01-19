#include "uart.h"

Uart::Uart(uint32_t baudrate) {
  uint32_t _uart_pclk_u32, _pclk_u32, _reg_value_u32;
  
  lpcPincon->PINSEL0 |= 0x00000050;
  lpcUart0->FCR = (1 << SBIT_FIFO) | (1 << SBIT_RX_FIFO) | (1 << SBIT_TX_FIFO);  // Enable FIFO and reset Rx/Tx FIFO buffers
  lpcUart0->LCR = (0x03 << SBIT_WORD_LENGTH) | (1 << SBIT_DLAB);                 // 8 bit data, 1 stop bit, no parity

 /** Baud Rate Calculation :
       PCLKSELx registers contains the PCLK info for all the clock dependent peripherals.
       Bit6,Bit7 contains the Uart Clock(ie.UART_PCLK) information.
       The UART_PCLK and the actual Peripheral Clock(PCLK) is calculated as below.
       (Refer data sheet for more info)
       UART_PCLK    PCLK
         0x00       SystemFreq/4        
         0x01       SystemFreq
         0x02       SystemFreq/2
         0x03       SystemFreq/8   
   **/

   _uart_pclk_u32 = (lpcSc->PCLKSEL0 >> 6) & 0x03;

   switch (_uart_pclk_u32) 
   {
    case 0x00:
      _pclk_u32 = SystemCoreClock / 4;
      break;
    case 0x01:
      _pclk_u32 = SystemCoreClock;
      break;
    case 0x02:
      _pclk_u32 = SystemCoreClock / 2;
      break;
    case 0x03:
      _pclk_u32 = SystemCoreClock / 8;
      break;
    default:
      _pclk_u32 = SystemCoreClock / 4;
      break;
   }

  _reg_value_u32 = (_pclk_u32 / (16 * baudrate));
  lpcUart0->DLL = _reg_value_u32 & 0xFF;
  lpcUart0->DLM = (_reg_value_u32 >> 0x08) & 0xFF;

  bit_clear(lpcUart0->LCR, (SBIT_DLAB)); // Clear DLAB after setting DLL, DLM

  bit_set(lpcUart0->IER, RBR_INT_EN_BIT);
  bit_set(*ISER, NVIC_INT_EN_BIT);
}

void Uart::uartTx(char byte) {
  while (is_bit_cleared(lpcUart0->LSR, SBIT_THRE));
  lpcUart0->THR = byte;
}

void Uart::uartTx(uint8_t *bytes, uint32_t lenght) {
  while (lenght) {
    while (is_bit_cleared(lpcUart0->LSR, SBIT_THRE));
    lpcUart0->THR = *bytes;
    lenght--;
    bytes++;
  }
}

char Uart::uartRx() {
  char byte;
  //while (is_bit_set(lpcUart0->LSR, SBIT_RDR));
  byte = lpcUart0->RBR;
  return byte;
}

bool Uart::byteAvailable() {
  return lpcUart0->LSR & 0x01 ? true : false; 
}