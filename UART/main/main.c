/*
 * main.c
 *
 * Created: 04/12/41 12:45:36 م
 *  Author: ABDULLAH 01
 */ 


#include "UART.h"
#include "LCD.h"
#include <util/delay.h>
int main(void)
{
	uint8 Rx_Data=0;
	/*
	UART_INIT();
	UART_SendString("HELLO");
	LCD_INIT();
	*/
    while(1)
    {
		Rx_Data =UART_RecieveByte();
		
		_delay_ms(100);
		
		LCD_WRITE_CHARACHTER(Rx_Data);
        //TODO:: Please write your application code 
    }
}