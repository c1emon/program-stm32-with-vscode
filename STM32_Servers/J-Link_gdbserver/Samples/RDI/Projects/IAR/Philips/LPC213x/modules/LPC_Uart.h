#ifndef __LPC_UART_H
#define __LPC_UART_H

/*************************************************************************
 *
 *    Used with ICCARM and AARM.
 *
 *    (c) Copyright IAR Systems 2003
 *
 *    File name   : LPC_Uart.h
 *    Description : 
 *
 *    History :
 *    1. Data: July 13, 2004                                              
 *       Author: Shawn Zhang                                                    
 *       Description: Create
 *
 *    2. Data        : Oct 9, 2004 
 *       Author      : Stanimir Bonev
 *       Description : Modify
 *
 *    $Revision: 1.1 $
 **************************************************************************/

#include <includes.h>
#include <lpc_uart_cnfg.h>

#define FIFODEEP    16

#define BD115200    115200
#define BD38400     38400
#define BD9600      9600

#define CR          0x0D
#define LF          0x0A

/* Uart line control register bit descriptions */
#define LCR_WORDLENTH_BIT         0
#define LCR_STOPBITSEL_BIT        2
#define LCR_PARITYENBALE_BIT      3
#define LCR_PARITYSEL_BIT         4
#define LCR_BREAKCONTROL_BIT      6
#define LCR_DLAB_BIT              7

/* Uart Interrupt Identification */
#define IIR_RSL                   0x3
#define IIR_RDA                   0x2
#define IIR_CTI                   0x6
#define IIR_THRE                  0x1

/* Uart Interrupt Enable Type*/
#define IER_RBR                   0x1
#define IER_THRE                  0x2
#define IER_RLS                   0x4

/* Uart Receiver Errors*/
#define RC_FIFO_OVERRUN_ERR       0x1
#define RC_OVERRUN_ERR            0x2
#define RC_PARITY_ERR             0x4
#define RC_FRAMING_ERR            0x8
#define RC_BREAK_IND              0x10

typedef enum {
  UART0 = 0,
  UART1
} LPC_UartChanel_t;

 // Word Lenth type
typedef enum {
    WordLength5 = 0,
    WordLength6,
    WordLength7,
    WordLength8
} LPC_Uart_WordLenth_t;

// Parity Select type
typedef enum {
    ParitySelOdd = 0,
    ParitySelEven,
    ParitySelStickHigh,
    ParitySelEvenLow
} LPC_Uart_ParitySelect_t;

// FIFO Rx Trigger Level type
typedef enum {
    FIFORXLEV0 = 0,	// 0x1
    FIFORXLEV1,		// 0x4
    FIFORXLEV2,		// 0x8
    FIFORXLEV3		// 0xe
} LPC_Uart_FIFORxTriggerLevel_t;

// Send and Receive data method mode
typedef enum {
    POLLING_MODE = 0,	
    INTERRUPT_MODE
} LPC_Uart_MethodMode_t;

typedef struct {
	char RxBuf[RXBUFSIZE];
	char TxBuf[TXBUFSIZE];
	
	int RxHeadPoint;
	int RxTailPoint;
	
	int TxHeadPoint;
	int TxTailPoint;
	
	int RxCount;
	int TxCount;

	volatile int RxFlag;
}LPC_Uart_Buffer_t;

typedef struct {
	unsigned long BaudRate;	        // Baud Rate
	
	LPC_Uart_WordLenth_t WordLenth;	// Frame format
	bool TwoStopBitsSelect;
	bool ParityEnable;
	LPC_Uart_ParitySelect_t ParitySelect;
	bool BreakEnable;

	bool FIFOEnable;
	int FIFORxTriggerLevel;

	unsigned long InterruptEnable ;	// Interrupt Type: RBR, THRE, RLS

	LPC_Uart_MethodMode_t MethodMode;
	LPC_Uart_Buffer_t  UartBuffer;
	
} LPC_Uart_Config_t;

/* Declare functions */
int UART_Init (LPC_UartChanel_t DevNum);
int UART_PutString(LPC_UartChanel_t DevNum, char *Buf);
char UART_GetChar(LPC_UartChanel_t DevNum);

void UART_PutCharByPolling (LPC_UartChanel_t DevNum, char ch);
int UART_PutStringByPolling(LPC_UartChanel_t DevNum, char *Buf);
char UART_GetCharByPolling (LPC_UartChanel_t DevNum);

int UART_PutStringByInterrupt (LPC_UartChanel_t DevNum, char *Buf);
char UART_GetCharByInterrupt (LPC_UartChanel_t DevNum, char *ch);

void UART0_ISR (void);
void UART1_ISR (void);

#endif //__LPC_UART_H
