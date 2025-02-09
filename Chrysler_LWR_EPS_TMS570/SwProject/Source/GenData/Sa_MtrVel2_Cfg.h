
/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Sa_MtrVel2_Cfg.h
* Module Description: Configuration file of DiagMgr module
* Product           : Gen II Plus - EA3.0
* Generator         : artt 2.0.2.0
* Generation Time   : 17.07.2013 15:43:02
*****************************************************************************/
/* Version Control:
 * Date Created:      Fri Jul 13 18:34:17 2012
 * %version:          4 %
 * %date_modified:    Thu Jul 18 10:30:27 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 09/20/12   1       ssk       Initial template creation
 * 	 	
 */

#ifndef SA_MTRVEL2_CFG_H
#define SA_MTRVEL2_CFG_H


/*******************************************************************************
**                      Define Section                                       **
*******************************************************************************/

/* MtrVel2_Per1_CP0 Checkpoint is enabled */
/* MtrVel2_Per2_CP0 Checkpoint is enabled */

/* Disable all checkpoints that are not enabled */
#define Rte_Call_MtrVel2_Per1_CP1_CheckpointReached()		(void)0 /* Checkpoint disabled */	 
#define Rte_Call_MtrVel2_Per2_CP1_CheckpointReached()		(void)0 /* Checkpoint disabled */	 
   
#endif /* MTRVEL2_CFG_H */

/*** End of file **************************************************************/
