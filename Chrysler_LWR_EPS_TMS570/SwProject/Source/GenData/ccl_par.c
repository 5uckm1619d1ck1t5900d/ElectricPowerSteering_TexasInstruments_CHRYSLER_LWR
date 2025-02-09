/* -----------------------------------------------------------------------------
  Filename:    ccl_par.c
  Description: Toolversion: 01.00.35.01.21.00.21.01.00.00
               
               Serial Number: CBD1210021
               Customer Info: Nexteer
                              Package: CBD_Chrysler_SLP1_UDS_Sgl
                              Micro: TexasInstruments TMS570 - TMX570LS0805APGEQQ1
                              Compiler: Texas Instruments 4.9.5
               
               
               Generator Fwk   : GENy 
               Generator Module: Ccl__core
               
               Configuration   : C:\ccm_wa\EPS\570\LWR\Chrysler_LWR_EPS_TMS570\Tools\AsrProject\GENy\Chrsyler_SLP1_EPS.gny
               
               ECU: 
                       TargetSystem: Hw_Tms470/570Cpu (Dcan)
                       Compiler:     TexasInstruments
                       Derivates:    TMS570PSFC66
               
               Channel "Channel0":
                       Databasefile: C:\cmsynergy\My_ePWM_LWR\Chrysler_LWR_EPS_TMS570\Tools\AsrProject\GENy\CAN C v1313 15LXMod.dbc
                       Bussystem:    CAN
                       Manufacturer: DaimlerChrysler
                       Node:         EPS

  Generated by , 2013-08-07  13:44:22
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

#define CCL_PAR_MODULE
#include "ccl_par.h"

/******************************************************************************/
/* external declarations (ROM const)                                          */
/******************************************************************************/
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 cclNmWakeUpAble = 0x1;   /* The variable store the wake up able channels (one bit per channel). */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 cclStartIndex[]={    0
};

V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 cclStopIndex[]={    0
};
/******************************************************************************/
/* global data definitions                                                    */
/******************************************************************************/
/***************************************************************************** 
| NAME:             CclInitPowerOnFct                                          
| PROTOTYPE:        void CclInitPowerOnFct( void )                             
| CALLED BY:        CclInitPowerOn                                             
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!          
| INPUT PARAMETERS: void                                                       
| RETURN VALUE:     void                                                       
| DESCRIPTION:      This function is a generated init container function. It   
|                   contains different init routines depending on the          
|                   used modules.                                              
|*****************************************************************************/

void CclInitPowerOnFct(void)
{

  XcpInit();
  #if defined(C_SINGLE_RECEIVE_CHANNEL) || defined(C_MULTIPLE_RECEIVE_CHANNEL)
    CanInitPowerOn();
  #else
    CanInitPowerOn(0);
  #endif
  dbkInit();
  NmOsekInit(NM_CANSLEEP);
  TpInitPowerOn();
  DescInitPowerOn(kDescPowerOnInitParam);
#if( kFrfmNumConfigs > 1 )
  FrfmInitPowerOn((t_FrfmNumConfigs)0);
#else
  FrfmInitPowerOn();
#endif
  DpmInitPowerOn();
}
/***************************************************************************** 
| NAME:             CclInitFct                                                 
| PROTOTYPE:        void CclInitFct( void )                                    
| CALLED BY:        CclInit                                                    
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!          
| INPUT PARAMETERS: void                                                       
| RETURN VALUE:     void                                                       
| DESCRIPTION:      This function is a generated init container function. It   
|                   contains different init routines depending on the          
|                   used modules.                                              
|*****************************************************************************/

void CclInitFct(void)
{
  ApplCclInit();
}

/**************************************************************************************
| NAME:             CclSystemShutdownFct                                               
| PROTOTYPE:        void CclSystemShutdownFct( void )                                  
| CALLED BY:        CclSystemShutdown                                                  
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!                  
| INPUT PARAMETERS: void                                                               
| RETURN VALUE:     void                                                               
| DESCRIPTION:      This function is a generated system shutdown  container            
|                   function. It could be used to stop services or deinitialize        
|                   variables after the system leave the "normal" mode.              
|*************************************************************************************/

