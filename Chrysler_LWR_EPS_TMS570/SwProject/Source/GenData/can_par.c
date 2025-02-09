/* -----------------------------------------------------------------------------
  Filename:    can_par.c
  Description: Toolversion: 01.00.35.01.21.00.21.01.00.00
               
               Serial Number: CBD1210021
               Customer Info: Nexteer
                              Package: CBD_Chrysler_SLP1_UDS_Sgl
                              Micro: TexasInstruments TMS570 - TMX570LS0805APGEQQ1
                              Compiler: Texas Instruments 4.9.5
               
               
               Generator Fwk   : GENy 
               Generator Module: DrvCan__base
               
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

  Generated by , 2013-04-25  11:29:38
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

#define C_DRV_INTERNAL
#include "can_inc.h"
#include "can_par.h"
#include "v_inc.h"

/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 tCanTxId0 V_MEMROM2 CanTxId0[kCanNumberOfTxObjects] = 
{
  MK_STDID0(0x61A) /* ID: 0x0000061a, Handle: 0, SD_RS_EPS [FC] */, 
  MK_STDID0(0x59A) /* ID: 0x0000059a, Handle: 1, ECU_APPL_EPS [FC] */, 
  MK_STDID0(0x4DA) /* ID: 0x000004da, Handle: 2, D_RS_EPS [FC] */, 
  MK_STDID0(0x41A) /* ID: 0x0000041a, Handle: 3, NM_EPS [BC] */, 
  MK_STDID0(0x220) /* ID: 0x00000220, Handle: 4, EPS_1 [FC] */, 
  MK_STDID0(0x12C) /* ID: 0x0000012c, Handle: 5, EPS_A1 [FC] */
};
/* ROM CATEGORY 1 END */


/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanTxDLC[kCanNumberOfTxObjects] = 
{
  MK_TX_DLC(8) /* ID: 0x0000061a, Handle: 0, SD_RS_EPS [FC] */, 
  MK_TX_DLC(8) /* ID: 0x0000059a, Handle: 1, ECU_APPL_EPS [FC] */, 
  MK_TX_DLC(8) /* ID: 0x000004da, Handle: 2, D_RS_EPS [FC] */, 
  MK_TX_DLC(8) /* ID: 0x0000041a, Handle: 3, NM_EPS [BC] */, 
  MK_TX_DLC(8) /* ID: 0x00000220, Handle: 4, EPS_1 [FC] */, 
  MK_TX_DLC(8) /* ID: 0x0000012c, Handle: 5, EPS_A1 [FC] */
};
/* ROM CATEGORY 1 END */


#ifdef C_ENABLE_COPY_TX_DATA
/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 TxDataPtr V_MEMROM2 CanTxDataPtr[kCanNumberOfTxObjects] = 
{
  (TxDataPtr)  & dbkBufferSD_RS_EPS /* ID: 0x0000061a, Handle: 0, SD_RS_EPS [FC] */, 
  (TxDataPtr) ECU_APPL_EPS._c /* ID: 0x0000059a, Handle: 1, ECU_APPL_EPS [FC] */, 
  (TxDataPtr) D_RS_EPS._c /* ID: 0x000004da, Handle: 2, D_RS_EPS [FC] */, 
  (TxDataPtr) nmSendMess /* ID: 0x0000041a, Handle: 3, NM_EPS [BC] */, 
  (TxDataPtr)  & dbkBufferEPS_1 /* ID: 0x00000220, Handle: 4, EPS_1 [FC] */, 
  (TxDataPtr)  & dbkBufferEPS_A1 /* ID: 0x0000012c, Handle: 5, EPS_A1 [FC] */
};
/* ROM CATEGORY 1 END */

#endif


#ifdef C_ENABLE_PRETRANSMIT_FCT
/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 ApplPreTransmitFct V_MEMROM2 CanTxApplPreTransmitPtr[kCanNumberOfTxObjects] = 
{
  V_NULL /* ID: 0x0000061a, Handle: 0, SD_RS_EPS [FC] */, 
  V_NULL /* ID: 0x0000059a, Handle: 1, ECU_APPL_EPS [FC] */, 
  V_NULL /* ID: 0x000004da, Handle: 2, D_RS_EPS [FC] */, 
  V_NULL /* ID: 0x0000041a, Handle: 3, NM_EPS [BC] */, 
  V_NULL /* ID: 0x00000220, Handle: 4, EPS_1 [FC] */, 
  V_NULL /* ID: 0x0000012c, Handle: 5, EPS_A1 [FC] */
};
/* ROM CATEGORY 1 END */

#endif


#ifdef C_ENABLE_CONFIRMATION_FCT
/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 ApplConfirmationFct V_MEMROM2 CanTxApplConfirmationPtr[kCanNumberOfTxObjects] = 
{
  dbkConfirmation /* ID: 0x0000061a, Handle: 0, SD_RS_EPS [FC] */, 
  XcpConfirmation /* ID: 0x0000059a, Handle: 1, ECU_APPL_EPS [FC] */, 
  TpDrvConfirmation /* ID: 0x000004da, Handle: 2, D_RS_EPS [FC] */, 
  NmConfirmation /* ID: 0x0000041a, Handle: 3, NM_EPS [BC] */, 
  dbkConfirmation /* ID: 0x00000220, Handle: 4, EPS_1 [FC] */, 
  dbkConfirmation /* ID: 0x0000012c, Handle: 5, EPS_A1 [FC] */
};
/* ROM CATEGORY 1 END */

#endif


#ifdef C_ENABLE_PART_OFFLINE
/* ROM CATEGORY 2 START */

V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanTxSendMask[kCanNumberOfTxObjects] = 
{
  (vuint8) C_SEND_GRP_APPL /* ID: 0x0000061a, Handle: 0, SD_RS_EPS [FC] */, 
  (vuint8) C_SEND_GRP_APPL /* ID: 0x0000059a, Handle: 1, ECU_APPL_EPS [FC] */, 
  (vuint8) C_SEND_GRP_DIAG /* ID: 0x000004da, Handle: 2, D_RS_EPS [FC] */, 
  (vuint8) C_SEND_GRP_NM /* ID: 0x0000041a, Handle: 3, NM_EPS [BC] */, 
  (vuint8) C_SEND_GRP_APPL /* ID: 0x00000220, Handle: 4, EPS_1 [FC] */, 
  (vuint8) C_SEND_GRP_APPL /* ID: 0x0000012c, Handle: 5, EPS_A1 [FC] */
};

/* ROM CATEGORY 2 END */

#endif


#ifdef C_ENABLE_CONFIRMATION_FLAG
/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanConfirmationOffset[kCanNumberOfTxObjects] = 
{
  0 /* ID: 0x0000061a, Handle: 0, SD_RS_EPS [FC] */, 
  0 /* ID: 0x0000059a, Handle: 1, ECU_APPL_EPS [FC] */, 
  0 /* ID: 0x000004da, Handle: 2, D_RS_EPS [FC] */, 
  0 /* ID: 0x0000041a, Handle: 3, NM_EPS [BC] */, 
  0 /* ID: 0x00000220, Handle: 4, EPS_1 [FC] */, 
  0 /* ID: 0x0000012c, Handle: 5, EPS_A1 [FC] */
};
/* ROM CATEGORY 1 END */


