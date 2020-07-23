/*
 * Temp_sensor.h
 *
 * Created: 25/11/41 08:30:30 ص
 *  Author: ABDULLAH 01
 */ 


#ifndef TEMP_SENSOR_H_
#define TEMP_SENSOR_H_

#include "ADC.h"

void TempsSensor_INIT(void);

void TempSensor_READ(uint16* temp);

#endif /* TEMP_SENSOR_H_ */