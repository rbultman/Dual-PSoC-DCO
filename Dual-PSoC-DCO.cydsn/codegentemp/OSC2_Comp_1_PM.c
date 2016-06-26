/*******************************************************************************
* File Name: OSC2_Comp_1.c
* Version 2.0
*
* Description:
*  This file provides the power management source code APIs for the
*  Comparator.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "OSC2_Comp_1.h"

static OSC2_Comp_1_backupStruct OSC2_Comp_1_backup;


/*******************************************************************************
* Function Name: OSC2_Comp_1_SaveConfig
********************************************************************************
*
* Summary:
*  Save the current user configuration
*
* Parameters:
*  void:
*
* Return:
*  void
*
*******************************************************************************/
void OSC2_Comp_1_SaveConfig(void) 
{
    /* Empty since all are system reset for retention flops */
}


/*******************************************************************************
* Function Name: OSC2_Comp_1_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
********************************************************************************/
void OSC2_Comp_1_RestoreConfig(void) 
{
    /* Empty since all are system reset for retention flops */    
}


/*******************************************************************************
* Function Name: OSC2_Comp_1_Sleep
********************************************************************************
*
* Summary:
*  Stop and Save the user configuration
*
* Parameters:
*  void:
*
* Return:
*  void
*
* Global variables:
*  OSC2_Comp_1_backup.enableState:  Is modified depending on the enable 
*   state of the block before entering sleep mode.
*
*******************************************************************************/
void OSC2_Comp_1_Sleep(void) 
{
    /* Save Comp's enable state */    
    if(OSC2_Comp_1_ACT_PWR_EN == (OSC2_Comp_1_PWRMGR & OSC2_Comp_1_ACT_PWR_EN))
    {
        /* Comp is enabled */
        OSC2_Comp_1_backup.enableState = 1u;
    }
    else
    {
        /* Comp is disabled */
        OSC2_Comp_1_backup.enableState = 0u;
    }    
    
    OSC2_Comp_1_Stop();
    OSC2_Comp_1_SaveConfig();
}


/*******************************************************************************
* Function Name: OSC2_Comp_1_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  OSC2_Comp_1_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void OSC2_Comp_1_Wakeup(void) 
{
    OSC2_Comp_1_RestoreConfig();
    
    if(OSC2_Comp_1_backup.enableState == 1u)
    {
        /* Enable Comp's operation */
        OSC2_Comp_1_Enable();

    } /* Do nothing if Comp was disabled before */ 
}


/* [] END OF FILE */
