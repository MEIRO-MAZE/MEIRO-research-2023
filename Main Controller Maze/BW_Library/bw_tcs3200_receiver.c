/*==============================================================================================
								PROJECT BW 2016 Ver.1.0
							  BW TCS3200 RECEIVER LIBRARY
==============================================================================================*/

#include "bw_tcs3200_receiver.h"


void Display_RGB_Data(unsigned int Tracer)
{
	int RED_FRONT,BLUE_FRONT,GREEN_FRONT,RED_BACK,BLUE_BACK,GREEN_BACK,STAT;
	int RED_GRIPPER_1,BLUE_GRIPPER_1,GREEN_GRIPPER_1,RED_GRIPPER_2,BLUE_GRIPPER_2,GREEN_GRIPPER_2,STAT_GRIPPER;

	RED_FRONT 	= TCS3200_SLV_DATA[0];
	GREEN_FRONT = TCS3200_SLV_DATA[1];
	BLUE_FRONT  = TCS3200_SLV_DATA[2];

	RED_BACK 	= TCS3200_SLV_DATA[3];
	GREEN_BACK 	= TCS3200_SLV_DATA[4];
	BLUE_BACK   = TCS3200_SLV_DATA[5];

	STAT 		= TCS3200_SLV_DATA[6];

	RED_GRIPPER_1   = TCS34725_SLV_DATA[0];
	GREEN_GRIPPER_1 = TCS34725_SLV_DATA[1];
	BLUE_GRIPPER_1  = TCS34725_SLV_DATA[2];

	RED_GRIPPER_2   = TCS34725_SLV_DATA[3];
	GREEN_GRIPPER_2 = TCS34725_SLV_DATA[4];
	BLUE_GRIPPER_2  = TCS34725_SLV_DATA[5];

	STAT_GRIPPER = TCS34725_SLV_DATA[6];

	if(Tracer==TRACER_GRIPPER)
	{
		lcd_display_clear();

		lcd_gotoxy(0,0);sprintf(lcd,"G1");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"R:%d",RED_GRIPPER_1);lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"G:%d",GREEN_GRIPPER_1);lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"B:%d",BLUE_GRIPPER_1);lcd_putstr(lcd);

		lcd_gotoxy(6,0);sprintf(lcd,"VL-ToF");lcd_putstr(lcd);
		lcd_gotoxy(6,1);sprintf(lcd,"V:%d",VL_SENSOR[0]);lcd_putstr(lcd);
		lcd_gotoxy(6,2);sprintf(lcd,"S_F:%d",SHARP_FRONT[0]);lcd_putstr(lcd);

		lcd_gotoxy(6,3);sprintf(lcd,"S-TCS:%d",STAT_GRIPPER);lcd_putstr(lcd);
		delay_ms(100);
	}
	else if(Tracer==TRACER_BOTTOM)
	{
		lcd_display_clear();

		lcd_gotoxy(0,0);sprintf(lcd,"FR");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"R:%d",RED_FRONT);lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"G:%d",GREEN_FRONT);lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"B:%d",BLUE_FRONT);lcd_putstr(lcd);

		lcd_gotoxy(6,0);sprintf(lcd,"BK");lcd_putstr(lcd);
		lcd_gotoxy(6,1);sprintf(lcd,"R:%d",RED_BACK);lcd_putstr(lcd);
		lcd_gotoxy(6,2);sprintf(lcd,"G:%d",GREEN_BACK);lcd_putstr(lcd);
		lcd_gotoxy(6,3);sprintf(lcd,"B:%d",BLUE_BACK);lcd_putstr(lcd);

		lcd_gotoxy(11,0);sprintf(lcd,"S:%d",STAT);lcd_putstr(lcd);
		delay_ms(100);
	}
}

void Display_Tracer_Data(void)
{
	int FRONT,FRONT2,MIDDLE,MIDDLE2,REAR,REAR2,TRC_STAT,FLAG;

	FLAG 		= TCS3200_SLV_BUF[0];
	FRONT 		= TCS3200_SLV_DATA[0];
	MIDDLE		= TCS3200_SLV_DATA[1];
	REAR        = TCS3200_SLV_DATA[2];
	TRACER_STAT	= TCS3200_SLV_DATA[3];

	lcd_display_clear();

	lcd_gotoxy(0,0);sprintf(lcd,"TRACER RAW VAL");lcd_putstr(lcd);

	lcd_gotoxy(0,1);sprintf(lcd,"F:%d",FRONT);lcd_putstr(lcd);
	lcd_gotoxy(7,1);sprintf(lcd,"M:%d",MIDDLE);lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"R:%d",REAR);lcd_putstr(lcd);
	lcd_gotoxy(0,3);sprintf(lcd,"T_STAT:%d",TRACER_STAT);lcd_putstr(lcd);
	lcd_gotoxy(9,3);sprintf(lcd,"FLG:%d",FLAG);lcd_putstr(lcd);
	delay_ms(100);
}