/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanConfirmationMask[kCanNumberOfTxObjects] = 
{
  0x00 /* ID: 0x0000061a, Handle: 0, SD_RS_EPS [FC] */, 
  0x01 /* ID: 0x0000059a, Handle: 1, ECU_APPL_EPS [FC] */, 
  0x00 /* ID: 0x000004da, Handle: 2, D_RS_EPS [FC] */, 
  0x00 /* ID: 0x0000041a, Handle: 3, NM_EPS [BC] */, 
  0x00 /* ID: 0x00000220, Handle: 4, EPS_1 [FC] */, 
  0x00 /* ID: 0x0000012c, Handle: 5, EPS_A1 [FC] */
};
/* ROM CATEGORY 1 END */


#endif




/* Id table depending on search algorithm */
/* Linear search */
/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 tCanRxId0 V_MEMROM2 CanRxId0[kCanNumberOfRxObjects] = 
{
  MK_STDID0(0x75A) /* ID: 0x0000075a, Handle: 33, D_RQ_EPS [FC] */, 
  MK_STDID0(0x6DA) /* ID: 0x000006da, Handle: 34, APPL_ECU_EPS [FC] */, 
  MK_STDID0(0x44A) /* ID: 0x0000044a, Handle: 0, VehCfg5 [FC] */, 
  MK_STDID0(0x441) /* ID: 0x00000441, Handle: 35, DG_RQ_GLOBAL_UDS [FC] */, 
  MK_STDID0(0x3F5) /* ID: 0x000003f5, Handle: 1, EcuCfg6 [FC] */, 
  MK_STDID0(0x3EB) /* ID: 0x000003eb, Handle: 2, VehCfg4 [FC] */, 
  MK_STDID0(0x3EA) /* ID: 0x000003ea, Handle: 3, VehCfg3 [FC] */, 
  MK_STDID0(0x3E9) /* ID: 0x000003e9, Handle: 4, VehCfg2 [FC] */, 
  MK_STDID0(0x3E8) /* ID: 0x000003e8, Handle: 5, VehCfg1 [FC] */, 
  MK_STDID0(0x3E4) /* ID: 0x000003e4, Handle: 6, NET_CFG_PT [FC] */, 
  MK_STDID0(0x3E1) /* ID: 0x000003e1, Handle: 7, ENG_CFG [FC] */, 
  MK_STDID0(0x3E0) /* ID: 0x000003e0, Handle: 8, VIN [FC] */, 
  MK_STDID0(0x381) /* ID: 0x00000381, Handle: 9, VehCfg7 [FC] */, 
  MK_STDID0(0x334) /* ID: 0x00000334, Handle: 10, CBC_PT1 [FC] */, 
  MK_STDID0(0x31F) /* ID: 0x0000031f, Handle: 11, GW_LIN_I_C2 [FC] */, 
  MK_STDID0(0x316) /* ID: 0x00000316, Handle: 12, CFG_RQ_C [FC] */, 
  MK_STDID0(0x314) /* ID: 0x00000314, Handle: 13, CFG_RQ [FC] */, 
  MK_STDID0(0x310) /* ID: 0x00000310, Handle: 14, IC_A1 [FC] */, 
  MK_STDID0(0x302) /* ID: 0x00000302, Handle: 15, EPB_1 [FC] */, 
  MK_STDID0(0x2F8) /* ID: 0x000002f8, Handle: 16, ECM_A3 [FC] */, 
  MK_STDID0(0x2A0) /* ID: 0x000002a0, Handle: 17, ECM_INDICATORS [FC] */, 
  MK_STDID0(0x29F) /* ID: 0x0000029f, Handle: 18, PTS_StrCtrl [FC] */, 
  MK_STDID0(0x294) /* ID: 0x00000294, Handle: 19, DST_TOC [FC] */, 
  MK_STDID0(0x292) /* ID: 0x00000292, Handle: 20, HALF_MTO_SteerControl [FC] */, 
  MK_STDID0(0x202) /* ID: 0x00000202, Handle: 21, WHEEL_SPEED_2 [FC] */, 
  MK_STDID0(0x200) /* ID: 0x00000200, Handle: 22, CBC_PT3 [FC] */, 
  MK_STDID0(0x170) /* ID: 0x00000170, Handle: 23, TRNS_STAT [FC] */, 
  MK_STDID0(0x158) /* ID: 0x00000158, Handle: 24, ESP_A6 [FC] */, 
  MK_STDID0(0x14C) /* ID: 0x0000014c, Handle: 25, ESP_A4 [FC] */, 
  MK_STDID0(0x144) /* ID: 0x00000144, Handle: 26, TRNS_SPD [FC] */, 
  MK_STDID0(0x126) /* ID: 0x00000126, Handle: 27, ORC_YRS_DATA [FC] */, 
  MK_STDID0(0x124) /* ID: 0x00000124, Handle: 28, ESP_A5 [FC] */, 
  MK_STDID0(0x11C) /* ID: 0x0000011c, Handle: 29, ESP_A8 [FC] */, 
  MK_STDID0(0x112) /* ID: 0x00000112, Handle: 30, CBC_PT2 [FC] */, 
  MK_STDID0(0x108) /* ID: 0x00000108, Handle: 31, ECM_A1 [FC] */, 
  MK_STDID0(0x102) /* ID: 0x00000102, Handle: 32, SCCM_STW_ANGL_STAT [FC] */
};
/* ROM CATEGORY 1 END */


