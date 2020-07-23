/*
 * ADC.c
 *
 * Created: 25/11/41 06:42:12 ص
 *  Author: ABDULLAH 01
 */ 

#include "ADC.h"


void ADC_INIT(void)
{
#if VOLTAGE_REFRENCE   ==    ADC_VREF_AVCC

Set_bit(ADMUX,6);
Clr_bit(ADMUX,7);
#endif

#if ADC_CHANNEL       ==   ADC_CHANNEL_1

Set_bit(ADMUX,0);
#endif

#if VOLTAGE_ADJUCENT   ==    ADC_RIGHT_ADJUST
Clr_bit(ADMUX,5);
#endif

#if ADC_CONVERSION_TRIGGER== ADC_AUTO_TRIGGER

Set_bit(ADCSRA,5);

#endif

#if ADC_PRESCALER     ==     ADC_PRESEC_128

Set_bit(ADCSRA,0);
Set_bit(ADCSRA,1);
Set_bit(ADCSRA,2);

#endif

#if ADC_INTERRUPT_STATUS  == ADC_INTERRUPT_DISABLE

Clr_bit(ADCSRA,3);

#endif

/* Enable ADC */

Set_bit(ADCSRA,7);
}

void ADC_READ(uint16* value)
{
	uint16 Digital_value=0;
	
	Set_bit(ADCSRA,6);
	
	#if ADC_INTERRUPT_STATUS  == ADC_INTERRUPT_DISABLE
	
	while (! Get_bit(ADCSRA,4));
	
	Digital_value=ADC_ADJUST;
	
	*value=((Digital_value *500)/1024);
	
	#endif
	
}