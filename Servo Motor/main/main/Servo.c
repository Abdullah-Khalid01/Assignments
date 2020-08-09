/*
 * Servo.c
 *
 * Created: 03/12/41 12:30:20 م
 *  Author: ABDULLAH 01
 */ 

#include "Servo.h"


void Servo_Init(void)
{
	DIO_SetPINDIR(DIO_PORTD , DIO_PIN5 , DIO_PIN_OUTPUT);
	PWM1_INIT();
	PWM1_Start();
}

void Servo_SetDegree(float degree)
{
	degree = degree * 0.1866666667 + 31.6;
	OCR1A = degree;
}