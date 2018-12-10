/****************************************************************************************************
 * arch/arm/src/tiva/hardware/cc13x2_cc26x2/cc13x2_cc26x2_flash.h
 *
 *   Copyright (C) 2018 Gregory Nutt. All rights reserved.
 *   Authors: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************************************/

#ifndef __ARCH_ARM_SRC_TIVA_HARDWARE_CC13X2_CC26X2_CC13X2_CC26X2_FLASH_H
#define __ARCH_ARM_SRC_TIVA_HARDWARE_CC13X2_CC26X2_CC13X2_CC26X2_FLASH_H

/****************************************************************************************************
 * Included Files
 ****************************************************************************************************/

#include <nuttx/config.h>
#include "hardware/tiva_memorymap.h"

/****************************************************************************************************
 * Pre-processor Definitions
 ****************************************************************************************************/

/* FLASH Register Offsets ***************************************************************************/


#define FLASH_STAT_OFFSET               0x001c  /* FMC and Efuse Status */
#define FLASH_CFG_OFFSET                0x0024
#define FLASH_SYSCODE_START_OFFSET      0x0028
#define FLASH_FLASH_SIZE_OFFSET         0x002c
#define FLASH_FWLOCK_OFFSET             0x003c
#define FLASH_FWFLAG_OFFSET             0x0040
#define FLASH_EFUSE_OFFSET              0x1000
#define FLASH_EFUSEADDR_OFFSET          0x1004
#define FLASH_DATAUPPER_OFFSET          0x1008
#define FLASH_DATALOWER_OFFSET          0x100c
#define FLASH_EFUSECFG_OFFSET           0x1010
#define FLASH_EFUSESTAT_OFFSET          0x1014
#define FLASH_ACC_OFFSET                0x1018
#define FLASH_BOUNDARY_OFFSET           0x101c
#define FLASH_EFUSEFLAG_OFFSET          0x1020
#define FLASH_EFUSEKEY_OFFSET           0x1024
#define FLASH_EFUSERELEASE_OFFSET       0x1028
#define FLASH_EFUSEPINS_OFFSET          0x102c
#define FLASH_EFUSECRA_OFFSET           0x1030
#define FLASH_EFUSEREAD_OFFSET          0x1034
#define FLASH_EFUSEPROGRAM_OFFSET       0x1038
#define FLASH_EFUSEERROR_OFFSET         0x103c
#define FLASH_SINGLEBIT_OFFSET          0x1040
#define FLASH_TWOBIT_OFFSET             0x1044
#define FLASH_SELFTESTCYC_OFFSET        0x1048
#define FLASH_SELFTESTSIGN_OFFSET       0x104c
#define FLASH_FRDCTL_OFFSET             0x2000
#define FLASH_FSPRD_OFFSET              0x2004
#define FLASH_FEDACCTL1_OFFSET          0x2008
#define FLASH_FEDACSTAT_OFFSET          0x201c
#define FLASH_FBPROT_OFFSET             0x2030
#define FLASH_FBSE_OFFSET               0x2034
#define FLASH_FBBUSY_OFFSET             0x2038
#define FLASH_FBAC_OFFSET               0x203c
#define FLASH_FBFALLBACK_OFFSET         0x2040
#define FLASH_FBPRDY_OFFSET             0x2044
#define FLASH_FPAC1_OFFSET              0x2048
#define FLASH_FPAC2_OFFSET              0x204c
#define FLASH_FMAC_OFFSET               0x2050
#define FLASH_FMSTAT_OFFSET             0x2054
#define FLASH_FLOCK_OFFSET              0x2064
#define FLASH_FVREADCT_OFFSET           0x2080
#define FLASH_FVHVCT1_OFFSET            0x2084
#define FLASH_FVHVCT2_OFFSET            0x2088
#define FLASH_FVHVCT3_OFFSET            0x208c
#define FLASH_FVNVCT_OFFSET             0x2090
#define FLASH_FVSLP_OFFSET              0x2094
#define FLASH_FVWLCT_OFFSET             0x2098
#define FLASH_FEFUSECTL_OFFSET          0x209c
#define FLASH_FEFUSESTAT_OFFSET         0x20a0
#define FLASH_FEFUSEDATA_OFFSET         0x20a4
#define FLASH_FSEQPMP_OFFSET            0x20a8
#define FLASH_FBSTROBES_OFFSET          0x2100
#define FLASH_FPSTROBES_OFFSET          0x2104
#define FLASH_FBMODE_OFFSET             0x2108
#define FLASH_FTCR_OFFSET               0x210c
#define FLASH_FADDR_OFFSET              0x2110
#define FLASH_FTCTL_OFFSET              0x211c
#define FLASH_FWPWRITE0_OFFSET          0x2120
#define FLASH_FWPWRITE1_OFFSET          0x2124
#define FLASH_FWPWRITE2_OFFSET          0x2128
#define FLASH_FWPWRITE3_OFFSET          0x212c
#define FLASH_FWPWRITE4_OFFSET          0x2130
#define FLASH_FWPWRITE5_OFFSET          0x2134
#define FLASH_FWPWRITE6_OFFSET          0x2138
#define FLASH_FWPWRITE7_OFFSET          0x213c
#define FLASH_FWPWRITE_ECC_OFFSET       0x2140
#define FLASH_FSWSTAT_OFFSET            0x2144
#define FLASH_FSM_GLBCTL_OFFSET         0x2200
#define FLASH_FSM_STATE_OFFSET          0x2204
#define FLASH_FSM_STAT_OFFSET           0x2208
#define FLASH_FSM_CMD_OFFSET            0x220c
#define FLASH_FSM_PE_OSU_OFFSET         0x2210
#define FLASH_FSM_VSTAT_OFFSET          0x2214
#define FLASH_FSM_PE_VSU_OFFSET         0x2218
#define FLASH_FSM_CMP_VSU_OFFSET        0x221c
#define FLASH_FSM_EX_VAL_OFFSET         0x2220
#define FLASH_FSM_RD_H_OFFSET           0x2224
#define FLASH_FSM_P_OH_OFFSET           0x2228
#define FLASH_FSM_ERA_OH_OFFSET         0x222c
#define FLASH_FSM_SAV_PPUL_OFFSET       0x2230
#define FLASH_FSM_PE_VH_OFFSET          0x2234
#define FLASH_FSM_PRG_PW_OFFSET         0x2240
#define FLASH_FSM_ERA_PW_OFFSET         0x2244
#define FLASH_FSM_SAV_ERA_PUL_OFFSET    0x2254
#define FLASH_FSM_TIMER_OFFSET          0x2258
#define FLASH_FSM_MODE_OFFSET           0x225c
#define FLASH_FSM_PGM_OFFSET            0x2260
#define FLASH_FSM_ERA_OFFSET            0x2264
#define FLASH_FSM_PRG_PUL_OFFSET        0x2268
#define FLASH_FSM_ERA_PUL_OFFSET        0x226c
#define FLASH_FSM_STEP_SIZE_OFFSET      0x2270
#define FLASH_FSM_PUL_CNTR_OFFSET       0x2274
#define FLASH_FSM_EC_STEP_HEIGHT_OFFSET 0x2278
#define FLASH_FSM_ST_MACHINE_OFFSET     0x227c
#define FLASH_FSM_FLES_OFFSET           0x2280
#define FLASH_FSM_WR_ENA_OFFSET         0x2288
#define FLASH_FSM_ACC_PP_OFFSET         0x228c
#define FLASH_FSM_ACC_EP_OFFSET         0x2290
#define FLASH_FSM_ADDR_OFFSET           0x22a0
#define FLASH_FSM_SECTOR_OFFSET         0x22a4
#define FLASH_FMC_REV_ID_OFFSET         0x22a8
#define FLASH_FSM_ERR_ADDR_OFFSET       0x22ac
#define FLASH_FSM_PGM_MAXPUL_OFFSET     0x22b0
#define FLASH_FSM_EXECUTE_OFFSET        0x22b4
#define FLASH_FSM_SECTOR1_OFFSET        0x22c0
#define FLASH_FSM_SECTOR2_OFFSET        0x22c4
#define FLASH_FSM_BSLE0_OFFSET          0x22e0
#define FLASH_FSM_BSLE1_OFFSET          0x22e4
#define FLASH_FSM_BSLP0_OFFSET          0x22f0
#define FLASH_FSM_BSLP1_OFFSET          0x22f4
#define FLASH_FSM_PGM128_OFFSET         0x22f8  /* FMC FSM Enable 128-bit Wide Programming */
#define FLASH_FCFG_BANK_OFFSET          0x2400
#define FLASH_FCFG_WRAPPER_OFFSET       0x2404
#define FLASH_FCFG_BNK_TYPE_OFFSET      0x2408
#define FLASH_FCFG_B0_START_OFFSET      0x2410
#define FLASH_FCFG_B1_START_OFFSET      0x2414
#define FLASH_FCFG_B2_START_OFFSET      0x2418
#define FLASH_FCFG_B3_START_OFFSET      0x241c
#define FLASH_FCFG_B4_START_OFFSET      0x2420
#define FLASH_FCFG_B5_START_OFFSET      0x2424
#define FLASH_FCFG_B6_START_OFFSET      0x2428
#define FLASH_FCFG_B7_START_OFFSET      0x242c
#define FLASH_FCFG_B0_SSIZE0_OFFSET     0x2430

/* FLASH Register Addresses *************************************************************************/

/* FLASH Bitfield Definitions ***********************************************************************/

/* FLASH_STAT */

