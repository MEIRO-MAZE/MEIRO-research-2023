/*==============================================================================================
								  	  PROJECT BW Ver.1.0
								  	 BW TRACER DECODER
==============================================================================================*/

#include "bw_tracer_decoder.h"

void BW_Tracer_Init(void)
{
	/* GPIOA Periph clock enable */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

    /* Configure PDA0 in output pushpull mode */
    GPIO_InitStructure.GPIO_Pin = TRACER_INIT;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void BW_RGB_Tracer_Encoder(void)
{
	if ( 	GPIO_ReadInputDataBit(TRACER_2)==1 &&
				GPIO_ReadInputDataBit(TRACER_1)==0 &&
				GPIO_ReadInputDataBit(TRACER_0)==1
		  )
		{
			TRACER= TRC_WHITE;
		}

	if ( 	GPIO_ReadInputDataBit(TRACER_2)==1 &&
				GPIO_ReadInputDataBit(TRACER_1)==1 &&
				GPIO_ReadInputDataBit(TRACER_0)==0
		  )
		{
			TRACER= TRC_BLACK;
		}

	if (    GPIO_ReadInputDataBit(TRACER_2)==0 &&
			GPIO_ReadInputDataBit(TRACER_1)==0 &&
			GPIO_ReadInputDataBit(TRACER_0)==1
	   )
		{
			TRACER= TRC_RED;
		}
	//GPIO_ResetBits(LED_ALL);

	if ( 	GPIO_ReadInputDataBit(TRACER_2)==0 &&
				GPIO_ReadInputDataBit(TRACER_1)==1 &&
				GPIO_ReadInputDataBit(TRACER_0)==0
		  )
		{
			TRACER= TRC_BLUE;
		}
	//GPIO_ResetBits(LED_ALL);

}

////ADC INTERRUPT INIT
//void Tracer_Decoder_Interrupt_Init(void)
//{
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
//
//	TIM_TimeBaseInitTypeDef    TIM_TimeBaseStructure;
//
//	TIM_TimeBaseStructure.TIM_Prescaler = 335;  //f per count= 84000000/(335+1)=250000Hz = 0.004ms
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
//	TIM_TimeBaseStructure.TIM_Period = 5000; //0.004*5000=50ms jadi sampling adc setiap 20ms
//	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
//	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
//	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
//
//	TIM_Cmd(TIM2, ENABLE); //default di off dulu
//
//	TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
//
//    NVIC_InitTypeDef NVIC_InitStructure;
//    NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//    NVIC_Init(&NVIC_InitStructure);
//
//}
//
//void TIM2_IRQHandler(void)
//{
//    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
//    	{
//    		BW_RGB_Tracer_Encoder();
//    		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
//    	}
//}
