/*	New Ping))) by Parallax Library
 * 	Tested !!
 * 	Last Update on Desember 02th, 2020
 * 	Created by Reyhan
 * 	Revised by Muhammad Yogi Nurrohman
 * 	Logs :
 * 	- Finished function and variables library
 * 	- Adjusted method to take measurments
 * 	- Fixed errors on process of emitting and receiving the wave
 * 	- Fixed errors caused by Interrupt, changed to use timer
 * 	- Code Cleanup and added timeout
 * 	- Fixed and added proper timeout method to avoid freeze
 * 	- Revised timeout mechanism to remove 0 on distance value being sent
 */


#include "main.h"

void UV_GPIO_Init(void)
{
	RCC_APB2PeriphClockCmd(UV_PIN, ENABLE);
	GPIO_InitStructure.GPIO_Pin   = UV | UV2;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}
void IR_CAT_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

}

void PING_Init_OUT(int PING)
{
	RCC_APB2PeriphClockCmd(SIG_PIN, ENABLE);
	GPIO_InitStructure.GPIO_Pin   = PING;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(SIG, &GPIO_InitStructure);
}

void PING_Init_IN(int PING)
{
	RCC_APB2PeriphClockCmd(SIG_PIN, ENABLE);
	GPIO_InitStructure.GPIO_Pin   = PING;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(SIG, &GPIO_InitStructure);
}

void PING_TIM_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	TIM_InitStructure.TIM_Prescaler = 71;
	TIM_InitStructure.TIM_Period = 65534;
	TIM_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
//	TIM_InitStructure.TIM_RepetitionCounter = 0;
	TIM_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4, &TIM_InitStructure);

//	TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);

//	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_Init(&NVIC_InitStructure);
}

void TIM4_SWITCH(int PARAM)
{
	switch(PARAM)
	{
		case ENA :
		{
			TIM_Cmd(TIM4, ENABLE);
			time_us = 0;
			TIM_Reset(TIM4);
		}break;
		case DIS :
		{
			TIM_Cmd(TIM4, DISABLE);
			time_us = TIM4 -> CNT;
		}break;
	}
}

void Pulse(uint32_t PING)
{
	GPIO_ResetBits(SIG, PING);
	DelayUs(2);
	GPIO_SetBits(SIG, PING);
	if(PING == PING_FRONT_SIG || PING == PING_UP_RIGHT_SIG || PING == PING_UP_LEFT_SIG)
	{
//		DelayUs(11);
		DelayUs(7);
	}
	else
	{
		DelayUs(7);
	}
	GPIO_ResetBits(SIG, PING);
	DelayUs(5);
}

void TIM_Reset(TIM_TypeDef *TIMx)
{
	assert_param(IS_TIM_ALL_PERIPH(TIMx));
	TIMx -> CNT = 0;
}

void TIM4_IRQHandler(void)
{
//	if(TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)
//	{
//		time_us++;
//	}
}

void USART1_Init(int baudrate)
{
	   /* Enable peripheral clocks for USART1 on GPIOA */
	    RCC_APB2PeriphClockCmd(
	        RCC_APB2Periph_USART1 |
	        RCC_APB2Periph_GPIOA |
	        RCC_APB2Periph_AFIO, ENABLE);

	    /* Configure PA9 and PA10 as USART1 TX/RX */

	    /* PA9 = alternate function push/pull output */
	    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	    GPIO_Init(GPIOA, &GPIO_InitStructure);

	    /* PA10 = floating input */
	    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	    GPIO_Init(GPIOA, &GPIO_InitStructure);

	    /* Configure and initialize usart... */
	    USART_InitStructure.USART_BaudRate = baudrate;
	    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	    USART_InitStructure.USART_StopBits = USART_StopBits_1;
	    USART_InitStructure.USART_Parity = USART_Parity_No;
	    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	    USART_Init(USART1, &USART_InitStructure);
	    /* Enable USART1 */
	    USART_Cmd(USART1, ENABLE);

	    // Enable the USART RX Interrupt
	    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	    NVIC_Init(&NVIC_InitStructure);

}