/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 CanReceiveHandle V_MEMROM2 CanRxMsgIndirection[kCanNumberOfRxObjects] = 
{
  33 /* ID: 0x0000075a, Handle: 33, D_RQ_EPS */, 
  34 /* ID: 0x000006da, Handle: 34, APPL_ECU_EPS */, 
  0 /* ID: 0x0000044a, Handle: 0, VehCfg5 */, 
  35 /* ID: 0x00000441, Handle: 35, DG_RQ_GLOBAL_UDS */, 
  1 /* ID: 0x000003f5, Handle: 1, EcuCfg6 */, 
  2 /* ID: 0x000003eb, Handle: 2, VehCfg4 */, 
  3 /* ID: 0x000003ea, Handle: 3, VehCfg3 */, 
  4 /* ID: 0x000003e9, Handle: 4, VehCfg2 */, 
  5 /* ID: 0x000003e8, Handle: 5, VehCfg1 */, 
  6 /* ID: 0x000003e4, Handle: 6, NET_CFG_PT */, 
  7 /* ID: 0x000003e1, Handle: 7, ENG_CFG */, 
  8 /* ID: 0x000003e0, Handle: 8, VIN */, 
  9 /* ID: 0x00000381, Handle: 9, VehCfg7 */, 
  10 /* ID: 0x00000334, Handle: 10, CBC_PT1 */, 
  11 /* ID: 0x0000031f, Handle: 11, GW_LIN_I_C2 */, 
  12 /* ID: 0x00000316, Handle: 12, CFG_RQ_C */, 
  13 /* ID: 0x00000314, Handle: 13, CFG_RQ */, 
  14 /* ID: 0x00000310, Handle: 14, IC_A1 */, 
  15 /* ID: 0x00000302, Handle: 15, EPB_1 */, 
  16 /* ID: 0x000002f8, Handle: 16, ECM_A3 */, 
  17 /* ID: 0x000002a0, Handle: 17, ECM_INDICATORS */, 
  18 /* ID: 0x0000029f, Handle: 18, PTS_StrCtrl */, 
  19 /* ID: 0x00000294, Handle: 19, DST_TOC */, 
  20 /* ID: 0x00000292, Handle: 20, HALF_MTO_SteerControl */, 
  21 /* ID: 0x00000202, Handle: 21, WHEEL_SPEED_2 */, 
  22 /* ID: 0x00000200, Handle: 22, CBC_PT3 */, 
  23 /* ID: 0x00000170, Handle: 23, TRNS_STAT */, 
  24 /* ID: 0x00000158, Handle: 24, ESP_A6 */, 
  25 /* ID: 0x0000014c, Handle: 25, ESP_A4 */, 
  26 /* ID: 0x00000144, Handle: 26, TRNS_SPD */, 
  27 /* ID: 0x00000126, Handle: 27, ORC_YRS_DATA */, 
  28 /* ID: 0x00000124, Handle: 28, ESP_A5 */, 
  29 /* ID: 0x0000011c, Handle: 29, ESP_A8 */, 
  30 /* ID: 0x00000112, Handle: 30, CBC_PT2 */, 
  31 /* ID: 0x00000108, Handle: 31, ECM_A1 */, 
  32 /* ID: 0x00000102, Handle: 32, SCCM_STW_ANGL_STAT */
};
/* ROM CATEGORY 1 END */


/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanRxDataLen[kCanNumberOfRxObjects] = 
{
  8 /* ID: 0x0000044a, Handle: 0, VehCfg5 [FC] */, 
  4 /* ID: 0x000003f5, Handle: 1, EcuCfg6 [FC] */, 
  8 /* ID: 0x000003eb, Handle: 2, VehCfg4 [FC] */, 
  8 /* ID: 0x000003ea, Handle: 3, VehCfg3 [FC] */, 
  8 /* ID: 0x000003e9, Handle: 4, VehCfg2 [FC] */, 
  8 /* ID: 0x000003e8, Handle: 5, VehCfg1 [FC] */, 
  8 /* ID: 0x000003e4, Handle: 6, NET_CFG_PT [FC] */, 
  4 /* ID: 0x000003e1, Handle: 7, ENG_CFG [FC] */, 
  8 /* ID: 0x000003e0, Handle: 8, VIN [FC] */, 
  8 /* ID: 0x00000381, Handle: 9, VehCfg7 [FC] */, 
  1 /* ID: 0x00000334, Handle: 10, CBC_PT1 [FC] */, 
  7 /* ID: 0x0000031f, Handle: 11, GW_LIN_I_C2 [FC] */, 
  3 /* ID: 0x00000316, Handle: 12, CFG_RQ_C [FC] */, 
  3 /* ID: 0x00000314, Handle: 13, CFG_RQ [FC] */, 
  7 /* ID: 0x00000310, Handle: 14, IC_A1 [FC] */, 
  8 /* ID: 0x00000302, Handle: 15, EPB_1 [FC] */, 
  8 /* ID: 0x000002f8, Handle: 16, ECM_A3 [FC] */, 
  4 /* ID: 0x000002a0, Handle: 17, ECM_INDICATORS [FC] */, 
  8 /* ID: 0x0000029f, Handle: 18, PTS_StrCtrl [FC] */, 
  8 /* ID: 0x00000294, Handle: 19, DST_TOC [FC] */, 
  6 /* ID: 0x00000292, Handle: 20, HALF_MTO_SteerControl [FC] */, 
  4 /* ID: 0x00000202, Handle: 21, WHEEL_SPEED_2 [FC] */, 
  7 /* ID: 0x00000200, Handle: 22, CBC_PT3 [FC] */, 
  8 /* ID: 0x00000170, Handle: 23, TRNS_STAT [FC] */, 
  8 /* ID: 0x00000158, Handle: 24, ESP_A6 [FC] */, 
  6 /* ID: 0x0000014c, Handle: 25, ESP_A4 [FC] */, 
  3 /* ID: 0x00000144, Handle: 26, TRNS_SPD [FC] */, 
  8 /* ID: 0x00000126, Handle: 27, ORC_YRS_DATA [FC] */, 
  4 /* ID: 0x00000124, Handle: 28, ESP_A5 [FC] */, 
  8 /* ID: 0x0000011c, Handle: 29, ESP_A8 [FC] */, 
  2 /* ID: 0x00000112, Handle: 30, CBC_PT2 [FC] */, 
  8 /* ID: 0x00000108, Handle: 31, ECM_A1 [FC] */, 
  8 /* ID: 0x00000102, Handle: 32, SCCM_STW_ANGL_STAT [FC] */, 
  8 /* ID: 0x0000075a, Handle: 33, D_RQ_EPS [FC] */, 
  8 /* ID: 0x000006da, Handle: 34, APPL_ECU_EPS [FC] */, 
  8 /* ID: 0x00000441, Handle: 35, DG_RQ_GLOBAL_UDS [FC] */
};
/* ROM CATEGORY 1 END */


