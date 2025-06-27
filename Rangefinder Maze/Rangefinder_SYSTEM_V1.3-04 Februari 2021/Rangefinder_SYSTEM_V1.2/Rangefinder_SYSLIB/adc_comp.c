#include "adc_comp.h"

GPIO_InitTypeDef GPIO_InitStructure;
ADC_InitTypeDef	ADC_InitStructure;

int buffer_fl=0;
int buffer_up=0;
uint8_t sharp_data[10];

volatile uint16_t ADCBuffer[] = {0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA};

void ADC_Config_X(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	RCC_ADCCLKConfig(RCC_PCLK2_Div2);
	ADC_DeInit(ADC1);

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_InitStructure.GPIO_Pin = SHARP_FL_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;	// we work in continuous sampling mode
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_NbrOfChannel = 1;

	ADC_Init ( ADC1, &ADC_InitStructure);	//set config of ADC1

	// enable ADC

	ADC_RegularChannelConfig(ADC1,ADC_Channel_1, 1,ADC_SampleTime_28Cycles5); // define regular conversion config
	ADC_Cmd(ADC1,ENABLE);	//enable ADC1
//	ADC_TempSensorVrefintCmd(ENABLE);
	ADC_Calibration();
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
//	while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);
}

void ADC_Config_GPIOA(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AIN;
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;        // that's ADC1 (PA1 on STM32)
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    //clock for ADC (max 14MHz --> 72/6=12MHz)
    RCC_ADCCLKConfig (RCC_PCLK2_Div6);
    // enable ADC system clock
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
    ADC_StructInit(&ADC_InitStructure);

    // define ADC config
    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;  // we work in continuous sampling mode
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStructure.ADC_NbrOfChannel = 2;

    ADC_Init(ADC1,&ADC_InitStructure);

    // enable ADC
    ADC_Cmd (ADC1,ENABLE);  //enable ADC1
//
    //  ADC calibration (optional, but recommended at power on)
    ADC_ResetCalibration(ADC1); // Reset previous calibration
    while(ADC_GetResetCalibrationStatus(ADC1));
    ADC_StartCalibration(ADC1); // Start new calibration (ADC must be off at that time)
    while(ADC_GetCalibrationStatus(ADC1));

    // start conversion
    ADC_Cmd (ADC1,ENABLE);  //enable ADC1

}

void ADC_Config_GPIOB(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AIN;
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_0 | GPIO_Pin_1;        // that's ADC1 (PA1 on STM32)
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    //clock for ADC (max 14MHz --> 72/6=12MHz)
    RCC_ADCCLKConfig (RCC_PCLK2_Div6);
    // enable ADC system clock
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
    ADC_StructInit(&ADC_InitStructure);

    // define ADC config
    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;  // we work in continuous sampling mode
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStructure.ADC_NbrOfChannel = 2;

    ADC_Init(ADC1,&ADC_InitStructure);

    // enable ADC
    ADC_Cmd (ADC1,ENABLE);  //enable ADC1
//
    //  ADC calibration (optional, but recommended at power on)
    ADC_ResetCalibration(ADC1); // Reset previous calibration
    while(ADC_GetResetCalibrationStatus(ADC1));
    ADC_StartCalibration(ADC1); // Start new calibration (ADC must be off at that time)
    while(ADC_GetCalibrationStatus(ADC1));

    // start conversion
    ADC_Cmd (ADC1,ENABLE);  //enable ADC1
}


void ADCInit(void)
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1|RCC_APB2Periph_GPIOA, ENABLE);
  ADC_DeInit(ADC1);

  // RA1 - analog input
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
  GPIO_Init (GPIOA, &GPIO_InitStructure);

  // ADC Structure Initialization
  ADC_StructInit(&ADC_InitStructure);

  // Preinit
  ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
  ADC_InitStructure.ADC_ScanConvMode = DISABLE;
  ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
  ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
  ADC_InitStructure.ADC_NbrOfChannel = 1;
  ADC_Init(ADC1, &ADC_InitStructure);

  // Enable the ADC
  ADC_Cmd(ADC1, ENABLE);
}

uint16_t GetADCChanel(int8_t chanel)
{
  // Configure chanel
  ADC_RegularChannelConfig(ADC1, chanel, 1, ADC_SampleTime_28Cycles5);

  // Start the conversion
  ADC_SoftwareStartConvCmd(ADC1, ENABLE);

  // Wait until conversion completion
  while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);

  // Get the conversion value
  return ADC_GetConversionValue(ADC1);
}


