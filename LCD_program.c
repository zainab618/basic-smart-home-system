/*
 * LCD_program.c
 *
 *  Created on: Jun 30, 2025
 *      Author: Ahmed Saeed
 */


#include "STD_Types.h"
#include "BIT_Math.h"
#include "LCD_interfac.h"
#include <util/delay.h>
#include "DIO_interface.h"

void LCD_GotoXY(u8 x ,u8 y)
{

}

void LCD_Clear(void)
{
	LCD_SendCommand(lcd_Clear);
}
//str ----> "Hello world '/0'"
void LCD_SendString(const char* str)
{
	while(*str)
	{
		LCD_SendChar(*str);
		str++;
	}
}


void LCD_SendCommand(u8 command)
{
    // RS = 0 for command
    DIO_SetPinVal(DTO_PORTA, PIN7, PIN_LOW);
    // RW = 0 for write
    DIO_SetPinVal(DTO_PORTA, PIN6, PIN_LOW);

    // Put command on data bus
    DIO_SetPortVal(DTO_PORTB, command);

    // Pulse Enable
    DIO_SetPinVal(DTO_PORTA, PIN5, PIN_HIGH);
    _delay_us(1); // tiny delay
    DIO_SetPinVal(DTO_PORTA, PIN5, PIN_LOW);

    _delay_ms(2); // allow LCD to process
}

void LCD_SendChar(u8 character)
{
    // RS = 1 for data
    DIO_SetPinVal(DTO_PORTA, PIN7, PIN_HIGH);
    // RW = 0 for write
    DIO_SetPinVal(DTO_PORTA, PIN6, PIN_LOW);

    // Put data on bus
    DIO_SetPortVal(DTO_PORTB, character);

    // Pulse Enable
    DIO_SetPinVal(DTO_PORTA, PIN5, PIN_HIGH);
    _delay_us(1);
    DIO_SetPinVal(DTO_PORTA, PIN5, PIN_LOW);

    _delay_ms(2);
}
void LCD_Init(void)
{
    // Control pins
    DIO_SetPinDir(DTO_PORTA, PIN7, PIN_OUT); // RS
    DIO_SetPinDir(DTO_PORTA, PIN6, PIN_OUT); // RW
    DIO_SetPinDir(DTO_PORTA, PIN5, PIN_OUT); // E

    // Data pins
    DIO_SetPortDir(DTO_PORTB, PORT_OUT);

    _delay_ms(15); // wait after power up

    LCD_SendCommand(0x38); // Function set: 8-bit, 2 lines, 5x8
    LCD_SendCommand(0x0C); // Display ON, cursor OFF
    LCD_SendCommand(0x01); // Clear display
    _delay_ms(2);
    LCD_SendCommand(0x06); // Entry mode
}

