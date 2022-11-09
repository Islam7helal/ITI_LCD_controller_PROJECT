// this is UART_program.c 
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "UART_interface.h" 
#include "UART_private.h" 
#include "UART_config.h" 



static u8 USART_DataSend;
static u8 USART_u8BusyState= IDLE;
static u8 USART_u8ISRSource;
static void (*USART_pvCallBackNotificationFunc)(void)=NULL;
static char * USART_pcString = NULL;
static u8 USART_u8ChainCharSendingIndex;

static u8 * USART_RecievedData = NULL;
static u8 USART_BufferSize;
static u8 * USART_ReceivedBuffer = NULL;



void UART_vInit(void)
{

	/* Temporary variable to write UCSRC register */
	u8 Temp_u8UcsrcData;

	/* Clear any rubbish values in the variable */
	Temp_u8UcsrcData = 0;

	/*SET Register UCSRC*/
	SET_BIT(Temp_u8UcsrcData,UCSRC_URSEL);

	/* Select DATA Size */

#if UART_dataSize == BITS_5
	CLR_BIT(Temp_u8UcsrcData,UCSRC_UCSZ0);
	CLR_BIT(Temp_u8UcsrcData,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

#elif UART_dataSize == BITS_6
	SET_BIT(Temp_u8UcsrcData,UCSRC_UCSZ0);
	CLR_BIT(Temp_u8UcsrcData,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

#elif UART_dataSize == BITS_7
	CLR_BIT(Temp_u8UcsrcData,UCSRC_UCSZ0);
	SET_BIT(Temp_u8UcsrcData,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

#elif UART_dataSize == BITS_8
	SET_BIT(Temp_u8UcsrcData,UCSRC_UCSZ0);
	SET_BIT(Temp_u8UcsrcData,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

#elif UART_dataSize == BITS_9
	SET_BIT(Temp_u8UcsrcData,UCSRC_UCSZ0);
	SET_BIT(Temp_u8UcsrcData,UCSRC_UCSZ1);
	SET_BIT(UCSRB,UCSRB_UCSZ2);

#endif

	/* Asynchronous Mode */
#if UART_MODE == ASYNCHRONOUS
	CLR_BIT(Temp_u8UcsrcData,UCSRC_UMSEL);
#elif UART_MODE == SYNCHRONOUS
	SET_BIT(Temp_u8UcsrcData,UCSRC_UMSEL);
#endif

	/*select normal speed and baudrate to 9600*/
	CLR_BIT(UCSRA,UCSRA_U2X);
	UBRRH = 0;
	UBRRL = 51;



	/*Select parity */
#if UART_PARITY == EVEN_PARITY
	CLR_BIT(Temp_u8UcsrcData,UCSRC_UPM0);
	SET_BIT(Temp_u8UcsrcData,UCSRC_UPM1);
#elif UART_PARITY == ODD_PARITY
	SET_BIT(Temp_u8UcsrcData,UCSRC_UPM0);
	SET_BIT(Temp_u8UcsrcData,UCSRC_UPM1);
#elif UART_PARITY == NO_PARITY
	CLR_BIT(Temp_u8UcsrcData,UCSRC_UPM0);
	CLR_BIT(Temp_u8UcsrcData,UCSRC_UPM1);

#endif

	/*Stop Bit Select*/
#if UART_stopBits == BITS_1
	CLR_BIT(Temp_u8UcsrcData,UCSRC_USBS);

#elif UART_stopBits == BITS_2
	SET_BIT(Temp_u8UcsrcData,UCSRC_USBS);
#else
#error "Wrong Choice USART Stop Bit Select"
#endif


	/* Update UCSRC register with Temp Data */
	UCSRC = Temp_u8UcsrcData;

	/* Enable Rx and Tx */
#if UART_ENABLE_TX == TRUE
	SET_BIT(UCSRB,UCSRB_TXEN);
#endif
#if UART_ENABLE_RX == TRUE
	SET_BIT(UCSRB,UCSRB_RXEN);
#endif

}

void UART_vSendByte(u8 Byte)
{
	/* Waiting till UDR register is Empty */
	while(GET_BIT(UCSRA,5) == 0);

	/* Update UDR register with the data needs to be sent */
	UDR = Byte;
}

u8   UART_u8ReceiveByte(void)
{
	/* Waiting till RxC flag raise */
	while(GET_BIT(UCSRA,7) == 0);

	/* Return the received Byte */
	return UDR;
}


void UART_vSendString(char Pu8Data[])
{
	u8 u8LoopCtr=0;
	while(Pu8Data[u8LoopCtr]!=0x00)//fakt l gomla dy *(Pu8DAta+u8loopctr) da nzakr pointer aw c ya man b2a
	{
		UART_vSendByte(Pu8Data[u8LoopCtr]);
		u8LoopCtr++;

	}
//	UART_u8ReceiveByte('/r');
//	UART_u8ReceiveByte('/n');
}
