/****************************************************************************************************
*	@file       app_scheduler_cfg.h
*	@brief      Services - Application tasks configuration file
*	@author     Luis Angel Hernandez
*	@version    1.0
*	@date       08/February/2023
****************************************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "compiler.h"

/*****************************************************************************************************
* Definitions
*****************************************************************************************************/
/* Global Task Scheduler Status definitions */
#define    TASK_SCHEDULER_INIT              0x00u
#define    TASK_SCHEDULER_RUNNING           0x01u
#define    TASK_SCHEDULER_OVERLOAD_1MS      0x02u
#define    TASK_SCHEDULER_OVERLOAD_2MS_A    0x03u
#define    TASK_SCHEDULER_OVERLOAD_2MS_B    0x04u
#define    TASK_SCHEDULER_HALTED            0xAAu

#define    TASK_SCH_MAX_NUMBER_TIME_TASKS   0x06u
#define    TASK_SCH_MAX_NUMBER_EVENT_TASKS  0x06u

#define    TASK_SCH_MAX_NUM_EVENT_TASKS     0X01u

#define    TASK_SCHEDULER_BASE_FREQ		    2000