#define FLASH_STAT_POWER_MODE           (1 << 0)  /* Bit 0:  Low power state of flash sub-system */
#define FLASH_STAT_BUSY                 (1 << 1)  /* Bit 1:  Fast version of the FMC FMSTAT.BUSY bit */
#define FLASH_STAT_SAMHOLD_DIS          (1 << 2)  /* Bit 2:  Status of flash sample and hold sequencing logic */
#define FLASH_STAT_EFUSE_ERRCODE_SHIFT  (8)       /* Bits 8-12:  Same as EFUSEERROR.CODE */
#define FLASH_STAT_EFUSE_ERRCODE_MASK   (31 << FLASH_STAT_EFUSE_ERRCODE_SHIFT)
#define FLASH_STAT_SPRS_BYTE_NOT_OK     (1 << 13) /* Bit 13:  Efuse scanning resulted in scan chain Sparse byte error. */
#define FLASH_STAT_EFUSE_TIMEOUT        (1 << 14) /* Bit 14: Efuse scanning resulted in timeout error */
#define FLASH_STAT_EFUSE_BLANK          (1 << 15) /* Bit 15: Efuse scanning detected if fuse ROM is blank */

/* FLASH_CFG */

#define FLASH_CFG_DIS_IDLE              (1 << 0)  /* Bit 0 */
#define FLASH_CFG_DIS_STANDBY           (1 << 1)  /* Bit 1 */
#define FLASH_CFG_ENABLE_SWINTF         (1 << 3)  /* Bit 3 */
#define FLASH_CFG_DIS_READACCESS        (1 << 4)  /* Bit 4 */
#define FLASH_CFG_DIS_EFUSECLK          (1 << 5)  /* Bit 5 */
#define FLASH_CFG_STANDBY_PW_SEL_SHIFT  (6)       /* Bits 6-7 */
#define FLASH_CFG_STANDBY_PW_SEL_MASK   (3 << FLASH_CFG_STANDBY_PW_SEL_SHIFT)
#define FLASH_CFG_STANDBY_MODE_SEL      (1 << 8)  /* Bit 8 */

/* FLASH_SYSCODE_START */

#define FLASH_SYSCODE_START_SYSCODE_START_SHIFT (0)     /* Bits 0-5 */
#define FLASH_SYSCODE_START_SYSCODE_START_MASK  (0x3f << FLASH_SYSCODE_START_SYSCODE_START_SHIFT)

/* FLASH_FLASH_SIZE */

#define FLASH_FLASH_SIZE_SECTORS_SHIFT  (0)       /* Bits 0-7 */
#define FLASH_FLASH_SIZE_SECTORS_MASK   (0xff << FLASH_FLASH_SIZE_SECTORS_SHIFT)

/* FLASH_FWLOCK */

#define FLASH_FWLOCK_FWLOCK_SHIFT       (0)       /* Bits 0-2 */
#define FLASH_FWLOCK_FWLOCK_MASK        (7 << FLASH_FWLOCK_FWLOCK_SHIFT)

/* FLASH_FWFLAG */

#define FLASH_FWFLAG_FWFLAG_SHIFT       (0)       /* Bits 0-2 */
#define FLASH_FWFLAG_FWFLAG_MASK        (7 << FLASH_FWFLAG_FWFLAG_SHIFT)

/* FLASH_EFUSE */

#define FLASH_EFUSE_DUMPWORD_SHIFT      (0)       /* Bits 0-5 */
#define FLASH_EFUSE_DUMPWORD_MASK       (0xffff << FLASH_EFUSE_DUMPWORD_SHIFT)
#define FLASH_EFUSE_INSTRUCTION_SHIFT   (24)      /* Bits 24-28 */
#define FLASH_EFUSE_INSTRUCTION_MASK    (31 << FLASH_EFUSE_INSTRUCTION_SHIFT)

/* FLASH_EFUSEADDR */

#define FLASH_EFUSEADDR_ROW_SHIFT       (0)       /* Bits 0-10 */
#define FLASH_EFUSEADDR_ROW_MASK        (0x7ff << FLASH_EFUSEADDR_ROW_SHIFT)
#define FLASH_EFUSEADDR_BLOCK_SHIFT     (11)      /* Bits 11-15 */
#define FLASH_EFUSEADDR_BLOCK_MASK      (31 << FLASH_EFUSEADDR_BLOCK_SHIFT)

/* FLASH_DATAUPPER */

#define FLASH_DATAUPPER_EEN             (1 << 0)  /* Bit 0 */
#define FLASH_DATAUPPER_R               (1 << 1)  /* Bit 1 */
#define FLASH_DATAUPPER_P               (1 << 2)  /* Bit 2 */
#define FLASH_DATAUPPER_SPARE_SHIFT     (3)       /* Bits 3-7 */
#define FLASH_DATAUPPER_SPARE_MASK      (31 << FLASH_DATAUPPER_SPARE_SHIFT)

/* FLASH_DATALOWER (32-bit value) */

/* FLASH_EFUSECFG */

#define FLASH_EFUSECFG_IDLEGATING       (1 << 8)  /* Bit 8 */

#define FLASH_EFUSECFG_GATING           (1 << 0)  /* Bit 0 */
#define FLASH_EFUSECFG_SLAVEPOWER_SHIFT (3)       /* Bits 3-4 */
#define FLASH_EFUSECFG_SLAVEPOWER_MASK  (3 << FLASH_EFUSECFG_SLAVEPOWER_SHIFT)

/* FLASH_EFUSESTAT */

#define FLASH_EFUSESTAT_RESETDONE       (1 << 0)  /* Bit 0 */

/* FLASH_ACC */

#define FLASH_ACC_ACCUMULATOR_SHIFT     (0)     /* Bits 0-23 */
#define FLASH_ACC_ACCUMULATOR_MASK      (0xffffff << FLASH_ACC_ACCUMULATOR_SHIFT)

/* FLASH_BOUNDARY */

#define FLASH_BOUNDARY_INPUTENABLE_SHIFT        (0)     /* Bits 0-3 */
#define FLASH_BOUNDARY_INPUTENABLE_MASK         (15 << FLASH_BOUNDARY_INPUTENABLE_SHIFT)
#define FLASH_BOUNDARY_SYS_WS_READ_STATES_SHIFT (4)     /* Bits 4-7 */
#define FLASH_BOUNDARY_SYS_WS_READ_STATES_MASK  (15 << FLASH_BOUNDARY_SYS_WS_READ_STATES_SHIFT)
#define FLASH_BOUNDARY_SYS_REPAIR_EN_SHIFT      (8)       /* Bits 8-9 */
#define FLASH_BOUNDARY_SYS_REPAIR_EN_MASK       (3 << FLASH_BOUNDARY_SYS_REPAIR_EN_SHIFT)
#define FLASH_BOUNDARY_SYS_DIEID_AUTOLOAD_EN    (1 << 10) /* Bit 10 */
#define FLASH_BOUNDARY_EFC_FDI                  (1 << 11) /* Bit 11 */
#define FLASH_BOUNDARY_SYS_ECC_OVERRIDE_EN      (1 << 12) /* Bit 12 */
#define FLASH_BOUNDARY_SYS_ECC_SELF_TEST_EN     (1 << 13) /* Bit 13 */
#define FLASH_BOUNDARY_OUTPUTENABLE_SHIFT       (14)      /* Bits 14-17 */
#define FLASH_BOUNDARY_OUTPUTENABLE_MASK        (15 << FLASH_BOUNDARY_OUTPUTENABLE_SHIFT)
#define FLASH_BOUNDARY_EFC_AUTOLOAD_ERROR       (1 << 18) /* Bit 18 */
#define FLASH_BOUNDARY_EFC_INSTRUCTION_ERROR    (1 << 19) /* Bit 19 */
#define FLASH_BOUNDARY_EFC_INSTRUCTION_INFO     (1 << 20) /* Bit 20 */
#define FLASH_BOUNDARY_EFC_SELF_TEST_ERROR      (1 << 21) /* Bit 21 */
#define FLASH_BOUNDARY_SPARE                    (1 << 22) /* Bit 22 */
#define FLASH_BOUNDARY_DISROW0                  (1 << 23) /* Bit 23 */

/* FLASH_EFUSEFLAG */

#define FLASH_EFUSEFLAG_KEY             (1 << 0)  /* Bit 0 */

/* FLASH_EFUSEKEY (32-bit code) */

/* FLASH_EFUSERELEASE */

#define FLASH_EFUSERELEASE_EFUSEDAY_SHIFT   (0)     /* Bits 0-4 */
#define FLASH_EFUSERELEASE_EFUSEDAY_MASK    (31 << FLASH_EFUSERELEASE_EFUSEDAY_SHIFT)
#define FLASH_EFUSERELEASE_EFUSEMONTH_SHIFT (5)     /* Bits 5-8 */
#define FLASH_EFUSERELEASE_EFUSEMONTH_MASK  (15 << FLASH_EFUSERELEASE_EFUSEMONTH_SHIFT)
#define FLASH_EFUSERELEASE_EFUSEYEAR_SHIFT  (9)     /* Bits 9-15 */
#define FLASH_EFUSERELEASE_EFUSEYEAR_MASK   (0x7f << FLASH_EFUSERELEASE_EFUSEYEAR_SHIFT)
#define FLASH_EFUSERELEASE_ODPDAY_SHIFT     (16)     /* Bits 16-20 */
#define FLASH_EFUSERELEASE_ODPDAY_MASK      (31 << FLASH_EFUSERELEASE_ODPDAY_SHIFT)
#define FLASH_EFUSERELEASE_ODPMONTH_SHIFT   (21)     /* Bits 21-24 */
#define FLASH_EFUSERELEASE_ODPMONTH_MASK    (15 << FLASH_EFUSERELEASE_ODPMONTH_SHIFT)
#define FLASH_EFUSERELEASE_ODPYEAR_SHIFT    (25)     /* Bits 25-31 */
#define FLASH_EFUSERELEASE_ODPYEAR_MASK     (0x7f << FLASH_EFUSERELEASE_ODPYEAR_SHIFT)

/* FLASH_EFUSEPINS */

