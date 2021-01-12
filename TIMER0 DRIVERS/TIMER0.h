/*
 * TIMER0.h
 *
 * Created: 12/13/2020 8:50:17 PM
 *  Author: mostafa gomaa
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "TIMER0_CONFIG.h"
#include "ATMEGA32_REGISTERS.h"
#include "common_macros.h"
#include "standard_types.h"
#include "DIO.h"

#define F_CPU 8000000

#define INTERNAL_CLK_SRC                       0
#define EXTERNAL_CLK_SRC                       1
  
#define FALLING_EDGE_CNT                       0
#define RISING_EDGE_CNT                        1

#define TMR0_NORMAL_MODE                       0
#define TMR0_FASTPWM_NON_INVERTED_MODE         1
#define TMR0_FASTPWM_INVERTED_MODE             2
#define TMR_PHASE_CORRECT_NON_INVERTED_MODE    3
#define TMR_PHASE_CORRECT_INVERTED_MODE        4
#define TMR0_CTC_MODE                          5

#define SET_ON_COMPARE                         0
#define CLEAR_ON_COMPARE                       1
#define TOOGLE_ON_COMPARE                      2

#define NO_PRESCALER                           0
#define PRESCALER_8                            1
#define PRESCALER_64                           2
#define PRESCALER_256                          3
#define PRESCALER_1024                         4


void TMR0_INIT();

void TMR0_START();

void TMR0_STOP();

void TMR0_DELAY(u_int32 DELAY_MS);



void TMR0_PWM_DUTYCYCLE(u_int8 DUTY_CYCLE);

void TMR0_PWM_START();

void TMR0_PWM_STOP();



u_int8 INIT_COUNTER0();



#endif /* TIMER0_H_ */