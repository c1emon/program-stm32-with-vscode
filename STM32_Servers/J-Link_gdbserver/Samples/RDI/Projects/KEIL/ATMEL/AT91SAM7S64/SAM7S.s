/***********************************************************************/
/*  This file is part of the CA ARM C Compiler package                 */
/*  Copyright KEIL ELEKTRONIK GmbH 2002-2005                           */
/***********************************************************************/
/*                                                                     */
/*  SAM7S.S:  Startup file for Atmel AT91SAM7S device series           */
/*                                                                     */
/***********************************************************************/


/* 
//*** <<< Use Configuration Wizard in Context Menu >>> *** 
*/


/*
 *  The STARTUP.S code is executed after CPU Reset. This file may be 
 *  translated with the following SET symbols. In uVision these SET 
 *  symbols are entered under Options - ASM - Set.
 *
 *  REMAP: when set the startup code remaps exception vectors from
 *  on-chip RAM to address 0.
 *
 *  RAM_INTVEC: when set the startup code copies exception vectors 
 *  from on-chip Flash to on-chip RAM.
 *
 *  RAM_MODE: when set the device is configured for code execution
 *  from on-chip RAM starting at address 0x00200000. The startup
 *  vectors are located to 0x00200000.
 */


// Standard definitions of Mode bits and Interrupt (I & F) flags in PSRs

        Mode_USR  EQU      0x10
        Mode_FIQ  EQU      0x11
        Mode_IRQ  EQU      0x12
        Mode_SVC  EQU      0x13
        Mode_ABT  EQU      0x17
        Mode_UND  EQU      0x1B
        Mode_SYS  EQU      0x1F

        I_Bit     EQU      0x80    /* when I bit is set, IRQ is disabled */
        F_Bit     EQU      0x40    /* when F bit is set, FIQ is disabled */


// Internal Memory Base Addresses
        FLASH_BASE      EQU     0x00100000   
        RAM_BASE        EQU     0x00200000


/*
// <h> Stack Configuration (Stack Sizes in Bytes)
//   <o0> Undefined Mode      <0x0-0xFFFFFFFF:4>
//   <o1> Supervisor Mode     <0x0-0xFFFFFFFF:4>
//   <o2> Abort Mode          <0x0-0xFFFFFFFF:4>
//   <o3> Fast Interrupt Mode <0x0-0xFFFFFFFF:4>
//   <o4> Interrupt Mode      <0x0-0xFFFFFFFF:4>
//   <o5> User/System Mode    <0x0-0xFFFFFFFF:4>
// </h>
*/
        UND_Stack_Size  EQU     0x00000004
        SVC_Stack_Size  EQU     0x00000004
        ABT_Stack_Size  EQU     0x00000004
        FIQ_Stack_Size  EQU     0x00000004
        IRQ_Stack_Size  EQU     0x00000080
        USR_Stack_Size  EQU     0x00000400

AREA   STACK, DATA, READWRITE, ALIGN=2
        DS   (USR_Stack_Size+3)&~3  ; Stack for User/System Mode 
        DS   (SVC_Stack_Size+3)&~3  ; Stack for Supervisor Mode
        DS   (IRQ_Stack_Size+3)&~3  ; Stack for Interrupt Mode
        DS   (FIQ_Stack_Size+3)&~3  ; Stack for Fast Interrupt Mode 
        DS   (ABT_Stack_Size+3)&~3  ; Stack for Abort Mode
        DS   (UND_Stack_Size+3)&~3  ; Stack for Undefined Mode
Top_Stack:


// Embedded Flash Controller (EFC) definitions
        EFC_BASE        EQU     0xFFFFFF00  /* EFC Base Address */
        EFC_FMR         EQU     0x60        /* EFC_FMR Offset */

/*
// <e> Embedded Flash Controller (EFC)
//   <o1.16..23> FMCN: Flash Microsecond Cycle Number <0-255>
//               <i> Number of Master Clock Cycles in 1us
//   <o1.8..9>   FWS: Flash Wait State
//               <0=> Read: 1 cycle / Write: 2 cycles
//               <1=> Read: 2 cycle / Write: 3 cycles
//               <2=> Read: 3 cycle / Write: 4 cycles
//               <3=> Read: 4 cycle / Write: 4 cycles
// </e>
*/
        EFC_SETUP       EQU     1
        EFC_FMR_Val     EQU     0x00320100


// Watchdog Timer (WDT) definitions
        WDT_BASE        EQU     0xFFFFFD40  /* WDT Base Address */
        WDT_MR          EQU     0x04        /* WDT_MR Offset */

/*
// <e> Watchdog Timer (WDT)
//   <o1.0..11>  WDV: Watchdog Counter Value <0-4095>
//   <o1.16..27> WDD: Watchdog Delta Value <0-4095>
//   <o1.12>     WDFIEN: Watchdog Fault Interrupt Enable
//   <o1.13>     WDRSTEN: Watchdog Reset Enable
//   <o1.14>     WDRPROC: Watchdog Reset Processor
//   <o1.28>     WDDBGHLT: Watchdog Debug Halt
//   <o1.29>     WDIDLEHLT: Watchdog Idle Halt
//   <o1.15>     WDDIS: Watchdog Disable
// </e>
*/
        WDT_SETUP       EQU     1
        WDT_MR_Val      EQU     0x00008000


