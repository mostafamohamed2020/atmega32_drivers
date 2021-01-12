/*
 * TMR1.c
 *
 * Created: 1/10/2021 8:55:22 PM
 *  Author: mostafa gomaa
 */ 

#include "TMR1.h"


void TMR1_INIT(void)
{
	#if TMR1_CLK_SOURCE == TMR1_EXTERNAL_CLK_SOURCE
	 
	  /* SET THE T1 CLK BIT AS INPUT */
	 DIO_SETPINDIR(DIO_PORTB , DIO_PIN1 , DIO_PIN_INPUT);
	
	 #if TMR1_COUNTING_ACTION == EXTERNAL_RISING_EDGE
	 
	  set_bit(TCCR1B , 0);
	  set_bit(TCCR1B , 1);
	  set_bit(TCCR1B , 2);
	  
	 #elif TMR1_COUNTING_ACTION == EXTERNAL_FALLING_EDGE
	 
	 clear_bit(TCCR1B , 0);
	 set_bit(TCCR1B , 1);
	 set_bit(TCCR1B , 2);
	 #endif
	 
	#elif TMR1_CLK_SOURCE == TMR1_INTERNAL_CLK_SOURCE
	
	 #if TMR1_MODE == NORMAL_MODE
	  
	  clear_bit(TCCR1A , 0);
	  clear_bit(TCCR1A , 1);
	  clear_bit(TCCR1B , 3);
	  clear_bit(TCCR1B , 4);
	  
	  /* NON PWM MODE */
	  set_bit(TCCR1A , 2);
	  set_bit(TCCR1A , 3);
	  
	  /* ENABLE INTERRUPT */
	  set_bit(SREG , 7);
	  set_bit(TIMSK , 2);
	  
	 #elif TMR1_MODE == CTC_UNITA_MODE
	  
	  /* SET THE OC1A BIT AS OUTPUT */
	  DIO_SETPINDIR(DIO_PORTD , DIO_PIN5 , DIO_PIN_OUTPUT);
	  
	   clear_bit(TCCR1A , 0);
	   clear_bit(TCCR1A , 1);
	   set_bit(TCCR1B , 3);
	   clear_bit(TCCR1B , 4);
	   
	   /* NON PWM MODE */
	   set_bit(TCCR1A , 3);
	   
	   /* ENABLE INTERRUPT */
	   set_bit(SREG , 7);
	   set_bit(TIMSK , 4);
	   
	   /* ACTION ON COMPARE MATCH OF UNIT A */
	   #if COMPARE_ACTION == SET_ON_COMPARE 
	    
		set_bit(TCCR1A , 6);
		set_bit(TCCR1A , 7);
		
	   #elif COMPARE_ACTION == CLEAR_ON_COMPARE
	   
	    clear_bit(TCCR1A , 6);
	    set_bit(TCCR1A , 7);
		
	   #elif COMPARE_ACTION == TOGGLE_ON_COMPARE
	    
		set_bit(TCCR1A , 6);
		clear_bit(TCCR1A , 7);
	   #endif 
	  
	 #elif TMR1_MODE == CTC_UNITB_MODE
	  
	   /* SET THE OC1B BIT AS OUTPUT */
	  DIO_SETPINDIR(DIO_PORTD , DIO_PIN4 , DIO_PIN_OUTPUT);
	  
	  clear_bit(TCCR1A , 0);
	  clear_bit(TCCR1A , 1);
	  set_bit(TCCR1B , 3);
	  clear_bit(TCCR1B , 4);
	  
	  /* NON PWM MODE */
	  set_bit(TCCR1A , 2);
	  
	  /* ENABLE INTERRUPT */
	  set_bit(SREG , 7);
	  set_bit(TIMSK , 3);
	  
	  /* ACTION ON COMPARE MATCH OF UNIT B */
	  #if COMPARE_ACTION == SET_ON_COMPARE
	  
	  set_bit(TCCR1A , 4);
	  set_bit(TCCR1A , 5);
	  
	  #elif COMPARE_ACTION == CLEAR_ON_COMPARE
	  
	  clear_bit(TCCR1A , 4);
	  set_bit(TCCR1A , 5);
	  
	  #elif COMPARE_ACTION == TOGGLE_ON_COMPARE
	  
	  set_bit(TCCR1A , 4);
	  clear_bit(TCCR1A , 5);
	  #endif
	  
	 #elif TMR1_MODE == PWM_8BIT_MODE
	  
	  set_bit(TCCR1A , 0);
	  clear_bit(TCCR1A , 1);
	  set_bit(TCCR1B , 3);
	  clear_bit(TCCR1B , 4);
	  
	  /* WHEN USING UNITA */
	#if PWM_MODE ==  PWM_UNITA_INVERTING_MODE
	
	 set_bit(TCCR1A , 6);
	 set_bit(TCCR1A , 7);
	 
	 /* SET THE OC1A BIT AS OUTPUT */
	 DIO_SETPINDIR(DIO_PORTD , DIO_PIN5 , DIO_PIN_OUTPUT);
	 
	#elif PWM_MODE ==  PWM_UNITA_NON_INVERTING_MODE
	
	clear_bit(TCCR1A , 6);
	set_bit(TCCR1A , 7);
	
	/* SET THE OC1A BIT AS OUTPUT */
	DIO_SETPINDIR(DIO_PORTD , DIO_PIN5 , DIO_PIN_OUTPUT);
	
	/* WHEN USING UNITB */
	#elif PWM_MODE ==  PWM_UNITB_INVERTING_MODE
	 
	 set_bit(TCCR1A , 4);
	 set_bit(TCCR1A , 5);
	 
	  /* SET THE OC1B BIT AS OUTPUT */
	  DIO_SETPINDIR(DIO_PORTD , DIO_PIN4 , DIO_PIN_OUTPUT);
	 
	#elif PWM_MODE ==  PWM_UNITB_NON_INVERTING_MODE
	 
	 clear_bit(TCCR1A , 4);
	 set_bit(TCCR1A , 5);
	 
	  /* SET THE OC1B BIT AS OUTPUT */
	  DIO_SETPINDIR(DIO_PORTD , DIO_PIN4 , DIO_PIN_OUTPUT);
	#endif

	 #elif TMR1_MODE == PWM_9BIT_MODE
	  
	  clear_bit(TCCR1A , 0);
	  set_bit(TCCR1A , 1);
	  set_bit(TCCR1B , 3);
	  clear_bit(TCCR1B , 4);
	  
	  /* WHEN USING UNITA */
	#if PWM_MODE ==  PWM_UNITA_INVERTING_MODE
	
	 set_bit(TCCR1A , 6);
	 set_bit(TCCR1A , 7);
	 
	 /* SET THE OC1A BIT AS OUTPUT */
	 DIO_SETPINDIR(DIO_PORTD , DIO_PIN5 , DIO_PIN_OUTPUT);
	 
	#elif PWM_MODE ==  PWM_UNITA_NON_INVERTING_MODE
	
	clear_bit(TCCR1A , 6);
	set_bit(TCCR1A , 7);
	
	/* SET THE OC1A BIT AS OUTPUT */
	DIO_SETPINDIR(DIO_PORTD , DIO_PIN5 , DIO_PIN_OUTPUT);
	
	/* WHEN USING UNITB */
	#elif PWM_MODE ==  PWM_UNITB_INVERTING_MODE
	 
	 set_bit(TCCR1A , 4);
	 set_bit(TCCR1A , 5);
	 
	 /* SET THE OC1B BIT AS OUTPUT */
	 DIO_SETPINDIR(DIO_PORTD , DIO_PIN4 , DIO_PIN_OUTPUT);
	 
	#elif PWM_MODE ==  PWM_UNITB_NON_INVERTING_MODE
	 
	 clear_bit(TCCR1A , 4);
	 set_bit(TCCR1A , 5);
	 
	 /* SET THE OC1B BIT AS OUTPUT */
	 DIO_SETPINDIR(DIO_PORTD , DIO_PIN4 , DIO_PIN_OUTPUT);
	
	#endif

	 #elif TMR1_MODE == PWM_10BIT_MODE
	  
	  set_bit(TCCR1A , 0);
	  set_bit(TCCR1A , 1);
	  set_bit(TCCR1B , 3);
	  clear_bit(TCCR1B , 4);
	  
	  /* WHEN USING UNITA */
	#if PWM_MODE ==  PWM_UNITA_INVERTING_MODE
	
	 set_bit(TCCR1A , 6);
	 set_bit(TCCR1A , 7);
	 
	 /* SET THE OC1A BIT AS OUTPUT */
	 DIO_SETPINDIR(DIO_PORTD , DIO_PIN5 , DIO_PIN_OUTPUT);
	 
	#elif PWM_MODE ==  PWM_UNITA_NON_INVERTING_MODE
	
	clear_bit(TCCR1A , 6);
	set_bit(TCCR1A , 7);
	
	/* SET THE OC1A BIT AS OUTPUT */
	DIO_SETPINDIR(DIO_PORTD , DIO_PIN5 , DIO_PIN_OUTPUT);
	
	/* WHEN USING UNITB */
	#elif PWM_MODE ==  PWM_UNITB_INVERTING_MODE
	 
	 set_bit(TCCR1A , 4);
	 set_bit(TCCR1A , 5);
	 
	 /* SET THE OC1B BIT AS OUTPUT */
	 DIO_SETPINDIR(DIO_PORTD , DIO_PIN4 , DIO_PIN_OUTPUT);
	 
	#elif PWM_MODE ==  PWM_UNITB_NON_INVERTING_MODE
	 
	 clear_bit(TCCR1A , 4);
	 set_bit(TCCR1A , 5);
	 
	 /* SET THE OC1B BIT AS OUTPUT */
	 DIO_SETPINDIR(DIO_PORTD , DIO_PIN4 , DIO_PIN_OUTPUT);
	#endif

	 #elif TMR1_MODE == PWM_ADAPTED_TOP
	  
	  clear_bit(TCCR1A , 0);
	  set_bit(TCCR1A , 1);
	  set_bit(TCCR1B , 3);
	  set_bit(TCCR1B , 4);
	  
	  /* WHEN USING UNITA */
	#if PWM_MODE ==  PWM_UNITA_INVERTING_MODE
	
	 set_bit(TCCR1A , 6);
	 set_bit(TCCR1A , 7);
	 
	 /* SET THE OC1A BIT AS OUTPUT */
	 DIO_SETPINDIR(DIO_PORTD , DIO_PIN5 , DIO_PIN_OUTPUT);
	 
	#elif PWM_MODE ==  PWM_UNITA_NON_INVERTING_MODE
	
	clear_bit(TCCR1A , 6);
	set_bit(TCCR1A , 7);
	
	/* SET THE OC1A BIT AS OUTPUT */
	DIO_SETPINDIR(DIO_PORTD , DIO_PIN5 , DIO_PIN_OUTPUT);
	
	/* WHEN USING UNITB */
	#elif PWM_MODE ==  PWM_UNITB_INVERTING_MODE
	 
	 set_bit(TCCR1A , 4);
	 set_bit(TCCR1A , 5);
	 
	 /* SET THE OC1B BIT AS OUTPUT */
	 DIO_SETPINDIR(DIO_PORTD , DIO_PIN4 , DIO_PIN_OUTPUT);
	 
	#elif PWM_MODE ==  PWM_UNITB_NON_INVERTING_MODE
	 
	 clear_bit(TCCR1A , 4);
	 set_bit(TCCR1A , 5);
	 
	 /* SET THE OC1B BIT AS OUTPUT */
	 DIO_SETPINDIR(DIO_PORTD , DIO_PIN4 , DIO_PIN_OUTPUT);
	#endif

	 #elif TMR1_MODE == PHASE_CORRECT_8BIT_MODE
	  
	  set_bit(TCCR1A , 0);
	  clear_bit(TCCR1A , 1);
	  clear_bit(TCCR1B , 3);
	  clear_bit(TCCR1B , 4);

	  /* IN CASE OF USING UNIT A */
	#if PHASE_CORRECT_MODE ==  PHASE_CORRECT_UNITA_INVERTING_MODE
	 
	 set_bit(TCCR1A , 6);
	 set_bit(TCCR1A , 7);
	 
	 /* SET THE OC1A BIT AS OUTPUT */
	 DIO_SETPINDIR(DIO_PORTD , DIO_PIN5 , DIO_PIN_OUTPUT);
	 
	#elif PHASE_CORRECT_MODE == PHASE_CORRECT_UNITA_NON_INVERTING_MODE
	 
	 clear_bit(TCCR1A , 6);
	 set_bit(TCCR1A , 7);
	 
	 /* SET THE OC1A BIT AS OUTPUT */
	 DIO_SETPINDIR(DIO_PORTD , DIO_PIN5 , DIO_PIN_OUTPUT);
	 
	 /* IN CASE OF USING UNIT B */
	#elif  PHASE_CORRECT_MODE == PHASE_CORRECT_UNITB_INVERTING_MODE
	 
	 set_bit(TCCR1A , 4);
	 set_bit(TCCR1A , 5);
	 
	 /* SET THE OC1B BIT AS OUTPUT */
	 DIO_SETPINDIR(DIO_PORTD , DIO_PIN4 , DIO_PIN_OUTPUT);
	 
	#elif  PHASE_CORRECT_MODE == PHASE_CORRECT_UNITB_NON_INVERTING_MODE
	 
	 clear_bit(TCCR1A , 4);
	 set_bit(TCCR1A , 5);
	 
	 /* SET THE OC1B BIT AS OUTPUT */
	 DIO_SETPINDIR(DIO_PORTD , DIO_PIN4 , DIO_PIN_OUTPUT);
	#endif
	  
	 #elif TMR1_MODE == PHASE_CORRECT_9BIT_MODE
	  
	  clear_bit(TCCR1A , 0);
	  set_bit(TCCR1A , 1);
	  clear_bit(TCCR1B , 3);
	  clear_bit(TCCR1B , 4);
	  
	  /* IN CASE OF USING UNIT A */
	#if PHASE_CORRECT_MODE ==  PHASE_CORRECT_UNITA_INVERTING_MODE
	 
	 set_bit(TCCR1A , 6);
	 set_bit(TCCR1A , 7);
	 
	 /* SET THE OC1A BIT AS OUTPUT */
	 DIO_SETPINDIR(DIO_PORTD , DIO_PIN5 , DIO_PIN_OUTPUT);
	 
	#elif PHASE_CORRECT_MODE == PHASE_CORRECT_UNITA_NON_INVERTING_MODE
	 
	 clear_bit(TCCR1A , 6);
	 set_bit(TCCR1A , 7);
	 
	 /* SET THE OC1A BIT AS OUTPUT */
	 DIO_SETPINDIR(DIO_PORTD , DIO_PIN5 , DIO_PIN_OUTPUT);
	 
	 /* IN CASE OF USING UNIT B */
	#elif  PHASE_CORRECT_MODE == PHASE_CORRECT_UNITB_INVERTING_MODE
	 
	 set_bit(TCCR1A , 4);
	 set_bit(TCCR1A , 5);
	 
	 /* SET THE OC1B BIT AS OUTPUT */
	 DIO_SETPINDIR(DIO_PORTD , DIO_PIN4 , DIO_PIN_OUTPUT);
	 
	#elif  PHASE_CORRECT_MODE == PHASE_CORRECT_UNITB_NON_INVERTING_MODE
	 
	 clear_bit(TCCR1A , 4);
	 set_bit(TCCR1A , 5);
	 
	 /* SET THE OC1B BIT AS OUTPUT */
	 DIO_SETPINDIR(DIO_PORTD , DIO_PIN4 , DIO_PIN_OUTPUT);
	#endif

	 #elif TMR1_MODE == PHASE_CORRECT_10BIT_MODE
	 
	 set_bit(TCCR1A , 0);
	 set_bit(TCCR1A , 1);
	 clear_bit(TCCR1B , 3);
	 clear_bit(TCCR1B , 4);

	 /* IN CASE OF USING UNIT A */
	#if PHASE_CORRECT_MODE ==  PHASE_CORRECT_UNITA_INVERTING_MODE
	 
	 set_bit(TCCR1A , 6);
	 set_bit(TCCR1A , 7);
	 
	 /* SET THE OC1A BIT AS OUTPUT */
	 DIO_SETPINDIR(DIO_PORTD , DIO_PIN5 , DIO_PIN_OUTPUT);
	 
	#elif PHASE_CORRECT_MODE == PHASE_CORRECT_UNITA_NON_INVERTING_MODE
	 
	 clear_bit(TCCR1A , 6);
	 set_bit(TCCR1A , 7);
	 
	 /* SET THE OC1A BIT AS OUTPUT */
	 DIO_SETPINDIR(DIO_PORTD , DIO_PIN5 , DIO_PIN_OUTPUT);
	 
	 /* IN CASE OF USING UNIT B */
	#elif  PHASE_CORRECT_MODE == PHASE_CORRECT_UNITB_INVERTING_MODE
	 
	 set_bit(TCCR1A , 4);
	 set_bit(TCCR1A , 5);
	 
	 /* SET THE OC1B BIT AS OUTPUT */
	 DIO_SETPINDIR(DIO_PORTD , DIO_PIN4 , DIO_PIN_OUTPUT);
	 
	#elif  PHASE_CORRECT_MODE == PHASE_CORRECT_UNITB_NON_INVERTING_MODE
	 
	 clear_bit(TCCR1A , 4);
	 set_bit(TCCR1A , 5);
	 
	 /* SET THE OC1B BIT AS OUTPUT */
	 DIO_SETPINDIR(DIO_PORTD , DIO_PIN4 , DIO_PIN_OUTPUT);
	#endif
	#endif
#endif
	 
}

