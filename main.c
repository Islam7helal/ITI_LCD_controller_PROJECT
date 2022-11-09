/*
 * main.c
 *
 *  Created on: Oct 29, 2022
 *      Author: User
 */

#include "util/delay.h"

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "S2P/S2P_interface.h"
#include "UART/UART_interface.h"
#include "DIO/DIO_interface.h"
#include "LCD/LCD_interface.h"

int main (void)
{


	LCD_INIT();
	UART_vInit();
	//S2P_vSendByte(0x53);

	LCD_print_string("islam");
	_delay_ms(2000);
	LCD_Clear();


	u8 data=0;
	while (1)
	{

		data = UART_u8ReceiveByte();
		if(data)
		{
			LCD_SendChar(data);
			data=0;
		}

		
	}
}

