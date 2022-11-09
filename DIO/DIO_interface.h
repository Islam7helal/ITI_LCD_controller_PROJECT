/*
 * DIO_interface.h
 *
 *  Created on: Sep 16, 2022
 *      Author: User
 */

#ifndef DIO_DIO_INTERFACE_H_
#define DIO_DIO_INTERFACE_H_

#define DIO_PIN_OUTPUT		1
#define DIO_PIN_INPUT			0

#define DIO_PIN_HIGH			1
#define DIO_PIN_LOW			0

#define DIO_PORT_OUTPUT		0xFF
#define DIO_PORT_INPUT		0

#define DIO_PORT_HIGH 		0xFF
#define DIO_PORT_LOW  		0

#define DIO_PORTA				0
#define DIO_PORTB				1
#define DIO_PORTC				2
#define DIO_PORTD				3

#define DIO_PIN0				0
#define DIO_PIN1				1
#define DIO_PIN2				2
#define DIO_PIN3				3
#define DIO_PIN4				4
#define DIO_PIN5				5
#define DIO_PIN6				6
#define DIO_PIN7				7


void DIO_vWritePinDirection(u8 A_u8PortID, u8 A_u8PinNo , u8 A_u8Direction);
void DIO_vWritePinVAlue(u8 A_u8PortID, u8 A_u8PinNo , u8 A_u8Value);
u8   DIO_u8ReadPinVAlue(u8 A_u8PortID, u8 A_u8PinNo );   //also you can use output parameter instead of return value
void DIO_vTogglePinValue(u8 A_u8PortID, u8 A_u8PinNo);

void DIO_vWritePortDirection(u8 A_u8PortID, u8 A_u8Direction);
void DIO_vWritePortVAlue(u8 A_u8PortID,u8 A_u8Value);
u8   DIO_u8ReadPortVAlue(u8 A_u8PortID);



#endif /* DIO_DIO_INTERFACE_H_ */
