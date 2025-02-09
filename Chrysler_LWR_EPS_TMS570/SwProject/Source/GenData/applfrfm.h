/* -----------------------------------------------------------------------------
  Filename:     applfrfm.h
  Description:  Toolversion: 01.00.35.01.21.00.21.01.00.00
                
                Serial Number: CBD1210021
                Customer Info: Nexteer
                               Package: CBD_Chrysler_SLP1_UDS_Sgl
                               Micro: TexasInstruments TMS570 - TMX570LS0805APGEQQ1
                               Compiler: Texas Instruments 4.9.5
                Manufacturer : Chrysler (Car)
                
                Configuration: C:\Synergy\Chrysler_LWR_EPS_TMS570-zz4r1x\Chrysler_LWR_EPS_TMS570\Tools\AsrProject\GENy\EPS_PN_4102_EI1555.cdi
                
                
                Interface towards the application used by Frfm (callbacks).

  Generated by  DtcGen v3.20.1 (2012-08-17)  at:  2012-12-07 14:41:20 -05:00
 ----------------------------------------------------------------------------- */
/* -----------------------------------------------------------------------------
  C O P Y R I G H T
 -------------------------------------------------------------------------------
  Copyright (c) 2004-2012 by Vector Informatik GmbH. All rights reserved.
 
  This software is copyright protected and proprietary to Vector Informatik 
  GmbH.
  
  Vector Informatik GmbH grants to you only those rights as set out in the 
  license conditions.
  
  All other rights remain with Vector Informatik GmbH.
 -------------------------------------------------------------------------------
 ----------------------------------------------------------------------------- */

#if !defined(__APPLFRFM_H__)
#define __APPLFRFM_H__

/* -----------------------------------------------------------------------------
    &&&~ Includes
 ----------------------------------------------------------------------------- */

#if !defined(__FRFM_H__)
# error "Include sequence error! You must include frfm.h before applfrfm.h ."
#endif




/* -----------------------------------------------------------------------------
    &&&~ Preprocessor constants (defines)
 ----------------------------------------------------------------------------- */

/* This magic number provides inter Frfm generation process consistency check.All Frfm files must have the same one. */
#define FRFM_APPL_INTERFACE_MAGIC_NUMBER                               31611


/* -----------------------------------------------------------------------------
    &&&~ Function prototypes
 ----------------------------------------------------------------------------- */

/*
** Following callbacks have to be implemented in the application
** Here are the prototypes:
*/

#if defined (FRFM_ENABLE_DEBUG_MODE)
/*******************************************************************************
* NAME:              ApplFrfmFatalError
*
* CALLED BY:         several internal functions
* PRECONDITIONS:     GENy feature active: Support Debug Mode (Assertions)
*                    
* DESCRIPTION:       This function catches assertions in the FRFM. It is called with
*                    a reason for the assertion (see frfm.h 'Debug codes') and the
*                    source code line (in frfm.c) that caused the assertion.
*                    This function shall not return.
*******************************************************************************/
void            ApplFrfmFatalError(vuint8 errorCode, vuint16 line);
#endif


/*******************************************************************************
* NAME:              ApplFrfmGetAddEnvData
*
* CALLED BY:         FrfmSetEventStatus, FrfmDebounceEventFailed, FrfmDebounceEventPassed
* PRECONDITIONS:     -
*                    
* DESCRIPTION:       This function is called by the FRFM software module when additional data shall be stored with a
*                    fault record and needs therefore be implemented by the external application. This function shall
*                    copy the requested set of environmental data to the buffer defined by the
*                    chronoStackAddEnvData pointer.
*                    The supported sets of data have to be defined during system design and then implemented in this
*                    function. If an unsupported data set has been requested or the maximum size is too small for the
*                    requested set of environmental data the function shall return 'kFrfmFailed'.
*                    If the data has been copied successfully to the buffer, the function shall return 'kFrfmSuccess'.
*******************************************************************************/
vuint8          ApplFrfmGetAddEnvData(vuint16 recordNumber, vuint8* chronoStackAddEnvData, vuint8 envDataSize);

/*******************************************************************************
* NAME:              ApplFrfmGetOdometerValue
*
* CALLED BY:         FrfmSetEventStatus, FrfmDebounceEventFailed, FrfmDebounceEventPassed,
*                    FrfmUpdateInterrogationRecord, FrfmClearHistoricalData and all EnableCondition related functions 
* PRECONDITIONS:     -
*                    
* DESCRIPTION:       Service of the application for updating the odometer value in the FRFM. This service is executed
*                    by the FRFM to retrieve the current value when this value is required by internal functionality.
*                    Return value t_FrfmOdometer:
*                    The current odometer value of the system. Resolution: 16km/bit.
*                      0 ... 0xFFFE   Set this odometer value.
*                      0xFFFF         No odometer value available (Default).
*******************************************************************************/
t_FrfmOdometer  ApplFrfmGetOdometerValue(void);

