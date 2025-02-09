/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2011 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Components/Rte_Sa_MtrPos2.h
 *     Workspace:  C:/Sankar/Chrysler/Synergy/CL/Temp_work/Chrysler_LWR_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Mon Jul 18 14:56:54 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SA_MTRPOS2_H
# define _RTE_SA_MTRPOS2_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Type.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_CorrectedMtrPos_Rev_f32 (0.0F)
#  define Rte_InitValue_CosTheta1_Volt_f32 (0.0F)
#  define Rte_InitValue_MechMtrPos_Rev_f32 (0.0F)
#  define Rte_InitValue_MotorVelMRF_MtrRadpS_f32 (0.0F)
#  define Rte_InitValue_SinTheta1_Volt_f32 (0.0F)
#  define Rte_InitValue_SysCCorrectedMtrPos_Rev_f32 (0.0F)
#  define Rte_InitValue_SysCMechMtrPos_Rev_f32 (0.0F)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_2ms_10, RTE_VAR_NOINIT) Rte_Task_2ms_10;

#  define RTE_STOP_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

#  define Rte_IRead_MtrPos2_Per1_MotorVelMRF_MtrRadpS_f32() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_MtrVel_MRFMotorVel_MtrRadpS_f32.value)

#  define Rte_IWrite_MtrPos2_Per1_CorrectedMtrPos_Rev_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrPos2_MtrPos2_Per1.Rte_CorrectedMtrPos_Rev_f32.value = (data) \
  )

#  define Rte_IWriteRef_MtrPos2_Per1_CorrectedMtrPos_Rev_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrPos2_MtrPos2_Per1.Rte_CorrectedMtrPos_Rev_f32.value)

#  define Rte_IWrite_MtrPos2_Per1_CosTheta1_Volt_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrPos2_MtrPos2_Per1.Rte_CosTheta1_Volt_f32.value = (data) \
  )

#  define Rte_IWriteRef_MtrPos2_Per1_CosTheta1_Volt_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrPos2_MtrPos2_Per1.Rte_CosTheta1_Volt_f32.value)

#  define Rte_IWrite_MtrPos2_Per1_MechMtrPos_Rev_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrPos2_MtrPos2_Per1.Rte_MechMtrPos_Rev_f32.value = (data) \
  )

#  define Rte_IWriteRef_MtrPos2_Per1_MechMtrPos_Rev_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrPos2_MtrPos2_Per1.Rte_MechMtrPos_Rev_f32.value)

#  define Rte_IWrite_MtrPos2_Per1_SinTheta1_Volt_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrPos2_MtrPos2_Per1.Rte_SinTheta1_Volt_f32.value = (data) \
  )

#  define Rte_IWriteRef_MtrPos2_Per1_SinTheta1_Volt_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrPos2_MtrPos2_Per1.Rte_SinTheta1_Volt_f32.value)

#  define Rte_IWrite_MtrPos2_Per1_SysCCorrectedMtrPos_Rev_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrPos2_MtrPos2_Per1.Rte_SysCCorrectedMtrPos_Rev_f32.value = (data) \
  )

#  define Rte_IWriteRef_MtrPos2_Per1_SysCCorrectedMtrPos_Rev_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrPos2_MtrPos2_Per1.Rte_SysCCorrectedMtrPos_Rev_f32.value)

#  define Rte_IWrite_MtrPos2_Per1_SysCMechMtrPos_Rev_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrPos2_MtrPos2_Per1.Rte_SysCMechMtrPos_Rev_f32.value = (data) \
  )

#  define Rte_IWriteRef_MtrPos2_Per1_SysCMechMtrPos_Rev_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrPos2_MtrPos2_Per1.Rte_SysCMechMtrPos_Rev_f32.value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR10_APPL_VAR) NTCFailed_Ptr_T_lgc);
#  define RTE_STOP_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCFailed NxtrDiagMgr10_GetNTCFailed
#  define RTE_START_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
#  define RTE_STOP_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_SetNTCStatus NxtrDiagMgr10_SetNTCStatus


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_SA_MTRPOS2_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRPOS2_APPL_CODE) MtrPos2_Init1(void);

FUNC(void, RTE_SA_MTRPOS2_APPL_CODE) MtrPos2_Per1(void);

# define RTE_STOP_SEC_SA_MTRPOS2_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1468867288
#    error "The magic number of the generated file <C:/Sankar/Chrysler/Synergy/CL/Temp_work/Chrysler_LWR_EPS_TMS570/SwProject/Source/GenDataRte/Components/Rte_Sa_MtrPos2.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1468867288
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_MTRPOS2_H */
