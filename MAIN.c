/*
 * MAIN.c
 *
 *  Created on: Sep 25, 2025
 *      Author: Lenovo
 */


#include "BIT_MATH.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DCMOTOR_interface.h"
#include "LCD_interfac.h"
#include "UART_interface.h"
#include "buzzer.h"
#include <util/delay.h>
#include <stdio.h>

volatile u8 current_mode=0;
volatile u8 manual_mode=1;
volatile u8 BT_mode=2;
volatile u8 led_state=3;
volatile u8 fan_state=4;
volatile u8 on =5;
volatile u8 off=6;

u8 buz_play_manual =0;
u8 buz_play_FANoff =0;
u8 buz_play_LEDoff =0;




//APPLIANCES CONTROL
void controlTasks(void *pvParameters)
{
	u8 received;

	    DIO_SetPinDir(DTO_PORTA, PIN2, PIN_IN);     // Mode switch
	    DIO_SetPinVal(DTO_PORTA, PIN2, PIN_HIGH);   // Pull-up

	    DIO_SetPinDir(DTO_PORTA, PIN0, PIN_IN);     // LED manual switch
	    DIO_SetPinVal(DTO_PORTA, PIN0, PIN_HIGH);   // Pull-up

	    DIO_SetPinDir(DTO_PORTA, PIN1, PIN_IN);     // FAN manual switch
	    DIO_SetPinVal(DTO_PORTA, PIN1, PIN_HIGH);   // Pull-up

	    //  Outputs
	    DIO_SetPinDir(DTO_PORTD, PIN6, PIN_OUT);    // LED output
	    DIO_SetPinDir(DTO_PORTD, PIN5, PIN_OUT);    // FAN output


	while(1)

	{
		//manual control
		if (DIO_GetPinVal(DTO_PORTA, PIN2) == 0)
		{
			current_mode=manual_mode;
			//led control
			if (DIO_GetPinVal(DTO_PORTA, PIN0) == 0)
			        {

			            DIO_SetPinVal(DTO_PORTD, PIN6, PIN_HIGH); // LED ON

			        }
			        else
			        {
			            DIO_SetPinVal(DTO_PORTD, PIN6, PIN_LOW);  // LED OFF
			        }

			 if (DIO_GetPinVal(DTO_PORTA, PIN1) == 0)
			           {

			               DIO_SetPinVal(DTO_PORTD, PIN5, PIN_HIGH); // FAN ON

			           }
			           else
			           {
			               DIO_SetPinVal(DTO_PORTD, PIN5, PIN_LOW);  // FAN OFF
			           }

		}
		//bluetooth control
		else
		{
			 current_mode=BT_mode;

			if (UART_receiveNonBlocking(&received))
			        {
			            if (received == '1')
			            {
			            	fan_state=on;
			                DIO_SetPinVal(DTO_PORTD, PIN5, PIN_HIGH);

			                }
			            else if (received == '2')
			            {
			            	fan_state=off;
			                DIO_SetPinVal(DTO_PORTD, PIN5, PIN_LOW);

			                }

			            else if (received == '3')
			            {
			            	led_state=on;
			              DIO_SetPinVal(DTO_PORTD, PIN6, PIN_HIGH);

			            }

			            else if (received == '4')
			            {
			            	led_state=off;
			                DIO_SetPinVal(DTO_PORTD, PIN6, PIN_LOW);

			           			                }

			        }
			        }
        vTaskDelay(pdMS_TO_TICKS(50)); // Small debounce delay

		}

	}




//feed back system

void feedBackSystem(void *pvParameters)
{

	while(1)
	{

  if (current_mode==manual_mode)
  {
	  LCD_SendString("manual mode ON");
	  if (buz_play_manual==0)
	  {
		  buzzer_beep();
		  buz_play_manual=1;

	  }

	  vTaskDelay(pdMS_TO_TICKS(5000));
      LCD_Clear();

  }
  else if (current_mode==BT_mode)
  {
	  buz_play_manual=0;
	  if (fan_state==on)
	  {
		  LCD_SendString("fan on");
		  vTaskDelay(pdMS_TO_TICKS(5000));
		  LCD_Clear();
		  buz_play_FANoff=0;

	  }
	  else if (fan_state==off)
	  {
		  LCD_SendString("fan off");
		  if (buz_play_FANoff==0)
		 	  {
		 		  buzzer_beep();
		 		  buz_play_FANoff=1;
		 	  }
		  vTaskDelay(pdMS_TO_TICKS(5000));
		  		  LCD_Clear();
	  }

	  if (led_state==on)
	  {
		  LCD_SendString("led on");
		  vTaskDelay(pdMS_TO_TICKS(5000));
		  		  LCD_Clear();
		  		buz_play_LEDoff=0;
	  }
	  else if (led_state==off)
	  {
		  LCD_SendString("led off");
		  if (buz_play_LEDoff==0)
		 	  {
		 		  buzzer_beep();
		 		  buz_play_LEDoff=1;
		 	  }
		 vTaskDelay(pdMS_TO_TICKS(5000));

		  		  LCD_Clear();
		   }
	 	}
}
}








void create_tasks()
{
	xTaskCreate(controlTasks, "appliances control", 200, NULL, 4, NULL);
	xTaskCreate(feedBackSystem, "feed back system", 200, NULL, 2, NULL);

}


int main()
{
	UART_init();
	LCD_Init();
	buzzer_init();

   create_tasks();

 vTaskStartScheduler();



	    while(1);
	    return 0;
}

