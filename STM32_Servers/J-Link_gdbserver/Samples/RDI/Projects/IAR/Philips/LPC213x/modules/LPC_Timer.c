/*************************************************************************
 *
 *    Used with ICCARM and AARM.
 *
 *    (c) Copyright IAR Systems 2003
 *
 *    File name   : LPC_Timer.c
 *    Description : Define API for Timer system
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

#include "LPC_Timer.h"

LPC_Timer_Config_t Timer0Config, Timer1Config;

/*************************************************************************
 * Function Name: TIMER_Init
 * Parameters:  LPC_TimerChanel_t DevNum
 *	        unsigned int precision -- the timer precision (Unit: us), general setting is 10 us
 * Return: int
 *              0: success
 *	 non-zero: error number
 * Description: Initialize Timer, Set the PR register that represent the precision of timer.
 *
 *************************************************************************/
int TIMER_Init(LPC_TimerChanel_t DevNum, unsigned long precision)
{
int i;
  //all registers are set to 0;
  switch (DevNum)
  {
  case TIMER0:
    // Set globe variable
    Timer0Config.Precision = precision;
    // PR = Precision(us) * Pclk
    Timer0Config.Prescaler = (precision * SYS_GetFpclk()) / 1000000;
    for (i=0; i<CH_MAXNUM; ++i)
    {
      Timer0Config.MatchCH[i].Enable = false;
      Timer0Config.MatchCH[i].Action = 0;
      Timer0Config.MatchCH[i].TimeValue =0;
      Timer0Config.MatchCH[i].Fnpr = NULL;
      Timer0Config.MatchCH[i].FnprArg = (void *)0;

      Timer0Config.CaptureCH[i].Enable = false;
      Timer0Config.CaptureCH[i].TriggerType= 0;
      Timer0Config.CaptureCH[i].EnableInt = 0;
      Timer0Config.CaptureCH[i].Fnpr = NULL;
      Timer0Config.CaptureCH[i].FnprArg = (void *)0;
      Timer0Config.CaptureCH[i].CPValue= 0;

      Timer0Config.ExtAction[i]= DONOTHING;
      Timer0Config.ExtBitValue[i]= 0;
    }
    // Clear interrupts flags	
    T0IR=0xFF;
    // Disable counting
    T0TCR=0;
    // Clear timer counter
    T0TC=0;
    // PR = Presclare - 1
    T0PR= Timer0Config.Prescaler - 1;
    // Clear prescaler timer counter
    T0PC=0;
    // Reset Compare modules
    T0MCR=0;
    T0MR0=0;
    T0MR1=0;
    T0MR2=0;
    T0MR3=0;
    // Reset Capture modules
    T0CCR=0;
    // Reset External Compare module
    T0EMR=0;
    break;
  case TIMER1:
    // Set globe variable
    Timer1Config.Precision = precision;
    // PR = Precision(us) * Pclk
    Timer1Config.Prescaler = (precision * SYS_GetFpclk()) / 1000000;
    for (i=0; i<CH_MAXNUM; ++i)
    {
      Timer1Config.MatchCH[i].Enable = false;
      Timer1Config.MatchCH[i].Action = 0;
      Timer1Config.MatchCH[i].TimeValue =0;
      Timer1Config.MatchCH[i].Fnpr = NULL;
      Timer1Config.MatchCH[i].FnprArg = (void *)0;

      Timer1Config.CaptureCH[i].Enable = false;
      Timer1Config.CaptureCH[i].TriggerType= 0;
      Timer1Config.CaptureCH[i].EnableInt = 0;
      Timer1Config.CaptureCH[i].Fnpr = NULL;
      Timer1Config.CaptureCH[i].FnprArg = (void *)0;
      Timer1Config.CaptureCH[i].CPValue= 0;

      Timer1Config.ExtAction[i]= DONOTHING;
      Timer1Config.ExtBitValue[i]= 0;
    }
    // Clear interrupts flags	
    T1IR=0xFF;
    // Disable counting
    T1TCR=0;
    // Clear timer counter
    T1TC=0;
    // PR = Prescaler - 1
    T1PR=Timer1Config.Prescaler - 1;
    // Clear prescaler timer counter
    T1PC=0;
    // Reset Compare modules
    T1MCR=0;
    T1MR0=0;
    T1MR1=0;
    T1MR2=0;
    T1MR3=0;
    // Reset Capture modules
    T1CCR=0;
    // Reset External Compare module
    T1EMR=0;
    break;
  default:
    return 1;
  }
  return 0;
}

