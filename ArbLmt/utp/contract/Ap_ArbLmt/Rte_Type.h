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
 *          File:  Rte_Type.h
 *     Workspace:  C:/Synergy_projects/ArbLmt-lz4p8n1/ArbLmt/autosar
 *     SW-C Type:  Ap_ArbLmt
 *  Generated at:  Wed Jul 10 16:37:52 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
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

# define Rte_TypeDef_Boolean
typedef boolean Boolean;

# define Rte_TypeDef_Float
typedef float32 Float;
# define Float_LowerLimit ((Float)-FLT_MAX)
# define Float_UpperLimit ((Float)FLT_MAX)

# define Rte_TypeDef_SInt16
typedef sint16 SInt16;
# define SInt16_LowerLimit ((SInt16)-32768)
# define SInt16_UpperLimit ((SInt16)32767)

# define Rte_TypeDef_SInt32
typedef sint32 SInt32;
# define SInt32_LowerLimit ((SInt32)-2147483648)
# define SInt32_UpperLimit ((SInt32)2147483647)

# define Rte_TypeDef_SInt8
typedef sint8 SInt8;
# define SInt8_LowerLimit ((SInt8)-128)
# define SInt8_UpperLimit ((SInt8)127)

# define Rte_TypeDef_UInt16
typedef uint16 UInt16;
# define UInt16_LowerLimit ((UInt16)0u)
# define UInt16_UpperLimit ((UInt16)65535u)

# define Rte_TypeDef_UInt32
typedef uint32 UInt32;
# define UInt32_LowerLimit ((UInt32)0u)
# define UInt32_UpperLimit ((UInt32)4294967295u)

# define Rte_TypeDef_UInt8
typedef uint8 UInt8;
# define UInt8_LowerLimit ((UInt8)0u)
# define UInt8_UpperLimit ((UInt8)255u)


# ifndef RTE_SUPPRESS_UNUSED_DATATYPES
/**********************************************************************************************************************
 * Unused Data type definitions
 *********************************************************************************************************************/

#  define Rte_TypeDef_Double
typedef float64 Double;
#  define Double_LowerLimit ((Double)-DBL_MAX)
#  define Double_UpperLimit ((Double)DBL_MAX)

#  define Rte_TypeDef_SInt4
typedef sint8 SInt4;
#  define SInt4_LowerLimit ((SInt4)-8)
#  define SInt4_UpperLimit ((SInt4)7)

#  define Rte_TypeDef_UInt4
typedef uint8 UInt4;
#  define UInt4_LowerLimit ((UInt4)0u)
#  define UInt4_UpperLimit ((UInt4)15u)

# endif


/**********************************************************************************************************************
 * Constant value definitions
 *********************************************************************************************************************/

# if (defined RTE_CONST_D_FALSE_CNT_LGC) || (defined D_FALSE_CNT_LGC)
#  if (!defined RTE_CONST_D_FALSE_CNT_LGC) || (RTE_CONST_D_FALSE_CNT_LGC != FALSE)
#   error "Constant value <D_FALSE_CNT_LGC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_FALSE_CNT_LGC (FALSE)
#  define D_FALSE_CNT_LGC ((Boolean)FALSE)
# endif

# if (defined RTE_CONST_D_TRUE_CNT_LGC) || (defined D_TRUE_CNT_LGC)
#  if (!defined RTE_CONST_D_TRUE_CNT_LGC) || (RTE_CONST_D_TRUE_CNT_LGC != TRUE)
#   error "Constant value <D_TRUE_CNT_LGC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_TRUE_CNT_LGC (TRUE)
#  define D_TRUE_CNT_LGC ((Boolean)TRUE)
# endif

# if (defined RTE_CONST_D_2MS_SEC_F32) || (defined D_2MS_SEC_F32)
#  if (!defined RTE_CONST_D_2MS_SEC_F32) || (RTE_CONST_D_2MS_SEC_F32 != 0.002)
#   error "Constant value <D_2MS_SEC_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_2MS_SEC_F32 (0.002)
#  define D_2MS_SEC_F32 ((Float)0.002)
# endif

# if (defined RTE_CONST_D_2PI_ULS_F32) || (defined D_2PI_ULS_F32)
#  if (!defined RTE_CONST_D_2PI_ULS_F32) || (RTE_CONST_D_2PI_ULS_F32 != 6.2831853071796)
#   error "Constant value <D_2PI_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_2PI_ULS_F32 (6.2831853071796)
#  define D_2PI_ULS_F32 ((Float)6.2831853071796)
# endif

# if (defined RTE_CONST_D_ONE_ULS_F32) || (defined D_ONE_ULS_F32)
#  if (!defined RTE_CONST_D_ONE_ULS_F32) || (RTE_CONST_D_ONE_ULS_F32 != 1)
#   error "Constant value <D_ONE_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_ULS_F32 (1)
#  define D_ONE_ULS_F32 ((Float)1)
# endif

