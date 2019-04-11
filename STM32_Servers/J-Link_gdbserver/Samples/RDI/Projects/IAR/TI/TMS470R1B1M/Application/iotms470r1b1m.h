/***************************************************************************
 **
 **    This file defines the Special Function Registers for
 **    Texas Instruments TMS470R1B1M
 **
 **    Used with ARM IAR C/C++ Compiler and Assembler.
 **
 **    (c) Copyright IAR Systems 2005
 **
 **    $Revision: 1.4 $
 **
 **    $Revision: 1.4 $  jm
***************************************************************************/

#ifndef __IOTMS470R1B1M_H
#define __IOTMS470R1B1M_H

#if (((__TID__ >> 8) & 0x7F) != 0x4F)     /* 0x4F = 79 dec */
#error This file should only be compiled by ARM IAR compiler and assembler
#endif

#include "io_macros.h"

/***************************************************************************
 ***************************************************************************
 **
 **    TMS470R1B1M SPECIAL FUNCTION REGISTERS
 **
 ***************************************************************************
***************************************************************************/

/* C-compiler specific declarations **********************************************/

#ifdef __IAR_SYSTEMS_ICC__

#ifndef _SYSTEM_BUILD
  #pragma system_include
#endif

#if __LITTLE_ENDIAN__ == 1
#error This file should only be compiled in big endian mode
#endif

/* MPU - MPU control register */
typedef struct {
  __REG32 CHAN0Special    :1;
  __REG32 CHAN0EN         :1;
  __REG32 CHAN0PRIV       :1;
  __REG32 CHAN0RONLY      :1;
  __REG32 CHAN1Special    :1;
  __REG32 CHAN1EN         :1;
  __REG32 CHAN1PRIV       :1;
  __REG32 CHAN1RONLY      :1;
  __REG32 CHAN2Special    :1;
  __REG32 CHAN2EN         :1;
  __REG32 CHAN2PRIV       :1;
  __REG32 CHAN2RONLY      :1;
  __REG32 CHAN3Special    :1;
  __REG32 CHAN3EN         :1;
  __REG32 CHAN3PRIV       :1;
  __REG32 CHAN3RONLY      :1;
  __REG32                 :16;
} __mpuctrl_bits;

/* MPU - MPUAHR MPU Address High Register */
typedef struct {
  __REG32 UPPERBOUND      :16;
  __REG32                 :16;
} __mpuahr_bits;

/* MPU - MPUALR MPU Address Low Register */
typedef struct {
  __REG32 LOWERBOUND      :16;
  __REG32 EQUAL           :3;
  __REG32                 :13;
} __mpualr_bits;

/* SMC - Static memory control register 0 */
typedef struct {
  __REG32 DW              :2;
  __REG32                 :1;
  __REG32 END             :1;
  __REG32 WS              :4;
  __REG32                 :1;
  __REG32 TWS             :3;
  __REG32 ASC             :2;
  __REG32                 :18;
} __smcr0_bits;

/* SMC - Static memory control registers 1 - 9 */
typedef struct {
  __REG32 DW              :2;
  __REG32 MLOC            :1;
  __REG32 END             :1;
  __REG32 WS              :4;
  __REG32                 :1;
  __REG32 TWS             :3;
  __REG32 ASC             :2;
  __REG32                 :18;
} __smcrx_bits;

/* SMC - Write control register */
typedef struct {
  __REG32 WBENABLE        :1;
  __REG32 WTWSOVR         :1;
  __REG32                 :30;
} __wcr_bits;

/* SMC - Peripheral location register */
typedef struct {
  __REG32 PLOC0           :1;
  __REG32 PLOC1           :1;
  __REG32 PLOC2           :1;
  __REG32 PLOC3           :1;
  __REG32 PLOC4           :1;
  __REG32 PLOC5           :1;
  __REG32 PLOC6           :1;
  __REG32 PLOC7           :1;
  __REG32 PLOC8           :1;
  __REG32 PLOC9           :1;
  __REG32 PLOC10          :1;
  __REG32 PLOC11          :1;
  __REG32 PLOC12          :1;
  __REG32 PLOC13          :1;
  __REG32 PLOC14          :1;
  __REG32 PLOC15          :1;
  __REG32                 :16;
} __plr_bits;

/* SMC - Peripheral protection register */
typedef struct {
  __REG32 PPROT0           :1;
  __REG32 PPROT1           :1;
  __REG32 PPROT2           :1;
  __REG32 PPROT3           :1;
  __REG32 PPROT4           :1;
  __REG32 PPROT5           :1;
  __REG32 PPROT6           :1;
  __REG32 PPROT7           :1;
  __REG32 PPROT8           :1;
  __REG32 PPROT9           :1;
  __REG32 PPROT10          :1;
  __REG32 PPROT11          :1;
  __REG32 PPROT12          :1;
  __REG32 PPROT13          :1;
  __REG32 PPROT14          :1;
  __REG32 PPROT15          :1;
  __REG32                 :16;
} __pprot_bits;

/* SMC - Memory Fine Base Address High Registers */
typedef struct {
  __REG32 Address31_16    :16;
  __REG32                 :16;
} __mfbahr_bits;

/* SMC - Memory Fine Base Address Low Registers 0 */
typedef struct {
  __REG32 PRIV            :1;
  __REG32 RONLY           :1;
  __REG32                 :2;
  __REG32 BlockSize       :4;
  __REG32 MS              :1;
  __REG32                 :1;
  __REG32 Address15_10    :6;
  __REG32                 :16;
} __mfbalr0_bits;

/* SMC - Memory Fine Base Address Low Registers 1 - 9 */
typedef struct {
  __REG32 PRIV            :1;
  __REG32 RONLY           :1;
  __REG32                 :2;
  __REG32 BlockSize       :4;
  __REG32                 :1;
  __REG32 AW              :1;
  __REG32 Address15_10    :6;
  __REG32                 :16;
} __mfbalrx_bits;

/* SMC - Memory Coarse Base Address High Registers */
typedef struct {
  __REG32 Address31_16    :16;
  __REG32                 :16;
} __mcbahr_bits;

/* SMC - Memory Coarse Base Address Low Registers */
typedef struct {
  __REG32 PRIV            :1;
  __REG32 RONLY           :1;
  __REG32                 :2;
  __REG32 BlockSize       :4;
  __REG32                 :1;
  __REG32 AW              :1;
  __REG32                 :5;
  __REG32 Address15       :1;
  __REG32                 :16;
} __mcbalr_bits;

/* SMC - RTI Counter */
typedef struct {
  __REG32 MOD10_0         :11;
  __REG32 CNTR20_0        :21;
} __rticntr_bits;

/* SMC - RTI Preload Control Register */
typedef struct {
  __REG32 PRELD10_0       :11;
  __REG32 RTIM2_0         :3;
  __REG32                 :18;
} __rtipctl_bits;

/* RTI Control Register */
typedef struct {
  __REG32                 :6;
  __REG32 TAPENA          :1;
  __REG32 TAPFLAG         :1;
  __REG32                 :24;
} __rticntl_bits;

/* RTI Compare Register1 */
typedef struct {
  __REG32 COMPARE1_20_0   :21;
  __REG32                 :11;
} __rticmp1_bits;

/* SMC - RTI Compare Register2 */
typedef struct {
  __REG32 COMPARE2_20_0   :21;
  __REG32                 :11;
} __rticmp2_bits;

/* SMC - RTI Compare Interrupt Control Register */
typedef struct {
  __REG32                 :4;
  __REG32 CMP2ENA         :1;
  __REG32 CMP1ENA         :1;
  __REG32 CMP2FLAG        :1;
  __REG32 CMP1FLAG        :1;
  __REG32                 :24;
} __rticint_bits;

/* SMC - RTICNTEN RTI Count Enable Register */
typedef struct {
  __REG32 CNTEN           :2;
  __REG32                 :30;
} __rticnten_bits;

/* SMC - IRQIVEC IRQ Index Offset Vector Register */
typedef struct {
  __REG32 IRQIVEC_7_0     :8;
  __REG32                 :24;
} __irqivec_bits;

/* SMC - FIQIVEC FIQ Index Offset Vector Registers */
typedef struct {
  __REG32 FIQIVEC_7_0     :8;
  __REG32                 :24;
} __fiqivec_bits;

/* SMC - CIMIVEC CIM Index Offset Vector Register */
typedef struct {
  __REG32 CIMIVEC_7_0     :8;
  __REG32                 :24;
} __cimivec_bits;

/* SMC - SSIF System Software Interrupt Flag Register */
typedef struct {
  __REG32 SSIF            :1;
  __REG32                 :31;
} __ssif_bits;

/* SMC - SSIR System Software Interrupt Request Register */
typedef struct {
  __REG32 SSDATA_7_0      :8;
  __REG32 SSKEY_7_0       :8;
  __REG32                 :16;
} __ssir_bits;

/* SMC - PSAENABLE PSA Enable */
typedef struct {
  __REG32 PSADIS          :1;
  __REG32                 :31;
} __psaenable_bits;

/* SMC - Peripheral clock register */
typedef struct {
  __REG32 PENABLE         :1;
  __REG32 CLKDIV          :4;
  __REG32                 :27;
} __pcr_bits;

/* SMC - CLKCNTL Clock Control Register */
typedef struct {
  __REG32 LPM             :2;
  __REG32 CLK_DIN         :1;
  __REG32 CLK_DOUT        :1;
  __REG32 CLK_DIR         :1;
  __REG32 CLKSR           :2;
  __REG32 PPW_NOVR        :1;
  __REG32                 :24;
} __clkcntl_bits;

/* SMC - GCR Global Control Register (old name GLBCTRL) */
typedef struct {
  __REG32 CLK_DIV_PRE     :3;
  __REG32 MULT4           :1;
  __REG32 FLCONFIG        :1;
  __REG32                 :9;
  __REG32 RTI_CTRL        :1;
  __REG32 RST_OSC_FAIL_EN :1;
  __REG32                 :16;
} __gcr_bits;

/* SMC - GCR_N Global Control Register JM */
typedef struct {
  __REG32                 :18;
  __REG32 FMENA           :1;
  __REG32 DMOD            :6;
  __REG32 MUL             :2;
  __REG32                 :1;
  __REG32 DEPTH           :2;
  __REG32                 :2;
} __gcr_n_bits;

/* SMC - SYSECR System Exception Control Register */
typedef struct {
  __REG32 ILL_OVR         :1;
  __REG32 ACC_OVR         :1;
  __REG32 PACC_OVR        :1;
  __REG32                 :11;
  __REG32 RESET           :2;
  __REG32                 :16;
} __sysecr_bits;

/* SMC - SYSESR System Reset Exception Status Register */
typedef struct {
  __REG32                 :7;
  __REG32 SW_RST          :1;
  __REG32 ILL_MAP         :1;
  __REG32 PILL_ACC        :1;
  __REG32 ILL_ACC         :1;
  __REG32 ILL_ADR         :1;
  __REG32 ILL_MODE        :1;
  __REG32 WD_RST          :1;
  __REG32 CLK_RST         :1;
  __REG32 POR_RST         :1;
  __REG32                 :16;
} __sysesr_bits;

/* SMC - ABRTESR Abort Exception Status Register */
typedef struct {
  __REG32                 :13;
  __REG32 PACC_VIO        :1;
  __REG32 MEM_ABT         :1;
  __REG32 ADR_ABT         :1;
  __REG32                 :16;
} __abrtesr_bits;

/* SMC - GLBSTAT Global Status Register */
typedef struct {
  __REG32 PLL_SLIP        :1;
  __REG32 OSC_FAIL        :1;
  __REG32                 :2;
  __REG32 MPU_ACC         :1;
  __REG32 MPU_ADDR        :1;
  __REG32 SYS_ACC         :1;
  __REG32 SYS_ADDR        :1;
  __REG32                 :24;
} __glbstat_bits;

/* SMC - DEV Device Identification Register */
typedef struct {
  __REG32 DEV_15_0        :16;
  __REG32                 :16;
} __dev_bits;

/* IEM - Interrupt Pending Register 0 (INTPEND0) */
typedef struct {
  __REG32 INTPEND0  : 1;
  __REG32 INTPEND1  : 1;
  __REG32 INTPEND2  : 1;
  __REG32 INTPEND3  : 1;
  __REG32 INTPEND4  : 1;
  __REG32 INTPEND5  : 1;
  __REG32 INTPEND6  : 1;
  __REG32 INTPEND7  : 1;
  __REG32 INTPEND8  : 1;
  __REG32 INTPEND9  : 1;
  __REG32 INTPEND10 : 1;
  __REG32 INTPEND11 : 1;
  __REG32 INTPEND12 : 1;
  __REG32 INTPEND13 : 1;
  __REG32 INTPEND14 : 1;
  __REG32 INTPEND15 : 1;
  __REG32 INTPEND16 : 1;
  __REG32 INTPEND17 : 1;
  __REG32 INTPEND18 : 1;
  __REG32 INTPEND19 : 1;
  __REG32 INTPEND20 : 1;
  __REG32 INTPEND21 : 1;
  __REG32 INTPEND22 : 1;
  __REG32 INTPEND23 : 1;
  __REG32 INTPEND24 : 1;
  __REG32 INTPEND25 : 1;
  __REG32 INTPEND26 : 1;
  __REG32 INTPEND27 : 1;
  __REG32 INTPEND28 : 1;
  __REG32 INTPEND29 : 1;
  __REG32 INTPEND30 : 1;
  __REG32 INTPEND31 : 1;
} __intpend0_bits;

/* IEM - Interrupt Pending Register 1 (INTPEND1) */
typedef struct {
  __REG32 INTPEND32  : 1;
  __REG32 INTPEND33 : 1;
  __REG32 INTPEND34 : 1;
  __REG32 INTPEND35 : 1;
  __REG32 INTPEND36 : 1;
  __REG32 INTPEND37 : 1;
  __REG32 INTPEND38 : 1;
  __REG32 INTPEND39 : 1;
  __REG32 INTPEND40 : 1;
  __REG32 INTPEND41 : 1;
  __REG32 INTPEND42 : 1;
  __REG32 INTPEND43 : 1;
  __REG32 INTPEND44 : 1;
  __REG32 INTPEND45 : 1;
  __REG32 INTPEND46 : 1;
  __REG32 INTPEND47 : 1;
  __REG32 INTPEND48 : 1;
  __REG32 INTPEND49 : 1;
  __REG32 INTPEND50 : 1;
  __REG32 INTPEND51 : 1;
  __REG32 INTPEND52 : 1;
  __REG32 INTPEND53 : 1;
  __REG32 INTPEND54 : 1;
  __REG32 INTPEND55 : 1;
  __REG32 INTPEND56 : 1;
  __REG32 INTPEND57 : 1;
  __REG32 INTPEND58 : 1;
  __REG32 INTPEND59 : 1;
  __REG32 INTPEND60 : 1;
  __REG32 INTPEND61 : 1;
  __REG32 INTPEND62 : 1;
  __REG32 INTPEND63 : 1;
} __intpend1_bits;

/* IEM - Interrupt Control Register 0 (INTCTRL0) */
typedef struct {
  __REG32 INTMAP3 : 5;
  __REG32         : 3;
  __REG32 INTMAP2 : 5;
  __REG32         : 3;
  __REG32 INTMAP1 : 5;
  __REG32         : 3;
  __REG32 INTMAP0 : 5;
  __REG32         : 3;
} __intctrl0_bits;

/* IEM - Interrupt Control Register 1 (INTCTRL1) */
typedef struct {
  __REG32 INTMAP7 : 5;
  __REG32         : 3;
  __REG32 INTMAP6 : 5;
  __REG32         : 3;
  __REG32 INTMAP5 : 5;
  __REG32         : 3;
  __REG32 INTMAP4 : 5;
  __REG32         : 3;
} __intctrl1_bits;

/* IEM - Interrupt Control Register 2 (INTCTRL2) */
typedef struct {
  __REG32 INTMAP11  : 5;
  __REG32           : 3;
  __REG32 INTMAP10  : 5;
  __REG32           : 3;
  __REG32 INTMAP9   : 5;
  __REG32           : 3;
  __REG32 INTMAP8   : 5;
  __REG32           : 3;
} __intctrl2_bits;

/* IEM - Interrupt Control Register 3 (INTCTRL3) */
typedef struct {
  __REG32 INTMAP15  : 5;
  __REG32           : 3;
  __REG32 INTMAP14  : 5;
  __REG32           : 3;
  __REG32 INTMAP13  : 5;
  __REG32           : 3;
  __REG32 INTMAP12  : 5;
  __REG32           : 3;
} __intctrl3_bits;

/* IEM - Interrupt Control Register 4 (INTCTRL4) */
typedef struct {
  __REG32 INTMAP19  : 5;
  __REG32           : 3;
  __REG32 INTMAP18  : 5;
  __REG32           : 3;
  __REG32 INTMAP17  : 5;
  __REG32           : 3;
  __REG32 INTMAP16  : 5;
  __REG32           : 3;
} __intctrl4_bits;

/* IEM - Interrupt Control Register 5 (INTCTRL5) */
typedef struct {
  __REG32 INTMAP23  : 5;
  __REG32           : 3;
  __REG32 INTMAP22  : 5;
  __REG32           : 3;
  __REG32 INTMAP21  : 5;
  __REG32           : 3;
  __REG32 INTMAP20  : 5;
  __REG32           : 3;
} __intctrl5_bits;

/* IEM - Interrupt Control Register 6 (INTCTRL6) */
typedef struct {
  __REG32 INTMAP27  : 5;
  __REG32           : 3;
  __REG32 INTMAP26  : 5;
  __REG32           : 3;
  __REG32 INTMAP25  : 5;
  __REG32           : 3;
  __REG32 INTMAP24  : 5;
  __REG32           : 3;
} __intctrl6_bits;

/* IEM - Interrupt Control Register 7 (INTCTRL7) */
typedef struct {
  __REG32 INTMAP31  : 5;
  __REG32           : 3;
  __REG32 INTMAP30  : 5;
  __REG32           : 3;
  __REG32 INTMAP29  : 5;
  __REG32           : 3;
  __REG32 INTMAP28  : 5;
  __REG32           : 3;
} __intctrl7_bits;

/* IEM - Interrupt Control Register 8 (INTCTRL8) */
typedef struct {
  __REG32 INTMAP35  : 5;
  __REG32           : 3;
  __REG32 INTMAP34  : 5;
  __REG32           : 3;
  __REG32 INTMAP33  : 5;
  __REG32           : 3;
  __REG32 INTMAP32  : 5;
  __REG32           : 3;
} __intctrl8_bits;

/* IEM - Interrupt Control Register 9 (INTCTRL9) */
typedef struct {
  __REG32 INTMAP39  : 5;
  __REG32           : 3;
  __REG32 INTMAP38  : 5;
  __REG32           : 3;
  __REG32 INTMAP37  : 5;
  __REG32           : 3;
  __REG32 INTMAP36  : 5;
  __REG32           : 3;
} __intctrl9_bits;

/* IEM - Interrupt Control Register 10 (INTCTRL10) */
typedef struct {
  __REG32 INTMAP43  : 5;
  __REG32           : 3;
  __REG32 INTMAP42  : 5;
  __REG32           : 3;
  __REG32 INTMAP41  : 5;
  __REG32           : 3;
  __REG32 INTMAP40  : 5;
  __REG32           : 3;
} __intctrl10_bits;

/* IEM - Interrupt Control Register 11 (INTCTRL11) */
typedef struct {
  __REG32 INTMAP47  : 5;
  __REG32           : 3;
  __REG32 INTMAP46  : 5;
  __REG32           : 3;
  __REG32 INTMAP45  : 5;
  __REG32           : 3;
  __REG32 INTMAP44  : 5;
  __REG32           : 3;
} __intctrl11_bits;

/* IEM - Interrupt Control Register 12 (INTCTRL12) */
typedef struct {
  __REG32 INTMAP51  : 5;
  __REG32           : 3;
  __REG32 INTMAP50  : 5;
  __REG32           : 3;
  __REG32 INTMAP49  : 5;
  __REG32           : 3;
  __REG32 INTMAP48  : 5;
  __REG32           : 3;
} __intctrl12_bits;

/* IEM - Interrupt Control Register 13 (INTCTRL13) */
typedef struct {
  __REG32 INTMAP55  : 5;
  __REG32           : 3;
  __REG32 INTMAP54  : 5;
  __REG32           : 3;
  __REG32 INTMAP53  : 5;
  __REG32           : 3;
  __REG32 INTMAP52  : 5;
  __REG32           : 3;
} __intctrl13_bits;

/* IEM - Interrupt Control Register 14 (INTCTRL14) */
typedef struct {
  __REG32 INTMAP59  : 5;
  __REG32           : 3;
  __REG32 INTMAP58  : 5;
  __REG32           : 3;
  __REG32 INTMAP57  : 5;
  __REG32           : 3;
  __REG32 INTMAP56  : 5;
  __REG32           : 3;
} __intctrl14_bits;

/* IEM - Interrupt Control Register 15 (INTCTRL15) */
typedef struct {
  __REG32 INTMAP63  : 5;
  __REG32           : 3;
  __REG32 INTMAP62  : 5;
  __REG32           : 3;
  __REG32 INTMAP61  : 5;
  __REG32           : 3;
  __REG32 INTMAP60  : 5;
  __REG32           : 3;
} __intctrl15_bits;

/* MSM - Status and Control Register (MSMSCR) */
typedef struct {
  __REG32 SEC       : 1;
  __REG32           :30;
  __REG32 FORCESEC  : 1;
} __msmscr_bits;

/* HET - HETGCR Global Configuration Register */
typedef struct {
  __REG32 ON              :1;
  __REG32 IGNORE_SUSPEND  :1;
  __REG32 DEBUG_STATUS    :1;
  __REG32                 :5;
  __REG32 ACCESS64        :1;
  __REG32                 :7;
  __REG32 CLK_MASTER      :1;
  __REG32                 :7;
  __REG32 POWER_DOWN      :1;
  __REG32                 :7;
} __hetgcr_bits;

