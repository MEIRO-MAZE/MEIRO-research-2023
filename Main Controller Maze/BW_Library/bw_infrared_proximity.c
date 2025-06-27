/*==============================================================================================
								 	 PROJECT BW Ver.1.0
								 BW INFRARED PROXIMITY LIBRARY
==============================================================================================*/

#include <bw_infrared_proximity.h>

/*
 * Func  : void IR_Proximity_Init(void)
 * Brief : Infrared Switch Sensor GPIO Initialization
 * Param : N/A
 * Written By: Ryan (MISSING NOTE)
 * Revised By: Ryan (Wednesday, February 24th 2016)
 * Ver   : 2 * Programmer's Note: Configured for the new BW 2016 pin mapping
 */
void IR_Proximity_Init(void)
{
//	//Enable Port C Clock
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_IR_C, ENABLE);
//	//-----------------Pin ADC3 Channel1 pin as analog input--------
//	GPIO_InitStructure.GPIO_Pin   = IR_PIN_FRONT_LEFT  | IR_PIN_FRONT_RIGHT |
//									IR_PIN_MID_LEFT    | IR_PIN_MID_RIGHT   |
//									IR_PIN_BUMPER_LEFT | IR_PIN_BUMPER_RIGHT;
//	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; //kecepatan clock(2, 25, 50 or 100 MHz)
//	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
//	GPIO_Init(IR_PORT_C, &GPIO_InitStructure);
//
	//Enable Port B Clock
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_IR_B, ENABLE);
	GPIO_InitStructure.GPIO_Pin   = /*IR_PIN_BUMPER_LEFT*/ IR_PIN_BUMPER_LEFT ;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; //kecepatan clock(2, 25, 50 or 100 MHz)
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_Init(IR_PORT_B, &GPIO_InitStructure);

	//Enable Port A Clock
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_IR_A, ENABLE);
	GPIO_InitStructure.GPIO_Pin   = IR_PIN_BUMPER_RIGHT; //IR_PIN_FRONT_LEFT |  //FRONT LEFT
//									IR_PIN_FRONT_RIGHT; //FRONT RIGHT
//	GPIO_InitStructure.GPIO_Pin   = IR_PIN_FRONT_LEFT | IR_PIN_BUMPER_LEFT | //FRONT LEFT
//									IR_PIN_FRONT_RIGHT| IR_PIN_BUMPER_RIGHT; //FRONT RIGHT
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_Init(IR_PORT_A, &GPIO_InitStructure);

	//Enable Port E Clock
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_IR_E, ENABLE);
//	GPIO_InitStructure.GPIO_Pin   = IR_PIN_MID_RIGHT | IR_PIN_UPPER_RIGHT;
//	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
//	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
//	GPIO_Init(IR_PORT_E, &GPIO_InitStructure);

	//Enable Port C Clock
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_IR_C, ENABLE);
//	GPIO_InitStructure.GPIO_Pin   = IR_PIN_MID_LEFT | //MID LEFT
//									IR_PIN_FRONT_MIDDLE; //FRONT MIDDLE
//	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
//	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
//	GPIO_Init(IR_PORT_C, &GPIO_InitStructure);

	//Enable Port D Clock
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_IR_D, ENABLE);
//	GPIO_InitStructure.GPIO_Pin   = IR_PIN_BUMPER_RIGHT; //UPPER LEFT
//	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
//	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
//	GPIO_Init(IR_PORT_D, &GPIO_InitStructure);

}

/*
 * Func  : void Get_IR(void)
 * Brief : Get IR Sensor output
 * Param : N/A
 * Retval: N/A (IR Sensor output stored in INFRARED[0] ~ INFRARED[7]
 * Written By: Ryan (MISSING NOTE)
 * Revised By: Ryan (Wednesday, February 24th 2016)
 * Ver   : 2
 * Programmer's Note: Configured for the new BW 2016 pin mapping
 */
