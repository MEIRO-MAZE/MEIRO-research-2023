/*****************************************************
Project   : BW* Main Controller
Version   : 1.4
Year      : 2021
Date      : November 12rd
Author    : Muhammad Yogi Nurrohman(2018)
University: University of Brawijaya
Department: Electrical Engineering Department, Engineering Faculty
Division  : Legged Fire-Fighting Division (KRPAI)
Comments  : *Bhatara Wijaya GO INTERNATIONAL

What's New: New Pin Mapping for New Board Design
			Implemented I2C LCD
			Sync Write for Dynamixels control, removed TX delay time
			Proper Speed calculation for each servo in movement
			Torque and Compliant slope control and adjustment for dynamixel
			Better start position recognition and follow decision for avoiding hard obstacle
			Faster flame position detection and flame extinguishing
			Few small changes on gait steps to fix turning and rotation
			New PID Calculation, roll back to basic PID equation with few adjustment to meet requirement, implemented Integral controller
			Added Compass automatic flag decision, no further programming required, just input the compass data boundaries
			Easier calibration
			Added fault detection, not optimized yet
			Added EEPROM (not used anymore)
			Better Cat avoiding algorithm
			Added looping movement recognition to escape following obstacle
			Optimization from 1.0
			New movement with better Inverse Kinematics calculation

Board Type: STM32F4 Discovery Board
Chip  Type: STM32F407VG
*****************************************************/


#include "main.h"

void BW_Initialization(void);
void BW_SystemCheck(void);

