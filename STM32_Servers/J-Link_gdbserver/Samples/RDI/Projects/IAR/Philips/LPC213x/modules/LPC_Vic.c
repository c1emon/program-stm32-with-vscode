/*************************************************************************
 *
 *    Used with ICCARM and AARM.
 *
 *    (c) Copyright IAR Systems 2003
 *
 *    File name   : LPC_Vic.h
 *    Description : Define API for VIC
 *
 *    History :
 *    1. Data: July 8th, 2004
 *       Author: Wilson Liu
 *       Description: Create the basic function
 *
 *    2. Data: August 4th, 2004
 *       Author: Shawn Zhang
 *       Description: Clean up the functions. Support nonvector interrupt at first.
 *
 *    3. Data        : Oct 11, 2004
 *       Author      : Stanimir Bonev
 *       Description : Modify some function and interface
 *
 *    $Revision: 1.1 $
 **************************************************************************/

#include "LPC_Vic.h"

/*************************************************************************
 * Function Name: VIC_SetProtectionMode
 * Parameters: LPC_Vic_ProtectionMode_t ProtectionType
 * Return: void
 *
 * Description: According to the parameter:- ProtectionType to decide the VIC
 *              access mode (previledged mode | user or previledged mode).
 *
 *************************************************************************/
void VIC_SetProtectionMode(LPC_Vic_ProtectionMode_t ProtectionType)
{
  VICProtection_bit.PROTECT = ProtectionType;
  return ;
}

/*************************************************************************
 * Function Name: VIC_GetProtectionMode
 * Parameters: void
 * Return: LPC_Vic_ProtectionMode_t
 *
 * Description: Get the VIC access mode (previledged mode | user or previledged mode).
 *
 *************************************************************************/
LPC_Vic_ProtectionMode_t VIC_GetProtectionMode(void)
{
LPC_Vic_ProtectionMode_t ProtectionType;

  if (VICProtection & 0x1)
    ProtectionType = PrivilegedMode;
  else
    ProtectionType = UserandPrivilegedMode;
	
  return ProtectionType;
}


/*************************************************************************
 * Function Name: VIC_Init
 * Parameters: void
 * Return: void
 *
 * Description: Initialize VIC
 *
 *************************************************************************/
void VIC_Init(void)
{
  // Assign all interrupt chanels to IRQ
  VICIntSelect  =  0;
  // Diasable all interrupts
  VICIntEnClear = 0xFFFFFFFF;
  // Clear all software interrutps
  VICSoftIntClear = 0xFFFFFFFF;
  // VIC registers can be accessed in User or privileged mode
  VICProtection = 0;
  // Clear interrupt
  VICVectAddr = 0;
  // Clear address of the Interrupt Service routine (ISR) for non-vectored IRQs.
  VICDefVectAddr = 0;
	
  // Clear address of the Interrupt Service routine (ISR) for vectored IRQs.
  VICVectAddr0  = \
  VICVectAddr1  = \
  VICVectAddr2  = \
  VICVectAddr3  = \
  VICVectAddr4  = \
  VICVectAddr5  = \
  VICVectAddr6  = \
  VICVectAddr7  = \
  VICVectAddr8  = \
  VICVectAddr9  = \
  VICVectAddr10 = \
  VICVectAddr11 = \
  VICVectAddr12 = \
  VICVectAddr13 = \
  VICVectAddr14 = \
  VICVectAddr15 = 0;

  // Disable all vectored IRQ slots
  VICVectCntl0  = \
  VICVectCntl1  = \
  VICVectCntl2  = \
  VICVectCntl3  = \
  VICVectCntl4  = \
  VICVectCntl5  = \
  VICVectCntl6  = \
  VICVectCntl7  = \
  VICVectCntl8  = \
  VICVectCntl9  = \
  VICVectCntl10 = \
  VICVectCntl11 = \
  VICVectCntl12 = \
  VICVectCntl13 = \
  VICVectCntl14 = \
  VICVectCntl15 = 0;
}

/*************************************************************************
 * Function Name: VIC_GetIRQStatus
 * Parameters: void
 * Return: unsigned int
 *
 * Description: Get IRQ Status of VIC. Return register VICIRQSTATUS's value.
 *              If some IRQ interrupt request is enabled, then the corresponding
 *		bit of VICIRQSTATUS is set.
 *
 *************************************************************************/
unsigned int VIC_GetIRQStatus(void)
{
  return (VICIRQStatus);
}

/*************************************************************************
 * Function Name: VIC_GetFIQStatus
 * Parameters: void
 * Return: unsigned int
 *
 * Description: Get FIQ Status of VIC. Return register VICFIQSTATUS's value.
 *              If some FIQ interrupt request is enabled, then the corresponding
 *		bit of VICFIQSTATUS is set. If more that one interrupt request
 *              is assigned as FIQ, then invoking this function can decide which
 *              one or ones is/are the request source(s).
 *
 *************************************************************************/
unsigned int VIC_GetFIQStatus(void)
{
  return (VICFIQStatus);
}

/*************************************************************************
 * Function Name: VIC_EnableInt
 * Parameters: lpc_uint32 IntType
 * Return: void
 *
 * Description: Enable specific interrupt
 *
 *************************************************************************/
void VIC_EnableInt(unsigned int IntType)
{
  VICIntEnable |= IntType;
}

/*************************************************************************
 * Function Name: VIC_DisableInt
 * Parameters: unsigned int IntType
 * Return: void
 *
 * Description: Disable specific interrupt
 *
 *************************************************************************/
void VIC_DisableInt(unsigned int IntType)
{
  VICIntEnClear |= IntType;
}

/*************************************************************************
 * Function Name: VIC_EnableNonVectoredIRQ
 * Parameters:  pIRQSub - Non Vectored IRQ Sub address
 * Return: void
 *
 * Description:  Set VICDefVectAddr to be the IRQ Sub address.
 *
 *************************************************************************/
void VIC_EnableNonVectoredIRQ(void(*pIRQSub)())
{
  VICDefVectAddr = (unsigned int)pIRQSub;
}

/*************************************************************************
 * Function Name: VIC_DisableNonVectoredIRQ
 * Parameters: void
 * Return: void
 *
 * Description: set VICDefVectAddr to be reset value (NULL).
 *		
 *************************************************************************/
void VIC_DisableNonVectoredIRQ(void)
{
  VICDefVectAddr = NULL;
}

/*************************************************************************
 * Function Name: VIC_SetVectoredIRQ
 * Parameters:  void(*pIRQSub)()
 *              LPC_VicIrqSlots_t VicIrqSlot
 *              unsigned int VicIntSouce
 *
 * Return: void
 *
 * Description:  Init vectored inerrutps
 *
 *************************************************************************/
void VIC_SetVectoredIRQ(void(*pIRQSub)(), LPC_VicIrqSlots_t VicIrqSlot, unsigned int VicIntSource)
{
unsigned long volatile *pReg;
  // load base address of vectored address registers
  pReg = &VICVectAddr0;
  // Set Address of callback function to corresponding Slot
  *(pReg+VicIrqSlot) = (unsigned long)pIRQSub;
  // load base address of ctrl registers
  pReg = &VICVectCntl0;
  // Set source chanel and enable the slot
  *(pReg+VicIrqSlot) = VicIntSource | 0x20;
  // Clear FIQ select bit
  VICIntSelect &= ~(1<<VicIntSource);
}
