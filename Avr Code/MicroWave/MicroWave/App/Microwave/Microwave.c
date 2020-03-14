
#include "Microwave.h"
#include "ECUS.h"
#include <util/delay.h>
uint8 arr_sec[4] = {0, 0, 0, 0};
uint8 Clear_arr[16] = "                ";
volatile uint32 Seconds;
static uint8 Microwave_ChangeFlag = 0;
static uint8 Arr_SecIndex = 0;
static Microwave_State_t Microwave_state;
struct_PinsCnfg_t mylcd={{C4,C5,C6,C7},
						C3,
						C2};
						
KeyPad_PinCnfg_t mykeypad={{D4,D5,D6,D7},
						   {D3,D2,D1}};

void Microwave_InsertMessage(uint8* message)
{   
    lcd_goto(&mylcd,1, 0);
    lcd_str(&mylcd,Clear_arr);
    lcd_goto(&mylcd,1, 0);
    lcd_str(&mylcd,message);
}

void Update_Seconds()
{
    arr_sec[0] = Seconds / 600;
    arr_sec[1] = (Seconds % 600) / 60;
    arr_sec[2] = ((Seconds % 600) % 60) / 10;
    arr_sec[3] = ((Seconds % 600) % 60) % 10;
    lcd_goto(&mylcd,0, 0);
    lcd_chr(&mylcd,arr_sec[0] + 48);
    lcd_chr(&mylcd,arr_sec[1] + 48);
    lcd_chr(&mylcd,':');
    lcd_chr(&mylcd,arr_sec[2] + 48);
    lcd_chr(&mylcd,arr_sec[3] + 48);
}

uint8 Check_Door()
{
    uint16 val;
    val = adc_read(CHANNEL1);
    if (val == 1023)
    {
        return 1;
    }
    else
    {
        Microwave_InsertMessage("Door open!");
        return 0;
    }
}

uint8 Check_weight()
{
    uint16 val;
    val = adc_read(CHANNEL0);
    if (val == 0)
    {
        Microwave_InsertMessage("Oven Empty!");        
        return 0;
    }
    else
    {
        if (val > 500)
        {
            Microwave_InsertMessage("Over Weight!");
            return 0;
        }
        else
        {
            return 1;
        }
    }
}

void Microwave_init(void)
{
    Microwave_state = IDEAL;
    lcd_init(&mylcd);
    key_pad_init(&mykeypad,Microwave_GetInputs_Cbk);
    BAZZER_init;
    MLH_init;
    TMU_init(Microwave_UpdateTime_Cbk);
    adc_init(AVCC,FREE_RUNNING_MODE,CLK_ADC_DIV_128);

    lcd_goto(&mylcd,0, 0);
    lcd_str(&mylcd,"00:00");
    Microwave_InsertMessage("welcome");
    _delay_ms(1000);
    lcd_goto(&mylcd,1, 0);
    lcd_str(&mylcd,Clear_arr);
    lcd_goto(&mylcd,0, 0);
}
void Microwave_GetInputs_Cbk(uint8 key)
{

    BAZZER_ON;
    _delay_ms(200);
    BAZZER_OFF;

    if ((key != '#') && (key != '*')) // Set timing
    {
        if (Arr_SecIndex < 4)
        {
            lcd_chr(&mylcd,key);
            arr_sec[Arr_SecIndex++] = (key - 48);
            if (Arr_SecIndex == 2) // to skip : in the display
            {
                lcd_goto(&mylcd,0, 3);
            }
            if (Arr_SecIndex == 4)
            {
                Microwave_ChangeFlag = 1;
                Microwave_state = READY;
            }
        }
        else
        {
            // never be here
        }
    }
    else // Set control Start or stop
    {
        Microwave_ChangeFlag = 1;
        if (key == '#')
        {
            if (Microwave_state == SUSPEND)
            {
                Microwave_state = WORKING;
            }
            else
            {
                Microwave_state = READY;
            }
        }
        else
        {
            if (Microwave_state == SUSPEND)
            {
                Microwave_state = IDEAL; // CLEAR EVERY THING
            }
            else
            {
                Microwave_state = SUSPEND;
            }
        }
    }
}

void Microwave_MainFanction(void)
{
    if (Microwave_ChangeFlag)
    {
        Microwave_ChangeFlag = 0;
        switch (Microwave_state)
        {
        case IDEAL: //
            Arr_SecIndex = 0;
            arr_sec[0] = 0;
            arr_sec[1] = 0;
            arr_sec[2] = 0;
            arr_sec[3] = 0;
            Seconds = 0;
            lcd_goto(&mylcd,1, 0);
            lcd_str(&mylcd,Clear_arr);
            lcd_goto(&mylcd,0, 0);
            lcd_str(&mylcd,"00:00");
            lcd_goto(&mylcd,0, 0);
            lcd_cmd(&mylcd,CURSOR_BLINK);
            break;

        case READY:
            if (Check_Door())
            {
                if (Check_weight())
                {
                    if (Arr_SecIndex == 0)                     {
                        Seconds += 30;   // multiple times of 30 seconds
                        Update_Seconds();
                    }
                    else
                    {
                        Seconds = (arr_sec[0] * 600) + (arr_sec[1] * 60) +
                                  (arr_sec[2] * 10) + (arr_sec[3]);
                    }
                    Microwave_state = WORKING;
                    Microwave_ChangeFlag = 1;
                }
            }
            break;

        case WORKING:
            TMU_TriggerEvent();
            lcd_cmd(&mylcd,CURSOR_OFF);
            MLH_ON;
            Microwave_InsertMessage("Heating");
            break;

        case SUSPEND:
            TMU_EndEvent();
            MLH_OFF;
            Microwave_InsertMessage("Pause");
            break;

        default:
            break;
        }
    }
}

void Microwave_UpdateTime_Cbk(void)
{
    if (Seconds != 0)
    {
        Seconds--;
        Update_Seconds();
    }
    else
    {
        TMU_EndEvent();
        MLH_OFF;
        for (uint8 i = 0; i < 8; i++)
        {
            lcd_goto(&mylcd,1, 0);
            if (i % 2 == 0)
            {
                BAZZER_ON;
                lcd_str(&mylcd,"DONE");
            }
            else
            {
                BAZZER_OFF;
                lcd_str(&mylcd,Clear_arr);
            }
            _delay_ms(500);
        }
        Microwave_ChangeFlag = 1;
        Microwave_state = IDEAL;
    }
}