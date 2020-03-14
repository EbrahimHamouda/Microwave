/*
 * File:   gpio.c
 * Author: ebrah
 *
 * Created on February 14, 2020, 3:28 PM
 */
#include <xc.h>

void Gpio_Kpad_Cfg()
{
    TRISD |= 0x0f;
    TRISB &= 0xf8;
}

void Gpio_Lcd_Cfg()
{
      TRISE=0x00;
      TRISD=0x00;
}
