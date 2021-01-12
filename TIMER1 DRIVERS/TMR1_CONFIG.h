/*
 * TMR1_CONFIG.h
 *
 * Created: 1/10/2021 8:54:59 PM
 *  Author: mostafa gomaa
 */ 


#ifndef TMR1_CONFIG_H_
#define TMR1_CONFIG_H_

#define TMR1_CLK_SOURCE       TMR1_EXTERNAL_CLK_SOURCE 

#define TMR1_COUNTING_ACTION  EXTERNAL_RISING_EDGE

#define TMR1_MODE             PWM_10BIT_MODE 

#define PWM_MODE              PWM_UNITA_NON_INVERTING_MODE

#define PHASE_CORRECT_MODE    PHASE_CORRECT_UNITA_NON_INVERTING_MODE

#define PRESCALER_VALUE       NO_PRESCALER

#define COMPARE_ACTION        TOGGLE_ON_COMPARE



#endif /* TMR1_CONFIG_H_ */