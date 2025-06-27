#ifndef __ADC_COMP_H
#define __ADC_COMP_H

//#include "main.h"
#include <stm32f10x_adc.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x.h>
#include <stm32f10x_rcc.h>
#include <stm32f10x_usart.h>
#include <stm32f10x.h>
#include <stm32f10x_i2c.h>
#include <stm32f10x_iwdg.h>
#include <stm32f10x_tim.h>
#include "delay.h"
#include <misc.h>
#include <stm32f10x_dma.h>

#define IR_FRONT		0
#define IR_STAIRS		1
#define IR_ASKEW_FR		2
#define IR_RIGHT		3
#define IR_ASKEW_RR		4
#define IR_ASKEW_FL		5
#define IR_LEFT			6
#define IR_ASKEW_RL		7


#define SHARP_FR_PIN	GPIO_Pin_3
#define SHARP_FL_PIN	GPIO_Pin_1
#define ChannelNol		ADC_Channel_0
#define ChannelSatu		ADC_Channel_1
#define ChannelDua		ADC_Channel_2

uint32_t adc_value;
extern uint8_t sharp_data[];
extern int data_sharp2;
extern int buffer_fl;
extern int buffer_up;

extern volatile uint16_t ADCBuffer[];

void ADC_DMA_init(void);
void ADC_Config_GPIOA(void);
void ADC_Config_GPIOB(void);
void ADC_Calibration(void);
uint16_t ADC1_Read(void);
uint16_t Sharp[2];
void SHARP_FL_read(void);
void SHARP_IR_read(int IR_PIN);
void BW_ADC_Init(void);
void SHARP_BUMPER_RIGHT_Read(void);
void SHARP_BUMPER_LEFT_Read(void);
void Stair_Read();
uint16_t GetADCChanel(int8_t chanel);

#endif