void TMR1_START(void)
{
	#if TMR1_CLK_SOURCE == TMR1_INTERNAL_CLK_SOURCE
	 
	 #if PRESCALER_VALUE == PRESCALER_1024
	 
	 set_bit(TCCR1B , 0);
	 clear_bit(TCCR1B , 1);
	 set_bit(TCCR1B , 2);
	 
	 #elif PRESCALER_VALUE == PRESCALER_256
	 
	 clear_bit(TCCR1B , 0);
	 clear_bit(TCCR1B , 1);
	 set_bit(TCCR1B , 2);
	 
	 #elif PRESCALER_VALUE == PRESCALER_64
	 
	 set_bit(TCCR1B , 0);
	 set_bit(TCCR1B , 1);
	 clear_bit(TCCR1B , 2);
	 
	 #elif PRESCALER_VALUE == NO_PRESCALER
	 
	 set_bit(TCCR1B , 0);
	 clear_bit(TCCR1B , 1);
	 clear_bit(TCCR1B , 2);
	 #endif
	#endif
	
	
}

void TMR1_SET_DELAY(u_int32 DELAY_MS)
{
	u_int32 Tick_Time = 1024 / 8 ;
	u_int32 Total_Num_Ticks =  ( DELAY_MS * 1000) / Tick_Time ;
	OCR1A = Total_Num_Ticks - 1;

}

