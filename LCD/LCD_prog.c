/*
 * LCD_prog.c
 *
 *  Created on: Sep 10, 2022
 *      Author: User
 */

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

#include <avr/io.h>
#include <util/delay.h>

#include "../DIO/DIO_interface.h"
#include "../S2P/S2P_interface.h"
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

void LCD_SendChar(u8 A_u8Charachter)
{
	u8 u8local_temp=A_u8Charachter;
	//Select RS->1
	//SET_BIT(LCD_CTRL_PORT,LCD_RS_PIN);
	////////////DIO_vWritePinVAlue(LCD_CTRL_PORT, LCD_RS_PIN , DIO_PIN_HIGH);

	u8local_temp &= 0xF0;
	u8local_temp = u8local_temp>>4 ;
	SET_BIT(u8local_temp,7);



	//DIO_vWritePortVAlue(LCD_DATA_PORT ,A_u8Charachter);
	S2P_vSendByte(u8local_temp);
	_delay_ms(2);

	//Select EN->2/
	//SET_BIT(LCD_CTRL_PORT,LCD_E_PIN);
	DIO_vWritePinVAlue(DIO_PORTA, LCD_E_PIN , DIO_PIN_HIGH);

	_delay_ms(1);
	_delay_ms(1);
	//CLR_BIT(LCD_CTRL_PORT,LCD_E_PIN);
	DIO_vWritePinVAlue(DIO_PORTA, LCD_E_PIN , DIO_PIN_LOW);
	_delay_ms(10);




	//DIO_vWritePortVAlue(LCD_DATA_PORT ,(A_u8Charachter<<4));
	u8local_temp=A_u8Charachter;
	u8local_temp &= 0x0F;
	//u8local_temp=(u8local_temp<<4);
	SET_BIT(u8local_temp,7);
	S2P_vSendByte(u8local_temp);

	_delay_ms(2);

	//Select EN->2/
	//SET_BIT(LCD_CTRL_PORT,LCD_E_PIN);
	DIO_vWritePinVAlue(DIO_PORTA, LCD_E_PIN , DIO_PIN_HIGH);

	_delay_ms(1);
	_delay_ms(1);
	//CLR_BIT(LCD_CTRL_PORT,LCD_E_PIN);
	DIO_vWritePinVAlue(DIO_PORTA, LCD_E_PIN , DIO_PIN_LOW);
	_delay_ms(10);




}

void LCD_SendCmd(u8 A_u8CMD)
{

	u8 u8local_temp=A_u8CMD;    // b7 b6 b5 b4 b3 b2 b1 b0

	//Select RS->1/
	//CLR_BIT(LCD_CTRL_PORT,LCD_RS_PIN);
	DIO_vWritePinVAlue(LCD_CTRL_PORT, LCD_RS_PIN , DIO_PIN_LOW);

	u8local_temp &= 0xF0;
	u8local_temp = u8local_temp>>4;

	CLR_BIT(u8local_temp,7);
	S2P_vSendByte(u8local_temp);


	//DIO_vWritePortVAlue(LCD_DATA_PORT ,A_u8CMD);
	_delay_ms(2);

	//Select EN->2/
	//SET_BIT(LCD_CTRL_PORT,LCD_E_PIN);
	DIO_vWritePinVAlue(DIO_PORTA, LCD_E_PIN , DIO_PIN_HIGH);
	_delay_ms(1);
	_delay_ms(1);

	//CLR_BIT(LCD_CTRL_PORT,LCD_E_PIN);
	DIO_vWritePinVAlue(DIO_PORTA, LCD_E_PIN , DIO_PIN_LOW);
	_delay_ms(10);


	//DIO_vWritePortVAlue(LCD_DATA_PORT ,(A_u8CMD<<4));
	u8local_temp=A_u8CMD;
	u8local_temp &= 0x0F;
	//u8local_temp=(u8local_temp<<4);
	CLR_BIT(u8local_temp,7);
	S2P_vSendByte(u8local_temp);
	_delay_ms(2);

	//Select EN->2/
	//SET_BIT(LCD_CTRL_PORT,LCD_E_PIN);
	DIO_vWritePinVAlue(DIO_PORTA, LCD_E_PIN , DIO_PIN_HIGH);
	_delay_ms(1);
	_delay_ms(1);

	//CLR_BIT(LCD_CTRL_PORT,LCD_E_PIN);
	DIO_vWritePinVAlue(DIO_PORTA, LCD_E_PIN , DIO_PIN_LOW);
	_delay_ms(10);





}

void LCD_INIT(void)
{

	S2P_vInit();
	DIO_vWritePinDirection(DIO_PORTA,LCD_E_PIN,DIO_PIN_OUTPUT);
	_delay_ms(50);
	LCD_SendCmd(lcd_Home);
	LCD_SendCmd(lcd_FunctionSet4bit);

	_delay_ms(1);
	LCD_SendCmd(lcd_DisplayOn);
	_delay_ms(1);
	LCD_SendCmd(lcd_Clear);
	_delay_ms(2);
	LCD_SendCmd(lcd_EntryMode);
	_delay_ms(1);


}

void LCD_print_string(u8 A_u8str[])
{
	for (int i =0 ; A_u8str[i]!= '\0'; i++)
	{
		LCD_SendChar(A_u8str[i]);
	}

}



void LCD_Clear(void)
{
	LCD_SendCmd(lcd_Clear);

}
