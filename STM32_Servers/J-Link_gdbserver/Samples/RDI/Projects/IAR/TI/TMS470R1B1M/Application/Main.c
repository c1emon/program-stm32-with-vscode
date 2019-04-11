
#include <intrinsic.h>
#include "iotms470r1b1m.h"
#include "tms470r1b1m_bit_definitions.h"

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

static int* _pLEDs;

/*********************************************************************
*
*       Static const data
*
**********************************************************************
*/

//
// LEDs moving pattern codes.
//
static int _aLEDs[] = {
  0x1818, 0x3C3C, 0x7E7E, 0xFFFF, 0xE7E7, 0xC3C3, 0x8181, 0x4242, 0x2424, -1
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/
/*********************************************************************
*
*       _SetLED
*/
static void _SetLED(unsigned Mask) {
  GIODOUTE = Mask  & 0xFF;
  HETDOUT  = (Mask & 0xFF00) >> 8;
}

/*********************************************************************
*
*       COMP1_irq_handler
*/
static void COMP1_irq_handler() {
  RTICINT &= ~CMP1FLAG;   // interrupt control, clear CMP1
  if (*_pLEDs == -1) {
    _pLEDs = _aLEDs;
  }
  _SetLED(*_pLEDs);
  _pLEDs++;
}

/*********************************************************************
*
*       irq_handler
*/
__irq __arm void irq_handler(void) {
  if (((0xff & IRQIVEC) - 1) == CIM_COMP1) {
    COMP1_irq_handler();
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       main
*/
void main(void) {
  __disable_interrupt();
  _pLEDs    = _aLEDs;
  PCR       = CLKDIV_4;                   // ICLK = SYSCLK/4
  PCR      |= PENABLE;                    // enable peripherals
  GCR       = ZPLL_CLK_DIV_PRE_1;         // SYSCLK = 8 x fOSC
  REQMASK   = (1 << CIM_COMP1);           // Enable SPI Interrupt mask
  RTICNTEN  = CNTEN_NOCNT;                // Stop counting
  RTICNTR   = 0x00;                       // clear 21-bits CNTR
  RTIPCTL   = 0x3;                        // preload 11-bits MOD
  RTICMP1   = 0xfffff;
  RTICNTL   = 0x00;                       // clear and disable tap
  RTICINT   = 0x00;
  RTICINT  |= CMP1ENA;
  RTICNTEN  = CNTEN_UP;
  HETDIR    = 0xff;                       // Set HET as GIO outputs
  HETDOUT   = 0xff;                       // Output on
  HETDOUT   = 0x00;                       // Output off
  HETDOUT   = 0xff;                       // Output on
  GIODIRE   = 0xff;                       // Set GIO outputs
  GIODOUTE  = 0xff;                       // Output on
   __enable_interrupt();                  // Enable Interrupts
  while (1);
}

/************************** End Of File *****************************/
