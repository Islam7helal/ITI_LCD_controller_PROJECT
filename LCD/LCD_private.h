/*
 * LCD_private.h
 *
 *  Created on: Sep 10, 2022
 *      Author: User
 */

#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

#define lcd_Clear           0x01          /* replace all characters with ASCII 'space'                       */
#define lcd_Home            0x02          /* return cursor to first position on first line                   */
#define lcd_EntryMode       0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOff      0x08          // turn display off
#define lcd_DisplayOn       0x0C          // display on, cursor off, don't blink character
#define lcd_FunctionReset   0x30          // reset the LCD
#define lcd_FunctionSet8bit 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_FunctionSet4bit 0x28          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor       0x80          // set cursor position

#define CGRAM_BASE_ADDRESS  0x40          // CGRAM BASE ADDRESS
#define DDRAM_BASE_ADDRESS  0x80          // DDRAM BASE ADDRESS




#endif /* LCD_PRIVATE_H_ */
