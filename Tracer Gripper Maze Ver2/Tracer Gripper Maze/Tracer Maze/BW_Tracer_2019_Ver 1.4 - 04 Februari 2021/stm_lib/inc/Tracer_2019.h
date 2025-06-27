#ifndef TRACER_2019_H
#define TRACER_2019_H

#include <stm32f10x_gpio.h>
#include <misc.h>
#include <stm32f10x_rcc.h>
#include <stm32f10x_usart.h>
#include <stm32f10x.h>
#include <stm32f10x_i2c.h>
#include <stm32f10x_iwdg.h>
#include <stm32f10x_tim.h>
#include <stm32f10x_dma.h>
#include "TCS_Tracer2019.h"
#include "adc_comp.h"
#include "delay.h"
#include "string.h"
#include "stdlib.h"

#define Transistor_PIN RCC_APB2Periph_GPIOB

#define BASE_ON 0
#define BASE_OFF 1

#define Pin_ADC_0 GPIO_Pin_0
#define Pin_ADC_1 GPIO_Pin_1
#define Pin_ADC_2 GPIO_Pin_2
#define Pin_ADC_3 GPIO_Pin_3
#define Pin_ADC_4 GPIO_Pin_4
#define Pin_ADC_5 GPIO_Pin_5

#define Trans_Pin_1 GPIO_Pin_12
#define Trans_Pin_2 GPIO_Pin_4
#define Trans_Pin_3 GPIO_Pin_8

#define Trans1_Base_ON GPIO_ResetBits(GPIOB, GPIO_Pin_12);
#define Trans2_Base_ON GPIO_ResetBits(GPIOB, GPIO_Pin_4);
#define Trans3_Base_ON GPIO_ResetBits(GPIOB, GPIO_Pin_8);

#define Trans1_Base_OFF GPIO_SetBits(GPIOB, GPIO_Pin_12);
#define Trans2_Base_OFF GPIO_SetBits(GPIOB, GPIO_Pin_4);
#define Trans3_Base_OFF GPIO_SetBits(GPIOB, GPIO_Pin_8);

#define SECTION_FRONT 0
#define SECTION_MIDDLE 1
#define SECTION_BACK 2
#define FINAL 3

#define Tracer_Upper_Threshold 600
#define	Tracer_Lower_Threshold 290

#define COLOUR_BLACK 0
#define COLOUR_GRAY 1
#define COLOUR_WHITE 2

#define CMD_GET_TRACER  0x53
#define HYBRID_CMD_SEND_THRESHOLD 0x58
#define TRACER_CMD_SEND_RAW 0x42
#define CMD_IDLE 0x5E
#define TRACER_CMD_SEND_RGB 0x70

extern unsigned int COMMAND_FLAG_A ;
extern unsigned int COMMAND_FLAG_B ;
extern unsigned int COMMAND_COMPLETED;
extern const int CMD_GET_TCS3200;
extern const int RAW_VAL_FLAG ;
extern const int RAW_DATA ;
extern const int STAT_DATA ;
extern const int TH_DATA ;
extern const int RGB_VAL_FLAG;

#define NO_DATA 0

extern unsigned int COMMAND_FLAG_A ;
extern unsigned int COMMAND_FLAG_B ;
//extern volatile uint8_t char_;

extern unsigned int ADC_Buf[];
extern unsigned int ADC_SUM;
extern unsigned int Tracer_ADC_Raw[];
extern unsigned int Tracer_Stat[];
extern uint8_t SLAVE_COMMAND[3];

void USART2_Init(int Baudrate);
void USART_Send(USART_TypeDef *USARTx, unsigned int DATA);
void Reset_Pin_Init();
void Set_Transistor(int state);
void Tracer_Get_Value(unsigned int adc);
void Tracer_Get_Colour();
void setclockto72();
void I2C_Initialize(I2C_TypeDef *I2Cx);


#endif	    
