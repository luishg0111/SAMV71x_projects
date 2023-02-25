/****************************************************************************************************
 *	@file       pbutton_ctrl.c
 *	@brief      ECU Abstraction - Push button control
 *	@author     Luis Angel Hernandez
 *	@version    1.0
 *	@date       03/February/2023
 ****************************************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "pushb_ctrl.h"
#include "pushb_ctrl_cfg.h"

#include "typedefs.h"
#include "led_ctrl.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
// PIN_SWX to configure PIN and PIN interrupt.
Pin PBCTRL_PinSW0 = PIN_SW0;

/*****************************************************************************************************
* Definition of  VARIABLEs - 
*****************************************************************************************************/
T_SCHEDTASK PushButtonTask = {TASK_EVENT, LEDCTRL_v_StaticLED0, SUSPENDED, 2};
/*******************************************************************************
 * Code
 ******************************************************************************/

/// @brief Configure any SWx push button as input
/// @param pPin_SWx 
/// @param p_v_handler 
void PBCTRL_v_configSWx(const Pin* pPin_SWx, void (*p_v_handler)( const Pin* ))
{
	/* Configure PinSW0 as input. */
	PIO_Configure(pPin_SWx, 1);
	/* PinSW0 denounce filter parameters, uses 10 Hz filter*/
	PIO_SetDebounceFilter(pPin_SWx, 10);
	/* Initialize PinSW0 interrupt handler */
	PIO_ConfigureIt(pPin_SWx, p_v_handler); /* Interrupt on rising edge, SW0_Handler as callback function */
	/* Enable PinSW0 controller IRQs. */
	NVIC_EnableIRQ((IRQn_Type)pPin_SWx->id);
	/* Enable PinSW0 line interrupts. */
	PIO_EnableIt(pPin_SWx);
}

/// @brief Set the output for debug process in SW0 Event
/// @param  
void PBCTRL_v_SW0Event(bool b_status)
{
	if(SW0_VALID_EVENT == b_status)
	{
		//Change output for mesurement time to start task
		LEDCTRL_v_StaticLEDx(LEDCTRL_LED1);
		//Add Button SW0 task to queue
		vfnEventActivationHandler(&PushButtonTask);
		//Execute Schedule point to preempt the event task
		vfnSchedulePoint();
	}
}

/// @brief Rising edge detection interruption handler
/// @param Pin *pPin_SW0 
void PBCTRL_v_SW0Handler(const Pin *pPin_SW0)
{
	if (pPin_SW0 == &PBCTRL_PinSW0)
	{
		PBCTRL_v_SW0Event(SW0_VALID_EVENT);
	}
}

