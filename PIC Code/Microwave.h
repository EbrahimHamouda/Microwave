/* 
 * File:   Display.h
 * Author: ebrah
 *
 * Created on February 27, 2020, 9:43 AM
 */

#ifndef DISPLAY_H
#define	DISPLAY_H
#include "ebra_common.h"
#include "Kpad.h"
#include "Lcd.h"
#include "TMU.h"
#include "ADC.h"


typedef enum
{
    IDEAL,
    READY,
    WORKING,
    SUSPEND
} Microwave_State_t;

Microwave_State_t Microwave_state;
uint8 Operation_Flag;

void Microwave_init(void);
void Microwave_GetInputs_Cbk(uint8 key);
void Microwave_UpdateTime_Cbk (void);
void Microwave_MainFanction(void);

#endif	/* DISPLAY_H */

