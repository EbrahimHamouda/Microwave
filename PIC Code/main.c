#include "ebra_common.h"
#include "Microwave.h"
#include "Delay.h"
uint16 val;



void main()
{
   Microwave_init();

   Enable_Interrupts();
   while (1)
   {
      TMU_MainFunction();
      KPad_MainFunction();
      Microwave_MainFanction();
   }
}
