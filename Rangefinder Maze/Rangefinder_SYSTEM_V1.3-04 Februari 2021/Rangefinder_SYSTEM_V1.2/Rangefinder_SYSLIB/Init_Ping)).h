#ifndef INIT_PING_H
#define INIT_PING_H

#include "main.h"

#define SIG_PIN				RCC_APB2Periph_GPIOB
#define SIG					GPIOB

//#define ASKEW_FR_SIG 		GPIO_Pin_6
//#define ASKEW_FL_SIG		GPIO_Pin_12
//#define PING_R_SIG			GPIO_Pin_11
//#define PING_L_SIG			GPIO_Pin_13
//#define ASKEW_RL_SIG		GPIO_Pin_14
//#define ASKEW_RR_SIG		GPIO_Pin_8
//#define PING_REAR_SIG		GPIO_Pin_15
//#define PING_FRONT_SIG		GPIO_Pin_4
//#define PING_UP_RIGHT_SIG	GPIO_Pin_5
//#define PING_UP_LEFT_SIG	GPIO_Pin_3

#define ASKEW_FR_SIG 		GPIO_Pin_1
#define ASKEW_FL_SIG		GPIO_Pin_3
#define PING_R_SIG			GPIO_Pin_12
#define PING_L_SIG			GPIO_Pin_4
#define ASKEW_RL_SIG		GPIO_Pin_5
#define ASKEW_RR_SIG		GPIO_Pin_13
#define PING_REAR_SIG		GPIO_Pin_9
#define PING_FRONT_SIG		GPIO_Pin_15
#define PING_UP_RIGHT_SIG	GPIO_Pin_14
#define PING_UP_LEFT_SIG	GPIO_Pin_6

// Identifier PING
#define ASKEW_FR			0
#define ASKEW_FL			1
#define PING_R				2
#define PING_L				3
#define ASKEW_RR			4
#define ASKEW_RL			5
#define PING_FRONT			6
#define PING_REAR			7
#define PING_UP_RIGHT		8
#define PING_UP_LEFT		9

#define ENA					1
#define DIS					0

#define UV_PIN				RCC_APB2Periph_GPIOB
#define UV					GPIO_Pin_7
#define UV2					GPIO_Pin_1
#define ERROR_CODE			253
#define FIRE				0
#define NO_FIRE				1

uint32_t time_us;
uint8_t distance[10];
uint32_t time_out_flag;
uint8_t UV_DATA1, UV_DATA2, CAT_DATA1, CAT_DATA2, ROOM_STAT;

void PING_Init(void);
void PING_Init_IN(int PING);
void PING_Init_OUT(int PING);
void TIM4_SWITCH(int PARAM);
void TIM4_IRQHandler(void);
void USART1_Init(int baudrate);
void USART_Send(USART_TypeDef *USARTx, unsigned int DATA);
void USART1_IRQHandler(void);
void TIM_Reset(TIM_TypeDef *TIMx);
void PingScan(uint32_t PING);
void GPIO_driver_motor(void);
void PING_TIM_Init(void);
int timeout(int val);
void Start_TIM4(void);
void UV_GPIO_Init(void);
void IR_CAT_Init(void);
void CAT_READ(void);
void allpincheck(void);
void out_all(void);
void UV_Read_Only(void);
void UV_Send_Only(void);


#endif