void CclSystemShutdownFct(void) 
{ 
}
/**********************************************************************************
| NAME:             CclPollingTask                                                 
| PROTOTYPE:        void CclPollingTask( void )                                    
| CALLED BY:        Application or operating system                                
| PRECONDITIONS:    looptime < callcycle                                           
| INPUT PARAMETERS: void                                                           
| RETURN VALUE:     void                                                           
| DESCRIPTION:      This function is a generated polling task container. It        
|                   contains different cyclic routines                             
|                   depending on the used modules.                                 
|*********************************************************************************/
void CCL_API_CALL_TYPE CclPollingTask (void)
{ 
  CanTask();
}
/*********************************************************************************************** 
| NAME:             Ccl_2_0msTaskCont    
| PROTOTYPE:        void Ccl_2_0msTaskCont( void ) 
| CALLED BY:        task handler                                                                 
| PRECONDITIONS:                                                                                 
| INPUT PARAMETERS: void                                                                         
| RETURN VALUE:     void                                                                         
| DESCRIPTION:      This function is a generated <x> ms task container                           
|                   function. It contains different cyclic routines                              
|                   depending on the used modules.                                               
|***********************************************************************************************/
void CCL_API_CALL_TYPE Ccl_2_0msTaskCont(void) 
{ 
  dbkTxTask();

}


/*********************************************************************************************** 
| NAME:             Ccl_10_0msTaskCont    
| PROTOTYPE:        void Ccl_10_0msTaskCont( void ) 
| CALLED BY:        task handler                                                                 
| PRECONDITIONS:                                                                                 
| INPUT PARAMETERS: void                                                                         
| RETURN VALUE:     void                                                                         
| DESCRIPTION:      This function is a generated <x> ms task container                           
|                   function. It contains different cyclic routines                              
|                   depending on the used modules.                                               
|***********************************************************************************************/
void CCL_API_CALL_TYPE Ccl_10_0msTaskCont(void) 
{ 
  dbkRxTask();

   TpRxTask();

   TpTxTask();

  NmBasicTask(); /* Nexteer Patch for convience of scheduling NmBasicTask along with the other ComStack cyclic functions, NmBasicTask scheduling is not currently generated by Ccl */
  
  NmTask();
  
  DescTimerTask(); /* Nexteer Patch to separate cycle critical Timing in DescTimerTask from service Handler in DescStateTask */

}


/*********************************************************************************************** 
| NAME:             Ccl_20_0msTaskCont    
| PROTOTYPE:        void Ccl_20_0msTaskCont( void ) 
| CALLED BY:        task handler                                                                 
| PRECONDITIONS:                                                                                 
| INPUT PARAMETERS: void                                                                         
| RETURN VALUE:     void                                                                         
| DESCRIPTION:      This function is a generated <x> ms task container                           
|                   function. It contains different cyclic routines                              
|                   depending on the used modules.                                               
|***********************************************************************************************/
void CCL_API_CALL_TYPE Ccl_20_0msTaskCont(void) 
{ 
  DpmTask();
  CclTask();

}


/*********************************************************************************************** 
| NAME:             Ccl_10_2msTaskCont    
| PROTOTYPE:        void Ccl_10_2msTaskCont( void ) 
| CALLED BY:        task handler                                                                 
| PRECONDITIONS:                                                                                 
| INPUT PARAMETERS: void                                                                         
| RETURN VALUE:     void                                                                         
| DESCRIPTION:      This function is a generated <x> ms task container                           
|                   function. It contains different cyclic routines                              
|                   depending on the used modules.                                               
|***********************************************************************************************/
void CCL_API_CALL_TYPE Ccl_10_2msTaskCont(void) 
{ 
  DescStateTask();  /* Nexteer Patch to separate cycle critical Timing in DescTimerTask from service Handler in DescStateTask */

  FrfmTask();

}

