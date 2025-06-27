/*==============================================================================================
								  PROJECT BW Ver.2.0
							BW INTERRUPT MONITOR LIBRARY
==============================================================================================*/

//USER DEFINED LIBRARIES
#include "bw_interrupt_monitor.h"

//void BW_LED_Interrupt_Init(void)
//{
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);
//
//	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
//
//	TIM_TimeBaseStructure.TIM_Prescaler = 8399; //f per count= 84.000.000/(8399+1)=10.000Hz = 0,1ms (0,0001 s)
//	//335;  //f per count= 84000000/(335+1)=250000Hz = 0.004ms
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
//	TIM_TimeBaseStructure.TIM_Period = 5000;//10000; //0,1ms x 10000 = 1 s
//	//0.004*125000=500ms jadi sampling adc setiap 500ms //MAX 65535
//	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
//	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
//	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);
//	TIM_Cmd(TIM5, ENABLE); //default di off dulu
////	TIM_ITConfig(TIM5, TIM_IT_Update, ENABLE);
//	TIM_ITConfig(TIM5, TIM_IT_Update, DISABLE); //DEFAULT DISABLED
//
//    NVIC_InitTypeDef NVIC_InitStructure;
//    NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//    NVIC_Init(&NVIC_InitStructure);
//}
//