/*************************************************************************
 * Function Name: TIMER_GetPrescaler
 * Parameters:  LPC_TimerChanel_t DevNum
 * Return: unsigned int
 *
 *
 * Description: Return prescaler value
 *
 *
 *************************************************************************/
unsigned long TIMER_GetPrescaler(LPC_TimerChanel_t DevNum)
{
  switch (DevNum)
  {
  case TIMER0:
    return Timer0Config.Prescaler;
  case TIMER1:
    return Timer1Config.Prescaler;
  }
  return 0;
}

/*************************************************************************
 * Function Name: TIMER_Reset
 * Parameters:  LPC_TimerChanel_t DevNum
  * Return: int
 *              0: success
 *       non-zero: error number
 * Description: When next pclk arrives, only the TC and PC will be reset.
 *              Whilst other registers remain.
 *
 *************************************************************************/
int TIMER_Reset(LPC_TimerChanel_t DevNum)
{
  switch (DevNum)
  {
  case TIMER0:
    T0TCR |= 2;
    return 0;
  case TIMER1:
    T1TCR |= 2;
    return 0;
  }
  return 1;
}

/*************************************************************************
 * Function Name: TIMER_Start
 * Parameters:  LPC_TimerChanel_t DevNum
 * Return: int
 *              0: success
 *       non-zero: error number
 * Description: Start Timer or enable the Timer. if the Timer stop now, the Timer will
 *		resume running after calling this function.
 *
 *************************************************************************/
int TIMER_Start(LPC_TimerChanel_t DevNum)
{
  switch (DevNum)
  {
  case TIMER0:
    // Clear reset flag
    T0TCR &= ~2;
    // Counting enable
    T0TCR_bit.CE = true;
    return 0;
  case TIMER1:
    // Clear reset flag
    T1TCR &= ~2;
    // Counting enable
    T1TCR_bit.CE = true;
    return 0;
  }
  return 1;
}

/*************************************************************************
 * Function Name: TIMER_Stop
 * Parameters:  LPC_TimerChanel_t DevNum
 * Return: int
 *              0: success
 *       non-zero: error number
 * Description: Just stop Timer or disable Timer, all registers remain.
 *
 *************************************************************************/
int TIMER_Stop(LPC_TimerChanel_t DevNum)
{
  switch (DevNum)
  {
  case TIMER0:
    T0TCR_bit.CE = false;
    return 0;
  case TIMER1:
    T1TCR_bit.CE = false;
    return 0;
  }
  return 1;
}

/*************************************************************************
 * Function Name: TIMER_GetTimerMatch
 * Parameters:  LPC_TimerChanel_t DevNum,
 *	        unsigned int MRNum,
 *	        unsigned int * pAction ,
 *	        unsigned int * pMatchValue
 * Return: int
 *              0: success
 *	 non-zero: error number
 * Description: Get correponding matching information for specific timer.
 *
 *************************************************************************/
int TIMER_GetTimerMatch(LPC_TimerChanel_t DevNum, unsigned int MRNum,
	          unsigned int * pAction , unsigned int * pMatchValue)
{
  if (MRNum >= CH_MAXNUM)
    return 1;
  switch(DevNum)
  {
  case TIMER0:
    *pMatchValue = Timer0Config.MatchCH[MRNum].TimeValue;
    *pAction = Timer0Config.MatchCH[MRNum].Action;
    break;
  case TIMER1:
    *pMatchValue = Timer1Config.MatchCH[MRNum].TimeValue;
    *pAction = Timer1Config.MatchCH[MRNum].Action;
    break;
  default:
    return 1;
  }
  return 0;
}

