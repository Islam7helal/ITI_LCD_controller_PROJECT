// this is S2P_program.c 


#include "../LIB/BIT_MATH.h"

#include "../LIB/STD_TYPES.h"


#include "S2P_interface.h"
#include "S2P_private.h"
#include "S2P_config.h"
   
#include "../DIO/DIO_interface.h"
#include "util/delay.h"



void S2P_vInit(void)
{
	/* config the shift register pins */
	DIO_vWritePinDirection(S2P_PORT,  S2P_SHIFT_CLOCK   ,   DIO_PIN_OUTPUT);
	DIO_vWritePinDirection(S2P_PORT,  S2P_LATCH         ,   DIO_PIN_OUTPUT);
	DIO_vWritePinDirection(S2P_PORT,  S2P_DATA          ,   DIO_PIN_OUTPUT);

	DIO_vWritePinVAlue(S2P_PORT  ,  S2P_SHIFT_CLOCK  ,  DIO_PIN_LOW );
}

void S2P_vKICK (void)
{

	DIO_vWritePinVAlue(S2P_PORT  , S2P_SHIFT_CLOCK  ,DIO_PIN_HIGH );
	//delay  for one micro sec
	_delay_us(1);
	DIO_vWritePinVAlue(S2P_PORT  , S2P_SHIFT_CLOCK  ,DIO_PIN_LOW );
	_delay_us(1);

}

void S2P_vLATCH (void)
{
	DIO_vWritePinVAlue(S2P_PORT  , S2P_LATCH  ,DIO_PIN_HIGH );
	//delay  for one micro sec
	_delay_us(1);
	DIO_vWritePinVAlue(S2P_PORT  , S2P_LATCH  ,DIO_PIN_LOW );
	_delay_us(1);
}



void S2P_vSendByte (u8 A_u8Data)
{
	for (int i =0; i< NO_REG*8 ; i++)
	{
		DIO_vWritePinVAlue(S2P_PORT  , S2P_DATA  , GET_BIT(A_u8Data,i) );
		S2P_vKICK();
	}
	S2P_vLATCH();

}
void S2P_vSendData (u8 A_u8Data[])
{
	u8 iterator=0;

	while (A_u8Data[iterator] != '\0')
	{
		S2P_vSendByte(A_u8Data[iterator]);
		iterator++;
	}

}
