/* -----------------------------------------------------------------------------
  Filename:    xcp_cfg.h
  Description: Toolversion: 01.00.35.01.21.00.21.01.00.00
               
               Serial Number: CBD1210021
               Customer Info: Nexteer
                              Package: CBD_Chrysler_SLP1_UDS_Sgl
                              Micro: TexasInstruments TMS570 - TMX570LS0805APGEQQ1
                              Compiler: Texas Instruments 4.9.5
               
               
               Generator Fwk   : GENy 
               Generator Module: Xcp
               
               Configuration   : C:\cmsynergy\My_ePWM_LWR\Chrysler_LWR_EPS_TMS570\Tools\AsrProject\GENy\Chrsyler_SLP1_EPS.gny
               
               ECU: 
                       TargetSystem: Hw_Tms470/570Cpu (Dcan)
                       Compiler:     TexasInstruments
                       Derivates:    TMS570PSFC66
               
               Channel "Channel0":
                       Databasefile: C:\cmsynergy\My_ePWM_LWR\Chrysler_LWR_EPS_TMS570\Tools\AsrProject\GENy\CAN C v1313 15LXMod.dbc
                       Bussystem:    CAN
                       Manufacturer: DaimlerChrysler
                       Node:         EPS

  Generated by , 2013-08-27  09:05:08
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

#if !defined(__XCP_CFG_H__)
#define __XCP_CFG_H__

/*  */
#include "v_inc.h"
/*  */
/* General settings */
#define XCP_ENABLE_PARAMETER_CHECK
#define XCP_ENABLE_CALIBRATION
#define XCP_DISABLE_SEND_EVENT
#define XCP_DISABLE_TESTMODE
#define XCP_DISABLE_BOOTLOADER_DOWNLOAD
#define XCP_ENABLE_WRITE_PROTECTION
#define XCP_ENABLE_READ_PROTECTION
#define XCP_DISABLE_CONTROL
#define XCP_DISABLE_GET_XCP_DATA_POINTER
#define XCP_DISABLE_OPENCMDIF
#define XCP_DISABLE_DEV_ERROR_DETECT
/*  */
/* EEPROM access */
#define XCP_ENABLE_READ_EEPROM
#define XCP_ENABLE_WRITE_EEPROM
/*  */
/* Service request message */
#define XCP_DISABLE_SERV_TEXT
#define XCP_DISABLE_SERV_TEXT_PUTCHAR
#define XCP_DISABLE_SERV_TEXT_PRINT
/*  */
/* Standard commands */
#define XCP_ENABLE_COMM_MODE_INFO
#define XCP_DISABLE_SEED_KEY
#define XCP_DISABLE_MODIFY_BITS
#define XCP_ENABLE_SHORT_DOWNLOAD
#define XCP_ENABLE_USER_COMMAND
#define XCP_DISABLE_VECTOR_MAPNAMES
#define XCP_DISABLE_TL_COMMAND
/*  */
/* Block transfer */
#define XCP_ENABLE_BLOCK_UPLOAD
#define XCP_ENABLE_BLOCK_DOWNLOAD
#define kXcpBlockDownloadMinSt               0u
/*  */
/* Checksum */
#define XCP_DISABLE_CHECKSUM
/*  */
/* Synchronous Data Acquisition (DAQ) */
#define XCP_ENABLE_DAQ
#define kXcpDaqMemSize                       512u
#define XCP_DISABLE_STIM
#define XCP_DISABLE_UNALIGNED_MEM_ACCESS
#define XCP_ENABLE_SEND_QUEUE
#define XCP_ENABLE_DAQ_PRESCALER
#define XCP_ENABLE_DAQ_OVERRUN_INDICATION
#define XCP_ENABLE_WRITE_DAQ_MULTIPLE
#define XCP_DISABLE_DAQ_HDR_ODT_DAQ
#define XCP_DISABLE_DAQ_RESUME
#define XCP_ENABLE_DAQ_PROCESSOR_INFO
#define XCP_ENABLE_DAQ_RESOLUTION_INFO
#define XCP_DISABLE_VIRTUAL_MEASUREMENT
/*  */
/* Events */
#define XCP_ENABLE_DAQ_EVENT_INFO
#define kXcpMaxEvent                         1u
/*  */
/* DAQ Timestamp */
#define XCP_ENABLE_DAQ_TIMESTAMP
#define XCP_DISABLE_DAQ_TIMESTAMP_FIXED
#define kXcpDaqTimestampSize                 DAQ_TIMESTAMP_WORD
#define kXcpDaqTimestampUnit                 DAQ_TIMESTAMP_UNIT_1US
#define kXcpDaqTimestampTicksPerUnit         1u
/*  */
/* Page switching */
#define XCP_DISABLE_CALIBRATION_PAGE
/*  */
/* Programming */
#define XCP_ENABLE_PROGRAM
#define kXcpProgramMinStPgm                  0u
#define XCP_DISABLE_PROGRAMMING_WRITE_PROTECTION
#define CP_XCPDLL_VERSION                    0x0218
#define CP_XCPDLL_RELEASE_VERSION            0x02
/* -----------------------------------------------------------------------------
    &&&~ Multiple transport layer support
 ----------------------------------------------------------------------------- */

/* Multiple transport layer support */
#define NUMBER_OF_TRANSPORTLAYERS            1u
/* CompilerAbstractionEnabled == FALSE */
/* 1 */
#define XCP_TRANSPORT_LAYER_CAN              0


/* -----------------------------------------------------------------------------
    &&&~ FlexRay parameter access
 ----------------------------------------------------------------------------- */

#define XCP_DISABLE_VECTOR_GENERICMEASUREMENT


/* Transport Layer */
/*  */
#define kXcpNumberOfCanChannels              1
#define XCP_DISABLE_CAN_MULTI_CHANNEL
#define XCP_DISABLE_CAN_MULTI_CONNECTION_PROTECTION
#define XCP_TRANSPORT_LAYER_TYPE_CAN
#define XCP_TRANSPORT_LAYER_VERSION_CAN      0x0100
#define kCanXcpMaxCTO                        8
#define kCanXcpMaxDTO                        8
#define XCP_DISABLE_CAN_VARIABLE_DLC
#define kXcpSendQueueMinSize                 1
/*  */
#define CP_XCPONCANDLL_VERSION               0x0108
#define CP_XCPONCANDLL_RELEASE_VERSION       0x01

#define XCP_ENABLE_CALIBRATION_MEM_ACCESS_BY_APPL
/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 103168731
      #error "The magic number of the generated file <C:\Synergy_WorkArea\ESG_Dev_65\Chrysler_LWR_EPS_TMS570-tzj9qy\Chrysler_LWR_EPS_TMS570\SwProject\Source\_GenData\xcp_cfg.h> is different. Please check time and date of generated files!"
  #endif
#else
  #define MAGIC_NUMBER 103168731
#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

#endif /* __XCP_CFG_H__ */
