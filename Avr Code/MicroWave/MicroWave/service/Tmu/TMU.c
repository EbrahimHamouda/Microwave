
#include "TMU.h"

static void (*Callback_Event)();
static uint16 Scounter;
volatile static uint8 Event_DoneFlage,Event_StatusFlage;

void TMU_init(void (*P2F)())
{
	Scounter = 1000;
    Timer_init();
    Callback_Event = P2F;
}

void TMU_TriggerEvent ()
{
    Scounter = 1000; 
    Timer_Start();
}

void TMU_EndEvent(void)
{
    Event_StatusFlage=0;
    Timer_Stop();
}

void TMU_MainFunction(void)
{
    if(Event_DoneFlage==1)
    {
        Event_DoneFlage=0;
        Callback_Event();
    }
}

void TMU_Cbk(void)
{
    if(Scounter==0)
    {
        Event_DoneFlage =1;
        Scounter = 1000;
    }
    else
    {
        Scounter--;
    }
}