#define FLASH_EFUSEPINS_SYS_WS_READ_STATES_SHIFT (0)       /* Bits 0-3 */
#define FLASH_EFUSEPINS_SYS_WS_READ_STATES_MASK  (15 << FLASH_EFUSEPINS_SYS_WS_READ_STATES_SHIFT)
#define FLASH_EFUSEPINS_SYS_REPAIR_EN_SHIFT      (4)       /* Bits 4-5 */
#define FLASH_EFUSEPINS_SYS_REPAIR_EN_MASK       (3 << FLASH_EFUSEPINS_SYS_REPAIR_EN_SHIFT)
#define FLASH_EFUSEPINS_SYS_DIEID_AUTOLOAD_EN    (1 << 6)  /* Bit 6 */
#define FLASH_EFUSEPINS_EFC_FCLRZ                (1 << 7)  /* Bit 7 */
#define FLASH_EFUSEPINS_EFC_READY                (1 << 8)  /* Bit 8 */
#define FLASH_EFUSEPINS_SYS_ECC_OVERRIDE_EN      (1 << 9)  /* Bit 9 */
#define FLASH_EFUSEPINS_EFC_AUTOLOAD_ERROR       (1 << 10) /* Bit 10 */
#define FLASH_EFUSEPINS_EFC_INSTRUCTION_ERROR    (1 << 11) /* Bit 11 */
#define FLASH_EFUSEPINS_EFC_INSTRUCTION_INFO     (1 << 12) /* Bit 12 */
#define FLASH_EFUSEPINS_SYS_ECC_SELF_TEST_EN     (1 << 13) /* Bit 13 */
#define FLASH_EFUSEPINS_EFC_SELF_TEST_ERROR      (1 << 14) /* Bit 14 */
#define FLASH_EFUSEPINS_EFC_SELF_TEST_DONE       (1 << 15) /* Bit 15 */

/* FLASH_EFUSECRA */

#define FLASH_EFUSECRA_DATA_SHIFT       (0)       /* Bits 0-5 */
#define FLASH_EFUSECRA_DATA_MASK        (0x3f << FLASH_EFUSECRA_DATA_SHIFT)

/* FLASH_EFUSEREAD */

#define FLASH_EFUSEREAD_MARGIN_SHIFT    (0)       /* Bits 0-1 */
#define FLASH_EFUSEREAD_MARGIN_MASK     (3 << FLASH_EFUSEREAD_MARGIN_SHIFT)
#define FLASH_EFUSEREAD_SPARE           (1 << 2)  /* Bit 2 */
#define FLASH_EFUSEREAD_DEBUG           (1 << 3)  /* Bit 3 */
#define FLASH_EFUSEREAD_READCLOCK_SHIFT (4)       /* Bits 4-7 */
#define FLASH_EFUSEREAD_READCLOCK_MASK  (15 << FLASH_EFUSEREAD_READCLOCK_SHIFT)
#define FLASH_EFUSEREAD_DATABIT_SHIFT   (8)       /* Bits 8-9 */
#define FLASH_EFUSEREAD_DATABIT_MASK    (3 << FLASH_EFUSEREAD_DATABIT_SHIFT)

/* FLASH_EFUSEPROGRAM */

#define FLASH_EFUSEPROGRAM_WRITECLOCK_SHIFT (0)       /* Bits 0-8 */
#define FLASH_EFUSEPROGRAM_ITERATIONS_SHIFT (9)       /* Bits 9-12 */
#define FLASH_EFUSEPROGRAM_ITERATIONS_MASK  (15 << FLASH_EFUSEPROGRAM_ITERATIONS_SHIFT)
#define FLASH_EFUSEPROGRAM_WRITECLOCK_MASK  (0x1ff << FLASH_EFUSEPROGRAM_WRITECLOCK_SHIFT)
#define FLASH_EFUSEPROGRAM_VPPTOVDD         (1 << 13) /* Bit 13 */
#define FLASH_EFUSEPROGRAM_CLOCKSTALL_SHIFT (14)      /* Bits 14-29 */
#define FLASH_EFUSEPROGRAM_CLOCKSTALL_MASK  (0xffff << FLASH_EFUSEPROGRAM_CLOCKSTALL_SHIFT)
#define FLASH_EFUSEPROGRAM_COMPAREDISABLE   (1 << 30) /* Bit 30 */

/* FLASH_EFUSEERROR */

#define FLASH_EFUSEERROR_CODE_SHIFT     (0)       /* Bits 0-4 */
#define FLASH_EFUSEERROR_CODE_MASK      (31 << FLASH_EFUSEERROR_CODE_SHIFT)
#define FLASH_EFUSEERROR_DONE           (1 << 5)  /* Bit 5 */

/* FLASH_SINGLEBIT */

#define FLASH_SINGLEBIT_FROM0           (1 << 0)  /* Bit 0 */
#define FLASH_SINGLEBIT_FROMN_SHIFT     (1)       /* Bits 1-31 */
#define FLASH_SINGLEBIT_FROMN_MASK      (0x7fffffff << FLASH_SINGLEBIT_FROMN_SHIFT)

/* FLASH_TWOBIT */

#define FLASH_TWOBIT_FROM0              (1 << 0)  /* Bit 0 */
#define FLASH_TWOBIT_FROMN_SHIFT        (1)       /* Bits 1-31 */
#define FLASH_TWOBIT_FROMN_MASK         (0x7fffffff << FLASH_TWOBIT_FROMN_SHIFT)

/* FLASH_SELFTESTCYC (32-bit value) */
/* FLASH_SELFTESTSIGN (32-bit value) */

/* FLASH_FRDCTL */

#define FLASH_FRDCTL_RWAIT_SHIFT        (8)       /* Bits 8-11 */
#define FLASH_FRDCTL_RWAIT_MASK         (15 << FLASH_FRDCTL_RWAIT_SHIFT)

/* FLASH_FSPRD */

#define FLASH_FSPRD_RM0                 (1 << 0)  /* Bit 0 */
#define FLASH_FSPRD_RM1                 (1 << 1)  /* Bit 1 */
#define FLASH_FSPRD_RMBSEM_SHIFT        (8)       /* Bits 8-15 */
#define FLASH_FSPRD_RMBSEM_MASK         (0xff << FLASH_FSPRD_RMBSEM_SHIFT)

/* FLASH_FEDACCTL1 */

#define FLASH_FEDACCTL1_SUSP_IGNR       (1 << 24) /* Bit 24 */

/* FLASH_FEDACSTAT */

#define FLASH_FEDACSTAT_FSM_DONE        (1 << 24)  /* Bit 24 */
#define FLASH_FEDACSTAT_RVF_INT         (1 << 25)  /* Bit 25 */

/* FLASH_FBPROT */

#define FLASH_FBPROT_PROTL1DIS          (1 << 0)  /* Bit 0 */

/* FLASH_FBSE */

#define FLASH_FBSE_BSE_SHIFT            (0)       /* Bits 0-15 */
#define FLASH_FBSE_BSE_MASK             (0xffff << FLASH_FBSE_BSE_SHIFT)

/* FLASH_FBBUSY */

#define FLASH_FBBUSY_BUSY_SHIFT         (0)       /* Bits 0-7 */
#define FLASH_FBBUSY_BUSY_MASK          (0xff << FLASH_FBBUSY_BUSY_SHIFT)

/* FLASH_FBAC */

#define FLASH_FBAC_VREADS_SHIFT         (0)       /* Bits 0-7 */
#define FLASH_FBAC_VREADS_MASK          (0xff << FLASH_FBAC_VREADS_SHIFT)
#define FLASH_FBAC_BAGP_SHIFT           (8)       /* Bits 8-15 */
#define FLASH_FBAC_BAGP_MASK            (0xff << FLASH_FBAC_BAGP_SHIFT)
#define FLASH_FBAC_OTPPROTDIS           (1 << 16) /* Bit 16 */

/* FLASH_FBFALLBACK */

#define FLASH_FBFALLBACK_BANKPWR0_SHIFT   (0)     /* Bits 0-1 */
#define FLASH_FBFALLBACK_BANKPWR0_MASK    (3 << FLASH_FBFALLBACK_BANKPWR0_SHIFT)
#define FLASH_FBFALLBACK_BANKPWR1_SHIFT   (2)     /* Bits 2-3 */
#define FLASH_FBFALLBACK_BANKPWR1_MASK    (3 << FLASH_FBFALLBACK_BANKPWR1_SHIFT)
#define FLASH_FBFALLBACK_BANKPWR2_SHIFT   (4)     /* Bits 4-5 */
#define FLASH_FBFALLBACK_BANKPWR2_MASK    (3 << FLASH_FBFALLBACK_BANKPWR2_SHIFT)
#define FLASH_FBFALLBACK_BANKPWR3_SHIFT   (6)     /* Bits 6-7 */
#define FLASH_FBFALLBACK_BANKPWR3_MASK    (3 << FLASH_FBFALLBACK_BANKPWR3_SHIFT)
#define FLASH_FBFALLBACK_BANKPWR4_SHIFT   (8)     /* Bits 8-9 */
#define FLASH_FBFALLBACK_BANKPWR4_MASK    (3 << FLASH_FBFALLBACK_BANKPWR4_SHIFT)
#define FLASH_FBFALLBACK_BANKPWR5_SHIFT   (10)     /* Bits 10-11 */
#define FLASH_FBFALLBACK_BANKPWR5_MASK    (3 << FLASH_FBFALLBACK_BANKPWR5_SHIFT)
#define FLASH_FBFALLBACK_BANKPWR6_SHIFT   (12)     /* Bits 12-13 */
#define FLASH_FBFALLBACK_BANKPWR6_MASK    (3 << FLASH_FBFALLBACK_BANKPWR6_SHIFT)
#define FLASH_FBFALLBACK_BANKPWR7_SHIFT   (14)     /* Bits 14-15 */
#define FLASH_FBFALLBACK_BANKPWR7_MASK    (3 << FLASH_FBFALLBACK_BANKPWR7_SHIFT)
#define FLASH_FBFALLBACK_REG_PWRSAV_SHIFT (16)     /* Bits 16-19 */
#define FLASH_FBFALLBACK_REG_PWRSAV_MASK  (15 << FLASH_FBFALLBACK_REG_PWRSAV_SHIFT)
#define FLASH_FBFALLBACK_FSM_PWRSAV_SHIFT (24)     /* Bits 24-27 */
#define FLASH_FBFALLBACK_FSM_PWRSAV_MASK  (15 << FLASH_FBFALLBACK_FSM_PWRSAV_SHIFT)

