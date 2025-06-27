#include "main.h"

void Servo_PWM_Config(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

    GPIO_InitStructure.GPIO_Pin     = SERVO_PWM_1_Pin | SERVO_PWM_2_Pin | SERVO_PWM_3_Pin | SERVO_PWM_4_Pin;
    GPIO_InitStructure.GPIO_Mode    = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed   = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_OType   = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd    = GPIO_PuPd_UP;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    GPIO_PinAFConfig(SERVO_PWM_1_Type, SERVO_PWM_1_PinSource, GPIO_AF_TIM4);
    GPIO_PinAFConfig(SERVO_PWM_2_Type, SERVO_PWM_2_PinSource, GPIO_AF_TIM4);
    GPIO_PinAFConfig(SERVO_PWM_3_Type, SERVO_PWM_3_PinSource, GPIO_AF_TIM4);
    GPIO_PinAFConfig(SERVO_PWM_4_Type, SERVO_PWM_4_PinSource, GPIO_AF_TIM4);

    /* Setup TIM / PWM values
         Servo Requirements:  (May be different for your servo)
            - 50Hz (== 20ms) PWM signal
            - 0.6 - 2.1 ms Duty Cycle

         1. Determine Required Timer_Freq.
                TIM_Period = (Timer_Freq. / PWM_Freq) - 1

                - We need a period of 20ms (or 20000탎) and our PWM_Freq = 50Hz (i.e. 1/20ms)
                - See NOTES, for why we use 탎
                TIM_Period = 20000 - 1 = 19999  (since its 0 offset)

                Timer_Freq = (TIM_Period + 1) * PWM_Freq.
                Timer_Freq = (19999 + 1) * 50
                Timer_Freq = 1000000 = 1MHz

         2. Determine Pre-Scaler
            APB1 clock frequency:
                - SYS_CLK/4 when prescaler == 1 (i.e. 168MHz / 4 = 42MHz)
                - SYS_CLK/2 when prescaler != 1 (i.e. 168MHz / 2 = 84MHz)

            Prescaler = APB1_Freq / Timer_Freq
            Prescaler = 84 MHz / 1 MHz
            Prescaler = 84

            For our example, we can prescale the TIM clock by 84, which gives us a Timer_Freq of 1MHz
                Timer_Freq = 84 MHz / 84 = 1 MHz
            So the TIMx_CNT register will increase by 1 000 000 ticks every second. When TIMx_CNT is increased by 1 that is 1 탎. So if we want a duty cycle of 1.5ms (1500 탎) then we can set our CCRx register to 1500.

         NOTES:
            - TIMx_CNT Register is 16 bits, i.e. we can count from 0 to (2^16)-1 = 65535
            - If the period, TIMx_ARR, is greater than the max TIMx_CNT value (65535), then we need to choose a larger prescaler value in order to slow down the count.
            - We use the 탎 for a more precise adjustment of the duty cycle

            Control the servo via PWM wave 50Hz. The angle (counterclockwise) is proportional to the duty of Logic High.
            Duration of Logic High (ms)				Angle
            		0.6		= 600					0
            		0.9		= 900					30
            		1.2		= 1200					60
            		1.5		= 1500					90
            		1.8		= 1800					120
            		2.1		= 2100					150

            				= 2400					180
            				= 2700
         */

    uint16_t PrescalerValue = (uint16_t) 84;

    // Time Base Configuration
    TIM_TimeBaseStructure.TIM_Period        = 19999;
    TIM_TimeBaseStructure.TIM_Prescaler     = PrescalerValue;
    TIM_TimeBaseStructure.TIM_ClockDivision = 0;
    TIM_TimeBaseStructure.TIM_CounterMode   = TIM_CounterMode_Up;

    TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

    // Common TIM Settings
    TIM_OCInitStructure.TIM_OCMode      = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse       = 0;
    TIM_OCInitStructure.TIM_OCPolarity  = TIM_OCPolarity_High;

    // Channel 1
    TIM_OC1Init(TIM4, &TIM_OCInitStructure);
    TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);

    // Channel 2
    TIM_OC2Init(TIM4, &TIM_OCInitStructure);
    TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);

    // Channel 3
    TIM_OC3Init(TIM4, &TIM_OCInitStructure);
    TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);

    // Channel 4
    TIM_OC4Init(TIM4, &TIM_OCInitStructure);
    TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);

    TIM_ARRPreloadConfig(TIM4, ENABLE);

    // Start timer
    TIM_Cmd(TIM4, ENABLE);
}

