/*
 * DIO_interface.h
 *
 *  Created on: Jun 29, 2025
 *      Author: yousef.ahmed
 */

#include "STD_TYPES.h"
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


#define PIN0      0
#define PIN1      1
#define PIN2      2
#define PIN3      3
#define PIN4      4
#define PIN5      5
#define PIN6      6
#define PIN7      7

#define DTO_PORTA     1
#define DTO_PORTB     2
#define DTO_PORTC     3
#define DTO_PORTD     4

#define PIN_OUT   1
#define PIN_IN    0

#define PIN_HIGH  1
#define PIN_LOW   0

#define PORT_OUT   0XFF
#define PORT_IN    0X00

#define PORT_HIGH  0XFF
#define PORT_LOW   0X00

void DIO_SetPortDir(u8 PortNum,u8 PortDir);
void DIO_SetPortVal(u8 PortNum,u8 PortVal);

void DIO_SetPinDir(u8 PortNum,u8 PinNum,u8 PinDir);
void DIO_SetPinVal(u8 PortNum,u8 PinNum,u8 PinVal);

u8 DIO_GetPinVal(u8 PortNum,u8 PinNum);
#endif /* DIO_INTERFACE_H_ */