#ifdef C_ENABLE_COPY_RX_DATA
/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 RxDataPtr V_MEMROM2 CanRxDataPtr[kCanNumberOfRxObjects] = 
{
  (RxDataPtr)  & dbkBufferVehCfg5 /* ID: 0x0000044a, Handle: 0, VehCfg5 [FC] */, 
  (RxDataPtr)  & dbkBufferEcuCfg6 /* ID: 0x000003f5, Handle: 1, EcuCfg6 [FC] */, 
  (RxDataPtr)  & dbkBufferVehCfg4 /* ID: 0x000003eb, Handle: 2, VehCfg4 [FC] */, 
  (RxDataPtr)  & dbkBufferVehCfg3 /* ID: 0x000003ea, Handle: 3, VehCfg3 [FC] */, 
  (RxDataPtr)  & dbkBufferVehCfg2 /* ID: 0x000003e9, Handle: 4, VehCfg2 [FC] */, 
  (RxDataPtr)  & dbkBufferVehCfg1 /* ID: 0x000003e8, Handle: 5, VehCfg1 [FC] */, 
  (RxDataPtr)  & dbkBufferNET_CFG_PT /* ID: 0x000003e4, Handle: 6, NET_CFG_PT [FC] */, 
  (RxDataPtr)  & dbkBufferENG_CFG /* ID: 0x000003e1, Handle: 7, ENG_CFG [FC] */, 
  (RxDataPtr)  & dbkBufferVIN /* ID: 0x000003e0, Handle: 8, VIN [FC] */, 
  (RxDataPtr)  & dbkBufferVehCfg7 /* ID: 0x00000381, Handle: 9, VehCfg7 [FC] */, 
  (RxDataPtr)  & dbkBufferCBC_PT1 /* ID: 0x00000334, Handle: 10, CBC_PT1 [FC] */, 
  (RxDataPtr)  & dbkBufferGW_LIN_I_C2 /* ID: 0x0000031f, Handle: 11, GW_LIN_I_C2 [FC] */, 
  (RxDataPtr)  & dbkBufferCFG_RQ_C /* ID: 0x00000316, Handle: 12, CFG_RQ_C [FC] */, 
  (RxDataPtr)  & dbkBufferCFG_RQ /* ID: 0x00000314, Handle: 13, CFG_RQ [FC] */, 
  (RxDataPtr)  & dbkBufferIC_A1 /* ID: 0x00000310, Handle: 14, IC_A1 [FC] */, 
  (RxDataPtr)  & dbkBufferEPB_1 /* ID: 0x00000302, Handle: 15, EPB_1 [FC] */, 
  (RxDataPtr)  & dbkBufferECM_A3 /* ID: 0x000002f8, Handle: 16, ECM_A3 [FC] */, 
  (RxDataPtr)  & dbkBufferECM_INDICATORS /* ID: 0x000002a0, Handle: 17, ECM_INDICATORS [FC] */, 
  (RxDataPtr)  & dbkBufferPTS_StrCtrl /* ID: 0x0000029f, Handle: 18, PTS_StrCtrl [FC] */, 
  (RxDataPtr)  & dbkBufferDST_TOC /* ID: 0x00000294, Handle: 19, DST_TOC [FC] */, 
  (RxDataPtr)  & dbkBufferHALF_MTO_SteerControl /* ID: 0x00000292, Handle: 20, HALF_MTO_SteerControl [FC] */, 
  (RxDataPtr)  & dbkBufferWHEEL_SPEED_2 /* ID: 0x00000202, Handle: 21, WHEEL_SPEED_2 [FC] */, 
  (RxDataPtr)  & dbkBufferCBC_PT3 /* ID: 0x00000200, Handle: 22, CBC_PT3 [FC] */, 
  (RxDataPtr)  & dbkBufferTRNS_STAT /* ID: 0x00000170, Handle: 23, TRNS_STAT [FC] */, 
  (RxDataPtr)  & dbkBufferESP_A6 /* ID: 0x00000158, Handle: 24, ESP_A6 [FC] */, 
  (RxDataPtr)  & dbkBufferESP_A4 /* ID: 0x0000014c, Handle: 25, ESP_A4 [FC] */, 
  (RxDataPtr)  & dbkBufferTRNS_SPD /* ID: 0x00000144, Handle: 26, TRNS_SPD [FC] */, 
  (RxDataPtr)  & dbkBufferORC_YRS_DATA /* ID: 0x00000126, Handle: 27, ORC_YRS_DATA [FC] */, 
  (RxDataPtr)  & dbkBufferESP_A5 /* ID: 0x00000124, Handle: 28, ESP_A5 [FC] */, 
  (RxDataPtr)  & dbkBufferESP_A8 /* ID: 0x0000011c, Handle: 29, ESP_A8 [FC] */, 
  (RxDataPtr)  & dbkBufferCBC_PT2 /* ID: 0x00000112, Handle: 30, CBC_PT2 [FC] */, 
  (RxDataPtr)  & dbkBufferECM_A1 /* ID: 0x00000108, Handle: 31, ECM_A1 [FC] */, 
  (RxDataPtr)  & dbkBufferSCCM_STW_ANGL_STAT /* ID: 0x00000102, Handle: 32, SCCM_STW_ANGL_STAT [FC] */, 
  (RxDataPtr) 0 /* ID: 0x0000075a, Handle: 33, D_RQ_EPS [FC] */, 
  (RxDataPtr) APPL_ECU_EPS._c /* ID: 0x000006da, Handle: 34, APPL_ECU_EPS [FC] */, 
  (RxDataPtr) 0 /* ID: 0x00000441, Handle: 35, DG_RQ_GLOBAL_UDS [FC] */
};
/* ROM CATEGORY 1 END */

#endif


#ifdef C_ENABLE_PRECOPY_FCT
/* CODE CATEGORY 1 START */
/* CODE CATEGORY 1 END */

/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 ApplPrecopyFct V_MEMROM2 CanRxApplPrecopyPtr[kCanNumberOfRxObjects] = 
{
  dbkPrecopy /* ID: 0x0000044a, Handle: 0, VehCfg5 [FC] */, 
  dbkPrecopy /* ID: 0x000003f5, Handle: 1, EcuCfg6 [FC] */, 
  dbkPrecopy /* ID: 0x000003eb, Handle: 2, VehCfg4 [FC] */, 
  dbkPrecopy /* ID: 0x000003ea, Handle: 3, VehCfg3 [FC] */, 
  dbkPrecopy /* ID: 0x000003e9, Handle: 4, VehCfg2 [FC] */, 
  dbkPrecopy /* ID: 0x000003e8, Handle: 5, VehCfg1 [FC] */, 
  dbkPrecopy /* ID: 0x000003e4, Handle: 6, NET_CFG_PT [FC] */, 
  dbkPrecopy /* ID: 0x000003e1, Handle: 7, ENG_CFG [FC] */, 
  dbkPrecopy /* ID: 0x000003e0, Handle: 8, VIN [FC] */, 
  dbkPrecopy /* ID: 0x00000381, Handle: 9, VehCfg7 [FC] */, 
  dbkPrecopy /* ID: 0x00000334, Handle: 10, CBC_PT1 [FC] */, 
  dbkPrecopy /* ID: 0x0000031f, Handle: 11, GW_LIN_I_C2 [FC] */, 
  dbkPrecopy /* ID: 0x00000316, Handle: 12, CFG_RQ_C [FC] */, 
  dbkPrecopy /* ID: 0x00000314, Handle: 13, CFG_RQ [FC] */, 
  dbkPrecopy /* ID: 0x00000310, Handle: 14, IC_A1 [FC] */, 
  dbkPrecopy /* ID: 0x00000302, Handle: 15, EPB_1 [FC] */, 
  dbkPrecopy /* ID: 0x000002f8, Handle: 16, ECM_A3 [FC] */, 
  dbkPrecopy /* ID: 0x000002a0, Handle: 17, ECM_INDICATORS [FC] */, 
  dbkPrecopy /* ID: 0x0000029f, Handle: 18, PTS_StrCtrl [FC] */, 
  dbkPrecopy /* ID: 0x00000294, Handle: 19, DST_TOC [FC] */, 
  dbkPrecopy /* ID: 0x00000292, Handle: 20, HALF_MTO_SteerControl [FC] */, 
  dbkPrecopy /* ID: 0x00000202, Handle: 21, WHEEL_SPEED_2 [FC] */, 
  dbkPrecopy /* ID: 0x00000200, Handle: 22, CBC_PT3 [FC] */, 
  dbkPrecopy /* ID: 0x00000170, Handle: 23, TRNS_STAT [FC] */, 
  dbkPrecopy /* ID: 0x00000158, Handle: 24, ESP_A6 [FC] */, 
  dbkPrecopy /* ID: 0x0000014c, Handle: 25, ESP_A4 [FC] */, 
  dbkPrecopy /* ID: 0x00000144, Handle: 26, TRNS_SPD [FC] */, 
  dbkPrecopy /* ID: 0x00000126, Handle: 27, ORC_YRS_DATA [FC] */, 
  dbkPrecopy /* ID: 0x00000124, Handle: 28, ESP_A5 [FC] */, 
  dbkPrecopy /* ID: 0x0000011c, Handle: 29, ESP_A8 [FC] */, 
  dbkPrecopy /* ID: 0x00000112, Handle: 30, CBC_PT2 [FC] */, 
  dbkPrecopy /* ID: 0x00000108, Handle: 31, ECM_A1 [FC] */, 
  dbkPrecopy /* ID: 0x00000102, Handle: 32, SCCM_STW_ANGL_STAT [FC] */, 
  TpPrecopy /* ID: 0x0000075a, Handle: 33, D_RQ_EPS [FC] */, 
  XcpPreCopy /* ID: 0x000006da, Handle: 34, APPL_ECU_EPS [FC] */, 
  TpFuncPrecopy /* ID: 0x00000441, Handle: 35, DG_RQ_GLOBAL_UDS [FC] */
};
/* ROM CATEGORY 1 END */