void Servo_PWM_Set_Angle(int SERVO, int Angle)
{
	switch (SERVO)
	{
		case SERVO_1:
		{
			TIM4->CCR1 = Angle;
		}break;
		case SERVO_2:
		{
			TIM4->CCR2 = Angle;
		}break;
		case SERVO_3:
		{
			TIM4->CCR3 = Angle;
		}break;
		case SERVO_4:
		{
			TIM4->CCR4 = Angle;
		}break;
	}
}

void CO2_Launcher_PWM_Servo(void)
{
	Servo_PWM_Set_Angle(SERVO_4,degree_90);
	delay_ms(100);
	Servo_PWM_Set_Angle(SERVO_4,degree_0);
	delay_ms(200);
	Servo_PWM_Set_Angle(SERVO_4,degree_90);
}

void Push_To_Burst(void)
{
	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"  PROJECT MAZE  ");lcd_putstr(lcd);
	lcd_gotoxy(0,1);sprintf(lcd,"    BRAWIJAYA   ");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"  PUSH TO BURST ");lcd_putstr(lcd);
	lcd_gotoxy(0,3);sprintf(lcd,"  DTE FT-UB 63  ");lcd_putstr(lcd);

	if(BW_BUTTON_CLICKED)
	{
		while(BW_BUTTON_CLICKED)
//		CO2_Launcher_PWM_Servo();
			Servo_PWM_Set_Angle(SERVO_4, degree_0);
	}
	else
	{
		while(BW_BUTTON_UNCLICKED)
			Servo_PWM_Set_Angle(SERVO_4, degree_90);
	}
}

void Gripper_PWM_Capit(void)
{
	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"  PROJECT MAZE  ");lcd_putstr(lcd);
	lcd_gotoxy(0,1);sprintf(lcd,"    BRAWIJAYA   ");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"   GRIP CAPIT   ");lcd_putstr(lcd);
	lcd_gotoxy(0,3);sprintf(lcd,"  DTE FT-UB 63  ");lcd_putstr(lcd);

	if(BW_BUTTON_CLICKED)
	{
		while(BW_BUTTON_CLICKED)
			Servo_PWM_Set_Angle(SERVO_4, degree_180);
	}
	else
	{
		while(BW_BUTTON_UNCLICKED)
			Servo_PWM_Set_Angle(SERVO_4, degree_60);
	}
}

void Gripper_PWM_Up(void)
{
	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"  PROJECT MAZE  ");lcd_putstr(lcd);
	lcd_gotoxy(0,1);sprintf(lcd,"    BRAWIJAYA   ");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"     GRIP UP    ");lcd_putstr(lcd);
	lcd_gotoxy(0,3);sprintf(lcd,"  DTE FT-UB 63  ");lcd_putstr(lcd);

	if(BW_BUTTON_CLICKED)
	{
		while(BW_BUTTON_CLICKED)
		{
			Servo_PWM_Set_Angle(SERVO_2, degree_0);
			Servo_PWM_Set_Angle(SERVO_3, degree_180);
		}
	}
	else
	{
		while(BW_BUTTON_UNCLICKED)
		{
			Servo_PWM_Set_Angle(SERVO_2, degree_90);
			Servo_PWM_Set_Angle(SERVO_3, degree_90);
		}
	}
}

