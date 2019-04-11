//*----------------------------------------------------------------------------
//*      ATMEL Microcontroller Software Support  -  ROUSSET  -
//*----------------------------------------------------------------------------
//* The software is delivered "AS IS" without warranty or condition of any
//* kind, either express, implied or statutory. This includes without
//* limitation any warranty or condition with respect to merchantability or
//* fitness for any particular purpose, or against the infringements of
//* intellectual property rights of others.
//*----------------------------------------------------------------------------
//* File Name           : interrupt_timer.c
//* Object              : Timer interrupt management
//*                     : Use LED7 & LED8 for status interrupt
//*
//* 1.0 24/Jun/04 JPP   : Creation
//*----------------------------------------------------------------------------

// Include Standard LIB  files
#include "Board.h"

//* Global variable
int count_timer0_interrupt;
int count_timer1_interrupt;

#define TIMER0_INTERRUPT_LEVEL		1
#define TIMER1_INTERRUPT_LEVEL		4

/*-----------------*/
/* Clock Selection */
/*-----------------*/
#define TC_CLKS                  0x7
#define TC_CLKS_MCK2             0x0
#define TC_CLKS_MCK8             0x1
#define TC_CLKS_MCK32            0x2
#define TC_CLKS_MCK128           0x3
#define TC_CLKS_MCK1024          0x4

//*------------------------- Internal Function --------------------------------
//*----------------------------------------------------------------------------
//* Function Name       : AT91F_TC_Open
//* Object              : Initialize Timer Counter Channel and enable is clock
//* Input Parameters    : <tc_pt> = TC Channel Descriptor Pointer
//*                       <mode> = Timer Counter Mode
//*                     : <TimerId> = Timer peripheral ID definitions
//* Output Parameters   : None
//*----------------------------------------------------------------------------
void AT91F_TC_Open ( AT91PS_TC TC_pt, unsigned int Mode, unsigned int TimerId)
//* Begin
{
    unsigned int dummy;

    //* First, enable the clock of the TIMER
    	AT91F_PMC_EnablePeriphClock ( AT91C_BASE_PMC, 1<< TimerId ) ;

    //* Disable the clock and the interrupts
	TC_pt->TC_CCR = AT91C_TC_CLKDIS ;
	TC_pt->TC_IDR = 0xFFFFFFFF ;

    //* Clear status bit
        dummy = TC_pt->TC_SR;
    //* Suppress warning variable "dummy" was set but never used
        dummy = dummy;
    //* Set the Mode of the Timer Counter
	TC_pt->TC_CMR = Mode ;

    //* Enable the clock
	TC_pt->TC_CCR = AT91C_TC_CLKEN ;
//* End
}

//*------------------------- Interrupt Function -------------------------------

//*----------------------------------------------------------------------------
//* Function Name       : timer0_c_irq_handler
//* Object              : C handler interrupt function called by the interrupts
//*                       assembling routine
//* Output Parameters   : increment count_timer0_interrupt
//*----------------------------------------------------------------------------
void timer0_c_irq_handler(void)
{
	AT91PS_TC TC_pt = AT91C_BASE_TC0;
    unsigned int dummy;
    //* Acknowledge interrupt status
    dummy = TC_pt->TC_SR;
    //* Suppress warning variable "dummy" was set but never used
    dummy = dummy;
    count_timer0_interrupt++;
    //* Read the output state
    if ( (AT91F_PIO_GetInput(AT91C_BASE_PIOA) & LED3 ) == LED3 )
    {
        AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, LED3 );
    }
    else
    {
        AT91F_PIO_SetOutput( AT91C_BASE_PIOA, LED3 );
    }
}
//*----------------------------------------------------------------------------
//* Function Name       : timer1_c_irq_handler
//* Object              : C handler interrupt function called by the interrupts
//*                       assembling routine
//* Output Parameters   : increment count_timer1_interrupt
//*----------------------------------------------------------------------------
void timer1_c_irq_handler(void)
{
	AT91PS_TC TC_pt = AT91C_BASE_TC1;
    unsigned int dummy;
    //* Acknowledge interrupt status
    dummy = TC_pt->TC_SR;
    //* Suppress warning variable "dummy" was set but never used
    dummy = dummy;
    count_timer1_interrupt++;

    //* Read the output state
    if ( (AT91F_PIO_GetInput(AT91C_BASE_PIOA) & LED4 ) == LED4 )
    {
        AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, LED4 );
    }
    else
    {
        AT91F_PIO_SetOutput( AT91C_BASE_PIOA, LED4 );
    }
}
//*-------------------------- External Function -------------------------------

//*----------------------------------------------------------------------------
//* Function Name       : timer_init
//* Object              : Init timer counter
//* Input Parameters    : none
//* Output Parameters   : TRUE
//*----------------------------------------------------------------------------
void timer_init ( void )
//* Begin
{
    //init the timer interrupt counter
    count_timer0_interrupt=0;
    count_timer1_interrupt=0;

    //* Open timer0
	AT91F_TC_Open(AT91C_BASE_TC0,TC_CLKS_MCK1024,AT91C_ID_TC0);

    //* Open Timer 0 interrupt
	AT91F_AIC_ConfigureIt ( AT91C_BASE_AIC, AT91C_ID_TC0, TIMER0_INTERRUPT_LEVEL,AT91C_AIC_SRCTYPE_INT_LEVEL_SENSITIVE, timer0_c_irq_handler);
	AT91C_BASE_TC0->TC_IER = AT91C_TC_CPCS;  //  IRQ enable CPC
	AT91F_AIC_EnableIt (AT91C_BASE_AIC, AT91C_ID_TC0);

    //* Open timer1
	AT91F_TC_Open(AT91C_BASE_TC1,TC_CLKS_MCK128,AT91C_ID_TC1);

    //* Open Timer 1 interrupt
	AT91F_AIC_ConfigureIt ( AT91C_BASE_AIC, AT91C_ID_TC1, TIMER1_INTERRUPT_LEVEL,AT91C_AIC_SRCTYPE_INT_LEVEL_SENSITIVE, timer1_c_irq_handler);
	AT91C_BASE_TC1->TC_IER  = AT91C_TC_CPCS;  //  IRQ enable CPC
	AT91F_AIC_EnableIt (AT91C_BASE_AIC, AT91C_ID_TC1);


    //* Generate interrupt by software
 	AT91F_AIC_Trig (AT91C_BASE_AIC,AT91C_ID_TC0) ;
 	AT91F_AIC_Trig (AT91C_BASE_AIC,AT91C_ID_TC1) ;
    //* Start timer0
        AT91C_BASE_TC0->TC_CCR = AT91C_TC_SWTRG ;

    //* Start timer1
        AT91C_BASE_TC1->TC_CCR = AT91C_TC_SWTRG ;

//* End
}
