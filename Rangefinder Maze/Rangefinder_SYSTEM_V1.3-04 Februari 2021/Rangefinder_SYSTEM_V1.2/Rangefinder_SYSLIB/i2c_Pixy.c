#include "i2c_pixy.h"
//#include "main.h"


//void i2c_Pixy_Init(void)
//{
//	I2C_InitTypeDef	I2C_InitStructure;
//	GPIO_InitTypeDef GPIO_InitStructure;
//
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);
//	I2C_InitStructure.I2C_ClockSpeed = 100000;
//	I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
//	I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
//	I2C_InitStructure.I2C_OwnAddress1 = 0x00;
//	I2C_InitStructure.I2C_Ack = I2C_Ack_Disable;
//	I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
//	I2C_Init(PIXY_I2Cx, &I2C_InitStructure);
//	I2C_Cmd(PIXY_I2Cx, ENABLE);
//
//	RCC_APB2PeriphClockCmd(PIXY_GPIO_RCC, ENABLE);
//	GPIO_InitStructure.GPIO_Pin = I2C_PIXY_SCL | I2C_PIXY_SDA;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
//	GPIO_Init(PIXY_GPIOx, &GPIO_InitStructure);
//}
//
//void i2c_start(void)
//{
//	while(I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY));
//	I2C_GenerateSTART(PIXY_I2Cx, ENABLE);
//	while(!I2C_CheckEvent(PIXY_I2Cx, I2C_EVENT_MASTER_MODE_SELECT));
//}
//
//void i2c_stop(void)
//{
//	I2C_GenerateSTOP(PIXY_I2Cx, ENABLE);
//	while(I2C_GetFlagStatus(PIXY_I2Cx, I2C_FLAG_STOPF));
//}
//
//void i2c_address_direction(uint8_t address, uint8_t direction)
//{
//	I2C_Send7bitAddress(PIXY_I2Cx, address, direction);
//
//	if (direction == I2C_Direction_Transmitter)
//	{
//		while(!I2C_CheckEvent(PIXY_I2Cx, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
//	}
//	else if(direction == I2C_Direction_Receiver)
//	{
//		while(!I2C_CheckEvent(PIXY_I2Cx, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));
//	}
//}
//
//void i2c_transmit(uint8_t byte)
//{
//    I2C_SendData(PIXY_I2Cx, byte);
//    while (!I2C_CheckEvent(PIXY_I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
//}
//
//uint8_t i2c_receive_ack(void)
//{
//    I2C_AcknowledgeConfig(PIXY_I2Cx, ENABLE);
//    while (!I2C_CheckEvent(PIXY_I2Cx, I2C_EVENT_MASTER_BYTE_RECEIVED));
//    return I2C_ReceiveData(PIXY_I2Cx);
//}
//
//uint8_t i2c_receive_nack(void)
//{
//    I2C_AcknowledgeConfig(PIXY_I2Cx, DISABLE);
//    while (!I2C_CheckEvent(PIXY_I2Cx, I2C_EVENT_MASTER_BYTE_RECEIVED));
//    return I2C_ReceiveData(PIXY_I2Cx);
//}
//
//void i2c_write(uint8_t address, uint8_t data)
//{
//    i2c_start();
//    i2c_address_direction(address << 1, I2C_Direction_Transmitter);
//    i2c_transmit(data);
//    i2c_stop();
//}
//
//void i2c_read(uint8_t address, uint8_t* data)
//{
//    i2c_start();
//    i2c_address_direction(address << 1, I2C_Direction_Receiver);
//    *data = i2c_receive_nack();
//    i2c_stop();
//}