/* FLASH_FBPRDY */

#define FLASH_FBPRDY_BANKRDY            (1 << 0)  /* Bit 0 */
#define FLASH_FBPRDY_PUMPRDY            (1 << 15) /* Bit 15 */
#define FLASH_FBPRDY_BANKBUSY           (1 << 16) /* Bit 16 */

/* FLASH_FPAC1 */

#define FLASH_FPAC1_PUMPPWR_SHIFT       (0)       /* Bits 0-1 */
#define FLASH_FPAC1_PUMPPWR_MASK        (3 << FLASH_FPAC1_PUMPPWR_SHIFT)
#define FLASH_FPAC1_PUMPRESET_PW_SHIFT  (4)       /* Bits 4-15 */
#define FLASH_FPAC1_PUMPRESET_PW_MASK   (0xfff << FLASH_FPAC1_PUMPRESET_PW_SHIFT)
#define FLASH_FPAC1_PSLEEPTDIS_SHIFT    (16)      /* Bits 16-17 */
#define FLASH_FPAC1_PSLEEPTDIS_MASK     (0xfff << FLASH_FPAC1_PSLEEPTDIS_SHIFT)

/* FLASH_FPAC2 */

#define FLASH_FPAC2_PAGP_SHIFT          (0)     /* Bits 0-25 */
#define FLASH_FPAC2_PAGP_MASK           (0xffff << FLASH_FPAC2_PAGP_SHIFT)

/* FLASH_FMAC */

#define FLASH_FMAC_BANK_SHIFT           (0)     /* Bits 0-2 */
#define FLASH_FMAC_BANK_MASK            (7 << FLASH_FMAC_BANK_SHIFT)

/* FLASH_FMSTAT */

#define FLASH_FMSTAT_SLOCK              (1 << 0)  /* Bit 0 */
#define FLASH_FMSTAT_PSUSP              (1 << 1)  /* Bit 1 */
#define FLASH_FMSTAT_ESUSP              (1 << 2)  /* Bit 2 */
#define FLASH_FMSTAT_VOLSTAT            (1 << 3)  /* Bit 3 */
#define FLASH_FMSTAT_CSTAT              (1 << 4)  /* Bit 4 */
#define FLASH_FMSTAT_INVDAT             (1 << 5)  /* Bit 5 */
#define FLASH_FMSTAT_PGM                (1 << 6)  /* Bit 6 */
#define FLASH_FMSTAT_ERS                (1 << 7)  /* Bit 7 */
#define FLASH_FMSTAT_BUSY               (1 << 8)  /* Bit 8 */
#define FLASH_FMSTAT_CV                 (1 << 9)  /* Bit 9 */
#define FLASH_FMSTAT_EV                 (1 << 10) /* Bit 10 */
#define FLASH_FMSTAT_PCV                (1 << 11) /* Bit 11 */
#define FLASH_FMSTAT_PGV                (1 << 12) /* Bit 12 */
#define FLASH_FMSTAT_DBF                (1 << 13) /* Bit 13 */
#define FLASH_FMSTAT_ILA                (1 << 14) /* Bit 14 */
#define FLASH_FMSTAT_RVF                (1 << 15) /* Bit 15 */
#define FLASH_FMSTAT_RDVER              (1 << 16) /* Bit 16 */
#define FLASH_FMSTAT_RVSUSP             (1 << 17) /* Bit 17 */

/* FLASH_FLOCK */

#define FLASH_FLOCK_ENCOM_SHIFT         (0)       /* Bits 0-15 */
#define FLASH_FLOCK_ENCOM_MASK          (0xffff << FLASH_FLOCK_ENCOM_SHIFT)

/* FLASH_FVREADCT */

#define FLASH_FVREADCT_VREADCT_SHIFT    (0)       /* Bits 0-3 */
#define FLASH_FVREADCT_VREADCT_MASK     (15 << FLASH_FVREADCT_VREADCT_SHIFT)

/* FLASH_FVHVCT1 */

#define FLASH_FVHVCT1_VHVCT_PV_SHIFT    (0)       /* Bits 0-3 */
#define FLASH_FVHVCT1_VHVCT_PV_MASK     (15 << FLASH_FVHVCT1_VHVCT_PV_SHIFT)
#define FLASH_FVHVCT1_TRIM13_PV_SHIFT   (4)       /* Bits 4-7 */
#define FLASH_FVHVCT1_TRIM13_PV_MASK    (15 << FLASH_FVHVCT1_TRIM13_PV_SHIFT)
#define FLASH_FVHVCT1_VHVCT_E_SHIFT     (16)      /* Bits 16-19 */
#define FLASH_FVHVCT1_VHVCT_E_MASK      (15 << FLASH_FVHVCT1_VHVCT_E_SHIFT)
#define FLASH_FVHVCT1_TRIM13_E_SHIFT    (20)      /* Bits 20-23 */
#define FLASH_FVHVCT1_TRIM13_E_MASK     (15 << FLASH_FVHVCT1_TRIM13_E_SHIFT)

/* FLASH_FVHVCT2 */

#define FLASH_FVHVCT2_VHVCT_P_SHIFT     (16)      /* Bits 16-19 */
#define FLASH_FVHVCT2_VHVCT_P_MASK      (15 << FLASH_FVHVCT2_VHVCT_P_SHIFT)
#define FLASH_FVHVCT2_TRIM13_P_SHIFT    (20)      /* Bits 20-23 */
#define FLASH_FVHVCT2_TRIM13_P_MASK     (15 << FLASH_FVHVCT2_TRIM13_P_SHIFT)

/* FLASH_FVHVCT3 */

#define FLASH_FVHVCT3_VHVCT_READ_SHIFT  (0)       /* Bits 0-3 */
#define FLASH_FVHVCT3_VHVCT_READ_MASK   (15 << FLASH_FVHVCT3_VHVCT_READ_SHIFT)
#define FLASH_FVHVCT3_WCT_SHIFT         (16)      /* Bits 16-19 */
#define FLASH_FVHVCT3_WCT_MASK          (15 << FLASH_FVHVCT3_WCT_SHIFT)

/* FLASH_FVNVCT */

#define FLASH_FVNVCT_VIN_CT_SHIFT       (0)       /* Bits 0-4 */
#define FLASH_FVNVCT_VIN_CT_MASK        (31 << FLASH_FVNVCT_VIN_CT_SHIFT)
#define FLASH_FVNVCT_VCG2P5CT_SHIFT     (8)       /* Bits 8-12 */
#define FLASH_FVNVCT_VCG2P5CT_MASK      (31 << FLASH_FVNVCT_VCG2P5CT_SHIFT)

/* FLASH_FVSLP */

#define FLASH_FVSLP_VSL_P_SHIFT         (12)      /* Bits 12-15 */
#define FLASH_FVSLP_VSL_P_MASK          (15 << FLASH_FVSLP_VSL_P_SHIFT)

/* FLASH_FVWLCT */

#define FLASH_FVWLCT_VWLCT_P_SHIFT      (0)       /* Bits 0-4 */
#define FLASH_FVWLCT_VWLCT_P_MASK       (31 << FLASH_FVWLCT_VWLCT_P_SHIFT)

/* FLASH_FEFUSECTL */

#define FLASH_FEFUSECTL_EFUSE_EN_SHIFT  (0)       /* Bits 0-3 */
#define FLASH_FEFUSECTL_EFUSE_EN_MASK   (15 << FLASH_FEFUSECTL_EFUSE_EN_SHIFT)
#define FLASH_FEFUSECTL_EF_TEST         (1 << 4)  /* Bit 4 */
#define FLASH_FEFUSECTL_EF_CLRZ         (1 << 8)  /* Bit 8 */
#define FLASH_FEFUSECTL_BP_SEL          (1 << 16) /* Bit 16 */
#define FLASH_FEFUSECTL_WRITE_EN        (1 << 17) /* Bit 17 */
#define FLASH_FEFUSECTL_CHAIN_SEL_SHIFT (24)      /* Bits 24-26 */
#define FLASH_FEFUSECTL_CHAIN_SEL_MASK  (7 << FLASH_FEFUSECTL_CHAIN_SEL_SHIFT)

/* FLASH_FEFUSESTAT */

#define FLASH_FEFUSESTAT_SHIFT_DONE     (1 << 0)  /* Bit 0 */

/* FLASH_FEFUSEDATA (32-bit value) */

/* FLASH_FSEQPMP */

#define FLASH_FSEQPMP_VIN_BY_PASS       (1 << 8)  /* Bit 8 */
#define FLASH_FSEQPMP_VIN_AT_X_SHIFT    (12)      /* Bits 12-14 */
#define FLASH_FSEQPMP_VIN_AT_X_MASK     (7 << FLASH_FSEQPMP_VIN_AT_X_SHIFT)
#define FLASH_FSEQPMP_TRIM_0P8_SHIFT    (16)      /* Bits 16-19 */
#define FLASH_FSEQPMP_TRIM_0P8_MASK     (15 << FLASH_FSEQPMP_TRIM_0P8_SHIFT)
#define FLASH_FSEQPMP_TRIM_1P7_SHIFT    (20)      /* Bits 20-21 */
#define FLASH_FSEQPMP_TRIM_1P7_MASK     (3 << FLASH_FSEQPMP_TRIM_1P7_SHIFT)
#define FLASH_FSEQPMP_TRIM_3P4_SHIFT    (24)      /* Bits 24-27 */
#define FLASH_FSEQPMP_TRIM_3P4_MASK     (15 << FLASH_FSEQPMP_TRIM_3P4_SHIFT)

