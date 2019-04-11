/*************************************************************************
 *
 *    Used with ICCARM and AARM.
 *
 *    (c) Copyright IAR Systems 2003
 *
 *    File name   : LPC_Uart.c
 *    Description : Define API for UART
 *
 *    History :
 *    1. Data: July 13, 2004                                              
 *       Author: Shawn Zhang                                                    
 *       Description: Create the basic function    
 *
 *    2. Data: August 09, 2004                                              
 *       Author: Shawn Zhang                                                    
 *       Description: Integrate two method :- by polling and by interrupt, user 
 *		      could select it.
 *
 *    3. Data: August 17, 2004                                              
 *       Author: Shawn Zhang                                                    
 *       Description:  1) Repair the bug about Tx ring buffer.
 *	 	       2) Repair the bug about ReadTxBuf function and ISR.
 *
 *    4. Data        : Oct 9, 2004 
 *       Author      : Stanimir Bonev
 *       Description : Modify some function and interface  
 *
 *    $Revision: 1.1 $
 **************************************************************************/

#include "LPC_Uart.h"

// Define globe variable
LPC_Uart_Config_t Uart0Config = {BD9600, WordLength8, false, false, ParitySelOdd, 
				  false, true, FIFORXLEV2, IER_RBR | IER_RLS,
				  INTERRUPT_MODE,};
							
LPC_Uart_Config_t Uart1Config = {BD9600, WordLength8, false, false, ParitySelOdd, 
				  false, true, FIFORXLEV2, IER_RBR | IER_RLS,
				  INTERRUPT_MODE,};

/*************************************************************************
 * Function Name: UART_InitUartBuf
 * Parameters: LPC_Uart_Buffer_t *pUartBuf
 * Return: void
 *
 * Description: Initialize Rx & Tx buffer, which is used when adopting interrupt method
 *  
 *************************************************************************/
void UART_InitUartBuf (LPC_Uart_Buffer_t *pUartBuf)
{
  pUartBuf->RxHeadPoint=0;
  pUartBuf->RxTailPoint=0;
	
  pUartBuf->TxHeadPoint=0;
  pUartBuf->TxTailPoint=0;

  pUartBuf->RxCount=0;
  pUartBuf->TxCount=0;

  pUartBuf->RxFlag=0;
}
							
/*************************************************************************
 * Function Name: UART_Init
 * Parameters: LPC_UartChanel_t DevNum
 * 			
 * Return: int 
 *             	0: sucess
 *		1: fail
 * Description: Initialize Uart, configure baut rate, frame format and FIFO
 *  
 *************************************************************************/