void allpincheck(void)
{
    RCC_APB2PeriphClockCmd(
        RCC_APB2Periph_GPIOA |
        RCC_APB2Periph_GPIOB |
        RCC_APB2Periph_GPIOC |
        RCC_APB2Periph_GPIOD |
        RCC_APB2Periph_GPIOE, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOE, &GPIO_InitStructure);
}

void out_all(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_All);
	GPIO_SetBits(GPIOB, GPIO_Pin_All);
	GPIO_SetBits(GPIOC, GPIO_Pin_All);
	GPIO_SetBits(GPIOD, GPIO_Pin_All);
	GPIO_SetBits(GPIOE, GPIO_Pin_All);
}

void USART_Send(USART_TypeDef *USARTx, unsigned int DATA)
{
	while(USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET){};
	USART_SendData(USARTx,DATA);
	while(USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET){};
}

/*
void USART1_IRQHandler(void)
{
	if(USART_GetITStatus(USART1, USART_IT_RXNE))
	{
		while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);
		char t = USART_ReceiveData(USART1);USART1 -> DR;
		ROOM_STAT = t;
	}
}
*/

void USART1_IRQHandler(void)
{
  if(USART_GetITStatus(USART1, USART_IT_RXNE))//enter interrupt when STM32 receive data.
  {
     USART_ClearITPendingBit(USART1, USART_IT_RXNE);
     ROOM_STAT = USART_ReceiveData(USART1); //receive a char
  }
}

void Start_TIM4(void)
{
	TIM_Cmd(TIM4, ENABLE);
	TIM_Reset(TIM4);
}

int timeout(int val)
{
	if((TIM4 -> CNT) >= val)
	{
		time_out_flag = 1;
		TIM_Cmd(TIM4, DISABLE);
	}
	else time_out_flag = 0;;
	return time_out_flag;
}