void ADC_DMA_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	ADC_InitTypeDef ADC_InitStructure;
	DMA_InitTypeDef DMA_InitStructure;

	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
    /* Enable ADC1 and GPIOA and GPIOB clock */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 | RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1 , ENABLE );

	DMA_InitStructure.DMA_BufferSize = 3;
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)ADCBuffer;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&ADC1->DR;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;
	DMA_Init(DMA1_Channel1, &DMA_InitStructure);
	DMA_Cmd(DMA1_Channel1 , ENABLE ) ;

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_4 | GPIO_Pin_7; //7 kanan 4 kiri
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStructure.ADC_NbrOfChannel = 3;
	ADC_InitStructure.ADC_ScanConvMode = ENABLE;
	ADC_Init(ADC1, &ADC_InitStructure);

	ADC_RegularChannelConfig(ADC1, ADC_Channel_5, 1, ADC_SampleTime_28Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_4, 2, ADC_SampleTime_28Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_7, 3, ADC_SampleTime_28Cycles5);
//	ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_28Cycles5);
//	ADC_RegularChannelConfig(ADC1, ADC_Channel_8, 2, ADC_SampleTime_28Cycles5);
//	ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 3, ADC_SampleTime_28Cycles5);
//	ADC_RegularChannelConfig(ADC1, ADC_Channel_7, 4, ADC_SampleTime_28Cycles5);
//	ADC_RegularChannelConfig(ADC1, ADC_Channel_3, 6, ADC_SampleTime_28Cycles5);

	ADC_Cmd(ADC1 , ENABLE ) ;
	ADC_DMACmd(ADC1 , ENABLE ) ;
	ADC_ResetCalibration(ADC1);

	while(ADC_GetResetCalibrationStatus(ADC1));
	ADC_StartCalibration(ADC1);

	while(ADC_GetCalibrationStatus(ADC1));
	ADC_SoftwareStartConvCmd ( ADC1 , ENABLE ) ;
}

void ADC_Calibration(void)
{
	ADC_ResetCalibration(ADC1);	// Reset previous calibration
	while(ADC_GetResetCalibrationStatus(ADC1));
	ADC_StartCalibration(ADC1);	// Start new calibration (ADC must be off at that time)
	while(ADC_GetCalibrationStatus(ADC1));
}

uint16_t ADC1_Read(void)
{
	ADC_SoftwareStartConvCmd(ADC1,ENABLE);
	int adc_value = ADC_GetConversionValue(ADC1);
	return adc_value;
}

void BW_ADC_Init(void)
{
//	ADC_Config_GPIOA();
//	ADC_Config_GPIOB();

	ADC_DMA_init();
}

void Sharp_Distance_Calc(uint16_t val)
{

}

void SHARP_IR_read(int IR_PIN)
{
	uint16_t ADC_Val[30];
	float SHARP_Vo;
	float buffer;

	switch(IR_PIN)
	{
		case IR_FRONT :
		{
			ADC_Val[0] = ADCBuffer[0];
			buffer = ADC_Val[0];
			SHARP_Vo = (float)(buffer/4096)*5;
			buffer= (float)((1/((0.0413*SHARP_Vo)-0.0042)-0.42));
			sharp_data[IR_FRONT] = (uint8_t)buffer;
		}break;

		case IR_LEFT :
		{
			ADC_Val[1] = ADCBuffer[1];
			buffer = ADC_Val[1];
			SHARP_Vo = (float)(buffer/4096)*5;
			buffer= (float)((1/((0.0413*SHARP_Vo)-0.0042)-0.42));
			sharp_data[IR_LEFT] = (float)buffer;
//			USART_Send(USART1,(int)sharp_data);
		}break;

		case IR_RIGHT :
		{
			ADC_Val[2] = ADCBuffer[2];
			buffer = ADC_Val[2];
			SHARP_Vo = (float)(buffer/4096)*5;
			buffer= (float)((1/((0.0413*SHARP_Vo)-0.0042)-0.42));
			sharp_data[IR_RIGHT] = (float)buffer;
//			USART_Send(USART1,(int)sharp_data);
		}break;

//		case IR_ASKEW_RL :
//		{
//			ADC_Val[1] = ADCBuffer[1];
//			buffer = ADC_Val[1];
//			SHARP_Vo = (float)(buffer/4096)*5;
//			buffer= (float)((1/((0.0413*SHARP_Vo)-0.0042)-0.42));
//			sharp_data[IR_ASKEW_RL] = (uint8_t)buffer;
//			USART_Send(USART1,(int)sharp_data);
//		}break;

//		case IR_ASKEW_FR :
//		{
//			ADC_Val[2] = ADCBuffer[2];
//			buffer = ADC_Val[2];
//			SHARP_Vo = (float)(buffer/4096)*5;
//			buffer= (float)((1/((0.0413*SHARP_Vo)-0.0042)-0.42));
//			sharp_data[IR_ASKEW_FR] = (uint8_t)buffer;
////			USART_Send(USART1,(int)sharp_data);
//		}break;


		case IR_ASKEW_FL :
		{
			ADC_Val[4] = ADCBuffer[4];
			buffer = ADC_Val[4];
			SHARP_Vo = (float)(buffer/4096)*5;
			buffer= (float)((1/((0.0413*SHARP_Vo)-0.0042)-0.42));
			sharp_data[IR_ASKEW_FL] = (uint8_t)buffer;
//			USART_Send(USART1,(int)sharp_data);
		}break;

		case IR_STAIRS :
		{
			ADC_Val[5] = ADCBuffer[5];
			buffer = ADC_Val[5];
			SHARP_Vo = (float)(buffer/4096)*5;
			buffer= (float)((1/((0.0413*SHARP_Vo)-0.0042)-0.42));
			sharp_data[IR_FRONT] = (uint8_t)buffer;
//			USART_Send(USART1,(int)sharp_data);
		}break;

		case IR_ASKEW_RR :
		{
			ADC_Val[7] = ADCBuffer[3];
			buffer = ADC_Val[7];
			SHARP_Vo = (float)(buffer/4096)*5;
			buffer= (float)((1/((0.0413*SHARP_Vo)-0.0042)-0.42));
			sharp_data[IR_ASKEW_RR] = (uint8_t)buffer;
//			USART_Send(USART1,(int)sharp_data);
		}break;
	}

	if (sharp_data[IR_PIN] >= 75)
	{
		sharp_data[IR_PIN] = 75;
	}

	if (sharp_data[IR_PIN] <= 0)
	{
		sharp_data[IR_PIN] = 75;
	}
}

