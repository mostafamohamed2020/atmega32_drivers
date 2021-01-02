/*
 * ADC.h
 *
 * Created: 16/10/2020 01:47:37 م
 *  Author: mostafa gomaa
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "ATMEGA32_REGISTERS.h"
#include "standard_types.h"
#include "common_macros.h"
#include "ADC_Cfg.h"


#define  AREF_SOURCE      0
#define  AVCC_SOURCE      1
#define  INTERNAL_SOURCE  2


#define CHANNEL0            0
#define CHANNEL1            1
#define CHANNEL2            2
#define CHANNEL3            3
#define CHANNEL4            4
#define CHANNEL5            5
#define CHANNEL6            6
#define CHANNEL7            7

#define AUTO_RUNNING_MODE   0
#define EXTERNAL_INT0       1

#define  RIGHT_ADJUST       0
#define  LEFT_ADJUST        1

#define ADC_INT_ENABLED     0
#define ADC_INT_DISABLED    1


#define PRESCALER2          0
#define PRESCALER4          1
#define PRESCALER8          2
#define PRESCALER16         3
#define PRESCALER128        4



void ADC_Init(void);

u_int16 ADC_Read(void);


#endif /* ADC_H_ */