/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_ThrmlDutyCycle.c
 *     Workspace:  C:/Synergy_projects/ThrmDutyCycle-lz4p8n/ThrmDutyCycle/autosar
 *     SW-C Type:  Ap_ThrmlDutyCycle
 *  Generated at:  Wed Feb 20 17:35:14 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_ThrmlDutyCycle>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr  4 10:00:00 2012
 * %version:          12 %
 * %derived_by:       nzt9hv %
 * %date_modified:    Thu Feb 28 10:28:40 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date       Rev      Author    Change Description                                                              SCR #
 * --------   -------  --------  ------------------------------------------------------------------------------  ------
 * 05/21/12   1        OT        Iniital Component Version                                                       3946
 * 05/30/12   2        LWW       Made local constant global, added limit block on maxout terms
 * 06/16/12   3        NRAR      6 filter embedded data constants values are changed- Anom 3445
 * 07/09/12   4        OT        Updated to SF-09 v003                                                           
 * 08/09/12   5        BWL       Updated to SF-09 v004
 * 08/10/12   6        BWL       Removed setting NTC status on defeat
 * 09/23/12   7        Selva     Checkpoints added and mempmap macros corrected		                              6250
 * 10/17/12   8        BWL       Updated to SF-09 v004                                                            6563
 * 01/31/12	  9,10	   Selva     Updated to SF09 v006   		 
 * 02/20/13	  11	   SP		 Updated to SF09 v007
 * 02/28/13	  12       Selva      Anomoly 4517 Fixed                                                              7502         
 * 01/31/12	  13	   Selva     Updated to SF09 v008   
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_ThrmlDutyCycle.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Ap_ThrmlDutyCycle_Cfg.h"
#include "fixmath.h"
#include "GlobalMacro.h"
#include "CalConstants.h"
#include "filters.h"
#include "interpolation.h"
#include "math.h"

STATIC FUNC(uint16, AP_DUTYCYCLE_CODE) StepVarXY_u16_s16Xu16Y_Cnt (const sint16 *TableX, const uint16 *TableY, 
					const uint16 Size, const sint16 input);

#define D_FILT1LPFKN_HZ_F32				0.100094f    /*  1/(2*Pi*1.59) */
#define D_FILT2LPFKN_HZ_F32				0.010009f    /*  1/(2*Pi*15.9)  */
#define D_FILT3LPFKN_HZ_F32				0.001001f    /*  1/(2*Pi*159)   */
#define D_FILT4LPFKN_HZ_F32				0.000531f    /*  1/(2*Pi*300)   */
#define D_FILT5LPFKN_HZ_F32				0.000100f    /*  1/(2*Pi*1590)  */
#define D_FILT6LPFKN_HZ_F32				0.000039f    /*  1/(2*Pi*4000)  */
#define D_FILTOUTLIM_ULS_F32			200.0f
#define D_1PERC_ULS_F32					0.01f
#define D_DEFEATDUTYCYCLELEVEL_ULS_F32	0.0f
#define D_DEFEATTHERMLIMITPERC_ULS_F32	0.0f
#define D_DEFEATTHERMLIMIT_MTRNM_F32	8.8f
#define D_TAU3_SEC_F32 					159.0f
#define D_TAU4_SEC_F32 					300.0f
#define D_TAU5_SEC_F32 					1590.0f
#define D_TAU6_SEC_F32 					4000.0f

#define THRMLDUTYCYCLE_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint16,  AP_DUTYCYCLE_VAR_NOINIT) ThrmLoadLmtTblYRam_MtrNm_M_u9p7[TableSize_m(t_ThrmLoadLmtTblY_MtrNm_u9p7)];
STATIC VAR(uint16,  AP_DUTYCYCLE_VAR_NOINIT) AbsTempFltAcc_Cnt_M_u16;
STATIC volatile VAR(uint16,  AP_DUTYCYCLE_VAR_NOINIT) MaxOut_AmpSq_D_u16p0;
STATIC volatile VAR(uint16,  AP_DUTYCYCLE_VAR_NOINIT) LastTblVal_MtrNm_D_u9p7;
STATIC volatile VAR(uint16,  AP_DUTYCYCLE_VAR_NOINIT) LastTblValSlew_MtrNm_D_u9p7;
STATIC volatile VAR(uint16,  AP_DUTYCYCLE_VAR_NOINIT) Mult1_Uls_D_u3p13;
STATIC volatile VAR(uint16,  AP_DUTYCYCLE_VAR_NOINIT) Mult2_Uls_D_u3p13;
STATIC volatile VAR(uint16,  AP_DUTYCYCLE_VAR_NOINIT) Mult3_Uls_D_u3p13;
STATIC volatile VAR(uint16,  AP_DUTYCYCLE_VAR_NOINIT) Mult4_Uls_D_u3p13;
STATIC volatile VAR(uint16,  AP_DUTYCYCLE_VAR_NOINIT) Mult5_Uls_D_u3p13;
STATIC volatile VAR(uint16,  AP_DUTYCYCLE_VAR_NOINIT) Mult6_Uls_D_u3p13;
#define THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */


#define THRMLDUTYCYCLE_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32, AP_DUTYCYCLE_VAR_NOINIT) AbsTempLimit_MtrNm_M_f32;
STATIC volatile VAR(float32, AP_DUTYCYCLE_VAR_NOINIT) Mult12Temp_DegC_D_f32;
STATIC volatile VAR(float32, AP_DUTYCYCLE_VAR_NOINIT) Mult36Temp_DegC_D_f32;
STATIC volatile VAR(float32, AP_DUTYCYCLE_VAR_NOINIT) ThermLim_MtrNm_D_f32;
STATIC volatile VAR(float32, AP_DUTYCYCLE_VAR_NOINIT) AbsTempLimit_MtrNm_D_f32;
STATIC volatile VAR(float32, AP_DUTYCYCLE_VAR_NOINIT) ThrmLoadLmtTblYVal_MtrNm_D_f32;
#define THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

	
#define THRMLDUTYCYCLE_START_SEC_VAR_SAVED_ZONEH_8
#include "MemMap.h" /* PRQA S 5087 */

STATIC VAR(uint8, AP_DUTYCYCLE_VAR_NOINIT) eFilter3ValueTyH_Cnt_M_u8;
STATIC VAR(uint8, AP_DUTYCYCLE_VAR_NOINIT) eFilter4ValueTyH_Cnt_M_u8;
STATIC VAR(uint8, AP_DUTYCYCLE_VAR_NOINIT) eFilter5ValueTyH_Cnt_M_u8;
STATIC VAR(uint8, AP_DUTYCYCLE_VAR_NOINIT) eFilter6ValueTyH_Cnt_M_u8;


#define THRMLDUTYCYCLE_STOP_SEC_VAR_SAVED_ZONEH_8
#include "MemMap.h" /* PRQA S 5087 */