#endif


#ifdef C_ENABLE_INDICATION_FCT
/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 ApplIndicationFct V_MEMROM2 CanRxApplIndicationPtr[kCanNumberOfRxObjects] = 
{
  V_NULL /* ID: 0x0000044a, Handle: 0, VehCfg5 [FC] */, 
  V_NULL /* ID: 0x000003f5, Handle: 1, EcuCfg6 [FC] */, 
  V_NULL /* ID: 0x000003eb, Handle: 2, VehCfg4 [FC] */, 
  V_NULL /* ID: 0x000003ea, Handle: 3, VehCfg3 [FC] */, 
  V_NULL /* ID: 0x000003e9, Handle: 4, VehCfg2 [FC] */, 
  V_NULL /* ID: 0x000003e8, Handle: 5, VehCfg1 [FC] */, 
  V_NULL /* ID: 0x000003e4, Handle: 6, NET_CFG_PT [FC] */, 
  V_NULL /* ID: 0x000003e1, Handle: 7, ENG_CFG [FC] */, 
  V_NULL /* ID: 0x000003e0, Handle: 8, VIN [FC] */, 
  V_NULL /* ID: 0x00000381, Handle: 9, VehCfg7 [FC] */, 
  V_NULL /* ID: 0x00000334, Handle: 10, CBC_PT1 [FC] */, 
  V_NULL /* ID: 0x0000031f, Handle: 11, GW_LIN_I_C2 [FC] */, 
  V_NULL /* ID: 0x00000316, Handle: 12, CFG_RQ_C [FC] */, 
  V_NULL /* ID: 0x00000314, Handle: 13, CFG_RQ [FC] */, 
  V_NULL /* ID: 0x00000310, Handle: 14, IC_A1 [FC] */, 
  V_NULL /* ID: 0x00000302, Handle: 15, EPB_1 [FC] */, 
  V_NULL /* ID: 0x000002f8, Handle: 16, ECM_A3 [FC] */, 
  V_NULL /* ID: 0x000002a0, Handle: 17, ECM_INDICATORS [FC] */, 
  V_NULL /* ID: 0x0000029f, Handle: 18, PTS_StrCtrl [FC] */, 
  V_NULL /* ID: 0x00000294, Handle: 19, DST_TOC [FC] */, 
  V_NULL /* ID: 0x00000292, Handle: 20, HALF_MTO_SteerControl [FC] */, 
  V_NULL /* ID: 0x00000202, Handle: 21, WHEEL_SPEED_2 [FC] */, 
  V_NULL /* ID: 0x00000200, Handle: 22, CBC_PT3 [FC] */, 
  V_NULL /* ID: 0x00000170, Handle: 23, TRNS_STAT [FC] */, 
  V_NULL /* ID: 0x00000158, Handle: 24, ESP_A6 [FC] */, 
  V_NULL /* ID: 0x0000014c, Handle: 25, ESP_A4 [FC] */, 
  V_NULL /* ID: 0x00000144, Handle: 26, TRNS_SPD [FC] */, 
  V_NULL /* ID: 0x00000126, Handle: 27, ORC_YRS_DATA [FC] */, 
  V_NULL /* ID: 0x00000124, Handle: 28, ESP_A5 [FC] */, 
  V_NULL /* ID: 0x0000011c, Handle: 29, ESP_A8 [FC] */, 
  V_NULL /* ID: 0x00000112, Handle: 30, CBC_PT2 [FC] */, 
  V_NULL /* ID: 0x00000108, Handle: 31, ECM_A1 [FC] */, 
  V_NULL /* ID: 0x00000102, Handle: 32, SCCM_STW_ANGL_STAT [FC] */, 
  V_NULL /* ID: 0x0000075a, Handle: 33, D_RQ_EPS [FC] */, 
  V_NULL /* ID: 0x000006da, Handle: 34, APPL_ECU_EPS [FC] */, 
  V_NULL /* ID: 0x00000441, Handle: 35, DG_RQ_GLOBAL_UDS [FC] */
};
/* ROM CATEGORY 1 END */

#endif