int main(void)
{
	int BUTTON_ACT;
	int SOUND_ACT;

	BW_Initialization();
	delay_ms(500);

	lcd_display_clear();

	Dyna_Slope(FRONT_RIGHT_DX_COXA, 28, 29);
	Dyna_Slope(FRONT_RIGHT_DX_FEMUR, 28, 29);
	Dyna_Slope(FRONT_RIGHT_DX_TIBIA, 28, 29);
	setPunch(FRONT_RIGHT_DX_COXA, 48);
	setPunch(FRONT_RIGHT_DX_FEMUR, 49);
	setPunch(FRONT_RIGHT_DX_TIBIA, 48);
//	SetMaxTorque(FRONT_RIGHT_DX_COXA);
//	SetMaxTorque(FRONT_RIGHT_DX_FEMUR);
//	SetMaxTorque(FRONT_RIGHT_DX_TIBIA);
	delay_ms(10);

	Dyna_Slope(FRONT_LEFT_DX_COXA, 28, 29);
	Dyna_Slope(FRONT_LEFT_DX_FEMUR, 28, 29);
	Dyna_Slope(FRONT_LEFT_DX_TIBIA, 28, 29);
	setPunch(FRONT_LEFT_DX_COXA, 48);
	setPunch(FRONT_LEFT_DX_FEMUR, 49);
	setPunch(FRONT_LEFT_DX_TIBIA, 48);
//	SetMaxTorque(FRONT_LEFT_DX_COXA);
//	SetMaxTorque(FRONT_LEFT_DX_FEMUR);
//	SetMaxTorque(FRONT_LEFT_DX_TIBIA);
	delay_ms(10);

	Dyna_Slope(MIDDLE_RIGHT_DX_COXA, 28, 29);
	Dyna_Slope(MIDDLE_RIGHT_DX_FEMUR, 28, 29);
	Dyna_Slope(FRONT_RIGHT_DX_TIBIA, 28, 29);
	setPunch(MIDDLE_RIGHT_DX_COXA, 48);
	setPunch(MIDDLE_RIGHT_DX_FEMUR, 49);
	setPunch(MIDDLE_RIGHT_DX_TIBIA, 48);
//	SetMaxTorque(MIDDLE_RIGHT_DX_COXA);
//	SetMaxTorque(MIDDLE_RIGHT_DX_FEMUR);
//	SetMaxTorque(MIDDLE_RIGHT_DX_TIBIA);
	delay_ms(10);

	Dyna_Slope(MIDDLE_LEFT_DX_COXA, 28, 29);
	Dyna_Slope(MIDDLE_LEFT_DX_FEMUR, 28, 29);
	Dyna_Slope(MIDDLE_LEFT_DX_TIBIA, 28, 29);
	setPunch(MIDDLE_LEFT_DX_COXA, 48);
	setPunch(MIDDLE_LEFT_DX_FEMUR, 49);
	setPunch(MIDDLE_LEFT_DX_TIBIA, 48);
//	SetMaxTorque(MIDDLE_LEFT_DX_COXA);
//	SetMaxTorque(MIDDLE_LEFT_DX_FEMUR);
//	SetMaxTorque(MIDDLE_LEFT_DX_TIBIA);
	delay_ms(10);

	Dyna_Slope(REAR_RIGHT_DX_COXA, 28, 29);
	Dyna_Slope(REAR_RIGHT_DX_FEMUR, 28, 29);
	Dyna_Slope(REAR_RIGHT_DX_TIBIA, 28, 32);
	setPunch(REAR_RIGHT_DX_COXA, 48);
	setPunch(REAR_RIGHT_DX_FEMUR, 49);
	setPunch(REAR_RIGHT_DX_TIBIA, 48);
//	SetMaxTorque(REAR_RIGHT_DX_COXA);
//	SetMaxTorque(REAR_RIGHT_DX_FEMUR);
//	SetMaxTorque(REAR_RIGHT_DX_TIBIA);
	delay_ms(10);

	Dyna_Slope(REAR_LEFT_DX_COXA, 28, 29);
	Dyna_Slope(REAR_LEFT_DX_FEMUR, 28, 29);
	Dyna_Slope(REAR_LEFT_DX_TIBIA, 28, 29);
	setPunch(REAR_LEFT_DX_COXA, 48);
	setPunch(REAR_LEFT_DX_FEMUR, 49);
	setPunch(REAR_LEFT_DX_TIBIA, 48);
//	SetMaxTorque(REAR_LEFT_DX_COXA);
//	SetMaxTorque(REAR_LEFT_DX_FEMUR);
//	SetMaxTorque(REAR_LEFT_DX_TIBIA);
	delay_ms(10);

//	Dyna_Slope(DYNA_EXT_ID, 28, 29);
//	setPunch(DYNA_EXT_ID, 48);
//	SetMaxTorque(DYNA_EXT_ID);

	Dyna_Slope(CLEANER, 32, 32);
	setPunch(CLEANER, 32);
//	SetMaxTorque(CLEANER);
	delay_ms(10);

	Dyna_Slope(GRIPPER_UP, 32, 32);
	Dyna_Slope(GRIPPER_CLIP, 32, 32);
	setPunch(GRIPPER_UP, 32);
	setPunch(GRIPPER_CLIP, 32);
//	SetMaxTorque(GRIPPER_UP);
//	SetMaxTorque(GRIPPER_CLIP);
	delay_ms(10);

//	DynaExt(150);
//	DynaGrip(DG_GRIP_DOWN,120);
	DynaCleaner(245);
	delay_ms(10);

	GRIPPER_LED_OFF;

	Gripper_Close_K1();
	Gripper_Up_K1();
	delay_ms(100);

	lcd_gotoxy(0,0);sprintf(lcd,"IK STATIC");lcd_putstr(lcd);

	Dynamx_Mov_Static_Interpolate(LEVEL2, IKCALC_ENABLE);
	delay_ms(500);

	int RT_MODE = 1; // Ganti 0 untuk TRIAL, ganti 1 untuk Running Test

	if(RT_MODE == 1)
	{
		SND_ACT_LED_ON;
		FIRE_LED_ON;
		delay_ms(200);
		FIRE_LED_OFF;
		SND_ACT_LED_OFF;
	}
	BW_PID_Init();

	if(RT_MODE == 0)
	{
		BW_SystemCheck();

		if(RCC_GetFlagStatus(RCC_FLAG_SFTRST))
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"SFT");lcd_putstr(lcd);
			RCC_ClearFlag();
			delay_ms(1000);
		}

		else if(RCC_GetFlagStatus(RCC_FLAG_PORRST))
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"NORMAL");lcd_putstr(lcd);
			RCC_ClearFlag();
			delay_ms(1000);
		}

		else if(RCC_GetFlagStatus(RCC_FLAG_PINRST))
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"PIN");lcd_putstr(lcd);
			RCC_ClearFlag();
			delay_ms(1000);
		}

		else
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"STM32 OK");lcd_putstr(lcd);
			delay_ms(1000);
		}
	}

	Load_CAT_MIN_DATA();
	if(Load_CMPS_DATA() != 0)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"EEPROM NO DATA");lcd_putstr(lcd);

		// isi nilai dari hasil kalibrasi manual, jaga2 kalau eeprom rusak di tengah2
		R4AB_THRESHOLD_UPPER = 315; // kiri dari 4A
		R4AB_THRESHOLD_LOWER = 173; // kanan dari 4A

		R4A_THRESHOLD_UPPER = 272;	//kiri 4A
		R4A_THRESHOLD_LOWER = 206;	//kanan 4A
		R4B_THRESHOLD_LOWER = 129;	//kiri 4B
		R4B_THRESHOLD_UPPER = 358;	//kanan 4B

		//unsigned int R4A_THRESHOLD_MIDDLE=(160+210)/2;
		R4A_THRESHOLD_MIDDLE = 238;
		R4B_THRESHOLD_MIDDLE = 59;
		START_MIDDLE = 70;
		R1BC_THRESHOLD_MIDDLE = 242;

		//stairs
		STAIRS_THRESHOLD_4B_UPPER =141;
		STAIRS_THRESHOLD_4B_LOWER =221;
		STAIRS_THRESHOLD_4B_MIDDLE =87;
		STAIRS_THRESHOLD_4A_UPPER =11;
		STAIRS_THRESHOLD_4A_LOWER =342;
		STAIRS_THRESHOLD_4A_MIDDLE =316;
	}

	if(CAT_MIN_RANGE <= 0)
	{
		CAT_MIN_RANGE = 11;
	}
	R4AB_THRESHOLD_MIDDLE=(R4AB_THRESHOLD_UPPER+R4AB_THRESHOLD_LOWER)/2;

	int direction_check = 1;

	if (direction_check == 1)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"KALIBRASI OK");lcd_putstr(lcd);

		NORTH = 166;
		SOUTH = 334;
		EAST = 86;
		WEST = 283;

		K1_NORTH = 166;
		K1_SOUTH = 334;
		K1_EAST = 86;
		K1_WEST = 283;

		K2_NORTH = 179;
		K2_SOUTH = 334;
		K2_EAST = 95;
		K2_WEST = 283;

		R9_NORTH = 177;
		R9_SOUTH = 334;
		R9_EAST = 98;
		R9_WEST = 283;

		Fix_Direction();
	}

	lcd_display_clear();

	int mode_tes ;
	mode_tes = 0; // 1 untuk masuk dan 0 untuk skip mode tes

	int IK_tes;
	IK_tes = 0;	  // 1 untuk masuk dan 0 untuk skip cek value trajectory
	if (IK_tes == 1)
	{
		while(IK_tes == 1)
		{
				lcd_gotoxy(0,1);sprintf(lcd,"%d%d%d%d%d%d",X_STATIC_IK[0],X_STATIC_IK[1],X_STATIC_IK[2],X_STATIC_IK[3],X_STATIC_IK[4],X_STATIC_IK[5]);lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"%d%d%d%d%d%d",Y_STATIC_IK[0],Y_STATIC_IK[1],Y_STATIC_IK[2],Y_STATIC_IK[3],Y_STATIC_IK[4],Y_STATIC_IK[5]);lcd_putstr(lcd);
				lcd_gotoxy(0,3);sprintf(lcd,"%d%d%d%d%d%d",Z_STATIC_IK[0],Z_STATIC_IK[1],Z_STATIC_IK[2],Z_STATIC_IK[3],Z_STATIC_IK[4],Z_STATIC_IK[5]);lcd_putstr(lcd);
				while(1){};
		}

	}

	if(mode_tes == 1)
	{

	}

	while(BW_BUTTON_UNCLICKED)
	{
		if(BW_BUTTON_CLICKED){BUTTON_ACT=1;break;}
		if(BUTTON_A_CLICKED)
		{
			while(BUTTON_A_CLICKED){}
			ENABLE_UV1 = (!ENABLE_UV1);
		}
		if(BUTTON_B_CLICKED)
		{
			while(BUTTON_B_CLICKED){}
			ENABLE_UV2 = (!ENABLE_UV2);
		}
		RotSwitch_Sampling();
		Display_MODE();
		if(BW_BUTTON_CLICKED){BUTTON_ACT=1;break;}
	}

	if(BW_BUTTON_CLICKED){BUTTON_ACT=1;}
	if(SOUND_ACTIVATED){SOUND_ACT=1;}

	if(BUTTON_ACT==1)
	{
		lcd_display_clear();
		lcd_gotoxy(5,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"BUTTON ACTIVATED");lcd_putstr(lcd);
		delay_ms(100);
	}

	switch(rot_switch_mode)
	{
		case BW_MODE_DEFAULT:
			{

			}break;

		case BW_MODE_1:
			{
				while(1)
				{
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"   ME:ZE 2023   ");lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"NAVIGASI  REGION");lcd_putstr(lcd);
					lcd_gotoxy(0,2);sprintf(lcd,"   ALGORITM 1   ");lcd_putstr(lcd);
					lcd_gotoxy(0,3);sprintf(lcd,"  DTE FT-UB 63  ");lcd_putstr(lcd);
					delay_ms(100);

					BW_Algorithm1_2023();
					while(1)
					{
						Dynamx_Mov_Static_Interpolate(LEVEL3,IKCALC_ENABLE);
						GRIPPER_LED_ON;
						delay_ms(500);
						GRIPPER_LED_OFF;
						delay_ms(500);
					}
				}
			}break;

		case BW_MODE_2:
			{
				USART3_PutChar(NOT_IN_ROOM_STAT);
				BW_Initial_Setup(rot_switch_mode);

				while(1)
				{
					BW_Mode_2();

					while(1)
					{
						SND_ACT_LED_OFF;
						Dynamx_Mov_Static_Interpolate(LEVEL3,IKCALC_ENABLE);
					}
				}
			}break;

		case BW_MODE_3:
			{
				BW_Initial_Setup(rot_switch_mode);
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"   MEIRO|MAZE   ");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"   PID TUNING   ");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"      TEST      ");lcd_putstr(lcd);

				BW_PID_Init();
				BW_LOCATION[0] = LOCATION_CORRIDOR;
