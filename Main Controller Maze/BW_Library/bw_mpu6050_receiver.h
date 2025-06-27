
#include "main.h"
#ifndef BW_MPU6050_RECEIVER_H
#define BW_MPU6050_RECEIVER_H


//MPU6050 receiver variables
extern unsigned int IMU_SLAVE_DATA[4];
extern int YAW_IMU;
extern int PITCH_IMU;
extern int ROLL_IMU;

//COMMAND FLAG FROM MAIN CONTROLLER
extern unsigned int COMMAND_FLAG_A;
extern unsigned int COMMAND_FLAG_B;
extern unsigned int COMMAND_COMPLETED;

//MANDATORY COMMAND HYBRID IMU PROCESSOR
extern const int IMU_CMD_SEND_RAW; //DATA
extern unsigned int BW_SOUND_ACTIVATED;

//SOUND
extern const int SOUNDCHECK;

void UART4_Init(uint32_t baudrate);
void Display_IMU_Data(void);
void IMU_CMD(USART_TypeDef* USARTx, volatile char *s);
void IMU_Transmit(USART_TypeDef* USARTx, int DATA);

#endif
