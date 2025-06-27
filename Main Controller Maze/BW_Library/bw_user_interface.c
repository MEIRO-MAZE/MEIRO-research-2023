/*==============================================================================================
								 	 PROJECT BW Ver.1.0
								  	 USER INTERFACE LIBRARY
==============================================================================================*/

#include "bw_user_interface.h"

int cntt = 0;
int taek = 0;
int MENU_VAR=0;

//BW START BUTTON
void Button_Init(void)
{
	StartButton_Init();
	UserButton_Init();
}

void StartButton_Init(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_BUTTON, ENABLE);
	GPIO_InitStructure.GPIO_Pin   = BUTTON_PIN;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; //kecepatan clock(2, 25, 50 or 100 MHz)
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;
	GPIO_Init(BUTTON_PORT, &GPIO_InitStructure);
}

/* func      : void UserButton_Init(void)
 * brief     : UserButton GPIO Init
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Sunday, February 22nd 2015)
 * Revised BY: N/A
 */
void UserButton_Init(void)
{
	/*
	 * USERBUTTON A
	 */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_USERBUTTON_A, ENABLE);
	GPIO_InitStructure.GPIO_Pin   = USERBUTTON_A_PIN;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; //kecepatan clock(2, 25, 50 or 100 MHz)
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;
	GPIO_Init(USERBUTTON_A_PORT, &GPIO_InitStructure);

	/*
	 * USERBUTTON B
	 */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_USERBUTTON_B, ENABLE);
	GPIO_InitStructure.GPIO_Pin   = USERBUTTON_B_PIN;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; //kecepatan clock(2, 25, 50 or 100 MHz)
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;
	GPIO_Init(USERBUTTON_B_PORT, &GPIO_InitStructure);
}

void BW_Buzz(int counter)
{

}

void FIRE_LED_Init(void)
{
	RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_FIRE_LED, ENABLE);
	GPIO_InitStructure.GPIO_Pin 	= FIRE_LED_PIN;
	GPIO_InitStructure.GPIO_Mode 	= GPIO_Mode_OUT;       // Pin ini memiliki Mode Ouput
	GPIO_InitStructure.GPIO_OType 	= GPIO_OType_PP; 		// Pin bersifat Push Pull (Pull-up, down or no Pull)
	GPIO_InitStructure.GPIO_Speed 	= GPIO_Speed_100MHz; 	// kecepatan clock(2, 25, 50 or 100 MHz)
	GPIO_InitStructure.GPIO_PuPd 	= GPIO_PuPd_NOPULL; 	// pin tidak diberikan pull up
	GPIO_Init(FIRE_LED_PORT, &GPIO_InitStructure); 		// inisialisasi periperal GPIO sesuai parameter typdef diatas
}

void TCS_GRIPPER_LED_Init(void)
{
	RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_GRIPPER_LED, ENABLE);
	GPIO_InitStructure.GPIO_Pin 	= GRIPPER_LED_PIN;
	GPIO_InitStructure.GPIO_Mode 	= GPIO_Mode_OUT;       // Pin ini memiliki Mode Ouput
	GPIO_InitStructure.GPIO_OType 	= GPIO_OType_PP; 		// Pin bersifat Push Pull (Pull-up, down or no Pull)
	GPIO_InitStructure.GPIO_Speed 	= GPIO_Speed_100MHz; 	// kecepatan clock(2, 25, 50 or 100 MHz)
	GPIO_InitStructure.GPIO_PuPd 	= GPIO_PuPd_NOPULL; 	// pin tidak diberikan pull up
	GPIO_Init(GRIPPER_LED_PORT, &GPIO_InitStructure); 		// inisialisasi periperal GPIO sesuai parameter typdef diatas
}

/* func      : void SND_ACT_LED_Init(void)
 * brief     : Sound Activation LED Indicator GPIO Initialization
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Wednesday, February 24th 2016
 * Programmer's Note:
 */
