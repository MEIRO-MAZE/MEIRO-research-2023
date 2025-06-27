#include "Tracer_2023.h"

ADC_InitTypeDef ADC_InitStructure;
GPIO_InitTypeDef  GPIO_InitStructure;
USART_InitTypeDef USART_InitStructure;
NVIC_InitTypeDef NVIC_InitStructure;
I2C_InitTypeDef I2C_InitStructure;
TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

uint8_t SLAVE_COMMAND[3]={0,0,0};

unsigned int COMMAND_FLAG_A = 0x3C;
unsigned int COMMAND_FLAG_B = 0x3E;
unsigned int COMMAND_COMPLETED = 0x7C;
const int CMD_GET_TCS3200= 0x52;
const int RAW_VAL_FLAG = 0x52;
const int RAW_DATA = 0x10;
const int STAT_DATA = 0x11;
const int TH_DATA = 0x12;
const int RGB_VAL_FLAG = 0x13;
unsigned int ADC_Buf[5] = {0,0,0,0,0};
unsigned int ADC_SUM;
unsigned int Tracer_ADC_Raw[3] = {0,0,0};
unsigned int Tracer_Stat[4] = {0,0,0,0};
//uint8_t  char_ = 0;

void setclockto72()	
{
		ErrorStatus HSEStartUpStatus;
    /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration -----------------------------*/
    /* RCC system reset(for debug purpose) */
    RCC_DeInit();

    /* Enable HSE */
    RCC_HSEConfig( RCC_HSE_ON);

    /* Wait till HSE is ready */
    HSEStartUpStatus = RCC_WaitForHSEStartUp();

    if (HSEStartUpStatus == SUCCESS)
    {
        /* Enable Prefetch Buffer */
    	//FLASH_PrefetchBufferCmd( FLASH_PrefetchBuffer_Enable);

        /* Flash 2 wait state */
        //FLASH_SetLatency( FLASH_Latency_2);

        /* HCLK = SYSCLK */
        RCC_HCLKConfig( RCC_SYSCLK_Div1);

        /* PCLK2 = HCLK */
        RCC_PCLK2Config( RCC_HCLK_Div1);

        /* PCLK1 = HCLK/2 */
        RCC_PCLK1Config( RCC_HCLK_Div2);

        /* PLLCLK = 8MHz * 9 = 72 MHz */
        RCC_PLLConfig(0x00010000, RCC_PLLMul_9);

        /* Enable PLL */
        RCC_PLLCmd( ENABLE);

        /* Wait till PLL is ready */
        while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
        {
        }

        /* Select PLL as system clock source */
        RCC_SYSCLKConfig( RCC_SYSCLKSource_PLLCLK);

        /* Wait till PLL is used as system clock source */
        while (RCC_GetSYSCLKSource() != 0x08)
        {
        }
    }
    else
    { /* If HSE fails to start-up, the application will have wrong clock configuration.
     User can add here some code to deal with this error */

        /* Go to infinite loop */
        while (1)
        {
        }
    }
} 

void TIM_Init()
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5 , ENABLE);

	TIM_TimeBaseStructure.TIM_Period = 2672;
	TIM_TimeBaseStructure.TIM_Prescaler = 512;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);
    TIM_ITConfig(TIM5, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIM5, ENABLE);

    NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

void TIM5_IRQHandler()
{
	if (TIM_GetITStatus(TIM5, TIM_IT_Update) != RESET)
	{
		TIM_ClearITPendingBit(TIM5, TIM_IT_Update);
		TCS_Get_Rule(TCS34725_GET_CLEAR);
		TCS_Get_Rule(TCS34725_GET_RGB);
	}

}

void USART2_Init(int Baudrate)
 {
		/* UASRT CONFIGUARTION FOR NEW TRACER*/
 		RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2 , ENABLE);
 		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);
	    /* Configure PB10 and PB11 as USART1 TX/RX */

	    /*alternate function push/pull output as Tx */
	    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 ;
	    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	    GPIO_Init(GPIOA, &GPIO_InitStructure);


	    /* floating input as Rx*/
	    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	    GPIO_Init(GPIOA, &GPIO_InitStructure);


	    /* Configure and initialize usart... */
	    USART_InitStructure.USART_BaudRate = Baudrate;
	    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	    USART_InitStructure.USART_StopBits = USART_StopBits_1;
	    USART_InitStructure.USART_Parity = USART_Parity_No;
	    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	    USART_Init(USART2, &USART_InitStructure);

	    /* Enable USART */
	    USART_Cmd(USART2, ENABLE);

	    USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
	    NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
	    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	    NVIC_Init(&NVIC_InitStructure);
 }
 
 
