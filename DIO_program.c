/*
 * DIO_program.c
 *
 *  Created on: Jun 29, 2025
 *      Author: yousef.ahmed
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_private.h"

void DIO_SetPortDir(u8 PortNum,u8 PortDir)
{
	switch(PortNum)
	{
	case DTO_PORTA:DDRA_REG=PortDir;break;
	case DTO_PORTB:DDRB_REG=PortDir;break;
	case DTO_PORTC:DDRC_REG=PortDir;break;
	case DTO_PORTD:DDRD_REG=PortDir;break;
	}

}
void DIO_SetPortVal(u8 PortNum,u8 PortVal)
{
	switch(PortNum)
	{
	case DTO_PORTA:PORTA_REG=PortVal;break;
	case DTO_PORTB:PORTB_REG=PortVal;break;
	case DTO_PORTC:PORTC_REG=PortVal;break;
	case DTO_PORTD:PORTD_REG=PortVal;break;
	}

}

void DIO_SetPinDir(u8 PortNum,u8 PinNum,u8 PinDir)
{
	if(PinDir==PIN_OUT)
	{
		switch(PortNum)
		{
		case DTO_PORTA:SET_BIT(DDRA_REG,PinNum);break;
		case DTO_PORTB:SET_BIT(DDRB_REG,PinNum);break;
		case DTO_PORTC:SET_BIT(DDRC_REG,PinNum);break;
		case DTO_PORTD:SET_BIT(DDRD_REG,PinNum);break;
		}
	}
	else if(PinDir==PIN_IN)
	{
		switch(PortNum)
		{
		case DTO_PORTA:CLR_BIT(DDRA_REG,PinNum);break;
		case DTO_PORTB:CLR_BIT(DDRB_REG,PinNum);break;
		case DTO_PORTC:CLR_BIT(DDRC_REG,PinNum);break;
		case DTO_PORTD:CLR_BIT(DDRD_REG,PinNum);break;
		}
	}

}
void DIO_SetPinVal(u8 PortNum,u8 PinNum,u8 PinVal)
{
	if(PinVal==PIN_HIGH)
	{
		switch(PortNum)
		{
		case DTO_PORTA:SET_BIT(PORTA_REG,PinNum);break;
		case DTO_PORTB:SET_BIT(PORTB_REG,PinNum);break;
		case DTO_PORTC:SET_BIT(PORTC_REG,PinNum);break;
		case DTO_PORTD:SET_BIT(PORTD_REG,PinNum);break;
		}
	}
	else if(PinVal==PIN_LOW)
	{
		switch(PortNum)
		{
		case DTO_PORTA:CLR_BIT(PORTA_REG,PinNum);break;
		case DTO_PORTB:CLR_BIT(PORTB_REG,PinNum);break;
		case DTO_PORTC:CLR_BIT(PORTC_REG,PinNum);break;
		case DTO_PORTD:CLR_BIT(PORTD_REG,PinNum);break;
		}
	}
}

u8 DIO_GetPinVal(u8 PortNum,u8 PinNum)
{
	u8 Result=0;
	switch(PortNum)
	{
	case DTO_PORTA:Result=GET_BIT(PINA_REG,PinNum);break;
	case DTO_PORTB:Result=GET_BIT(PINB_REG,PinNum);break;
	case DTO_PORTC:Result=GET_BIT(PINC_REG,PinNum);break;
	case DTO_PORTD:Result=GET_BIT(PIND_REG,PinNum);break;
	}
	return Result;
}
