/*
 * ADC.c
 *
 * Created: 16/10/2020 01:47:24 م
 *  Author: mostafa gomaa
 */ 

#include "ADC.h"


void ADC_Init(void)
{
	#if   ADC_VOLTAGE_REFRENCE   ==      AVCC_SOURCE
	
	set_bit(ADMUX , 6);
	clear_bit(ADMUX , 7);
	
	#elif  ADC_VOLTAGE_REFRENCE  ==     INTERNAL_SOURCE
	
	set_bit(ADMUX , 6);
	set_bit(ADMUX , 7);
	
	#elif  ADC_VOLTAGE_REFRENCE  ==     AREF_SOURCE 
	
	clear_bit(ADMUX , 6);
	clear_bit(ADMUX , 7);
	#endif
	
	#if    ADC_ADjUST            ==     RIGHT_ADJUST
	
	clear_bit(ADMUX , 5);
	
	#elif    ADC_ADjUST          ==     LEFT_ADJUST
	
	set_bit(ADMUX , 5);
	#endif
	
	#if   ADC_CHANNEL           ==     CHANNEL1
	
	set_bit(ADMUX , 0);
	
	#elif   ADC_CHANNEL           ==     CHANNEL0
	
	#elif   ADC_CHANNEL           ==     CHANNEL2
	 
	 set_bit(ADMUX , 1);
	 
	#elif   ADC_CHANNEL           ==     CHANNEL3
	 
	 set_bit(ADMUX , 0);
	 set_bit(ADMUX , 1);
	 
	#elif   ADC_CHANNEL           ==     CHANNEL4
	 
	 set_bit(ADMUX , 2);
	 
	#elif   ADC_CHANNEL           ==     CHANNEL5
	 
	 set_bit(ADMUX , 0);
	 set_bit(ADMUX , 2);
	 
	#elif   ADC_CHANNEL           ==     CHANNEL6
	 
	 set_bit(ADMUX , 1);
	 set_bit(ADMUX , 2);
	 
	#elif   ADC_CHANNEL           ==     CHANNEL7
	 
	 set_bit(ADMUX , 0);
	 set_bit(ADMUX , 1);
	 set_bit(ADMUX , 2);
	#endif
	
	#if  ADC_CONVERSION_TRIGGER  ==    AUTO_RUNNING_MODE
	
	set_bit(ADCSRA , 5);
	
	#elif  ADC_CONVERSION_TRIGGER  ==    EXTERNAL_INT0 
	 set_bit(SFIOR , 6);
	#endif
	
	#if  ADC_PRESCALER          ==      PRESCALER128
	
	set_bit(ADCSRA , 0);
	set_bit(ADCSRA , 1);
	set_bit(ADCSRA , 2);
	
	#elif  ADC_PRESCALER          ==      PRESCALER16
	 
	 set_bit(ADCSRA , 2);
	 
	#elif  ADC_PRESCALER          ==      PRESCALER8
	 
	 set_bit(ADCSRA , 0);
	 set_bit(ADCSRA , 1);
	 
	#elif  ADC_PRESCALER          ==      PRESCALER4
	
	 set_bit(ADCSRA , 1);
	 
	#elif  ADC_PRESCALER          ==      PRESCALER2
	#endif
	
	#if  ADC_INTERRUPT_STATUS   ==     ADC_INT_DISABLED
	
	clear_bit(ADCSRA , 3);
	
	#elif  ADC_INTERRUPT_STATUS   ==     ADC_INT_ENABLED 
	 
	 set_bit(SREG , 7);
	 set_bit(ADCSRA , 3);
	#endif
	
	//Enable  ADC
	set_bit(ADCSRA , 7);
	
	
}

u_int16 ADC_Read(void)
{
	u_int16 VALUE = 0;
	
	set_bit(ADCSRA , 6);
	
	while(get_bit(ADCSRA,4) == 0);
	
	VALUE = ADC_VAL ;
	
	return VALUE;
}