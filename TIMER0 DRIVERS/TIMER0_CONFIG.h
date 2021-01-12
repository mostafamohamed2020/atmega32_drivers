/*
 * TIMER0_CONFIG.h
 *
 * Created: 12/13/2020 8:50:45 PM
 *  Author: mostafa gomaa
 */ 


#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_


#define TIMER0_CLK_SRC           EXTERNAL_CLK_SRC

#define CNT0_EXTERNAL_EDGE_MODE  RISING_EDGE_CNT

#define TIMER0_MODE              TMR0_FASTPWM_NON_INVERTED_MODE

#define TIMER0_PRESCALER_VAL     NO_PRESCALER

#define COMPARE_ACTION           TOOGLE_ON_COMPARE



#endif /* TIMER0_CONFIG_H_ */