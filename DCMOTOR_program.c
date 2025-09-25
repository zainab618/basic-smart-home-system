/*
 * DCMOTOR_program.c
 *
 *  Created on: Jul 2, 2025
 *      Author: Ahmed Saeed
 */
#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO_interface.h"
#include "DCMOTOR_interface.h"
#include "DCMOTOR_config.h"
void DCMOTOR_Init(void)
{
	DIO_SetPinDir(DCMOTOR_PORT,DCMOTOR_PIN1,PIN_OUT);
	DIO_SetPinDir(DCMOTOR_PORT,DCMOTOR_PIN2,PIN_OUT);
}

void DCMOTOR_RotateClockwise(void)
{
	DIO_SetPinVal(DCMOTOR_PORT,DCMOTOR_PIN1,PIN_HIGH);
	DIO_SetPinVal(DCMOTOR_PORT,DCMOTOR_PIN2,PIN_LOW);

}
void DCMOTOR_RotateCounterClockwise(void)
{
	DIO_SetPinVal(DCMOTOR_PORT,DCMOTOR_PIN1,PIN_LOW);
	DIO_SetPinVal(DCMOTOR_PORT,DCMOTOR_PIN2,PIN_HIGH);
}
void DCMOTOR_Stop(void)
{
	DIO_SetPinVal(DCMOTOR_PORT,DCMOTOR_PIN1,PIN_LOW);
	DIO_SetPinVal(DCMOTOR_PORT,DCMOTOR_PIN2,PIN_LOW);
}
