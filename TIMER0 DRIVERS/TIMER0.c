/*
 * TIMER0.c
 *
 * Created: 12/13/2020 8:49:57 PM
 *  Author: mostafa gomaa
 */ 

#include "TIMER0.h"

u_int32 NO_OF_OVS = 0;
u_int32 INITIAL_VAL = 0;

void TMR0_INIT()
{
	 /* COUNTER MODE OF TMR0 */
	#if TIMER0_CLK_SRC == EXTERNAL_CLK_SRC
	
	  /* EXTERNAL PIN AS CLOCK SOURCE */
	  DIO_SETPINDIR(DIO_PORTB , DIO_PIN0 , DIO_PIN_INPUT);

	  DIO_SETPULLUPS(DIO_PORTB , DIO_PIN0 );
	  
	 #if CNT0_EXTERNAL_EDGE_MODE == FALLING_EDGE_CNT
	  
	  clear_bit(TCCR0 , 0);
	  set_bit(TCCR0 , 1);
	  set_bit(TCCR0 , 2);
	  
	 #elif CNT0_EXTERNAL_EDGE_MODE == RISING_EDGE_CNT
	  
	  set_bit(TCCR0 , 0);
	  set_bit(TCCR0 , 1);
	  set_bit(TCCR0 , 2);
	 #endif
	 
	 /* TIMER MODE OF TMR0 */
	#elif TIMER0_CLK_SRC == INTERNAL_CLK_SRC
	
	 #if TIMER0_MODE == TMR0_NORMAL_MODE
	 
	 clear_bit(TCCR0 , 7);
	 clear_bit(TCCR0 , 6);
	 clear_bit(TCCR0 , 3);
	 clear_bit(TCCR0 , 4);
	 clear_bit(TCCR0 , 5);
	 
	 /* ENABLE INTERRUPT */
	 set_bit(SREG , 7);
	 set_bit(TIMSK , 0);
	 
	 #elif TIMER0_MODE == TMR0_FASTPWM_NON_INVERTED_MODE
	 
	 set_bit(TCCR0 , 7);
	 set_bit(TCCR0 , 6);
	 set_bit(TCCR0 , 3);
	 clear_bit(TCCR0 , 4);
	 set_bit(TCCR0 , 5);
	 
	 
	 
	 #elif TIMER0_MODE == TMR0_FASTPWM_INVERTED_MODE
	 
	 set_bit(TCCR0 , 7);
	 set_bit(TCCR0 , 6);
	 set_bit(TCCR0 , 3);
	 set_bit(TCCR0 , 4);
	 set_bit(TCCR0 , 5);
	 
	 #elif TIMER0_MODE == TMR_PHASE_CORRECT_NON_INVERTED_MODE
	 
	 set_bit(TCCR0 , 7);
	 set_bit(TCCR0 , 6);
	 clear_bit(TCCR0 , 3);
	 clear_bit(TCCR0 , 4);
	 set_bit(TCCR0 , 5);
	 
	 #elif TIMER0_MODE == TMR_PHASE_CORRECT_INVERTED_MODE
	 
	 set_bit(TCCR0 , 7);
	 set_bit(TCCR0 , 6);
	 clear_bit(TCCR0 , 3);
	 set_bit(TCCR0 , 4);
	 set_bit(TCCR0 , 5);
	 
	 #elif TIMER0_MODE == TMR0_CTC_MODE
	 
	 DIO_SETPINDIR(DIO_PORTB , DIO_PIN3 , DIO_PIN_OUTPUT);
	 
	 clear_bit(TCCR0 , 7);
	 clear_bit(TCCR0 , 6);
	 set_bit(TCCR0 , 3);
	 
	 /* ENABLE INTERRUPT */
	 set_bit(SREG , 7);
	 set_bit(TIMSK , 1);
	 
	  #if COMPARE_ACTION == SET_ON_COMPARE
	   
	   set_bit(TCCR0 , 4);
	   set_bit(TCCR0 , 5);
	   
	  #elif COMPARE_ACTION == CLEAR_ON_COMPARE
	   
	   clear_bit(TCCR0 , 4);
	   set_bit(TCCR0 , 5);
	   
	  #elif COMPARE_ACTION == TOOGLE_ON_COMPARE
	   
	   set_bit(TCCR0 , 4);
	   clear_bit(TCCR0 , 5);
	  #endif
	 #endif
	#endif

}