/* HET - HETPFR Prescale Factor Register */
typedef struct {
  __REG32 HRPRES_FACTOR   :6;
  __REG32                 :2;
  __REG32 LRPRES_FACTOR   :3;
  __REG32                 :21;
} __hetpfr_bits;

/* HET - HETADDR HET Current Address Register */
typedef struct {
  __REG32 HETADDR         :8;
  __REG32                 :24;
} __hetaddr_bits;

/* HET - HETOFF Offset Level Register */
typedef struct {
  __REG32 OFFSET          :8;
  __REG32                 :24;
} __hetoff_bits;

/* HET - HETEXC1 Exception Control Register 1 */
typedef struct {
  __REG32 PRGM_OVRFL_PRY  :1;
  __REG32 APCNT_UNDRFL_PRY:1;
  __REG32 APCNT_OVRFL_PRY :1;
  __REG32                 :5;
  __REG32 PRGM_OVRFL_ENA  :1;
  __REG32                 :7;
  __REG32 APCNT_UNDRFL_ENA:1;
  __REG32                 :7;
  __REG32 APCNT_OVRFL_ENA :1;
  __REG32                 :7;
} __hetexc1_bits;

/* HET - HETEXC2 Exception Control Register 2 */
typedef struct {
  __REG32 PRGM_OVRFL_FLG  :1;
  __REG32 APCNT_UNDRFL_FLG:1;
  __REG32 APCNT_OVRFL_FLG :1;
  __REG32                 :29;
} __hetexc2_bits;

/* HET - HETHRSH HR Share Control Register */
typedef struct {
  __REG32 HR_SHARE_0_1    :1;
  __REG32 HR_SHARE_2_3    :1;
  __REG32 HR_SHARE_4_5    :1;
  __REG32 HR_SHARE_6_7    :1;
  __REG32 HR_SHARE_8_9    :1;
  __REG32 HR_SHARE_10_11  :1;
  __REG32 HR_SHARE_12_13  :1;
  __REG32 HR_SHARE_14_15  :1;
  __REG32 HR_SHARE_16_17  :1;
  __REG32 HR_SHARE_18_19  :1;
  __REG32 HR_SHARE_20_21  :1;
  __REG32 HR_SHARE_22_23  :1;
  __REG32                 :20;
} __hethrsh_bits;

/* HET - HETXOR HR XOR Control Register */
typedef struct {
  __REG32 HR_XOR_SHARE_0_1  :1;
  __REG32 HR_XOR_SHARE_2_3  :1;
  __REG32 HR_XOR_SHARE_4_5  :1;
  __REG32 HR_XOR_SHARE_6_7  :1;
  __REG32 HR_XOR_SHARE_8_9  :1;
  __REG32 HR_XOR_SHARE_10_11:1;
  __REG32 HR_XOR_SHARE_12_13:1;
  __REG32 HR_XOR_SHARE_14_15:1;
  __REG32 HR_XOR_SHARE_16_17:1;
  __REG32 HR_XOR_SHARE_18_19:1;
  __REG32 HR_XOR_SHARE_20_21:1;
  __REG32 HR_XOR_SHARE_22_23:1;
  __REG32                   :20;
} __hetxor_bits;

/* SPI - SPICTRL1 SPI Control Register 1 */
typedef struct {
  __REG32 CHARLEN         :5;
  __REG32 PRESCALE        :8;
  __REG32                 :19;
} __spictrl1_bits;

/* SPI - SPICTRL2 SPI Control Register 2 */
typedef struct {
  __REG32 PHASE           :1;
  __REG32 POLARITY        :1;
  __REG32 PWRDN           :1;
  __REG32 MASTER          :1;
  __REG32 SPIEN           :1;
  __REG32 CLKMOD          :1;
  __REG32                 :26;
} __spictrl2_bits;

/* SPI - SPICTRL3 SPI Control Register 3 */
typedef struct {
  __REG32 RXINTFLAG       :1;
  __REG32 RXINTEN         :1;
  __REG32 RCVR_OVRN       :1;
  __REG32 OVRNINTEN       :1;
  __REG32                 :1;
  __REG32 ENABLE_HIGH_Z   :1;
  __REG32                 :26;
} __spictrl3_bits;

/* SPI - SPIDAT1 SPI Shift Register 0 */
typedef struct {
  __REG32 SPIDAT0         :16;
  __REG32                 :16;
} __spidat0_bits;

/* SPI - SPIDAT1 SPI Shift Register 1 */
typedef struct {
  __REG32 SPIDAT1         :16;
  __REG32                 :16;
} __spidat1_bits;

/* SPI - SPIBUF SPI Buffer Register */
typedef struct {
  __REG32 SPIBUF          :16;
  __REG32 RXINTFLAG_IMG   :1;
  __REG32 RCVR_OVRN_IMG   :1;
  __REG32                 :14;
} __spibuf_bits;

/* SPI - SPIEMU SPI Emulation Register */
typedef struct {
  __REG32 SPIEMU          :16;
  __REG32                 :16;
} __spiemu_bits;

/* SPI - SPIPC1 SPI Pin Control Register 1 */
typedef struct {
  __REG32 ENA_DIR         :1;
  __REG32 CLK_DIR         :1;
  __REG32 SIMO_DIR        :1;
  __REG32 SOMI_DIR        :1;
  __REG32 SCS_DIR         :1;
  __REG32                 :27;
} __spipc1_bits;

/* SPI - SPIPC2 SPI Pin Control Register 2 */
typedef struct {
  __REG32 ENA_DIN         :1;
  __REG32 CLK_DIN         :1;
  __REG32 SIMO_DIN        :1;
  __REG32 SOMI_DIN        :1;
  __REG32 SCS_DIN         :1;
  __REG32                 :27;
} __spipc2_bits;

/* SPI - SPIPC3 SPI Pin Control Register 3 */
typedef struct {
  __REG32 ENA_DOUT        :1;
  __REG32 CLK_DOUT        :1;
  __REG32 SIMO_DOUT       :1;
  __REG32 SOMI_DOUT       :1;
  __REG32 SCS_DOUT        :1;
  __REG32                 :27;
} __spipc3_bits;

/* SPI - SPIPC4 SPI Pin Control Register 4 */
typedef struct {
  __REG32 ENA_DSET        :1;
  __REG32 CLK_DSET        :1;
  __REG32 SIMO_DSET       :1;
  __REG32 SOMI_DSET       :1;
  __REG32 SCS_DSET        :1;
  __REG32                 :27;
} __spipc4_bits;

/* SPI - SPIPC5 SPI Pin Control Register 5 */
typedef struct {
  __REG32 ENA_DCLR        :1;
  __REG32 CLK_DCLR        :1;
  __REG32 SIMO_DCLR       :1;
  __REG32 SOMI_DCLR       :1;
  __REG32 SCS_DCLR        :1;
  __REG32                 :27;
} __spipc5_bits;

/* SPI - SPIPC6 SPI Pin Control Register 6 */
typedef struct {
  __REG32 ENA_FUN         :1;
  __REG32 CLK_FUN         :1;
  __REG32 SIMO_FUN        :1;
  __REG32 SOMI_FUN        :1;
  __REG32 SCS_FUN         :1;
  __REG32                 :27;
} __spipc6_bits;

/* SCI - SCICCR Communication Control Register */
typedef struct {
  __REG8 CHAR0           :1;
  __REG8 CHAR1           :1;
  __REG8 CHAR2           :1;
  __REG8 COMM_MODE       :1;
  __REG8 TIMING_MODE     :1;
  __REG8 PARITY_ENA      :1;
  __REG8 PARITY          :1;
  __REG8 STOP            :1;
} __sciccr_bits;

/* SCI - SCICTL1 SCI Control Register 1 */
typedef struct {
  __REG8 RXENA           :1;
  __REG8 RXWAKE          :1;
  __REG8 RXRDY           :1;
  __REG8 SLEEP           :1;
  __REG8 IDLE            :1;
  __REG8                 :3;
} __scictl1_bits;

/* SCI - SCICTL2 SCI Control Register 2 */
typedef struct {
  __REG8 TXENA           :1;
  __REG8 TXWAKE          :1;
  __REG8 TXRDY           :1;
  __REG8 TX_EMPTY        :1;
  __REG8                 :2;
  __REG8 LOOP_BACK       :1;
  __REG8 CONT            :1;
} __scictl2_bits;

/* SCI - SCICTL3 SCI Control Register 3 */
typedef struct {
  __REG8 RXERR_INT_ENA   :1;
  __REG8 BRKDT_INT_ENA   :1;
  __REG8 WAKEUP_INT_ENA  :1;
  __REG8 TX_ACTION_ENA   :1;
  __REG8 RX_ACTION_ENA   :1;
  __REG8 CLOCK           :1;
  __REG8 POWER_DOWN      :1;
  __REG8 SW_RESET        :1;
} __scictl3_bits;

/* SCI - SCIRXST Receiver Status Register */
typedef struct {
  __REG8 RXERR           :1;
  __REG8 BRKDT           :1;
  __REG8 WAKEUP          :1;
  __REG8 PE              :1;
  __REG8 OE              :1;
  __REG8 FE              :1;
  __REG8                 :1;
  __REG8 BUS_BUSY        :1;
} __scirxst_bits;

/* SCI - SCIPC1 Pin Control Register 1 */
typedef struct {
  __REG8 CLK_DATA_DIR    :1;
  __REG8 CLK_FUNC        :1;
  __REG8 CLK_DATA_OUT    :1;
  __REG8 CLK_DATA_IN     :1;
  __REG8                 :4;
} __scipc1_bits;

/* SCI - SCIPC2 Pin Control Register 2 */
typedef struct {
  __REG8 RX_DATA_DIR     :1;
  __REG8 RX_FUNC         :1;
  __REG8 RX_DATA_OUT     :1;
  __REG8 RX_DATA_IN      :1;
  __REG8                 :4;
} __scipc2_bits;

/* SCI - SCIPC3 Pin Control Register 2 */
typedef struct {
  __REG8 TX_DATA_DIR     :1;
  __REG8 TX_FUNC         :1;
  __REG8 TX_DATA_OUT     :1;
  __REG8 TX_DATA_IN      :1;
  __REG8                 :4;
} __scipc3_bits;

/* MibADC - ADCR1 AD Control Register 1 */
typedef struct {
  __REG16 PS              :3;
  __REG16 ACQ             :2;
  __REG16 ADC_EN          :1;
  __REG16                 :2;
  __REG16 PWR_DN          :1;
  __REG16 SELF_TST        :1;
  __REG16 HILO            :1;
  __REG16 BRIDGE_EN       :1;
  __REG16 CAL_ST          :1;
  __REG16 CAL_EN          :1;
  __REG16                 :1;
  __REG16 COS             :1;
} __adccr1_bits;

/* MibADC - ADCR2 AD Control Register 2 */
typedef struct {
  __REG16 ENA_G2_INT      :1;
  __REG16 FRZ_G2          :1;
  __REG16 G2_MODE         :1;
  __REG16 ENA_G1_INT      :1;
  __REG16 FRZ_G1          :1;
  __REG16 G1_MODE         :1;
  __REG16                 :2;
  __REG16 EV_EDG_SEL      :1;
  __REG16 ENA_EV_INT      :1;
  __REG16 FRZ_EV          :1;
  __REG16 EV_MODE         :1;
  __REG16                 :4;
} __adccr2_bits;

/* MibADC - ADSR AD Status Register */
typedef struct {
  __REG16 EV_END          :1;
  __REG16 G2_END          :1;
  __REG16 G1_END          :1;
  __REG16                 :5;
  __REG16 EV_STOP         :1;
  __REG16 G2_STOP         :1;
  __REG16 G1_STOP         :1;
  __REG16 EV_BUSY         :1;
  __REG16 G2_BUSY         :1;
  __REG16 G1_BUSY         :1;
  __REG16                 :2;
} __adsr_bits;

/* MibADC - ADCALR Calibration and Offset Error Correction Register */
typedef struct {
  __REG16 CALR            :10;
  __REG16                 :6;
} __adcalr_bits;

/* MibADC - ADDR0 Digital Result Registers */
typedef struct {
  __REG16 DT              :10;
  __REG16                 :5;
  __REG16 DT_ST           :1;
} __addr_bits;

/* MibADC - ADEMDR0 Emulation Digital Result Registers */
typedef struct {
  __REG16 EDT_9_0         :10;
  __REG16                 :5;
  __REG16 EDT_ST          :1;
} __ademdr_bits;

/* MibADC - ADMDR0 Emulation Digital Result Registers */
/* MibADC - ADBUFE AD Event FIFO Buffer */
typedef union {
  //ADEMDRx
  struct {
    __REG16 EDT_9_0         :10;
    __REG16                 :5;
    __REG16 EDT_ST          :1;
  };
  //ADBUFE
  struct {
    __REG16 EVDR            :10;
    __REG16 EVCHID          :4;
    __REG16                 :1;
    __REG16 EV_EMPTY        :1;
  };
} __ademdr014adbufe_bits;

typedef union{
  /* Buffered mode */
  /* ADEMDR4 Emulation Digital Result Registers */
  struct {
    __REG16 EDT_9_0         :10;
    __REG16                 :5;
    __REG16 EDT_ST          :1;
  };
  /* Compatibility mode */
  /* ADBUF1 AD Group 1 FIFO Buffer */
  struct {
    __REG16 G1DR            :10;
    __REG16 G1CHID          :4;
    __REG16                 :1;
    __REG16 G1_EMPTY        :1;
  };
} __ademdr4adbuf1_bits;

typedef union{
  /* Buffered mode */
  /* ADEMDR8 ADMDR15 Emulation Digital Result Registers */
  struct {
    __REG16 EDT_9_0         :10;
    __REG16                 :5;
    __REG16 EDT_ST          :1;
  };
  /* Compatibility mode */
  /* ADBUF2 AD Group 2 FIFO Buffer */
  struct {
    __REG16 G2DR            :10;
    __REG16 G2CHID          :4;
    __REG16                 :1;
    __REG16 G2_EMPTY        :1;
  };
} __ademdr815adbuf2_bits;

typedef union{
  /* Buffered mode */
  /* ADDR15 Digital Result Registers */
  struct {
    __REG16 DT              :10;
    __REG16                 :5;
    __REG16 DT_ST           :1;
  };
  /* Compatibility mode */
  /* ADBUF1 AD Group 1 FIFO Buffer */
  struct {
    __REG16 G1DR            :10;
    __REG16 G1CHID          :4;
    __REG16                 :1;
    __REG16 G1_EMPTY        :1;
  };
} __addr15ademubuf1_bits;

/* MibADC - ADCPCR Pin Control Register */
typedef struct {
  __REG16 EVT_DIR         :1;
  __REG16                 :1;
  __REG16 EVT_OUT         :1;
  __REG16 EVT_IN          :1;
  __REG16                 :12;
} __adcpcr_bits;

/* MibADC - ADBCR1 AD Buffer Control Register 1 */
typedef struct {
  __REG16 BNDB            :8;
  __REG16 BNDA            :7;
  __REG16 BUFEN           :1;
} __adbcr1_bits;

/* MibADC - ADBCR2 AD Buffer Control Register 2 */
typedef struct {
  __REG16 BINDEND         :3;
  __REG16                 :13;
} __adbcr2_bits;

/* MibADC - ADBCR3 AD Buffer Control Register 3 */
typedef struct {
  __REG16 CHID            :1;
  __REG16 G2_8_BIT        :1;
  __REG16 G1_8_BIT        :1;
  __REG16 EV_8_BIT        :1;
  __REG16                 :3;
  __REG16 G2_BUF_INTEN    :1;
  __REG16 G1_BUF_INTEN    :1;
  __REG16 EV_BUF_INTEN    :1;
  __REG16 G2_OVR_INTEN    :1;
  __REG16 G1_OVR_INTEN    :1;
  __REG16 EV_OVR_INTEN    :1;
  __REG16                 :3;
} __adbcr3_bits;

/* MibADC - ADBUFST AD Buffer Status Register */
typedef struct {
  __REG16 G2_EMPTY        :1;
  __REG16 G1_EMPTY        :1;
  __REG16 EV_EMPTY        :1;
  __REG16                 :1;
  __REG16 G2_OVR_FLAG     :1;
  __REG16 G1_OVR_FLAG     :1;
  __REG16 EV_OVR_FLAG     :1;
  __REG16                 :1;
  __REG16 G2_INT_FLAG     :1;
  __REG16 G1_INT_FLAG     :1;
  __REG16 EV_INT_FLAG     :1;
  __REG16                 :5;
} __adbufst_bits;

/* MibADC - ADTHREV AD Event Group Threshold Counter */
typedef struct {
  __REG16 EVTHR           :10;
  __REG16 SIGN_EX         :6;
} __adthrev_bits;

/* MibADC - ADTHRG1 AD Group 1 Threshold Counter */
typedef struct {
  __REG16 G1THR           :10;
  __REG16 SIGN_EX         :6;
} __adthrg1_bits;

/* MibADC - ADTHRG2 AD Group 2 Threshold Counter */
typedef struct {
  __REG16 G2THR           :10;
  __REG16 SIGN_EX         :6;
} __adthrg2_bits;

/* MibADC - ADSAMPEV AD Sample Time Event Register */
typedef struct {
  __REG16 EVACQ           :8;
  __REG16                 :7;
  __REG16 SEN             :1;
} __adsampev_bits;

/* MibADC - ADSAMP1 AD Sample Time Group 1 Register */
typedef struct {
  __REG16 G1ACQ           :8;
  __REG16                 :8;
} __adsamp1_bits;

/* MibADC - ADSAMP2 AD Sample Time Group 2 Register */
typedef struct {
  __REG16 G2ACQ           :8;
  __REG16                 :8;
} __adsamp2_bits;

/* MibADC - ADEVTSRC AD Event Source Register */
typedef struct {
  __REG16 EVSRC           :2;
  __REG16                 :2;
  __REG16 G1SRC           :2;
  __REG16                 :1;
  __REG16 G1_EDG_SEL      :1;
  __REG16 G1_ENA          :1;
  __REG16                 :7;
} __adevtsrc_bits;

/* ECP - ECPCTRL ECP Control Register */
typedef struct {
  __REG16 ECPDIV          :8;
  __REG16 ECPCOS          :1;
  __REG16                 :6;
  __REG16 ECPEN           :1;
} __ecpctrl_bits;

/* EBM - EBRWCR EBM Read/Write Control Register */
typedef struct {
  __REG8 EBOE   : 1;
  __REG8 EBWR   : 2;
  __REG8 EBCS   : 4;
  __REG8 EBHOLD : 1;
} __ebrwcr_bits;

/* EBM - EBACR1 EBM Address Control Register 1 */
typedef struct {
  __REG8 EBADDR : 6;
  __REG8 EBWR   : 2;
} __ebacr1_bits;

/* EBM - EBMCR1 EBM Control Register */
typedef struct {
  __REG8 LPM    :1;
  __REG8 DSIZE  :2;
  __REG8        :3; /* must be 0 */
  __REG8        :2;
} __ebmcr1_bits;

/* GIOPWDN GIO Power Down */
typedef struct {
  __REG32 GIOPWDN         :1;
  __REG32                 :31;
} __giopwdn_bits;

/* GIOENA1 GIO Interrupt Enable */
typedef struct {
  __REG32 ENA_A           :8;
  __REG32 ENA_B           :8;
  __REG32                 :16;
} __gioena1_bits;

/* GIOPOL1 GIO Interrupt Polarity */
typedef struct {
  __REG32 POL_A           :8;
  __REG32 POL_B           :8;
  __REG32                 :16;
} __giopol1_bits;

/* GIOFLG1 GIO Interrupt Flag */
typedef struct {
  __REG32 FLG_A           :8;
  __REG32 FLG_B           :8;
  __REG32                 :16;
} __gioflg1_bits;

/* GIOPRY1 GIO Interrupt Priority */
typedef struct {
  __REG32 PRY_A           :8;
  __REG32 PRY_B           :8;
  __REG32                 :16;
} __giopry1_bits;

/* GIOOFFA GIO Offset A */
typedef struct {
  __REG32 GIOOFFA         :7;
  __REG32                 :25;
} __giooffa_bits;

/* GIOEMUA GIO Emulation A */
typedef struct {
  __REG32 GIOEMUA         :7;
  __REG32                 :25;
} __gioemua_bits;

/* GIOOFFB GIO Offset B */
typedef struct {
  __REG32 GIOOFFB         :7;
  __REG32                 :25;
} __giooffb_bits;

/* GIOEMUB GIO Emulation B */
typedef struct {
  __REG32 GIOEMUB         :7;
  __REG32                 :25;
} __gioemub_bits;

/* GIODIRx GIO Data Direction */
typedef struct {
  __REG32 GIODIR0         :1;
  __REG32 GIODIR1         :1;
  __REG32 GIODIR2         :1;
  __REG32 GIODIR3         :1;
  __REG32 GIODIR4         :1;
  __REG32 GIODIR5         :1;
  __REG32 GIODIR6         :1;
  __REG32 GIODIR7         :1;
  __REG32                 :24;
} __giodir_bits;

/* GIODINx GIO Data Input */
typedef struct {
  __REG32 GIODIN0         :1;
  __REG32 GIODIN1         :1;
  __REG32 GIODIN2         :1;
  __REG32 GIODIN3         :1;
  __REG32 GIODIN4         :1;
  __REG32 GIODIN5         :1;
  __REG32 GIODIN6         :1;
  __REG32 GIODIN7         :1;
  __REG32                 :24;
} __giodin_bits;

