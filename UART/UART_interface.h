// this is UART_interface.h 
#ifndef UART_interface_H
#define UART_interface_H


#define TRUE  	1
#define FASLE 	0

#define BITS_1 	0
#define BITS_2 	1

#define BITS_5	0
#define BITS_6	1
#define BITS_7	2
#define BITS_8	3
#define BITS_9	7

#define NO_PARITY	0
#define EVEN_PARITY	2
#define ODD_PARITY	3

#define IDLE        0
#define BUSY	    1


void UART_vInit(void);

void UART_vSendByte(u8 Byte);

u8   UART_u8ReceiveByte(void);

void UART_vSendString(char Pu8Data[]);

//---------------------------------------------------------------------------------------------


u8 USART_voidSendCharSynch(u8 Copy_u8Data);
u8 USART_u8SendStringSynch(char * Copy_pcString);

u8 USART_u8SendCharAsynch(u8 Copy_u8Data , void(*Copy_pvNotificationFunc)(void));
u8 USART_u8SendStringAsynch(char * Copy_pcString , void(*Copy_pvNotificationFunc)(void));

u8 USART_u8RecieveCharSynch(void);
u8 USART_u8RecieveCharAsynch(u8 * Copy_u8ReceivedData,void(*Copy_pvNotificationFunc)(void));

u8 USART_voidReceiveBufferSynch(u8 * Copy_u8Buffer , u8 Copy_u8BufferSize);
u8 USART_voidReceiveBufferAsynch(u8 * Copy_u8Buffer , u8 Copy_u8BufferSize , void(*Copy_pvNotificationFunc)(void));







#endif /* UART_INT_H_ */
 
