
#include "ADC.h"


void adc_init(void)
{
  ADCON0=0x01;
  ADCON1=0x0B;
  ADCON2=0x01;
}

unsigned int ADC_Read(unsigned char canal)
{
 switch(canal)
    {
      case 0: 
        ADCON0=0x01;
        break;
      case 1: 
        ADCON0=0x05;
        break;
      case 2: 
        ADCON0=0x09;
        break;
    }   
    ADCON0bits.GO=1;
    while(ADCON0bits.GO == 1);

   return ((((unsigned int)ADRESH)<<2)|(ADRESL>>6));
}
