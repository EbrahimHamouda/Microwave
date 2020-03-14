

#include "Timer.h"


void Timer_init(void)
{
    T08BIT=1; // 8-bit timer
    T0CS=0;   //  internal clock
    
    PSA =0;   //  Prescaler /16  
    T0PS0=1;
    T0PS1=1;
    T0PS2=0;
    TMR0IP=0; // low priority 
}


void Timer_Start(void)
{
    TMR0L =6;
    TMR0ON = 1;
    TMR0IE =1;
}

void Timer_Stop(void)
{
    TMR0ON = 0;
    TMR0IE =0;
}