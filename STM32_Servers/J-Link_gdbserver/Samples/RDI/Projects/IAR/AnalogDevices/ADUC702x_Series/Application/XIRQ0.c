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
File    : XIRQ.c
Purpose : Test / demonstration of J-Link with ADuC
---------------------------END-OF-HEADER------------------------------
*/

#include "ioaduc7024.h"

/*********************************************************************
*
*       Delay
*/
void Delay (volatile int length) {
  while (length >=0) {
    length--;
  }
}

/*********************************************************************
*
*       irq_handler
*  Function description
*    Called whenever the IRQ-pin (key on eval board) is pressed
*/
__irq __arm void irq_handler(void) {
  GP4DAT &= ~0x00ff0000;	   		// 	Switch LED on
	while(GP0DAT & 0x00010){}			//      wait for XIRQ to be low again
  GP4DAT |= 0x00ff0000;	   		// 	Switch LED off
}

/*********************************************************************
*
*       main
*/
int main (void) {
	IRQEN = XIRQ0_BIT;				//	Enable XIRQ0 in IRQEnable
	GP0CON = 0x00;
	GP4DAT = 0x04000000;				//	Configure P4.2 as output
	GP3DAT = 0xff000000;				//	Configure port 3 as output

	while(1){
		GP4DAT ^= 0x00ff0000;	   		// 	Toggle LED
		Delay(40000);				//	Delay to make blink visible
	}
}

/*************************** end of file ****************************/



