/*************************************************************************
 *
 *    Used with ICCARM and AARM.
 *
 *    (c) Copyright IAR Systems 2003
 *
 *    File name   : LPC_SysControl.c
 *    Description : Define API for system init
 *
 *    History :
 *    1. Data:  August 17, 2004
 *       Author: Shawn Zhang
 *       Description: Create the basic function
 *
 *    2. Data        : Oct 7, 2004
 *       Author      : Stanimir Bonev
 *       Description : Modify some function and interface
 *
 *    $Revision: 1.2 $
 **************************************************************************/

#include "LPC_SysControl.h"

LPC_Syscontrol_Config_t SysConfig;

/*************************************************************************
 * Function Name: SYS_Init
 * Parameters:  unsigned long Fosc
 *	        unsigned long Fcclk
 * 		LPC_SysControl_VPBDiv_t VPBDivider
 *		LPC_SysControl_RemapMode_t RemapMode
 *		bool MAMEnable
 *		LPC_SysControl_MAMConfig_t *pMAMConfig
 *              unsigned long PortDir0
 *              unsigned long Port0
 *              unsigned long PortDir1
 *              unsigned long Port1
 *
 * Return: int
 *             	0: success
 *	 non-zero: error number
 *
 * Description: Initialize the whole system, setting MEMMAP, VPB, whether enable PLL,
 *			 whether enable MAM
 *
 *************************************************************************/
int SYS_Init (unsigned long Fosc, unsigned long Fcclk,
                LPC_SysControl_VPBDiv_t VPBDivider,
                LPC_SysControl_RemapMode_t RemapMode,
                unsigned long PortDir0, unsigned long Port0,
                unsigned long PortDir1, unsigned long Port1)
{
unsigned long M, P_min, P_max, P, i;
int Pflag = 0, PLLflag = 0;
	
  // Check vaild
  if ( Fosc<Fosc_MIN || Fosc>Fosc_MAX)
    return 1;
  if ( Fcclk<Fcclk_MIN || Fcclk>Fcclk_MAX)
    return 1;
  if (Fcclk < Fosc)
    return 1;
  else if (Fcclk > Fosc)
  {
    // Calculate PLL's value M & P if need
    M = Fcclk / Fosc;
    P_min = Fcco_MIN / (2*Fcclk) + 1;
    P_max = Fcco_MAX / (2*Fcclk);
    for (i=P_min; i<=P_max; i++)
    {
      if ((i ==1) || (i==2) ||(i==4) || (i==8))
      {
        P=i;
        Pflag = 1;
        break;
      }
    }
    if (!Pflag) return 1;
    PLLflag = 1;
  }
  // Set globe variable
  SysConfig.Fosc = Fosc;
  SysConfig.Fcclk = Fcclk;
  switch(VPBDivider)
  {
  case VPBDIV4:
    SysConfig.Fpclk= Fcclk / 4;
    break;
  case VPBDIV1:
    SysConfig.Fpclk= Fcclk;
    break;	
  case VPBDIV2:
    SysConfig.Fpclk= Fcclk / 2;
    break;
  default:
    return 1;
  }
  SysConfig.VPBDivider = VPBDivider;
  SysConfig.RemapMode = RemapMode;

  // Do PLL
  if (PLLflag)
  {
    PLLCFG_bit.MSEL = M-1;      // Set M & P
    switch(P)
    {
    case 1:
      break;
    case 2:
      PLLCFG_bit.PSEL = 0x1;
      break;
    case 4:
      PLLCFG_bit.PSEL = 0x2;
      break;
    case 8:
      PLLCFG_bit.PSEL = 0x3;
      break;
    default:
      return 1;
    }
    PLLCON_bit.PLLE = true;     // Enable PLL
    // Interrups must be disble
    PLLFEED = PLLFEED_DATA1;
    PLLFEED = PLLFEED_DATA2;

    while (!PLLSTAT_bit.PLOCK); // Wait PLL lock

    PLLCON_bit.PLLC = true;	// Connect PLL
    PLLFEED = PLLFEED_DATA1;
    PLLFEED = PLLFEED_DATA2;
  }
  else
  {
    PLLCON_bit.PLLC = true;
    PLLCON_bit.PLLE = false;
    PLLFEED = PLLFEED_DATA1;
    PLLFEED = PLLFEED_DATA2;
  }
  // Do VPB
  VPBDIV_bit.VPBDIV = VPBDivider;

  // Do MEMAMP
  MEMMAP_bit.MAP = SysConfig.RemapMode;

  // Set GIO
  PINSEL0 = PINSEL1 = 0;
  IO0SET = Port0;
  IO0CLR = ~Port0;
  IO0DIR = PortDir0;
  IO1SET = Port1;
  IO1CLR = ~Port1;
  IO1DIR = PortDir1;
  return 0;
}

