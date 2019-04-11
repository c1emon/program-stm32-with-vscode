/*********************************************************************
*              SEGGER MICROCONTROLLER SYSTEME GmbH                   *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996-2005 SEGGER Microcontroller Systeme GmbH           *
*                                                                    *
* Internet: www.segger.com Support: support@segger.com               *
*                                                                    *
**********************************************************************
----------------------------------------------------------------------
File    : STR71xF_Example.c
Purpose : Test / demonstration of J-Link with STR71xF
---------------------------END-OF-HEADER------------------------------
*/

#include <iostr710.h>
#include <inarm.h>

#define LED_12      (1UL << 11)
#define LED_13      (1UL << 12)
#define LED_14      (1UL << 13)
#define LED_15      (1UL << 14)
#define LED_MASK_P2 (LED_12 | LED_13 | LED_14 | LED_15)
#define TIMING      (0x1000)

/*********************************************************************
*
*       T1_INT_Handler
*/
__arm __irq void T1_INT_Handler( void ) {
  if (TIM1_SR_bit.OCFA && TIM1_CR2_bit.OCAIE) {
    TIM1_OCAR += TIMING;              /* set next compare time */
    TIM1_SR_bit.OCFA = 0;             /* clear flag */
    IOPORT2_PD ^= (LED_MASK_P2);      /* toggle led display */
  }
  EIC_IPR0 |= (1UL << T1_INT);
}

/*********************************************************************
*
*       main
*/
int main(void) {
  /* general preparations */
  EIC_ICR  = 0 ;
  EIC_FIR  = 0 ;
  EIC_IER0 = 0 ;                      /* reset all irqs */
  EIC_IPR0 = 0xFFFFFFFF ;

  /* start timer */
  TIM1_CR1 = 0;                       /* reset */
  TIM1_CR2 = 0x3F;                    /* prescaler */
  TIM1_CR1_bit.EN = 1;
  EIC_SIR19_bit.SIV = (unsigned long)T1_INT_Handler;
  EIC_SIR19_bit.SIPL = 1;             /* proi 1 */
  EIC_IER0 |= (1UL << T1_INT);

  /* prepare output */
  IOPORT2_PC0 |=  (LED_MASK_P2);      /* push pull output */
  IOPORT2_PC1 &= ~(LED_MASK_P2);
  IOPORT2_PC2 |=  (LED_MASK_P2);
  IOPORT2_PD  &= ~(LED_MASK_P2);      /* clear all */
  IOPORT2_PD  |=  (LED_13 | LED_14);  /* initial pattern */

  /* enable global interrupts */
  EIC_ICR_bit.IRQ_EN = 1;             /* enable irq line */
  __enable_interrupt();

  /* set the timeout compare interrupt */
  TIM1_OCAR = TIM1_CNTR + TIMING;
  TIM1_SR_bit.OCFA = 0;               /* clear flag */
  TIM1_CR2_bit.OCAIE = 1;             /* enable interrupt */

  while( 1 ) {
  }
}

/*************************** end of file ****************************/
