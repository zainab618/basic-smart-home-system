/*
 * FreeRTOS_hooks.c
 *
 *  Created on: Aug 3, 2025
 *      Author: Lenovo
 */

#include "FreeRTOS.h"
#include "task.h"
void vApplicationMallocFailedHook(void)
{
   while(1);
}

void vApplicationStackOverflowHook(TaskHandle_t  xTask, char *pcTaskName)
{

    while(1); // Stay here if stack overflow happens
}
