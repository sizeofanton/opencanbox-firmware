#pragma  once
#include "LPC17xx.h"
#include "../../util/bit_operations.h"
#include "../../data/can_msg/can_msg.h"
#include "can_bitrate.h"

class Can {
  public:
    enum CanInstance {
        Can1,
        Can2
    };

    enum CanAcceptanceMode {
      OffMode,
      BypassMode,
      OperatingMode
    };

    struct CanInterrupt {
      uint8_t ReceiveInterrupt: 1;
      uint8_t Transmit1Interrupt: 1;
      uint8_t ErrorWarningInterrupt: 1;
      uint8_t DataOverrunInterrupt: 1;
      uint8_t WakeupInterrupt: 1;
      uint8_t ErrorPassiveInterrupt: 1;
      uint8_t ArbitrationLostInterrupt: 1;
      uint8_t BusErrorInterrupt: 1;
      uint8_t IdReadyInterrupt: 1;
      uint8_t Transmit2Interrupt: 1;
      uint8_t Transmit3Interrupt: 1;
    };

  public:
      Can(CanInstance instance, BaudRate baud);
      uint8_t       canSend(CanMsg msg);
      CanMsg        canRead();
      void          setBaudRate(BaudRate baudRate);
      void          changeBaudRate(BaudRate baudRate);
      bool          canMsgAvailable();
      void          setEnabledInterrupts(CanInterrupt enInt);
      CanInterrupt  getInterruptSource();
      void          setAcceptanceMode(CanAcceptanceMode mode);
      void          setFilterSf(uint32_t *idBuffer, uint32_t len);
      void          setFilterRangeSf(uint32_t idStart, uint32_t idStop);

   private: 
      LPC_SC_TypeDef      *systemControl  = (LPC_SC_TypeDef *) LPC_SC;
      LPC_PINCON_TypeDef  *pinCon         = (LPC_PINCON_TypeDef *) LPC_PINCON;
      LPC_CANCR_TypeDef   *canCentral     = (LPC_CANCR_TypeDef *) LPC_CANCR;
      LPC_CAN_TypeDef     *can            = (LPC_CAN_TypeDef *) LPC_CAN1;
      LPC_CANAF_TypeDef   *canAcf         = (LPC_CANAF_TypeDef *) LPC_CANAF;
      uint32_t            *ISER           = (uint32_t *) 0xE000E100;

      uint8_t channel = 0;
      
      const char ISE_CAN          = 25u;
      const char AFMR_OFF_MODE    = 0u;
      const char AFMR_BYMASS_MODE = 1u;

      const char RX_INTERRUPT_BIT               = 0u;
      const char TX_INTERRUPT_BIT               = 1u;
      const char ERROR_WARNING_INTERRUPT_BIT    = 2u;
      const char DATA_OVERRUN_INTERRUPT_BIT     = 3u;
      const char WAKEUP_INTERRUPT_BIT           = 4u;
      const char ERROR_PASSIVE_INTERRUPT_BIT    = 5u;
      const char ARBITRATION_LOST_INTERRUPT_BIT = 6u;
      const char BUS_ERROR_INTERRUPT_BIT        = 7u;
      const char ID_READY_INTERRUPT_BIT         = 8u;
      const char TX2_INTERRUPT_BIT              = 9u;
      const char TX3_INTERRUPT_BIT              = 10u;

  private:
      inline void releaseRxBuffer();
      inline bool canTxBuf1Available();
      inline bool canTxBuf2Available();
      inline bool canTxBuf3Available();

      

    
};