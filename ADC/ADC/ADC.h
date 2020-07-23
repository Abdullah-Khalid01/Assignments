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

/******************************************************* VREF SOURCE **************************************************************/

#define ADC_VREF_AVCC				 0

#define ADC_VREF_INTERNAL_AREF       1

#define ADC_VREF_INTERNAL_TURNED_OFF 2

/******************************************************** ADJUST TYPE  ************************************************************/

#define ADC_RIGHT_ADJUST             0

#define ADC_LEFT_ADJUST              1

/******************************************************** ADC CHANNEL *************************************************************/

#define ADC_CHANNEL_0				 0
#define ADC_CHANNEL_1				 1
#define ADC_CHANNEL_2				 2
#define ADC_CHANNEL_3				 3
#define ADC_CHANNEL_4				 4
#define ADC_CHANNEL_5				 5
#define ADC_CHANNEL_6				 6
#define ADC_CHANNEL_7				 7

/******************************************************** ADC TRIGGER *************************************************************/

#define ADC_AUTO_TRIGGER		     0

/****************************************************** ADC PRESCALLER ************************************************************/

#define ADC_PRESEC_2				 0
#define ADC_PRESEC_2b				 1
#define ADC_PRESEC_4				 2
#define ADC_PRESEC_8				 3
#define ADC_PRESEC_16				 4
#define ADC_PRESEC_32				 5
#define ADC_PRESEC_64				 6
#define ADC_PRESEC_128				 7

/****************************************************ADC INTERRUPT STATUS *********************************************************/

#define ADC_INTERRUPT_DISABLE		 0

#define ADC_INTERRUPT_ENABLE		 1
/***************************************************** APIS *****************************************/

void ADC_INIT(void);

void ADC_READ(uint16* value);



#endif /* ADC_H_ */