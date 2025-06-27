/*==============================================================================================
								  	  PROJECT BW Ver.1.0
								  	 BW TRACER DECODER
==============================================================================================*/

#ifndef BW_TRACER_DECODER_H
#define BW_TRACER_DECODER_H

//#include "stm32f4xx.h"
//#include "stm32f4xx_gpio.h"
//#include "stm32f4xx_tim.h"
//#include "stm32f4xx_rcc.h"
////#include "stm32f4xx_adc.h"
////#include <stdio.h>
//
//#include "bw_systick_delay.h"
//#include "bw_macro_lib.h"
//#include "bw_global_var.h"
#include "main.h"


/*
 *  BW TRACER ENCODER TYPEDEF
 */
GPIO_InitTypeDef      	   GPIO_InitStructure;
TIM_OCInitTypeDef          TIM_OCInitStructure;

#define TRACER_INIT   GPIO_Pin_0 | GPIO_Pin_1| GPIO_Pin_2
#define TRACER_0   GPIOA, GPIO_Pin_0
#define TRACER_1   GPIOA, GPIO_Pin_1
#define TRACER_2   GPIOA, GPIO_Pin_2

extern int loop;
extern int TRACER;
const int TRC_BLACK = 1;
const int TRC_WHITE = 2;
const int TRC_RED   = 3;
const int TRC_BLUE  = 4;


/*
 *
 */
void BW_Tracer_Init(void);
void BW_RGB_Tracer_Encoder(void);

void Tracer_Decoder_Interrupt_Init(void);
void TIM2_IRQHandler(void);


#endif
