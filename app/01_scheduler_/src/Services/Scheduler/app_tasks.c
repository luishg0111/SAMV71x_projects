/****************************************************************************************************/
/**
\file       app_tasks.c
\brief      Multi-thread Task scheduler - list of tasks.
\author     Abraham Tezmol
\version    1.0
\date       07/09/2013
*/
/****************************************************************************************************/

/*****************************************************************************************************
* Include files
*****************************************************************************************************/

/** Scheduler function prototypes definitions */
#include    "app_tasks.h"
#include    "led_ctrl.h"
#include    "app_scheduler.h"
/*****************************************************************************************************
* Definition of  VARIABLEs - 
*****************************************************************************************************/


/*****************************************************************************************************
* Definition of module wide (CONST-) CONSTANTs 
*****************************************************************************************************/

/*****************************************************************************************************
* Code of module wide FUNCTIONS
*****************************************************************************************************/
/* List of tasks to be executed @ 1ms */
void TASKS_LIST_1MS( void )
{
    vfnSchedulePoint();
}

/* List of tasks to be executed @ 2ms, first group */
void TASKS_LIST_2MS_A(void)
{
    vfnSchedulePoint();
}

/* List of tasks to be executed @ 2ms, second group */
void TASKS_LIST_2MS_B( void )
{
    vfnSchedulePoint();
}
    
/* List of tasks to be executed @ 10ms */
void TASKS_LIST_10MS( void )
{
    LEDCTRL_v_BlinkingLED0();
    vfnSchedulePoint();
}

/* List of tasks to be executed @ 50ms */
void TASKS_LIST_50MS( void )
{
    vfnSchedulePoint();
}

/* List of tasks to be executed @ 100ms */
void TASKS_LIST_100MS( void )
{
    vfnSchedulePoint();
}


