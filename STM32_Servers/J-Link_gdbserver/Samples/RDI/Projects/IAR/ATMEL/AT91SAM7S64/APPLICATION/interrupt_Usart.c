//*----------------------------------------------------------------------------
//*      ATMEL Microcontroller Software Support  -  ROUSSET  -
//*----------------------------------------------------------------------------
//* The software is delivered "AS IS" without warranty or condition of any
//* kind, either express, implied or statutory. This includes without
//* limitation any warranty or condition with respect to merchantability or
//* fitness for any particular purpose, or against the infringements of
//* intellectual property rights of others.
//*----------------------------------------------------------------------------
//* File Name           : interrupt_Usart.c
//* Object              : USART Interrupt Management
//*
//* 1.0 24/Jun/04 JPP   : Creation
//*----------------------------------------------------------------------------

// Include Standard LIB  files
#include "Board.h"


#define USART_INTERRUPT_LEVEL		7
#define AT91_BAUD_RATE				115200
static const char atmel_header[]=
{
"\n\r  *** ATMEL Usart IRQ ***\n\r"
"Copyright (C) 2002 ATMEL Corporations Version: 1.0\n\r"
};

//* \fn    AT91F_US_Baudrate
//* \brief Calculate the baudrate
//* Standard Asynchronous Mode : 8 bits , 1 stop , no parity
#define AT91C_US_ASYNC_MODE ( AT91C_US_USMODE_NORMAL + \
                        AT91C_US_NBSTOP_1_BIT + \
                        AT91C_US_PAR_NONE + \
                        AT91C_US_CHRL_8_BITS + \
                        AT91C_US_CLKS_CLOCK )

//*------------------------- Internal Function --------------------------------

//*----------------------------------------------------------------------------
//* Function Name       : Usart_c_irq_handler
//* Object              : C handler interrupt function called by the interrupts
//*                       assembling routine
//* Input Parameters    : <RTC_pt> time rtc descriptor
//* Output Parameters   : increment count_timer0_interrupt
//*----------------------------------------------------------------------------
void Usart_c_irq_handler(void)
{
	AT91PS_USART USART_pt = AT91C_BASE_US0;
	unsigned int status;
	//* get Usart status register
	status = USART_pt->US_CSR;
	if ( status & AT91C_US_RXRDY){
		//* Get byte and send
		AT91F_US_PutChar (USART_pt, AT91F_US_GetChar(USART_pt));
	}

	if ( status & AT91C_US_OVRE) {
		//* clear US_RXRDY
		 AT91F_US_GetChar(USART_pt);
		 AT91F_US_PutChar (USART_pt, 'O');
	}

	//* Check error
	if ( status & AT91C_US_PARE) {
		 AT91F_US_PutChar (USART_pt, 'P');
	}

	if ( status & AT91C_US_FRAME) {
		 AT91F_US_PutChar (USART_pt, 'F');
	}

	if ( status & AT91C_US_TIMEOUT){
		USART_pt->US_CR = AT91C_US_STTTO;
		 AT91F_US_PutChar (USART_pt, 'T');
	}

	//* Reset the satus bit
	 USART_pt->US_CR = AT91C_US_RSTSTA;
}
//*-------------------------- External Function -------------------------------

//*----------------------------------------------------------------------------
//* Function Name       : Usart_init
//* Object              : USART initialization
//* Input Parameters    : none
//* Output Parameters   : TRUE
//*----------------------------------------------------------------------------
void Usart_init ( void )
//* Begin
{
	AT91PS_USART COM0 = AT91C_BASE_US0;

 	//* Configure PIO controllers to periph mode
 	AT91F_PIO_CfgPeriph( AT91C_BASE_PIOA,
 		((unsigned int) AT91C_PA5_RXD0    ) |
 		((unsigned int) AT91C_PA6_TXD0    ) |
 		((unsigned int) AT91C_PA7_RTS0    ) |
 		((unsigned int) AT91C_PA8_CTS0    ), // Peripheral A
 		0); // Peripheral B


   	// First, enable the clock of the PIOB
    	AT91F_PMC_EnablePeriphClock ( AT91C_BASE_PMC, 1 << AT91C_ID_US0 ) ;
	// Usart Configure
      AT91F_US_Configure (COM0, MCK, AT91C_US_ASYNC_MODE, AT91_BAUD_RATE, 0);

	// Enable usart
	COM0->US_CR = AT91C_US_RXEN | AT91C_US_TXEN;

    //* Enable USART IT error and RXRDY
    	AT91F_US_EnableIt(COM0,AT91C_US_TIMEOUT | AT91C_US_FRAME | AT91C_US_OVRE |AT91C_US_RXRDY);

    	//* open Usart 1 interrupt
	AT91F_AIC_ConfigureIt ( AT91C_BASE_AIC, AT91C_ID_US0, USART_INTERRUPT_LEVEL,AT91C_AIC_SRCTYPE_INT_LEVEL_SENSITIVE, Usart_c_irq_handler);
	AT91F_AIC_EnableIt (AT91C_BASE_AIC, AT91C_ID_US0);

	AT91F_US_PutChar (COM0,'X');

 	AT91F_US_SendFrame(COM0,(char *)atmel_header,sizeof(atmel_header),0,0);


//* End
}