/* GIODOUTx GIO Data Output */
typedef struct {
  __REG32 GIODOUT0        :1;
  __REG32 GIODOUT1        :1;
  __REG32 GIODOUT2        :1;
  __REG32 GIODOUT3        :1;
  __REG32 GIODOUT4        :1;
  __REG32 GIODOUT5        :1;
  __REG32 GIODOUT6        :1;
  __REG32 GIODOUT7        :1;
  __REG32                 :24;
} __giodout_bits;

/* GIODSETx GIO Data Set */
typedef struct {
  __REG32 GIODSET0        :1;
  __REG32 GIODSET1        :1;
  __REG32 GIODSET2        :1;
  __REG32 GIODSET3        :1;
  __REG32 GIODSET4        :1;
  __REG32 GIODSET5        :1;
  __REG32 GIODSET6        :1;
  __REG32 GIODSET7        :1;
  __REG32                 :24;
} __giodset_bits;

/* GIODCLRx GIO Data Clear */
typedef struct {
  __REG32 GIODCLR0        :1;
  __REG32 GIODCLR1        :1;
  __REG32 GIODCLR2        :1;
  __REG32 GIODCLR3        :1;
  __REG32 GIODCLR4        :1;
  __REG32 GIODCLR5        :1;
  __REG32 GIODCLR6        :1;
  __REG32 GIODCLR7        :1;
  __REG32                 :24;
} __giodclr_bits;

/* CAN/HECC - CANGAM Global acceptance mask */
typedef struct {
  __REG32 GAM             :29;
  __REG32                 :2;
  __REG32 AMI             :1;
} __cangam_bits;

/* CAN/HECC - CANMC Master control */
typedef struct {
  __REG32 MBNR            :5;
  __REG32 SRES            :1;
  __REG32 STM             :1;
  __REG32 ABO             :1;
  __REG32 CDR             :1;
  __REG32 WUBA            :1;
  __REG32 DBO             :1;
  __REG32 PDR             :1;
  __REG32 CCR             :1;
  __REG32 SCM             :1;
  __REG32 LNTM            :1;
  __REG32 LNTC            :1;
  __REG32                 :16;
} __canmc_bits;

/* CAN/HECC - CANBTC Bit-timing configuration */
typedef struct {
  __REG32 TSEG2           :3;
  __REG32 TSEG1           :4;
  __REG32 SAM             :1;
  __REG32 SJW             :2;
  __REG32 ERM             :1;
  __REG32                 :5;
  __REG32 BRP             :8;
  __REG32                 :8;
} __canbtc_bits;

/* CAN/HECC - CANES Error and status */
typedef struct {
  __REG32 TM              :1;
  __REG32 RM              :1;
  __REG32                 :1;
  __REG32 PDA             :1;
  __REG32 CCE             :1;
  __REG32 SMA             :1;
  __REG32                 :10;
  __REG32 EW              :1;
  __REG32 EP              :1;
  __REG32 BO              :1;
  __REG32 ACKE            :1;
  __REG32 SE              :1;
  __REG32 CRCE            :1;
  __REG32 SA1             :1;
  __REG32 BE              :1;
  __REG32 FE              :1;
  __REG32                 :7;
} __canes_bits;

/* CAN/HECC - CANTEC Transmit error counter */
typedef struct {
  __REG32 TEC             :8;
  __REG32                 :24;
} __cantec_bits;

/* CAN/HECC - CANREC Receive error counter */
typedef struct {
  __REG32 REC             :8;
  __REG32                 :24;
} __canrec_bits;

/* CAN/HECC - CANGIFx Global interrupt flag */
typedef struct {
  __REG32 MIV_3_0         :4;
  __REG32 MIV_4           :1;
  __REG32                 :3;
  __REG32 WLIF            :1;
  __REG32 EPIF            :1;
  __REG32 BOIF            :1;
  __REG32 RMLIF           :1;
  __REG32 WUIF            :1;
  __REG32 WDIF            :1;
  __REG32 AAIF            :1;
  __REG32 GMIF            :1;
  __REG32 TCOIF           :1;
  __REG32 MAIF            :1;
  __REG32                 :14;
} __cangif_bits;

/* CAN/HECC - CANGIM Global interrupt mask */
typedef struct {
  __REG32 I0EN            :1;
  __REG32 I1EN            :1;
  __REG32 SIL             :1;
  __REG32                 :5;
  __REG32 WLIM            :1;
  __REG32 EPIM            :1;
  __REG32 BOIM            :1;
  __REG32 RMLIM           :1;
  __REG32 WUIM            :1;
  __REG32 WDIM            :1;
  __REG32 AAIM            :1;
  __REG32                 :1;
  __REG32 TCOIM           :1;
  __REG32 MAIM            :1;
  __REG32                 :14;
} __cangim_bits;

/* CAN/HECC - CANTIOC TX I/O control */
typedef struct {
  __REG32 TXIN            :1;
  __REG32 TXOUT           :1;
  __REG32 TXDIR           :1;
  __REG32 TXFUNC          :1;
  __REG32                 :28;
} __cantioc_bits;

/* CAN/HECC - CANRIOC RX I/O control */
typedef struct {
  __REG32 RXIN            :1;
  __REG32 RXOUT           :1;
  __REG32 RXDIR           :1;
  __REG32 RXFUNC          :1;
  __REG32                 :28;
} __canrioc_bits;

/* CAN/HECC RAM - Message Identifier Register (MID) */
typedef struct {
  __REG32 ID  :29;
  __REG32 AAM : 1;
  __REG32 AME : 1;
  __REG32 IDE : 1;
} __mid_bits;

/* CAN/HECC RAM - Message Control Field Register (MCF) */
typedef struct {
  __REG32 DLC : 4;
  __REG32 RTR : 1;
  __REG32     : 3;
  __REG32 TPL : 6;
  __REG32     :18;
} __mcf_bits;

 /* I2COAR I2C Own Address Register */
typedef struct {
  __REG16 OA              :10;
  __REG16                 :6;
} __i2coar_bits;

/* I2CIMR I2C Interrupt Mask/Status Register */
typedef struct {
  __REG16 ALEN            :1;
  __REG16 NACKEN          :1;
  __REG16 ARDYEN          :1;
  __REG16 RXRDYEN         :1;
  __REG16 TXRDYEN         :1;
  __REG16 SCDEN           :1;
  __REG16 AASEN           :1;
  __REG16                 :9;
} __i2cimr_bits;

/* I2CISR I2C Interrupt Status Register */
typedef struct {
  __REG16 AL              :1;
  __REG16 NACK            :1;
  __REG16 ARDY            :1;
  __REG16 RXRDY           :1;
  __REG16 TXRDY           :1;
  __REG16 SCD             :1;
  __REG16                 :2;
  __REG16 AD0             :1;
  __REG16 AAS             :1;
  __REG16 XSMT            :1;
  __REG16 RSFULL          :1;
  __REG16 BB              :1;
  __REG16 NACKSNT         :1;
  __REG16 SDIR            :1;
  __REG16                 :1;
} __i2csr_bits;

/* I2CDRR I2C Data Receive Register */
typedef struct {
  __REG16 DATARX          :8;
  __REG16                 :8;
} __i2cdrr_bits;

/* I2CSAR I2C Slave Address Register */
typedef struct {
  __REG16 SA              :10;
  __REG16                 :6;
} __i2csar_bits;

/* I2CDXR I2C Data Transmit Register */
typedef struct {
  __REG16 DATATX          :8;
  __REG16                 :8;
} __i2cdxr_bits;

/* I2CMDR I2C Mode Register */
typedef struct {
  __REG16 BC              :3;
  __REG16 FDF             :1;
  __REG16 STB             :1;
  __REG16 nIRS            :1;
  __REG16 DLB             :1;
  __REG16 RM              :1;
  __REG16 XA              :1;
  __REG16 TRX             :1;
  __REG16 MST             :1;
  __REG16 STP             :1;
  __REG16 LPM             :1;
  __REG16 STT             :1;
  __REG16 FREE            :1;
  __REG16 NACKMOD         :1;
} __i2cmdr_bits;

/* I2CIVR I2C Interrupt Vector Register */
typedef struct {
  __REG16 INTCODE         :3;
  __REG16                 :5;
  __REG16 TESTMD          :4;
  __REG16                 :4;
} __i2civr_bits;

/* I2CEMR I2C Extended Mode Register */
typedef struct {
  __REG16 BCM             :1;
  __REG16                 :15;
} __i2cemr_bits;

/* I2CPSC I2C Prescale Register */
typedef struct {
  __REG16 PSC             :8;
  __REG16                 :8;
} __i2cpsc_bits;

/* I2CDIR I2C Data Direction Register */
typedef struct {
  __REG16 SCLDIR          :1;
  __REG16 SDADIR          :1;
  __REG16 SCLFUNC         :1;
  __REG16 SDAFUNC         :1;
  __REG16 RXDMAEN         :1;
  __REG16 TXDMAEN         :1;
  __REG16                 :10;
} __i2cdir_bits;

/* I2CDOUTP I2C Data Out Register */
typedef struct {
  __REG16 SCLOUT          :1;
  __REG16 SDAOUT          :1;
  __REG16                 :14;
} __i2cdoutp_bits;

/* I2CDINP I2C Data Input Register */
typedef struct {
  __REG16 SCLIN           :1;
  __REG16 SDAIN           :1;
  __REG16                 :14;
} __i2cdinp_bits;

/* I2CPFNC I2C Function Register */
typedef struct {
  __REG16 PFUNC           :1;
  __REG16                 :15;
} __i2cpgnc_bits;

/* I2CPDIR I2CPin Direction Register */
typedef struct {
  __REG16 SCLDIR          :1;
  __REG16 SDADIR          :1;
  __REG16                 :14;
} __i2cpdir_bits;

/* I2CDIN I2C Data Input Register */
typedef struct {
  __REG16 SCLIN           :1;
  __REG16 SDAIN           :1;
  __REG16                 :14;
} __i2cdin_bits;

/* I2CDOUT I2C Data Output Register */
typedef struct {
  __REG16 SCLOUT          :1;
  __REG16 SDAOUT          :1;
  __REG16                 :14;
} __i2cdout_bits;

/* I2CDSET I2C Data Set Register */
typedef struct {
  __REG16 SCLSET          :1;
  __REG16 SDASET          :1;
  __REG16                 :14;
} __i2cdset_bits;

/* I2CDCLR I2C Data Clear Register */
typedef struct {
  __REG16 SCLCLR          :1;
  __REG16 SDACLR          :1;
  __REG16                 :14;
} __i2cdclr_bits;

/* I2CPID1 I2C Peripheral ID Register 1 */
typedef struct {
  __REG16 REVISION        :8;
  __REG16 CLASS           :8;
} __i2cpid1_bits;

/* I2CPID2 I2C Peripheral ID Register 2 */
typedef struct {
  __REG16 TYPE            :8;
  __REG16                 :8;
} __i2cpid2_bits;

/* FMBAC1 Bank Access Control Register 1 */
typedef struct {
  __REG16 BNKPWR         :2;
  __REG16 BSTDBY         :6;
  __REG16 BAGP           :8;
} __fmbac1_bits;

/* FMBAC2 Bank Access Control Register 2 */
typedef struct {
  __REG16 WAIT_3_0       :4;
  __REG16 WAIT_7_4       :4;
  __REG16 BSLEEP         :7;
  __REG16 OTPPROTDIS     :1;
} __fmbac2_bits;

/* FMBRDY Bank Ready Register */
typedef struct {
  __REG16                :5;
  __REG16 BANKRDY        :1;
  __REG16                :10;
} __fmbrdy_bits;

/* FMREGOPT Option Control Register */
typedef struct {
  __REG32 ENPIPE         :1;
  __REG32 READOTP        :1;
  __REG32 RDMRGN0        :1;
  __REG32 RDMRGN1        :1;
  __REG32                :28;
} __fmregopt_bits;

/* FMBBUSY Bank Busy Register */
typedef struct {
  __REG32 BUSY           :8;
  __REG32                :7;
  __REG32 PROTL2DIS      :1;
  __REG32                :16;
} __fmbbusy_bits;

/* FMPRDY Pump Ready Register */
typedef struct {
  __REG16                :9;
  __REG16 PUMPRDY        :1;
  __REG16                :6;
} __fmprdy_bits;

/* FMMAC1 Module Access Control Register 1 */
typedef struct {
  __REG16 PSLEEP         :15;
  __REG16 PROTL1DIS      :1;
} __fmmac1_bits;

/* FMMAC2 Module Access Control Register 2 */
typedef struct {
  __REG16 BANK           :3;
  __REG16 PMPPWR         :2;
  __REG16 PSTDBY         :11;
} __fmmac2_bits;

/* FMMSTAT Module Status Register */
typedef struct {
  __REG16 SLOCK          :1;
  __REG16 PSUSP          :1;
  __REG16 ESUSP          :1;
  __REG16 _3VSTAT        :1;  /* 3VSTAT (symbols cannot start with a digit) */
  __REG16 CSTAT          :1;
  __REG16 INVDAT         :1;
  __REG16 PGM            :1;
  __REG16 ERS            :1;
  __REG16 BUSY           :1;
  __REG16                :7;
} __fmmstat_bits;

/* DMA configuration Reg */
typedef struct {
  __REG32 DCHN           :1;
  __REG32 SRCMOD         :4;
  __REG32 DSTMOD         :4;
  __REG32 SRCINC         :1;
  __REG32                :1;
  __REG32 DSTINC         :1;
  __REG32                :1;
  __REG32 TRSIZE         :2;
  __REG32 INTEN          :1;
  __REG32                :8;
  __REG32 NCPACK         :5;
  __REG32                :3;

} __dmac_bits;

/* DMA Source Addr Reg */
typedef struct {
  __REG32 SOURCEADDR     :32;

} __dmasa_bits;

/* DMA Destination Addr Reg */
typedef struct {
  __REG32 DESTADDR       :32;

} __dmada_bits;

/* DMA Transfer Count Reg */
typedef struct {
  __REG32 TRANSCOUNT     :16;
  __REG32                :16;

} __dmatc_bits;

/* DMA Channel Control 0 Reg */
typedef struct {
  __REG32                :1;
  __REG32 RQEN0          :1;
  __REG32 SEN0           :1;
  __REG32 IL0            :1;
  __REG32                :1;
  __REG32 RQEN1          :1;
  __REG32 SEN1           :1;
  __REG32 IL1            :1;
  __REG32                :1;
  __REG32 RQEN2          :1;
  __REG32 SEN2           :1;
  __REG32 IL2            :1;
  __REG32                :1;
  __REG32 RQEN3          :1;
  __REG32 SEN3           :1;
  __REG32 IL3            :1;
  __REG32                :1;
  __REG32 RQEN4          :1;
  __REG32 SEN4           :1;
  __REG32 IL4            :1;
  __REG32                :1;
  __REG32 RQEN5          :1;
  __REG32 SEN5           :1;
  __REG32 IL5            :1;
  __REG32                :1;
  __REG32 RQEN6          :1;
  __REG32 SEN6           :1;
  __REG32 IL6            :1;
  __REG32                :1;
  __REG32 RQEN7          :1;
  __REG32 SEN7           :1;
  __REG32 IL7            :1;

} __dmacc0_bits;

/* DMA Channel Control 1 Reg */
typedef struct {
  __REG32                :1;
  __REG32 RQEN8          :1;
  __REG32 SEN8           :1;
  __REG32 IL8            :1;
  __REG32                :1;
  __REG32 RQEN9          :1;
  __REG32 SEN9           :1;
  __REG32 IL9            :1;
  __REG32                :1;
  __REG32 RQEN10         :1;
  __REG32 SEN10          :1;
  __REG32 IL10           :1;
  __REG32                :1;
  __REG32 RQEN11         :1;
  __REG32 SEN11          :1;
  __REG32 IL11           :1;
  __REG32                :1;
  __REG32 RQEN12         :1;
  __REG32 SEN12          :1;
  __REG32 IL12           :1;
  __REG32                :1;
  __REG32 RQEN13         :1;
  __REG32 SEN13          :1;
  __REG32 IL13           :1;
  __REG32                :1;
  __REG32 RQEN14         :1;
  __REG32 SEN14          :1;
  __REG32 IL14           :1;
  __REG32                :1;
  __REG32 RQEN15         :1;
  __REG32 SEN15          :1;
  __REG32 IL15           :1;

} __dmacc1_bits;

/* DMA Status Reg */
typedef struct {
  __REG32 IF0            :1;
  __REG32 IF1            :1;
  __REG32 IF2            :1;
  __REG32 IF3            :1;
  __REG32 IF4            :1;
  __REG32 IF5            :1;
  __REG32 IF6            :1;
  __REG32 IF7            :1;
  __REG32 IF8            :1;
  __REG32 IF9            :1;
  __REG32 IF10           :1;
  __REG32 IF11           :1;
  __REG32 IF12           :1;
  __REG32 IF13           :1;
  __REG32 IF14           :1;
  __REG32 IF15           :1;
  __REG32 PINT           :1;
  __REG32 TC             :1;
  __REG32                :14;

} __dmas_bits;

/* DMA Offset 0 Reg */
typedef struct {
  __REG32 OFFSET0        :8;
  __REG32                :24;

} __dmaio0_bits;

/* DMA Offset 1 Reg */
typedef struct {
  __REG32 OFFSET1        :8;
  __REG32                :24;

} __dmaio1_bits;

/* DMA Control Packet Status Reg */
typedef struct {
  __REG32 CPS            :32;

} __dmacps_bits;

/* DMA Control Packet Status Clear Reg */
typedef struct {
  __REG32 CPSC           :32;

} __dmacpsc_bits;

/* DMA Global Control Reg */
typedef struct {
  __REG32 CHSS           :4;
  __REG32 BMSS           :1;
  __REG32 CHPR           :1;
  __REG32 HFIQ           :1;
  __REG32 HIRQ           :1;
  __REG32                :24;

} __dmagc_bits;

/* DMA Global Disable Reg */
typedef struct {
  __REG32 DMA_HALT       :1;
  __REG32 DMA_STOP       :1;
  __REG32                :30;

} __dmagd_bits;

/* DMA Actice Channel Reg */
typedef struct {
  __REG32 ACT_CHN        :4;
  __REG32                :28;

} __dmaac_bits;

/* DMA Channel Control Packet 0 Reg */
typedef struct {
  __REG32 CCPACK0        :5;
  __REG32                :1;
  __REG32 DMAEN0         :1;
  __REG32                :1;
  __REG32 CCPACK1        :5;
  __REG32                :1;
  __REG32 DMAEN1         :1;
  __REG32                :1;
  __REG32 CCPACK2        :5;
  __REG32                :1;
  __REG32 DMAEN2         :1;
  __REG32                :1;
  __REG32 CCPACK3        :5;
  __REG32                :1;
  __REG32 DMAEN3         :1;
  __REG32                :1;

} __dmaccp0_bits;

/* DMA Channel Control Packet 1 Reg */
typedef struct {
  __REG32 CCPACK4        :5;
  __REG32                :1;
  __REG32 DMAEN4         :1;
  __REG32                :1;
  __REG32 CCPACK5        :5;
  __REG32                :1;
  __REG32 DMAEN5         :1;
  __REG32                :1;
  __REG32 CCPACK6        :5;
  __REG32                :1;
  __REG32 DMAEN6         :1;
  __REG32                :1;
  __REG32 CCPACK7        :5;
  __REG32                :1;
  __REG32 DMAEN7         :1;
  __REG32                :1;

} __dmaccp1_bits;

/* DMA Channel Control Packet 2 Reg */
typedef struct {
  __REG32 CCPACK8        :5;
  __REG32                :1;
  __REG32 DMAEN8         :1;
  __REG32                :1;
  __REG32 CCPACK9        :5;
  __REG32                :1;
  __REG32 DMAEN9         :1;
  __REG32                :1;
  __REG32 CCPACK10       :5;
  __REG32                :1;
  __REG32 DMAEN10        :1;
  __REG32                :1;
  __REG32 CCPACK11       :5;
  __REG32                :1;
  __REG32 DMAEN11        :1;
  __REG32                :1;

} __dmaccp2_bits;

/* DMA Channel Control Packet 3 Reg */
typedef struct {
  __REG32 CCPACK12       :5;
  __REG32                :1;
  __REG32 DMAEN12        :1;
  __REG32                :1;
  __REG32 CCPACK13       :5;
  __REG32                :1;
  __REG32 DMAEN13        :1;
  __REG32                :1;
  __REG32 CCPACK14       :5;
  __REG32                :1;
  __REG32 DMAEN14        :1;
  __REG32                :1;
  __REG32 CCPACK15       :5;
  __REG32                :1;
  __REG32 DMAEN15        :1;
  __REG32                :1;

} __dmaccp3_bits;

#endif    /* __IAR_SYSTEMS_ICC__ */

/* Declarations common to compiler and assembler *********************************/

/***************************************************************************
 **
 ** System module control (SMC)
 **
 ***************************************************************************/
__IO_REG32_BIT(SMCR0,    0xfffffd00,__READ_WRITE,__smcr0_bits);
__IO_REG32_BIT(SMCR1,    0xfffffd04,__READ_WRITE,__smcrx_bits);
__IO_REG32_BIT(SMCR2,    0xfffffd08,__READ_WRITE,__smcrx_bits);
__IO_REG32_BIT(SMCR3,    0xfffffd0c,__READ_WRITE,__smcrx_bits);
__IO_REG32_BIT(SMCR4,    0xfffffd10,__READ_WRITE,__smcrx_bits);
__IO_REG32_BIT(SMCR5,    0xfffffd14,__READ_WRITE,__smcrx_bits);
__IO_REG32_BIT(SMCR6,    0xfffffd18,__READ_WRITE,__smcrx_bits);
__IO_REG32_BIT(SMCR7,    0xfffffd1c,__READ_WRITE,__smcrx_bits);
__IO_REG32_BIT(SMCR8,    0xfffffd20,__READ_WRITE,__smcrx_bits);
__IO_REG32_BIT(SMCR9,    0xfffffd24,__READ_WRITE,__smcrx_bits);
__IO_REG32_BIT(WCR0,     0xfffffd2c,__READ_WRITE,__wcr_bits);

