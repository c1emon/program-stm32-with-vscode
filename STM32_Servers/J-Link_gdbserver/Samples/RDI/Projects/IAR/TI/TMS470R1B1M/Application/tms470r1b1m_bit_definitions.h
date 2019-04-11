//###########################################################################
//
// FILE:   tms470r1_bit_definitions.h
//
// TITLE:  TMS470R1 Device Bit Definitions.
//
//###########################################################################
//
//  Ver  | dd mmm yyyy | Who  | Description of changes
// ======|=============|======|==============================================
//  0.01 | 14 Aug 2005 | J.M. | Created
//       |             |      |
//       |             |      |
// The following signals were inconfict with other desigantions andd required
// unique names which included the module.
//
//  HETGCR_POWERDOWN    CAN_TXDIR     CAN_RXDIR
//  SCI_POWERDOWN       C2_TXDIR      C2_RXDIR
//  SPI_POWERDOWN
//
//  Texas Instruments, Inc
//  Copyright Texas Instruments 2005 . All rights reserved.
//###########################################################################

#ifndef tms470r1b1m_bit_definitions_H
#define tms470r1b1m_bit_definitions_H

#ifdef __cplusplus
extern "C" {
#endif



//***********************************************************************************
// C2SIA Module and C2SIB Module Same definitions for both modules
//-------------------------------------------------
// C2SIA C2SIAISR Interrupt Status Register bit definitions
//
//  C2SIAISR_BITS
#define   RBFIF        ((unsigned int) 0x1 <<  0) // 0      Receive buffer full interrupt flag
#define   BRKIF        ((unsigned int) 0x1 <<  1) // 1      Receive break interrupt flag
#define   RCCIF        ((unsigned int) 0x1 <<  2) // 2      Receive completion code interrupt flag
#define   RXOIF        ((unsigned int) 0x1 <<  3) // 3      Receive over-run interrupt flag
#define   TXUOIF       ((unsigned int) 0x1 <<  4) // 4      Transmit under-run/over-run interrupt flag
#define   TBEIF        ((unsigned int) 0x1 <<  5) // 5      Transmit buffer empty interrupt flag
#define   TIDLIF       ((unsigned int) 0x1 <<  6) // 6      Transmit idle interrupt flag
#define   ARBIF        ((unsigned int) 0x1 <<  7) // 7      Transmit arbitration lost interrupt flag

//-------------------------------------------------
// C2SIA C2SIAICR Interrupt Control Register bit definitions
//
// C2SIAICR_BITS
#define   RBFIE        ((unsigned int) 0x1 <<  0) // 0      Receive buffer full interrupt enable
#define   BRKIE        ((unsigned int) 0x1 <<  1) // 1      Receive break interrupt enable
#define   RCCIE        ((unsigned int) 0x1 <<  2) // 2      Receive completion code interrupt enable
#define   RXOIE        ((unsigned int) 0x1 <<  3) // 3      Receive over-run interrupt enable
#define   TXUOIE       ((unsigned int) 0x1 <<  4) // 4      Transmit under-run/over-run interrupt enable
#define   TBEIE        ((unsigned int) 0x1 <<  5) // 5      Transmit buffer empty interrupt enable
#define   TIDLIE       ((unsigned int) 0x1 <<  6) // 6      Transmit idle interrupt enable
#define   ARBIE        ((unsigned int) 0x1 <<  7) // 7      Transmit arbitration lost interrupt enable

//-------------------------------------------------
// C2SIA C2SIAGSR Global Status Register bit definitions
//
//  C2SIAGSR_BITS
#define   WAKE         ((unsigned int) 0x1 <<  0) // 0      Wake-up from low power mode status flag
#define   NOISE        ((unsigned int) 0x1 <<  1) // 1      Noise detected on C2Sia data link flag
#define   SHORTGND     ((unsigned int) 0x1 <<  2) // 2      Short to ground detected
#define   IDLE         ((unsigned int) 0x1 <<  3) // 3      Data link idle flag
#define   RIFR         ((unsigned int) 0x1 <<  4) // 4      Receive In-frame response control bit
#define   TXERROR      ((unsigned int) 0x1 <<  5) // 5      Transmission error found

//-------------------------------------------------
// C2SIA C2SIAGCR Global Control Register bit definitions
//
//  C2SIAGCR_BITS
#define   ENWAKE       ((unsigned int) 0x1 <<  0) // 0      Wake-up enable
#define   TIFR         ((unsigned int) 0x1 <<  1) // 1      Transmit in-frame response control bit
#define   TBRK         ((unsigned int) 0x1 <<  2) // 2      Transmit break sequence control bit
#define   TXRESET      ((unsigned int) 0x1 <<  3) // 3      Transmit reset
#define   NBPOL        ((unsigned int) 0x1 <<  4) // 4      Normalization bit polarity control bit
#define   T2IFR        ((unsigned int) 0x1 <<  5) // 5      Type 2 in-frame response control bit
#define   MODE4X       ((unsigned int) 0x1 <<  6) // 6      4X mode control bit
#define   CRCDIS       ((unsigned int) 0x1 <<  7) // 7      CRC disable

//-------------------------------------------------
// C2SIA C2SIACCSR Completion Code Status Register bit definitions
//
// C2SIACCSR_BITS
#define   IFRCRC      ((unsigned int) 0x1 <<  0) // 0      Receiver in-frame response with a CRC flag
#define   IFR         ((unsigned int) 0x1 <<  1) // 1      Receiver in-frame response flag
#define   BREAK       ((unsigned int) 0x1 <<  2) // 2      Receiver break sequence flag
#define   XMITOK      ((unsigned int) 0x1 <<  3) // 3      Received transmitted message and transmit was OK flag
#define   CRCERR      ((unsigned int) 0x1 <<  4) // 4      Received message CRC error flag
#define   BYTERR      ((unsigned int) 0x1 <<  5) // 5      Received an incomplete byte error flag
#define   BITERR      ((unsigned int) 0x1 <<  6) // 6      Received an improperly timed bit error flag
#define   ROVR        ((unsigned int) 0x1 <<  7) // 7      Receive completion code over-run flag

//-------------------------------------------------
// C2SIA C2SIACTR Completion Code Status Register bit definitions
//
//  C2SIACTR_BITS
#define   LPM          ((unsigned int) 0x1 <<  0) // 0      Low power mode
#define   ESPEN        ((unsigned int) 0x1 <<  1) // 1      Emulator suspend
#define   RXDMAEN      ((unsigned int) 0x1 <<  2) // 2      Receive DMA enable
#define   TXDMAEN      ((unsigned int) 0x1 <<  3) // 3      Transmit DMA enable
#define   SOFX         ((unsigned int) 0x1 <<  4) // 4      SOF behavior
#define   LPEN         ((unsigned int) 0x1 <<  5) // 5      Loopback enable
#define   CALEN        ((unsigned int) 0x1 <<  6) // 6      Auto calibration enable
#define   LONGBRK      ((unsigned int) 0x1 <<  7) // 7      Long break symbol length

//-------------------------------------------------
// C2SIA C2SIAPC1 Pin Control Register 1 bit definitions
//
//  C2SIAPC1_BITS
#define   LPDIR     ((unsigned int) 0x1 <<  0) // 0      Loopback pin direction select
#define   C2_RXDIR     ((unsigned int) 0x1 <<  1) // 1      Receive pin direction select
#define   C2_TXDIR     ((unsigned int) 0x1 <<  2) // 2      Transmit pin direction select
#define   LPFUN     ((unsigned int) 0x1 <<  3) // 3      Loopback pin function select
#define   RXFUN     ((unsigned int) 0x1 <<  4) // 4      Receive pin function select
#define   TXFUN     ((unsigned int) 0x1 <<  5) // 5      Transmit pin function select
#define   RXPOL     ((unsigned int) 0x1 <<  6) // 6      Receive pin polarity select
#define   TXPOL     ((unsigned int) 0x1 <<  7) // 7      Transmit pin polarity select

//-------------------------------------------------
// C2SIA C2SIAPC2 Pin Control Register 2 bit definitions
//
//  C2SIAPC2_BITS
#define   LPDOUT       ((unsigned int) 0x1 <<  0) // 0      Loopback data out
#define   RXDOUT       ((unsigned int) 0x1 <<  1) // 1      Receive data out
#define   TXDOUT       ((unsigned int) 0x1 <<  2) // 2      Transmit data out

//-------------------------------------------------
// C2SIA C2SIAPC3 Pin Control Register 3 bit definitions
//
//  C2SIAPC3_BITS
#define   LPDIN        ((unsigned int) 0x1 <<  0) // 0      Loopback data in
#define   RXDIN        ((unsigned int) 0x1 <<  1) // 1      Receive data in
#define   TXDIN        ((unsigned int) 0x1 <<  2) // 2      Transmit data in

//-------------------------------------------------
// C2SIA C2SIACAL Calibration Control Register bit definitions
//
//  C2SIACAL_BITS
#define   ARBTYPE      ((unsigned int) 0x1 <<  7) // 7      Arbitration type

//-------------------------------------------------
// C2SIA C2SIABRK Break Status Register bit definitions
//
//  C2SIABRK_BITS
#define   INBREAK      ((unsigned int) 0x1 <<  0) // 0      Break status
#define   BREAKEND     ((unsigned int) 0x1 <<  1) // 1      End of break found


//******************************************************************************************
// GIO Module
//-------------------------------------------------
// GIO GIOPWDN GIO Power Down Register bit definitions
//
//  GIOPWDN_BITS
#define   GIOPWDN                ((unsigned int) 0x1 <<  0) // 0      GIO power down

//-------------------------------------------------
// GIO GIOENA1, GIOPOL1, GIOFLG1 and GIOPRY1  GIO Interrupt Enable Register bit definitions
//

#define   A0             ((unsigned int) 0x1 <<  0) // 0      Pin interrupt enable
#define   A1             ((unsigned int) 0x1 <<  1) // 1      Pin interrupt enable
#define   A2             ((unsigned int) 0x1 <<  2) // 2      Pin interrupt enable
#define   A3             ((unsigned int) 0x1 <<  3) // 3      Pin interrupt enable
#define   A4             ((unsigned int) 0x1 <<  4) // 4      Pin interrupt enable
#define   A5             ((unsigned int) 0x1 <<  5) // 5      Pin interrupt enable
#define   A6             ((unsigned int) 0x1 <<  6) // 6      Pin interrupt enable
#define   A7             ((unsigned int) 0x1 <<  7) // 7      Pin interrupt enable
#define   B0             ((unsigned int) 0x1 <<  8) // 8      Pin interrupt enable
#define   B1             ((unsigned int) 0x1 <<  9) // 9      Pin interrupt enable
#define   B2             ((unsigned int) 0x1 <<  10) // 10     Pin interrupt enable
#define   B3             ((unsigned int) 0x1 <<  11) // 11     Pin interrupt enable
#define   B4             ((unsigned int) 0x1 <<  12) // 12     Pin interrupt enable
#define   B5             ((unsigned int) 0x1 <<  13) // 13     Pin interrupt enable
#define   B6             ((unsigned int) 0x1 <<  14) // 14     Pin interrupt enable
#define   B7             ((unsigned int) 0x1 <<  15) // 15     Pin interrupt enable
#define   C0             ((unsigned int) 0x1 <<  16) // 16     Pin interrupt enable
#define   C1             ((unsigned int) 0x1 <<  17) // 17     Pin interrupt enable
#define   C2             ((unsigned int) 0x1 <<  18) // 18     Pin interrupt enable
#define   C3             ((unsigned int) 0x1 <<  19) // 19     Pin interrupt enable
#define   C4             ((unsigned int) 0x1 <<  20) // 20     Pin interrupt enable
#define   C5             ((unsigned int) 0x1 <<  21) // 21     Pin interrupt enable
#define   C6             ((unsigned int) 0x1 <<  22) // 22     Pin interrupt enable
#define   C7             ((unsigned int) 0x1 <<  23) // 23     Pin interrupt enable
#define   D0             ((unsigned int) 0x1 <<  24) // 24     Pin interrupt enable
#define   D1             ((unsigned int) 0x1 <<  25) // 25     Pin interrupt enable
#define   D2             ((unsigned int) 0x1 <<  26) // 26     Pin interrupt enable
#define   D3             ((unsigned int) 0x1 <<  27) // 27     Pin interrupt enable
#define   D4             ((unsigned int) 0x1 <<  28) // 28     Pin interrupt enable
#define   D5             ((unsigned int) 0x1 <<  29) // 29     Pin interrupt enable
#define   D6             ((unsigned int) 0x1 <<  30) // 30     Pin interrupt enable
#define   D7             ((unsigned int) 0x1 <<  31) // 31     Pin interrupt enable



//-------------------------------------------------
// GIO GIODIRx , GIODINx, GIODOUTx ,GIODSETx and GIODCLRA GIO Data Direction Register bit definitions
//

#define   X0             ((unsigned int) 0x1 <<  0) // 0      Port x, pin 0
#define   X1             ((unsigned int) 0x1 <<  1) // 1      Port x, pin 1
#define   X2             ((unsigned int) 0x1 <<  2) // 2      Port x, pin 2
#define   X3             ((unsigned int) 0x1 <<  3) // 3      Port x, pin 3
#define   X4             ((unsigned int) 0x1 <<  4) // 4      Port x, pin 4
#define   X5             ((unsigned int) 0x1 <<  5) // 5      Port x, pin 5
#define   X6             ((unsigned int) 0x1 <<  6) // 6      Port x, pin 6
#define   X7             ((unsigned int) 0x1 <<  7) // 7      Port x, pin 7



//-------------------------------------------------
// GIO GIOENA2, GIOPOL2, GIOFLG2 and GIOPRY2 GIO Interrupt Enable Register bit definitions
//

#define   E0             ((unsigned int) 0x1 <<  0) // 0      Pin interrupt enable
#define   E1             ((unsigned int) 0x1 <<  1) // 1      Pin interrupt enable
#define   E2             ((unsigned int) 0x1 <<  2) // 2      Pin interrupt enable
#define   E3             ((unsigned int) 0x1 <<  3) // 3      Pin interrupt enable
#define   E4             ((unsigned int) 0x1 <<  4) // 4      Pin interrupt enable
#define   E5             ((unsigned int) 0x1 <<  5) // 5      Pin interrupt enable
#define   E6             ((unsigned int) 0x1 <<  6) // 6      Pin interrupt enable
#define   E7             ((unsigned int) 0x1 <<  7) // 7      Pin interrupt enable
#define   F0             ((unsigned int) 0x1 <<  8) // 8      Pin interrupt enable
#define   F1             ((unsigned int) 0x1 <<  9) // 9      Pin interrupt enable
#define   F2             ((unsigned int) 0x1 <<  10) // 10     Pin interrupt enable
#define   F3             ((unsigned int) 0x1 <<  11) // 11     Pin interrupt enable
#define   F4             ((unsigned int) 0x1 <<  12) // 12     Pin interrupt enable
#define   F5             ((unsigned int) 0x1 <<  13) // 13     Pin interrupt enable
#define   F6             ((unsigned int) 0x1 <<  14) // 14     Pin interrupt enable
#define   F7             ((unsigned int) 0x1 <<  15) // 15     Pin interrupt enable
#define   G0             ((unsigned int) 0x1 <<  16) // 16     Pin interrupt enable
#define   G1             ((unsigned int) 0x1 <<  17) // 17     Pin interrupt enable
#define   G2             ((unsigned int) 0x1 <<  18) // 18     Pin interrupt enable
#define   G3             ((unsigned int) 0x1 <<  19) // 19     Pin interrupt enable
#define   G4             ((unsigned int) 0x1 <<  20) // 20     Pin interrupt enable
#define   G5             ((unsigned int) 0x1 <<  21) // 21     Pin interrupt enable
#define   G6             ((unsigned int) 0x1 <<  22) // 22     Pin interrupt enable
#define   G7             ((unsigned int) 0x1 <<  23) // 23     Pin interrupt enable
#define   H0             ((unsigned int) 0x1 <<  24) // 24     Pin interrupt enable
#define   H1             ((unsigned int) 0x1 <<  25) // 25     Pin interrupt enable
#define   H2             ((unsigned int) 0x1 <<  26) // 26     Pin interrupt enable
#define   H3             ((unsigned int) 0x1 <<  27) // 27     Pin interrupt enable
#define   H4             ((unsigned int) 0x1 <<  28) // 28     Pin interrupt enable
#define   H5             ((unsigned int) 0x1 <<  29) // 29     Pin interrupt enable
#define   H6             ((unsigned int) 0x1 <<  30) // 30     Pin interrupt enable
#define   H7             ((unsigned int) 0x1 <<  31) // 31     Pin interrupt enable

//-------------------------------------------------
// External Clock Prescaler (ECP) Control Register bit definitions
//
//  ECPCTRL_BITS
#define   ECPCOS                 ((unsigned int) 0x1 <<  8) // 8      ECP continue on suspend
#define   ECPEN                  ((unsigned int) 0x1 <<  15) // 15     ECP enable




//*****************************************************************************************
// HET Module
//-------------------------------------------------
// HET HETGCR Global Configuration Register bit definitions
//
// HETGCR_BITS
#define   ON                        ((unsigned int) 0x1 <<  0)  // 0      HET turn on/off
#define   IGNORE_SUSPEND            ((unsigned int) 0x1 <<  1)  // 1      Ignore suspend flag
#define   DEBUG_STATUS              ((unsigned int) 0x1 <<  2)  // 2      Debug status flag
#define   ACCESS64                  ((unsigned int) 0x1 <<  8)  // 8      64-bit access
#define   CLK_MASTER                ((unsigned int) 0x1 <<  16)  // 16     Clock master/slave
#define   HETGCR_POWERDOWN          ((unsigned int) 0x1 <<  24)  // 24     Power-down mode

//-------------------------------------------------
//  HET HETPFR Prescale Factor Register bit definitions
//
// HETPFR_BITS
#define   HRPRES_FACTOR_1           ((unsigned int) 0x0 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_2           ((unsigned int) 0x1 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_3           ((unsigned int) 0x2 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_4           ((unsigned int) 0x3 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_5           ((unsigned int) 0x4 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_6           ((unsigned int) 0x5 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_7           ((unsigned int) 0x6 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_8           ((unsigned int) 0x7 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_9           ((unsigned int) 0x8 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_10          ((unsigned int) 0x9 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_11          ((unsigned int) 0x0A <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_12          ((unsigned int) 0x0B <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_13          ((unsigned int) 0x0C <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_14          ((unsigned int) 0x0D <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_15          ((unsigned int) 0x0E <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_16          ((unsigned int) 0x0F <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_17          ((unsigned int) 0x10 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_18          ((unsigned int) 0x11 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_19          ((unsigned int) 0x12 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_20          ((unsigned int) 0x13 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_21          ((unsigned int) 0x14 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_22          ((unsigned int) 0x15 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_23          ((unsigned int) 0x16 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_24          ((unsigned int) 0x17 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_25          ((unsigned int) 0x18 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_26          ((unsigned int) 0x19 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_27          ((unsigned int) 0x1A <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_28          ((unsigned int) 0x1B <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_29          ((unsigned int) 0x1C <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_30          ((unsigned int) 0x1D <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_31          ((unsigned int) 0x1E <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_32          ((unsigned int) 0x1F <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_33          ((unsigned int) 0x20 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_34          ((unsigned int) 0x21 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_35          ((unsigned int) 0x22 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_36          ((unsigned int) 0x23 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_37          ((unsigned int) 0x24 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_38          ((unsigned int) 0x25 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_39          ((unsigned int) 0x26 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_40          ((unsigned int) 0x27 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_41          ((unsigned int) 0x28 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_42          ((unsigned int) 0x29 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_43          ((unsigned int) 0x2A <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_44          ((unsigned int) 0x2B <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_45          ((unsigned int) 0x2C <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_46          ((unsigned int) 0x2D <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_47          ((unsigned int) 0x2E <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_48          ((unsigned int) 0x2F <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_49          ((unsigned int) 0x30 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_50          ((unsigned int) 0x31 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_51          ((unsigned int) 0x32 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_52          ((unsigned int) 0x33 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_53          ((unsigned int) 0x34 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_54          ((unsigned int) 0x35 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_55          ((unsigned int) 0x36 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_56          ((unsigned int) 0x37 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_57          ((unsigned int) 0x38 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_58          ((unsigned int) 0x39 <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_59          ((unsigned int) 0x3A <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_60          ((unsigned int) 0x3B <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_61          ((unsigned int) 0x3C <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_62          ((unsigned int) 0x3D <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_63          ((unsigned int) 0x3E <<  0)  // 5:0    HR prescale factor code
#define   HRPRES_FACTOR_64          ((unsigned int) 0x3F <<  0)  // 5:0    HR prescale factor code
#define   LRPRES_FACTOR_1           ((unsigned int) 0x0 <<  8)  // 10:8   Loop resolution pre-scale factor code
#define   LRPRES_FACTOR_2           ((unsigned int) 0x1 <<  8)  // 10:8   Loop resolution pre-scale factor code
#define   LRPRES_FACTOR_4           ((unsigned int) 0x2 <<  8)  // 10:8   Loop resolution pre-scale factor code
#define   LRPRES_FACTOR_8           ((unsigned int) 0x3 <<  8)  // 10:8   Loop resolution pre-scale factor code
#define   LRPRES_FACTOR_16          ((unsigned int) 0x4 <<  8)  // 10:8   Loop resolution pre-scale factor code
#define   LRPRES_FACTOR_32          ((unsigned int) 0x5 <<  8)  // 10:8   Loop resolution pre-scale factor code

//-------------------------------------------------
//  HET HETEXC1 Exception Control Register bit definitions
//
// HETEXC1_BITS
#define   PRGM_OVRFL_PRY           ((unsigned int) 0x1 <<  0)  // 0      Program overflow exception priority
#define   APCNT_UNDRFL_PRY         ((unsigned int) 0x1 <<  1)  // 1      Angle period counter underflow exception priority
#define   APCNT_OVRFL_PRY          ((unsigned int) 0x1 <<  2)  // 2      Angle period counter overflow exception priority
#define   PRGM_OVRFL_ENA           ((unsigned int) 0x1 <<  8)  // 8      Program overflow exception enable
#define   APCNT_UNDRFL_ENA         ((unsigned int) 0x1 <<  16)  // 16     Angle period counter underflow exception enable
#define   APCNT_OVRFL_ENA          ((unsigned int) 0x1 <<  24)  // 24     Angle period counter overflow exception enable

//-------------------------------------------------
//  HET HETEXC2 Exception Control Register bit definitions
//
// HETEXC2_BITS
#define   PRGM_OVRFL_FLG            ((unsigned int) 0x1 <<  0)  // 0      Program overflow exception flag
#define   APCNT_UNDRFL_FLG          ((unsigned int) 0x1 <<  1)  // 1      Angle period counter underflow exception flag
#define   APCNT_OVRFL_FLG           ((unsigned int) 0x1 <<  2)  // 2      Angle period counter overflow exception flag

//-------------------------------------------------
//  HET HETPRY Interrupt Priority Register bit definitions
//
// HETPRY_BITS
#define   HETPRY0                          ((unsigned int) 0x1 <<  0)  // 0      HET interrupt source 0 priority
#define   HETPRY1                          ((unsigned int) 0x1 <<  1)  // 1      HET interrupt source 1 priority
#define   HETPRY2                          ((unsigned int) 0x1 <<  2)  // 2      HET interrupt source 2 priority
#define   HETPRY3                          ((unsigned int) 0x1 <<  3)  // 3      HET interrupt source 3 priority
#define   HETPRY4                          ((unsigned int) 0x1 <<  4)  // 4      HET interrupt source 4 priority
#define   HETPRY5                          ((unsigned int) 0x1 <<  5)  // 5      HET interrupt source 5 priority
#define   HETPRY6                          ((unsigned int) 0x1 <<  6)  // 6      HET interrupt source 6 priority
#define   HETPRY7                          ((unsigned int) 0x1 <<  7)  // 7      HET interrupt source 7 priority
#define   HETPRY8                          ((unsigned int) 0x1 <<  8)  // 8      HET interrupt source 8 priority
#define   HETPRY9                          ((unsigned int) 0x1 <<  9)  // 9      HET interrupt source 9 priority
#define   HETPRY10                         ((unsigned int) 0x1 <<  10)  // 10     HET interrupt source 10 priority
#define   HETPRY11                         ((unsigned int) 0x1 <<  11)  // 11     HET interrupt source 11 priority
#define   HETPRY12                         ((unsigned int) 0x1 <<  12)  // 12     HET interrupt source 12 priority
#define   HETPRY13                         ((unsigned int) 0x1 <<  13)  // 13     HET interrupt source 13 priority
#define   HETPRY14                         ((unsigned int) 0x1 <<  14)  // 14     HET interrupt source 14 priority
#define   HETPRY15                         ((unsigned int) 0x1 <<  15)  // 15     HET interrupt source 15 priority
#define   HETPRY16                         ((unsigned int) 0x1 <<  16)  // 16     HET interrupt source 16 priority
#define   HETPRY17                         ((unsigned int) 0x1 <<  17)  // 17     HET interrupt source 17 priority
#define   HETPRY18                         ((unsigned int) 0x1 <<  18)  // 18     HET interrupt source 18 priority
#define   HETPRY19                         ((unsigned int) 0x1 <<  19)  // 19     HET interrupt source 19 priority
#define   HETPRY20                         ((unsigned int) 0x1 <<  20)  // 20     HET interrupt source 20 priority
#define   HETPRY21                         ((unsigned int) 0x1 <<  21)  // 21     HET interrupt source 21 priority
#define   HETPRY22                         ((unsigned int) 0x1 <<  22)  // 22     HET interrupt source 22 priority
#define   HETPRY23                         ((unsigned int) 0x1 <<  23)  // 23     HET interrupt source 23 priority
#define   HETPRY24                         ((unsigned int) 0x1 <<  24)  // 24     HET interrupt source 24 priority
#define   HETPRY25                         ((unsigned int) 0x1 <<  25)  // 25     HET interrupt source 25 priority
#define   HETPRY26                         ((unsigned int) 0x1 <<  26)  // 26     HET interrupt source 26 priority
#define   HETPRY27                         ((unsigned int) 0x1 <<  27)  // 27     HET interrupt source 27 priority
#define   HETPRY28                         ((unsigned int) 0x1 <<  28)  // 28     HET interrupt source 28 priority
#define   HETPRY29                         ((unsigned int) 0x1 <<  29)  // 29     HET interrupt source 29 priority
#define   HETPRY30                         ((unsigned int) 0x1 <<  30)  // 30     HET interrupt source 30 priority
#define   HETPRY31                         ((unsigned int) 0x1 <<  31)  // 31     HET interrupt source 31 priority

//-------------------------------------------------
//  HET HETPFLG Interrupt FLAG Register bit definitions
//
// HETFLG_BITS

#define   HETFLG0                          ((unsigned int) 0x1 <<  0)  // 0      HET interrupt source 0 flag
#define   HETFLG1                          ((unsigned int) 0x1 <<  1)  // 1      HET interrupt source 1 flag
#define   HETFLG2                          ((unsigned int) 0x1 <<  2)  // 2      HET interrupt source 2 flag
#define   HETFLG3                          ((unsigned int) 0x1 <<  3)  // 3      HET interrupt source 3 flag
#define   HETFLG4                          ((unsigned int) 0x1 <<  4)  // 4      HET interrupt source 4 flag
#define   HETFLG5                          ((unsigned int) 0x1 <<  5)  // 5      HET interrupt source 5 flag
#define   HETFLG6                          ((unsigned int) 0x1 <<  6)  // 6      HET interrupt source 6 flag
#define   HETFLG7                          ((unsigned int) 0x1 <<  7)  // 7      HET interrupt source 7 flag
#define   HETFLG8                          ((unsigned int) 0x1 <<  8)  // 8      HET interrupt source 8 flag
#define   HETFLG9                          ((unsigned int) 0x1 <<  9)  // 9      HET interrupt source 9 flag
#define   HETFLG10                         ((unsigned int) 0x1 <<  10)  // 10     HET interrupt source 10 flag
#define   HETFLG11                         ((unsigned int) 0x1 <<  11)  // 11     HET interrupt source 11 flag
#define   HETFLG12                         ((unsigned int) 0x1 <<  12)  // 12     HET interrupt source 12 flag
#define   HETFLG13                         ((unsigned int) 0x1 <<  13)  // 13     HET interrupt source 13 flag
#define   HETFLG14                         ((unsigned int) 0x1 <<  14)  // 14     HET interrupt source 14 flag
#define   HETFLG15                         ((unsigned int) 0x1 <<  15)  // 15     HET interrupt source 15 flag
#define   HETFLG16                         ((unsigned int) 0x1 <<  16)  // 16     HET interrupt source 16 flag
#define   HETFLG17                         ((unsigned int) 0x1 <<  17)  // 17     HET interrupt source 17 flag
#define   HETFLG18                         ((unsigned int) 0x1 <<  18)  // 18     HET interrupt source 18 flag
#define   HETFLG19                         ((unsigned int) 0x1 <<  19)  // 19     HET interrupt source 19 flag
#define   HETFLG20                         ((unsigned int) 0x1 <<  20)  // 20     HET interrupt source 20 flag
#define   HETFLG21                         ((unsigned int) 0x1 <<  21)  // 21     HET interrupt source 21 flag
#define   HETFLG22                         ((unsigned int) 0x1 <<  22)  // 22     HET interrupt source 22 flag
#define   HETFLG23                         ((unsigned int) 0x1 <<  23)  // 23     HET interrupt source 23 flag
#define   HETFLG24                         ((unsigned int) 0x1 <<  24)  // 24     HET interrupt source 24 flag
#define   HETFLG25                         ((unsigned int) 0x1 <<  25)  // 25     HET interrupt source 25 flag
#define   HETFLG26                         ((unsigned int) 0x1 <<  26)  // 26     HET interrupt source 26 flag
#define   HETFLG27                         ((unsigned int) 0x1 <<  27)  // 27     HET interrupt source 27 flag
#define   HETFLG28                         ((unsigned int) 0x1 <<  28)  // 28     HET interrupt source 28 flag
#define   HETFLG29                         ((unsigned int) 0x1 <<  29)  // 29     HET interrupt source 29 flag
#define   HETFLG30                         ((unsigned int) 0x1 <<  30)  // 30     HET interrupt source 30 flag
#define   HETFLG31                         ((unsigned int) 0x1 <<  31)  // 31     HET interrupt source 31 flag

//-------------------------------------------------
//  HET HETHRSH HR Share  Control Register bit definitions
//
// HETHRSH_BITS
#define   HR_SHARE_0_1                      ((unsigned int) 0x1 <<  0)  // 0      HET structure share 0:1
#define   HR_SHARE_2_3                      ((unsigned int) 0x1 <<  1)  // 1      HET structure share 2:3
#define   HR_SHARE_4_5                      ((unsigned int) 0x1 <<  2)  // 2      HET structure share 4:5
#define   HR_SHARE_6_7                      ((unsigned int) 0x1 <<  3)  // 3      HET structure share 6:7
#define   HR_SHARE_8_9                      ((unsigned int) 0x1 <<  4)  // 4      HET structure share 8:9
#define   HR_SHARE_10_11                    ((unsigned int) 0x1 <<  5)  // 5      HET structure share 10:11
#define   HR_SHARE_12_13                    ((unsigned int) 0x1 <<  6)  // 6      HET structure share 12:13
#define   HR_SHARE_14_15                    ((unsigned int) 0x1 <<  7)  // 7      HET structure share 14:15
#define   HR_SHARE_16_17                    ((unsigned int) 0x1 <<  8)  // 8      HET structure share 16:17
#define   HR_SHARE_18_19                    ((unsigned int) 0x1 <<  9)  // 9      HET structure share 18:19
#define   HR_SHARE_20_21                    ((unsigned int) 0x1 <<  10)  // 10     HET structure share 20:21
#define   HR_SHARE_22_23                    ((unsigned int) 0x1 <<  11)  // 11     HET structure share 22:23

//-------------------------------------------------
//  HET HETXOR HR XOR Control Register bit definitions
//
// HETXOR_BITS
#define   HR_XOR_SHARE_0_1                  ((unsigned int) 0x1 <<  0)  // 0      HET structure XOR share 0:1
#define   HR_XOR_SHARE_2_3                  ((unsigned int) 0x1 <<  1)  // 1      HET structure XOR share 2:3
#define   HR_XOR_SHARE_4_5                  ((unsigned int) 0x1 <<  2)  // 2      HET structure XOR share 4:5
#define   HR_XOR_SHARE_6_7                  ((unsigned int) 0x1 <<  3)  // 3      HET structure XOR share 6:7
#define   HR_XOR_SHARE_8_9                  ((unsigned int) 0x1 <<  4)  // 4      HET structure XOR share 8:9
#define   HR_XOR_SHARE_10_11                ((unsigned int) 0x1 <<  5)  // 5      HET structure XOR share 10:11
#define   HR_XOR_SHARE_12_13                ((unsigned int) 0x1 <<  6)  // 6      HET structure XOR share 12:13
#define   HR_XOR_SHARE_14_15                ((unsigned int) 0x1 <<  7)  // 7      HET structure XOR share 14:15
#define   HR_XOR_SHARE_16_17                ((unsigned int) 0x1 <<  8)  // 8      HET structure XOR share 16:17
#define   HR_XOR_SHARE_18_19                ((unsigned int) 0x1 <<  9)  // 9      HET structure XOR share 18:19
#define   HR_XOR_SHARE_20_21                ((unsigned int) 0x1 <<  10)  // 10     HET structure XOR share 20:21
#define   HR_XOR_SHARE_22_23                ((unsigned int) 0x1 <<  11)  // 11     HET structure XOR share 22:23

//-------------------------------------------------
//  HET HETDIR Direction Register bit definitions
//
// HETDIR_BITS

#define   HETDIR0                          ((unsigned int) 0x1 <<  0)  // 0      HET pin 0 direction bit
#define   HETDIR1                          ((unsigned int) 0x1 <<  1)  // 1      HET pin 1 direction bit
#define   HETDIR2                          ((unsigned int) 0x1 <<  2)  // 2      HET pin 2 direction bit
#define   HETDIR3                          ((unsigned int) 0x1 <<  3)  // 3      HET pin 3 direction bit
#define   HETDIR4                          ((unsigned int) 0x1 <<  4)  // 4      HET pin 4 direction bit
#define   HETDIR5                          ((unsigned int) 0x1 <<  5)  // 5      HET pin 5 direction bit
#define   HETDIR6                          ((unsigned int) 0x1 <<  6)  // 6      HET pin 6 direction bit
#define   HETDIR7                          ((unsigned int) 0x1 <<  7)  // 7      HET pin 7 direction bit
#define   HETDIR8                          ((unsigned int) 0x1 <<  8)  // 8      HET pin 8 direction bit
#define   HETDIR9                          ((unsigned int) 0x1 <<  9)  // 9      HET pin 9 direction bit

#define   HETDIR10                         ((unsigned int) 0x1 <<  10)  // 10     HET pin 10 direction bit
#define   HETDIR11                         ((unsigned int) 0x1 <<  11)  // 11     HET pin 11 direction bit
#define   HETDIR12                         ((unsigned int) 0x1 <<  12)  // 12     HET pin 12 direction bit
#define   HETDIR13                         ((unsigned int) 0x1 <<  13)  // 13     HET pin 13 direction bit
#define   HETDIR14                         ((unsigned int) 0x1 <<  14)  // 14     HET pin 14 direction bit
#define   HETDIR15                         ((unsigned int) 0x1 <<  15)  // 15     HET pin 15 direction bit
#define   HETDIR16                         ((unsigned int) 0x1 <<  16)  // 16     HET pin 16 direction bit
#define   HETDIR17                         ((unsigned int) 0x1 <<  17)  // 17     HET pin 17 direction bit
#define   HETDIR18                         ((unsigned int) 0x1 <<  18)  // 18     HET pin 18 direction bit
#define   HETDIR19                         ((unsigned int) 0x1 <<  19)  // 19     HET pin 19 direction bit
#define   HETDIR20                         ((unsigned int) 0x1 <<  20)  // 20     HET pin 20 direction bit
#define   HETDIR21                         ((unsigned int) 0x1 <<  21)  // 21     HET pin 21 direction bit
#define   HETDIR22                         ((unsigned int) 0x1 <<  22)  // 22     HET pin 22 direction bit
#define   HETDIR23                         ((unsigned int) 0x1 <<  23)  // 23     HET pin 23 direction bit
#define   HETDIR24                         ((unsigned int) 0x1 <<  24)  // 24     HET pin 24 direction bit
#define   HETDIR25                         ((unsigned int) 0x1 <<  25)  // 25     HET pin 25 direction bit
#define   HETDIR26                         ((unsigned int) 0x1 <<  26)  // 26     HET pin 26 direction bit
#define   HETDIR27                         ((unsigned int) 0x1 <<  27)  // 27     HET pin 27 direction bit
#define   HETDIR28                         ((unsigned int) 0x1 <<  28)  // 28     HET pin 28 direction bit
#define   HETDIR29                         ((unsigned int) 0x1 <<  29)  // 29     HET pin 29 direction bit
#define   HETDIR30                         ((unsigned int) 0x1 <<  30)  // 30     HET pin 30 direction bit
#define   HETDIR31                         ((unsigned int) 0x1 <<  31)  // 31     HET pin 31 direction bit

//-------------------------------------------------
//  HET HETDIN Data Input Register bit definitions
//
// HETDIN_BITS

#define   HETDIN0                          ((unsigned int) 0x1 <<  0)  // 0      HET pin 0 data input bit
#define   HETDIN1                          ((unsigned int) 0x1 <<  1)  // 1      HET pin 1 data input bit
#define   HETDIN2                          ((unsigned int) 0x1 <<  2)  // 2      HET pin 2 data input bit
#define   HETDIN3                          ((unsigned int) 0x1 <<  3)  // 3      HET pin 3 data input bit
#define   HETDIN4                          ((unsigned int) 0x1 <<  4)  // 4      HET pin 4 data input bit
#define   HETDIN5                          ((unsigned int) 0x1 <<  5)  // 5      HET pin 5 data input bit
#define   HETDIN6                          ((unsigned int) 0x1 <<  6)  // 6      HET pin 6 data input bit
#define   HETDIN7                          ((unsigned int) 0x1 <<  7)  // 7      HET pin 7 data input bit
#define   HETDIN8                          ((unsigned int) 0x1 <<  8)  // 8      HET pin 8 data input bit
#define   HETDIN9                          ((unsigned int) 0x1 <<  9)  // 9      HET pin 9 data input bit
#define   HETDIN10                         ((unsigned int) 0x1 <<  10)  // 10     HET pin 10 data input bit
#define   HETDIN11                         ((unsigned int) 0x1 <<  11)  // 11     HET pin 11 data input bit
#define   HETDIN12                         ((unsigned int) 0x1 <<  12)  // 12     HET pin 12 data input bit
#define   HETDIN13                         ((unsigned int) 0x1 <<  13)  // 13     HET pin 13 data input bit
#define   HETDIN14                         ((unsigned int) 0x1 <<  14)  // 14     HET pin 14 data input bit
#define   HETDIN15                         ((unsigned int) 0x1 <<  15)  // 15     HET pin 15 data input bit
#define   HETDIN16                         ((unsigned int) 0x1 <<  16)  // 16     HET pin 16 data input bit
#define   HETDIN17                         ((unsigned int) 0x1 <<  17)  // 17     HET pin 17 data input bit
#define   HETDIN18                         ((unsigned int) 0x1 <<  18)  // 18     HET pin 18 data input bit
#define   HETDIN19                         ((unsigned int) 0x1 <<  19)  // 19     HET pin 19 data input bit
#define   HETDIN20                         ((unsigned int) 0x1 <<  20)  // 20     HET pin 20 data input bit
#define   HETDIN21                         ((unsigned int) 0x1 <<  21)  // 21     HET pin 21 data input bit
#define   HETDIN22                         ((unsigned int) 0x1 <<  22)  // 22     HET pin 22 data input bit
#define   HETDIN23                         ((unsigned int) 0x1 <<  23)  // 23     HET pin 23 data input bit
#define   HETDIN24                         ((unsigned int) 0x1 <<  24)  // 24     HET pin 24 data input bit
#define   HETDIN25                         ((unsigned int) 0x1 <<  25)  // 25     HET pin 25 data input bit
#define   HETDIN26                         ((unsigned int) 0x1 <<  26)  // 26     HET pin 26 data input bit
#define   HETDIN27                         ((unsigned int) 0x1 <<  27)  // 27     HET pin 27 data input bit
#define   HETDIN28                         ((unsigned int) 0x1 <<  28)  // 28     HET pin 28 data input bit
#define   HETDIN29                         ((unsigned int) 0x1 <<  29)  // 29     HET pin 29 data input bit
#define   HETDIN30                         ((unsigned int) 0x1 <<  30)  // 30     HET pin 30 data input bit
#define   HETDIN31                         ((unsigned int) 0x1 <<  31)  // 31     HET pin 31 data input bit

//-------------------------------------------------
//  HET HETPDOUT Data Output Register bit definitions
//
//  HETDOUT_BITS
#define   HETDOUT0                          ((unsigned int) 0x1 <<  0)  // 0      HET pin 0 data output bit
#define   HETDOUT1                          ((unsigned int) 0x1 <<  1)  // 1      HET pin 1 data output bit
#define   HETDOUT2                          ((unsigned int) 0x1 <<  2)  // 2      HET pin 2 data output bit
#define   HETDOUT3                          ((unsigned int) 0x1 <<  3)  // 3      HET pin 3 data output bit
#define   HETDOUT4                          ((unsigned int) 0x1 <<  4)  // 4      HET pin 4 data output bit
#define   HETDOUT5                          ((unsigned int) 0x1 <<  5)  // 5      HET pin 5 data output bit
#define   HETDOUT6                          ((unsigned int) 0x1 <<  6)  // 6      HET pin 6 data output bit
#define   HETDOUT7                          ((unsigned int) 0x1 <<  7)  // 7      HET pin 7 data output bit
#define   HETDOUT8                          ((unsigned int) 0x1 <<  8)  // 8      HET pin 8 data output bit
#define   HETDOUT9                          ((unsigned int) 0x1 <<  9)  // 9      HET pin 9 data output bit
#define   HETDOUT10                         ((unsigned int) 0x1 <<  10)  // 10     HET pin 10 data output bit
#define   HETDOUT11                         ((unsigned int) 0x1 <<  11)  // 11     HET pin 11 data output bit
#define   HETDOUT12                         ((unsigned int) 0x1 <<  12)  // 12     HET pin 12 data output bit
#define   HETDOUT13                         ((unsigned int) 0x1 <<  13)  // 13     HET pin 13 data output bit
#define   HETDOUT14                         ((unsigned int) 0x1 <<  14)  // 14     HET pin 14 data output bit
#define   HETDOUT15                         ((unsigned int) 0x1 <<  15)  // 15     HET pin 15 data output bit
#define   HETDOUT16                         ((unsigned int) 0x1 <<  16)  // 16     HET pin 16 data output bit
#define   HETDOUT17                         ((unsigned int) 0x1 <<  17)  // 17     HET pin 17 data output bit
#define   HETDOUT18                         ((unsigned int) 0x1 <<  18)  // 18     HET pin 18 data output bit
#define   HETDOUT19                         ((unsigned int) 0x1 <<  19)  // 19     HET pin 19 data output bit
#define   HETDOUT20                         ((unsigned int) 0x1 <<  20)  // 20     HET pin 20 data output bit
#define   HETDOUT21                         ((unsigned int) 0x1 <<  21)  // 21     HET pin 21 data output bit
#define   HETDOUT22                         ((unsigned int) 0x1 <<  22)  // 22     HET pin 22 data output bit
#define   HETDOUT23                         ((unsigned int) 0x1 <<  23)  // 23     HET pin 23 data output bit
#define   HETDOUT24                         ((unsigned int) 0x1 <<  24)  // 24     HET pin 24 data output bit
#define   HETDOUT25                         ((unsigned int) 0x1 <<  25)  // 25     HET pin 25 data output bit
#define   HETDOUT26                         ((unsigned int) 0x1 <<  26)  // 26     HET pin 26 data output bit
#define   HETDOUT27                         ((unsigned int) 0x1 <<  27)  // 27     HET pin 27 data output bit
#define   HETDOUT28                         ((unsigned int) 0x1 <<  28)  // 28     HET pin 28 data output bit
#define   HETDOUT29                         ((unsigned int) 0x1 <<  29)  // 29     HET pin 29 data output bit
#define   HETDOUT30                         ((unsigned int) 0x1 <<  30)  // 30     HET pin 30 data output bit
#define   HETDOUT31                         ((unsigned int) 0x1 <<  31)  // 31     HET pin 31 data output bit

//-------------------------------------------------
//  HET HETDSET Data Set Register bit definitions
//
// HETDSET_BITS
#define   HETDSET0                          ((unsigned int) 0x1 <<  0)  // 0      HET pin 0 set bit
#define   HETDSET1                          ((unsigned int) 0x1 <<  1)  // 1      HET pin 1 set bit
#define   HETDSET2                          ((unsigned int) 0x1 <<  2)  // 2      HET pin 2 set bit
#define   HETDSET3                          ((unsigned int) 0x1 <<  3)  // 3      HET pin 3 set bit
#define   HETDSET4                          ((unsigned int) 0x1 <<  4)  // 4      HET pin 4 set bit
#define   HETDSET5                          ((unsigned int) 0x1 <<  5)  // 5      HET pin 5 set bit
#define   HETDSET6                          ((unsigned int) 0x1 <<  6)  // 6      HET pin 6 set bit
#define   HETDSET7                          ((unsigned int) 0x1 <<  7)  // 7      HET pin 7 set bit
#define   HETDSET8                          ((unsigned int) 0x1 <<  8)  // 8      HET pin 8 set bit
#define   HETDSET9                          ((unsigned int) 0x1 <<  9)  // 9      HET pin 9 set bit
#define   HETDSET10                         ((unsigned int) 0x1 <<  10)  // 10     HET pin 10 set bit
#define   HETDSET11                         ((unsigned int) 0x1 <<  11)  // 11     HET pin 11 set bit
#define   HETDSET12                         ((unsigned int) 0x1 <<  12)  // 12     HET pin 12 set bit
#define   HETDSET13                         ((unsigned int) 0x1 <<  13)  // 13     HET pin 13 set bit
#define   HETDSET14                         ((unsigned int) 0x1 <<  14)  // 14     HET pin 14 set bit
#define   HETDSET15                         ((unsigned int) 0x1 <<  15)  // 15     HET pin 15 set bit
#define   HETDSET16                         ((unsigned int) 0x1 <<  16)  // 16     HET pin 16 set bit
#define   HETDSET17                         ((unsigned int) 0x1 <<  17)  // 17     HET pin 17 set bit
#define   HETDSET18                         ((unsigned int) 0x1 <<  18)  // 18     HET pin 18 set bit
#define   HETDSET19                         ((unsigned int) 0x1 <<  19)  // 19     HET pin 19 set bit
#define   HETDSET20                         ((unsigned int) 0x1 <<  20)  // 20     HET pin 20 set bit
#define   HETDSET21                         ((unsigned int) 0x1 <<  21)  // 21     HET pin 21 set bit
#define   HETDSET22                         ((unsigned int) 0x1 <<  22)  // 22     HET pin 22 set bit
#define   HETDSET23                         ((unsigned int) 0x1 <<  23)  // 23     HET pin 23 set bit
#define   HETDSET24                         ((unsigned int) 0x1 <<  24)  // 24     HET pin 24 set bit
#define   HETDSET25                         ((unsigned int) 0x1 <<  25)  // 25     HET pin 25 set bit
#define   HETDSET26                         ((unsigned int) 0x1 <<  26)  // 26     HET pin 26 set bit
#define   HETDSET27                         ((unsigned int) 0x1 <<  27)  // 27     HET pin 27 set bit
#define   HETDSET28                         ((unsigned int) 0x1 <<  28)  // 28     HET pin 28 set bit
#define   HETDSET29                         ((unsigned int) 0x1 <<  29)  // 29     HET pin 29 set bit
#define   HETDSET30                         ((unsigned int) 0x1 <<  30)  // 30     HET pin 30 set bit
#define   HETDSET31                         ((unsigned int) 0x1 <<  31)  // 31     HET pin 31 set bit

//-------------------------------------------------
//  HET HETDCLR Data Clear Register bit definitions
//

// HETDCLR_BITS
#define   HETDCLR0                          ((unsigned int) 0x1 <<  0)  // 0      HET pin 0 clr bit
#define   HETDCLR1                          ((unsigned int) 0x1 <<  1)  // 1      HET pin 1 clr bit
#define   HETDCLR2                          ((unsigned int) 0x1 <<  2)  // 2      HET pin 2 clr bit
#define   HETDCLR3                          ((unsigned int) 0x1 <<  3)  // 3      HET pin 3 clr bit
#define   HETDCLR4                          ((unsigned int) 0x1 <<  4)  // 4      HET pin 4 clr bit
#define   HETDCLR5                          ((unsigned int) 0x1 <<  5)  // 5      HET pin 5 clr bit
#define   HETDCLR6                          ((unsigned int) 0x1 <<  6)  // 6      HET pin 6 clr bit
#define   HETDCLR7                          ((unsigned int) 0x1 <<  7)  // 7      HET pin 7 clr bit
#define   HETDCLR8                          ((unsigned int) 0x1 <<  8)  // 8      HET pin 8 clr bit
#define   HETDCLR9                          ((unsigned int) 0x1 <<  9)  // 9      HET pin 9 clr bit
#define   HETDCLR10                         ((unsigned int) 0x1 <<  10)  // 10     HET pin 10 clr bit
#define   HETDCLR11                         ((unsigned int) 0x1 <<  11)  // 11     HET pin 11 clr bit
#define   HETDCLR12                         ((unsigned int) 0x1 <<  12)  // 12     HET pin 12 clr bit
#define   HETDCLR13                         ((unsigned int) 0x1 <<  13)  // 13     HET pin 13 clr bit
#define   HETDCLR14                         ((unsigned int) 0x1 <<  14)  // 14     HET pin 14 clr bit
#define   HETDCLR15                         ((unsigned int) 0x1 <<  15)  // 15     HET pin 15 clr bit
#define   HETDCLR16                         ((unsigned int) 0x1 <<  16)  // 16     HET pin 16 clr bit
#define   HETDCLR17                         ((unsigned int) 0x1 <<  17)  // 17     HET pin 17 clr bit
#define   HETDCLR18                         ((unsigned int) 0x1 <<  18)  // 18     HET pin 18 clr bit
#define   HETDCLR19                         ((unsigned int) 0x1 <<  19)  // 19     HET pin 19 clr bit
#define   HETDCLR20                         ((unsigned int) 0x1 <<  20)  // 20     HET pin 20 clr bit
#define   HETDCLR21                         ((unsigned int) 0x1 <<  21)  // 21     HET pin 21 clr bit
#define   HETDCLR22                         ((unsigned int) 0x1 <<  22)  // 22     HET pin 22 clr bit
#define   HETDCLR23                         ((unsigned int) 0x1 <<  23)  // 23     HET pin 23 clr bit
#define   HETDCLR24                         ((unsigned int) 0x1 <<  24)  // 24     HET pin 24 clr bit
#define   HETDCLR25                         ((unsigned int) 0x1 <<  25)  // 25     HET pin 25 clr bit
#define   HETDCLR26                         ((unsigned int) 0x1 <<  26)  // 26     HET pin 26 clr bit
#define   HETDCLR27                         ((unsigned int) 0x1 <<  27)  // 27     HET pin 27 clr bit
#define   HETDCLR28                         ((unsigned int) 0x1 <<  28)  // 28     HET pin 28 clr bit
#define   HETDCLR29                         ((unsigned int) 0x1 <<  29)  // 29     HET pin 29 clr bit
#define   HETDCLR30                         ((unsigned int) 0x1 <<  30)  // 30     HET pin 30 clr bit
#define   HETDCLR31                         ((unsigned int) 0x1 <<  31)  // 31     HET pin 31 clr bit

//*************************************************************************************
// SCC CAN
//-------------------------------------------------
// CAN Mailbox enable register bit definitions
//
//  CANME_BITS
#define   ME0             ((unsigned int) 0x1 <<  0) // 0      Mailbox 0
#define   ME1             ((unsigned int) 0x1 <<  1) // 1      Mailbox 1
#define   ME2             ((unsigned int) 0x1 <<  2) // 2      Mailbox 2
#define   ME3             ((unsigned int) 0x1 <<  3) // 3      Mailbox 3
#define   ME4             ((unsigned int) 0x1 <<  4) // 4      Mailbox 4
#define   ME5             ((unsigned int) 0x1 <<  5) // 5      Mailbox 5
#define   ME6             ((unsigned int) 0x1 <<  6) // 6      Mailbox 6
#define   ME7             ((unsigned int) 0x1 <<  7) // 7      Mailbox 7
#define   ME8             ((unsigned int) 0x1 <<  8) // 8      Mailbox 8
#define   ME9             ((unsigned int) 0x1 <<  9) // 9      Mailbox 9
#define   ME10            ((unsigned int) 0x1 <<  10) // 10     Mailbox 10
#define   ME11            ((unsigned int) 0x1 <<  11) // 11     Mailbox 11
#define   ME12            ((unsigned int) 0x1 <<  12) // 12     Mailbox 12
#define   ME13            ((unsigned int) 0x1 <<  13) // 13     Mailbox 13
#define   ME14            ((unsigned int) 0x1 <<  14) // 14     Mailbox 14
#define   ME15            ((unsigned int) 0x1 <<  15) // 15     Mailbox 15


//-------------------------------------------------
// CAN Mailbox direction register bit definitions
//
//  CANMD_BITS
#define   MD0             ((unsigned int) 0x1 <<  0) // 0      Mailbox 0
#define   MD1             ((unsigned int) 0x1 <<  1) // 1      Mailbox 1
#define   MD2             ((unsigned int) 0x1 <<  2) // 2      Mailbox 2
#define   MD3             ((unsigned int) 0x1 <<  3) // 3      Mailbox 3
#define   MD4             ((unsigned int) 0x1 <<  4) // 4      Mailbox 4
#define   MD5             ((unsigned int) 0x1 <<  5) // 5      Mailbox 5
#define   MD6             ((unsigned int) 0x1 <<  6) // 6      Mailbox 6
#define   MD7             ((unsigned int) 0x1 <<  7) // 7      Mailbox 7
#define   MD8             ((unsigned int) 0x1 <<  8) // 8      Mailbox 8
#define   MD9             ((unsigned int) 0x1 <<  9) // 9      Mailbox 9
#define   MD10            ((unsigned int) 0x1 <<  10) // 10     Mailbox 10
#define   MD11            ((unsigned int) 0x1 <<  11) // 11     Mailbox 11
#define   MD12            ((unsigned int) 0x1 <<  12) // 12     Mailbox 12
#define   MD13            ((unsigned int) 0x1 <<  13) // 13     Mailbox 13
#define   MD14            ((unsigned int) 0x1 <<  14) // 14     Mailbox 14
#define   MD15            ((unsigned int) 0x1 <<  15) // 15     Mailbox 15

//-------------------------------------------------
// CAN Transmit Request Set register bit definitions
//
// CANTRS_BITS
#define   TRS0             ((unsigned int) 0x1 <<  0) // 0      Mailbox 0
#define   TRS1             ((unsigned int) 0x1 <<  1) // 1      Mailbox 1
#define   TRS2             ((unsigned int) 0x1 <<  2) // 2      Mailbox 2
#define   TRS3             ((unsigned int) 0x1 <<  3) // 3      Mailbox 3
#define   TRS4             ((unsigned int) 0x1 <<  4) // 4      Mailbox 4
#define   TRS5             ((unsigned int) 0x1 <<  5) // 5      Mailbox 5
#define   TRS6             ((unsigned int) 0x1 <<  6) // 6      Mailbox 6
#define   TRS7             ((unsigned int) 0x1 <<  7) // 7      Mailbox 7
#define   TRS8             ((unsigned int) 0x1 <<  8) // 8      Mailbox 8
#define   TRS9             ((unsigned int) 0x1 <<  9) // 9      Mailbox 9
#define   TRS10            ((unsigned int) 0x1 <<  10) // 10     Mailbox 10
#define   TRS11            ((unsigned int) 0x1 <<  11) // 11     Mailbox 11
#define   TRS12            ((unsigned int) 0x1 <<  12) // 12     Mailbox 12
#define   TRS13            ((unsigned int) 0x1 <<  13) // 13     Mailbox 13
#define   TRS14            ((unsigned int) 0x1 <<  14) // 14     Mailbox 14
#define   TRS15            ((unsigned int) 0x1 <<  15) // 15     Mailbox 15

//-------------------------------------------------
// CAN Transmit Request Reset register bit definitions
//
//  CANTRR_BITS
#define   TRR0             ((unsigned int) 0x1 <<  0) // 0      Mailbox 0
#define   TRR1             ((unsigned int) 0x1 <<  1) // 1      Mailbox 1
#define   TRR2             ((unsigned int) 0x1 <<  2) // 2      Mailbox 2
#define   TRR3             ((unsigned int) 0x1 <<  3) // 3      Mailbox 3
#define   TRR4             ((unsigned int) 0x1 <<  4) // 4      Mailbox 4
#define   TRR5             ((unsigned int) 0x1 <<  5) // 5      Mailbox 5
#define   TRR6             ((unsigned int) 0x1 <<  6) // 6      Mailbox 6
#define   TRR7             ((unsigned int) 0x1 <<  7) // 7      Mailbox 7
#define   TRR8             ((unsigned int) 0x1 <<  8) // 8      Mailbox 8
#define   TRR9             ((unsigned int) 0x1 <<  9) // 9      Mailbox 9
#define   TRR10            ((unsigned int) 0x1 <<  10) // 10     Mailbox 10
#define   TRR11            ((unsigned int) 0x1 <<  11) // 11     Mailbox 11
#define   TRR12            ((unsigned int) 0x1 <<  12) // 12     Mailbox 12
#define   TRR13            ((unsigned int) 0x1 <<  13) // 13     Mailbox 13
#define   TRR14            ((unsigned int) 0x1 <<  14) // 14     Mailbox 14
#define   TRR15            ((unsigned int) 0x1 <<  15) // 15     Mailbox 15

//-------------------------------------------------
// CAN Transmit Acknowledge register bit definitions
//
//  CANTA_BITS
#define   TA0             ((unsigned int) 0x1 <<  0) // 0      Mailbox 0
#define   TA1             ((unsigned int) 0x1 <<  1) // 1      Mailbox 1
#define   TA2             ((unsigned int) 0x1 <<  2) // 2      Mailbox 2
#define   TA3             ((unsigned int) 0x1 <<  3) // 3      Mailbox 3
#define   TA4             ((unsigned int) 0x1 <<  4) // 4      Mailbox 4
#define   TA5             ((unsigned int) 0x1 <<  5) // 5      Mailbox 5
#define   TA6             ((unsigned int) 0x1 <<  6) // 6      Mailbox 6
#define   TA7             ((unsigned int) 0x1 <<  7) // 7      Mailbox 7
#define   TA8             ((unsigned int) 0x1 <<  8) // 8      Mailbox 8
#define   TA9             ((unsigned int) 0x1 <<  9) // 9      Mailbox 9
#define   TA10            ((unsigned int) 0x1 <<  10) // 10     Mailbox 10
#define   TA11            ((unsigned int) 0x1 <<  11) // 11     Mailbox 11
#define   TA12            ((unsigned int) 0x1 <<  12) // 12     Mailbox 12
#define   TA13            ((unsigned int) 0x1 <<  13) // 13     Mailbox 13
#define   TA14            ((unsigned int) 0x1 <<  14) // 14     Mailbox 14
#define   TA15            ((unsigned int) 0x1 <<  15) // 15     Mailbox 15

//-------------------------------------------------
// CAN Transmit Abort Acknowledge register bit definitions
//
//  CANAA_BITS
#define   AA0             ((unsigned int) 0x1 <<  0) // 0      Mailbox 0
#define   AA1             ((unsigned int) 0x1 <<  1) // 1      Mailbox 1
#define   AA2             ((unsigned int) 0x1 <<  2) // 2      Mailbox 2
#define   AA3             ((unsigned int) 0x1 <<  3) // 3      Mailbox 3
#define   AA4             ((unsigned int) 0x1 <<  4) // 4      Mailbox 4
#define   AA5             ((unsigned int) 0x1 <<  5) // 5      Mailbox 5
#define   AA6             ((unsigned int) 0x1 <<  6) // 6      Mailbox 6
#define   AA7             ((unsigned int) 0x1 <<  7) // 7      Mailbox 7
#define   AA8             ((unsigned int) 0x1 <<  8) // 8      Mailbox 8
#define   AA9             ((unsigned int) 0x1 <<  9) // 9      Mailbox 9
#define   AA10            ((unsigned int) 0x1 <<  10) // 10     Mailbox 10
#define   AA11            ((unsigned int) 0x1 <<  11) // 11     Mailbox 11
#define   AA12            ((unsigned int) 0x1 <<  12) // 12     Mailbox 12
#define   AA13            ((unsigned int) 0x1 <<  13) // 13     Mailbox 13
#define   AA14            ((unsigned int) 0x1 <<  14) // 14     Mailbox 14
#define   AA15            ((unsigned int) 0x1 <<  15) // 15     Mailbox 15

//-------------------------------------------------
// CAN Received Message Pending register bit definitions
//
//  CANRMP_BITS
#define   RMP0             ((unsigned int) 0x1 <<  0) // 0      Mailbox 0
#define   RMP1             ((unsigned int) 0x1 <<  1) // 1      Mailbox 1
#define   RMP2             ((unsigned int) 0x1 <<  2) // 2      Mailbox 2
#define   RMP3             ((unsigned int) 0x1 <<  3) // 3      Mailbox 3
#define   RMP4             ((unsigned int) 0x1 <<  4) // 4      Mailbox 4
#define   RMP5             ((unsigned int) 0x1 <<  5) // 5      Mailbox 5
#define   RMP6             ((unsigned int) 0x1 <<  6) // 6      Mailbox 6
#define   RMP7             ((unsigned int) 0x1 <<  7) // 7      Mailbox 7
#define   RMP8             ((unsigned int) 0x1 <<  8) // 8      Mailbox 8
#define   RMP9             ((unsigned int) 0x1 <<  9) // 9      Mailbox 9
#define   RMP10            ((unsigned int) 0x1 <<  10) // 10     Mailbox 10
#define   RMP11            ((unsigned int) 0x1 <<  11) // 11     Mailbox 11
#define   RMP12            ((unsigned int) 0x1 <<  12) // 12     Mailbox 12
#define   RMP13            ((unsigned int) 0x1 <<  13) // 13     Mailbox 13
#define   RMP14            ((unsigned int) 0x1 <<  14) // 14     Mailbox 14
#define   RMP15            ((unsigned int) 0x1 <<  15) // 15     Mailbox 15

//-------------------------------------------------
// CAN Received Message Lost register bit definitions
//
//  CANRML_BITS
#define   RML0             ((unsigned int) 0x1 <<  0) // 0      Mailbox 0
#define   RML1             ((unsigned int) 0x1 <<  1) // 1      Mailbox 1
#define   RML2             ((unsigned int) 0x1 <<  2) // 2      Mailbox 2
#define   RML3             ((unsigned int) 0x1 <<  3) // 3      Mailbox 3
#define   RML4             ((unsigned int) 0x1 <<  4) // 4      Mailbox 4
#define   RML5             ((unsigned int) 0x1 <<  5) // 5      Mailbox 5
#define   RML6             ((unsigned int) 0x1 <<  6) // 6      Mailbox 6
#define   RML7             ((unsigned int) 0x1 <<  7) // 7      Mailbox 7
#define   RML8             ((unsigned int) 0x1 <<  8) // 8      Mailbox 8
#define   RML9             ((unsigned int) 0x1 <<  9) // 9      Mailbox 9
#define   RML10            ((unsigned int) 0x1 <<  10) // 10     Mailbox 10
#define   RML11            ((unsigned int) 0x1 <<  11) // 11     Mailbox 11
#define   RML12            ((unsigned int) 0x1 <<  12) // 12     Mailbox 12
#define   RML13            ((unsigned int) 0x1 <<  13) // 13     Mailbox 13
#define   RML14            ((unsigned int) 0x1 <<  14) // 14     Mailbox 14
#define   RML15            ((unsigned int) 0x1 <<  15) // 15     Mailbox 15

//-------------------------------------------------
// CAN Remote Frame Pending register bit definitions
//
//  CANRFP_BITS
#define   RFP0             ((unsigned int) 0x1 <<  0) // 0      Mailbox 0
#define   RFP1             ((unsigned int) 0x1 <<  1) // 1      Mailbox 1
#define   RFP2             ((unsigned int) 0x1 <<  2) // 2      Mailbox 2
#define   RFP3             ((unsigned int) 0x1 <<  3) // 3      Mailbox 3
#define   RFP4             ((unsigned int) 0x1 <<  4) // 4      Mailbox 4
#define   RFP5             ((unsigned int) 0x1 <<  5) // 5      Mailbox 5
#define   RFP6             ((unsigned int) 0x1 <<  6) // 6      Mailbox 6
#define   RFP7             ((unsigned int) 0x1 <<  7) // 7      Mailbox 7
#define   RFP8             ((unsigned int) 0x1 <<  8) // 8      Mailbox 8
#define   RFP9             ((unsigned int) 0x1 <<  9) // 9      Mailbox 9
#define   RFP10            ((unsigned int) 0x1 <<  10) // 10     Mailbox 10
#define   RFP11            ((unsigned int) 0x1 <<  11) // 11     Mailbox 11
#define   RFP12            ((unsigned int) 0x1 <<  12) // 12     Mailbox 12
#define   RFP13            ((unsigned int) 0x1 <<  13) // 13     Mailbox 13
#define   RFP14            ((unsigned int) 0x1 <<  14) // 14     Mailbox 14
#define   RFP15            ((unsigned int) 0x1 <<  15) // 15     Mailbox 15

//-------------------------------------------------
// CAN Global Acceptance Mask register bit definitions
//
//  CANGAM_BITS
#define   GAM0             ((unsigned int) 0x1 <<  0) // 0 Global acceptance mask  28:0
#define   GAM1             ((unsigned int) 0x1 <<  1) // 1 Global acceptance mask
#define   GAM2             ((unsigned int) 0x1 <<  2) // 2 Global acceptance mask
#define   GAM3             ((unsigned int) 0x1 <<  3) // 3 Global acceptance mask
#define   GAM4             ((unsigned int) 0x1 <<  4) // 4 Global acceptance mask
#define   GAM5             ((unsigned int) 0x1 <<  5) // 5 Global acceptance mask
#define   GAM6             ((unsigned int) 0x1 <<  6) // 6 Global acceptance mask
#define   GAM7             ((unsigned int) 0x1 <<  7) // 7 Global acceptance mask
#define   GAM8             ((unsigned int) 0x1 <<  8) // 8 Global acceptance mask
#define   GAM9             ((unsigned int) 0x1 <<  9) // 9 Global acceptance mask
#define   GAM10            ((unsigned int) 0x1 <<  10) // 10 Global acceptance mask
#define   GAM11            ((unsigned int) 0x1 <<  11) // 11 Global acceptance mask
#define   GAM12            ((unsigned int) 0x1 <<  12) // 12 Global acceptance mask
#define   GAM13            ((unsigned int) 0x1 <<  13) // 13 Global acceptance mask
#define   GAM14            ((unsigned int) 0x1 <<  14) // 14 Global acceptance mask
#define   GAM15            ((unsigned int) 0x1 <<  15) // 15 Global acceptance mask
#define   GAM16            ((unsigned int) 0x1 <<  16) // 16 Global acceptance mask
#define   GAM17            ((unsigned int) 0x1 <<  17) // 17 Global acceptance mask
#define   GAM18            ((unsigned int) 0x1 <<  18) // 18 Global acceptance mask
#define   GAM19            ((unsigned int) 0x1 <<  19) // 19 Global acceptance mask
#define   GAM20            ((unsigned int) 0x1 <<  20) // 20 Global acceptance mask
#define   GAM21            ((unsigned int) 0x1 <<  21) // 21 Global acceptance mask
#define   GAM22            ((unsigned int) 0x1 <<  22) // 22 Global acceptance mask
#define   GAM23            ((unsigned int) 0x1 <<  23) // 23 Global acceptance mask
#define   GAM24            ((unsigned int) 0x1 <<  24) // 24 Global acceptance mask
#define   GAM25            ((unsigned int) 0x1 <<  25) // 25 Global acceptance mask
#define   GAM26            ((unsigned int) 0x1 <<  26) // 26 Global acceptance mask
#define   GAM27            ((unsigned int) 0x1 <<  27) // 27 Global acceptance mask
#define   GAM28            ((unsigned int) 0x1 <<  28) // 28 Global acceptance mask
#define   AMI              ((unsigned int) 0x1 <<  31) // 31 Acceptance mask identifier extension bit

//-------------------------------------------------
// CAN Master Control register bit definitions
//
//  CANMC_BITS
#define   MBNR0             ((unsigned int) 0x1 <<  0) // 0    MBX # for CDR bit
#define   MBNR1             ((unsigned int) 0x1 <<  1) // 1    MBX # for CDR bit
#define   MBNR2             ((unsigned int) 0x1 <<  2) // 2    MBX # for CDR bit
#define   MBNR3             ((unsigned int) 0x1 <<  3) // 3      MBX # for CDR bit
#define   MBNR_0            ((unsigned int) 0x0 <<  0) // 3:0    MBX # for CDR bit
#define   MBNR_1            ((unsigned int) 0x0 <<  1) // 3:0    MBX # for CDR bit
#define   MBNR_2            ((unsigned int) 0x0 <<  2) // 3:0    MBX # for CDR bit
#define   MBNR_3            ((unsigned int) 0x0 <<  3) // 3:0    MBX # for CDR bit
#define   MBNR_4            ((unsigned int) 0x0 <<  4) // 3:0    MBX # for CDR bit
#define   MBNR_5            ((unsigned int) 0x0 <<  5) // 3:0    MBX # for CDR bit
#define   MBNR_6            ((unsigned int) 0x0 <<  6) // 3:0    MBX # for CDR bit
#define   MBNR_7            ((unsigned int) 0x0 <<  7) // 3:0    MBX # for CDR bit
#define   MBNR_8            ((unsigned int) 0x0 <<  8) // 3:0    MBX # for CDR bit
#define   MBNR_9            ((unsigned int) 0x0 <<  9) // 3:0    MBX # for CDR bit
#define   MBNR_10           ((unsigned int) 0x0 <<  10) // 3:0    MBX # for CDR bit
#define   MBNR_11           ((unsigned int) 0x0 <<  11) // 3:0    MBX # for CDR bit
#define   MBNR_12           ((unsigned int) 0x0 <<  12) // 3:0    MBX # for CDR bit
#define   MBNR_13           ((unsigned int) 0x0 <<  13) // 3:0    MBX # for CDR bit
#define   MBNR_14           ((unsigned int) 0x0 <<  14) // 3:0    MBX # for CDR bit
#define   MBNR_15           ((unsigned int) 0x0 <<  15) // 3:0    MBX # for CDR bit
#define   SRES              ((unsigned int) 0x1 <<  5) // 5      Soft reset
#define   STM               ((unsigned int) 0x1 <<  6) // 6      Self-test mode
#define   ABO               ((unsigned int) 0x1 <<  7) // 7      Auto bus on
#define   CDR               ((unsigned int) 0x1 <<  8) // 8      Change data request
#define   WUBA              ((unsigned int) 0x1 <<  9) // 9      Wake-up on bus activity
#define   DBO               ((unsigned int) 0x1 <<  10) // 10    Data byte order
#define   PDR               ((unsigned int) 0x1 <<  11) // 11    Powerdown mode request
#define   CCR               ((unsigned int) 0x1 <<  12) // 12    Change configuration request

//-------------------------------------------------
// CAN Bit-timing configuration register bit definitions
//
//  CANBTC_BITS
#define   TSEG20           ((unsigned int) 0x0 <<  0) // 0    TSEG2 register value
#define   TSEG21           ((unsigned int) 0x0 <<  0) // 1    TSEG2 register value
#define   TSEG22           ((unsigned int) 0x0 <<  0) // 2    TSEG2 register value
#define   TSEG2_1          ((unsigned int) 0x0 <<  0) // 2:0    TSEG2 register value
#define   TSEG2_2          ((unsigned int) 0x1 <<  0) // 2:0    TSEG2 register value
#define   TSEG2_3          ((unsigned int) 0x2 <<  0) // 2:0    TSEG2 register value
#define   TSEG2_4          ((unsigned int) 0x3 <<  0) // 2:0    TSEG2 register value
#define   TSEG2_5          ((unsigned int) 0x4 <<  0) // 2:0    TSEG2 register value
#define   TSEG2_6          ((unsigned int) 0x5 <<  0) // 2:0    TSEG2 register value
#define   TSEG2_7          ((unsigned int) 0x6 <<  0) // 2:0    TSEG2 register value
#define   TSEG2_8          ((unsigned int) 0x7 <<  0) // 2:0    TSEG2 register value
#define   TSEG10           ((unsigned int) 0x0 <<  3) // 3    TSEG1 register value
#define   TSEG11           ((unsigned int) 0x0 <<  4) // 4    TSEG1 register value
#define   TSEG12           ((unsigned int) 0x0 <<  5) // 5    TSEG1 register value
#define   TSEG13           ((unsigned int) 0x0 <<  6) // 6    TSEG1 register value
#define   TSEG1_1          ((unsigned int) 0x0 <<  3) // 6:3    TSEG1 register value
#define   TSEG1_2          ((unsigned int) 0x1 <<  3) // 6:3    TSEG1 register value
#define   TSEG1_3          ((unsigned int) 0x2 <<  3) // 6:3    TSEG1 register value
#define   TSEG1_4          ((unsigned int) 0x3 <<  3) // 6:3    TSEG1 register value
#define   TSEG1_5          ((unsigned int) 0x4 <<  3) // 6:3    TSEG1 register value
#define   TSEG1_6          ((unsigned int) 0x5 <<  3) // 6:3    TSEG1 register value
#define   TSEG1_7          ((unsigned int) 0x6 <<  3) // 6:3    TSEG1 register value
#define   TSEG1_8          ((unsigned int) 0x7 <<  3) // 6:3    TSEG1 register value
#define   TSEG1_9          ((unsigned int) 0x8 <<  3) // 6:3    TSEG1 register value
#define   TSEG1_10         ((unsigned int) 0x9 <<  3) // 6:3    TSEG1 register value
#define   TSEG1_11         ((unsigned int) 0x0a <<  3) // 6:3    TSEG1 register value
#define   TSEG1_12         ((unsigned int) 0x0b <<  3) // 6:3    TSEG1 register value
#define   TSEG1_13         ((unsigned int) 0x0c <<  3) // 6:3    TSEG1 register value
#define   TSEG1_14         ((unsigned int) 0x0d <<  3) // 6:3    TSEG1 register value
#define   TSEG1_15         ((unsigned int) 0x0e <<  3) // 6:3    TSEG1 register value
#define   TSEG1_16         ((unsigned int) 0x0f <<  3) // 6:3    TSEG1 register value
#define   SAM              ((unsigned int) 0x1 <<  7) // 7      Sample point setting
#define   SJW0             ((unsigned int) 0x1 <<  8) // 9:8    Synchroniztion jump width register value
#define   SJW1             ((unsigned int) 0x1 <<  9) // 9:8    Synchroniztion jump width register value
#define   SJW_1            ((unsigned int) 0x0 <<  8) // 9:8    Synchroniztion jump width register value
#define   SJW_2            ((unsigned int) 0x1 <<  8) // 9:8    Synchroniztion jump width register value
#define   SJW_3            ((unsigned int) 0x2 <<  8) // 9:8    Synchroniztion jump width register value
#define   SJW_4            ((unsigned int) 0x3 <<  8) // 9:8    Synchroniztion jump width register value
#define   ERM              ((unsigned int) 0x1 <<  10) // 10     Edge re-synchronization mode

//-------------------------------------------------
// CAN Error & Status register bit definitions
//
//  CANES_BITS
#define   TM                ((unsigned int) 0x1 <<  0) // 0      Transmit mode
#define   RM                ((unsigned int) 0x1 <<  1) // 1      Receive mode
#define   PDA               ((unsigned int) 0x1 <<  3) // 3      Power-down acknowledge
#define   CCE               ((unsigned int) 0x1 <<  4) // 4      Change configuration enable
#define   SMA               ((unsigned int) 0x1 <<  5) // 5      Suspend mode acknowledge
#define   EW                ((unsigned int) 0x1 <<  16) // 16     Warning status
#define   EP                ((unsigned int) 0x1 <<  17) // 17     Error passive status
#define   BO                ((unsigned int) 0x1 <<  18) // 18     Bus-off status
#define   ACKE              ((unsigned int) 0x1 <<  19) // 19     Acknowledge error
#define   SE                ((unsigned int) 0x1 <<  20) // 20     Stuff error
#define   CRCE              ((unsigned int) 0x1 <<  21) // 21     CRC error
#define   SA1               ((unsigned int) 0x1 <<  22) // 22     Stuck at dominant error
#define   BE                ((unsigned int) 0x1 <<  23) // 23     Bit error
#define   FE                ((unsigned int) 0x1 <<  24) // 24     Framing error

//-------------------------------------------------

// CAN Global Interrupt Flag 0 Register bit definitions
//
//  CANGIF0_BITS
#define   MIV00          ((unsigned int) 0x1 <<  0) // 3:0    Mailbox interrupt vector
#define   MIV01          ((unsigned int) 0x1 <<  1) // 3:0    Mailbox interrupt vector
#define   MIV02          ((unsigned int) 0x1 <<  2) // 3:0    Mailbox interrupt vector
#define   MIV03          ((unsigned int) 0x1 <<  3) // 3:0    Mailbox interrupt vector
#define   MIV0_0           ((unsigned int) 0x0 <<  0) // 3:0    Mailbox interrupt vector
#define   MIV0_1           ((unsigned int) 0x1 <<  0) // 3:0    Mailbox interrupt vector
#define   MIV0_2           ((unsigned int) 0x2 <<  0) // 3:0    Mailbox interrupt vector
#define   MIV0_3           ((unsigned int) 0x3 <<  0) // 3:0    Mailbox interrupt vector
#define   MIV0_4           ((unsigned int) 0x4 <<  0) // 3:0    Mailbox interrupt vector
#define   MIV0_5           ((unsigned int) 0x5 <<  0) // 3:0    Mailbox interrupt vector
#define   MIV0_6           ((unsigned int) 0x6 <<  0) // 3:0    Mailbox interrupt vector
#define   MIV0_7           ((unsigned int) 0x7 <<  0) // 3:0    Mailbox interrupt vector
#define   MIV0_8           ((unsigned int) 0x8 <<  0) // 3:0    Mailbox interrupt vector
#define   MIV0_9           ((unsigned int) 0x9 <<  0) // 3:0    Mailbox interrupt vector
#define   MIV0_10          ((unsigned int) 0x0a <<  0) // 3:0    Mailbox interrupt vector
#define   MIV0_11          ((unsigned int) 0x0b <<  0) // 3:0    Mailbox interrupt vector
#define   MIV0_12          ((unsigned int) 0x0c <<  0) // 3:0    Mailbox interrupt vector
#define   MIV0_13          ((unsigned int) 0x0d <<  0) // 3:0    Mailbox interrupt vector
#define   MIV0_14          ((unsigned int) 0x0e <<  0) // 3:0    Mailbox interrupt vector
#define   MIV0_15          ((unsigned int) 0x0f <<  0) // 3:0    Mailbox interrupt vector
#define   WLIF0           ((unsigned int) 0x1 <<  8) // 8      Warning level interrupt flag
#define   EPIF0           ((unsigned int) 0x1 <<  9) // 9      Error-passive interrupt flag
#define   BOIF0           ((unsigned int) 0x1 <<  10) // 10     Bus-off interrupt flag
#define   RMLIF0          ((unsigned int) 0x1 <<  11) // 11     Received message lost interrupt flag
#define   WUIF0           ((unsigned int) 0x1 <<  12) // 12     Wakeup interrupt flag
#define   WDIF0           ((unsigned int) 0x1 <<  13) // 13     Write denied interrupt flag
#define   AAIF0           ((unsigned int) 0x1 <<  14) // 14     Abort ack interrupt flag
#define   GMIF0           ((unsigned int) 0x1 <<  15) // 15     Global mailbox interrupt flag

//-------------------------------------------------
// CAN Global Interrupt Mask register bit definitions
//
//  CANGIM_BITS
#define   I0EN             ((unsigned int) 0x1 <<  0) // 0      Interrupt 0 enable
#define   I1EN             ((unsigned int) 0x1 <<  1) // 1      Interrupt 1 enable
#define   GIL              ((unsigned int) 0x1 <<  2) // 2      Global interrupt level
#define   WLIM             ((unsigned int) 0x1 <<  8) // 8      Warning level interrupt mask
#define   EPIM             ((unsigned int) 0x1 <<  9) // 9      Error-passive interrupt mask
#define   BOIM             ((unsigned int) 0x1 <<  10) // 10     Bus-off interrupt mask
#define   RMLIM            ((unsigned int) 0x1 <<  11) // 11     Received message lost interrupt mask
#define   WUIM             ((unsigned int) 0x1 <<  12) // 12     Wakeup interrupt mask
#define   WDIM             ((unsigned int) 0x1 <<  13) // 13     Write denied interrupt mask
#define   AAIM             ((unsigned int) 0x1 <<  14) // 14     Abort Ack interrupt mask

//-------------------------------------------------
// CAN Global Interrupt Flag 1 Register bit definitions
//
//  CANGIF1_BITS
#define   MIV10           ((unsigned int) 0x1 <<  0)          // 3:0    Mailbox interrupt Vector
#define   MIV11           ((unsigned int) 0x1 <<  1)          // 3:0    Mailbox interrupt Vector
#define   MIV12           ((unsigned int) 0x1 <<  2)          // 3:0    Mailbox interrupt Vector
#define   MIV13           ((unsigned int) 0x1 <<  3)          // 3:0    Mailbox interrupt Vector
#define   MIV1_0          ((unsigned int) 0x0 <<  0) // 3:0    Mailbox interrupt vector
#define   MIV1_1          ((unsigned int) 0x1 <<  0) // 3:0    Mailbox interrupt vector
#define   MIV1_2          ((unsigned int) 0x2 <<  0) // 3:0    Mailbox interrupt vector
#define   MIV1_3          ((unsigned int) 0x3 <<  0) // 3:0    Mailbox interrupt vector
#define   MIV1_4          ((unsigned int) 0x4 <<  0) // 3:0    Mailbox interrupt vector
#define   MIV1_5          ((unsigned int) 0x5 <<  0) // 3:0    Mailbox interrupt vector
#define   MIV1_6          ((unsigned int) 0x6 <<  0) // 3:0    Mailbox interrupt vector
#define   MIV1_7          ((unsigned int) 0x7 <<  0) // 3:0    Mailbox interrupt vector
#define   MIV1_8          ((unsigned int) 0x8 <<  0) // 3:0    Mailbox interrupt vector
#define   MIV1_9          ((unsigned int) 0x9 <<  0) // 3:0    Mailbox interrupt vector
#define   MIV1_10         ((unsigned int) 0x0a <<  0) // 3:0    Mailbox interrupt vector
#define   MIV1_11         ((unsigned int) 0x0b <<  0) // 3:0    Mailbox interrupt vector
#define   MIV1_12         ((unsigned int) 0x0c <<  0) // 3:0    Mailbox interrupt vector
#define   MIV1_13         ((unsigned int) 0x0d <<  0) // 3:0    Mailbox interrupt vector
#define   MIV1_14         ((unsigned int) 0x0e <<  0) // 3:0    Mailbox interrupt vector
#define   MIV1_15         ((unsigned int) 0x0f <<  0) // 3:0    Mailbox interrupt vector
#define   WLIF1           ((unsigned int) 0x1 <<  8) // 8      Warning level interrupt flag
#define   EPIF1           ((unsigned int) 0x1 <<  9) // 9      Error-passive interrupt flag
#define   BOIF1           ((unsigned int) 0x1 <<  10)  // 10     Bus-off interrupt flag
#define   RMLIF1          ((unsigned int) 0x1 <<  11) // 11     Received message lost interrupt flag
#define   WUIF1           ((unsigned int) 0x1 <<  12) // 12     Wakeup interrupt flag
#define   WDIF1           ((unsigned int) 0x1 <<  13) // 13     Write denied interrupt flag
#define   AAIF1           ((unsigned int) 0x1 <<  14) // 14     Abort ack interrupt flag
#define   GMIF1           ((unsigned int) 0x1 <<  15)  // 15     Global mailbox interrupt flag

//-------------------------------------------------
// CAN Mailbox Interrupt Mask register bit definitions
//
//  CANMIM_BITS
#define   MIM0             ((unsigned int) 0x1 <<  0) // 0      Mailbox 0
#define   MIM1             ((unsigned int) 0x1 <<  1) // 1      Mailbox 1
#define   MIM2             ((unsigned int) 0x1 <<  2) // 2      Mailbox 2
#define   MIM3             ((unsigned int) 0x1 <<  3) // 3      Mailbox 3
#define   MIM4             ((unsigned int) 0x1 <<  4) // 4      Mailbox 4
#define   MIM5             ((unsigned int) 0x1 <<  5) // 5      Mailbox 5
#define   MIM6             ((unsigned int) 0x1 <<  6) // 6      Mailbox 6
#define   MIM7             ((unsigned int) 0x1 <<  7) // 7      Mailbox 7
#define   MIM8             ((unsigned int) 0x1 <<  8) // 8      Mailbox 8
#define   MIM9             ((unsigned int) 0x1 <<  9) // 9      Mailbox 9
#define   MIM10            ((unsigned int) 0x1 <<  10) // 10     Mailbox 10
#define   MIM11            ((unsigned int) 0x1 <<  11) // 11     Mailbox 11
#define   MIM12            ((unsigned int) 0x1 <<  12) // 12     Mailbox 12
#define   MIM13            ((unsigned int) 0x1 <<  13) // 13     Mailbox 13
#define   MIM14            ((unsigned int) 0x1 <<  14) // 14     Mailbox 14
#define   MIM15            ((unsigned int) 0x1 <<  15) // 15     Mailbox 15

//-------------------------------------------------
// CAN Mailbox Interrupt Level register bit definitions
//
//  CANMIL_BITS
#define   MIL0             ((unsigned int) 0x1 <<  0) // 0      Mailbox 0
#define   MIL1             ((unsigned int) 0x1 <<  1) // 1      Mailbox 1
#define   MIL2             ((unsigned int) 0x1 <<  2) // 2      Mailbox 2
#define   MIL3             ((unsigned int) 0x1 <<  3) // 3      Mailbox 3
#define   MIL4             ((unsigned int) 0x1 <<  4) // 4      Mailbox 4
#define   MIL5             ((unsigned int) 0x1 <<  5) // 5      Mailbox 5
#define   MIL6             ((unsigned int) 0x1 <<  6) // 6      Mailbox 6
#define   MIL7             ((unsigned int) 0x1 <<  7) // 7      Mailbox 7
#define   MIL8             ((unsigned int) 0x1 <<  8) // 8      Mailbox 8
#define   MIL9             ((unsigned int) 0x1 <<  9) // 9      Mailbox 9
#define   MIL10            ((unsigned int) 0x1 <<  10) // 10     Mailbox 10
#define   MIL11            ((unsigned int) 0x1 <<  11) // 11     Mailbox 11
#define   MIL12            ((unsigned int) 0x1 <<  12) // 12     Mailbox 12
#define   MIL13            ((unsigned int) 0x1 <<  13) // 13     Mailbox 13
#define   MIL14            ((unsigned int) 0x1 <<  14) // 14     Mailbox 14
#define   MIL15            ((unsigned int) 0x1 <<  15) // 15     Mailbox 15

//-------------------------------------------------
// CAN Overwrite Protection Control register bit definitions
//
//  CANOPC_BITS
#define   OPC0             ((unsigned int) 0x1 <<  0) // 0      Mailbox 0
#define   OPC1             ((unsigned int) 0x1 <<  1) // 1      Mailbox 1
#define   OPC2             ((unsigned int) 0x1 <<  2) // 2      Mailbox 2
#define   OPC3             ((unsigned int) 0x1 <<  3) // 3      Mailbox 3
#define   OPC4             ((unsigned int) 0x1 <<  4) // 4      Mailbox 4
#define   OPC5             ((unsigned int) 0x1 <<  5) // 5      Mailbox 5
#define   OPC6             ((unsigned int) 0x1 <<  6) // 6      Mailbox 6
#define   OPC7             ((unsigned int) 0x1 <<  7) // 7      Mailbox 7
#define   OPC8             ((unsigned int) 0x1 <<  8) // 8      Mailbox 8
#define   OPC9             ((unsigned int) 0x1 <<  9) // 9      Mailbox 9
#define   OPC10            ((unsigned int) 0x1 <<  10) // 10     Mailbox 10
#define   OPC11            ((unsigned int) 0x1 <<  11) // 11     Mailbox 11
#define   OPC12            ((unsigned int) 0x1 <<  12) // 12     Mailbox 12
#define   OPC13            ((unsigned int) 0x1 <<  13) // 13     Mailbox 13
#define   OPC14            ((unsigned int) 0x1 <<  14) // 14     Mailbox 14
#define   OPC15            ((unsigned int) 0x1 <<  15) // 15     Mailbox 15

//-------------------------------------------------
// CAN TX I/O Control Register bit definitions[AD1]
//
//  CANTIOC_BITS
#define   TXIN             ((unsigned int) 0x1 <<  0) // 0      TX pin in data
#define   TXOUT            ((unsigned int) 0x1 <<  1) // 1      TX pin out data
#define   CAN_TXDIR        ((unsigned int) 0x1 <<  2) // 2      TX pin direction
#define   TXFUNC           ((unsigned int) 0x1 <<  3) // 3      TX pin function

//-------------------------------------------------
// CAN RX I/O Control Register bit definitions[AD2]
//
//  CANRIOC_BITS
#define   RXIN             ((unsigned int) 0x1 <<  0) // 0      RX pin in data
#define   RXOUT            ((unsigned int) 0x1 <<  1) // 1      RX pin out data
#define   CAN_RXDIR        ((unsigned int) 0x1 <<  2) // 2      RX pin direction
#define   RXFUNC           ((unsigned int) 0x1 <<  3) // 3      RX pin function


//===========================================================================
// SCC Local Acceptance Mask Registers Individual Bit Definitions
//

//-------------------------------------------------
// CAN Local Acceptance Mask bit definitions
//
//  CANLAM_BITS
#define   LAM0             ((unsigned int) 0x1 <<  0) // 0 Local acceptance mask  28:0
#define   LAM1             ((unsigned int) 0x1 <<  1) // 1 Local acceptance mask
#define   LAM2             ((unsigned int) 0x1 <<  2) // 2 Local acceptance mask
#define   LAM3             ((unsigned int) 0x1 <<  3) // 3 Local acceptance mask
#define   LAM4             ((unsigned int) 0x1 <<  4) // 4 Local acceptance mask
#define   LAM5             ((unsigned int) 0x1 <<  5) // 5 Local acceptance mask
#define   LAM6             ((unsigned int) 0x1 <<  6) // 6 Local acceptance mask
#define   LAM7             ((unsigned int) 0x1 <<  7) // 7 Local acceptance mask
#define   LAM8             ((unsigned int) 0x1 <<  8) // 8 Local acceptance mask
#define   LAM9             ((unsigned int) 0x1 <<  9) // 9 Local acceptance mask
#define   LAM10            ((unsigned int) 0x1 <<  10) // 10 Local acceptance mask
#define   LAM11            ((unsigned int) 0x1 <<  11) // 11 Local acceptance mask
#define   LAM12            ((unsigned int) 0x1 <<  12) // 12 Local acceptance mask
#define   LAM13            ((unsigned int) 0x1 <<  13) // 13 Local acceptance mask
#define   LAM14            ((unsigned int) 0x1 <<  14) // 14 Local acceptance mask
#define   LAM15            ((unsigned int) 0x1 <<  15) // 15 Local acceptance mask
#define   LAM16            ((unsigned int) 0x1 <<  16) // 16 Local acceptance mask
#define   LAM17            ((unsigned int) 0x1 <<  17) // 17 Local acceptance mask
#define   LAM18            ((unsigned int) 0x1 <<  18) // 18 Local acceptance mask
#define   LAM19            ((unsigned int) 0x1 <<  19) // 19 Local acceptance mask
#define   LAM20            ((unsigned int) 0x1 <<  20) // 20 Local acceptance mask
#define   LAM21            ((unsigned int) 0x1 <<  21) // 21 Local acceptance mask
#define   LAM22            ((unsigned int) 0x1 <<  22) // 22 Local acceptance mask
#define   LAM23            ((unsigned int) 0x1 <<  23) // 23 Local acceptance mask
#define   LAM24            ((unsigned int) 0x1 <<  24) // 24 Local acceptance mask
#define   LAM25            ((unsigned int) 0x1 <<  25) // 25 Local acceptance mask
#define   LAM26            ((unsigned int) 0x1 <<  26) // 26 Local acceptance mask
#define   LAM27            ((unsigned int) 0x1 <<  27) // 27 Local acceptance mask
#define   LAM28            ((unsigned int) 0x1 <<  28) // 28 Local acceptance mask
#define   LAMI             ((unsigned int) 0x1 <<  31) // 31 Local acceptance mask identifier extension bit

//===========================================================================
// SCC Mailbox Individual Bit Definitions
//

//-------------------------------------------------
// CAN Message ID bit definitions
//
//  CANMID_BITS
#define   ID0             ((unsigned int) 0x1 <<  0) // 0 Identifier  28:0
#define   ID1             ((unsigned int) 0x1 <<  1) // 1 Identifier
#define   ID2             ((unsigned int) 0x1 <<  2) // 2 Identifier
#define   ID3             ((unsigned int) 0x1 <<  3) // 3 Identifier
#define   ID4             ((unsigned int) 0x1 <<  4) // 4 Identifier
#define   ID5             ((unsigned int) 0x1 <<  5) // 5 Identifier
#define   ID6             ((unsigned int) 0x1 <<  6) // 6 Identifier
#define   ID7             ((unsigned int) 0x1 <<  7) // 7 Identifier
#define   ID8             ((unsigned int) 0x1 <<  8) // 8 Identifier
#define   ID9             ((unsigned int) 0x1 <<  9) // 9 Identifier
#define   ID10            ((unsigned int) 0x1 <<  10) // 10 Identifier
#define   ID11            ((unsigned int) 0x1 <<  11) // 11 Identifier
#define   ID12            ((unsigned int) 0x1 <<  12) // 12 Identifier
#define   ID13            ((unsigned int) 0x1 <<  13) // 13 Identifier
#define   ID14            ((unsigned int) 0x1 <<  14) // 14 Identifier
#define   ID15            ((unsigned int) 0x1 <<  15) // 15 Identifier
#define   ID16            ((unsigned int) 0x1 <<  16) // 16 Identifier
#define   ID17            ((unsigned int) 0x1 <<  17) // 17 Identifier
#define   ID18            ((unsigned int) 0x1 <<  18) // 18 Identifier
#define   ID19            ((unsigned int) 0x1 <<  19) // 19 Identifier
#define   ID20            ((unsigned int) 0x1 <<  20) // 20 Identifier
#define   ID21            ((unsigned int) 0x1 <<  21) // 21 Identifier
#define   ID22            ((unsigned int) 0x1 <<  22) // 22 Identifier
#define   ID23            ((unsigned int) 0x1 <<  23) // 23 Identifier
#define   ID24            ((unsigned int) 0x1 <<  24) // 24 Identifier
#define   ID25            ((unsigned int) 0x1 <<  25) // 25 Identifier
#define   ID26            ((unsigned int) 0x1 <<  26) // 26 Identifier
#define   ID27            ((unsigned int) 0x1 <<  27) // 27 Identifier
#define   ID28            ((unsigned int) 0x1 <<  28) // 28 Identifier
#define   AAM             ((unsigned int) 0x1 <<  29) // 29 AAM
#define   AME             ((unsigned int) 0x1 <<  30) // 30 AME
#define   IDE             ((unsigned int) 0x1 <<  31) // 31 IDE

//-------------------------------------------------
// CAN Message Control Field bit definitions
//
//  CANMCF_BITS
#define   DLC0           ((unsigned int) 0x0 <<  0) // 0:3    Data code 0
#define   DLC1           ((unsigned int) 0x1 <<  0) // 0:3    Data code 1
#define   DLC2           ((unsigned int) 0x2 <<  0) // 0:3    Data length code 2
#define   DLC_0           ((unsigned int) 0x0 <<  0) // 0:3    Data length code 0
#define   DLC_1           ((unsigned int) 0x1 <<  0) // 0:3    Data length code 1
#define   DLC_2           ((unsigned int) 0x2 <<  0) // 0:3    Data length code 2
#define   DLC_3           ((unsigned int) 0x3 <<  0) // 0:3    Data length code 3
#define   DLC_4           ((unsigned int) 0x4 <<  0) // 0:3    Data length code 4
#define   DLC_5           ((unsigned int) 0x5 <<  0) // 0:3    Data length code 5
#define   DLC_6           ((unsigned int) 0x6 <<  0) // 0:3    Data length code 6
#define   DLC_7           ((unsigned int) 0x7 <<  0) // 0:3    Data length code 7
#define   DLC_8           ((unsigned int) 0x8 <<  0) // 0:3    Data length code 8
#define   RTR             ((unsigned int) 0x1 <<  4) // 4   Remote transmission request bit





//*************************************************************************************
// SCI Module
//-------------------------------------------------
// SCI Communication Control Register bit definitions
//
// SCICCR BITS
#define   CHAR0               ((unsigned int) 0x0 <<  0)    // Character  control 1
#define   CHAR1               ((unsigned int) 0x1 <<  0)    // Character  control 2
#define   CHAR2               ((unsigned int) 0x2 <<  0)    // Character  control 3
#define   CHAR_1              ((unsigned int) 0x0 <<  0)    // Character length control 1
#define   CHAR_2              ((unsigned int) 0x1 <<  0)    // Character length control 2
#define   CHAR_3              ((unsigned int) 0x2 <<  0)    // Character length control 3
#define   CHAR_4              ((unsigned int) 0x3 <<  0)    // Character length control 4
#define   CHAR_5              ((unsigned int) 0x4 <<  0)    // Character length control 5
#define   CHAR_6              ((unsigned int) 0x5 <<  0)    // Character length control 6
#define   CHAR_7              ((unsigned int) 0x6 <<  0)    // Character length control 7
#define   CHAR_8              ((unsigned int) 0x7 <<  0)    // Character length control 8
#define   COMM_MODE_ADDRESS   ((unsigned int) 0x1 <<  3)    // Address Mode
#define   TIMING_MODE_ASYNC   ((unsigned int) 0x1 <<  4)    // Timing Mode
#define   PARITY_ENA          ((unsigned int) 0x1 <<  5)    // Parity Enable
#define   PARITY              ((unsigned int) 0x1 <<  6)    // Even Parity
#define   STOP                ((unsigned int) 0x1 <<  7)    // Two Stop Bits



//-------------------------------------------------
//  Control Register 1 bit definitions
//
// SCICTL1 BITS
#define   RXENA               ((unsigned int) 0x1 <<  0)    //  0      Rx enable
#define   RXWAKE              ((unsigned int) 0x1 <<  1)    //  1      Rx wake-up flag
#define   RXRDY               ((unsigned int) 0x1 <<  2)    //  2      Rx ready flag
#define   SLEEP               ((unsigned int) 0x1 <<  3)    //  3      Sleep
#define   SCICTL1_IDLE        ((unsigned int) 0x1 <<  4)    //  4      Idle state
#define   RX_DMA_ENA          ((unsigned int) 0x1 <<  5)    //  5      SCI RX DMA interrupt enable
#define   RX_DMA_ALL          ((unsigned int) 0x1 <<  6)    //  6      SCI RX DMA interrupt control


//-------------------------------------------------
// SCI Control Register 2 bit definitions
//
// SCICTL2 BITS
#define   TXENA               ((unsigned int) 0x1 <<  0)    // 0      Tx enable
#define   TXWAKE              ((unsigned int) 0x1 <<  1)    // 1      Tx wake-up flag
#define   TXRDY               ((unsigned int) 0x1 <<  2)    // 2      Tx ready flag
#define   TX_EMPTY            ((unsigned int) 0x1 <<  3)    // 3      Tx empty flag
#define   TX_DMA_ENA          ((unsigned int) 0x1 <<  5)    // 5       TX DMA interrupt enable
#define   LOOP_BACK           ((unsigned int) 0x1 <<  6)    // 6      Loopback mode
#define   CONT                ((unsigned int) 0x1 <<  7)    // 7      Continue on suspend


//-------------------------------------------------
// SCI Control Register 3 bit definitions
//
//  SCICTL3 BITS
#define   RXERR_INT_ENA       ((unsigned int) 0x1 <<  0)    // 0      Rx error interrupt enable
#define   BRKDT_INT_ENA       ((unsigned int) 0x1 <<  1)    // 1      Break-detect interrupt enable
#define   WAKEUP_INT_ENA      ((unsigned int) 0x1 <<  2)    // 2      Wake-up interrupt enable
#define   TX_ACTION_ENA       ((unsigned int) 0x1 <<  3)    // 3      Tx DMA or interrupt enable
#define   RX_ACTION_ENA       ((unsigned int) 0x1 <<  4)    // 4      Rx DMA or interrupt enable
#define   CLOCK               ((unsigned int) 0x1 <<  5)    // 5      Internal clock enable
#define   SCI_POWERDOWN           ((unsigned int) 0x1 <<  6)    // 6      Power down
#define   SW_NRESET           ((unsigned int) 0x1 <<  7)    // 7      Software reset (active low)

//-------------------------------------------------
// SCI Receiver Status Register bit definitions
//
// SCIRXST BITS
#define   RXERROR             ((unsigned int) 0x1 <<  0)    // 0      Receiver error flag
#define   BRKDT               ((unsigned int) 0x1 <<  1)    // 1      Break-detect flag
#define   WAKEUP              ((unsigned int) 0x1 <<  2)    // 2      Wake-up flag
#define   PE                  ((unsigned int) 0x1 <<  3)    // 3      Parity error flag
#define   OE                  ((unsigned int) 0x1 <<  4)    // 4      Overrun error flag
#define   SCIRXST_FE                  ((unsigned int) 0x1 <<  5)    // 5      Framing error flag
#define   BUS_BUSY            ((unsigned int) 0x1 <<  7)    // 7      Bus busy flag

//-------------------------------------------------
// SCI Pin Control Register 1 bit definitions
//
// SCIPC1 BITS
#define   CLK_DATA_DIR        ((unsigned int) 0x1 <<  0)    // 0      SCICLK pin direction
#define   CLK_FUNC            ((unsigned int) 0x1 <<  1)    // 1      CLK pin function
#define   CLK_DATA_OUT        ((unsigned int) 0x1 <<  2)    // 2      SCICLK pin output data
#define   CLK_DATA_IN         ((unsigned int) 0x1 <<  3)    // 3      SCICLK pin input data


//-------------------------------------------------
// SCI Pin Control Register 2 bit definitions
//
//  SCIPC2 BITS
#define   RX_DATA_DIR         ((unsigned int) 0x1 <<  0)    // 0      SCIRX pin direction
#define   RX_FUNC             ((unsigned int) 0x1 <<  1)    // 1      SCIRX pin function
#define   RX_DATA_OUT         ((unsigned int) 0x1 <<  2)    // 2      SCIRX pin output data
#define   RX_DATA_IN          ((unsigned int) 0x1 <<  3)    // 3      SCIRX pin input data


//-------------------------------------------------
// SCI Pin Control Register 3 bit definitions
//
//  SCIPC3 BITS
#define   TX_DATA_DIR         ((unsigned int) 0x1 <<  0)    // 0      SCITX pin direction
#define   TX_FUNC             ((unsigned int) 0x1 <<  1)    // 1      SCITX pin function
#define   TX_DATA_OUT         ((unsigned int) 0x1 <<  2)    // 2      SCITX pin output data
#define   TX_DATA_IN          ((unsigned int) 0x1 <<  3)    // 3      SCITX pin input data


//*******************************************************************************************
//   System Module
//-------------------------------------------------
// Static Memory Control Register 0 bit definitions
//
// SMCR0,  SMCRX_
#define   DW0                  ((unsigned int) 0x1 <<  0)    // 0    Data width 0
#define   DW1                  ((unsigned int) 0x1 <<  0)    // 1    Data width 1
#define   DW_8                 ((unsigned int) 0x0 <<  0)    // 1:0    Data width 8 bits
#define   DW_16                ((unsigned int) 0x1 <<  0)    // 1:0    Data width 16 bits
#define   DW_32                ((unsigned int) 0x2 <<  0)    // 1:0    Data width 32 bits
#define   END_LITTLE           ((unsigned int) 0x1 <<  3)    // 3      Endian mode
#define   WS0                  ((unsigned int) 0x1 <<  4)    //  Wait states  0
#define   WS1                  ((unsigned int) 0x1 <<  5)    //  Wait states  1
#define   WS2                  ((unsigned int) 0x1 <<  6)    //  Wait states  2
#define   WS3                  ((unsigned int) 0x1 <<  7)    //  Wait states  3
#define   WS_0                 ((unsigned int) 0x0 <<  4)    //  Wait states (read/write) 0
#define   WS_1                 ((unsigned int) 0x1 <<  5)    //  Wait states (read/write) 1
#define   WS_2                 ((unsigned int) 0x2 <<  6)    //  Wait states (read/write) 2
#define   WS_3                 ((unsigned int) 0x3 <<  7)    //  Wait states (read/write) 3
#define   WS_4                 ((unsigned int) 0x4 <<  4)    //  Wait states (read/write) 4
#define   WS_5                 ((unsigned int) 0x5 <<  4)    //  Wait states (read/write) 5
#define   WS_6                 ((unsigned int) 0x6 <<  4)    //  Wait states (read/write) 6
#define   WS_7                 ((unsigned int) 0x7 <<  4)    //  Wait states (read/write) 7
#define   WS_8                 ((unsigned int) 0x8 <<  4)    //  Wait states (read/write) 8
#define   WS_9                 ((unsigned int) 0x9 <<  4)    //  Wait states (read/write) 9
#define   WS_10                ((unsigned int) 0x0A <<  4)    //  Wait states (read/write) 10
#define   WS_11                ((unsigned int) 0x0B <<  4)    //  Wait states (read/write) 11
#define   WS_12                ((unsigned int) 0x0C <<  4)    //  Wait states (read/write) 12
#define   WS_13                ((unsigned int) 0x0D <<  4)    //  Wait states (read/write) 13
#define   WS_14                ((unsigned int) 0x0E <<  4)    //  Wait states (read/write) 14
#define   WS_15                ((unsigned int) 0x0F <<  4)    //  Wait states (read/write) 15
#define   TWS0                 ((unsigned int) 0x1 <<  9)    // Trailing wait states (read/write)
#define   TWS1                 ((unsigned int) 0x1 <<  10)    // Trailing wait states (read/write)
#define   TWS2                 ((unsigned int) 0x1 <<  11)    // Trailing wait states (read/write)
#define   TWS_0                ((unsigned int) 0x0 <<  9)    // Trailing wait states (read/write)
#define   TWS_1                ((unsigned int) 0x1 <<  9)    // Trailing wait states (read/write)
#define   TWS_2                ((unsigned int) 0x2 <<  9)    // Trailing wait states (read/write)
#define   TWS_3                ((unsigned int) 0x3 <<  9)    // Trailing wait states (read/write)
#define   TWS_4                ((unsigned int) 0x4 <<  9)    // Trailing wait states (read/write)
#define   TWS_5                ((unsigned int) 0x5 <<  9)    // Trailing wait states (read/write)
#define   TWS_6                ((unsigned int) 0x6 <<  9)    // Trailing wait states (read/write)
#define   TWS_7                ((unsigned int) 0x7 <<  9)    // Trailing wait states (read/write)
#define   ASC0                 ((unsigned int) 0x1 <<  12)  // 12  Address setup time cycles
#define   ASC1                 ((unsigned int) 0x1 <<  13)  // 13  Address setup time cycles
#define   ASC_0                ((unsigned int) 0x0 <<  12)  // 13:12  Address setup time cycles (write) no setup
#define   ASC_1                ((unsigned int) 0x1 <<  12)  // 13:12  Address setup time cycles (write) wr strobe delayed 1 cycle
#define   ASC_2                ((unsigned int) 0x2 <<  12)  // 13:12  Address setup time cycles (write) wr strobe delayed 2 cycle
#define   ASC_3                ((unsigned int) 0x3 <<  12)  // 13:12  Address setup time cycles (write) wr strobe delayed 3 cycle


//-------------------------------------------------
// Write Control Register bit definitions
//
// WCR0_BITS
#define   WBENABLE              ((unsigned int) 0x1 <<  0)    // 0      Write buffer enable
#define   WTWSOVR               ((unsigned int) 0x1 <<  1)    // 1      Write trailing wait state override

//-------------------------------------------------
// Peripheral Clock Register bit definitions
//
//  PCR_BITS
#define  PENABLE                 ((unsigned int) 0x1 <<  0)    // 0      Peripheral enable
#define  CLKDIV0                 ((unsigned int) 0x1 <<  1)    // 0 Peripheral clock divide
#define  CLKDIV1                 ((unsigned int) 0x1 <<  2)    // 1 Peripheral clock divide
#define  CLKDIV2                 ((unsigned int) 0x1 <<  3)    // 2 Peripheral clock divide
#define  CLKDIV3                 ((unsigned int) 0x1 <<  4)    // 3 Peripheral clock divide
#define  CLKDIV_1                ((unsigned int) 0x0 <<  1)    // Peripheral clock divide ratio ICLK=SYSCLK
#define  CLKDIV_2                ((unsigned int) 0x1 <<  1)    // Peripheral clock divide ratio ICLK=SYSCLK/2
#define  CLKDIV_3                ((unsigned int) 0x2 <<  1)    // Peripheral clock divide ratio ICLK=SYSCLK/3
#define  CLKDIV_4                ((unsigned int) 0x3 <<  1)    // Peripheral clock divide ratio ICLK=SYSCLK/4
#define  CLKDIV_5                ((unsigned int) 0x4 <<  1)    // Peripheral clock divide ratio ICLK=SYSCLK/5
#define  CLKDIV_6                ((unsigned int) 0x5 <<  1)    // Peripheral clock divide ratio ICLK=SYSCLK/6
#define  CLKDIV_7                ((unsigned int) 0x6 <<  1)    // Peripheral clock divide ratio ICLK=SYSCLK/7
#define  CLKDIV_8                ((unsigned int) 0x7 <<  1)    // Peripheral clock divide ratio ICLK=SYSCLK/8
#define  CLKDIV_9                ((unsigned int) 0x8 <<  1)    // Peripheral clock divide ratio ICLK=SYSCLK/9
#define  CLKDIV_10               ((unsigned int) 0x9 <<  1)    // Peripheral clock divide ratio ICLK=SYSCLK/10
#define  CLKDIV_11               ((unsigned int) 0x0A <<  1)    // Peripheral clock divide ratio ICLK=SYSCLK/11
#define  CLKDIV_12               ((unsigned int) 0x0B <<  1)    // Peripheral clock divide ratio ICLK=SYSCLK/12
#define  CLKDIV_13               ((unsigned int) 0x0C <<  1)    // Peripheral clock divide ratio ICLK=SYSCLK/13
#define  CLKDIV_14               ((unsigned int) 0x0D <<  1)    // Peripheral clock divide ratio ICLK=SYSCLK/14
#define  CLKDIV_15               ((unsigned int) 0x0E <<  1)    // Peripheral clock divide ratio ICLK=SYSCLK/15
#define  CLKDIV_16               ((unsigned int) 0x0F <<  1)    // Peripheral clock divide ratio ICLK=SYSCLK/16

//-------------------------------------------------
// Peripheral Location Register bit definitions
//
// PLR_BITS
#define   PLOC0                 ((unsigned int) 0x1 <<  0)    // 0      Peripheral 0 location
#define   PLOC1                 ((unsigned int) 0x1 <<  1)    // 1      Peripheral 1 location
#define   PLOC2                 ((unsigned int) 0x1 <<  2)    // 2      Peripheral 2 location
#define   PLOC3                 ((unsigned int) 0x1 <<  3)    // 3      Peripheral 3 location
#define   PLOC4                 ((unsigned int) 0x1 <<  4)    // 4      Peripheral 4 location
#define   PLOC5                 ((unsigned int) 0x1 <<  5)    // 5      Peripheral 5 location
#define   PLOC6                 ((unsigned int) 0x1 <<  6)    // 6      Peripheral 6 location
#define   PLOC7                 ((unsigned int) 0x1 <<  7)    // 7      Peripheral 7 location
#define   PLOC8                 ((unsigned int) 0x1 <<  8)    // 8      Peripheral 8 location
#define   PLOC9                 ((unsigned int) 0x1 <<  9)    // 9      Peripheral 9 location
#define   PLOC10                ((unsigned int) 0x1 <<  10)    // 10     Peripheral 10 location
#define   PLOC11                ((unsigned int) 0x1 <<  11)    // 11     Peripheral 11 location
#define   PLOC12                ((unsigned int) 0x1 <<  12)    // 12     Peripheral 12 location
#define   PLOC13                ((unsigned int) 0x1 <<  13)    // 13     Peripheral 13 location
#define   PLOC14                ((unsigned int) 0x1 <<  14)    // 14     Peripheral 14 location
#define   PLOC15                ((unsigned int) 0x1 <<  15)    // 15     Peripheral 15 location

//-------------------------------------------------
// Peripheral Protection Register bit definitions
//
// struct  PPROT_BITS
#define   PPROT0                    ((unsigned int) 0x1 <<  0)    // 0      Peripheral 0 protection
#define   PPROT1                    ((unsigned int) 0x1 <<  1)    // 1      Peripheral 1 protection
#define   PPROT2                    ((unsigned int) 0x1 <<  2)    // 2      Peripheral 2 protection
#define   PPROT3                    ((unsigned int) 0x1 <<  3)    // 3      Peripheral 3 protection
#define   PPROT4                    ((unsigned int) 0x1 <<  4)    // 4      Peripheral 4 protection
#define   PPROT5                    ((unsigned int) 0x1 <<  5)    // 5      Peripheral 5 protection
#define   PPROT6                    ((unsigned int) 0x1 <<  6)    // 6      Peripheral 6 protection
#define   PPROT7                    ((unsigned int) 0x1 <<  7)    // 7      Peripheral 7 protection
#define   PPROT8                    ((unsigned int) 0x1 <<  8)    // 8      Peripheral 8 protection
#define   PPROT9                    ((unsigned int) 0x1 <<  9)    // 9      Peripheral 9 protection
#define   PPROT10                   ((unsigned int) 0x1 <<  10)    // 10     Peripheral 10 protection
#define   PPROT11                   ((unsigned int) 0x1 <<  11)    // 11     Peripheral 11 protection
#define   PPROT12                   ((unsigned int) 0x1 <<  12)    // 12     Peripheral 12 protection
#define   PPROT13                   ((unsigned int) 0x1 <<  13)    // 13     Peripheral 13 protection
#define   PPROT14                   ((unsigned int) 0x1 <<  14)    // 14     Peripheral 14 protection
#define   PPROT15                   ((unsigned int) 0x1 <<  15)    // 15     Peripheral 15 protection

//-------------------------------------------------
// Memory Fine Base Address Low Register 0 bit definitions
//
//  MFBALR0 MFBALRx MCBALRX
#define   PRIV               ((unsigned int) 0x1 <<  0)    // 0      Privilege mode protection
#define   RONLY              ((unsigned int) 0x1 <<  1)    // 1      Read-only protection
#define   ZERO               ((unsigned int) 0x1 <<  3)    // 3      User must clear this bit to 0
#define   BLOCK_SIZE_DIS     ((unsigned int) 0x0 <<  4)    // 7:4    Block size
#define   BLOCK_SIZE_1K      ((unsigned int) 0x1 <<  4)    // 7:4    Block size
#define   BLOCK_SIZE_2K      ((unsigned int) 0x2 <<  4)    // 7:4    Block size
#define   BLOCK_SIZE_4K      ((unsigned int) 0x3 <<  4)    // 7:4    Block size
#define   BLOCK_SIZE_8K      ((unsigned int) 0x4 <<  4)    // 7:4    Block size
#define   BLOCK_SIZE_16K     ((unsigned int) 0x5 <<  4)    // 7:4    Block size
#define   BLOCK_SIZE_32K     ((unsigned int) 0x6 <<  4)    // 7:4    Block size
#define   BLOCK_SIZE_64K     ((unsigned int) 0x7 <<  4)    // 7:4    Block size
#define   BLOCK_SIZE_128K    ((unsigned int) 0x8 <<  4)    // 7:4    Block size
#define   BLOCK_SIZE_256K    ((unsigned int) 0x9 <<  4)    // 7:4    Block size
#define   BLOCK_SIZE_512K    ((unsigned int) 0x0A <<  4)    // 7:4    Block size
#define   BLOCK_SIZE_1M      ((unsigned int) 0x0B <<  4)    // 7:4    Block size
#define   BLOCK_SIZE_2M      ((unsigned int) 0x0C <<  4)    // 7:4    Block size
#define   BLOCK_SIZE_4M      ((unsigned int) 0x0D <<  4)    // 7:4    Block size
#define   BLOCK_SIZE_8M      ((unsigned int) 0x0E <<  4)    // 7:4    Block size
#define   BLOCK_SIZE_16M     ((unsigned int) 0x0F <<  4)    // 7:4    Block size
#define   MS                 ((unsigned int) 0x1 <<  8)     // 8      Memory map select
#define   AW                 ((unsigned int) 0x1 <<  9)     // 9      Memory map select



//-------------------------------------------------
// RTI Preload Control Register bit definitions
//
//  RTIPCTL_BITS [AD3]
#define   RTIM_CNTR20        ((unsigned int) 0x0 <<  11)    // 13:11  Tap select CNTR 20
#define   RTIM_CNTR17        ((unsigned int) 0x1 <<  11)    // 13:11  Tap select CNTR 17
#define   RTIM_CNTR14        ((unsigned int) 0x2 <<  11)    // 13:11  Tap select CNTR 14
#define   RTIM_CNTR11        ((unsigned int) 0x3 <<  11)    // 13:11  Tap select CNTR 11
#define   RTIM_CNTR8         ((unsigned int) 0x4 <<  11)    // 13:11  Tap select CNTR 8
#define   RTIM_CNTR5         ((unsigned int) 0x5 <<  11)    // 13:11  Tap select CNTR 5
#define   RTIM_CNTR2         ((unsigned int) 0x6 <<  11)    // 13:11  Tap select CNTR 2
#define   RTIM_UNDFLOW       ((unsigned int) 0x7 <<  11)    // 13:11  Tap select UNDFLOW

//-------------------------------------------------
// RTI Control Register bit definitions
//
//  RTICNTL_BITS
#define   TAPENA             ((unsigned int) 0x1 <<  6)    // 6      Tap interrupt enable bit
#define   TAPFLAG            ((unsigned int) 0x1 <<  7)    // 7      Tap interrupt flag bit

//-------------------------------------------------
// RTI Compare Interrupt Control Register bit definitions
//
//  RTICINT_BITS
#define   CMP2ENA            ((unsigned int) 0x1 <<  4)    // 4      Compare 2 enable
#define   CMP1ENA            ((unsigned int) 0x1 <<  5)    // 5      Compare 1 enable
#define   CMP2FLAG           ((unsigned int) 0x1 <<  6)    // 6      Compare 2 flag
#define   CMP1FLAG           ((unsigned int) 0x1 <<  7)    // 7      Compare 1 flag

//-------------------------------------------------
// RTI Count Enable Register bit definitions
//
//  RTICNTEN_BITS
#define   CNTEN_UP          ((unsigned int) 0x0 <<  0)    // 1:0    Counter enable User / Privilege
#define   CNTEN_PO          ((unsigned int) 0x1 <<  0)    // 1:0    Counter enable Privilege Olny
#define   CNTEN_UO          ((unsigned int) 0x2 <<  0)    // 1:0    Counter enable User Only
#define   CNTEN_NOCNT       ((unsigned int) 0x3 <<  0)    // 1:0    Counter enable No Count

//-------------------------------------------------
// FIQ/IRQ Program Control Register bit definitions
//
//  FIRQPR_BITS
#define   FIRQPR0                   ((unsigned int) 0x1 <<  0)  // 0      Interrupt 0
#define   FIRQPR1                   ((unsigned int) 0x1 <<  1)  // 1      Interrupt 1
#define   FIRQPR2                   ((unsigned int) 0x1 <<  2)  // 2      Interrupt 2
#define   FIRQPR3                   ((unsigned int) 0x1 <<  3)  // 3      Interrupt 3
#define   FIRQPR4                   ((unsigned int) 0x1 <<  4)  // 4      Interrupt 4
#define   FIRQPR5                   ((unsigned int) 0x1 <<  5)  // 5      Interrupt 5
#define   FIRQPR6                   ((unsigned int) 0x1 <<  6)  // 6      Interrupt 6
#define   FIRQPR7                   ((unsigned int) 0x1 <<  7)  // 7      Interrupt 7
#define   FIRQPR8                   ((unsigned int) 0x1 <<  8)  // 8      Interrupt 8
#define   FIRQPR9                   ((unsigned int) 0x1 <<  9)  // 9      Interrupt 9
#define   FIRQPR10                  ((unsigned int) 0x1 <<  10)  // 10     Interrupt 10
#define   FIRQPR11                  ((unsigned int) 0x1 <<  11)  // 11     Interrupt 11
#define   FIRQPR12                  ((unsigned int) 0x1 <<  12)  // 12     Interrupt 12
#define   FIRQPR13                  ((unsigned int) 0x1 <<  13)  // 13     Interrupt 13
#define   FIRQPR14                  ((unsigned int) 0x1 <<  14)  // 14     Interrupt 14
#define   FIRQPR15                  ((unsigned int) 0x1 <<  15)  // 15     Interrupt 15
#define   FIRQPR16                  ((unsigned int) 0x1 <<  16)  // 16     Interrupt 16
#define   FIRQPR17                  ((unsigned int) 0x1 <<  17)  // 17     Interrupt 17
#define   FIRQPR18                  ((unsigned int) 0x1 <<  18)  // 18     Interrupt 18
#define   FIRQPR19                  ((unsigned int) 0x1 <<  19)  // 19     Interrupt 19
#define   FIRQPR20                  ((unsigned int) 0x1 <<  20)  // 20     Interrupt 20
#define   FIRQPR21                  ((unsigned int) 0x1 <<  21)  // 21     Interrupt 21
#define   FIRQPR22                  ((unsigned int) 0x1 <<  22)  // 22     Interrupt 22
#define   FIRQPR23                  ((unsigned int) 0x1 <<  23)  // 23     Interrupt 23
#define   FIRQPR24                  ((unsigned int) 0x1 <<  24)  // 24     Interrupt 24
#define   FIRQPR25                  ((unsigned int) 0x1 <<  25)  // 25     Interrupt 25
#define   FIRQPR26                  ((unsigned int) 0x1 <<  26)  // 26     Interrupt 26
#define   FIRQPR27                  ((unsigned int) 0x1 <<  27)  // 27     Interrupt 27
#define   FIRQPR28                  ((unsigned int) 0x1 <<  28)  // 28     Interrupt 28
#define   FIRQPR29                  ((unsigned int) 0x1 <<  29)  // 29     Interrupt 29
#define   FIRQPR30                  ((unsigned int) 0x1 <<  30)  // 30     Interrupt 30
#define   FIRQPR31                  ((unsigned int) 0x1 <<  31)  // 31     Interrupt 31

//-------------------------------------------------
// Pending Interrupt Read Location Register bit definitions
//
//  INTREQ_BITS

#define   INTREQ0                   ((unsigned int) 0x1 <<  0)  // 0      Interrupt 0
#define   INTREQ1                   ((unsigned int) 0x1 <<  1)  // 1      Interrupt 1
#define   INTREQ2                   ((unsigned int) 0x1 <<  2)  // 2      Interrupt 2
#define   INTREQ3                   ((unsigned int) 0x1 <<  3)  // 3      Interrupt 3
#define   INTREQ4                   ((unsigned int) 0x1 <<  4)  // 4      Interrupt 4

#define   INTREQ5                   ((unsigned int) 0x1 <<  5)  // 5      Interrupt 5
#define   INTREQ6                   ((unsigned int) 0x1 <<  6)  // 6      Interrupt 6
#define   INTREQ7                   ((unsigned int) 0x1 <<  7)  // 7      Interrupt 7
#define   INTREQ8                   ((unsigned int) 0x1 <<  8)  // 8      Interrupt 8
#define   INTREQ9                   ((unsigned int) 0x1 <<  9)  // 9      Interrupt 9
#define   INTREQ10                  ((unsigned int) 0x1 <<  10)  // 10     Interrupt 10
#define   INTREQ11                  ((unsigned int) 0x1 <<  11)  // 11     Interrupt 11
#define   INTREQ12                  ((unsigned int) 0x1 <<  12)  // 12     Interrupt 12
#define   INTREQ13                  ((unsigned int) 0x1 <<  13)  // 13     Interrupt 13
#define   INTREQ14                  ((unsigned int) 0x1 <<  14)  // 14     Interrupt 14
#define   INTREQ15                  ((unsigned int) 0x1 <<  15)  // 15     Interrupt 15
#define   INTREQ16                  ((unsigned int) 0x1 <<  16)  // 16     Interrupt 16
#define   INTREQ17                  ((unsigned int) 0x1 <<  17)  // 17     Interrupt 17
#define   INTREQ18                  ((unsigned int) 0x1 <<  18)  // 18     Interrupt 18
#define   INTREQ19                  ((unsigned int) 0x1 <<  19)  // 19     Interrupt 19
#define   INTREQ20                  ((unsigned int) 0x1 <<  20)  // 20     Interrupt 20
#define   INTREQ21                  ((unsigned int) 0x1 <<  21)  // 21     Interrupt 21
#define   INTREQ22                  ((unsigned int) 0x1 <<  22)  // 22     Interrupt 22
#define   INTREQ23                  ((unsigned int) 0x1 <<  23)  // 23     Interrupt 23
#define   INTREQ24                  ((unsigned int) 0x1 <<  24)  // 24     Interrupt 24
#define   INTREQ25                  ((unsigned int) 0x1 <<  25)  // 25     Interrupt 25
#define   INTREQ26                  ((unsigned int) 0x1 <<  26)  // 26     Interrupt 26
#define   INTREQ27                  ((unsigned int) 0x1 <<  27)  // 27     Interrupt 27
#define   INTREQ28                  ((unsigned int) 0x1 <<  28)  // 28     Interrupt 28
#define   INTREQ29                  ((unsigned int) 0x1 <<  29)  // 29     Interrupt 29
#define   INTREQ30                  ((unsigned int) 0x1 <<  30)  // 30     Interrupt 30

#define   INTREQ31                  ((unsigned int) 0x1 <<  31)  // 31     Interrupt 31

//------------------------------------------------
// Interrupt Request Mask Register bit definitions
//  REQMASK_BITS
#define   REQMASK0                  ((unsigned int) 0x1 <<  0)  // 0      Interrupt 0
#define   REQMASK1                  ((unsigned int) 0x1 <<  1)  // 1      Interrupt 1
#define   REQMASK2                  ((unsigned int) 0x1 <<  2)  // 2      Interrupt 2
#define   REQMASK3                  ((unsigned int) 0x1 <<  3)  // 3      Interrupt 3
#define   REQMASK4                  ((unsigned int) 0x1 <<  4)  // 4      Interrupt 4
#define   REQMASK5                  ((unsigned int) 0x1 <<  5)  // 5      Interrupt 5
#define   REQMASK6                  ((unsigned int) 0x1 <<  6)  // 6      Interrupt 6
#define   REQMASK7                  ((unsigned int) 0x1 <<  7)  // 7      Interrupt 7
#define   REQMASK8                  ((unsigned int) 0x1 <<  8)  // 8      Interrupt 8
#define   REQMASK9                  ((unsigned int) 0x1 <<  9)  // 9      Interrupt 9
#define   REQMASK10                 ((unsigned int) 0x1 <<  10)  // 10     Interrupt 10
#define   REQMASK11                 ((unsigned int) 0x1 <<  11)  // 11     Interrupt 11
#define   REQMASK12                 ((unsigned int) 0x1 <<  12)  // 12     Interrupt 12
#define   REQMASK13                 ((unsigned int) 0x1 <<  13)  // 13     Interrupt 13
#define   REQMASK14                 ((unsigned int) 0x1 <<  14)  // 14     Interrupt 14
#define   REQMASK15                 ((unsigned int) 0x1 <<  15)  // 15     Interrupt 15
#define   REQMASK16                 ((unsigned int) 0x1 <<  16)  // 16     Interrupt 16
#define   REQMASK17                 ((unsigned int) 0x1 <<  17)  // 17     Interrupt 17
#define   REQMASK18                 ((unsigned int) 0x1 <<  18)  // 18     Interrupt 18
#define   REQMASK19                 ((unsigned int) 0x1 <<  19)  // 19     Interrupt 19
#define   REQMASK20                 ((unsigned int) 0x1 <<  20)  // 20     Interrupt 20
#define   REQMASK21                 ((unsigned int) 0x1 <<  21)  // 21     Interrupt 21
#define   REQMASK22                 ((unsigned int) 0x1 <<  22)  // 22     Interrupt 22
#define   REQMASK23                 ((unsigned int) 0x1 <<  23)  // 23     Interrupt 23
#define   REQMASK24                 ((unsigned int) 0x1 <<  24)  // 24     Interrupt 24
#define   REQMASK25                 ((unsigned int) 0x1 <<  25)  // 25     Interrupt 25
#define   REQMASK26                 ((unsigned int) 0x1 <<  26)  // 26     Interrupt 26
#define   REQMASK27                 ((unsigned int) 0x1 <<  27)  // 27     Interrupt 27
#define   REQMASK28                 ((unsigned int) 0x1 <<  28)  // 28     Interrupt 28
#define   REQMASK29                 ((unsigned int) 0x1 <<  29)  // 29     Interrupt 29
#define   REQMASK30                 ((unsigned int) 0x1 <<  30)  // 30     Interrupt 30
#define   REQMASK31                 ((unsigned int) 0x1 <<  31)  // 31     Interrupt 31

//-------------------------------------------------
// CPU Data Bus Parallel Signature Analysis Enable Register bit definitions
//
//  PSAENABLE_BITS
#define   PSADIS                             ((unsigned int) 0x1 <<  0)    // 0      PSA Disable

//-------------------------------------------------
// Clock Control Register bit definitions
//
//  CLKCNTL_BITS
#define   LPM_RUN            ((unsigned int) 0x0 <<  0)    // 1:0    Low-power mode bits
#define   LPM_IDLE           ((unsigned int) 0x1 <<  0)    // 1:0    Low-power mode bits
#define   LPM_STANDBY        ((unsigned int) 0x2 <<  0)    // 1:0    Low-power mode bits
#define   LPM_HA             ((unsigned int) 0x3 <<  0)    // 1:0    Low-power mode bits
#define   CLKDIN             ((unsigned int) 0x1 <<  2)    // 2      CLKOUT input pin data
#define   CLKDOUT            ((unsigned int) 0x1 <<  3)    // 3      CLKOUT output pin data
#define   CLKDIR             ((unsigned int) 0x1 <<  4)    // 4      CLKOUT pin direction
#define   CLKSR_IO           ((unsigned int) 0x0 <<  5)    // 6:5    CLKOUT source bits
#define   CLKSR_ICLK         ((unsigned int) 0x1 <<  5)    // 6:5    CLKOUT source bits
#define   CLKSR_MCLK         ((unsigned int) 0x2 <<  5)    // 6:5    CLKOUT source bits
#define   CLKSR_SYSCLK       ((unsigned int) 0x3 <<  5)    // 6:5    CLKOUT source bits
#define   PPWNOVR            ((unsigned int) 0x1 <<  7)    // 7      Peripheral power down enable

//-------------------------------------------------
// Global Control Register bit definitions
//
// GCR_BITS
#define   ZPLL_CLK_DIV_PRE1      ((unsigned int) 0x1 <<  0) // 0      ZPLL clock divider precale[AD4]
#define   ZPLL_CLK_DIV_PRE2      ((unsigned int) 0x1 <<  1) // 1      ZPLL clock divider precale
#define   ZPLL_CLK_DIV_PRE3      ((unsigned int) 0x1 <<  2) // 2      ZPLL clock divider precale
#define   ZPLL_CLK_DIV_PRE_1     ((unsigned int) 0x0 <<  0) // 2:0    ZPLL clock divider precale
#define   ZPLL_CLK_DIV_PRE_2     ((unsigned int) 0x1 <<  0) // 2:0    ZPLL clock divider precale
#define   ZPLL_CLK_DIV_PRE_3     ((unsigned int) 0x2 <<  0) // 2:0    ZPLL clock divider precale
#define   ZPLL_CLK_DIV_PRE_4     ((unsigned int) 0x3 <<  0) // 2:0    ZPLL clock divider precale
#define   ZPLL_CLK_DIV_PRE_5     ((unsigned int) 0x4 <<  0) // 2:0    ZPLL clock divider precale
#define   ZPLL_CLK_DIV_PRE_6     ((unsigned int) 0x5 <<  0) // 2:0    ZPLL clock divider precale
#define   ZPLL_CLK_DIV_PRE_7     ((unsigned int) 0x6 <<  0) // 2:0    ZPLL clock divider precale
#define   ZPLL_CLK_DIV_PRE_8     ((unsigned int) 0x7 <<  0) // 2:0    ZPLL clock divider precale
#define   ZPLL_MULT4             ((unsigned int) 0x1 <<  3) // 3      Multiply-by-4 or 8
#define   FLCONFIG               ((unsigned int) 0x1 <<  4) // 4      Flash configuration enable
#define   RTI_CTRL               ((unsigned int) 0x1 <<  14)// 14     RTI control
#define   RST_OSC_FAIL_EN        ((unsigned int) 0x1 <<  15)// 15     Reset on oscillator failure enable

//-------------------------------------------------
// System Exception Control Register bit definitions
//
// SYSECR_BITS
#define   ILLOVR              ((unsigned int) 0x1 <<  0)    // 0      Illegal address reset override (test mode only)
#define   ACCOVR              ((unsigned int) 0x1 <<  1)    // 1      Memory access violation reset override (test mode only)
#define   PACCOVR             ((unsigned int) 0x1 <<  2)    // 2      Peripheral access violation override (test mode only)
#define   RESET0             ((unsigned int) 0x1 <<  14)   // 15:14  Software reset bits
#define   RESET1             ((unsigned int) 0x1 <<  15)   // 15:14  Software reset bits

//-------------------------------------------------
// System Reset Exception Status Register bit definitions
//
// SYSESR_BITS
#define   SWRST               ((unsigned int) 0x1 <<  7)    // 7      Software reset flag
#define   ILLMAP              ((unsigned int) 0x1 <<  8)    // 8      Illegal address map flag
#define   PILLACC             ((unsigned int) 0x1 <<  9)    // 9      Peripheral access violation flag
#define   ILLACC              ((unsigned int) 0x1 <<  10)   // 10     Illegal memory access flag
#define   ILLADR              ((unsigned int) 0x1 <<  11)   // 11     Illegal address flag
#define   ILLMODE             ((unsigned int) 0x1 <<  12)   // 12     Illegal mode flag
#define   WDRST               ((unsigned int) 0x1 <<  13)   // 13     Watchdog reset flag
#define   CLKRST              ((unsigned int) 0x1 <<  14)   // 14     Clock fail flag
#define   PORRST              ((unsigned int) 0x1 <<  15)   // 15     Power-up reset flag

//-------------------------------------------------
// Abort Exception Status Register bit definitions
//
// ABRTESR_BITS
#define   PACCVIO             ((unsigned int) 0x1 <<  13)   // 13     Peripheral access violation error
#define   MEMABT              ((unsigned int) 0x1 <<  14)   // 14     Memory access abort
#define   ADRABT              ((unsigned int) 0x1 <<  15)   // 15     Illegal address abort

//-------------------------------------------------
// Global Status Register bit definitions
//
// GLBSTAT_BITS
#define  PLLSLIP              ((unsigned int) 0x1 <<  0)    // 0      PLL slip flag
#define  OSCFAIL              ((unsigned int) 0x1 <<  1)    // 1      Oscillator fail flag
#define  MPUACC               ((unsigned int) 0x1 <<  4)    // 4      MPU illegal access flag
#define  MPUADDR              ((unsigned int) 0x1 <<  5)    // 5      MPU illegal address flag
#define  SYSACC               ((unsigned int) 0x1 <<  6)    // 6      System illegal access flag
#define  SYSADDR              ((unsigned int) 0x1 <<  7)    // 7      System illegal address flag

//===========================================================================
// Memory Protection Unit (MPU) Register Bit Definitions
//-------------------------------------------------
// MPU Control Register bit definitions
//
//  MPUCTRL_BITS
#define   CHAN0_SPECIAL       ((unsigned int) 0x1 <<  0)      // 0      Channel 0 special bit
#define   CHAN0_EN            ((unsigned int) 0x1 <<  1)      // 1      Channel 0 enable bit
#define   CHAN0_PRIV          ((unsigned int) 0x1 <<  2)      // 2      Channel 0 privilege bit
#define   CHAN0_RONLY         ((unsigned int) 0x1 <<  3)      // 3      Channel 0 read-only bit
#define   CHAN1_SPECIAL       ((unsigned int) 0x1 <<  4)      // 4      Channel 1 special bit
#define   CHAN1_EN            ((unsigned int) 0x1 <<  5)      // 5      Channel 1 enable bit
#define   CHAN1_PRIV          ((unsigned int) 0x1 <<  6)      // 6      Channel 1 privilege bit
#define   CHAN1_RONLY         ((unsigned int) 0x1 <<  7)      // 7      Channel 1 read-only bit
#define   CHAN2_SPECIAL       ((unsigned int) 0x1 <<  8)      // 8      Channel 2 special bit
#define   CHAN2_EN            ((unsigned int) 0x1 <<  9)      // 9      Channel 2 enable bit
#define   CHAN2_PRIV          ((unsigned int) 0x1 <<  10)     // 10     Channel 2 privilege bit
#define   CHAN2_RONLY         ((unsigned int) 0x1 <<  11)     // 11     Channel 2 read-only bit
#define   CHAN3_SPECIAL       ((unsigned int) 0x1 <<  12)     // 12     Channel 3 special bit
#define   CHAN3_EN            ((unsigned int) 0x1 <<  13)     // 13     Channel 3 enable bit
#define   CHAN3_PRIV          ((unsigned int) 0x1 <<  14)     // 14     Channel 3 privilege bit
#define   CHAN3_RONLY         ((unsigned int) 0x1 <<  15)     // 15     Channel 3 read-only bit



//*********************************************************************************************
//       SPI Module
// SPICTRL1_BITS   description
#define   CHARLEN0                 ((unsigned int) 0x1 <<  0)    // Character length
#define   CHARLEN1                 ((unsigned int) 0x1 <<  1)    // Character length
#define   CHARLEN2                 ((unsigned int) 0x1 <<  2)    // Character length
#define   CHARLEN3                 ((unsigned int) 0x1 <<  3)    // Character length
#define   CHARLEN4                 ((unsigned int) 0x1 <<  4)    // Character length
#define   CHARLEN_1                ((unsigned int) 0x1 <<  0)    // Character length 1
#define   CHARLEN_2                ((unsigned int) 0x2 <<  0)    // Character length 2
#define   CHARLEN_3                ((unsigned int) 0x3 <<  0)    // Character length 3
#define   CHARLEN_4                ((unsigned int) 0x4 <<  0)    // Character length 4
#define   CHARLEN_5                ((unsigned int) 0x5 <<  0)    // Character length 5
#define   CHARLEN_6                ((unsigned int) 0x6 <<  0)    // Character length 6
#define   CHARLEN_7                ((unsigned int) 0x7 <<  0)    // Character length 7
#define   CHARLEN_8                ((unsigned int) 0x8 <<  0)    // Character length 8
#define   CHARLEN_9                ((unsigned int) 0x9 <<  0)    // Character length 9
#define   CHARLEN_10               ((unsigned int) 0x0a <<  0)   // Character length 10
#define   CHARLEN_11               ((unsigned int) 0x0b <<  0)   // Character length 11
#define   CHARLEN_12               ((unsigned int) 0x0c <<  0)   // Character length 12
#define   CHARLEN_13               ((unsigned int) 0x0d <<  0)   // Character length 13
#define   CHARLEN_14               ((unsigned int) 0x0e <<  0)   // Character length 14
#define   CHARLEN_15               ((unsigned int) 0x0f <<  0)   // Character length 15
#define   CHARLEN_16               ((unsigned int) 0x10 <<  0)   // Character length 16
#define   PRESCALE0                ((unsigned int) 0x1 <<  5)    // Prescale Divide Value
#define   PRESCALE1                ((unsigned int) 0x1 <<  6)    // Prescale Divide Value
#define   PRESCALE2                ((unsigned int) 0x1 <<  7)    // Prescale Divide Value
#define   PRESCALE3                ((unsigned int) 0x1 <<  8)    // Prescale Divide Value
#define   PRESCALE4                ((unsigned int) 0x1 << 9)     // Prescale Divide Value
#define   PRESCALE5                ((unsigned int) 0x1 << 10)    // Prescale Divide Value
#define   PRESCALE6                ((unsigned int) 0x1 << 11)    // Prescale Divide Value
#define   PRESCALE7                ((unsigned int) 0x1 << 12)    // Prescale Divide Value
#define   PRESCALE_1               ((unsigned int) 0x1 <<  5)    // Prescale Divide Value
#define   PRESCALE_2               ((unsigned int) 0x1 <<  6)    // Prescale Divide Value
#define   PRESCALE_4               ((unsigned int) 0x1 <<  7)    // Prescale Divide Value
#define   PRESCALE_8               ((unsigned int) 0x1 <<  8)    // Prescale Divide Value
#define   PRESCALE_16              ((unsigned int) 0x1 << 9)     // Prescale Divide Value
#define   PRESCALE_32              ((unsigned int) 0x1 << 10)    // Prescale Divide Value
#define   PRESCALE_64              ((unsigned int) 0x1 << 11)    // Prescale Divide Value
#define   PRESCALE_128             ((unsigned int) 0x1 << 12)    // Prescale Divide Value
#define   PRESCALE_255             ((unsigned int) 0xff << 5)    // Prescale Divide Value


//-------------------------------------------------
// SPI Control Register 2 bit definitions
//
//  SPICTRL2_BITS
#define   PHASE                    ((unsigned int) 0x1 <<  0)    // 0      Phase selection
#define   POLARITY                 ((unsigned int) 0x1 <<  1)    // 1      Polarity selection
#define   SPI_POWERDOWN       ((unsigned int) 0x1 <<  2)    // 2      Powerdown
#define   MASTER                   ((unsigned int) 0x1 <<  3)    // 3      Master pin selection
#define   SPIEN                    ((unsigned int) 0x1 <<  4)    // 4      SPI enable
#define   CLKMOD                   ((unsigned int) 0x1 <<  5)    // 5      Clock mode

//-------------------------------------------------
// SPI Control Register 3 bit definitions
//
// SPICTRL3_BITS
#define   RX_INT_FLAG               ((unsigned int) 0x1 <<  0)    // 0      Receive interrupt flag
#define   RX_INT_EN                 ((unsigned int) 0x1 <<  1)    // 1      Receive interrupt enable
#define   RCVR_OVRN                 ((unsigned int) 0x1 <<  2)    // 2      Receiver overrun flag
#define   OVRN_INT_EN               ((unsigned int) 0x1 <<  3)    // 3      Overrun interrupt enable
#define   DMA_REQ_EN                ((unsigned int) 0x1 <<  4)    // 4      DMA request enable
#define   ENABLE_HIGHZ              ((unsigned int) 0x1 <<  5)    // 5      SPIENA pin high-Z enable

//-------------------------------------------------
// SPI Buffer Register bit definitions
//
// SPIBUF_BITS
#define   RX_INT_FLAG_IMG           ((unsigned int) 0x1 <<  16)    // 16     RX interrupt flag image
#define   RCVR_OVRN_IMG             ((unsigned int) 0x1 <<  17)    // 17     RX overrun flag image

//-------------------------------------------------
// SPI Pin Control Register 1 bit definitions
//
// SPIPC1_BITS
#define   ENA_DIR                   ((unsigned int) 0x1 <<  0)    // 0      SPIENA pin direction
#define   CLK_DIR                   ((unsigned int) 0x1 <<  1)    // 1      SPICLK pin direction
#define   SIMO_DIR                  ((unsigned int) 0x1 <<  2)    // 2      SPISIMO pin direction
#define   SOMI_DIR                  ((unsigned int) 0x1 <<  3)    // 3      SPISOMI pin direction
#define   SCS_DIR                   ((unsigned int) 0x1 <<  4)    // 4      SPISCS pin direction

//-------------------------------------------------
// SPI Pin Control Register 2 bit definitions
//
// SPIPC2_BITS
#define   ENA_DIN                   ((unsigned int) 0x1 <<  0)    // 0      SPIENA data in
#define   CLK_DIN                   ((unsigned int) 0x1 <<  1)    // 1      SPICLK data in
#define   SIMO_DIN                  ((unsigned int) 0x1 <<  2)    // 2      SPISIMO data in
#define   SOMI_DIN                  ((unsigned int) 0x1 <<  3)    // 3      SPISOMI data in
#define   SCS_DIN                   ((unsigned int) 0x1 <<  4)    // 4      SPISCS data in

//-------------------------------------------------
// SPI Pin Control Register 3 bit definitions
//
// SPIPC3_BITS
#define   ENA_DOUT                  ((unsigned int) 0x1 <<  0)    // 0      SPIENA data out
#define   CLK_DOUT                  ((unsigned int) 0x1 <<  1)    // 1      SPICLK data out
#define   SIMO_DOUT                 ((unsigned int) 0x1 <<  2)    // 2      SPISIMO data out
#define   SOMI_DOUT                 ((unsigned int) 0x1 <<  3)    // 3      SPISOMI data out
#define   SCS_DOUT                  ((unsigned int) 0x1 <<  4)    // 4      SPISCS data out

//-------------------------------------------------
// SPI Pin Control Register 4 bit definitions
//
// SPIPC4_BITS
#define   ENA_DSET                  ((unsigned int) 0x1 <<  0)    // 0      SPIENA data set
#define   CLK_DSET                  ((unsigned int) 0x1 <<  1)    // 1      SPICLK data set
#define   SIMO_DSET                 ((unsigned int) 0x1 <<  2)    // 2      SPISIMO data set
#define   SOMI_DSET                 ((unsigned int) 0x1 <<  3)    // 3      SPISOMI data set
#define   SCS_DSET                  ((unsigned int) 0x1 <<  4)    // 4      SPISCS data set

//-------------------------------------------------
// SPI Pin Control Register 5 bit definitions
//
// SPIPC5_BITS
#define   ENA_DCLR                  ((unsigned int) 0x1 <<  0)    // 0      SPIENA data clear
#define   CLK_DCLR                  ((unsigned int) 0x1 <<  1)    // 1      SPICLK data clear
#define   SIMO_DCLR                 ((unsigned int) 0x1 <<  2)    // 2      SPISIMO data clear
#define   SOMI_DCLR                 ((unsigned int) 0x1 <<  3)    // 3      SPISOMI data clear
#define   SCS_DCLR                  ((unsigned int) 0x1 <<  4)    // 4      SPISCS data clear

//-------------------------------------------------
// SPI Pin Control Register 6 bit definitions
//
// SPIPC6_BITS
#define   ENA_FUN                  ((unsigned int) 0x1 <<  0)    // 0      SPIENA pin function
#define   CLK_FUN                  ((unsigned int) 0x1 <<  1)    // 1      SPICLK pin function
#define   SIMO_FUN                 ((unsigned int) 0x1 <<  2)    // 2      SPISIMO pin function
#define   SOMI_FUN                 ((unsigned int) 0x1 <<  3)    // 3      SPISOMI pin function
#define   SCS_FUN                  ((unsigned int) 0x1 <<  4)    // 4      SPISCS pin function

//*******************************************************************************************
// MibADC
//

//-------------------------------------------------
// AD Control Register 1 bit definitions
//
// ADCR1_BITS
#define   PS0                  ((unsigned int) 0x1 <<  0)    // 0    Prescaler ICLK bit 0
#define   PS1                  ((unsigned int) 0x1 <<  1)    // 1    Prescaler ICLK bit 1
#define   PS2                  ((unsigned int) 0x1 <<  2)    // 2    Prescaler ICLK bit 2
#define   PS_1                 ((unsigned int) 0x0 <<  0)    // 2:0    Prescaler 1 ICLK cycle
#define   PS_2                 ((unsigned int) 0x1 <<  0)    // 2:0    Prescaler 2 ICLK cycles
#define   PS_3                 ((unsigned int) 0x2 <<  0)    // 2:0    Prescaler 3 ICLK cycles
#define   PS_4                 ((unsigned int) 0x3 <<  0)    // 2:0    Prescaler 4 ICLK cycles
#define   PS_5                 ((unsigned int) 0x4 <<  0)    // 2:0    Prescaler 5 ICLK cycles
#define   PS_6                 ((unsigned int) 0x5 <<  0)    // 2:0    Prescaler 6 ICLK cycles
#define   PS_7                 ((unsigned int) 0x6 <<  0)    // 2:0    Prescaler 7 ICLK cycles
#define   PS_8                 ((unsigned int) 0x7 <<  0)    // 2:0    Prescaler 8 ICLK cycles
#define   ACQ0                 ((unsigned int) 0x1 <<  3)    // 3    Acquisition Prescaler  bit 0
#define   ACQ1                 ((unsigned int) 0x1 <<  4)    // 4    Acquisition Prescaler  bit 1
#define   ACQ_2                ((unsigned int) 0x0 <<  3)    // 4:3    Acquisition prescale 2
#define   ACQ_8                ((unsigned int) 0x1 <<  3)    // 4:3    Acquisition prescale 8
#define   ACQ_32               ((unsigned int) 0x2 <<  3)    // 4:3    Acquisition prescale 32
#define   ACQ_128              ((unsigned int) 0x3 <<  3)    // 4:3    Acquisition prescale 128
#define   ADC_EN               ((unsigned int) 0x1 <<  5)    // 5      ADC Enable
#define   PWR_DN               ((unsigned int) 0x1 <<  8)    // 8      ADC power-down
#define   SELF_TST             ((unsigned int) 0x1 <<  9)    // 9      Self-test mode
#define   HILO                 ((unsigned int) 0x1 <<  10)   // 10     Test and reference source selection
#define   BRIDGE_EN            ((unsigned int) 0x1 <<  11)   // 11     Bridge enable
#define   CAL_ST               ((unsigned int) 0x1 <<  12)   // 12     Calibration conversion start
#define   CAL_EN               ((unsigned int) 0x1 <<  13)   // 13     Calibration enable
#define   COS                  ((unsigned int) 0x1 <<  15)   // 15     Continue on suspend enable

//-------------------------------------------------
// AD Control Register 2 bit definitions
//
// ADCR2_BITS
#define   ENA_GP2_INT          ((unsigned int) 0x1 <<  0)    // 0      Enable group 2 interrupt
#define   FRZ_GP2              ((unsigned int) 0x1 <<  1)    // 1      Freeze conversion group 2
#define   G2_MODE             ((unsigned int) 0x1 <<  2)    // 2      Enable continuous conversion of group 2
#define   ENA_GP1_INT          ((unsigned int) 0x1 <<  3)    // 3      Enable group 1 interrupt
#define   FRZ_GP1              ((unsigned int) 0x1 <<  4)    // 4      Freeze conversion group 1
#define   G1_MODE             ((unsigned int) 0x1 <<  5)    // 5      Enable continuous conversion of group 1
#define   EV_EDG_SEL           ((unsigned int) 0x1 <<  8)    // 8      ADC event trigger on low-to-high transition
#define   ENA_EV_INT           ((unsigned int) 0x1 <<  9)    // 9      Enable event group interrupt
#define   FRZ_EV               ((unsigned int) 0x1 <<  10)   // 10     Freeze conversion event group
#define   EV_MODE              ((unsigned int) 0x1 <<  11)   // 11     Enable continuous conversion of event group

//-------------------------------------------------
// AD Status Register bit definitions
//
// ADSR_BITS
#define   EV_END                ((unsigned int) 0x1 <<  0)    // 0      Event conversion-ended flag
#define   G2_END               ((unsigned int) 0x1 <<  1)    // 1      Group 2 conversion-ended flag
#define   GP1_END               ((unsigned int) 0x1 <<  2)    // 2      Group 1 conversion-ended flag
#define   EV_STOP               ((unsigned int) 0x1 <<  8)    // 8      Event group conversion-stopped flag
#define   G2_STOP              ((unsigned int) 0x1 <<  9)    // 9      Group 2 conversion-stopped flag
#define   G1_STOP              ((unsigned int) 0x1 <<  10)   // 10     Group 1 conversion-stopped flag
#define   EV_BUSY               ((unsigned int) 0x1 <<  11)   // 11     Event group conversion-busy flag
#define   G2_BUSY              ((unsigned int) 0x1 <<  12)   // 12     Group 2 conversion-busy flag
#define   G1_BUSY              ((unsigned int) 0x1 <<  13)   // 13     Group 1 conversion-busy flag

//-------------------------------------------------
// AD Event Group Input Channel Select Register bit definitions
//
// ADEISR, ADISR1
#define   CH0                ((unsigned int) 0x1 <<  0)    // 0      Event group enable - Channel 0
#define   CH1                ((unsigned int) 0x1 <<  1)    // 1      Event group enable - Channel 1
#define   CH2                ((unsigned int) 0x1 <<  2)    // 2      Event group enable - Channel 2
#define   CH3                ((unsigned int) 0x1 <<  3)    // 3      Event group enable - Channel 3
#define   CH4                ((unsigned int) 0x1 <<  4)    // 4      Event group enable - Channel 4
#define   CH5                ((unsigned int) 0x1 <<  5)    // 5      Event group enable - Channel 5
#define   CH6                ((unsigned int) 0x1 <<  6)    // 6      Event group enable - Channel 6
#define   CH7                ((unsigned int) 0x1 <<  7)    // 7      Event group enable - Channel 7
#define   CH8                ((unsigned int) 0x1 <<  8)    // 8      Event group enable - Channel 8
#define   CH9                ((unsigned int) 0x1 <<  9)    // 9      Event group enable - Channel 9
#define   CH10               ((unsigned int) 0x1 <<  10)   // 10     Event group enable - Channel 10
#define   CH11               ((unsigned int) 0x1 <<  11)   // 11     Event group enable - Channel 11
#define   CH12               ((unsigned int) 0x1 <<  12)   // 12     Event group enable - Channel 12
#define   CH13               ((unsigned int) 0x1 <<  13)   // 13     Event group enable - Channel 13
#define   CH14               ((unsigned int) 0x1 <<  14)   // 14     Event group enable - Channel 14
#define   CH15               ((unsigned int) 0x1 <<  15)   // 15     Event group enable - Channel 15


//-------------------------------------------------
// Calibration and Offset Error Correction Register bit definitions
//
// ADCALR_BITS
#define   CALR_1              ((unsigned int) 0x1 <<  0)    // 0      Calibration bits
#define   CALR_2              ((unsigned int) 0x1 <<  1)    // 1      Calibration bits
#define   CALR_4              ((unsigned int) 0x1 <<  2)    // 2      Calibration bits
#define   CALR_8              ((unsigned int) 0x1 <<  3)    // 3      Calibration bits
#define   CALR_16             ((unsigned int) 0x1 <<  4)    // 4      Calibration bits
#define   CALR_32             ((unsigned int) 0x1 <<  5)    // 5      Calibration bits
#define   CALR_64             ((unsigned int) 0x1 <<  6)    // 6      Calibration bits
#define   CALR_128            ((unsigned int) 0x1 <<  7)    // 7      Calibration bits
#define   CALR_256            ((unsigned int) 0x1 <<  8)    // 8      Calibration bits
#define   CALR_512            ((unsigned int) 0x1 <<  9)    // 9      Calibration bits

//-------------------------------------------------
// AD Data Input Register register bit definitions
//
// ADINR_BITS
#define   IN0                 ((unsigned int) 0x1 <<  0)    // 0      Digital input pin 0
#define   IN1                 ((unsigned int) 0x1 <<  1)    // 1      Digital input pin 1
#define   IN2                 ((unsigned int) 0x1 <<  2)    // 2      Digital input pin 2
#define   IN3                 ((unsigned int) 0x1 <<  3)    // 3      Digital input pin 3
#define   IN4                 ((unsigned int) 0x1 <<  4)    // 4      Digital input pin 4
#define   IN5                 ((unsigned int) 0x1 <<  5)    // 5      Digital input pin 5
#define   IN6                 ((unsigned int) 0x1 <<  6)    // 6      Digital input pin 6
#define   IN7                 ((unsigned int) 0x1 <<  7)    // 7      Digital input pin 7
#define   IN8                 ((unsigned int) 0x1 <<  8)    // 8      Digital input pin 8
#define   IN9                 ((unsigned int) 0x1 <<  9)    // 9      Digital input pin 9
#define   IN10                ((unsigned int) 0x1 <<  10)   // 10     Digital input pin 10
#define   IN11                ((unsigned int) 0x1 <<  11)   // 11     Digital input pin 11
#define   IN12                ((unsigned int) 0x1 <<  12)   // 12     Digital input pin 12
#define   IN13                ((unsigned int) 0x1 <<  13)   // 13     Digital input pin 13
#define   IN_4                ((unsigned int) 0x1 <<  14)   // 14     Digital input pin 14
#define   IN15                ((unsigned int) 0x1 <<  15)   // 15     Digital input pin 15

//-------------------------------------------------
// AD Pin Control Register bit definitions
//
// ADPCR_BITS
#define   EVT_DIR              ((unsigned int) 0x1 <<  0)    // 0      ADEVT pin direction selection
#define   EVT_OUT              ((unsigned int) 0x1 <<  2)    // 2      ADEVT pin data output
#define   EVT_IN               ((unsigned int) 0x1 <<  3)    // 3      ADEVT pin input value

//-------------------------------------------------
// AD Sample Time Event Register bit definitions
//
// ADSAMPEV_BITS
#define   EVACQ_1           ((unsigned int) 0x1 <<  0)    // 0      Event group acquisition prescale bits
#define   EVACQ_2           ((unsigned int) 0x1 <<  1)    // 1      Event group acquisition prescale bits
#define   EVACQ_4           ((unsigned int) 0x1 <<  2)    // 2      Event group acquisition prescale bits
#define   EVACQ_8           ((unsigned int) 0x1 <<  3)    // 3      Event group acquisition prescale bits
#define   EVACQ_16          ((unsigned int) 0x1 <<  4)    // 4      Event group acquisition prescale bits
#define   EVACQ_32          ((unsigned int) 0x1 <<  5)    // 5      Event group acquisition prescale bits
#define   EVACQ_64          ((unsigned int) 0x1 <<  6)    // 6      Event group acquisition prescale bits
#define   EVACQ_128         ((unsigned int) 0x1 <<  7)    // 7      Event group acquisition prescale bits
#define   SEN               ((unsigned int) 0x1 <<  15)   // 15     Sample register enable

//-------------------------------------------------
// AD Sample Time Group 1 Register bit definitions
//
// ADSAMP1_BITS
#define   G1ACQ_1            ((unsigned int) 0x1 <<  0)    // 0      Group 1 acquisition prescale bits
#define   G1ACQ_2            ((unsigned int) 0x1 <<  1)    // 1      Group 1 acquisition prescale bits
#define   G1ACQ_4            ((unsigned int) 0x1 <<  2)    // 2      Group 1 acquisition prescale bits
#define   G1ACQ_8            ((unsigned int) 0x1 <<  3)    // 3      Group 1 acquisition prescale bits
#define   G1ACQ_16           ((unsigned int) 0x1 <<  4)    // 4      Group 1 acquisition prescale bits
#define   G1ACQ_32           ((unsigned int) 0x1 <<  5)    // 5      Group 1 acquisition prescale bits
#define   G1ACQ_64           ((unsigned int) 0x1 <<  6)    // 6      Group 1 acquisition prescale bits
#define   G1ACQ_128          ((unsigned int) 0x1 <<  7)    // 7      Group 1 acquisition prescale bits

//-------------------------------------------------
// AD Sample Time Group 2 Register bit definitions
//
// ADSAMP2_BITS
#define   G2ACQ_1            ((unsigned int) 0x1 <<  0)    // 0      Group 2 acquisition prescale bits
#define   G2ACQ_2            ((unsigned int) 0x1 <<  1)    // 1      Group 2 acquisition prescale bits
#define   G2ACQ_4            ((unsigned int) 0x1 <<  2)    // 2      Group 2 acquisition prescale bits
#define   G2ACQ_8            ((unsigned int) 0x1 <<  3)    // 3      Group 2 acquisition prescale bits
#define   G2ACQ_16           ((unsigned int) 0x1 <<  4)    // 4      Group 2 acquisition prescale bits
#define   G2ACQ_32           ((unsigned int) 0x1 <<  5)    // 5      Group 2 acquisition prescale bits
#define   G2ACQ_64           ((unsigned int) 0x1 <<  6)    // 6      Group 2 acquisition prescale bits
#define   G2ACQ_128          ((unsigned int) 0x1 <<  7)    // 7      Group 2 acquisition prescale bits

//-------------------------------------------------
// AD Buffer control Register 1 bit definitions
//
// ADBCR1_BITS
#define   BNDB_1              ((unsigned int) 0x1 <<  0)    // 0      Buffer boundary B
#define   BNDB_2              ((unsigned int) 0x1 <<  1)    // 1      Buffer boundary B
#define   BNDB_4              ((unsigned int) 0x1 <<  2)    // 2      Buffer boundary B
#define   BNDB_8              ((unsigned int) 0x1 <<  3)    // 3      Buffer boundary B
#define   BNDB_16             ((unsigned int) 0x1 <<  4)    // 4      Buffer boundary B
#define   BNDB_32             ((unsigned int) 0x1 <<  5)    // 5      Buffer boundary B
#define   BNDB_64             ((unsigned int) 0x1 <<  6)    // 6      Buffer boundary B
#define   BNDB_128            ((unsigned int) 0x1 <<  7)    // 7      Buffer boundary B
#define   BNDA_1              ((unsigned int) 0x1 <<  8)    // 8      Buffer boundary A
#define   BNDA_2              ((unsigned int) 0x1 <<  9)    // 9      Buffer boundary A
#define   BNDA_4              ((unsigned int) 0x1 <<  10)   // 10     Buffer boundary A
#define   BNDA_8              ((unsigned int) 0x1 <<  11)   // 11     Buffer boundary A
#define   BNDA_16             ((unsigned int) 0x1 <<  12)   // 12     Buffer boundary A
#define   BNDA_32             ((unsigned int) 0x1 <<  13)   // 13     Buffer boundary A
#define   BNDA_64             ((unsigned int) 0x1 <<  14)   // 14     Buffer boundary A
#define   BUF_EN              ((unsigned int) 0x1 <<  15)   // 15     Buffer mode enable

//-------------------------------------------------
// AD Buffer control Register 2 bit definitions
//
// ADBCR2_BITS
#define   BNDEND_16           ((unsigned int) 0x0 <<  0)    // 2:0    Buffer end boundary - 16 words
#define   BNDEND_32           ((unsigned int) 0x1 <<  0)    // 2:0    Buffer end boundary - 32 words
#define   BNDEND_64           ((unsigned int) 0x2 <<  0)    // 2:0    Buffer end boundary - 64 words
#define   BNDEND_128          ((unsigned int) 0x3 <<  0)    // 2:0    Buffer end boundary - 128 words
#define   BNDEND_192          ((unsigned int) 0x4 <<  0)    // 2:0    Buffer end boundary - 192 words
#define   BNDEND_256          ((unsigned int) 0x5 <<  0)    // 2:0    Buffer end boundary - 256 words
#define   BNDEND_384          ((unsigned int) 0x6 <<  0)    // 2:0    Buffer end boundary - 384 words
#define   BNDEND_512          ((unsigned int) 0x7 <<  0)    // 2:0    Buffer end boundary - 512 words

//-------------------------------------------------
// AD Buffer control Register 3 bit definitions
//
// ADBCR3_BITS
#define   CH_ID               ((unsigned int) 0x1 <<  0)    // 0      Channel ID FIFO mode
#define   G2_8BIT             ((unsigned int) 0x1 <<  1)    // 1      Group 2 FIFO buffer 8-bit result mode
#define   G1_8BIT             ((unsigned int) 0x1 <<  2)    // 2      Group 1 FIFO buffer 8-bit result mode
#define   EV_8BIT             ((unsigned int) 0x1 <<  3)    // 3      Event group FIFO buffer 8-bit result mode
#define   G2_BUF_INT_EN       ((unsigned int) 0x1 <<  7)    // 7      Group 2 FIFO buffer interrupt enable
#define   G1_BUF_INT_EN       ((unsigned int) 0x1 <<  8)    // 8      Group 2 FIFO buffer interrupt enable
#define   EV_BUF_INT_EN       ((unsigned int) 0x1 <<  9)    // 9      Event group FIFO buffer interrupt enable
#define   G2_OVR_INT_EN       ((unsigned int) 0x1 <<  10)   // 10     Group 2 FIFO overrrun interrupt enable
#define   G1_OVR_INT_EN       ((unsigned int) 0x1 <<  11)   // 11     Group 1 FIFO overrrun interrupt enable
#define   EV_OVR_INT_EN       ((unsigned int) 0x1 <<  12)   // 12     Event group FIFO overrrun interrupt enable
#define   G2_DMA_EN           ((unsigned int) 0x1 <<  13)   // 13     Group 2 DMA enable
#define   G1_DMA_EN           ((unsigned int) 0x1 <<  14)   // 14     Group 1 DMA enable
#define   EV_DMA_EN           ((unsigned int) 0x1 <<  15)   // 15     Event group DMA enable

//-------------------------------------------------
// AD Buffer Status Register bit definitions
//
// ADBUFST_BITS
#define   G2_EMPTY           ((unsigned int) 0x1 <<  0)    // 0      Group 2 FIFO empty
#define   G1_EMPTY           ((unsigned int) 0x1 <<  1)    // 1      Group 1 FIFO empty
#define   EV_EMPTY           ((unsigned int) 0x1 <<  2)    // 2      Event group FIFO empty
#define   G2_OVR             ((unsigned int) 0x1 <<  4)    // 4      Group 2 FIFO overrun
#define   G1_OVR             ((unsigned int) 0x1 <<  5)    // 5      Group 1 FIFO overrun
#define   EV_OVR             ((unsigned int) 0x1 <<  6)    // 6      Event group FIFO overrun
#define   G2_INT_FLAG        ((unsigned int) 0x1 <<  8)    // 8      Group 2 FIFO interrupt flag
#define   G1_INT_FLAG        ((unsigned int) 0x1 <<  9)    // 9      Group 1 FIFO interrupt flag
#define   EV_INT_FLAG        ((unsigned int) 0x1 <<  10)   // 10     Event group FIFO interrupt flag


//-------------------------------------------------
// AD Event Group Threshold Counter Register bit definitions
//
// ADTHREV_BITS
#define   EVTHR_1            ((unsigned int) 0x1 <<  0)    // 0      Event group interrupt threshold counter
#define   EVTHR_2            ((unsigned int) 0x1 <<  1)    // 1      Event group interrupt threshold counter
#define   EVTHR_4            ((unsigned int) 0x1 <<  2)    // 2      Event group interrupt threshold counter
#define   EVTHR_8            ((unsigned int) 0x1 <<  3)    // 3      Event group interrupt threshold counter
#define   EVTHR_16           ((unsigned int) 0x1 <<  4)    // 4      Event group interrupt threshold counter
#define   EVTHR_32           ((unsigned int) 0x1 <<  5)    // 5      Event group interrupt threshold counter
#define   EVTHR_64           ((unsigned int) 0x1 <<  6)    // 6      Event group interrupt threshold counter
#define   EVTHR_128          ((unsigned int) 0x1 <<  7)    // 7      Event group interrupt threshold counter
#define   EVTHR_256          ((unsigned int) 0x1 <<  8)    // 8      Event group interrupt threshold counter
#define   EVTHR_512          ((unsigned int) 0x1 <<  9)    // 9      Event group interrupt threshold counter
#define   SIGN_EXTENSION_1   ((unsigned int) 0x1 <<  10)   // 10     Sign extension
#define   SIGN_EXTENSION_2   ((unsigned int) 0x1 <<  11)   // 11     Sign extension
#define   SIGN_EXTENSION_4   ((unsigned int) 0x1 <<  12)   // 12     Sign extension
#define   SIGN_EXTENSION_8   ((unsigned int) 0x1 <<  13)   // 13     Sign extension
#define   SIGN_EXTENSION_16  ((unsigned int) 0x1 <<  14)   // 14     Sign extension
#define   SIGN_EXTENSION_32  ((unsigned int) 0x1 <<  15)   // 15     Sign extension

//-------------------------------------------------
// AD Group 1 Threshold Counter Register bit definitions
//
// ADTHRG1_BITS
#define   G1THR_1            ((unsigned int) 0x1 <<  0)    // 0      Group 1 interrupt threshold counter
#define   G1THR_2            ((unsigned int) 0x1 <<  1)    // 1      Group 1 interrupt threshold counter
#define   G1THR_4            ((unsigned int) 0x1 <<  2)    // 2      Group 1 interrupt threshold counter
#define   G1THR_8            ((unsigned int) 0x1 <<  3)    // 3      Group 1 interrupt threshold counter
#define   G1THR_16           ((unsigned int) 0x1 <<  4)    // 4      Group 1 interrupt threshold counter
#define   G1THR_32           ((unsigned int) 0x1 <<  5)    // 5      Group 1 interrupt threshold counter
#define   G1THR_64           ((unsigned int) 0x1 <<  6)    // 6      Group 1 interrupt threshold counter
#define   G1THR_128          ((unsigned int) 0x1 <<  7)    // 7      Group 1 interrupt threshold counter
#define   G1THR_256          ((unsigned int) 0x1 <<  8)    // 8      Group 1 interrupt threshold counter
#define   G1THR_512          ((unsigned int) 0x1 <<  9)    // 9      Group 1 interrupt threshold counter
#define   SIGN_EXTENSION_1   ((unsigned int) 0x1 <<  10)   // 10     Sign extension
#define   SIGN_EXTENSION_2   ((unsigned int) 0x1 <<  11)   // 11     Sign extension
#define   SIGN_EXTENSION_4   ((unsigned int) 0x1 <<  12)   // 12     Sign extension
#define   SIGN_EXTENSION_8   ((unsigned int) 0x1 <<  13)   // 13     Sign extension
#define   SIGN_EXTENSION_16  ((unsigned int) 0x1 <<  14)   // 14     Sign extension
#define   SIGN_EXTENSION_32  ((unsigned int) 0x1 <<  15)   // 15     Sign extension

//-------------------------------------------------
// AD Group 2 Threshold Counter Register bit definitions
//
// ADTHRG2_BITS
#define   G2THR_1            ((unsigned int) 0x1 <<  0)    // 0      Group 2 interrupt threshold counter
#define   G2THR_2            ((unsigned int) 0x1 <<  1)    // 1      Group 2 interrupt threshold counter
#define   G2THR_4            ((unsigned int) 0x1 <<  2)    // 2      Group 2 interrupt threshold counter
#define   G2THR_8            ((unsigned int) 0x1 <<  3)    // 3      Group 2 interrupt threshold counter
#define   G2THR_16           ((unsigned int) 0x1 <<  4)    // 4      Group 2 interrupt threshold counter
#define   G2THR_32           ((unsigned int) 0x1 <<  5)    // 5      Group 2 interrupt threshold counter
#define   G2THR_64           ((unsigned int) 0x1 <<  6)    // 6      Group 2 interrupt threshold counter
#define   G2THR_128          ((unsigned int) 0x1 <<  7)    // 7      Group 2 interrupt threshold counter
#define   G2THR_256          ((unsigned int) 0x1 <<  8)    // 8      Group 2 interrupt threshold counter
#define   G2THR_512          ((unsigned int) 0x1 <<  9)    // 9      Group 2 interrupt threshold counter
#define   SIGN_EXTENSION_1   ((unsigned int) 0x1 <<  10)   // 10     Sign extension
#define   SIGN_EXTENSION_2   ((unsigned int) 0x1 <<  11)   // 11     Sign extension
#define   SIGN_EXTENSION_4   ((unsigned int) 0x1 <<  12)   // 12     Sign extension
#define   SIGN_EXTENSION_8   ((unsigned int) 0x1 <<  13)   // 13     Sign extension
#define   SIGN_EXTENSION_16  ((unsigned int) 0x1 <<  14)   // 14     Sign extension
#define   SIGN_EXTENSION_32  ((unsigned int) 0x1 <<  15)   // 15     Sign extension

//-------------------------------------------------
// AD Event Source Register bit definitions
//
// ADEVTSRC_BITS
#define   EV_SRC_ADEVT      ((unsigned int) 0x0 <<  0)    // 1:0    Event group source select - ADEVT pin
#define   EV_SRC_INT1       ((unsigned int) 0x1 <<  0)    // 1:0    Event group source select - Internal 1
#define   EV_SRC_INT2       ((unsigned int) 0x2 <<  0)    // 1:0    Event group source select - Internal 2
#define   EV_SRC_INT3       ((unsigned int) 0x3 <<  0)    // 1:0    Event group source select - Internal 3
#define   G1_SRC_ADEVT      ((unsigned int) 0x0 <<  4)    // 5:4    Group 1 source select - ADEVT pin
#define   G1_SRC_INT1       ((unsigned int) 0x1 <<  4)    // 5:4    Group 1 source select - Internal 1
#define   G1_SRC_INT2       ((unsigned int) 0x2 <<  4)    // 5:4    Group 1 source select - Internal 2
#define   G1_SRC_INT3       ((unsigned int) 0x3 <<  4)    // 5:4    Group 1 source select - Internal 3
#define   G1_EDG_SEL        ((unsigned int) 0x1 <<  7)    // 7      Group 1 event trigger edge select
#define   G1_ENA            ((unsigned int) 0x1 <<  8)    // 8      Group 1 event trigger enable

//===========================================================================
// Compatibility Mode Specific Registers
//

//-------------------------------------------------
// AD Digital Result Register bit definitions
//
// ADDRX_BITS
#define   DTX_1                ((unsigned int) 0x1 <<  0)    // 0      Conversion data bits
#define   DTX_2                ((unsigned int) 0x1 <<  1)    // 1      Conversion data bits
#define   DTX_4                ((unsigned int) 0x1 <<  2)    // 2      Conversion data bits
#define   DTX_8                ((unsigned int) 0x1 <<  3)    // 3      Conversion data bits
#define   DTX_16               ((unsigned int) 0x1 <<  4)    // 4      Conversion data bits
#define   DTX_32               ((unsigned int) 0x1 <<  5)    // 5      Conversion data bits
#define   DTX_64               ((unsigned int) 0x1 <<  6)    // 6      Conversion data bits
#define   DTX_128              ((unsigned int) 0x1 <<  7)    // 7      Conversion data bits
#define   DTX_256              ((unsigned int) 0x1 <<  8)    // 8      Conversion data bits
#define   DTX_512              ((unsigned int) 0x1 <<  9)    // 9      Conversion data bits
#define   DTX_ST               ((unsigned int) 0x1 <<  15)   // 15     Data read status

//-------------------------------------------------
// AD Emulation Digital Result Register bit definitions
//
// ADEMDRX_BITS
#define   EDTX_1             ((unsigned int) 0x1 <<  0)    // 0      Conversion data bits
#define   EDTX_2             ((unsigned int) 0x1 <<  1)    // 1      Conversion data bits
#define   EDTX_4             ((unsigned int) 0x1 <<  2)    // 2      Conversion data bits
#define   EDTX_8             ((unsigned int) 0x1 <<  3)    // 3      Conversion data bits
#define   EDTX_16            ((unsigned int) 0x1 <<  4)    // 4      Conversion data bits
#define   EDTX_32            ((unsigned int) 0x1 <<  5)    // 5      Conversion data bits
#define   EDTX_64            ((unsigned int) 0x1 <<  6)    // 6      Conversion data bits
#define   EDTX_128           ((unsigned int) 0x1 <<  7)    // 7      Conversion data bits
#define   EDTX_256           ((unsigned int) 0x1 <<  8)    // 8      Conversion data bits
#define   EDTX_512           ((unsigned int) 0x1 <<  9)    // 9      Conversion data bits
#define   EDTX_ST            ((unsigned int) 0x1 <<  15)   // 15     Data read status

//===========================================================================
// Buffered Mode Specific Registers
//

//-------------------------------------------------
// AD Control Register 2 bit definitions
//
// ADBUFE_BITS
#define   EV_DR_1             ((unsigned int) 0x1 <<  0)    // 0      Event group digital result
#define   EV_DR_2             ((unsigned int) 0x1 <<  1)    // 1      Event group digital result
#define   EV_DR_4             ((unsigned int) 0x1 <<  2)    // 2      Event group digital result
#define   EV_DR_8             ((unsigned int) 0x1 <<  3)    // 3      Event group digital result
#define   EV_DR_16            ((unsigned int) 0x1 <<  4)    // 4      Event group digital result
#define   EV_DR_32            ((unsigned int) 0x1 <<  5)    // 5      Event group digital result
#define   EV_DR_64            ((unsigned int) 0x1 <<  6)    // 6      Event group digital result
#define   EV_DR_128           ((unsigned int) 0x1 <<  7)    // 7      Event group digital result
#define   EV_DR_256           ((unsigned int) 0x1 <<  8)    // 8      Event group digital result
#define   EV_DR_512           ((unsigned int) 0x1 <<  9)    // 9      Event group digital result
#define   EV_CH_0             ((unsigned int) 0x0 <<  10)   // 13:10  Event group channel ID 0
#define   EV_CH_1             ((unsigned int) 0x1 <<  10)   // 13:10  Event group channel ID 1
#define   EV_CH_2             ((unsigned int) 0x2 <<  10)   // 13:10  Event group channel ID 2
#define   EV_CH_3             ((unsigned int) 0x3 <<  10)   // 13:10  Event group channel ID 3
#define   EV_CH_4             ((unsigned int) 0x4 <<  10)   // 13:10  Event group channel ID 4
#define   EV_CH_5             ((unsigned int) 0x5 <<  10)   // 13:10  Event group channel ID 5
#define   EV_CH_6             ((unsigned int) 0x6 <<  10)   // 13:10  Event group channel ID 6
#define   EV_CH_7             ((unsigned int) 0x7 <<  10)   // 13:10  Event group channel ID 7
#define   EV_CH_8             ((unsigned int) 0x8 <<  10)   // 13:10  Event group channel ID 8
#define   EV_CH_9             ((unsigned int) 0x9 <<  10)   // 13:10  Event group channel ID 9
#define   EV_CH_10            ((unsigned int) 0xA <<  10)   // 13:10  Event group channel ID 10
#define   EV_CH_11            ((unsigned int) 0xB <<  10)   // 13:10  Event group channel ID 11
#define   EV_CH_12            ((unsigned int) 0xC <<  10)   // 13:10  Event group channel ID 12
#define   EV_CH_13            ((unsigned int) 0xD <<  10)   // 13:10  Event group channel ID 13
#define   EV_CH_14            ((unsigned int) 0xE <<  10)   // 13:10  Event group channel ID 14
#define   EV_CH_15            ((unsigned int) 0xF <<  10)   // 13:10  Event group channel ID 15
#define   ADBUFE_EV_EMPTY            ((unsigned int) 0x1 <<  15)   // 15     Event group FIFO empty

//-------------------------------------------------
// AD Group 1 Fifo Buffer
//
// ADBUF1_BITS
#define   G1_DR_1             ((unsigned int) 0x1 <<  0)    // 0      Group 1 digital result
#define   G1_DR_2             ((unsigned int) 0x1 <<  1)    // 1      Group 1 digital result
#define   G1_DR_4             ((unsigned int) 0x1 <<  2)    // 2      Group 1 digital result
#define   G1_DR_8             ((unsigned int) 0x1 <<  3)    // 3      Group 1 digital result
#define   G1_DR_16            ((unsigned int) 0x1 <<  4)    // 4      Group 1 digital result
#define   G1_DR_32            ((unsigned int) 0x1 <<  5)    // 5      Group 1 digital result
#define   G1_DR_64            ((unsigned int) 0x1 <<  6)    // 6      Group 1 digital result
#define   G1_DR_128           ((unsigned int) 0x1 <<  7)    // 7      Group 1 digital result
#define   G1_DR_256           ((unsigned int) 0x1 <<  8)    // 8      Group 1 digital result
#define   G1_DR_512           ((unsigned int) 0x1 <<  9)    // 9      Group 1 digital result
#define   G1_CH_0             ((unsigned int) 0x0 <<  10)   // 13:10  Group 1 channel ID 0
#define   G1_CH_1             ((unsigned int) 0x1 <<  10)   // 13:10  Group 1 channel ID 1
#define   G1_CH_2             ((unsigned int) 0x2 <<  10)   // 13:10  Group 1 channel ID 2
#define   G1_CH_3             ((unsigned int) 0x3 <<  10)   // 13:10  Group 1 channel ID 3
#define   G1_CH_4             ((unsigned int) 0x4 <<  10)   // 13:10  Group 1 channel ID 4
#define   G1_CH_5             ((unsigned int) 0x5 <<  10)   // 13:10  Group 1 channel ID 5
#define   G1_CH_6             ((unsigned int) 0x6 <<  10)   // 13:10  Group 1 channel ID 6
#define   G1_CH_7             ((unsigned int) 0x7 <<  10)   // 13:10  Group 1 channel ID 7
#define   G1_CH_8             ((unsigned int) 0x8 <<  10)   // 13:10  Group 1 channel ID 8
#define   G1_CH_9             ((unsigned int) 0x9 <<  10)   // 13:10  Group 1 channel ID 9
#define   G1_CH_10            ((unsigned int) 0xA <<  10)   // 13:10  Group 1 channel ID 10
#define   G1_CH_11            ((unsigned int) 0xB <<  10)   // 13:10  Group 1 channel ID 11
#define   G1_CH_12            ((unsigned int) 0xC <<  10)   // 13:10  Group 1 channel ID 12
#define   G1_CH_13            ((unsigned int) 0xD <<  10)   // 13:10  Group 1 channel ID 13
#define   G1_CH_14            ((unsigned int) 0xE <<  10)   // 13:10  Group 1 channel ID 14
#define   G1_CH_15            ((unsigned int) 0xF <<  10)   // 13:10  Group 1 channel ID 15
#define   ADBUF1_G1_EMPTY            ((unsigned int) 0x1 <<  15)   // 15     Group 1 FIFO empty

//-------------------------------------------------
// AD Group 2 Fifo Buffer
//
// ADBUF2_BITS
#define   G2_DR_1             ((unsigned int) 0x1 <<  0)    // 0      Group 2 digital result
#define   G2_DR_2             ((unsigned int) 0x1 <<  1)    // 1      Group 2 digital result
#define   G2_DR_4             ((unsigned int) 0x1 <<  2)    // 2      Group 2 digital result
#define   G2_DR_8             ((unsigned int) 0x1 <<  3)    // 3      Group 2 digital result
#define   G2_DR_16            ((unsigned int) 0x1 <<  4)    // 4      Group 2 digital result
#define   G2_DR_32            ((unsigned int) 0x1 <<  5)    // 5      Group 2 digital result
#define   G2_DR_64            ((unsigned int) 0x1 <<  6)    // 6      Group 2 digital result
#define   G2_DR_128           ((unsigned int) 0x1 <<  7)    // 7      Group 2 digital result
#define   G2_DR_256           ((unsigned int) 0x1 <<  8)    // 8      Group 2 digital result
#define   G2_DR_512           ((unsigned int) 0x1 <<  9)    // 9      Group 2 digital result
#define   G2_CH_0             ((unsigned int) 0x0 <<  10)   // 13:10  Group 2 channel ID 0
#define   G2_CH_1             ((unsigned int) 0x1 <<  10)   // 13:10  Group 2 channel ID 1
#define   G2_CH_2             ((unsigned int) 0x2 <<  10)   // 13:10  Group 2 channel ID 2
#define   G2_CH_3             ((unsigned int) 0x3 <<  10)   // 13:10  Group 2 channel ID 3
#define   G2_CH_4             ((unsigned int) 0x4 <<  10)   // 13:10  Group 2 channel ID 4
#define   G2_CH_5             ((unsigned int) 0x5 <<  10)   // 13:10  Group 2 channel ID 5
#define   G2_CH_6             ((unsigned int) 0x6 <<  10)   // 13:10  Group 2 channel ID 6
#define   G2_CH_7             ((unsigned int) 0x7 <<  10)   // 13:10  Group 2 channel ID 7
#define   G2_CH_8             ((unsigned int) 0x8 <<  10)   // 13:10  Group 2 channel ID 8
#define   G2_CH_9             ((unsigned int) 0x9 <<  10)   // 13:10  Group 2 channel ID 9
#define   G2_CH_10            ((unsigned int) 0xA <<  10)   // 13:10  Group 2 channel ID 10
#define   G2_CH_11            ((unsigned int) 0xB <<  10)   // 13:10  Group 2 channel ID 11
#define   G2_CH_12            ((unsigned int) 0xC <<  10)   // 13:10  Group 2 channel ID 12
#define   G2_CH_13            ((unsigned int) 0xD <<  10)   // 13:10  Group 2 channel ID 13
#define   G2_CH_14            ((unsigned int) 0xE <<  10)   // 13:10  Group 2 channel ID 14
#define   G2_CH_15            ((unsigned int) 0xF <<  10)   // 13:10  Group 2 channel ID 15
#define   ADBUF2_G2_EMPTY            ((unsigned int) 0x1 <<  15)   // 15     Group 2 FIFO empty

//-------------------------------------------------
// AD Emulation Event Fifo Buffer
//
// ADEMUBUFE_BITS
#define   EV_DR_1          ((unsigned int) 0x1 <<  0)    // 0      Event group digital result
#define   EV_DR_2          ((unsigned int) 0x1 <<  1)    // 1      Event group digital result
#define   EV_DR_4          ((unsigned int) 0x1 <<  2)    // 2      Event group digital result
#define   EV_DR_8          ((unsigned int) 0x1 <<  3)    // 3      Event group digital result
#define   EV_DR_16         ((unsigned int) 0x1 <<  4)    // 4      Event group digital result
#define   EV_DR_32         ((unsigned int) 0x1 <<  5)    // 5      Event group digital result
#define   EV_DR_64         ((unsigned int) 0x1 <<  6)    // 6      Event group digital result
#define   EV_DR_128        ((unsigned int) 0x1 <<  7)    // 7      Event group digital result
#define   EV_DR_256        ((unsigned int) 0x1 <<  8)    // 8      Event group digital result
#define   EV_DR_512        ((unsigned int) 0x1 <<  9)    // 9      Event group digital result
#define   EV_CH_0          ((unsigned int) 0x0 <<  10)   // 13:10  Event group channel ID 0
#define   EV_CH_1          ((unsigned int) 0x1 <<  10)   // 13:10  Event group channel ID 1
#define   EV_CH_2          ((unsigned int) 0x2 <<  10)   // 13:10  Event group channel ID 2
#define   EV_CH_3          ((unsigned int) 0x3 <<  10)   // 13:10  Event group channel ID 3
#define   EV_CH_4          ((unsigned int) 0x4 <<  10)   // 13:10  Event group channel ID 4
#define   EV_CH_5          ((unsigned int) 0x5 <<  10)   // 13:10  Event group channel ID 5
#define   EV_CH_6          ((unsigned int) 0x6 <<  10)   // 13:10  Event group channel ID 6
#define   EV_CH_7          ((unsigned int) 0x7 <<  10)   // 13:10  Event group channel ID 7
#define   EV_CH_8          ((unsigned int) 0x8 <<  10)   // 13:10  Event group channel ID 8
#define   EV_CH_9          ((unsigned int) 0x9 <<  10)   // 13:10  Event group channel ID 9
#define   EV_CH_10         ((unsigned int) 0xA <<  10)   // 13:10  Event group channel ID 10
#define   EV_CH_11         ((unsigned int) 0xB <<  10)   // 13:10  Event group channel ID 11
#define   EV_CH_12         ((unsigned int) 0xC <<  10)   // 13:10  Event group channel ID 12
#define   EV_CH_13         ((unsigned int) 0xD <<  10)   // 13:10  Event group channel ID 13
#define   EV_CH_14         ((unsigned int) 0xE <<  10)   // 13:10  Event group channel ID 14
#define   EV_CH_15         ((unsigned int) 0xF <<  10)   // 13:10  Event group channel ID 15
#define   ADEMUBUFE_EV_EMPTY         ((unsigned int) 0x1 <<  15)   // 15     Event group FIFO empty

//-------------------------------------------------
// AD Emulation Group 1 Fifo Buffer
//
// ADEMUBUF1_BITS

#define   G1_DR_1          ((unsigned int) 0x1 <<  0)    // 0      Group 1 digital result
#define   G1_DR_2          ((unsigned int) 0x1 <<  1)    // 1      Group 1 digital result
#define   G1_DR_4          ((unsigned int) 0x1 <<  2)    // 2      Group 1 digital result
#define   G1_DR_8          ((unsigned int) 0x1 <<  3)    // 3      Group 1 digital result
#define   G1_DR_16         ((unsigned int) 0x1 <<  4)    // 4      Group 1 digital result
#define   G1_DR_32         ((unsigned int) 0x1 <<  5)    // 5      Group 1 digital result
#define   G1_DR_64         ((unsigned int) 0x1 <<  6)    // 6      Group 1 digital result
#define   G1_DR_128        ((unsigned int) 0x1 <<  7)    // 7      Group 1 digital result
#define   G1_DR_256        ((unsigned int) 0x1 <<  8)    // 8      Group 1 digital result
#define   G1_DR_512        ((unsigned int) 0x1 <<  9)    // 9      Group 1 digital result
#define   G1_CH_0          ((unsigned int) 0x0 <<  10)   // 13:10  Group 1 channel ID 0
#define   G1_CH_1          ((unsigned int) 0x1 <<  10)   // 13:10  Group 1 channel ID 1
#define   G1_CH_2          ((unsigned int) 0x2 <<  10)   // 13:10  Group 1 channel ID 2
#define   G1_CH_3          ((unsigned int) 0x3 <<  10)   // 13:10  Group 1 channel ID 3
#define   G1_CH_4          ((unsigned int) 0x4 <<  10)   // 13:10  Group 1 channel ID 4
#define   G1_CH_5          ((unsigned int) 0x5 <<  10)   // 13:10  Group 1 channel ID 5
#define   G1_CH_6          ((unsigned int) 0x6 <<  10)   // 13:10  Group 1 channel ID 6
#define   G1_CH_7          ((unsigned int) 0x7 <<  10)   // 13:10  Group 1 channel ID 7
#define   G1_CH_8          ((unsigned int) 0x8 <<  10)   // 13:10  Group 1 channel ID 8
#define   G1_CH_9          ((unsigned int) 0x9 <<  10)   // 13:10  Group 1 channel ID 9
#define   G1_CH_10         ((unsigned int) 0xA <<  10)   // 13:10  Group 1 channel ID 10
#define   G1_CH_11         ((unsigned int) 0xB <<  10)   // 13:10  Group 1 channel ID 11
#define   G1_CH_12         ((unsigned int) 0xC <<  10)   // 13:10  Group 1 channel ID 12
#define   G1_CH_13         ((unsigned int) 0xD <<  10)   // 13:10  Group 1 channel ID 13
#define   G1_CH_14         ((unsigned int) 0xE <<  10)   // 13:10  Group 1 channel ID 14
#define   G1_CH_15         ((unsigned int) 0xF <<  10)   // 13:10  Group 1 channel ID 15
#define   ADEMUBUF1_G1_EMPTY         ((unsigned int) 0x1 <<  15)   // 15     Group 1 FIFO empty

//-------------------------------------------------
// AD Emulation Group 2 Fifo Buffer
//
// ADEMUBUF2_BITS
#define   G2_DR_1          ((unsigned int) 0x1 <<  0)    // 0      Group 2 digital result
#define   G2_DR_2          ((unsigned int) 0x1 <<  1)    // 1      Group 2 digital result
#define   G2_DR_4          ((unsigned int) 0x1 <<  2)    // 2      Group 2 digital result
#define   G2_DR_8          ((unsigned int) 0x1 <<  3)    // 3      Group 2 digital result
#define   G2_DR_16         ((unsigned int) 0x1 <<  4)    // 4      Group 2 digital result
#define   G2_DR_32         ((unsigned int) 0x1 <<  5)    // 5      Group 2 digital result
#define   G2_DR_64         ((unsigned int) 0x1 <<  6)    // 6      Group 2 digital result
#define   G2_DR_128        ((unsigned int) 0x1 <<  7)    // 7      Group 2 digital result
#define   G2_DR_256        ((unsigned int) 0x1 <<  8)    // 8      Group 2 digital result
#define   G2_DR_512        ((unsigned int) 0x1 <<  9)    // 9      Group 2 digital result
#define   G2_CH_0          ((unsigned int) 0x0 <<  10)   // 13:10  Group 2 channel ID 0
#define   G2_CH_1          ((unsigned int) 0x1 <<  10)   // 13:10  Group 2 channel ID 1
#define   G2_CH_2          ((unsigned int) 0x2 <<  10)   // 13:10  Group 2 channel ID 2
#define   G2_CH_3          ((unsigned int) 0x3 <<  10)   // 13:10  Group 2 channel ID 3
#define   G2_CH_4          ((unsigned int) 0x4 <<  10)   // 13:10  Group 2 channel ID 4
#define   G2_CH_5          ((unsigned int) 0x5 <<  10)   // 13:10  Group 2 channel ID 5
#define   G2_CH_6          ((unsigned int) 0x6 <<  10)   // 13:10  Group 2 channel ID 6
#define   G2_CH_7          ((unsigned int) 0x7 <<  10)   // 13:10  Group 2 channel ID 7
#define   G2_CH_8          ((unsigned int) 0x8 <<  10)   // 13:10  Group 2 channel ID 8
#define   G2_CH_9          ((unsigned int) 0x9 <<  10)   // 13:10  Group 2 channel ID 9

#define   G2_CH_10         ((unsigned int) 0xA <<  10)   // 13:10  Group 2 channel ID 10
#define   G2_CH_11         ((unsigned int) 0xB <<  10)   // 13:10  Group 2 channel ID 11
#define   G2_CH_12         ((unsigned int) 0xC <<  10)   // 13:10  Group 2 channel ID 12
#define   G2_CH_13         ((unsigned int) 0xD <<  10)   // 13:10  Group 2 channel ID 13
#define   G2_CH_14         ((unsigned int) 0xE <<  10)   // 13:10  Group 2 channel ID 14
#define   G2_CH_15         ((unsigned int) 0xF <<  10)   // 13:10  Group 2 channel ID 15
#define   ADEMUBUF2_G2_EMPTY         ((unsigned int) 0x1 <<  15)   // 15     Group 2 FIFO empty

//===========================================================================
// I2C Individual Register Bit Definitions
//
//-------------------------------------------------
// I2CMDR I2C Mode Register
//
// i2cmdr_bits

#define   BC              ((unsigned int) 0x3 <<  0)              //
#define   FDF             ((unsigned int) 0x1 <<  3)             //
#define   STB             ((unsigned int) 0x1 <<  4)            //
#define   NIRS            ((unsigned int) 0x1 <<  5)            //
#define   DLB             ((unsigned int) 0x1 <<  6)             //
#define   I2C_RM              ((unsigned int) 0x1 <<  7)      //
#define   XA              ((unsigned int) 0x1 <<  8)            //
#define   TRX             ((unsigned int) 0x1 <<  9)           //
#define   MST             ((unsigned int) 0x1 <<  10)        //
#define   STP             ((unsigned int) 0x1 <<  11)         //
#define   I2C_LPM             ((unsigned int) 0x1 <<  12)    //
#define   STT             ((unsigned int) 0x1 <<  13)         //
#define   FREE            ((unsigned int) 0x1 <<  14)         //
#define   NACKMOD         ((unsigned int) 0x1 <<  15)    //

//-------------------------------------------------
// I2CDIR I2C Data Direction Register
//
// i2cdir_bits
#define   SCLDIR          ((unsigned int) 0x1 <<  0)     //
#define   SDADIR          ((unsigned int) 0x1 <<  1)     //
#define   SCLFUNC         ((unsigned int) 0x1 <<  2)     //
#define   SDAFUNC         ((unsigned int) 0x1 <<  3)     //
#define   I2C_RXDMAEN         ((unsigned int) 0x1 <<  4)     //
#define   I2C_TXDMAEN         ((unsigned int) 0x1 <<  5)     //


//===========================================================================
// Flash Individual Register Bit Definitions
//

//-------------------------------------------------
// Flash Option Control Register bit definitions
//
//FMREGOPT_BITS
#define   ENPIPE            ((unsigned int) 0x1 <<  0)   // 0      Flash pipeline mode enable
#define   READOTP           ((unsigned int) 0x1 <<  1)   // 1      Read OTP sector
#define   RDMRGN0           ((unsigned int) 0x1 <<  2)   // 2      Read margin 0
#define   RDMRGN1           ((unsigned int) 0x1 <<  3)   // 3      Read margin 1


//-------------------------------------------------
// Flash Bank Access Control Register 1 bit definitions
//
// FMBAC1_BITS

#define   BNKPWR_SLEEP      ((unsigned int) 0x00 <<  0)    //  1:0    Bank power mode
#define   BNKPWR_STANDBY    ((unsigned int) 0x01 <<  0)    //  1:0    Bank power mode
#define   BNKPWR_ACTIVE     ((unsigned int) 0x03 <<  0)    // 1:0    Bank power mode
#define   BSTDBY_MAX        ((unsigned int) 0x3f <<  2)    // 7:2    Bank standby

//-------------------------------------------------
// Flash Bank Access Control Register 2 bit definitions
//
// FMBAC2_BITS

#define   PIPELINE_MODE     ((unsigned int) 0x11 <<  0)    // 0:7 Set Pipeline mode
#define   BSLEEP_MAX        ((unsigned int) 0x7f <<  8)    // 14:8   Bank sleep

//-------------------------------------------------
// Flash Module Access Control Register 2 bit definitions
//
//FMMAC2_BITS
#define   BANK0_ENA      ((unsigned int) 0x00 <<  0)    // 0:2      BANK Enable 0
#define   BANK1_ENA      ((unsigned int) 0x01 <<  0)    // 0:2      BANK Enable 1
#define   BANK2_ENA      ((unsigned int) 0x02 <<  0)    // 0:2      BANK Enable 2
#define   BANK3_ENA      ((unsigned int) 0x03 <<  0)    // 0:2      BANK Enable 3
#define   BANK4_ENA      ((unsigned int) 0x04 <<  0)    // 0:2      BANK Enable 4
#define   BANK5_ENA      ((unsigned int) 0x05 <<  0)    // 0:2      BANK Enable 5
#define   BANK6_ENA      ((unsigned int) 0x06 <<  0)    // 0:2      BANK Enable 6
#define   BANK7_ENA      ((unsigned int) 0x07 <<  0)    // 0:2      BANK Enable 7

#define   PMPPWR_SLEEP   ((unsigned int) 0x00 <<  3)    // 4:3    Flash pump fallback power mode
#define   PMPPWR_STANDBY ((unsigned int) 0x01 <<  3)    // 4:3    Flash pump fallback power mode
#define   PMPPWR_ACTIVE  ((unsigned int) 0x03 <<  3)    // 4:3    Flash pump fallback power mode
#define   PSTDBY_MAX      ((unsigned int) 0x07ff <<  5)            // 15:5   Pump standby

//*******************************************************************************************
// DMA
//

//-------------------------------------------------
// DMA Configuration Register
//
// DMAC_BITS
#define   DCHN           ((unsigned int) 0x01 <<  0)    // 0        Data Chaining Enable
#define   SRCMOD_1       ((unsigned int) 0x01 <<  1)    // 1:4      Memory module controlled by fine memory select 1.
#define   SRCMOD_2       ((unsigned int) 0x02 <<  1)    // 1:4      Memory module controlled by fine memory select 2.
#define   SRCMOD_3       ((unsigned int) 0x03 <<  1)    // 1:4      Memory module controlled BY fine memory select 3.
#define   SRCMOD_4       ((unsigned int) 0x04 <<  1)    // 1:4      Memory module controlled by fine memory select 4.
#define   SRCMOD_5       ((unsigned int) 0x05 <<  1)    // 1:4      Memory module controlled by fine memory select 5.
#define   SRCMOD_6       ((unsigned int) 0x06 <<  1)    // 1:4      Memory module controlled by coarse memory select 0.
#define   SRCMOD_7       ((unsigned int) 0x07 <<  1)    // 1:4      Memory module controlled by coarse memory select 1.
#define   SRCMOD_8       ((unsigned int) 0x08 <<  1)    // 1:4      Memory module controlled by coarse memory select 2.
#define   SRCMOD_9       ((unsigned int) 0x09 <<  1)    // 1:4      Memory module controlled by coarse memory select 3.
#define   SRCMOD_10      ((unsigned int) 0x0A <<  1)    // 1:4      Memory module controlled by coarse memory select 4.
#define   SRCMOD_11      ((unsigned int) 0x0B <<  1)    // 1:4      Memory module controlled by coarse memory select 5.
#define   SRCMOD_12      ((unsigned int) 0x0C <<  1)    // 1:4      Memory module with own address decoding on the CPU bus.
#define   SRCMOD_15      ((unsigned int) 0x0F <<  1)    // 1:4      Expansion bus peripherals
#define   DSTMOD_1       ((unsigned int) 0x01 <<  5)    // 5:8      Memory module controlled by fine memory select 1.
#define   DSTMOD_2       ((unsigned int) 0x02 <<  5)    // 5:8      Memory module controlled by fine memory select 2.
#define   DSTMOD_3       ((unsigned int) 0x03 <<  5)    // 5:8      Memory module controlled BY fine memory select 3.
#define   DSTMOD_4       ((unsigned int) 0x04 <<  5)    // 5:8      Memory module controlled by fine memory select 4.
#define   DSTMOD_5       ((unsigned int) 0x05 <<  5)    // 5:8      Memory module controlled by fine memory select 5.
#define   DSTMOD_6       ((unsigned int) 0x06 <<  5)    // 5:8      Memory module controlled by coarse memory select 0.
#define   DSTMOD_7       ((unsigned int) 0x07 <<  5)    // 5:8      Memory module controlled by coarse memory select 1.
#define   DSTMOD_8       ((unsigned int) 0x08 <<  5)    // 5:8      Memory module controlled by coarse memory select 2.
#define   DSTMOD_9       ((unsigned int) 0x09 <<  5)    // 5:8      Memory module controlled by coarse memory select 3.
#define   DSTMOD_10      ((unsigned int) 0x0A <<  5)    // 5:8      Memory module controlled by coarse memory select 4.
#define   DSTMOD_11      ((unsigned int) 0x0B <<  5)    // 5:8      Memory module controlled by coarse memory select 5.
#define   DSTMOD_12      ((unsigned int) 0x0C <<  5)    // 5:8      Memory module with own address decoding on the CPU bus.
#define   DSTMOD_15      ((unsigned int) 0x0F <<  5)    // 5:8      Expansion bus peripherals
#define   SRCINC         ((unsigned int) 0x01 <<  9)    // 9        Source Address Increment
#define   DSTINC         ((unsigned int) 0x01 <<  11)   // 11       Destination Address Increment
#define   TRSIZE_0       ((unsigned int) 0x00 <<  13)   // 13:14    An 8-bit read/write
#define   TRSIZE_1       ((unsigned int) 0x01 <<  13)   // 13:14    A 16-bit read/write
#define   TRSIZE_2       ((unsigned int) 0x02 <<  13)   // 13:14    A 32-bit read/write
#define   INTEN          ((unsigned int) 0x01 <<  15)   // 15       Interrupt Enable
#define   NCPACK_0       ((unsigned int) 0x00 <<  24)   // 24:28    Next Control Packet: 0
#define   NCPACK_1       ((unsigned int) 0x01 <<  24)   // 24:28    Next Control Packet: 1
#define   NCPACK_2       ((unsigned int) 0x01 <<  25)   // 24:28    Next Control Packet: 2
#define   NCPACK_4       ((unsigned int) 0x01 <<  26)   // 24:28    Next Control Packet: 4
#define   NCPACK_8       ((unsigned int) 0x01 <<  27)   // 24:28    Next Control Packet: 8
#define   NCPACK_16      ((unsigned int) 0x01 <<  28)   // 24:28    Next Control Packet: 16

//-------------------------------------------------
// DMA Channel Control 0
//
// DMACC0_BITS
                                                         // 0        Reserved
#define   RQEN0           ((unsigned int) 0x01 <<  1)    // 1        Request enable for the channel.
#define   SEN0            ((unsigned int) 0x01 <<  2)    // 2        Suspend enable for the channel.
#define   IL0             ((unsigned int) 0x01 <<  3)    // 3        Interrupt level for the channel.
                                                         // 4        Reserved
#define   RQEN1           ((unsigned int) 0x01 <<  5)    // 5        Request enable for the channel.
#define   SEN1            ((unsigned int) 0x01 <<  6)    // 6        Suspend enable for the channel.
#define   IL1             ((unsigned int) 0x01 <<  7)    // 7        Interrupt level for the channel.
                                                         // 8        Reserved
#define   RQEN2           ((unsigned int) 0x01 <<  9)    // 9        Request enable for the channel.
#define   SEN2            ((unsigned int) 0x01 <<  10)   // 10       Suspend enable for the channel.
#define   IL2             ((unsigned int) 0x01 <<  11)   // 11       Interrupt level for the channel.
                                                         // 12       Reserved
#define   RQEN3           ((unsigned int) 0x01 <<  13)   // 13       Request enable for the channel.
#define   SEN3            ((unsigned int) 0x01 <<  14)   // 14       Suspend enable for the channel.
#define   IL3             ((unsigned int) 0x01 <<  15)   // 15       Interrupt level for the channel.
                                                         // 16       Reserved
#define   RQEN4           ((unsigned int) 0x01 <<  16)   // 17       Request enable for the channel.
#define   SEN4            ((unsigned int) 0x01 <<  17)   // 18       Suspend enable for the channel.
#define   IL4             ((unsigned int) 0x01 <<  18)   // 19       Interrupt level for the channel.
                                                         // 20       Reserved
#define   RQEN5           ((unsigned int) 0x01 <<  21)   // 21       Request enable for the channel.
#define   SEN5            ((unsigned int) 0x01 <<  22)   // 22       Suspend enable for the channel.
#define   IL5             ((unsigned int) 0x01 <<  23)   // 23       Interrupt level for the channel.
                                                         // 24       Reserved
#define   RQEN6           ((unsigned int) 0x01 <<  25)   // 25       Request enable for the channel.
#define   SEN6            ((unsigned int) 0x01 <<  26)   // 26       Suspend enable for the channel.
#define   IL6             ((unsigned int) 0x01 <<  27)   // 27       Interrupt level for the channel.
                                                         // 28       Reserved
#define   RQEN7           ((unsigned int) 0x01 <<  29)   // 29       Request enable for the channel.
#define   SEN7            ((unsigned int) 0x01 <<  30)   // 30       Suspend enable for the channel.
#define   IL7             ((unsigned int) 0x01 <<  31)   // 31       Interrupt level for the channel.

//-------------------------------------------------
// DMA Channel Control 1
//
// DMACC1_BITS
                                                         // 0        Reserved
#define   RQEN8           ((unsigned int) 0x01 <<  1)    // 1        Request enable for the channel.
#define   SEN8            ((unsigned int) 0x01 <<  2)    // 2        Suspend enable for the channel.
#define   IL8             ((unsigned int) 0x01 <<  3)    // 3        Interrupt level for the channel.
                                                         // 4        Reserved
#define   RQEN9           ((unsigned int) 0x01 <<  5)    // 5        Request enable for the channel.
#define   SEN9            ((unsigned int) 0x01 <<  6)    // 6        Suspend enable for the channel.
#define   IL9             ((unsigned int) 0x01 <<  7)    // 7        Interrupt level for the channel.
                                                         // 8        Reserved
#define   RQEN10          ((unsigned int) 0x01 <<  9)    // 9        Request enable for the channel.
#define   SEN10           ((unsigned int) 0x01 <<  10)   // 10       Suspend enable for the channel.
#define   IL10            ((unsigned int) 0x01 <<  11)   // 11       Interrupt level for the channel.
                                                         // 12       Reserved
#define   RQEN11          ((unsigned int) 0x01 <<  13)   // 13       Request enable for the channel.
#define   SEN11           ((unsigned int) 0x01 <<  14)   // 14       Suspend enable for the channel.
#define   IL11            ((unsigned int) 0x01 <<  15)   // 15       Interrupt level for the channel.
                                                         // 16       Reserved
#define   RQEN12          ((unsigned int) 0x01 <<  16)   // 17       Request enable for the channel.
#define   SEN12           ((unsigned int) 0x01 <<  17)   // 18       Suspend enable for the channel.
#define   IL12            ((unsigned int) 0x01 <<  18)   // 19       Interrupt level for the channel.
                                                         // 20       Reserved
#define   RQEN13          ((unsigned int) 0x01 <<  21)   // 21       Request enable for the channel.
#define   SEN13           ((unsigned int) 0x01 <<  22)   // 22       Suspend enable for the channel.
#define   IL13            ((unsigned int) 0x01 <<  23)   // 23       Interrupt level for the channel.
                                                         // 24       Reserved
#define   RQEN14          ((unsigned int) 0x01 <<  25)   // 25       Request enable for the channel.
#define   SEN14           ((unsigned int) 0x01 <<  26)   // 26       Suspend enable for the channel.
#define   IL14            ((unsigned int) 0x01 <<  27)   // 27       Interrupt level for the channel.
                                                         // 28       Reserved
#define   RQEN15          ((unsigned int) 0x01 <<  29)   // 29       Request enable for the channel.
#define   SEN15           ((unsigned int) 0x01 <<  30)   // 30       Suspend enable for the channel.
#define   IL15            ((unsigned int) 0x01 <<  31)   // 31       Interrupt level for the channel.

//-------------------------------------------------
// DMA Status Register
//
// DMAS_BITS
#define   IF0             ((unsigned int) 0x01 <<  0)    // 0        Interrupt flag for channel 0
#define   IF1             ((unsigned int) 0x01 <<  1)    // 1        Interrupt flag for channel 1
#define   IF2             ((unsigned int) 0x01 <<  2)    // 2        Interrupt flag for channel 2
#define   IF3             ((unsigned int) 0x01 <<  3)    // 3        Interrupt flag for channel 3
#define   IF4             ((unsigned int) 0x01 <<  4)    // 4        Interrupt flag for channel 4
#define   IF5             ((unsigned int) 0x01 <<  5)    // 5        Interrupt flag for channel 5
#define   IF6             ((unsigned int) 0x01 <<  6)    // 6        Interrupt flag for channel 6
#define   IF7             ((unsigned int) 0x01 <<  7)    // 7        Interrupt flag for channel 7
#define   IF8             ((unsigned int) 0x01 <<  8)    // 8        Interrupt flag for channel 8
#define   IF9             ((unsigned int) 0x01 <<  9)    // 9        Interrupt flag for channel 9
#define   IF10            ((unsigned int) 0x01 <<  10)   // 10       Interrupt flag for channel 10
#define   IF11            ((unsigned int) 0x01 <<  11)   // 11       Interrupt flag for channel 11
#define   IF12            ((unsigned int) 0x01 <<  12)   // 12       Interrupt flag for channel 12
#define   IF13            ((unsigned int) 0x01 <<  13)   // 13       Interrupt flag for channel 13
#define   IF14            ((unsigned int) 0x01 <<  14)   // 14       Interrupt flag for channel 14
#define   IF15            ((unsigned int) 0x01 <<  15)   // 15       Interrupt flag for channel 15
#define   PINT            ((unsigned int) 0x01 <<  16)   // 16       Pending interrupt.
#define   TC              ((unsigned int) 0x01 <<  17)   // 17       Transfer complete flag.

//-------------------------------------------------
// DMA Global Control Register
//
// DMAGC_BITS
#define   CHSS_0          ((unsigned int) 0x00 <<  0)    // 0:3      1 Transaction to be performed
#define   CHSS_1          ((unsigned int) 0x01 <<  0)    // 0:3      2 Transaction to be performed
#define   CHSS_2          ((unsigned int) 0x02 <<  0)    // 0:3      3 Transaction to be performed
#define   CHSS_4          ((unsigned int) 0x04 <<  0)    // 0:3      5 Transaction to be performed
#define   CHSS_8          ((unsigned int) 0x08 <<  0)    // 0:3      9 Transaction to be performed
#define   BMSS            ((unsigned int) 0x01 <<  4)    // 4        Bus master switch size.
#define   CHPR            ((unsigned int) 0x01 <<  5)    // 5        Channel priority.
#define   HFIQ            ((unsigned int) 0x01 <<  6)    // 6        Halt on FIQ mode entry.
#define   HIRQ            ((unsigned int) 0x01 <<  7)    // 7        Halt on IRQ mode entry.

//-------------------------------------------------
// DMA Global Disable Register
//
// DMAGD_BITS
#define   DMA_HALT        ((unsigned int) 0x01 <<  0)    // 0
#define   DMA_STOP        ((unsigned int) 0x01 <<  1)    // 1

//-------------------------------------------------
// DMA Active Channel Register
//
// DMAAC_BITS
#define   ACT_CHN_0       ((unsigned int) 0x00 <<  0)    // 0        Active channel = 0
#define   ACT_CHN_1       ((unsigned int) 0x01 <<  0)    // 0        Active channel = 1
#define   ACT_CHN_2       ((unsigned int) 0x02 <<  0)    // 0        Active channel = 2
#define   ACT_CHN_4       ((unsigned int) 0x04 <<  0)    // 0        Active channel = 4
#define   ACT_CHN_8       ((unsigned int) 0x08 <<  0)    // 0        Active channel = 8

//-------------------------------------------------
// DMA Current Control Packet 0 Register
//
// DMACCP0_BITS
#define   CCPACK0_0       ((unsigned int) 0x00 <<  0)    // 0:4      Control Packet 0
#define   CCPACK0_1       ((unsigned int) 0x01 <<  0)    // 0:4      Control Packet 1
#define   CCPACK0_2       ((unsigned int) 0x02 <<  0)    // 0:4      Control Packet 2
#define   CCPACK0_4       ((unsigned int) 0x04 <<  0)    // 0:4      Control Packet 4
#define   CCPACK0_8       ((unsigned int) 0x08 <<  0)    // 0:4      Control Packet 8
#define   CCPACK0_16      ((unsigned int) 0x10 <<  0)    // 0:4      Control Packet 16
                                                         // 5        Reserved
#define   DMEN0           ((unsigned int) 0x01 <<  6)    // 6        DMA enable for the channel
                                                         // 7        Reserved
#define   CCPACK1_0       ((unsigned int) 0x00 <<  8)    // 8:12     Control Packet 0
#define   CCPACK1_1       ((unsigned int) 0x01 <<  8)    // 8:12     Control Packet 1
#define   CCPACK1_2       ((unsigned int) 0x02 <<  8)    // 8:12     Control Packet 2
#define   CCPACK1_4       ((unsigned int) 0x04 <<  8)    // 8:12     Control Packet 4
#define   CCPACK1_8       ((unsigned int) 0x08 <<  8)    // 8:12     Control Packet 8
#define   CCPACK1_16      ((unsigned int) 0x10 <<  8)    // 8:12     Control Packet 16
                                                         // 13       Reserved
#define   DMEN1           ((unsigned int) 0x01 <<  14    // 14       DMA enable for the channel
                                                         // 15       Reserved
#define   CCPACK2_0       ((unsigned int) 0x00 <<  16)   // 16:20    Control Packet 0
#define   CCPACK2_1       ((unsigned int) 0x01 <<  16)   // 16:20    Control Packet 1
#define   CCPACK2_2       ((unsigned int) 0x02 <<  16)   // 16:20    Control Packet 2
#define   CCPACK2_4       ((unsigned int) 0x04 <<  16)   // 16:20    Control Packet 4
#define   CCPACK2_8       ((unsigned int) 0x08 <<  16)   // 16:20    Control Packet 8
#define   CCPACK2_16      ((unsigned int) 0x10 <<  16)   // 16:20    Control Packet 16
                                                         // 21       Reserved
#define   DMEN2           ((unsigned int) 0x01 <<  22)   // 22       DMA enable for the channel
                                                         // 23       Reserved
#define   CCPACK3_0       ((unsigned int) 0x00 <<  24)   // 24:28    Control Packet 0
#define   CCPACK3_1       ((unsigned int) 0x01 <<  24)   // 24:28    Control Packet 1
#define   CCPACK3_2       ((unsigned int) 0x02 <<  24)   // 24:28    Control Packet 2
#define   CCPACK3_4       ((unsigned int) 0x04 <<  24)   // 24:28    Control Packet 4
#define   CCPACK3_8       ((unsigned int) 0x08 <<  24)   // 24:28    Control Packet 8
#define   CCPACK3_16      ((unsigned int) 0x10 <<  24)   // 24:28    Control Packet 16
                                                         // 29       Reserved
#define   DMEN3           ((unsigned int) 0x01 <<  30)   // 30       DMA enable for the channel
                                                         // 31       Reserved

//-------------------------------------------------
// DMA Current Control Packet 1 Register
//
// DMACCP1_BITS
#define   CCPACK4_0       ((unsigned int) 0x00 <<  0)    // 0:4      Control Packet 0
#define   CCPACK4_1       ((unsigned int) 0x01 <<  0)    // 0:4      Control Packet 1
#define   CCPACK4_2       ((unsigned int) 0x02 <<  0)    // 0:4      Control Packet 2
#define   CCPACK4_4       ((unsigned int) 0x04 <<  0)    // 0:4      Control Packet 4
#define   CCPACK4_8       ((unsigned int) 0x08 <<  0)    // 0:4      Control Packet 8
#define   CCPACK4_16      ((unsigned int) 0x10 <<  0)    // 0:4      Control Packet 16
                                                         // 5        Reserved
#define   DMEN4           ((unsigned int) 0x01 <<  6)    // 6        DMA enable for the channel
                                                         // 7        Reserved
#define   CCPACK5_0       ((unsigned int) 0x00 <<  8)    // 8:12     Control Packet 0
#define   CCPACK5_1       ((unsigned int) 0x01 <<  8)    // 8:12     Control Packet 1
#define   CCPACK5_2       ((unsigned int) 0x02 <<  8)    // 8:12     Control Packet 2
#define   CCPACK5_4       ((unsigned int) 0x04 <<  8)    // 8:12     Control Packet 4
#define   CCPACK5_8       ((unsigned int) 0x08 <<  8)    // 8:12     Control Packet 8
#define   CCPACK5_16      ((unsigned int) 0x10 <<  8)    // 8:12     Control Packet 16
                                                         // 13       Reserved
#define   DMEN5           ((unsigned int) 0x01 <<  14    // 14       DMA enable for the channel
                                                         // 15       Reserved
#define   CCPACK6_0       ((unsigned int) 0x00 <<  16)   // 16:20    Control Packet 0
#define   CCPACK6_1       ((unsigned int) 0x01 <<  16)   // 16:20    Control Packet 1
#define   CCPACK6_2       ((unsigned int) 0x02 <<  16)   // 16:20    Control Packet 2
#define   CCPACK6_4       ((unsigned int) 0x04 <<  16)   // 16:20    Control Packet 4
#define   CCPACK6_8       ((unsigned int) 0x08 <<  16)   // 16:20    Control Packet 8
#define   CCPACK6_16      ((unsigned int) 0x10 <<  16)   // 16:20    Control Packet 16
                                                         // 21       Reserved
#define   DMEN6           ((unsigned int) 0x01 <<  22)   // 22       DMA enable for the channel
                                                         // 23       Reserved
#define   CCPACK7_0       ((unsigned int) 0x00 <<  24)   // 24:28    Control Packet 0
#define   CCPACK7_1       ((unsigned int) 0x01 <<  24)   // 24:28    Control Packet 1
#define   CCPACK7_2       ((unsigned int) 0x02 <<  24)   // 24:28    Control Packet 2
#define   CCPACK7_4       ((unsigned int) 0x04 <<  24)   // 24:28    Control Packet 4
#define   CCPACK7_8       ((unsigned int) 0x08 <<  24)   // 24:28    Control Packet 8
#define   CCPACK7_16      ((unsigned int) 0x10 <<  24)   // 24:28    Control Packet 16
                                                         // 29       Reserved
#define   DMEN7           ((unsigned int) 0x01 <<  30)   // 30       DMA enable for the channel
                                                         // 31       Reserved

//-------------------------------------------------
// DMA Current Control Packet 2 Register
//
// DMACCP2_BITS
#define   CCPACK8_0       ((unsigned int) 0x00 <<  0)    // 0:4      Control Packet 0
#define   CCPACK8_1       ((unsigned int) 0x01 <<  0)    // 0:4      Control Packet 1
#define   CCPACK8_2       ((unsigned int) 0x02 <<  0)    // 0:4      Control Packet 2
#define   CCPACK8_4       ((unsigned int) 0x04 <<  0)    // 0:4      Control Packet 4
#define   CCPACK8_8       ((unsigned int) 0x08 <<  0)    // 0:4      Control Packet 8
#define   CCPACK8_16      ((unsigned int) 0x10 <<  0)    // 0:4      Control Packet 16
                                                         // 5        Reserved
#define   DMEN8           ((unsigned int) 0x01 <<  6)    // 6        DMA enable for the channel
                                                         // 7        Reserved
#define   CCPACK9_0       ((unsigned int) 0x00 <<  8)    // 8:12     Control Packet 0
#define   CCPACK9_1       ((unsigned int) 0x01 <<  8)    // 8:12     Control Packet 1
#define   CCPACK9_2       ((unsigned int) 0x02 <<  8)    // 8:12     Control Packet 2
#define   CCPACK9_4       ((unsigned int) 0x04 <<  8)    // 8:12     Control Packet 4
#define   CCPACK9_8       ((unsigned int) 0x08 <<  8)    // 8:12     Control Packet 8
#define   CCPACK9_16      ((unsigned int) 0x10 <<  8)    // 8:12     Control Packet 16
                                                         // 13       Reserved
#define   DMEN9           ((unsigned int) 0x01 <<  14    // 14       DMA enable for the channel
                                                         // 15       Reserved
#define   CCPACK10_0       ((unsigned int) 0x00 <<  16)  // 16:20    Control Packet 0
#define   CCPACK10_1       ((unsigned int) 0x01 <<  16)  // 16:20    Control Packet 1
#define   CCPACK10_2       ((unsigned int) 0x02 <<  16)  // 16:20    Control Packet 2
#define   CCPACK10_4       ((unsigned int) 0x04 <<  16)  // 16:20    Control Packet 4
#define   CCPACK10_8       ((unsigned int) 0x08 <<  16)  // 16:20    Control Packet 8
#define   CCPACK10_16      ((unsigned int) 0x10 <<  16)  // 16:20    Control Packet 16
                                                         // 21       Reserved
#define   DMEN10           ((unsigned int) 0x01 <<  22)  // 22       DMA enable for the channel
                                                         // 23       Reserved
#define   CCPACK11_0       ((unsigned int) 0x00 <<  24)  // 24:28    Control Packet 0
#define   CCPACK11_1       ((unsigned int) 0x01 <<  24)  // 24:28    Control Packet 1
#define   CCPACK11_2       ((unsigned int) 0x02 <<  24)  // 24:28    Control Packet 2
#define   CCPACK11_4       ((unsigned int) 0x04 <<  24)  // 24:28    Control Packet 4
#define   CCPACK11_8       ((unsigned int) 0x08 <<  24)  // 24:28    Control Packet 8
#define   CCPACK11_16      ((unsigned int) 0x10 <<  24)  // 24:28    Control Packet 16
                                                         // 29       Reserved
#define   DMEN11           ((unsigned int) 0x01 <<  30)  // 30       DMA enable for the channel
                                                         // 31       Reserved

//-------------------------------------------------
// DMA Current Control Packet 3 Register
//
// DMACCP3_BITS
#define   CCPACK12_0       ((unsigned int) 0x00 <<  0)   // 0:4      Control Packet 0
#define   CCPACK12_1       ((unsigned int) 0x01 <<  0)   // 0:4      Control Packet 1
#define   CCPACK12_2       ((unsigned int) 0x02 <<  0)   // 0:4      Control Packet 2
#define   CCPACK12_4       ((unsigned int) 0x04 <<  0)   // 0:4      Control Packet 4
#define   CCPACK12_8       ((unsigned int) 0x08 <<  0)   // 0:4      Control Packet 8
#define   CCPACK12_16      ((unsigned int) 0x10 <<  0)   // 0:4      Control Packet 16
                                                         // 5        Reserved
#define   DMEN12           ((unsigned int) 0x01 <<  6)   // 6        DMA enable for the channel
                                                         // 7        Reserved
#define   CCPACK13_0       ((unsigned int) 0x00 <<  8)   // 8:12     Control Packet 0
#define   CCPACK13_1       ((unsigned int) 0x01 <<  8)   // 8:12     Control Packet 1
#define   CCPACK13_2       ((unsigned int) 0x02 <<  8)   // 8:12     Control Packet 2
#define   CCPACK13_4       ((unsigned int) 0x04 <<  8)   // 8:12     Control Packet 4
#define   CCPACK13_8       ((unsigned int) 0x08 <<  8)   // 8:12     Control Packet 8
#define   CCPACK13_16      ((unsigned int) 0x10 <<  8)   // 8:12     Control Packet 16
                                                         // 13       Reserved
#define   DMEN13           ((unsigned int) 0x01 <<  14   // 14       DMA enable for the channel
                                                         // 15       Reserved
#define   CCPACK14_0       ((unsigned int) 0x00 <<  16)  // 16:20    Control Packet 0
#define   CCPACK14_1       ((unsigned int) 0x01 <<  16)  // 16:20    Control Packet 1
#define   CCPACK14_2       ((unsigned int) 0x02 <<  16)  // 16:20    Control Packet 2
#define   CCPACK14_4       ((unsigned int) 0x04 <<  16)  // 16:20    Control Packet 4
#define   CCPACK14_8       ((unsigned int) 0x08 <<  16)  // 16:20    Control Packet 8
#define   CCPACK14_16      ((unsigned int) 0x10 <<  16)  // 16:20    Control Packet 16
                                                         // 21       Reserved
#define   DMEN14           ((unsigned int) 0x01 <<  22)  // 22       DMA enable for the channel
                                                         // 23       Reserved
#define   CCPACK15_0       ((unsigned int) 0x00 <<  24)  // 24:28    Control Packet 0
#define   CCPACK15_1       ((unsigned int) 0x01 <<  24)  // 24:28    Control Packet 1
#define   CCPACK15_2       ((unsigned int) 0x02 <<  24)  // 24:28    Control Packet 2
#define   CCPACK15_4       ((unsigned int) 0x04 <<  24)  // 24:28    Control Packet 4
#define   CCPACK15_8       ((unsigned int) 0x08 <<  24)  // 24:28    Control Packet 8
#define   CCPACK15_16      ((unsigned int) 0x10 <<  24)  // 24:28    Control Packet 16
                                                         // 29       Reserved
#define   DMEN15           ((unsigned int) 0x01 <<  30)  // 30       DMA enable for the channel
                                                         // 31       Reserved


//===========================================================================
#ifdef __cplusplus
}       // end of extern "C"
#endif

#endif  // end of tms470r1b1m_bit_definitions

//===========================================================================
// End of file
//===========================================================================
