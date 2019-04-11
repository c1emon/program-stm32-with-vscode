#include "Board.h"

void timer_init ( void );

/* Global variables */

#define SPEED 		(MCKKHz/10)
unsigned int LedSpeed = SPEED *50 ;
const int led_mask[8]= {LED1, LED2, LED3, LED4};

//*--------------------------------------------------------------------------------------
//* Function Name       : change_speed
//* Object              : Adjust "LedSpeed" value depending on SW1 and SW2 are pressed or not
//* Input Parameters    : none
//* Output Parameters   : Update of LedSpeed value.
//*--------------------------------------------------------------------------------------

void change_speed(void) {
  if ( (AT91F_PIO_GetInput(AT91C_BASE_PIOA) & SW1_MASK) == 0 ) {
    if ( LedSpeed > SPEED ) {
      LedSpeed -= SPEED ;
    }
  }
  if ( (AT91F_PIO_GetInput(AT91C_BASE_PIOA) & SW3_MASK) == 0 ) {
    if ( LedSpeed < MCK ) {
      LedSpeed += SPEED ;
    }
  }
}

//*--------------------------------------------------------------------------------------
//* Function Name       : wait
//* Object              : Software waiting loop
//* Input Parameters    : none. Waiting time is defined by the global variable LedSpeed.
//* Output Parameters   : none
//*--------------------------------------------------------------------------------------
void wait(void) {
    unsigned int waiting_time;
    change_speed();
    for(waiting_time = 0; waiting_time < LedSpeed; waiting_time++) ;
}

//*--------------------------------------------------------------------------------------
//* Function Name       : Main
//* Object              : Software entry point
//* Input Parameters    : none.
//* Output Parameters   : none.
//*--------------------------------------------------------------------------------------
int main() {
  int i;
  // First, enable the clock of the PIO
  AT91F_PMC_EnablePeriphClock ( AT91C_BASE_PMC, 1 << AT91C_ID_PIOA ) ;
	// then, we configure the PIO Lines corresponding to LED1 to LED4
	// to be outputs. No need to set these pins to be driven by the PIO because it is GPIO pins only.
	AT91F_PIO_CfgOutput( AT91C_BASE_PIOA, LED_MASK ) ;
	// Clear the LED's. On the EB55 we must apply a "1" to turn off LEDs
	AT91F_PIO_SetOutput( AT91C_BASE_PIOA, LED_MASK ) ;
	//* Init timer interrupt
	timer_init();
  // Loop forever
  for (;;) { // Once a Shot on each led
    for ( i=0 ; i < NB_LEB ; i++ ) {
      AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, led_mask[i]);
      wait();
      AT91F_PIO_SetOutput( AT91C_BASE_PIOA, led_mask[i] );
      wait();
    }
    // Once a Shot on each led
    for ( i = (NB_LEB - 1) ; i >= 0 ; i-- ) {
      AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, led_mask[i]);
      wait();
      AT91F_PIO_SetOutput( AT91C_BASE_PIOA, led_mask[i]);
      wait();
    }
  }
}
