/*
 * File:   delay.c
 * Author: ebrah
 *
 * Created on February 14, 2020, 1:44 PM
 */
#include "Delay.h"
#include "ebra_common.h"


void delay_ms(unsigned int duration) 
{
   volatile unsigned int  i;
 for (i =0; i< duration; i++)
 {
     __delay_ms(1);
 }
}
			