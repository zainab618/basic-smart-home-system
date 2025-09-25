/*
  * buzzer.c
 *
 *  Created on: Aug 14, 2025
 *      Author: Lenovo
 */

#include "DIO_interface.h"
#include "buzzer.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
void buzzer_init()
{
	DIO_SetPinDir(DTO_PORTD,PIN7,PIN_OUT);
}

void buzzer_beep()
{
	DIO_SetPinVal(DTO_PORTD,PIN7,PIN_HIGH);
	_delay_ms(500);
	DIO_SetPinVal(DTO_PORTD,PIN7,PIN_LOW);

}
void buzzer_shut()
		{
	DIO_SetPinVal(DTO_PORTD,PIN7,PIN_LOW);
		}
