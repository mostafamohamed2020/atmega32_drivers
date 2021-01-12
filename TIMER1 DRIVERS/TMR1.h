/*
 * TMR1.h
 *
 * Created: 1/10/2021 8:55:09 PM
 *  Author: mostafa gomaa
 */ 


#ifndef TMR1_H_
#define TMR1_H_

#include "DIO.h"
#include "ATMEGA32_REGISTERS.h"
#include "common_macros.h"
#include "standard_types.h"
#include "TMR1_CONFIG.h"

#define  F_CPU 8000000


/* CLOCK SOURCE */
#define TMR1_INTERNAL_CLK_SOURCE               0
#define TMR1_EXTERNAL_CLK_SOURCE               1

/* AVAILABLE OPTIONS OF EXTERNAL TRIGGER */
#define EXTERNAL_FALLING_EDGE                  0
#define EXTERNAL_RISING_EDGE                   1

/* INTERNAL CLOCK SOURCE OPTIONS */
#define NORMAL_MODE                            0

#define CTC_UNITA_MODE                         1
#define CTC_UNITB_MODE                         2

#define PWM_UNITA_INVERTING_MODE               3
#define PWM_UNITA_NON_INVERTING_MODE           4
#define PWM_UNITB_INVERTING_MODE               5
#define PWM_8BIT_MODE                          6
#define PWM_9BIT_MODE                          7
#define PWM_10BIT_MODE                         8
#define PWM_ADAPTED_TOP                        9

#define PHASE_CORRECT_UNITA_INVERTING_MODE     10
#define PHASE_CORRECT_UNITB_INVERTING_MODE     11
#define PHASE_CORRECT_UNITA_NON_INVERTING_MODE 12
#define PHASE_CORRECT_UNITB_NON_INVERTING_MODE 13
#define PHASE_CORRECT_8BIT_MODE                14
#define PHASE_CORRECT_9BIT_MODE                15
#define PHASE_CORRECT_10BIT_MODE               16

/* COMPARE ACTIONS */
#define SET_ON_COMPARE                         0
#define CLEAR_ON_COMPARE                       1
#define TOGGLE_ON_COMPARE                      2

/* PRESCALLER VALUES */
#define NO_PRESCALER                           0
#define PRESCALER_8                            1
#define PRESCALER_64                           2
#define PRESCALER_256                          3
#define PRESCALER_1024                         4


void TMR1_INIT(void);

void TMR1_START(void);

void TMR1_SET_DELAY(u_int32 DELAY_MS);

void TMR1_STOP(void);


void TMR1_PWM_START(void);

void TMR1_PWM_DUTY_CYCLE(u_int8 DUTY);

void TMR1_PWM_STOP(void);


u_int16 TMR1_COUNTER(void);

#endif /* TMR1_H_ */