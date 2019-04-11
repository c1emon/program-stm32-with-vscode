/**********************************************************
*          SEGGER MICROCONTROLLER SYSTEME GmbH
*   Solutions for real time microcontroller applications
***********************************************************
*
* File    : JLINKDCC_Process_ASM.s
* Purpose : Routines for setting and writing co-processor register CP14 
            (DCC-communication)
--------- END-OF-HEADER ---------------------------------
*/

/*********************************************************************
*
*       GNU ARM
*
*/
        .text
        .global  CP14_ReadDCCStat
        .global  CP14_ReadDCC
        .global  CP14_WriteDCC
        .arm
        .section .text, "ax" 

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/

/*********************************************************************
*
*       CP14_ReadDCCStat
*/
CP14_ReadDCCStat:
  mrc P14,0,R0,C0,C0,0
  bx lr


/*********************************************************************
*
*       CP14_ReadDCC
*/
CP14_ReadDCC:
  mrc P14,0,R0,C1,C0,0
  bx lr

/*********************************************************************
*
*       CP14_WriteDCC
*/
CP14_WriteDCC:
  mcr P14,0,R0,C1,C0,0
  bx lr
  
  .end
/**************************** End of file ***************************/