/*************************************************************************
 * Function Name: TIMER_SetMatchAction
 * Parameters:  LPC_TimerChanel_t DevNum -- Device Number
 *		unsigned int MRNum -- Match Channel Number
 *		unsigned int action -- General Interrupt | Reset Timer | Stop Timer
 *		unsigned int Timevalue -- the time value (Unit: us)
 *		void (* Fnpr)(void *) -- ISR function pointer
 *		void * FnprArg -- relative argument
 *		LPC_Timer_ExtAction_t ExtAction -- External Match Control Action
 *
 * Return: int
 *              0: success
 *       non-zero: error number
 * Description: Set correponding matching action and other information to the channel
 *		for specific timer.
 *
 *************************************************************************/
int TIMER_SetMatchAction(LPC_TimerChanel_t DevNum,
                          unsigned int MRNum,
                          unsigned int action ,
                          unsigned long TimeValue,
                          void (* Fnpr)(void *),
                          void * FnprArg,
                          LPC_Timer_ExtAction_t ExtAction)
{
  // Check parameter valid
  if (action>TimerAction_StopTimer+TimerAction_ResetTimer+TimerAction_Interrupt)
    return 1;
  if (ExtAction > TOGGLE)
    return 1;
  switch (DevNum)
  {
  case TIMER0:
    // Set Mash register
    switch (MRNum)
    {
    case CH0:
      T0MR0=TimeValue;
      break;
    case CH1:
      T0MR1=TimeValue;
      break;
    case CH2:
      T0MR2=TimeValue;
      break;
    case CH3:
      T0MR3=TimeValue;
      break;
    default:
      return 1;
    }
    Timer0Config.MatchCH[MRNum].Enable = true;
    Timer0Config.MatchCH[MRNum].Action = action;
    Timer0Config.MatchCH[MRNum].TimeValue= TimeValue;
    Timer0Config.ExtAction[MRNum]= ExtAction;
    // Clear actions
    T0MCR &= ~(7<<(MRNum*3));
    //Set Reset on Match
    if (action & TimerAction_ResetTimer)
      T0MCR |= TimerAction_ResetTimer << (3*MRNum);
    //Set StopWatch on Match
    if (action & TimerAction_StopTimer)
      T0MCR |= TimerAction_StopTimer << (3*MRNum);
    //Set Interrupt on Match
    if (action & TimerAction_Interrupt)
    {
      Timer0Config.MatchCH[MRNum].Fnpr = Fnpr;
      Timer0Config.MatchCH[MRNum].FnprArg = FnprArg;
      T0MCR |= TimerAction_Interrupt << (3*MRNum);
    }
    // Clear External action
    T0EMR &= ~(3 << (4 + 2*MRNum));
    // Set External action
    switch (MRNum)
    {
    case CH0:
      // Set External action type
      T0EMR_bit.EMC0 = ExtAction;
      // Assign pin to match modyle
      if (ExtAction != DONOTHING)
        PINSEL0_bit.P0_3 = 0x2;
      break;
    case CH1:
      // Set External action type
      T0EMR_bit.EMC1 = ExtAction;
      // Assign pin to match modyle
      if (ExtAction != DONOTHING)
        PINSEL0_bit.P0_5 = 0x2;
      break;
    case CH2:
      // Set External action type
      T0EMR_bit.EMC2 = ExtAction;
      // Assign pin to match modyle
      if (ExtAction != DONOTHING)
        PINSEL1_bit.P0_16 = 0x2;
      break;
    case CH3:
      // Set External action type
      T0EMR_bit.EMC3 = ExtAction;
      break;
    }
    return 0;
  case TIMER1:
    // Set Mash register
    switch (MRNum)
    {
    case CH0:
      T1MR0=TimeValue;
      break;
    case CH1:
      T1MR1=TimeValue;
      break;
    case CH2:
      T1MR2=TimeValue;
      break;
    case CH3:
      T1MR3=TimeValue;
      break;
    default:
      return 1;
    }

    Timer1Config.MatchCH[MRNum].Enable = true;
    Timer1Config.MatchCH[MRNum].Action = action;
    Timer1Config.MatchCH[MRNum].TimeValue= TimeValue;
    Timer1Config.ExtAction[MRNum]= ExtAction;
    // Clear actions
    T1MCR &= ~(7<<(MRNum*3));
    //Set Reset on Match
    if (action & TimerAction_ResetTimer)
      T1MCR |= TimerAction_ResetTimer << (3*MRNum);
    //Set StopWatch on Match
    if (action & TimerAction_StopTimer)
      T1MCR |= TimerAction_StopTimer << (3*MRNum);
    //Set Interrupt on Match
    if (action & TimerAction_Interrupt)
    {
      Timer1Config.MatchCH[MRNum].Fnpr = Fnpr;
      Timer1Config.MatchCH[MRNum].FnprArg = FnprArg;
      T1MCR |= TimerAction_Interrupt << (3*MRNum);
    }
    // Clear External action
    T1EMR &= ~(3 << (4 + 2*MRNum));
    // Set External action
    switch (MRNum)
    {
    case CH0:
      // Set External action type
      T1EMR_bit.EMC0 = ExtAction;
      // Assign pin to match modyle
      if (ExtAction != DONOTHING)
        PINSEL0_bit.P0_12 = 0x2;
      break;
    case CH1:
      // Set External action type
      T1EMR_bit.EMC1 = ExtAction;
      // Assign pin to match modyle
      if (ExtAction != DONOTHING)
        PINSEL0_bit.P0_13 = 0x2;
      break;
    case CH2:
      // Set External action type
      T1EMR_bit.EMC2 = ExtAction;
      // Assign pin to match modyle
      if (ExtAction != DONOTHING)
        PINSEL1_bit.P0_19 = 0x2;
      break;
    case CH3:
      // Set External action type
      T0EMR_bit.EMC3 = ExtAction;
      // Assign pin to match modyle
      if (ExtAction != DONOTHING)
        PINSEL1_bit.P0_20 = 0x2;
      break;
    }
    return 0;
  }
  return 1;
}