//				ROOM4A_CAT_AVOIDER = ROOM4A_CAT_AVOIDER_ACTIVE;

				while(1)
				{
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"   MEIRO|MAZE   ");lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"   PID TUNING   ");lcd_putstr(lcd);
					lcd_gotoxy(0,2);sprintf(lcd,"   P:L|A:R|H:O  ");lcd_putstr(lcd);


					BW_PID_Init_Obs();
					if(BW_BUTTON_CLICKED){
						while(BW_BUTTON_CLICKED){}
						delay_ms(200);
						Kp_Tuning_R_Obs();
						while(BW_BUTTON_CLICKED){}
						delay_ms(200);
						Ki_Tuning_R_Obs();
						while(BW_BUTTON_CLICKED){}
						delay_ms(200);
						Kd_Tuning_R_Obs();
						while(BW_BUTTON_CLICKED){}
						delay_ms(200);
						Dynamx_Mov_Static_Obs(LEVEL2);
						delay_ms(1000);
						BW_FollowCounter_Right_Obs(1000);
						Dynamx_Mov_Static_Obs(LEVEL2);

					}
					BW_PID_Init();
					if(BUTTON_B_CLICKED)
					{
						while(BW_BUTTON_CLICKED){}
						delay_ms(200);
						Kp_Tuning_L();
						while(BW_BUTTON_CLICKED){}
						delay_ms(200);
						Ki_Tuning_L();
						while(BW_BUTTON_CLICKED){}
						delay_ms(200);
						Kd_Tuning_L();
						while(BW_BUTTON_CLICKED){}
						delay_ms(200);
						BW_FollowTracer_Left_Interpolate();
						Dynamx_Mov_Static_Interpolate(LEVEL3,IKCALC_ENABLE);
						FOLLOW_CALC = KOSONG;

					}

					else if(BUTTON_A_CLICKED)
					{
						while(BW_BUTTON_CLICKED){}
						delay_ms(200);
						Kp_Tuning_R();
						while(BW_BUTTON_CLICKED){}
						delay_ms(200);
						Ki_Tuning_R();
						while(BW_BUTTON_CLICKED){}
						delay_ms(200);
						Kd_Tuning_R();
						while(BW_BUTTON_CLICKED){}
						delay_ms(200);
//						BW_FollowTracer_Right_Interpolate();
						BW_FollowCounter_Right(100);
						Dynamx_Mov_Static_Interpolate(LEVEL3,IKCALC_ENABLE);
						FOLLOW_CALC = KOSONG;
					}
				}

			}break;

		case BW_MODE_4:
			{
				BW_Initial_Setup(rot_switch_mode);
				lcd_display_clear();

				while(1)
				{
					Aktuator_Monitor();
				}
			}break;

		case BW_MODE_5:
			{
				BW_Initial_Setup(rot_switch_mode);
				lcd_display_clear();

				while(1)
				{
					Sensor_Menu();
				}
			}break;

		case BW_MODE_6:
			{

				BW_Initial_Setup(rot_switch_mode);
				lcd_display_clear();

				lcd_gotoxy(1,0);sprintf(lcd,"BHATARA WIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(1,1);sprintf(lcd,"TEST MOVEMENT");lcd_putstr(lcd);
				delay_ms(100);

				lcd_display_clear();
				while (1)
				{
					BW_Test_Menu();
				}


			}break;
	}
	while(1)

	return 0;
}