/* FLASH_FBSTROBES */

#define FLASH_FBSTROBES_TEZ             (1 << 2)  /* Bit 2 */
#define FLASH_FBSTROBES_OTP             (1 << 3)  /* Bit 3 */
#define FLASH_FBSTROBES_TI_OTP          (1 << 4)  /* Bit 4 */
#define FLASH_FBSTROBES_PRECOL          (1 << 5)  /* Bit 5 */
#define FLASH_FBSTROBES_NOCOLRED        (1 << 6)  /* Bit 6 */
#define FLASH_FBSTROBES_CTRLENZ         (1 << 8)  /* Bit 8 */
#define FLASH_FBSTROBES_FLCLKEN         (1 << 16) /* Bit 16 */
#define FLASH_FBSTROBES_RWAIT_FLCLK     (1 << 17) /* Bit 17 */
#define FLASH_FBSTROBES_RWAIT2_FLCLK    (1 << 18) /* Bit 18 */
#define FLASH_FBSTROBES_ECBIT           (1 << 24) /* Bit 24 */

/* FLASH_FPSTROBES */

#define FLASH_FPSTROBES_V5PWRDNZ        (1 << 0)  /* Bit 0 */
#define FLASH_FPSTROBES_V3PWRDNZ        (1 << 1)  /* Bit 1 */
#define FLASH_FPSTROBES_EXECUTEZ        (1 << 8)  /* Bit 8 */

/* FLASH_FBMODE */

#define FLASH_FBMODE_MODE_SHIFT         (0)       /* Bits 0-2 */
#define FLASH_FBMODE_MODE_MASK          (7 << FLASH_FBMODE_MODE_SHIFT)

/* FLASH_FTCR */

#define FLASH_FTCR_TCR_SHIFT            (0)       /* Bits 0-6 */
#define FLASH_FTCR_TCR_MASK             (0x7f << FLASH_FTCR_TCR_SHIFT)

/* FLASH_FADDR (32-bit value) */

/* FLASH_FTCTL */

#define FLASH_FTCTL_TEST_EN             (1 << 1)  /* Bit 1 */
#define FLASH_FTCTL_WDATA_BLK_CLR       (1 << 16) /* Bit 16 */

/* FLASH_FWPWRITE0 (32-bit value) */
/* FLASH_FWPWRITE1 (32-bit value) */
/* FLASH_FWPWRITE2 (32-bit value) */
/* FLASH_FWPWRITE3 (32-bit value) */
/* FLASH_FWPWRITE4 (32-bit value) */
/* FLASH_FWPWRITE5 (32-bit value) */
/* FLASH_FWPWRITE6 (32-bit value) */
/* FLASH_FWPWRITE7 (32-bit value) */

/* FLASH_FWPWRITE_ECC */

#define FLASH_FWPWRITE_ECC_ECCBYTES31_24_SHIFT (0)       /* Bits 0-7 */
#define FLASH_FWPWRITE_ECC_ECCBYTES31_24_MASK  (0xff << FLASH_FWPWRITE_ECC_ECCBYTES31_24_SHIFT)
#define FLASH_FWPWRITE_ECC_ECCBYTES23_16_SHIFT (8)       /* Bits 8-15 */
#define FLASH_FWPWRITE_ECC_ECCBYTES23_16_MASK  (0xff << FLASH_FWPWRITE_ECC_ECCBYTES23_16_SHIFT)
#define FLASH_FWPWRITE_ECC_ECCBYTES15_08_SHIFT (16)      /* Bits 16-23 */
#define FLASH_FWPWRITE_ECC_ECCBYTES15_08_MASK  (0xff << FLASH_FWPWRITE_ECC_ECCBYTES15_08_SHIFT)
#define FLASH_FWPWRITE_ECC_ECCBYTES07_00_SHIFT (24)      /* Bits 24-31 */
#define FLASH_FWPWRITE_ECC_ECCBYTES07_00_MASK  (0xff << FLASH_FWPWRITE_ECC_ECCBYTES07_00_SHIFT)

/* FLASH_FSWSTAT */

#define FLASH_FSWSTAT_SAFELV            (1 << 0)  /* Bit 0 */

/* FLASH_FSM_GLBCTL */

#define FLASH_FSM_GLBCTL_CLKSEL         (1 << 0)  /* Bit 0 */

/* FLASH_FSM_STATE */

#define FLASH_FSM_STATE_OTP_ACT         (1 << 6)  /* Bit 6 */
#define FLASH_FSM_STATE_TIOTP_ACT       (1 << 7)  /* Bit 7 */
#define FLASH_FSM_STATE_FSM_ACT         (1 << 8)  /* Bit 8 */
#define FLASH_FSM_STATE_EXECUTEZ        (1 << 10) /* Bit 10 */
#define FLASH_FSM_STATE_CTRLENZ         (1 << 11) /* Bit 11 */

/* FLASH_FSM_STAT */

#define FLASH_FSM_STAT_INV_DAT          (1 << 0)  /* Bit 0 */
#define FLASH_FSM_STAT_OVR_PUL_CNT      (1 << 1)  /* Bit 1 */
#define FLASH_FSM_STAT_NON_OP           (1 << 2)  /* Bit 2 */

/* FLASH_FSM_CMD */

#define FLASH_FSM_CMD_FSMCMD_SHIFT      (0)       /* Bits 0-5 */
#define FLASH_FSM_CMD_FSMCMD_MASK       (0x3f << FLASH_FSM_CMD_FSMCMD_SHIFT)

/* FLASH_FSM_PE_OSU */

#define FLASH_FSM_PE_OSU_ERA_OSU_SHIFT  (0)       /* Bits 0-7 */
#define FLASH_FSM_PE_OSU_ERA_OSU_MASK   (0xff << FLASH_FSM_PE_OSU_ERA_OSU_SHIFT)
#define FLASH_FSM_PE_OSU_PGM_OSU_SHIFT  (8)       /* Bits 8-15 */
#define FLASH_FSM_PE_OSU_PGM_OSU_MASK   (0xff << FLASH_FSM_PE_OSU_PGM_OSU_SHIFT)

/* FLASH_FSM_VSTAT */

#define FLASH_FSM_VSTAT_VSTAT_CNT_SHIFT (12)      /* Bits 12-15 */
#define FLASH_FSM_VSTAT_VSTAT_CNT_MASK  (15 << FLASH_FSM_VSTAT_VSTAT_CNT_SHIFT)

/* FLASH_FSM_PE_VSU */

#define FLASH_FSM_PE_VSU_PGM_VSU_SHIFT  (8)       /* Bits 8-15 */
#define FLASH_FSM_PE_VSU_PGM_VSU_MASK   (0xff << FLASH_FSM_PE_VSU_PGM_VSU_SHIFT)
#define FLASH_FSM_PE_VSU_ERA_VSU_SHIFT  (0)       /* Bits 0-7 */
#define FLASH_FSM_PE_VSU_ERA_VSU_MASK   (0xff << FLASH_FSM_PE_VSU_ERA_VSU_SHIFT)

/* FLASH_FSM_CMP_VSU */

#define FLASH_FSM_CMP_VSU_ADD_EXZ_SHIFT (12)      /* Bits 12-15 */
#define FLASH_FSM_CMP_VSU_ADD_EXZ_MASK  (15<< FLASH_FSM_CMP_VSU_ADD_EXZ_SHIFT)

/* FLASH_FSM_EX_VAL */

#define FLASH_FSM_EX_VAL_EXE_VALD_SHIFT (0)       /* Bits 0-7 */
#define FLASH_FSM_EX_VAL_EXE_VALD_MASK  (0xff << FLASH_FSM_EX_VAL_EXE_VALD_SHIFT)
#define FLASH_FSM_EX_VAL_REP_VSU_SHIFT  (8)       /* Bits 8-15 */
#define FLASH_FSM_EX_VAL_REP_VSU_MASK   (0xff << FLASH_FSM_EX_VAL_REP_VSU_SHIFT)

/* FLASH_FSM_RD_H */

#define FLASH_FSM_RD_H_RD_H_SHIFT       (0)       /* Bits 0-7 */
#define FLASH_FSM_RD_H_RD_H_MASK        (0xff << FLASH_FSM_RD_H_RD_H_SHIFT)

/* FLASH_FSM_P_OH */

#define FLASH_FSM_P_OH_PGM_OH_SHIFT     (8)       /* Bits 8-15 */
#define FLASH_FSM_P_OH_PGM_OH_MASK      (0xff << FLASH_FSM_P_OH_PGM_OH_SHIFT)

/* FLASH_FSM_ERA_OH */

#define FLASH_FSM_ERA_OH_ERA_OH_SHIFT   (0)       /* Bits 0-15 */
#define FLASH_FSM_ERA_OH_ERA_OH_MASK    (0xffff << FLASH_FSM_ERA_OH_ERA_OH_SHIFT)

/* FLASH_FSM_SAV_PPUL */

#define FLASH_FSM_SAV_PPUL_SAV_P_PUL_SHIFT (0)    /* Bits 0-11 */
#define FLASH_FSM_SAV_PPUL_SAV_P_PUL_MASK  (0xfff << FLASH_FSM_SAV_PPUL_SAV_P_PUL_SHIFT)

/* FLASH_FSM_PE_VH */

#define FLASH_FSM_PE_VH_PGM_VH_SHIFT    (8)       /* Bits 8-15 */
#define FLASH_FSM_PE_VH_PGM_VH_MASK     (0xff << FLASH_FSM_PE_VH_PGM_VH_SHIFT)

/* FLASH_FSM_PRG_PW */

