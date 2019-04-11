/*********************************************************************
*              SEGGER MICROCONTROLLER SYSTEME GmbH                   *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*           (c) 2006  SEGGER Microcontroller Systeme GmbH            *
*                                                                    *
*      Internet: www.segger.com   Support: support@segger.com        *
*                                                                    *
**********************************************************************
----------------------------------------------------------------------
File    : JLINKDCC.h
Purpose : Header file for J-Link ARM type DCC communication
---------------------------END-OF-HEADER------------------------------
*/

#ifndef JLINKDCC_H
#define JLINKDCC_H             // Avoid multiple inclusion

void JLINKDCC_Process(void);
void JLINKDCC_HandleDataAbort(void);
void JLINKDCC_SendString(const char * s);
void JLINKDCC_SendChar(char c);
void JLINKDCC_SendOnChannel      (unsigned Channel, unsigned char* pData, int NumItems);
void JLINKDCC_SetpfOnRx          (unsigned Channel, void          (* pf)(unsigned Channel, unsigned char c));
void JLINKDCC_SetpfOnTx          (unsigned Channel, void          (* pf)(unsigned Channel));
void JLINKDCC_SendCharOnChannelNB(unsigned Channel, unsigned char Data);

#endif                         // Avoid multiple inclusion

/*************************** end of file ****************************/

