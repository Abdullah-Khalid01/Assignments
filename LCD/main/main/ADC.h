/*
 * ADC.h
 *
 * Created: 25/11/41 06:41:39 ص
 *  Author: ABDULLAH 01
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "BIT_Math.h"
//#include "STD.h"
#include "Atmega32_registers.h"
#include "ADC_Cfg.h"

#define ADC_VREF_AVCC         0

#define ADC_RIGHT_ADJUST      0

#define ADC_CHANNEL_1         1

#define ADC_AUTO_TRIGGER      0

#define ADC_PRESEC_128        7

#define ADC_INTERRUPT_DISABLE 0


/***************************************************** APIS *****************************************/

void ADC_INIT(void);

void ADC_READ(uint16* value);



#endif /* ADC_H_ */