/******************************************************************************
| NAME:             CclComStart                                                
| PROTOTYPE:        void CclComStart(void)                                  
| CALLED BY:        network management                                         
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!          
| INPUT PARAMETERS:                                                            
| RETURN VALUE:     void                                                       
| DESCRIPTION:      This function start the communication with DBKOM.
|*****************************************************************************/
void CclComStart(void)
{
  cclComSwState[0]=kCclComSwOn;
  dbkTxStart();
  dbkRxStart();
}
/******************************************************************************
| NAME:             CclComStop                                                 
| PROTOTYPE:        void CclComStop(void)                                      
| CALLED BY:        network management                                         
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!          
| INPUT PARAMETERS:                                                            
| RETURN VALUE:     void                                                       
| DESCRIPTION:      This function stop the communication with DBKOM.
|*****************************************************************************/
void CclComStop(void)
{
  dbkTxStop();
  dbkRxStop();
  cclComSwState[0]=kCclComSwOff;
  ApplCclComStop();
}
/******************************************************************************
| NAME:             CclBusOffStart                                             
| PROTOTYPE:        void CclBusOffStart(void)                                  
| CALLED BY:        network management                                         
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!          
| INPUT PARAMETERS:                                          ,                 
| RETURN VALUE:     void                                                       
| DESCRIPTION:      This function stops the communication with DBKOM.
|*****************************************************************************/
void CclBusOffStart(void)
{
  dbkTxStop();
  #if defined( CCL_ENABLE_STOP_TIMEOUT)
    dbkRxStop();
  #endif
  ApplCclBusOffStart();
}
/******************************************************************************
| NAME:             CclBusOffEnd                                               
| PROTOTYPE:        void CclBusOffEnd(void)                                    
| CALLED BY:        network management                                         
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!          
| INPUT PARAMETERS:                                                            
| RETURN VALUE:     void                                                       
| DESCRIPTION:      This function starts the communication with DBKOM.
|*****************************************************************************/
void CclBusOffEnd(void)

{
  dbkTxStart();
  #if defined( CCL_ENABLE_STOP_TIMEOUT)
    dbkRxStart();
  #endif
  ApplCclBusOffEnd();
}
/**********************************************************************************
| NAME:             CclNmActiveReqFct                                              
| PROTOTYPE:        vuint8 CclNmActiveReqFct( vuint8 network )                     
| CALLED BY:        CclTask                                                        
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!              
| INPUT PARAMETERS: vuint8 network                                                 
| RETURN VALUE:     vuint8                                                         
| DESCRIPTION:      This function contains the algorithm to go in the active       
|                   mode. The algorithm depends on the used modules.               
|*********************************************************************************/

vuint8 CclNmActiveReqFct(vuint8 network)
{
#if defined V_ENABLE_USE_DUMMY_STATEMENT
  network = network;

#endif
  GotoMode(Awake);
  return NM_OK;
}
/***********************************************************************************
| NAME:             CclNmPrepareSleepReqFct                                          
| PROTOTYPE:        void CclNmPrepareSleepReqFct( void )                             
| CALLED BY:        CclTask                                                          
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!                
| INPUT PARAMETERS: void                                                             
| RETURN VALUE:     void                                                             
| DESCRIPTION:      This function contains the algorithm to set the system in        
|                   prepare sleep mode. The algorithm depends on the used            
|                   modules.                                                         
|***********************************************************************************/

void CclNmPrepareSleepReqFct(void)
{
  GotoMode(Awake);
}
/***********************************************************************************
| NAME:             CclNmSleepReqFct                                                
| PROTOTYPE:        void CclNmSleepReqFct( vuint8 network )                         
| CALLED BY:        CclRelNetRequest                                                
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!               
| INPUT PARAMETERS: vuint8 network                                                  
| RETURN VALUE:     void                                                            
| DESCRIPTION:      This function contains the algorithm to go in the sleep         
|                   mode. The algorithm depends on the used modules.                
|**********************************************************************************/
void CclNmSleepReqFct(vuint8 network)
{
#if defined V_ENABLE_USE_DUMMY_STATEMENT
  network = network;

#endif
   GotoMode(BusSleep);
}
/********************************************************************************
| NAME:             CclExtEmcComReqFct                                              
| PROTOTYPE:        void CclExtEmcComReqFct(void)                                   
| CALLED BY:        ApplCanWakeUp,                                               
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!            
| INPUT PARAMETERS: void                                                         
| RETURN VALUE:     void                                                         
| DESCRIPTION:      This function sets a communication flag. This flag is        
|                   used to synchronize the state requests between CCL           
|                   and higher layer component.                                  
|*******************************************************************************/

void CclExtEmcComReqFct(void)
{
  ApplCclSetExtEmcComReq();
}
/********************************************************************************
| NAME:             CclExtCanComReqFct                                              
| PROTOTYPE:        void CclExtCanComReqFct(void)                                   
| CALLED BY:        ApplCanWakeUp,                                               
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!            
| INPUT PARAMETERS: void                                                         
| RETURN VALUE:     void                                                         
| DESCRIPTION:      This function sets a communication flag. This flag is        
|                   used to synchronize the state requests between CCL           
|                   and higher layer component.                                             
|*******************************************************************************/