#define FLASH_FSM_PRG_PW_PROG_PUL_WIDTH_SHIFT (0)     /* Bits 0-15 */
#define FLASH_FSM_PRG_PW_PROG_PUL_WIDTH_MASK  (0xffff << FLASH_FSM_PRG_PW_PROG_PUL_WIDTH_SHIFT)

/* FLASH_FSM_ERA_PW (32-bit value) */

/* FLASH_FSM_SAV_ERA_PUL */

#define FLASH_FSM_SAV_ERA_PUL_SAV_ERA_PUL_SHIFT (0)     /* Bits 0-11 */
#define FLASH_FSM_SAV_ERA_PUL_SAV_ERA_PUL_MASK  (0xfff << FLASH_FSM_SAV_ERA_PUL_SAV_ERA_PUL_SHIFT)

/* FLASH_FSM_TIMER (32-bit value) */

/* FLASH_FSM_MODE */

#define FLASH_FSM_MODE_CMD_SHIFT          (0)       /* Bits 0-2 */
#define FLASH_FSM_MODE_CMD_MASK           (7 << FLASH_FSM_MODE_CMD_SHIFT)
#define FLASH_FSM_MODE_MODE_SHIFT         (3)       /* Bits 3-5 */
#define FLASH_FSM_MODE_MODE_MASK          (7 << FLASH_FSM_MODE_MODE_SHIFT)
#define FLASH_FSM_MODE_SAV_ERA_MODE_SHIFT (6)       /* Bits 6-8 */
#define FLASH_FSM_MODE_SAV_ERA_MODE_MASK  (7 << FLASH_FSM_MODE_SAV_ERA_MODE_SHIFT)
#define FLASH_FSM_MODE_SAV_PGM_CMD_SHIFT  (9)       /* Bits 9-11 */
#define FLASH_FSM_MODE_SAV_PGM_CMD_MASK   (7 << FLASH_FSM_MODE_SAV_PGM_CMD_SHIFT)
#define FLASH_FSM_MODE_SUBMODE_SHIFT      (12)      /* Bits 12-13 */
#define FLASH_FSM_MODE_SUBMODE_MASK       (3 << FLASH_FSM_MODE_SUBMODE_SHIFT)
#define FLASH_FSM_MODE_ERA_SUBMODE_SHIFT  (14)      /* Bits 14-15 */
#define FLASH_FSM_MODE_ERA_SUBMODE_MASK   (3 << FLASH_FSM_MODE_ERA_SUBMODE_SHIFT)
#define FLASH_FSM_MODE_PGM_SUBMODE_SHIFT  (16)      /* Bits 16-17 */
#define FLASH_FSM_MODE_PGM_SUBMODE_MASK   (3 << FLASH_FSM_MODE_PGM_SUBMODE_SHIFT)
#define FLASH_FSM_MODE_RDV_SUBMODE_SHIFT  (18)      /* Bits 18-19 */
#define FLASH_FSM_MODE_RDV_SUBMODE_MASK   (3 << FLASH_FSM_MODE_RDV_SUBMODE_SHIFT)

/* FLASH_FSM_PGM */

#define FLASH_FSM_PGM_PGM_ADDR_SHIFT    (0)       /* Bits 0-22 */
#define FLASH_FSM_PGM_PGM_ADDR_MASK     (0x7fffff << FLASH_FSM_PGM_PGM_ADDR_SHIFT)
#define FLASH_FSM_PGM_PGM_BANK_SHIFT    (23)      /* Bits 23-25 */
#define FLASH_FSM_PGM_PGM_BANK_MASK     (7 << FLASH_FSM_PGM_PGM_BANK_SHIFT)

/* FLASH_FSM_ERA */

#define FLASH_FSM_ERA_ERA_ADDR_SHIFT    (0)       /* Bits 0-22 */
#define FLASH_FSM_ERA_ERA_ADDR_MASK     (0x7fffff << FLASH_FSM_ERA_ERA_ADDR_SHIFT)
#define FLASH_FSM_ERA_ERA_BANK_SHIFT    (23)      /* Bits 23-25 */
#define FLASH_FSM_ERA_ERA_BANK_MASK     (7 << FLASH_FSM_ERA_ERA_BANK_SHIFT)

/* FLASH_FSM_PRG_PUL */

#define FLASH_FSM_PRG_PUL_MAX_PRG_PUL_SHIFT  (0)       /* Bits 0-11 */
#define FLASH_FSM_PRG_PUL_MAX_PRG_PUL_MASK   (0xfff << FLASH_FSM_PRG_PUL_MAX_PRG_PUL_SHIFT)
#define FLASH_FSM_PRG_PUL_BEG_EC_LEVEL_SHIFT (16)      /* Bits 16-19 */
#define FLASH_FSM_PRG_PUL_BEG_EC_LEVEL_MASK  (15 << FLASH_FSM_PRG_PUL_BEG_EC_LEVEL_SHIFT)

/* FLASH_FSM_ERA_PUL */

#define FLASH_FSM_ERA_PUL_MAX_ERA_PUL_SHIFT  (0)       /* Bits 0-11 */
#define FLASH_FSM_ERA_PUL_MAX_ERA_PUL_MASK   (0xfff << FLASH_FSM_ERA_PUL_MAX_ERA_PUL_SHIFT)
#define FLASH_FSM_ERA_PUL_MAX_EC_LEVEL_SHIFT (16)      /* Bits 16-19 */
#define FLASH_FSM_ERA_PUL_MAX_EC_LEVEL_MASK  (15 << FLASH_FSM_ERA_PUL_MAX_EC_LEVEL_SHIFT)

/* FLASH_FSM_STEP_SIZE */

#define FLASH_FSM_STEP_SIZE_EC_STEP_SIZE_SHIFT (16)      /* Bits 16-24 */
#define FLASH_FSM_STEP_SIZE_EC_STEP_SIZE_MASK  (0x1ff << FLASH_FSM_STEP_SIZE_EC_STEP_SIZE_SHIFT)

/* FLASH_FSM_PUL_CNTR */

#define FLASH_FSM_PUL_CNTR_PUL_CNTR_SHIFT      (0)       /* Bits 0-11 */
#define FLASH_FSM_PUL_CNTR_PUL_CNTR_MASK       (0xfff << FLASH_FSM_PUL_CNTR_PUL_CNTR_SHIFT)
#define FLASH_FSM_PUL_CNTR_CUR_EC_LEVEL_SHIFT  (16)      /* Bits 16-24 */
#define FLASH_FSM_PUL_CNTR_CUR_EC_LEVEL_MASK   (0x1ff << FLASH_FSM_PUL_CNTR_CUR_EC_LEVEL_SHIFT)

/* FLASH_FSM_EC_STEP_HEIGHT */

#define FLASH_FSM_EC_STEP_HEIGHT_EC_STEP_HEIGHT_SHIFT (0)     /* Bits 0-3 */
#define FLASH_FSM_EC_STEP_HEIGHT_EC_STEP_HEIGHT_MASK  (15 << FLASH_FSM_EC_STEP_HEIGHT_EC_STEP_HEIGHT_SHIFT)

/* FLASH_FSM_ST_MACHINE */

#define FLASH_FSM_ST_MACHINE_OVERRIDE            (1 << 0)  /* Bit 0 */
#define FLASH_FSM_ST_MACHINE_INV_DATA            (1 << 1)  /* Bit 1 */
#define FLASH_FSM_ST_MACHINE_CMD_EN              (1 << 2)  /* Bit 2 */
#define FLASH_FSM_ST_MACHINE_DIS_TST_EN          (1 << 3)  /* Bit 3 */
#define FLASH_FSM_ST_MACHINE_PREC_STOP_EN        (1 << 4)  /* Bit 4 */
#define FLASH_FSM_ST_MACHINE_PGM_SEC_COF_EN      (1 << 5)  /* Bit 5 */
#define FLASH_FSM_ST_MACHINE_DBG_SHORT_ROW_SHIFT (7)       /* Bits 7-10 */
#define FLASH_FSM_ST_MACHINE_DBG_SHORT_ROW_MASK  (15 << FLASH_FSM_ST_MACHINE_DBG_SHORT_ROW_SHIFT)
#define FLASH_FSM_ST_MACHINE_DO_REDU_COL         (1 << 11) /* Bit 11 */
#define FLASH_FSM_ST_MACHINE_ONE_TIME_GOOD       (1 << 14) /* Bit 14 */
#define FLASH_FSM_ST_MACHINE_RV_INT_EN           (1 << 16) /* Bit 16 */
#define FLASH_FSM_ST_MACHINE_RV_RES              (1 << 17) /* Bit 17 */
#define FLASH_FSM_ST_MACHINE_RV_SEC_EN           (1 << 18) /* Bit 18 */
#define FLASH_FSM_ST_MACHINE_RANDOM              (1 << 19) /* Bit 19 */
#define FLASH_FSM_ST_MACHINE_CMPV_ALLOWED        (1 << 20) /* Bit 20 */
#define FLASH_FSM_ST_MACHINE_ALL_BANKS           (1 << 21) /* Bit 21 */
#define FLASH_FSM_ST_MACHINE_FSM_INT_EN          (1 << 22) /* Bit 22 */
#define FLASH_FSM_ST_MACHINE_DO_PRECOND          (1 << 23) /* Bit 23 */

/* FLASH_FSM_FLES */

#define FLASH_FSM_FLES_BLK_OTP_SHIFT    (0)       /* Bits 0-7 */
#define FLASH_FSM_FLES_BLK_OTP_MASK     (0xff << FLASH_FSM_FLES_BLK_OTP_SHIFT)
#define FLASH_FSM_FLES_BLK_TIOTP_SHIFT  (8)       /* Bits 8-11 */
#define FLASH_FSM_FLES_BLK_TIOTP_MASK   15 << FLASH_FSM_FLES_BLK_TIOTP_SHIFT)

/* FLASH_FSM_WR_ENA */

#define FLASH_FSM_WR_ENA_WR_ENA_SHIFT   (0)       /* Bits 0-2 */
#define FLASH_FSM_WR_ENA_WR_ENA_MASK    (7 << FLASH_FSM_WR_ENA_WR_ENA_SHIFT)

