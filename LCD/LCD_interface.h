/*
 * LCD_interface.h
 *
 *  Created on: Sep 10, 2022
 *      Author: User
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


/*
 * Public Functions Prototype
 */

void LCD_SendChar(u8 A_u8Charachter);

void LCD_SendCmd(u8 A_u8CMD);

void LCD_INIT(void);

void LCD_Clear(void);

void LCD_print_string(u8 A_u8str[]);

void LCD_print_num(u32 A_u32num);



#endif /* LCD_INTERFACE_H_ */
