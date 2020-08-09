/*
 * main.c
 *
 * Created: 03/12/41 12:29:30 م
 *  Author: ABDULLAH 01
 */ 


#include "Servo.h"

int main(void)
{
	Servo_Init();
	//PWM1_INIT();
	//PWM1_Generate(7);
	Servo_SetDegree(5);
    while(1)
    {
        //TODO:: Please write your application code 
    }
}