#if defined (FRFM_ENABLE_APPL_ENABLECOND)
/*******************************************************************************
* NAME:              ApplFrfmCheckOfApplEnableCond
*
* CALLED BY:         FrfmSetEventStatus, FrfmDebounceEventFailed, FrfmDebounceEventPassed, FrfmGetEnableConditions
* PRECONDITIONS:     -
*                    
* DESCRIPTION:       When processing enable condition checks, the FRFM asks the application for additional enable
*                    conditions by calling this function.
*                    By returning frfmFalse the application prohibits the storage/update of a DTC in the ChronoStack.
*                    A frfmTrue result will not automatically allow the storage/update as other enable conditions are
*                    consulted, too.
*                    Return value t_FrfmBool:
*                      frfmTrue Application enable condition is set to enabled.
*                      frfmFalse Application enable condition is set to disabled.
*******************************************************************************/
t_FrfmBool      ApplFrfmCheckOfApplEnableCond(t_FrfmDtcSfnType dtcSfn);
#endif

#if defined (FRFM_ENABLE_CLEAR_DTC_NOTIFY)
/*******************************************************************************
* NAME:              ApplFrfmDtcWillBeCleared
*
* CALLED BY:         FrfmClearDTC
* PRECONDITIONS:     -
*                    
* DESCRIPTION:       FRFM notifies the Application about the deletion of a specific DTC (group).
*                    Before calling this function the FRFM has checked that the DTC is supported.
*******************************************************************************/
void            ApplFrfmDtcWillBeCleared(t_FrfmDtcNumType toBeDeletedDtcCode);
#endif

#if defined (FRFM_ENABLE_CLEAR_DTC_NOTIFY)
/*******************************************************************************
* NAME:              ApplFrfmDtcWasCleared
*
* CALLED BY:         FrfmClearDTC
* PRECONDITIONS:     -
*                    
* DESCRIPTION:       FRFM notifies the Application that the deletion of a specific DTC (group) has finished.
*                    The API is the twin of ApplFrfmDtcWillBeCleared, and will be called at end of the clear request.
*******************************************************************************/
void            ApplFrfmDtcWasCleared(t_FrfmDtcNumType deletedDtcCode);
#endif

/*******************************************************************************
* NAME:              ApplFrfmOnDtcStatusChange
*
* CALLED BY:         FrfmClearDTC, FrfmTask, FrfmSetEventStatus, FrfmDebounceEventFailed, FrfmDebounceEventPassed
* PRECONDITIONS:     -
*                    
* DESCRIPTION:       FRFM notifies the Application about a DTC change. A change occurs when
*                    - DTC status is changed
*                    - A DTC is removed from the ChronoStack
*                    - A DTC is cleared by external request
*                    No notifications are given, if the whole ChronoStack is initialized.
*******************************************************************************/
void            ApplFrfmOnDtcStatusChange(t_FrfmDtcNumType dtcNum, t_FrfmDtcStatusByte oldDtcStatus, t_FrfmDtcStatusByte newDtcStatus);

#if defined (FRFM_ENABLE_APPL_CLEARDIAGINFO)
/*******************************************************************************
* NAME:              ApplFrfmCheckClearDTC
*
* CALLED BY:         FrfmClearDTC
* PRECONDITIONS:     GENy feature active: Application callback for 'ClearDiagnosticInformation'
*                    
* DESCRIPTION:       Before clearing a DTC or DTC group the function FrfmClearDTC() triggers this callback function.
*                    If this callback results frfmFalse, function FrfmClearDTC() will abort the clearing with return
*                    code frfmRC_Failed. Typically this will abort the current diagnostic service request 0x14 with the
*                    negative return code 0x22 (ConditionsNotCorrect).
*                    Return value t_FrfmBool: Permission to delete the requested (range of) DTC(s)
*                      frfmTrue   DTC shall be cleared.
*                      frfmFalse  DTC must not be cleared.
*******************************************************************************/
t_FrfmBool      ApplFrfmCheckClearDTC(t_FrfmDtcNumType reqDtc);
#endif

#if defined (FRFM_ENABLE_APPL_CLEAR_HISTDATA)
/*******************************************************************************
* NAME:              ApplFrfmCheckIsVinOrigLocked
*
* CALLED BY:         FrfmClearHistoricalData
* PRECONDITIONS:     GENy feature active: Application callback 'Clear Historical Data'
*                    
* DESCRIPTION:       Check if the Historical Stack and the Historical Interrogation Record is erasable
*                    (e.g. when the VIN Original is not locked)
*                    Result codes:
*                      frfmTrue:    the historical data will NOT be erasable.
*                      frfmFalse:   the historical data will be erasable.
*******************************************************************************/
t_FrfmBool      ApplFrfmCheckIsVinOrigLocked(void);
#endif




/* -----------------------------------------------------------------------------
    &&&~ ROM definitions
 ----------------------------------------------------------------------------- */





#endif /* __APPLFRFM_H__ */
