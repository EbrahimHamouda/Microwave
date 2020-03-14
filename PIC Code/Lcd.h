/* 
 * File:   Lcd.h
 * Author: ebrah
 *
 * Created on February 25, 2020, 9:08 AM
 */

#ifndef LCD_H
#define	LCD_H
#include "ebra_common.h"

#define EN_PIN    PORTEbits.RE1
#define RS_PIN    PORTEbits.RE2
#define DATA_PORT     PORTD

#define LCD_DISPLAY_OFF	    0x08
#define LCD_CLEAR_SCREEN	0x01
#define LCD_ROW_0           0x80
#define LCD_ROW_1           0xC0
#define LCD_CURSOR_BLINK	0x0F
#define LCD_CURSOR_OFF      0x0C
#define LCD_8BIT_MODE       0x38

void Lcd_Init(void);
void Lcd_Cmd(uint8 val); 
void Lcd_Chr(uint8 val);
void Lcd_Str(const uint8* str);
void Lcd_Goto(uint8 row, uint8 col);
void Lcd_num(uint16 num);
#endif	/* LCD_H */