void Display_Raw_Data(void)
{
	int FRONT,BACK,STAT;

	FRONT 		= TCS3200_SLV_DATA[0];
	BACK		= TCS3200_SLV_DATA[1];
	STAT        = TCS3200_SLV_DATA[2];

	lcd_display_clear();

	lcd_gotoxy(0,0);sprintf(lcd,"TRACER RAW VAL");lcd_putstr(lcd);

	lcd_gotoxy(0,1);sprintf(lcd,"FRONT:%d",FRONT);lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"BACK:%d",BACK);lcd_putstr(lcd);
	lcd_gotoxy(0,3);sprintf(lcd,"STAT:%d",STAT);lcd_putstr(lcd);
	delay_ms(100);
}

/* func      : void Tracer_Calibration(void)
 * brief     : BW Photodiode Tracer Calibration Routine
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (MISSING NOTES)
 * Revised BY: Ver. 2 -> Ryan (Thursday, April 25th 2016
 * 					Tracer_Calibration New Routines
 * programmer's Note:
 */
void Tracer_Calibration(void)
{
	lcd_display_clear();
	lcd_gotoxy(1,0);sprintf(lcd,"TRACER");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"CALIBRATION");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"PRESS START");lcd_putstr(lcd);
	lcd_gotoxy(5,3);sprintf(lcd,"TO INITIATE");lcd_putstr(lcd);
	delay_ms(100);

	if(BW_BUTTON_CLICKED)
	{
		BW_Buzz(1);
		delay_ms(1000);

		while(BW_BUTTON_UNCLICKED)
		{
			TCS3200_Transmit(UART5, TRACER_CMD_SEND_RAW);
			Tracer_Cal_DisplayStat(1);
		}


		if(BW_BUTTON_CLICKED)
		{
			TCS3200_Transmit(UART5, TRACER_CALIBRATE_GRAY);
			BW_Buzz(2);
			delay_ms(500);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"GRAY DATA");lcd_putstr(lcd);
			lcd_gotoxy(7,1);sprintf(lcd,"ACQUIRED!");lcd_putstr(lcd);
			delay_ms(100);

		}
		delay_ms(1000);

		while(BW_BUTTON_UNCLICKED)
		{
			TCS3200_Transmit(UART5, TRACER_CMD_SEND_RAW);
			Tracer_Cal_DisplayStat(2);
		}


		if(BW_BUTTON_CLICKED)
		{
			TCS3200_Transmit(UART5, TRACER_CALIBRATE_WHITE);
			BW_Buzz(2);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"WHITE DATA");lcd_putstr(lcd);
			lcd_gotoxy(7,1);sprintf(lcd,"ACQUIRED!");lcd_putstr(lcd);
			delay_ms(100);

		}
		delay_ms(1000);

		while(BW_BUTTON_UNCLICKED)
		{
			TCS3200_Transmit(UART5, TRACER_CMD_SEND_RAW);
			Tracer_Cal_DisplayStat(3);
		}


		if(BW_BUTTON_CLICKED)
		{
			TCS3200_Transmit(UART5, TRACER_CALIBRATE_BLACK);
			BW_Buzz(2);
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"BLACK DATA");lcd_putstr(lcd);
			lcd_gotoxy(7,1);sprintf(lcd,"ACQUIRED!");lcd_putstr(lcd);
			delay_ms(100);

		}
		delay_ms(1000);


		BW_Buzz(2);
		BW_Buzz(2);
		TCS3200_Transmit(UART5, TRACER_CALIBRATE_GETRULE);
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"TRACER RULE");lcd_putstr(lcd);
		lcd_gotoxy(7,1);sprintf(lcd,"ACQUIRED!");lcd_putstr(lcd);
		delay_ms(100);

		delay_ms(1000);
	}
	else
	{

	}

}

/*
 * MODE:
 * 	1 -> CALIBRATE GRAY
 * 	2 -> CALIBRATE WHITE
 * 	3 -> CALIBRATE BLACK
 */
void Tracer_Cal_DisplayStat(int MODE)
{
	int FRONT,MIDDLE,REAR,TRC_THOLD_UP,TRC_THOLD_DOWN;

	FRONT		= TCS3200_SLV_DATA[1];
	MIDDLE		= TCS3200_SLV_DATA[2];
	REAR		= TCS3200_SLV_DATA[3];
	TRACER_STAT	= TCS3200_SLV_DATA[7];
	TRC_THOLD_UP 	= TCS3200_SLV_DATA[8];
	TRC_THOLD_DOWN 	= TCS3200_SLV_DATA[9];

	lcd_display_clear();
	switch(MODE)
	{
		case 1: {
					lcd_gotoxy(0,0);sprintf(lcd,"CALIBRATE GRAY");lcd_putstr(lcd);
				}break;
		case 2: {
					lcd_gotoxy(0,0);sprintf(lcd,"CALIBRATE WHITE");lcd_putstr(lcd);
				}break;
		case 3: {
					lcd_gotoxy(0,0);sprintf(lcd,"CALIBRATE BLACK");lcd_putstr(lcd);
				}break;
	}

	lcd_gotoxy(0,1);sprintf(lcd,"F:%d",FRONT);lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"M:%d",MIDDLE);lcd_putstr(lcd);
	lcd_gotoxy(0,3);sprintf(lcd,"R:%d",REAR);lcd_putstr(lcd);
	lcd_gotoxy(6,1);sprintf(lcd,"T_STAT:%d",TRACER_STAT);lcd_putstr(lcd);
	lcd_gotoxy(6,2);sprintf(lcd,"TH_UP:%d",TRC_THOLD_UP);lcd_putstr(lcd);
	lcd_gotoxy(6,3);sprintf(lcd,"TH_DW:%d",TRC_THOLD_DOWN);lcd_putstr(lcd);
	delay_ms(100);
}


