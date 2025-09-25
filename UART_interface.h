/*
 * UART_interface.h
 *
 *  Created on: Jul 13, 2025
 *      Author: mariam
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_
#include "STD_TYPES.h"
#define baud_rate  9600
#define f_cpu 8000000UL
#define prescale 51
void UART_init();
void UART_send(u8 data);
u8   UART_recieve();
u8   UART_receiveNonBlocking(u8 *data); // returns 1 if data available, 0 if not
void UART_SendString(const char *str);
u8 UART_receive(void);
void UART_sendNumber(u16 num);
#endif /* UART_INTERFACE_H_ */