__IO_REG32_BIT(PLR,      0xfffffd34,__READ_WRITE,__plr_bits);
__IO_REG32_BIT(PPROT,    0xfffffd38,__READ_WRITE,__pprot_bits);

__IO_REG32_BIT(MFBAHR0,  0xfffffe00,__READ_WRITE,__mfbahr_bits);
__IO_REG32_BIT(MFBALR0,  0xfffffe04,__READ_WRITE,__mfbalr0_bits);
__IO_REG32_BIT(MFBAHR1,  0xfffffe08,__READ_WRITE,__mfbahr_bits);
__IO_REG32_BIT(MFBALR1,  0xfffffe0c,__READ_WRITE,__mfbalrx_bits);
__IO_REG32_BIT(MFBAHR2,  0xfffffe10,__READ_WRITE,__mfbahr_bits);
__IO_REG32_BIT(MFBALR2,  0xfffffe14,__READ_WRITE,__mfbalrx_bits);
__IO_REG32_BIT(MFBAHR3,  0xfffffe18,__READ_WRITE,__mfbahr_bits);
__IO_REG32_BIT(MFBALR3,  0xfffffe1c,__READ_WRITE,__mfbalrx_bits);
__IO_REG32_BIT(MFBAHR4,  0xfffffe20,__READ_WRITE,__mfbahr_bits);
__IO_REG32_BIT(MFBALR4,  0xfffffe24,__READ_WRITE,__mfbalrx_bits);
__IO_REG32_BIT(MFBAHR5,  0xfffffe28,__READ_WRITE,__mfbahr_bits);
__IO_REG32_BIT(MFBALR5,  0xfffffe2c,__READ_WRITE,__mfbalrx_bits);
__IO_REG32_BIT(MCBAHR0,  0xfffffe30,__READ_WRITE,__mcbahr_bits);
__IO_REG32_BIT(MCBALR0,  0xfffffe34,__READ_WRITE,__mcbalr_bits);
__IO_REG32_BIT(MCBAHR1,  0xfffffe38,__READ_WRITE,__mcbahr_bits);
__IO_REG32_BIT(MCBALR1,  0xfffffe3c,__READ_WRITE,__mcbalr_bits);
__IO_REG32_BIT(MCBAHR2,  0xfffffe40,__READ_WRITE,__mcbahr_bits);
__IO_REG32_BIT(MCBALR2,  0xfffffe44,__READ_WRITE,__mcbalr_bits);
__IO_REG32_BIT(MCBAHR3,  0xfffffe48,__READ_WRITE,__mcbahr_bits);
__IO_REG32_BIT(MCBALR3,  0xfffffe4c,__READ_WRITE,__mcbalr_bits);
__IO_REG32_BIT(MCBAHR4,  0xfffffe50,__READ_WRITE,__mcbahr_bits);
__IO_REG32_BIT(MCBALR4,  0xfffffe54,__READ_WRITE,__mcbalr_bits);
__IO_REG32_BIT(MCBAHR5,  0xfffffe58,__READ_WRITE,__mcbahr_bits);
__IO_REG32_BIT(MCBALR5,  0xfffffe5c,__READ_WRITE,__mcbalr_bits);
	
__IO_REG32_BIT(RTICNTR,  0xffffff00,__READ_WRITE,__rticntr_bits);
__IO_REG32_BIT(RTIPCTL,  0xffffff04,__READ_WRITE,__rtipctl_bits);
__IO_REG32_BIT(RTICNTL,  0xffffff08,__READ_WRITE,__rticntl_bits);
__IO_REG32(    WKEY,     0xffffff0c,__READ_WRITE);
__IO_REG32_BIT(RTICMP1,  0xffffff10,__READ_WRITE,__rticmp1_bits);
__IO_REG32_BIT(RTICMP2,  0xffffff14,__READ_WRITE,__rticmp2_bits);
__IO_REG32_BIT(RTICINT,  0xffffff18,__READ_WRITE,__rticint_bits);
__IO_REG32_BIT(RTICNTEN, 0xffffff1c,__READ_WRITE,__rticnten_bits);

__IO_REG32_BIT(IRQIVEC,  0xffffff20,__READ_WRITE,__irqivec_bits);
__IO_REG32_BIT(FIQIVEC,  0xffffff24,__READ_WRITE,__fiqivec_bits);
__IO_REG32_BIT(CIMIVEC,  0xffffff28,__READ_WRITE,__cimivec_bits);
__IO_REG32(    FIRQPR,   0xffffff2c,__READ_WRITE);
__IO_REG32(    INTREQ,   0xffffff30,__READ_WRITE);
__IO_REG32(    REQMASK,  0xffffff34,__READ_WRITE);
__IO_REG32_BIT(SSIF,     0xfffffff8,__READ_WRITE,__ssif_bits);
__IO_REG32_BIT(SSIR,     0xfffffffc,__READ_WRITE,__ssir_bits);

__IO_REG32(    CPUPSA,   0xffffff40,__READ_WRITE);
__IO_REG32_BIT(PSAENABLE,0xffffff50,__READ_WRITE,__psaenable_bits);

__IO_REG32_BIT(PCR,      0xfffffd30,__READ_WRITE,__pcr_bits);
__IO_REG32_BIT(CLKCNTL,  0xffffffd0,__READ_WRITE,__clkcntl_bits);
__IO_REG32_BIT(GCR,      0xffffffdc,__READ_WRITE,__gcr_bits);
__IO_REG32_BIT(GCR_N,    0xffffffcc,__READ_WRITE,__gcr_n_bits); /*JM*/

__IO_REG32_BIT(SYSECR,   0xffffffe0,__READ_WRITE,__sysecr_bits);
__IO_REG32_BIT(SYSESR,   0xffffffe4,__READ_WRITE,__sysesr_bits);
__IO_REG32_BIT(ABRTESR,  0xffffffe8,__READ_WRITE,__abrtesr_bits);
__IO_REG32_BIT(GLBSTAT,  0xffffffec,__READ_WRITE,__glbstat_bits);

__IO_REG32_BIT(DEV,      0xfffffff0,__READ_WRITE,__dev_bits);

/***************************************************************************
 **
 ** IEM
 **
 ***************************************************************************/
__IO_REG32_BIT(INTPEND0,  0xfffffc00, __READ      , __intpend0_bits);
__IO_REG32_BIT(INTPEND1,  0xfffffc04, __READ      , __intpend1_bits);
__IO_REG32_BIT(INTCTRL0,  0xfffffc20, __READ_WRITE, __intctrl0_bits);
__IO_REG32_BIT(INTCTRL1,  0xfffffc24, __READ_WRITE, __intctrl1_bits);
__IO_REG32_BIT(INTCTRL2,  0xfffffc28, __READ_WRITE, __intctrl2_bits);
__IO_REG32_BIT(INTCTRL3,  0xfffffc2c, __READ_WRITE, __intctrl3_bits);
__IO_REG32_BIT(INTCTRL4,  0xfffffc30, __READ_WRITE, __intctrl4_bits);
__IO_REG32_BIT(INTCTRL5,  0xfffffc34, __READ_WRITE, __intctrl5_bits);
__IO_REG32_BIT(INTCTRL6,  0xfffffc38, __READ_WRITE, __intctrl6_bits);
__IO_REG32_BIT(INTCTRL7,  0xfffffc3c, __READ_WRITE, __intctrl7_bits);
__IO_REG32_BIT(INTCTRL8,  0xfffffc40, __READ_WRITE, __intctrl8_bits);
__IO_REG32_BIT(INTCTRL9,  0xfffffc44, __READ_WRITE, __intctrl9_bits);
__IO_REG32_BIT(INTCTRL10, 0xfffffc48, __READ_WRITE, __intctrl10_bits);
__IO_REG32_BIT(INTCTRL11, 0xfffffc4c, __READ_WRITE, __intctrl11_bits);
__IO_REG32_BIT(INTCTRL12, 0xfffffc50, __READ_WRITE, __intctrl12_bits);
__IO_REG32_BIT(INTCTRL13, 0xfffffc54, __READ_WRITE, __intctrl13_bits);
__IO_REG32_BIT(INTCTRL14, 0xfffffc58, __READ_WRITE, __intctrl14_bits);
__IO_REG32_BIT(INTCTRL15, 0xfffffc5c, __READ_WRITE, __intctrl15_bits);

/***************************************************************************
 **
 ** MSM 1 - Memory Security Module 1
 **
 ***************************************************************************/
__IO_REG32(     MSMKEY0,  0xfffff700, __READ_WRITE);
__IO_REG32(     MSMKEY1,  0xfffff704, __READ_WRITE);
__IO_REG32(     MSMKEY2,  0xfffff708, __READ_WRITE);
__IO_REG32(     MSMKEY3,  0xfffff70c, __READ_WRITE);
__IO_REG32_BIT( MSMSCR,   0xfffff724, __READ_WRITE, __msmscr_bits);

__IO_REG32(     MSMPWL0,  0x0000ffe0, __READ_WRITE); // password for first MSM
__IO_REG32(     MSMPWL1,  0x0000ffe4, __READ_WRITE);
__IO_REG32(     MSMPWL2,  0x0000ffe8, __READ_WRITE);
__IO_REG32(     MSMPWL3,  0x0000ffec, __READ_WRITE);


/***************************************************************************
 **
 ** MPU
 **
 ***************************************************************************/

__IO_REG32_BIT(MPUAHR0,  0xffe84000,__READ_WRITE,__mpuahr_bits);
__IO_REG32_BIT(MPUALR0,  0xffe84004,__READ_WRITE,__mpualr_bits);
__IO_REG32_BIT(MPUAHR1,  0xffe84008,__READ_WRITE,__mpuahr_bits);
__IO_REG32_BIT(MPUALR1,  0xffe8400c,__READ_WRITE,__mpualr_bits);
__IO_REG32_BIT(MPUAHR2,  0xffe84010,__READ_WRITE,__mpuahr_bits);
__IO_REG32_BIT(MPUALR2,  0xffe84014,__READ_WRITE,__mpualr_bits);
__IO_REG32_BIT(MPUAHR3,  0xffe84018,__READ_WRITE,__mpuahr_bits);
__IO_REG32_BIT(MPUALR3,  0xffe8401c,__READ_WRITE,__mpualr_bits);
__IO_REG32_BIT(MPUCTRL,  0xffe84020,__READ_WRITE,__mpuctrl_bits);


/***************************************************************************
 **
 ** HET
 **
 ***************************************************************************/
__IO_REG32_BIT(HETGCR,   0xfff7fc00,__READ_WRITE,__hetgcr_bits);
__IO_REG32_BIT(HETPFR,   0xfff7fc04,__READ_WRITE,__hetpfr_bits);
__IO_REG32_BIT(HETADDR,  0xfff7fc08,__READ_WRITE,__hetaddr_bits);
__IO_REG32_BIT(HETOFF1,  0xfff7fc0c,__READ_WRITE,__hetoff_bits);
__IO_REG32_BIT(HETOFF2,  0xfff7fc10,__READ_WRITE,__hetoff_bits);
__IO_REG32_BIT(HETEXC1,  0xfff7fc14,__READ_WRITE,__hetexc1_bits);
__IO_REG32_BIT(HETEXC2,  0xfff7fc18,__READ_WRITE,__hetexc2_bits);
__IO_REG32(    HETPRY,   0xfff7fc1c,__READ_WRITE);
__IO_REG32(    HETFLG,   0xfff7fc20,__READ_WRITE);
__IO_REG32_BIT(HETHRSH,  0xfff7fc2c,__READ_WRITE,__hethrsh_bits);
__IO_REG32_BIT(HETXOR,   0xfff7fc30,__READ_WRITE,__hetxor_bits);
__IO_REG32(    HETDIR,   0xfff7fc34,__READ_WRITE);
__IO_REG32(    HETDIN,   0xfff7fc38,__READ_WRITE);
__IO_REG32(    HETDOUT,  0xfff7fc3c,__READ_WRITE);
__IO_REG32(    HETDSET,  0xfff7fc40,__READ_WRITE);
__IO_REG32(    HETDCLR,  0xfff7fc44,__READ_WRITE);

/***************************************************************************
 **
 ** SPI1
 **
 ***************************************************************************/

__IO_REG32_BIT(SPI1CTRL1,0xfff7f800,__READ_WRITE,__spictrl1_bits);
__IO_REG32_BIT(SPI1CTRL2,0xfff7f804,__READ_WRITE,__spictrl2_bits);
__IO_REG32_BIT(SPI1CTRL3,0xfff7f808,__READ_WRITE,__spictrl3_bits);
__IO_REG32_BIT(SPI1DAT0, 0xfff7f80C,__READ_WRITE,__spidat0_bits);
__IO_REG32_BIT(SPI1DAT1, 0xfff7f810,__READ_WRITE,__spidat1_bits);
__IO_REG32_BIT(SPI1BUF,  0xfff7f814,__READ_WRITE,__spibuf_bits);
__IO_REG32_BIT(SPI1EMU,  0xfff7f818,__READ_WRITE,__spiemu_bits);
__IO_REG32_BIT(SPI1PC1,  0xfff7f81c,__READ_WRITE,__spipc1_bits);
__IO_REG32_BIT(SPI1PC2,  0xfff7f820,__READ_WRITE,__spipc2_bits);
__IO_REG32_BIT(SPI1PC3,  0xfff7f824,__READ_WRITE,__spipc3_bits);
__IO_REG32_BIT(SPI1PC4,  0xfff7f828,__READ_WRITE,__spipc4_bits);
__IO_REG32_BIT(SPI1PC5,  0xfff7f82c,__READ_WRITE,__spipc5_bits);
__IO_REG32_BIT(SPI1PC6,  0xfff7f830,__READ_WRITE,__spipc6_bits);

/***************************************************************************
 **
 ** SPI2
 **
 ***************************************************************************/

__IO_REG32_BIT(SPI2CTRL1,0xfff7d400,__READ_WRITE,__spictrl1_bits);
__IO_REG32_BIT(SPI2CTRL2,0xfff7d404,__READ_WRITE,__spictrl2_bits);
__IO_REG32_BIT(SPI2CTRL3,0xfff7d408,__READ_WRITE,__spictrl3_bits);
__IO_REG32_BIT(SPI2DAT0, 0xfff7d40c,__READ_WRITE,__spidat0_bits);
__IO_REG32_BIT(SPI2DAT1, 0xfff7d410,__READ_WRITE,__spidat1_bits);
__IO_REG32_BIT(SPI2BUF,  0xfff7d414,__READ_WRITE,__spibuf_bits);
__IO_REG32_BIT(SPI2EMU,  0xfff7d418,__READ_WRITE,__spiemu_bits);
__IO_REG32_BIT(SPI2PC1,  0xfff7d41c,__READ_WRITE,__spipc1_bits);
__IO_REG32_BIT(SPI2PC2,  0xfff7d420,__READ_WRITE,__spipc2_bits);
__IO_REG32_BIT(SPI2PC3,  0xfff7d424,__READ_WRITE,__spipc3_bits);
__IO_REG32_BIT(SPI2PC4,  0xfff7d428,__READ_WRITE,__spipc4_bits);
__IO_REG32_BIT(SPI2PC5,  0xfff7d42c,__READ_WRITE,__spipc5_bits);
__IO_REG32_BIT(SPI2PC6,  0xfff7d430,__READ_WRITE,__spipc6_bits);


/***************************************************************************
 **
 ** SCI1
 **
 ***************************************************************************/

__IO_REG8_BIT(SCI1CCR,   0xfff7f403,__READ_WRITE,__sciccr_bits);
__IO_REG8_BIT(SCI1CTL1,  0xfff7f407,__READ_WRITE,__scictl1_bits);
__IO_REG8_BIT(SCI1CTL2,  0xfff7f40b,__READ_WRITE,__scictl2_bits);
__IO_REG8_BIT(SCI1CTL3,  0xfff7f40f,__READ_WRITE,__scictl3_bits);
__IO_REG8_BIT(SCI1RXST,  0xfff7f413,__READ_WRITE,__scirxst_bits);
__IO_REG8(    SCI1HBAUD, 0xfff7f417,__READ_WRITE);
__IO_REG8(    SCI1MBAUD, 0xfff7f41b,__READ_WRITE);
__IO_REG8(    SCI1LBAUD, 0xfff7f41f,__READ_WRITE);
__IO_REG8(    SCI1RXEMU, 0xfff7f423,__READ_WRITE);
__IO_REG8(    SCI1RXBUF, 0xfff7f427,__READ_WRITE);
__IO_REG8(    SCI1TXBUF, 0xfff7f42b,__READ_WRITE);
__IO_REG8_BIT(SCI1PC1,   0xfff7f42f,__READ_WRITE,__scipc1_bits);
__IO_REG8_BIT(SCI1PC2,   0xfff7f433,__READ_WRITE,__scipc2_bits);
__IO_REG8_BIT(SCI1PC3,   0xfff7f437,__READ_WRITE,__scipc3_bits);

/***************************************************************************
 **
 ** SCI2
 **
 ***************************************************************************/

__IO_REG8_BIT(SCI2CCR,   0xfff7f503,__READ_WRITE,__sciccr_bits);
__IO_REG8_BIT(SCI2CTL1,  0xfff7f507,__READ_WRITE,__scictl1_bits);
__IO_REG8_BIT(SCI2CTL2,  0xfff7f50b,__READ_WRITE,__scictl2_bits);
__IO_REG8_BIT(SCI2CTL3,  0xfff7f50f,__READ_WRITE,__scictl3_bits);
__IO_REG8_BIT(SCI2RXST,  0xfff7f513,__READ_WRITE,__scirxst_bits);
__IO_REG8(    SCI2HBAUD, 0xfff7f517,__READ_WRITE);
__IO_REG8(    SCI2MBAUD, 0xfff7f51b,__READ_WRITE);
__IO_REG8(    SCI2LBAUD, 0xfff7f51f,__READ_WRITE);
__IO_REG8(    SCI2RXEMU, 0xfff7f523,__READ_WRITE);
__IO_REG8(    SCI2RXBUF, 0xfff7f527,__READ_WRITE);
__IO_REG8(    SCI2TXBUF, 0xfff7f52b,__READ_WRITE);
__IO_REG8_BIT(SCI2PC1,   0xfff7f52f,__READ_WRITE,__scipc1_bits);
__IO_REG8_BIT(SCI2PC2,   0xfff7f533,__READ_WRITE,__scipc2_bits);
__IO_REG8_BIT(SCI2PC3,   0xfff7f537,__READ_WRITE,__scipc3_bits);

/***************************************************************************
 **
 ** SCI3
 **
 ***************************************************************************/

__IO_REG8_BIT(SCI3CCR,   0xfff7f603,__READ_WRITE,__sciccr_bits);
__IO_REG8_BIT(SCI3CTL1,  0xfff7f607,__READ_WRITE,__scictl1_bits);
__IO_REG8_BIT(SCI3CTL2,  0xfff7f60b,__READ_WRITE,__scictl2_bits);
__IO_REG8_BIT(SCI3CTL3,  0xfff7f60f,__READ_WRITE,__scictl3_bits);
__IO_REG8_BIT(SCI3RXST,  0xfff7f613,__READ_WRITE,__scirxst_bits);
__IO_REG8(    SCI3HBAUD, 0xfff7f617,__READ_WRITE);
__IO_REG8(    SCI3MBAUD, 0xfff7f61b,__READ_WRITE);
__IO_REG8(    SCI3LBAUD, 0xfff7f61f,__READ_WRITE);
__IO_REG8(    SCI3RXEMU, 0xfff7f623,__READ_WRITE);
__IO_REG8(    SCI3RXBUF, 0xfff7f627,__READ_WRITE);
__IO_REG8(    SCI3TXBUF, 0xfff7f62b,__READ_WRITE);
__IO_REG8_BIT(SCI3PC1,   0xfff7f62f,__READ_WRITE,__scipc1_bits);
__IO_REG8_BIT(SCI3PC2,   0xfff7f633,__READ_WRITE,__scipc2_bits);
__IO_REG8_BIT(SCI3PC3,   0xfff7f637,__READ_WRITE,__scipc3_bits);

/***************************************************************************
 **
 ** MibADC
 **
 ***************************************************************************/
__IO_REG16_BIT(ADCR1,    0xfff7f002,__READ_WRITE,__adccr1_bits);
__IO_REG16_BIT(ADCR2,    0xfff7f006,__READ_WRITE,__adccr2_bits);
__IO_REG16_BIT(ADSR,     0xfff7f00a,__READ_WRITE,__adsr_bits);
__IO_REG16(    ADEISR,   0xfff7f00e,__READ_WRITE);
__IO_REG16(    ADISR1,   0xfff7f012,__READ_WRITE);
__IO_REG16(    ADISR2,   0xfff7f016,__READ_WRITE);
__IO_REG16_BIT(ADCALR,   0xfff7f01a,__READ_WRITE,__adcalr_bits);
__IO_REG16_BIT(ADDR0,    0xfff7f01e,__READ_WRITE,__addr_bits);

