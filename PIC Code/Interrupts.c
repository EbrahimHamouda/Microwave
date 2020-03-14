#include "ebra_common.h"
#include "TMU.h"

void Enable_Interrupts()
{
    IPEN =1;
    GIE=1;
    PEIE=1;  
}


 


void  interrupt low_priority isrl()
{
    if(TMR0IF)
    {
        TMR0IF =0;
        TMU_Cbk();
        TMR0L =6;
    } 
}