/*************************************************************************
 * Function Name: TIMER_GetTimerExternalMatch
 * Parameters:  LPC_TimerChanel_t DevNum
 *	        unsigned int MRNum,
 *	        unsigned int *pAction,
 *	        unsigned int *pExternalMatchValue
 * Return: int
 *              0: success
 *	 non-zero: error number
 * Description: Get correponding external matching information from specific timer.
 *
 *************************************************************************/
int TIMER_GetTimerExternalMatch(LPC_TimerChanel_t DevNum, unsigned int MRNum,
	          unsigned int * pAction , unsigned int *pExternalMatchValue)
{
  if (MRNum >= CH_MAXNUM)
    return 1;
  switch(DevNum)
  {
  case TIMER0:
    *pExternalMatchValue = Timer0Config.ExtAction[MRNum];
    *pAction = Timer0Config.MatchCH[MRNum].Action;
    break;
  case TIMER1:
    *pExternalMatchValue = Timer1Config.ExtAction[MRNum];
    *pAction = Timer1Config.MatchCH[MRNum].Action;
    break;
  default:
    return 1;
  }
  return 0;
}


/*************************************************************************
 * Function Name: TIMER_GetTimerCapture
 * Parameters:  LPC_TimerChanel_t DevNum,
 *		unsigned int CRNum,
 *		unsigned int * pCaptureValue
 * Return: int
 *             	0: success
 *	 non-zero: error number
 * Description: Get correponding capture information from specific timer.
 *
 *************************************************************************/
int TIMER_GetTimerCapture(LPC_TimerChanel_t DevNum, unsigned int CRNum,
	          unsigned int * pCaptureValue)
{
  switch(DevNum)
  {
  case TIMER0:
    if (CRNum >= CPCH_MAXNUM-1)
      return 1;
    *pCaptureValue = Timer0Config.CaptureCH[CRNum].CPValue;
    break;
  case TIMER1:
    if (CRNum >= CPCH_MAXNUM)
      return 1;
    *pCaptureValue = Timer1Config.CaptureCH[CRNum].CPValue;
    break;
  default:
    return 1;
  }
  return 0;
}


/*************************************************************************
 * Function Name: TIMER_SetCaptureAction
 * Parameters:  LPC_TimerChanel_t DevNum	-- Device Number
 *	        unsigned char CPCHNum -- Capture Channel Number
 *	 	unsigned char TriggerType -- Rising edge | Falling edge
 *		bool EnableInt -- whether interrupt is generated
 *		void (* Fnpr)(void *) -- ISR function pointer
 *		void * FnprArg -- relative argument
 *
 * Return: int
 *              0: success
 *	 non-zero: error number
 * Description: Set correponding capture trigger type and other information to the channel
 *		for specific timer.
 *
 *************************************************************************/