void USART_Send(USART_TypeDef *USARTx, unsigned int DATA)
{
	while(USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET){};
	USART_SendData(USARTx,DATA);
	while(USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET){};
}
 

void I2C_Initialize(I2C_TypeDef *I2Cx)
{
	if(I2Cx == I2C1)
	{
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

		/* Configure I2C_EE pins: SCL and SDA */
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6 | GPIO_Pin_7;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
		GPIO_Init(GPIOB, &GPIO_InitStructure);

		/* I2C configuration */
		I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
		I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
		I2C_InitStructure.I2C_OwnAddress1 = 0x00;
		I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
		I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
		I2C_InitStructure.I2C_ClockSpeed = 50000;

		/* I2C Peripheral Enable */
		I2C_Cmd(I2C1, ENABLE);
		/* Apply I2C configuration after enabling it */
		I2C_Init(I2C1, &I2C_InitStructure);
	}
	else if(I2Cx == I2C2)
	{
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C2, ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

		/* Configure I2C_EE pins: SCL and SDA */
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_10 | GPIO_Pin_11;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
		GPIO_Init(GPIOB, &GPIO_InitStructure);

		/* I2C configuration */
		I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
		I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
		I2C_InitStructure.I2C_OwnAddress1 = 0x38;
		I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
		I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
		I2C_InitStructure.I2C_ClockSpeed = 50000;



		/* I2C Peripheral Enable */
		I2C_Cmd(I2C2, ENABLE);
		/* Apply I2C configuration after enabling it */
		I2C_Init(I2C2, &I2C_InitStructure);
	}
}
 
void Reset_Pin_Init()
 {
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
 }
 
void Tracer_Get_Value(unsigned int adc)
{
	int count = 0;
//	ADC_GetConversionValue(ADC1);
//	ADC_SoftwareStartConvCmd(ADC1,ENABLE);

	switch(adc)
	{
		case ADC_Channel_0:
		{
			for(count=0;count<=4;count++)
			{
				ADC_Buf[count] = Get_ADC_Value(ADC_Channel_0);
//				DelayMs(5);
			}
			ADC_SUM = ADC_Buf[0]+ADC_Buf[1]+ADC_Buf[2]+ADC_Buf[3]+ADC_Buf[4];
			Tracer_ADC_Raw[SECTION_BACK]=ADC_SUM/5;
			
			if(Tracer_ADC_Raw[SECTION_BACK] >= Tracer_Upper_Threshold)
			{
				Tracer_Stat[SECTION_BACK] = COLOUR_WHITE;
			}
			else if(Tracer_ADC_Raw[SECTION_BACK] > Tracer_Lower_Threshold && Tracer_ADC_Raw[SECTION_BACK] < Tracer_Upper_Threshold)
			{
				Tracer_Stat[SECTION_BACK] = COLOUR_GRAY;
			}
			else
			{
				Tracer_Stat[SECTION_BACK] = COLOUR_BLACK;
			}
			break;

		}
		
		case ADC_Channel_1:
		{
			for(count=0;count<=4;count++)
			{
				ADC_Buf[count] =  Get_ADC_Value(ADC_Channel_1);
//				DelayMs(5);
			}
			
			ADC_SUM = ADC_Buf[0]+ADC_Buf[1]+ADC_Buf[2]+ADC_Buf[3]+ADC_Buf[4];
			Tracer_ADC_Raw[SECTION_MIDDLE]=ADC_SUM/5;
//			Tracer_ADC_Raw[SECTION_MIDDLE] = (Tracer_ADC_Raw[SECTION_MIDDLE]*5/4096);
//			Tracer_ADC_Raw[SECTION_MIDDLE] = (Tracer_ADC_Raw[SECTION_MIDDLE]*255/5);
			
			if(Tracer_ADC_Raw[SECTION_MIDDLE] >= Tracer_Upper_Threshold)
			{
				Tracer_Stat[SECTION_MIDDLE] = COLOUR_WHITE;
			}
			else if(Tracer_ADC_Raw[SECTION_MIDDLE] > Tracer_Lower_Threshold && Tracer_ADC_Raw[SECTION_MIDDLE] < Tracer_Upper_Threshold)
			{
				Tracer_Stat[SECTION_MIDDLE] = COLOUR_GRAY;
			}
			else
			{
				Tracer_Stat[SECTION_MIDDLE] = COLOUR_BLACK;
			}
			break;		
		}
		
		case ADC_Channel_2:
		{
			for(count=0;count<=4;count++)
			{
				ADC_Buf[count] =  Get_ADC_Value(ADC_Channel_2);
//				DelayMs(5);
			}
			
			ADC_SUM = ADC_Buf[0]+ADC_Buf[1]+ADC_Buf[2]+ADC_Buf[3]+ADC_Buf[4];
			Tracer_ADC_Raw[SECTION_FRONT]=ADC_SUM/5;
//			Tracer_ADC_Raw[SECTION_BACK] = (Tracer_ADC_Raw[SECTION_FRONT]*5/4096);
//			Tracer_ADC_Raw[SECTION_BACK] = (Tracer_ADC_Raw[SECTION_FRONT]*255/5);
			
			if(Tracer_ADC_Raw[SECTION_FRONT] >= Tracer_Upper_Threshold)
			{
				Tracer_Stat[SECTION_FRONT] = COLOUR_WHITE;
			}
			else if((Tracer_ADC_Raw[SECTION_FRONT] > Tracer_Lower_Threshold) && (Tracer_ADC_Raw[SECTION_FRONT] < Tracer_Upper_Threshold))
			{
				Tracer_Stat[SECTION_FRONT] = COLOUR_GRAY;
			}
			else
			{
				Tracer_Stat[SECTION_FRONT] = COLOUR_BLACK;
			}
			break;	
		}
		
	}
	
}
 
