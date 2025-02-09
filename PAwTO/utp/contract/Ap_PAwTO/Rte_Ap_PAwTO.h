/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2010 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_Ap_PAwTO.h
 *     Workspace:  C:/CMSynergy/PAwTO/autosar
 *     SW-C Type:  Ap_PAwTO
 *  Generated at:  Tue Oct 22 16:19:33 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_PAwTO> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_PAWTO_H
# define _RTE_AP_PAWTO_H

# ifdef RTE_APPLICATION_HEADER_FILE
#  error Multiple application header files included.
# endif
# define RTE_APPLICATION_HEADER_FILE

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Type.h"

typedef P2CONST(struct Rte_CDS_Ap_PAwTO, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DiagStsRecRmpToZeroFltPres_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_HandsOnDetect_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_HwTorque_HwNm_f32 ((Float)0)
# define Rte_InitValue_IWSSCalcVspd_Kph_f32 ((Float)0)
# define Rte_InitValue_LimitPercentFiltered_Uls_f32 ((Float)0)
# define Rte_InitValue_PABoostCurveSwitch_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_PAEnableRqst_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_PAErrInterfaceActive_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_PAExtSystemFltActive_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_PAIntSystemFltActive_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_PAManoeuvrePhase_Cnt_u08 ((UInt8)0u)
# define Rte_InitValue_PATrqOvCmdRqst_HwNm_f32 ((Float)0)
# define Rte_InitValue_PAWheelCriteriaMet_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_PAWhlDirRLStat_Cnt_u08 ((UInt8)3u)
# define Rte_InitValue_PAWhlDirRRStat_Cnt_u08 ((UInt8)3u)
# define Rte_InitValue_PAWhlPlsCntRLValid_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_PAWhlPlsCntRRValid_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_PrkAssistActive_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_PrkAssistState_Cnt_u08 ((UInt8)0u)
# define Rte_InitValue_PrkAssistSuspend_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_PrkAsstFuncPresent_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_PrkAsstSlewComplete_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_TOEOLDisable_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_TrqOvReverseGearEngage_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_VehicleSpeed_Kph_f32 ((Float)0)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_PAwTO_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_PAwTO_NxtrDiagMgr_GetNTCActive(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_PAWTO_APPL_VAR) NTCActive_Ptr_T_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_PAwTO_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_PAwTO_PrkAssistState_SCom_Transition(UInt8 State_Cnt_T_u08);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_PAwTO_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_PAWTO_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_PAwTO_SystemTime_GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_PAWTO_APPL_VAR) CurrentTime);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_PAwTO_Init1_HwTorque_HwNm_f32() \
  (Rte_Inst_Ap_PAwTO->PAwTO_Init1_HwTorque_HwNm_f32->value)

# define Rte_IRead_PAwTO_Per1_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc() \
  (Rte_Inst_Ap_PAwTO->PAwTO_Per1_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc->value)

# define Rte_IRead_PAwTO_Per1_DiagStsRecRmpToZeroFltPres_Cnt_lgc() \
  (Rte_Inst_Ap_PAwTO->PAwTO_Per1_DiagStsRecRmpToZeroFltPres_Cnt_lgc->value)

# define Rte_IRead_PAwTO_Per1_HwTorque_HwNm_f32() \
  (Rte_Inst_Ap_PAwTO->PAwTO_Per1_HwTorque_HwNm_f32->value)

# define Rte_IRead_PAwTO_Per1_LimitPercentFiltered_Uls_f32() \
  (Rte_Inst_Ap_PAwTO->PAwTO_Per1_LimitPercentFiltered_Uls_f32->value)

# define Rte_IRead_PAwTO_Per1_PAEnableRqst_Cnt_lgc() \
  (Rte_Inst_Ap_PAwTO->PAwTO_Per1_PAEnableRqst_Cnt_lgc->value)

# define Rte_IRead_PAwTO_Per1_PAErrInterfaceActive_Cnt_lgc() \
  (Rte_Inst_Ap_PAwTO->PAwTO_Per1_PAErrInterfaceActive_Cnt_lgc->value)

# define Rte_IRead_PAwTO_Per1_PAExtSystemFltActive_Cnt_lgc() \
  (Rte_Inst_Ap_PAwTO->PAwTO_Per1_PAExtSystemFltActive_Cnt_lgc->value)

# define Rte_IRead_PAwTO_Per1_PAIntSystemFltActive_Cnt_lgc() \
  (Rte_Inst_Ap_PAwTO->PAwTO_Per1_PAIntSystemFltActive_Cnt_lgc->value)

# define Rte_IRead_PAwTO_Per1_PAWheelCriteriaMet_Cnt_lgc() \
  (Rte_Inst_Ap_PAwTO->PAwTO_Per1_PAWheelCriteriaMet_Cnt_lgc->value)

# define Rte_IRead_PAwTO_Per1_PrkAsstFuncPresent_Cnt_lgc() \
  (Rte_Inst_Ap_PAwTO->PAwTO_Per1_PrkAsstFuncPresent_Cnt_lgc->value)

# define Rte_IRead_PAwTO_Per1_PrkAsstSlewComplete_Cnt_lgc() \
  (Rte_Inst_Ap_PAwTO->PAwTO_Per1_PrkAsstSlewComplete_Cnt_lgc->value)

# define Rte_IRead_PAwTO_Per1_TOEOLDisable_Cnt_lgc() \
  (Rte_Inst_Ap_PAwTO->PAwTO_Per1_TOEOLDisable_Cnt_lgc->value)

# define Rte_IRead_PAwTO_Per1_TrqOvReverseGearEngage_Cnt_lgc() \
  (Rte_Inst_Ap_PAwTO->PAwTO_Per1_TrqOvReverseGearEngage_Cnt_lgc->value)

# define Rte_IWrite_PAwTO_Per1_HandsOnDetect_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_PAwTO->PAwTO_Per1_HandsOnDetect_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_PAwTO_Per1_HandsOnDetect_Cnt_lgc() \
  (&Rte_Inst_Ap_PAwTO->PAwTO_Per1_HandsOnDetect_Cnt_lgc->value)

# define Rte_IWrite_PAwTO_Per1_PABoostCurveSwitch_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_PAwTO->PAwTO_Per1_PABoostCurveSwitch_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_PAwTO_Per1_PABoostCurveSwitch_Cnt_lgc() \
  (&Rte_Inst_Ap_PAwTO->PAwTO_Per1_PABoostCurveSwitch_Cnt_lgc->value)

# define Rte_IWrite_PAwTO_Per1_PrkAssistActive_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_PAwTO->PAwTO_Per1_PrkAssistActive_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_PAwTO_Per1_PrkAssistActive_Cnt_lgc() \
  (&Rte_Inst_Ap_PAwTO->PAwTO_Per1_PrkAssistActive_Cnt_lgc->value)

# define Rte_IWrite_PAwTO_Per1_PrkAssistState_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_PAwTO->PAwTO_Per1_PrkAssistState_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_PAwTO_Per1_PrkAssistState_Cnt_u08() \
  (&Rte_Inst_Ap_PAwTO->PAwTO_Per1_PrkAssistState_Cnt_u08->value)

# define Rte_IWrite_PAwTO_Per1_PrkAssistSuspend_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_PAwTO->PAwTO_Per1_PrkAssistSuspend_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_PAwTO_Per1_PrkAssistSuspend_Cnt_lgc() \
  (&Rte_Inst_Ap_PAwTO->PAwTO_Per1_PrkAssistSuspend_Cnt_lgc->value)

# define Rte_IRead_PAwTO_Per2_IWSSCalcVspd_Kph_f32() \
  (Rte_Inst_Ap_PAwTO->PAwTO_Per2_IWSSCalcVspd_Kph_f32->value)

# define Rte_IRead_PAwTO_Per2_PAEnableRqst_Cnt_lgc() \
  (Rte_Inst_Ap_PAwTO->PAwTO_Per2_PAEnableRqst_Cnt_lgc->value)

# define Rte_IRead_PAwTO_Per2_PAManoeuvrePhase_Cnt_u08() \
  (Rte_Inst_Ap_PAwTO->PAwTO_Per2_PAManoeuvrePhase_Cnt_u08->value)

# define Rte_IRead_PAwTO_Per2_PATrqOvCmdRqst_HwNm_f32() \
  (Rte_Inst_Ap_PAwTO->PAwTO_Per2_PATrqOvCmdRqst_HwNm_f32->value)

# define Rte_IRead_PAwTO_Per2_PAWhlDirRLStat_Cnt_u08() \
  (Rte_Inst_Ap_PAwTO->PAwTO_Per2_PAWhlDirRLStat_Cnt_u08->value)

# define Rte_IRead_PAwTO_Per2_PAWhlDirRRStat_Cnt_u08() \
  (Rte_Inst_Ap_PAwTO->PAwTO_Per2_PAWhlDirRRStat_Cnt_u08->value)

# define Rte_IRead_PAwTO_Per2_PAWhlPlsCntRLValid_Cnt_lgc() \
  (Rte_Inst_Ap_PAwTO->PAwTO_Per2_PAWhlPlsCntRLValid_Cnt_lgc->value)

# define Rte_IRead_PAwTO_Per2_PAWhlPlsCntRRValid_Cnt_lgc() \
  (Rte_Inst_Ap_PAwTO->PAwTO_Per2_PAWhlPlsCntRRValid_Cnt_lgc->value)

# define Rte_IRead_PAwTO_Per2_PrkAsstFuncPresent_Cnt_lgc() \
  (Rte_Inst_Ap_PAwTO->PAwTO_Per2_PrkAsstFuncPresent_Cnt_lgc->value)

# define Rte_IRead_PAwTO_Per2_TrqOvReverseGearEngage_Cnt_lgc() \
  (Rte_Inst_Ap_PAwTO->PAwTO_Per2_TrqOvReverseGearEngage_Cnt_lgc->value)

# define Rte_IRead_PAwTO_Per2_VehicleSpeed_Kph_f32() \
  (Rte_Inst_Ap_PAwTO->PAwTO_Per2_VehicleSpeed_Kph_f32->value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_PAwTO_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_NxtrDiagMgr_GetNTCActive Rte_Call_Ap_PAwTO_NxtrDiagMgr_GetNTCActive
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Ap_PAwTO_NxtrDiagMgr_SetNTCStatus
# define Rte_Call_PrkAssistState_SCom_Transition Rte_Call_Ap_PAwTO_PrkAssistState_SCom_Transition
# define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16 Rte_Call_Ap_PAwTO_SystemTime_DtrmnElapsedTime_mS_u16
# define Rte_Call_SystemTime_GetSystemTime_mS_u32 Rte_Call_Ap_PAwTO_SystemTime_GetSystemTime_mS_u32




# define RTE_START_SEC_AP_PAWTO_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: PAwTO_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_PAwTO_Init1_HwTorque_HwNm_f32(void)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_PrkAssistState_SCom_Transition(UInt8 State_Cnt_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PAWTO_APPL_CODE) PAwTO_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PAwTO_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_PAwTO_Per1_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc(void)
 *   Boolean Rte_IRead_PAwTO_Per1_DiagStsRecRmpToZeroFltPres_Cnt_lgc(void)
 *   Float Rte_IRead_PAwTO_Per1_HwTorque_HwNm_f32(void)
 *   Float Rte_IRead_PAwTO_Per1_LimitPercentFiltered_Uls_f32(void)
 *   Boolean Rte_IRead_PAwTO_Per1_PAEnableRqst_Cnt_lgc(void)
 *   Boolean Rte_IRead_PAwTO_Per1_PAErrInterfaceActive_Cnt_lgc(void)
 *   Boolean Rte_IRead_PAwTO_Per1_PAExtSystemFltActive_Cnt_lgc(void)
 *   Boolean Rte_IRead_PAwTO_Per1_PAIntSystemFltActive_Cnt_lgc(void)
 *   Boolean Rte_IRead_PAwTO_Per1_PAWheelCriteriaMet_Cnt_lgc(void)
 *   Boolean Rte_IRead_PAwTO_Per1_PrkAsstFuncPresent_Cnt_lgc(void)
 *   Boolean Rte_IRead_PAwTO_Per1_PrkAsstSlewComplete_Cnt_lgc(void)
 *   Boolean Rte_IRead_PAwTO_Per1_TOEOLDisable_Cnt_lgc(void)
 *   Boolean Rte_IRead_PAwTO_Per1_TrqOvReverseGearEngage_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_PAwTO_Per1_HandsOnDetect_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PAwTO_Per1_HandsOnDetect_Cnt_lgc(void)
 *   void Rte_IWrite_PAwTO_Per1_PABoostCurveSwitch_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PAwTO_Per1_PABoostCurveSwitch_Cnt_lgc(void)
 *   void Rte_IWrite_PAwTO_Per1_PrkAssistActive_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PAwTO_Per1_PrkAssistActive_Cnt_lgc(void)
 *   void Rte_IWrite_PAwTO_Per1_PrkAssistState_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_PAwTO_Per1_PrkAssistState_Cnt_u08(void)
 *   void Rte_IWrite_PAwTO_Per1_PrkAssistSuspend_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PAwTO_Per1_PrkAssistSuspend_Cnt_lgc(void)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCActive(NTCNumber NTC_Cnt_T_enum, Boolean *NTCActive_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_PrkAssistState_SCom_Transition(UInt8 State_Cnt_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PAWTO_APPL_CODE) PAwTO_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PAwTO_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_PAwTO_Per2_IWSSCalcVspd_Kph_f32(void)
 *   Boolean Rte_IRead_PAwTO_Per2_PAEnableRqst_Cnt_lgc(void)
 *   UInt8 Rte_IRead_PAwTO_Per2_PAManoeuvrePhase_Cnt_u08(void)
 *   Float Rte_IRead_PAwTO_Per2_PATrqOvCmdRqst_HwNm_f32(void)
 *   UInt8 Rte_IRead_PAwTO_Per2_PAWhlDirRLStat_Cnt_u08(void)
 *   UInt8 Rte_IRead_PAwTO_Per2_PAWhlDirRRStat_Cnt_u08(void)
 *   Boolean Rte_IRead_PAwTO_Per2_PAWhlPlsCntRLValid_Cnt_lgc(void)
 *   Boolean Rte_IRead_PAwTO_Per2_PAWhlPlsCntRRValid_Cnt_lgc(void)
 *   Boolean Rte_IRead_PAwTO_Per2_PrkAsstFuncPresent_Cnt_lgc(void)
 *   Boolean Rte_IRead_PAwTO_Per2_TrqOvReverseGearEngage_Cnt_lgc(void)
 *   Float Rte_IRead_PAwTO_Per2_VehicleSpeed_Kph_f32(void)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCActive(NTCNumber NTC_Cnt_T_enum, Boolean *NTCActive_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PAWTO_APPL_CODE) PAwTO_Per2(void);

# define RTE_STOP_SEC_AP_PAWTO_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1u)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1382470639
#    error "The magic number of the generated file <C:/CMSynergy/Ap_PAwTO/Rte_Ap_PAwTO.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1382470639
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_PAWTO_H */