int TIMER_SetCaptureAction (LPC_TimerChanel_t DevNum,
                              unsigned char CPCHNum,
                              unsigned char  TriggerType,
                              bool EnableInt,
                              void (* Fnpr)(void *),
                              void * FnprArg )
{
  // Check parameter valid
  if (TriggerType > TimerCPTrigger_Rising+TimerCPTrigger_Falling)
    return 1;
  switch (DevNum)
  {
  case TIMER0:
    if (CPCHNum > CPCH_MAXNUM-2)  // for timer 0 cature chanel 3 is not exist
      return 1;
    Timer0Config.CaptureCH[CPCHNum].Enable = true;
    Timer0Config.CaptureCH[CPCHNum].TriggerType = TriggerType;

    // Clear Capture actions
    T0CCR &= ~(7 << (3*CPCHNum));
    // Assign of pin to capture module
    switch (CPCHNum)
    {
    case CH0:
      if (TriggerType == 0)
        PINSEL0_bit.P0_2 = 0;
      else
        PINSEL0_bit.P0_2 = 0x2;
      break;
    case CH1:
      if (TriggerType == 0)
        PINSEL0_bit.P0_4 = 0;
      else
        PINSEL0_bit.P0_4 = 0x2;
      break;
    case CH2:
      if (TriggerType == 0)
        PINSEL0_bit.P0_6 = 0;
      else
        PINSEL0_bit.P0_6 = 0x2;
      break;
    }
    //Set Capture on Rising Edge
    if (TriggerType & TimerCPTrigger_Rising)
      T0CCR |= TimerCPTrigger_Rising << (3*CPCHNum);
    //Set Capture on Falling Edge
    if (TriggerType & TimerCPTrigger_Falling)
      T0CCR |= TimerCPTrigger_Falling << (3*CPCHNum);

    //Set Interrupt on Capture
    if (EnableInt && TriggerType)
    {
      Timer0Config.CaptureCH[CPCHNum].EnableInt = true;
      Timer0Config.CaptureCH[CPCHNum].Fnpr = Fnpr;
      Timer0Config.CaptureCH[CPCHNum].FnprArg = FnprArg;
      T0CCR |= 0x4 << (3*CPCHNum);
    }
    else
    {
      Timer0Config.CaptureCH[CPCHNum].EnableInt = false;
      Timer0Config.CaptureCH[CPCHNum].Fnpr = NULL;
      Timer0Config.CaptureCH[CPCHNum].FnprArg = (void *)0;
    }
    return 0;
  case TIMER1:
    if (CPCHNum > CPCH_MAXNUM-1)
      return 1;
    Timer1Config.CaptureCH[CPCHNum].Enable = true;
    Timer1Config.CaptureCH[CPCHNum].TriggerType = TriggerType;

    // Clear Capture actions
    T1CCR &= ~(7 << (3*CPCHNum));
    // Assign of pin to capture module
    switch (CPCHNum)
    {
    case CH0:
      if (TriggerType == 0)
        PINSEL0_bit.P0_10 = 0;
      else
        PINSEL0_bit.P0_10 = 0x2;
      break;
    case CH1:
      if (TriggerType)
        PINSEL0_bit.P0_11 = 0x2;
      break;
    case CH2:
      if (TriggerType == 0)
        PINSEL1_bit.P0_17 = 0;
      else
        PINSEL1_bit.P0_17 = 0x2;
      break;
    case CH3:
      if (TriggerType == 0)
        PINSEL1_bit.P0_18 = 0;
      else
        PINSEL1_bit.P0_18 = 0x2;
      break;
    }
    //Set Capture on Rising Edge
    if (TriggerType & TimerCPTrigger_Rising)
      T1CCR |= TimerCPTrigger_Rising << (3*CPCHNum);

    //Set Capture on Falling Edge
    if (TriggerType & TimerCPTrigger_Falling)
      T1CCR |= TimerCPTrigger_Falling << (3*CPCHNum);

    //Set Interrupt on Capture
    if (EnableInt && TriggerType)
    {
      Timer1Config.CaptureCH[CPCHNum].EnableInt = true;
      Timer1Config.CaptureCH[CPCHNum].Fnpr = Fnpr;
      Timer1Config.CaptureCH[CPCHNum].FnprArg = FnprArg;
      T1CCR |= 0x4 << (3*CPCHNum);
    }
    else
    {
      Timer1Config.CaptureCH[CPCHNum].EnableInt = false;
      Timer1Config.CaptureCH[CPCHNum].Fnpr = NULL;
      Timer1Config.CaptureCH[CPCHNum].FnprArg = (void *)0;
    }
    return 0;
  }
  return 1;
}

