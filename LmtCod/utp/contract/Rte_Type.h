


/*
   !! B E T A   V E R S I O N !!

  These programs are fully operative programs.
  However, they are not thoroughly tested yet (beta-version).
  With regard to the fact that the programs are a beta-version only,
  Vector Informatik's liability shall be expressly excluded in cases of ordinary negligence,
  to the extent admissible by law or statute.
*/



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
 *          File:  Rte_Type.h
 *     Workspace:  C:/cmsynergy/CBD_LmtCod_SF38/LmtCod-wz7x3j/LmtCod/autosar/Ap_LmtCod.dcf
 *     SW-C Type:  Ap_LmtCod
 *  Generated at:  Fri May 17 08:56:54 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1 (Beta)
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Header file containing user defined AUTOSAR types and RTE structures (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_TYPE_H
# define _RTE_TYPE_H

# include "Rte.h"


/**********************************************************************************************************************
 * Data type definitions
 *********************************************************************************************************************/

# define Rte_TypeDef_Float
typedef float32 Float;
# define Float_LowerLimit (-FLT_MAX)
# define Float_UpperLimit (FLT_MAX)

# define Rte_TypeDef_FltInjectionLocType
typedef uint8 FltInjectionLocType;
# define FltInjectionLocType_LowerLimit (0U)
# define FltInjectionLocType_UpperLimit (255U)
# if (defined RTE_CONST_FLTINJ_ASSIST) || (defined FLTINJ_ASSIST)
#  if (!defined RTE_CONST_FLTINJ_ASSIST) || (RTE_CONST_FLTINJ_ASSIST != 1U)
#   error "Enumeration constant <FLTINJ_ASSIST> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_ASSIST (1U)
#  define FLTINJ_ASSIST (1U)
# endif
# if (defined RTE_CONST_FLTINJ_RETURN) || (defined FLTINJ_RETURN)
#  if (!defined RTE_CONST_FLTINJ_RETURN) || (RTE_CONST_FLTINJ_RETURN != 2U)
#   error "Enumeration constant <FLTINJ_RETURN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_RETURN (2U)
#  define FLTINJ_RETURN (2U)
# endif
# if (defined RTE_CONST_FLTINJ_DAMPING) || (defined FLTINJ_DAMPING)
#  if (!defined RTE_CONST_FLTINJ_DAMPING) || (RTE_CONST_FLTINJ_DAMPING != 3U)
#   error "Enumeration constant <FLTINJ_DAMPING> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_DAMPING (3U)
#  define FLTINJ_DAMPING (3U)
# endif
# if (defined RTE_CONST_FLTINJ_ASSTSUMNLMT) || (defined FLTINJ_ASSTSUMNLMT)
#  if (!defined RTE_CONST_FLTINJ_ASSTSUMNLMT) || (RTE_CONST_FLTINJ_ASSTSUMNLMT != 4U)
#   error "Enumeration constant <FLTINJ_ASSTSUMNLMT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_ASSTSUMNLMT (4U)
#  define FLTINJ_ASSTSUMNLMT (4U)
# endif
# if (defined RTE_CONST_FLTINJ_AVGFRICLRN) || (defined FLTINJ_AVGFRICLRN)
#  if (!defined RTE_CONST_FLTINJ_AVGFRICLRN) || (RTE_CONST_FLTINJ_AVGFRICLRN != 7U)
#   error "Enumeration constant <FLTINJ_AVGFRICLRN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_AVGFRICLRN (7U)
#  define FLTINJ_AVGFRICLRN (7U)
# endif
# if (defined RTE_CONST_FLTINJ_VECU_BATTERYVOLTAGE) || (defined FLTINJ_VECU_BATTERYVOLTAGE)
#  if (!defined RTE_CONST_FLTINJ_VECU_BATTERYVOLTAGE) || (RTE_CONST_FLTINJ_VECU_BATTERYVOLTAGE != 8U)
#   error "Enumeration constant <FLTINJ_VECU_BATTERYVOLTAGE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_VECU_BATTERYVOLTAGE (8U)
#  define FLTINJ_VECU_BATTERYVOLTAGE (8U)
# endif
# if (defined RTE_CONST_FLTINJ_HYSTCOMP) || (defined FLTINJ_HYSTCOMP)
#  if (!defined RTE_CONST_FLTINJ_HYSTCOMP) || (RTE_CONST_FLTINJ_HYSTCOMP != 12U)
#   error "Enumeration constant <FLTINJ_HYSTCOMP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_HYSTCOMP (12U)
#  define FLTINJ_HYSTCOMP (12U)
# endif
# if (defined RTE_CONST_FLTINJ_INERTIACOMP) || (defined FLTINJ_INERTIACOMP)
#  if (!defined RTE_CONST_FLTINJ_INERTIACOMP) || (RTE_CONST_FLTINJ_INERTIACOMP != 14U)
#   error "Enumeration constant <FLTINJ_INERTIACOMP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_INERTIACOMP (14U)
#  define FLTINJ_INERTIACOMP (14U)
# endif
# if (defined RTE_CONST_FLTINJ_EOTDAMPING_ETDMPFW) || (defined FLTINJ_EOTDAMPING_ETDMPFW)
#  if (!defined RTE_CONST_FLTINJ_EOTDAMPING_ETDMPFW) || (RTE_CONST_FLTINJ_EOTDAMPING_ETDMPFW != 27U)
#   error "Enumeration constant <FLTINJ_EOTDAMPING_ETDMPFW> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_EOTDAMPING_ETDMPFW (27U)
#  define FLTINJ_EOTDAMPING_ETDMPFW (27U)
# endif
# if (defined RTE_CONST_FLTINJ_STABILITYCOMP) || (defined FLTINJ_STABILITYCOMP)
#  if (!defined RTE_CONST_FLTINJ_STABILITYCOMP) || (RTE_CONST_FLTINJ_STABILITYCOMP != 29U)
#   error "Enumeration constant <FLTINJ_STABILITYCOMP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_STABILITYCOMP (29U)
#  define FLTINJ_STABILITYCOMP (29U)
# endif
# if (defined RTE_CONST_FLTINJ_TRQBASEDINRTCOMP) || (defined FLTINJ_TRQBASEDINRTCOMP)
#  if (!defined RTE_CONST_FLTINJ_TRQBASEDINRTCOMP) || (RTE_CONST_FLTINJ_TRQBASEDINRTCOMP != 30U)
#   error "Enumeration constant <FLTINJ_TRQBASEDINRTCOMP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_TRQBASEDINRTCOMP (30U)
#  define FLTINJ_TRQBASEDINRTCOMP (30U)
# endif
# if (defined RTE_CONST_FLTINJ_SRLCOMVEHSPD_SGNLCOND) || (defined FLTINJ_SRLCOMVEHSPD_SGNLCOND)
#  if (!defined RTE_CONST_FLTINJ_SRLCOMVEHSPD_SGNLCOND) || (RTE_CONST_FLTINJ_SRLCOMVEHSPD_SGNLCOND != 33U)
#   error "Enumeration constant <FLTINJ_SRLCOMVEHSPD_SGNLCOND> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_SRLCOMVEHSPD_SGNLCOND (33U)
#  define FLTINJ_SRLCOMVEHSPD_SGNLCOND (33U)
# endif
# if (defined RTE_CONST_FLTINJ_ASSTFIREWALL) || (defined FLTINJ_ASSTFIREWALL)
#  if (!defined RTE_CONST_FLTINJ_ASSTFIREWALL) || (RTE_CONST_FLTINJ_ASSTFIREWALL != 34U)
#   error "Enumeration constant <FLTINJ_ASSTFIREWALL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_ASSTFIREWALL (34U)
#  define FLTINJ_ASSTFIREWALL (34U)
# endif
# if (defined RTE_CONST_FLTINJ_ASSTEOTGAIN_LMTCOD) || (defined FLTINJ_ASSTEOTGAIN_LMTCOD)
#  if (!defined RTE_CONST_FLTINJ_ASSTEOTGAIN_LMTCOD) || (RTE_CONST_FLTINJ_ASSTEOTGAIN_LMTCOD != 38U)
#   error "Enumeration constant <FLTINJ_ASSTEOTGAIN_LMTCOD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_ASSTEOTGAIN_LMTCOD (38U)
#  define FLTINJ_ASSTEOTGAIN_LMTCOD (38U)
# endif
# if (defined RTE_CONST_FLTINJ_DDASTFACTRQST_DRVDYNCTRL) || (defined FLTINJ_DDASTFACTRQST_DRVDYNCTRL)
#  if (!defined RTE_CONST_FLTINJ_DDASTFACTRQST_DRVDYNCTRL) || (RTE_CONST_FLTINJ_DDASTFACTRQST_DRVDYNCTRL != 150U)
#   error "Enumeration constant <FLTINJ_DDASTFACTRQST_DRVDYNCTRL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_DDASTFACTRQST_DRVDYNCTRL (150U)
#  define FLTINJ_DDASTFACTRQST_DRVDYNCTRL (150U)
# endif
# if (defined RTE_CONST_FLTINJ_DDDMPFACTRQST_DRVDYNCTRL) || (defined FLTINJ_DDDMPFACTRQST_DRVDYNCTRL)
#  if (!defined RTE_CONST_FLTINJ_DDDMPFACTRQST_DRVDYNCTRL) || (RTE_CONST_FLTINJ_DDDMPFACTRQST_DRVDYNCTRL != 151U)
#   error "Enumeration constant <FLTINJ_DDDMPFACTRQST_DRVDYNCTRL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_DDDMPFACTRQST_DRVDYNCTRL (151U)
#  define FLTINJ_DDDMPFACTRQST_DRVDYNCTRL (151U)
# endif
# if (defined RTE_CONST_FLTINJ_DDRTNFACTRQST_DRVDYNCTRL) || (defined FLTINJ_DDRTNFACTRQST_DRVDYNCTRL)
#  if (!defined RTE_CONST_FLTINJ_DDRTNFACTRQST_DRVDYNCTRL) || (RTE_CONST_FLTINJ_DDRTNFACTRQST_DRVDYNCTRL != 152U)
#   error "Enumeration constant <FLTINJ_DDRTNFACTRQST_DRVDYNCTRL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_DDRTNFACTRQST_DRVDYNCTRL (152U)
#  define FLTINJ_DDRTNFACTRQST_DRVDYNCTRL (152U)
# endif
# if (defined RTE_CONST_FLTINJ_OUTPUTRAMPMULT_LMTCOD) || (defined FLTINJ_OUTPUTRAMPMULT_LMTCOD)
#  if (!defined RTE_CONST_FLTINJ_OUTPUTRAMPMULT_LMTCOD) || (RTE_CONST_FLTINJ_OUTPUTRAMPMULT_LMTCOD != 153U)
#   error "Enumeration constant <FLTINJ_OUTPUTRAMPMULT_LMTCOD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_OUTPUTRAMPMULT_LMTCOD (153U)
#  define FLTINJ_OUTPUTRAMPMULT_LMTCOD (153U)
# endif
# if (defined RTE_CONST_FLTINJ_ASSTEOTLIMIT_LMTCOD) || (defined FLTINJ_ASSTEOTLIMIT_LMTCOD)
#  if (!defined RTE_CONST_FLTINJ_ASSTEOTLIMIT_LMTCOD) || (RTE_CONST_FLTINJ_ASSTEOTLIMIT_LMTCOD != 154U)
#   error "Enumeration constant <FLTINJ_ASSTEOTLIMIT_LMTCOD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_ASSTEOTLIMIT_LMTCOD (154U)
#  define FLTINJ_ASSTEOTLIMIT_LMTCOD (154U)
# endif


/**********************************************************************************************************************
 * Constant value definitions
 *********************************************************************************************************************/

# if (defined RTE_CONST_D_2MS_SEC_F32) || (defined D_2MS_SEC_F32)
#  if (!defined RTE_CONST_D_2MS_SEC_F32) || (RTE_CONST_D_2MS_SEC_F32 != 0.002F)
#   error "Constant value <D_2MS_SEC_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_2MS_SEC_F32 (0.002F)
#  define D_2MS_SEC_F32 (0.002F)
# endif

# if (defined RTE_CONST_D_MTRTRQCMDHILMT_MTRNM_F32) || (defined D_MTRTRQCMDHILMT_MTRNM_F32)
#  if (!defined RTE_CONST_D_MTRTRQCMDHILMT_MTRNM_F32) || (RTE_CONST_D_MTRTRQCMDHILMT_MTRNM_F32 != 8.8F)
#   error "Constant value <D_MTRTRQCMDHILMT_MTRNM_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_MTRTRQCMDHILMT_MTRNM_F32 (8.8F)
#  define D_MTRTRQCMDHILMT_MTRNM_F32 (8.8F)
# endif

# if (defined RTE_CONST_D_ONE_ULS_F32) || (defined D_ONE_ULS_F32)
#  if (!defined RTE_CONST_D_ONE_ULS_F32) || (RTE_CONST_D_ONE_ULS_F32 != 1.0F)
#   error "Constant value <D_ONE_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_ULS_F32 (1.0F)
#  define D_ONE_ULS_F32 (1.0F)
# endif

# if (defined RTE_CONST_D_ZERO_ULS_F32) || (defined D_ZERO_ULS_F32)
#  if (!defined RTE_CONST_D_ZERO_ULS_F32) || (RTE_CONST_D_ZERO_ULS_F32 != 0.0F)
#   error "Constant value <D_ZERO_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_ULS_F32 (0.0F)
#  define D_ZERO_ULS_F32 (0.0F)
# endif



/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  Float value;
} Rte_DE_Float;


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_Ap_LmtCod
{
  /* Data Handles section */
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_LMTCOD_APPL_VAR) LmtCod_Per1_AssistEOTGain_Uls_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_LMTCOD_APPL_VAR) LmtCod_Per1_AssistEOTLimit_MtrNm_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_LMTCOD_APPL_VAR) LmtCod_Per1_AssistStallLimit_MtrNm_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_LMTCOD_APPL_VAR) LmtCod_Per1_AssistVehSpdLimit_MtrNm_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_LMTCOD_APPL_VAR) LmtCod_Per1_EOTGainLtd_Uls_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_LMTCOD_APPL_VAR) LmtCod_Per1_EOTLimitLtd_MtrNm_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_LMTCOD_APPL_VAR) LmtCod_Per1_OutputRampMultLtd_Uls_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_LMTCOD_APPL_VAR) LmtCod_Per1_OutputRampMult_Uls_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_LMTCOD_APPL_VAR) LmtCod_Per1_StallLimitLtd_MtrNm_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_LMTCOD_APPL_VAR) LmtCod_Per1_ThermalLimitLtd_MtrNm_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_LMTCOD_APPL_VAR) LmtCod_Per1_ThermalLimit_MtrNm_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_LMTCOD_APPL_VAR) LmtCod_Per1_VehSpdLimitLtd_MtrNm_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_LMTCOD_APPL_VAR) LmtCod_Per1_VehicleSpeed_Kph_f32;
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

extern CONSTP2CONST(struct Rte_CDS_Ap_LmtCod, RTE_CONST, RTE_CONST) Rte_Inst_Ap_LmtCod;

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1368799705
#    error "The magic number of the generated file <C:/cmsynergy/CBD_LmtCod_SF38/LmtCod-wz7x3j/LmtCod/utp/contract/Ap_LmtCod/Rte_Type.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1368799705
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_TYPE_H */