void SND_ACT_LED_Init(void)
{
	RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_SND_ACT_LED, ENABLE);
	GPIO_InitStructure.GPIO_Pin 	= SND_ACT_LED_PIN ;
	GPIO_InitStructure.GPIO_Mode 	= GPIO_Mode_OUT;       	// Pin ini memiliki Mode Ouput
	GPIO_InitStructure.GPIO_OType 	= GPIO_OType_PP; 		// Pin bersifat Push Pull (Pull-up, down or no Pull)
	GPIO_InitStructure.GPIO_Speed 	= GPIO_Speed_100MHz; 	// kecepatan clock(2, 25, 50 or 100 MHz)
	GPIO_InitStructure.GPIO_PuPd 	= GPIO_PuPd_NOPULL; 	// pin tidak diberikan pull up
	GPIO_Init(SND_ACT_LED_PORT, &GPIO_InitStructure); 		// inisialisasi periperal GPIO sesuai parameter typdef diatas
}


/* func      : void BW_LED_Interrupt_Init(void)
 * brief     : FIRE LED Indicator Timer Interrupt Initialization
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (MISSING NOTE)
 * Programmer's Note: LED Blinking effect Initialization using timer 5
 */
void BW_LED_Interrupt_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

	TIM_TimeBaseStructure.TIM_Prescaler = 8399; //f per count= 84.000.000/(8399+1)=10.000Hz = 0,1ms (0,001 s)
	//335;  //f per count= 84000000/(335+1)=250000Hz = 0.004ms
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period = 1000;// 0,1 ms x 1000 = 100 ms -> 1 s -> 1 Hz
//	TIM_TimeBaseStructure.TIM_Period = 500;// 0,1 ms x 500 = 50 ms -> 0,5 s -> 2 Hz
			//200; //0,1 X 200 = 20 ms -> 0,2 s -> 5 Hz
	//10000; //0,1ms x 10000 = 1 s
	//0.004*125000=500ms jadi sampling adc setiap 500ms //MAX 65535
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);
	TIM_Cmd(TIM5, ENABLE); //default di off dulu
//	TIM_ITConfig(TIM5, TIM_IT_Update, ENABLE);
	TIM_ITConfig(TIM5, TIM_IT_Update, DISABLE);

    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

/* func      : void TIM5_IRQHandler(void)
 * brief     : FIRE LED Indicator Timer Handler
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (MISSING NOTE)
 * Programmer's Note: LED Blinking effect Handler
 */
void TIM5_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM5, TIM_IT_Update) != RESET)
    {
    	if  (UV_Lock==0)
    	{
    		if(led_off_counter==0)
    		{
    			FIRE_LED_OFF;
    		}

    		else if(led_off_counter>=1)
    		{
            	if(led_counter==1)
                {
            		FIRE_LED_ON;
                	led_counter=2;
                }

                else if(led_counter==2)
                {
                	FIRE_LED_OFF;
                	led_counter=1;
                }

            	led_off_counter++;

        		if(led_off_counter>=4000)
        		{
        			FIRE_LED_OFF;
        			led_off_counter=0;
        			BW_LED_BLINK_OFF;
        		}
    		}
    	}

    	else if (UV_Lock==1)
    	{
    		led_off_counter=0;

        	if(led_counter==1)
            {
        		FIRE_LED_ON;
            	led_counter=2;
            }

            else if(led_counter==2)
            {
            	FIRE_LED_OFF;
            	led_counter=1;
            }
    	}

    	TIM_ClearITPendingBit(TIM5, TIM_IT_Update);
    }
}

void BW_Initial_Setup(int BW_MODE)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
	delay_ms(100);
}

void Led_Blink(void)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(2,2);sprintf(lcd,"BLINK LED TEST");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);

	FIRE_LED_ON;
	SND_ACT_LED_OFF;
	delay_ms(200);
	FIRE_LED_OFF;
	SND_ACT_LED_ON;
	delay_ms(200);
}