void TMR1_STOP(void)
{
	/* TURN THE CLOCK OFF */
	clear_bit(TCCR1B , 0);
	clear_bit(TCCR1B , 1);
	clear_bit(TCCR1B , 2);
}


void TMR1_PWM_START(void)
{
	#if TMR1_CLK_SOURCE == TMR1_INTERNAL_CLK_SOURCE
	 
	 #if PRESCALER_VALUE == PRESCALER_1024
	 
	 set_bit(TCCR1B , 0);
	 clear_bit(TCCR1B , 1);
	 set_bit(TCCR1B , 2);
	 
	 #elif PRESCALER_VALUE == PRESCALER_256
	 
	 clear_bit(TCCR1B , 0);
	 clear_bit(TCCR1B , 1);
	 set_bit(TCCR1B , 2);
	 
	 #elif PRESCALER_VALUE == PRESCALER_64
	 
	 set_bit(TCCR1B , 0);
	 set_bit(TCCR1B , 1);
	 clear_bit(TCCR1B , 2);
	 
	 #elif PRESCALER_VALUE == NO_PRESCALER
	 
	 set_bit(TCCR1B , 0);
	 clear_bit(TCCR1B , 1);
	 clear_bit(TCCR1B , 2);
	 #endif
	#endif
}

void TMR1_PWM_DUTY_CYCLE(u_int8 DUTY_CYCLE)
{
	OCR1A = ((DUTY_CYCLE * 256) /100) - 1;
}

void TMR1_PWM_STOP(void)
{
	/* TURN THE CLOCK OFF */
	clear_bit(TCCR1B , 0);
	clear_bit(TCCR1B , 1);
	clear_bit(TCCR1B , 2);
}

u_int16 TMR1_COUNTER(void)
{
	u_int16 counter_val = 0;
	
	counter_val = TCNT1 - 3 ; 
	
	return counter_val ;
}