# if (defined RTE_CONST_D_PIOVR180_ULS_F32) || (defined D_PIOVR180_ULS_F32)
#  if (!defined RTE_CONST_D_PIOVR180_ULS_F32) || (RTE_CONST_D_PIOVR180_ULS_F32 != 0.0174532925199)
#   error "Constant value <D_PIOVR180_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_PIOVR180_ULS_F32 (0.0174532925199)
#  define D_PIOVR180_ULS_F32 ((Float)0.0174532925199)
# endif

# if (defined RTE_CONST_D_PI_ULS_F32) || (defined D_PI_ULS_F32)
#  if (!defined RTE_CONST_D_PI_ULS_F32) || (RTE_CONST_D_PI_ULS_F32 != 3.1415926535898)
#   error "Constant value <D_PI_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_PI_ULS_F32 (3.1415926535898)
#  define D_PI_ULS_F32 ((Float)3.1415926535898)
# endif

# if (defined RTE_CONST_D_ZERO_ULS_F32) || (defined D_ZERO_ULS_F32)
#  if (!defined RTE_CONST_D_ZERO_ULS_F32) || (RTE_CONST_D_ZERO_ULS_F32 != 0)
#   error "Constant value <D_ZERO_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_ULS_F32 (0)
#  define D_ZERO_ULS_F32 ((Float)0)
# endif

# if (defined RTE_CONST_D_NEGONE_CNT_S16) || (defined D_NEGONE_CNT_S16)
#  if (!defined RTE_CONST_D_NEGONE_CNT_S16) || (RTE_CONST_D_NEGONE_CNT_S16 != -1)
#   error "Constant value <D_NEGONE_CNT_S16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_NEGONE_CNT_S16 (-1)
#  define D_NEGONE_CNT_S16 ((SInt16)-1)
# endif

# if (defined RTE_CONST_D_ONE_CNT_S16) || (defined D_ONE_CNT_S16)
#  if (!defined RTE_CONST_D_ONE_CNT_S16) || (RTE_CONST_D_ONE_CNT_S16 != 1)
#   error "Constant value <D_ONE_CNT_S16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_S16 (1)
#  define D_ONE_CNT_S16 ((SInt16)1)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_S16) || (defined D_ZERO_CNT_S16)
#  if (!defined RTE_CONST_D_ZERO_CNT_S16) || (RTE_CONST_D_ZERO_CNT_S16 != 0)
#   error "Constant value <D_ZERO_CNT_S16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_S16 (0)
#  define D_ZERO_CNT_S16 ((SInt16)0)
# endif

# if (defined RTE_CONST_D_NEGONE_CNT_S32) || (defined D_NEGONE_CNT_S32)
#  if (!defined RTE_CONST_D_NEGONE_CNT_S32) || (RTE_CONST_D_NEGONE_CNT_S32 != -1)
#   error "Constant value <D_NEGONE_CNT_S32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_NEGONE_CNT_S32 (-1)
#  define D_NEGONE_CNT_S32 ((SInt32)-1)
# endif

# if (defined RTE_CONST_D_ONE_CNT_S32) || (defined D_ONE_CNT_S32)
#  if (!defined RTE_CONST_D_ONE_CNT_S32) || (RTE_CONST_D_ONE_CNT_S32 != 1)
#   error "Constant value <D_ONE_CNT_S32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_S32 (1)
#  define D_ONE_CNT_S32 ((SInt32)1)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_S32) || (defined D_ZERO_CNT_S32)
#  if (!defined RTE_CONST_D_ZERO_CNT_S32) || (RTE_CONST_D_ZERO_CNT_S32 != 0)
#   error "Constant value <D_ZERO_CNT_S32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_S32 (0)
#  define D_ZERO_CNT_S32 ((SInt32)0)
# endif

# if (defined RTE_CONST_D_NEGONE_CNT_S8) || (defined D_NEGONE_CNT_S8)
#  if (!defined RTE_CONST_D_NEGONE_CNT_S8) || (RTE_CONST_D_NEGONE_CNT_S8 != -1)
#   error "Constant value <D_NEGONE_CNT_S8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_NEGONE_CNT_S8 (-1)
#  define D_NEGONE_CNT_S8 ((SInt8)-1)
# endif

# if (defined RTE_CONST_D_ONE_CNT_S8) || (defined D_ONE_CNT_S8)
#  if (!defined RTE_CONST_D_ONE_CNT_S8) || (RTE_CONST_D_ONE_CNT_S8 != 1)
#   error "Constant value <D_ONE_CNT_S8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_S8 (1)
#  define D_ONE_CNT_S8 ((SInt8)1)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_S8) || (defined D_ZERO_CNT_S8)
#  if (!defined RTE_CONST_D_ZERO_CNT_S8) || (RTE_CONST_D_ZERO_CNT_S8 != 0)
#   error "Constant value <D_ZERO_CNT_S8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_S8 (0)
#  define D_ZERO_CNT_S8 ((SInt8)0)
# endif