void CclExtCanComReqFct(void)
{
  ApplCclSetExtCanComReq();
}
/********************************************************************************
| NAME:             CclIntComReqFct                                              
| PROTOTYPE:        void CclIntComReqFct(void)                                   
| CALLED BY:        CclRequestNetwork                                            
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!            
| INPUT PARAMETERS: void                                                         
| RETURN VALUE:     void                                                         
| DESCRIPTION:      This function sets a communication flag. This flag is        
|                   used to synchronize the state requests between CCL           
|                   and higher layer component.                                             
|*******************************************************************************/

void CclIntComReqFct(void)
{
  ApplCclSetIntComReq();
}
/********************************************************************************
| NAME:             CclComRelFct                                            
| PROTOTYPE:        void CclComRelFct(void)                                 
| CALLED BY:        ApplNmCanSleep                                               
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!            
| INPUT PARAMETERS: void                                                         
| RETURN VALUE:     void                                                         
| DESCRIPTION:      This function clears a communication flag. This flag are     
|                   used to synchronize the state requests between CCL           
|                   and higher layer component.                                             
|*******************************************************************************/

void CclComRelFct(void)
{
  ApplCclClearComReq();
}

/********************************************************************************
| NAME:             CclInitTrcvFct                                              
| PROTOTYPE:        void CclInitTrcvFct( void )                                 
| CALLED BY:        CclInitPortsPowerOn                                          
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!            
| INPUT PARAMETERS: void                                                         
| RETURN VALUE:     void                                                         
| DESCRIPTION:      This function contains the transceiver init routine.         
|                   The routine depends on the used transceiver type.            
|*******************************************************************************/

void CclInitTrcvFct(void)
{
  ApplCclInitTrcv();
}
/************************************************************************************
| NAME:             CclWakeUpTrcvFct                                                
| PROTOTYPE:        void CclWakeUpTrcvFct( void )                                   
| CALLED BY:        ApplNmCanNormal                                                  
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!                
| INPUT PARAMETERS: void                                                             
| RETURN VALUE:     void                                                             
| DESCRIPTION:      This function contains the routine to wakeup the                 
|                   transceiver. The routine depends on the used transceiver         
|                   type.                                                            
|***********************************************************************************/

void CclWakeUpTrcvFct(void)
{ 
  ApplCclWakeUpTrcv();
}
/************************************************************************************
| NAME:             CclSleepTrcvFct                                                 
| PROTOTYPE:        void CclSleepTrcvFct( void )                                    
| CALLED BY:        ApplNmCanSleep                                                   
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!                
| INPUT PARAMETERS: void                                                             
| RETURN VALUE:     void                                                             
| DESCRIPTION:      This function contains the routine to switch the                 
|                   transceiver into sleep mode. The routine depends on              
|                   the used transceiver type.                                       
|***********************************************************************************/

void CclSleepTrcvFct(void)
{
  ApplCclStandbyTrcv();
}






/**********************************************************************************
| NAME:             CclNmStateCheckFct                                           
| PROTOTYPE:        vuint8 CclNmActiveReqFct( void )                               
| CALLED BY:        CclSystemShutdown                                              
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!              
| INPUT PARAMETERS: void                                                           
| RETURN VALUE:     kCclNmNotInSleep: means network management is not in sleep mode
|                   kCclNmInSleep   : means network management is in sleep mode    
| DESCRIPTION:      This function check if the network management in sleep mode.   
|*********************************************************************************/

vuint8 CclNmStateCheckFct(void)
{
  vuint8 retState;
  vuint8 actNmState;
  NmStatusType nmState;

  retState = (vuint8)kCclNmNotInSleep;
  nmState = NmGetStatus();
  actNmState = (vuint8)NmStateBusSleep(nmState);

  if(actNmState == (vuint8)kCclNmInSleep)
  {
    retState = (vuint8)kCclNmInSleep;
  }
  return retState;
}



/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 103168731
      #error "The magic number of the generated file <C:\Synergy\Chrysler_LWR_EPS_TMS570-zz4r1x\Chrysler_LWR_EPS_TMS570\SwProject\Source\_GenData\ccl_par.c> is different. Please check time and date of generated files!"
  #endif
#else
  #error "The magic number is not defined in the generated file <C:\Synergy\Chrysler_LWR_EPS_TMS570-zz4r1x\Chrysler_LWR_EPS_TMS570\SwProject\Source\_GenData\ccl_par.c> "

#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