void BW_Initialization(void)
{
	//CLOCK CONFIG
	SystemInit();

	//SYSTICK DELAY INIT
	SysTick_Init();

	//BW EXTINGUISHER INIT
	BW_Extinguisher_Init();

	//LCD INIT
	delay_ms(50);
	BW_LCD_Init();
	lcd_cursor_off_blink_off();
	lcd_display_clear();

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(5,1);sprintf(lcd,"SYSTEM");lcd_putstr(lcd);
	lcd_gotoxy(1,2);sprintf(lcd,"INITIALIZATION");lcd_putstr(lcd);
	lcd_gotoxy(1,3);sprintf(lcd,"BRAWIJAYA 2021");lcd_putstr(lcd);
	delay_ms(500);

	//INERTIAL MEASUREMENT UNIT (IMU) SENSOR
	BW_CMPS11_Init();

	//BW COMPAS INTERRUPT INITIALIZATION
	Cmps11_Interrupt_Init();

	//MZ TRACER BOTTOM INIT
	USART1_Init_Tracer(1000000);

	//MZ TRACER & ToF GRIPPER INIT
	USART6_Init_Tracer_Grip(1000000);

	//MZ RANGERFINDER INIT
	USART3_Init(115200);

	//MZ DYNAMIXEL SERVO INIT
	Dynamixel_USART2_Init(1000000);

	//BW USER INTERFACE
	Button_Init();
	FIRE_LED_Init();
	BW_LED_Interrupt_Init();
	RotSwitch_Init();
	RotSwitch_Sampling();

	TCS_GRIPPER_LED_Init();
	SND_ACT_LED_Init();

	//MZ SERVO PWM INIT
	Servo_PWM_Config();

	//BW PID CONTROLLER INITIALIZATION
	BW_PID_Init();
	PID_Calculate_Rule_Interrupt_Init();

	//BW FLAME TRACKING PID
	FlameSense_PID_Init();

	//BW SOUND ACTIVATION INIT
	BW_Sound_Activation_Init();

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(5,1);sprintf(lcd,"SYSTEM");lcd_putstr(lcd);
	lcd_gotoxy(1,2);sprintf(lcd,"INITIALIZATION");lcd_putstr(lcd);
	lcd_gotoxy(3,3);sprintf(lcd,"COMPLETED");lcd_putstr(lcd);
	delay_ms(50);

}

