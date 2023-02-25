/****************************************************************************************************/
/**
\file       led_ctrl.c
\brief      MCU abstraction level - LED control
\author     Abraham Tezmol - Modified Luis Angel Hernandez
\version    1.1
\project    Tau 
\date       4/Feb/2023
*/
/****************************************************************************************************/

/*****************************************************************************************************
* Include files
*****************************************************************************************************/
/** Own headers */
#include "led_ctrl.h"
/** Other modules */
#include "led.h"
#include "typedefs.h"

/*****************************************************************************************************
* Definition of module wide VARIABLEs 
*****************************************************************************************************/

/****************************************************************************************************
* Declaration of module wide FUNCTIONs 
****************************************************************************************************/

/****************************************************************************************************
* Definition of module wide MACROs / #DEFINE-CONSTANTs 
*****************************************************************************************************/

/****************************************************************************************************
* Declaration of module wide TYPEs 
*****************************************************************************************************/

/****************************************************************************************************
* Definition of module wide (CONST-) CONSTANTs 
*****************************************************************************************************/

/****************************************************************************************************
* Code of module wide FUNCTIONS
*****************************************************************************************************/


/*****************************************************************************************************/
/**
* \brief    Configures LED 0 and 1 of SAMV71 board
* \author   Abraham Tezmol
* \param    void
* \return   void
*/
void LEDCTRL_v_Configure( void )
{
	LED_Configure( LEDCTRL_LED0 ) ;
	LED_Configure( LEDCTRL_LED1 ) ;
}

/*****************************************************************************************************/
/**
* \brief    Turn a combination of 2 LEDs with a unique blinking pattern.
			Call this function periodically @ 10ms to operate
* \author   Abraham Tezmol
* \param    void
* \return   void
*/
void LEDCTRL_v_BlinkingPattern(void)
{
/* Global state machine status for LED flashing control  */
	static uint8_t ui8_Index;

    (ui8_Index)++;
    
    switch ((ui8_Index))
    {
        case  1:
            LED_Set(LEDCTRL_LED0);
            LED_Set(LEDCTRL_LED1);
            break;
        case  11:
            LED_Set(LEDCTRL_LED0);
            LED_Set(LEDCTRL_LED1);
            break;
        case  3:
            LED_Clear(LEDCTRL_LED0);
            LED_Clear(LEDCTRL_LED1);
            break;
        case  13:
            LED_Clear(LEDCTRL_LED0);
            LED_Clear(LEDCTRL_LED1);
            break;
        case 101:
            ui8_Index = 0;
            break;
        default:
            break;
    }
}

void LEDCTRL_v_BlinkingLEDx(uint32_t ui32_LED)
{
/* Global state machine status for LED flashing control  */
	static uint8_t ui8_Index;

    (ui8_Index)++;
    
    switch ((ui8_Index))
    {
        case  1:
            LED_Set(ui32_LED);
            break;
        case  11:
            LED_Set(ui32_LED);
            break;
        case  3:
            LED_Clear(ui32_LED);
            break;
        case  13:
            LED_Clear(ui32_LED);
            break;
        case 101:
            ui8_Index = 0;
            break;
        default:
            break;
    }
}

void LEDCTRL_v_BlinkingLED0( void )
{
/* Global state machine status for LED flashing control  */
	static uint8_t ui8_Index;

    (ui8_Index)++;
    
    switch ((ui8_Index))
    {
        case  1:
            LED_Set(LEDCTRL_LED0);
            break;
        case  11:
            LED_Set(LEDCTRL_LED0);
            break;
        case  3:
            LED_Clear(LEDCTRL_LED0);
            break;
        case  13:
            LED_Clear(LEDCTRL_LED0);
            break;
        case 101:
            ui8_Index = 0;
            break;
        default:
            break;
    }
}

void LEDCTRL_v_BlinkingLED1( void )
{
/* Global state machine status for LED flashing control  */
	static uint8_t ui8_Index;

    (ui8_Index)++;
    
    switch ((ui8_Index))
    {
        case  1:
            LED_Set(LEDCTRL_LED1);
            break;
        case  11:
            LED_Set(LEDCTRL_LED1);
            break;
        case  3:
            LED_Clear(LEDCTRL_LED1);
            break;
        case  13:
            LED_Clear(LEDCTRL_LED1);
            break;
        case 101:
            ui8_Index = 0;
            break;
        default:
            break;
    }
}

void LEDCTRL_v_StaticLEDx( uint32_t ui32_LED )
{
	LED_Set(ui32_LED);
}

void LEDCTRL_v_StaticLED0( void )
{
	LED_Set(LEDCTRL_LED0);
}

void LEDCTRL_v_StaticLED1( void )
{
	LED_Set(LEDCTRL_LED1);
}

void LEDCTRL_v_TurnOffLEDx( uint32_t ui32_LED )
{
	LED_Clear(ui32_LED);
}

void LEDCTRL_v_TurnOffLED0( void )
{
	LED_Clear(LEDCTRL_LED0);
}

void LEDCTRL_v_TurnOffLED1( void )
{
	LED_Clear(LEDCTRL_LED1);
}
/*******************************************************************************/