/*************************************************************************
 * Function Name: TIMER_GetREGValue_CR
 * Parameters:  LPC_TimerChanel_t DevNum
 *	        int CRNum
 * Return: unsigned long
 *
 * Description: Get CR register value
 *
 *************************************************************************/
unsigned long TIMER_GetREGValue_CR(LPC_TimerChanel_t DevNum, int CRNum)
{
  switch (DevNum)
  {
  case TIMER0:
    switch(CRNum)
    {
    case CPCH0:
      return T0CR0;
    case CPCH1:
      return T0CR1;
    case CPCH2:
      return T0CR2;
    case CPCH3:
      return T0CR3;
    }
  case TIMER1:
    switch(CRNum)
    {
    case CPCH0:
      return T1CR0;
    case CPCH1:
      return T1CR1;
    case CPCH2:
      return T1CR2;
    case CPCH3:
      return T1CR3;
    }
  }
  return (unsigned int)-1;
}

/*************************************************************************
 * Function Name: TIMER_GetREGValue_TC
 * Parameters: LPC_TimerChanel_t DevNum
 * Return: unsigned long
 *
 * Description: Get TC register value
 *
 *************************************************************************/
unsigned long TIMER_GetREGValue_TC(LPC_TimerChanel_t DevNum)
{
  switch (DevNum)
  {
  case TIMER0:
    return T0TC;
  case TIMER1:
    return T1TC;
  }
  return (unsigned int)-1;
}

/*************************************************************************
 * Function Name: TIMER_CheckIntSrc
 * Parameters: LPC_TimerChanel_t DevNum
 * Return: unsigned long
 *	TIMERMR0...3Int | TIMERCR0...3Int
 *
 * Description: Get Timer interrupt Type
 *
 *************************************************************************/
unsigned long TIMER_CheckIntType(LPC_TimerChanel_t DevNum)
{
  switch (DevNum)
  {
  case TIMER0:
    return (T0IR & 0xFF);
  case TIMER1:
    return (T1IR & 0xFF);
  default:
    return (unsigned long)-1;
  }
}

/*************************************************************************
 * Function Name: RTC_ClearInt
 * Parameters:  LPC_TimerChanel_t DevNum
 *	        int IntType
 *			
 * Return: unsigned long
 *             	0: sucess
 *		1: fail
 *
 * Description: Clear Timer interrupt.
 *
 *************************************************************************/
unsigned long TIMER_ClearInt(LPC_TimerChanel_t DevNum, int IntType)
{
  if (IntType<1 || IntType>0xFF)
    return 1;

  switch (DevNum)
  {
  case TIMER0:
    T0IR = (IntType & 0xFF);
    break;
  case TIMER1:
    T1IR = (IntType & 0xFF);
    break;
  default:
    return 1;
  }
  return 0;
}

/*************************************************************************
 * Function Name: T0ISR
 * Parameters: void
 * Return: void
 *
 * Description: TIMER0 interrupt subroutine
 *
 *************************************************************************/
