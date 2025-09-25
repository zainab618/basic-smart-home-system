/*
 * UART_private.h
 *
 *  Created on: Jul 13, 2025
 *      Author: mariam
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define UDR    *((volatile u8*)0X2C)
#define UCSRA  *((volatile u8*)0X2B)
#define UCSRB  *((volatile u8*)0X2A)
#define UCSRC  *((volatile u8*)0X40)
#define UBRRL  *((volatile u8*)0X29)
#define UBRRH  *((volatile u8*)0X40)



#endif /* UART_PRIVATE_H_ */
