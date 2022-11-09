/*
 * LCD_config.h
 *
 *  Created on: Sep 10, 2022
 *      Author: User
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*
 * Configurations
 */

#define LCD_DATA_PORT		DIO_PORTA   //PORTA

#define LCD_CTRL_PORT		DIO_PORTA   //PORTA
#define LCD_RS_PIN			PIN0
#define LCD_RW_PIN			PIN1
#define LCD_E_PIN			PIN4

#define lcd_mode_4_8        lcd_FunctionSet4bit

#endif /* LCD_CONFIG_H_ */