/* FLASH_FSM_ACC_PP (32-bit value) */

/* FLASH_FSM_ACC_EP */

#define FLASH_FSM_ACC_EP_ACC_EP_SHIFT   (0)       /* Bits 0-15 */
#define FLASH_FSM_ACC_EP_ACC_EP_MASK    (0xffff << FLASH_FSM_ACC_EP_ACC_EP_SHIFT)

/* FLASH_FSM_ADDR */

#define FLASH_FSM_ADDR_CUR_ADDR_SHIFT   (0)       /* Bits 0-27 */
#define FLASH_FSM_ADDR_CUR_ADDR_MASK    (0xfffffff << FLASH_FSM_ADDR_CUR_ADDR_SHIFT)
#define FLASH_FSM_ADDR_BANK_SHIFT       (28)      /* Bits 28-30 */
#define FLASH_FSM_ADDR_BANK_MASK        (7 << FLASH_FSM_ADDR_BANK_SHIFT)

/* FLASH_FSM_SECTOR */

#define FLASH_FSM_SECTOR_SEC_OUT_SHIFT              (0)       /* Bits 0-3 */
#define FLASH_FSM_SECTOR_SEC_OUT_MASK               (15 << FLASH_FSM_SECTOR_SEC_OUT_SHIFT)
#define FLASH_FSM_SECTOR_SECTOR_SHIFT               (4)       /* Bits 4-7 */
#define FLASH_FSM_SECTOR_SECTOR_MASK                (15 << FLASH_FSM_SECTOR_SECTOR_SHIFT)
#define FLASH_FSM_SECTOR_FSM_SECTOR_EXTENSION_SHIFT (8)       /* Bits 8-15 */
#define FLASH_FSM_SECTOR_FSM_SECTOR_EXTENSION_MASK  (0xff << FLASH_FSM_SECTOR_FSM_SECTOR_EXTENSION_SHIFT)
#define FLASH_FSM_SECTOR_SECT_ERASED_SHIFT          (16)      /* Bits 16-31 */
#define FLASH_FSM_SECTOR_SECT_ERASED_MASK           (0xffff << FLASH_FSM_SECTOR_SECT_ERASED_SHIFT)

/* FLASH_FMC_REV_ID */

#define FLASH_FMC_REV_ID_CONFIG_CRC_SHIFT  (0)       /* Bits 0-11 */
#define FLASH_FMC_REV_ID_CONFIG_CRC_MASK   (0xfff << FLASH_FMC_REV_ID_CONFIG_CRC_SHIFT)
#define FLASH_FMC_REV_ID_MOD_VERSION_SHIFT (12)      /* Bits 12-31 */
#define FLASH_FMC_REV_ID_MOD_VERSION_MASK  (0xfffff << FLASH_FMC_REV_ID_MOD_VERSION_SHIFT)

/* FLASH_FSM_ERR_ADDR */

#define FLASH_FSM_ERR_ADDR_FSM_ERR_BANK_SHIFT (0)       /* Bits 0-3 */
#define FLASH_FSM_ERR_ADDR_FSM_ERR_BANK_MASK  (15 << FLASH_FSM_ERR_ADDR_FSM_ERR_BANK_SHIFT)
#define FLASH_FSM_ERR_ADDR_FSM_ERR_ADDR_SHIFT (8)       /* Bits 8-31 */
#define FLASH_FSM_ERR_ADDR_FSM_ERR_ADDR_MASK  (0xffffff << FLASH_FSM_ERR_ADDR_FSM_ERR_ADDR_SHIFT)

/* FLASH_FSM_PGM_MAXPUL */

#define FLASH_FSM_PGM_MAXPUL_FSM_PGM_MAXPUL_SHIFT (0)     /* Bits 0-11 */
#define FLASH_FSM_PGM_MAXPUL_FSM_PGM_MAXPUL_MASK  (0xfff << FLASH_FSM_PGM_MAXPUL_FSM_PGM_MAXPUL_SHIFT)

/* FLASH_FSM_EXECUTE */

#define FLASH_FSM_EXECUTE_FSMEXECUTE_SHIFT  (0)       /* Bits 0-4 */
#define FLASH_FSM_EXECUTE_FSMEXECUTE_MASK   (31 << FLASH_FSM_EXECUTE_FSMEXECUTE_SHIFT)
#define FLASH_FSM_EXECUTE_SUSPEND_NOW_SHIFT (16)      /* Bits 16-19 */
#define FLASH_FSM_EXECUTE_SUSPEND_NOW_MASK  (15 << FLASH_FSM_EXECUTE_SUSPEND_NOW_SHIFT)

/* FLASH_FSM_SECTOR1 (32-bit value) */
/* FLASH_FSM_SECTOR2 (32-bit value) */
/* FLASH_FSM_BSLE0 (32-bit value) */
/* FLASH_FSM_BSLE1 *(32-bit value) /
/* FLASH_FSM_BSLP0 (32-bit value) */
/* FLASH_FSM_BSLP1 (32-bit value) */

/* FLASH_FSM_PGM128 */

#define FLASH_FSM_PGM128_EN_PGM128      (1 << 0)  /* Bit 0:  Enable 129-bit wide programming (vs 64) */

/* FLASH_FCFG_BANK */

#define FLASH_FCFG_BANK_MAIN_NUM_BANK_SHIFT   (0)     /* Bits 0-3 */
#define FLASH_FCFG_BANK_MAIN_NUM_BANK_MASK    (15 << FLASH_FCFG_BANK_MAIN_NUM_BANK_SHIFT)
#define FLASH_FCFG_BANK_MAIN_BANK_WIDTH_SHIFT (4)     /* Bits 4-15 */
#define FLASH_FCFG_BANK_MAIN_BANK_WIDTH_MASK  (0xfff << FLASH_FCFG_BANK_MAIN_BANK_WIDTH_SHIFT)
#define FLASH_FCFG_BANK_EE_NUM_BANK_SHIFT     (16)     /* Bits 16-19 */
#define FLASH_FCFG_BANK_EE_NUM_BANK_MASK      (15 << FLASH_FCFG_BANK_EE_NUM_BANK_SHIFT)
#define FLASH_FCFG_BANK_EE_BANK_WIDTH_SHIFT   (20)     /* Bits 20-31 */
#define FLASH_FCFG_BANK_EE_BANK_WIDTH_MASK    (0xfff << FLASH_FCFG_BANK_EE_BANK_WIDTH_SHIFT)

/* FLASH_FCFG_WRAPPER */

#define FLASH_FCFG_WRAPPER_CPU_TYPE1_SHIFT   (0)       /* Bits 0-3 */
#define FLASH_FCFG_WRAPPER_CPU_TYPE1_MASK    (15 << FLASH_FCFG_WRAPPER_CPU_TYPE1_SHIFT)
#define FLASH_FCFG_WRAPPER_UERR_SHIFT        (4)       /* Bits 4-5 */
#define FLASH_FCFG_WRAPPER_UERR_MASK         (3 << FLASH_FCFG_WRAPPER_UERR_SHIFT)
#define FLASH_FCFG_WRAPPER_AUTO_SUSP_SHIFT   (6)       /* Bits 6-7 */
#define FLASH_FCFG_WRAPPER_AUTO_SUSP_MASK    (3 << FLASH_FCFG_WRAPPER_AUTO_SUSP_SHIFT)
#define FLASH_FCFG_WRAPPER_ECCA              (1 << 8)  /* Bit 8 */
#define FLASH_FCFG_WRAPPER_SIL3              (1 << 9)  /* Bit 9 */
#define FLASH_FCFG_WRAPPER_IFLUSH            (1 << 10) /* Bit 10 */
#define FLASH_FCFG_WRAPPER_ROM               (1 << 11) /* Bit 11 */
#define FLASH_FCFG_WRAPPER_EE_IN_MAIN_SHIFT  (12)      /* Bits 12-15 */
#define FLASH_FCFG_WRAPPER_EE_IN_MAIN_MASK   (15 << FLASH_FCFG_WRAPPER_EE_IN_MAIN_SHIFT)
#define FLASH_FCFG_WRAPPER_CPU2_SHIFT        (16)      /* Bits 16-19 */
#define FLASH_FCFG_WRAPPER_CPU2_MASK         (15 << FLASH_FCFG_WRAPPER_CPU2_SHIFT)
#define FLASH_FCFG_WRAPPER_MEM_MAP           (1 << 20) /* Bit 20 */
#define FLASH_FCFG_WRAPPER_FAMILY_TYPE_SHIFT (24)      /* Bits 24-31 */
#define FLASH_FCFG_WRAPPER_FAMILY_TYPE_MASK  (0xff << FLASH_FCFG_WRAPPER_FAMILY_TYPE_SHIFT)

/* FLASH_FCFG_BNK_TYPE */