__IO_REG16_BIT(ADEMDR0,  0xfff7f022,__READ_WRITE,__ademdr014adbufe_bits);
__IO_REG16_BIT(ADDR1,    0xfff7f026,__READ_WRITE,__addr_bits);
__IO_REG16_BIT(ADEMDR1,  0xfff7f02a,__READ_WRITE,__ademdr_bits);
__IO_REG16_BIT(ADDR2,    0xfff7f02e,__READ_WRITE,__addr_bits);
__IO_REG16_BIT(ADEMDR2,  0xfff7f032,__READ_WRITE,__ademdr_bits);
__IO_REG16_BIT(ADDR3,    0xfff7f036,__READ_WRITE,__addr_bits);
__IO_REG16_BIT(ADEMDR3,  0xfff7f03a,__READ_WRITE,__ademdr_bits);
__IO_REG16_BIT(ADDR4,    0xfff7f03e,__READ_WRITE,__addr_bits);
__IO_REG16_BIT(ADEMDR4,  0xfff7f042,__READ_WRITE,__ademdr4adbuf1_bits);
__IO_REG16_BIT(ADDR5,    0xfff7f046,__READ_WRITE,__addr_bits);
__IO_REG16_BIT(ADEMDR5,  0xfff7f04a,__READ_WRITE,__ademdr_bits);
__IO_REG16_BIT(ADDR6,    0xfff7f04e,__READ_WRITE,__addr_bits);
__IO_REG16_BIT(ADEMDR6,  0xfff7f052,__READ_WRITE,__ademdr_bits);
__IO_REG16_BIT(ADDR7,    0xfff7f056,__READ_WRITE,__addr_bits);
__IO_REG16_BIT(ADEMDR7,  0xfff7f05a,__READ_WRITE,__ademdr_bits);
__IO_REG16_BIT(ADDR8,    0xfff7f05e,__READ_WRITE,__addr_bits);
__IO_REG16_BIT(ADEMDR8,  0xfff7f062,__READ_WRITE,__ademdr815adbuf2_bits);
__IO_REG16_BIT(ADDR9,    0xfff7f066,__READ_WRITE,__addr_bits);
__IO_REG16_BIT(ADEMDR9,  0xfff7f06a,__READ_WRITE,__ademdr_bits);
__IO_REG16_BIT(ADDR10,   0xfff7f06e,__READ_WRITE,__addr_bits);
__IO_REG16_BIT(ADEMDR10, 0xfff7f072,__READ_WRITE,__ademdr_bits);
__IO_REG16_BIT(ADDR11,   0xfff7f076,__READ_WRITE,__addr_bits);
__IO_REG16_BIT(ADEMDR11, 0xfff7f07a,__READ_WRITE,__ademdr_bits);
__IO_REG16_BIT(ADDR12,   0xfff7f07e,__READ_WRITE,__addr_bits);
__IO_REG16_BIT(ADEMDR12, 0xfff7f082,__READ_WRITE,__ademdr_bits);
__IO_REG16_BIT(ADDR13,   0xfff7f086,__READ_WRITE,__addr_bits);
__IO_REG16_BIT(ADEMDR13, 0xfff7f08a,__READ_WRITE,__ademdr_bits);
__IO_REG16_BIT(ADDR14,   0xfff7f08e,__READ_WRITE,__addr_bits);
__IO_REG16_BIT(ADEMDR14, 0xfff7f092,__READ_WRITE,__ademdr014adbufe_bits);
__IO_REG16_BIT(ADDR15,   0xfff7f096,__READ_WRITE,__addr15ademubuf1_bits);
__IO_REG16_BIT(ADEMDR15, 0xfff7f09a,__READ_WRITE,__ademdr815adbuf2_bits);

/*
 * These registers are used in buffered mode only. They have the same
 * addresses as some of the registers in compatibility mode.
 */
#define ADBUFE    ADEMDR0
#define ADBUF1    ADEMDR4
#define ADBUF2    ADEMDR8
#define ADEMUBUFE ADEMDR14
#define ADEMUBUF1 ADDR15
#define ADEMUBUF2 ADEMDR15

__IO_REG16(    ADINR,    0xfff7f09e,__READ_WRITE);
__IO_REG16_BIT(ADCPCR,   0xfff7f0a2,__READ_WRITE,__adcpcr_bits);

__IO_REG16_BIT(ADSAMPEV, 0xfff7f0b2,__READ_WRITE,__adsampev_bits);
__IO_REG16_BIT(ADSAMP1,  0xfff7f0b6,__READ_WRITE,__adsamp1_bits);
__IO_REG16_BIT(ADSAMP2,  0xfff7f0ba,__READ_WRITE,__adsamp2_bits);
__IO_REG16_BIT(ADBCR1,   0xfff7f0be,__READ_WRITE,__adbcr1_bits);
__IO_REG16_BIT(ADBCR2,   0xfff7f0c2,__READ_WRITE,__adbcr2_bits);
__IO_REG16_BIT(ADBCR3,   0xfff7f0c6,__READ_WRITE,__adbcr3_bits);
__IO_REG16_BIT(ADBUFST,  0xfff7f0ca,__READ_WRITE,__adbufst_bits);
__IO_REG16_BIT(ADTHREV,  0xfff7f0ce,__READ_WRITE,__adthrev_bits);
__IO_REG16_BIT(ADTHRG1,  0xfff7f0d2,__READ_WRITE,__adthrg1_bits);
__IO_REG16_BIT(ADTHRG2,  0xfff7f0d6,__READ_WRITE,__adthrg2_bits);
__IO_REG16_BIT(ADEVTSRC, 0xfff7f0da,__READ_WRITE,__adevtsrc_bits);

/***************************************************************************
 **
 ** ECP
 **
 ***************************************************************************/

__IO_REG16_BIT(ECPCTRL,  0xfff7ef02,__READ_WRITE,__ecpctrl_bits);

/***************************************************************************
 **
 ** EBM
 **
 ***************************************************************************/

__IO_REG8(    EBDMACR,0xfff7ed03,__READ_WRITE);
__IO_REG8_BIT(EBRWCR, 0xfff7ed07,__READ_WRITE, __ebrwcr_bits);
__IO_REG8_BIT(EBACR1, 0xfff7ed0b,__READ_WRITE, __ebacr1_bits);
__IO_REG8(    EBDCR,  0xfff7ed0f,__READ_WRITE);
__IO_REG8(    EBADCR, 0xfff7ed13,__READ_WRITE);
__IO_REG8(    EBACR2, 0xfff7ed17,__READ_WRITE);
__IO_REG8(    EBACR3, 0xfff7ed1b,__READ_WRITE);
__IO_REG8_BIT(EBMCR1, 0xfff7ed1f,__READ_WRITE,  __ebmcr1_bits);


/***************************************************************************
 **
 ** GIO
 **
 ***************************************************************************/

__IO_REG32_BIT(GIOPWDN,  0xfff7ec00,__READ_WRITE,__giopwdn_bits);
__IO_REG32_BIT(GIOENA1,  0xfff7ec04,__READ_WRITE,__gioena1_bits);
__IO_REG32_BIT(GIOPOL1,  0xfff7ec08,__READ_WRITE,__giopol1_bits);
__IO_REG32_BIT(GIOFLG1,  0xfff7ec0c,__READ_WRITE,__gioflg1_bits);
__IO_REG32_BIT(GIOPRY1,  0xfff7ec10,__READ_WRITE,__giopry1_bits);
__IO_REG32_BIT(GIOOFFA,  0xfff7ec14,__READ_WRITE,__giooffa_bits);
__IO_REG32_BIT(GIOEMUA,  0xfff7ec18,__READ_WRITE,__gioemua_bits);
__IO_REG32_BIT(GIOOFFB,  0xfff7ec1c,__READ_WRITE,__giooffb_bits);
__IO_REG32_BIT(GIOEMUB,  0xfff7ec20,__READ_WRITE,__gioemub_bits);
__IO_REG32_BIT(GIODIRA,  0xfff7ec24,__READ_WRITE,__giodir_bits);
__IO_REG32_BIT(GIODINA,  0xfff7ec28,__READ_WRITE,__giodin_bits);
__IO_REG32_BIT(GIODOUTA, 0xfff7ec2c,__READ_WRITE,__giodout_bits);
__IO_REG32_BIT(GIODSETA, 0xfff7ec30,__READ_WRITE,__giodset_bits);
__IO_REG32_BIT(GIODCLRA, 0xfff7ec34,__READ_WRITE,__giodclr_bits);
__IO_REG32_BIT(GIODIRB,  0xfff7ec38,__READ_WRITE,__giodir_bits);
__IO_REG32_BIT(GIODINB,  0xfff7ec3c,__READ_WRITE,__giodin_bits);
__IO_REG32_BIT(GIODOUTB, 0xfff7ec40,__READ_WRITE,__giodout_bits);
__IO_REG32_BIT(GIODSETB, 0xfff7ec44,__READ_WRITE,__giodset_bits);
__IO_REG32_BIT(GIODCLRB, 0xfff7ec48,__READ_WRITE,__giodclr_bits);
__IO_REG32_BIT(GIODIRC,  0xfff7ec4c,__READ_WRITE,__giodir_bits);
__IO_REG32_BIT(GIODINC,  0xfff7ec50,__READ_WRITE,__giodin_bits);
__IO_REG32_BIT(GIODOUTC, 0xfff7ec54,__READ_WRITE,__giodout_bits);
__IO_REG32_BIT(GIODSETC, 0xfff7ec58,__READ_WRITE,__giodset_bits);
__IO_REG32_BIT(GIODCLRC, 0xfff7ec5c,__READ_WRITE,__giodclr_bits);
__IO_REG32_BIT(GIODIRD,  0xfff7ec60,__READ_WRITE,__giodir_bits);
__IO_REG32_BIT(GIODIND,  0xfff7ec64,__READ_WRITE,__giodin_bits);
__IO_REG32_BIT(GIODOUTD, 0xfff7ec68,__READ_WRITE,__giodout_bits);
__IO_REG32_BIT(GIODSETD, 0xfff7ec6c,__READ_WRITE,__giodset_bits);
__IO_REG32_BIT(GIODCLRD, 0xfff7ec70,__READ_WRITE,__giodclr_bits);
__IO_REG32_BIT(GIODIRE,  0xfff7ec74,__READ_WRITE,__giodir_bits);
__IO_REG32_BIT(GIODINE,  0xfff7ec78,__READ_WRITE,__giodin_bits);
__IO_REG32_BIT(GIODOUTE, 0xfff7ec7c,__READ_WRITE,__giodout_bits);
__IO_REG32_BIT(GIODSETE, 0xfff7ec80,__READ_WRITE,__giodset_bits);
__IO_REG32_BIT(GIODCLRE, 0xfff7ec84,__READ_WRITE,__giodclr_bits);
__IO_REG32_BIT(GIODIRF,  0xfff7ec88,__READ_WRITE,__giodir_bits);
__IO_REG32_BIT(GIODINF,  0xfff7ec8c,__READ_WRITE,__giodin_bits);
__IO_REG32_BIT(GIODOUTF, 0xfff7ec90,__READ_WRITE,__giodout_bits);
__IO_REG32_BIT(GIODSETF, 0xfff7ec94,__READ_WRITE,__giodset_bits);
__IO_REG32_BIT(GIODCLRF, 0xfff7ec98,__READ_WRITE,__giodclr_bits);
__IO_REG32_BIT(GIODIRG,  0xfff7ec9c,__READ_WRITE,__giodir_bits);
__IO_REG32_BIT(GIODING,  0xfff7eca0,__READ_WRITE,__giodin_bits);
__IO_REG32_BIT(GIODOUTG, 0xfff7eca4,__READ_WRITE,__giodout_bits);
__IO_REG32_BIT(GIODSETG, 0xfff7eca8,__READ_WRITE,__giodset_bits);
__IO_REG32_BIT(GIODCLRG, 0xfff7ecac,__READ_WRITE,__giodclr_bits);
__IO_REG32_BIT(GIODIRH,  0xfff7ecb0,__READ_WRITE,__giodir_bits);
__IO_REG32_BIT(GIODINH,  0xfff7ecb4,__READ_WRITE,__giodin_bits);
__IO_REG32_BIT(GIODOUTH, 0xfff7ecb8,__READ_WRITE,__giodout_bits);
__IO_REG32_BIT(GIODSETH, 0xfff7ecbc,__READ_WRITE,__giodset_bits);
__IO_REG32_BIT(GIODCLRH, 0xfff7ecc0,__READ_WRITE,__giodclr_bits);



__IO_REG32_BIT(GIOENA2,  0xfff7ecc4,__READ_WRITE,__gioena1_bits);
__IO_REG32_BIT(GIOPOL2,  0xfff7ecc8,__READ_WRITE,__giopol1_bits);
__IO_REG32_BIT(GIOFLG2,  0xfff7eccc,__READ_WRITE,__gioflg1_bits);
__IO_REG32_BIT(GIOPRY2,  0xfff7ecd0,__READ_WRITE,__giopry1_bits);









/***************************************************************************
 **
 ** SCC
 **
 ***************************************************************************/

__IO_REG32(    SCCCANME,   0xfff7e000,__READ_WRITE);
__IO_REG32(    SCCCANMD,   0xfff7e004,__READ_WRITE);
__IO_REG32(    SCCCANTRS,  0xfff7e008,__READ_WRITE);
__IO_REG32(    SCCCANTRR,  0xfff7e00c,__READ_WRITE);
__IO_REG32(    SCCCANTA,   0xfff7e010,__READ_WRITE);
__IO_REG32(    SCCCANAA,   0xfff7e014,__READ_WRITE);
__IO_REG32(    SCCCANRMP,  0xfff7e018,__READ_WRITE);
__IO_REG32(    SCCCANRML,  0xfff7e01c,__READ_WRITE);
__IO_REG32(    SCCCANRFP,  0xfff7e020,__READ_WRITE);
__IO_REG32_BIT(SCCCANGAM,  0xfff7e024,__READ_WRITE,__cangam_bits);
__IO_REG32_BIT(SCCCANMC,   0xfff7e028,__READ_WRITE,__canmc_bits);
__IO_REG32_BIT(SCCCANBTC,  0xfff7e02c,__READ_WRITE,__canbtc_bits);
__IO_REG32_BIT(SCCCANES,   0xfff7e030,__READ_WRITE,__canes_bits);
__IO_REG32_BIT(SCCCANTEC,  0xfff7e034,__READ_WRITE,__cantec_bits);
__IO_REG32_BIT(SCCCANREC,  0xfff7e038,__READ_WRITE,__canrec_bits);
__IO_REG32_BIT(SCCCANGIF0, 0xfff7e03c,__READ_WRITE,__cangif_bits);
__IO_REG32_BIT(SCCCANGIM,  0xfff7e040,__READ_WRITE,__cangim_bits);
__IO_REG32_BIT(SCCCANGIF1, 0xfff7e044,__READ_WRITE,__cangif_bits);
__IO_REG32(    SCCCANMIM,  0xfff7e048,__READ_WRITE);
__IO_REG32(    SCCCANMIL,  0xfff7e04c,__READ_WRITE);
__IO_REG32(    SCCCANOPC,  0xfff7e050,__READ_WRITE);
__IO_REG32_BIT(SCCCANTIOC, 0xfff7e054,__READ_WRITE,__cantioc_bits);
__IO_REG32_BIT(SCCCANRIOC, 0xfff7e058,__READ_WRITE,__canrioc_bits);

/***************************************************************************
 **
 ** SCC RAM
 **
 ***************************************************************************/

__IO_REG32_BIT(    SCCCANMID0 ,  0xfff7dc00,__READ_WRITE, __mid_bits);  /* Message identifier */
__IO_REG32_BIT(    SCCCANMID1 ,  0xfff7dc10,__READ_WRITE, __mid_bits);
__IO_REG32_BIT(    SCCCANMID2 ,  0xfff7dc20,__READ_WRITE, __mid_bits);
__IO_REG32_BIT(    SCCCANMID3 ,  0xfff7dc30,__READ_WRITE, __mid_bits);
__IO_REG32_BIT(    SCCCANMID4 ,  0xfff7dc40,__READ_WRITE, __mid_bits);
__IO_REG32_BIT(    SCCCANMID5 ,  0xfff7dc50,__READ_WRITE, __mid_bits);
__IO_REG32_BIT(    SCCCANMID6 ,  0xfff7dc60,__READ_WRITE, __mid_bits);
__IO_REG32_BIT(    SCCCANMID7 ,  0xfff7dc70,__READ_WRITE, __mid_bits);
__IO_REG32_BIT(    SCCCANMID8 ,  0xfff7dc80,__READ_WRITE, __mid_bits);
__IO_REG32_BIT(    SCCCANMID9 ,  0xfff7dc90,__READ_WRITE, __mid_bits);
__IO_REG32_BIT(    SCCCANMID10,  0xfff7dca0,__READ_WRITE, __mid_bits);
__IO_REG32_BIT(    SCCCANMID11,  0xfff7dcb0,__READ_WRITE, __mid_bits);
__IO_REG32_BIT(    SCCCANMID12,  0xfff7dcc0,__READ_WRITE, __mid_bits);
__IO_REG32_BIT(    SCCCANMID13,  0xfff7dcd0,__READ_WRITE, __mid_bits);
__IO_REG32_BIT(    SCCCANMID14,  0xfff7dce0,__READ_WRITE, __mid_bits);
__IO_REG32_BIT(    SCCCANMID15,  0xfff7dcf0,__READ_WRITE, __mid_bits);
__IO_REG32_BIT(    SCCCANMCF0 ,  0xfff7dc04,__READ_WRITE, __mcf_bits);  /* Message control field */
__IO_REG32_BIT(    SCCCANMCF1 ,  0xfff7dc14,__READ_WRITE, __mcf_bits);
__IO_REG32_BIT(    SCCCANMCF2 ,  0xfff7dc24,__READ_WRITE, __mcf_bits);
__IO_REG32_BIT(    SCCCANMCF3 ,  0xfff7dc34,__READ_WRITE, __mcf_bits);
__IO_REG32_BIT(    SCCCANMCF4 ,  0xfff7dc44,__READ_WRITE, __mcf_bits);
__IO_REG32_BIT(    SCCCANMCF5 ,  0xfff7dc54,__READ_WRITE, __mcf_bits);
__IO_REG32_BIT(    SCCCANMCF6 ,  0xfff7dc64,__READ_WRITE, __mcf_bits);
__IO_REG32_BIT(    SCCCANMCF7 ,  0xfff7dc74,__READ_WRITE, __mcf_bits);
__IO_REG32_BIT(    SCCCANMCF8 ,  0xfff7dc84,__READ_WRITE, __mcf_bits);
__IO_REG32_BIT(    SCCCANMCF9 ,  0xfff7dc94,__READ_WRITE, __mcf_bits);
__IO_REG32_BIT(    SCCCANMCF10,  0xfff7dca4,__READ_WRITE, __mcf_bits);
__IO_REG32_BIT(    SCCCANMCF11,  0xfff7dcb4,__READ_WRITE, __mcf_bits);
__IO_REG32_BIT(    SCCCANMCF12,  0xfff7dcc4,__READ_WRITE, __mcf_bits);
__IO_REG32_BIT(    SCCCANMCF13,  0xfff7dcd4,__READ_WRITE, __mcf_bits);
__IO_REG32_BIT(    SCCCANMCF14,  0xfff7dce4,__READ_WRITE, __mcf_bits);
__IO_REG32_BIT(    SCCCANMCF15,  0xfff7dcf4,__READ_WRITE, __mcf_bits);
__IO_REG32(    SCCCANMDL0 ,  0xfff7dc08,__READ_WRITE);  /* Message data low word */
__IO_REG32(    SCCCANMDL1 ,  0xfff7dc18,__READ_WRITE);
__IO_REG32(    SCCCANMDL2 ,  0xfff7dc28,__READ_WRITE);
__IO_REG32(    SCCCANMDL3 ,  0xfff7dc38,__READ_WRITE);
__IO_REG32(    SCCCANMDL4 ,  0xfff7dc48,__READ_WRITE);
__IO_REG32(    SCCCANMDL5 ,  0xfff7dc58,__READ_WRITE);
__IO_REG32(    SCCCANMDL6 ,  0xfff7dc68,__READ_WRITE);
__IO_REG32(    SCCCANMDL7 ,  0xfff7dc78,__READ_WRITE);
__IO_REG32(    SCCCANMDL8 ,  0xfff7dc88,__READ_WRITE);
__IO_REG32(    SCCCANMDL9 ,  0xfff7dc98,__READ_WRITE);
__IO_REG32(    SCCCANMDL10,  0xfff7dca8,__READ_WRITE);
__IO_REG32(    SCCCANMDL11,  0xfff7dcb8,__READ_WRITE);
__IO_REG32(    SCCCANMDL12,  0xfff7dcc8,__READ_WRITE);
__IO_REG32(    SCCCANMDL13,  0xfff7dcd8,__READ_WRITE);
__IO_REG32(    SCCCANMDL14,  0xfff7dce8,__READ_WRITE);
__IO_REG32(    SCCCANMDL15,  0xfff7dcf8,__READ_WRITE);
__IO_REG32(    SCCCANMDH0 ,  0xfff7dc0c,__READ_WRITE);  /* Message data high word */
__IO_REG32(    SCCCANMDH1 ,  0xfff7dc1c,__READ_WRITE);
__IO_REG32(    SCCCANMDH2 ,  0xfff7dc2c,__READ_WRITE);
__IO_REG32(    SCCCANMDH3 ,  0xfff7dc3c,__READ_WRITE);
__IO_REG32(    SCCCANMDH4 ,  0xfff7dc4c,__READ_WRITE);
__IO_REG32(    SCCCANMDH5 ,  0xfff7dc5c,__READ_WRITE);
__IO_REG32(    SCCCANMDH6 ,  0xfff7dc6c,__READ_WRITE);
__IO_REG32(    SCCCANMDH7 ,  0xfff7dc7c,__READ_WRITE);
__IO_REG32(    SCCCANMDH8 ,  0xfff7dc8c,__READ_WRITE);
__IO_REG32(    SCCCANMDH9 ,  0xfff7dc9c,__READ_WRITE);
__IO_REG32(    SCCCANMDH10,  0xfff7dcac,__READ_WRITE);
__IO_REG32(    SCCCANMDH11,  0xfff7dcbc,__READ_WRITE);
__IO_REG32(    SCCCANMDH12,  0xfff7dccc,__READ_WRITE);
__IO_REG32(    SCCCANMDH13,  0xfff7dcdc,__READ_WRITE);
__IO_REG32(    SCCCANMDH14,  0xfff7dcec,__READ_WRITE);
__IO_REG32(    SCCCANMDH15,  0xfff7dcfc,__READ_WRITE);