void Gripper_PWM_Down(void)
{
	int pos = 0;
	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"  PROJECT MAZE  ");lcd_putstr(lcd);
	lcd_gotoxy(0,1);sprintf(lcd,"    BRAWIJAYA   ");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"    GRIP DOWN   ");lcd_putstr(lcd);
	lcd_gotoxy(0,3);sprintf(lcd,"  DTE FT-UB 63  ");lcd_putstr(lcd);

	if(BW_BUTTON_CLICKED)
	{
		while(BW_BUTTON_CLICKED)
		{
			for(pos=0;pos<=180;pos++)
			{
				Servo_PWM_Set_Angle(SERVO_2, (degree_90+(pos*5)));
				Servo_PWM_Set_Angle(SERVO_3, (degree_90-(pos*5)));
				delay_ms(10);
			}
		}
	}
	else
	{
		while(BW_BUTTON_UNCLICKED)
		{
			for(pos=0;pos<=180;pos++)
			{
				Servo_PWM_Set_Angle(SERVO_2, (degree_180-(pos*5)));
				Servo_PWM_Set_Angle(SERVO_3, (degree_0+(pos*5)));
				delay_ms(10);
			}
		}
	}
}

void Gripper_PWM_Trial_Button(void)
{
	int counter = 0;
	int pos = 0;
	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"  PROJECT MAZE  ");lcd_putstr(lcd);
	lcd_gotoxy(0,1);sprintf(lcd,"    BRAWIJAYA   ");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"  GRIPPER TRIAL ");lcd_putstr(lcd);
	lcd_gotoxy(0,3);sprintf(lcd,"  DTE FT-UB 63  ");lcd_putstr(lcd);

	if(BW_BUTTON_CLICKED){counter=1;}
	if(counter==1)
	{
		for(pos=0;pos<=180;pos++)
		{
			Servo_PWM_Set_Angle(SERVO_2, (degree_0+(pos*5)));
			Servo_PWM_Set_Angle(SERVO_3, (degree_180-(pos*5)));
			delay_us(1000);
		}
		for(pos=0;pos<=120;pos++)
		{
			Servo_PWM_Set_Angle(SERVO_2, (degree_90+(pos*5)));
			Servo_PWM_Set_Angle(SERVO_3, (degree_90-(pos*5)));
			delay_us(1000);
		}
		GRIPPER_LED_ON;
		delay_ms(1000);
		Gripper_Open_K1();
		while(1)
		{
			if(BW_BUTTON_UNCLICKED)
			{
				Display_RGB_Data(TRACER_GRIPPER);
			}
			if(BW_BUTTON_CLICKED)break;
		}

		delay_ms(500);
		Gripper_Close_K1();
		delay_ms(500);
		for(pos=0;pos<=120;pos++)
		{
			Servo_PWM_Set_Angle(SERVO_2, (2100-(pos*5)));
			Servo_PWM_Set_Angle(SERVO_3, (900+(pos*5)));
			delay_us(2000);
		}
		for(pos=0;pos<=180;pos++)
		{
			Servo_PWM_Set_Angle(SERVO_2, (degree_90-(pos*5)));
			Servo_PWM_Set_Angle(SERVO_3, (degree_90+(pos*5)));
			delay_us(2000);
		}

		counter=0;
	}

}

void Gripper_Down_K1(void)
{
	Servo_PWM_Set_Angle(SERVO_2, 1950);
	Servo_PWM_Set_Angle(SERVO_3, 1050);
}

void Gripper_Up_K1(void)
{
	Servo_PWM_Set_Angle(SERVO_2, degree_0);
	Servo_PWM_Set_Angle(SERVO_3, degree_180);

}

void Gripper_Open_K1(void)
{
	Servo_PWM_Set_Angle(SERVO_4, degree_90);
}

void Gripper_Open_K3(void)
{
	Servo_PWM_Set_Angle(SERVO_4, 2250);
}

void Gripper_Close_K1(void)
{
	Servo_PWM_Set_Angle(SERVO_4, 2050);
}

