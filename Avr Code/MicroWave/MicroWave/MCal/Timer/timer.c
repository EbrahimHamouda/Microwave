/*
 * timer.c
 *
 * Created: 3/13/2020 10:54:58 AM
 *  Author: ebrah
 */ 
#include "timer.h"
#include <avr//io.h>
#include <avr/interrupt.h>
#include "TMU.h"
ISR(TIMER0_OVF_vect)
{
	TMU_Cbk();
	TCNT0=131;
}

void Timer_init(void)
{
	TIMSK |= 1<<0;	//enable interrupt for timer
	TCCR0 |= 1<<1;	// TCCR0 for edjust the resolution
	TCNT0 =131;
}


void Timer_Start(void)
{
	TIMSK |= (1<<0);	//Enable interrupt for timer
}

void Timer_Stop(void)
{
	TIMSK &= ~(1<<0);	//disable interrupt for timer
}