void Get_IR(void)
{
//	INFRARED[0]= INFRARED_FRONT_LEFT;
//	INFRARED[1]= INFRARED_FRONT_RIGHT;
//	INFRARED[2]= INFRARED_MID_LEFT;
//	INFRARED[3]= INFRARED_MID_RIGHT;
//	INFRARED[4]= INFRARED_FRONT_MIDDLE;
//	INFRARED[6]= INFRARED_BUMPER_LEFT;
//	INFRARED[7]= INFRARED_BUMPER_RIGHT;

	INFRARED[0]= INFRARED_FRONT_LEFT;
	INFRARED[1]= INFRARED_FRONT_RIGHT;
	INFRARED[2]= INFRARED_MID_LEFT;
	INFRARED[3]= INFRARED_MID_RIGHT;
	INFRARED[4]= INFRARED_UPPER_LEFT;
	INFRARED[5]= INFRARED_UPPER_RIGHT;
	INFRARED[6]= INFRARED_FRONT_MIDDLE;
	INFRARED[7]= INFRARED_BUMPER_LEFT;
	INFRARED[8]= INFRARED_BUMPER_RIGHT;

//	INFRARED[7]= INFRARED_BUMPER_RIGHT;
}

void Get_IR_Right(void)
{
	INFRARED[3]= INFRARED_MID_RIGHT;
}
void Get_IR_Left(void)
{
	INFRARED[2]= INFRARED_MID_LEFT;
}
void Display_IR_Stat(void)
{
	Get_IR();
	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"BW  IR MONITOR");lcd_putstr(lcd);
	lcd_gotoxy(0,1);sprintf(lcd,"F_L:%d",INFRARED[IR_FRONT_LEFT]);lcd_putstr(lcd);
	lcd_gotoxy(5,1);sprintf(lcd,"F_M:%d",INFRARED[IR_FRONT_MIDDLE]);lcd_putstr(lcd);
	lcd_gotoxy(11,1);sprintf(lcd,"F_R:%d",INFRARED[IR_FRONT_RIGHT]);lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"M_L: %d",INFRARED[IR_MID_LEFT]);lcd_putstr(lcd);
	lcd_gotoxy(10,2);sprintf(lcd,"M_R: %d",INFRARED[IR_MID_RIGHT]);lcd_putstr(lcd);
	lcd_gotoxy(0,3);sprintf(lcd,"U_L: %d",INFRARED[IR_UPPER_LEFT]);lcd_putstr(lcd);
	lcd_gotoxy(10,3);sprintf(lcd,"U_R: %d",INFRARED[IR_UPPER_RIGHT]);lcd_putstr(lcd);
//	lcd_gotoxy(0,1);sprintf(lcd," U_L: %d",INFRARED[IR_UPPER_LEFT]);lcd_putstr(lcd);
//	lcd_gotoxy(8,1);sprintf(lcd," U_R: %d",INFRARED[IR_UPPER_RIGHT]);lcd_putstr(lcd);
//	lcd_gotoxy(0,3);sprintf(lcd," B_L: %d",INFRARED[IR_BUMPER_LEFT]);lcd_putstr(lcd);
//	lcd_gotoxy(8,3);sprintf(lcd," B_R: %d",INFRARED[IR_BUMPER_RIGHT]);lcd_putstr(lcd);

	delay_ms(100);

//	lcd_gotoxy(0,2);sprintf(lcd," F_MID: %d",INFRARED[IR_FRONT_MIDDLE]);lcd_putstr(lcd);

}

/*
void IR_Interrupt_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	TIM_TimeBaseInitTypeDef    TIM_TimeBaseStructure;

	TIM_TimeBaseStructure.TIM_Prescaler = 335;  //f per count= 84000000/(335+1)=250000Hz = 0.004ms
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period = 5000; //0.004*5000=50ms jadi sampling adc setiap 20ms
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 1;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	TIM_Cmd(TIM3, ENABLE); //default di off dulu

	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);

    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

}

void TIM3_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
    	{
    		IR_Control();
    		//BW_RGB_Tracer_Encoder();
    		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
    	}
}
*/