#ifdef C_ENABLE_INDICATION_FLAG
/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanIndicationOffset[kCanNumberOfRxObjects] = 
{
  0 /* ID: 0x0000044a, Handle: 0, VehCfg5 [FC] */, 
  0 /* ID: 0x000003f5, Handle: 1, EcuCfg6 [FC] */, 
  0 /* ID: 0x000003eb, Handle: 2, VehCfg4 [FC] */, 
  0 /* ID: 0x000003ea, Handle: 3, VehCfg3 [FC] */, 
  0 /* ID: 0x000003e9, Handle: 4, VehCfg2 [FC] */, 
  0 /* ID: 0x000003e8, Handle: 5, VehCfg1 [FC] */, 
  0 /* ID: 0x000003e4, Handle: 6, NET_CFG_PT [FC] */, 
  0 /* ID: 0x000003e1, Handle: 7, ENG_CFG [FC] */, 
  0 /* ID: 0x000003e0, Handle: 8, VIN [FC] */, 
  0 /* ID: 0x00000381, Handle: 9, VehCfg7 [FC] */, 
  0 /* ID: 0x00000334, Handle: 10, CBC_PT1 [FC] */, 
  0 /* ID: 0x0000031f, Handle: 11, GW_LIN_I_C2 [FC] */, 
  0 /* ID: 0x00000316, Handle: 12, CFG_RQ_C [FC] */, 
  0 /* ID: 0x00000314, Handle: 13, CFG_RQ [FC] */, 
  0 /* ID: 0x00000310, Handle: 14, IC_A1 [FC] */, 
  0 /* ID: 0x00000302, Handle: 15, EPB_1 [FC] */, 
  0 /* ID: 0x000002f8, Handle: 16, ECM_A3 [FC] */, 
  0 /* ID: 0x000002a0, Handle: 17, ECM_INDICATORS [FC] */, 
  0 /* ID: 0x0000029f, Handle: 18, PTS_StrCtrl [FC] */, 
  0 /* ID: 0x00000294, Handle: 19, DST_TOC [FC] */, 
  0 /* ID: 0x00000292, Handle: 20, HALF_MTO_SteerControl [FC] */, 
  0 /* ID: 0x00000202, Handle: 21, WHEEL_SPEED_2 [FC] */, 
  0 /* ID: 0x00000200, Handle: 22, CBC_PT3 [FC] */, 
  0 /* ID: 0x00000170, Handle: 23, TRNS_STAT [FC] */, 
  0 /* ID: 0x00000158, Handle: 24, ESP_A6 [FC] */, 
  0 /* ID: 0x0000014c, Handle: 25, ESP_A4 [FC] */, 
  0 /* ID: 0x00000144, Handle: 26, TRNS_SPD [FC] */, 
  0 /* ID: 0x00000126, Handle: 27, ORC_YRS_DATA [FC] */, 
  0 /* ID: 0x00000124, Handle: 28, ESP_A5 [FC] */, 
  0 /* ID: 0x0000011c, Handle: 29, ESP_A8 [FC] */, 
  0 /* ID: 0x00000112, Handle: 30, CBC_PT2 [FC] */, 
  0 /* ID: 0x00000108, Handle: 31, ECM_A1 [FC] */, 
  0 /* ID: 0x00000102, Handle: 32, SCCM_STW_ANGL_STAT [FC] */, 
  0 /* ID: 0x0000075a, Handle: 33, D_RQ_EPS [FC] */, 
  0 /* ID: 0x000006da, Handle: 34, APPL_ECU_EPS [FC] */, 
  0 /* ID: 0x00000441, Handle: 35, DG_RQ_GLOBAL_UDS [FC] */
};
/* ROM CATEGORY 1 END */


/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanIndicationMask[kCanNumberOfRxObjects] = 
{
  0x00 /* ID: 0x0000044a, Handle: 0, VehCfg5 [FC] */, 
  0x00 /* ID: 0x000003f5, Handle: 1, EcuCfg6 [FC] */, 
  0x00 /* ID: 0x000003eb, Handle: 2, VehCfg4 [FC] */, 
  0x00 /* ID: 0x000003ea, Handle: 3, VehCfg3 [FC] */, 
  0x00 /* ID: 0x000003e9, Handle: 4, VehCfg2 [FC] */, 
  0x00 /* ID: 0x000003e8, Handle: 5, VehCfg1 [FC] */, 
  0x00 /* ID: 0x000003e4, Handle: 6, NET_CFG_PT [FC] */, 
  0x00 /* ID: 0x000003e1, Handle: 7, ENG_CFG [FC] */, 
  0x00 /* ID: 0x000003e0, Handle: 8, VIN [FC] */, 
  0x00 /* ID: 0x00000381, Handle: 9, VehCfg7 [FC] */, 
  0x00 /* ID: 0x00000334, Handle: 10, CBC_PT1 [FC] */, 
  0x00 /* ID: 0x0000031f, Handle: 11, GW_LIN_I_C2 [FC] */, 
  0x00 /* ID: 0x00000316, Handle: 12, CFG_RQ_C [FC] */, 
  0x00 /* ID: 0x00000314, Handle: 13, CFG_RQ [FC] */, 
  0x00 /* ID: 0x00000310, Handle: 14, IC_A1 [FC] */, 
  0x00 /* ID: 0x00000302, Handle: 15, EPB_1 [FC] */, 
  0x00 /* ID: 0x000002f8, Handle: 16, ECM_A3 [FC] */, 
  0x00 /* ID: 0x000002a0, Handle: 17, ECM_INDICATORS [FC] */, 
  0x00 /* ID: 0x0000029f, Handle: 18, PTS_StrCtrl [FC] */, 
  0x00 /* ID: 0x00000294, Handle: 19, DST_TOC [FC] */, 
  0x00 /* ID: 0x00000292, Handle: 20, HALF_MTO_SteerControl [FC] */, 
  0x00 /* ID: 0x00000202, Handle: 21, WHEEL_SPEED_2 [FC] */, 
  0x00 /* ID: 0x00000200, Handle: 22, CBC_PT3 [FC] */, 
  0x00 /* ID: 0x00000170, Handle: 23, TRNS_STAT [FC] */, 
  0x00 /* ID: 0x00000158, Handle: 24, ESP_A6 [FC] */, 
  0x00 /* ID: 0x0000014c, Handle: 25, ESP_A4 [FC] */, 
  0x00 /* ID: 0x00000144, Handle: 26, TRNS_SPD [FC] */, 
  0x00 /* ID: 0x00000126, Handle: 27, ORC_YRS_DATA [FC] */, 
  0x00 /* ID: 0x00000124, Handle: 28, ESP_A5 [FC] */, 
  0x00 /* ID: 0x0000011c, Handle: 29, ESP_A8 [FC] */, 
  0x00 /* ID: 0x00000112, Handle: 30, CBC_PT2 [FC] */, 
  0x00 /* ID: 0x00000108, Handle: 31, ECM_A1 [FC] */, 
  0x00 /* ID: 0x00000102, Handle: 32, SCCM_STW_ANGL_STAT [FC] */, 
  0x00 /* ID: 0x0000075a, Handle: 33, D_RQ_EPS [FC] */, 
  0x01 /* ID: 0x000006da, Handle: 34, APPL_ECU_EPS [FC] */, 
  0x00 /* ID: 0x00000441, Handle: 35, DG_RQ_GLOBAL_UDS [FC] */
};
/* ROM CATEGORY 1 END */


#endif




/* -----------------------------------------------------------------------------
    &&&~ Init structures
 ----------------------------------------------------------------------------- */

/* ROM CATEGORY 4 START */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanInitObjectStartIndex[2] = 
{
  0, 
  1
};

/* ROM CATEGORY 4 END */

/* ROM CATEGORY 4 START */
V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 CanInitBRP_Reg[1] = 
{
  0x00
};
V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 CanInitBitTiming[1] = 
{
  0x3AC9
};
V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 CanInitBasicMsk1[1][1] = 
{
  
  {
    0x0000
  }
};
V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 CanInitBasicMsk2[1][1] = 
{
  
  {
    0xFF00
  }
};
V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 CanInitBasicCod1[1][1] = 
{
  
  {
    0x0000
  }
};
V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 CanInitBasicCod2[1][1] = 
{
  
  {
    0x1000
  }
};
/* ROM CATEGORY 4 END */



