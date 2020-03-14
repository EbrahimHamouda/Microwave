
#include "Lcd.h"
#include "Gpio.h"
#include <stdlib.h> 

static void Lcd_Write(uint8 val)
{
  DATA_PORT=val;
}

void Lcd_Cmd(uint8 val)
{
    Gpio_Lcd_Cfg();
    EN_PIN=1;
    Lcd_Write(val);
    RS_PIN=0;
    __delay_ms(3);
    EN_PIN=0;
    __delay_ms(3);
    EN_PIN=1;
}
 
void Lcd_Chr(uint8 val)
{
    Gpio_Lcd_Cfg();
    EN_PIN=1;
    Lcd_Write(val);
    RS_PIN=1;
    __delay_ms(1);
    EN_PIN=0;
    __delay_ms(1);
    EN_PIN=1;
}

void Lcd_Init(void)
{
    Gpio_Lcd_Cfg();
    RS_PIN=0;
    EN_PIN=0;
    __delay_ms(20);
    EN_PIN=1;
	Lcd_Cmd(LCD_8BIT_MODE);
    __delay_ms(5);
    Lcd_Cmd(LCD_8BIT_MODE);
    __delay_ms(1);
    Lcd_Cmd(LCD_8BIT_MODE);
    Lcd_Cmd(LCD_DISPLAY_OFF);
    Lcd_Cmd(LCD_CURSOR_BLINK);
	Lcd_Cmd(LCD_CLEAR_SCREEN);  
	Lcd_Cmd(LCD_8BIT_MODE); 
    Lcd_Goto(0,0);
}

void Lcd_Str(const char* str)
{
 unsigned char i=0;
 while(str[i] != 0 )
 {
   Lcd_Chr(str[i]);
   i++;
 }  
}

void Lcd_Goto(uint8 row, uint8 col)
{
    if (row == 0)
	{
		Lcd_Cmd(((uint8)LCD_ROW_0) | col);
	}
	else 
	{
		Lcd_Cmd((uint8)LCD_ROW_1 | col);
	}
}

void Lcd_num(uint16 num)
{
    uint8 num_str[5];
    itoa(num_str,num,10);
    Lcd_Str(num_str);
}






 