#define SCC_RAM_OFFSET 0xFFF7DC00

/***************************************************************************
 **
 ** HECC 1
 **
 ***************************************************************************/

__IO_REG32(    HECC1CANME,   0xfff7e800,__READ_WRITE);
__IO_REG32(    HECC1CANMD,   0xfff7e804,__READ_WRITE);
__IO_REG32(    HECC1CANTRS,  0xfff7e808,__READ_WRITE);
__IO_REG32(    HECC1CANTRR,  0xfff7e80c,__READ_WRITE);
__IO_REG32(    HECC1CANTA,   0xfff7e810,__READ_WRITE);
__IO_REG32(    HECC1CANAA,   0xfff7e814,__READ_WRITE);
__IO_REG32(    HECC1CANRMP,  0xfff7e818,__READ_WRITE);
__IO_REG32(    HECC1CANRML,  0xfff7e81c,__READ_WRITE);
__IO_REG32(    HECC1CANRFP,  0xfff7e820,__READ_WRITE);
__IO_REG32_BIT(HECC1CANGAM,  0xfff7e824,__READ_WRITE,__cangam_bits);
__IO_REG32_BIT(HECC1CANMC,   0xfff7e828,__READ_WRITE,__canmc_bits);
__IO_REG32_BIT(HECC1CANBTC,  0xfff7e82c,__READ_WRITE,__canbtc_bits);
__IO_REG32_BIT(HECC1CANES,   0xfff7e830,__READ_WRITE,__canes_bits);
__IO_REG32_BIT(HECC1CANTEC,  0xfff7e834,__READ_WRITE,__cantec_bits);
__IO_REG32_BIT(HECC1CANREC,  0xfff7e838,__READ_WRITE,__canrec_bits);
__IO_REG32_BIT(HECC1CANGIF0, 0xfff7e83c,__READ_WRITE,__cangif_bits);
__IO_REG32_BIT(HECC1CANGIM,  0xfff7e840,__READ_WRITE,__cangim_bits);
__IO_REG32_BIT(HECC1CANGIF1, 0xfff7e844,__READ_WRITE,__cangif_bits);
__IO_REG32(    HECC1CANMIM,  0xfff7e848,__READ_WRITE);
__IO_REG32(    HECC1CANMIL,  0xfff7e84c,__READ_WRITE);
__IO_REG32(    HECC1CANOPC,  0xfff7e850,__READ_WRITE);
__IO_REG32_BIT(HECC1CANTIOC, 0xfff7e854,__READ_WRITE,__cantioc_bits);
__IO_REG32_BIT(HECC1CANRIOC, 0xfff7e858,__READ_WRITE,__canrioc_bits);
__IO_REG32(    HECC1CANLNT,  0xfff7e85c,__READ_WRITE);
__IO_REG32(    HECC1CANTOC,  0xfff7e860,__READ_WRITE);
__IO_REG32(    HECC1CANTOS,  0xfff7e864,__READ_WRITE);

__IO_REG32(    HECC1CANLAM0, 0xfff7e880,__READ_WRITE);
__IO_REG32(    HECC1CANLAM1, 0xfff7e884,__READ_WRITE);
__IO_REG32(    HECC1CANLAM2, 0xfff7e888,__READ_WRITE);
__IO_REG32(    HECC1CANLAM3, 0xfff7e88c,__READ_WRITE);
__IO_REG32(    HECC1CANLAM4, 0xfff7e890,__READ_WRITE);
__IO_REG32(    HECC1CANLAM5, 0xfff7e894,__READ_WRITE);
__IO_REG32(    HECC1CANLAM6, 0xfff7e898,__READ_WRITE);
__IO_REG32(    HECC1CANLAM7, 0xfff7e89c,__READ_WRITE);
__IO_REG32(    HECC1CANLAM8, 0xfff7e8a0,__READ_WRITE);
__IO_REG32(    HECC1CANLAM9, 0xfff7e8a4,__READ_WRITE);
__IO_REG32(    HECC1CANLAM10, 0xfff7e8a8,__READ_WRITE);
__IO_REG32(    HECC1CANLAM11, 0xfff7e8ac,__READ_WRITE);
__IO_REG32(    HECC1CANLAM12, 0xfff7e8b0,__READ_WRITE);
__IO_REG32(    HECC1CANLAM13, 0xfff7e8b4,__READ_WRITE);
__IO_REG32(    HECC1CANLAM14, 0xfff7e8b8,__READ_WRITE);
__IO_REG32(    HECC1CANLAM15, 0xfff7e8bc,__READ_WRITE);
__IO_REG32(    HECC1CANLAM16, 0xfff7e8c0,__READ_WRITE);
__IO_REG32(    HECC1CANLAM17, 0xfff7e8c4,__READ_WRITE);
__IO_REG32(    HECC1CANLAM18, 0xfff7e8c8,__READ_WRITE);
__IO_REG32(    HECC1CANLAM19, 0xfff7e8cc,__READ_WRITE);
__IO_REG32(    HECC1CANLAM20, 0xfff7e8d0,__READ_WRITE);
__IO_REG32(    HECC1CANLAM21, 0xfff7e8d4,__READ_WRITE);
__IO_REG32(    HECC1CANLAM22, 0xfff7e8d8,__READ_WRITE);
__IO_REG32(    HECC1CANLAM23, 0xfff7e8dc,__READ_WRITE);
__IO_REG32(    HECC1CANLAM24, 0xfff7e8e0,__READ_WRITE);
__IO_REG32(    HECC1CANLAM25, 0xfff7e8e4,__READ_WRITE);
__IO_REG32(    HECC1CANLAM26, 0xfff7e8e8,__READ_WRITE);
__IO_REG32(    HECC1CANLAM27, 0xfff7e8ec,__READ_WRITE);
__IO_REG32(    HECC1CANLAM28, 0xfff7e9f0,__READ_WRITE);
__IO_REG32(    HECC1CANLAM29, 0xfff7e9f4,__READ_WRITE);
__IO_REG32(    HECC1CANLAM30, 0xfff7e9f8,__READ_WRITE);
__IO_REG32(    HECC1CANLAM31, 0xfff7e9fc,__READ_WRITE);




/***************************************************************************
 **
 ** HECC 1 RAM
 **
 ***************************************************************************/

__IO_REG32_BIT(    HECC1CANMID0 ,  0xfff7e400,__READ_WRITE,  __mid_bits);  /* Message identifier */
__IO_REG32_BIT(    HECC1CANMID1 ,  0xfff7e410,__READ_WRITE,  __mid_bits);
__IO_REG32_BIT(    HECC1CANMID2 ,  0xfff7e420,__READ_WRITE,  __mid_bits);
__IO_REG32_BIT(    HECC1CANMID3 ,  0xfff7e430,__READ_WRITE,  __mid_bits);
__IO_REG32_BIT(    HECC1CANMID4 ,  0xfff7e440,__READ_WRITE,  __mid_bits);
__IO_REG32_BIT(    HECC1CANMID5 ,  0xfff7e450,__READ_WRITE,  __mid_bits);
__IO_REG32_BIT(    HECC1CANMID6 ,  0xfff7e460,__READ_WRITE,  __mid_bits);
__IO_REG32_BIT(    HECC1CANMID7 ,  0xfff7e470,__READ_WRITE,  __mid_bits);
__IO_REG32_BIT(    HECC1CANMID8 ,  0xfff7e480,__READ_WRITE,  __mid_bits);
__IO_REG32_BIT(    HECC1CANMID9 ,  0xfff7e490,__READ_WRITE,  __mid_bits);
__IO_REG32_BIT(    HECC1CANMID10,  0xfff7e4a0,__READ_WRITE,  __mid_bits);
__IO_REG32_BIT(    HECC1CANMID11,  0xfff7e4b0,__READ_WRITE,  __mid_bits);
__IO_REG32_BIT(    HECC1CANMID12,  0xfff7e4c0,__READ_WRITE,  __mid_bits);
__IO_REG32_BIT(    HECC1CANMID13,  0xfff7e4d0,__READ_WRITE,  __mid_bits);
__IO_REG32_BIT(    HECC1CANMID14,  0xfff7e4e0,__READ_WRITE,  __mid_bits);
__IO_REG32_BIT(    HECC1CANMID15,  0xfff7e4f0,__READ_WRITE,  __mid_bits);
__IO_REG32_BIT(    HECC1CANMCF0 ,  0xfff7e404,__READ_WRITE, __mcf_bits);  /* Message control field */
__IO_REG32_BIT(    HECC1CANMCF1 ,  0xfff7e414,__READ_WRITE, __mcf_bits);
__IO_REG32_BIT(    HECC1CANMCF2 ,  0xfff7e424,__READ_WRITE, __mcf_bits);
__IO_REG32_BIT(    HECC1CANMCF3 ,  0xfff7e434,__READ_WRITE, __mcf_bits);
__IO_REG32_BIT(    HECC1CANMCF4 ,  0xfff7e444,__READ_WRITE, __mcf_bits);
__IO_REG32_BIT(    HECC1CANMCF5 ,  0xfff7e454,__READ_WRITE, __mcf_bits);
__IO_REG32_BIT(    HECC1CANMCF6 ,  0xfff7e464,__READ_WRITE, __mcf_bits);
__IO_REG32_BIT(    HECC1CANMCF7 ,  0xfff7e474,__READ_WRITE, __mcf_bits);
__IO_REG32_BIT(    HECC1CANMCF8 ,  0xfff7e484,__READ_WRITE, __mcf_bits);
__IO_REG32_BIT(    HECC1CANMCF9 ,  0xfff7e494,__READ_WRITE, __mcf_bits);
__IO_REG32_BIT(    HECC1CANMCF10,  0xfff7e4a4,__READ_WRITE, __mcf_bits);
__IO_REG32_BIT(    HECC1CANMCF11,  0xfff7e4b4,__READ_WRITE, __mcf_bits);
__IO_REG32_BIT(    HECC1CANMCF12,  0xfff7e4c4,__READ_WRITE, __mcf_bits);
__IO_REG32_BIT(    HECC1CANMCF13,  0xfff7e4d4,__READ_WRITE, __mcf_bits);
__IO_REG32_BIT(    HECC1CANMCF14,  0xfff7e4e4,__READ_WRITE, __mcf_bits);
__IO_REG32_BIT(    HECC1CANMCF15,  0xfff7e4f4,__READ_WRITE, __mcf_bits);
__IO_REG32(    HECC1CANMDL0 ,  0xfff7e408,__READ_WRITE);  /* Message data low word */
__IO_REG32(    HECC1CANMDL1 ,  0xfff7e418,__READ_WRITE);
__IO_REG32(    HECC1CANMDL2 ,  0xfff7e428,__READ_WRITE);
__IO_REG32(    HECC1CANMDL3 ,  0xfff7e438,__READ_WRITE);
__IO_REG32(    HECC1CANMDL4 ,  0xfff7e448,__READ_WRITE);
__IO_REG32(    HECC1CANMDL5 ,  0xfff7e458,__READ_WRITE);
__IO_REG32(    HECC1CANMDL6 ,  0xfff7e468,__READ_WRITE);
__IO_REG32(    HECC1CANMDL7 ,  0xfff7e478,__READ_WRITE);
__IO_REG32(    HECC1CANMDL8 ,  0xfff7e488,__READ_WRITE);
__IO_REG32(    HECC1CANMDL9 ,  0xfff7e498,__READ_WRITE);
__IO_REG32(    HECC1CANMDL10,  0xfff7e4a8,__READ_WRITE);
__IO_REG32(    HECC1CANMDL11,  0xfff7e4b8,__READ_WRITE);
__IO_REG32(    HECC1CANMDL12,  0xfff7e4c8,__READ_WRITE);
__IO_REG32(    HECC1CANMDL13,  0xfff7e4d8,__READ_WRITE);
__IO_REG32(    HECC1CANMDL14,  0xfff7e4e8,__READ_WRITE);
__IO_REG32(    HECC1CANMDL15,  0xfff7e4f8,__READ_WRITE);
__IO_REG32(    HECC1CANMDH0 ,  0xfff7e40c,__READ_WRITE);  /* Message data high word */
__IO_REG32(    HECC1CANMDH1 ,  0xfff7e41c,__READ_WRITE);
__IO_REG32(    HECC1CANMDH2 ,  0xfff7e42c,__READ_WRITE);
__IO_REG32(    HECC1CANMDH3 ,  0xfff7e43c,__READ_WRITE);
__IO_REG32(    HECC1CANMDH4 ,  0xfff7e44c,__READ_WRITE);
__IO_REG32(    HECC1CANMDH5 ,  0xfff7e45c,__READ_WRITE);
__IO_REG32(    HECC1CANMDH6 ,  0xfff7e46c,__READ_WRITE);
__IO_REG32(    HECC1CANMDH7 ,  0xfff7e47c,__READ_WRITE);
__IO_REG32(    HECC1CANMDH8 ,  0xfff7e48c,__READ_WRITE);
__IO_REG32(    HECC1CANMDH9 ,  0xfff7e49c,__READ_WRITE);
__IO_REG32(    HECC1CANMDH10,  0xfff7e4ac,__READ_WRITE);
__IO_REG32(    HECC1CANMDH11,  0xfff7e4bc,__READ_WRITE);
__IO_REG32(    HECC1CANMDH12,  0xfff7e4cc,__READ_WRITE);
__IO_REG32(    HECC1CANMDH13,  0xfff7e4dc,__READ_WRITE);
__IO_REG32(    HECC1CANMDH14,  0xfff7e4ec,__READ_WRITE);
__IO_REG32(    HECC1CANMDH15,  0xfff7e4fc,__READ_WRITE);

#define HECC1_RAM_OFFSET 0xFFF7e400

/***************************************************************************
 **
 ** HECC 2
 **
 ***************************************************************************/

__IO_REG32(    HECC2CANME,   0xfff7ea00,__READ_WRITE);
__IO_REG32(    HECC2CANMD,   0xfff7ea04,__READ_WRITE);
__IO_REG32(    HECC2CANTRS,  0xfff7ea08,__READ_WRITE);
__IO_REG32(    HECC2CANTRR,  0xfff7ea0c,__READ_WRITE);
__IO_REG32(    HECC2CANTA,   0xfff7ea10,__READ_WRITE);
__IO_REG32(    HECC2CANAA,   0xfff7ea14,__READ_WRITE);
__IO_REG32(    HECC2CANRMP,  0xfff7ea18,__READ_WRITE);
__IO_REG32(    HECC2CANRML,  0xfff7ea1c,__READ_WRITE);
__IO_REG32(    HECC2CANRFP,  0xfff7ea20,__READ_WRITE);
__IO_REG32_BIT(HECC2CANGAM,  0xfff7ea24,__READ_WRITE,__cangam_bits);
__IO_REG32_BIT(HECC2CANMC,   0xfff7ea28,__READ_WRITE,__canmc_bits);
__IO_REG32_BIT(HECC2CANBTC,  0xfff7ea2c,__READ_WRITE,__canbtc_bits);
__IO_REG32_BIT(HECC2CANES,   0xfff7ea30,__READ_WRITE,__canes_bits);
__IO_REG32_BIT(HECC2CANTEC,  0xfff7ea34,__READ_WRITE,__cantec_bits);
__IO_REG32_BIT(HECC2CANREC,  0xfff7ea38,__READ_WRITE,__canrec_bits);
__IO_REG32_BIT(HECC2CANGIF0, 0xfff7ea3c,__READ_WRITE,__cangif_bits);
__IO_REG32_BIT(HECC2CANGIM,  0xfff7ea40,__READ_WRITE,__cangim_bits);
__IO_REG32_BIT(HECC2CANGIF1, 0xfff7ea44,__READ_WRITE,__cangif_bits);
__IO_REG32(    HECC2CANMIM,  0xfff7ea48,__READ_WRITE);
__IO_REG32(    HECC2CANMIL,  0xfff7ea4c,__READ_WRITE);
__IO_REG32(    HECC2CANOPC,  0xfff7ea50,__READ_WRITE);
__IO_REG32_BIT(HECC2CANTIOC, 0xfff7ea54,__READ_WRITE,__cantioc_bits);
__IO_REG32_BIT(HECC2CANRIOC, 0xfff7ea58,__READ_WRITE,__canrioc_bits);
__IO_REG32(    HECC2CANLNT,  0xfff7ea5c,__READ_WRITE);
__IO_REG32(    HECC2CANTOC,  0xfff7ea60,__READ_WRITE);
__IO_REG32(    HECC2CANTOS,  0xfff7ea64,__READ_WRITE);

__IO_REG32(    HECC2CANLAM0, 0xfff7ea80,__READ_WRITE);
__IO_REG32(    HECC2CANLAM1, 0xfff7ea84,__READ_WRITE);
__IO_REG32(    HECC2CANLAM2, 0xfff7ea88,__READ_WRITE);
__IO_REG32(    HECC2CANLAM3, 0xfff7ea8c,__READ_WRITE);
__IO_REG32(    HECC2CANLAM4, 0xfff7ea90,__READ_WRITE);
__IO_REG32(    HECC2CANLAM5, 0xfff7ea94,__READ_WRITE);
__IO_REG32(    HECC2CANLAM6, 0xfff7ea98,__READ_WRITE);
__IO_REG32(    HECC2CANLAM7, 0xfff7ea9c,__READ_WRITE);
__IO_REG32(    HECC2CANLAM8, 0xfff7eaa0,__READ_WRITE);
__IO_REG32(    HECC2CANLAM9, 0xfff7eaa4,__READ_WRITE);
__IO_REG32(    HECC2CANLAM10, 0xfff7a8a8,__READ_WRITE);
__IO_REG32(    HECC2CANLAM11, 0xfff7a8ac,__READ_WRITE);
__IO_REG32(    HECC2CANLAM12, 0xfff7a8b0,__READ_WRITE);
__IO_REG32(    HECC2CANLAM13, 0xfff7a8b4,__READ_WRITE);
__IO_REG32(    HECC2CANLAM14, 0xfff7a8b8,__READ_WRITE);
__IO_REG32(    HECC2CANLAM15, 0xfff7a8bc,__READ_WRITE);
__IO_REG32(    HECC2CANLAM16, 0xfff7a8c0,__READ_WRITE);
__IO_REG32(    HECC2CANLAM17, 0xfff7a8c4,__READ_WRITE);
__IO_REG32(    HECC2CANLAM18, 0xfff7a8c8,__READ_WRITE);
__IO_REG32(    HECC2CANLAM19, 0xfff7a8cc,__READ_WRITE);
__IO_REG32(    HECC2CANLAM20, 0xfff7a8d0,__READ_WRITE);
__IO_REG32(    HECC2CANLAM21, 0xfff7a8d4,__READ_WRITE);
__IO_REG32(    HECC2CANLAM22, 0xfff7a8d8,__READ_WRITE);
__IO_REG32(    HECC2CANLAM23, 0xfff7a8dc,__READ_WRITE);
__IO_REG32(    HECC2CANLAM24, 0xfff7a8e0,__READ_WRITE);
__IO_REG32(    HECC2CANLAM25, 0xfff7a8e4,__READ_WRITE);
__IO_REG32(    HECC2CANLAM26, 0xfff7a8e8,__READ_WRITE);
__IO_REG32(    HECC2CANLAM27, 0xfff7a8ec,__READ_WRITE);
__IO_REG32(    HECC2CANLAM28, 0xfff7a9f0,__READ_WRITE);
__IO_REG32(    HECC2CANLAM29, 0xfff7a9f4,__READ_WRITE);
__IO_REG32(    HECC2CANLAM30, 0xfff7a9f8,__READ_WRITE);
__IO_REG32(    HECC2CANLAM31, 0xfff7a9fc,__READ_WRITE);



/***************************************************************************
 **
 ** HECC 2 RAM
 **
 ***************************************************************************/