void Tracer_Get_Colour()
{
	if(Tracer_Stat[SECTION_FRONT] == COLOUR_WHITE || Tracer_Stat[SECTION_MIDDLE] == COLOUR_WHITE || Tracer_Stat[SECTION_BACK] == COLOUR_WHITE)
	{
		Tracer_Stat[FINAL] = COLOUR_WHITE;
	}
	else if(Tracer_Stat[SECTION_FRONT] == COLOUR_GRAY || Tracer_Stat[SECTION_MIDDLE] == COLOUR_GRAY || Tracer_Stat[SECTION_BACK] == COLOUR_GRAY)
	{
		Tracer_Stat[FINAL] = COLOUR_GRAY;
	}

	else
	{
		Tracer_Stat[FINAL] = COLOUR_BLACK;
	}
}

void Tracer_Get_Rule()
{
	Tracer_Get_Value(ADC_Channel_2);
	Tracer_Get_Value(ADC_Channel_1);
	Tracer_Get_Value(ADC_Channel_0);
	Tracer_Get_Colour();
}



void USART2_IRQHandler(void)
{
  if(USART_GetITStatus(USART2, USART_IT_RXNE))//enter interrupt when STM32 receive data.
  {
 	SLAVE_COMMAND[0] = USART2 -> DR;
	if(SLAVE_COMMAND[0] == CMD_IDLE)
 	{
 		SLAVE_COMMAND[1] = SLAVE_COMMAND[0];
 		SLAVE_COMMAND[0] = SLAVE_COMMAND[2];
 	}
	switch(SLAVE_COMMAND[0])
	{
	case TRACER_CMD_SEND_RAW:
	{

		unsigned int Tracer_front_H;
		unsigned int Tracer_front_L;

		unsigned int Tracer_back_H;
		unsigned int Tracer_back_L;


		Tracer_front_H = TCS_DATA[SECTION_FRONT] >> 8;
		Tracer_front_L = TCS_DATA[SECTION_FRONT] & 0xFF;

		Tracer_back_H = TCS_DATA[SECTION_BACK] >> 8;
		Tracer_back_L = TCS_DATA[SECTION_BACK] & 0xFF;

		USART_Send(USART2,COMMAND_FLAG_A);
		USART_Send(USART2,COMMAND_FLAG_B);
		USART_Send(USART2,RAW_VAL_FLAG);
		USART_Send(USART2,Tracer_front_H);
		USART_Send(USART2,Tracer_front_L);
		USART_Send(USART2,Tracer_back_H);
		USART_Send(USART2,Tracer_back_L);
		USART_Send(USART2,Tracer_Stat[FINAL]);

	}break;

	case TRACER_CMD_SEND_RGB:
	{
		Tracer_front_R_H = TCS_F.RedData >> 8;
		Tracer_front_R_L = TCS_F.RedData & 0xFF;

		Tracer_front_G_H = TCS_F.GreenData >> 8;
		Tracer_front_G_L = TCS_F.GreenData & 0xFF;

		Tracer_front_B_H = TCS_F.BlueData >> 8;
		Tracer_front_B_L = TCS_F.BlueData & 0xFF;

		Tracer_back_R_H = TCS_B.RedData >> 8;
		Tracer_back_R_L = TCS_B.RedData & 0xFF;

		Tracer_back_G_H = TCS_B.GreenData >> 8;
		Tracer_back_G_L = TCS_B.GreenData & 0xFF;

		Tracer_back_B_H = TCS_B.BlueData >> 8;
		Tracer_back_B_L = TCS_B.BlueData & 0xFF;

		USART_Send(USART2,COMMAND_FLAG_A);
		USART_Send(USART2,COMMAND_FLAG_B);
		USART_Send(USART2,RGB_VAL_FLAG);
		USART_Send(USART2,Tracer_front_R_H);
		USART_Send(USART2,Tracer_front_R_L);
		USART_Send(USART2,Tracer_front_G_H);
		USART_Send(USART2,Tracer_front_G_L);
		USART_Send(USART2,Tracer_front_B_H);
		USART_Send(USART2,Tracer_front_B_L);
		USART_Send(USART2,Tracer_back_R_H);
		USART_Send(USART2,Tracer_back_R_L);
		USART_Send(USART2,Tracer_back_G_H);
		USART_Send(USART2,Tracer_back_G_L);
		USART_Send(USART2,Tracer_back_B_H);
		USART_Send(USART2,Tracer_back_B_L);
		USART_Send(USART2,Tracer_Stat[FINAL]);

	}break;

	case CMD_GET_TRACER:
	{
		USART_Send(USART2,COMMAND_FLAG_A);
		USART_Send(USART2,COMMAND_FLAG_B);
		USART_Send(USART2,STAT_DATA);
		USART_Send(USART2,Tracer_Stat[FINAL]);
	}break;

	case HYBRID_CMD_SEND_THRESHOLD:
	{
		unsigned int TH_UP_H;
		unsigned int TH_UP_L;
		unsigned int TH_LOWER_H;
		unsigned int TH_LOWER_L;
		unsigned int TH_RGB_FRONT_UP_H;
		unsigned int TH_RGB_FRONT_UP_L;
		unsigned int TH_RGB_FRONT_LOW_H;
		unsigned int TH_RGB_FRONT_LOW_L;
		unsigned int TH_RGB_BACK_UP_H;
		unsigned int TH_RGB_BACK_UP_L;
		unsigned int TH_RGB_BACK_LOW_H;
		unsigned int TH_RGB_BACK_LOW_L;


		TH_UP_H = Tracer_Upper_Threshold >> 8;
		TH_UP_L = Tracer_Upper_Threshold & 0xFF;

		TH_LOWER_H = Tracer_Lower_Threshold >> 8;
		TH_LOWER_L = Tracer_Lower_Threshold & 0xFF;

		TH_RGB_FRONT_UP_H = RGB_Threshold_front_up >> 8;
		TH_RGB_FRONT_UP_L = RGB_Threshold_front_up & 0xFF;

		TH_RGB_FRONT_LOW_H = RGB_Threshold_front_low >> 8;
		TH_RGB_FRONT_LOW_L = RGB_Threshold_front_low & 0xFF;

		TH_RGB_BACK_UP_H = RGB_Threshold_back_up >> 8;
		TH_RGB_BACK_UP_L = RGB_Threshold_back_up & 0xFF;

		TH_RGB_BACK_LOW_H = RGB_Threshold_back_low >> 8;
		TH_RGB_BACK_LOW_L = RGB_Threshold_back_low & 0xFF;

		USART_Send(USART2,COMMAND_FLAG_A);
		USART_Send(USART2,COMMAND_FLAG_B);
		USART_Send(USART2,TH_DATA);
		USART_Send(USART2,TH_UP_H);
		USART_Send(USART2,TH_UP_L);
		USART_Send(USART2,TH_LOWER_H);
		USART_Send(USART2,TH_LOWER_L);
		USART_Send(USART2,TH_RGB_FRONT_UP_H);
		USART_Send(USART2,TH_RGB_FRONT_UP_L);
		USART_Send(USART2,TH_RGB_FRONT_LOW_H);
		USART_Send(USART2,TH_RGB_FRONT_LOW_L);
		USART_Send(USART2,TH_RGB_BACK_UP_H);
		USART_Send(USART2,TH_RGB_BACK_UP_L);
		USART_Send(USART2,TH_RGB_BACK_LOW_H);
		USART_Send(USART2,TH_RGB_BACK_LOW_L);
	}break;
	}

  }

}
