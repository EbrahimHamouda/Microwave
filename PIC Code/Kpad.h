/* 
 * File:   Kpad.h
 * Author: ebrah
 *
 * Created on February 25, 2020, 12:47 PM
 */

#ifndef KPAD_H
#define	KPAD_H
#include "ebra_common.h"
#include "Gpio.h"


#define TL1 0x01
#define TL2 0x02
#define TL3 0x04

#define TC1 PORTDbits.RD3
#define TC2 PORTDbits.RD2
#define TC3 PORTDbits.RD1
#define TC4 PORTDbits.RD0


uint8 Kpad_arr[4][3]=
{
    {'1','2','3'},   
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
};

void kpad_init(void (*P2F)(uint8));
void KPad_MainFunction (void);


#endif	/* KPAD_H */