void Hybrid_TCS3200Tracer_MainMenu(void)
{
	int MENU_VAR=0;

	while(BUTTON_IDLE)
	{
		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"BW  2021");lcd_putstr(lcd);
		lcd_gotoxy(1,1);sprintf(lcd,"TCS34725 TRACER");lcd_putstr(lcd);
		lcd_gotoxy(3,2);sprintf(lcd,"MAIN  MENU");lcd_putstr(lcd);
		lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
		TCS3200_Transmit(UART5, CMD_IDLE);
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
				BW_Buzz(1);
				while(BUTTON_B_CLICKED){};
				MENU_VAR--;
			}

			if(MENU_VAR>4) MENU_VAR=0;
			else if (MENU_VAR<0) MENU_VAR=4;

			switch(MENU_VAR)
			{
				case 0:
						{
							TCS3200_Transmit(UART5, TRACER_CMD_SEND_RGB);
							Display_RGB_Data(TRACER_BOTTOM);
						}break;
				case 1:
						{
							TCS3200_Transmit(UART5, TRACER_CMD_SEND_RAW);
							Display_Raw_Data();
						}break;
				case 2:
						{
							TCS3200_Transmit(UART5, HYBRID_CMD_SEND_THRESHOLD);
							Display_Threshold_Raw();
						}break;
				case 3:
						{
							TCS3200_Transmit(UART5, HYBRID_CMD_SEND_THRESHOLD);
							Display_Threshold_RGB();
						}break;
				case 4:
						{
							TCS3200_Transmit(UART5, CMD_GET_TRACER);
							Display_tracer_stat();
						}break;

			}

		}

	}

	else if(BUTTON_A_CLICKED)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"MENU_A");lcd_putstr(lcd);
		delay_ms(100);
	}

	else if(BUTTON_B_CLICKED)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"MENU_B");lcd_putstr(lcd);
		delay_ms(100);
	}
	else
	{

	}

}

void Display_Threshold_Raw(void)
{

	int TRACER_THRESHOLD_UP, TRACER_THRESHOLD_DOWN;

	TRACER_THRESHOLD_UP = (TCS3200_SLV_DATA[1]);
	TRACER_THRESHOLD_DOWN = (TCS3200_SLV_DATA[2]);

	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"THRESHOLD RAW");lcd_putstr(lcd);

	lcd_gotoxy(0,1);sprintf(lcd,"TRC_THld_U: %d",TRACER_THRESHOLD_UP);lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"TRC_THld_D: %d",TRACER_THRESHOLD_DOWN);lcd_putstr(lcd);

	delay_ms(100);
}

void Display_Threshold_RGB(void)
{

	int Threshold_F_UP, Threshold_F_LOW, Threshold_B_UP, Threshold_B_LOW;

	Threshold_F_UP = (TCS3200_SLV_DATA[3]);
	Threshold_F_LOW = (TCS3200_SLV_DATA[4]);
	Threshold_B_UP = (TCS3200_SLV_DATA[5]);
	Threshold_B_LOW = (TCS3200_SLV_DATA[6]);

	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"THRESHOLD RGB");lcd_putstr(lcd);

	lcd_gotoxy(0,1);sprintf(lcd,"F_U:%d",Threshold_F_UP);lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"F_L:%d",Threshold_F_LOW);lcd_putstr(lcd);
	lcd_gotoxy(8,1);sprintf(lcd,"B_U:%d",Threshold_B_UP);lcd_putstr(lcd);
	lcd_gotoxy(8,2);sprintf(lcd,"B_L:%d",Threshold_B_LOW);lcd_putstr(lcd);

	delay_ms(100);
}


void Display_tracer_stat()
{
	int TRACER_STATUS,FLAG;
	TRACER_STATUS = TCS3200_SLV_DATA[1];
	FLAG = TCS3200_SLV_BUF[0];
	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"DISPLAY TRACER");lcd_putstr(lcd);
	lcd_gotoxy(0,1);sprintf(lcd,"TRACER STAT = %d",TRACER_STATUS);lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FLAG = %d",FLAG);lcd_putstr(lcd);

	delay_ms(100);
}
