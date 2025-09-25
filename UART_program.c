/*
 * UART_program.c
 *
 *  Created on: Jul 13, 2025
 *      Author: mariam
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_interface.h"
#include "UART_private.h"
#include "stdio.h"
void UART_init()
{
	//SET_BIT(UCSRA,1);
	//double speed mode u2x
	UBRRL=prescale;
	UBRRH = prescale >> 8;
	//8-bit data size
	//ASynchronous
	UCSRC =0b10000110;
	CLR_BIT(UCSRB,2);

	//enable RX ,TX
	SET_BIT(UCSRB,3);
	SET_BIT(UCSRB,4);


}

void UART_send(u8 data)
{
	while ((GET_BIT(UCSRA,5))==0);

	UDR=data;
}

u8   UART_recieve()
{
	while ((GET_BIT(UCSRA,7))==0);

	return UDR;
}
u8 UART_receiveNonBlocking(u8 *data)
{
    // Check if RX complete flag is set
    if (GET_BIT(UCSRA, 7))
    {
        *data = UDR;
        return 1; // data available
    }
    return 0; // no data
}

void UART_SendString(const char *str)
{
    while (*str != '\0')   // loop until end of string
    {
        UART_send(*str);   // send single character (your existing function)
        str++;
    }
}
u8 UART_receive(void)
{
    // Wait until RXC0 flag is set (data received)
    while(!GET_BIT(UCSRA, 7));

    // Return received byte
    return UDR;
}

void UART_sendNumber(u16 num)
{
    char buffer[10];              // enough to hold up to 65535 + '\0'
    sprintf(buffer, "%u", num);   // convert number to string (unsigned decimal)
    UART_SendString(buffer); // send it over UART
}
