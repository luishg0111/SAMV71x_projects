/****************************************************************************************************
*	@file       pbutton_ctrl_cfg.h
*	@brief      ECU Abstraction - Push button control configuration file
*	@author     Luis Angel Hernandez
*	@version    1.0
*	@date       03/February/2023
****************************************************************************************************/

/** Core modules */
#include "compiler.h"
#include "board.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
// SW0 Definition for Pin type
#define PIN_SW0 {PIO_PA9,         \
                 PIOA,            \
                 ID_PIOA,         \
                 PIO_INPUT,       \
                 PIO_PULLUP |     \
                 PIO_DEBOUNCE |   \
                 PIO_IT_RISE_EDGE \
	            } 

#define SW0_VALID_EVENT     (bool)true
#define SW0_INVALID_EVENT   (bool)false