void TMR0_START()
{
	#if TIMER0_PRESCALER_VAL == PRESCALER_1024
	
	set_bit(TCCR0 , 0);
	clear_bit(TCCR0 , 1);
	set_bit(TCCR0 , 2);
	
	#elif TIMER0_PRESCALER_VAL == NO_PRESCALER
	
	set_bit(TCCR0 , 0);
	clear_bit(TCCR0 , 1);
	clear_bit(TCCR0 , 2);
	
	#elif TIMER0_PRESCALER_VAL == PRESCALER_8
	
	clear_bit(TCCR0 , 0);
	set_bit(TCCR0 , 1);
	clear_bit(TCCR0 , 2);
	
	#elif TIMER0_PRESCALER_VAL == PRESCALER_64
	
	set_bit(TCCR0 , 0);
	set_bit(TCCR0 , 1);
	clear_bit(TCCR0 , 2);
	
	#elif TIMER0_PRESCALER_VAL == PRESCALER_256
	
	clear_bit(TCCR0 , 0);
	clear_bit(TCCR0 , 1);
	set_bit(TCCR0 , 2);
	#endif
}

void TMR0_STOP()
{
	clear_bit(TCCR0 , 0);
	clear_bit(TCCR0 , 1);
	clear_bit(TCCR0 , 2);
	
}

void TMR0_DELAY(u_int32 DELAY_MS)
{
	#if TIMER0_PRESCALER_VAL == PRESCALER_1024
	 
	u_int8 TICK_TIME = (1024 / (F_CPU / 1000000));
	u_int32 TOTAL_TICKS = ((DELAY_MS * 1000) / TICK_TIME);
	NO_OF_OVS = (TOTAL_TICKS / 256);
	INITIAL_VAL = 265 - (TOTAL_TICKS % 256);
	TCNT0 = INITIAL_VAL;
	NO_OF_OVS++;
	
	#elif TIMER0_PRESCALER_VAL == PRESCALER_256
	
	u_int8 TICK_TIME = (256 / (F_CPU / 1000000));
	u_int32 TOTAL_TICKS = ((DELAY_MS * 1000) / TICK_TIME);
	NO_OF_OVS = (TOTAL_TICKS / 256);
	INITIAL_VAL = 265 - (TOTAL_TICKS % 256);
	TCNT0 = INITIAL_VAL;
	NO_OF_OVS++;
	
	#elif TIMER0_PRESCALER_VAL == PRESCALER_64
	
	u_int8 TICK_TIME = (64 / (F_CPU / 1000000));
	u_int32 TOTAL_TICKS = ((DELAY_MS * 1000)/ TICK_TIME);
	NO_OF_OVS = (TOTAL_TICKS / 256);
	INITIAL_VAL = 265 - (TOTAL_TICKS % 256);
	TCNT0 = INITIAL_VAL;
	NO_OF_OVS++;
	
	#endif
}

void TMR0_PWM_DUTYCYCLE(u_int8 DUTY_CYCLE)
{ 
	/* PWM PIN AS OUTPUT */
	DIO_SETPINDIR(DIO_PORTB , DIO_PIN3 , DIO_PIN_OUTPUT);
	
	/*
	 * DUTY CYCLE IS NOT THE SAME FOR INVERTED && NON INVERTED
	 * WHILE FREQUENCY WILL NOT CHANGE
	 */
	#if TIMER0_MODE == TMR0_FASTPWM_NON_INVERTED_MODE
	
	OCR0 =((DUTY_CYCLE * 255) / 100 ) - 1 ;
	
	#elif TIMER0_MODE == TMR0_FASTPWM_INVERTED_MODE
	
	OCR0 = (255) - ((DUTY_CYCLE * 256) / 100);
	
	#endif
}

void TMR0_PWM_START()
{
	#if TIMER0_PRESCALER_VAL == PRESCALER_1024
	
	set_bit(TCCR0 , 0);
	clear_bit(TCCR0 , 1);
	set_bit(TCCR0 , 2);
	
	#elif TIMER0_PRESCALER_VAL == NO_PRESCALER
	
	set_bit(TCCR0 , 0);
	clear_bit(TCCR0 , 1);
	clear_bit(TCCR0 , 2);
	
	#elif TIMER0_PRESCALER_VAL == PRESCALER_8
	
	clear_bit(TCCR0 , 0);
	set_bit(TCCR0 , 1);
	clear_bit(TCCR0 , 2);
	
	#elif TIMER0_PRESCALER_VAL == PRESCALER_64
	
	set_bit(TCCR0 , 0);
	set_bit(TCCR0 , 1);
	clear_bit(TCCR0 , 2);
	
	#elif TIMER0_PRESCALER_VAL == PRESCALER_256
	
	clear_bit(TCCR0 , 0);
	clear_bit(TCCR0 , 1);
	set_bit(TCCR0 , 2);
	#endif
	
}

void TMR0_PWM_STOP()
{
	clear_bit(TCCR0 , 0);
	clear_bit(TCCR0 , 1);
	clear_bit(TCCR0 , 2);
}

u_int8 INIT_COUNTER0()
{
	u_int8 value ;
	
	/* RETURN THE VALUE OF TCNT0 */	
    value = ( TCNT0 - 3 ); 
	
	return value ;
}