void TIMER0_ISR ()
{
int IntStatus;
  IntStatus = TIMER_CheckIntType(TIMER0);
  TIMER_ClearInt(TIMER0, IntStatus);

  /* Match Register Interrupt */
  if (IntStatus & TIMERMR0Int)	
  {
    (Timer0Config.MatchCH[0].Fnpr)((void *)Timer0Config.MatchCH[0].FnprArg);
  }
	
  if (IntStatus & TIMERMR1Int)	
  {
    (Timer0Config.MatchCH[1].Fnpr)((void *)Timer0Config.MatchCH[1].FnprArg);
  }
	
  if (IntStatus & TIMERMR2Int)	
  {
    (Timer0Config.MatchCH[2].Fnpr)((void *)Timer0Config.MatchCH[2].FnprArg);
  }
	
  if (IntStatus & TIMERMR3Int)	
  {
    (Timer0Config.MatchCH[3].Fnpr)((void *)Timer0Config.MatchCH[3].FnprArg);
  }

  /* Capture Register Interrupt */
  if (IntStatus & TIMERCR0Int)	
  {
    Timer0Config.CaptureCH[0].CPValue = TIMER_GetREGValue_CR(TIMER0, CPCH0);
    (Timer0Config.CaptureCH[0].Fnpr)((void *)Timer0Config.CaptureCH[0].FnprArg);
  }
	
  if (IntStatus & TIMERCR1Int)	
  {
    Timer0Config.CaptureCH[1].CPValue = TIMER_GetREGValue_CR(TIMER0, CPCH1);
    (Timer0Config.CaptureCH[1].Fnpr)((void *)Timer0Config.CaptureCH[1].FnprArg);
  }
	
  if (IntStatus & TIMERCR2Int)	
  {
    Timer0Config.CaptureCH[2].CPValue = TIMER_GetREGValue_CR(TIMER0, CPCH2);
    (Timer0Config.CaptureCH[2].Fnpr)((void *)Timer0Config.CaptureCH[2].FnprArg);
  }
	
  if (IntStatus & TIMERCR3Int)	
  {
    Timer0Config.CaptureCH[3].CPValue = TIMER_GetREGValue_CR(TIMER0, CPCH3);
    (Timer0Config.CaptureCH[3].Fnpr)((void *)Timer0Config.CaptureCH[3].FnprArg);
  }
  VICVectAddr = 0;    // Clear interrupt in VIC.
}

/*************************************************************************
 * Function Name: T1ISR
 * Parameters: void
 * Return: void
 *
 * Description: TIMER1 interrupt subroutine
 *
 *************************************************************************/
void TIMER1_ISR ()
{
  int IntStatus;

  IntStatus = TIMER_CheckIntType(TIMER1);
  TIMER_ClearInt(TIMER1, IntStatus);

  /* Match Register Interrupt */
  if (IntStatus & TIMERMR0Int)	
  {
    (Timer1Config.MatchCH[0].Fnpr)((void *)Timer1Config.MatchCH[0].FnprArg);
  }
	
  if (IntStatus & TIMERMR1Int)	
  {
    (Timer1Config.MatchCH[1].Fnpr)((void *)Timer1Config.MatchCH[1].FnprArg);
  }
	
  if (IntStatus & TIMERMR2Int)	
  {
    (Timer1Config.MatchCH[2].Fnpr)((void *)Timer1Config.MatchCH[2].FnprArg);
  }
	
  if (IntStatus & TIMERMR3Int)	
  {
    (Timer1Config.MatchCH[3].Fnpr)((void *)Timer1Config.MatchCH[3].FnprArg);
  }

  /* Capture Register Interrupt */
  if (IntStatus & TIMERCR0Int)	
  {
    Timer1Config.CaptureCH[0].CPValue = TIMER_GetREGValue_CR(TIMER1, CPCH0);
    (Timer1Config.CaptureCH[0].Fnpr)((void *)Timer1Config.CaptureCH[0].FnprArg);
  }
	
  if (IntStatus & TIMERCR1Int)	
  {
    Timer1Config.CaptureCH[1].CPValue = TIMER_GetREGValue_CR(TIMER1, CPCH1);
    (Timer1Config.CaptureCH[1].Fnpr)((void *)Timer1Config.CaptureCH[1].FnprArg);
  }
	
  if (IntStatus & TIMERCR2Int)	
  {
    Timer1Config.CaptureCH[2].CPValue = TIMER_GetREGValue_CR(TIMER1, CPCH2);
    (Timer1Config.CaptureCH[2].Fnpr)((void *)Timer1Config.CaptureCH[2].FnprArg);
  }
	
  if (IntStatus & TIMERCR3Int)	
  {
    Timer1Config.CaptureCH[3].CPValue = TIMER_GetREGValue_CR(TIMER1, CPCH3);
    (Timer1Config.CaptureCH[3].Fnpr)((void *)Timer1Config.CaptureCH[3].FnprArg);
  }

  VICVectAddr = 0;    // Clear interrupt in VIC.
}