void Gripper_Up_Calibration(void)
{
	while(1)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"  PROJECT MAZE  ");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"    BRAWIJAYA   ");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"GRIP  UP  CLBRTN");lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"  DTE FT-UB 63  ");lcd_putstr(lcd);
		if(BW_BUTTON_CLICKED)break;
	}
	int pos=0;
	for(pos=0;pos<=180;pos++)
	{
		Servo_PWM_Set_Angle(SERVO_2, (degree_180-(pos*5)));
		Servo_PWM_Set_Angle(SERVO_3, (degree_0+(pos*5)));
		delay_us(2000);
		while((pos==30)||(pos==60)||(pos==90)||(pos==120)||(pos==150)||(pos==180))
		{
			int servo2 = degree_180-(pos*5);
			int servo3 = degree_0+(pos*5);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"Servo2: %d",servo2);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"Servo3: %d",servo3);lcd_putstr(lcd);
			if(BW_BUTTON_CLICKED)break;
		}
	}
	for(pos=0;pos<=180;pos++)
	{
		Servo_PWM_Set_Angle(SERVO_2, (degree_90-(pos*5)));
		Servo_PWM_Set_Angle(SERVO_3, (degree_90+(pos*5)));
		delay_us(2000);
		while((pos==30)||(pos==60)||(pos==90)||(pos==120)||(pos==150)||(pos==180))
		{
			int servo2 = degree_90-(pos*5);
			int servo3 = degree_90+(pos*5);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"Servo2: %d",servo2);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"Servo3: %d",servo3);lcd_putstr(lcd);
			if(BW_BUTTON_CLICKED)break;
		}
	}
}

void Gripper_Down_Calibration(void)
{
	while(1)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"  PROJECT MAZE  ");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"    BRAWIJAYA   ");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"GRIP DOWN CLBRTN");lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"  DTE FT-UB 63  ");lcd_putstr(lcd);
		if(BW_BUTTON_CLICKED)break;
	}
	int pos=0;
	for(pos=0;pos<=180;pos++)
	{
		Servo_PWM_Set_Angle(SERVO_2, (degree_0+(pos*5)));
		Servo_PWM_Set_Angle(SERVO_3, (degree_180-(pos*5)));
		delay_us(1000);
		while((pos==30)||(pos==60)||(pos==90)||(pos==120)||(pos==150)||(pos==180))
		{
			int servo2 = degree_0+(pos*5);
			int servo3 = degree_180-(pos*5);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"Servo2: %d",servo2);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"Servo3: %d",servo3);lcd_putstr(lcd);
			if(BW_BUTTON_CLICKED)break;
		}
	}
	for(pos=0;pos<=180;pos++)
	{
		Servo_PWM_Set_Angle(SERVO_2, (degree_90+(pos*5)));
		Servo_PWM_Set_Angle(SERVO_3, (degree_90-(pos*5)));
		delay_us(1000);
		while((pos==30)||(pos==60)||(pos==90)||(pos==120)||(pos==150)||(pos==180))
		{
			int servo2 = degree_90+(pos*5);
			int servo3 = degree_90-(pos*5);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"Servo2: %d",servo2);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"Servo3: %d",servo3);lcd_putstr(lcd);
			if(BW_BUTTON_CLICKED)break;
		}
	}
}

void Gripper_Close_Calibration(void)
{
	while(1)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"  PROJECT MAZE  ");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"    BRAWIJAYA   ");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd," GRIP CLS CLBRTN");lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"  DTE FT-UB 63  ");lcd_putstr(lcd);
		if(BW_BUTTON_CLICKED)break;
	}
	Servo_PWM_Set_Angle(SERVO_4, degree_30);
	while(1)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"Ser4: 30-%d",degree_30);lcd_putstr(lcd);
		if(BW_BUTTON_CLICKED)break;
	}
	Servo_PWM_Set_Angle(SERVO_4, degree_60);
	while(1)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"Ser4: 60-%d",degree_60);lcd_putstr(lcd);
		if(BW_BUTTON_CLICKED)break;
	}
	Servo_PWM_Set_Angle(SERVO_4, degree_90);
	while(1)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"Ser4: 90-%d",degree_90);lcd_putstr(lcd);
		if(BW_BUTTON_CLICKED)break;
	}
	Servo_PWM_Set_Angle(SERVO_4, degree_120);
	while(1)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"Ser4: 120-%d",degree_120);lcd_putstr(lcd);
		if(BW_BUTTON_CLICKED)break;
	}
	Servo_PWM_Set_Angle(SERVO_4, degree_150);
	while(1)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"Ser4: 150-%d",degree_150);lcd_putstr(lcd);
		if(BW_BUTTON_CLICKED)break;
	}
	Servo_PWM_Set_Angle(SERVO_4, degree_180);
	while(1)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"Ser4: 180-%d",degree_180);lcd_putstr(lcd);
		if(BW_BUTTON_CLICKED)break;
	}
}