// Power Mangement Controller (PMC) definitions
        PMC_BASE        EQU     0xFFFFFC00  /* PMC Base Address */
        PMC_MOR         EQU     0x20        /* PMC_MOR Offset */
        PMC_MCFR        EQU     0x24        /* PMC_MCFR Offset */
        PMC_PLLR        EQU     0x2C        /* PMC_PLLR Offset */
        PMC_MCKR        EQU     0x30        /* PMC_MCKR Offset */
        PMC_SR          EQU     0x68        /* PMC_SR Offset */
        PMC_MOSCEN      EQU     (1<<0)      /* Main Oscillator Enable */
        PMC_OSCBYPASS   EQU     (1<<1)      /* Main Oscillator Bypass */
        PMC_OSCOUNT     EQU     (0xFF<<8)   /* Main OScillator Start-up Time */
        PMC_DIV         EQU     (0xFF<<0)   /* PLL Divider */
        PMC_PLLCOUNT    EQU     (0x3F<<8)   /* PLL Lock Counter */
        PMC_OUT         EQU     (0x03<<14)  /* PLL Clock Frequency Range */
        PMC_MUL         EQU     (0x7FF<<16) /* PLL Multiplier */
        PMC_USBDIV      EQU     (0x03<<28)  /* USB Clock Divider */
        PMC_CSS         EQU     (3<<0)      /* Clock Source Selection */
        PMC_PRES        EQU     (7<<2)      /* Prescaler Selection */
        PMC_MOSCS       EQU     (1<<0)      /* Main Oscillator Stable */
        PMC_LOCK        EQU     (1<<2)      /* PLL Lock Status */

/*
// <e> Power Mangement Controller (PMC)
//   <h> Main Oscillator
//     <o1.0>      MOSCEN: Main Oscillator Enable
//     <o1.1>      OSCBYPASS: Oscillator Bypass
//     <o1.8..15>  OSCCOUNT: Main Oscillator Startup Time <0-255>
//   </h>
//   <h> Phase Locked Loop (PLL)
//     <o2.0..7>   DIV: PLL Divider <0-255>
//     <o2.16..26> MUL: PLL Multiplier <0-2047>
//                 <i> PLL Output is multiplied by MUL+1
//     <o2.14..15> OUT: PLL Clock Frequency Range
//                 <0=> 80..160MHz  <1=> Reserved
//                 <2=> 150..220MHz <3=> Reserved
//     <o2.8..13>  PLLCOUNT: PLL Lock Counter <0-63>
//     <o2.28..29> USBDIV: USB Clock Divider
//                 <0=> None  <1=> 2  <2=> 4  <3=> Reserved
//   </h>
//   <o3.0..1>   CSS: Clock Source Selection
//               <0=> Slow Clock
//               <1=> Main Clock
//               <2=> Reserved
//               <3=> PLL Clock
//   <o3.2..4>   PRES: Prescaler
//               <0=> None
//               <1=> Clock / 2    <2=> Clock / 4
//               <3=> Clock / 8    <4=> Clock / 16
//               <5=> Clock / 32   <6=> Clock / 64
//               <7=> Reserved
// </e>
*/
        PMC_SETUP       EQU     1
        PMC_MOR_Val     EQU     0x00000601
        PMC_PLLR_Val    EQU     0x00191C05
        PMC_MCKR_Val    EQU     0x00000007


$IF (RAM_INTVEC)
// Exception Vector Area in RAM
AREA   VECTORS, DATA, AT RAM_BASE
                DS      64
$ENDIF        


// Startup Code must be linked at address which it expects to run.

$IF (RAM_MODE)
        CODE_BASE       EQU     RAM_BASE
$ELSE
        CODE_BASE       EQU     FLASH_BASE
$ENDIF
									
AREA   STARTUPCODE, CODE, AT CODE_BASE
       PUBLIC  __startup

       EXTERN  CODE32 (?C?INIT)

__startup       PROC    CODE32

// Pre-defined interrupt handlers that may be directly 
// overwritten by C interrupt functions
EXTERN CODE32 (Undef_Handler?A)
EXTERN CODE32 (SWI_Handler?A)
EXTERN CODE32 (PAbt_Handler?A)
EXTERN CODE32 (DAbt_Handler?A)
; EXTERN CODE32 (IRQ_Handler?A)
; EXTERN CODE32 (FIQ_Handler?A)

// Exception Vectors
//  Mapped to Address 0.
//  Absolute addressing mode must be used.

Vectors:        LDR     PC,Reset_Addr         
                LDR     PC,Undef_Addr
                LDR     PC,SWI_Addr
                LDR     PC,PAbt_Addr
                LDR     PC,DAbt_Addr
                NOP                            /* Reserved Vector */