void BW_SystemCheck(void)
{
	ping_count = 0;
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(2,1);sprintf(lcd,"SYSTEM CHECK");lcd_putstr(lcd);
	delay_ms(500);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(3,1);sprintf(lcd,"PING CHECK");lcd_putstr(lcd);
	delay_ms(500);
	lcd_display_clear();
	if((Ping[PING_FRONT] != 253)&&(Ping[PING_FRONT] != 0))
	{
//		lcd_gotoxy(0,0);sprintf(lcd,"FRONT O");lcd_putstr(lcd);

	}
	else
	{
//		lcd_gotoxy(0,0);sprintf(lcd,"FRONT X");lcd_putstr(lcd);
		PING_ERROR[ping_count] = 1;
		ping_count++;
	}
//	delay_ms(200);
	if((Ping[PING_REAR] != 253)&&(Ping[PING_REAR] != 0))
	{

//		lcd_gotoxy(0,1);sprintf(lcd,"REAR  O");lcd_putstr(lcd);
	}
	else
	{
//		lcd_gotoxy(0,1);sprintf(lcd,"REAR  X");lcd_putstr(lcd);
		PING_ERROR[ping_count] = 2;
		ping_count++;
	}
//	delay_ms(200);
	if((Ping[PING_RIGHT] != 253)&&(Ping[PING_RIGHT] != 0))
	{

//		lcd_gotoxy(0,2);sprintf(lcd,"RIGHT O");lcd_putstr(lcd);
	}
	else
	{
//		lcd_gotoxy(0,2);sprintf(lcd,"RIGHT X");lcd_putstr(lcd);
		PING_ERROR[ping_count] = 3;
		ping_count++;
	}
//	delay_ms(200);
	if((Ping[PING_LEFT] != 253)&&(Ping[PING_LEFT] != 0))
	{

//		lcd_gotoxy(0,3);sprintf(lcd,"LEFT  O");lcd_putstr(lcd);
	}
	else
	{
//		lcd_gotoxy(0,3);sprintf(lcd,"LEFT  X");lcd_putstr(lcd);
		PING_ERROR[ping_count] = 4;
		ping_count++;
	}
//	delay_ms(200);
	if((Ping[PING_ASKEW_RIGHT] != 253)&&(Ping[PING_ASKEW_RIGHT] != 0))
	{

//		lcd_gotoxy(8,0);sprintf(lcd,"F_R   O");lcd_putstr(lcd);
	}
	else
	{
//		lcd_gotoxy(8,0);sprintf(lcd,"F_R   X");lcd_putstr(lcd);
		PING_ERROR[ping_count] = 5;
		ping_count++;
	}
//	delay_ms(200);
	if((Ping[PING_ASKEW_LEFT] != 253)&&(Ping[PING_ASKEW_LEFT] != 0))
	{

//		lcd_gotoxy(8,1);sprintf(lcd,"F_L   O");lcd_putstr(lcd);
	}
	else
	{
//		lcd_gotoxy(8,1);sprintf(lcd,"F_L   X");lcd_putstr(lcd);
		PING_ERROR[ping_count] = 6;
		ping_count++;
	}
//	delay_ms(200);
	if((Ping[PING_REAR_RIGHT] != 253)&&(Ping[PING_REAR_RIGHT] != 0))
	{

//		lcd_gotoxy(8,2);sprintf(lcd,"R_R   O");lcd_putstr(lcd);
	}
	else
	{
//		lcd_gotoxy(8,2);sprintf(lcd,"R_R   X");lcd_putstr(lcd);
		PING_ERROR[ping_count] = 7;
		ping_count++;
	}
//	delay_ms(200);
	if((Ping[PING_REAR_LEFT] != 253)&&(Ping[PING_REAR_LEFT] != 0))
	{

//		lcd_gotoxy(8,3);sprintf(lcd,"R_L   O");lcd_putstr(lcd);
	}
	else
	{
//		lcd_gotoxy(8,3);sprintf(lcd,"R_L   X");lcd_putstr(lcd);
		PING_ERROR[ping_count] = 8;
		ping_count++;
	}

	if(ping_count > 0)
	{
		int f;
		for(f = 0;f < ping_count;f++)
		{
		switch(PING_ERROR[f])
		{
			case 1 :
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"ERROR FRONT");lcd_putstr(lcd);
				while(BW_BUTTON_UNCLICKED && (Ping[PING_FRONT] == 0 || Ping[PING_FRONT] == 253))
				{
					lcd_gotoxy(0,1);sprintf(lcd,"CEK PLISS");lcd_putstr(lcd);
				}
				break;
			case 2 :
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"ERROR REAR");lcd_putstr(lcd);
				while(BW_BUTTON_UNCLICKED && (Ping[PING_REAR] == 0 || Ping[PING_REAR] == 253))
				{
					lcd_gotoxy(0,1);sprintf(lcd,"CEK PLISS");lcd_putstr(lcd);
				}
				break;
			case 3 :
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"ERROR RIGHT");lcd_putstr(lcd);
				while(BW_BUTTON_UNCLICKED && (Ping[PING_RIGHT] == 0 || Ping[PING_RIGHT] == 253))
				{
					lcd_gotoxy(0,1);sprintf(lcd,"CEK PLISS");lcd_putstr(lcd);
				}
				break;
			case 4 :
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"ERROR LEFT");lcd_putstr(lcd);
				while(BW_BUTTON_UNCLICKED && (Ping[PING_LEFT] == 0 || Ping[PING_LEFT] == 253))
				{
					lcd_gotoxy(0,1);sprintf(lcd,"CEK PLISS");lcd_putstr(lcd);
				}
				break;
			case 5 :
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"ERROR FRONT RIGHT");lcd_putstr(lcd);
				while(BW_BUTTON_UNCLICKED && (Ping[PING_ASKEW_RIGHT] == 0 || Ping[PING_ASKEW_RIGHT] == 253))
				{
					lcd_gotoxy(0,1);sprintf(lcd,"CEK PLISS");lcd_putstr(lcd);
				}
				break;
			case 6 :
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"ERROR FRONT LEFT");lcd_putstr(lcd);
				while(BW_BUTTON_UNCLICKED && (Ping[PING_ASKEW_LEFT] == 0 || Ping[PING_ASKEW_LEFT] == 253))
				{
					lcd_gotoxy(0,1);sprintf(lcd,"CEK PLISS");lcd_putstr(lcd);
				}
				break;
			case 7 :
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"ERROR REAR RIGHT");lcd_putstr(lcd);
				while(BW_BUTTON_UNCLICKED && (Ping[PING_REAR_RIGHT] == 0 || Ping[PING_REAR_RIGHT] == 253))
				{
					lcd_gotoxy(0,1);sprintf(lcd,"CEK PLISS");lcd_putstr(lcd);
				}
				break;
			case 8 :
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"ERROR REAR LEFT");lcd_putstr(lcd);
				while(BW_BUTTON_UNCLICKED && (Ping[PING_REAR_LEFT] == 0 || Ping[PING_REAR_LEFT] == 253))
				{
					lcd_gotoxy(0,1);sprintf(lcd,"CEK PLISS");lcd_putstr(lcd);
				}
				break;
			case 0 :
				lcd_display_clear();
				lcd_gotoxy(6,0);sprintf(lcd,"AMAN");lcd_putstr(lcd);
				delay_ms(1000);
				break;
			}
		}
	}

	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(0,1);sprintf(lcd,"FLAME CHECK");lcd_putstr(lcd);
	if(Flame_Stat == 1)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"FLAME MANTULL");lcd_putstr(lcd);
		delay_ms(1000);
	}
	else
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"FLAME MODAR");lcd_putstr(lcd);
		while(BW_BUTTON_UNCLICKED && Flame_Stat == 0)
		{
			lcd_gotoxy(0,1);sprintf(lcd,"CEK PLISS");lcd_putstr(lcd);
		}
	}
	I2C3_Test();
	delay_ms(1000);
}
