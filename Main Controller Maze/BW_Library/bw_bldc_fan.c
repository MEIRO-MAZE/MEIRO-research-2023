
#include "bw_bldc_fan.h"

//#define BLDC_FAN TIM12->CCR1
#define BLDC_FAN TIM4->CCR1

//int PWM_servo;
//void TIM12_PWM_Config(void);
void TIM4_PWM_Init(void);

void button_init(void);

void BW_BLDC_Init(void)
{
//	TIM12_PWM_Config();
	TIM4_PWM_Init();


	//button_init();
	BLDC_FAN= 2000;
//	BLDC_FAN= 780;
//	delay_ms(8000);
}
/*
 * BRUSHLESS DC FAN ON PIN D12
 * Waktu kalibrasi seharusnya 2 secs, tapi realitanya harus di set 6 sec. (systick tidak akurat?) catatan: pakai delay 2secs di AVR bisa
 */
void BW_BLDC_Fight(void)
{
	BLDC_FAN = 4000;
	delay_ms(3000);
	BLDC_FAN= 2000;
}

void BW_Suppress_Fire(void)
{

}
/*
int main(void)
{
	int count;
	SystemInit();
	SysTick_Init();
	button_init();
	TIM12_PWM_Config();

	//PWM_servo=2000;
	//TIM12->CCR1 = 2000;
	//for (count=0;count<=50000000; count++) {PWM_servo = 2000;TIM12->CCR1 = 2000;}
	//PWM_servo = 2000;TIM12->CCR1 = 2000;
	PWM_servo = 2000;


	//for (count=0;count<=50000; count++) {PWM_servo = 4000;TIM12->CCR1 = 4000;}
	//TIM12->CCR1 = 2000;

	//delay_ms(1);

	//TIM12->CCR1 = 3000;
	//delay_ms(2000);
    while(1)
    {
    	if (GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==0)
		{
    		if (GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==1)
				{
    				delay_ms(2000);
    				BLDC_FAN = 4000;
    				delay_ms(750);
    				BLDC_FAN= 2000;

				}
		}
    	//if (ReadInputDataBit)
    	//PWM_servo = 3000;
    	//PWM_servo = 4000;

    	//TIM12->CCR1 = 3000;
    	//delay_ms(2000);
    }
}

*/

void TIM12_PWM_Config(void) //TIM 12
{

	// Clock enable
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);   // Clocking GPIOC (AHB1/APB1 = 42MHz)
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM12, ENABLE);   // Clocking TIM12  (APB1 = 42x2PLL=84MHz)

	// GPIO__TIM_init
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;           // PWM is an alternative function
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;      // GPIO_HIGH_Speed
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;          // Push-pull
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOB, &GPIO_InitStructure);                  // Initializing GPIOC structure
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource15, GPIO_AF_TIM12); // Routing TIM3 output to PC6

	// Timer init
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;      // => 0 = Not dividing
	TIM_TimeBaseStructure.TIM_CounterMode   = TIM_CounterMode_Up;// Upcounting configuration
	TIM_TimeBaseStructure.TIM_Period        = 39999;             // 39999=TCNT ==>pwm_freq=2000000/39999+1=50Hz
	TIM_TimeBaseStructure.TIM_Prescaler     = 41;            	 // Tim_tick => 84000000Hz/41+1=2000000Hz
	TIM_TimeBaseInit(TIM12, &TIM_TimeBaseStructure);             // Initializing Time Base structure

	TIM_Cmd(TIM12, ENABLE);                                      // Ready, Set, Go!

	// Channel 1, Ch.1 (PC6)
	TIM_OCInitStructure.TIM_OCMode      = TIM_OCMode_PWM2;       // PWM mode 1 = Set on compare match, PWM mode 2 = Clear on compare match pasangan OCPolarity_LOW
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;// Enabling the Output Compare state
	TIM_OCInitStructure.TIM_OCPolarity  = TIM_OCPolarity_Low;    // Regular polarity (low will inverse it)
	TIM_OCInitStructure.TIM_Pulse       = BLDC_FAN;             // Output Compare 1 reg value

	TIM_OC1Init(TIM12, &TIM_OCInitStructure);                    // Initializing Output Compare 1 structure
	TIM_OC1PreloadConfig(TIM12, TIM_OCPreload_Enable);           // Enable Ch.1 Output Compare preload

	 //TIM_ClearOC1Ref(TIM3, TIM_OCClear_Enable);
	 //TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
	 //TIM_ITConfig(TIM3, TIM_IT_CC1, ENABLE);
	//TIM_ARRPreloadConfig(TIM12, ENABLE);
	// Timer enable

}


void TIM4_PWM_Init(void)
{
	// Clock enable
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);   // Clocking GPIOC (AHB1/APB1 = 42MHz)
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);   // Clocking TIM12  (APB1 = 42x2PLL=84MHz)

	// GPIO__TIM_init
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;           // PWM is an alternative function
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;      // GPIO_HIGH_Speed
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;          // Push-pull
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL ;
	GPIO_Init(GPIOD, &GPIO_InitStructure);                  // Initializing GPIOC structure
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_TIM4); // Routing TIM3 output to PC6

	// Timer init
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;      // => 0 = Not dividing
	TIM_TimeBaseStructure.TIM_CounterMode   = TIM_CounterMode_Up;// Upcounting configuration
	TIM_TimeBaseStructure.TIM_Period        = 39999;             // 39999=TCNT ==>pwm_freq=2000000/39999+1=50Hz
	TIM_TimeBaseStructure.TIM_Prescaler     = 41;            	 // Tim_tick => 84000000Hz/41+1=2000000Hz
//	TIM_TimeBaseStructure.TIM_Period        = 19999;             // 39999=TCNT ==>pwm_freq=2000000/39999+1=50Hz
//	TIM_TimeBaseStructure.TIM_Prescaler     = 83;            	 // Tim_tick => 84000000Hz/41+1=2000000Hz
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);             // Initializing Time Base structure

	TIM_Cmd(TIM4, ENABLE);                                      // Ready, Set, Go!

	// Channel 1, Ch.1 (PC6)
	TIM_OCInitStructure.TIM_OCMode      = TIM_OCMode_PWM2;       // PWM mode 1 = Set on compare match, PWM mode 2 = Clear on compare match pasangan OCPolarity_LOW
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;// Enabling the Output Compare state
	TIM_OCInitStructure.TIM_OCPolarity  = TIM_OCPolarity_Low;    // Regular polarity (low will inverse it)
	TIM_OCInitStructure.TIM_Pulse       = BLDC_FAN;             // Output Compare 1 reg value

	TIM_OC1Init(TIM4, &TIM_OCInitStructure);                    // Initializing Output Compare 1 structure
	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);           // Enable Ch.1 Output Compare preload

	 //TIM_ClearOC1Ref(TIM3, TIM_OCClear_Enable);
	 //TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
	 //TIM_ITConfig(TIM3, TIM_IT_CC1, ENABLE);
	//TIM_ARRPreloadConfig(TIM12, ENABLE);
	// Timer enable
}
void button_init(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	  GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_0;
	  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	  GPIO_Init(GPIOA, &GPIO_InitStructure);

}
