/*================================================================================================
								  	PROJECT BW Ver.1.0
								  	 BW BRUSHLESS DC FAN
================================================================================================*/

#ifndef BW_BLDC_FAN_H
#define BW_BLDC_FAN_H

#include "main.h"

/*
 *  BW BRUSHLESS DC MOTOR FAN TYPEDEF
 */
GPIO_InitTypeDef  			GPIO_InitStructure, GPIO_I2C,GPIO_InitStructure;
TIM_TimeBaseInitTypeDef     TIM_TimeBaseStructure;
TIM_OCInitTypeDef           TIM_OCInitStructure;


/*
 *
 */
void TIM4_PWM_Config(void);
void button_init(void);
void BW_BLDC_Init(void);
void BW_BLDC_Fight(void);
void TIM12_PWM_Config(void);
void TIM4_PWM_Init(void);

void button_init(void);

#define BLDC_FAN TIM4->CCR1
#define BW_BLDC_ON  BLDC_FAN = 4000
#define BW_BLDC_OFF BLDC_FAN= 2000
#endif