int UART_Init (LPC_UartChanel_t DevNum)
{
unsigned long Divisor, Frame, FIFO;
LPC_Uart_Config_t *pConfig;

  if ( DevNum == UART0 )
    pConfig = &Uart0Config;
  else
    pConfig = &Uart1Config;

  if ((pConfig->BaudRate == 0) || (pConfig->BaudRate > BD115200))
    return 0;

  // baut rate
  Divisor = (SYS_GetFpclk() >>4) / pConfig->BaudRate; // Divisor = pclk / (16*bautrate)

  // frame format
  Frame = pConfig->WordLenth;
  if ( pConfig->TwoStopBitsSelect )
    Frame |= ( 1<<LCR_STOPBITSEL_BIT );
  if ( pConfig->ParityEnable )
  {
    Frame |= ( 1<<LCR_PARITYENBALE_BIT );
    Frame |= ( pConfig->ParitySelect<<LCR_PARITYSEL_BIT );
  }
  if ( pConfig->BreakEnable )
    Frame |= ( 1<<LCR_BREAKCONTROL_BIT );

  // FIFO
  if ( pConfig->FIFOEnable )
    FIFO = ((pConfig->FIFORxTriggerLevel & 0x3)<<6) | 0x1;

  // Method Mode
  if ( pConfig->MethodMode == INTERRUPT_MODE )
    UART_InitUartBuf (&pConfig->UartBuffer);
  if ( DevNum == UART0 )
  {
    // Set baut rate
    U0LCR_bit.DLAB = true;	// DLAB = 1
    U0DLM = Divisor >> 8;
    U0DLL = Divisor;

    // Set frame format
    U0LCR = Frame;	        // DLAB = 0

    // Set FIFO
    U0FCR = FIFO;

    // Set Interrupt Enable Register
    U0IER = pConfig->InterruptEnable & 0x5;

    // Enable TxD0 and RxD0, bit 0~3=0101
//    PINSEL0 |= 0x05;
    PINSEL0_bit.P0_0 = 0x1;
    PINSEL0_bit.P0_1 = 0x1;
  }
  else if ( DevNum == UART1 )
  {
    // Set baut rate
    U1LCR_bit.DLAB = true;      // DLAB = 1
    U1DLM = Divisor>>8;
    U1DLL = Divisor & 0xff;

    // Set frame format
    U1LCR = Frame;              // DLAB =0

    /* Set FIFO */
    U1FCR = FIFO;

    // Set Interrupt Enable Register
    U1IER = pConfig->InterruptEnable & 0x5;

    // Enable TxD0 and RxD0, bit 16~19=0101
//    PINSEL0 |= 0x50000;
    PINSEL0_bit.P0_8 = 0x1;
    PINSEL0_bit.P0_9 = 0x1;
  }
  else
    return 1;
  return 0;
}


/*************************************************************************
 * Function Name: UART_PutCharByPolling
 * Parameters: LPC_UartChanel_t DevNum
 * 	       char ch
 * Return: void
 *
 *
 * Description: Send character by polling LSR register
 *  
 *************************************************************************/
void UART_PutCharByPolling (LPC_UartChanel_t DevNum, char ch)
{
  if ( DevNum == UART0 )
  {
    while(!U0LSR_bit.THRE);
    U0THR = ch;
  }
  else
  {
    while(!U1LSR_bit.THRE);
    U1THR = ch;
  }
}

/*************************************************************************
 * Function Name: UART_PutStringByPolling
 * Parameters: LPC_UartChanel_t DevNum
 * 	       char *Buf
 * Return: int : send character count
 *
 *
 * Description: Send a string by using polling method 
 *  
 *************************************************************************/
int UART_PutStringByPolling(LPC_UartChanel_t DevNum, char *Buf)
{
char *pBuf = Buf ;
int SendCount = 0;
  while (*pBuf)
  {
    UART_PutCharByPolling(DevNum, *pBuf++);
    ++SendCount;
  }
  return (SendCount);
}

/*************************************************************************
 * Function Name: UART_GetCharByPolling
 * Parameters: LPC_UartChanel_t DevNum
 * Return: char 
 *
 * Description: Receive a character from Uart by polling LSR register
 *  
 *************************************************************************/
char UART_GetCharByPolling (LPC_UartChanel_t DevNum)
{
  if ( DevNum == UART0 )
  {
    while (!U0LSR_bit.DR);
    return (U0RBR);
  }
  while (!U1LSR_bit.DR);
  return (U1RBR);
}

/*************************************************************************
 * Function Name: UART_PutStringByInterrupt
 * Parameters: LPC_UartChanel_t DevNum
 *	       char *Buf
 * Return: int : send character count
 *
 * Description: Send a string into Uart Buffer. 
 * 		Then Uart will send buffer data in its IRQ subroutine.
 *  
 *************************************************************************/
