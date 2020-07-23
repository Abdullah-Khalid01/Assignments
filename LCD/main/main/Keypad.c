/*
 * Keypad.c
 *
 * Created: 29/11/41 12:16:24 ص
 *  Author: ABDULLAH 01
 */ 

#include "keypad.h"
//#include "DIO.h"
#define F_CPU 16000000
#include <util/delay.h>

uint8 pass[4];
uint8 *arr_ptr =pass;

#define LOC_COL_INIT  0

#define LOC_COL_FINAL 3

#define LOC_ROW_INIT  4

#define LOC_ROW_FINAL 7

#define NOT_PRESSED   0

const uint8 Keypad_Elements[4][4]={  {'7','8','9','/'},
                                    {'4','5','6','*'},
								    {'1','2','3','-'},
								    {'c','0','=','+'} };	 
								 
void Keypad_Init(void)
{
	DIO_SetPINDIR(KEYPAD_PORT  , KEYPAD_COL0 , DIO_PIN_OUTPUT);
	DIO_SetPINDIR(KEYPAD_PORT  , KEYPAD_COL1 , DIO_PIN_OUTPUT);
	DIO_SetPINDIR(KEYPAD_PORT  , KEYPAD_COL2 , DIO_PIN_OUTPUT);
	DIO_SetPINDIR(KEYPAD_PORT  , KEYPAD_COL3 , DIO_PIN_OUTPUT);
	
	DIO_SetPINDIR(KEYPAD_PORT  , KEYPAD_ROW0 , DIO_PIN_INPUT);
	DIO_SetPINDIR(KEYPAD_PORT  , KEYPAD_ROW1 , DIO_PIN_INPUT);
    DIO_SetPINDIR(KEYPAD_PORT  , KEYPAD_ROW2 , DIO_PIN_INPUT);
	DIO_SetPINDIR(KEYPAD_PORT  , KEYPAD_ROW3 , DIO_PIN_INPUT);
	
	DIO_SetPullUp(KEYPAD_PORT,KEYPAD_ROW0);
	DIO_SetPullUp(KEYPAD_PORT,KEYPAD_ROW1);
	DIO_SetPullUp(KEYPAD_PORT,KEYPAD_ROW2);
	DIO_SetPullUp(KEYPAD_PORT,KEYPAD_ROW3);
	
	DIO_WritePIN(KEYPAD_PORT , KEYPAD_COL0 ,DIO_PIN_HIGH);
	DIO_WritePIN(KEYPAD_PORT , KEYPAD_COL1 ,DIO_PIN_HIGH);
	DIO_WritePIN(KEYPAD_PORT , KEYPAD_COL2 ,DIO_PIN_HIGH);
	DIO_WritePIN(KEYPAD_PORT , KEYPAD_COL3 ,DIO_PIN_HIGH);
	
}

uint8 Keypad_GetValue(void)
{
	uint8 LOC_COL=0;
	
	uint8 LOC_ROW=0;
	
	uint8 value=0;
	
	uint8 temp=0;
	
	for (LOC_COL=LOC_COL_INIT;LOC_COL<=LOC_COL_FINAL;LOC_COL++)
	{
		DIO_WritePIN(KEYPAD_PORT , LOC_COL ,DIO_PIN_LOW);
		
		for (LOC_ROW=LOC_ROW_INIT;LOC_ROW<=LOC_ROW_FINAL;LOC_ROW++)
		{
			DIO_ReadPin(KEYPAD_PORT,LOC_ROW,&temp);
			
			if (!temp)
			{
				value=Keypad_Elements[LOC_ROW-LOC_ROW_INIT][LOC_COL-LOC_COL_INIT];
				
				while (!temp)
				{
					DIO_ReadPin(KEYPAD_PORT,LOC_ROW,&temp);
				}
				_delay_ms(10);
			}
		}
		
		DIO_WritePIN(KEYPAD_PORT , LOC_COL ,DIO_PIN_HIGH);
	}
	
	return value;
}

uint8 Keypad_GetPass(uint8 pass_Cha)
{
	 
	uint8 i=0;
	for(i=0;i<4;i++)
	{
		pass[i]=pass_Cha;
	}
	
	return arr_ptr;
}							 
							 	 