__IO_REG32_BIT(    HECC2CANMID0 ,  0xfff7e600,__READ_WRITE,  __mid_bits);  /* Message identifier */
__IO_REG32_BIT(    HECC2CANMID1 ,  0xfff7e610,__READ_WRITE,  __mid_bits);
__IO_REG32_BIT(    HECC2CANMID2 ,  0xfff7e620,__READ_WRITE,  __mid_bits);
__IO_REG32_BIT(    HECC2CANMID3 ,  0xfff7e630,__READ_WRITE,  __mid_bits);
__IO_REG32_BIT(    HECC2CANMID4 ,  0xfff7e640,__READ_WRITE,  __mid_bits);
__IO_REG32_BIT(    HECC2CANMID5 ,  0xfff7e650,__READ_WRITE,  __mid_bits);
__IO_REG32_BIT(    HECC2CANMID6 ,  0xfff7e660,__READ_WRITE,  __mid_bits);
__IO_REG32_BIT(    HECC2CANMID7 ,  0xfff7e670,__READ_WRITE,  __mid_bits);
__IO_REG32_BIT(    HECC2CANMID8 ,  0xfff7e680,__READ_WRITE,  __mid_bits);
__IO_REG32_BIT(    HECC2CANMID9 ,  0xfff7e690,__READ_WRITE,  __mid_bits);
__IO_REG32_BIT(    HECC2CANMID10,  0xfff7e6a0,__READ_WRITE,  __mid_bits);
__IO_REG32_BIT(    HECC2CANMID11,  0xfff7e6b0,__READ_WRITE,  __mid_bits);
__IO_REG32_BIT(    HECC2CANMID12,  0xfff7e6c0,__READ_WRITE,  __mid_bits);
__IO_REG32_BIT(    HECC2CANMID13,  0xfff7e6d0,__READ_WRITE,  __mid_bits);
__IO_REG32_BIT(    HECC2CANMID14,  0xfff7e6e0,__READ_WRITE,  __mid_bits);
__IO_REG32_BIT(    HECC2CANMID15,  0xfff7e6f0,__READ_WRITE,  __mid_bits);
__IO_REG32_BIT(    HECC2CANMCF0 ,  0xfff7e604,__READ_WRITE,  __mcf_bits);  /* Message control field */
__IO_REG32_BIT(    HECC2CANMCF1 ,  0xfff7e614,__READ_WRITE,  __mcf_bits);
__IO_REG32_BIT(    HECC2CANMCF2 ,  0xfff7e624,__READ_WRITE,  __mcf_bits);
__IO_REG32_BIT(    HECC2CANMCF3 ,  0xfff7e634,__READ_WRITE,  __mcf_bits);
__IO_REG32_BIT(    HECC2CANMCF4 ,  0xfff7e644,__READ_WRITE,  __mcf_bits);
__IO_REG32_BIT(    HECC2CANMCF5 ,  0xfff7e654,__READ_WRITE,  __mcf_bits);
__IO_REG32_BIT(    HECC2CANMCF6 ,  0xfff7e664,__READ_WRITE,  __mcf_bits);
__IO_REG32_BIT(    HECC2CANMCF7 ,  0xfff7e674,__READ_WRITE,  __mcf_bits);
__IO_REG32_BIT(    HECC2CANMCF8 ,  0xfff7e684,__READ_WRITE,  __mcf_bits);
__IO_REG32_BIT(    HECC2CANMCF9 ,  0xfff7e694,__READ_WRITE,  __mcf_bits);
__IO_REG32_BIT(    HECC2CANMCF10,  0xfff7e6a4,__READ_WRITE,  __mcf_bits);
__IO_REG32_BIT(    HECC2CANMCF11,  0xfff7e6b4,__READ_WRITE,  __mcf_bits);
__IO_REG32_BIT(    HECC2CANMCF12,  0xfff7e6c4,__READ_WRITE,  __mcf_bits);
__IO_REG32_BIT(    HECC2CANMCF13,  0xfff7e6d4,__READ_WRITE,  __mcf_bits);
__IO_REG32_BIT(    HECC2CANMCF14,  0xfff7e6e4,__READ_WRITE,  __mcf_bits);
__IO_REG32_BIT(    HECC2CANMCF15,  0xfff7e6f4,__READ_WRITE,  __mcf_bits);
__IO_REG32(    HECC2CANMDL0 ,  0xfff7e608,__READ_WRITE);  /* Message data low word */
__IO_REG32(    HECC2CANMDL1 ,  0xfff7e618,__READ_WRITE);
__IO_REG32(    HECC2CANMDL2 ,  0xfff7e628,__READ_WRITE);
__IO_REG32(    HECC2CANMDL3 ,  0xfff7e638,__READ_WRITE);
__IO_REG32(    HECC2CANMDL4 ,  0xfff7e648,__READ_WRITE);
__IO_REG32(    HECC2CANMDL5 ,  0xfff7e658,__READ_WRITE);
__IO_REG32(    HECC2CANMDL6 ,  0xfff7e668,__READ_WRITE);
__IO_REG32(    HECC2CANMDL7 ,  0xfff7e678,__READ_WRITE);
__IO_REG32(    HECC2CANMDL8 ,  0xfff7e688,__READ_WRITE);
__IO_REG32(    HECC2CANMDL9 ,  0xfff7e698,__READ_WRITE);
__IO_REG32(    HECC2CANMDL10,  0xfff7e6a8,__READ_WRITE);
__IO_REG32(    HECC2CANMDL11,  0xfff7e6b8,__READ_WRITE);
__IO_REG32(    HECC2CANMDL12,  0xfff7e6c8,__READ_WRITE);
__IO_REG32(    HECC2CANMDL13,  0xfff7e6d8,__READ_WRITE);
__IO_REG32(    HECC2CANMDL14,  0xfff7e6e8,__READ_WRITE);
__IO_REG32(    HECC2CANMDL15,  0xfff7e6f8,__READ_WRITE);
__IO_REG32(    HECC2CANMDH0 ,  0xfff7e60c,__READ_WRITE);  /* Message data high word */
__IO_REG32(    HECC2CANMDH1 ,  0xfff7e61c,__READ_WRITE);
__IO_REG32(    HECC2CANMDH2 ,  0xfff7e62c,__READ_WRITE);
__IO_REG32(    HECC2CANMDH3 ,  0xfff7e63c,__READ_WRITE);
__IO_REG32(    HECC2CANMDH4 ,  0xfff7e64c,__READ_WRITE);
__IO_REG32(    HECC2CANMDH5 ,  0xfff7e65c,__READ_WRITE);
__IO_REG32(    HECC2CANMDH6 ,  0xfff7e66c,__READ_WRITE);
__IO_REG32(    HECC2CANMDH7 ,  0xfff7e67c,__READ_WRITE);
__IO_REG32(    HECC2CANMDH8 ,  0xfff7e68c,__READ_WRITE);
__IO_REG32(    HECC2CANMDH9 ,  0xfff7e69c,__READ_WRITE);
__IO_REG32(    HECC2CANMDH10,  0xfff7e6ac,__READ_WRITE);
__IO_REG32(    HECC2CANMDH11,  0xfff7e6bc,__READ_WRITE);
__IO_REG32(    HECC2CANMDH12,  0xfff7e6cc,__READ_WRITE);
__IO_REG32(    HECC2CANMDH13,  0xfff7e6dc,__READ_WRITE);
__IO_REG32(    HECC2CANMDH14,  0xfff7e6ec,__READ_WRITE);
__IO_REG32(    HECC2CANMDH15,  0xfff7e6fc,__READ_WRITE);

#define HECC2_RAM_OFFSET 0xFFF7e600

/***************************************************************************
 **
 ** I2C1
 **
 ***************************************************************************/

__IO_REG16_BIT(I2C1OAR,   0xfff7d802,__READ_WRITE,__i2coar_bits);
__IO_REG16_BIT(I2C1IMR,   0xfff7d806,__READ_WRITE,__i2cimr_bits);
__IO_REG16_BIT(I2C1SR,    0xfff7d80a,__READ_WRITE,__i2csr_bits);
__IO_REG16(    I2C1CKL,   0xfff7d80e,__READ_WRITE);
__IO_REG16(    I2C1CKH,   0xfff7d812,__READ_WRITE);
__IO_REG16(    I2C1CNT,   0xfff7d816,__READ_WRITE);
__IO_REG16_BIT(I2C1DRR,   0xfff7d81a,__READ_WRITE,__i2cdrr_bits);
__IO_REG16_BIT(I2C1SAR,   0xfff7d81e,__READ_WRITE,__i2csar_bits);
__IO_REG16_BIT(I2C1DXR,   0xfff7d822,__READ_WRITE,__i2cdxr_bits);
__IO_REG16_BIT(I2C1MDR,   0xfff7d826,__READ_WRITE,__i2cmdr_bits);
__IO_REG16_BIT(I2C1IVR,   0xfff7d82a,__READ_WRITE,__i2civr_bits);
__IO_REG16_BIT(I2C1EMR,   0xfff7d82e,__READ_WRITE,__i2cemr_bits);
__IO_REG16_BIT(I2C1PSC,   0xfff7d832,__READ_WRITE,__i2cpsc_bits);
__IO_REG16_BIT(I2C1DIR,   0xfff7d836,__READ_WRITE,__i2cdir_bits);
__IO_REG16_BIT(I2C1DOUTP, 0xfff7d83a,__READ_WRITE,__i2cdoutp_bits);
__IO_REG16_BIT(I2C1DINP,  0xfff7d83e,__READ_WRITE,__i2cdinp_bits);
__IO_REG16_BIT(I2C1PFNC,  0xfff7d84a,__READ_WRITE,__i2cpgnc_bits);
__IO_REG16_BIT(I2C1PDIR,  0xfff7d84e,__READ_WRITE,__i2cpdir_bits);
__IO_REG16_BIT(I2C1DIN,   0xfff7d852,__READ_WRITE,__i2cdin_bits);
__IO_REG16_BIT(I2C1DOUT,  0xfff7d856,__READ_WRITE,__i2cdout_bits);
__IO_REG16_BIT(I2C1DSET,  0xfff7d85a,__READ_WRITE,__i2cdset_bits);
__IO_REG16_BIT(I2C1DCLR,  0xfff7d85e,__READ_WRITE,__i2cdclr_bits);
__IO_REG16_BIT(I2C1PID1,  0xfff7d866,__READ_WRITE,__i2cpid1_bits);
__IO_REG16_BIT(I2C1PID2,  0xfff7d86a,__READ_WRITE,__i2cpid2_bits);

/***************************************************************************
 **
 ** I2C2
 **
 ***************************************************************************/

__IO_REG16_BIT(I2C2OAR,   0xfff7d902,__READ_WRITE,__i2coar_bits);
__IO_REG16_BIT(I2C2IMR,   0xfff7d906,__READ_WRITE,__i2cimr_bits);
__IO_REG16_BIT(I2C2SR,    0xfff7d90a,__READ_WRITE,__i2csr_bits);
__IO_REG16(    I2C2CKL,   0xfff7d90e,__READ_WRITE);
__IO_REG16(    I2C2CKH,   0xfff7d912,__READ_WRITE);
__IO_REG16(    I2C2CNT,   0xfff7d916,__READ_WRITE);
__IO_REG16_BIT(I2C2DRR,   0xfff7d91a,__READ_WRITE,__i2cdrr_bits);
__IO_REG16_BIT(I2C2SAR,   0xfff7d91e,__READ_WRITE,__i2csar_bits);
__IO_REG16_BIT(I2C2DXR,   0xfff7d922,__READ_WRITE,__i2cdxr_bits);
__IO_REG16_BIT(I2C2MDR,   0xfff7d926,__READ_WRITE,__i2cmdr_bits);
__IO_REG16_BIT(I2C2IVR,   0xfff7d92a,__READ_WRITE,__i2civr_bits);
__IO_REG16_BIT(I2C2EMR,   0xfff7d92e,__READ_WRITE,__i2cemr_bits);
__IO_REG16_BIT(I2C2PSC,   0xfff7d932,__READ_WRITE,__i2cpsc_bits);
__IO_REG16_BIT(I2C2DIR,   0xfff7d936,__READ_WRITE,__i2cdir_bits);
__IO_REG16_BIT(I2C2DOUTP, 0xfff7d93a,__READ_WRITE,__i2cdoutp_bits);
__IO_REG16_BIT(I2C2DINP,  0xfff7d93e,__READ_WRITE,__i2cdinp_bits);
__IO_REG16_BIT(I2C2PFNC,  0xfff7d94a,__READ_WRITE,__i2cpgnc_bits);
__IO_REG16_BIT(I2C2PDIR,  0xfff7d94e,__READ_WRITE,__i2cpdir_bits);
__IO_REG16_BIT(I2C2DIN,   0xfff7d952,__READ_WRITE,__i2cdin_bits);
__IO_REG16_BIT(I2C2DOUT,  0xfff7d956,__READ_WRITE,__i2cdout_bits);
__IO_REG16_BIT(I2C2DSET,  0xfff7d95a,__READ_WRITE,__i2cdset_bits);
__IO_REG16_BIT(I2C2DCLR,  0xfff7d95e,__READ_WRITE,__i2cdclr_bits);
__IO_REG16_BIT(I2C2PID1,  0xfff7d966,__READ_WRITE,__i2cpid1_bits);
__IO_REG16_BIT(I2C2PID2,  0xfff7d96a,__READ_WRITE,__i2cpid2_bits);

/***************************************************************************
 **
 ** I2C3
 **
 ***************************************************************************/

__IO_REG16_BIT(I2C3OAR,   0xfff7da02,__READ_WRITE,__i2coar_bits);
__IO_REG16_BIT(I2C3IMR,   0xfff7da06,__READ_WRITE,__i2cimr_bits);
__IO_REG16_BIT(I2C3SR,    0xfff7da0a,__READ_WRITE,__i2csr_bits);
__IO_REG16(    I2C3CKL,   0xfff7da0e,__READ_WRITE);
__IO_REG16(    I2C3CKH,   0xfff7da12,__READ_WRITE);
__IO_REG16(    I2C3CNT,   0xfff7da16,__READ_WRITE);
__IO_REG16_BIT(I2C3DRR,   0xfff7da1a,__READ_WRITE,__i2cdrr_bits);
__IO_REG16_BIT(I2C3SAR,   0xfff7da1e,__READ_WRITE,__i2csar_bits);
__IO_REG16_BIT(I2C3DXR,   0xfff7da22,__READ_WRITE,__i2cdxr_bits);
__IO_REG16_BIT(I2C3MDR,   0xfff7da26,__READ_WRITE,__i2cmdr_bits);
__IO_REG16_BIT(I2C3IVR,   0xfff7da2a,__READ_WRITE,__i2civr_bits);
__IO_REG16_BIT(I2C3EMR,   0xfff7da2e,__READ_WRITE,__i2cemr_bits);
__IO_REG16_BIT(I2C3PSC,   0xfff7da32,__READ_WRITE,__i2cpsc_bits);
__IO_REG16_BIT(I2C3DIR,   0xfff7da36,__READ_WRITE,__i2cdir_bits);
__IO_REG16_BIT(I2C3DOUTP, 0xfff7da3a,__READ_WRITE,__i2cdoutp_bits);
__IO_REG16_BIT(I2C3DINP,  0xfff7da3e,__READ_WRITE,__i2cdinp_bits);
__IO_REG16_BIT(I2C3PFNC,  0xfff7da4a,__READ_WRITE,__i2cpgnc_bits);
__IO_REG16_BIT(I2C3PDIR,  0xfff7da4e,__READ_WRITE,__i2cpdir_bits);
__IO_REG16_BIT(I2C3DIN,   0xfff7da52,__READ_WRITE,__i2cdin_bits);
__IO_REG16_BIT(I2C3DOUT,  0xfff7da56,__READ_WRITE,__i2cdout_bits);
__IO_REG16_BIT(I2C3DSET,  0xfff7da5a,__READ_WRITE,__i2cdset_bits);
__IO_REG16_BIT(I2C3DCLR,  0xfff7da5e,__READ_WRITE,__i2cdclr_bits);
__IO_REG16_BIT(I2C3PID1,  0xfff7da66,__READ_WRITE,__i2cpid1_bits);
__IO_REG16_BIT(I2C3PID2,  0xfff7da6a,__READ_WRITE,__i2cpid2_bits);

/***************************************************************************
 **
 ** I2C4
 **
 ***************************************************************************/

__IO_REG16_BIT(I2C4OAR,   0xfff7db02,__READ_WRITE,__i2coar_bits);
__IO_REG16_BIT(I2C4IMR,   0xfff7db06,__READ_WRITE,__i2cimr_bits);
__IO_REG16_BIT(I2C4SR,    0xfff7db0a,__READ_WRITE,__i2csr_bits);
__IO_REG16(    I2C4CKL,   0xfff7db0e,__READ_WRITE);
__IO_REG16(    I2C4CKH,   0xfff7db12,__READ_WRITE);
__IO_REG16(    I2C4CNT,   0xfff7db16,__READ_WRITE);
__IO_REG16_BIT(I2C4DRR,   0xfff7db1a,__READ_WRITE,__i2cdrr_bits);
__IO_REG16_BIT(I2C4SAR,   0xfff7db1e,__READ_WRITE,__i2csar_bits);
__IO_REG16_BIT(I2C4DXR,   0xfff7db22,__READ_WRITE,__i2cdxr_bits);
__IO_REG16_BIT(I2C4MDR,   0xfff7db26,__READ_WRITE,__i2cmdr_bits);
__IO_REG16_BIT(I2C4IVR,   0xfff7db2a,__READ_WRITE,__i2civr_bits);
__IO_REG16_BIT(I2C4EMR,   0xfff7db2e,__READ_WRITE,__i2cemr_bits);
__IO_REG16_BIT(I2C4PSC,   0xfff7db32,__READ_WRITE,__i2cpsc_bits);
__IO_REG16_BIT(I2C4DIR,   0xfff7db36,__READ_WRITE,__i2cdir_bits);
__IO_REG16_BIT(I2C4DOUTP, 0xfff7db3a,__READ_WRITE,__i2cdoutp_bits);
__IO_REG16_BIT(I2C4DINP,  0xfff7db3e,__READ_WRITE,__i2cdinp_bits);
__IO_REG16_BIT(I2C4PFNC,  0xfff7db4a,__READ_WRITE,__i2cpgnc_bits);
__IO_REG16_BIT(I2C4PDIR,  0xfff7db4e,__READ_WRITE,__i2cpdir_bits);
__IO_REG16_BIT(I2C4DIN,   0xfff7db52,__READ_WRITE,__i2cdin_bits);
__IO_REG16_BIT(I2C4DOUT,  0xfff7db56,__READ_WRITE,__i2cdout_bits);
__IO_REG16_BIT(I2C4DSET,  0xfff7db5a,__READ_WRITE,__i2cdset_bits);
__IO_REG16_BIT(I2C4DCLR,  0xfff7db5e,__READ_WRITE,__i2cdclr_bits);
__IO_REG16_BIT(I2C4PID1,  0xfff7db66,__READ_WRITE,__i2cpid1_bits);
__IO_REG16_BIT(I2C4PID2,  0xfff7db6a,__READ_WRITE,__i2cpid2_bits);

/***************************************************************************
 **
 ** I2C5
 **
 ***************************************************************************/

__IO_REG16_BIT(I2C5OAR,   0xfff7d502,__READ_WRITE,__i2coar_bits);
__IO_REG16_BIT(I2C5IMR,   0xfff7d506,__READ_WRITE,__i2cimr_bits);
__IO_REG16_BIT(I2C5SR,    0xfff7d50a,__READ_WRITE,__i2csr_bits);
__IO_REG16(    I2C5CKL,   0xfff7d50e,__READ_WRITE);
__IO_REG16(    I2C5CKH,   0xfff7d512,__READ_WRITE);
__IO_REG16(    I2C5CNT,   0xfff7d516,__READ_WRITE);
__IO_REG16_BIT(I2C5DRR,   0xfff7d51a,__READ_WRITE,__i2cdrr_bits);
__IO_REG16_BIT(I2C5SAR,   0xfff7d51e,__READ_WRITE,__i2csar_bits);
__IO_REG16_BIT(I2C5DXR,   0xfff7d522,__READ_WRITE,__i2cdxr_bits);
__IO_REG16_BIT(I2C5MDR,   0xfff7d526,__READ_WRITE,__i2cmdr_bits);
__IO_REG16_BIT(I2C5IVR,   0xfff7d52a,__READ_WRITE,__i2civr_bits);
__IO_REG16_BIT(I2C5EMR,   0xfff7d52e,__READ_WRITE,__i2cemr_bits);
__IO_REG16_BIT(I2C5PSC,   0xfff7d532,__READ_WRITE,__i2cpsc_bits);
__IO_REG16_BIT(I2C5DIR,   0xfff7d536,__READ_WRITE,__i2cdir_bits);
__IO_REG16_BIT(I2C5DOUTP, 0xfff7d53a,__READ_WRITE,__i2cdoutp_bits);
__IO_REG16_BIT(I2C5DINP,  0xfff7d53e,__READ_WRITE,__i2cdinp_bits);
__IO_REG16_BIT(I2C5PFNC,  0xfff7d54a,__READ_WRITE,__i2cpgnc_bits);
__IO_REG16_BIT(I2C5PDIR,  0xfff7d54e,__READ_WRITE,__i2cpdir_bits);
__IO_REG16_BIT(I2C5DIN,   0xfff7d552,__READ_WRITE,__i2cdin_bits);
__IO_REG16_BIT(I2C5DOUT,  0xfff7d556,__READ_WRITE,__i2cdout_bits);
__IO_REG16_BIT(I2C5DSET,  0xfff7d55a,__READ_WRITE,__i2cdset_bits);
__IO_REG16_BIT(I2C5DCLR,  0xfff7d55e,__READ_WRITE,__i2cdclr_bits);
__IO_REG16_BIT(I2C5PID1,  0xfff7d566,__READ_WRITE,__i2cpid1_bits);
__IO_REG16_BIT(I2C5PID2,  0xfff7d56a,__READ_WRITE,__i2cpid2_bits);

/***************************************************************************
 **
 ** Flash Module
 **
 ***************************************************************************/

__IO_REG16_BIT(FMBAC1,    0xffe88002,__READ_WRITE,__fmbac1_bits);
__IO_REG16_BIT(FMBAC2,    0xffe88006,__READ_WRITE,__fmbac2_bits);
__IO_REG16(    FMBSEA,    0xffe8800a,__READ_WRITE);
__IO_REG16(    FMBSEB,    0xffe8800e,__READ_WRITE);
__IO_REG16_BIT(FMBRDY,    0xffe88012,__READ_WRITE,__fmbrdy_bits);

__IO_REG32_BIT(FMREGOPT,  0xffe89c00,__READ_WRITE,__fmregopt_bits);
__IO_REG32_BIT(FMBBUSY,   0xffe89c08,__READ_WRITE,__fmbbusy_bits);
__IO_REG32(    FMPKEY,    0xffe89c0c,__READ_WRITE);

__IO_REG16_BIT(FMPRDY,    0xffe8a816,__READ_WRITE,__fmprdy_bits);

__IO_REG16_BIT(FMMAC1,    0xffe8bc02,__READ_WRITE,__fmmac1_bits);
__IO_REG16_BIT(FMMAC2,    0xffe8bc06,__READ_WRITE,__fmmac2_bits);
__IO_REG16(    FMPAGP,    0xffe8bc0a,__READ_WRITE);
__IO_REG16_BIT(FMMSTAT,   0xffe8bc0e,__READ_WRITE,__fmmstat_bits);

/***************************************************************************
 **
 ** DMA Module
 **
 ***************************************************************************/
