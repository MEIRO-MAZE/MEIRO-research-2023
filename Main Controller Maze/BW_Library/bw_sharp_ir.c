/*==============================================================================================
								  	  PROJECT BW 2.16 Ver.1.0
								  	 BW SHARP INFRARED DISTANCE SENSOR
==============================================================================================*/

#include "bw_sharp_ir.h"

void SHARP_IR_Init(void)
{
	//Enable Port C Clock
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

	//-----------------Pin ADC3 Channel1 pin as analog input--------
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
	//GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //gak perlu
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	/*Enable ADC3 clock*********************************************************/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3, ENABLE);

	/* ADC Common Init **********************************************************/
	ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div2;

	ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
	ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;
	ADC_CommonInit(&ADC_CommonInitStructure);

	/* ADC3 Init ****************************************************************/
	ADC_InitStructure.ADC_Resolution = ADC_Resolution_10b;
	ADC_InitStructure.ADC_ScanConvMode = ENABLE;
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
	ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T1_CC1;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_NbrOfConversion = 1;

	ADC_Init(ADC3, &ADC_InitStructure);

	/* Enable ADC3 */
	ADC_Cmd(ADC3, ENABLE);
	ADC_ContinuousModeCmd(ADC3, ENABLE);
	ADC_RegularChannelConfig(ADC3,ADC_Channel_13,1,ADC_SampleTime_3Cycles); //channel 13 = IN1= datasheet PA.1(ADC323,IN1)
}

void SHARP_IR_Sampling(void)
{
	float Sharp_Raw;

	ADC_SoftwareStartConv(ADC3);
	ADC_GetConversionValue(ADC3);
	Sharp_Raw= ADC_GetConversionValue(ADC3);

	Sendto_PC(USART1,"SHARP RAW: %d \r",(int)Sharp_Raw);

}
