/*==============================================================================================
								  PROJECT BW 2.16 Ver.1.0
								  BW ARTICULATED MANIPULATOR
==============================================================================================*/

#include "bw_articulated_manipulator.h"


/* func      : void BW_Manipulator_Initialization(void)
 * brief     : Articulated manipulator (arm robot) initialization
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, January 21st 2016)
 * Revised BY: N/A
 * programmer's Note: This function must be called in the BW_Initialization() function
 *
 */
void BW_Manipulator_Initialization(void)
{
	Manipulator_Servo_Init();
	Manipulator_Interrupt_Init();
	Manipulator_TIM_Init();
}

/* func      : void Manipulator_Servo_Init(void)
 * brief     : Articulated manipulator servo GPIO initialization
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, January 21st 2016)
 * Revised BY: N/A
 * programmer's Note: This function must be called in the BW_Manipulator_Initialization() function.
 *
 */
void Manipulator_Servo_Init(void)
{
	//SHOULDER SERVO GPIO INIT
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_SHOULDER, ENABLE);

	GPIO_InitStructure.GPIO_Pin = SHOULDER_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(SHOULDER_PORT, &GPIO_InitStructure);

	//ELBOW SERVO GPIO INIT
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_ELBOW, ENABLE);

	GPIO_InitStructure.GPIO_Pin = ELBOW_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(ELBOW_PORT, &GPIO_InitStructure);

	//GRIPPER SERVO GPIO INIT
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GRIPPER, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GRIPPER_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GRIPPER_PORT, &GPIO_InitStructure);
}



/* func      : void Manipulator_TIM_Init(void)
 * brief     : Articulated manipulator timer configuration
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, January 21st 2016)
 * Revised BY: N/A
 * programmer's Note: This function must be called in the BW_Manipulator_Initialization() function.
 *
 */
void Manipulator_TIM_Init(void)
{
	 //PrescalerValue = (uint32_t) ((SystemCoreClock / 2) / 9830250) - 1;

	 /* Time base configuration */
	 TIM_TimeBaseStructure.TIM_Period = MANIPULATOR_TIM_PERIOD;//65535;//10000;//65535; /*nilai mak utk timer=16bit*/
	 TIM_TimeBaseStructure.TIM_Prescaler = MANIPULATOR_TIM_PRESCALER;//21;
	 TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	 TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	 TIM_TimeBaseInit(MANIPULATOR_TIMER, &TIM_TimeBaseStructure);

	 /* Prescaler configuration */
	 //TIM_PrescalerConfig(TIM3, PrescalerValue, TIM_PSCReloadMode_Immediate);
}

/* func      : void Manipulator_Interrupt_Init(void)
 * brief     : Articulated manipulator SOFT PWM interrupt scheduling
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, January 21st 2016)
 * Revised BY: N/A
 * programmer's Note: This function must be called in the BW_Manipulator_Initialization() function.
 *
 */
//void Manipulator_Interrupt_Init(void)
//{
//	 NVIC_InitTypeDef NVIC_InitStructure;
//
//	 /* TIM3 clock enable */
//	 RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
//	 /* Enable the TIM3 gloabal Interrupt */
//	 NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
//	 NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//	 NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
//	 NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	 NVIC_Init(&NVIC_InitStructure);
//
//	 /* Output Compare Timing Mode configuration: Channel1 */
//	 TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Timing;
//	 TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//	 TIM_OCInitStructure.TIM_Pulse = ARM_CCR1_Val;
//	 TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
//	 TIM_OC1Init(TIM2, &TIM_OCInitStructure);
//
//	 TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Disable);
//
//	 TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//	 TIM_OCInitStructure.TIM_Pulse = ARM_CCR2_Val;
//	 TIM_OC2Init(TIM2, &TIM_OCInitStructure);
//
//	 TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Disable);
//
//	 TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//	 TIM_OCInitStructure.TIM_Pulse = ARM_CCR2_Val;
//	 TIM_OC3Init(TIM2, &TIM_OCInitStructure);
//
//	 TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Disable);
//
//	 //TIM_ClearOC1Ref(TIM3, TIM_OCClear_Enable);
//	 //TIM_ClearOC2Ref(TIM3, TIM_OCClear_Enable);
//	 //TIM_ForcedOC1Config(TIM3, TIM_ForcedAction_Active);
//	 /* TIM Interrupts enable */
//	 TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
//	 TIM_ITConfig(TIM2, TIM_IT_CC1, ENABLE);
//	 TIM_ITConfig(TIM2, TIM_IT_CC2, ENABLE);
//	 TIM_ITConfig(TIM2, TIM_IT_CC3, ENABLE);
//
//	 /* TIM3 enable counter */
//	 TIM_Cmd(TIM2, ENABLE);
//}
//
//
//
//void TIM2_IRQHandler(void)
//{
//
//	 if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
//	 {
//		 if(++arm_counter>=2) {arm_counter=0;}
//
//		 TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
//
//		 switch (arm_counter)
//		 {
//
//		 	 	 case 0:
//		 		        GPIO_SetBits(ARM_CHANNEL_0);
//		 		 	    break;
//		 		 case 1:
//		 	 	    	GPIO_SetBits(ARM_CHANNEL_1);
//		 	 	    	break;
//		 		 case 2:
//		 	 	    	GPIO_SetBits(ARM_CHANNEL_2);
//		 	 	    	break;
//		 }
//		 if(arm_counter>2)         {arm_counter=0;}
////		 else if(arm_counter<=5)   {index_bantu=index_servo;}
////
////		 TIM2 -> CCR1=sudut[index_bantu];
////		 TIM2 -> CCR2=sudut[index_bantu+6];
////		 TIM2 -> CCR3=sudut[index_bantu+12];
//
//		 TIM2 -> CCR1= Arm_Angle[0];
//		 TIM2 -> CCR2= Arm_Angle[1];
//		 TIM2 -> CCR3= Arm_Angle[2];
//		 //index_servo++;
//		 //if(index_servo>=5) {index_servo=0;}
//	  }
//
//	else if (TIM_GetITStatus(TIM2, TIM_IT_CC1) == SET)
//	{
//		TIM_ClearITPendingBit(TIM2, TIM_IT_CC1);
//
//		GPIO_ResetBits(ARM_CHANNEL_0);
//
//	}
//	else if (TIM_GetITStatus(TIM2, TIM_IT_CC2) == SET)
//	{
//		TIM_ClearITPendingBit(TIM2, TIM_IT_CC2);
//
//		GPIO_ResetBits(ARM_CHANNEL_1);
//	}
//
//	else if (TIM_GetITStatus(TIM2, TIM_IT_CC3) == SET)
//	{
//		TIM_ClearITPendingBit(TIM2, TIM_IT_CC3);
//
//		GPIO_ResetBits(ARM_CHANNEL_2);
//	}
//}


void Move_ARM(int CHANNEL,float VALUE)
{
	Arm_Angle[CHANNEL]= (long int) VALUE + Arm_Correction[CHANNEL];
//	sudut[ch_num] =(long int)((A_const[ch_num]*(value+correct[ch_num]))+ B_const[ch_num]);
	//sudut[ch_num] = ((A_const[ch_num]*value)+B_const[ch_num]);
}