void PingScan(uint32_t PING)
{
	int timeout_occured = 0;
	switch(PING)
	{
		case ASKEW_FR :
		{
			PING_Init_OUT(ASKEW_FR_SIG);
			Pulse(ASKEW_FR_SIG);
			PING_Init_IN(ASKEW_FR_SIG);
			Start_TIM4();
			while((GPIO_ReadInputDataBit(SIG, ASKEW_FR_SIG)) == 1){if(timeout(50000) == 1)break;}
			Start_TIM4();
			while((GPIO_ReadInputDataBit(SIG, ASKEW_FR_SIG)) == 0){if(timeout(50000) == 1)break;}
			TIM4_SWITCH(ENA);
			while((GPIO_ReadInputDataBit(SIG, ASKEW_FR_SIG)) == 1){if(timeout(50000) == 1){TIM_Cmd(TIM4, DISABLE);TIM_Reset(TIM4);timeout_occured = 1;break;}}
			TIM4_SWITCH(DIS);
		}break;

		case ASKEW_FL :
		{
			PING_Init_OUT(ASKEW_FL_SIG);
			Pulse(ASKEW_FL_SIG);
			PING_Init_IN(ASKEW_FL_SIG);
			Start_TIM4();
			while((GPIO_ReadInputDataBit(SIG, ASKEW_FL_SIG)) == 1){if(timeout(50000) == 1)break;}
			Start_TIM4();
			while((GPIO_ReadInputDataBit(SIG, ASKEW_FL_SIG)) == 0){if(timeout(50000) == 1)break;}
			TIM4_SWITCH(ENA);
			while((GPIO_ReadInputDataBit(SIG, ASKEW_FL_SIG)) == 1){if(timeout(50000) == 1){TIM_Cmd(TIM4, DISABLE);TIM_Reset(TIM4);timeout_occured = 1;break;}}
			TIM4_SWITCH(DIS);
		}break;

		case PING_R :
		{
			PING_Init_OUT(PING_R_SIG);
			Pulse(PING_R_SIG);
			PING_Init_IN(PING_R_SIG);
			Start_TIM4();
			while((GPIO_ReadInputDataBit(SIG, PING_R_SIG)) == 1){if(timeout(50000) == 1)break;}
			Start_TIM4();
			while((GPIO_ReadInputDataBit(SIG, PING_R_SIG)) == 0){if(timeout(50000) == 1)break;}
			TIM4_SWITCH(ENA);
			while((GPIO_ReadInputDataBit(SIG, PING_R_SIG)) == 1){if(timeout(50000) == 1){TIM_Cmd(TIM4, DISABLE);TIM_Reset(TIM4);timeout_occured = 1;break;}}
			TIM4_SWITCH(DIS);
		}break;

		case PING_L :
		{
			PING_Init_OUT(PING_L_SIG);
			Pulse(PING_L_SIG);
			PING_Init_IN(PING_L_SIG);
			Start_TIM4();
			while((GPIO_ReadInputDataBit(SIG, PING_L_SIG)) == 1){if(timeout(50000) == 1)break;}
			Start_TIM4();
			while((GPIO_ReadInputDataBit(SIG, PING_L_SIG)) == 0){if(timeout(50000) == 1)break;}
			TIM4_SWITCH(ENA);
			while((GPIO_ReadInputDataBit(SIG, PING_L_SIG)) == 1){if(timeout(50000) == 1){TIM_Cmd(TIM4, DISABLE);TIM_Reset(TIM4);timeout_occured = 1;break;}}
			TIM4_SWITCH(DIS);
		}break;

		case ASKEW_RR :
		{
			PING_Init_OUT(ASKEW_RR_SIG);
			Pulse(ASKEW_RR_SIG);
			PING_Init_IN(ASKEW_RR_SIG);
			Start_TIM4();
			while((GPIO_ReadInputDataBit(SIG, ASKEW_RR_SIG)) == 1){if(timeout(50000) == 1)break;}
			Start_TIM4();
			while((GPIO_ReadInputDataBit(SIG, ASKEW_RR_SIG)) == 0){if(timeout(50000) == 1)break;}
			TIM4_SWITCH(ENA);
			while((GPIO_ReadInputDataBit(SIG, ASKEW_RR_SIG)) == 1){if(timeout(50000) == 1){TIM_Cmd(TIM4, DISABLE);TIM_Reset(TIM4);timeout_occured = 1;break;}}
			TIM4_SWITCH(DIS);
		}break;

		case ASKEW_RL :
		{
			PING_Init_OUT(ASKEW_RL_SIG);
			Pulse(ASKEW_RL_SIG);
			PING_Init_IN(ASKEW_RL_SIG);
			Start_TIM4();
			while((GPIO_ReadInputDataBit(SIG, ASKEW_RL_SIG)) == 1){if(timeout(50000) == 1)break;}
			Start_TIM4();
			while((GPIO_ReadInputDataBit(SIG, ASKEW_RL_SIG)) == 0){if(timeout(50000) == 1)break;}
			TIM4_SWITCH(ENA);
			while((GPIO_ReadInputDataBit(SIG, ASKEW_RL_SIG)) == 1){if(timeout(50000) == 1){TIM_Cmd(TIM4, DISABLE);TIM_Reset(TIM4);timeout_occured = 1;break;}}
			TIM4_SWITCH(DIS);
		}break;

		case PING_FRONT :
		{
			PING_Init_OUT(PING_FRONT_SIG);
			Pulse(PING_FRONT_SIG);
			PING_Init_IN(PING_FRONT_SIG);
			Start_TIM4();
			while((GPIO_ReadInputDataBit(SIG, PING_FRONT_SIG)) == 1){if(timeout(50000) == 1)break;}
			Start_TIM4();
			while((GPIO_ReadInputDataBit(SIG, PING_FRONT_SIG)) == 0){if(timeout(50000) == 1)break;}
			TIM4_SWITCH(ENA);
			while((GPIO_ReadInputDataBit(SIG, PING_FRONT_SIG)) == 1){if(timeout(50000) == 1){TIM_Cmd(TIM4, DISABLE);TIM_Reset(TIM4);timeout_occured = 1;break;}}
			TIM4_SWITCH(DIS);
		}break;

		case PING_REAR :
		{
			PING_Init_OUT(PING_REAR_SIG);
			Pulse(PING_REAR_SIG);
			PING_Init_IN(PING_REAR_SIG);
			Start_TIM4();
			while((GPIO_ReadInputDataBit(SIG, PING_REAR_SIG)) == 1){if(timeout(50000) == 1)break;}
			Start_TIM4();
			while((GPIO_ReadInputDataBit(SIG, PING_REAR_SIG)) == 0){if(timeout(50000) == 1)break;}
			TIM4_SWITCH(ENA);
			while((GPIO_ReadInputDataBit(SIG, PING_REAR_SIG)) == 1){if(timeout(50000) == 1){TIM_Cmd(TIM4, DISABLE);TIM_Reset(TIM4);timeout_occured = 1;break;}}
			TIM4_SWITCH(DIS);
		}break;

		case PING_UP_LEFT :
		{
			PING_Init_OUT(PING_UP_RIGHT_SIG);
			Pulse(PING_UP_RIGHT_SIG);
			PING_Init_IN(PING_UP_RIGHT_SIG);
			Start_TIM4();
			while((GPIO_ReadInputDataBit(SIG, PING_UP_RIGHT_SIG)) == 1){if(timeout(50000) == 1)break;}
			Start_TIM4();
			while((GPIO_ReadInputDataBit(SIG, PING_UP_RIGHT_SIG)) == 0){if(timeout(50000) == 1)break;}
			TIM4_SWITCH(ENA);
			while((GPIO_ReadInputDataBit(SIG, PING_UP_RIGHT_SIG)) == 1){if(timeout(50000) == 1){TIM_Cmd(TIM4, DISABLE);TIM_Reset(TIM4);timeout_occured = 1;break;}}
			TIM4_SWITCH(DIS);
		}break;

		case PING_UP_RIGHT :
		{
			PING_Init_OUT(PING_UP_LEFT_SIG);
			Pulse(PING_UP_LEFT_SIG);
			PING_Init_IN(PING_UP_LEFT_SIG);
			Start_TIM4();
			while((GPIO_ReadInputDataBit(SIG, PING_UP_LEFT_SIG)) == 1){if(timeout(50000) == 1)break;}
			Start_TIM4();
			while((GPIO_ReadInputDataBit(SIG, PING_UP_LEFT_SIG)) == 0){if(timeout(50000) == 1)break;}
			TIM4_SWITCH(ENA);
			while((GPIO_ReadInputDataBit(SIG, PING_UP_LEFT_SIG)) == 1){if(timeout(50000) == 1){TIM_Cmd(TIM4, DISABLE);TIM_Reset(TIM4);timeout_occured = 1;break;}}
			TIM4_SWITCH(DIS);
		}break;
	}
	if(timeout_occured == 0)
	{
		if(PING == PING_FRONT || PING == PING_UP_RIGHT || PING == PING_UP_LEFT)
		{
			distance[PING] = (uint32_t)(time_us/58);
		}
		else
		{
			distance[PING] = (uint32_t)(time_us*0.034/2);
			if(distance[PING] >= 200)
			{
				distance[PING] = 200;
			}
		}
	}
	else distance[PING] = 253;
}


void GPIO_driver_motor(void)
{
//	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;

	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void UV_Send_Only(void)
{
	USART_Send(USART1, UV_DATA1);
	USART_Send(USART1, UV_DATA2);
}

void UV_Read_Only(void)
{
	if(ROOM_STAT == 1)
	{
		UV_DATA1 = GPIO_ReadInputDataBit(GPIOB, UV);
		UV_DATA2 = GPIO_ReadInputDataBit(GPIOB, UV2);
	}
	else
	{
		UV_DATA1 = 1;
		UV_DATA2 = 1;
	}
}

void CAT_READ(void)
{
	CAT_DATA1 = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11);
	USART_Send(USART1, 0/*CAT_DATA1*/);
}