int UART_PutStringByInterrupt (LPC_UartChanel_t DevNum, char *Buf)
{
char *pBuf = Buf, ch;
LPC_Uart_Buffer_t *pUartBuf;
int SendCount = 0;
unsigned long IntFlagsHold;

  if ( DevNum == UART0 )
    pUartBuf = &Uart0Config.UartBuffer;
  else
    pUartBuf = &Uart1Config.UartBuffer;
  while (*pBuf)
  {
    // if FIFO is full pending here, wait for send characters
    if (pUartBuf->TxCount >= TXBUFSIZE)
    {
      break;
    }
    ch = *pBuf & 0xff;    
    pUartBuf->TxBuf[pUartBuf->TxTailPoint] = ch;
    pUartBuf->TxTailPoint = (pUartBuf->TxTailPoint+1)%TXBUFSIZE;
    IntFlagsHold = disable_IRQ();
    pUartBuf->TxCount++;
    restore_IRQ(IntFlagsHold);
    SendCount++;
    pBuf++;
  }
  if (DevNum == UART0)
    U0IER |= IER_THRE;
  else
    U1IER |= IER_THRE;
  return SendCount;
}

/*************************************************************************
 * Function Name: UART_GetCharByInterrupt
 * Parameters:  LPC_UartChanel_t DevNum, char *ch
 * Return:  0 -  Rx FIFO is empty 
 *          1 - valid char
 * Description: Get character from Uart Port by making use of interrupt. At same time,
 *		the received data will be stored into its buffer.
 *  
 *************************************************************************/
char UART_GetCharByInterrupt (LPC_UartChanel_t DevNum, char* Buf)
{
LPC_Uart_Buffer_t *pUartBuf;
unsigned long IntFlagsHold;
  if (DevNum == UART0)
  {
    pUartBuf = &Uart0Config.UartBuffer;
  }
  else
  {
    pUartBuf = &Uart1Config.UartBuffer;
  }
  if (pUartBuf->RxCount == 0)
    return 0;
  *Buf = pUartBuf->RxBuf[pUartBuf->RxHeadPoint];
  pUartBuf->RxHeadPoint = (pUartBuf->RxHeadPoint+1)%RXBUFSIZE;
  IntFlagsHold = disable_IRQ();
  pUartBuf->RxCount--;
  restore_IRQ(IntFlagsHold);
  return 1;
}

/*************************************************************************
 * Function Name: UART_PutString
 * Parameters: LPC_UartChanel_t DevNum
 * 	       char *Buf
 * Return: int : send character count
 *
 *
 * Description: Send a string 
 *  
 *************************************************************************/
int UART_PutString(LPC_UartChanel_t DevNum, char *Buf)
{
LPC_Uart_MethodMode_t MethodMode;
  if ( DevNum == UART0 )
    MethodMode = Uart0Config.MethodMode;
  else
    MethodMode = Uart1Config.MethodMode;

  if (MethodMode)
    // interrupt method
    return(UART_PutStringByInterrupt(DevNum, Buf));
  // Polling method
  return(UART_PutStringByPolling(DevNum, Buf));
}

/*************************************************************************
 * Function Name: UART_GetChar
 * Parameters: LPC_UartChanel_t DevNum
 *
 * Return: char 
 *
 * Description: Receive a character from Uart.
 *  
 *************************************************************************/
char UART_GetChar(LPC_UartChanel_t DevNum)
{
LPC_Uart_MethodMode_t MethodMode;
char ch;
  if ( DevNum == UART0 )
    MethodMode = Uart0Config.MethodMode;
  else
    MethodMode = Uart1Config.MethodMode;

  if (MethodMode)
  {
    // interrupt method
    while(!UART_GetCharByInterrupt(DevNum,&ch));
    return(ch);
  }
  // Polling method
  return(UART_GetCharByPolling(DevNum));
}

/*************************************************************************
 * Function Name: UART_ReadTxBuf
 * Parameters: LPC_Uart_Buffer_t *pUartBuf
 *	       char *ch
 * Return: int : 1 one character or more
 *		 0 no character in buffer, means current Txcount = 0
 *
 * Description: Read a character from to Uart Buffer, which is only used by IRQ subroutine.
 *  
 *************************************************************************/
