/*========================================================================================
								   PROJECT BW 2.16 Ver.1.0
								  BW Hydro Extinguisher Library
==============================================================================================*/

#include "bw_extinguisher.h"

#define OPEN			100 //60 //170 //
#define CLOSE			150 //190

void BW_Extinguisher_Init(void)
{
//	EXTINGUISHER_OFF;
	Pump_GPIOInit();
	EXTINGUISHER_OFF;
}

void Pump_GPIOInit(void)
{

	RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_EXTINGUISHER, ENABLE); // Clocking GPIOC (AHB1/APB1 = 42MHz)
	GPIO_InitStructure.GPIO_Pin = EXTINGUISHER_PIN | GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;       // Pin ini memiliki Mode Ouput
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD; 		// Pin bersifat Push Pull (Pull-up, down or no Pull)
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; 	// kecepatan clock(2, 25, 50 or 100 MHz)
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; 	// pin tidak diberikan pull up
	GPIO_Init(EXTINGUISHER_PORT, &GPIO_InitStructure); 		// inisialisasi peripheral GPIO sesuai parameter typdef diatas

}

void DynaExt(int Degree)
{
	Dyna_Actuate(DYNA_EXT_ID, Degree, HEXSPD_ULTRAFAST, 220);
}

void CO2_LAUNCHER(int EXTEND_DEG, int delay_val)
{
	DynaExt(CLOSE);
	delay_ms(200);
	DynaExt(OPEN - EXTEND_DEG);
	delay_ms(delay_val);
	DynaExt(CLOSE);
}

void BW_CO2_EXTINGUISH(int open_degree,int time)
{
	DynaExt(250);
	delay_ms(200);
	DynaExt(250 - open_degree);
	delay_ms(time);
	DynaExt(250);
}

void TEST_CO2_EXTI(int degree)
{
	DynaExt(CLOSE);
	DynaExt(degree);
	delay_ms(300);
	DynaExt(CLOSE);
}

void BW_HydroPump (void)
{
	EXTINGUISHER_ON;
	EXT_1_ON;
	delay_ms(2200);
	EXT_1_OFF;
	EXTINGUISHER_OFF;
}

void BW_Pump_R4(void)
{
	while(FlameSenseDigi[0] != 4 && FlameFrontDigi[0] != 4)
	{
		FlameTracking_Center();
	}
	if(FlameSenseDigi[0] == 4 || FlameFrontDigi[0] == 4)
	{
		if(SHARP[SHARP_FRONT_L] > 18 && Ping[PING_FRONT] > 28)Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_DISABLE);
		if(SHARP[SHARP_FRONT_L] > 18 && Ping[PING_FRONT] > 28)Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_DISABLE);
		while(FlameSenseDigi[0] != 4 && FlameFrontDigi[0] != 4)
		{
			FlameTracking_Center();
		}
		/*EXTINGUISHER_ON;*/
//		DynaExt(OPEN);
		Dynamx_Mov_Static_Interpolate(LEVEL3,IKCALC_DISABLE);
		if(FlameSenseDigi[0] == 4 || FlameFrontDigi[0] == 4)
		{
			BW_HydroPump_V10();
		}
//		Dynamx_Mov_Extinguish_V10(LEVEL2);
//		Dynamx_Mov_Extinguish_V10(LEVEL2);
//		DynaExt(CLOSE);
	}

	Get_UV();
	if(UV_Lock==UVLOCK_ACTIVE)
	{
		UVLock_Refresh();
		delay_ms(1000);
	}

	Get_UV();
	if(UV_Lock == UVLOCK_ACTIVE)
	{
		if(UV_Lock==UVLOCK_ACTIVE)
		{
			UVLock_Refresh();
			delay_ms(1000);
		}
		if(UV_Lock == UVLOCK_ACTIVE)
		{
		if((FlameSenseDigi[0] != 4 && FlameFrontDigi[0] != 4) && UV_Lock == UVLOCK_ACTIVE)
		{
			FlameTracking_Center();
		}
		if(SHARP[SHARP_FRONT_L] > 18 && Ping[PING_FRONT] > 28)
		{
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_DISABLE);
		}
		if(SHARP[SHARP_FRONT_L] > 18 && Ping[PING_FRONT] > 28)
		{
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_DISABLE);
		}
		}

		if(UV_Lock==UVLOCK_ACTIVE)
		{
			UVLock_Refresh();
			delay_ms(1000);
		}
		if((FlameSenseDigi[0] != 4 && FlameFrontDigi[0] != 4) && UV_Lock == UVLOCK_ACTIVE)
		{
			FlameTracking_Center();
			if(FlameSenseDigi[0] == 4 || FlameFrontDigi[0] == 4)
			{
				BW_HydroPump_V10();
			}
		}

