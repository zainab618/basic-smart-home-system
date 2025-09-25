/*
 * LCD_interfac.h
 *
 *  Created on: Jun 30, 2025
 *      Author: Ahmed Saeed
 */
#include "STD_TYPES.h"
#ifndef LCD_INTERFAC_H_
#define LCD_INTERFAC_H_

#define lcd_Clear           0x01          /* replace all characters with ASCII 'space'                       */
#define lcd_Home            0x02          /* return cursor to first position on first line                   */
#define lcd_EntryMode       0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOff      0x08          // turn display off
#define lcd_DisplayOn       0x0C          // display on, cursor off, don't blink character
#define lcd_FunctionReset   0x30          // reset the LCD
#define lcd_FunctionSet8bit 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor       0x80          // set cursor position

void LCD_Init(void);
void LCD_SendChar(u8 charachter);
void LCD_SendCommand(u8 command);

void LCD_GotoXY(u8 x ,u8 y);
void LCD_Clear(void);
void LCD_SendString(const char* str);


#endif /* LCD_INTERFAC_H_ */
