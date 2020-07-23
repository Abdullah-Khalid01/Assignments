/*
 * ADC.c
 *
 * Created: 25/11/41 06:36:26 ص
 *  Author: ABDULLAH 01
 */ 


#include "LCD.h"
#include "Temp_sensor.h"
#define F_CPU 16000000
#include <util/delay.h>

int main(void)
{
	uint16 temp=0;
	LCD_Init();
	TempsSensor_INIT();
    while(1)
    {
        
        TempSensor_READ(&temp); 
		
		LCD_Clear();
		
		LCD_WriteInteger(temp);
		
		_delay_ms(500);
    }
}