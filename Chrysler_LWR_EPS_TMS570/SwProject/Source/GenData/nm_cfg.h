/* -----------------------------------------------------------------------------
  Filename:    nm_cfg.h
  Description: Toolversion: 01.00.35.01.21.00.21.01.00.00
               
               Serial Number: CBD1210021
               Customer Info: Nexteer
                              Package: CBD_Chrysler_SLP1_UDS_Sgl
                              Micro: TexasInstruments TMS570 - TMX570LS0805APGEQQ1
                              Compiler: Texas Instruments 4.9.5
               
               
               Generator Fwk   : GENy 
               Generator Module: Nm_DirOsek
               
               Configuration   : C:\Synergy\Chrysler_LWR_EPS_TMS570-zz4r1x\Chrysler_LWR_EPS_TMS570\Tools\AsrProject\GENy\Chrsyler_SLP1_EPS.gny
               
               ECU: 
                       TargetSystem: Hw_Tms470/570Cpu (Dcan)
                       Compiler:     TexasInstruments
                       Derivates:    TMS570PSFC66
               
               Channel "Channel0":
                       Databasefile: C:\Synergy\Chrysler_LWR_EPS_TMS570-zz4r1x\Chrysler_LWR_EPS_TMS570\Tools\AsrProject\GENy\CAN C v1232 EPS.dbc
                       Bussystem:    CAN
                       Manufacturer: DaimlerChrysler
                       Node:         EPS

  Generated by , 2012-12-11  16:14:28
 ----------------------------------------------------------------------------- */
/* -----------------------------------------------------------------------------
  C O P Y R I G H T
 -------------------------------------------------------------------------------
  Copyright (c) 2001-2011 by Vector Informatik GmbH. All rights reserved.
 
  This software is copyright protected and proprietary to Vector Informatik 
  GmbH.
  
  Vector Informatik GmbH grants to you only those rights as set out in the 
  license conditions.
  
  All other rights remain with Vector Informatik GmbH.
 -------------------------------------------------------------------------------
 ----------------------------------------------------------------------------- */

#if !defined(__NM_CFG_H__)
#define __NM_CFG_H__

#define NM_DIROSEKDLL_VERSION                0x0208
#define NM_DIROSEKDLL_RELEASE_VERSION        0x03
#define kNmNumberOfChannels                  1
/* Define needed by some other components */
#define NM_CFG_H
/* Compatibility switch for old NM component */
#define NM_NO_COMPATIBILITY
/* Nm instance properties */
#define NM_TYPE_DBAG_OSEK
#define NM_DISABLE_RINGDATA_ACCESS
#define NM_DISABLE_INDEXED_NM
#define NM_DISABLE_COPY_RINGDATA
#define NM_ENABLE_EXTENDED_CALLBACK
#define NM_DISABLE_CONFIG
#define NM_DISABLE_CAN_ERRORBIT
#define NM_DISABLE_ERRORPIN_SEND
#define NM_DISABLE_BUS_DIAGNOSTICS
#define NM_DISABLE_IMMEDIATE_ALIVE
#define NM_ENABLE_FAST_BUSOFF_RECOVERY
#define NM_DISABLE_COPY_RINGDATA_TO_TEMPBUFFER
#define NM_ENABLE_USERDATA_ACCESS
#define NM_ENABLE_ONM_EXT_API
#define NM_DISABLE_GW_MULTI_NM
#define NM_DISABLE_REMOTESLEEP_INDICATION
#define NM_DISABLE_EXTERNAL_CANONLINE_HANDLING
#define NM_DISABLE_ASSERTIONS
/*  */
#define kNmNumberOfRanges                    1
#define NM_RANGE_MASK                        0x3F
#define NM_RANGE_CODE                        0x0400
/* Nm channel properties */
#define kNmTxObj                             CanTxNM_EPS
#define kNmEcuNr                             0x1A
#define kNmCanPara                           0
#define kNmCallCycle                         10
#define NM_COUNT_RING_TYP                    9
#define NM_COUNT_RING_MAX                    25
#define NM_COUNT_LIMPHOME                    100
#define NM_COUNT_WAIT_BUSSLEEP               150
#define NM_COUNT_RING_TYP_INITIAL            9
#define NM_COUNT_PREPARESLEEP                1
#define NM_COUNT_LIMPHOME_SHORT              5
#define NM_COUNT_SHORT_NUMBER                20
#define NM_DISABLE_MULTIPLE_NODES

/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 103168731
      #error "The magic number of the generated file <C:\Synergy\Chrysler_LWR_EPS_TMS570-zz4r1x\Chrysler_LWR_EPS_TMS570\SwProject\Source\_GenData\nm_cfg.h> is different. Please check time and date of generated files!"
  #endif
#else
  #define MAGIC_NUMBER 114462992
#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

#endif /* __NM_CFG_H__ */