#if defined(C_ENABLE_MULTI_ECU_CONFIG)
/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanPhysToLogChannel[kVNumberOfIdentities][kCanNumberOfPhysChannels] = 
{
  
  {
    0
  }
};
/* ROM CATEGORY 1 END */

#endif

#if defined(C_ENABLE_MULTI_ECU_CONFIG)
/* ROM CATEGORY 2 START */

V_MEMROM0 V_MEMROM1 tVIdentityMsk V_MEMROM2 CanChannelIdentityAssignment[kCanNumberOfChannels] = 
{
  0x01
};

/* ROM CATEGORY 2 END */

#endif

#if defined(C_ENABLE_MULTI_ECU_PHYS)
/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 tVIdentityMsk V_MEMROM2 CanRxIdentityAssignment[kCanNumberOfRxObjects] = 
{
  0x01 /* ID: 0x0000044a, Handle: 0, VehCfg5 [FC] */, 
  0x01 /* ID: 0x000003f5, Handle: 1, EcuCfg6 [FC] */, 
  0x01 /* ID: 0x000003eb, Handle: 2, VehCfg4 [FC] */, 
  0x01 /* ID: 0x000003ea, Handle: 3, VehCfg3 [FC] */, 
  0x01 /* ID: 0x000003e9, Handle: 4, VehCfg2 [FC] */, 
  0x01 /* ID: 0x000003e8, Handle: 5, VehCfg1 [FC] */, 
  0x01 /* ID: 0x000003e4, Handle: 6, NET_CFG_PT [FC] */, 
  0x01 /* ID: 0x000003e1, Handle: 7, ENG_CFG [FC] */, 
  0x01 /* ID: 0x000003e0, Handle: 8, VIN [FC] */, 
  0x01 /* ID: 0x00000381, Handle: 9, VehCfg7 [FC] */, 
  0x01 /* ID: 0x00000334, Handle: 10, CBC_PT1 [FC] */, 
  0x01 /* ID: 0x0000031f, Handle: 11, GW_LIN_I_C2 [FC] */, 
  0x01 /* ID: 0x00000316, Handle: 12, CFG_RQ_C [FC] */, 
  0x01 /* ID: 0x00000314, Handle: 13, CFG_RQ [FC] */, 
  0x01 /* ID: 0x00000310, Handle: 14, IC_A1 [FC] */, 
  0x01 /* ID: 0x00000302, Handle: 15, EPB_1 [FC] */, 
  0x01 /* ID: 0x000002f8, Handle: 16, ECM_A3 [FC] */, 
  0x01 /* ID: 0x000002a0, Handle: 17, ECM_INDICATORS [FC] */, 
  0x01 /* ID: 0x0000029f, Handle: 18, PTS_StrCtrl [FC] */, 
  0x01 /* ID: 0x00000294, Handle: 19, DST_TOC [FC] */, 
  0x01 /* ID: 0x00000292, Handle: 20, HALF_MTO_SteerControl [FC] */, 
  0x01 /* ID: 0x00000202, Handle: 21, WHEEL_SPEED_2 [FC] */, 
  0x01 /* ID: 0x00000200, Handle: 22, CBC_PT3 [FC] */, 
  0x01 /* ID: 0x00000170, Handle: 23, TRNS_STAT [FC] */, 
  0x01 /* ID: 0x00000158, Handle: 24, ESP_A6 [FC] */, 
  0x01 /* ID: 0x0000014c, Handle: 25, ESP_A4 [FC] */, 
  0x01 /* ID: 0x00000144, Handle: 26, TRNS_SPD [FC] */, 
  0x01 /* ID: 0x00000126, Handle: 27, ORC_YRS_DATA [FC] */, 
  0x01 /* ID: 0x00000124, Handle: 28, ESP_A5 [FC] */, 
  0x01 /* ID: 0x0000011c, Handle: 29, ESP_A8 [FC] */, 
  0x01 /* ID: 0x00000112, Handle: 30, CBC_PT2 [FC] */, 
  0x01 /* ID: 0x00000108, Handle: 31, ECM_A1 [FC] */, 
  0x01 /* ID: 0x00000102, Handle: 32, SCCM_STW_ANGL_STAT [FC] */, 
  0x01 /* ID: 0x0000075a, Handle: 33, D_RQ_EPS [FC] */, 
  0x01 /* ID: 0x000006da, Handle: 34, APPL_ECU_EPS [FC] */, 
  0x01 /* ID: 0x00000441, Handle: 35, DG_RQ_GLOBAL_UDS [FC] */
};
/* ROM CATEGORY 1 END */

/* ROM CATEGORY 4 START */
V_MEMROM0 V_MEMROM1 tVIdentityMsk V_MEMROM2 CanTxIdentityAssignment[kCanNumberOfTxObjects] = 
{
  0x01 /* ID: 0x0000061a, Handle: 0, SD_RS_EPS [FC] */, 
  0x01 /* ID: 0x0000059a, Handle: 1, ECU_APPL_EPS [FC] */, 
  0x01 /* ID: 0x000004da, Handle: 2, D_RS_EPS [FC] */, 
  0x01 /* ID: 0x0000041a, Handle: 3, NM_EPS [BC] */, 
  0x01 /* ID: 0x00000220, Handle: 4, EPS_1 [FC] */, 
  0x01 /* ID: 0x0000012c, Handle: 5, EPS_A1 [FC] */
};
/* ROM CATEGORY 4 END */

#endif


