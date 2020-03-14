#include "Kpad.h"
#include "Gpio.h"

// for save the call back fun to call it in MainFunction 
static void (*ptr_CallBackFun)(uint8);
const unsigned char linha[4] = {TL1, TL2, TL3};
uint8 Kpad_Enable;

static unsigned char Get_key() {
    unsigned char i;
    unsigned char ret = 0;
    Gpio_Kpad_Cfg();
    for (i = 0; i < 3; i++) {
        PORTB |= (~linha[i]);
        if (!TC1) {
            __delay_ms(20);
            if (!TC1) {
                while (!TC1);
                ret = Kpad_arr[0][i];
                break;
            }
        };
        if (!TC2) {
            __delay_ms(20);
            if (!TC2) {
                while (!TC2);
                ret = Kpad_arr[1][i];
                break;
            }
        };
        if (!TC3) {
            __delay_ms(20);
            if (!TC3) {
                while (!TC3);
                ret = Kpad_arr[2][i];
                break;
            }
        };
        if (!TC4) {
            __delay_ms(20);
            if (!TC4) {
                while (!TC4);
                ret = Kpad_arr[3][i];
                break;
            }
        };
        PORTB &= linha[i];
    }
    return ret;
}

void kpad_init(void (*P2F)(uint8)) {
    Gpio_Kpad_Cfg();
    ptr_CallBackFun = P2F;
}


void KPad_MainFunction() 
{
        uint8 key;
        Gpio_Kpad_Cfg();
        key = Get_key();
        if (key != 0) {
            ptr_CallBackFun(key);
        }
    
}