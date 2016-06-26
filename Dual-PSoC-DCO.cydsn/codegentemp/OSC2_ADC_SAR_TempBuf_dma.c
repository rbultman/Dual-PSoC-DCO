/***************************************************************************
* File Name: OSC2_ADC_SAR_TempBuf_dma.c  
* Version 1.70
*
*  Description:
*   Provides an API for the DMAC component. The API includes functions
*   for the DMA controller, DMA channels and Transfer Descriptors.
*
*
*   Note:
*     This module requires the developer to finish or fill in the auto
*     generated funcions and setup the dma channel and TD's.
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/
#include <CYLIB.H>
#include <CYDMAC.H>
#include <OSC2_ADC_SAR_TempBuf_dma.H>



/****************************************************************************
* 
* The following defines are available in Cyfitter.h
* 
* 
* 
* OSC2_ADC_SAR_TempBuf__DRQ_CTL_REG
* 
* 
* OSC2_ADC_SAR_TempBuf__DRQ_NUMBER
* 
* Number of TD's used by this channel.
* OSC2_ADC_SAR_TempBuf__NUMBEROF_TDS
* 
* Priority of this channel.
* OSC2_ADC_SAR_TempBuf__PRIORITY
* 
* True if OSC2_ADC_SAR_TempBuf_TERMIN_SEL is used.
* OSC2_ADC_SAR_TempBuf__TERMIN_EN
* 
* TERMIN interrupt line to signal terminate.
* OSC2_ADC_SAR_TempBuf__TERMIN_SEL
* 
* 
* True if OSC2_ADC_SAR_TempBuf_TERMOUT0_SEL is used.
* OSC2_ADC_SAR_TempBuf__TERMOUT0_EN
* 
* 
* TERMOUT0 interrupt line to signal completion.
* OSC2_ADC_SAR_TempBuf__TERMOUT0_SEL
* 
* 
* True if OSC2_ADC_SAR_TempBuf_TERMOUT1_SEL is used.
* OSC2_ADC_SAR_TempBuf__TERMOUT1_EN
* 
* 
* TERMOUT1 interrupt line to signal completion.
* OSC2_ADC_SAR_TempBuf__TERMOUT1_SEL
* 
****************************************************************************/


/* Zero based index of OSC2_ADC_SAR_TempBuf dma channel */
uint8 OSC2_ADC_SAR_TempBuf_DmaHandle = DMA_INVALID_CHANNEL;

/*********************************************************************
* Function Name: uint8 OSC2_ADC_SAR_TempBuf_DmaInitalize
**********************************************************************
* Summary:
*   Allocates and initialises a channel of the DMAC to be used by the
*   caller.
*
* Parameters:
*   BurstCount.
*       
*       
*   ReqestPerBurst.
*       
*       
*   UpperSrcAddress.
*       
*       
*   UpperDestAddress.
*       
*
* Return:
*   The channel that can be used by the caller for DMA activity.
*   DMA_INVALID_CHANNEL (0xFF) if there are no channels left. 
*
*
*******************************************************************/
uint8 OSC2_ADC_SAR_TempBuf_DmaInitialize(uint8 BurstCount, uint8 ReqestPerBurst, uint16 UpperSrcAddress, uint16 UpperDestAddress) 
{

    /* Allocate a DMA channel. */
    OSC2_ADC_SAR_TempBuf_DmaHandle = (uint8)OSC2_ADC_SAR_TempBuf__DRQ_NUMBER;

    /* Configure the channel. */
    (void)CyDmaChSetConfiguration(OSC2_ADC_SAR_TempBuf_DmaHandle,
                                  BurstCount,
                                  ReqestPerBurst,
                                  (uint8)OSC2_ADC_SAR_TempBuf__TERMOUT0_SEL,
                                  (uint8)OSC2_ADC_SAR_TempBuf__TERMOUT1_SEL,
                                  (uint8)OSC2_ADC_SAR_TempBuf__TERMIN_SEL);

    /* Set the extended address for the transfers */
    (void)CyDmaChSetExtendedAddress(OSC2_ADC_SAR_TempBuf_DmaHandle, UpperSrcAddress, UpperDestAddress);

    /* Set the priority for this channel */
    (void)CyDmaChPriority(OSC2_ADC_SAR_TempBuf_DmaHandle, (uint8)OSC2_ADC_SAR_TempBuf__PRIORITY);
    
    return OSC2_ADC_SAR_TempBuf_DmaHandle;
}

/*********************************************************************
* Function Name: void OSC2_ADC_SAR_TempBuf_DmaRelease
**********************************************************************
* Summary:
*   Frees the channel associated with OSC2_ADC_SAR_TempBuf.
*
*
* Parameters:
*   void.
*
*
*
* Return:
*   void.
*
*******************************************************************/
void OSC2_ADC_SAR_TempBuf_DmaRelease(void) 
{
    /* Disable the channel */
    (void)CyDmaChDisable(OSC2_ADC_SAR_TempBuf_DmaHandle);
}

