/*
 * main.c
 *
 * Created: 16/12/41 11:49:58 ص
 *  Author: ABDULLAH 01
 */ 

#include "Timer.h"
#include "LCD.h"


extern uint32 ICU_ReadCapturedVal_1 ;
extern uint32 ICU_ReadCapturedVal_2 ;
extern uint32 ICU_ReadCapturedVal_3 ;
extern uint8 Cap_Counter;
int main(void)
{
	uint32 Duty = 0;
	uint32 frequency =0;
	
	PWM2_Init();
	LCD_INIT();
	PWM2_generate(70);
	
	ICU_Init();
	
	LCD_WriteString("WELCOME");
	
	LCD_CLEAR();
    while(1)
    {
       if (Cap_Counter == 3)
       {
		   Duty =((ICU_ReadCapturedVal_2 - ICU_ReadCapturedVal_1) * 100) / (ICU_ReadCapturedVal_3 - ICU_ReadCapturedVal_1);
		   
		   frequency = 8000000 /(ICU_ReadCapturedVal_3 - ICU_ReadCapturedVal_1);
		   
		   LCD_MoveTo(0,0);
		   
		   LCD_WriteString("Duty Cycle :");
		   
		   LCD_WriteInteger(Duty);
		   
		   LCD_WRITE_CHARACHTER('%');
		   
		   LCD_MoveTo(1,0);
		   
		   LCD_WriteString("Freq. :");
		   
		   LCD_WriteInteger(frequency);
		   
		   LCD_WriteString("Hz");
		   
		   Cap_Counter = 0;
		   
		   Set_bit(TIMSK,5);
       }
    }
}