void Test_Mode_6(void)
{
	while (BW_BUTTON_UNCLICKED)
	{
		int buff = cntt;
		if(BW_BUTTON_CLICKED){break;}
		if(BUTTON_A_CLICKED)
		{
			while(BUTTON_A_CLICKED){}
			cntt--;
		}
		if(BUTTON_B_CLICKED)
		{
			while(BUTTON_B_CLICKED){}
			cntt++;
		}

		if(BW_BUTTON_CLICKED){break;}
		switch (cntt)
		{
			case 0 :
					{
						lcd_gotoxy(0,0);sprintf(lcd,"CURVE RIGHT");lcd_putstr(lcd);
					}break;

			case 1 :
					{
						lcd_gotoxy(0,0);sprintf(lcd,"CURVE LEFT");lcd_putstr(lcd);
					}break;

			case 2:
					{
						lcd_gotoxy(0,0);sprintf(lcd,"ROTASI KANAN");lcd_putstr(lcd);
					}break;

			case 3:
					{
						lcd_gotoxy(0,0);sprintf(lcd,"ROTASI KIRI");lcd_putstr(lcd);
					}break;

			case 4:
					{
						lcd_gotoxy(0,0);sprintf(lcd,"GESER KANAN");lcd_putstr(lcd);
					}break;

			case 5:
					{
						lcd_gotoxy(0,0);sprintf(lcd,"GESER KIRI");lcd_putstr(lcd);
					}break;

			case 6:
					{
						lcd_gotoxy(0,0);sprintf(lcd,"MAJU");lcd_putstr(lcd);
					}break;

			case 7:
					{
						lcd_gotoxy(0,0);sprintf(lcd,"MUNDUR");lcd_putstr(lcd);
					}break;

			case 8:
					{
						lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW COUNTER");lcd_putstr(lcd);
						lcd_gotoxy(0,1);sprintf(lcd,"KANAN");lcd_putstr(lcd);
					}break;

			case 9:
					{
						lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW COUNTER");lcd_putstr(lcd);
						lcd_gotoxy(0,1);sprintf(lcd,"KIRI");lcd_putstr(lcd);
					}break;

			case 10:
					{
						lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW TRACER");lcd_putstr(lcd);
						lcd_gotoxy(0,1);sprintf(lcd,"KANAN");lcd_putstr(lcd);
					}break;

			case 11:
					{
						lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW TRACER");lcd_putstr(lcd);
						lcd_gotoxy(0,1);sprintf(lcd,"KIRI");lcd_putstr(lcd);								}break;

			case 12:
					{
						lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW KARPET");lcd_putstr(lcd);
						lcd_gotoxy(0,1);sprintf(lcd,"KANAN");lcd_putstr(lcd);
						lcd_gotoxy(0,2);sprintf(lcd,"NORMAL");lcd_putstr(lcd);
					}break;

			case 13:
					{
						lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW KARPET");lcd_putstr(lcd);
						lcd_gotoxy(0,1);sprintf(lcd,"KIRI");lcd_putstr(lcd);
						lcd_gotoxy(0,2);sprintf(lcd,"NORMAL");lcd_putstr(lcd);
					}break;

			case 14:
					{
						lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW KARPET");lcd_putstr(lcd);
						lcd_gotoxy(0,1);sprintf(lcd,"KANAN");lcd_putstr(lcd);
						lcd_gotoxy(0,2);sprintf(lcd,"INVERSE");lcd_putstr(lcd);
					}break;

			case 15:
					{
						lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW KARPET");lcd_putstr(lcd);
						lcd_gotoxy(0,1);sprintf(lcd,"KIRI");lcd_putstr(lcd);
						lcd_gotoxy(0,2);sprintf(lcd,"INVERSE");lcd_putstr(lcd);
					}break;

			case 16:
					{
						lcd_gotoxy(0,0);sprintf(lcd,"FINDING STAIRS");lcd_putstr(lcd);
					}break;

			case 17:
					{
						lcd_gotoxy(0,0);sprintf(lcd,"BREAK STAIRS");lcd_putstr(lcd);
					}break;
		}

	if (cntt != buff){lcd_display_clear();}

	if (cntt > 17){ cntt = 0;}
	if (cntt < 0){ cntt = 17;}

	if(BW_BUTTON_CLICKED){break;}
	Dynamx_Mov_Static_Interpolate(LEVEL3,IKCALC_ENABLE);
	}

	delay_ms(200);

	while (BW_BUTTON_UNCLICKED)
	{
		if(BW_BUTTON_CLICKED){break;}
		switch (cntt)
		{
			case 0 :
					{
						if (taek == 0)
						{
							BW_PID_Init();
							taek = 63;
						}
						FOLLOW_CALC=KANAN;
						float oke = 0;

						Dynamx_MoveCurveRight_IK(LEVEL6,1,&oke);

					}break;

			case 1 :
					{
						if (taek == 0)
						{
							BW_PID_Init();
							taek = 63;
						}
						FOLLOW_CALC=KIRI;
						float eko = 0;

						Dynamx_MoveCurveLeft_IK(LEVEL6,1,&eko);

					}break;

			case 2:
					{
						Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
						if(BW_BUTTON_CLICKED){break;}

					}break;

			case 3:
					{
						Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
						if(BW_BUTTON_CLICKED){break;}
					}break;

			case 4:
					{
						Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);
						if(BW_BUTTON_CLICKED){break;}
					}break;

			case 5:
					{
						Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
						if(BW_BUTTON_CLICKED){break;}

					}break;

			case 6:
					{
						Dynamx_MovFwd4cm_Interpolate(8, LEVEL6, IKCALC_ENABLE);
						if(BW_BUTTON_CLICKED){break;}
					}break;

			case 7:
					{
						Dynamx_MovBwd_Interpolate(9, LEVEL6, IKCALC_ENABLE);
						if(BW_BUTTON_CLICKED){break;}

					}break;

			case 8:
					{
						if (taek == 0)
						{
							BW_PID_Init();
							taek = 63;
						}

						BW_FollowCounter_Right(1);
						if(BW_BUTTON_CLICKED){break;}
					}break;

			case 9:
					{
						if (taek == 0)
						{
							BW_PID_Init();
							taek = 63;
						}
						BW_FollowCounter_Left(1);
						if(BW_BUTTON_CLICKED){break;}

					}break;

			case 10:
					{
						if (taek == 0)
						{
							BW_PID_Init();
							taek = 63;
						}

						BW_FollowTracer_Right_Interpolate();
						if(BW_BUTTON_CLICKED){break;}
					}break;

			case 11:
					{
						if (taek == 0)
						{
							BW_PID_Init();
							taek = 63;
						}
						BW_FollowTracer_Left_Interpolate();
						if(BW_BUTTON_CLICKED){break;}

					}break;

			case 12:
					{
						BW_PID_Init_Room();
						BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,NORMAL);
						if(BW_BUTTON_CLICKED){break;}
					}break;

			case 13:
					{
						BW_PID_Init_Room();
						BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,NORMAL);
						if(BW_BUTTON_CLICKED){break;}

					}break;

			case 14:
					{
						BW_PID_Init_Room();
						BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);
						if(BW_BUTTON_CLICKED){break;}
					}break;

			case 15:
					{
						BW_PID_Init_Room();
						BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);
						if(BW_BUTTON_CLICKED){break;}

					}break;

			case 16 :
					{
						CLIMBING_INTERRUPT_FLAG = 1;
						while(1)
						{
							lcd_gotoxy(0,0);sprintf(lcd,"BW CLIMB STAIRS");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"IK STAIRS STATIC");lcd_putstr(lcd);
							lcd_gotoxy(1,3);sprintf(lcd,"CLICK TO START");lcd_putstr(lcd);
							if(BW_BUTTON_CLICKED){break;}
						}

						BW_Climbing_Stairs();
						CLIMBING_INTERRUPT_FLAG = 0;
					}break;
			case 17 :
					{
						lcd_display_clear();
						int BUFF = 0;
						CLIMBING_INTERRUPT_FLAG = 1;
						while(BUTTON_A_UNCLICKED)
						{
							lcd_gotoxy(0,0);sprintf(lcd,"MASUK WHILE");lcd_putstr(lcd);
							if (BW_CMPS11.PitchKF < -8 ){BUFF = 1;}
							if(BW_CMPS11.PitchKF == 0 && (SHARP[IR_STAIRS] > 15 && SHARP[IR_STAIRS] < 20) && BUFF == 1){break;}
						}

						lcd_display_clear();
						CLIMBING_INTERRUPT_FLAG = 0;
						lcd_gotoxy(0,0);sprintf(lcd,"KELUAR WHILE");lcd_putstr(lcd);
//						Dynamx_Mov_Static_Stairs(LEVEL3,0);
						while(1){};

					}break;
		}

		if(BW_BUTTON_CLICKED){break;}
	}

	delay_ms(200);
}