//Control Packet 00
__IO_REG32_BIT(DMAC00,   0xFFFFF800,__READ_WRITE,__dmac_bits);
__IO_REG32_BIT(DMASA00,  0xFFFFF804,__READ_WRITE,__dmasa_bits);
__IO_REG32_BIT(DMADA00,  0xFFFFF808,__READ_WRITE,__dmada_bits);
__IO_REG32_BIT(DMATC00,  0xFFFFF80C,__READ_WRITE,__dmatc_bits);
//Control Packet 01
__IO_REG32_BIT(DMAC01,   0xFFFFF810,__READ_WRITE,__dmac_bits);
__IO_REG32_BIT(DMASA01,  0xFFFFF814,__READ_WRITE,__dmasa_bits);
__IO_REG32_BIT(DMADA01,  0xFFFFF818,__READ_WRITE,__dmada_bits);
__IO_REG32_BIT(DMATC01,  0xFFFFF81C,__READ_WRITE,__dmatc_bits);
//Control Packet 02
__IO_REG32_BIT(DMAC02,   0xFFFFF820,__READ_WRITE,__dmac_bits);
__IO_REG32_BIT(DMASA02,  0xFFFFF824,__READ_WRITE,__dmasa_bits);
__IO_REG32_BIT(DMADA02,  0xFFFFF828,__READ_WRITE,__dmada_bits);
__IO_REG32_BIT(DMATC02,  0xFFFFF82C,__READ_WRITE,__dmatc_bits);
//Control Packet 03
__IO_REG32_BIT(DMAC03,   0xFFFFF830,__READ_WRITE,__dmac_bits);
__IO_REG32_BIT(DMASA03,  0xFFFFF834,__READ_WRITE,__dmasa_bits);
__IO_REG32_BIT(DMADA03,  0xFFFFF838,__READ_WRITE,__dmada_bits);
__IO_REG32_BIT(DMATC03,  0xFFFFF83C,__READ_WRITE,__dmatc_bits);
//Control Packet 04
__IO_REG32_BIT(DMAC04,   0xFFFFF840,__READ_WRITE,__dmac_bits);
__IO_REG32_BIT(DMASA04,  0xFFFFF844,__READ_WRITE,__dmasa_bits);
__IO_REG32_BIT(DMADA04,  0xFFFFF848,__READ_WRITE,__dmada_bits);
__IO_REG32_BIT(DMATC04,  0xFFFFF84C,__READ_WRITE,__dmatc_bits);
//Control Packet 05
__IO_REG32_BIT(DMAC05,   0xFFFFF850,__READ_WRITE,__dmac_bits);
__IO_REG32_BIT(DMASA05,  0xFFFFF854,__READ_WRITE,__dmasa_bits);
__IO_REG32_BIT(DMADA05,  0xFFFFF858,__READ_WRITE,__dmada_bits);
__IO_REG32_BIT(DMATC05,  0xFFFFF85C,__READ_WRITE,__dmatc_bits);
//Control Packet 06
__IO_REG32_BIT(DMAC06,   0xFFFFF860,__READ_WRITE,__dmac_bits);
__IO_REG32_BIT(DMASA06,  0xFFFFF864,__READ_WRITE,__dmasa_bits);
__IO_REG32_BIT(DMADA06,  0xFFFFF868,__READ_WRITE,__dmada_bits);
__IO_REG32_BIT(DMATC06,  0xFFFFF86C,__READ_WRITE,__dmatc_bits);
//Control Packet 07
__IO_REG32_BIT(DMAC07,   0xFFFFF870,__READ_WRITE,__dmac_bits);
__IO_REG32_BIT(DMASA07,  0xFFFFF874,__READ_WRITE,__dmasa_bits);
__IO_REG32_BIT(DMADA07,  0xFFFFF878,__READ_WRITE,__dmada_bits);
__IO_REG32_BIT(DMATC07,  0xFFFFF87C,__READ_WRITE,__dmatc_bits);
//Control Packet 08
__IO_REG32_BIT(DMAC08,   0xFFFFF880,__READ_WRITE,__dmac_bits);
__IO_REG32_BIT(DMASA08,  0xFFFFF884,__READ_WRITE,__dmasa_bits);
__IO_REG32_BIT(DMADA08,  0xFFFFF888,__READ_WRITE,__dmada_bits);
__IO_REG32_BIT(DMATC08,  0xFFFFF88C,__READ_WRITE,__dmatc_bits);
//Control Packet 09
__IO_REG32_BIT(DMAC09,   0xFFFFF890,__READ_WRITE,__dmac_bits);
__IO_REG32_BIT(DMASA09,  0xFFFFF894,__READ_WRITE,__dmasa_bits);
__IO_REG32_BIT(DMADA09,  0xFFFFF898,__READ_WRITE,__dmada_bits);
__IO_REG32_BIT(DMATC09,  0xFFFFF89C,__READ_WRITE,__dmatc_bits);
//Control Packet 10
__IO_REG32_BIT(DMAC10,   0xFFFFF8A0,__READ_WRITE,__dmac_bits);
__IO_REG32_BIT(DMASA10,  0xFFFFF8A4,__READ_WRITE,__dmasa_bits);
__IO_REG32_BIT(DMADA10,  0xFFFFF8A8,__READ_WRITE,__dmada_bits);
__IO_REG32_BIT(DMATC10,  0xFFFFF8AC,__READ_WRITE,__dmatc_bits);
//Control Packet 11
__IO_REG32_BIT(DMAC11,   0xFFFFF8B0,__READ_WRITE,__dmac_bits);
__IO_REG32_BIT(DMASA11,  0xFFFFF8B4,__READ_WRITE,__dmasa_bits);
__IO_REG32_BIT(DMADA11,  0xFFFFF8B8,__READ_WRITE,__dmada_bits);
__IO_REG32_BIT(DMATC11,  0xFFFFF8BC,__READ_WRITE,__dmatc_bits);
//Control Packet 12
__IO_REG32_BIT(DMAC12,   0xFFFFF8C0,__READ_WRITE,__dmac_bits);
__IO_REG32_BIT(DMASA12,  0xFFFFF8C4,__READ_WRITE,__dmasa_bits);
__IO_REG32_BIT(DMADA12,  0xFFFFF8C8,__READ_WRITE,__dmada_bits);
__IO_REG32_BIT(DMATC12,  0xFFFFF8CC,__READ_WRITE,__dmatc_bits);
//Control Packet 13
__IO_REG32_BIT(DMAC13,   0xFFFFF8D0,__READ_WRITE,__dmac_bits);
__IO_REG32_BIT(DMASA13,  0xFFFFF8D4,__READ_WRITE,__dmasa_bits);
__IO_REG32_BIT(DMADA13,  0xFFFFF8D8,__READ_WRITE,__dmada_bits);
__IO_REG32_BIT(DMATC13,  0xFFFFF8DC,__READ_WRITE,__dmatc_bits);
//Control Packet 14
__IO_REG32_BIT(DMAC14,   0xFFFFF8E0,__READ_WRITE,__dmac_bits);
__IO_REG32_BIT(DMASA14,  0xFFFFF8E4,__READ_WRITE,__dmasa_bits);
__IO_REG32_BIT(DMADA14,  0xFFFFF8E8,__READ_WRITE,__dmada_bits);
__IO_REG32_BIT(DMATC14,  0xFFFFF8EC,__READ_WRITE,__dmatc_bits);
//Control Packet 15
__IO_REG32_BIT(DMAC15,   0xFFFFF8F0,__READ_WRITE,__dmac_bits);
__IO_REG32_BIT(DMASA15,  0xFFFFF8F4,__READ_WRITE,__dmasa_bits);
__IO_REG32_BIT(DMADA15,  0xFFFFF8F8,__READ_WRITE,__dmada_bits);
__IO_REG32_BIT(DMATC15,  0xFFFFF8FC,__READ_WRITE,__dmatc_bits);
//Control Packet 16
__IO_REG32_BIT(DMAC16,   0xFFFFF900,__READ_WRITE,__dmac_bits);
__IO_REG32_BIT(DMASA16,  0xFFFFF904,__READ_WRITE,__dmasa_bits);
__IO_REG32_BIT(DMADA16,  0xFFFFF908,__READ_WRITE,__dmada_bits);
__IO_REG32_BIT(DMATC16,  0xFFFFF90C,__READ_WRITE,__dmatc_bits);
//Control Packet 17
__IO_REG32_BIT(DMAC17,   0xFFFFF910,__READ_WRITE,__dmac_bits);
__IO_REG32_BIT(DMASA17,  0xFFFFF914,__READ_WRITE,__dmasa_bits);
__IO_REG32_BIT(DMADA17,  0xFFFFF918,__READ_WRITE,__dmada_bits);
__IO_REG32_BIT(DMATC17,  0xFFFFF91C,__READ_WRITE,__dmatc_bits);
//Control Packet 18
__IO_REG32_BIT(DMAC18,   0xFFFFF920,__READ_WRITE,__dmac_bits);
__IO_REG32_BIT(DMASA18,  0xFFFFF924,__READ_WRITE,__dmasa_bits);
__IO_REG32_BIT(DMADA18,  0xFFFFF928,__READ_WRITE,__dmada_bits);
__IO_REG32_BIT(DMATC18,  0xFFFFF92C,__READ_WRITE,__dmatc_bits);
//Control Packet 19
__IO_REG32_BIT(DMAC19,   0xFFFFF930,__READ_WRITE,__dmac_bits);
__IO_REG32_BIT(DMASA19,  0xFFFFF934,__READ_WRITE,__dmasa_bits);
__IO_REG32_BIT(DMADA19,  0xFFFFF938,__READ_WRITE,__dmada_bits);
__IO_REG32_BIT(DMATC19,  0xFFFFF93C,__READ_WRITE,__dmatc_bits);
//Control Packet 20
__IO_REG32_BIT(DMAC20,   0xFFFFF940,__READ_WRITE,__dmac_bits);
__IO_REG32_BIT(DMASA20,  0xFFFFF944,__READ_WRITE,__dmasa_bits);
__IO_REG32_BIT(DMADA20,  0xFFFFF948,__READ_WRITE,__dmada_bits);
__IO_REG32_BIT(DMATC20,  0xFFFFF94C,__READ_WRITE,__dmatc_bits);
//Control Packet 21
__IO_REG32_BIT(DMAC21,   0xFFFFF950,__READ_WRITE,__dmac_bits);
__IO_REG32_BIT(DMASA21,  0xFFFFF954,__READ_WRITE,__dmasa_bits);
__IO_REG32_BIT(DMADA21,  0xFFFFF958,__READ_WRITE,__dmada_bits);
__IO_REG32_BIT(DMATC21,  0xFFFFF95C,__READ_WRITE,__dmatc_bits);
//Control Packet 22
__IO_REG32_BIT(DMAC22,   0xFFFFF960,__READ_WRITE,__dmac_bits);
__IO_REG32_BIT(DMASA22,  0xFFFFF964,__READ_WRITE,__dmasa_bits);
__IO_REG32_BIT(DMADA22,  0xFFFFF968,__READ_WRITE,__dmada_bits);
__IO_REG32_BIT(DMATC22,  0xFFFFF96C,__READ_WRITE,__dmatc_bits);
//Control Packet 23
__IO_REG32_BIT(DMAC23,   0xFFFFF970,__READ_WRITE,__dmac_bits);
__IO_REG32_BIT(DMASA23,  0xFFFFF974,__READ_WRITE,__dmasa_bits);
__IO_REG32_BIT(DMADA23,  0xFFFFF978,__READ_WRITE,__dmada_bits);
__IO_REG32_BIT(DMATC23,  0xFFFFF97C,__READ_WRITE,__dmatc_bits);
//Control Packet 24
__IO_REG32_BIT(DMAC24,   0xFFFFF980,__READ_WRITE,__dmac_bits);
__IO_REG32_BIT(DMASA24,  0xFFFFF984,__READ_WRITE,__dmasa_bits);
__IO_REG32_BIT(DMADA24,  0xFFFFF988,__READ_WRITE,__dmada_bits);
__IO_REG32_BIT(DMATC24,  0xFFFFF98C,__READ_WRITE,__dmatc_bits);
//Control Packet 25
__IO_REG32_BIT(DMAC25,   0xFFFFF990,__READ_WRITE,__dmac_bits);
__IO_REG32_BIT(DMASA25,  0xFFFFF994,__READ_WRITE,__dmasa_bits);
__IO_REG32_BIT(DMADA25,  0xFFFFF998,__READ_WRITE,__dmada_bits);
__IO_REG32_BIT(DMATC25,  0xFFFFF99C,__READ_WRITE,__dmatc_bits);
//Control Packet 26
__IO_REG32_BIT(DMAC26,   0xFFFFF9A0,__READ_WRITE,__dmac_bits);
__IO_REG32_BIT(DMASA26,  0xFFFFF9A4,__READ_WRITE,__dmasa_bits);
__IO_REG32_BIT(DMADA26,  0xFFFFF9A8,__READ_WRITE,__dmada_bits);
__IO_REG32_BIT(DMATC26,  0xFFFFF9AC,__READ_WRITE,__dmatc_bits);
//Control Packet 27
__IO_REG32_BIT(DMAC27,   0xFFFFF9B0,__READ_WRITE,__dmac_bits);
__IO_REG32_BIT(DMASA27,  0xFFFFF9B4,__READ_WRITE,__dmasa_bits);
__IO_REG32_BIT(DMADA27,  0xFFFFF9B8,__READ_WRITE,__dmada_bits);
__IO_REG32_BIT(DMATC27,  0xFFFFF9BC,__READ_WRITE,__dmatc_bits);
//Control Packet 28
__IO_REG32_BIT(DMAC28,   0xFFFFF9C0,__READ_WRITE,__dmac_bits);
__IO_REG32_BIT(DMASA28,  0xFFFFF9C4,__READ_WRITE,__dmasa_bits);
__IO_REG32_BIT(DMADA28,  0xFFFFF9C8,__READ_WRITE,__dmada_bits);
__IO_REG32_BIT(DMATC28,  0xFFFFF9CC,__READ_WRITE,__dmatc_bits);
//Control Packet 29
__IO_REG32_BIT(DMAC29,   0xFFFFF9D0,__READ_WRITE,__dmac_bits);
__IO_REG32_BIT(DMASA29,  0xFFFFF9D4,__READ_WRITE,__dmasa_bits);
__IO_REG32_BIT(DMADA29,  0xFFFFF9D8,__READ_WRITE,__dmada_bits);
__IO_REG32_BIT(DMATC29,  0xFFFFF9DC,__READ_WRITE,__dmatc_bits);
//Control Packet 30
__IO_REG32_BIT(DMAC30,   0xFFFFF9E0,__READ_WRITE,__dmac_bits);
__IO_REG32_BIT(DMASA30,  0xFFFFF9E4,__READ_WRITE,__dmasa_bits);
__IO_REG32_BIT(DMADA30,  0xFFFFF9E8,__READ_WRITE,__dmada_bits);
__IO_REG32_BIT(DMATC30,  0xFFFFF9EC,__READ_WRITE,__dmatc_bits);
//Control Packet 31
__IO_REG32_BIT(DMAC31,   0xFFFFF9F0,__READ_WRITE,__dmac_bits);
__IO_REG32_BIT(DMASA31,  0xFFFFF9F4,__READ_WRITE,__dmasa_bits);
__IO_REG32_BIT(DMADA31,  0xFFFFF9F8,__READ_WRITE,__dmada_bits);
__IO_REG32_BIT(DMATC31,  0xFFFFF9FC,__READ_WRITE,__dmatc_bits);

// DMA Channel Control 0
__IO_REG32_BIT(DMACC0,   0xFFFFFE80,__READ_WRITE,__dmacc0_bits);
// DMA Channel Control 1
__IO_REG32_BIT(DMACC1,   0xFFFFFE84,__READ_WRITE,__dmacc1_bits);
// DMA Status
__IO_REG32_BIT(DMAS,     0xFFFFFE88,__READ_WRITE,__dmas_bits);
// DMA Interrupt Offset 0
__IO_REG32_BIT(DMAIO0,   0xFFFFFE8C,__READ,__dmaio0_bits);
// DMA Interrupt Offset 1
__IO_REG32_BIT(DMAIO1,   0xFFFFFE90,__READ,__dmaio1_bits);
// DMA Control Packet Status
__IO_REG32_BIT(DMACPS,   0xFFFFFE94,__READ_WRITE,__dmacps_bits);
// DMA Control Packet Status Clear
__IO_REG32_BIT(DMACPSC,  0xFFFFFE98,__READ,__dmacpsc_bits);
// DMA Global Control
__IO_REG32_BIT(DMAGC,    0xFFFFFE9C,__READ_WRITE,__dmagc_bits);
// DMA Global Disable
__IO_REG32_BIT(DMAGD,    0xFFFFFEA0,__READ_WRITE,__dmagd_bits);
// DMA Active Channel
__IO_REG32_BIT(DMAAC,    0xFFFFFEA4,__READ,__dmaac_bits);
// DMA Current Control Packet 0
__IO_REG32_BIT(DMACCP0,  0xFFFFFEA8,__READ_WRITE,__dmaccp0_bits);
// DMA Current Control Packet 1
__IO_REG32_BIT(DMACCP1,  0xFFFFFEAC,__READ_WRITE,__dmaccp1_bits);
// DMA Current Control Packet 2
__IO_REG32_BIT(DMACCP2,  0xFFFFFEB0,__READ_WRITE,__dmaccp2_bits);
// DMA Current Control Packet 3
__IO_REG32_BIT(DMACCP3,  0xFFFFFEB4,__READ_WRITE,__dmaccp3_bits);


/* Assembler-specific declarations **********************************************/

#ifdef __IAR_SYSTEMS_ASM__


#endif    /* __IAR_SYSTEMS_ASM__ */

/***************************************************************************
 **
 **    TMS470R1B1M INTERRUPT VALUES
 **
***************************************************************************/
/***************************************************************************
 **
 **  Interrupt vector table
 **
 ***************************************************************************/
#define RESETV  0x00  /* Reset                           */
#define UNDEFV  0x04  /* Undefined instruction           */
#define SWIV    0x08  /* Software interrupt              */
#define PABORTV 0x0c  /* Prefetch abort                  */
#define DABORTV 0x10  /* Data abort                      */
#define IRQV    0x18  /* Normal interrupt                */
#define FIQV    0x1c  /* Fast interrupt                  */

/***************************************************************************
 **
 **  CIM interrupt channels
 **
 ***************************************************************************/
#define CIM_SPI1           0  /* SPI1 end-transfer/overrun          */
#define CIM_COMP2       1  /* COMP2 interrupt                    */
#define CIM_COMP1       2  /* COMP1 interrupt                    */
#define CIM_TAP            3  /* TAP interrupt                      */
#define CIM_SPI2           4  /* SPI2 end-transfer/overrun          */
#define CIM_GIOA          5  /* GIO interrupt A                    */
//#define CIM_RES           6  /* --- Reserved ---                   */
#define CIM_HET1          7  /* HET interrupt 1                    */
#define CIM_I2C1           8  /* I2C1 interrupt                     */
#define CIM_SCIRXERR   9  /* SCI1 or SCI2 error interrupt       */
#define CIM_SCI1RX       10  /* SCI1 receive interrupt             */
//#define CIM_RES           11  /* --- Reserved ---                   */
#define CIM_I2C2           12  /* I2C2 interrupt                     */
#define CIM_HECC1A      13  /* HECC1 interrupt A                  */
#define CIM_SCCA          14  /* SCC interrupt A                    */
//#define CIM_RES           15  /* --- Reserved ---                   */
#define CIM_MIBADCEE   16  /* MibADC end event conversion        */
#define CIM_SCI2RX       17  /* SCI2 receive interrupt             */
#define CIM_DMA0         18  /* DMA interrupt 0                    */
#define CIM_I2C3           19  /* I2C3 interrupt                     */
#define CIM_SCI1TX       20  /* SCI1 transmit interrupt            */
#define CIM_SSI             21  /* SW interrupt (SSI)                 */
//#define CIM_RES           22  /* --- Reserved ---                   */
#define CIM_HET2          23  /* HET interrupt 2                    */
#define CIM_HECC1B      24  /* HECC1 interrupt B                  */
#define CIM_SCCB          25  /* SCC interrupt B                    */
#define CIM_SCI2TX       26  /* SCI2 transmit interrupt            */
#define CIM_MIBADCE1   27  /* MibADC end Group 1 conversion      */
#define CIM_DMA1          28  /* DMA Interrupt 1                    */
#define CIM_GIOB           29  /* GIO interrupt B                    */
#define CIM_MIBADCE2   30  /* MibADC end Group 2 conversion      */
#define CIM_SCI3           31  /* SCI3 error interrupt               */

/***************************************************************************
 **
 **  IEM interrupt channels
 **
 ***************************************************************************/
//#define IEM_RES          32  /* --- Reserved ---                   */
//#define IEM_RES          33  /* --- Reserved ---                   */
//#define IEM_RES          34  /* --- Reserved ---                   */
//#define IEM_RES          35  /* --- Reserved ---                   */
//#define IEM_RES          36  /* --- Reserved ---                   */
//#define IEM_RES          37  /* --- Reserved ---                   */
#define IEM_HECC2A      38  /* HECC1 interrupt B                  */
#define IEM_HECC2B      39  /* HECC1 interrupt B                  */
#define IEM_SCI3RX      40  /* SCI2 receive interrupt             */
#define IEM_SCI3TX      41  /* SCI1 transmit interrupt            */
#define IEM_I2C4          42  /* I2C4 interrupt                      */
#define IEM_I2C5          43  /* I2C5 interrupt                       */

//#define IEM_RES          44  /* --- Reserved ---                   */
//#define IEM_RES          45  /* --- Reserved ---                   */
//#define IEM_RES          46  /* --- Reserved ---                   */
//#define IEM_RES          47  /* --- Reserved ---                   */



#endif    /* __IOTMS470R1B1M_H */

