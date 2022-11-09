// this is UART_config.h 
#ifndef UART_config_H
#define UART_config_H



/* stop bits config */
/*
 * OPTIONS :-
 * 			1- BITS_1
 * 			2- BITS_2
 */

#define UART_stopBits BITS_1


//------------------------------------------------------------------------------------
/* data bits 5,6,7,8,9 config */
/*
 * OPTIONS :-
 *           1- BITS_5
 *           2- BITS_6
 *           3- BITS_7
 *           4- BITS_8
 *           5- BITS_9
 */

#define UART_dataSize BITS_8


//------------------------------------------------------------------------------------
/* parity bits config */
/*
 * OPTIONS :-
 * 			1-ODD_PARITY
 * 			2-EVEN_PARITY
 * 			3-NO_PARITY
 */
#define UART_PARITY EVEN_PARITY


//------------------------------------------------------------------------------------
/* UART mode
 * OPTIONS :-
 * 			1-SYNCHRONOUS
 * 			2-ASYNCHRONOUS
 */

#define UART_MODE ASYNCHRONOUS


//------------------------------------------------------------------------------------
/* TX and RX interrupt enable */
/*
 *   TRUE ==> enabled
 *   FALSE ===> disabled
 *
 *
 */
#define UART_interruptEnable_RX TRUE  //recieve complete  interrupt
#define UART_interruptEnable_TX TRUE  //transmite interrupt
#define UART_interruptEnable_DRE TRUE  //data register empty interrupt

//------------------------------------------------------------------------------------
/* baud rate config */


//------------------------------------------------------------------------------------
/* TX and RX enable (TRUE - FALSE )
 *   TRUE ==> enabled
 *   FALSE ===> disabled
 *
 */
#define UART_ENABLE_TX TRUE // enable the transmit in the uart
#define UART_ENABLE_RX TRUE // enable the recieve in the uart

#endif /* UART_CFG_H_ */
 