#pragma inline
static int UART_ReadTxBuf (LPC_Uart_Buffer_t *pUartBuf, char *ch)
{
  if (pUartBuf->TxCount == 0)
    return 0;
  *ch = pUartBuf->TxBuf[pUartBuf->TxHeadPoint];
  pUartBuf->TxHeadPoint = (pUartBuf->TxHeadPoint+1)%TXBUFSIZE;
  pUartBuf->TxCount--;
  return 1;
}

/*************************************************************************
 * Function Name: UART0_ISR
 * Parameters: void
 * Return: void
 *
 * Description: Uart0 interrupt subroutine
 *  
 *************************************************************************/
void UART0_ISR (void)
{
int i;
char temp;
LPC_Uart_Buffer_t *pUartBuf = &Uart0Config.UartBuffer;
  switch((U0IIR>>1)&0x7)
  {
  case IIR_THRE:  // continue sending data
    // Check for Transmitter FIFO enable
    if (Uart0Config.FIFOEnable) 
      // when FIFO is enable load FIFODEEP bytes
      i = FIFODEEP;
    else
      // when FIFO is disable load 1 byte
      i = 1;
    do
    {
      // Check for software FIFO state and load data into transmitter hold register
      // disable interups imediatly aftre write when FIFO is empty
      if(!UART_ReadTxBuf(pUartBuf, (char*)&U0THR) || (pUartBuf->TxCount == 0))
      {
        // Disable interrup when FIFO is empty
        U0IER_bit.THREIE = false;
        break;
      }
    }
    while(--i);
    break;
  case IIR_RSL:	// error manage
    temp = U0LSR;
    pUartBuf->RxFlag |= temp & 0x9E;
    break;
  case IIR_RDA:	// receive data
  case IIR_CTI:	// time out
    pUartBuf->RxBuf[pUartBuf->RxTailPoint] = U0RBR;
    pUartBuf->RxTailPoint = (pUartBuf->RxTailPoint+1)%RXBUFSIZE;
    // overflow
    if (++pUartBuf->RxCount > RXBUFSIZE)
    {
      pUartBuf->RxHeadPoint = pUartBuf->RxTailPoint;
      pUartBuf->RxFlag |= RC_FIFO_OVERRUN_ERR;
    }
    break;
  default:
    break;
  }
  VICVectAddr = 0;    // Clear interrupt in VIC.
}

/*************************************************************************
 * Function Name: UART1_ISR
 * Parameters: void
 * Return: void
 *
 * Description: Uart1 interrupt subroutine
 *  
 *************************************************************************/
void UART1_ISR (void)
{
int i;
char temp;
LPC_Uart_Buffer_t *pUartBuf = &Uart1Config.UartBuffer;
  switch((U1IIR>>1)&0x7)
  {
  case IIR_THRE:  // continue sending data
    // Check for Transmitter FIFO enable
    if (Uart1Config.FIFOEnable) 
      // when FIFO is enable load FIFODEEP bytes
      i = FIFODEEP;
    else
      // when FIFO is disable load 1 byte
      i = 1;
    do
    {
      // Check for software FIFO state and load data into transmitter hold register
      // disable interups imediatly aftre write when FIFO is empty
      if(!UART_ReadTxBuf(pUartBuf, (char*)&U1THR) || (pUartBuf->TxCount == 0))
      {
        // Disable interrup when FIFO is empty
        U1IER_bit.THREIE = false;
        break;
      }
    }
    while(--i);
    break;
  case IIR_RSL:	// error manage
    temp = U1LSR;
    pUartBuf->RxFlag |= temp & 0x9E;
    break;
  case IIR_RDA:	// receive data
  case IIR_CTI:	// time out
    pUartBuf->RxBuf[pUartBuf->RxTailPoint] = U1RBR;
    if (++pUartBuf->RxCount > RXBUFSIZE)
    {
      pUartBuf->RxFlag |= RC_FIFO_OVERRUN_ERR;
    }
    pUartBuf->RxTailPoint = (pUartBuf->RxTailPoint+1)%RXBUFSIZE;
    break;
  default:
    break;
  }
  VICVectAddr = 0;    // Clear interrupt in VIC.
}
