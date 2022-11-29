#include "mbed.h"
#include "LCD_DISCO_F469NI.h"
#include "makra.h"


LCD_DISCO_F469NI lcd;

Thread thread1, thread2, thread3;



void text1_thread()
{   
    while (true)
    {

            lcd.SetTextColor(BARVA1);
            lcd.DisplayStringAtLine(SMER1, (uint8_t *)TEXT1);

            ThisThread::sleep_for(CAS1);
            lcd.ClearStringLine(SMER1);
            ThisThread::sleep_for(CAS1);
        
    }
}

void text2_thread()
{   
    while (true)
    {

            lcd.SetTextColor(BARVA2);
            lcd.DisplayStringAtLine(SMER2, (uint8_t *)TEXT2);

            ThisThread::sleep_for(CAS2);
            lcd.ClearStringLine(SMER2);
            ThisThread::sleep_for(CAS2);
        
    }
}

void text3_thread()
{   
    while (true)
    {

            lcd.SetTextColor(BARVA3);
            lcd.DisplayStringAtLine(SMER3, (uint8_t *)TEXT3);

            ThisThread::sleep_for(CAS3);
            lcd.ClearStringLine(SMER1);
            ThisThread::sleep_for(CAS3);
        
    }
}


int main()
{    
    thread1.start(text1_thread());
    thread2.start(text2_thread());
    thread3.start(text3_thread());
}