void SHARP_FL_read(void)
{
	uint16_t ADC_Val[30];
	float SHARP_Vo;
//	int i;
	float buffer;
/*	for(i = 0;i <= 4;i++)
	{
		ADC_Val[i] = GetADCChanel(ChannelSatu); //ADC_GetConversionValue(ADC1);
		DelayMs(5);
		buffer = buffer + ADC_Val[i];
	}*/
	ADC_Val[0] = GetADCChanel(ADC_Channel_0);
	buffer = ADC_Val[0];
	SHARP_Vo = (float)(buffer/4096)*5;
	buffer= (float)((1/((0.0413*SHARP_Vo)-0.0042)-0.42));
	data_sharp2 = (unsigned int)buffer;
//	USART_Send(USART1,(int)data_sharp2);
}

void SHARP_BUMPER_LEFT_Read(void)
{
	uint16_t ADC_Val[30];
	float SHARP_Vo;
//	int i;
	float buffer;
/*	for(i = 0;i <= 4;i++)
	{
		ADC_Val[i] = GetADCChanel(ChannelDua); //ADC_GetConversionValue(ADC1);
		DelayMs(5);
		buffer = buffer + ADC_Val[i];
	}*/
	ADC_Val[0] = GetADCChanel(ChannelDua);
	buffer = ADC_Val[0];
	SHARP_Vo = (float)(buffer/4096)*5;
	buffer = (int)((1/((0.0413*SHARP_Vo)-0.0042)-0.42));
	USART_Send(USART1, (int)buffer);
}

void SHARP_BUMPER_RIGHT_Read(void)
{
	uint16_t ADC_Val[30];
	float SHARP_Vo;
//	int i;
	float buffer;
/*	for(i = 0;i <= 4;i++)
	{
		ADC_Val[i] = GetADCChanel(ChannelNol); //ADC_GetConversionValue(ADC1);
		DelayMs(5);
		buffer = buffer + ADC_Val[i];
	}*/
	ADC_Val[0] = GetADCChanel(ChannelNol);
	buffer_fl = ADC_Val[0];
	SHARP_Vo = (float)(buffer_fl/4096)*5;
	buffer_fl = (float)((1/((0.0413*SHARP_Vo)-0.0042)-0.42));
	USART_Send(USART1, (int)buffer_fl);
}

void Stair_Read()
{
	uint16_t ADC_Val[30];
	float SHARP_Vo;
	float buf;
	//	int i;
	/*	for(i = 0;i <= 4;i++)
		{
			ADC_Val[i] = GetADCChanel(ChannelNol); //ADC_GetConversionValue(ADC1);
			DelayMs(5);
			buffer = buffer + ADC_Val[i];
		}*/
	ADC_Val[0] = GetADCChanel(ADC_Channel_3);
	buf = ADC_Val[0];
	SHARP_Vo = (float)(buf/4096)*5;
	buf = (float)((1/((0.0413*SHARP_Vo)-0.0042)-0.42));
	buffer_up = (float)buf;
	USART_Send(USART1,(int) buffer_up);
}
