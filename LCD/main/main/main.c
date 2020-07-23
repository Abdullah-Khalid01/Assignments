/*
 * main.c
 *
 * Created: 21/11/41 02:35:49 م
 *  Author: ABDULLAH 01
 */ 


//#include <avr/io.h>
#include "LCD.h"
int main(void)
{
	uint16 temp=0;
	uint8 value=0;
	uint8 password[4]={0};
	uint8 password_re[4]={0};
	LCD_INIT();
    Keypad_Init();
	TempsSensor_INIT();
	
		
    while(1)
    {	
		
		
		LCD_WriteString("ENTER PASSWORD:");
		_delay_ms(2000);
		LCD_CLEAR();
		
		for (uint8 i=0;i<4;i++)
		{
			while(!value)
			{
				value=Keypad_GetValue();
			}
			LCD_WRITE_CHARACHTER(value);
			password[i]=value;
			value=0;
			if (i==3)
			{
				LCD_CLEAR();
			}
		}
		LCD_WriteString("REENTER TO UNLOCK");
		_delay_ms(2000);
		LCD_CLEAR();
		for (uint8 i=0;i<4;i++)
		{
			while(!value)
			{
				value=Keypad_GetValue();
			}
			LCD_WRITE_CHARACHTER(value);
			password_re[i]=value;
			value=0;
			if (i==3)
			{
				LCD_CLEAR();
				break;
			}
		}
		for (uint8 i=0;i<4;i++)
		{
			static uint8 counter=0;
			if (password_re[i]==password[i])
			{
				
				if (counter==3)
				{
					LCD_WriteString("Welcome");
					_delay_ms(2000);
					LCD_CLEAR();
					LCD_WriteString("Temp. is: ");
					value=0;
					while(!value)
					{
						
					TempSensor_READ(&temp);
				//	LCD_CLEAR();
					
					LCD_WriteInteger(temp);
					_delay_ms(1000);
					LCD_MoveTo(0,10);
				//	LCD_MoveTo(1,0);
					}					
					
				}
				counter++;
			}
			else
			{
				LCD_WriteString("Wrong PASSWORD");
				_delay_ms(1000);
				break;
			}
		}
		
		
      /*		
		value=Keypad_GetValue();
		if(value)
		{
			static uint8 counter=0;
			counter++;
       LCD_WRITE_CHARACHTER(value);
	   if(counter==16)
	   {
		   LCD_MoveTo(1,0);
	   }		   
		}	
		*/   
    }
}