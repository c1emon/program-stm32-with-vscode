/******************************************************************************/
/*  This file is part of the uVision/ARM development tools                    */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2004                                  */
/******************************************************************************/
/*                                                                            */
/*  BLINKY.C:  LED Flasher                                                    */
/*                                                                            */
/******************************************************************************/
                  
#include <AT91SAM7S64.H>                       /* AT91SAMT7S64 definitions  */
#include <lib_AT91SAM7S64.h>
#include "Board.h"

#define SPEED (MCKKHz/10)

const int led_mask[] = { LED1, LED2, LED3, LED4 };

unsigned int LEDSpeed = 50*SPEED;


/* 
 * Change Speed depending on SW1 and SW2
 */

void change_speed (void) {
  if ((AT91F_PIO_GetInput(AT91C_BASE_PIOA) & SW1_MASK) == 0) {
    if (LEDSpeed > SPEED) LEDSpeed -= SPEED;
  }
  if ((AT91F_PIO_GetInput(AT91C_BASE_PIOA) & SW2_MASK) == 0) {
    if (LEDSpeed < MCK)   LEDSpeed += SPEED;
  }
}


/*
 * Wait Function (SW Waiting Loop)
 *   Waiting Time defined by global variable LEDSpeed
 */
 
void wait (void) {
  unsigned int n;

  change_speed();
  for (n = 0; n < LEDSpeed; n++);
}
  

/*
 * Main Program
 */

int main (void) {
  int i;

  // Enable the Clock of the PIO
  AT91F_PMC_EnablePeriphClock(AT91C_BASE_PMC, 1 << AT91C_ID_PIOA);

  // Configure the PIO Lines corresponding to LED1..LED4 as Outputs
  AT91F_PIO_CfgOutput(AT91C_BASE_PIOA, LED_MASK);

  // Clear the LED's. On the Board we must apply a "1" to turn off LEDs
  AT91F_PIO_SetOutput(AT91C_BASE_PIOA, LED_MASK);

  // Loop forever
  for (;;) {
    for (i = 0; i < NB_LED; i++) {
	  AT91F_PIO_ClearOutput(AT91C_BASE_PIOA, led_mask[i]);
	  wait();
	  AT91F_PIO_SetOutput  (AT91C_BASE_PIOA, led_mask[i]);
	  wait();
    }
    for (i = (NB_LED - 1); i >= 0; i--) {
	  AT91F_PIO_ClearOutput(AT91C_BASE_PIOA, led_mask[i]);
	  wait();
	  AT91F_PIO_SetOutput  (AT91C_BASE_PIOA, led_mask[i]);
	  wait();
    }
  }
}
