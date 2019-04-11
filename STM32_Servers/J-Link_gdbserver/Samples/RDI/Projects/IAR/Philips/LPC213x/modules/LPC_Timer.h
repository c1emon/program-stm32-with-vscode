#ifndef __LPC_TIMER_H
#define __LPC_TIMER_H

/*************************************************************************
 *
 *    Used with ICCARM and AARM.
 *
 *    (c) Copyright IAR Systems 2003
 *
 *    File name   : LPC_Timer.h
 *    Description : 
 *
 *    History :
 *    1. Date: July 08, 2004                                              
 *       Author: Wilson Liu                                                    
 *       Description: Create the basic function    
 *
 *    2. Date: August 12, 2004                                              
 *       Author: Shawn Zhang                                                 
 *       Description: Re-write some API interface
 *
 *    3. Data        : Oct 10, 2004 
 *       Author      : Stanimir Bonev
 *       Description : Modify some function and interface  
 *
 *    $Revision: 1.1 $
 **************************************************************************/

#include <includes.h>

/* Timer Control register bit descriptions */
#define TCR_ENABLE_BIT  0
#define TCR_RESET_BIT   1

// The channel name which is used in matching, in fact they represent 
// corresponding Match Register 
#define CH_MAXNUM       4
#define CH0             0
#define CH1             1
#define CH2             2
#define CH3             3

// The channel name which is used in capturing, in fact they represent 
// corresponding Capture Register 
#define CPCH_MAXNUM     4
#define CPCH0           0
#define CPCH1           1
#define CPCH2           2
#define CPCH3           3

//The actions when matching
#define TimerAction_Interrupt   0x1
#define TimerAction_ResetTimer  0x2
#define TimerAction_StopTimer   0x4

//Interrupt source type
#define TIMERMR0Int     0x01
#define TIMERMR1Int     0x02
#define TIMERMR2Int     0x04
#define TIMERMR3Int     0x08
#define TIMERCR0Int     0x10
#define TIMERCR1Int     0x20
#define TIMERCR2Int     0x40
#define TIMERCR3Int     0x80

#define TIMERALLInt     0xFF

// TIMER Chanel def
typedef enum {
  TIMER0 = 0,
  TIMER1
} LPC_TimerChanel_t;

// External Match Control Action Type
typedef enum {
    DONOTHING = 0,
    SETTOLOW,
    SETTOHIGH,
    TOGGLE
} LPC_Timer_ExtAction_t;

// Capture Control Action Type
typedef enum {
  TimerCPTrigger_Rising	= 1,
  TimerCPTrigger_Falling
} LPC_Timer_CapureAction_t;

typedef struct {
	bool Enable;			
	unsigned char Action;
	unsigned long TimeValue;
	void (* Fnpr)(void *);
	void * FnprArg;
} LPC_Timer_MatchChannel_t;

typedef struct {
	bool Enable;			
	unsigned char TriggerType;
	bool EnableInt;
	void (* Fnpr)(void *);
	void * FnprArg;

	long CPValue;
} LPC_Timer_CaptureChannel_t;

typedef struct {
	unsigned long Precision;
	unsigned long Prescaler;
	LPC_Timer_MatchChannel_t MatchCH[CH_MAXNUM];
	LPC_Timer_CaptureChannel_t CaptureCH[CPCH_MAXNUM];

	LPC_Timer_ExtAction_t ExtAction[CH_MAXNUM];
	unsigned char ExtBitValue[CH_MAXNUM];		    // low or high, only 1 bit
} LPC_Timer_Config_t;


/* Declare functions */
int TIMER_Init(LPC_TimerChanel_t DevNum, unsigned long precision);
int TIMER_Reset(LPC_TimerChanel_t DevNum);
int TIMER_Start(LPC_TimerChanel_t DevNum);
int TIMER_Stop(LPC_TimerChanel_t DevNum);

int TIMER_SetMatchAction(LPC_TimerChanel_t DevNum, 
                          unsigned int CHNum, 
                          unsigned int action , 
                          unsigned long TimeValue,
                          void (* Fnpr)(void *),
                          void * FnprArg,
                          LPC_Timer_ExtAction_t ExtAction);

int TIMER_GetTimerMatch(LPC_TimerChanel_t DevNum, unsigned int MRNum,
	          unsigned int * pAction , unsigned int * pMatchValue);

int TIMER_GetTimerExternalMatch(LPC_TimerChanel_t DevNum, unsigned int MATNum,
	          unsigned int * pAction , unsigned int *pExternalMatchValue);

int TIMER_SetCaptureAction (LPC_TimerChanel_t DevNum, 
                          unsigned char CPCHNum, 
                          unsigned char  TriggerType, 
                          bool EnableInt,
                          void (* Fnpr)(void *),
                          void * FnprArg );

int TIMER_GetTimerCapture(LPC_TimerChanel_t DevNum, unsigned int CRNum,
	          unsigned int * pCaptureValue);

unsigned long TIMER_CheckIntType(LPC_TimerChanel_t DevNum);
unsigned long TIMER_ClearInt(LPC_TimerChanel_t DevNum, int IntType);

unsigned long TIMER_GetREGValue_CR(LPC_TimerChanel_t DevNum, int CRNum);
unsigned long TIMER_GetREGValue_TC(LPC_TimerChanel_t DevNum);
unsigned long TIMER_GetPrescaler(LPC_TimerChanel_t DevNum);

void TIMER0_ISR ();
void TIMER1_ISR ();

// Time defenition
#define sec_T0  *(SYS_GetFpclk()/TIMER_GetPrescaler(TIMER0))
#define msec_T0 *(SYS_GetFpclk()/(TIMER_GetPrescaler(TIMER0)*1000))
#define usec_T0 *(SYS_GetFpclk()/(TIMER_GetPrescaler(TIMER0)*1000000))

#define sec_T1  *(SYS_GetFpclk()/TIMER_GetPrescaler(TIMER1))
#define msec_T1 *(SYS_GetFpclk()/(TIMER_GetPrescaler(TIMER1)*1000))
#define usec_T1 *(SYS_GetFpclk()/(TIMER_GetPrescaler(TIMER1)*1000000))

#endif //__LPC_Timer_H
