/*==============================================================================================
								 	 PROJECT BW Ver.1.0
								  	  	MACRO LIBRARY
==============================================================================================*/
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_adc.h"
#include "stm32f4xx_tim.h"
#include "misc.h"
#include "stm32f4xx_usart.h"
#include "stm32f4xx_i2c.h"

#include <stdio.h>
/*
 * PROJECT BW MAIN CONTROLLER - TYPEDEF
 */

// GPIO TYPEDEF
GPIO_InitTypeDef          	GPIO_InitStructure;

// ADC TYPEDEF
ADC_InitTypeDef       		ADC_InitStructure;
ADC_CommonInitTypeDef 		ADC_CommonInitStructure;

// TIMER & INTERRUPT TYPEDEF
TIM_TimeBaseInitTypeDef     TIM_TimeBaseStructure;
TIM_OCInitTypeDef           TIM_OCInitStructure;
NVIC_InitTypeDef 			NVIC_InitStructure;

//USART COMMNUNICATION TYPEDEF
USART_InitTypeDef 			USART_InitStructure;

//I2C COMMUNICATION TYPEDEF
I2C_InitTypeDef  			I2C_InitStructure;

#define SEARCH_FIRE_RESET 0x31
#define SEARCH_FIRE_GO    0x32
#define SRC_FR_A 0x41 //1
#define SRC_FR_B 0x42 //2
#define SRC_FR_C 0x43 //3
#define SRC_FR_D 0x44 //4
#define SRC_FR_E 0x45 //5
#define SRC_FR_F 0x46 //6
#define SRC_FR_G 0x47 //7
#define SRC_FR_H 0x48 //8
#define SRC_FR_I 0x49 //9
#define SRC_FR_J 0x4A //10
#define SRC_FR_K 0x4B //11
#define SRC_FR_L 0x4C //12
#define SRC_FR_M 0x4D //13
#define SRC_FR_N 0x4E //14
#define SRC_FR_O 0x4F //15
#define SRC_FR_P 0x50 //16

