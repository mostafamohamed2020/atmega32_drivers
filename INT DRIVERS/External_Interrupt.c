/*
 * External_Interrupt.c
 *
 * Created: 11/13/2020 1:08:19 AM
 *  Author: mostafa gomaa
 */ 

#include "External_Interrupt.h"

void SET_GLOBALINTERRUPT(void)
{
	#if GLOBAL_INTERRUPT_STATE  ==  GLOBAL_INTERRUPT_STATE_ENABLE
	
	  set_bit(SREG , 7);
	  
	#elif GLOBAL_INTERRUPT_STATE == GLOBAL_INTERRUPT_STATE_DISABLE
	
	  clear_bit(SREG , 7);
	  
	#endif
}

void INT0_INIT(void)
{
	SET_GLOBALINTERRUPT();
	
	    /* Enable INT0 */
		set_bit(GICR , 6);
		
	#if  EXTERNAL_INT0_TRIGGER   ==  INT_TRIGGER_RISING_EDGE
	
	  set_bit(MCUCR , 0);
	  set_bit(MCUCR , 1);
	  
	#elif  EXTERNAL_INT0_TRIGGER  == INT_TRIGGER_FALLING_EDGE
	
	  set_bit(MCUCR , 1);
	  clear_bit(MCUCR  , 0);
	  
	#elif EXTERNAL_INT0_TRIGGER  ==  INT_TRIGGER_LOW_LEVEL
	
	  clear_bit(MCUCR , 0);
	  clear_bit(MCUCR , 1);
	  
	#elif EXTERNAL_INT0_TRIGGER  == INT_TRIGGER_ANY_CHANGE
	
	  set_bit(MCUCR , 0);
	  clear_bit(MCUCR ,1);
	  
	#endif
	
}

void INT1_INIT(void)
{
	SET_GLOBALINTERRUPT();
	
	/* Enable INT1 */
	set_bit(GICR , 7);
	
	#if EXTERNAL_INT1_TRIGGER  == INT_TRIGGER_RISING_EDGE 
	
	  set_bit(MCUCR , 2);
	  set_bit(MCUCR , 3);
	  
	#elif EXTERNAL_INT1_TRIGGER == INT_TRIGGER_FALLING_EDGE
	 
	  clear_bit(MCUCR , 2);
	  set_bit(MCUCR , 3);
	  
	#elif EXTERNAL_INT1_TRIGGER == INT_TRIGGER_LOW_LEVEL
	  
	  clear_bit(MCUCR , 2);
	  clear_bit(MCUCR , 3);
	  
	#elif EXTERNAL_INT1_TRIGGER == INT_TRIGGER_ANY_CHANGE
	
	  set_bit(MCUCR , 2);
	  clear_bit(MCUCR , 3);
	  
	#endif
}

void INT2_INIT(void)
{
	SET_GLOBALINTERRUPT();
	
	/* Enable INT2 */
	set_bit(GICR , 5);
	
	#if EXTERNAL_INT2_TRIGGER == INT_TRIGGER_FALLING_EDGE
	  
	  clear_bit(MCUCSR , 6);
	  
	#elif EXTERNAL_INT2_TRIGGER == INT_TRIGGER_RISING_EDGE
	  
	  set_bit(MCUCSR , 6);
	  
	#endif
}