void Gripper_Open_Calibration(void)
{
	while(1)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"  PROJECT MAZE  ");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"    BRAWIJAYA   ");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"GRIP OPEN CLBRTN");lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"  DTE FT-UB 63  ");lcd_putstr(lcd);
		if(BW_BUTTON_CLICKED)break;
	}
	Servo_PWM_Set_Angle(SERVO_4, degree_180);
	while(1)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"Ser4: 180-%d",degree_180);lcd_putstr(lcd);
		if(BW_BUTTON_CLICKED)break;
	}
	Servo_PWM_Set_Angle(SERVO_4, degree_150);
	while(1)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"Ser4: 150-%d",degree_150);lcd_putstr(lcd);
		if(BW_BUTTON_CLICKED)break;
	}
	Servo_PWM_Set_Angle(SERVO_4, degree_120);
	while(1)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"Ser4: 120-%d",degree_120);lcd_putstr(lcd);
		if(BW_BUTTON_CLICKED)break;
	}
	Servo_PWM_Set_Angle(SERVO_4, degree_90);
	while(1)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"Ser4: 90-%d",degree_90);lcd_putstr(lcd);
		if(BW_BUTTON_CLICKED)break;
	}
	Servo_PWM_Set_Angle(SERVO_4, degree_60);
	while(1)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"Ser4: 60-%d",degree_60);lcd_putstr(lcd);
		if(BW_BUTTON_CLICKED)break;
	}
	Servo_PWM_Set_Angle(SERVO_4, degree_30);
	while(1)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"Ser4: 30-%d",degree_30);lcd_putstr(lcd);
		if(BW_BUTTON_CLICKED)break;
	}
}

void Gripper_Down_New(void)
{
	int pos=0;
	for(pos=0;pos<=180;pos++)
	{
		Servo_PWM_Set_Angle(SERVO_2, (degree_0+(pos*5)));
		Servo_PWM_Set_Angle(SERVO_3, (degree_180-(pos*5)));
		delay_us(1000);
	}
	for(pos=0;pos<=150;pos++)
	{
		Servo_PWM_Set_Angle(SERVO_2, (degree_90+(pos*5)));
		Servo_PWM_Set_Angle(SERVO_3, (degree_90-(pos*5)));
		delay_us(1000);
	}
}

void Gripper_Up_New(void)
{
	int pos=0;
	for(pos=0;pos<=120;pos++)
	{
		Servo_PWM_Set_Angle(SERVO_2, (2250-(pos*5)));
		Servo_PWM_Set_Angle(SERVO_3, (750+(pos*5)));
		delay_us(2500);
	}
	for(pos=0;pos<=180;pos++)
	{
		Servo_PWM_Set_Angle(SERVO_2, (degree_90-(pos*5)));
		Servo_PWM_Set_Angle(SERVO_3, (degree_90+(pos*5)));
		delay_us(2500);
	}
}

void Gripper_Up_Dikit(void)
{
	int pos=0;
	for(pos=0;pos<=90;pos++)
	{
		Servo_PWM_Set_Angle(SERVO_2, (2250-(pos*5)));
		Servo_PWM_Set_Angle(SERVO_3, (750+(pos*5)));
		delay_us(2500);
	}
}

void Gripper_Up_Full(void)
{
	int pos=0;
	for(pos=0;pos<=60;pos++)
	{
		Servo_PWM_Set_Angle(SERVO_2, (1800-(pos*5)));
		Servo_PWM_Set_Angle(SERVO_3, (1200+(pos*5)));
		delay_us(2500);
	}
	for(pos=0;pos<=180;pos++)
	{
		Servo_PWM_Set_Angle(SERVO_2, (degree_90-(pos*5)));
		Servo_PWM_Set_Angle(SERVO_3, (degree_90+(pos*5)));
		delay_us(2500);
	}
}
