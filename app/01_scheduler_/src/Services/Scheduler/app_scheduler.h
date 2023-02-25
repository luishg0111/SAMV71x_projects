/*******************************************************************************
\file       app_scheduler.h
\brief      Task scheduler function prototypes
\author     Abraham Tezmol - Modified Luis Angel Hernandez
\version    0.1
\date       09/09/2008
*/

#ifndef APP_SCHEDULER_H        /*prevent duplicated includes*/
#define APP_SCHEDULER_H

/*-- Includes ----------------------------------------------------------------*/

#include "compiler.h"
#include "typedefs.h"
#include "app_scheduler_cfg.h"

/*****************************************************************************************************
* Declaration of module wide TYPES
*****************************************************************************************************/
typedef enum
{
    SUSPENDED,
    READY,
    RUNNING
}E_TASK_STATES;

/* Task Scheduler Tasks IDs definitions */
typedef enum  
{   
    TASKS_1_MS,
    TASKS_2_MS_A,
    TASKS_2_MS_B,
    TASKS_10_MS,
    TASKS_50_MS,
    TASKS_100_MS,
    TASK_EVENT,
    TASK_NULL,
}E_SCHEDTASK_ID;

typedef struct 
{
    E_SCHEDTASK_ID      e_TaskID;
    tPtr_to_function    p_Task;
    E_TASK_STATES       e_TaskState;
    uint8_t             ui8_Priority;
}T_SCHEDTASK;

/*****************************************************************************************************
* Definition of module wide MACROS / #DEFINE-CONSTANTS 
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of module wide VARIABLEs
*****************************************************************************************************/
extern T_SCHEDTASK TimeTriggeredTasks[TASK_SCH_MAX_NUMBER_TIME_TASKS];
extern T_SCHEDTASK EventTriggeredTasks[TASK_SCH_MAX_NUMBER_EVENT_TASKS];

/*****************************************************************************************************
* Declaration of module wide FUNCTIONS
*****************************************************************************************************/

/** Scheduler Initalization (arming) */
void vfnScheduler_Init(void);

/** Scheduler kick-off function */
void vfnScheduler_Start(void);

/** Scheduler stop function */
void vfnScheduler_Stop(void);

/** Multi-thread round robin task scheduler */
void vfnTask_Scheduler(void);

void vfnScheduler_TaskStart( T_SCHEDTASK* t_Task );

void vfnScheduler_TaskActivate( T_SCHEDTASK* t_Task );

void vfnScheduler_TaskPreempt( T_SCHEDTASK* t_Task );

void vfnScheduler_TaskRestart( T_SCHEDTASK* t_Task );

void vfnScheduler_KillTask(T_SCHEDTASK* t_Task);

void vfnEventActivationHandler(T_SCHEDTASK* t_TaskEvent);

void vfnScheduler_SetTaskRunning(T_SCHEDTASK* t_TaskRunning);

T_SCHEDTASK* vfnScheduler_GetTaskRunning( void );

/** Schedule point checks the priority of tasks */
void vfnSchedulePoint(void);

/*******************************************************************************/

#endif /* APP_SCHEDULER_H */