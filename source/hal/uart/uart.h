#pragma  once
#include "LPC17xx.h"
#include "../../util/bit_operations.h"
#include <stdint.h>
#include "../abstract/abstract_uart.h"

#define SBIT_WORD_LENGTH  0x00u
#define SBIT_DLAB         0x07u
#define SBIT_FIFO         0x00u
#define SBIT_RX_FIFO      0x01u
#define SBIT_TX_FIFO      0x02u

#define SBIT_RDR          0x00u
#define SBIT_THRE         0x05u

#define RBR_INT_EN_BIT    0x00u
#define NVIC_INT_EN_BIT   0x05u

class Uart: AbstractUart {
  public:
    Uart(uint32_t baudrate);
    void uartTx(char byte);
    void uartTx(uint8_t *bytes, uint32_t lenght); 
    char uartRx();
    bool byteAvailable();

  private:
    LPC_PINCON_TypeDef  *lpcPincon  = (LPC_PINCON_TypeDef*) LPC_PINCON;
    LPC_UART_TypeDef    *lpcUart0   = (LPC_UART_TypeDef*) LPC_UART0; 
    LPC_SC_TypeDef      *lpcSc      = (LPC_SC_TypeDef*) LPC_SC;
    uint32_t            *ISER       = (uint32_t *) 0xE000E100;
};