;               LDR     PC,IRQ_Addr
                LDR     PC,[PC,#-0xF20]        /* Vector From AIC_IVR */
;               LDR     PC,FIQ_Addr
                LDR     PC,[PC,#-0xF20]        /* Vector From AIC_FVR */

Reset_Addr:     DD      Reset_Handler
Undef_Addr:     DD      Undef_Handler?A
SWI_Addr:       DD      SWI_Handler?A
PAbt_Addr:      DD      PAbt_Handler?A
DAbt_Addr:      DD      DAbt_Handler?A
                DD      0                      /* Reserved Address */
;IRQ_Addr:      DD      IRQ_Handler?A
IRQ_Addr:       DD      0
;FIQ_Addr:      DD      FIQ_Handler?A
FIQ_Addr:       DD      0


// Reset Handler

Reset_Handler:  


// Setup EFC
IF (EFC_SETUP != 0)
                LDR     R0, =EFC_BASE
                LDR     R1, =EFC_FMR_Val
                STR     R1, [R0, #EFC_FMR]
ENDIF


// Setup WDT
IF (WDT_SETUP != 0)
                LDR     R0, =WDT_BASE
                LDR     R1, =WDT_MR_Val
                STR     R1, [R0, #WDT_MR]
ENDIF


// Setup PMC
IF (PMC_SETUP != 0)
                LDR     R0, =PMC_BASE

//  Setup Main Oscillator
                LDR     R1, =PMC_MOR_Val
                STR     R1, [R0, #PMC_MOR]

//  Wait until Main Oscillator is stablilized
IF ((PMC_MOR_Val & PMC_MOSCEN) != 0)
MOSCS_Loop:     LDR     R2, [R0, #PMC_SR]
                ANDS    R2, R2, #PMC_MOSCS
                BEQ     MOSCS_Loop
ENDIF

//  Setup the PLL
IF ((PMC_PLLR_Val & PMC_MUL) != 0)
                LDR     R1, =PMC_PLLR_Val
                STR     R1, [R0, #PMC_PLLR]

//  Wait until PLL is stabilized
PLL_Loop:       LDR     R2, [R0, #PMC_SR]
                ANDS    R2, R2, #PMC_LOCK
                BEQ     PLL_Loop
ENDIF

//  Select Clock
                LDR     R1, =PMC_MCKR_Val
                STR     R1, [R0, #PMC_MCKR]
ENDIF


// Copy Exception Vectors to Internal RAM

$IF (RAM_INTVEC)
                ADR     R8, Vectors         ; Source
                LDR     R9, =RAM_BASE       ; Destination
                LDMIA   R8!, {R0-R7}        ; Load Vectors 
                STMIA   R9!, {R0-R7}        ; Store Vectors 
                LDMIA   R8!, {R0-R7}        ; Load Handler Addresses 
                STMIA   R9!, {R0-R7}        ; Store Handler Addresses
$ENDIF


// Remap on-chip RAM to address 0

                MC_BASE EQU  0xFFFFFF00  /* MC Base Address */
                MC_RCR  EQU  0x00        /* MC_RCR Offset */

$IF (REMAP)                 
                LDR     R0, =MC_BASE
                MOV     R1, #1
                STR     R1, [R0, #MC_RCR]   ; Remap
$ENDIF


// Setup Stack for each mode
                LDR     R0, =Top_Stack

// Enter Undefined Instruction Mode and set its Stack Pointer
                MSR     CPSR_c, #Mode_UND|I_Bit|F_Bit
                MOV     SP, R0
                SUB     R0, R0, #UND_Stack_Size

// Enter Abort Mode and set its Stack Pointer
                MSR     CPSR_c, #Mode_ABT|I_Bit|F_Bit
                MOV     SP, R0
                SUB     R0, R0, #ABT_Stack_Size

// Enter FIQ Mode and set its Stack Pointer
                MSR     CPSR_c, #Mode_FIQ|I_Bit|F_Bit
                MOV     SP, R0
                SUB     R0, R0, #FIQ_Stack_Size

// Enter IRQ Mode and set its Stack Pointer
                MSR     CPSR_c, #Mode_IRQ|I_Bit|F_Bit
                MOV     SP, R0
                SUB     R0, R0, #IRQ_Stack_Size

// Enter Supervisor Mode and set its Stack Pointer
                MSR     CPSR_c, #Mode_SVC|I_Bit|F_Bit
                MOV     SP, R0
                SUB     R0, R0, #SVC_Stack_Size

// Enter User Mode and set its Stack Pointer
                MSR     CPSR_c, #Mode_USR
                MOV     SP, R0

// Enter the C code
                LDR     R0,=?C?INIT
                TST     R0,#1       ; Bit-0 set: main is Thumb
                LDREQ   LR,=exit?A  ; ARM Mode
                LDRNE   LR,=exit?T  ; Thumb Mode
                BX      R0
                ENDP

PUBLIC exit?A
exit?A          PROC    CODE32
                B       exit?A
                ENDP

PUBLIC exit?T
exit?T          PROC    CODE16
                B       exit?T
                ENDP

                END
