/*
 * I2C.h
 *
 * Created: 1/2/2021 10:16:11 PM
 *  Author: mostafa gomaa
 */ 


#ifndef I2C_H_
#define I2C_H_

#include "standard_types.h"

#include "ATMEGA32_REGISTERS.h"

#include "common_macros.h"

#include "DIO.h"

#define F_CPU 8000000

#define I2C_400KHZ_SPEED                  0

#define I2C_200KHZ_SPEED                  1

#define I2C_ENABLE_INTERRUPT              0

#define I2C_DISABLE_INTERRUPT             1

#define ENABLE_ACK_BIT                    0

#define DISABLE_ACK_BIT                   1

#define ENABLE_General_Call_Recognition   0

#define DISABLE_General_Call_Recognition  1

#define START_ACK                0x08 // start has been sent
#define REP_START_ACK            0x10 // repeated start
#define SLAVE_ADD_AND_WR_ACK     0x18 // Master transmit ( slave address + Write request ) ACK
#define SLAVE_ADD_AND_RD_ACK     0x40 // Master transmit ( slave address + Read request ) ACK
#define WR_BYTE_ACK              0x28 // Master transmit data ACK
#define RD_BYTE_WITH_NACK        0x58// Master received data with not NACK
#define RD_BYTE_WITH_ACK         0x50// Master received data with ACK
#define SLAVE_ADD_RCVD_RD_REQ    0xA8 // means that slave address is received with write req
#define SLAVE_ADD_RCVD_WR_REQ    0x60 // means that slave address is received with read req
#define SLAVE_DATA_RECEIVED      0x80 // means that read byte req is received
#define SLAVE_BYTE_TRANSMITTED   0xC0 // means that write byte req is received

void I2C_MASTER_INIT();

void I2C_SLAVE_INIT(u_int8 address);

void I2C_START_CONDITION();

void I2C_REPEATED_START();

void I2C_SEND_TO_SLAVE(u_int8 address);

void I2C_READ_FROM_SLAVE(u_int8 address);

void I2C_SEND_DATA(u_int8 DATA);

u_int8 I2C_RECEIVE_DATA();

void I2C_STOP_CONDITION();


#endif /* I2C_H_ */