#define THRMLDUTYCYCLE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(LPF32KSV_Str, AP_DUTYCYCLE_VAR_NOINIT) Filter1KSV_M_str;
STATIC VAR(LPF32KSV_Str, AP_DUTYCYCLE_VAR_NOINIT) Filter2KSV_M_str;
STATIC VAR(LPF32KSV_Str, AP_DUTYCYCLE_VAR_NOINIT) Filter3KSV_M_str;
STATIC VAR(LPF32KSV_Str, AP_DUTYCYCLE_VAR_NOINIT) Filter4KSV_M_str;
STATIC VAR(LPF32KSV_Str, AP_DUTYCYCLE_VAR_NOINIT) Filter5KSV_M_str;
STATIC VAR(LPF32KSV_Str, AP_DUTYCYCLE_VAR_NOINIT) Filter6KSV_M_str;
#define THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Boolean: Boolean (standard type)
 * Float: Real in interval ]-FLT_MAX...FLT_MAX[ with single precision (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * NTCNumber: Enumeration of integer in interval [0...511] with enumerators
 *   NTC_Num_FlashWrapperLgcFlt (1u)
 *   NTC_Num_FlashECCCorr (2u)
 *   NTC_Num_FlashECCMemFlt (3u)
 *   NTC_Num_FlashCRCMemFault (4u)
 *   NTC_Num_EEPROMDiag (10u)
 *   NTC_Num_EEPROMDiagMtrStr (11u)
 *   NTC_Num_PriSnsrTrqStorFlt (12u)
 *   NTC_Num_EEPROMDiagPosTrimStr (13u)
 *   NTC_Num_SecSnsrTrqStorFlt (14u)
 *   NTC_Num_EEPROMDiagPolarityStr (15u)
 *   NTC_Num_RAMDiag_GeneralFlt (16u)
 *   NTC_Num_RAMDiag_WrprLgcFlt (17u)
 *   NTC_Num_RAMDiag_ECCCorrIndFlt (18u)
 *   NTC_Num_RAMDiag_ECCMemFlt (19u)
 *   NTC_Num_RAMDiag_CRCMemFlt (20u)
 *   NTC_Num_RAMDiag_VIMRamFlt (23u)
 *   NTC_Num_RAMDiag_NHET1RamFlt (24u)
 *   NTC_Num_RAMDiag_NHET2RamFlt (25u)
 *   NTC_Num_RAMDiag_ADC1RamFlt (26u)
 *   NTC_Num_RAMDiag_DCANRamFault (27u)
 *   NTC_Num_RAMDiag_ADC2RamFlt (28u)
 *   NTC_Num_RAMDiag_HETTU1RamFlt (29u)
 *   NTC_Num_RAMDiag_HETTU2RamFlt (30u)
 *   NTC_Num_CPU_RegVer (32u)
 *   NTC_Num_CPU_CoreInitFlt (33u)
 *   NTC_Num_CPU_CoreRunTimeFlt (34u)
 *   NTC_Num_CPU_ClockMon (35u)
 *   NTC_Num_CPU_eFuseFlt (36u)
 *   NTC_Num_CPU_MPUViolation (37u)
 *   NTC_Num_CPU_FactPrcsErr (40u)
 *   NTC_Num_PropExeDiag_InitDiag (41u)
 *   NTC_Num_PrgFlwDeadlnFlt (42u)
 *   NTC_Num_PropExeDiag_RunTimeDiag (43u)
 *   NTC_Num_PropExeDiag_COPTimeout (44u)
 *   NTC_Num_PropExeDiag_PrefetchAbort (48u)
 *   NTC_Num_PropExeDiag_DataAbort (49u)
 *   NTC_Num_PerDiag_ADC1Flt (50u)
 *   NTC_Num_PerDiag_ADC2Flt (51u)
 *   NTC_Num_PerDiag_ADCCrossChkFlt (52u)
 *   NTC_Num_PerDiag_IllegalAccess (53u)
 *   NTC_Num_PerDiag_DMAFlt (54u)
 *   NTC_Num_PerDiag_CPUWarning (63u)
 *   NTC_Num_TmpMonFunc (64u)
 *   NTC_Num_TmpMonRunTimeFlt (65u)
 *   NTC_Num_PowerRelayInitFlt (66u)
 *   NTC_Num_PrechargeFailure (67u)
 *   NTC_Num_PowerRelayRunFlt (68u)
 *   NTC_Num_Thermistor (69u)
 *   NTC_Num_RefSupplyVltg (70u)
 *   NTC_Num_TrcvrInterfaceFlt (71u)
 *   NTC_Num_CPUSupplyOvervoltage (72u)
 *   NTC_Num_GateDrvFlt (77u)
 *   NTC_Num_OnStateSingleFET (78u)
 *   NTC_Num_OnStateMultiFET (79u)
 *   NTC_Num_PhaseVoltageVerf (80u)
 *   NTC_Num_PhaseDscnt (81u)
 *   NTC_Num_DigPhaseVoltageVerf (82u)
 *   NTC_Num_PhaseDscntFailedDisable (83u)
 *   NTC_Num_CurrentMeas1 (84u)
 *   NTC_Num_CurrentMeas2 (85u)
 *   NTC_Num_CurrentMeasCrossChk (86u)
 *   NTC_Num_PDSupplyOverVoltage (87u)
 *   NTC_Num_ChargePumpUnderVoltage (88u)
 *   NTC_Num_HwTrqSensor (96u)
 *   NTC_Num_AnaVsDigHwTrq (97u)
 *   NTC_Num_TrqSensorRecoveryFlt (98u)
 *   NTC_Num_TrqSensorScaleInvalid (100u)
 *   NTC_Num_T1vsT2 (101u)
 *   NTC_Num_T1OutofRange (102u)
 *   NTC_Num_T2OutofRange (103u)
 *   NTC_Num_DigT1vsT2 (104u)
 *   NTC_Num_DigT1OutofRange (105u)
 *   NTC_Num_DigT2OutofRange (106u)
 *   NTC_Num_RedT1vsT2 (107u)
 *   NTC_Num_HWASensorRel (110u)
 *   NTC_Num_HWASensorAbs (111u)
 *   NTC_Num_PriMSB_SinCosCorr (112u)
 *   NTC_Num_SecMSB_SinCosCorr (113u)
 *   NTC_Num_PriVsSec_SinCosCorr (114u)
 *   NTC_Num_DigMSBFlt (115u)
 *   NTC_Num_MtrVelFlt (116u)
 *   NTC_Num_HWAtoMtrAngleCorr (117u)
 *   NTC_Num_RedPriVsSec_SinCosCorr (118u)
 *   NTC_Num_TurnCntr_PosLoss (128u)
 *   NTC_Num_TurnCntr_MicroProcFlt (129u)
 *   NTC_Num_TurnCntr_SensorPosFlt (130u)
 *   NTC_Num_TurnCntr_SpiComFlt (131u)
 *   NTC_Num_TurnCntr_HighQuiescCur (132u)
 *   NTC_Num_TurnCntr_MainResets (133u)
 *   NTC_Num_KinematicIntDiag (144u)
 *   NTC_Num_HighFriction (145u)
 *   NTC_Num_DutyCycleExceeded (148u)
 *   NTC_Num_AbsTempThermLimit (149u)
 *   NTC_Num_LatchActive (160u)
 *   NTC_Num_OpTrqVsHwTrq (168u)
 *   NTC_Num_CurrentReas (169u)
 *   NTC_Num_OpVoltage (176u)
 *   NTC_Num_ExVoltageLow (177u)
 *   NTC_Num_ReducedAsstLowVoltage (178u)
 *   NTC_Num_ExVoltageHigh (180u)
 *   NTC_Num_OpVoltageOvrMax (181u)
 *   NTC_Num_IgnConfDiag (184u)
 *   NTC_Num_TurnCntr_LowBattery (185u)
 *   NTC_Num_EEPROMCloseFailed (191u)
 *   NTC_Num_SigPath1CrossChk (192u)
 *   NTC_Num_SigPath2CrossChk (193u)
 *   NTC_Num_SigPath3CrossChk (194u)
 *   NTC_Num_SigPath4CrossChk (195u)
 *   NTC_Num_SigPath5CrossChk (196u)
 *   NTC_Num_DampingFWReached (197u)
 *   NTC_Num_AssistFWReached (198u)
 *   NTC_Num_ReturnFWReached (199u)
 *   NTC_Num_DampingFWFltMode (200u)
 *   NTC_Num_AssistFWFltMode (201u)
 *   NTC_Num_VBICFltMode (202u)
 *   NTC_Num_StaMdsSysC (203u)
 *   NTC_NUM_SysFailureForRotVel (204u)
 *   NTC_NUM_SysFailForRedntRotVel (205u)
 *   NTC_Num_SysFailureForTrqSnsr (206u)
 *   NTC_Num_SysFailureForRedTrqSnsr (207u)
 *   NTC_NUM_SysFailureForCtrlVolt (209u)
 *   NTC_Num_GlblSgnlOvrwrtDet (223u)
 *   NTC_Num_VLF_00 (224u)
 *   NTC_Num_VLF_01 (225u)
 *   NTC_Num_VLF_02 (226u)
 *   NTC_Num_VLF_03 (227u)
 *   NTC_Num_VLF_04 (228u)
 *   NTC_Num_VLF_05 (229u)
 *   NTC_Num_VLF_06 (230u)
 *   NTC_Num_VLF_07 (231u)
 *   NTC_Num_VLF_08 (232u)
 *   NTC_Num_VLF_09 (233u)
 *   NTC_Num_VLF_10 (234u)
 *   NTC_Num_VLF_11 (235u)
 *   NTC_Num_VLF_12 (236u)
 *   NTC_Num_VLF_13 (237u)
 *   NTC_Num_VLF_14 (238u)
 *   NTC_Num_VLF_15 (239u)
 *   NTC_Num_VLF_16 (240u)
 *   NTC_Num_VLF_17 (241u)
 *   NTC_Num_VLF_18 (242u)
 *   NTC_Num_VLF_19 (243u)
 *   NTC_Num_VLF_20 (244u)
 *   NTC_Num_VLF_21 (245u)
 *   NTC_Num_VLF_22 (246u)
 *   NTC_Num_VLF_23 (247u)
 *   NTC_Num_VLF_24 (248u)
 *   NTC_Num_VLF_25 (249u)
 *   NTC_Num_VLF_26 (250u)
 *   NTC_Num_VLF_27 (251u)
 *   NTC_Num_VLF_28 (252u)
 *   NTC_Num_VLF_29 (253u)
 *   NTC_Num_VLF_30 (254u)
 *   NTC_Num_VLF_31 (255u)
 *   NTC_Num_BusOffCh1 (256u)
 *   NTC_Num_BusOffCh1NodeMute (257u)
 *   NTC_Num_Node1AAbsent (258u)
 *   NTC_Num_Node1AFaulty (259u)
 *   NTC_Num_Node1BAbsent (260u)
 *   NTC_Num_Node1BFaulty (261u)
 *   NTC_Num_Node1CAbsent (262u)
 *   NTC_Num_Node1CFaulty (263u)
 *   NTC_Num_Node1DAbsent (264u)
 *   NTC_Num_Node1DFaulty (265u)
 *   NTC_Num_Node1EAbsent (266u)
 *   NTC_Num_Node1EFaulty (267u)
 *   NTC_Num_Node1FAbsent (268u)
 *   NTC_Num_Node1FFaulty (269u)
 *   NTC_Num_Node1GAbsent (270u)
 *   NTC_Num_Node1GFaulty (271u)
 *   NTC_Num_BusOffCh2 (272u)
 *   NTC_Num_Node2AAbsent (273u)
 *   NTC_Num_Node2AFaulty (274u)
 *   NTC_Num_Node2BAbsent (275u)
 *   NTC_Num_Node2BFaulty (276u)
 *   NTC_Num_Node2CAbsent (277u)
 *   NTC_Num_Node2CFaulty (278u)
 *   NTC_Num_Node2DAbsent (279u)
 *   NTC_Num_Node2DFaulty (280u)
 *   NTC_Num_Node2EAbsent (281u)
 *   NTC_Num_Node2EFaulty (282u)
 *   NTC_Num_Node2FAbsent (283u)
 *   NTC_Num_Node2FFaulty (284u)
 *   NTC_Num_Node2GAbsent (285u)
 *   NTC_Num_Node2GFaulty (286u)
 *   NTC_Num_InvalidMsg_M (288u)
 *   NTC_Num_MissingMsg_M (289u)
 *   NTC_Num_CRCFltMsg_M (290u)
 *   NTC_Num_PgrsCntFltMsg_M (291u)
 *   NTC_Num_DataRngFltMsg_M (292u)
 *   NTC_Num_DataRateFltMsg_M (293u)
 *   NTC_Num_DataOtherFltMsg_M (294u)
 *   NTC_Num_InvalidMsg_N (296u)
 *   NTC_Num_MissingMsg_N (297u)
 *   NTC_Num_CRCFltMsg_N (298u)
 *   NTC_Num_PgrsCntFltMsg_N (299u)
 *   NTC_Num_DataRngFltMsg_N (300u)
 *   NTC_Num_DataRateFltMsg_N (301u)
 *   NTC_Num_DataOtherFltMsg_N (302u)
 *   NTC_Num_DataOtherFlt2Msg_N (303u)
 *   NTC_Num_InvalidMsg_O (304u)
 *   NTC_Num_MissingMsg_O (305u)
 *   NTC_Num_CRCFltMsg_O (306u)
 *   NTC_Num_PgrsCntFltMsg_O (307u)
 *   NTC_Num_DataRngFltMsg_O (308u)
 *   NTC_Num_DataRateFltMsg_O (309u)
 *   NTC_Num_DataOtherFltMsg_O (310u)
 *   NTC_Num_InvalidMsg_P (312u)
 *   NTC_Num_MissingMsg_P (313u)
 *   NTC_Num_CRCFltMsg_P (314u)
 *   NTC_Num_PgrsCntFltMsg_P (315u)
 *   NTC_Num_DataRngFltMsg_P (316u)
 *   NTC_Num_DataRateFltMsg_P (317u)
 *   NTC_Num_DataOtherFltMsg_P (318u)
 *   NTC_Num_InvalidMsg_Q (320u)
 *   NTC_Num_MissingMsg_Q (321u)
 *   NTC_Num_CRCFltMsg_Q (322u)
 *   NTC_Num_PgrsCntFltMsg_Q (323u)
 *   NTC_Num_DataRngFltMsg_Q (324u)
 *   NTC_Num_DataRateFltMsg_Q (325u)
 *   NTC_Num_DataOtherFltMsg_Q (326u)
 *   NTC_Num_InvalidMsg_R (328u)
 *   NTC_Num_MissingMsg_R (329u)
 *   NTC_Num_CRCFltMsg_R (330u)
 *   NTC_Num_PgrsCntFltMsg_R (331u)
 *   NTC_Num_DataRngFltMsg_R (332u)
 *   NTC_Num_DataRateFltMsg_R (333u)
 *   NTC_Num_DataOtherFltMsg_R (334u)
 *   NTC_Num_DataOtherFlt2Msg_R (335u)
 *   NTC_Num_InvalidMsg_S (336u)
 *   NTC_Num_MissingMsg_S (337u)
 *   NTC_Num_CRCFltMsg_S (338u)
 *   NTC_Num_PgrsCntFltMsg_S (339u)
 *   NTC_Num_DataRngFltMsg_S (340u)
 *   NTC_Num_DataRateFltMsg_S (341u)
 *   NTC_Num_DataOtherFltMsg_S (342u)
 *   NTC_Num_InvalidMsg_T (344u)
 *   NTC_Num_MissingMsg_T (345u)
 *   NTC_Num_CRCFltMsg_T (346u)
 *   NTC_Num_PgrsCntFltMsg_T (347u)
 *   NTC_Num_DataRngFltMsg_T (348u)
 *   NTC_Num_DataRateFltMsg_T (349u)
 *   NTC_Num_DataOtherFltMsg_T (350u)
 *   NTC_Num_InvalidMsg_U (352u)
 *   NTC_Num_MissingMsg_U (353u)
 *   NTC_Num_CRCFltMsg_U (354u)
 *   NTC_Num_PgrsCntFltMsg_U (355u)
 *   NTC_Num_DataRngFltMsg_U (356u)
 *   NTC_Num_DataRateFltMsg_U (357u)
 *   NTC_Num_DataOtherFltMsg_U (358u)
 *   NTC_Num_InvalidMsg_V (360u)
 *   NTC_Num_MissingMsg_V (361u)
 *   NTC_Num_CRCFltMsg_V (362u)
 *   NTC_Num_PgrsCntFltMsg_V (363u)
 *   NTC_Num_DataRngFltMsg_V (364u)
 *   NTC_Num_DataRateFltMsg_V (365u)
 *   NTC_Num_DataOtherFltMsg_V (366u)
 *   NTC_Num_InvalidMsg_W (368u)
 *   NTC_Num_MissingMsg_W (369u)
 *   NTC_Num_CRCFltMsg_W (370u)
 *   NTC_Num_PgrsCntFltMsg_W (371u)
 *   NTC_Num_DataRngFltMsg_W (372u)
 *   NTC_Num_DataRateFltMsg_W (373u)
 *   NTC_Num_DataOtherFltMsg_W (374u)
 *   NTC_Num_InvalidMsg_X (376u)
 *   NTC_Num_MissingMsg_X (377u)
 *   NTC_Num_CRCFltMsg_X (378u)
 *   NTC_Num_PgrsCntFltMsg_X (379u)
 *   NTC_Num_DataRngFltMsg_X (380u)
 *   NTC_Num_DataRateFltMsg_X (381u)
 *   NTC_Num_DataOtherFltMsg_X (382u)
 *   NTC_Num_InvalidMsg_Y (384u)
 *   NTC_Num_MissingMsg_Y (385u)
 *   NTC_Num_CRCFltMsg_Y (386u)
 *   NTC_Num_PgrsCntFltMsg_Y (387u)
 *   NTC_Num_DataRngFltMsg_Y (388u)
 *   NTC_Num_DataRateFltMsg_Y (389u)
 *   NTC_Num_DataOtherFltMsg_Y (390u)
 *   NTC_Num_InvalidMsg_Z (392u)
 *   NTC_Num_MissingMsg_Z (393u)
 *   NTC_Num_CRCFltMsg_Z (394u)
 *   NTC_Num_PgrsCntFltMsg_Z (395u)
 *   NTC_Num_DataRngFltMsg_Z (396u)
 *   NTC_Num_DataRateFltMsg_Z (397u)
 *   NTC_Num_DataOtherFltMsg_Z (398u)
 *   NTC_Num_DSTXORActive (399u)
 *   NTC_Num_InvalidMsg_AA (400u)
 *   NTC_Num_MissingMsg_AA (401u)
 *   NTC_Num_CRCFltMsg_AA (402u)
 *   NTC_Num_PgrsCntFltMsg_AA (403u)
 *   NTC_Num_DataRngFltMsg_AA (404u)
 *   NTC_Num_DataRateFltMsg_AA (405u)
 *   NTC_Num_DataOtherFltMsg_AA (406u)
 *   NTC_Num_InvalidMsg_AB (408u)
 *   NTC_Num_MissingMsg_AB (409u)
 *   NTC_Num_CRCFltMsg_AB (410u)
 *   NTC_Num_PgrsCntFltMsg_AB (411u)
 *   NTC_Num_DataRngFltMsg_AB (412u)
 *   NTC_Num_DataRateFltMsg_AB (413u)
 *   NTC_Num_DataOtherFltMsg_AB (414u)
 *   NTC_Num_InvalidMsg_AC (416u)
 *   NTC_Num_MissingMsg_AC (417u)
 *   NTC_Num_CRCFltMsg_AC (418u)
 *   NTC_Num_PgrsCntFltMsg_AC (419u)
 *   NTC_Num_DataRngFltMsg_AC (420u)
 *   NTC_Num_DataRateFltMsg_AC (421u)
 *   NTC_Num_DataOtherFltMsg_AC (422u)
 *   NTC_Num_InvalidMsg_AD (424u)
 *   NTC_Num_MissingMsg_AD (425u)
 *   NTC_Num_CRCFltMsg_AD (426u)
 *   NTC_Num_PgrsCntFltMsg_AD (427u)
 *   NTC_Num_DataRngFltMsg_AD (428u)
 *   NTC_Num_DataRateFltMsg_AD (429u)
 *   NTC_Num_DataOtherFltMsg_AD (430u)
 *   NTC_Num_InvalidMsg_AE (432u)
 *   NTC_Num_MissingMsg_AE (433u)
 *   NTC_Num_CRCFltMsg_AE (434u)
 *   NTC_Num_PgrsCntFltMsg_AE (435u)
 *   NTC_Num_DataRngFltMsg_AE (436u)
 *   NTC_Num_DataRateFltMsg_AE (437u)
 *   NTC_Num_DataOtherFltMsg_AE (438u)
 *   NTC_Num_InvalidMsg_AF (440u)
 *   NTC_Num_MissingMsg_AF (441u)
 *   NTC_Num_CRCFltMsg_AF (442u)
 *   NTC_Num_PgrsCntFltMsg_AF (443u)
 *   NTC_Num_DataRngFltMsg_AF (444u)
 *   NTC_Num_DataRateFltMsg_AF (445u)
 *   NTC_Num_DataOtherFltMsg_AF (446u)
 *   NTC_Num_InvalidMsg_AG (448u)
 *   NTC_Num_MissingMsg_AG (449u)
 *   NTC_Num_CRCFltMsg_AG (450u)
 *   NTC_Num_PgrsCntFltMsg_AG (451u)
 *   NTC_Num_DataRngFltMsg_AG (452u)
 *   NTC_Num_DataRateFltMsg_AG (453u)
 *   NTC_Num_DataOtherFltMsg_AG (454u)
 *   NTC_Num_InvalidMsg_AH (456u)
 *   NTC_Num_MissingMsg_AH (457u)
 *   NTC_Num_CRCFltMsg_AH (458u)
 *   NTC_Num_PgrsCntFltMsg_AH (459u)
 *   NTC_Num_DataRngFltMsg_AH (460u)
 *   NTC_Num_DataRateFltMsg_AH (461u)
 *   NTC_Num_DataOtherFltMsg_AH (462u)
 *   NTC_Num_FlexrayCommunicationError (465u)
 *   NTC_Num_SysConsistencyVerf (496u)
 *   NTC_Num_ConfigMisMatch (497u)
 *   NTC_Num_CalNotPrgmd (498u)
 *   NTC_Num_EOLVehTunNtPerf (501u)
 *   NTC_Num_MtrSensorNotTrimmed (502u)
 *   NTC_Num_HWASensorNotTrimmed (504u)
 *   NTC_Num_HWASensorTrimNoAttempt (505u)
 *   NTC_Num_TrqSensorScaleNotSet (506u)
 *   NTC_Num_TrqSensorNotTrimmed (507u)
 *   NTC_Num_DigTrqSensorScaleNotSet (509u)
 *   NTC_Num_DigTrqSensorNotTrimmed (510u)
 * NxtrDiagMgrStatus: Enumeration of integer in interval [0...255] with enumerators
 *   NTC_STATUS_PASSED (0u)
 *   NTC_STATUS_FAILED (1u)
 *   NTC_STATUS_PREPASSED (2u)
 *   NTC_STATUS_PREFAILED (3u)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Defined Constants
 *
 **********************************************************************************************************************
 *
 * Primitive Type Constants:
 * =========================
 * Boolean: D_FALSE_CNT_LGC = FALSE
 * Float: D_100MS_SEC_F32 = 0.1
 * Float: D_MTRTRQCMDHILMT_MTRNM_F32 = 8.8
 * Float: D_ONE_ULS_F32 = 1
 * Float: D_ZERO_ULS_F32 = 0
 * UInt16: D_ONE_CNT_U16 = 1u
 * UInt32: D_ONE_CNT_U32 = 1u
 * UInt32: D_ZERO_CNT_U32 = 0u
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_THRMLDUTYCYCLE_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ThrmlDutyCycle_Init1
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
 *   UInt32 Rte_IRead_ThrmlDutyCycle_Init1_IgnTimeOff_Cnt_u32(void)
 *   Boolean Rte_IRead_ThrmlDutyCycle_Init1_VehTimeValid_Cnt_lgc(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_THRMLDUTYCYCLE_APPL_CODE) ThrmlDutyCycle_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ThrmlDutyCycle_Init1
 *********************************************************************************************************************/
	
	
	VAR(uint16, AUTOMATIC) i;
		
	VAR(boolean, AUTOMATIC) VehTimeValid_Cnt_T_lgc;
	VAR(uint32, AUTOMATIC) IgnTimeOff_Sec_T_u32;
	VAR(float32, AUTOMATIC) ExpFiltDecayIn_Sec_T_f32;
		
	IgnTimeOff_Sec_T_u32 = Rte_IRead_ThrmlDutyCycle_Init1_IgnTimeOff_Cnt_u32();
	VehTimeValid_Cnt_T_lgc = Rte_IRead_ThrmlDutyCycle_Init1_VehTimeValid_Cnt_lgc();
	
	AbsTempLimit_MtrNm_M_f32 = FPM_FixedToFloat_m(t_AbsTmpTblY_MtrNm_u9p7[0], u9p7_T);
	
	for(i = 0u; i < TableSize_m(t_ThrmLoadLmtTblY_MtrNm_u9p7); i++)
	{
	   ThrmLoadLmtTblYRam_MtrNm_M_u9p7[i] = t_ThrmLoadLmtTblY_MtrNm_u9p7[i];
	}
	
	LPF_KUpdate_f32_m(D_FILT1LPFKN_HZ_F32, D_100MS_SEC_F32, &Filter1KSV_M_str);
	LPF_KUpdate_f32_m(D_FILT2LPFKN_HZ_F32, D_100MS_SEC_F32, &Filter2KSV_M_str);
	LPF_KUpdate_f32_m(D_FILT3LPFKN_HZ_F32, D_100MS_SEC_F32, &Filter3KSV_M_str);
	LPF_KUpdate_f32_m(D_FILT4LPFKN_HZ_F32, D_100MS_SEC_F32, &Filter4KSV_M_str);
	LPF_KUpdate_f32_m(D_FILT5LPFKN_HZ_F32, D_100MS_SEC_F32, &Filter5KSV_M_str);
	LPF_KUpdate_f32_m(D_FILT6LPFKN_HZ_F32, D_100MS_SEC_F32, &Filter6KSV_M_str);
	
	/* Power ON Tasks */
	if (VehTimeValid_Cnt_T_lgc == TRUE) 
	{
		ExpFiltDecayIn_Sec_T_f32 = (float32)IgnTimeOff_Sec_T_u32; 
	}
	else
	{ 
		ExpFiltDecayIn_Sec_T_f32 = k_DefaultIgnOffTime_Sec_f32;
	}
	Filter3KSV_M_str.SV_Uls_f32 = (expf((((-D_ONE_ULS_F32) * ExpFiltDecayIn_Sec_T_f32) / D_TAU3_SEC_F32)) * (float32)eFilter3ValueTyH_Cnt_M_u8);
	Filter4KSV_M_str.SV_Uls_f32 = (expf((((-D_ONE_ULS_F32) * ExpFiltDecayIn_Sec_T_f32) / D_TAU4_SEC_F32)) * (float32)eFilter4ValueTyH_Cnt_M_u8);
	Filter5KSV_M_str.SV_Uls_f32 = (expf((((-D_ONE_ULS_F32) * ExpFiltDecayIn_Sec_T_f32) / D_TAU5_SEC_F32)) * (float32)eFilter5ValueTyH_Cnt_M_u8);
	Filter6KSV_M_str.SV_Uls_f32 = (expf((((-D_ONE_ULS_F32) * ExpFiltDecayIn_Sec_T_f32) / D_TAU6_SEC_F32)) * (float32)eFilter6ValueTyH_Cnt_M_u8);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ThrmlDutyCycle_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_ThrmlDutyCycle_Per1_CuTempEst_DegC_f32(void)
 *   Boolean Rte_IRead_ThrmlDutyCycle_Per1_DefeatDutySvc_Cnt_lgc(void)
 *   Float Rte_IRead_ThrmlDutyCycle_Per1_FiltMeasTemp_DegC_f32(void)
 *   Float Rte_IRead_ThrmlDutyCycle_Per1_FilteredPkCurr_AmpSq_f32(void)
 *   Float Rte_IRead_ThrmlDutyCycle_Per1_MagTempEst_DegC_f32(void)
 *   Float Rte_IRead_ThrmlDutyCycle_Per1_MotorVelCRF_MtrRadpS_f32(void)
 *   Float Rte_IRead_ThrmlDutyCycle_Per1_MtrPkCurr_AmpSq_f32(void)
 *   Float Rte_IRead_ThrmlDutyCycle_Per1_SiTempEst_DegC_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_ThrmlDutyCycle_Per1_DutyCycleLevel_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_ThrmlDutyCycle_Per1_DutyCycleLevel_Uls_f32(void)
 *   void Rte_IWrite_ThrmlDutyCycle_Per1_ThermLimitPerc_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_ThrmlDutyCycle_Per1_ThermLimitPerc_Uls_f32(void)
 *   void Rte_IWrite_ThrmlDutyCycle_Per1_ThermalLimit_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_ThrmlDutyCycle_Per1_ThermalLimit_MtrNm_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_THRMLDUTYCYCLE_APPL_CODE) ThrmlDutyCycle_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ThrmlDutyCycle_Per1
 *********************************************************************************************************************/
	
	
	VAR(float32, AUTOMATIC) CuTempEst_DegC_T_f32;
	VAR(float32, AUTOMATIC) FiltMeasTemp_DegC_T_f32;
	VAR(float32, AUTOMATIC) FiltPkCurr_AmpSq_T_f32;
	VAR(float32, AUTOMATIC) MagTempEst_DegC_T_f32;
	VAR(float32, AUTOMATIC) MotorVelCRF_MtrRadpS_T_f32;
	VAR(float32, AUTOMATIC) MtrPkCurr_AmpSq_T_f32;
	VAR(float32, AUTOMATIC) SiTempEst_DegC_T_f32;
	VAR(boolean, AUTOMATIC) DiagStsDefTemp_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) PrevAbsTempLimit_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) AbsMotorVelCRF_MtrRadpS_T_f32;
	VAR(float32, AUTOMATIC) Mult12Temp_DegC_T_f32;
	VAR(float32, AUTOMATIC) Mult36Temp_DegC_T_f32;
	VAR(sint16,  AUTOMATIC) SlcTemp_DegC_T_s15p0;
	VAR(sint16,  AUTOMATIC) Mult12Temp_DegC_T_s15p0;
	VAR(sint16,  AUTOMATIC) Mult36Temp_DegC_T_s15p0;
	VAR(sint16,  AUTOMATIC) Mult36TempSlc_DegC_T_s15p0;
	VAR(uint16,  AUTOMATIC) Mult1_Uls_T_u3p13;
	VAR(uint16,  AUTOMATIC) Mult2_Uls_T_u3p13;
	VAR(uint16,  AUTOMATIC) Mult3_Uls_T_u3p13;
	VAR(uint16,  AUTOMATIC) Mult4_Uls_T_u3p13;
	VAR(uint16,  AUTOMATIC) Mult5_Uls_T_u3p13;
	VAR(uint16,  AUTOMATIC) Mult6_Uls_T_u3p13;
	VAR(float32, AUTOMATIC) FilterInput_Uls_T_f32;
	VAR(float32, AUTOMATIC) MaxSlowFilt_Uls_T_f32;
	VAR(float32, AUTOMATIC) MaxOut_Uls_T_f32;
	VAR(uint16,  AUTOMATIC) MaxOut_Uls_T_u16p0;
	VAR(uint16,  AUTOMATIC) LastTblValRaw_MtrNm_T_u9p7;
	VAR(uint16,  AUTOMATIC) LastTblVal_MtrNm_T_u9p7;
	VAR(uint16,  AUTOMATIC) ThermalLoadLmt_MtrNm_T_u9p7;
	VAR(float32, AUTOMATIC) ThermalLoadLmt_MtrNm_T_f32;
	VAR(uint16,  AUTOMATIC) AbsTempLimit_MtrNm_T_u9p7;
	VAR(float32, AUTOMATIC) AbsTempLimit_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) AbsTempLimitSlew_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) ThermalLimit_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) DivFactor_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) ThermLimitPerc_Uls_T_f32;
	VAR(boolean, AUTOMATIC) DefeatDutySvc_Cnt_T_lgc;

	
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_ThrmlDutyCycle_Per1_CP0_CheckpointReached();

	CuTempEst_DegC_T_f32 = Rte_IRead_ThrmlDutyCycle_Per1_CuTempEst_DegC_f32();
	FiltMeasTemp_DegC_T_f32 = Rte_IRead_ThrmlDutyCycle_Per1_FiltMeasTemp_DegC_f32();
	FiltPkCurr_AmpSq_T_f32 = Rte_IRead_ThrmlDutyCycle_Per1_FilteredPkCurr_AmpSq_f32();
	MagTempEst_DegC_T_f32 = Rte_IRead_ThrmlDutyCycle_Per1_MagTempEst_DegC_f32();
	MotorVelCRF_MtrRadpS_T_f32 = Rte_IRead_ThrmlDutyCycle_Per1_MotorVelCRF_MtrRadpS_f32();
	MtrPkCurr_AmpSq_T_f32 = Rte_IRead_ThrmlDutyCycle_Per1_MtrPkCurr_AmpSq_f32();
	SiTempEst_DegC_T_f32 = Rte_IRead_ThrmlDutyCycle_Per1_SiTempEst_DegC_f32();
	DefeatDutySvc_Cnt_T_lgc = Rte_IRead_ThrmlDutyCycle_Per1_DefeatDutySvc_Cnt_lgc();
	
	PrevAbsTempLimit_MtrNm_T_f32 = AbsTempLimit_MtrNm_M_f32;
	
	AbsMotorVelCRF_MtrRadpS_T_f32 = Abs_f32_m(MotorVelCRF_MtrRadpS_T_f32);
	
	(void) Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_Thermistor, &DiagStsDefTemp_Cnt_T_lgc);
	
	/* Temperature Selection */
	
	if( TRUE == DiagStsDefTemp_Cnt_T_lgc )
	{
		Mult12Temp_DegC_T_f32 = k_EOCCtrlTemp_DegC_f32;
		Mult36Temp_DegC_T_f32 = k_EOCCtrlTemp_DegC_f32;
	}
	else
	{
		if( TRUE == k_CtrlTempSlc_Cnt_lgc )
		{
			Mult12Temp_DegC_T_f32 = FiltMeasTemp_DegC_T_f32;
		}
		else
		{
			Mult12Temp_DegC_T_f32 = SiTempEst_DegC_T_f32;
		}
		
		if( TRUE == k_MtrPrTempSlc_Cnt_lgc )
		{
			Mult36Temp_DegC_T_f32 = MagTempEst_DegC_T_f32;
		}
		else
		{
			Mult36Temp_DegC_T_f32 = CuTempEst_DegC_T_f32;
		}
	}
	
	Mult12Temp_DegC_T_s15p0 = (sint16)Mult12Temp_DegC_T_f32;
	Mult36Temp_DegC_T_s15p0 = (sint16)Mult36Temp_DegC_T_f32;
	
	if( TRUE == k_MultTempSlc_Cnt_lgc )
	{
		SlcTemp_DegC_T_s15p0 = Mult12Temp_DegC_T_s15p0;
	}
	else
	{
		SlcTemp_DegC_T_s15p0 = Mult36Temp_DegC_T_s15p0;
	}
	
	
	
	/* Load Limiting - Multiplier */
	
	if( TRUE == k_SlowFltTempSlc_Cnt_lgc )
	{
		Mult36TempSlc_DegC_T_s15p0 = Mult12Temp_DegC_T_s15p0;
	}
	else
	{
		Mult36TempSlc_DegC_T_s15p0 = Mult36Temp_DegC_T_s15p0;
	}
	
	if( AbsMotorVelCRF_MtrRadpS_T_f32 > k_AbsMtrVelBkt_MtrRadps_f32 )
	{
		Mult1_Uls_T_u3p13 = StepVarXY_u16_s16Xu16Y_Cnt(t_MultTblX_DegC_s15p0, t_Mult1NSTblY_Uls_u3p13, (uint16)TableSize_m(t_MultTblX_DegC_s15p0), Mult12Temp_DegC_T_s15p0);
		Mult2_Uls_T_u3p13 = StepVarXY_u16_s16Xu16Y_Cnt(t_MultTblX_DegC_s15p0, t_Mult2NSTblY_Uls_u3p13, (uint16)TableSize_m(t_MultTblX_DegC_s15p0), Mult12Temp_DegC_T_s15p0);
		Mult3_Uls_T_u3p13 = StepVarXY_u16_s16Xu16Y_Cnt(t_MultTblX_DegC_s15p0, t_Mult3NSTblY_Uls_u3p13, (uint16)TableSize_m(t_MultTblX_DegC_s15p0), Mult36TempSlc_DegC_T_s15p0);
		Mult4_Uls_T_u3p13 = StepVarXY_u16_s16Xu16Y_Cnt(t_MultTblX_DegC_s15p0, t_Mult4NSTblY_Uls_u3p13, (uint16)TableSize_m(t_MultTblX_DegC_s15p0), Mult36TempSlc_DegC_T_s15p0);
		Mult5_Uls_T_u3p13 = StepVarXY_u16_s16Xu16Y_Cnt(t_MultTblX_DegC_s15p0, t_Mult5NSTblY_Uls_u3p13, (uint16)TableSize_m(t_MultTblX_DegC_s15p0), Mult36TempSlc_DegC_T_s15p0);
		Mult6_Uls_T_u3p13 = StepVarXY_u16_s16Xu16Y_Cnt(t_MultTblX_DegC_s15p0, t_Mult6NSTblY_Uls_u3p13, (uint16)TableSize_m(t_MultTblX_DegC_s15p0), Mult36TempSlc_DegC_T_s15p0);
	}
	else
	{
		Mult1_Uls_T_u3p13 = StepVarXY_u16_s16Xu16Y_Cnt(t_MultTblX_DegC_s15p0, t_Mult1STblY_Uls_u3p13, (uint16)TableSize_m(t_MultTblX_DegC_s15p0), Mult12Temp_DegC_T_s15p0);
		Mult2_Uls_T_u3p13 = StepVarXY_u16_s16Xu16Y_Cnt(t_MultTblX_DegC_s15p0, t_Mult2STblY_Uls_u3p13, (uint16)TableSize_m(t_MultTblX_DegC_s15p0), Mult12Temp_DegC_T_s15p0);
		Mult3_Uls_T_u3p13 = StepVarXY_u16_s16Xu16Y_Cnt(t_MultTblX_DegC_s15p0, t_Mult3STblY_Uls_u3p13, (uint16)TableSize_m(t_MultTblX_DegC_s15p0), Mult36TempSlc_DegC_T_s15p0);
		Mult4_Uls_T_u3p13 = StepVarXY_u16_s16Xu16Y_Cnt(t_MultTblX_DegC_s15p0, t_Mult4STblY_Uls_u3p13, (uint16)TableSize_m(t_MultTblX_DegC_s15p0), Mult36TempSlc_DegC_T_s15p0);
		Mult5_Uls_T_u3p13 = StepVarXY_u16_s16Xu16Y_Cnt(t_MultTblX_DegC_s15p0, t_Mult5STblY_Uls_u3p13, (uint16)TableSize_m(t_MultTblX_DegC_s15p0), Mult36TempSlc_DegC_T_s15p0);
		Mult6_Uls_T_u3p13 = StepVarXY_u16_s16Xu16Y_Cnt(t_MultTblX_DegC_s15p0, t_Mult6STblY_Uls_u3p13, (uint16)TableSize_m(t_MultTblX_DegC_s15p0), Mult36TempSlc_DegC_T_s15p0);
	}
	
	
	
	/* Load Limiting - FilterPerc_Max */
	
	FilterInput_Uls_T_f32 = FPM_FixedToFloat_m(Mult1_Uls_T_u3p13, u3p13_T) * MtrPkCurr_AmpSq_T_f32;
	LPF_OpUpdate_f32_m(FilterInput_Uls_T_f32, &Filter1KSV_M_str);
	
	FilterInput_Uls_T_f32 = FPM_FixedToFloat_m(Mult2_Uls_T_u3p13, u3p13_T) * MtrPkCurr_AmpSq_T_f32;
	LPF_OpUpdate_f32_m(FilterInput_Uls_T_f32, &Filter2KSV_M_str);
	
	FilterInput_Uls_T_f32 = FPM_FixedToFloat_m(Mult3_Uls_T_u3p13, u3p13_T) * MtrPkCurr_AmpSq_T_f32;
	LPF_OpUpdate_f32_m(FilterInput_Uls_T_f32, &Filter3KSV_M_str);
	
	FilterInput_Uls_T_f32 = FPM_FixedToFloat_m(Mult4_Uls_T_u3p13, u3p13_T) * FiltPkCurr_AmpSq_T_f32;
	LPF_OpUpdate_f32_m(FilterInput_Uls_T_f32, &Filter4KSV_M_str);
	
	FilterInput_Uls_T_f32 = FPM_FixedToFloat_m(Mult5_Uls_T_u3p13, u3p13_T) * FiltPkCurr_AmpSq_T_f32;
	LPF_OpUpdate_f32_m(FilterInput_Uls_T_f32, &Filter5KSV_M_str);
	
	FilterInput_Uls_T_f32 = FPM_FixedToFloat_m(Mult6_Uls_T_u3p13, u3p13_T) * FiltPkCurr_AmpSq_T_f32;
	LPF_OpUpdate_f32_m(FilterInput_Uls_T_f32, &Filter6KSV_M_str);
	
	MaxSlowFilt_Uls_T_f32 = Max_m(Filter3KSV_M_str.SV_Uls_f32, Filter4KSV_M_str.SV_Uls_f32);
	MaxSlowFilt_Uls_T_f32 = Max_m(MaxSlowFilt_Uls_T_f32, Filter5KSV_M_str.SV_Uls_f32);
	MaxSlowFilt_Uls_T_f32 = Max_m(MaxSlowFilt_Uls_T_f32, Filter6KSV_M_str.SV_Uls_f32);
	MaxOut_Uls_T_f32 = Max_m(MaxSlowFilt_Uls_T_f32, Filter1KSV_M_str.SV_Uls_f32);
	MaxOut_Uls_T_f32 = Max_m(MaxOut_Uls_T_f32, Filter2KSV_M_str.SV_Uls_f32);
	
	eFilter3ValueTyH_Cnt_M_u8 = (uint8)(Filter3KSV_M_str.SV_Uls_f32);	/* Store the filter outputs in EEPROM upon power off */
	eFilter4ValueTyH_Cnt_M_u8 = (uint8)(Filter4KSV_M_str.SV_Uls_f32);
	eFilter5ValueTyH_Cnt_M_u8 = (uint8)(Filter5KSV_M_str.SV_Uls_f32);
	eFilter6ValueTyH_Cnt_M_u8 = (uint8)(Filter6KSV_M_str.SV_Uls_f32);

	MaxSlowFilt_Uls_T_f32 = Limit_m(MaxSlowFilt_Uls_T_f32, D_ZERO_ULS_F32, D_FILTOUTLIM_ULS_F32);
	MaxOut_Uls_T_f32 = Limit_m(MaxOut_Uls_T_f32, D_ZERO_ULS_F32, D_FILTOUTLIM_ULS_F32);
	
	MaxOut_Uls_T_u16p0 = FPM_FloatToFixed_m(MaxOut_Uls_T_f32, u16p0_T);
	
	/* Load Limiting - Thermal_LoadLimit */
	
	if( AbsMotorVelCRF_MtrRadpS_T_f32 > k_AbsMtrVelBkt_MtrRadps_f32 )
	{
		LastTblValRaw_MtrNm_T_u9p7 = StepVarXY_u16_s16Xu16Y_Cnt(t_MultTblX_DegC_s15p0, t_LastTblValNS_MtrNm_u9p7, (uint16)TableSize_m(t_MultTblX_DegC_s15p0), SlcTemp_DegC_T_s15p0);
	}
	else
	{
		LastTblValRaw_MtrNm_T_u9p7 = StepVarXY_u16_s16Xu16Y_Cnt(t_MultTblX_DegC_s15p0, t_LastTblValS_MtrNm_u9p7, (uint16)TableSize_m(t_MultTblX_DegC_s15p0), SlcTemp_DegC_T_s15p0);
	}
	
	
	LastTblVal_MtrNm_T_u9p7 = (uint16)Limit_m(((sint32)LastTblValRaw_MtrNm_T_u9p7), 
											  ((sint32)ThrmLoadLmtTblYRam_MtrNm_M_u9p7[TableSize_m(t_ThrmLoadLmtTblY_MtrNm_u9p7) - 1U]) - ((sint32)k_TrqCmdSlewDown_MtrNm_u9p7),
											  ((sint32)ThrmLoadLmtTblYRam_MtrNm_M_u9p7[TableSize_m(t_ThrmLoadLmtTblY_MtrNm_u9p7) - 1U]) + ((sint32)k_TrqCmdSlewUp_MtrNm_u9p7));
	
	ThrmLoadLmtTblYRam_MtrNm_M_u9p7[TableSize_m(t_ThrmLoadLmtTblY_MtrNm_u9p7) -1U] = LastTblVal_MtrNm_T_u9p7;
	
	ThermalLoadLmt_MtrNm_T_u9p7 = IntplVarXY_u16_u16Xu16Y_Cnt(	t_ThrmLoadLmtTblX_Uls_u16p0,
                      											ThrmLoadLmtTblYRam_MtrNm_M_u9p7, 
                      											TableSize_m(t_ThrmLoadLmtTblX_Uls_u16p0),
                      											MaxOut_Uls_T_u16p0);
	
	ThermalLoadLmt_MtrNm_T_f32 = FPM_FixedToFloat_m(ThermalLoadLmt_MtrNm_T_u9p7, u9p7_T);
	
	
	
	/* Temperature Limiting */
	
	if( SlcTemp_DegC_T_s15p0 >= t_AbsTmpTblX_DegC_s15p0[0] )
	{
		AbsTempFltAcc_Cnt_M_u16 = DiagPStep_m(AbsTempFltAcc_Cnt_M_u16, k_AbsTempDiag_Cnt_str);
	}
	else
	{
		AbsTempFltAcc_Cnt_M_u16 = DiagNStep_m(AbsTempFltAcc_Cnt_M_u16, k_AbsTempDiag_Cnt_str);
	}
	
	if( DiagFailed_m(AbsTempFltAcc_Cnt_M_u16, k_AbsTempDiag_Cnt_str) == TRUE )
	{
		(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_AbsTempThermLimit, 0x02u, NTC_STATUS_FAILED);
	}
	else
	{
		if( AbsTempFltAcc_Cnt_M_u16 == 0u )
		{
			(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_AbsTempThermLimit, 0x02u, NTC_STATUS_PASSED);
		}
	}
	
	AbsTempLimit_MtrNm_T_u9p7 = IntplVarXY_u16_s16Xu16Y_Cnt(t_AbsTmpTblX_DegC_s15p0,
															t_AbsTmpTblY_MtrNm_u9p7,
															TableSize_m(t_AbsTmpTblX_DegC_s15p0),
															SlcTemp_DegC_T_s15p0);
	
	AbsTempLimit_MtrNm_T_f32 = FPM_FixedToFloat_m(AbsTempLimit_MtrNm_T_u9p7, u9p7_T);
	
	AbsTempLimitSlew_MtrNm_T_f32 = Limit_m(	AbsTempLimit_MtrNm_T_f32,
											PrevAbsTempLimit_MtrNm_T_f32 - k_AbsTmpTrqSlewLmt_MtrNm_f32,
											PrevAbsTempLimit_MtrNm_T_f32 + k_AbsTmpTrqSlewLmt_MtrNm_f32);
	
	

	/*** Defeat thermal load limit ***/
	if( TRUE == DefeatDutySvc_Cnt_T_lgc )
	{
		ThermalLimit_MtrNm_T_f32 = Min_m(D_DEFEATTHERMLIMIT_MTRNM_F32, AbsTempLimitSlew_MtrNm_T_f32);
		
	}
	else
	{
		ThermalLimit_MtrNm_T_f32 = Min_m(ThermalLoadLmt_MtrNm_T_f32, AbsTempLimitSlew_MtrNm_T_f32);
	}	
	
	/* Thermal Limiting Status */
	
	if( TRUE == DefeatDutySvc_Cnt_T_lgc )
	{
		/*Don't set NTC on defeat.*/
	}
	else if( MaxOut_Uls_T_u16p0 >= k_DutyCycFltTrshld_Uls_u16p0 )
	{
		(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DutyCycleExceeded, 0x01u, NTC_STATUS_FAILED);
	}
	else
	{
		(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DutyCycleExceeded, 0x01u, NTC_STATUS_PASSED);
	}
	
	DivFactor_MtrNm_T_f32 = Max_m(FPM_FixedToFloat_m(t_ThrmLoadLmtTblY_MtrNm_u9p7[0], u9p7_T), D_1PERC_ULS_F32);
	
	ThermLimitPerc_Uls_T_f32 = D_ONE_ULS_F32 - Min_m((ThermalLimit_MtrNm_T_f32 / DivFactor_MtrNm_T_f32), D_ONE_ULS_F32);
	
	
	
	ThermalLimit_MtrNm_T_f32 = Limit_m(ThermalLimit_MtrNm_T_f32, D_ZERO_ULS_F32, D_MTRTRQCMDHILMT_MTRNM_F32);
	
	/*** Defeat the Them_Limit_Flag and DutyCycleLevel ***/
	if( TRUE == DefeatDutySvc_Cnt_T_lgc )
	{
		MaxSlowFilt_Uls_T_f32 = D_DEFEATDUTYCYCLELEVEL_ULS_F32;
		ThermLimitPerc_Uls_T_f32 = D_DEFEATTHERMLIMITPERC_ULS_F32;
		
	}
	
	AbsTempLimit_MtrNm_M_f32 = AbsTempLimitSlew_MtrNm_T_f32;
	
	Mult12Temp_DegC_D_f32 = Mult12Temp_DegC_T_f32;
	Mult36Temp_DegC_D_f32 = Mult36Temp_DegC_T_f32;
	MaxOut_AmpSq_D_u16p0 = MaxOut_Uls_T_u16p0;
	ThermLim_MtrNm_D_f32 = ThermalLoadLmt_MtrNm_T_f32;
	Mult1_Uls_D_u3p13 = Mult1_Uls_T_u3p13;
	Mult2_Uls_D_u3p13 = Mult2_Uls_T_u3p13;
	Mult3_Uls_D_u3p13 = Mult3_Uls_T_u3p13;
	Mult4_Uls_D_u3p13 = Mult4_Uls_T_u3p13;
	Mult5_Uls_D_u3p13 = Mult5_Uls_T_u3p13;
	Mult6_Uls_D_u3p13 = Mult6_Uls_T_u3p13;
	LastTblVal_MtrNm_D_u9p7 = LastTblValRaw_MtrNm_T_u9p7;
	LastTblValSlew_MtrNm_D_u9p7 = LastTblVal_MtrNm_T_u9p7;
	AbsTempLimit_MtrNm_D_f32 = AbsTempLimit_MtrNm_T_f32;
	ThrmLoadLmtTblYVal_MtrNm_D_f32 = DivFactor_MtrNm_T_f32;
	
	Rte_IWrite_ThrmlDutyCycle_Per1_DutyCycleLevel_Uls_f32(MaxSlowFilt_Uls_T_f32);
	Rte_IWrite_ThrmlDutyCycle_Per1_ThermLimitPerc_Uls_f32(ThermLimitPerc_Uls_T_f32);
	Rte_IWrite_ThrmlDutyCycle_Per1_ThermalLimit_MtrNm_f32(ThermalLimit_MtrNm_T_f32);
	/* Configurable End of Runnable Checkpoint */
    Rte_Call_ThrmlDutyCycle_Per1_CP1_CheckpointReached();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_THRMLDUTYCYCLE_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/*******************************************************************************
  * Name		:	StepVarXY_u16_s16Xu16Y_Cnt (TableX, TableY,
  *					 Size, input) 
  * Description	:	Signed 16 bit Variable X Unsigned 16 bit Variable Y 
  * 				2D Table Lookup function (without interpolation).
  *					TableX is the independent axis and the TableY is
  *					the dependent axis. If input is between two X values,
  *					the minimum X value is chosen. If input is out of 
  *					the range of TableX, the boundary value is used.
  * Inputs		:	Name of TableX, Name of TableY, Table size, X input
  * Outputs		:	Y output
  *****************************************************************************/
STATIC FUNC(uint16, AP_DUTYCYCLE_CODE) StepVarXY_u16_s16Xu16Y_Cnt (const sint16 *TableX, const uint16 *TableY, 
					const uint16 Size, const sint16 input)
{
	VAR(uint32, AUTOMATIC)	index_Cnt_T_u32;

	index_Cnt_T_u32 = D_ZERO_CNT_U32;

	/* Check for Range */
	if ( input <= TableX[0] )
	{
		index_Cnt_T_u32 = D_ZERO_CNT_U32;
	}
	else if ( input >= TableX[Size - D_ONE_CNT_U16] )
	{
		index_Cnt_T_u32 = (uint32)Size - D_ONE_CNT_U16;
	}
	else/* In range. Get Index */
	{
		while ( TableX[index_Cnt_T_u32 + D_ONE_CNT_U32] <= input )
		{
			index_Cnt_T_u32++;
		}
	}

	return TableY[index_Cnt_T_u32];
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