/*************************************************************************
 * Function Name: SYS_GetFpclk
 * Parameters: void
 * Return: int
 *             	0: success
 *	 non-zero: error number
 * Description: Get Fpclk
 *
 *************************************************************************/
unsigned int SYS_GetFpclk (void)
{
  return SysConfig.Fpclk;
}

/*************************************************************************
 * Function Name: PM_SetMode
 * Parameters: LPC_SysControl_PMMode_t Mode -- PM_STANDARD ,PM_IDLE or PM_POWERDOWN
 * Return: int
 *             	0: success
 *	 non-zero: error number
 * Description: Set power manage mode
 *
 *************************************************************************/
int PM_SetMode (LPC_SysControl_PMMode_t Mode)
{
  PCON = Mode & 0x3;
  return 0;
}

/*************************************************************************
 * Function Name: PM_OpenPeripheral
 * Parameters: lpc_uint32 DevType
 * Return: int
 *             	0: success
 *	 non-zero: error number
 * Description: Open specifical peripheral
 *
 *************************************************************************/
int PM_OpenPeripheral (unsigned int DevType)
{
  PCONP |= DevType;
  return 0;
}

/*************************************************************************
 * Function Name: PM_ClosePeripheral
 * Parameters: lpc_uint32 DevType
 * Return: int
 *             	0: success
 *	 non-zero: error number
 * Description: Close specifical peripheral
 *
 *************************************************************************/
int PM_ClosePeripheral (unsigned int DevType)
{
  PCONP &= (~DevType);
  return 0;
}


/*************************************************************************
 * Function Name: EXTINT_Init
 * Parameters: LPC_SysControl_ExtInt_Chanel_t ExtIntNum
 *	       bool WakeupEnable
 *
 * Return: int
 *             	0 : success
 *	 non-zero : error number
 * Description: Set External Interrupt
 *
 *************************************************************************/
int EXTINT_Init (LPC_SysControl_ExtInt_Chanel_t ExtIntNum,
                          bool WakeupEnable)
{
  switch(ExtIntNum)
  {
  case EXTINT0:
    // Assign pin to Ext Interrup logic
    PINSEL1_bit.P0_16 = 1;
    // Clear interrupt flag
    EXTINT_bit.EINT0 = 1;
    // Set Wakeup
    if (WakeupEnable)
      EXTWAKE_bit.EXTWAKE0 = 1;
    else
      EXTWAKE_bit.EXTWAKE0 = 0;
    break;
  case EXTINT1:
    // Assign pin to Ext Interrup logic
    PINSEL0_bit.P0_14 = 1;
    // Clear interrupt flag
    EXTINT_bit.EINT1 = 1;
    // Set Wakeup
    if (WakeupEnable)
      EXTWAKE_bit.EXTWAKE1 = 1;
    else
      EXTWAKE_bit.EXTWAKE1 = 0;
    break;
  case EXTINT2:
    // Assign pin to Ext Interrup logic
    PINSEL0_bit.P0_15 = 1;
    // Clear interrupt flag
    EXTINT_bit.EINT2 = 1;
    // Set Wakeup
    if (WakeupEnable)
      EXTWAKE_bit.EXTWAKE2 = 1;
    else
      EXTWAKE_bit.EXTWAKE2 = 0;
    break;
  default:
    return 1;
  }
  return 0;
}
