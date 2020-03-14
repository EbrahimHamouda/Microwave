/*
 * MicroWave.c
 *
 * Created: 3/13/2020 9:49:26 AM
 * Author : ebrah
 */ 


#include "Microwave.h"
#include <avr/interrupt.h>

extern KeyPad_PinCnfg_t mykeypad;

int main(void)
{
	Microwave_init();
	sei();
    while (1) 
    {
		Microwave_MainFanction();
		keyPad_dispatcher(&mykeypad);
		TMU_MainFunction();
    }
}

