/*
 * I2C.c
 *
 * Created: 1/2/2021 10:15:53 PM
 *  Author: mostafa gomaa
 */ 

#include "I2C.h"

void I2C_MASTER_INIT()
{
	/* SET PINS AS OUTPUT PINS */
	DIO_SETPINDIR(DIO_PORTC , DIO_PIN0 , DIO_PIN_OUTPUT);
	DIO_SETPINDIR(DIO_PORTC , DIO_PIN1 , DIO_PIN_OUTPUT);
	
	/* ENABLE TWI PRIPHERAL */
	set_bit(TWCR , 2);
	
	/* SPEED SELECTION  WHEN F_CPU = 8 MHZ */
	#if I2C_SPEED_MODE == I2C_400KHZ_SPEED
	 
	 TWBR = 0X02;
	 
	#elif I2C_SPEED_MODE == I2C_400KHZ_SPEED
	
	 TWBR = 0X0C;
	#endif
}

void I2C_SLAVE_INIT(u_int8 address)
{
	/* STORE THE ADDRESS OF THE SLAVE */
	#if General_Call_Recognition_MODE == DISABLE_General_Call_Recognition
	 
	 TWAR = (address << 1);
	 
	#elif General_Call_Recognition_MODE == ENABLE_General_Call_Recognition
	 
	 TWAR = (address << 1) | (0x01);
	#endif
	
	/* ENABLE TWI PRIPHERAL */
	set_bit(TWCR , 2);
	
}

void I2C_START_CONDITION()
{
	/* GENERATE START CONDITION */
	set_bit(TWCR , 5);
	
	/* CLEAR THE FLAG */
	set_bit(TWCR , 7);
	
	/* CHECK CONDITION OCCURANCE */
	while (get_bit(TWCR , 7) == 0);
	
	while((TWSR & 0XF8) != START_ACK);
}

void I2C_REPEATED_START()
{
	/* GENERATE START CONDITION */
	set_bit(TWCR , 5);
	
	/* CLEAR THE FLAG */
	set_bit(TWCR , 7);
	
	/* CHECK CONDITION OCCURANCE */
	while (get_bit(TWCR , 7) == 0);
	
	while((TWSR & 0XF8) != REP_START_ACK);
	
}

void I2C_SEND_TO_SLAVE(u_int8 address)
{
	TWDR = (address << 1);
	
	/* CLEAR THE FLAG */
	set_bit(TWCR , 7);
	
	/* CHECK CONDITION OCCURANCE */
	while (get_bit(TWCR , 7) == 0);
	
	while((TWSR & 0XF8) != SLAVE_ADD_AND_WR_ACK);
	
}

void I2C_READ_FROM_SLAVE(u_int8 address)
{
	TWDR = ((address << 1) | 0x01 );
	
	/* CLEAR THE FLAG */
	set_bit(TWCR , 7);
	
	/* CHECK CONDITION OCCURANCE */
	while (get_bit(TWCR , 7) == 0);
	
	while((TWSR & 0XF8) != SLAVE_ADD_AND_RD_ACK);
}

void I2C_SEND_DATA(u_int8 DATA)
{
	TWDR = DATA ; 
	
	/* CLEAR THE FLAG */
	set_bit(TWCR , 7);
	
	/* CHECK CONDITION OCCURANCE */
	while (get_bit(TWCR , 7) == 0);
	
	while((TWSR & 0XF8) != WR_BYTE_ACK);
}

u_int8 I2C_RECEIVE_DATA()
{
	/* CLEAR THE FLAG */
	set_bit(TWCR , 7);
	
	/* CHECK CONDITION OCCURANCE */
	while (get_bit(TWCR , 7) == 0);
	
	while((TWSR & 0XF8) != RD_BYTE_WITH_ACK);
	
	return TWDR ; 
}

void I2C_STOP_CONDITION()
{
	set_bit(TWCR , 4);
	
	/* CLEAR THE FLAG */
	set_bit(TWCR , 7);
	
	/* CHECK CONDITION OCCURANCE */
	while (get_bit(TWCR , 7) == 0);
}
