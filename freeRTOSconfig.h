/*
 * freeRTOSconfig.h
 *
 *  Created on: Jul 31, 2025
 *      Author: Lenovo
 */

#ifndef FREERTOSCONFIG_H_
#define FREERTOSCONFIG_H_

#include <stdint.h>
#include <stdlib.h>
#define configUSE_16_BIT_TICKS 1


#define configFRTOS_MEMORY_SCHEME        2
#define configSUPPORT_DYNAMIC_ALLOCATION 1
#define configSUPPORT_STATIC_ALLOCATION  0
#define INCLUDE_vTaskDelete    1

#define INCLUDE_vTaskDelay   1

//#define configTOTAL_HEAP_SIZE            ((size_t)(1024))

//#define configUSE_MALLOC_FAILED_HOOK     0
#define configAPPLICATION_ALLOCATED_HEAP 0

#define configUSE_IDLE_HOOK              0
#define configUSE_TICK_HOOK              0


//#define configTICK_TYPE_WIDTH_IN_BITS   16
#define configCPU_CLOCK_HZ        (8000000UL)
#define configTICK_RATE_HZ        (1000)           // 1ms system tick
#define configMAX_PRIORITIES      (5)              // Number of priority levels
#define configMINIMAL_STACK_SIZE  (85)             // Depends on task complexity
#define configTOTAL_HEAP_SIZE     (1024)           // Memory pool for FreeRTOS
#define configUSE_PREEMPTION      1                // Enables preemptive multitasking
#define configUSE_IDLE_HOOK       0
#define configUSE_TICK_HOOK       0
#define configUSE_MUTEXES         1
#define configUSE_COUNTING_SEMAPHORES 1
#define configUSE_RECURSIVE_MUTEXES 0
#define configCHECK_FOR_STACK_OVERFLOW 2
#define configUSE_MALLOC_FAILED_HOOK 1

#endif /* FREERTOSCONFIG_H_ */