/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanRxMinDataLen[kCanNumberOfRxObjects] = 
{
  8 /* ID: 0x0000044a, Handle: 0, VehCfg5 [FC] */, 
  4 /* ID: 0x000003f5, Handle: 1, EcuCfg6 [FC] */, 
  8 /* ID: 0x000003eb, Handle: 2, VehCfg4 [FC] */, 
  8 /* ID: 0x000003ea, Handle: 3, VehCfg3 [FC] */, 
  8 /* ID: 0x000003e9, Handle: 4, VehCfg2 [FC] */, 
  8 /* ID: 0x000003e8, Handle: 5, VehCfg1 [FC] */, 
  8 /* ID: 0x000003e4, Handle: 6, NET_CFG_PT [FC] */, 
  4 /* ID: 0x000003e1, Handle: 7, ENG_CFG [FC] */, 
  8 /* ID: 0x000003e0, Handle: 8, VIN [FC] */, 
  8 /* ID: 0x00000381, Handle: 9, VehCfg7 [FC] */, 
  1 /* ID: 0x00000334, Handle: 10, CBC_PT1 [FC] */, 
  7 /* ID: 0x0000031f, Handle: 11, GW_LIN_I_C2 [FC] */, 
  3 /* ID: 0x00000316, Handle: 12, CFG_RQ_C [FC] */, 
  3 /* ID: 0x00000314, Handle: 13, CFG_RQ [FC] */, 
  7 /* ID: 0x00000310, Handle: 14, IC_A1 [FC] */, 
  8 /* ID: 0x00000302, Handle: 15, EPB_1 [FC] */, 
  8 /* ID: 0x000002f8, Handle: 16, ECM_A3 [FC] */, 
  4 /* ID: 0x000002a0, Handle: 17, ECM_INDICATORS [FC] */, 
  8 /* ID: 0x0000029f, Handle: 18, PTS_StrCtrl [FC] */, 
  8 /* ID: 0x00000294, Handle: 19, DST_TOC [FC] */, 
  6 /* ID: 0x00000292, Handle: 20, HALF_MTO_SteerControl [FC] */, 
  4 /* ID: 0x00000202, Handle: 21, WHEEL_SPEED_2 [FC] */, 
  7 /* ID: 0x00000200, Handle: 22, CBC_PT3 [FC] */, 
  8 /* ID: 0x00000170, Handle: 23, TRNS_STAT [FC] */, 
  8 /* ID: 0x00000158, Handle: 24, ESP_A6 [FC] */, 
  6 /* ID: 0x0000014c, Handle: 25, ESP_A4 [FC] */, 
  3 /* ID: 0x00000144, Handle: 26, TRNS_SPD [FC] */, 
  8 /* ID: 0x00000126, Handle: 27, ORC_YRS_DATA [FC] */, 
  4 /* ID: 0x00000124, Handle: 28, ESP_A5 [FC] */, 
  8 /* ID: 0x0000011c, Handle: 29, ESP_A8 [FC] */, 
  2 /* ID: 0x00000112, Handle: 30, CBC_PT2 [FC] */, 
  8 /* ID: 0x00000108, Handle: 31, ECM_A1 [FC] */, 
  8 /* ID: 0x00000102, Handle: 32, SCCM_STW_ANGL_STAT [FC] */, 
  8 /* ID: 0x0000075a, Handle: 33, D_RQ_EPS [FC] */, 
  8 /* ID: 0x000006da, Handle: 34, APPL_ECU_EPS [FC] */, 
  8 /* ID: 0x00000441, Handle: 35, DG_RQ_GLOBAL_UDS [FC] */
};
/* ROM CATEGORY 1 END */

#ifdef C_ENABLE_TX_FULLCAN_OBJECTS
/* ROM CATEGORY 2 START */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanTxHwObj[kCanNumberOfTxObjects] = 
{
  0x05 /* ID: 0x0000061a, Handle: 0, SD_RS_EPS [FC] */, 
  0x04 /* ID: 0x0000059a, Handle: 1, ECU_APPL_EPS [FC] */, 
  0x03 /* ID: 0x000004da, Handle: 2, D_RS_EPS [FC] */, 
  0x02 /* ID: 0x0000041a, Handle: 3, NM_EPS [BC] */, 
  0x01 /* ID: 0x00000220, Handle: 4, EPS_1 [FC] */, 
  0x00 /* ID: 0x0000012c, Handle: 5, EPS_A1 [FC] */
};
/* ROM CATEGORY 2 END */

#endif



/* ROM CATEGORY 1 START */
/* CanHwObjIndivPolling[kCanNumberOfHwChannels][kCanNumberOfHwObjIndivPolling]; // in Polling Type == 2 Und !UsesContinuousCANObjects */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanHwObjIndivPolling[kCanNumberOfHwChannels][kCanNumberOfHwObjIndivPolling] = 
{
  
  {
    0 /* Channel0, EPS_A1 */, 
    0 /* Channel0, EPS_1 */, 
    0 /* Channel0, NM_EPS */, 
    0 /* Channel0, D_RS_EPS */, 
    0 /* Channel0, ECU_APPL_EPS */, 
    0 /* Channel0, SD_RS_EPS */, 
    0 /* Channel0, Normal Tx Polling */, 
    0 /* Unused */, 
    0 /* Unused */, 
    0 /* Unused */, 
    0 /* Unused */, 
    0 /* Unused */, 
    0 /* Unused */, 
    0 /* Unused */, 
    0 /* Unused */, 
    0 /* Unused */, 
    0 /* Unused */, 
    0 /* Unused */, 
    0 /* Unused */, 
    0 /* Unused */, 
    0 /* Unused */, 
    0 /* Unused */, 
    0 /* Unused */, 
    0 /* Unused */, 
    0 /* Unused */, 
    0 /* Unused */, 
    1 /* Channel0, D_RQ_EPS */, 
    0 /* Channel0, APPL_ECU_EPS */, 
    1 /* Channel0, VehCfg5 */, 
    1 /* Channel0, DG_RQ_GLOBAL_UDS */, 
    1 /* Channel0, EcuCfg6 */, 
    1 /* Channel0, VehCfg4 */, 
    1 /* Channel0, VehCfg3 */, 
    1 /* Channel0, VehCfg2 */, 
    1 /* Channel0, VehCfg1 */, 
    1 /* Channel0, NET_CFG_PT */, 
    1 /* Channel0, ENG_CFG */, 
    1 /* Channel0, VIN */, 
    1 /* Channel0, VehCfg7 */, 
    1 /* Channel0, CBC_PT1 */, 
    1 /* Channel0, GW_LIN_I_C2 */, 
    1 /* Channel0, CFG_RQ_C */, 
    1 /* Channel0, CFG_RQ */, 
    1 /* Channel0, IC_A1 */, 
    1 /* Channel0, EPB_1 */, 
    1 /* Channel0, ECM_A3 */, 
    1 /* Channel0, ECM_INDICATORS */, 
    1 /* Channel0, PTS_StrCtrl */, 
    1 /* Channel0, DST_TOC */, 
    1 /* Channel0, HALF_MTO_SteerControl */, 
    1 /* Channel0, WHEEL_SPEED_2 */, 
    1 /* Channel0, CBC_PT3 */, 
    1 /* Channel0, TRNS_STAT */, 
    1 /* Channel0, ESP_A6 */, 
    1 /* Channel0, ESP_A4 */, 
    1 /* Channel0, TRNS_SPD */, 
    1 /* Channel0, ORC_YRS_DATA */, 
    1 /* Channel0, ESP_A5 */, 
    1 /* Channel0, ESP_A8 */, 
    1 /* Channel0, CBC_PT2 */, 
    1 /* Channel0, ECM_A1 */, 
    1 /* Channel0, SCCM_STW_ANGL_STAT */, 
    1 /* Channel0, BasicCAN0 Rx Polling */, 
    1 /* Channel0, BasicCAN0 Rx Polling */
  }
};
/* ROM CATEGORY 1 END */


/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 103168731
      #error "The magic number of the generated file <C:\Synergy_WorkArea\ESG_Dev_65\Chrysler_LWR_EPS_TMS570-tzj9qy\Chrysler_LWR_EPS_TMS570\SwProject\Source\_GenData\can_par.c> is different. Please check time and date of generated files!"
  #endif
#else
  #error "The magic number is not defined in the generated file <C:\Synergy_WorkArea\ESG_Dev_65\Chrysler_LWR_EPS_TMS570-tzj9qy\Chrysler_LWR_EPS_TMS570\SwProject\Source\_GenData\can_par.c> "

#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