//		Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_CLOSE,IKCALC_DISABLE);
//		Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_CLOSE,IKCALC_DISABLE);
		if(UV_Lock==UVLOCK_ACTIVE)
		{
			UVLock_Refresh();
			delay_ms(1000);
		}
		if(UV_Lock == UVLOCK_ACTIVE)
		{
		if((FlameSenseDigi[0] != 4 && FlameFrontDigi[0] != 4) && UV_Lock == UVLOCK_ACTIVE)
		{
			FlameTracking_Center();
		}
		if(SHARP[SHARP_FRONT_L] > 18 && Ping[PING_FRONT] > 28)
		{
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_DISABLE);
		}
		if(SHARP[SHARP_FRONT_L] > 18 && Ping[PING_FRONT] > 28)
		{
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_DISABLE);
		}
		if((FlameSenseDigi[0] != 4 && FlameFrontDigi[0] != 4) && UV_Lock == UVLOCK_ACTIVE)
		{
			FlameTracking_Center();
			if(FlameSenseDigi[0] == 4 || FlameFrontDigi[0] == 4)
			{
				BW_HydroPump_V10();
			}
		}
		}

	}
}

void BW_HydroPump_V10 (void)
{
	Dynamx_Mov_Static_Interpolate(LEVEL5,IKCALC_ENABLE);

	CO2_LAUNCHER(0, 250);
}

void BW_HydroPump_2021_1 (void){
	Dynamx_Mov_Static_Interpolate(LEVEL5,IKCALC_ENABLE);

	CO2_LAUNCHER_V2(0, 100);
}

void BW_HydroPump_2021_2 (void){
	Dynamx_Mov_Static_Interpolate(LEVEL5,IKCALC_ENABLE);

	CO2_LAUNCHER_V3(0, 100);
}

void CO2_LAUNCHER_V2(int EXTEND_DEG, int delay_val)
{
	DynaExt(CLOSE);
	delay_ms(200);
	DynaExt(OPEN - EXTEND_DEG);
	delay_ms(delay_val);
	Dynamx_Rot_Right_Interpolate(LEVEL_MAX,HEXSTEP_FAR,IKCALC_DISABLE);
	DynaExt(CLOSE);
}

void CO2_LAUNCHER_V3(int EXTEND_DEG, int delay_val)
{
	DynaExt(CLOSE);
	delay_ms(200);
	DynaExt(OPEN - EXTEND_DEG);
	delay_ms(delay_val);
	Dynamx_Rot_Left_Interpolate(LEVEL_MAX,HEXSTEP_FAR,IKCALC_DISABLE);
	DynaExt(CLOSE);
}

void BW_CO2_TEST(void)
{
	int tes_co2 = CLOSE;
	while(1)
	{
		lcd_display_clear();
		lcd_gotoxy(1,0);sprintf(lcd,"BHATARA WIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(2,2);sprintf(lcd,"CO2 EXTI");lcd_putstr(lcd);
		lcd_gotoxy(2,3);sprintf(lcd,"Degree : %d",tes_co2);lcd_putstr(lcd);

		if(BUTTON_A_CLICKED)
		{
			while(BUTTON_A_CLICKED);
			tes_co2 += 5;
		}

		else if(BUTTON_B_CLICKED)
		{
			while(BUTTON_B_CLICKED);
			tes_co2 -= 5;
		}

		if(tes_co2 < 0)tes_co2 = 0;
		else if(tes_co2 > 300)tes_co2 = 300;

		if(BW_BUTTON_CLICKED)
		{
			TEST_CO2_EXTI(tes_co2);
		}
		delay_ms(100);
	}
}


void PushTo_Burst (void)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(2,2);sprintf(lcd,"PUSH TO BURST");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
	delay_ms(100);

	if(BW_BUTTON_CLICKED)
	{
		while(BW_BUTTON_CLICKED)
		CO2_LAUNCHER(0,190);
	}
}

void DynaCleaner(int Degree)
{
	Dyna_Actuate(CLEANER, Degree, HEXSPD_SLOW, 220);
}
