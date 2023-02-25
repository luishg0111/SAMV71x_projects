/****************************************************************************************************/
/**
\file       led_ctrl.h
\brief      MCU abstraction level - LED control
\author     Abraham Tezmol
\version    1.0
\project    Tau 
\date       24/June/2016
*/
/****************************************************************************************************/

#ifndef __LED_CTRL_H        /*prevent duplicated includes*/
#define __LED_CTRL_H

/*****************************************************************************************************
* Include files
*****************************************************************************************************/

/** Core modules */
#include "compiler.h"

/** Used modules */

/*****************************************************************************************************
* Declaration of module wide TYPEs 
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of module wide MACROs / #DEFINE-CONSTANTs 
*****************************************************************************************************/
#define LEDCTRL_LED0    (uint32_t)0u
#define LEDCTRL_LED1    (uint32_t)1u

/*****************************************************************************************************
* Declaration of module wide FUNCTIONS
*****************************************************************************************************/

/** Configures LED 0 and 1 of SAMV71 board */
void LEDCTRL_v_Configure( void );

/** Turn a combination of 2 LEDs with a unique blinking pattern */
void LEDCTRL_v_BlinkingPattern( void );

/** Turn a combination of 2 LEDs with a unique blinking pattern */
void LEDCTRL_v_BlinkingLEDx( uint32_t ui32_LED );

void LEDCTRL_v_BlinkingLED0( void );

void LEDCTRL_v_BlinkingLED1( void );

/** Turn static any of 2 LEDs */
void LEDCTRL_v_StaticLEDx( uint32_t ui32_LED );

void LEDCTRL_v_StaticLED0( void );

void LEDCTRL_v_StaticLED1( void );

/** Turn off any of 2 LEDs */
void LEDCTRL_v_TurnOffLEDx( uint32_t ui32_LED );

void LEDCTRL_v_TurnOffLED0( void );

void LEDCTRL_v_TurnOffLED1( void );

/**************************************************************************************************/

#endif /* __LED_CTRL_H */