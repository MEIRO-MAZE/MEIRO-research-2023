#ifndef I2C_PIXY_H
#define I2C_PIXY_H

#include "main.h"

#define I2C_PIXY_SCL	GPIO_Pin_10
#define I2C_PIXY_SDA	GPIO_Pin_11
#define I2C_RCC			RCC_APB1Periph_I2C2
#define PIXY_I2Cx		I2C2
#define PIXY_GPIO_RCC	RCC_APB2Periph_GPIOB
#define PIXY_GPIOx		GPIOB

#define Transmitter		I2C_Direction_Transmitter
#define Receiver		I2C_Direction_Receiver

void i2c_Pixy_Init(void);
void i2c_start(void);
void i2c_stop(void);
void i2c_address_direction(uint8_t address, uint8_t direction);
void i2c_transmit(uint8_t byte);
uint8_t i2c_receive_ack(void);
uint8_t i2c_receive_nack(void);
void i2c_write(uint8_t address, uint8_t data);
void i2c_read(uint8_t address, uint8_t* data);

#endif