# if (defined RTE_CONST_D_ONE_CNT_U16) || (defined D_ONE_CNT_U16)
#  if (!defined RTE_CONST_D_ONE_CNT_U16) || (RTE_CONST_D_ONE_CNT_U16 != 1u)
#   error "Constant value <D_ONE_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_U16 (1u)
#  define D_ONE_CNT_U16 ((UInt16)1u)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_U16) || (defined D_ZERO_CNT_U16)
#  if (!defined RTE_CONST_D_ZERO_CNT_U16) || (RTE_CONST_D_ZERO_CNT_U16 != 0u)
#   error "Constant value <D_ZERO_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_U16 (0u)
#  define D_ZERO_CNT_U16 ((UInt16)0u)
# endif

# if (defined RTE_CONST_D_ONE_CNT_U32) || (defined D_ONE_CNT_U32)
#  if (!defined RTE_CONST_D_ONE_CNT_U32) || (RTE_CONST_D_ONE_CNT_U32 != 1u)
#   error "Constant value <D_ONE_CNT_U32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_U32 (1u)
#  define D_ONE_CNT_U32 ((UInt32)1u)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_U32) || (defined D_ZERO_CNT_U32)
#  if (!defined RTE_CONST_D_ZERO_CNT_U32) || (RTE_CONST_D_ZERO_CNT_U32 != 0u)
#   error "Constant value <D_ZERO_CNT_U32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_U32 (0u)
#  define D_ZERO_CNT_U32 ((UInt32)0u)
# endif

# if (defined RTE_CONST_D_ONE_CNT_U8) || (defined D_ONE_CNT_U8)
#  if (!defined RTE_CONST_D_ONE_CNT_U8) || (RTE_CONST_D_ONE_CNT_U8 != 1u)
#   error "Constant value <D_ONE_CNT_U8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_U8 (1u)
#  define D_ONE_CNT_U8 ((UInt8)1u)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_U8) || (defined D_ZERO_CNT_U8)
#  if (!defined RTE_CONST_D_ZERO_CNT_U8) || (RTE_CONST_D_ZERO_CNT_U8 != 0u)
#   error "Constant value <D_ZERO_CNT_U8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_U8 (0u)
#  define D_ZERO_CNT_U8 ((UInt8)0u)
# endif



/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  Boolean value;
} Rte_DE_Boolean;

typedef struct
{
  UInt8 value;
} Rte_DE_UInt8;

typedef struct
{
  Float value;
} Rte_DE_Float;


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_Ap_ArbLmt
{
  /* Data Handles section */
  P2VAR(Rte_DE_UInt8, TYPEDEF, RTE_AP_ARBLMT_APPL_VAR) ArbLmt_Per1_ActiveFunctionBits_Cnt_u08;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_ARBLMT_APPL_VAR) ArbLmt_Per1_DSTActive_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_ARBLMT_APPL_VAR) ArbLmt_Per1_DSTSlewComplete_Cnt_lgc;
  P2VAR(Rte_DE_UInt8, TYPEDEF, RTE_AP_ARBLMT_APPL_VAR) ArbLmt_Per1_DSTState_Cnt_u08;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_ARBLMT_APPL_VAR) ArbLmt_Per1_DSTTrqOvCmdRqst_HwNm_f32;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_ARBLMT_APPL_VAR) ArbLmt_Per1_HaLFActive_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_ARBLMT_APPL_VAR) ArbLmt_Per1_HaLFSlewComplete_Cnt_lgc;
  P2VAR(Rte_DE_UInt8, TYPEDEF, RTE_AP_ARBLMT_APPL_VAR) ArbLmt_Per1_HaLFTOState_Cnt_u08;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_ARBLMT_APPL_VAR) ArbLmt_Per1_HaLFTrqOvCmdRqst_MtrNm_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_ARBLMT_APPL_VAR) ArbLmt_Per1_IpTrqOvr_HwNm_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_ARBLMT_APPL_VAR) ArbLmt_Per1_OpTrqOvr_MtrNm_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_ARBLMT_APPL_VAR) ArbLmt_Per1_PAReturnSclFct_Uls_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_ARBLMT_APPL_VAR) ArbLmt_Per1_PATrqOvCmdRqst_HwNm_f32;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_ARBLMT_APPL_VAR) ArbLmt_Per1_PICmpDisableLearning_Cnt_lgc;
  P2VAR(Rte_DE_UInt8, TYPEDEF, RTE_AP_ARBLMT_APPL_VAR) ArbLmt_Per1_PrkAssistState_Cnt_u08;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_ARBLMT_APPL_VAR) ArbLmt_Per1_PrkAsstSlewComplete_Cnt_lgc;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_ARBLMT_APPL_VAR) ArbLmt_Per1_VehicleSpeed_Kph_f32;
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

extern CONSTP2CONST(struct Rte_CDS_Ap_ArbLmt, RTE_CONST, RTE_CONST) Rte_Inst_Ap_ArbLmt;

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1373494855
#    error "The magic number of the generated file <C:/Synergy_projects/ArbLmt-lz4p8n1/ArbLmt/utp/contract/Ap_ArbLmt/Rte_Type.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1373494855
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_TYPE_H */
