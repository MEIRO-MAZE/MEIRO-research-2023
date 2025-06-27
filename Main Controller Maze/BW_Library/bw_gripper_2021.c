#include "main.h"
#include "bw_gripper_2021.h"

int LOW_LEVEL = 0;
int MEDIUM_LEVEL = 1;
int HIGH_LEVEL = 2;

void DynaGrip (int Degree1, int Degree2)
{
	Dyna_movespeed(GRIPPER_UP, Degree1, 300,220);
	Dyna_movespeed(GRIPPER_CLIP, Degree2,300,220);
}

void Grip( int Dg1, int Dg2, int movement)
{
	int speed;

	switch (movement)
	{
		case 0:
		{
			speed = 200;
		}break;

		case 1:
		{
			speed = 500;
		}break;

		case 2:
		{
			speed = 1000;
		}break;
	}

	Dyna_movespeed(GRIPPER_CLIP, Dg2,speed,220);
	Dyna_movespeed(GRIPPER_UP, Dg1,speed,220);
}

void Lift_Grip(int movement)
{
	Grip(125,150,movement);
}

void Close_Grip(int movement)
{
	Grip(165,150,movement);
}

void Down_Grip(int movement)
{
	Grip(165,150,movement);
}

void Open_Grip(int movement)
{
	Grip(165,100,movement);
}

void Aktuator_Monitor (void)
{
	int MENU_VAR=0;

	while(BUTTON_IDLE)
	{
		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"MAZE  2023");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"AKTUATOR MONITOR");lcd_putstr(lcd);
		lcd_gotoxy(3,2);sprintf(lcd,"MAIN  MENU");lcd_putstr(lcd);
		lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
		delay_ms(100);
	}

	if(BW_BUTTON_CLICKED)
	{
		while(1)
		{
			if(BUTTON_A_CLICKED)
			{
				BW_Buzz(2);
				while(BUTTON_A_CLICKED){};
				MENU_VAR++;
			}
			if(BUTTON_B_CLICKED)
			{
				BW_Buzz(2);
				while(BUTTON_B_CLICKED){};
				MENU_VAR--;
			}

			if(MENU_VAR>3) MENU_VAR=0;
			else if (MENU_VAR<0) MENU_VAR=3;

			switch (MENU_VAR)
			{
				case 0:
				{
//					Grippler_Trial_Button();
					Servo_PWM_Set_Angle(SERVO_4, degree_180);
					Servo_PWM_Set_Angle(SERVO_2, degree_0);
					Servo_PWM_Set_Angle(SERVO_3, degree_180);
					Gripper_PWM_Trial_Button();
				}break;

				case 1:
				{
					Servo_PWM_Set_Angle(SERVO_4, degree_120);
					Gripper_Down_Calibration();
					Gripper_Up_Calibration();
				}break;

				case 2:
				{
					Gripper_Down_K1();
					Gripper_Open_Calibration();
					Gripper_Close_Calibration();
				}break;

				case 3:
				{
//					Gripper_PWM_Down();
					lcd_display_clear();
					lcd_gotoxy(4,2);sprintf(lcd,"HAYOO!");lcd_putstr(lcd);
				}break;
			}

		}
	}
}

void Grippler_Trial_Button(void)
{
	lcd_display_clear();
	lcd_gotoxy(3,0);sprintf(lcd,"BW  2021");lcd_putstr(lcd);
	lcd_gotoxy(0,1);sprintf(lcd,"GRIPPER TEST");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"PUSH TO START");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
	delay_ms(100);

	if (BW_BUTTON_CLICKED)
	{
		while(BW_BUTTON_CLICKED){};
		int state = 0;
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"GRIPPER GASSS");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"Yellow: OPEN");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"Red: CLOSE");lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"Black: UP & DOWN");lcd_putstr(lcd);
		delay_ms(10);

		while(1)
		{
			if (BW_BUTTON_CLICKED && state ==0)
			{
				while(BW_BUTTON_CLICKED && state ==0){};
				Dyna_movespeed(GRIPPER_UP, DG_GRIP_DOWN,400,220);
				state = 1;
			}

			if (BW_BUTTON_CLICKED && state ==1)
			{
				while(BW_BUTTON_CLICKED && state ==1){};
				Dyna_movespeed(GRIPPER_UP, DG_GRIP_UP,400,220);
				state = 0;
			}

			if (BUTTON_A_CLICKED)
			{
				while(BUTTON_A_CLICKED){};
				Dyna_movespeed(GRIPPER_CLIP, 120,200,220);
			}

			if (BUTTON_B_CLICKED)
			{
				while(BUTTON_B_CLICKED){};
				Dyna_movespeed(GRIPPER_CLIP, 170,200,220);
			}
		}
	}


}
