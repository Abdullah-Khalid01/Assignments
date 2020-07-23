/*
 * Temp_sensor.c
 *
 * Created: 25/11/41 08:30:49 ص
 *  Author: ABDULLAH 01
 */ 


#include "Temp_sensor.h"

void TempsSensor_INIT(void)
{
	ADC_INIT();
}
void TempSensor_READ(uint16* temp)
{
	ADC_READ(temp);
}