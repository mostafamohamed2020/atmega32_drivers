/*
 * External_Interrupt.h
 *
 * Created: 11/13/2020 1:08:02 AM
 *  Author: mostafa gomaa
 */ 


#ifndef EXTERNAL_INTERRUPT_H_
#define EXTERNAL_INTERRUPT_H_

#include "External_Interrupt_Config.h"
#include "ATMEGA32_REGISTERS.h"
#include "common_macros.h"

#define GLOBAL_INTERRUPT_STATE_ENABLE    1
#define GLOBAL_INTERRUPT_STATE_DISABLE   0

#define INT_TRIGGER_RISING_EDGE          0
#define INT_TRIGGER_FALLING_EDGE         1
#define INT_TRIGGER_ANY_CHANGE           2
#define INT_TRIGGER_LOW_LEVEL            3


void SET_GLOBALINTERRUPT(void);
void INT0_INIT(void);
void INT1_INIT(void);
void INT2_INIT(void);


#endif /* EXTERNAL_INTERRUPT_H_ */