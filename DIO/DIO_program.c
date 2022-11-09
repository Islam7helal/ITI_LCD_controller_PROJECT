/*
 * DIO_program.c
 *
 *  Created on: Sep 16, 2022
 *      Author: User
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"


#include "DIO_interface.h"
#include "DIO.private.h"
#include "DIO_config.h"




void DIO_vWritePinDirection(u8 A_u8PortID, u8 A_u8PinNo , u8 A_u8Direction)
{
	if(A_u8Direction == DIO_PIN_OUTPUT){
		switch (A_u8PortID)
		{
			case DIO_PORTA:
				SET_BIT(DDRA,A_u8PinNo);
			break;
			case DIO_PORTB:
				SET_BIT(DDRB,A_u8PinNo);
			break;
			case DIO_PORTC:
				SET_BIT(DDRC,A_u8PinNo);
			break;
			case DIO_PORTD:
				SET_BIT(DDRD,A_u8PinNo);
			break;
		}
	}
	else if (A_u8Direction == DIO_PIN_INPUT){
		switch (A_u8PortID)
		{
		case DIO_PORTA:
				CLR_BIT(DDRA,A_u8PinNo);
			break;
			case DIO_PORTB:
				CLR_BIT(DDRB,A_u8PinNo);
			break;
			case DIO_PORTC:
				CLR_BIT(DDRC,A_u8PinNo);
			break;
			case DIO_PORTD:
				CLR_BIT(DDRD,A_u8PinNo);
			break;
		}
	}
}
void DIO_vWritePinVAlue(u8 A_u8PortID, u8 A_u8PinNo , u8 A_u8Value)
{
	{
		if(A_u8Value == DIO_PIN_HIGH){
			switch (A_u8PortID)
			{
				case DIO_PORTA:
					SET_BIT(PORTA,A_u8PinNo);
				break;
				case DIO_PORTB:
					SET_BIT(PORTB,A_u8PinNo);
				break;
				case DIO_PORTC:
					SET_BIT(PORTC,A_u8PinNo);
				break;
				case DIO_PORTD:
					SET_BIT(PORTD,A_u8PinNo);
				break;
			}
		}
		else if (A_u8Value == DIO_PIN_LOW){
			switch (A_u8PortID)
			{
			case DIO_PORTA:
					CLR_BIT(PORTA,A_u8PinNo);
				break;
				case DIO_PORTB:
					CLR_BIT(PORTB,A_u8PinNo);
				break;
				case DIO_PORTC:
					CLR_BIT(PORTC,A_u8PinNo);
				break;
				case DIO_PORTD:
					CLR_BIT(PORTD,A_u8PinNo);
				break;
			}
		}
	}
}
u8 DIO_u8ReadPinVAlue(u8 A_u8PortID, u8 A_u8PinNo )   //also you can use output parameter instead of return value
{
	u8 L_u8PinValue=0;
	switch(A_u8PortID)
		{
		case DIO_PORTA : L_u8PinValue= GET_BIT(PINA , A_u8PinNo); break;
		case DIO_PORTB : L_u8PinValue= GET_BIT(PINB , A_u8PinNo); break;
		case DIO_PORTC : L_u8PinValue= GET_BIT(PINC , A_u8PinNo); break;
		case DIO_PORTD : L_u8PinValue= GET_BIT(PIND , A_u8PinNo); break;

		}
	return L_u8PinValue;
}
void DIO_vTogglePinValue(u8 A_u8PortID, u8 A_u8PinNo)
{
	switch(A_u8PortID)
		{
		case DIO_PORTA : TOG_BIT(PINA , A_u8PinNo); break;
		case DIO_PORTB : TOG_BIT(PINB , A_u8PinNo); break;
		case DIO_PORTC : TOG_BIT(PINC , A_u8PinNo); break;
		case DIO_PORTD : TOG_BIT(PIND , A_u8PinNo); break;

		}
}

void DIO_vWritePortDirection(u8 A_u8PortID, u8 A_u8Direction)
{
	switch(A_u8PortID)
		{
		case DIO_PORTA : DDRA=A_u8Direction; break;
		case DIO_PORTB : DDRB=A_u8Direction; break;
		case DIO_PORTC : DDRC=A_u8Direction; break;
		case DIO_PORTD : DDRD=A_u8Direction; break;

		}
}
void DIO_vWritePortVAlue(u8 A_u8PortID,u8 A_u8Value)
{
	switch(A_u8PortID)
		{
		case DIO_PORTA : PORTA=A_u8Value; break;
		case DIO_PORTB : PORTB=A_u8Value; break;
		case DIO_PORTC : PORTC=A_u8Value; break;
		case DIO_PORTD : PORTD=A_u8Value; break;

		}
}
u8 DIO_u8ReadPortVAlue(u8 A_u8PortID)
{
	u8 L_u8PortValue=0;
	switch(A_u8PortID)
		{
		case DIO_PORTA : L_u8PortValue=PINA; break;
		case DIO_PORTB : L_u8PortValue=PINB; break;
		case DIO_PORTC : L_u8PortValue=PINC; break;
		case DIO_PORTD : L_u8PortValue=PIND; break;

		}
	return L_u8PortValue;
}