#define FLASH_FCFG_BNK_TYPE_B0_TYPE_SHIFT (0)       /* Bits 0-3 */
#define FLASH_FCFG_BNK_TYPE_B0_TYPE_MASK  (15 << FLASH_FCFG_BNK_TYPE_B0_TYPE_SHIFT)
#define FLASH_FCFG_BNK_TYPE_B1_TYPE_SHIFT (4)       /* Bits 4-7 */
#define FLASH_FCFG_BNK_TYPE_B1_TYPE_MASK  (15 << FLASH_FCFG_BNK_TYPE_B1_TYPE_SHIFT)
#define FLASH_FCFG_BNK_TYPE_B2_TYPE_SHIFT (8)       /* Bits 8-11 */
#define FLASH_FCFG_BNK_TYPE_B2_TYPE_MASK  (15 << FLASH_FCFG_BNK_TYPE_B2_TYPE_SHIFT)
#define FLASH_FCFG_BNK_TYPE_B3_TYPE_SHIFT (12)      /* Bits 12-15 */
#define FLASH_FCFG_BNK_TYPE_B3_TYPE_MASK  (15 << FLASH_FCFG_BNK_TYPE_B3_TYPE_SHIFT)
#define FLASH_FCFG_BNK_TYPE_B4_TYPE_SHIFT (16)      /* Bits 16-19 */
#define FLASH_FCFG_BNK_TYPE_B4_TYPE_MASK  (15 << FLASH_FCFG_BNK_TYPE_B4_TYPE_SHIFT)
#define FLASH_FCFG_BNK_TYPE_B5_TYPE_SHIFT (20)      /* Bits 20-23 */
#define FLASH_FCFG_BNK_TYPE_B5_TYPE_MASK  (15 << FLASH_FCFG_BNK_TYPE_B5_TYPE_SHIFT)
#define FLASH_FCFG_BNK_TYPE_B6_TYPE_SHIFT (24)      /* Bits 24-27 */
#define FLASH_FCFG_BNK_TYPE_B6_TYPE_MASK  (15 << FLASH_FCFG_BNK_TYPE_B6_TYPE_SHIFT)
#define FLASH_FCFG_BNK_TYPE_B7_TYPE_SHIFT (28)      /* Bits 28-31 */
#define FLASH_FCFG_BNK_TYPE_B7_TYPE_MASK  (15 << FLASH_FCFG_BNK_TYPE_B7_TYPE_SHIFT)

/* FLASH_FCFG_B0_START */

#define FLASH_FCFG_B0_START_B0_START_ADDR_SHIFT (0)       /* Bits 0-23 */
#define FLASH_FCFG_B0_START_B0_START_ADDR_MASK  (0xffffff << FLASH_FCFG_B0_START_B0_START_ADDR_SHIFT)
#define FLASH_FCFG_B0_START_B0_MUX_FACTOR_SHIFT (24)      /* Bits 24-27 */
#define FLASH_FCFG_B0_START_B0_MUX_FACTOR_MASK  (15 << FLASH_FCFG_B0_START_B0_MUX_FACTOR_SHIFT)
#define FLASH_FCFG_B0_START_B0_MAX_SECTOR_SHIFT (28)      /* Bits 28-31 */
#define FLASH_FCFG_B0_START_B0_MAX_SECTOR_MASK  (15 << FLASH_FCFG_B0_START_B0_MAX_SECTOR_SHIFT)

/* FLASH_FCFG_B1_START */

#define FLASH_FCFG_B1_START_B1_START_ADDR_SHIFT (0)       /* Bits 0-23 */
#define FLASH_FCFG_B1_START_B1_START_ADDR_MASK  (0xffffff << FLASH_FCFG_B1_START_B1_START_ADDR_SHIFT)
#define FLASH_FCFG_B1_START_B1_MUX_FACTOR_SHIFT (24)      /* Bits 24-27 */
#define FLASH_FCFG_B1_START_B1_MUX_FACTOR_MASK  (15 << FLASH_FCFG_B1_START_B1_MUX_FACTOR_SHIFT)
#define FLASH_FCFG_B1_START_B1_MAX_SECTOR_SHIFT (28)      /* Bits 28-31 */
#define FLASH_FCFG_B1_START_B1_MAX_SECTOR_MASK  (15 << FLASH_FCFG_B1_START_B1_MAX_SECTOR_SHIFT)

/* FLASH_FCFG_B2_START */

#define FLASH_FCFG_B2_START_B2_START_ADDR_SHIFT (0)       /* Bits 0-23 */
#define FLASH_FCFG_B2_START_B2_START_ADDR_MASK  (0xffffff << FLASH_FCFG_B2_START_B2_START_ADDR_SHIFT)
#define FLASH_FCFG_B2_START_B2_MUX_FACTOR_SHIFT (24)      /* Bits 24-27 */
#define FLASH_FCFG_B2_START_B2_MUX_FACTOR_MASK  (15 << FLASH_FCFG_B2_START_B2_MUX_FACTOR_SHIFT)
#define FLASH_FCFG_B2_START_B2_MAX_SECTOR_SHIFT (28)      /* Bits 28-31 */
#define FLASH_FCFG_B2_START_B2_MAX_SECTOR_MASK  (15 << FLASH_FCFG_B2_START_B2_MAX_SECTOR_SHIFT)

/* FLASH_FCFG_B3_START */

#define FLASH_FCFG_B3_START_B3_START_ADDR_SHIFT (0)       /* Bits 0-23 */
#define FLASH_FCFG_B3_START_B3_START_ADDR_MASK  (0xffffff << FLASH_FCFG_B3_START_B3_START_ADDR_SHIFT)
#define FLASH_FCFG_B3_START_B3_MUX_FACTOR_SHIFT (24)      /* Bits 24-27 */
#define FLASH_FCFG_B3_START_B3_MUX_FACTOR_MASK  (15 << FLASH_FCFG_B3_START_B3_MUX_FACTOR_SHIFT)
#define FLASH_FCFG_B3_START_B3_MAX_SECTOR_SHIFT (28)      /* Bits 28-31 */
#define FLASH_FCFG_B3_START_B3_MAX_SECTOR_MASK  (15 << FLASH_FCFG_B3_START_B3_MAX_SECTOR_SHIFT)

/* FLASH_FCFG_B4_START */

#define FLASH_FCFG_B4_START_B4_START_ADDR_SHIFT (0)       /* Bits 0-23 */
#define FLASH_FCFG_B4_START_B4_START_ADDR_MASK  (0xffffff << FLASH_FCFG_B4_START_B4_START_ADDR_SHIFT)
#define FLASH_FCFG_B4_START_B4_MUX_FACTOR_SHIFT (24)      /* Bits 24-27 */
#define FLASH_FCFG_B4_START_B4_MUX_FACTOR_MASK  (15 << FLASH_FCFG_B4_START_B4_MUX_FACTOR_SHIFT)
#define FLASH_FCFG_B4_START_B4_MAX_SECTOR_SHIFT (28)      /* Bits 28-31 */
#define FLASH_FCFG_B4_START_B4_MAX_SECTOR_MASK  (15 << FLASH_FCFG_B4_START_B4_MAX_SECTOR_SHIFT)

/* FLASH_FCFG_B5_START */

#define FLASH_FCFG_B5_START_B5_START_ADDR_SHIFT (0)       /* Bits 0-23 */
#define FLASH_FCFG_B5_START_B5_START_ADDR_MASK  (0xffffff << FLASH_FCFG_B5_START_B5_START_ADDR_SHIFT)
#define FLASH_FCFG_B5_START_B5_MUX_FACTOR_SHIFT (24)      /* Bits 24-27 */
#define FLASH_FCFG_B5_START_B5_MUX_FACTOR_MASK  (15 << FLASH_FCFG_B5_START_B5_MUX_FACTOR_SHIFT)
#define FLASH_FCFG_B5_START_B5_MAX_SECTOR_SHIFT (28)      /* Bits 28-31 */
#define FLASH_FCFG_B5_START_B5_MAX_SECTOR_MASK  (15 << FLASH_FCFG_B5_START_B5_MAX_SECTOR_SHIFT)

/* FLASH_FCFG_B6_START */

#define FLASH_FCFG_B6_START_B6_START_ADDR_SHIFT (0)       /* Bits 0-23 */
#define FLASH_FCFG_B6_START_B6_START_ADDR_MASK  (0xffffff << FLASH_FCFG_B6_START_B6_START_ADDR_SHIFT)
#define FLASH_FCFG_B6_START_B6_MUX_FACTOR_SHIFT (24)      /* Bits 24-27 */
#define FLASH_FCFG_B6_START_B6_MUX_FACTOR_MASK  (15 << FLASH_FCFG_B6_START_B6_MUX_FACTOR_SHIFT)
#define FLASH_FCFG_B6_START_B6_MAX_SECTOR_SHIFT (28)      /* Bits 28-31 */
#define FLASH_FCFG_B6_START_B6_MAX_SECTOR_MASK  (15 << FLASH_FCFG_B6_START_B6_MAX_SECTOR_SHIFT)

/* FLASH_FCFG_B7_START */

#define FLASH_FCFG_B7_START_B7_START_ADDR_SHIFT (0)       /* Bits 0-23 */
#define FLASH_FCFG_B7_START_B7_START_ADDR_MASK  (0xffffff << FLASH_FCFG_B7_START_B7_START_ADDR_SHIFT)
#define FLASH_FCFG_B7_START_B7_MUX_FACTOR_SHIFT (24)      /* Bits 24-27 */
#define FLASH_FCFG_B7_START_B7_MUX_FACTOR_MASK  (15 << FLASH_FCFG_B7_START_B7_MUX_FACTOR_SHIFT)
#define FLASH_FCFG_B7_START_B7_MAX_SECTOR_SHIFT (28)      /* Bits 28-31 */
#define FLASH_FCFG_B7_START_B7_MAX_SECTOR_MASK  (15 << FLASH_FCFG_B7_START_B7_MAX_SECTOR_SHIFT)

/* FLASH_FCFG_B0_SSIZE0 */

#define FLASH_FCFG_B0_SSIZE0_B0_SECT_SIZE_SHIFT   (0)     /* Bits 0-3 */
#define FLASH_FCFG_B0_SSIZE0_B0_SECT_SIZE_MASK    (15 << FLASH_FCFG_B0_SSIZE0_B0_SECT_SIZE_SHIFT)
#define FLASH_FCFG_B0_SSIZE0_B0_NUM_SECTORS_SHIFT (16)    /* Bits 16-27 */
#define FLASH_FCFG_B0_SSIZE0_B0_NUM_SECTORS_MASK  (0xfff << FLASH_FCFG_B0_SSIZE0_B0_NUM_SECTORS_SHIFT)

#endif /* __ARCH_ARM_SRC_TIVA_HARDWARE_CC13X2_CC26X2_CC13X2_CC26X2_FLASH_H */
