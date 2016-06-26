/*******************************************************************************
* File Name: OSC2_Coarse.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_OSC2_Coarse_H) /* Pins OSC2_Coarse_H */
#define CY_PINS_OSC2_Coarse_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "OSC2_Coarse_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 OSC2_Coarse__PORT == 15 && ((OSC2_Coarse__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    OSC2_Coarse_Write(uint8 value);
void    OSC2_Coarse_SetDriveMode(uint8 mode);
uint8   OSC2_Coarse_ReadDataReg(void);
uint8   OSC2_Coarse_Read(void);
void    OSC2_Coarse_SetInterruptMode(uint16 position, uint16 mode);
uint8   OSC2_Coarse_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the OSC2_Coarse_SetDriveMode() function.
     *  @{
     */
        #define OSC2_Coarse_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define OSC2_Coarse_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define OSC2_Coarse_DM_RES_UP          PIN_DM_RES_UP
        #define OSC2_Coarse_DM_RES_DWN         PIN_DM_RES_DWN
        #define OSC2_Coarse_DM_OD_LO           PIN_DM_OD_LO
        #define OSC2_Coarse_DM_OD_HI           PIN_DM_OD_HI
        #define OSC2_Coarse_DM_STRONG          PIN_DM_STRONG
        #define OSC2_Coarse_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define OSC2_Coarse_MASK               OSC2_Coarse__MASK
#define OSC2_Coarse_SHIFT              OSC2_Coarse__SHIFT
#define OSC2_Coarse_WIDTH              1u

/* Interrupt constants */
#if defined(OSC2_Coarse__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in OSC2_Coarse_SetInterruptMode() function.
     *  @{
     */
        #define OSC2_Coarse_INTR_NONE      (uint16)(0x0000u)
        #define OSC2_Coarse_INTR_RISING    (uint16)(0x0001u)
        #define OSC2_Coarse_INTR_FALLING   (uint16)(0x0002u)
        #define OSC2_Coarse_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define OSC2_Coarse_INTR_MASK      (0x01u) 
#endif /* (OSC2_Coarse__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define OSC2_Coarse_PS                     (* (reg8 *) OSC2_Coarse__PS)
/* Data Register */
#define OSC2_Coarse_DR                     (* (reg8 *) OSC2_Coarse__DR)
/* Port Number */
#define OSC2_Coarse_PRT_NUM                (* (reg8 *) OSC2_Coarse__PRT) 
/* Connect to Analog Globals */                                                  
#define OSC2_Coarse_AG                     (* (reg8 *) OSC2_Coarse__AG)                       
/* Analog MUX bux enable */
#define OSC2_Coarse_AMUX                   (* (reg8 *) OSC2_Coarse__AMUX) 
/* Bidirectional Enable */                                                        
#define OSC2_Coarse_BIE                    (* (reg8 *) OSC2_Coarse__BIE)
/* Bit-mask for Aliased Register Access */
#define OSC2_Coarse_BIT_MASK               (* (reg8 *) OSC2_Coarse__BIT_MASK)
/* Bypass Enable */
#define OSC2_Coarse_BYP                    (* (reg8 *) OSC2_Coarse__BYP)
/* Port wide control signals */                                                   
#define OSC2_Coarse_CTL                    (* (reg8 *) OSC2_Coarse__CTL)
/* Drive Modes */
#define OSC2_Coarse_DM0                    (* (reg8 *) OSC2_Coarse__DM0) 
#define OSC2_Coarse_DM1                    (* (reg8 *) OSC2_Coarse__DM1)
#define OSC2_Coarse_DM2                    (* (reg8 *) OSC2_Coarse__DM2) 
/* Input Buffer Disable Override */
#define OSC2_Coarse_INP_DIS                (* (reg8 *) OSC2_Coarse__INP_DIS)
/* LCD Common or Segment Drive */
#define OSC2_Coarse_LCD_COM_SEG            (* (reg8 *) OSC2_Coarse__LCD_COM_SEG)
/* Enable Segment LCD */
#define OSC2_Coarse_LCD_EN                 (* (reg8 *) OSC2_Coarse__LCD_EN)
/* Slew Rate Control */
#define OSC2_Coarse_SLW                    (* (reg8 *) OSC2_Coarse__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define OSC2_Coarse_PRTDSI__CAPS_SEL       (* (reg8 *) OSC2_Coarse__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define OSC2_Coarse_PRTDSI__DBL_SYNC_IN    (* (reg8 *) OSC2_Coarse__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define OSC2_Coarse_PRTDSI__OE_SEL0        (* (reg8 *) OSC2_Coarse__PRTDSI__OE_SEL0) 
#define OSC2_Coarse_PRTDSI__OE_SEL1        (* (reg8 *) OSC2_Coarse__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define OSC2_Coarse_PRTDSI__OUT_SEL0       (* (reg8 *) OSC2_Coarse__PRTDSI__OUT_SEL0) 
#define OSC2_Coarse_PRTDSI__OUT_SEL1       (* (reg8 *) OSC2_Coarse__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define OSC2_Coarse_PRTDSI__SYNC_OUT       (* (reg8 *) OSC2_Coarse__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(OSC2_Coarse__SIO_CFG)
    #define OSC2_Coarse_SIO_HYST_EN        (* (reg8 *) OSC2_Coarse__SIO_HYST_EN)
    #define OSC2_Coarse_SIO_REG_HIFREQ     (* (reg8 *) OSC2_Coarse__SIO_REG_HIFREQ)
    #define OSC2_Coarse_SIO_CFG            (* (reg8 *) OSC2_Coarse__SIO_CFG)
    #define OSC2_Coarse_SIO_DIFF           (* (reg8 *) OSC2_Coarse__SIO_DIFF)
#endif /* (OSC2_Coarse__SIO_CFG) */

/* Interrupt Registers */
#if defined(OSC2_Coarse__INTSTAT)
    #define OSC2_Coarse_INTSTAT            (* (reg8 *) OSC2_Coarse__INTSTAT)
    #define OSC2_Coarse_SNAP               (* (reg8 *) OSC2_Coarse__SNAP)
    
	#define OSC2_Coarse_0_INTTYPE_REG 		(* (reg8 *) OSC2_Coarse__0__INTTYPE)
#endif /* (OSC2_Coarse__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_OSC2_Coarse_H */


/* [] END OF FILE */
