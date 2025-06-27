/*==============================================================================================
								   PROJECT BW 2017 Ver.1.0
								     BW ALGORITHM LIBRARY
===============================================================================================*/

#include "bw2017_algorithm.h"
#include "bw_global_var.h"
/*==============================================================================================
								   PRE-TRIAL FUNCTION
===============================================================================================*/


void BW_Settings_2019(void)
{
	USART3_PutChar(IN_ROOM_STAT);
	while(BW_BUTTON_CLICKED)
	{

	}
	int MENU_VAR=0;

		while(1)
		{
			lcd_display_clear();
/*
			lcd_gotoxy(0,1);sprintf(lcd,"KIRI:%d KANAN:%d",UV_VARIABLE,UV_VARIABLE2);lcd_putstr(lcd);*/
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

			if(MENU_VAR>10) MENU_VAR=0;
			else if (MENU_VAR<0) MENU_VAR=10;

			switch(MENU_VAR)
			{
				case 0:
						{
							lcd_gotoxy(0,0);sprintf(lcd,"CMPS12 CAL");lcd_putstr(lcd);
							if(BW_BUTTON_CLICKED)
							{
								while(BW_BUTTON_CLICKED);
								Save_CMPS12_DATA();
							}
						}break;

				case 1:
						{
							lcd_gotoxy(0,0);sprintf(lcd,"CAT CAL");lcd_putstr(lcd);
							if(BW_BUTTON_CLICKED)
							{
								while(BW_BUTTON_CLICKED);
								CAT_CALIBRATION();
							}

						}break;
				case 8:
						{
							lcd_gotoxy(0,0);sprintf(lcd,"EEPROM COPY");lcd_putstr(lcd);
							if(BW_BUTTON_CLICKED)
							{
								copy_EEPROM_data();
							}

						}break;
				case 9:
						{
							lcd_gotoxy(0,0);sprintf(lcd,"CO2 VALVE SET");lcd_putstr(lcd);
							if(BW_BUTTON_CLICKED)
							{
								BW_CO2_TEST();
							}
						}break;

				case 7:
						{
							lcd_gotoxy(0,0);sprintf(lcd,"TRACER COPY");lcd_putstr(lcd);
							if(BW_BUTTON_CLICKED)
							{
								BW_COPY_TRACER_DATA();
							}
						}break;
				case 6:
						{
							lcd_gotoxy(0,0);sprintf(lcd,"TRACER CAL");lcd_putstr(lcd);
							if(BW_BUTTON_CLICKED)
							{
								Tracer_Calibration();
							}
						}break;
				case 10:
						{
							lcd_gotoxy(0,0);sprintf(lcd,"TRACER LOAD");lcd_putstr(lcd);
							if(BW_BUTTON_CLICKED)
							{
								//BW_LOAD_TRACER_DATA();
							}
						}break;
				case 4:
						{
							lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
							if(BW_BUTTON_CLICKED)
							{
								BW_FlameFollowDemo_Dynamixel();
							}
						}break;

				case 2:
						{
							lcd_gotoxy(0,0);sprintf(lcd,"ROOM DETECTOR");lcd_putstr(lcd);
							if(BW_BUTTON_CLICKED)
							{
								RoomDetector(1);
								delay_ms(500);
							}
						}break;
				case 3:
						{
							lcd_gotoxy(0,0);sprintf(lcd,"TRACER VIEW");lcd_putstr(lcd);
							if(BW_BUTTON_CLICKED)
							{
								while(BUTTON_A_UNCLICKED)
								{
									TCS3200_Transmit(UART5, TRACER_CMD_SEND_RAW);
									Display_Tracer_Data();
								}
							}
						}break;
				case 5:
						{
							lcd_gotoxy(0,0);sprintf(lcd,"Flamesense");lcd_putstr(lcd);
							if(BW_BUTTON_CLICKED)
							{
								while(BUTTON_A_UNCLICKED)
								{
									Display_FlameSense();
								}
							}
						}break;
				case 11:
						{

						}break;

			}
			delay_ms(100);
		}
}


void Nav_Test_Menu(void)
{
	int MENU_VAR=0;

	if(BW_BUTTON_CLICKED)
	{
		delay_ms(300);
		while(1)
		{

			if(BUTTON_A_CLICKED)
			{
				while(BUTTON_A_CLICKED){};
				MENU_VAR++;
			}
			if(BUTTON_B_CLICKED)
			{
				while(BUTTON_B_CLICKED){};
				MENU_VAR--;
			}

			if(MENU_VAR>27) MENU_VAR=0;
			else if (MENU_VAR<0) MENU_VAR=27;

			switch(MENU_VAR)
			{
				case 0:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"1A to 2");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_1A_To_2();
						}break;

				case 1:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"1A to 3");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_1A_To_3();
						}break;
				case 2:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"1A to 4A");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_1A_To_4A();
						}break;
				case 3:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"1A to 4B");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_1A_To_4B();
						}break;

				case 4:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"1B to 2");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_1B_To_2();
						}break;
				case 5:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"1C to 2");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_1C_To_2();
						}break;
				case 6:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"1C to 3");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_1C_To_3();
						}break;
				case 7:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"1C to 4A");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_1C_To_4A();
						}break;
				case 8:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"1C to 4B");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_1C_To_4B();
						}break;
				case 9:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"2 to 1A");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_2_To_1A();
						}break;
				case 10:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"2 to 3");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_2_To_3();
						}break;
				case 11:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"2 to 4A");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_2_To_4A();
						}break;
				case 12:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"2 to 4B");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_2_To_4B();
						}break;
				case 13:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"1C to 4B");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_1C_To_4B();
						}break;
				case 14:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"2A to 1BC");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_2A_To_1BC();
						}break;
				case 15:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"2B to 1BC");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_2B_To_1BC();
						}break;
				case 16:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"3 to 1A");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_3_To_1A();
						}break;
				case 17:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"3 to 1BC");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_3_To_1BC();
						}break;
				case 18:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"3 to 2");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_3_To_2();
						}break;
				case 19:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"3 to 4A");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_3_To_4A();
						}break;
				case 20:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"3 to 4B");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_3_To_4B();
						}break;
				case 21:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"4A to 1A");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_4A_To_1A();
						}break;
				case 22:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"4A to 2");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_4A_To_2();
						}break;
				case 23:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"4A to 3");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_4A_To_3();
						}break;
				case 24:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"4B to 1A");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_4B_To_1A();
						}break;
				case 25:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"4B to 1BC");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_4B_To_1BC();
						}break;
				case 26:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"4B to 2");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_4B_To_2();
						}break;
				case 27:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"NAVIGASI MENU");lcd_putstr(lcd);
							lcd_gotoxy(0,2);sprintf(lcd,"ROUTE :");lcd_putstr(lcd);
							lcd_gotoxy(0,3);sprintf(lcd,"4B to 3");lcd_putstr(lcd);
							delay_ms(150);

							if(BW_BUTTON_CLICKED)Nav_4B_To_3();
						}break;

			}

		}

	}
}

/* func      : void BW_Home_Detection_2017(void)
 * brief     : Detecting Home and Positioning
 * param     : N/A
 * retval    : N/A
 * Ver       : 4
 * written By: Toni(Tuesday, December 12th)
 * Revised BY: Reyhan(Sunday, September 2nd, 2018)
 * programmer's Note:
 * Fixed wrong logic in condition statements, PAY ATTENTION TO OPERATORS PRECEDENCE !!
 */

void BW_Home_Detection_2021(void)
{
	int a = 0;
	//KONDISI ROBOT DI POJOK RUANG MENGHADAP KE TENGAH RUANGAN
	if  (	( (Ping[PING_LEFT]<=20) && ((Ping[PING_ASKEW_LEFT]<=25)&&(Ping[PING_REAR_LEFT]<=25)))
			||
			( (Ping[PING_RIGHT]<=20) && ((Ping[PING_ASKEW_RIGHT]<=25)&&(Ping[PING_REAR_RIGHT]<=25)))
			||
			(((Ping[PING_REAR_LEFT]<=25)||(Ping[PING_LEFT]<=20)) && ((Ping[PING_REAR_RIGHT]<=25)||(Ping[PING_RIGHT]<=20)) && (Ping[PING_REAR]<=25))
			||
			((Ping[PING_ASKEW_RIGHT]<=25) && (Ping[PING_ASKEW_LEFT]<=25))
			||
			((Ping[PING_UP_LEFT] <= 20 || Ping[PING_UP_RIGHT] <= 20) && Ping[PING_REAR] <= 25)	)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"POS : CORNER");lcd_putstr(lcd);
		delay_ms(50);

		HOME_POS=POJOK;

		if(Ping[PING_RIGHT]>20)
		{
			if((Ping[PING_REAR]<=20) && (Ping[PING_LEFT]<20) && (Ping[PING_FRONT]<20))
			{
				while(Ping[PING_FRONT]<20)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
				}

				Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

				if(((Ping[PING_ASKEW_LEFT]<=11) && (Ping[PING_REAR_LEFT]<=11)) && ((Ping[PING_LEFT]>11) && (Ping[PING_LEFT]<20)))
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
				}

					if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
					{
						Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
						{
							Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
							if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
							{
								Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
							}
						}
					}

				FOLLOW_FLAG=KANAN;
			}

			else if(Ping[PING_FRONT]<20)
			{
				while(Ping[PING_FRONT]<20)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
				}

				Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

				if(((Ping[PING_ASKEW_RIGHT]<=11) && (Ping[PING_REAR_RIGHT]<=11)) && ((Ping[PING_RIGHT]>11) && (Ping[PING_RIGHT]<20)))
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
				}

				if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
					{
						Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
						{
							Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						}
					}
				}

				FOLLOW_FLAG=KANAN;
			}
			else
			{
				if (Ping[PING_LEFT]<20)
				{
					while(Ping[PING_FRONT]>20)
					{
						Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
						a++;
						if(a>10)break;
					}
					while(Ping[PING_FRONT]<20)
					{
						Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
					}

					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

					if(((Ping[PING_ASKEW_RIGHT]<=11) && (Ping[PING_REAR_RIGHT]<=11)) && ((Ping[PING_RIGHT]>11) && (Ping[PING_RIGHT]<20)))
					{
						Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
					}

					if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
					{
						Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
						{
							Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
							if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
							{
								Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
							}
						}
					}
				}
				else
				{
					while(Ping[PING_RIGHT]>20)
					{
						Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
						a++;
						if(a>10)break;
					}

					Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

					if(((Ping[PING_ASKEW_RIGHT]<=11) && (Ping[PING_REAR_RIGHT]<=11)) && ((Ping[PING_RIGHT]>11) && (Ping[PING_RIGHT]<20)))
					{
						Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
					}

					if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
					{
						Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
						{
							Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
							if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
							{
								Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
							}
						}
					}

				}
				FOLLOW_FLAG=KANAN;
			}
		}
		else
		{
			if((((Ping[PING_ASKEW_RIGHT]<9) && (Ping[PING_RIGHT]<9) && (Ping[PING_REAR_RIGHT]<9)) && (Ping[PING_FRONT]<10) && ((Ping[PING_LEFT]<30) || (Ping[PING_ASKEW_LEFT]<30))) && (Ping[PING_REAR]>50))//(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED))
			{
				while(Ping[PING_RIGHT]<20)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
				}
				Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

				if(((Ping[PING_ASKEW_LEFT]<=11) && (Ping[PING_REAR_LEFT]<=11)) && ((Ping[PING_LEFT]>11) && (Ping[PING_LEFT]<20)))
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
				}

				if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
					{
						Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
						{
							Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						}
					}
				}
				FOLLOW_FLAG=KANAN;
			}
			else if((Ping[PING_RIGHT]<10) && (Ping[PING_LEFT]<10))
			{
				while(Ping[PING_LEFT]<20)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
				}
				while(Ping[PING_LEFT]>20)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
					a++;
					if(a>10)break;

				}

				Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

				if(((Ping[PING_ASKEW_RIGHT]<=11) && (Ping[PING_REAR_RIGHT]<=11)) && ((Ping[PING_RIGHT]>11) && (Ping[PING_RIGHT]<20)))
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
				}

				if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
					{
						Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
						{
							Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						}
					}
				}

				FOLLOW_FLAG=KANAN;
			}
			else
			{
				while(Ping[PING_FRONT]<20)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
				}

				Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

				if(((Ping[PING_ASKEW_RIGHT]<=11) && (Ping[PING_REAR_RIGHT]<=11)) && ((Ping[PING_RIGHT]>11) && (Ping[PING_RIGHT]<20)))
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
				}

				if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
					{
						Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
						{
							Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						}
					}
				}

				FOLLOW_FLAG=KANAN;
			}
		}
	}
	else
	{
		int CMPS_FLAG = 0;
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"POS : MIDDLE");lcd_putstr(lcd);
		delay_ms(50);

		HOME_POS=TENGAH;

		GetCMPS11_Angle8Bit();
		if((CMPS11_Angle >= (START_MIDDLE-5) && CMPS11_Angle <= (START_MIDDLE+5)))
		{
			COMPASS_INTERRUPT = 0;
			CMPS_FLAG = 0;
		}
		else
		{
			COMPASS_INTERRUPT = 1; // mengambil data kompas dari TIM4
			CMPS_FLAG = 1;
		}

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"POS : MIDDLE");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
			delay_ms(20);

			if(START_MID_MANUAL == 0)
			{
			//hanya akan masuk fungsi ketika posisi robot tidak sesuai dengan nilai START MIDLE
			if(CMPS_FLAG == 1)
			{
				if((CMPS11_Angle>(START_MIDDLE)))
				{
					while((CMPS11_Angle>(START_MIDDLE)))
					{
						if(CMPS11_Angle < START_MIDDLE)break;
						Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"POS : MIDDLE");lcd_putstr(lcd);
						lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
						if(CMPS11_Angle < START_MIDDLE)break;
					}

					if(CMPS11_Angle < START_MIDDLE)
					{
						while(CMPS11_Angle < START_MIDDLE)
						{
							if(CMPS11_Angle > START_MIDDLE)break;
							Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"CORRECTION 1");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
							if(CMPS11_Angle > START_MIDDLE)break;
						}
					}

					if(CMPS11_Angle > START_MIDDLE)
					{
						while(CMPS11_Angle > START_MIDDLE)
						{
							if(CMPS11_Angle == START_MIDDLE)break;
							Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"CORRECTION 2");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
							if(CMPS11_Angle == START_MIDDLE)break;
						}
					}
				}
				else if(((CMPS11_Angle<(START_MIDDLE))))
				{
					while((CMPS11_Angle<(START_MIDDLE))&&(CMPS11_Angle>R4A_THRESHOLD_MIDDLE))
					{
						Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"POS : MIDDLE");lcd_putstr(lcd);
						lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
					}

					if(CMPS11_Angle > START_MIDDLE)
					{
						while(CMPS11_Angle > START_MIDDLE)
						{
							if(CMPS11_Angle < START_MIDDLE)break;
							Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"CORECTION 1");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
							if(CMPS11_Angle < START_MIDDLE)break;
						}
					}

					if(CMPS11_Angle < START_MIDDLE)
					{
						while(CMPS11_Angle < START_MIDDLE)
						{
							if(CMPS11_Angle == START_MIDDLE)break;
							Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"CORECTION 2");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
							if(CMPS11_Angle == START_MIDDLE)break;
						}
					}
				}
			}

			COMPASS_INTERRUPT = 0;
			int foward = 0;

			while(Ping[PING_FRONT] > 17 && Ping[PING_UP_LEFT] > 17 && Ping[PING_UP_RIGHT] > 17)
			{
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
				foward++;
				if(foward >= 6)break;
			}
		}

		if(ROOM_TYPE == GRAY_ROOM)
		{
			Dynamx_Mov_Static_Interpolate(LEVEL6,IKCALC_ENABLE);
			delay_ms(50);
			Dynamx_MovBwd_Interpolate(4,LEVEL6,IKCALC_ENABLE);
			FOLLOW_FLAG=KANAN;
			ROOM1A_SP_EXIT_FLAG=FLAG_INACTIVE;
		}

		else
		{
			int geser=0;
			while(((Ping[PING_RIGHT]>13 && Ping[PING_ASKEW_RIGHT] > 12 && Ping[PING_REAR_RIGHT] > 14) && geser<4) && Ping[PING_RIGHT] < 35 && Ping[PING_ASKEW_RIGHT] < 35)
			{
				Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,100);
				geser++;
			}

			if((Ping[PING_ASKEW_RIGHT]>35) || (Ping[PING_REAR_RIGHT]>35))
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"TEMBOK JAUH");lcd_putstr(lcd);
				delay_ms(50);

				FOLLOW_FLAG=KANAN;
				ROOM1A_SP_EXIT_FLAG=FLAG_INACTIVE;
			}
			else
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"TEMBOK DEKAT");lcd_putstr(lcd);
				delay_ms(50);

				FOLLOW_FLAG=KANAN;
				ROOM1A_SP_EXIT_FLAG=FLAG_INACTIVE;
			}
		}
	}

}

void BW_Home_Start_Left(void)
{
	if  (	( (Ping[PING_RIGHT]<=20) && ((Ping[PING_ASKEW_RIGHT]<=25)&&(Ping[PING_REAR_RIGHT]<=25)))
			||
			( (Ping[PING_LEFT]<=20) && ((Ping[PING_ASKEW_LEFT]<=25)&&(Ping[PING_REAR_LEFT]<=25)))
			||
			(((Ping[PING_REAR_RIGHT]<=25)||(Ping[PING_RIGHT]<=20)) && ((Ping[PING_REAR_LEFT]<=25)
			||
			(Ping[PING_LEFT]<=20)) && (Ping[PING_REAR]<=25))
			||
			((Ping[PING_ASKEW_LEFT]<=25) && (Ping[PING_ASKEW_RIGHT]<=25))
			||
			((Ping[PING_UP_RIGHT] <= 20 || Ping[PING_UP_LEFT] <= 20) && Ping[PING_REAR] <= 25)	)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"POS : CORNER");lcd_putstr(lcd);
		delay_ms(50);

		HOME_POS=POJOK;

		if(Ping[PING_LEFT]>20)
		{
			if((Ping[PING_REAR]<=20) && (Ping[PING_RIGHT]<20) && (Ping[PING_FRONT]<20))
			{
				while(Ping[PING_FRONT]<20)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
				}

				Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

				if(((Ping[PING_ASKEW_RIGHT]<=11) && (Ping[PING_REAR_RIGHT]<=11)) && ((Ping[PING_RIGHT]>11) && (Ping[PING_RIGHT]<20)))
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
				}

					if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
					{
						Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

						if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
						{
							Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

							if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
							{
								Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
							}
						}
					}

				FOLLOW_FLAG=KIRI;
			}


			else if(Ping[PING_FRONT]<20)
			{
				while(Ping[PING_FRONT]<20)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
				}

				Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

				if(((Ping[PING_ASKEW_LEFT]<=11) && (Ping[PING_REAR_LEFT]<=11)) && ((Ping[PING_LEFT]>11) && (Ping[PING_LEFT]<20)))
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
				}

				if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
					{
						Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
						{
							Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						}
					}
				}
				FOLLOW_FLAG=KIRI;
			}

			else
			{
				if (Ping[PING_RIGHT]<20)
				{
					while(Ping[PING_FRONT]>20)
					{
						Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
						a++;
						if(a>10)break;
					}
					while(Ping[PING_FRONT]<20)
					{
						Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
					}

					Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

					if(((Ping[PING_ASKEW_LEFT]<=11) && (Ping[PING_REAR_LEFT]<=11)) && ((Ping[PING_LEFT]>11) && (Ping[PING_LEFT]<20)))
					{
						Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
					}

					if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
					{
						Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
						{
							Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
							if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
							{
								Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
							}
						}
					}
				}

				else
				{
					while(Ping[PING_LEFT]>20)
					{
						Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
						a++;
						if(a>10)break;
					}

					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

					if(((Ping[PING_ASKEW_LEFT]<=11) && (Ping[PING_REAR_LEFT]<=11)) && ((Ping[PING_LEFT]>11) && (Ping[PING_LEFT]<20)))
					{
						Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
					}

					if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
					{
						Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
						{
							Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
							if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
							{
								Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
							}
						}
					}
				}
				FOLLOW_FLAG=KIRI;
			}
		}


		else
		{
			if((((Ping[PING_ASKEW_LEFT]<9) && (Ping[PING_LEFT]<9) && (Ping[PING_REAR_LEFT]<9)) && (Ping[PING_FRONT]<10) && ((Ping[PING_RIGHT]<30) || (Ping[PING_ASKEW_RIGHT]<30))) && (Ping[PING_REAR]>50))
			{
				while(Ping[PING_LEFT]<20)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
				}
				Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

				if(((Ping[PING_ASKEW_RIGHT]<=11) && (Ping[PING_REAR_RIGHT]<=11)) && ((Ping[PING_RIGHT]>11) && (Ping[PING_RIGHT]<20)))
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
				}

				if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
					{
						Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT])
						{
							Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						}
					}
				}
				FOLLOW_FLAG=KIRI;
			}


			else if((Ping[PING_LEFT]<10) && (Ping[PING_RIGHT]<10))
			{
				while(Ping[PING_RIGHT]<20)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
				}

				while(Ping[PING_RIGHT]>20)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
					a++;
					if(a>10)break;
				}

				Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

				if(((Ping[PING_ASKEW_LEFT]<=11) && (Ping[PING_REAR_LEFT]<=11)) && ((Ping[PING_LEFT]>11) && (Ping[PING_LEFT]<20)))
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
				}

				if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
					{
						Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
						{
							Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						}
					}
				}

				FOLLOW_FLAG=KIRI;
			}


			else
			{
				while(Ping[PING_FRONT]<20)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
				}

				Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

				if(((Ping[PING_ASKEW_LEFT]<=11) && (Ping[PING_REAR_LEFT]<=11)) && ((Ping[PING_LEFT]>11) && (Ping[PING_LEFT]<20)))
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
				}

				if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
					{
						Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT])
						{
							Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						}
					}
				}
				FOLLOW_FLAG=KIRI;
			}
		}
	}

}

void BW_Home_Start_Right(void)
{
	if  (	( (Ping[PING_LEFT]<=20) && ((Ping[PING_ASKEW_LEFT]<=25)&&(Ping[PING_REAR_LEFT]<=25)))
			||
			( (Ping[PING_RIGHT]<=20) && ((Ping[PING_ASKEW_RIGHT]<=25)&&(Ping[PING_REAR_RIGHT]<=25)))
			||
			(((Ping[PING_REAR_LEFT]<=25)||(Ping[PING_LEFT]<=20)) && ((Ping[PING_REAR_RIGHT]<=25)||(Ping[PING_RIGHT]<=20)) && (Ping[PING_REAR]<=25))
			||
			((Ping[PING_ASKEW_RIGHT]<=25) && (Ping[PING_ASKEW_LEFT]<=25))
			||
			((Ping[PING_UP_LEFT] <= 20 || Ping[PING_UP_RIGHT] <= 20) && Ping[PING_REAR] <= 25)	)
	{

		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"POS : CORNER");lcd_putstr(lcd);
		delay_ms(50);

		HOME_POS=POJOK;

		if(Ping[PING_RIGHT]>20)
		{
			if((Ping[PING_REAR]<=20) && (Ping[PING_LEFT]<20) && (Ping[PING_FRONT]<20))
			{
				while(Ping[PING_FRONT]<20)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
				}

				Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

				if(((Ping[PING_ASKEW_LEFT]<=11) && (Ping[PING_REAR_LEFT]<=11)) && ((Ping[PING_LEFT]>11) && (Ping[PING_LEFT]<20)))
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
				}

					if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT]+1)
					{
						Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT]+1)
						{
							Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
							if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT]+1)
							{
								Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
							}
						}
					}
				FOLLOW_FLAG=KANAN;
			}


			else if(Ping[PING_FRONT]<20)
			{
				while(Ping[PING_FRONT]<20)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
				}

				Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

				if(((Ping[PING_ASKEW_RIGHT]<=11) && (Ping[PING_REAR_RIGHT]<=11)) && ((Ping[PING_RIGHT]>11) && (Ping[PING_RIGHT]<20)))
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
				}

				if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT]+1)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT]+1)
					{
						Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT]+1)
						{
							Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						}
					}
				}
				FOLLOW_FLAG=KANAN;
			}


			else
			{
				if (Ping[PING_LEFT]<20)
				{

					while(Ping[PING_FRONT]>20)
					{
						Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
						a++;
						if(a>10)break;
					}
					while(Ping[PING_FRONT]<20)
					{
						Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
					}

					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

					if(((Ping[PING_ASKEW_RIGHT]<=11) && (Ping[PING_REAR_RIGHT]<=11)) && ((Ping[PING_RIGHT]>11) && (Ping[PING_RIGHT]<20)))
					{
						Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
					}

					if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT]+1)
					{
						Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT]+1)
						{
							Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
							if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT]+1)
							{
								Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
							}
						}
					}
				}
				else
				{
					while(Ping[PING_RIGHT]>20)
					{
						Dynamx_Rot_Right_Interpolate(200,HEXSTEP_MED,IKCALC_DISABLE);
						a++;
						if(a>10)break;
					}

					Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

					if(((Ping[PING_ASKEW_RIGHT]<=11) && (Ping[PING_REAR_RIGHT]<=11)) && ((Ping[PING_RIGHT]>11) && (Ping[PING_RIGHT]<20)))
					{
						Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
					}

					if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT]+1)
					{
						Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT]+1)
						{
							Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
							if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT]+1)
							{
								Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
							}
						}
					}
				}
				FOLLOW_FLAG=KANAN;
			}
		}


		else
		{
			if((((Ping[PING_ASKEW_RIGHT]<9) && (Ping[PING_RIGHT]<9) && (Ping[PING_REAR_RIGHT]<9)) && (Ping[PING_FRONT]<10) && ((Ping[PING_LEFT]<30) || (Ping[PING_ASKEW_LEFT]<30))) && (Ping[PING_REAR]>50))//(INFRARED[IR_UPPER_RIGHT]==IR_NOT_DETECTED))
			{
				while(Ping[PING_RIGHT]<20)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
				}
				Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

				if(((Ping[PING_ASKEW_LEFT]<=11) && (Ping[PING_REAR_LEFT]<=11)) && ((Ping[PING_LEFT]>11) && (Ping[PING_LEFT]<20)))
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
				}

				if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT]+1)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT]+1)
					{
						Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if(Ping[PING_ASKEW_LEFT]<Ping[PING_REAR_LEFT]+1)
						{
							Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						}
					}
				}
				FOLLOW_FLAG=KANAN;
			}

			else if((Ping[PING_RIGHT]<10) && (Ping[PING_LEFT]<10))
			{
				while(Ping[PING_LEFT]<20)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
				}

				while(Ping[PING_LEFT]>20)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
					a++;
					if(a>10)break;
				}

				Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

				if(((Ping[PING_ASKEW_RIGHT]<=11) && (Ping[PING_REAR_RIGHT]<=11)) && ((Ping[PING_RIGHT]>11) && (Ping[PING_RIGHT]<20)))
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
				}

				if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT]+1)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT]+1)
					{
						Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT]+1)
						{
							Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						}
					}
				}
				FOLLOW_FLAG=KANAN;
			}

			else
			{
				while(Ping[PING_FRONT]<20)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
				}

//				Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

				if(((Ping[PING_ASKEW_RIGHT]<=11) && (Ping[PING_REAR_RIGHT]<=11)) && ((Ping[PING_RIGHT]>11) && (Ping[PING_RIGHT]<20)))
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
				}

				if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT]+1)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT]+1)
					{
						Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if(Ping[PING_ASKEW_RIGHT]<Ping[PING_REAR_RIGHT]+1)
						{
							Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						}
					}
				}
				FOLLOW_FLAG=KANAN;
			}
		}
	}

}

void Home_HallwaySC_Detector(void)
{
	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	delay_ms(50);
	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	delay_ms(50);

	if	((TCS3200_SLV_DATA[0]==COLOUR_GRAY) && BW_LOCATION == LOCATION_CORRIDOR)
	{
			ROOM[1]= HALLWAY_SC;
			ROOM_COUNTER++;

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"HALLWAY SC");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"DETECTED");lcd_putstr(lcd);
			delay_ms(100);
	}

	else
	{
		lcd_gotoxy(0,0);sprintf(lcd,"HALLWAY SC");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"NOT DETECTED");lcd_putstr(lcd);
	}
}

/* 	  CAT POSSIBLE LOCATION
 * ___________________________
 *  |                         |
 *  |	  xxxx				  |
 * 	|    _____                |
 * 	|    |              |     |
 * 	|    |              | xxxx |
 * 	|    |              |     |
 * 	|    |              |     |
 *__| 	 |______________|     |
 * 	                          |
 *			xxxx              |
 *____________________________|
 *
 *
 *		Ver.3: Ryan (Sunday, April 23rd, 2017)
 *				Added parameter and simplifying the nested if-else
 */

void Cat_Avoider(void)
{
//	if((SHIFT_ALGORITHM_FLAG == SHIFT_ALGORITHM_ACTIVE) && (CAT_FLAG == CAT_NOT_DETECTED))
//	{
//		if(BW_LOCATION[0]==LOCATION_CORRIDOR)
//		{
//			if(ROOM4A_CAT_AVOIDER == ROOM4A_CAT_AVOIDER_ACTIVE)
//			{
//				if	 ( 	(SHARP[IR_FRONT] <11)
//						&&
//						(((Ping[PING_ASKEW_LEFT]>10)
//						&&
//						(Ping[PING_ASKEW_LEFT]<85))
//						||
//						((Ping[PING_ASKEW_RIGHT]>10)
//						&&
//						(Ping[PING_ASKEW_RIGHT]<85)))
//						&&
//						(Ping[PING_FRONT]>45)) /*  && Ping[PING_UP_LEFT] > 45 && Ping[PING_UP_RIGHT] >45))*/
//				{
//					lcd_display_clear();
//					lcd_gotoxy(3,0);sprintf(lcd,"CAT DETECTOR");lcd_putstr(lcd);
//					lcd_gotoxy(3,1);sprintf(lcd,"ACTIVATED");lcd_putstr(lcd);
//					CAT_FLAG = CAT_DETECTED;
//					Dynamx_Mov_Static_Interpolate(LEVEL5,IKCALC_ENABLE);
//					delay_ms(50);
//					Dynamx_MovBwd_Interpolate(4,LEVEL5,IKCALC_ENABLE);
//					ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_INACTIVE;
//				}
//			}
//			else
//			{
//				if	 ( 	(SHARP[IR_FRONT] <11)
//						&&
//						(((Ping[PING_ASKEW_LEFT]>10)
//						&&
//						(Ping[PING_ASKEW_LEFT]<85))
//						||
//						((Ping[PING_ASKEW_RIGHT]>10)
//						&&
//						(Ping[PING_ASKEW_RIGHT]<85)))
//						&&
//						(Ping[PING_FRONT]>45)) /* && Ping[PING_UP_LEFT] > 45 && Ping[PING_UP_RIGHT] >45))*/
//				{
//					lcd_display_clear();
//					lcd_gotoxy(3,0);sprintf(lcd,"CAT DETECTOR");lcd_putstr(lcd);
//					lcd_gotoxy(3,1);sprintf(lcd,"ACTIVATED");lcd_putstr(lcd);
//					CAT_FLAG = CAT_DETECTED;
//				}
//			}
//		}
//	}
//	else if((SHIFT_ALGORITHM_FLAG == SHIFT_ALGORITHM_ACTIVE) && (CAT_FLAG == CAT_DETECTED))
//	{
//		if(ROOM4A_CAT_AVOIDER == ROOM4A_CAT_AVOIDER_ACTIVE)
//		{
//			lcd_display_clear();
//			lcd_gotoxy(3,0);sprintf(lcd,"CAT DETECTOR");lcd_putstr(lcd);
//			lcd_gotoxy(3,1);sprintf(lcd,"ACTIVATED");lcd_putstr(lcd);
//			CAT_FLAG = CAT_DETECTED;
//			Dynamx_Mov_Static_Interpolate(LEVEL5,IKCALC_ENABLE);
//			delay_ms(50);
//			Dynamx_MovBwd_Interpolate(4,LEVEL5,IKCALC_ENABLE);
//			ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_INACTIVE;
//		}
//		else if(ROOM4A_CAT_AVOIDER == ROOM4A_CAT_AVOIDER_INACTIVE)
//		{
//			CAT_FLAG = CAT_DETECTED;
//		}
//	}
}


void Stairs_Detector(void)
{
	if(BW_LOCATION[0] == LOCATION_CORRIDOR && STAIRS_FLAG == STAIRS_NOT_DETECTED && STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
	{
		if(Ping[PING_FRONT] >= 30 && SHARP[IR_STAIRS] <= STAIRS_MIN_RANGE)
		{
			STAIRS_FLAG = STAIRS_DETECTED;
		}
	}

}

/*==============================================================================================
							NEW FEATURES FROM BW Ver.1.0
===============================================================================================*/

void FlameSense_PID_Init(void)
{
	//BW PID WALL FOLLOWING RIGHT RULE
	PID_FLAME.P[0]=0;
	PID_FLAME.P[1]=0;
	PID_FLAME.P[2]=0;
	PID_FLAME.I[0]=0;
	PID_FLAME.I[1]=0;
	PID_FLAME.I[2]=0;
	PID_FLAME.D[0]=0;
	PID_FLAME.D[1]=0;
	PID_FLAME.D[2]=0;

	PID_FLAME.Kp=2;
	PID_FLAME.Ki=0;
	PID_FLAME.Kd=0;

	PID_FLAME.Ts=1;

//	PID_FLAME.set_point_upper=3;
//	PID_FLAME.set_point_lower=3;
	PID_FLAME.set_point=3;

	PID_FLAME.error[0]=0;
	PID_FLAME.error[1]=0;
	PID_FLAME.error[2]=0;
	PID_FLAME.pid_value[0]=0;
	PID_FLAME.pid_value[1]=0;
	PID_FLAME.pid_value[2]=0;
}


void RoomTypeDetector(void)
{
	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	delay_ms(100);
	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	delay_ms(100);

	if	(TCS3200_SLV_DATA[1]==COLOUR_GRAY)
	{
		ROOM_TYPE= GRAY_ROOM;
		ROOM_MOVEMENT = 1;

		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
		lcd_gotoxy(2,3);sprintf(lcd,"GRAY ROOM");lcd_putstr(lcd);
		delay_ms(50);
	}

	else if	(TCS3200_SLV_DATA[1]==COLOUR_BLACK)
	{
		ROOM_TYPE= NORMAL_ROOM;
		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
		lcd_gotoxy(2,3);sprintf(lcd,"NORMAL ROOM");lcd_putstr(lcd);
		delay_ms(50);
	}

	else
	{
		ROOM_TYPE= NORMAL_ROOM;
		BW_PID_Init_Room();

		if(FOLLOW_FLAG==KIRI)
		{
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
			lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
			lcd_gotoxy(2,3);sprintf(lcd,"ID FAILED LEFT");lcd_putstr(lcd);
			delay_ms(50);

			if(Ping[PING_ASKEW_LEFT]>20)
			{
				Dynamx_Rot_Left_Interpolate(LEVEL7,HEXSTEP_MED, IKCALC_DISABLE);
			}

			BW_FollowCounter_Left(1);
		}

		else
		{
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
			lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
			lcd_gotoxy(2,3);sprintf(lcd,"ID FAILED RIGHT");lcd_putstr(lcd);
			delay_ms(50);

			if(Ping[PING_ASKEW_RIGHT]>20)
			{
				Dynamx_Rot_Right_Interpolate(LEVEL7,HEXSTEP_MED, IKCALC_DISABLE);
			}

			BW_FollowCounter_Right(1);

		}
		RoomTypeDetector();
	}
}

void RoomDetector(int ROOM_COUNTER)
{
	if(Ping[PING_FRONT] <= 40)
	{
		if(Ping[PING_UP_LEFT] <= 30 && Ping[PING_UP_RIGHT] >= 45)
		{
			Dynamx_Rot_Left_Interpolate(LEVEL4, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
			if(Ping[PING_UP_LEFT]+4 < Ping[PING_UP_RIGHT])
			{
				Dynamx_Rot_Left_Interpolate(LEVEL4, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
				if(Ping[PING_UP_LEFT]+4 < Ping[PING_UP_RIGHT])
				{
					Dynamx_Rot_Left_Interpolate(LEVEL4, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
					if(Ping[PING_UP_LEFT]+4 < Ping[PING_UP_RIGHT])
					{
						Dynamx_Rot_Left_Interpolate(LEVEL4, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
					}
				}
			}
		}

		else if(Ping[PING_UP_RIGHT] <= 30 && Ping[PING_UP_LEFT] >= 45)
		{
			Dynamx_Rot_Right_Interpolate(LEVEL4, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
			if(Ping[PING_UP_RIGHT]+4 < Ping[PING_UP_LEFT])
			{
				Dynamx_Rot_Right_Interpolate(LEVEL4, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
				if(Ping[PING_UP_RIGHT]+4 < Ping[PING_UP_LEFT])
				{
					Dynamx_Rot_Right_Interpolate(LEVEL4, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
					if(Ping[PING_UP_LEFT]+4 < Ping[PING_UP_RIGHT])
					{
						Dynamx_Rot_Left_Interpolate(LEVEL4, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
					}
				}
			}
		}

		if(Ping[PING_UP_LEFT] <= 30 && Ping[PING_UP_RIGHT] >= 45)
		{
			Dynamx_Rot_Left_Interpolate(LEVEL4, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
			if(Ping[PING_UP_LEFT]+4 < Ping[PING_UP_RIGHT])
			{
				Dynamx_Rot_Left_Interpolate(LEVEL4, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
				if(Ping[PING_UP_LEFT]+4 < Ping[PING_UP_RIGHT])
				{
					Dynamx_Rot_Left_Interpolate(LEVEL4, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
					if(Ping[PING_UP_LEFT]+4 < Ping[PING_UP_RIGHT])
					{
						Dynamx_Rot_Left_Interpolate(LEVEL4, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
					}
				}
			}
		}

		else if(Ping[PING_UP_RIGHT] <= 30 && Ping[PING_UP_LEFT] >= 45)
		{
			Dynamx_Rot_Right_Interpolate(LEVEL4, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
			if(Ping[PING_UP_RIGHT]+4 < Ping[PING_UP_LEFT])
			{
				Dynamx_Rot_Right_Interpolate(LEVEL4, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
				if(Ping[PING_UP_RIGHT]+4 < Ping[PING_UP_LEFT])
				{
					Dynamx_Rot_Right_Interpolate(LEVEL4, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
					if(Ping[PING_UP_LEFT]+4 < Ping[PING_UP_RIGHT])
					{
						Dynamx_Rot_Left_Interpolate(LEVEL4, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
					}
				}
			}
		}
	}

	else if(Ping[PING_FRONT] > 40 && Ping[PING_UP_RIGHT] > 30 && Ping[PING_UP_LEFT] > 30 && ROOM_TYPE != GRAY_ROOM)
	{
		if(Ping[PING_ASKEW_RIGHT] < 10)
		{
			if(Ping[PING_ASKEW_RIGHT]+4 < Ping[PING_REAR_RIGHT])
			{
				Dynamx_Rot_Left_Interpolate(LEVEL4, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
				if(Ping[PING_ASKEW_RIGHT]+4 < Ping[PING_REAR_RIGHT])
				{
					Dynamx_Rot_Left_Interpolate(LEVEL4, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
					if(Ping[PING_ASKEW_RIGHT]+4 < Ping[PING_REAR_RIGHT])
					{
						Dynamx_Rot_Left_Interpolate(LEVEL4, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
					}
				}
			}
		}
		Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL4);
	}

	ROOM[ROOM_COUNTER] = 99;
	if((Ping[PING_FRONT]>=45 && ((Ping[PING_UP_LEFT] >= 45) || (Ping[PING_UP_RIGHT] >= 45))))
	{
		if( ((Ping[PING_LEFT]<=50) && (Ping[PING_ASKEW_LEFT]<=30) && (Ping[PING_REAR_LEFT]<=30)) && (Ping[PING_RIGHT] > 20) && (Ping[PING_ASKEW_RIGHT] > 20) && Ping[PING_REAR] >= 45)
		{
			ROOM[ROOM_COUNTER]= ROOM_1C;
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"ROOM 1 ");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"DOOR C STD ");lcd_putstr(lcd);
			delay_ms(100);

			BW_COMPASS_CORRECTION(ROOM_1B_DETECT);
			if(ROOM[ROOM_COUNTER] == ROOM_1B && ROOM_2_1BC_MANUAL == 0)
			{
				ROOM[ROOM_COUNTER]= ROOM_1C;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"ROOM 1 ");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"DOOR C STD ");lcd_putstr(lcd);
				delay_ms(100);
			}
			else if(ROOM[ROOM_COUNTER] != ROOM_1B && ROOM_2_1BC_MANUAL == 0)
			{
				BW_COMPASS_CORRECTION(ROOM_4B_DETECT);
				if(ROOM[ROOM_COUNTER] == ROOM_4B)
				{
					ROOM[ROOM_COUNTER]= ROOM_4B;
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"ROOM 4AB ");lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"DOOR B CMPS");lcd_putstr(lcd);
					delay_ms(100);
				}
				else
				{
					ROOM[ROOM_COUNTER] = ROOM_4A;
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"ROOM 4AB ");lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"DOOR A CMPS");lcd_putstr(lcd);
					delay_ms(100);
				}
			}
		}
		else
		{
			GetCMPS11_Angle8Bit();	// INTERFERENSI PING KANAN
			if(ROOM_TYPE==GRAY_ROOM)
			{
				ROOM[ROOM_COUNTER]= ROOM_2B;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"ROOM 2");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"DOOR B ");lcd_putstr(lcd);
				delay_ms(100);
			}

			else if( (Ping[PING_RIGHT]>=50 && Ping[PING_REAR] >= 50)  )
			{
				ROOM[ROOM_COUNTER]= ROOM_1C;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"ROOM 1");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"DOOR C ALT");lcd_putstr(lcd);
				delay_ms(100);
			}
			else if(ROOM_2_1BC_MANUAL == 0)
			{
				BW_COMPASS_CORRECTION(ROOM_1C_DETECT);
				if(ROOM[ROOM_COUNTER] != ROOM_1C)
				{
					ROOM[ROOM_COUNTER]= ROOM_1A;
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"ROOM 1");lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"DOOR A CMPS");lcd_putstr(lcd);
					delay_ms(100);
				}
				else
				{
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"ROOM 1");lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"DOOR C CMPS");lcd_putstr(lcd);
					delay_ms(100);
				}
			}
			else if(Ping[PING_LEFT] < 25 && Ping[PING_RIGHT] > 50)
			{
				ROOM[ROOM_COUNTER]= ROOM_1C;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"ROOM 1");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"DOOR C ALT");lcd_putstr(lcd);
				delay_ms(100);
			}
			else
			{
				ROOM[ROOM_COUNTER]= ROOM_1A;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"ROOM 1");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"DOOR A STD");lcd_putstr(lcd);
				delay_ms(100);
			}

		}
	}
	else
	{
		if( (Ping[PING_RIGHT]<30) && (Ping[PING_ASKEW_RIGHT]<40) )
		{
			if(ROOM_TYPE==GRAY_ROOM)
			{
				ROOM[ROOM_COUNTER]= ROOM_2A;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"ROOM 2");
				lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"DOOR A ");lcd_putstr(lcd);
				delay_ms(100);
			}
			else
			{
				BW_COMPASS_CORRECTION(ROOM_4A_DETECT);
				if(ROOM[ROOM_COUNTER] != ROOM_4A)
				{
					ROOM[ROOM_COUNTER]= ROOM_3;
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"ROOM 3");lcd_putstr(lcd);
				}
				else
				{
					ROOM[ROOM_COUNTER] = ROOM_1A; // interferensi kucing B pintu 1A
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"ROOM 1A ALT");lcd_putstr(lcd);
				}
				delay_ms(100);
			}

		}

		else if( ((Ping[PING_LEFT]>=30)||Ping[PING_ASKEW_LEFT]>=30) && (Ping[PING_RIGHT]>=40) )
		{

			if( ( (Ping[PING_LEFT]>=30) && (Ping[PING_LEFT]<80) && (Ping[PING_ASKEW_LEFT]>=30) && (Ping[PING_ASKEW_LEFT]<80) ) && ( (Ping[PING_ASKEW_RIGHT]>=128) || (Ping[PING_RIGHT]>=128) ))
			{
				ROOM[ROOM_COUNTER]= ROOM_1B;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"ROOM 1 ");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"DOOR B ");lcd_putstr(lcd);
				delay_ms(100);

				if(Ping[PING_REAR]<=40)
				{
					if(ROOM_2_1BC_MANUAL == 0)
					{
						BW_COMPASS_CORRECTION(ROOM_1B_DETECT);
						if(ROOM[ROOM_COUNTER] != ROOM_1B)
						{
							ROOM[ROOM_COUNTER]= ROOM_4B;
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"ROOM 4 ");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"DOOR B ");lcd_putstr(lcd);
							delay_ms(100);
						}
						else
						{
							lcd_gotoxy(0,0);sprintf(lcd,"ROOM 1 ");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"DOOR B CMPS ");lcd_putstr(lcd);
							delay_ms(100);
						}
					}
				}
				else
				{
					ROOM[ROOM_COUNTER]= ROOM_1B;
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"ROOM 1 ");lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"DOOR B ");lcd_putstr(lcd);
					delay_ms(100);
				}
			}

			else
			{
				if( ( (Ping[PING_LEFT]>=40) && (Ping[PING_LEFT]<80) ) && (Ping[PING_RIGHT]>=80) && (Ping[PING_ASKEW_RIGHT]>=80))
				{
					ROOM[ROOM_COUNTER]= ROOM_1B;
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"ROOM 1 ");lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"DOOR B ");lcd_putstr(lcd);
					delay_ms(100);

					if(Ping[PING_REAR]<=40)
					{
						if(ROOM_2_1BC_MANUAL == 0)
						{
							BW_COMPASS_CORRECTION(ROOM_1B_DETECT);
							if(ROOM[ROOM_COUNTER] != ROOM_1B)
							{
								ROOM[ROOM_COUNTER]= ROOM_4B;
								lcd_display_clear();
								lcd_gotoxy(0,0);sprintf(lcd,"ROOM 4 ");lcd_putstr(lcd);
								lcd_gotoxy(0,1);sprintf(lcd,"DOOR B ");lcd_putstr(lcd);
								delay_ms(100);
							}
							else
							{
								lcd_display_clear();
								lcd_gotoxy(0,0);sprintf(lcd,"ROOM 1 ");lcd_putstr(lcd);
								lcd_gotoxy(0,1);sprintf(lcd,"DOOR B CMPS ");lcd_putstr(lcd);
								delay_ms(100);
							}
						}
					}
					else
					{
						ROOM[ROOM_COUNTER]= ROOM_1B;
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"ROOM 1 ");lcd_putstr(lcd);
						lcd_gotoxy(0,1);sprintf(lcd,"DOOR B ");lcd_putstr(lcd);
						delay_ms(100);
					}
				}

				else
				{
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"ROOM 4AB ");lcd_putstr(lcd);
					delay_ms(100);

					while(Ping[PING_FRONT]<=10)
					{
						Dynamx_MovBwd_Interpolate(3,LEVEL3,IKCALC_ENABLE);
					}

					if(Ping[PING_REAR]>=62)
					{
						ROOM[ROOM_COUNTER]= ROOM_1B;
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"ROOM 1");lcd_putstr(lcd);
						lcd_gotoxy(0,1);sprintf(lcd,"DOOR B");lcd_putstr(lcd);
						delay_ms(100);
					}

					else
					{
						BW_Buzz(1);
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"ROOM 4AB ");lcd_putstr(lcd);
						delay_ms(100);

						if(ROOM_4A_MANUAL == 0)
						{
						BW_COMPASS_CORRECTION(ROOM_4B_DETECT);

						if(ROOM[ROOM_COUNTER] != ROOM_4B)
						{
							ROOM[ROOM_COUNTER]= ROOM_4A;
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"ROOM 4 ");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"DOOR A 1");lcd_putstr(lcd);
							delay_ms(100);


						}
						else
						{
							BW_COMPASS_CORRECTION(ROOM_4A_DETECT);
							if(ROOM[ROOM_COUNTER] != ROOM_4A)
							{
								ROOM[ROOM_COUNTER]= ROOM_4B;
								lcd_display_clear();
								lcd_gotoxy(0,0);sprintf(lcd,"ROOM 4 ");lcd_putstr(lcd);
								lcd_gotoxy(0,1);sprintf(lcd,"DOOR B 1");lcd_putstr(lcd);
								delay_ms(100);
							}
							else
							{
								ROOM[ROOM_COUNTER]= ROOM_4A;
								lcd_display_clear();
								lcd_gotoxy(0,0);sprintf(lcd,"ROOM 4 ");lcd_putstr(lcd);
								lcd_gotoxy(0,1);sprintf(lcd,"DOOR A 2");lcd_putstr(lcd);
								delay_ms(100);
							}
						}
						}

						else
						{
							if((Ping[PING_LEFT] >= 30 && Ping[PING_LEFT] <= 75) && (Ping[PING_RIGHT] >= 50 && Ping[PING_RIGHT] <= 67))
							{
								ROOM[ROOM_COUNTER]= ROOM_4A;
								lcd_display_clear();
								lcd_gotoxy(0,0);sprintf(lcd,"ROOM 4 ");lcd_putstr(lcd);
								lcd_gotoxy(0,1);sprintf(lcd,"DOOR A ");lcd_putstr(lcd);
								delay_ms(100);
							}
							else if(Ping[PING_LEFT] > 55 && Ping[PING_RIGHT] > 70)
							{
								ROOM[ROOM_COUNTER]= ROOM_4B;
								lcd_display_clear();
								lcd_gotoxy(0,0);sprintf(lcd,"ROOM 4 ");lcd_putstr(lcd);
								lcd_gotoxy(0,1);sprintf(lcd,"DOOR B ");lcd_putstr(lcd);
								delay_ms(100);
							}
							}
						}

				}
			}
		}
		else
		{
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
			lcd_gotoxy(4,1);sprintf(lcd,"ROOM ID");lcd_putstr(lcd);
			lcd_gotoxy(4,2);sprintf(lcd,"FAILED");lcd_putstr(lcd);
			delay_ms(50);

			if(Ping[PING_FRONT]>17)
			{
				Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);
			}
			else if(Ping[PING_FRONT]<=17)
			{
				Dynamx_MovBwd_Interpolate(3,LEVEL5,IKCALC_ENABLE);
			}
			RoomDetector(ROOM_COUNTER);
		}
	}
}

/* func      : void BW_FireFight(void)
 * brief     : BW FireFighting Routines
 * param     : N/A
 * retval    : N/A
 * Ver       : 6
 * written By: Ryan (Thursday, March 23rd 2016)
 * Revised BY: Hafidin (Monday, Feb 27th 2017) Ver.3
 * 				Ver.4: Ryan (Sunday, April 23rd 2017)
 * 						Added special condition for ROOM4AB, bypassing the wall following
 * 						algorithm
 * 				Ver.5 > Hafidin (Fri, April 27th 2017)
 * 				Ver.6 > Hafidin (Tue, May 2nd 2017)
 * 				Ver.7 : Reyhan (Tue, October 30th 2018)
 * 						Optimized for CO2 Extinguisher System
 * programmer's Note:
 */

void BW_FireFight_V2(void)
{
	int cnt=0;
	int x,m;

	FlameSenseDigi_PID_Init();

	CANDLE_STICK=0;
	CANDLE_FIRE=0;

	FIRE_LED_BLINK_ON;

	BW_TurnAround = ACTIVE;
	UV_R2FLAG=UV_R2FLAG_INACTIVE;

	if(ROOM4AB_FLAG==ROOM4AB_ACTIVE)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"BW FIREFIGHT");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"ROOM4AB MODE");lcd_putstr(lcd);
		delay_ms(100);

//		RESET THE ROOM4AB FLAG
		ROOM4AB_FLAG=ROOM4AB_INACTIVE;
	}

	else
	{
		if(FIRESCAN_DIRECTION == SCAN_RIGHT)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"SCAN RIGHT");lcd_putstr(lcd);
			delay_ms(100);

			if(FIREROOM_R1A_FLAG == FIREROOM_R1A_ACTIVE)
			{
				FOLLOWMODE_FLAG=FOLLOW_TRACER_WHITE;
				TRACER_STAT=TRACER_BLACK;

				//BW_PID_Init();
				BW_PID_Init_Furniture();

				lcd_display_clear();

				while(FlameSenseDigi[0]!=4 || FlameFrontDigi[0]!=4 )
				{
					if(FlameSenseDigi[0] == 2){break;}
					if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==6) || (FlameSenseDigi[0] == 7))break;
					if(FlameFrontDigi[0] == 4)break;

					TCSlave_Check();

					Furniture_Avoider();
					BW_FollowCounter_Left(1);

								TCSlave_Check();
								if(TRACER_STAT==TRACER_WHITE){TRACER_BREAK=1;break;}

					cnt++;
					if(cnt>40)break;
					if(FlameFrontDigi[0] == 4)break;
					if(FlameSenseDigi[0] == 2){break;}
					if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==6) || (FlameSenseDigi[0] == 7))break;
				}

			}

			else if(SP_FIRE_R3==SP_FIRE_ACTIVE)
			{
				FOLLOWMODE_FLAG=FOLLOW_TRACER_WHITE;
				TRACER_STAT=TRACER_BLACK;

				BW_PID_Init_Furniture();

				lcd_display_clear();
				while(FlameFrontDigi[0]!=4)
				{
					if((FlameSenseDigi[0]==4)|| (FlameSenseDigi[0]==5) || (FlameSenseDigi[0] == 6))break;
					if(/*FlameSenseDigi[0]==3 || */FlameSenseDigi[0]==2){break;}
//					if(FlameFrontDigi[0]==4)break;
					lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"SCAN RIGHT SP R3");lcd_putstr(lcd);

					Furniture_Avoider();
					BW_FollowCounter_Left(1);

					TCSlave_Check();
					if(TRACER_STAT==TRACER_WHITE){TRACER_BREAK=1;break;}

					if((FlameSenseDigi[0]==4)|| (FlameSenseDigi[0]==5) || (FlameSenseDigi[0] == 6))break;
					if(FlameSenseDigi[0]==3 || FlameSenseDigi[0]==2){break;}
					if(FlameFrontDigi[0]==4)break;
				}
			}

			else if(ROOM4AB_FLAG==ROOM4AB_ACTIVE)
			{
				FOLLOWMODE_FLAG=FOLLOW_TRACER_WHITE;
				TRACER_STAT=TRACER_BLACK;

				BW_PID_Init_Furniture();

				lcd_display_clear();

				while(FlameSenseDigi[0]!=4)
				{
					if(FlameSenseDigi[0]!=0 && FlameSenseDigi[0]!=7 && FlameSenseDigi[0]!=6)break;
					if(FlameFrontDigi[0]==4)break;

					lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"SCAN RIGHT 4AB");lcd_putstr(lcd);

					BW_FollowCounter_Left(1);

					TCSlave_Check();
					if(TRACER_STAT==TRACER_WHITE){TRACER_BREAK=1;break;}
					if(FlameSenseDigi[0]!=0 && FlameSenseDigi[0]!=7 && FlameSenseDigi[0]!=6)break;
					if(FlameFrontDigi[0]==4)break;
				}
			}

			else if(FIREROOM_R1A_FLAG == ROOM1A_SP_MIDDLE_FLAG)
			{
				FOLLOWMODE_FLAG=FOLLOW_TRACER_WHITE;
				TRACER_STAT=TRACER_BLACK;

				BW_PID_Init_Furniture();

				lcd_display_clear();
				while(FlameSenseDigi[0]!=4)
				{
					if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==6) || (FlameSenseDigi[0]==7))break;
					if(FlameFrontDigi[0]==4)break;

					lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"SCAN RIGHT");lcd_putstr(lcd);

					Furniture_Avoider();
					BW_FollowCounter_Left(1);

					TCSlave_Check();
					if(TRACER_STAT==TRACER_WHITE){TRACER_BREAK=1;break;}

					if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==6) || (FlameSenseDigi[0]==7))break;
					if(FlameFrontDigi[0]==4)break;
				}

			}

			else if(ROOM[2] == ROOM_2A || ROOM[2] == ROOM_2B)
			{
				//BW_PID_Init();
				BW_PID_Init_Furniture();
				TRACER_STAT=TRACER_BLACK;

				lcd_display_clear();

				while(FlameSenseDigi[0]!=4)
				{
					if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==5)/* || (FlameSenseDigi[0]==6)*/)break;
					if(FlameFrontDigi[0]==4)break;

					Furniture_Avoider();
					BW_FollowCounter_Left(1);

						TCSlave_Check();
						if (TRACER_STAT==TRACER_WHITE)
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"TRACER STATS");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"WHITE");lcd_putstr(lcd);
							delay_ms(50);
							Dynamx_MovBwd_Interpolate(8,LEVEL5,IKCALC_DISABLE);
							Nav_TurnAround(TURN_RIGHT);
							Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
							TRACER_STAT=TRACER_BLACK;
						}

					if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==5)/* || (FlameSenseDigi[0]==6)*/)break;
					if(FlameFrontDigi[0]==4)break;
				}
			}

			else
			{
				TRACER_STAT=TRACER_BLACK;

				//BW_PID_Init();
				BW_PID_Init_Furniture();
				lcd_display_clear();

				while(FlameSenseDigi[0]!=4)
				{
					if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==2) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==6) || (FlameSenseDigi[0]==7))break;
					if(FlameFrontDigi[0]==4)break;

					Furniture_Avoider();
					BW_FollowCounter_Left(1);

						TCSlave_Check();
						if(TRACER_STAT==TRACER_WHITE)TRACER_BREAK=1;break;

					cnt++;
					if(cnt>28)break;
					if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==2) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==6)  || (FlameSenseDigi[0]==7))break;
					if(FlameFrontDigi[0]==4)break;
				}
			}
			FIRESCAN_DIRECTION = SCAN_RIGHT;
		}

		else if(FIRESCAN_DIRECTION==SCAN_LEFT)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"SCAN LEFT");lcd_putstr(lcd);
			delay_ms(100);

			if(SP_FIRE_1C==SP_FIRE_ACTIVE)
			{
				FOLLOWMODE_FLAG=FOLLOW_TRACER_WHITE;
				TRACER_STAT=TRACER_BLACK;

				//BW_PID_Init();
				BW_PID_Init_Furniture();
				lcd_display_clear();
				while(FlameSenseDigi[0]!=4)
				{
					if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5) || FlameSenseDigi[0] == 2 || FlameSenseDigi[0] == 1)break;
					if(FlameFrontDigi[0]==4)break;
					Furniture_Avoider();
					BW_FollowCounter_Right(1);

								TCSlave_Check();
								if(TRACER_STAT==TRACER_WHITE)TRACER_BREAK=1;break;

					cnt++;
					if(cnt>60)break;

					if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5) || FlameSenseDigi[0] == 2 || FlameSenseDigi[0] == 1)break;
					if(FlameFrontDigi[0]==4)break;
				}
			}

			else if(SP_FIRE_R3 == SP_FIRE_ACTIVE)
			{
				//BW_PID_Init();
				BW_PID_Init_Furniture();
				lcd_display_clear();
				while(FlameSenseDigi[0]!=4)
				{
					if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3)/* || (FlameSenseDigi[0]==5) *//*|| (FlameSenseDigi[0]==1)*/ || (FlameSenseDigi[0]==7))break;
					if(FlameFrontDigi[0]==4)break;


					Furniture_Avoider();
					BW_FollowCounter_Right(1);

					TCSlave_Check();
					if(TRACER_STAT==TRACER_WHITE)TRACER_BREAK=1;break;

					cnt++;
					if(cnt>28)break;

					if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==5))break;
					if(FlameFrontDigi[0]==4)break;
				}
				SP_FIRE_R3=SP_FIRE_INACTIVE;
			}

			else if(SP_FIRE_1B == SP_FIRE_ACTIVE)
			{
				TRACER_STAT=TRACER_BLACK;
				//BW_PID_Init();
				BW_PID_Init_Furniture();
				lcd_display_clear();
				while(FlameSenseDigi[0]!=4)
				{
					if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==6) || (FlameSenseDigi[0]==7))break; ///*|| (FlameSenseDigi[0]==1)*/ || (FlameSenseDigi[0]==7))break;
					if(FlameFrontDigi[0]==4)break;

					Furniture_Avoider();
					BW_FollowCounter_Right(1);

						TCSlave_Check();
						if(TRACER_STAT==TRACER_WHITE){TRACER_BREAK=1;break;}

					cnt++;
					if(cnt>28)break;

					if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==6) || (FlameSenseDigi[0]==7))break;
					if(FlameFrontDigi[0]==4)break;
				}
			}

			else
			{
				TRACER_STAT=TRACER_BLACK;
				//BW_PID_Init();
				BW_PID_Init_Furniture();
				lcd_display_clear();
				while(FlameSenseDigi[0]!=4)
				{
//					if(FlameSenseDigi[0]==2)break;
					if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5))break; ///*|| (FlameSenseDigi[0]==1)*/ || (FlameSenseDigi[0]==7))break;
					if(FlameFrontDigi[0]==4)break;

					Furniture_Avoider();
					BW_FollowCounter_Right(1);

						TCSlave_Check();
						if(TRACER_STAT==TRACER_WHITE){TRACER_BREAK=1;break;}

					cnt++;
					if(cnt>28)break;

					if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5))break;
					if(FlameFrontDigi[0]==4)break;
				}
			}

			FIRESCAN_DIRECTION = SCAN_LEFT;
		}

		else if(FIRESCAN_DIRECTION == NO_WALL_PARAM)
		{
			lcd_display_clear();
			while(FlameSenseDigi[0]==0)
			{
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"NO WALL PARAM");lcd_putstr(lcd);
				lcd_gotoxy(0,3);sprintf(lcd,"CNT = %d",cnt);lcd_putstr(lcd);
				Dynamx_Rot_Right_Interpolate(HEXSPD_FAST,HEXSTEP_MED,IKCALC_DISABLE);
				cnt++;
				if(cnt>30)
				{
					Dynamx_MovFwd4cm_Interpolate(8,LEVEL4,IKCALC_ENABLE);
				}

			}
		}


	}

	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
	lcd_gotoxy(0,3);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
	delay_ms(100);

	if((FIREROOM_R1A_FLAG==FIREROOM_R1A_ACTIVE) && (FlameSenseDigi[0]==0) && (TRACER_BREAK==1))
	{
		Dynamx_MovBwd_Interpolate(9,LEVEL5,IKCALC_ENABLE);

		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"SP FIRE");lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"CANDLE 1A");lcd_putstr(lcd);
		delay_ms(50);

		Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
		Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);

		Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);

		Dynamx_MovFwd4cm_Interpolate(8,LEVEL4,IKCALC_ENABLE);

		lcd_display_clear();
		for(m=0;m<=6;m++)
		{
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"SP FIRE 1C");lcd_putstr(lcd);
			delay_ms(50);
			Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
			if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==1)  || (FlameSenseDigi[0]==7) || (FlameFrontDigi[0]==4))break;
		}

	}

	else if((SP_FIRE_1C==SP_FIRE_ACTIVE) && (FlameSenseDigi[0]==0) && (TRACER_BREAK==1))
	{
		SP_FIRE_1C=SP_FIRE_INACTIVE;

		Dynamx_MovBwd_Interpolate(9,LEVEL5,IKCALC_ENABLE);

		BW_Buzz(1);
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"SP FIRE");lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"CANDLE 1C");lcd_putstr(lcd);
		delay_ms(50);

		Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
		Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
		Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
		Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);

		Dynamx_MovBwd_Interpolate(6,LEVEL5,IKCALC_DISABLE);

		Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_CLOSE,IKCALC_DISABLE);

		Dynamx_MovFwd4cm_Interpolate(8,LEVEL4,IKCALC_ENABLE);

		lcd_display_clear();
		for(m=0;m<=6;m++)
		{
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"SP FIRE 1C");lcd_putstr(lcd);
			delay_ms(50);
			Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
			if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==1)  || (FlameSenseDigi[0]==7) || (FlameFrontDigi[0]==4))break;
		}
	}

	else if((SP_FIRE_1B==SP_FIRE_ACTIVE) && (FlameSenseDigi[0]==0) && (TRACER_BREAK==1))
	{
		Dynamx_MovBwd_Interpolate(9,LEVEL5,IKCALC_ENABLE);
		Nav_TurnAround(TURN_RIGHT);
		lcd_display_clear();
		for(m=0;m<=6;m++)
		{
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"SP FIRE 1B");lcd_putstr(lcd);
			delay_ms(50);
			BW_FollowCounter_Left(1);
			if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==1)  || (FlameSenseDigi[0]==7) || (FlameFrontDigi[0]==4) || (FlameSenseDigi[0]==2) || (FlameFrontDigi[0]==6))break;
		}

	}

	else if((SP_FIRE_R3==SP_FIRE_ACTIVE) && (FlameSenseDigi[0]==0) && (TRACER_BREAK==1))
	{
		Dynamx_MovBwd_Interpolate(9,LEVEL5,IKCALC_ENABLE);
		Nav_TurnAround(TURN_RIGHT);
		if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3))
			{
				Dynamx_MovFwd4cm_Interpolate(8,LEVEL4,IKCALC_ENABLE);
			}
		else
		{
			if((Ping[PING_ASKEW_LEFT])<(Ping[PING_REAR_LEFT]))
			{
				Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_ASKEW_LEFT])<(Ping[PING_REAR_LEFT]))
				{	Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				}
			}
			else {
				Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_ASKEW_LEFT])>(Ping[PING_REAR_LEFT]))
				{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				}
			}
			Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
			Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
			Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);

			int i=0;
			while(Ping[PING_RIGHT]>10 && i<5)
			{
				Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
				i++;
			}
				Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);

				FIRESCAN_DIRECTION=SCAN_LEFT;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"SP FIRE R3");lcd_putstr(lcd);
				delay_ms(50);
		}
		SP_FIRE_R3=SP_FIRE_INACTIVE;
	}

	FIREROOM_R1A_FLAG = FIREROOM_R1A_INACTIVE;
	FlameTracking_Ver3();

	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"BW FIREFIGHT");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"TRACKING");lcd_putstr(lcd);
	delay_ms(100);

	if (ROOM[2]==ROOM_1A)
	{
		for(x=0;x<=3;x++)
		{
			FlameTracking_Center();

			lcd_display_clear();
			while(SHARP[SHARP_FRONT_R]>60 && SHARP[SHARP_FRONT_L]>600)
			{
				lcd_gotoxy(0,0);sprintf(lcd,"MAJU KE API");lcd_putstr(lcd);

				Dynamx_MovFwd4cm_Interpolate(4,LEVEL3,IKCALC_DISABLE);

				Furniture_Avoider();


				if(FlameFrontDigi[0]!=4)break;
			}

			FlameTracking_Center();



			while(SHARP[SHARP_FRONT_R]>60 && SHARP[SHARP_FRONT_L]>60)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"MAJU KE API");lcd_putstr(lcd);

				Dynamx_MovFwd4cm_Interpolate(4,LEVEL3,IKCALC_DISABLE);

				Furniture_Avoider();


				if(FlameFrontDigi[0]!=4)break;
			}


		}

	}

	else if((ROOM[2]==ROOM_1B) || (ROOM[2]==ROOM_1C) || (ROOM[2]==ROOM_2A) || (ROOM[2]==ROOM_3))
	{
		for(x=0;x<=3;x++)
		{
			FlameTracking_Center();

			while(SHARP[SHARP_FRONT_R]>60 && SHARP[SHARP_FRONT_L]>60)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"MAJU KE API");lcd_putstr(lcd);

				Dynamx_MovFwd4cm_Interpolate(4,LEVEL3,IKCALC_DISABLE);

				Furniture_Avoider();


				if(FlameFrontDigi[0]!=4)break;
			}

			FlameTracking_Center();



			while(SHARP[SHARP_FRONT_R]>60 && SHARP[SHARP_FRONT_L]>60)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"MAJU KE API");lcd_putstr(lcd);

				Dynamx_MovFwd4cm_Interpolate(4,LEVEL3,IKCALC_DISABLE);

				Furniture_Avoider();


				if(FlameFrontDigi[0]!=4)break;
			}


		}
	}

	else
	{
		for(x=0;x<=3;x++)
		{
			FlameTracking_Center();

			while(SHARP[SHARP_FRONT_R]>40 && SHARP[SHARP_FRONT_L]>40)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"MAJU KE API");lcd_putstr(lcd);

				Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);

				Furniture_Avoider();


				if(FlameFrontDigi[0]!=4)break;
			}

			FlameTracking_Center();



			while(SHARP[SHARP_FRONT_R]>40 && SHARP[SHARP_FRONT_L]>40)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"MAJU KE API");lcd_putstr(lcd);

				Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);

				Furniture_Avoider();


				if(FlameFrontDigi[0]!=4)break;
			}


		}
	}

	UV_R2FLAG=UV_R2FLAG_INACTIVE;

	FlameTracking_Center();
	FlameTracking_Ver3();

	Furniture_Avoider();

	UVLock_Refresh();
	if(1) // dummy if
	{
		lcd_display_clear();
		lcd_gotoxy(0,1);sprintf(lcd,"EXTINGUISH 1.0");lcd_putstr(lcd);
		Dynamx_Mov_Static_Interpolate(LEVEL5,IKCALC_ENABLE);
		delay_ms(50);

		if(ROOM[2] == ROOM_4A || ROOM[2] == ROOM_4B)
		{
			if(SHARP[SHARP_FRONT_L] > 18)
			{
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
			}
			if(SHARP[SHARP_FRONT_L] > 18)
			{
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
			}
			FlameTracking_Center();
		}
		else
		{
			if(SHARP[SHARP_FRONT_L] > 80)
			{
				FlameTracking_Center();
				delay_ms(100);
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
				Furniture_Avoider();
			}
			if(SHARP[SHARP_FRONT_L] > 80)
			{
				FlameTracking_Center();
				delay_ms(100);
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
				Furniture_Avoider();
			}
			if(SHARP[SHARP_FRONT_L] > 80)
			{
				FlameTracking_Center();
				delay_ms(100);
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
				Furniture_Avoider();
			}
		}

		FlameTracking_Center();
		if(ROOM[2] == ROOM_4A || ROOM[2] == ROOM_4B)
		{
			BW_Pump_R4();
		}
		else if(Ping[PING_UP_LEFT] <= 12 && (ROOM[2] != ROOM_4A && ROOM[2] != ROOM_4B) && SHARP[SHARP_FRONT_L] > 30)
		{
			if(Ping[PING_LEFT] > 20)
			{
				BW_PID_Init_Furniture();
				Furniture_Avoider();
				FlameTracking_Center();
			}
			else if(Ping[PING_RIGHT] > 20)
			{
				BW_PID_Init_Furniture();
				Furniture_Avoider();
				FlameTracking_Center();
			}
			if(FlameSenseDigi[0] == 4 || FlameFrontDigi[0] == 4)
			{
				BW_HydroPump_V10();
			}
			else FlameTracking_Center();
		}

		else if(Ping[PING_UP_RIGHT] <= 12 && (ROOM[2] != ROOM_4A && ROOM[2] != ROOM_4B)&& SHARP[SHARP_FRONT_L] > 30)
		{
			if(Ping[PING_LEFT] > 20)
			{
				BW_PID_Init_Furniture();
				Furniture_Avoider();
				FlameTracking_Center();
			}
			else if(Ping[PING_RIGHT] > 20)
			{
				BW_PID_Init_Furniture();
				Furniture_Avoider();
				FlameTracking_Center();
			}
			if(FlameSenseDigi[0] == 4 || FlameFrontDigi[0] == 4)
			{
				BW_HydroPump_V10();
			}
			else
			{
				FlameTracking_Center();
				if(FlameSenseDigi[0] == 4 || FlameFrontDigi[0] == 4)
				{
					BW_HydroPump_V10();
				}
			}
		}
		else
		{
			if(FlameSenseDigi[0] == 4 || FlameFrontDigi[0] == 4)
			{
				BW_HydroPump_V10();
			}
			else
			{
				FlameTracking_Center();
				if(FlameSenseDigi[0] == 4 || FlameFrontDigi[0] == 4)
				{
					BW_HydroPump_V10();
				}
			}
		}
	}
	delay_ms(1000);

	if(UV_Lock==UVLOCK_ACTIVE)
	{
		UVLock_Refresh();
		delay_ms(1000);
	}

	if(UV_Lock==UVLOCK_ACTIVE)
	{
		FlameTracking_Ver3();
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"EXTINGUISH 2.0");lcd_putstr(lcd);
		FlameTracking_Center();
		if(FlameSenseDigi[0] == 4 || FlameFrontDigi[0] == 4)
		{
			BW_HydroPump_V10();
		}
		else FlameTracking_Center();
	}

	if(UV_Lock==UVLOCK_ACTIVE)
	{
		UVLock_Refresh();
		delay_ms(1000);
	}

	if(FlameSenseDigi[0] != 4 && UV_Lock == UVLOCK_ACTIVE)
	{
		FlameTracking_Ver3();
		FlameTracking_Center();
	}

	if(UV_Lock==UVLOCK_ACTIVE)
	{
		UVLock_Refresh();
		delay_ms(1000);
	}

	if(UV_Lock == UVLOCK_ACTIVE)
	{
	int follow_mode = 0, init_pid = 0, counts=0;
	//Tracking Again
	counts = 0;
	}

	if(UV_Lock==UVLOCK_ACTIVE)
	{
		UVLock_Refresh();
		delay_ms(1000);
	}

	if(UV_Lock==UVLOCK_ACTIVE)
	{
		UVLock_Refresh();
		delay_ms(1000);
	}
	if(FlameSenseDigi[0] != 4 && UV_Lock == UVLOCK_ACTIVE)
	{
		FlameTracking_Ver3();
		FlameTracking_Center();
	}

	if(UV_Lock==UVLOCK_ACTIVE)
	{
		UVLock_Refresh();
		delay_ms(1000);
	}

	if(UV_Lock==UVLOCK_ACTIVE)
	{
		FlameTracking_Center();
		//Dynamx_Mov_Tracking(HEXSPD_SLOW);
		if(FlameSenseDigi[0] == 4 || FlameFrontDigi[0] == 4)
		{
			BW_HydroPump_V10();
		}
		else FlameTracking_Center();
	}

	if(UV_Lock==UVLOCK_ACTIVE)
	{
		UVLock_Refresh();
		delay_ms(1000);
	}


	if(FlameSenseDigi[0] != 4 && UV_Lock == UVLOCK_ACTIVE)
	{
		FlameTracking_Ver3();
		FlameTracking_Center();
	}

	if(UV_Lock==UVLOCK_ACTIVE)
	{
		FlameTracking_Center();
		lcd_display_clear();
		lcd_gotoxy(0,1);sprintf(lcd,"EXTINGUISH 1.1");lcd_putstr(lcd);
		if(FlameSenseDigi[0] == 4 || FlameFrontDigi[0] == 4)
		{
			BW_HydroPump_V10();
		}
		else FlameTracking_Center();
	}

	if(UV_Lock==UVLOCK_ACTIVE)
	{
		UVLock_Refresh();
		delay_ms(1000);
	}

	UVLock_Refresh();
	if(UV_Lock==UVLOCK_ACTIVE)
	{
		FlameTracking_Center();
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"EXTINGUISH 2.1");lcd_putstr(lcd);
		if(FlameSenseDigi[0] == 4 || FlameFrontDigi[0] == 4)
		{
			BW_HydroPump_V10();
		}
		else FlameTracking_Center();
	}

	if(UV_Lock==UVLOCK_ACTIVE)
	{
		UVLock_Refresh();
		delay_ms(1000);
	}

	if(FlameSenseDigi[0] != 4 && UV_Lock == UVLOCK_ACTIVE)
	{
		FlameTracking_Ver3();
		FlameTracking_Center();
	}

	if(UV_Lock==UVLOCK_ACTIVE)
	{
		UVLock_Refresh();
		delay_ms(1000);
	}

	UVLock_Refresh();
	if(UV_Lock==UVLOCK_ACTIVE)
	{
		int follow_mode = 0, init_pid = 0, counts=0;
		//Tracking Again
		counts = 0;
		Get_UV();
		while(FlameSenseDigi[0] != 4 && UV_state == UVLOCK_ACTIVE)
		{
			if(counts >= 20)
			{
				Get_UV();
				if(UV_state == UVSTATE_INACTIVE)break;
			}
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)
			{
				TRACER_STAT = TRACER_BLACK;
				init_pid = 1;
	//				Nav_TurnAround(TURN_LEFT);
				Dynamx_MovBwd_Interpolate(12,LEVEL5,IKCALC_ENABLE);
				Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_MED,IKCALC_DISABLE);
				Get_UV();
				if(UV_state == UVSTATE_INACTIVE)break;
			}
			if(init_pid == 1)
			{
				BW_PID_Init_Room();
				init_pid = 0;
			}
			if(FlameSenseDigi[0] != 0 || FlameFrontDigi[0] != 0)break;
			if(follow_mode == 0)
			{
				BW_FollowCounter_Left(1);
			}
			else BW_FollowCounter_Right(1);
			counts++;
		}

		FlameTracking_Ver3();
		FlameTracking_Center();
//		Dynamx_Mov_Tracking(HEXSPD_SLOW);
		if(FlameSenseDigi[0] == 4 || FlameFrontDigi[0] == 4)
		{
			BW_HydroPump_V10();
		}
		else FlameTracking_Center();
	}

	if(UV_Lock==UVLOCK_ACTIVE)
	{
		UVLock_Refresh();
		delay_ms(1000);
	}

	while(UV_Lock==UVLOCK_ACTIVE)
	{
		BW_TurnAround=INACTIVE;

		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) break;

		int follow_mode = 0, init_pid = 0, counts=0;
		//Tracking Again
		counts = 0;
		Get_UV();
		while(FlameSenseDigi[0] != 4 && UV_state == UVLOCK_ACTIVE)
		{
			UVLock_Refresh();
			if(UV_Lock==UVLOCK_INACTIVE) break;
			if(counts >= 20)
			{
				Get_UV();
				if(UV_state == UVSTATE_INACTIVE)break;
			}
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)
			{
				TRACER_STAT = TRACER_BLACK;
				init_pid = 1;
	//				Nav_TurnAround(TURN_LEFT);
				Dynamx_MovBwd_Interpolate(12,LEVEL5,IKCALC_ENABLE);
				Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_MED,IKCALC_DISABLE);
				Get_UV();
				if(UV_state == UVSTATE_INACTIVE)break;
			}
			if(init_pid == 1)
			{
				BW_PID_Init_Room();
				init_pid = 0;
			}
			if(FlameSenseDigi[0] != 0 || FlameFrontDigi[0] != 0)break;
			if(follow_mode == 0)
			{
				BW_FollowCounter_Left(1);
			}
			else BW_FollowCounter_Right(1);
			counts++;
			UVLock_Refresh();
			if(UV_Lock==UVLOCK_INACTIVE) break;
		}

		UVLock_Refresh();
		if(UV_Lock==UVLOCK_ACTIVE)
		{
			UVLock_Refresh();
			if(UV_Lock==UVLOCK_ACTIVE)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
				FlameTracking_Center();
			}

/////////////////////////////////////////////////////////////////////////////////

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_ACTIVE)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"EXTINGUISH 3");lcd_putstr(lcd);
				FlameTracking_Center();
				if(FlameSenseDigi[0] == 4 || FlameFrontDigi[0] == 4)
				{
					BW_HydroPump_V10();
				}
				else FlameTracking_Center();
			}
			delay_ms(200);

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_ACTIVE)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"EXTINGUISH 4");lcd_putstr(lcd);
				FlameTracking_Center();
				if(FlameSenseDigi[0] == 4 || FlameFrontDigi[0] == 4)
				{
					BW_HydroPump_V10();
				}
				else FlameTracking_Center();
			}
			delay_ms(200);

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_ACTIVE)
			{
				FlameTracking_Center();
//				Dynamx_Mov_Tracking(HEXSPD_SLOW);
				if(FlameSenseDigi[0] == 4 || FlameFrontDigi[0] == 4)
				{
					BW_HydroPump_V10();
				}
				else FlameTracking_Center();

			}
			delay_ms(200);
		}
		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) break;
	}

	EXTINGUISHER_OFF;
	EXTINGUISHED_FIRE=1;

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(2,1);sprintf(lcd,"FIREFIGHTING");lcd_putstr(lcd);
	lcd_gotoxy(3,2);sprintf(lcd,"SUCCESS!!!");lcd_putstr(lcd);
	delay_ms(200);

}


void UVLock_Refresh(void)
{
	Get_UV();
	if(UV_state==UVSTATE_INACTIVE)
	{
		UV_Lock=UVLOCK_INACTIVE;
	}
}


/* func      : void BW_Navi(int STARTING_POINT, int DESTINATION)
 * brief     : BW NAVIGATION ROUTINES
 * param     : int STARTING_POINT->Initial location | int DESTINATION -> BW's target location
 *     					STARTING POINT 					DESTINATION
 * 				HALLWAY_SC			(1A, 1B, 1C, 2A, 2B, 3, 4A, 4B					)
 * 				ROOM_1A				(HALLWAY_SC, 2A, 2B, 3, 4A, 4B				)
 * 				ROOM_1B				( 				N/A								)
 * 				ROOM_1C				(HALLWAY_SC, 2A, 2B, 3, 4A, 4B				)
 * 				ROOM_2A/2B			(HALLWAY_SC, 1A, 1B, 1C, 2A, 2B, 3, 4A, 4B	)
 * 				ROOM_3				(HALLWAY_SC, 1A, 1B, 1C, 2A, 2B, 3, 4A, 4B	)
 * 				ROOM_4A				(HALLWAY_SC, 1A, 1B, 1C, 2A, 2B, 3			)
 * 				ROOM_4B				(HALLWAY_SC, 1A, 1B, 1C, 2A, 2B, 3					)
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 25th 2016)
 * Revised BY: N/A
 * programmer's Note:
 *
 */
void BW_Navi(int STARTING_POINT, int DESTINATION)
{
	int DEPARTURE=99;

	DEPARTURE = STARTING_POINT;

	//STARTING POINT == HALLWAY SC
	if(DEPARTURE==HALLWAY_SC)
	{
		switch(DESTINATION)
		{
			case NAV_HALLWAY_SC:
				{
					while(1)
					{
						Dynamx_Mov_Static_Interpolate(LEVEL4,IKCALC_ENABLE);
					}
				}break;

			case NAV_ROOM_1A:
				{
					Nav_HallwaySC_To_1A(2);
				}break;

			case NAV_ROOM_1B:
				{
					Nav_HallwaySC_To_1B();
				}break;

			case NAV_ROOM_1C:
				{
					Nav_HallwaySC_To_1B();
				}break;

			case NAV_ROOM_2A:
				{
					Nav_HallwaySC_To_2();
				}break;

			case NAV_ROOM_2B:
				{
					Nav_HallwaySC_To_2();
				}break;

			case NAV_ROOM_3:
				{
					Nav_HallwaySC_To_3();
				}break;

			case NAV_ROOM_4A:
				{
					Nav_HallwaySC_To_4A();
				}break;

			case NAV_ROOM_4B:
				{
					Nav_HallwaySC_To_4B();
				}break;
		}
	}

	//STARTING POINT == ROOM 1A
	else if (DEPARTURE==NAV_ROOM_1A)
	{
		switch(DESTINATION)
		{
			case NAV_HALLWAY_SC:
				{
					Nav_1A_To_HallwaySC();

				}break;

			case NAV_ROOM_1A:
				{
					while(1)
					{
						Dynamx_Mov_Static_Interpolate(LEVEL3,IKCALC_ENABLE);
					}

				}break;

			case NAV_ROOM_1B:
				{
					//WRONG ANSWER
					while(1)
					{
						Dynamx_Mov_Static_Interpolate(LEVEL3,IKCALC_ENABLE);
					}
				}break;

			case NAV_ROOM_1C:
				{
					//WRONG ANSWER
					while(1)
					{
						Dynamx_Mov_Static_Interpolate(LEVEL3,IKCALC_ENABLE);
					}
				}break;

			case NAV_ROOM_2A:
				{
					Nav_1A_To_2();
				}break;

			case NAV_ROOM_2B:
				{
					Nav_1A_To_2();
				}break;

			case NAV_ROOM_3:
				{
					Nav_1A_To_3();
				}break;

			case NAV_ROOM_4A:
				{
					Nav_1A_To_4A();
				}break;

			case NAV_ROOM_4B:
				{
					Nav_1A_To_4B();
				}break;
		}
	}

	//STARTING POINT == ROOM 1B
	else if (DEPARTURE==NAV_ROOM_1B)
	{
		switch(DESTINATION)
		{
			case NAV_HALLWAY_SC:
				{
					Nav_1C_To_HallwaySC();

				}break;

			case NAV_ROOM_1A:
				{
					//WRONG ANSWER
					while(1)
					{
						Dynamx_Mov_Static_Interpolate(LEVEL3,IKCALC_ENABLE);
					}

				}break;

			case NAV_ROOM_1B:
				{
					//WRONG ANSWER
					while(1)
					{
						Dynamx_Mov_Static_Interpolate(LEVEL3,IKCALC_ENABLE);
					}
				}break;

			case NAV_ROOM_1C:
				{
					//WRONG ANSWER
					while(1)
					{
						Dynamx_Mov_Static_Interpolate(LEVEL3,IKCALC_ENABLE);
					}
				}break;

			case NAV_ROOM_2A:
				{
					Nav_1B_To_2();
				}break;

			case NAV_ROOM_2B:
				{
					Nav_1B_To_2();
				}break;

			case NAV_ROOM_3:
				{
					Nav_1C_To_3();
				}break;

			case NAV_ROOM_4A:
				{
					Nav_1C_To_4A();
				}break;

			case NAV_ROOM_4B:
				{
					Nav_1C_To_4B();
				}break;
		}
	}

	//STARTING POINT == ROOM 1C
	else if (DEPARTURE==NAV_ROOM_1C)
	{
		switch(DESTINATION)
		{
			case NAV_HALLWAY_SC:
				{
					Nav_1C_To_HallwaySC();

				}break;

			case NAV_ROOM_1A:
				{
					//WRONG ANSWER
					while(1)
					{
						Dynamx_Mov_Static_Interpolate(LEVEL3,IKCALC_ENABLE);
					}

				}break;

			case NAV_ROOM_1B:
				{
					//WRONG ANSWER
					while(1)
					{
						Dynamx_Mov_Static_Interpolate(LEVEL3,IKCALC_ENABLE);
					}
				}break;

			case NAV_ROOM_1C:
				{
					//WRONG ANSWER
					while(1)
					{
						Dynamx_Mov_Static_Interpolate(LEVEL3,IKCALC_ENABLE);
					}
				}break;

			case NAV_ROOM_2A:
				{
					Nav_1C_To_2();
				}break;

			case NAV_ROOM_2B:
				{
					Nav_1C_To_2();
				}break;

			case NAV_ROOM_3:
				{
					Nav_1C_To_3();
				}break;

			case NAV_ROOM_4A:
				{
					Nav_1C_To_4A();
				}break;

			case NAV_ROOM_4B:
				{
					Nav_1C_To_4B();
				}break;
		}
	}

	//STARTING POINT == ROOM 2A
	else if ( (DEPARTURE==NAV_ROOM_2A)  )
	{
		switch(DESTINATION)
		{
			case NAV_HALLWAY_SC:
				{
					Nav_2_To_HallwaySC();

				}break;

			case NAV_ROOM_1A:
				{
					Nav_2_To_1A();
				}break;

			case NAV_ROOM_1B:
				{
					Nav_2A_To_1BC();
				}break;

			case NAV_ROOM_1C:
				{
					Nav_2A_To_1BC();
				}break;

			case NAV_ROOM_2A:
				{
					//WRONG ANSWER
					while(1)
					{
						Dynamx_Mov_Static_Interpolate(LEVEL3,IKCALC_ENABLE);
					}

				}break;

			case NAV_ROOM_2B:
				{
					//WRONG ANSWER
					while(1)
					{
						Dynamx_Mov_Static_Interpolate(LEVEL3,IKCALC_ENABLE);
					}

				}break;

			case NAV_ROOM_3:
				{
					Nav_2_To_3();
				}break;

			case NAV_ROOM_4A:
				{
					Nav_2_To_4A();
				}break;

			case NAV_ROOM_4B:
				{
					Nav_2_To_4B();
				}break;
		}
	}

	//STARTING POINT == ROOM 2B
	else if ( (DEPARTURE==NAV_ROOM_2B) )
	{
		switch(DESTINATION)
		{
			case NAV_HALLWAY_SC:
				{
					Nav_2_To_HallwaySC();

				}break;

			case NAV_ROOM_1A:
				{
					Nav_2_To_1A();
				}break;

			case NAV_ROOM_1B:
				{
					Nav_2B_To_1BC();
				}break;

			case NAV_ROOM_1C:
				{
					Nav_2B_To_1BC();
				}break;

			case NAV_ROOM_2A:
				{
					//WRONG ANSWER
					while(1)
					{
						Dynamx_Mov_Static_Interpolate(LEVEL3,IKCALC_ENABLE);
					}

				}break;

			case NAV_ROOM_2B:
				{
					//WRONG ANSWER
					while(1)
					{
						Dynamx_Mov_Static_Interpolate(LEVEL3,IKCALC_ENABLE);
					}
				}break;

			case NAV_ROOM_3:
				{
					Nav_2_To_3();
				}break;

			case NAV_ROOM_4A:
				{
					Nav_2_To_4A();
				}break;

			case NAV_ROOM_4B:
				{
					Nav_2_To_4B();
				}break;
		}
	}


	//STARTING POINT == ROOM 3
	else if (DEPARTURE==NAV_ROOM_3)
	{
		switch(DESTINATION)
		{
			case NAV_HALLWAY_SC:
				{
					Nav_3_To_HallwaySC();
				}break;

			case NAV_ROOM_1A:
				{
					Nav_3_To_1A();
				}break;

			case NAV_ROOM_1B:
				{
					Nav_3_To_1BC();
				}break;

			case NAV_ROOM_1C:
				{
					Nav_3_To_1BC();
				}break;

			case NAV_ROOM_2A:
				{
					Nav_3_To_2();
				}break;

			case NAV_ROOM_2B:
				{
					Nav_3_To_2();
				}break;

			case NAV_ROOM_3:
				{
					//WRONG ANSWER
					while(1)
					{
						Dynamx_Mov_Static_Interpolate(LEVEL3,IKCALC_ENABLE);
					}
				}break;

			case NAV_ROOM_4A:
				{
					Nav_3_To_4A();
				}break;

			case NAV_ROOM_4B:
				{
					Nav_3_To_4B();
				}break;
		}
	}

	//STARTING POINT == ROOM 4A
	else if (DEPARTURE==NAV_ROOM_4A)
	{
		switch(DESTINATION)
		{
			case NAV_HALLWAY_SC:
				{
					Nav_4A_To_HallwaySC();
				}break;

			case NAV_ROOM_1A:
				{
					Nav_4A_To_1A();
				}break;

			case NAV_ROOM_1B:
				{
					//WRONG ANSWER
					while(1)
					{
						Dynamx_Mov_Static_Interpolate(LEVEL3,IKCALC_ENABLE);
					}
				}break;

			case NAV_ROOM_1C:
				{
					//WRONG ANSWER
					while(1)
					{
						Dynamx_Mov_Static_Interpolate(LEVEL3,IKCALC_ENABLE);
					}
				}break;

			case NAV_ROOM_2A:
				{
					Nav_4A_To_2();
				}break;

			case NAV_ROOM_2B:
				{
					Nav_4A_To_2();
				}break;

			case NAV_ROOM_3:
				{
					Nav_4A_To_3();
				}break;

			case NAV_ROOM_4A:
				{
					//WRONG ANSWER
					while(1)
					{
						Dynamx_Mov_Static_Interpolate(LEVEL3,IKCALC_ENABLE);
					}
				}break;

			case NAV_ROOM_4B:
				{
					//WRONG ANSWER
					while(1)
					{
						Dynamx_Mov_Static_Interpolate(LEVEL3,IKCALC_ENABLE);
					}
				}break;
		}
	}

	//STARTING POINT == ROOM 4B
	else if (DEPARTURE==NAV_ROOM_4B)
	{
		switch(DESTINATION)
		{
			case NAV_HALLWAY_SC:
				{
					Nav_4B_To_HallwaySC();
				}break;
			case NAV_ROOM_1A:
				{
					Nav_4B_To_1A();
				}break;
			case NAV_ROOM_1C:
				{
					Nav_4B_To_1BC();
				}break;
			case NAV_ROOM_1B:
				{
					Nav_4B_To_1BC();
				}break;

			case NAV_ROOM_2A:
				{
					Nav_4B_To_2();
				}break;

			case NAV_ROOM_2B:
				{
					Nav_4B_To_2();
				}break;

			case NAV_ROOM_3:
				{
					Nav_4B_To_3();
				}break;

			case NAV_ROOM_4A:
				{
					//WRONG ANSWER
					while(1)
					{
						Dynamx_Mov_Static_Interpolate(LEVEL3,IKCALC_ENABLE);
					}
				}break;

			case NAV_ROOM_4B:
				{
					//WRONG ANSWER
					while(1)
					{
						Dynamx_Mov_Static_Interpolate(LEVEL3,IKCALC_ENABLE);
					}
				}break;
		}
	}

	//WRONG CASE
	else
	{
		while(1)
		{
			BW_Buzz(2);
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
			lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
			lcd_gotoxy(2,3);sprintf(lcd,"NAVIGATION");lcd_putstr(lcd);
			delay_ms(100);
			Dynamx_Mov_Static_Interpolate(LEVEL4,IKCALC_ENABLE);

			delay_ms(500);

			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
			lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
			lcd_gotoxy(2,3);sprintf(lcd,"ERROR");lcd_putstr(lcd);
			delay_ms(100);
			Dynamx_Mov_Static_Interpolate(LEVEL4,IKCALC_ENABLE);

			delay_ms(500);
		}
	}


}

void Nav_HallwaySC_To_3(void)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"SC TO R3");lcd_putstr(lcd);
	delay_ms(100);

	BW_PID_Init();
	BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

	if (Ping[PING_LEFT]>15)
	{
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL6,IKCALC_ENABLE);
	}

	BW_PID_Init();
	BW_FollowTracer_Left_Interpolate();

	if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)
	{
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
	}

	FLAG_ROOM_3 = FLAG_ROOM_ACTIVE;
}

void Nav_HallwaySC_To_3_V3(void)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"SC TO R3_V3");lcd_putstr(lcd);
	delay_ms(50);

	STAIRS_DETECTOR = STAIRS_DETECTOR_ACTIVATED;

	BW_PID_Init();
	BW_FollowCounter_Right(5);

	Stairs_Detector();

	if (STAIRS_FLAG == STAIRS_DETECTED)
	{
		BW_Climbing_Stairs();
		STAIRS_FLAG = STAIRS_NOT_DETECTED;
	}

	STAIRS_DETECTOR = STAIRS_DETECTOR_DEACTIVATED;

	Dynamx_Slide_Right_Interpolate(HEXSPD_MED,LEVEL5);

	Dynamx_Rot_Right_IK(LEVEL6,STEP4);

	BW_PID_Init();
	BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

	if (Ping[PING_LEFT]>15)
	{
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL6,IKCALC_ENABLE);
	}

	BW_PID_Init();
	BW_FollowTracer_Left_Interpolate();

	BW_PID_Init();
	BW_FollowTracer_Left_Interpolate();

	if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)
	{
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
	}

	FLAG_ROOM_3 = FLAG_ROOM_ACTIVE;
}

/* func      : void Nav_HallwaySC_To_2(void)
 * brief     : Navigate from HallwaySC to Room 2
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 25th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_HallwaySC_To_2(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"SC TO R2");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	while(Ping[PING_ASKEW_LEFT]<=70)
//	while(SHARP[SHARP_LEFT]<=70)
	{
		BW_PID_Init();
		BW_FollowCounter_Right(1);
	}
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);

	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	lcd_gotoxy(0,1);sprintf(lcd," MIDDLE: %d",TCS3200_SLV_DATA[1]);lcd_putstr(lcd);
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	lcd_gotoxy(0,1);sprintf(lcd," MIDDLE: %d",TCS3200_SLV_DATA[1]);lcd_putstr(lcd);
	TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
	lcd_gotoxy(0,1);sprintf(lcd," MIDDLE: %d",TCS3200_SLV_DATA[1]);lcd_putstr(lcd);
	while(Ping[PING_RIGHT]>=20)
	{
		TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);
	}
	BW_PID_Init();
	BW_FollowTracer_Right_Interpolate();

}

/* func      : void Nav_HallwaySC_To_4B(void)
 * brief     : Navigate from HallwaySC to Room 4B
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 25th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_HallwaySC_To_4B(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"SC TO 4B");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	BW_PID_Init();
	BW_FollowTracer_Left_Interpolate();
	Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);
	while(1)
	{
		Dynamx_Mov_Static_Interpolate(LEVEL4,IKCALC_ENABLE);
	}
}

/* func      : void Nav_HallwaySC_To_4A(void)
 * brief     : Navigate from HallwaySC to Room 4A
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 25th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_HallwaySC_To_4A(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"SC TO R4A");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	while ( (Ping[PING_FRONT]>=25) && (INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED) )
	{
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
		if(Ping[PING_FRONT]<=5)
		{
			Dynamx_MovBwd_Interpolate(3,LEVEL5,IKCALC_ENABLE);
		}

	}

	//Get_IR();
	while ( Ping[PING_FRONT]<=25 || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
	{
		if(Ping[PING_FRONT]<=5)
		{
			Dynamx_MovBwd_Interpolate(3,LEVEL5,IKCALC_ENABLE);
		}
//		mov_rot_left(FAST_LEVEL_3,CLOSE);

	}

	BW_PID_Init();
	BW_FollowTracer_Right_Interpolate();

}

/* func      : void Nav_HallwaySC_To_1B(void)
 * brief     : Navigate from HallwaySC to Room 1B
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 25th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_HallwaySC_To_1B(void)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"SC TO R1BC");lcd_putstr(lcd);
	delay_ms(50);

	STAIRS_DETECTOR = STAIRS_DETECTOR_ACTIVATED;

	BW_PID_Init();
	BW_FollowCounter_Right(5);

	Stairs_Detector();

	if (STAIRS_FLAG == STAIRS_DETECTED)
	{
		BW_Climbing_Stairs();
		STAIRS_FLAG = STAIRS_NOT_DETECTED;
	}

	STAIRS_DETECTOR = STAIRS_DETECTOR_DEACTIVATED;

	for(int i =0; i<3; i++)
	{
		TCS3200_Transmit(UART5,CMD_GET_TRACER);
		if (TCS3200_SLV_BUF[0] == COLOUR_BLACK)break;
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL6,IKCALC_ENABLE);
		TCS3200_Transmit(UART5,CMD_GET_TRACER);
		if (TCS3200_SLV_BUF[0] == COLOUR_BLACK)break;

	}

	BW_PID_Init();
	BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

	Dynamx_MovFwd4cm_Interpolate(8,LEVEL5,IKCALC_ENABLE);
	Dynamx_Slide_Left_Interpolate(HEXSPD_MED,LEVEL4);
	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_FAR2,IKCALC_DISABLE);

	Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);

	BW_PID_Init();
	BW_FollowTracer_Left_Interpolate();

	FLAG_ROOM_1A = FLAG_ROOM_ACTIVE;

	if(TCS3200_SLV_BUF[0] == TRACER_WHITE)
	{
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);
	}
}

/* func      : void Nav_HallwaySC_To_1A(void)
 * brief     : Navigate from HallwaySC to Room 1A
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 25th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_HallwaySC_To_1A(int OPTION)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"SC TO R1A");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	switch(OPTION)
	{
		case 1:
				{
					BW_PID_Init();
					BW_FollowTracer_Left_Interpolate();
					Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);

				}break;
		case 2:
				{
					BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

					BW_PID_Init();
					BW_FollowTracer_Right_Interpolate();

				}break;
	}

}

/* func      : void Nav_3_To_HallwaySC(void)
 * brief     : Navigate from Room 3 to HallwaySC
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 26th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_3_To_HallwaySC(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R3 TO SC");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	while(Ping[PING_FRONT]<=25)
	{
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
	}

	BW_Buzz(2);
	BW_PID_Init();
//	FollowHome_Left();

}

void Nav_3_To_2(void)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R3 TO R2");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
	TRACER_STAT=TRACER_BLACK;

	BW_PID_Init();
	BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

	BW_PID_Init();
	BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

	BW_PID_Init();

	if(Ping[PING_FRONT] < 40)
	{
		Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
		BW_FollowTracer_Right_Interpolate();
	}
	else
	{
		BW_FollowTracer_Right_Interpolate();
	}

	if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)
	{
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);
	}

	FLAG_ROOM_2 = FLAG_ROOM_ACTIVE;
}

/* func      : void Nav_3_To_1A(void)
 * brief     : Navigate from Room 3 to Room 1A
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 26th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_3_To_1A(void)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R3 TO R1A");lcd_putstr(lcd);

	ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;
	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	Dynamx_MovFwd4cm_Interpolate(8,LEVEL6,IKCALC_ENABLE);
	TCS3200_Transmit(UART5,CMD_GET_TRACER);

	if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)
	{
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL6,IKCALC_ENABLE);
	}

	BW_PID_Init();
	BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

	lcd_display_clear();
	lcd_gotoxy(5,0);sprintf(lcd,"FOLLOW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"COUNTER");lcd_putstr(lcd);

	BW_PID_Init();
	BW_FollowCounter_Left(3);

/*	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;*/
	BW_PID_Init();

	while((Ping[PING_FRONT] > 19))
	{
		BW_FollowCounter_Left(1);
	}

//	Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_FAR,IKCALC_DISABLE);

	BW_PID_Init_FAR();
	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
	BWFollowCarpet_Left_Interpolate(COLOUR_BLACK, INVERSE);

	BW_PID_Init_FAR();
	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

	if(CAT_FLAG==CAT_DETECTED)
	{
		CAT_FLAG_A=CAT_DETECTED;
		CAT_DETECTOR=CAT_DIACTIVATED;
		R4ATO1_SP_ROUTE=SP_ROUTE_INACTIVE;

		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
		//Activate special route
		R4ATO3_SP_ROUTE=R4ATO3_SP_ACTIVE;
		R4ATO2_SP_ROUTE=SP_ROUTE_ACTIVE;

		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"CAT A");lcd_putstr(lcd);

		Dynamx_MovBwd_Interpolate(12,LEVEL5,IKCALC_ENABLE);

		Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);

		while(Ping[PING_RIGHT] > 30)
		{
			Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_CLOSE,IKCALC_DISABLE);
		}

		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"COUNTER ON");lcd_putstr(lcd);

		BW_PID_Init();
		int h = 0;
		while(h < 8)
		{
			if(Ping[PING_LEFT] < 30 && Ping[PING_REAR_LEFT] < 30)
			{
				break;
			}
			BW_FollowCounter_Right(1);
			h++;
			if(h>=8)break;
		}

		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"COUNTER OFF");lcd_putstr(lcd);

		if(Ping[PING_LEFT] > 17)
		{
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
		}

		BW_PID_Init();
		BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

		if(Ping[PING_RIGHT] > 17)
		{
			Dynamx_Slide_Right_Interpolate(4,LEVEL4);
		}

		BW_PID_Init();
		BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

		BW_PID_Init();
		BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"TO 1A");lcd_putstr(lcd);

		Dynamx_Rot_Right_Interpolate(LEVEL3, HEXSTEP_CLOSE, IKCALC_DISABLE);

		BW_PID_Init();
		BW_FollowTracer_Right_Interpolate();

		FIREROOM_R1A_FLAG=FIREROOM_R1A_ACTIVE;

	}
	else
	{
		int i;
		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"ARAH CAT B");lcd_putstr(lcd);
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);

		BW_PID_Init();
		BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"CAT B KE CARPET");lcd_putstr(lcd);

		BW_PID_Init();
		BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"ARAH CAT B");lcd_putstr(lcd);

		BW_PID_Init_FAR();
		while(Ping[PING_FRONT] > 20)
		{
			BW_FollowCounter_Left(1);
		}

		Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_FAR, IKCALC_DISABLE);

		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"CARI KUCING");lcd_putstr(lcd);

		BW_PID_Init_FAR();
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
		for(i = 0; i <= 8; i++)
		{
			Cat_Avoider();
			if(CAT_FLAG == CAT_DETECTED)break;
			if(CAT_FLAG == CAT_NOT_DETECTED)
			{
				Cat_Avoider();
				if(CAT_FLAG == CAT_DETECTED)break;
				BW_FollowCounter_Left(1);
			}
			else i = 9;

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)break;
		}

		if(CAT_FLAG==CAT_DETECTED)
		{
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"CAT B");lcd_putstr(lcd);

			CAT_DETECTOR=CAT_DIACTIVATED;
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
			CAT_FLAG_B=CAT_DETECTED;

			Dynamx_MovBwd_Interpolate(3,LEVEL5,IKCALC_ENABLE);

			Nav_TurnAround(TURN_LEFT);

			while(Ping[PING_RIGHT] > 25)
			{
				Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
			}

			BW_PID_Init();
			BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

			if(Ping[PING_ASKEW_RIGHT] + 4 < Ping[PING_REAR_RIGHT])
			{
				Dynamx_Rot_Left_Interpolate(LEVEL3, HEXSTEP_CLOSE, IKCALC_DISABLE);
				if(Ping[PING_ASKEW_RIGHT] + 4 < Ping[PING_REAR_RIGHT])
				{
					Dynamx_Rot_Left_Interpolate(LEVEL3, HEXSTEP_CLOSE, IKCALC_DISABLE);
				}
			}

			Dynamx_MovFwd4cm_Interpolate(4,LEVEL6,IKCALC_ENABLE);

			if(Ping[PING_RIGHT] < 16)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"LEFT");lcd_putstr(lcd);
				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
			}

			if(Ping[PING_LEFT] > 30)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"R4A DETECT");lcd_putstr(lcd);

				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);

				Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_CLOSE,IKCALC_DISABLE);

				BW_PID_Init();
				BW_FollowTracer_Left_Interpolate();

				if(ROOM_4A_MANUAL == 1)ROOM[2] = ROOM_4A;

			}
			else
			{
				if(Ping[PING_RIGHT] < 14)
				{
					Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL4);
					if(Ping[PING_LEFT] > 30)
					{
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"R4A DETECT");lcd_putstr(lcd);

						Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
						Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);

						Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);

						BW_PID_Init();
						BW_FollowTracer_Left_Interpolate();

						if(ROOM_4A_MANUAL == 1)ROOM[2] = ROOM_4A;
					}
					else
					{
						BW_PID_Init();
						BWFollowCarpet_Right_Interpolate(COLOUR_GRAY, INVERSE);
						BW_PID_Init();
						BW_FollowTracer_Left_Interpolate();
						if(ROOM_4A_MANUAL == 1)ROOM[2] = ROOM_4B;
					}
				}
				else
				{
					BW_PID_Init();
					BWFollowCarpet_Right_Interpolate(COLOUR_GRAY, INVERSE);
					BW_PID_Init();
					BW_FollowTracer_Left_Interpolate();
					if(ROOM_4A_MANUAL == 1)ROOM[2] = ROOM_4B;
				}

			}
			ROOM4AB_FLAG=ROOM4AB_ACTIVE;

		}
		else
		{
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

			BW_PID_Init();
			BW_FollowTracer_Left_Interpolate();
			FIREROOM_R1A_FLAG=FIREROOM_R1A_ACTIVE;
			CAT_FLAG_C=CAT_DETECTED;

		}
	}
}
/* func      : void Nav_3_To_1BC(void)
 * brief     : Navigate from Room 3 to Room 1BC
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Thursday, March 26th 2016)
 * Revised BY: Ver2 : Hafidin (Thurs, Feb 23th 2017)
 * programmer's Note:
 */
void Nav_3_To_1BC(void)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R3 TO R1BC");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	Dynamx_Rot_Left_Interpolate(LEVEL4, HEXSTEP_FAR, IKCALC_DISABLE);

	lcd_display_clear();
	lcd_gotoxy(0,1);sprintf(lcd,"COLOUR_BLACK");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R3 TO R1BC");lcd_putstr(lcd);

	BW_PID_Init();
	BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

	lcd_gotoxy(0,1);sprintf(lcd,"COLOUR_BLACK 2");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R3 TO R1BC");lcd_putstr(lcd);

	BW_PID_Init();
	BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);
	Dynamx_MovFwd4cm_Interpolate(3,LEVEL6,IKCALC_ENABLE);

	Dynamx_Rot_Left_Interpolate(LEVEL3, HEXSTEP_CLOSE, IKCALC_DISABLE);

	if(Ping[PING_LEFT]>=30)
	{
		lcd_display_clear();
		lcd_gotoxy(0,3);sprintf(lcd,"R1B detected");lcd_putstr(lcd);

		SP_FIRE_1B=SP_FIRE_ACTIVE;
		if(Ping[PING_RIGHT] < 15 || Ping[PING_ASKEW_RIGHT] < 16)
		{
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
		}
		if(Ping[PING_RIGHT] < 15 || Ping[PING_ASKEW_RIGHT] < 16)
		{
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
		}
		Dynamx_Rot_Left_Interpolate(LEVEL3, HEXSTEP_MED, IKCALC_DISABLE);
		Dynamx_Rot_Left_Interpolate(LEVEL3, HEXSTEP_MED, IKCALC_DISABLE);
	}
	else
	{
		lcd_display_clear();
		lcd_gotoxy(0,3);sprintf(lcd,"R1C detected");lcd_putstr(lcd);

		Dynamx_Slide_Left_Interpolate(HEXSTEP_CLOSE,LEVEL3);
		Dynamx_MovFwd4cm_Interpolate(3,LEVEL4,IKCALC_ENABLE);
		SP_FIRE_1C=SP_FIRE_ACTIVE;
	}

	BW_PID_Init();
	BW_FollowTracer_Left_Interpolate();

}

/* func      : void Nav_3_To_4A(void)
 * brief     : Navigate from Room 3 to Room 4A
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Thursday, March 26th 2016)
 * Revised BY: Ver2 : Hafidin (Friday, Feb 24th 2017)
 * programmer's Note:
 */
void Nav_3_To_4A(void)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R3 TO R4A");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	BW_Buzz(1);
	BW_PID_Init();
	BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

	Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);

	Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);

	BW_PID_Init();
	int fol_count = 0;
	for(fol_count = 0; fol_count <= 11; fol_count++)
	{
		BW_FollowCounter_Left(1);
		if(Ping[PING_FRONT] < 17)break;
	}

	ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;
	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

	//DEFAULT ROUTE
	if (R2TO4A_SP_ROUTE==R2TO4A_SP_INACTIVE)
	{
		BW_PID_Init_FAR();
		BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

		if(CAT_FLAG==CAT_NOT_DETECTED)
		{
			ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_INACTIVE;
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;;

			Dynamx_MovFwd4cm_Interpolate(8,LEVEL4,IKCALC_ENABLE);

			if(Ping[PING_RIGHT]<30)
			{
				Nav_TurnAround(TURN_RIGHT);

				BW_PID_Init();
				BW_FollowTracer_Left_Interpolate();

				if(ROOM_4A_MANUAL == 1)ROOM[2] = ROOM_4B;
			}
			else
			{
				Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);

				Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_FAR,IKCALC_DISABLE);

				BW_PID_Init();
				BW_FollowTracer_Right_Interpolate();

				if(ROOM_4A_MANUAL==1)ROOM[2] = ROOM_4A;
			}
		}

		if(CAT_FLAG==CAT_DETECTED)
		{
			R4ATO3_SP_ROUTE=R4ATO3_SP_ACTIVE;
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"ALTERNATE");lcd_putstr(lcd);
			lcd_gotoxy(8,1);sprintf(lcd,"ROUTE");lcd_putstr(lcd);
			delay_ms(100);

			Dynamx_MovBwd_Interpolate(12,LEVEL5,IKCALC_ENABLE);

			Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_MED,IKCALC_DISABLE);

			Dynamx_MovFwd4cm_Interpolate(12,LEVEL4,IKCALC_ENABLE);

			CAT_FLAG=CAT_NOT_DETECTED;
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);

			BW_PID_Init();
			BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,NORMAL);

			BW_PID_Init();
			BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,NORMAL);

			BW_PID_Init();
			BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,NORMAL);

			BW_PID_Init();
			BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,NORMAL);

			Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);

			BW_PID_Init();
			BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

			if(Ping[PING_RIGHT]<=15)
			{
				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
			}

			if((Ping[PING_LEFT]>=20) && (Ping[PING_ASKEW_LEFT]>=20))
			{
				Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_MED,IKCALC_DISABLE);
			}
			else
			{
				Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
				Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
			}

			BW_PID_Init();
			BW_FollowTracer_Left_Interpolate();

			if(ROOM_4A_MANUAL == 1)ROOM[2]=ROOM_4A;
		}
	}
	else if (R2TO4A_SP_ROUTE==R2TO4A_SP_ACTIVE)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"SPECIAL");lcd_putstr(lcd);
		lcd_gotoxy(8,1);sprintf(lcd,"ROUTE");lcd_putstr(lcd);
		lcd_gotoxy(3,2);sprintf(lcd,"R3 TO R4");lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"CAT CONFIG A");lcd_putstr(lcd);
		delay_ms(100);

		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

		Nav_TurnAround(TURN_LEFT);

		BW_PID_Init();
		BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

		BW_PID_Init();
		BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

		BW_PID_Init();
		BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

		Dynamx_Rot_Left_Interpolate(LEVEL3, HEXSTEP_MED, IKCALC_DISABLE);

		BW_PID_Init();
		BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

		Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);

		BW_PID_Init();
		BW_FollowTracer_Left_Interpolate();

		if(ROOM_4A_MANUAL == 1)ROOM[2] = ROOM_4A;
	}

	ROOM4AB_FLAG=ROOM4AB_ACTIVE;

}

/* func      : void Nav_3_To_4B(void)
 * brief     : Navigate from Room 3 to Room 4B
 * param     : N/A
 * retval    : N/A
 * Ver       : 3
 * written By: Ryan (Thursday, March 26th 2016)
 * Revised BY: Ver.2 - Ryan (Wednesday, May 19th 2016)
 * 			   Ver.3 - Hafidin (Friday, Feb 24th 2017)
 * programmer's Note:
 */
void Nav_3_To_4B(void)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R3 TO R4B");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	BW_PID_Init();
	BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

	BW_PID_Init();
	BW_FollowCounter_Left(12);

	Nav_TurnAround(TURN_RIGHT);

	BW_PID_Init();
	BW_FollowTracer_Left_Interpolate();

	ROOM4AB_FLAG=ROOM4AB_ACTIVE;
}

void Nav_3_To_4B_V2(void)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R3 TO R4B");lcd_putstr(lcd);
	delay_ms(50);

	BW_PID_Init();
	BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

	Dynamx_MovFwd4cm_Interpolate(4,LEVEL6,IKCALC_ENABLE);

	BW_PID_Init();
	BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,NORMAL);


	Dynamx_Rot_Left_IK(LEVEL6,STEP4);
	Dynamx_Rot_Left_IK(LEVEL6,STEP4);

	Dynamx_MovFwd4cm_Interpolate(4,LEVEL6,IKCALC_ENABLE);

	BW_PID_Init();
	BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,NORMAL);

	BW_PID_Init();
	BW_FollowCounter_Right(5);

	if(Ping[PING_LEFT]>20)
	{
		Dynamx_Slide_Left_Interpolate(HEXSPD_MED,LEVEL4);
		Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_FAR2,IKCALC_DISABLE);
	}

	BW_PID_Init();
	BW_FollowTracer_Left_Interpolate();

	if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)
	{
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
	}

	if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)
	{
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
	}

	FLAG_ROOM_4B = FLAG_ROOM_ACTIVE;

//	for(int i=0; i<10; i++)
//	{
//		TCS3200_Transmit(UART5,CMD_GET_TRACER);
//		if (TCS3200_SLV_BUF[0] == COLOUR_BLACK)break;
//		Dynamx_MovFwd4cm_Interpolate(4,LEVEL6,IKCALC_ENABLE);
//		TCS3200_Transmit(UART5,CMD_GET_TRACER);
//		if (TCS3200_SLV_BUF[0] == COLOUR_BLACK)break;
//	}
//
//	Dynamx_MovFwd4cm_Interpolate(8,LEVEL6,IKCALC_ENABLE);
//
//	if (Ping[PING_RIGHT]<10)
//	{
//		Dynamx_Slide_Left_Interpolate(HEXSPD_MED,LEVEL5);
//		Dynamx_Slide_Left_Interpolate(HEXSPD_MED,LEVEL5);
//	}
//
//	else
//	{
//		Dynamx_Slide_Left_Interpolate(HEXSPD_MED,LEVEL5);
//	}
//
//	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_FAR2,IKCALC_DISABLE);
//
//	BW_PID_Init();
//	BW_FollowTracer_Left_Interpolate();
//
//	FLAG_ROOM_4B = FLAG_ROOM_ACTIVE;
//
//	if(TCS3200_SLV_BUF[0] == TRACER_WHITE)
//	{
//		Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);
//	}
}

/* func      : void Nav_2_To_HallwaySC(void)
 * brief     : Navigate from Room 2 to HallwaySC
 * param     : N/A
 * retval    : N/A
 * Ver       : 13.
 * *.3.*
 * +--
 * written By: Ryan (Thursday, March 27th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_2_To_HallwaySC(void)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R2 TO SC");lcd_putstr(lcd);
	delay_ms(100);

	if (Ping[PING_FRONT]<10)
	{
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL6,IKCALC_ENABLE);
		if (Ping[PING_FRONT]<10)
		{
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL6,IKCALC_ENABLE);
		}
	}

	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_FAR2,IKCALC_DISABLE);

	Dynamx_Slide_Right_Interpolate(HEXSPD_MED,LEVEL5);
	Dynamx_Slide_Right_Interpolate(HEXSPD_MED,LEVEL5);

	if (Ping[PING_RIGHT]>10)
	{
		Dynamx_Slide_Right_Interpolate(HEXSPD_MED,LEVEL5);
	}

	Dynamx_MovFwd4cm_Interpolate(12,LEVEL5,IKCALC_ENABLE);

	BW_PID_Init();
	BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

	if ((Ping[PING_LEFT]) <= (Ping[PING_REAR_LEFT]+4))
	{
		Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		if ((Ping[PING_LEFT]) <= (Ping[PING_REAR_LEFT]+4))
		{
			Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		}
	}

	if ((Ping[PING_LEFT]) >= (Ping[PING_REAR_LEFT]+4))
	{
		Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		if ((Ping[PING_LEFT]) >= (Ping[PING_REAR_LEFT]+4))
		{
			Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		}
	}


	STAIRS_DETECTOR = STAIRS_DETECTOR_ACTIVATED;

	Dynamx_MovFwd4cm_Interpolate(24,LEVEL4,IKCALC_ENABLE);

	Stairs_Detector();

	if (STAIRS_FLAG == STAIRS_DETECTED)
	{
		BW_Climbing_Stairs();
		STAIRS_FLAG = STAIRS_NOT_DETECTED;
	}

	STAIRS_DETECTOR = STAIRS_DETECTOR_DEACTIVATED;

	if (Ping[PING_LEFT]<10)
	{
		Dynamx_Slide_Left_Interpolate(HEXSPD_MED,LEVEL3);
	}

	BW_PID_Init();
	while ((Ping[PING_FRONT] >= FRONT_THRESHOLD))
	{
		if ((Ping[PING_FRONT] <= FRONT_THRESHOLD) && (SHARP[IR_FRONT] <= 13))break;
		BW_FollowCounter_Left(1);
		if ((Ping[PING_FRONT] <= FRONT_THRESHOLD) && (SHARP[IR_FRONT] <= 13))break;
	}
}


void Nav_2A_To_1BC(void)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R2A TO R1BC");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	BW_PID_Init();

	if(Ping[PING_FRONT] < 40)
	{
		Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
		BW_FollowTracer_Right_Interpolate();
	}
	else
	{
		BW_FollowTracer_Right_Interpolate();
	}

	FLAG_ROOM_1A = FLAG_ROOM_ACTIVE;
}

/* func      : void Nav_2B_To_1BC(void)
 * brief     : Navigate from Room 2 to Room 1BC
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Wednesday, April 14th 2016)
 * Revised BY: Ver2 : Hafidin (Wed, Feb 23th 2017)
 * programmer's Note:
 */
void Nav_2B_To_1BC(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R2B TO ROOM 1BC");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
	TRACER_STAT=TRACER_BLACK;

	BW_Buzz(1);
	BW_PID_Init();
	BW_FollowTracer_Right_Interpolate();
}


/* func      : void Nav_2_To_3(void)
 * brief     : Navigate from Room 2 to Room 3
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Thursday, March 27th 2016)
 * Revised BY: Ver2 : Hafidin (Wed, Feb 23th 2017)
 * programmer's Note:
 */
void Nav_2_To_3(void)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R2 TO R3");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	if(EXTINGUISHED_FIRE==1)
	{
		if(Ping[PING_RIGHT] < 20 || Ping[PING_ASKEW_RIGHT] < 20)
		{
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
		}

		if(Ping[PING_RIGHT] < 20 || Ping[PING_ASKEW_RIGHT] < 20)
		{
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
		}

		Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_CLOSE,IKCALC_DISABLE);
		Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

		if(Ping[PING_ASKEW_LEFT] <= 9 || Ping[PING_UP_LEFT] <= 9)
		{
			Dynamx_Rot_Right_Interpolate(LEVEL3, HEXSTEP_MED, IKCALC_DISABLE);
			Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);
		}
	}
	else
	{
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL5, IKCALC_ENABLE);
		if(Ping[PING_RIGHT] < 20 || Ping[PING_ASKEW_RIGHT] < 20)
		{
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
		}

		if(Ping[PING_RIGHT] < 20 || Ping[PING_ASKEW_RIGHT] < 20)
		{
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
		}

		Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_CLOSE,IKCALC_DISABLE);
		Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

		if(Ping[PING_ASKEW_LEFT] <= 14 || Ping[PING_UP_LEFT] <= 14)
		{
			Dynamx_Rot_Right_Interpolate(LEVEL3, HEXSTEP_MED, IKCALC_DISABLE);
			Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);
		}
	}

	if(ROOM_2_1BC_MANUAL == 0)
	{

	}

	if(ROOM_2_1BC_MANUAL == 1)
	{
		//ON PROCESS
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL3,IKCALC_ENABLE);
	}

	BW_PID_Init();
	int l;
	for(l = 0;l <= 2;l++)
	{
		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1] == COLOUR_GRAY)break;
		if(((Ping[PING_ASKEW_LEFT] < 11 || Ping[PING_LEFT] < 11)))
		{
			BW_FollowCounter_Left(1);
		}
		else if(Ping[PING_ASKEW_RIGHT] < 11 || Ping[PING_RIGHT] < 11)
		{
			BW_FollowCounter_Right(1);
		}

		else Dynamx_MovFwd4cm_Interpolate(4,LEVEL6, IKCALC_ENABLE);
		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1] == COLOUR_GRAY)break;
	}

	BW_PID_Init();
	BW_FollowTracer_Left_Interpolate();
}

void Nav_3_To_4AB(void)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R3 TO R4");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
	CAT_FLAG = CAT_NOT_DETECTED;

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"MAJU");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"ASHIAP");lcd_putstr(lcd);
	Dynamx_MovFwd4cm_Interpolate(12,LEVEL6,IKCALC_ENABLE);

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"MUTER");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"KIRI");lcd_putstr(lcd);
	Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
	Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_MED,IKCALC_DISABLE);

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"FOLLOW KANAN");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"CARPET IN");lcd_putstr(lcd);

	BW_PID_Init();
	BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

	Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);


	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"FOLLOW KIRI");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"Counter");lcd_putstr(lcd);
	BW_PID_Init();

	while(Ping[PING_FRONT] > 18)
	{
		BW_FollowCounter_Left(1);
	}
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"MUTER");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"KANAN");lcd_putstr(lcd);
	Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
	Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);

	BW_PID_Init_FAR();
	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

		TCS3200_Transmit(UART5,CMD_GET_TRACER);
		while(TCS3200_SLV_DATA[1] == COLOUR_GRAY)
		{
			TCS3200_Transmit(UART5,CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1] == COLOUR_BLACK){break;}
			Cat_Avoider();
			if(CAT_FLAG == CAT_DETECTED){break;}
			BW_FollowCounter_Left(1);
		}


	if(CAT_FLAG == CAT_DETECTED)
	{
		CAT_FLAG_A = CAT_DETECTED;

		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"CAT DETECT");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"CAT A");lcd_putstr(lcd);
		delay_ms(100);

		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

		Dynamx_MovBwd_Interpolate(4,LEVEL6,IKCALC_ENABLE);
		Dynamx_MovBwd_Interpolate(4,LEVEL6,IKCALC_ENABLE);
		Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_Slide_Right_Interpolate(HEXSTEP_CLOSE, LEVEL3);
		Dynamx_Slide_Right_Interpolate(HEXSTEP_CLOSE, LEVEL3);

			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"CAT A");lcd_putstr(lcd);
			lcd_gotoxy(4,1);sprintf(lcd,"ALTERNATE R");lcd_putstr(lcd);
			delay_ms(100);
			BW_PID_Init();


			while(Ping[PING_REAR_LEFT] > 30)
			{
				BW_FollowCounter_Right(1);
			}

			Dynamx_Slide_Left_Interpolate(HEXSTEP_CLOSE, LEVEL3);
			BW_PID_Init();
			BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);
			if(/*Ping[PING_ASKEW_LEFT] > 40 && */Ping[PING_LEFT] >= 30)
			{
				lcd_display_clear();
				lcd_gotoxy(2,0);sprintf(lcd,"CAT A");lcd_putstr(lcd);
				lcd_gotoxy(4,1);sprintf(lcd,"TO 4B");lcd_putstr(lcd);

				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
				Dynamx_Rot_Left_Interpolate(LEVEL6,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Rot_Left_Interpolate(LEVEL6,HEXSTEP_MED,IKCALC_DISABLE);

				BW_PID_Init();
				BW_FollowTracer_Left_Interpolate();
				if(ROOM_4B_MANUAL == 1)
				{
					ROOM[2] = ROOM_4B;
				}
			}
			else
			{
				lcd_display_clear();
				lcd_gotoxy(2,0);sprintf(lcd,"CAT A");lcd_putstr(lcd);
				lcd_gotoxy(4,1);sprintf(lcd,"TO 4A");lcd_putstr(lcd);
				delay_ms(100);
				BW_PID_Init();
				BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);
				Dynamx_MovFwd4cm_Interpolate(4,LEVEL6,IKCALC_ENABLE);

				BW_PID_Init();
				BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);
				Dynamx_MovFwd4cm_Interpolate(4,LEVEL6,IKCALC_ENABLE);

				BW_PID_Init();
				BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);
				Dynamx_MovFwd4cm_Interpolate(4,LEVEL6,IKCALC_ENABLE);

				Dynamx_Slide_Left_Interpolate(4,LEVEL6);
				Dynamx_Rot_Left_Interpolate(LEVEL6,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_MED,IKCALC_DISABLE);

				BW_PID_Init();
				BW_FollowTracer_Left_Interpolate();
				if(ROOM_4B_MANUAL == 1)
				{
					ROOM[2] = ROOM_4A;
				}
			}

	}


	else
		{
			int stat_room = 0;
			CAT_FLAG_A = CAT_NOT_DETECTED;
			Dynamx_MovFwd4cm_Interpolate(8,LEVEL6,IKCALC_ENABLE);
			BW_PID_Init();
			BWFollowCarpet_Left_Interpolate(COLOUR_GRAY, INVERSE);

			Dynamx_MovFwd4cm_Interpolate(4,LEVEL6,IKCALC_ENABLE);

				SHIFT_ALGORITHM_FLAG = SHIFT_ALGORITHM_ACTIVE;
				BW_PID_Init_FAR();
				BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);
				if(CAT_FLAG == CAT_DETECTED)
				{
					CAT_FLAG_B = CAT_DETECTED;
					SHIFT_ALGORITHM_FLAG = SHIFT_ALGORITHM_INACTIVE;
					lcd_display_clear();
					lcd_gotoxy(2,0);sprintf(lcd,"CAT B");lcd_putstr(lcd);
					lcd_gotoxy(4,1);sprintf(lcd,"ALTERNATE R");lcd_putstr(lcd);
					if(CAT_FLAG_B == CAT_DETECTED)
					{
						Dynamx_MovBwd_Interpolate(6,LEVEL6,IKCALC_DISABLE);
						Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
						Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_FAR,IKCALC_DISABLE);
						while(Ping[PING_FRONT] < 20)
						{
							Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
						}

						lcd_display_clear();
						lcd_gotoxy(2,0);sprintf(lcd,"CAT B");lcd_putstr(lcd);

						BW_PID_Init();
						BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);
						Dynamx_MovFwd4cm_Interpolate(4,LEVEL6,IKCALC_ENABLE);

						if(/*Ping[PING_ASKEW_LEFT] > 40 && */Ping[PING_LEFT] >= 30 )
						{
							Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
							Dynamx_Rot_Left_Interpolate(LEVEL6,HEXSTEP_FAR,IKCALC_DISABLE);
							Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);

							BW_PID_Init();
							BW_FollowTracer_Left_Interpolate();

							if(ROOM_4B_MANUAL == 1)
							{
								ROOM[2] = ROOM_4A;
							}
						}
						else
						{
						BW_PID_Init();
						BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);
						Dynamx_MovFwd4cm_Interpolate(4,LEVEL6,IKCALC_ENABLE);

						BW_PID_Init();
						BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);
						Dynamx_MovFwd4cm_Interpolate(4,LEVEL6,IKCALC_ENABLE);

						Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
						Dynamx_Rot_Left_Interpolate(LEVEL6,HEXSTEP_FAR,IKCALC_DISABLE);
						Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_MED,IKCALC_DISABLE);

						BW_PID_Init();
						BW_FollowTracer_Left_Interpolate();
						if(ROOM_4B_MANUAL == 1)
						{
							ROOM[2] = ROOM_4B;
						}
						}
					}
				}

				else
				{
					BW_PID_Init();
					BW_FollowCounter_Left(1);

//					Nav_TurnAround(TURN_LEFT);
//					BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);
					Dynamx_MovFwd4cm_Interpolate(4,LEVEL3,IKCALC_ENABLE);
					Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_FAR,IKCALC_DISABLE);
					Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
					Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
					delay_ms(500);
					Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_FAR,IKCALC_DISABLE);
					Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);


						lcd_display_clear();
						lcd_gotoxy(2,0);sprintf(lcd,"CAT C");lcd_putstr(lcd);
						lcd_gotoxy(4,1);sprintf(lcd,"ALTERNATE R");lcd_putstr(lcd);
						CAT_FLAG_C = CAT_DETECTED;
						SHIFT_ALGORITHM_FLAG = SHIFT_ALGORITHM_INACTIVE;


							lcd_display_clear();
							lcd_gotoxy(2,0);sprintf(lcd,"CAT C");lcd_putstr(lcd);

							BW_PID_Init();
							BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

							BW_PID_Init();
							BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);
							Dynamx_MovFwd4cm_Interpolate(8,LEVEL6,IKCALC_ENABLE);
							if(/*Ping[PING_ASKEW_LEFT] > 40 && */Ping[PING_LEFT] >= 30)
							{
								Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL4);
								Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_FAR,IKCALC_DISABLE);
								Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
								BW_FollowTracer_Left_Interpolate();
								if(ROOM_4B_MANUAL == 1)
								{
									ROOM[2] = ROOM_4A;
								}
							}
//
//							BW_PID_Init();
//							BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);
//							Dynamx_MovFwd4cm_Interpolate(4,LEVEL6,IKCALC_DISABLE);

//							BW_PID_Init();
//							BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);
//							Dynamx_MovFwd4cm_Interpolate(4,LEVEL6,IKCALC_DISABLE);
//							Dynamx_MovFwd4cm_Interpolate(4,LEVEL6,IKCALC_DISABLE);
//
//							Dynamx_Slide_Left_Interpolate(4,LEVEL6);
//							Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
//							Dynamx_Rot_Left_Interpolate(LEVEL6,HEXSTEP_MED,IKCALC_DISABLE);
//							Dynamx_Slide_Left_Interpolate(HEXSTEP_CLOSE,LEVEL4);

							BW_PID_Init();
							BW_FollowTracer_Left_Interpolate();
							if(ROOM_4B_MANUAL == 1)
							{
								ROOM[2] = ROOM_4B;
							}


//					Cat_Avoider();
//					if(CAT_FLAG == CAT_DETECTED)
//					{
//						Dynamx_MovBwd_Interpolate(4,LEVEL6,IKCALC_ENABLE);
//						Dynamx_Rot_Right_Interpolate(LEVEL6,HEXSTEP_FAR,IKCALC_DISABLE);
//						Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_FAR,IKCALC_DISABLE);
//					}

				}


		}



}

void Nav_4A_To_2_NEW(void)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R4A TO R2");lcd_putstr(lcd);
	delay_ms(100);

	Dynamx_MovFwd4cm_Interpolate(4,LEVEL6,IKCALC_ENABLE);
	Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
	Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);

	SHIFT_ALGORITHM_FLAG = SHIFT_ALGORITHM_INACTIVE;

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"ROAD TO");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"R3 LUR");lcd_putstr(lcd);
	delay_ms(100);

	TCS3200_Transmit(UART5,CMD_GET_TRACER);
	while(TCS3200_SLV_DATA[1]==COLOUR_BLACK)
	{
		TCS3200_Transmit(UART5,CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1]==COLOUR_GRAY){break;}
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL6,IKCALC_ENABLE);
		TCS3200_Transmit(UART5,CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1]==COLOUR_GRAY){break;}
	}

	if(Ping[PING_REAR_RIGHT] < 7 )
	{
		Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_MED,IKCALC_DISABLE);
	}

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"FOLLOW KIRI");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"CARPET IN");lcd_putstr(lcd);
	delay_ms(100);
	BW_PID_Init();
	BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"MUTER");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"LUR");lcd_putstr(lcd);
	delay_ms(100);
	Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
	Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
	Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL6);

	TCS3200_Transmit(UART5,CMD_GET_TRACER);
	while(TCS3200_SLV_DATA[1]==COLOUR_BLACK)
	{
		TCS3200_Transmit(UART5,CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1]==COLOUR_GRAY){break;}
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL6,IKCALC_DISABLE);
		TCS3200_Transmit(UART5,CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1]==COLOUR_GRAY){break;}
	}

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"FOLLOW KIRI");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"CARPET IN");lcd_putstr(lcd);
	delay_ms(100);

	BW_PID_Init();
	BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

	if(Ping[PING_ASKEW_RIGHT] > 11 || Ping[PING_RIGHT] > 11)
	{
		Dynamx_Slide_Right_Interpolate(HEXSPD_FAST,LEVEL3);
		Dynamx_Slide_Right_Interpolate(HEXSPD_FAST,LEVEL3);
	}

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"FOLLOW KANAN");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"CARPET IN");lcd_putstr(lcd);
	delay_ms(100);
	BW_PID_Init();
	if(Ping[PING_ASKEW_RIGHT] < 10 || Ping[PING_RIGHT] < 10)
	{	lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"FOLLOW KANAN");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"CARPET IN");lcd_putstr(lcd);
		delay_ms(100);
		while(Ping[PING_ASKEW_RIGHT] < 10 || Ping[PING_RIGHT] < 10)
		{
			if(Ping[PING_ASKEW_RIGHT] >= 10 || Ping[PING_RIGHT] >= 10){break;}
			BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);
			if(Ping[PING_ASKEW_RIGHT] >= 10 || Ping[PING_RIGHT] >= 10){break;}
		}
	}

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"FOLLOW KANAN");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"TRACER");lcd_putstr(lcd);
	delay_ms(100);
	BW_PID_Init();
	BW_FollowTracer_Right_Interpolate();
}


/* func      : void Nav_2_To_4A_NEW_VER2(void)
 * brief     : Navigate from Room 2 to Room 4A Alternatif CAT A NOT CHECKED
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Toni (Monday, March 12th 2018)
 * Revised BY:
 * programmer's Note:
 */
void Nav_2_To_4A(void)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R2 TO R4A NEW");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	if(EXTINGUISHED_FIRE==0)
	{
			BW_PID_Init();
			if(Ping[PING_RIGHT] < 25 || Ping[PING_ASKEW_RIGHT] < 25)
			{
				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
			}

			if(Ping[PING_RIGHT] < 25 || Ping[PING_ASKEW_RIGHT] < 25)
			{
				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
			}

			Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_CLOSE,IKCALC_DISABLE);
			Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_CLOSE,IKCALC_DISABLE);

			if(Ping[PING_ASKEW_LEFT] > 17)
			{
				if(Ping[PING_ASKEW_LEFT] > 17)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				}
			}

			if(Ping[PING_REAR_RIGHT] < Ping[PING_ASKEW_RIGHT])
			{
				Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			}
			if(Ping[PING_ASKEW_LEFT] <= 9 || Ping[PING_UP_LEFT] <= 9)
			{
//				Dynamx_Rot_Right_Interpolate(LEVEL3, HEXSTEP_MED, IKCALC_DISABLE);
				Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);
			}

			if(ROOM_2_1BC_MANUAL == 0)
			{

			}

			if(ROOM_2_1BC_MANUAL == 1)
			{
				Dynamx_MovFwd4cm_Interpolate(4,LEVEL3,IKCALC_DISABLE);
			}

			BW_PID_Init();
			lcd_display_clear();

			BW_PID_Init();
			int l;
			for(l = 0;l <= 2;l++)
			{
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1] == COLOUR_GRAY)break;
				if(((Ping[PING_ASKEW_LEFT] < 15 || Ping[PING_LEFT] < 15)))
				{
					BW_FollowCounter_Left(1);

				}
				else if(Ping[PING_ASKEW_RIGHT] < 11 || Ping[PING_RIGHT] < 11)
				{
					BW_FollowCounter_Right(1);
				}

				else Dynamx_MovFwd4cm_Interpolate(4,LEVEL6, IKCALC_ENABLE);

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1] == COLOUR_GRAY)break;
			}

			BW_PID_Init();
			BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

			Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_CLOSE,IKCALC_DISABLE);

			if(Ping[PING_FRONT]<19)
			{
				while(Ping[PING_FRONT]<19)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_FAR,IKCALC_DISABLE);
				}
			}
			if(Ping[PING_LEFT] <= 15)
			{
				Dynamx_Slide_Right_Interpolate(HEXSTEP_CLOSE, LEVEL3);
			}

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"KOREKSI");lcd_putstr(lcd);

				Dynamx_Rot_Right_Interpolate(LEVEL3, HEXSTEP_MED, IKCALC_DISABLE);

			if(Ping[PING_RIGHT] <= 10 || Ping[PING_ASKEW_RIGHT] <= 10)
			{
				Dynamx_Slide_Left_Interpolate(HEXSTEP_CLOSE,LEVEL3);
			}
			if(Ping[PING_RIGHT] <= 10 || Ping[PING_ASKEW_RIGHT] <= 10)
			{
				Dynamx_Slide_Left_Interpolate(HEXSTEP_CLOSE,LEVEL3);
			}

//			Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd," FOLLOW ABU");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd," BELOK KE 4B");lcd_putstr(lcd);

			BW_PID_Init();
			BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"HALLWAY 4AB");lcd_putstr(lcd);

		if(Ping[PING_ASKEW_RIGHT] < 10)
		{
			Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
//			Dynamx_Slide_Left_Interpolate(HEXSTEP_CLOSE, IKCALC_DISABLE);
		}

		else if(Ping[PING_ASKEW_LEFT] < 10)
		{
			Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
//			Dynamx_Slide_Right_Interpolate(HEXSTEP_CLOSE, IKCALC_DISABLE);

		}

		if((Ping[PING_LEFT] >= 30))
		{
			if(Ping[PING_RIGHT] > 16)
			{
				Dynamx_Slide_Right_Interpolate(HEXSTEP_CLOSE, LEVEL5);
			}

			Cat_Avoider();
			CAT_FLAG=CAT_NOT_DETECTED;
			ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;

			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd," FOLLOW CARPET");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd," ABU 1");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"R4B DETECT");lcd_putstr(lcd);

			CAT_DETECTOR = CAT_ACTIVATED;
			BW_PID_Init_FAR();
			BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

			if(CAT_FLAG==CAT_DETECTED)			// CAT C
			{
				CAT_DETECTOR=CAT_DIACTIVATED;
				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
				CAT_FLAG_C=CAT_DETECTED;

				Dynamx_MovBwd_Interpolate(4,LEVEL5,IKCALC_ENABLE);

				Nav_TurnAround(TURN_RIGHT);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

				Dynamx_MovFwd4cm_Interpolate(4, LEVEL3, IKCALC_ENABLE);

				if(Ping[PING_LEFT] < 12)
				{
					Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);
				}

				Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_MED,IKCALC_DISABLE);
				Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_MED,IKCALC_DISABLE);

//				Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_MED,IKCALC_DISABLE);
//
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL3, IKCALC_ENABLE);
////============================= tmbhn
				BW_PID_Init();
				BW_FollowCounter_Right(4);


				FIREROOM_R1A_FLAG=FIREROOM_R1A_ACTIVE;

			}
			else //CAT C KOSONG
			{
				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

//				Dynamx_MovFwd4cm_Interpolate(,LEVEL5,IKCALC_DISABLE);

	//			Dynamx_MovFwd4cm_Interpolate(4,50,IKCALC_DISABLE);

	//			Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_CLOSE,IKCALC_DISABLE);


				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

//				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, 100);
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
				Dynamx_Rot_Left_Interpolate(LEVEL3, HEXSTEP_MED, IKCALC_DISABLE);
//				Dynamx_Rot_Left_Interpolate(LEVEL3, HEXSTEP_CLOSE, IKCALC_DISABLE);

				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
				CAT_DETECTOR = CAT_ACTIVATED;
				BW_PID_Init();
				BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

				if(CAT_FLAG==CAT_NOT_DETECTED)
				{
					BW_Buzz(1);
					if(Ping[PING_REAR_LEFT] < 10 || Ping[PING_LEFT] < 10)
					{
						Dynamx_Slide_Right_Interpolate(HEXSTEP_CLOSE,LEVEL5);
					}
					if(Ping[PING_REAR_LEFT] < 10 || Ping[PING_LEFT] < 10)
					{
						Dynamx_Slide_Right_Interpolate(HEXSTEP_CLOSE,LEVEL5);
					}
					BW_PID_Init();
					BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);
				}
				if(CAT_FLAG==CAT_DETECTED)			// CAT B
				{
					SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

					CAT_DETECTOR=CAT_DIACTIVATED;
					CAT_FLAG=CAT_NOT_DETECTED;
					CAT_FLAG_B=CAT_DETECTED;
					REVERSE_FLAG=REVERSEFLAG_ACTIVE;

					R4ATO1_SP_ROUTE=SP_ROUTE_ACTIVE;

					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"ALTERNATE");lcd_putstr(lcd);
					lcd_gotoxy(8,1);sprintf(lcd,"ROUTE");lcd_putstr(lcd);

					Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
					Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);

					while(Ping[PING_FRONT]<25)
					{
						Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_CLOSE,IKCALC_DISABLE);
					}

					//Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);

					BW_Buzz(1);
					BW_PID_Init();
					BW_FollowTracer_Right_Interpolate();

				}
				else //CAT B kosong
				{
					Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);

					R4ATO1_SP_ROUTE=SP_ROUTE_INACTIVE;

					SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
					//Activate special route
					R4ATO3_SP_ROUTE=R4ATO3_SP_ACTIVE;
					R4ATO2_SP_ROUTE=SP_ROUTE_ACTIVE;

					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					BW_PID_Init();
					int cat_count_step = 0;
					while(SHARP[SHARP_FRONT_L] >= 15 && TCS3200_SLV_DATA[1] != COLOUR_GRAY)
					{
						if(cat_count_step >= 3)break;
						TCS3200_Transmit(UART5, CMD_GET_TRACER);
						BW_FollowCounter_Left(1);
						cat_count_step++;
					}
					cat_count_step = 0;

					CAT_DETECTOR=CAT_DIACTIVATED;
					CAT_FLAG=CAT_NOT_DETECTED;
					CAT_FLAG_B=CAT_DETECTED; // FOR RETURN TRIP

					R4ATO1_SP_ROUTE=SP_ROUTE_ACTIVE;

					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"CAT A");lcd_putstr(lcd);
					lcd_gotoxy(8,1);sprintf(lcd,"FLAG ACTIVE");lcd_putstr(lcd);

					Dynamx_MovBwd_Interpolate(6, LEVEL6, IKCALC_DISABLE);

					Nav_TurnAround(TURN_LEFT);


					BW_Buzz(1);
					BW_PID_Init();
					BW_FollowTracer_Right_Interpolate();

					if(ROOM_4A_MANUAL == 1)ROOM[2] = ROOM_4B;
				}
			}
		}
		else
		{
			lcd_display_clear();
			lcd_gotoxy(0,2);sprintf(lcd,"R4A DETECT");lcd_putstr(lcd);

//			if(Ping[PING_RIGHT] > 16)
//			{
//				Dynamx_Slide_Right_Interpolate(HEXSTEP_CLOSE, LEVEL5);
//			}
//			Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);

			if(CAT_FLAG_C==CAT_DETECTED)
			{
				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

				Dynamx_MovBwd_Interpolate(6, LEVEL6, IKCALC_DISABLE);
				Nav_TurnAround(TURN_RIGHT);
				if(Ping[PING_RIGHT] < 12)
				{
					Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, 100);
				}
				else if(Ping[PING_LEFT] <12)
				{
					Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,100);
				}

				Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);

				BW_Buzz(1);
				BW_PID_Init();
				BW_FollowTracer_Right_Interpolate();

				if(ROOM_4B_MANUAL == 1)ROOM[2] = ROOM_4A;

			}
			else
			{
				if(Ping[PING_ASKEW_RIGHT] < 8)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
					Dynamx_Slide_Left_Interpolate(HEXSTEP_CLOSE, IKCALC_DISABLE);
				}
				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

				Cat_Avoider();
				CAT_FLAG=CAT_NOT_DETECTED;
				ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;

				BW_Buzz(1);
				BW_PID_Init();

				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

				BW_Buzz(1);
				BW_PID_Init();
				CAT_DETECTOR = CAT_ACTIVATED;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"To GRAY");lcd_putstr(lcd);
				BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

				if(CAT_FLAG==CAT_DETECTED)			// CAT C
				{
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"CAT DETECT C");lcd_putstr(lcd);

					CAT_DETECTOR=CAT_DIACTIVATED;
					SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
					CAT_FLAG_C=CAT_DETECTED;
					CAT_FLAG=CAT_NOT_DETECTED;;

					Nav_TurnAround(TURN_RIGHT);

					Dynamx_MovFwd4cm_Interpolate(4,LEVEL6,IKCALC_ENABLE);

					BW_Buzz(1);
					BW_PID_Init();
					BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

					BW_Buzz(1);
					BW_PID_Init();
					BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

					BW_Buzz(1);
					BW_PID_Init();
					BW_FollowTracer_Left_Interpolate();

					FIREROOM_R1A_FLAG=FIREROOM_R1A_ACTIVE;

				}
				else //CAT C KOSONG
				{
					CAT_FLAG=CAT_NOT_DETECTED;
					SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
//					Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);
//					Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);

/*					if(Ping[PING_LEFT] < 11 || Ping[PING_ASKEW_LEFT] < 11)
					{
						Dynamx_Slide_Right_Interpolate(HEXSTEP_CLOSE, LEVEL3);
					}*/

					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"To BLACK");lcd_putstr(lcd);
					BW_Buzz(1);
					BW_PID_Init();
					BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

/*					if(Ping[PING_REAR_LEFT] < 11 || Ping[PING_LEFT] < 11)
					{
						Dynamx_Slide_Right_Interpolate(HEXSTEP_CLOSE,LEVEL5);
					}
					if(Ping[PING_REAR_LEFT] < 11 || Ping[PING_LEFT] < 11)
					{
						Dynamx_Slide_Right_Interpolate(HEXSTEP_CLOSE,LEVEL5);
					}*/

					SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

					BW_Buzz(1);
					BW_PID_Init();
					CAT_DETECTOR = CAT_ACTIVATED;

//					Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, 100);
					Dynamx_Rot_Left_Interpolate(LEVEL3, HEXSTEP_MED, IKCALC_DISABLE);
//					Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
//					Dynamx_Rot_Left_Interpolate(LEVEL3, HEXSTEP_CLOSE, IKCALC_DISABLE);


					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"To GRAY 2");lcd_putstr(lcd);
					BW_PID_Init();
					BWFollowCarpet_Left_Interpolate(COLOUR_GRAY, INVERSE);

					if(CAT_FLAG==CAT_NOT_DETECTED)
					{
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"To WHITE");lcd_putstr(lcd);

						BW_Buzz(1);
						BW_PID_Init();
						SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
						BW_PID_Init();
//						BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

//==================== test lngsung follow trcer ==================
						BW_FollowTracer_Left_Interpolate();

						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"BREAK");lcd_putstr(lcd);
					}
					if(CAT_FLAG==CAT_DETECTED)			// CAT B
					{
						CAT_DETECTOR=CAT_DIACTIVATED;
						CAT_FLAG=CAT_NOT_DETECTED;
						CAT_FLAG_B=CAT_DETECTED;
						REVERSE_FLAG=REVERSEFLAG_ACTIVE;

						SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

						R4ATO1_SP_ROUTE=SP_ROUTE_ACTIVE;

						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"ALTERNATE");lcd_putstr(lcd);
						lcd_gotoxy(8,1);sprintf(lcd,"ROUTE");lcd_putstr(lcd);

						Dynamx_MovBwd_Interpolate(3,LEVEL6,IKCALC_DISABLE);

						Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
						Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);

						while(Ping[PING_FRONT]<25)
						{
							Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_CLOSE,IKCALC_DISABLE);
						}

						Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_CLOSE,IKCALC_DISABLE);

						BW_Buzz(1);
						BW_PID_Init();
						BW_FollowTracer_Right_Interpolate();

						if(ROOM_4A_MANUAL==1)ROOM[2] = ROOM_4A;

					}
					else //CAT B kosong
					{
						CAT_DETECTOR=CAT_DIACTIVATED;
						CAT_FLAG=CAT_NOT_DETECTED;
						R4ATO1_SP_ROUTE=SP_ROUTE_INACTIVE;

						SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
						//Activate special route
						R4ATO3_SP_ROUTE=R4ATO3_SP_ACTIVE;
						R4ATO2_SP_ROUTE=SP_ROUTE_ACTIVE;

						if(ROOM_4A_MANUAL==1)ROOM[2] = ROOM_4A;
						CAT_FLAG_A=CAT_DETECTED;

					}

				}

			}

		}
	}

}


/* func      : void Nav_2_To_4B(void)
 * brief     : Navigate from Room 2 to Room 4B
 * param     : N/A
 * retval    : N/A
 * Ver       : 3
 * written By: Ryan (Thursday, March 27th 2016)
 * Revised BY: ver2 : Ryan (Friday, December 2nd 2016
 *		       Ver3 : Hafidin (Wed, Feb 23th 2017)
 * programmer's Note:
 */
void Nav_2_To_4B(void)
{
//	int counter;
	int g;

	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R2 TO R4B");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
	{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
		{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		}
	}
	else
	{	Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		if((Ping[PING_REAR_RIGHT])<(Ping[PING_ASKEW_RIGHT]))
		{	Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		}
	}
	if(Ping[PING_RIGHT] < 20 || Ping[PING_ASKEW_RIGHT] < 20)
	{
		Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
	}

	if(Ping[PING_RIGHT] < 20 || Ping[PING_ASKEW_RIGHT] < 20)
	{
		Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
	}

	if(Ping[PING_RIGHT] < 20 || Ping[PING_ASKEW_RIGHT] < 20)
	{
		Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
	}

	Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);

	if(Ping[PING_ASKEW_LEFT] <= 9 || Ping[PING_UP_LEFT] <= 9)
	{
		Dynamx_Rot_Right_Interpolate(LEVEL3, HEXSTEP_MED, IKCALC_DISABLE);
		Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);
	}

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(0,1);sprintf(lcd,"1");lcd_putstr(lcd);
	delay_ms(100);

	BW_PID_Init();
	int l;
	for(l = 0;l <= 2;l++)
	{
		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1] == COLOUR_GRAY)break;
		if(((Ping[PING_ASKEW_LEFT] < 11 || Ping[PING_LEFT] < 11)))
		{
			BW_FollowCounter_Left(1);

		}
		else if(Ping[PING_ASKEW_RIGHT] < 11 || Ping[PING_RIGHT] < 11)
		{
			BW_FollowCounter_Right(1);
		}
/*		else if(SHARP[SHARP_FRONT_L] < 10 || SHARP[SHARP_FRONT_R] < 10 || TCS3200_SLV_DATA[1] == COLOUR_WHITE)
		{
			Dynamx_MovBwd_Interpolate(6, LEVEL5, IKCALC_DISABLE);
			Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
			TCS3200_Transmit(UART5,CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1] == TRACER_WHITE)
			{
				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
			}
//			BW_COMPASS_CORRECTION(ROOM_2_1BC_CORRECTION);
//			Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
			if(SHARP[SHARP_BUMPER_LEFT] < 10)
			{
				Dynamx_Slide_Right_Interpolate(HEXSTEP_CLOSE, LEVEL3);
			}
			else if(SHARP[SHARP_BUMPER_RIGHT] < 10)
			{
				Dynamx_Slide_Left_Interpolate(HEXSTEP_CLOSE, LEVEL3);
			}
			l = 0;
		}*/
		else Dynamx_MovFwd4cm_Interpolate(4,LEVEL6, IKCALC_ENABLE);
		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1] == COLOUR_GRAY)break;
	}
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(0,1);sprintf(lcd,"2");lcd_putstr(lcd);
	delay_ms(100);

	BW_Buzz(1);
	BW_PID_Init();
	BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

	if((Ping[PING_LEFT]+4)<(Ping[PING_REAR_LEFT]))
	{
		if((Ping[PING_REAR_LEFT])>(Ping[PING_LEFT]+4))
		{
			Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		}
		if((Ping[PING_REAR_LEFT])>(Ping[PING_LEFT]+4))
		{
			Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		}
	}

	if(Ping[PING_LEFT] < 18 || Ping[PING_REAR_LEFT] < 18)
	{
		Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);
	}

	if(Ping[PING_LEFT] < 18 || Ping[PING_REAR_LEFT] < 18)
	{
		Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);
	}

	/*Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);*/
/*	BW_PID_Init();
	BW_FollowCounter_Right(2);*/

	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"KOREKSI");lcd_putstr(lcd);

	if(FOUR_WAY_MANUAL == 0)
	{
/*			GetCMPS11_Angle8Bit();
	if(CMPS11_Angle > (R4A_THRESHOLD_MIDDLE - 15) && CMPS11_Angle < R4AB_THRESHOLD_UPPER)
	{
		while(CMPS11_Angle > (R4A_THRESHOLD_MIDDLE - 15) && CMPS11_Angle < R4AB_THRESHOLD_UPPER)
		{
			Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
			delay_ms(20);
			GetCMPS11_Angle8Bit();
		}
	}

	else if(CMPS11_Angle < (R4A_THRESHOLD_MIDDLE - 15) || CMPS11_Angle > R4AB_THRESHOLD_LOWER)
	{
		while(CMPS11_Angle < (R4A_THRESHOLD_MIDDLE - 15) || CMPS11_Angle > R4AB_THRESHOLD_LOWER)
		{
			Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
			delay_ms(20);
			GetCMPS11_Angle8Bit();
		}
	}*/
//		BW_COMPASS_CORRECTION(FOUR_WAY_CORRECTION);
//		BW_COMPASS_CORRECTION(FOUR_WAY_CORRECTION);
	}

	GetCMPS11_Angle8Bit();
	if(FOUR_WAY_MANUAL == 0)
	{
//		Dynamx_Rot_Right_Interpolate(LEVEL3, HEXSTEP_MED, IKCALC_DISABLE);
/*			if(CMPS11_Angle >= (R4A_THRESHOLD_MIDDLE - 60) && CMPS11_Angle > R4AB_THRESHOLD_UPPER)
	{
		while(CMPS11_Angle >= (R4A_THRESHOLD_MIDDLE - 60) && CMPS11_Angle > R4AB_THRESHOLD_UPPER)
		{
			Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
			delay_ms(20);
			GetCMPS11_Angle8Bit();
		}
	}*/
	}

	else
	{
		Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);
		Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_MED, IKCALC_DISABLE);
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL3,IKCALC_ENABLE);
	}



	Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
	Dynamx_Rot_Right_Interpolate(LEVEL3, HEXSTEP_MED, IKCALC_DISABLE);

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(0,1);sprintf(lcd,"3");lcd_putstr(lcd);
	delay_ms(100);

	BW_Buzz(1);
	BW_PID_Init();
	BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

	Dynamx_MovFwd4cm_Interpolate(8,LEVEL4,IKCALC_ENABLE);

	Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
	Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);

	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_FAR,IKCALC_DISABLE);
	Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);

	BW_Buzz(1);
	BW_PID_Init();
	BW_FollowTracer_Left_Interpolate();

	/*
	 * 	ACTIVATE ROOM4AB_FLAG
	 */
	ROOM4AB_FLAG=ROOM4AB_ACTIVE;
}

/* func      : void Nav_2_To_1A(void)
 * brief     : Navigate from Room 2 to Room 1A
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Thursday, March 27th 2016)
 * Revised BY: Ver.2 : Ryan (Tuesday, April 5th 2016)
 * programmer's Note:
 */
void Nav_2_To_1A(void)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R2 TO R1A");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	while(1)
	{
		Dynamx_Mov_Static_Interpolate(HEXSPD_ULTRAFAST,IKCALC_ENABLE);
	}
}

/* func      : void Nav_1A_To_4A(void)
 * brief     : Navigate from Room 1A to Room HallwaySC
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 28th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_1A_To_HallwaySC(void)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1A TO SC");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	BW_PID_Init();
	BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

	if(CAT_FLAG==CAT_NOT_DETECTED)
	{
		BW_PID_Init();
		BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);
	}

	//CAT DETECTED IN CONFIG B (RIGHT SIDE OF ROOM 4
	if(CAT_FLAG==CAT_DETECTED)
	{
		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"CAT DETECTED");lcd_putstr(lcd);
		lcd_gotoxy(3,1);sprintf(lcd,"CONFIG B");lcd_putstr(lcd);
		delay_ms(100);

		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"FOLLOWCARPET");lcd_putstr(lcd);
		lcd_gotoxy(3,1);sprintf(lcd,"BLACK");lcd_putstr(lcd);
		delay_ms(100);
		BW_Buzz(2);
		BW_PID_Init();
		BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"FOLLOWCARPET");lcd_putstr(lcd);
		lcd_gotoxy(3,1);sprintf(lcd,"GRAY");lcd_putstr(lcd);
		delay_ms(100);
		BW_Buzz(2);
		BW_PID_Init();
		BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"FOLLOWCARPET");lcd_putstr(lcd);
		lcd_gotoxy(3,1);sprintf(lcd,"BLACK");lcd_putstr(lcd);
		delay_ms(100);
		BW_Buzz(2);
		BW_PID_Init();
		BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"FORWARD TO");lcd_putstr(lcd);
		lcd_gotoxy(3,1);sprintf(lcd,"CROSSROAD");lcd_putstr(lcd);
		delay_ms(100);
		BW_Buzz(2);
		while( (Ping[PING_LEFT]<=30) || (Ping[PING_RIGHT]<=30) )
		{
			if(
				(INFRARED[IR_FRONT_LEFT]==IR_DETECTED) ||
				(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
				(Ping[PING_FRONT]<=25)
			  )
			{
//				mov_rot_right(FAST_LEVEL_3,CLOSE);
//				mov_rot_right(FAST_LEVEL_3,CLOSE);
			}

			Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);
		}

		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"FOLLOW RIGHT");lcd_putstr(lcd);
		lcd_gotoxy(3,1);sprintf(lcd,"10 STEP");lcd_putstr(lcd);
		delay_ms(100);
		BW_PID_Init();
		BW_FollowCounter_Right(10);

		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"DEFLECT LEFT");lcd_putstr(lcd);
		lcd_gotoxy(3,1);sprintf(lcd,"3 TIMES");lcd_putstr(lcd);
		delay_ms(100);
//		mov_deflect_left(FAST,CLOSE);
//		mov_deflect_left(FAST,CLOSE);
//		mov_deflect_left(FAST,CLOSE);

		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"FOLLOWHOME");lcd_putstr(lcd);
		lcd_gotoxy(3,1);sprintf(lcd,"LEFT RULE");lcd_putstr(lcd);
		delay_ms(100);
		BW_Buzz(2);
		BW_PID_Init();
//		FollowHome_Left();
	}

	//CAT NOT DETECTED IN CONFIG B
	else
	{

		//CAT DETECTED IN CONFIG A
		if(CAT_FLAG==CAT_DETECTED)
		{
			lcd_display_clear();
			lcd_gotoxy(3,0);sprintf(lcd,"CAT DETECTED");lcd_putstr(lcd);
			lcd_gotoxy(3,1);sprintf(lcd,"CONFIG A");lcd_putstr(lcd);
			delay_ms(100);

			BW_Buzz(2);
			BW_PID_Init();
			BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

			BW_Buzz(2);
			BW_PID_Init();
			BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

			BW_Buzz(2);
			while( (Ping[PING_LEFT]<=30) || (Ping[PING_RIGHT]<=30) )
			{
				if(
					(INFRARED[IR_FRONT_LEFT]==IR_DETECTED) ||
					(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
					(Ping[PING_FRONT]<=25)
				  )
				{
//					mov_rot_right(FAST_LEVEL_3,CLOSE);
//					mov_rot_right(FAST_LEVEL_3,CLOSE);
				}

				Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);
			}

			BW_Buzz(2);
			BW_PID_Init();
			BW_FollowCounter_Right(10);

//			mov_deflect_left(FAST,CLOSE);
//			mov_deflect_left(FAST,CLOSE);
//			mov_deflect_left(FAST,CLOSE);

			BW_Buzz(2);
			BW_PID_Init();
//			FollowHome_Left();
		}

		//CAT OBSTACLE NOT DETECTED
		else
		{

		}

	}



}


/* func      : void BW_COMPASS_CORRECTION(int SECTION)
 * brief     : BW 2019  Adaptive Compass Correction
 * param     : SECTION
 * retval    : N/A
 * Ver       : 0.1
 * written By: Reyhan
 * Revised BY: Reyhan
 *
 *
 * programmer's Note:
 */

void BW_COMPASS_CORRECTION(int SECTION)
{
	COMPASS_INTERRUPT = 1;

	ROOM_COUNTER = 1;
	if(SECTION == FOUR_WAY_CORRECTION)
	{
		if(R1BC_THRESHOLD_MIDDLE < R4AB_THRESHOLD_LOWER && R1BC_THRESHOLD_MIDDLE < R4AB_THRESHOLD_UPPER)
		{
			if(R4AB_THRESHOLD_UPPER > R4AB_THRESHOLD_LOWER)
			{
			if(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE || CMPS11_Angle > R4AB_THRESHOLD_UPPER)
			{
				while(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE || CMPS11_Angle > R4AB_THRESHOLD_UPPER)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
			else if(CMPS11_Angle > R1BC_THRESHOLD_MIDDLE && CMPS11_Angle < R4AB_THRESHOLD_LOWER)
			{
				while(CMPS11_Angle > R1BC_THRESHOLD_MIDDLE && CMPS11_Angle < R4AB_THRESHOLD_LOWER)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
			}

			else
			{
				if(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE || CMPS11_Angle > R4AB_THRESHOLD_LOWER)
				{
					while(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE || CMPS11_Angle > R4AB_THRESHOLD_LOWER)
					{
						Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
						delay_ms(50);
					}
				}
				else if(CMPS11_Angle > R1BC_THRESHOLD_MIDDLE && CMPS11_Angle < R4AB_THRESHOLD_UPPER)
				{
					while(CMPS11_Angle > R1BC_THRESHOLD_MIDDLE && CMPS11_Angle < R4AB_THRESHOLD_UPPER)
					{
						Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
						delay_ms(50);
					}
				}
			}
		}
		else if(R1BC_THRESHOLD_MIDDLE > R4AB_THRESHOLD_UPPER && R1BC_THRESHOLD_MIDDLE < R4AB_THRESHOLD_LOWER)
		{
			if(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE)
			{
				while(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
			else if(CMPS11_Angle > R1BC_THRESHOLD_MIDDLE)
			{
				while(CMPS11_Angle > R1BC_THRESHOLD_MIDDLE)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
		}
		else if(R1BC_THRESHOLD_MIDDLE < R4AB_THRESHOLD_UPPER && R1BC_THRESHOLD_MIDDLE > R4AB_THRESHOLD_LOWER)
		{
			if(CMPS11_Angle > R1BC_THRESHOLD_MIDDLE)
			{
				while(CMPS11_Angle > R1BC_THRESHOLD_MIDDLE)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
			else if(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE)
			{
				while(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
		}
		else if(R1BC_THRESHOLD_MIDDLE > R4AB_THRESHOLD_UPPER && R1BC_THRESHOLD_MIDDLE > R4AB_THRESHOLD_LOWER)
		{
			if(R4AB_THRESHOLD_UPPER > R4AB_THRESHOLD_LOWER)
			{
			if(CMPS11_Angle < R4AB_THRESHOLD_LOWER || CMPS11_Angle > R1BC_THRESHOLD_MIDDLE)
			{
				while(CMPS11_Angle < R4AB_THRESHOLD_LOWER || CMPS11_Angle > R1BC_THRESHOLD_MIDDLE)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
			else if(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE && CMPS11_Angle > R4AB_THRESHOLD_UPPER)
			{
				while(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE && CMPS11_Angle > R4AB_THRESHOLD_UPPER)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
			}
			else
			{
				if(CMPS11_Angle < R4AB_THRESHOLD_UPPER || CMPS11_Angle > R1BC_THRESHOLD_MIDDLE)
				{
					while(CMPS11_Angle < R4AB_THRESHOLD_UPPER || CMPS11_Angle > R1BC_THRESHOLD_MIDDLE)
					{
						Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
						delay_ms(50);
					}
				}
				else if(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE && CMPS11_Angle > R4AB_THRESHOLD_LOWER)
				{
					while(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE && CMPS11_Angle > R4AB_THRESHOLD_LOWER)
					{
						Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
						delay_ms(50);
					}
				}

			}
		}
	}

	else if(SECTION == ROOM_2_1BC_CORRECTION)
	{
		if(R1BC_THRESHOLD_MIDDLE < R4AB_THRESHOLD_LOWER && R1BC_THRESHOLD_MIDDLE < R4AB_THRESHOLD_UPPER)
		{
			if(R4AB_THRESHOLD_UPPER > R4AB_THRESHOLD_LOWER)
			{
			if(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE || CMPS11_Angle > R4AB_THRESHOLD_UPPER)
			{
				while(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE || CMPS11_Angle > R4AB_THRESHOLD_UPPER)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
			else if(CMPS11_Angle > R1BC_THRESHOLD_MIDDLE && CMPS11_Angle < R4AB_THRESHOLD_LOWER)
			{
				while(CMPS11_Angle > R1BC_THRESHOLD_MIDDLE && CMPS11_Angle < R4AB_THRESHOLD_LOWER)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
			}

			else
			{
				if(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE || CMPS11_Angle > R4AB_THRESHOLD_LOWER)
				{
					while(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE || CMPS11_Angle > R4AB_THRESHOLD_LOWER)
					{
						Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
						delay_ms(50);
					}
				}
				else if(CMPS11_Angle > R1BC_THRESHOLD_MIDDLE && CMPS11_Angle < R4AB_THRESHOLD_UPPER)
				{
					while(CMPS11_Angle > R1BC_THRESHOLD_MIDDLE && CMPS11_Angle < R4AB_THRESHOLD_UPPER)
					{

						Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
						delay_ms(50);
					}
				}
			}
		}
		else if(R1BC_THRESHOLD_MIDDLE > R4AB_THRESHOLD_UPPER && R1BC_THRESHOLD_MIDDLE < R4AB_THRESHOLD_LOWER)
		{
			if(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE)
			{
				while(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
			else if(CMPS11_Angle > R1BC_THRESHOLD_MIDDLE)
			{
				while(CMPS11_Angle > R1BC_THRESHOLD_MIDDLE)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
		}
		else if(R1BC_THRESHOLD_MIDDLE < R4AB_THRESHOLD_UPPER && R1BC_THRESHOLD_MIDDLE > R4AB_THRESHOLD_LOWER)
		{
			if(CMPS11_Angle > R1BC_THRESHOLD_MIDDLE)
			{
				while(CMPS11_Angle > R1BC_THRESHOLD_MIDDLE)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
			else if(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE)
			{
				while(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
		}
		else if(R1BC_THRESHOLD_MIDDLE > R4AB_THRESHOLD_UPPER && R1BC_THRESHOLD_MIDDLE > R4AB_THRESHOLD_LOWER)
		{
			if(R4AB_THRESHOLD_UPPER > R4AB_THRESHOLD_LOWER)
			{
			if(CMPS11_Angle < R4AB_THRESHOLD_LOWER || CMPS11_Angle > R1BC_THRESHOLD_MIDDLE)
			{
				while(CMPS11_Angle < R4AB_THRESHOLD_LOWER || CMPS11_Angle > R1BC_THRESHOLD_MIDDLE)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
			else if(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE && CMPS11_Angle > R4AB_THRESHOLD_UPPER)
			{
				while(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE && CMPS11_Angle > R4AB_THRESHOLD_UPPER)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
			}
			else
			{
				if(CMPS11_Angle < R4AB_THRESHOLD_UPPER || CMPS11_Angle > R1BC_THRESHOLD_MIDDLE)
				{
					while(CMPS11_Angle < R4AB_THRESHOLD_UPPER || CMPS11_Angle > R1BC_THRESHOLD_MIDDLE)
					{
						Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
						delay_ms(50);
					}
				}
				else if(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE && CMPS11_Angle > R4AB_THRESHOLD_LOWER)
				{
					while(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE && CMPS11_Angle > R4AB_THRESHOLD_LOWER)
					{
						Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
						delay_ms(50);
					}
				}

			}
		}

	}

	else if(SECTION == ROOM_1A_CORRECTION)
	{
		if(R1BC_THRESHOLD_MIDDLE < R4AB_THRESHOLD_LOWER && R1BC_THRESHOLD_MIDDLE < R4AB_THRESHOLD_UPPER)
		{
			if(R4AB_THRESHOLD_UPPER > R4AB_THRESHOLD_LOWER)
			{
			if(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE || CMPS11_Angle > R4AB_THRESHOLD_UPPER)
			{
				while(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE || CMPS11_Angle > R4AB_THRESHOLD_UPPER)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
			else if(CMPS11_Angle > R1BC_THRESHOLD_MIDDLE && CMPS11_Angle < R4AB_THRESHOLD_LOWER)
			{
				while(CMPS11_Angle > R1BC_THRESHOLD_MIDDLE && CMPS11_Angle < R4AB_THRESHOLD_LOWER)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
			}

			else
			{
				if(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE || CMPS11_Angle > R4AB_THRESHOLD_LOWER)
				{
					while(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE || CMPS11_Angle > R4AB_THRESHOLD_LOWER)
					{
						Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
						delay_ms(50);
					}
				}
				else if(CMPS11_Angle > R1BC_THRESHOLD_MIDDLE && CMPS11_Angle < R4AB_THRESHOLD_UPPER)
				{
					while(CMPS11_Angle > R1BC_THRESHOLD_MIDDLE && CMPS11_Angle < R4AB_THRESHOLD_UPPER)
					{
						Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
						delay_ms(50);
					}
				}
			}
		}
		else if(R1BC_THRESHOLD_MIDDLE > R4AB_THRESHOLD_UPPER && R1BC_THRESHOLD_MIDDLE < R4AB_THRESHOLD_LOWER)
		{
			if(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE)
			{
				while(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
			else if(CMPS11_Angle > R1BC_THRESHOLD_MIDDLE)
			{
				while(CMPS11_Angle > R1BC_THRESHOLD_MIDDLE)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
		}
		else if(R1BC_THRESHOLD_MIDDLE < R4AB_THRESHOLD_UPPER && R1BC_THRESHOLD_MIDDLE > R4AB_THRESHOLD_LOWER)
		{
			if(CMPS11_Angle > R1BC_THRESHOLD_MIDDLE)
			{
				while(CMPS11_Angle > R1BC_THRESHOLD_MIDDLE)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
			else if(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE)
			{
				while(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
		}
		else if(R1BC_THRESHOLD_MIDDLE > R4AB_THRESHOLD_UPPER && R1BC_THRESHOLD_MIDDLE > R4AB_THRESHOLD_LOWER)
		{
			if(R4AB_THRESHOLD_UPPER > R4AB_THRESHOLD_LOWER)
			{
			if(CMPS11_Angle < R4AB_THRESHOLD_LOWER || CMPS11_Angle > R1BC_THRESHOLD_MIDDLE)
			{
				while(CMPS11_Angle < R4AB_THRESHOLD_LOWER || CMPS11_Angle > R1BC_THRESHOLD_MIDDLE)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
			else if(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE && CMPS11_Angle > R4AB_THRESHOLD_UPPER)
			{
				while(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE && CMPS11_Angle > R4AB_THRESHOLD_UPPER)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
			}
			else
			{
				if(CMPS11_Angle < R4AB_THRESHOLD_UPPER || CMPS11_Angle > R1BC_THRESHOLD_MIDDLE)
				{
					while(CMPS11_Angle < R4AB_THRESHOLD_UPPER || CMPS11_Angle > R1BC_THRESHOLD_MIDDLE)
					{
						Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
						delay_ms(50);
					}
				}
				else if(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE && CMPS11_Angle > R4AB_THRESHOLD_LOWER)
				{
					while(CMPS11_Angle < R1BC_THRESHOLD_MIDDLE && CMPS11_Angle > R4AB_THRESHOLD_LOWER)
					{
						Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
						delay_ms(50);
					}
				}

			}
		}
	}

	else if(SECTION == ROOM_4B_TURN_CORRECTION)
	{
		if(R4AB_THRESHOLD_UPPER < R4B_THRESHOLD_UPPER && R4AB_THRESHOLD_UPPER < R4A_THRESHOLD_UPPER)
		{
			if(R4B_THRESHOLD_UPPER > R4A_THRESHOLD_UPPER)
			{
			if(CMPS11_Angle > R4AB_THRESHOLD_UPPER && CMPS11_Angle < R4A_THRESHOLD_UPPER)
			{
				while(CMPS11_Angle > R4AB_THRESHOLD_UPPER && CMPS11_Angle < R4A_THRESHOLD_UPPER)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
			else if(CMPS11_Angle < R4AB_THRESHOLD_UPPER || CMPS11_Angle > R4B_THRESHOLD_UPPER)
			{
				while(CMPS11_Angle < R4AB_THRESHOLD_UPPER || CMPS11_Angle > R4B_THRESHOLD_UPPER)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
			}
			else
			{
				if(CMPS11_Angle > R4AB_THRESHOLD_UPPER && CMPS11_Angle < R4B_THRESHOLD_UPPER)
				{
					while(CMPS11_Angle > R4AB_THRESHOLD_UPPER && CMPS11_Angle < R4B_THRESHOLD_UPPER)
					{
						Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
						delay_ms(50);
					}
				}
				else if(CMPS11_Angle < R4AB_THRESHOLD_UPPER || CMPS11_Angle > R4A_THRESHOLD_UPPER)
				{
					while(CMPS11_Angle < R4AB_THRESHOLD_UPPER || CMPS11_Angle > R4A_THRESHOLD_UPPER)
					{
						Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
						delay_ms(50);
					}
				}
			}
		}
		else if(R4AB_THRESHOLD_UPPER > R4B_THRESHOLD_UPPER && R4AB_THRESHOLD_UPPER < R4A_THRESHOLD_UPPER)
		{
			if(CMPS11_Angle < R4AB_THRESHOLD_UPPER)
			{
				while(CMPS11_Angle < R4AB_THRESHOLD_UPPER)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
			else if(CMPS11_Angle > R4AB_THRESHOLD_UPPER)
			{
				while(CMPS11_Angle > R4AB_THRESHOLD_UPPER)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
		}
		else if(R4AB_THRESHOLD_UPPER < R4B_THRESHOLD_UPPER && R4AB_THRESHOLD_UPPER > R4A_THRESHOLD_UPPER)
		{
			if(CMPS11_Angle > R4AB_THRESHOLD_UPPER)
			{
				while(CMPS11_Angle > R4AB_THRESHOLD_UPPER)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
			else if(CMPS11_Angle < R4AB_THRESHOLD_UPPER)
			{
				while(CMPS11_Angle < R4AB_THRESHOLD_UPPER)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
		}
		else if(R4AB_THRESHOLD_UPPER > R4B_THRESHOLD_UPPER && R4AB_THRESHOLD_UPPER > R4A_THRESHOLD_UPPER)
		{
			if(R4B_THRESHOLD_UPPER > R4A_THRESHOLD_UPPER)
			{
			if(CMPS11_Angle > R4B_THRESHOLD_UPPER && CMPS11_Angle < R4AB_THRESHOLD_UPPER)
			{
				while(CMPS11_Angle > R4B_THRESHOLD_UPPER && CMPS11_Angle < R4AB_THRESHOLD_UPPER)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
			else if(CMPS11_Angle < R4A_THRESHOLD_UPPER || CMPS11_Angle > R4AB_THRESHOLD_UPPER)
			{
				while(CMPS11_Angle < R4A_THRESHOLD_UPPER || CMPS11_Angle > R4AB_THRESHOLD_UPPER)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
			}

			else
			{
				if(CMPS11_Angle < R4B_THRESHOLD_UPPER || CMPS11_Angle > R4AB_THRESHOLD_UPPER)
				{
					while(CMPS11_Angle < R4B_THRESHOLD_UPPER || CMPS11_Angle > R4AB_THRESHOLD_UPPER)
					{
						Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
						delay_ms(50);
					}
				}
				else if(CMPS11_Angle > R4A_THRESHOLD_UPPER && CMPS11_Angle < R4AB_THRESHOLD_UPPER)
				{
					while(CMPS11_Angle > R4A_THRESHOLD_UPPER && CMPS11_Angle < R4AB_THRESHOLD_UPPER)
					{
						Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
						delay_ms(50);
					}
				}
			}
		}

	}

	else if(SECTION == START_MID_CORRECTION)
	{
		if(R4A_THRESHOLD_MIDDLE > START_MIDDLE)
		{
			if(R4AB_THRESHOLD_UPPER < START_MIDDLE)
			{
				selisih_CMPS = START_MIDDLE - CMPS11_Angle;
				if(selisih_CMPS > (START_MIDDLE - R4A_THRESHOLD_MIDDLE) && selisih_CMPS < 0)
				{
					while(selisih_CMPS > (START_MIDDLE - R4A_THRESHOLD_MIDDLE) && selisih_CMPS < 0)
					{
						selisih_CMPS = START_MIDDLE - CMPS11_Angle;
						Dynamx_Rot_Right_Interpolate(LEVEL4, HEXSTEP_FAR, IKCALC_DISABLE);
						selisih_CMPS = START_MIDDLE - CMPS11_Angle;
						delay_ms(50);
					}
				}

				else if(selisih_CMPS > 0 )
				{
					while(selisih_CMPS > 0)
					{
						selisih_CMPS =START_MIDDLE - CMPS11_Angle;
						Dynamx_Rot_Left_Interpolate(LEVEL4, HEXSTEP_FAR, IKCALC_DISABLE);
						selisih_CMPS = START_MIDDLE - CMPS11_Angle;
						delay_ms(50);
					}
				}
				else
				{
					if(selisih_CMPS < (START_MIDDLE - R4A_THRESHOLD_MIDDLE))
					{
						while(selisih_CMPS < (START_MIDDLE - R4A_THRESHOLD_MIDDLE))
						{
							selisih_CMPS = START_MIDDLE - CMPS11_Angle;
							Dynamx_Rot_Left_Interpolate(LEVEL4, HEXSTEP_FAR, IKCALC_DISABLE);
							selisih_CMPS = START_MIDDLE - CMPS11_Angle;
							delay_ms(50);
						}
					}
				}
			}

			else
			{
				selisih_CMPS = START_MIDDLE - CMPS11_Angle;
				if(selisih_CMPS > (START_MIDDLE - R4A_THRESHOLD_MIDDLE) && selisih_CMPS < 0)
				{
					while(selisih_CMPS > (START_MIDDLE - R4A_THRESHOLD_MIDDLE) && selisih_CMPS < 0 )
					{
						selisih_CMPS = START_MIDDLE - CMPS11_Angle;
						Dynamx_Rot_Left_Interpolate(LEVEL4, HEXSTEP_FAR, IKCALC_DISABLE);
						selisih_CMPS = START_MIDDLE - CMPS11_Angle;
						delay_ms(50);
					}
				}

				else if(selisih_CMPS > 0  )
				{
					while(selisih_CMPS > 0)
					{
						selisih_CMPS = START_MIDDLE - CMPS11_Angle;
						Dynamx_Rot_Right_Interpolate(LEVEL4, HEXSTEP_FAR, IKCALC_DISABLE);
						selisih_CMPS = START_MIDDLE - CMPS11_Angle;
						delay_ms(50);
					}
				}
				else
				{
					if(selisih_CMPS < (START_MIDDLE - R4A_THRESHOLD_MIDDLE))
					{
						while(selisih_CMPS < (START_MIDDLE - R4A_THRESHOLD_MIDDLE))
						{
							selisih_CMPS = START_MIDDLE - CMPS11_Angle;
							Dynamx_Rot_Right_Interpolate(LEVEL4, HEXSTEP_FAR, IKCALC_DISABLE);
							selisih_CMPS = START_MIDDLE - CMPS11_Angle;
							delay_ms(50);
						}
					}
				}

			}
		}

		else if(R4A_THRESHOLD_MIDDLE < START_MIDDLE)
		{
			if(R4AB_THRESHOLD_UPPER < START_MIDDLE)
			{
				selisih_CMPS = START_MIDDLE - CMPS11_Angle;
				if(selisih_CMPS < (START_MIDDLE - R4A_THRESHOLD_MIDDLE) && selisih_CMPS > 0)
				{
					while(selisih_CMPS < (START_MIDDLE - R4A_THRESHOLD_MIDDLE) && selisih_CMPS > 0)
					{
						selisih_CMPS = START_MIDDLE - CMPS11_Angle;
						Dynamx_Rot_Right_Interpolate(LEVEL4, HEXSTEP_FAR, IKCALC_DISABLE);
						selisih_CMPS = START_MIDDLE - CMPS11_Angle;
						delay_ms(50);
				    }
				}
				else if(selisih_CMPS < 0 )
				{
					while(selisih_CMPS < 0 )
					{
						selisih_CMPS = START_MIDDLE - CMPS11_Angle;
						Dynamx_Rot_Left_Interpolate(LEVEL4, HEXSTEP_FAR, IKCALC_DISABLE);
						selisih_CMPS = START_MIDDLE - CMPS11_Angle;
						delay_ms(50);
					}
				}
				else
				{
					if(selisih_CMPS > (START_MIDDLE - R4A_THRESHOLD_MIDDLE))
					{
						while(selisih_CMPS > (START_MIDDLE - R4A_THRESHOLD_MIDDLE))
						{
							selisih_CMPS = START_MIDDLE - CMPS11_Angle;
							Dynamx_Rot_Left_Interpolate(LEVEL4, HEXSTEP_FAR,IKCALC_DISABLE);
							selisih_CMPS = START_MIDDLE - CMPS11_Angle;
							delay_ms(50);
						}
					}
				}
			}

			else
			{
				selisih_CMPS = START_MIDDLE - CMPS11_Angle;
				if(selisih_CMPS < 188 &&selisih_CMPS > 0 )
				{
					while(selisih_CMPS < (START_MIDDLE - R4A_THRESHOLD_MIDDLE) &&selisih_CMPS > 0)
					{
						selisih_CMPS = START_MIDDLE - CMPS11_Angle;
						Dynamx_Rot_Left_Interpolate(LEVEL4, HEXSTEP_FAR, IKCALC_DISABLE);
						selisih_CMPS = START_MIDDLE - CMPS11_Angle;
						delay_ms(50);
					}
				}

				else if(selisih_CMPS < 0)
				{
					while(selisih_CMPS < 0)
					{
						selisih_CMPS = START_MIDDLE - CMPS11_Angle;
						Dynamx_Rot_Right_Interpolate(LEVEL4, HEXSTEP_FAR, IKCALC_DISABLE);
						selisih_CMPS = START_MIDDLE - CMPS11_Angle;
						delay_ms(50);
					}
				}
				else
				{
					while(selisih_CMPS > (START_MIDDLE - R4A_THRESHOLD_MIDDLE))
					{
						selisih_CMPS = START_MIDDLE - CMPS11_Angle;
						Dynamx_Rot_Right_Interpolate(LEVEL4, HEXSTEP_FAR, IKCALC_DISABLE);
						selisih_CMPS = START_MIDDLE - CMPS11_Angle;
						delay_ms(50);
					}
				}

			}
		}

	}
	else if(SECTION == ROOM_1A_RETURN)
	{
		if(R4A_THRESHOLD_MIDDLE > START_MIDDLE)
		{
			if(R4AB_THRESHOLD_UPPER < START_MIDDLE)
			{
				if(CMPS11_Angle < START_MIDDLE)
				{
					while(CMPS11_Angle < START_MIDDLE)
					{
						Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
						delay_ms(50);
					}
				}

				else if(CMPS11_Angle > START_MIDDLE)
				{
					while(CMPS11_Angle > START_MIDDLE)
					{
						Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
						delay_ms(50);
					}
				}
			}

			else
			{
				if(CMPS11_Angle < START_MIDDLE)
				{
					while(CMPS11_Angle < START_MIDDLE)
					{
						Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
						delay_ms(50);
					}
				}

				else if(CMPS11_Angle > START_MIDDLE)
				{
					while(CMPS11_Angle > START_MIDDLE)
					{
						Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
						delay_ms(50);
					}
				}

			}
		}

		else if(R4A_THRESHOLD_MIDDLE < START_MIDDLE)
		{
			if(R4AB_THRESHOLD_UPPER < START_MIDDLE)
			{
				if(CMPS11_Angle < START_MIDDLE)
				{
					while(CMPS11_Angle < START_MIDDLE)
					{
						Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
						delay_ms(50);
					}
				}

				else if(CMPS11_Angle > START_MIDDLE)
				{
					while(CMPS11_Angle > START_MIDDLE)
					{
						Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
						delay_ms(50);
					}
				}
			}

			else
			{
				if(CMPS11_Angle < START_MIDDLE)
				{
					while(CMPS11_Angle < START_MIDDLE)
					{
						Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
						delay_ms(50);
					}
				}

				else if(CMPS11_Angle > START_MIDDLE)
				{
					while(CMPS11_Angle > START_MIDDLE)
					{
						Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
						delay_ms(50);
					}
				}

			}
		}
	}

	else if(SECTION == FOUR_WAY_INV)
	{
		if(R4B_THRESHOLD_MIDDLE < R4B_THRESHOLD_LOWER && R4B_THRESHOLD_MIDDLE < R4B_THRESHOLD_UPPER)
		{
			if(CMPS11_Angle > R4B_THRESHOLD_MIDDLE && CMPS11_Angle < R4B_THRESHOLD_UPPER)
			{
				while(CMPS11_Angle > R4B_THRESHOLD_MIDDLE && CMPS11_Angle < R4B_THRESHOLD_UPPER)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
			else if(CMPS11_Angle < R4B_THRESHOLD_MIDDLE || CMPS11_Angle > R4B_THRESHOLD_LOWER)
			{
				while(CMPS11_Angle < R4B_THRESHOLD_MIDDLE || CMPS11_Angle > R4B_THRESHOLD_LOWER)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
		}
		else if(R4B_THRESHOLD_MIDDLE > R4B_THRESHOLD_UPPER && R4B_THRESHOLD_MIDDLE < R4B_THRESHOLD_LOWER)
		{
			if(CMPS11_Angle < R4B_THRESHOLD_MIDDLE && CMPS11_Angle > R4B_THRESHOLD_UPPER)
			{
				while(CMPS11_Angle < R4B_THRESHOLD_MIDDLE && CMPS11_Angle > R4B_THRESHOLD_UPPER)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
			else if(CMPS11_Angle > R4B_THRESHOLD_MIDDLE && CMPS11_Angle < R4B_THRESHOLD_LOWER)
			{
				while(CMPS11_Angle > R4B_THRESHOLD_MIDDLE && CMPS11_Angle < R4B_THRESHOLD_LOWER)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
		}
		else if(R4B_THRESHOLD_MIDDLE < R4B_THRESHOLD_UPPER && R4B_THRESHOLD_MIDDLE > R4B_THRESHOLD_LOWER)
		{
			if(CMPS11_Angle > R4B_THRESHOLD_MIDDLE && CMPS11_Angle < R4B_THRESHOLD_UPPER)
			{
				while(CMPS11_Angle > R4B_THRESHOLD_MIDDLE && CMPS11_Angle < R4B_THRESHOLD_UPPER)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
			else if(CMPS11_Angle < R4B_THRESHOLD_MIDDLE && CMPS11_Angle > R4B_THRESHOLD_LOWER)
			{
				while(CMPS11_Angle < R4B_THRESHOLD_MIDDLE && CMPS11_Angle > R4B_THRESHOLD_LOWER)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
		}
		else if(R4B_THRESHOLD_MIDDLE > R4B_THRESHOLD_UPPER && R4B_THRESHOLD_MIDDLE > R4B_THRESHOLD_LOWER)
		{
			if(CMPS11_Angle < R4B_THRESHOLD_UPPER || CMPS11_Angle > R4B_THRESHOLD_MIDDLE)
			{
				while(CMPS11_Angle < R4B_THRESHOLD_UPPER || CMPS11_Angle > R4B_THRESHOLD_MIDDLE)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
			else if(CMPS11_Angle < R4B_THRESHOLD_MIDDLE && CMPS11_Angle > R4B_THRESHOLD_LOWER)
			{
				while(CMPS11_Angle < R4B_THRESHOLD_MIDDLE && CMPS11_Angle > R4B_THRESHOLD_LOWER)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
					delay_ms(50);
				}
			}
		}
	}

	else if(SECTION == ROOM_4A_DETECT)
	{
		if(R4A_THRESHOLD_MIDDLE < R4A_THRESHOLD_LOWER && R4A_THRESHOLD_MIDDLE < R4A_THRESHOLD_UPPER)
		{
			if(R4A_THRESHOLD_UPPER > R4A_THRESHOLD_LOWER)
			{
			if(CMPS11_Angle > R4A_THRESHOLD_MIDDLE && CMPS11_Angle > R4A_THRESHOLD_UPPER)
			{
				ROOM[ROOM_COUNTER] = ROOM_4A;
			}
			else if(CMPS11_Angle < R4A_THRESHOLD_MIDDLE || CMPS11_Angle < R4A_THRESHOLD_LOWER)
			{
				ROOM[ROOM_COUNTER] = ROOM_4A;
			}
			}
			else
			{
				if(CMPS11_Angle > R4A_THRESHOLD_MIDDLE && CMPS11_Angle < R4A_THRESHOLD_UPPER)
				{
					ROOM[ROOM_COUNTER] = ROOM_4A;
				}
				else if(CMPS11_Angle < R4A_THRESHOLD_MIDDLE || CMPS11_Angle > R4A_THRESHOLD_LOWER)
				{
					ROOM[ROOM_COUNTER] = ROOM_4A;
				}
			}
		}
		else if(R4A_THRESHOLD_MIDDLE > R4A_THRESHOLD_UPPER && R4A_THRESHOLD_MIDDLE < R4A_THRESHOLD_LOWER)
		{
			if(CMPS11_Angle < R4A_THRESHOLD_MIDDLE && CMPS11_Angle > R4A_THRESHOLD_UPPER)
			{
				ROOM[ROOM_COUNTER] = ROOM_4A;
			}
			else if(CMPS11_Angle > R4A_THRESHOLD_MIDDLE && CMPS11_Angle < R4A_THRESHOLD_LOWER)
			{
				ROOM[ROOM_COUNTER] = ROOM_4A;
			}
		}
		else if(R4A_THRESHOLD_MIDDLE < R4A_THRESHOLD_UPPER && R4A_THRESHOLD_MIDDLE > R4A_THRESHOLD_LOWER)
		{
			if(CMPS11_Angle > R4A_THRESHOLD_MIDDLE && CMPS11_Angle < R4A_THRESHOLD_UPPER)
			{
				ROOM[ROOM_COUNTER] = ROOM_4A;
			}
			else if(CMPS11_Angle < R4A_THRESHOLD_MIDDLE && CMPS11_Angle > R4A_THRESHOLD_LOWER)
			{
				ROOM[ROOM_COUNTER] = ROOM_4A;
			}
		}
		else if(R4A_THRESHOLD_MIDDLE > R4A_THRESHOLD_UPPER && R4A_THRESHOLD_MIDDLE > R4A_THRESHOLD_LOWER)
		{
			if(R4A_THRESHOLD_UPPER > R4A_THRESHOLD_LOWER)
			{
			if(CMPS11_Angle > R4A_THRESHOLD_UPPER || CMPS11_Angle > R4A_THRESHOLD_MIDDLE)
			{
				ROOM[ROOM_COUNTER] = ROOM_4A;
			}
			else if(CMPS11_Angle < R4A_THRESHOLD_MIDDLE && CMPS11_Angle < R4A_THRESHOLD_LOWER)
			{
				ROOM[ROOM_COUNTER] = ROOM_4A;
			}
			}
			else
			{
				if(CMPS11_Angle < R4A_THRESHOLD_UPPER || CMPS11_Angle > R4A_THRESHOLD_MIDDLE)
				{
					ROOM[ROOM_COUNTER] = ROOM_4A;
				}
				else if(CMPS11_Angle < R4A_THRESHOLD_MIDDLE && CMPS11_Angle > R4A_THRESHOLD_LOWER)
				{
					ROOM[ROOM_COUNTER] = ROOM_4A;
				}
			}
		}
	}

	else if(SECTION == ROOM_4B_DETECT)
	{
		if(R4B_THRESHOLD_MIDDLE < R4B_THRESHOLD_LOWER && R4B_THRESHOLD_MIDDLE < R4B_THRESHOLD_UPPER)
		{
			if(R4B_THRESHOLD_UPPER < R4B_THRESHOLD_LOWER)
			{
			if(CMPS11_Angle >= R4B_THRESHOLD_MIDDLE && CMPS11_Angle < R4B_THRESHOLD_UPPER)
			{
				ROOM[ROOM_COUNTER] = ROOM_4B;
			}
			else if(CMPS11_Angle <= R4B_THRESHOLD_MIDDLE || CMPS11_Angle > R4B_THRESHOLD_LOWER)
			{
				ROOM[ROOM_COUNTER] = ROOM_4B;
			}
			}
			else
			{
				if(CMPS11_Angle <= R4B_THRESHOLD_MIDDLE || CMPS11_Angle > R4B_THRESHOLD_UPPER)
				{
					ROOM[ROOM_COUNTER] = ROOM_4B;
				}
				else if(CMPS11_Angle >= R4B_THRESHOLD_MIDDLE && CMPS11_Angle < R4B_THRESHOLD_LOWER)
				{
					ROOM[ROOM_COUNTER] = ROOM_4B;
				}
			}
		}
		else if(R4B_THRESHOLD_MIDDLE > R4B_THRESHOLD_UPPER && R4B_THRESHOLD_MIDDLE < R4B_THRESHOLD_LOWER)
		{
			if(CMPS11_Angle <= R4B_THRESHOLD_MIDDLE && CMPS11_Angle > R4B_THRESHOLD_UPPER)
			{
				ROOM[ROOM_COUNTER] = ROOM_4B;
			}
			else if(CMPS11_Angle >= R4B_THRESHOLD_MIDDLE && CMPS11_Angle < R4B_THRESHOLD_LOWER)
			{
				ROOM[ROOM_COUNTER] = ROOM_4B;
			}
		}
		else if(R4B_THRESHOLD_MIDDLE < R4B_THRESHOLD_UPPER && R4B_THRESHOLD_MIDDLE > R4B_THRESHOLD_LOWER)
		{
			if(CMPS11_Angle >= R4B_THRESHOLD_MIDDLE && CMPS11_Angle < R4B_THRESHOLD_UPPER)
			{
				ROOM[ROOM_COUNTER] = ROOM_4B;
			}
			else if(CMPS11_Angle <= R4B_THRESHOLD_MIDDLE && CMPS11_Angle > R4B_THRESHOLD_LOWER)
			{
				ROOM[ROOM_COUNTER] = ROOM_4B;
			}
		}
		else if(R4B_THRESHOLD_MIDDLE > R4B_THRESHOLD_UPPER && R4B_THRESHOLD_MIDDLE > R4B_THRESHOLD_LOWER)
		{
			if(R4B_THRESHOLD_UPPER < R4B_THRESHOLD_LOWER)
			{
			if(CMPS11_Angle < R4B_THRESHOLD_UPPER || CMPS11_Angle >= R4B_THRESHOLD_MIDDLE)
			{
				ROOM[ROOM_COUNTER] = ROOM_4B;
			}
			else if(CMPS11_Angle <= R4B_THRESHOLD_MIDDLE && CMPS11_Angle > R4B_THRESHOLD_LOWER)
			{
				ROOM[ROOM_COUNTER] = ROOM_4B;
			}
			}
			else
			{
				if(CMPS11_Angle > R4B_THRESHOLD_UPPER && CMPS11_Angle <= R4B_THRESHOLD_MIDDLE)
				{
					ROOM[ROOM_COUNTER] = ROOM_4B;
				}
				else if(CMPS11_Angle >= R4B_THRESHOLD_MIDDLE || CMPS11_Angle < R4B_THRESHOLD_LOWER)
				{
					ROOM[ROOM_COUNTER] = ROOM_4B;
				}
			}
		}
	}

	else if(SECTION == ROOM_1B_DETECT)
	{
		if(R4AB_THRESHOLD_UPPER < R4B_THRESHOLD_UPPER && R4AB_THRESHOLD_UPPER < R4A_THRESHOLD_UPPER)
		{
			if(R4A_THRESHOLD_UPPER > R4B_THRESHOLD_UPPER)
			{
			if(CMPS11_Angle >= R4AB_THRESHOLD_UPPER && CMPS11_Angle < R4B_THRESHOLD_UPPER)
			{
				ROOM[ROOM_COUNTER] = ROOM_1B;
			}
			else if(CMPS11_Angle <= R4AB_THRESHOLD_UPPER || CMPS11_Angle > R4A_THRESHOLD_UPPER)
			{
				ROOM[ROOM_COUNTER] = ROOM_1B;
			}
			}
			else
			{
				if(R4A_THRESHOLD_UPPER < R4B_THRESHOLD_UPPER)
				{
				if(CMPS11_Angle >= R4AB_THRESHOLD_UPPER && CMPS11_Angle < R4A_THRESHOLD_UPPER)
				{
					ROOM[ROOM_COUNTER] = ROOM_1B;
				}
				else if(CMPS11_Angle <= R4AB_THRESHOLD_UPPER || CMPS11_Angle > R4B_THRESHOLD_UPPER)
				{
					ROOM[ROOM_COUNTER] = ROOM_1B;
				}
				}
			}
		}
		else if(R4AB_THRESHOLD_UPPER > R4B_THRESHOLD_UPPER && R4AB_THRESHOLD_UPPER < R4A_THRESHOLD_UPPER)
		{
			if(CMPS11_Angle <= R4AB_THRESHOLD_UPPER && CMPS11_Angle > R4B_THRESHOLD_UPPER)
			{
				ROOM[ROOM_COUNTER] = ROOM_1B;
			}
			else if(CMPS11_Angle >= R4AB_THRESHOLD_UPPER && CMPS11_Angle < R4A_THRESHOLD_UPPER)
			{
				ROOM[ROOM_COUNTER] = ROOM_1B;
			}
		}
		else if(R4AB_THRESHOLD_UPPER < R4B_THRESHOLD_UPPER && R4AB_THRESHOLD_UPPER > R4A_THRESHOLD_UPPER)
		{
			if(CMPS11_Angle >= R4AB_THRESHOLD_UPPER && CMPS11_Angle < R4B_THRESHOLD_UPPER)
			{
				ROOM[ROOM_COUNTER] = ROOM_1B;
			}
			else if(CMPS11_Angle <= R4AB_THRESHOLD_UPPER && CMPS11_Angle > R4A_THRESHOLD_UPPER)
			{
				ROOM[ROOM_COUNTER] = ROOM_1B;
			}
		}
		else if(R4AB_THRESHOLD_UPPER > R4B_THRESHOLD_UPPER && R4AB_THRESHOLD_UPPER > R4A_THRESHOLD_UPPER)
		{
			if(R4A_THRESHOLD_UPPER > R4B_THRESHOLD_UPPER)
			{
			if(CMPS11_Angle < R4B_THRESHOLD_UPPER || CMPS11_Angle >= R4AB_THRESHOLD_UPPER)
			{
				ROOM[ROOM_COUNTER] = ROOM_1B;
			}
			else if(CMPS11_Angle > R4A_THRESHOLD_UPPER && CMPS11_Angle <= R4AB_THRESHOLD_UPPER)
			{
				ROOM[ROOM_COUNTER] = ROOM_1B;
			}
			}
			else
			{
				if(CMPS11_Angle < R4A_THRESHOLD_UPPER || CMPS11_Angle > R4AB_THRESHOLD_UPPER)
				{
					ROOM[ROOM_COUNTER] = ROOM_1B;
				}
				else if(CMPS11_Angle > R4B_THRESHOLD_UPPER && CMPS11_Angle <= R4AB_THRESHOLD_UPPER)
				{
					ROOM[ROOM_COUNTER] = ROOM_1B;
				}
			}
		}
	}

	else if(SECTION == ROOM_1C_DETECT)
	{
		if(R4AB_THRESHOLD_UPPER < R4B_THRESHOLD_UPPER && R4AB_THRESHOLD_UPPER < R4A_THRESHOLD_UPPER)
		{
			if(R4A_THRESHOLD_UPPER > R4B_THRESHOLD_UPPER)
			{
			if(CMPS11_Angle >= R4AB_THRESHOLD_UPPER && CMPS11_Angle < R4B_THRESHOLD_UPPER)
			{
				ROOM[ROOM_COUNTER] = ROOM_1C;
			}
			else if(CMPS11_Angle <= R4AB_THRESHOLD_UPPER || CMPS11_Angle > R4A_THRESHOLD_UPPER)
			{
				ROOM[ROOM_COUNTER] = ROOM_1C;
			}
			}
			else
			{
				if(R4A_THRESHOLD_UPPER < R4B_THRESHOLD_UPPER)
				{
				if(CMPS11_Angle >= R4AB_THRESHOLD_UPPER && CMPS11_Angle < R4A_THRESHOLD_UPPER)
				{
					ROOM[ROOM_COUNTER] = ROOM_1C;
				}
				else if(CMPS11_Angle <= R4AB_THRESHOLD_UPPER || CMPS11_Angle > R4B_THRESHOLD_UPPER)
				{
					ROOM[ROOM_COUNTER] = ROOM_1C;
				}
				}
			}
		}
		else if(R4AB_THRESHOLD_UPPER > R4B_THRESHOLD_UPPER && R4AB_THRESHOLD_UPPER < R4A_THRESHOLD_UPPER)
		{
			if(CMPS11_Angle <= R4AB_THRESHOLD_UPPER && CMPS11_Angle > R4B_THRESHOLD_UPPER)
			{
				ROOM[ROOM_COUNTER] = ROOM_1C;
			}
			else if(CMPS11_Angle >= R4AB_THRESHOLD_UPPER && CMPS11_Angle < R4A_THRESHOLD_UPPER)
			{
				ROOM[ROOM_COUNTER] = ROOM_1C;
			}
		}
		else if(R4AB_THRESHOLD_UPPER < R4B_THRESHOLD_UPPER && R4AB_THRESHOLD_UPPER > R4A_THRESHOLD_UPPER)
		{
			if(CMPS11_Angle >= R4AB_THRESHOLD_UPPER && CMPS11_Angle < R4B_THRESHOLD_UPPER)
			{
				ROOM[ROOM_COUNTER] = ROOM_1C;
			}
			else if(CMPS11_Angle <= R4AB_THRESHOLD_UPPER && CMPS11_Angle > R4A_THRESHOLD_UPPER)
			{
				ROOM[ROOM_COUNTER] = ROOM_1C;
			}
		}
		else if(R4AB_THRESHOLD_UPPER > R4B_THRESHOLD_UPPER && R4AB_THRESHOLD_UPPER > R4A_THRESHOLD_UPPER)
		{
			if(R4A_THRESHOLD_UPPER > R4B_THRESHOLD_UPPER)
			{
			if(CMPS11_Angle < R4B_THRESHOLD_UPPER || CMPS11_Angle >= R4AB_THRESHOLD_UPPER)
			{
				ROOM[ROOM_COUNTER] = ROOM_1C;
			}
			else if(CMPS11_Angle > R4A_THRESHOLD_UPPER && CMPS11_Angle <= R4AB_THRESHOLD_UPPER)
			{
				ROOM[ROOM_COUNTER] = ROOM_1C;
			}
			}
			else
			{
				if(CMPS11_Angle < R4A_THRESHOLD_UPPER || CMPS11_Angle > R4AB_THRESHOLD_UPPER)
				{
					ROOM[ROOM_COUNTER] = ROOM_1C;
				}
				else if(CMPS11_Angle > R4B_THRESHOLD_UPPER && CMPS11_Angle <= R4AB_THRESHOLD_UPPER)
				{
					ROOM[ROOM_COUNTER] = ROOM_1C;
				}
			}
		}
	}

	else if(SECTION == ROOM_4A_DETECT_IN)
	{
		if(R4B_THRESHOLD_MIDDLE < R4AB_THRESHOLD_LOWER && R4B_THRESHOLD_MIDDLE < R4AB_THRESHOLD_UPPER)
		{
			if(CMPS11_Angle > R4B_THRESHOLD_MIDDLE && CMPS11_Angle < R4AB_THRESHOLD_UPPER)
			{
				ROOM[2] = ROOM_4A;
			}
			else if(CMPS11_Angle < R4B_THRESHOLD_MIDDLE || CMPS11_Angle > R4AB_THRESHOLD_LOWER)
			{
				ROOM[2] = ROOM_4A;
			}
			else if(CMPS11_Angle == R4B_THRESHOLD_MIDDLE)
			{
				ROOM[2] = ROOM_4A;
			}
		}
		else if(R4B_THRESHOLD_MIDDLE > R4AB_THRESHOLD_UPPER && R4B_THRESHOLD_MIDDLE < R4AB_THRESHOLD_LOWER)
		{
			if(CMPS11_Angle < R4B_THRESHOLD_MIDDLE && CMPS11_Angle > R4AB_THRESHOLD_UPPER)
			{
				ROOM[2] = ROOM_4A;
			}
			else if(CMPS11_Angle > R4B_THRESHOLD_MIDDLE && CMPS11_Angle < R4AB_THRESHOLD_LOWER)
			{
				ROOM[2] = ROOM_4A;
			}
			else if(CMPS11_Angle == R4B_THRESHOLD_MIDDLE)
			{
				ROOM[2] = ROOM_4A;
			}
		}
		else if(R4B_THRESHOLD_MIDDLE < R4AB_THRESHOLD_UPPER && R4B_THRESHOLD_MIDDLE > R4AB_THRESHOLD_LOWER)
		{
			if(CMPS11_Angle > R4B_THRESHOLD_MIDDLE && CMPS11_Angle < R4AB_THRESHOLD_UPPER)
			{
				ROOM[2] = ROOM_4A;
			}
			else if(CMPS11_Angle < R4B_THRESHOLD_MIDDLE && CMPS11_Angle > R4AB_THRESHOLD_LOWER)
			{
				ROOM[2] = ROOM_4A;
			}
			else if(CMPS11_Angle == R4B_THRESHOLD_MIDDLE)
			{
				ROOM[2] = ROOM_4A;
			}
		}
		else if(R4B_THRESHOLD_MIDDLE > R4AB_THRESHOLD_UPPER && R4B_THRESHOLD_MIDDLE > R4AB_THRESHOLD_LOWER)
		{
			if(CMPS11_Angle < R4AB_THRESHOLD_UPPER || CMPS11_Angle > R4B_THRESHOLD_MIDDLE)
			{
				ROOM[2] = ROOM_4A;
			}
			else if(CMPS11_Angle < R4B_THRESHOLD_MIDDLE && CMPS11_Angle > R4AB_THRESHOLD_LOWER)
			{
				ROOM[2] = ROOM_4A;
			}
			else if(CMPS11_Angle == R4B_THRESHOLD_MIDDLE)
			{
				ROOM[2] = ROOM_4A;
			}
		}
	}

	else if(SECTION == ROOM_4B_DETECT_IN)
	{
		if(R4A_THRESHOLD_MIDDLE < R4AB_THRESHOLD_LOWER && R4A_THRESHOLD_MIDDLE < R4AB_THRESHOLD_UPPER)
		{
			if(CMPS11_Angle > R4A_THRESHOLD_MIDDLE && CMPS11_Angle < R4AB_THRESHOLD_UPPER)
			{
				ROOM[2] = ROOM_4B;
			}
			else if(CMPS11_Angle < R4A_THRESHOLD_MIDDLE || CMPS11_Angle > R4AB_THRESHOLD_LOWER)
			{
				ROOM[2] = ROOM_4B;
			}
		}
		else if(R4A_THRESHOLD_MIDDLE > R4AB_THRESHOLD_UPPER && R4A_THRESHOLD_MIDDLE < R4AB_THRESHOLD_LOWER)
		{
			if(CMPS11_Angle < R4A_THRESHOLD_MIDDLE && CMPS11_Angle > R4AB_THRESHOLD_UPPER)
			{
				ROOM[2] = ROOM_4B;
			}
			else if(CMPS11_Angle > R4A_THRESHOLD_MIDDLE && CMPS11_Angle < R4AB_THRESHOLD_LOWER)
			{
				ROOM[2] = ROOM_4B;
			}
		}
		else if(R4A_THRESHOLD_MIDDLE < R4AB_THRESHOLD_UPPER && R4A_THRESHOLD_MIDDLE > R4AB_THRESHOLD_LOWER)
		{
			if(CMPS11_Angle > R4A_THRESHOLD_MIDDLE && CMPS11_Angle < R4AB_THRESHOLD_UPPER)
			{
				ROOM[2] = ROOM_4B;
			}
			else if(CMPS11_Angle < R4A_THRESHOLD_MIDDLE && CMPS11_Angle > R4A_THRESHOLD_LOWER)
			{
				ROOM[2] = ROOM_4B;
			}
		}
		else if(R4A_THRESHOLD_MIDDLE > R4AB_THRESHOLD_UPPER && R4A_THRESHOLD_MIDDLE > R4AB_THRESHOLD_LOWER)
		{
			if(CMPS11_Angle < R4AB_THRESHOLD_UPPER || CMPS11_Angle > R4A_THRESHOLD_MIDDLE)
			{
				ROOM[2] = ROOM_4B;
			}
			else if(CMPS11_Angle < R4A_THRESHOLD_MIDDLE && CMPS11_Angle > R4AB_THRESHOLD_LOWER)
			{
				ROOM[2] = ROOM_4B;
			}
		}
	}

	else if(SECTION == ROOM_1B_DETECT_NAV)
	{
		if(R4AB_THRESHOLD_UPPER < R4B_THRESHOLD_UPPER && R4AB_THRESHOLD_UPPER < R4A_THRESHOLD_UPPER)
		{
			if(R4A_THRESHOLD_UPPER > R4B_THRESHOLD_UPPER)
			{
			if(CMPS11_Angle > R4AB_THRESHOLD_UPPER && CMPS11_Angle < R4B_THRESHOLD_UPPER)
			{
				ROOM[ROOM_COUNTER] = ROOM_1B;
			}
			else if(CMPS11_Angle < R4AB_THRESHOLD_UPPER || CMPS11_Angle > R4A_THRESHOLD_UPPER)
			{
				ROOM[ROOM_COUNTER] = ROOM_1B;
			}
			}
			else
			{
				if(R4A_THRESHOLD_UPPER < R4B_THRESHOLD_UPPER)
				{
				if(CMPS11_Angle > R4AB_THRESHOLD_UPPER && CMPS11_Angle < R4A_THRESHOLD_UPPER)
				{
					ROOM[ROOM_COUNTER] = ROOM_1B;
				}
				else if(CMPS11_Angle < R4AB_THRESHOLD_UPPER || CMPS11_Angle > R4B_THRESHOLD_UPPER)
				{
					ROOM[ROOM_COUNTER] = ROOM_1B;
				}
				}
			}
		}
		else if(R4AB_THRESHOLD_UPPER > R4B_THRESHOLD_UPPER && R4AB_THRESHOLD_UPPER < R4A_THRESHOLD_UPPER)
		{
			if(CMPS11_Angle < R4AB_THRESHOLD_UPPER && CMPS11_Angle > R4B_THRESHOLD_UPPER)
			{
				ROOM[ROOM_COUNTER] = ROOM_1B;
			}
			else if(CMPS11_Angle > R4AB_THRESHOLD_UPPER && CMPS11_Angle < R4A_THRESHOLD_UPPER)
			{
				ROOM[ROOM_COUNTER] = ROOM_1B;
			}
		}
		else if(R4AB_THRESHOLD_UPPER < R4B_THRESHOLD_UPPER && R4AB_THRESHOLD_UPPER > R4A_THRESHOLD_UPPER)
		{
			if(CMPS11_Angle > R4AB_THRESHOLD_UPPER && CMPS11_Angle < R4B_THRESHOLD_UPPER)
			{
				ROOM[ROOM_COUNTER] = ROOM_1B;
			}
			else if(CMPS11_Angle < R4AB_THRESHOLD_UPPER && CMPS11_Angle > R4A_THRESHOLD_UPPER)
			{
				ROOM[ROOM_COUNTER] = ROOM_1B;
			}
		}
		else if(R4AB_THRESHOLD_UPPER > R4B_THRESHOLD_UPPER && R4AB_THRESHOLD_UPPER > R4A_THRESHOLD_UPPER)
		{
			if(R4A_THRESHOLD_UPPER > R4B_THRESHOLD_LOWER)
			{
			if(CMPS11_Angle < R4B_THRESHOLD_UPPER || CMPS11_Angle > R4AB_THRESHOLD_UPPER)
			{
				ROOM[ROOM_COUNTER] = ROOM_1B;
			}
			else if(CMPS11_Angle > R4A_THRESHOLD_UPPER && CMPS11_Angle < R4AB_THRESHOLD_UPPER)
			{
				ROOM[ROOM_COUNTER] = ROOM_1B;
			}
			}
			else
			{
				if(CMPS11_Angle < R4A_THRESHOLD_UPPER || CMPS11_Angle > R4AB_THRESHOLD_UPPER)
				{
					ROOM[ROOM_COUNTER] = ROOM_1B;
				}
				else if(CMPS11_Angle > R4B_THRESHOLD_UPPER && CMPS11_Angle < R4AB_THRESHOLD_UPPER)
				{
					ROOM[ROOM_COUNTER] = ROOM_1B;
				}
			}
		}
	}

	else if(SECTION == ROOM_1C_DETECT_NAV)
	{
		if(R4AB_THRESHOLD_UPPER < R4B_THRESHOLD_UPPER && R4AB_THRESHOLD_UPPER < R4A_THRESHOLD_UPPER)
		{
			if(R4A_THRESHOLD_UPPER > R4B_THRESHOLD_UPPER)
			{
			if(CMPS11_Angle > R4AB_THRESHOLD_UPPER && CMPS11_Angle < R4B_THRESHOLD_UPPER)
			{
				ROOM[2] = ROOM_1C;
			}
			else if(CMPS11_Angle < R4AB_THRESHOLD_UPPER || CMPS11_Angle > R4A_THRESHOLD_UPPER)
			{
				ROOM[2] = ROOM_1C;
			}
			}
			else
			{
				if(R4A_THRESHOLD_UPPER < R4B_THRESHOLD_UPPER)
				{
				if(CMPS11_Angle > R4AB_THRESHOLD_UPPER && CMPS11_Angle < R4A_THRESHOLD_UPPER)
				{
					ROOM[2] = ROOM_1C;
				}
				else if(CMPS11_Angle < R4AB_THRESHOLD_UPPER || CMPS11_Angle > R4B_THRESHOLD_UPPER)
				{
					ROOM[2] = ROOM_1C;
				}
				}
			}
		}
		else if(R4AB_THRESHOLD_UPPER > R4B_THRESHOLD_UPPER && R4AB_THRESHOLD_UPPER < R4A_THRESHOLD_UPPER)
		{
			if(CMPS11_Angle < R4AB_THRESHOLD_UPPER && CMPS11_Angle > R4B_THRESHOLD_UPPER)
			{
				ROOM[2] = ROOM_1C;
			}
			else if(CMPS11_Angle > R4AB_THRESHOLD_UPPER && CMPS11_Angle < R4A_THRESHOLD_UPPER)
			{
				ROOM[2] = ROOM_1C;
			}
		}
		else if(R4AB_THRESHOLD_UPPER < R4B_THRESHOLD_UPPER && R4AB_THRESHOLD_UPPER > R4A_THRESHOLD_UPPER)
		{
			if(CMPS11_Angle > R4AB_THRESHOLD_UPPER && CMPS11_Angle < R4B_THRESHOLD_UPPER)
			{
				ROOM[2] = ROOM_1C;
			}
			else if(CMPS11_Angle < R4AB_THRESHOLD_UPPER && CMPS11_Angle > R4A_THRESHOLD_UPPER)
			{
				ROOM[2] = ROOM_1C;
			}
		}
		else if(R4AB_THRESHOLD_UPPER > R4B_THRESHOLD_UPPER && R4AB_THRESHOLD_UPPER > R4A_THRESHOLD_UPPER)
		{
			if(R4A_THRESHOLD_UPPER > R4B_THRESHOLD_LOWER)
			{
			if(CMPS11_Angle < R4B_THRESHOLD_UPPER || CMPS11_Angle > R4AB_THRESHOLD_UPPER)
			{
				ROOM[2] = ROOM_1C;
			}
			else if(CMPS11_Angle > R4A_THRESHOLD_UPPER && CMPS11_Angle < R4AB_THRESHOLD_UPPER)
			{
				ROOM[2] = ROOM_1C;
			}
			}
			else
			{
				if(CMPS11_Angle < R4A_THRESHOLD_UPPER || CMPS11_Angle > R4AB_THRESHOLD_UPPER)
				{
					ROOM[2] = ROOM_1C;
				}
				else if(CMPS11_Angle > R4B_THRESHOLD_UPPER && CMPS11_Angle < R4AB_THRESHOLD_UPPER)
				{
					ROOM[2] = ROOM_1C;
				}
			}
		}
	}

	else if(SECTION == STAIRS_DIRECTION_4B)
	{
		{

			if((CMPS11_Angle >STAIRS_THRESHOLD_4B_UPPER && CMPS11_Angle < STAIRS_THRESHOLD_4B_MIDDLE)
					||
					(CMPS11_Angle < STAIRS_THRESHOLD_4B_UPPER && CMPS11_Angle > STAIRS_THRESHOLD_4B_MIDDLE)
			)
			{
				while(
						(CMPS11_Angle >STAIRS_THRESHOLD_4B_UPPER && CMPS11_Angle < STAIRS_THRESHOLD_4B_MIDDLE)
						||
						(CMPS11_Angle <STAIRS_THRESHOLD_4B_UPPER && CMPS11_Angle > STAIRS_THRESHOLD_4B_MIDDLE)
				)
				{
					if(CMPS11_Angle == STAIRS_THRESHOLD_4B_MIDDLE) break;
					Dynamx_Rot_Right_Interpolate(LEVEL2,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if(CMPS11_Angle == STAIRS_THRESHOLD_4B_MIDDLE) break;
				}

				if((CMPS11_Angle > STAIRS_THRESHOLD_4B_LOWER && CMPS11_Angle < STAIRS_THRESHOLD_4B_MIDDLE)
					||
					(CMPS11_Angle < STAIRS_THRESHOLD_4B_LOWER && CMPS11_Angle > STAIRS_THRESHOLD_4B_MIDDLE)
					)

				{
					while((CMPS11_Angle > STAIRS_THRESHOLD_4B_LOWER && CMPS11_Angle < STAIRS_THRESHOLD_4B_MIDDLE)
					||
					(CMPS11_Angle < STAIRS_THRESHOLD_4B_LOWER && CMPS11_Angle > STAIRS_THRESHOLD_4B_MIDDLE))
					{
						if(CMPS11_Angle == STAIRS_THRESHOLD_4B_MIDDLE) break;
						Dynamx_Rot_Left_Interpolate(LEVEL2,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if(CMPS11_Angle == STAIRS_THRESHOLD_4B_MIDDLE) break;
					}
				}
			}

			else if(
					(CMPS11_Angle > STAIRS_THRESHOLD_4B_LOWER && CMPS11_Angle < STAIRS_THRESHOLD_4B_MIDDLE)
					||
					(CMPS11_Angle < STAIRS_THRESHOLD_4B_LOWER && CMPS11_Angle > STAIRS_THRESHOLD_4B_MIDDLE)
			)
			{
				while(
						(CMPS11_Angle > STAIRS_THRESHOLD_4B_LOWER && CMPS11_Angle < STAIRS_THRESHOLD_4B_MIDDLE)
						||
						(CMPS11_Angle < STAIRS_THRESHOLD_4B_LOWER && CMPS11_Angle > STAIRS_THRESHOLD_4B_MIDDLE)
				)
				{
					if(CMPS11_Angle == STAIRS_THRESHOLD_4B_MIDDLE) break;
					Dynamx_Rot_Left_Interpolate(LEVEL2,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if(CMPS11_Angle == STAIRS_THRESHOLD_4B_MIDDLE) break;
				}

				if(
						(CMPS11_Angle >STAIRS_THRESHOLD_4B_UPPER && CMPS11_Angle < STAIRS_THRESHOLD_4B_MIDDLE)
											||
						(CMPS11_Angle < STAIRS_THRESHOLD_4B_UPPER && CMPS11_Angle > STAIRS_THRESHOLD_4B_MIDDLE)
				)
				{
					while(
							(CMPS11_Angle >STAIRS_THRESHOLD_4B_UPPER && CMPS11_Angle < STAIRS_THRESHOLD_4B_MIDDLE)
																		||
							(CMPS11_Angle < STAIRS_THRESHOLD_4B_UPPER && CMPS11_Angle > STAIRS_THRESHOLD_4B_MIDDLE)
							)
					{
						if(CMPS11_Angle == STAIRS_THRESHOLD_4B_MIDDLE) break;
						Dynamx_Rot_Right_Interpolate(LEVEL2,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if(CMPS11_Angle == STAIRS_THRESHOLD_4B_MIDDLE) break;
					}
				}
			}
		}

	}

	else if(SECTION == STAIRS_DIRECTION_4A)
	{
		{

			if(CMPS11_Angle > R4A_THRESHOLD_UPPER && CMPS11_Angle < R4A_THRESHOLD_MIDDLE
					||
					CMPS11_Angle < R4A_THRESHOLD_UPPER && CMPS11_Angle > R4A_THRESHOLD_MIDDLE
			)
			{
				while(
						CMPS11_Angle < R4A_THRESHOLD_UPPER && CMPS11_Angle > R4A_THRESHOLD_MIDDLE
						||
						CMPS11_Angle > R4A_THRESHOLD_UPPER && CMPS11_Angle < R4A_THRESHOLD_MIDDLE
				)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_ENABLE);
				}

			}

			else if(
					CMPS11_Angle > R4A_THRESHOLD_LOWER && CMPS11_Angle < R4A_THRESHOLD_MIDDLE
					||
					CMPS11_Angle > R4A_THRESHOLD_LOWER && CMPS11_Angle < R4A_THRESHOLD_MIDDLE
			)
			{
				while(
						CMPS11_Angle > R4A_THRESHOLD_LOWER && CMPS11_Angle < R4A_THRESHOLD_MIDDLE
						||
						CMPS11_Angle > R4A_THRESHOLD_LOWER && CMPS11_Angle < R4A_THRESHOLD_MIDDLE
				)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_ENABLE);
				}
			}
		}
	}

	COMPASS_INTERRUPT = 0;

}

/* func      : void Nav_1A_To_2(void)
 * brief     : Navigate from Room 1A to Room 2
 * param     : N/A
 * retval    : N/A
 * Ver       : 6
 * written By: Ryan (Thursday, March 28th 2016)
 * Revised BY: Ver.2 : Ryan (Tuesday, April 5th 2016)
 * 			   Ver.3 : Hafidin (Wed, Feb 22th 2017)
 * 			   Ver.4 : Ryan (Thursday, April 20th 2017)
 * 			   Ver.5 : Ryan (Sunday, April 23rd 2017)
 * 			   Ver.6 : Hafidin (Tue, May 2nd, 2017)
 * 			   Ver.7 : Toni (Wednesday, November 22th, 2017)
 * programmer's Note:
 */
void Nav_1A_To_2(void)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1A TO R2");lcd_putstr(lcd);
	delay_ms(100);

	ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;
	Cat_Avoider();
	CAT_FLAG=CAT_NOT_DETECTED;

	if((Ping[PING_RIGHT]+4)<(Ping[PING_REAR_RIGHT]))
	{
		Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		if((Ping[PING_RIGHT]+4)<(Ping[PING_REAR_RIGHT]))
		{
			Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		}
	}
	else
	{
		if(((Ping[PING_RIGHT])>(Ping[PING_REAR_RIGHT] + 4)) && Ping[PING_RIGHT] < 60)
		{
			Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		}

		if(((Ping[PING_RIGHT])>(Ping[PING_REAR_RIGHT] + 4)) && Ping[PING_RIGHT] < 60)
		{
			Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		}
	}

	if(CAT_FLAG_A==CAT_DETECTED || CAT_FLAG_B==CAT_DETECTED)
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

		if(Ping[PING_RIGHT] < 16)
		{
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
		}

		if(Ping[PING_RIGHT] < 16)
		{
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
		}

		Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);

		int l;
		for(l = 0;l <= 2;l++)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1] == COLOUR_GRAY)break;
			if((Ping[PING_ASKEW_LEFT] < 11 || Ping[PING_LEFT] < 11))
			{
				BW_FollowCounter_Left(1);
			}
			else if(Ping[PING_ASKEW_RIGHT] < 11 || Ping[PING_RIGHT] < 11)
			{
				BW_FollowCounter_Right(1);
			}
			else Dynamx_MovFwd4cm_Interpolate(4,LEVEL6, IKCALC_DISABLE);
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1] == COLOUR_GRAY)break;
		}

		BW_PID_Init();
		BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

		BW_PID_Init();
		BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

		Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);

		BW_PID_Init();
		BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

		BW_PID_Init();
		BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

		Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL5);

		BW_PID_Init();
		BW_FollowTracer_Right_Interpolate();

	}
	else
	{
	BW_PID_Init();
	BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

	Dynamx_MovFwd4cm_Interpolate(4,LEVEL3,IKCALC_ENABLE);

	if(CAT_FLAG_C==CAT_DETECTED)
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
	}
	else
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
	}

	BW_PID_Init_FAR();
	BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

	if(CAT_FLAG==CAT_NOT_DETECTED)
	{
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);
		if(CAT_FLAG_C==CAT_DETECTED)
		{
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
		}
		else
		{
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
		}

		BW_PID_Init_FAR();
		BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);
		if(CAT_FLAG==CAT_NOT_DETECTED)
		{
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

			BW_PID_Init();
			BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"PUTAR BALIK");lcd_putstr(lcd);

			Dynamx_MovBwd_Interpolate(3,LEVEL5,IKCALC_ENABLE);

			Nav_TurnAround(TURN_LEFT);

			BW_PID_Init();
			BW_FollowTracer_Right_Interpolate();
		}

		else
		{
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

			Dynamx_MovBwd_Interpolate(8,LEVEL5,IKCALC_ENABLE);

			if(Ping[PING_RIGHT]>20)
			{
				Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
				if(Ping[PING_RIGHT]>20)
						{
							Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
						}
			}
			while(Ping[PING_RIGHT]<20)
			{
				Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
			}

			Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);

			while(Ping[PING_FRONT]<20)
			{
				Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
			}

			BW_PID_Init();
			BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

			BW_PID_Init();
			BW_FollowCounter_Left(10);

			BW_PID_Init();
			BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

			BW_PID_Init();
			BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

			BW_PID_Init();
			BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);

			BW_PID_Init();
			BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

			BW_PID_Init();
			BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

			Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);

			BW_PID_Init();
			BW_FollowTracer_Right_Interpolate();
		}

	}
	else
	{
		CAT_DETECTOR=CAT_DIACTIVATED;
		CAT_FLAG=CAT_NOT_DETECTED;
		REVERSE_FLAG=REVERSEFLAG_ACTIVE;
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
		R4ATO1_SP_ROUTE=SP_ROUTE_ACTIVE;

		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"ALTERNATE");lcd_putstr(lcd);
		lcd_gotoxy(8,1);sprintf(lcd,"ROUTE");lcd_putstr(lcd);
		delay_ms(100);

		Dynamx_MovBwd_Interpolate(4,LEVEL5,IKCALC_ENABLE);

		Nav_TurnAround(TURN_LEFT);

		Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);

		BW_PID_Init();
		BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

		BW_PID_Init();
		BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

		BW_PID_Init();
		BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

		Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);

		BW_PID_Init();
		BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

		BW_PID_Init();
		BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

		Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);

		BW_PID_Init();
		BW_FollowTracer_Right_Interpolate();
	}
}
}

void Nav_1A_To_3(void)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1A TO R3");lcd_putstr(lcd);
	delay_ms(100);

	if((Ping[PING_RIGHT]+4)<(Ping[PING_REAR_RIGHT]))
	{
		Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		if((Ping[PING_RIGHT]+4)<(Ping[PING_REAR_RIGHT]))
		{
			Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		}
	}

	else
	{
		if(((Ping[PING_RIGHT])>(Ping[PING_REAR_RIGHT] + 4)) && Ping[PING_RIGHT] < 60)
		{
			Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		}

		if(((Ping[PING_RIGHT])>(Ping[PING_REAR_RIGHT] + 4)) && Ping[PING_RIGHT] < 60)
		{
			Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		}
	}

	ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;
	Cat_Avoider();

	if(CAT_FLAG_A==CAT_DETECTED || CAT_FLAG_B==CAT_DETECTED)
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

		if(Ping[PING_RIGHT] < 20)
		{
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
		}

		if(Ping[PING_RIGHT] < 20)
		{
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
		}

		Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);

		Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);

		int l;
		for(l = 0;l <= 3;l++)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1] == COLOUR_GRAY)break;

			if((Ping[PING_ASKEW_LEFT] < 11 || Ping[PING_LEFT] < 11))
			{
				BW_FollowCounter_Left(1);
			}

			else if(Ping[PING_ASKEW_RIGHT] < 11 || Ping[PING_RIGHT] < 11)
			{
				BW_FollowCounter_Right(1);
			}
			else Dynamx_MovFwd4cm_Interpolate(4,LEVEL6, IKCALC_ENABLE);
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1] == COLOUR_GRAY)break;
		}

		BW_PID_Init();
		BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

		BW_PID_Init();
		BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

		BW_PID_Init();
		BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

		Dynamx_Rot_Left_Interpolate(LEVEL3, HEXSTEP_FAR, IKCALC_DISABLE);

		BW_PID_Init();
		BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

		Nav_TurnAround(TURN_RIGHT);

		BW_PID_Init();
		BW_FollowTracer_Left_Interpolate();

	}
	else
	{
		if(Ping[PING_RIGHT]>=10)
		{
			Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
		}

		BW_PID_Init();
		CAT_DETECTOR = CAT_ACTIVATED;
		BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

		if(CAT_FLAG_C==CAT_DETECTED)
		{
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
		}
		else
		{
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
		}

		BW_PID_Init_FAR();
		BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

		if(CAT_FLAG==CAT_NOT_DETECTED)
		{
			if(CAT_FLAG_C==CAT_DETECTED)
			{
				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
			}
			else
			{
				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
			}

			BW_PID_Init_FAR();
			BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

			if(CAT_FLAG==CAT_NOT_DETECTED)
			{
				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

				BW_PID_Init();
				BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

				BW_PID_Init();
				BW_FollowTracer_Right_Interpolate();
			}
			else
			{
				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

				Dynamx_MovBwd_Interpolate(6,LEVEL5,IKCALC_ENABLE);

				while(Ping[PING_RIGHT]<20)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
				}

				Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);

				while(Ping[PING_FRONT]<20)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
				}

				BW_PID_Init();
				BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

				BW_PID_Init();
				BW_FollowCounter_Left(12);

				Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);

				BW_PID_Init();
				BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

				BW_PID_Init();
				BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

				BW_PID_Init();
				BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);

				BW_PID_Init();
				BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

				BW_PID_Init();
				BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

				Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);

				Nav_TurnAround(TURN_RIGHT);

				BW_PID_Init();
				BW_FollowTracer_Left_Interpolate();
			}
		}
		else
		{
			CAT_DETECTOR=CAT_DIACTIVATED;
			CAT_FLAG=CAT_NOT_DETECTED;
			REVERSE_FLAG=REVERSEFLAG_ACTIVE;
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
			R4ATO1_SP_ROUTE=SP_ROUTE_ACTIVE;

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"ALTERNATE");lcd_putstr(lcd);
			lcd_gotoxy(8,1);sprintf(lcd,"ROUTE");lcd_putstr(lcd);
			delay_ms(100);

			Dynamx_MovBwd_Interpolate(3,LEVEL5,IKCALC_ENABLE);

			Nav_TurnAround(TURN_LEFT);

			Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);

			BW_PID_Init();
			BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

			BW_PID_Init();
			BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

			BW_PID_Init();
			BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);

			BW_PID_Init();
			BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

			BW_PID_Init();
			BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

			Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);

			Nav_TurnAround(TURN_RIGHT);

			BW_PID_Init();
			BW_FollowTracer_Left_Interpolate();

		}
	}
}

/* func      : void Nav_1A_To_4B(void)
 * brief     : Navigate from Room 1A to Room 4B
 * param     : N/A
 * retval    : N/A
 * Ver       : 4
 * written By: Ryan (Thursday, March 28th 2016)
 * Revised BY: Ver.2 : Ryan (Tuesday, April 5th 2016)
 * 			   Ver.3 : Hafidin (Wed, Feb 23th 2017)
 * 			   Ver.4 : Hafidin (Tue, May 2nd, 2017)
 * programmer's Note:
 */

void Nav_1A_To_4B(void)
{
	BW_Buzz(1);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1A TO R4B");lcd_putstr(lcd);
	delay_ms(100);

	if((Ping[PING_RIGHT]+2)<(Ping[PING_REAR_RIGHT]))
	{
		Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		if((Ping[PING_RIGHT]+2)<(Ping[PING_REAR_RIGHT]))
		{
			Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		}
	}
	else
	{

		if(((Ping[PING_RIGHT])>(Ping[PING_REAR_RIGHT] + 2)) && Ping[PING_RIGHT] < 30)
		{
			Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		}
		if(((Ping[PING_RIGHT])>(Ping[PING_REAR_RIGHT] + 2)) && Ping[PING_RIGHT] < 30)
		{
			Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		}

	}

	if((CAT_FLAG_A==CAT_DETECTED) || (CAT_FLAG_B==CAT_DETECTED))
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

		if(Ping[PING_RIGHT] < 20)
		{
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
		}

		if(Ping[PING_RIGHT] < 20)
		{
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
		}

		Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_CLOSE,IKCALC_DISABLE);

		Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);

		int l;
		for(l = 0;l <= 2;l++)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1] == COLOUR_GRAY)break;
			if((Ping[PING_ASKEW_LEFT] < 11 || Ping[PING_LEFT] < 11))
			{
				BW_FollowCounter_Left(1);

			}
			else if(Ping[PING_ASKEW_RIGHT] < 11 || Ping[PING_RIGHT] < 11)
			{
				BW_FollowCounter_Right(1);
			}
			else Dynamx_MovFwd4cm_Interpolate(4,LEVEL6, IKCALC_ENABLE);
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1] == COLOUR_GRAY)break;
		}

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

		BW_Buzz(1);
		BW_PID_Init();
		BW_FollowTracer_Right_Interpolate();
	}
	else if(CAT_FLAG_C==CAT_DETECTED)
	{
		ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;

		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
		CAT_FLAG=CAT_NOT_DETECTED;

		if(Ping[PING_RIGHT]>=10)
		{
				Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
		}
		BW_Buzz(1);
		BW_PID_Init_FAR();
		BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

		BW_Buzz(1);
		BW_PID_Init_FAR();
		BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

		BW_Buzz(1);
		BW_PID_Init();
		BW_FollowTracer_Left_Interpolate();
	}
	else
	{
		ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;

		CAT_FLAG=CAT_NOT_DETECTED;

		if(Ping[PING_RIGHT]>=10)
		{
				Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
		}
		BW_Buzz(1);
		BW_PID_Init_FAR();
		BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

		if(CAT_FLAG_C==CAT_DETECTED)
		{
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
		}
		else
		{
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
		}

		BW_Buzz(1);
		BW_PID_Init_FAR();
		BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

		if(CAT_FLAG==CAT_NOT_DETECTED)
		{
			BW_Buzz(1);
			BW_PID_Init_FAR();
			BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);
			Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);

			if(/*Ping[PING_ASKEW_LEFT]>=30 || */Ping[PING_LEFT]>=30)
			{
				ROOM4A_FLAG = ROOM4AFLAG_ACTIVE;
				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);

				Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_MED,IKCALC_DISABLE);

				BW_Buzz(1);
				BW_PID_Init();
				BW_FollowTracer_Left_Interpolate();

			}
			else
			{
				ROOM4B_FLAG = ROOM4BFLAG_ACTIVE;;

				if(CAT_FLAG_C==CAT_DETECTED)
				{
					SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
				}
				else
				{
					SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
				}

				if(Ping[PING_ASKEW_RIGHT]>Ping[PING_REAR_RIGHT])
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				}
				else
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				}

				BW_Buzz(1);
				BW_PID_Init_FAR();
				BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

				if(CAT_FLAG==CAT_DETECTED)
				{
					SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

					CAT_DETECTOR=CAT_DIACTIVATED;
					CAT_FLAG=CAT_NOT_DETECTED;
					REVERSE_FLAG=REVERSEFLAG_ACTIVE;

					R4ATO1_SP_ROUTE=SP_ROUTE_ACTIVE;

					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"ALTERNATE");lcd_putstr(lcd);
					lcd_gotoxy(8,1);sprintf(lcd,"ROUTE");lcd_putstr(lcd);
					delay_ms(100);

					Dynamx_MovBwd_Interpolate(4,LEVEL5,IKCALC_ENABLE);

					Nav_TurnAround(TURN_LEFT);

					Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);

					BW_Buzz(1);
					BW_PID_Init();
					BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

					BW_Buzz(1);
					BW_PID_Init();
					BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

					BW_Buzz(1);
					BW_PID_Init();
					BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

					BW_Buzz(1);
					BW_PID_Init();
					BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

					BW_Buzz(1);
					BW_PID_Init();
					BW_FollowTracer_Right_Interpolate();
				}

				else
				{
					BW_Buzz(1);
					BW_PID_Init();
					BW_FollowTracer_Left_Interpolate();
				}

			}

		}

		else if(CAT_FLAG==CAT_DETECTED)
		{
			CAT_DETECTOR=CAT_DIACTIVATED;
			CAT_FLAG=CAT_NOT_DETECTED;
			REVERSE_FLAG=REVERSEFLAG_ACTIVE;

			R4ATO1_SP_ROUTE=SP_ROUTE_ACTIVE;

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"ALTERNATE");lcd_putstr(lcd);
			lcd_gotoxy(8,1);sprintf(lcd,"ROUTE");lcd_putstr(lcd);
			delay_ms(100);


			Dynamx_MovBwd_Interpolate(3,LEVEL5,IKCALC_ENABLE);

			Nav_TurnAround(TURN_LEFT);

			Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

			Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);
			if(/*(Ping[PING_ASKEW_RIGHT]>30)||*/(Ping[PING_RIGHT]>=30))
			{
				BW_Buzz(1);
				BW_PID_Init();
				BW_FollowTracer_Right_Interpolate();
			}
			else
			{
				BW_PID_Init();
				BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

				BW_PID_Init();
				BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

				BW_PID_Init();
				BW_FollowTracer_Right_Interpolate();
			}
		}
	}

	/*
	 * 	ACTIVATE ROOM4AB_FLAG
	 */

	ROOM4AB_FLAG=ROOM4AB_ACTIVE;
}

/* func      : void Nav_1A_To_4A(void)
 * brief     : Navigate from Room 1A to Room 4A
 * param     : N/A
 * retval    : N/A
 * Ver       : 4
 * written By: Ryan (Thursday, March 28th 2016)
 * Revised BY: Ver.2 : Hafidin (Wed, Feb 23th 2017)
 * 			   Ver.3 : Ryan (Saturday, April 22nd 2017)
 * 			   			Added special route flag to R1BC when cat has been determined in config B/C
 *			   Ver.4 : Ryan (Sunday, April 23rd 2017)
 * 			   			Changes the wall following directions when CAT is not in config B
 * programmer's Note:
 */
void Nav_1A_To_4A(void)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1A TO R4A");lcd_putstr(lcd);
	delay_ms(100);

	if((Ping[PING_RIGHT]+4)<(Ping[PING_REAR_RIGHT]))
	{
		Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

		if((Ping[PING_RIGHT]+4)<(Ping[PING_REAR_RIGHT]))
		{
			Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		}
	}

	else
	{
		if(((Ping[PING_RIGHT])>(Ping[PING_REAR_RIGHT] + 4)) && Ping[PING_RIGHT] < 60)
		{
			Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		}
		if(((Ping[PING_RIGHT])>(Ping[PING_REAR_RIGHT] + 4)) && Ping[PING_RIGHT] < 60)
		{
			Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
		}
	}


	if(CAT_FLAG_B == CAT_DETECTED)
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

		if(ROOM_1A_MANUAL == 0)
		{

		}

		if(ROOM_1A_MANUAL==1)
		{
			// ON PROCESS
		}

		if(Ping[PING_RIGHT] < 20)
		{
			Dynamx_Slide_Left_Interpolate(HEXSTEP_CLOSE, LEVEL3);
		}

		if(Ping[PING_RIGHT] < 20)
		{
			Dynamx_Slide_Left_Interpolate(HEXSTEP_CLOSE, LEVEL3);
		}

		Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);

		Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);

		BW_PID_Init();

		int l;
		for(l = 0;l <= 2;l++)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1] == COLOUR_GRAY)break;
			if((Ping[PING_ASKEW_LEFT] < 11 || Ping[PING_LEFT] < 11))
			{
				BW_FollowCounter_Left(1);
			}
			else if(Ping[PING_ASKEW_RIGHT] < 11 || Ping[PING_RIGHT] < 11)
			{
				BW_FollowCounter_Right(1);
			}
			else Dynamx_MovFwd4cm_Interpolate(4,LEVEL6, IKCALC_ENABLE);
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1] == COLOUR_GRAY)break;
		}

		BW_PID_Init();
		BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

		BW_PID_Init();
		BW_FollowTracer_Right_Interpolate();
	}
	else if((CAT_FLAG_A == CAT_DETECTED || CAT_FLAG_B == CAT_DETECTED) && EXTINGUISHED_FIRE == 1)
	{
		BW_PID_Init();
		BWFollowCarpet_Right_Interpolate(COLOUR_GRAY, INVERSE);

		BW_PID_Init();
		BW_FollowTracer_Left_Interpolate();
	}

	else
	{
	ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;

	CAT_FLAG=CAT_NOT_DETECTED;

	if(Ping[PING_RIGHT] > 15 || Ping[PING_ASKEW_RIGHT] >= 17)
	{
		Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);
	}

	BW_PID_Init();
	CAT_DETECTOR = CAT_ACTIVATED;

	BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

	if(CAT_FLAG_C==CAT_DETECTED)
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
	}
	else
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
	}

	if(CAT_FLAG==CAT_NOT_DETECTED)
	{

		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"NO CAT");lcd_putstr(lcd);

		BW_PID_Init();
		while(Ping[PING_FRONT] > 24)
		{
			Cat_Avoider();
			if(CAT_FLAG == CAT_DETECTED)break;

			if(Ping[PING_FRONT] < 24)break;
			BW_FollowCounter_Right(1);
			Cat_Avoider();
			if(CAT_FLAG == CAT_DETECTED)break;
		}

		if(CAT_FLAG==CAT_DETECTED)
		{
			CAT_DETECTOR=CAT_DIACTIVATED;
			CAT_FLAG=CAT_NOT_DETECTED;
			REVERSE_FLAG=REVERSEFLAG_ACTIVE;
			CAT_FLAG_B=CAT_DETECTED;

			R4ATO1_SP_ROUTE=SP_ROUTE_ACTIVE;
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"ALTERNATE");lcd_putstr(lcd);
			lcd_gotoxy(8,1);sprintf(lcd,"ROUTE");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"CAT B");lcd_putstr(lcd);
			delay_ms(100);

			Dynamx_MovBwd_Interpolate(3,LEVEL3,IKCALC_ENABLE);

			Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_CLOSE,IKCALC_DISABLE);

			while(Ping[PING_FRONT] < 30)
			{
				Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_CLOSE,IKCALC_DISABLE);
			}

			BW_PID_Init();
			BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

			BW_PID_Init();
			BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

			BW_PID_Init();
			BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

			if((Ping[PING_RIGHT]>=30))
			{
				BW_PID_Init();
				BW_FollowTracer_Right_Interpolate();
				if(ROOM_4B_MANUAL == 1)ROOM[2] = ROOM_4B;
			}
			else
			{

			BW_PID_Init();
			BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

			Dynamx_Rot_Right_Interpolate(LEVEL3, HEXSTEP_CLOSE, IKCALC_DISABLE);

			BW_PID_Init();
			BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

			Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_CLOSE,IKCALC_DISABLE);

			BW_PID_Init();
			BW_FollowTracer_Right_Interpolate();
			if(ROOM_4A_MANUAL == 1)ROOM[2] = ROOM_4A;
			}
		}
		else
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"TO 4A");lcd_putstr(lcd);
			Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
			Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_FAR,IKCALC_DISABLE);
			if(Ping[PING_FRONT] < 17)
			{
				Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_CLOSE,IKCALC_DISABLE);
			}
			if(Ping[PING_ASKEW_RIGHT] < 18)
			{
				Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_CLOSE,IKCALC_DISABLE);
			}

			BW_PID_Init();
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
			BWFollowCarpet_Right_Interpolate(COLOUR_BLACK, INVERSE);

			BW_PID_Init();

			if(Ping[PING_LEFT] >= 30 /*|| Ping[PING_ASKEW_LEFT] >= 25*/)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"4A DETECT");lcd_putstr(lcd);
				ROOM4A_FLAG = ROOM4AFLAG_ACTIVE;

				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);

				Dynamx_Rot_Left_Interpolate(LEVEL3, HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Rot_Left_Interpolate(LEVEL3, HEXSTEP_CLOSE,IKCALC_DISABLE);

				BW_PID_Init();
				BW_FollowTracer_Left_Interpolate();
				if(ROOM_4A_MANUAL == 1)ROOM[2] = ROOM_4A;
			}
			else
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"4B DETECT");lcd_putstr(lcd);
				ROOM4B_FLAG = ROOM4BFLAG_ACTIVE;

				if(CAT_FLAG_C==CAT_DETECTED)
				{
					SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
				}
				else
				{
					SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
				}

				if(Ping[PING_RIGHT]> 17)
				{
					Dynamx_Slide_Right_Interpolate(HEXSTEP_CLOSE,LEVEL3);
				}
				if(Ping[PING_RIGHT]> 17)
				{
					Dynamx_Slide_Right_Interpolate(HEXSTEP_CLOSE,LEVEL3);
				}

				BW_PID_Init();
				CAT_DETECTOR = CAT_ACTIVATED;

				BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);
				if(CAT_FLAG == CAT_NOT_DETECTED)
				{
					Cat_Avoider();
				}

				if(CAT_FLAG==CAT_DETECTED)
				{
					SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

					CAT_DETECTOR=CAT_DIACTIVATED;
					CAT_FLAG=CAT_NOT_DETECTED;
					CAT_FLAG_A=CAT_DETECTED;
					REVERSE_FLAG=REVERSEFLAG_ACTIVE;

					R4ATO1_SP_ROUTE=SP_ROUTE_ACTIVE;

					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"ALTERNATE");lcd_putstr(lcd);
					lcd_gotoxy(8,1);sprintf(lcd,"ROUTE");lcd_putstr(lcd);
					delay_ms(100);

					Dynamx_MovBwd_Interpolate(4,LEVEL5,IKCALC_ENABLE);

					Nav_TurnAround(TURN_LEFT);

					BW_PID_Init();
					BW_FollowTracer_Right_Interpolate();
					if(ROOM_4B_MANUAL == 1)ROOM[2] = ROOM_4B;
				}

				else
				{
					SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

					BW_PID_Init();
					BW_FollowTracer_Left_Interpolate();
					if(ROOM_4B_MANUAL == 1)ROOM[2] = ROOM_4B;
				}
		}

		}

	}

	}

	ROOM4AB_FLAG=ROOM4AB_ACTIVE;

}


/* func      : void Nav_1C_To_HallwaySC(void)
 * brief     : Navigate from Room 1C to HallwaySC
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Sunday, April 10th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_1C_To_HallwaySC(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1C TO SC");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);
//	mov_rot_right(FAST_LEVEL_3,CLOSE);

	BW_Buzz(2);
	while(Ping[PING_FRONT]<=25)
	{
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
//		mov_rot_right(FAST_LEVEL_3,CLOSE);
	}

	BW_Buzz(2);
	while(Ping[PING_LEFT]>=30)
	{
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);
	}

	BW_Buzz(2);
	BW_PID_Init();
	while( (Ping[PING_ASKEW_LEFT]<=100) || (Ping[PING_ASKEW_RIGHT]<=100))
//	while( (SHARP[SHARP_LEFT]<=100) || (SHARP[SHARP_RIGHT]<=100))
//	while (SHARP[SHARP_LEFT]<=100)
	{
		BW_FollowCounter_Left(1);
	}

	//CROSSING CROSSROAD
	BW_Buzz(2);
	while(Ping[PING_LEFT]>=30)
	{
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);
	}

	BW_Buzz(2);
	BW_PID_Init();
//	FollowHome_Left();
}

void Nav_1_To_3_V2(void)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1 TO R3");lcd_putstr(lcd);
	delay_ms(100);

	if(Ping[PING_FRONT]> 15)
	{
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);
		if(Ping[PING_FRONT]> 15)
		{
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);
		}
	}

	BW_PID_Init();
	BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

	BW_PID_Init();
	BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,NORMAL);

	BW_PID_Init();
	BW_FollowTracer_Left_Interpolate();

	FLAG_ROOM_3 = FLAG_ROOM_ACTIVE;

	if(TCS3200_SLV_BUF[0] == TRACER_WHITE)
	{
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);
	}
}



/* func      : void Nav_1C_To_2(void)
 * brief     : Navigate from Room 1C to Room 2
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Thursday, March 29th 2016)
 * Revised BY: ver2 : Hafidin (Wed, Feb 23th 2017)
 * programmer's Note:
 */
void Nav_1C_To_2(void)
{
	BW_Buzz(1);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1C TO R2");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;


	if(Ping[PING_LEFT]>10)
	{
		Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
	}
	if(Ping[PING_LEFT]>10)
	{
		Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
	}

	BW_PID_Init();
	BW_FollowTracer_Left_Interpolate();
}

/* func      : void Nav_1B_To_2(void)
 * brief     : Navigate from Room 1B to Room 2
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (Wed, Feb 23th 2017)
 * Revised BY: N/A
 * programmer's Note:
 */

void Nav_1B_To_2(void)
{
	BW_Buzz(1);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1B TO R2");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	if(Ping[PING_LEFT] > 10 || Ping[PING_ASKEW_LEFT] > 10)
	{
		Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
	}

	if(Ping[PING_LEFT] > 10 || Ping[PING_ASKEW_LEFT] > 10)
	{
		Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
	}

	Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
	Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_MED,IKCALC_DISABLE);
	Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_CLOSE,IKCALC_DISABLE);

	BW_Buzz(1);
	BW_PID_Init();
	BW_FollowTracer_Left_Interpolate();
}

/* func      : void Nav_1C_To_3(void)
 * brief     : Navigate from Room 1C to Room 3
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Thursday, March 29th 2016)
 * Revised BY: Ver2 : Hafidin (Wed, Feb 23th 2017)
 * programmer's Note:
 */
void Nav_1C_To_3(void)
{
	int p;

	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1C TO R3");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

		Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);

//============================== edited for 1BC
		if(Ping[PING_FRONT] > 30)
		{
			if(Ping[PING_LEFT] < 25 || Ping[PING_ASKEW_LEFT] < 25)
			{
				Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);
			}

			if(Ping[PING_LEFT] < 25 || Ping[PING_ASKEW_LEFT] < 25)
			{
				Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);
			}

			if(Ping[PING_LEFT] < 25 || Ping[PING_ASKEW_LEFT] < 25)
			{
				Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);
			}

			Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_MED,IKCALC_DISABLE);
		}
		else
		{
			if(Ping[PING_FRONT] > 15)
			{
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
			}
			if(Ping[PING_FRONT] > 15)
			{
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
			}

			Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_MED,IKCALC_DISABLE);
		}
//=================================
			if(ROOM_2_1BC_MANUAL == 0)
			{
/*				GetCMPS11_Angle8Bit();
				if(CMPS11_Angle>R1BC_THRESHOLD_MIDDLE && CMPS11_Angle<=R4AB_THRESHOLD_LOWER)
				{
					lcd_display_clear();
					while(CMPS11_Angle>R1BC_THRESHOLD_MIDDLE && CMPS11_Angle<=R4AB_THRESHOLD_LOWER)
					{
					lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
					lcd_gotoxy(4,1);sprintf(lcd,"ROTATE CORRECTION ");lcd_putstr(lcd);
					Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					GetCMPS11_Angle8Bit();
					delay_ms(50);
					}
				}

				if(CMPS11_Angle<R1BC_THRESHOLD_MIDDLE && CMPS11_Angle>=R4AB_THRESHOLD_UPPER)
				{
					lcd_display_clear();
					while(CMPS11_Angle<R1BC_THRESHOLD_MIDDLE && CMPS11_Angle>=R4AB_THRESHOLD_UPPER)
					{
					lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
					lcd_gotoxy(4,1);sprintf(lcd,"ROTATE CORRECTION ");lcd_putstr(lcd);
					Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					GetCMPS11_Angle8Bit();
					delay_ms(50);
					}
				}*/
//					BW_COMPASS_CORRECTION(ROOM_2_1BC_CORRECTION);
//					BW_COMPASS_CORRECTION(ROOM_2_1BC_CORRECTION);
			}

			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
			lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
			lcd_gotoxy(2,3);sprintf(lcd,"R1C TO R3");lcd_putstr(lcd);
			delay_ms(100);

			if(Ping[PING_ASKEW_RIGHT] <= 9 || Ping[PING_UP_RIGHT] <= 9)
			{
				Dynamx_Rot_Left_Interpolate(LEVEL3, HEXSTEP_MED, IKCALC_DISABLE);
				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
			}

			BW_PID_Init();
			int l;
			for(l = 0;l <= 2;l++)
			{
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1] == COLOUR_GRAY)break;
				if(((Ping[PING_ASKEW_LEFT] < 11 || Ping[PING_LEFT] < 11)))
				{
					BW_FollowCounter_Left(1);

				}
				else if(Ping[PING_ASKEW_RIGHT] < 11 || Ping[PING_RIGHT] < 11)
				{
					BW_FollowCounter_Right(1);
				}
/*				else if(SHARP[SHARP_FRONT_L] < 10 || SHARP[SHARP_FRONT_R] < 10 || TCS3200_SLV_DATA[1] == COLOUR_WHITE)
				{
					Dynamx_MovBwd_Interpolate(6, LEVEL5, IKCALC_DISABLE);
					Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
					TCS3200_Transmit(UART5,CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == TRACER_WHITE)
					{
						Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
						Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
					}
		//			BW_COMPASS_CORRECTION(ROOM_2_1BC_CORRECTION);
		//			Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
					if(SHARP[SHARP_BUMPER_LEFT] < 10)
					{
						Dynamx_Slide_Right_Interpolate(HEXSTEP_CLOSE, LEVEL3);
					}
					else if(SHARP[SHARP_BUMPER_RIGHT] < 10)
					{
						Dynamx_Slide_Left_Interpolate(HEXSTEP_CLOSE, LEVEL3);
					}
					l = 0;
				}*/
				else Dynamx_MovFwd4cm_Interpolate(4,LEVEL6, IKCALC_ENABLE);
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1] == COLOUR_GRAY)break;
			}

			if(Ping[PING_ASKEW_RIGHT] <= 14)
			{
				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
			}

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowTracer_Left_Interpolate();

			if(Ping[PING_LEFT] < 12)
			{
				Dynamx_Slide_Right_Interpolate(HEXSTEP_CLOSE,LEVEL5);
			}

}

/* func      : void Nav_1C_To_4A(void)
 * brief     : Navigate from Room 1C to Room 4A
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Thursday, March 29th 2016)
 * Revised BY: Ver2 : Hafidin (Wed, Feb 23th 2017)
 * programmer's Note:
 */
void Nav_1C_To_4A(void)
{
	int g;

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1C TO R4A");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);
	if(Ping[PING_LEFT] < 25 || Ping[PING_ASKEW_LEFT] < 25)
	{
		Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);
	}

	if(Ping[PING_LEFT] < 25 || Ping[PING_ASKEW_LEFT] < 25)
	{
		Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);
	}

	if(Ping[PING_LEFT] < 25 || Ping[PING_ASKEW_LEFT] < 25)
	{
		Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);
	}

	Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
	Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_MED,IKCALC_DISABLE);
	Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_CLOSE,IKCALC_DISABLE);

	if(Ping[PING_ASKEW_RIGHT] <= 9 || Ping[PING_UP_RIGHT] <= 9)
	{
		Dynamx_Rot_Left_Interpolate(LEVEL3, HEXSTEP_MED, IKCALC_DISABLE);
		Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
	}

//	GetCMPS11_Angle8Bit();
//
//	if(ROOM_2_1BC_MANUAL == 0)
//	{
//
//	}

	BW_PID_Init();
	int l;
	for(l = 0;l <= 2;l++)
	{
		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1] == COLOUR_GRAY)break;
				if(((Ping[PING_ASKEW_LEFT] < 11 || Ping[PING_LEFT] < 11)))
		{
			BW_FollowCounter_Left(1);

		}
		else if(Ping[PING_ASKEW_RIGHT] < 11 || Ping[PING_RIGHT] < 11)
		{
			BW_FollowCounter_Right(1);
		}

		else Dynamx_MovFwd4cm_Interpolate(4,LEVEL6, IKCALC_ENABLE);
		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1] == COLOUR_GRAY)break;
	}

	if(FOUR_WAY_MANUAL == 0)
	{

	}

	BW_PID_Init();
	BWFollowCarpet_Left_Interpolate(COLOUR_GRAY, INVERSE);

	if(Ping[PING_LEFT] < 14 || Ping[PING_REAR_LEFT] < 14)
	{
		Dynamx_Slide_Right_Interpolate(HEXSTEP_CLOSE, LEVEL3);
	}

	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)
	{
		Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
	}
	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)
	{
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);
	}

	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)
	{
		Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
	}

	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)
	{
		Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
	}

	if(FOUR_WAY_MANUAL == 0)
	{

	}

	else
	{
/*		Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);
		Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_MED, IKCALC_DISABLE);
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL3,IKCALC_DISABLE);*/
	}

	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)
	{
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);
	}

	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)
	{
		Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
	}

	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)
	{
		Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
	}


//	Dynamx_Rot_Right_Interpolate(LEVEL3, HEXSTEP_CLOSE, IKCALC_DISABLE);
//	Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);


	if(EXTINGUISHED_FIRE==0)
	{
/*		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);*/

		Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
		Dynamx_Rot_Right_Interpolate(LEVEL3, HEXSTEP_MED, IKCALC_DISABLE);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

		BW_PID_Init();
		BW_FollowCounter_Right(2);

		if(Ping[PING_RIGHT]<10)
		{
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
		}

		if(/*(Ping[PING_ASKEW_LEFT]>30) && */(Ping[PING_LEFT]>=30))
		{
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
			Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
			/*Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);*/
			Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_MED,IKCALC_DISABLE);


			for(g=0;g<=2;g++)
			{
				Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);
				FOLLOWMODE_FLAG=FOLLOW_TRACER_WHITE;
				TRACER_STAT=TRACER_BLACK;

				TCSlave_Check();
				if(TRACER_STAT==TRACER_WHITE)break;
				if((Ping[PING_ASKEW_LEFT]<15) || (Ping[PING_ASKEW_RIGHT]<15))break;
			}

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowTracer_Left_Interpolate();

			Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);

			if(ROOM_4A_MANUAL == 1)ROOM[2] = ROOM_4B;
		}
		else
		{
				Nav_TurnAround(TURN_LEFT);

				Cat_Avoider();
				CAT_FLAG=CAT_NOT_DETECTED;

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

				ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;

				BW_Buzz(1);
				BW_PID_Init();
				BW_FollowCounter_Right(9);

				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

				BW_Buzz(1);
				if (EXTINGUISHED_FIRE==1){BW_PID_Init();}
				else {BW_PID_Init_FAR();}
				BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

				if(CAT_FLAG==CAT_DETECTED)
				{
					SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

					//Activate special route
					R4ATO3_SP_ROUTE=R4ATO3_SP_ACTIVE;
					R4ATO2_SP_ROUTE=SP_ROUTE_ACTIVE;

					Dynamx_MovBwd_Interpolate(12,LEVEL5,IKCALC_ENABLE);


					Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
					Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);

					while(Ping[PING_RIGHT]>25)
					{
						Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
					}

					Dynamx_MovFwd4cm_Interpolate(15,LEVEL3,IKCALC_ENABLE);

//					Start of changes
					BW_Buzz(1);
					BW_PID_Init();
					BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,NORMAL);
//
					BW_Buzz(1);
					BW_PID_Init();
					BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,NORMAL);
//
					BW_Buzz(1);
					BW_PID_Init();
					BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,NORMAL);

					BW_Buzz(1);
					BW_PID_Init();
					BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,NORMAL);

					Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);

					BW_Buzz(1);
					BW_PID_Init();
					BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

					if(Ping[PING_RIGHT]<=15)
					{
						Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
					}

					if((Ping[PING_LEFT]>=20) && (Ping[PING_ASKEW_LEFT]>=20))
					{
						Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_MED,IKCALC_DISABLE);
					}
					else
					{
						Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
						Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);
					}

					BW_Buzz(1);
					BW_PID_Init();
					BW_FollowTracer_Left_Interpolate();

					if(ROOM_4A_MANUAL == 1)ROOM[2] = ROOM_4A;
					//end of changes
				}
				else
				{
					SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

					Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
					Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);

					Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);

					BW_Buzz(1);
					BW_PID_Init();
					BW_FollowTracer_Right_Interpolate();

					if(ROOM_4A_MANUAL == 1)ROOM[2] = ROOM_4A;
				}
		}
	}
	else
	{
		if(R2TO4A_SP_ROUTE==R2TO4A_SP_ACTIVE)
		{
			ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_INACTIVE;
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

			Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
			Dynamx_Rot_Right_Interpolate(LEVEL3, HEXSTEP_MED, IKCALC_DISABLE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

//			Dynamx_MovFwd4cm(12,HEXSPD_MEDFAST,IKCALC_DISABLE);
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

			Dynamx_Rot_Left_Interpolate(LEVEL3, HEXSTEP_CLOSE, IKCALC_DISABLE);
			Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
			Dynamx_Rot_Left_Interpolate(LEVEL3, HEXSTEP_CLOSE, IKCALC_DISABLE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

			Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
			Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

			if(Ping[PING_RIGHT]<=15)
			{
				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
			}

				Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_MED,IKCALC_DISABLE);

				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowTracer_Left_Interpolate();

			if(ROOM_4A_MANUAL == 1)ROOM[2] = ROOM_4A;
		}
		else
		{
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

			Dynamx_MovBwd_Interpolate(12,LEVEL6,IKCALC_DISABLE);

			Nav_TurnAround(TURN_RIGHT);

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowCounter_Left(12);

			if(CAT_FLAG_A == CAT_NOT_DETECTED && CAT_FLAG_B == CAT_NOT_DETECTED && CAT_FLAG_C == CAT_NOT_DETECTED )
			{
				ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_INACTIVE;
				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
			}
			else
			{
				ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;
				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
			}

			Cat_Avoider();
			CAT_FLAG=CAT_NOT_DETECTED;

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

			if(CAT_FLAG==CAT_DETECTED)
			{
				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

				Dynamx_MovBwd_Interpolate(12,LEVEL5,IKCALC_ENABLE);


				while(Ping[PING_RIGHT]>25)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
				}

				Dynamx_MovFwd4cm_Interpolate(20,LEVEL5,IKCALC_ENABLE);

				BW_Buzz(1);
				BW_PID_Init();
				if(Ping[PING_REAR] > 12)
				{
					Dynamx_MovBwd_Interpolate(4,LEVEL5,IKCALC_ENABLE);
				}

				if(Ping[PING_REAR] > 12)
				{
					Dynamx_MovBwd_Interpolate(4,LEVEL5,IKCALC_ENABLE);
				}

				Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
				while(Ping[PING_FRONT] < 16)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
				}

				while(Ping[PING_FRONT] > 16)
				{
					BW_FollowCounter_Right(1);
				}

				while(Ping[PING_FRONT] < 20)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
				}

				int h;
				for(h = 0;h <=5;h++)
				{
					if(Ping[PING_REAR_LEFT] < 17)break;
					BW_FollowCounter_Right(1);
				}

				if(Ping[PING_LEFT] > 17)
				{
					Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
				}

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

				Dynamx_MovFwd4cm_Interpolate(4,LEVEL3,IKCALC_ENABLE);

				if(/*Ping[PING_ASKEW_LEFT] >= 30 || */Ping[PING_LEFT] >= 30)
				{
					if(ROOM_4A_MANUAL == 1)ROOM[2] = ROOM_4B;
				}
				else if(ROOM_4A_MANUAL == 1)
				{
					ROOM[2] = ROOM_4A;
				}

				BW_FollowTracer_Left_Interpolate();

			}
			else
			{
				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

				Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);

				Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);

				BW_Buzz(1);
				BW_PID_Init();
				BW_FollowTracer_Right_Interpolate();
				if(ROOM_4A_MANUAL == 1)ROOM[2] = ROOM_4A;
			}
		}

	}

	/*
	 * 	ACTIVATE ROOM4AB_FLAG
	 */
	ROOM4AB_FLAG=ROOM4AB_ACTIVE;
}

void Nav_1_To_4(void)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1 TO R4");lcd_putstr(lcd);
	delay_ms(100);

	BW_PID_Init();
	BW_FollowCounter_Right(7);

	BW_PID_Init();
	BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,NORMAL);

	BW_PID_Init();
	BW_FollowCounter_Right(1);


	if(Ping[PING_LEFT]>20)
	{
		Dynamx_Slide_Left_Interpolate(HEXSPD_MED,LEVEL4);
		Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_FAR2,IKCALC_DISABLE);
	}

	BW_PID_Init();
	BW_FollowTracer_Left_Interpolate();

	if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)
	{
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
	}

	if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)
	{
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
	}

	FLAG_ROOM_4B = FLAG_ROOM_ACTIVE;
}


void Nav_1C_To_4B(void)
{
	int g;

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R1C TO R4B");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	if(Ping[PING_LEFT] < 25 || Ping[PING_ASKEW_LEFT] < 25)
	{
		Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);
	}

	if(Ping[PING_LEFT] < 25 || Ping[PING_ASKEW_LEFT] < 25)
	{
		Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);
	}

	Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR2,IKCALC_DISABLE);


	if(Ping[PING_ASKEW_RIGHT] <= 9 || Ping[PING_UP_RIGHT] <= 9)
	{
		Dynamx_Rot_Left_Interpolate(LEVEL3, HEXSTEP_MED, IKCALC_DISABLE);
		Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
	}

	BW_PID_Init();
	int l;
	for(l = 0;l <= 2;l++)
	{
		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1] == COLOUR_GRAY)break;
				if(((Ping[PING_ASKEW_LEFT] < 11 || Ping[PING_LEFT] < 11)))
		{
			BW_FollowCounter_Left(1);

		}
		else if(Ping[PING_ASKEW_RIGHT] < 11 || Ping[PING_RIGHT] < 11)
		{
			BW_FollowCounter_Right(1);
		}

		else Dynamx_MovFwd4cm_Interpolate(4,LEVEL6, IKCALC_ENABLE);
		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1] == COLOUR_GRAY)break;
	}
	Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);


	Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
	Dynamx_Rot_Right_Interpolate(LEVEL3, HEXSTEP_MED, IKCALC_DISABLE);

	BW_PID_Init();
	BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

	Dynamx_MovFwd4cm_Interpolate(8,LEVEL5,IKCALC_ENABLE);

	Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);

	Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
	Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);

	for(g=0;g<=3;g++)
	{
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL3,IKCALC_ENABLE);
		FOLLOWMODE_FLAG=FOLLOW_TRACER_WHITE;
		TRACER_STAT=TRACER_BLACK;

		TCSlave_Check();
		if(TRACER_STAT==TRACER_WHITE)break;
		if((Ping[PING_ASKEW_LEFT]<15) || (Ping[PING_ASKEW_RIGHT]<15))break;
	}

	BW_PID_Init();
	BW_FollowTracer_Left_Interpolate();

	Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_CLOSE,IKCALC_DISABLE);

	ROOM4AB_FLAG=ROOM4AB_ACTIVE;
}

/* func      : void Nav_4A_To_HallwaySC(void)
 * brief     : Navigate from Room 4A to Hallway SC
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Monday, April 10th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_4A_To_HallwaySC(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R4A TO SC");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);
//	mov_rot_left(FAST_LEVEL_3,CLOSE);


	while(Ping[PING_FRONT]<=25)
	{
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
//		mov_rot_left(FAST_LEVEL_3,CLOSE);
	}

	if(CAT_FLAG==CAT_DETECTED)
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
		BW_Buzz(2);
		BW_PID_Init();
		BW_FollowCounter_Left(15);

		BW_Buzz(2);
		BW_PID_Init();

		BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

		BW_Buzz(2);
		BW_PID_Init();
		BW_FollowCounter_Left(15);

		BW_Buzz(2);
//		mov_deflect_right(FAST,CLOSE);
//		mov_deflect_right(FAST,CLOSE);
//		mov_deflect_right(FAST,CLOSE);

		BW_PID_Init();
		BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

		BW_PID_Init();
		BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

		BW_PID_Init();
		BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

		BW_PID_Init();
		BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

		BW_Buzz(2);
		BW_PID_Init();
		BW_FollowCounter_Right(25);

//		BW_Buzz(2);
//		mov_deflect_left(FAST,CLOSE);
//		mov_deflect_left(FAST,CLOSE);
//		mov_deflect_left(FAST,CLOSE);

		BW_Buzz(2);
		BW_PID_Init();
//		FollowHome_Left();
	}

}

/* func      : void Nav_4A_To_3(void)
 * brief     : Navigate from Room 4A to Room 3
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Thursday, March 29th 2016)
 * Revised BY: Ver2 : Hafidin (Friday, Feb 24th 2017)
 * 			   Ver3 : Toni (Tuesday, Nov 2th 2017)
 * programmer's Note:
 */
void Nav_4A_To_3(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R4A TO R3");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	TCS3200_Transmit(UART5,CMD_GET_TRACER);
	if(TCS3200_SLV_DATA[1]==COLOUR_GRAY && Ping[RIGHT] > 25)
	{
		Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
		Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
	}

	if(R4ATO3_SP_ROUTE==R4ATO3_SP_ACTIVE)
	{
		R4ATO3_SP_ROUTE=R4ATO3_SP_INACTIVE;
		R4ATO1_SP_ROUTE=SP_ROUTE_ACTIVE;
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(Ping[PING_FRONT]>17 && TCS3200_SLV_DATA[1] != COLOUR_GRAY)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
		}

		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(Ping[PING_FRONT]>17 && TCS3200_SLV_DATA[1] != COLOUR_GRAY)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
		}

		Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_CLOSE,IKCALC_DISABLE);

		BW_PID_Init();
		while(Ping[PING_FRONT] < 17)
		{
			BW_FollowCounter_Left(1);
		}

		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"COUNTER");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"ON");lcd_putstr(lcd);

		BW_PID_Init();
		BW_FollowCounter_Left(4);

		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"FOLLOW CARPET");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"HITAM1");lcd_putstr(lcd);

		BW_PID_Init();
		BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);


		Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);


		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"FOLLOW CARPET");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"ABU 1");lcd_putstr(lcd);

//		Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
		Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_MED,IKCALC_DISABLE);
		if(Ping[PING_RIGHT] > 16)
		{
			Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL5);
		}

//		Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

//		BW_PID_Init();
//		BW_FollowCounter_Right(1);

		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"FOLLOW CARPET");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"HITAM 2");lcd_putstr(lcd);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

//		if(Ping[PING_LEFT] > 17 || Ping[PING_ASKEW_LEFT] > 16)Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);

		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"FOLLOW CARPET");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"ABU 2");lcd_putstr(lcd);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"JUNCTION");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"ARRIVED");lcd_putstr(lcd);

		Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_MED,IKCALC_DISABLE);

		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"FOLLOW CARPET");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"HITAM 3");lcd_putstr(lcd);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

		if(FOUR_WAY_MANUAL == 0)
		{
/*		if(CMPS11_Angle < R4B_THRESHOLD_MIDDLE && CMPS11_Angle > R4AB_THRESHOLD_UPPER)
		{
			while(CMPS11_Angle < R4B_THRESHOLD_MIDDLE && CMPS11_Angle > R4AB_THRESHOLD_UPPER)
			{
				GetCMPS11_Angle8Bit();
				Dynamx_Rot_Left_Interpolate(LEVEL3, HEXSTEP_MED, IKCALC_DISABLE);
			}
		}

		else if(CMPS11_Angle > R4B_THRESHOLD_MIDDLE && CMPS11_Angle < R4AB_THRESHOLD_LOWER)
		{
			while(CMPS11_Angle > R4B_THRESHOLD_MIDDLE && CMPS11_Angle < R4AB_THRESHOLD_LOWER)
			{
				GetCMPS11_Angle8Bit();
				Dynamx_Rot_Right_Interpolate(LEVEL3, HEXSTEP_MED, IKCALC_DISABLE);
			}
		}*/
//			BW_COMPASS_CORRECTION(FOUR_WAY_INV);
		}

		if(Ping[PING_RIGHT] > 15 || Ping[PING_ASKEW_RIGHT] > 16)Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);

		Nav_TurnAround(TURN_RIGHT);

		BW_Buzz(1);
		BW_PID_Init();
		BW_FollowTracer_Left_Interpolate();
	}

//	DEFAULT ROUTE
	else if(R4ATO3_SP_ROUTE==R4ATO3_SP_INACTIVE)
	{
		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(Ping[PING_FRONT]>17 && TCS3200_SLV_DATA[1] != COLOUR_GRAY)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
		}

//		TCS3200_Transmit(UART5, CMD_GET_TRACER);
//		if(Ping[PING_FRONT]>17 && TCS3200_SLV_DATA[1] != COLOUR_GRAY)
//		{
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
//		}


		if(CAT_FLAG_A == CAT_NOT_DETECTED && CAT_FLAG_B == CAT_NOT_DETECTED && CAT_FLAG_C == CAT_NOT_DETECTED)
		{
			ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;
		}

//		Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);

		Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
//		Dynamx_Rot_Left_Interpolate(LEVEL4, HEXSTEP_CLOSE, IKCALC_DISABLE);

		while(Ping[PING_FRONT]<25)
		{
			Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_CLOSE,IKCALC_DISABLE);
		}

		if(CAT_FLAG_B == CAT_NOT_DETECTED && CAT_FLAG_C == CAT_NOT_DETECTED)
		{
			if(Ping[PING_REAR_RIGHT] > (Ping[PING_ASKEW_RIGHT]))
			{
				Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
//				if(Ping[PING_REAR_RIGHT] > (Ping[PING_ASKEW_RIGHT]))
//				{
//						Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
//				}
			}
//			else
//			{
//				Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
////				if((Ping[PING_REAR_RIGHT]) > (Ping[PING_ASKEW_RIGHT]))
////				{
////					Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
////				}
//			}

			if(Ping[PING_REAR_RIGHT] > Ping[PING_ASKEW_RIGHT])
			{
				Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
//				if(Ping[PING_REAR_RIGHT] > (Ping[PING_ASKEW_RIGHT]))
//				{
//						Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
//				}
			}

			if((Ping[PING_REAR_RIGHT]+6) < (Ping[PING_ASKEW_RIGHT]))
			{
				Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
			}
//			if(Ping[PING_REAR_RIGHT] < Ping[PING_ASKEW_RIGHT])
//			{
//				Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
//			}
//			else
//			{
//				Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
//				if((Ping[PING_REAR_RIGHT]+6) < (Ping[PING_ASKEW_RIGHT]))
//				{
//					Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
//				}
//			}

		}


		if(CAT_FLAG_A==CAT_NOT_DETECTED && CAT_FLAG_B==CAT_NOT_DETECTED && CAT_FLAG_C==CAT_NOT_DETECTED && ROOM_4A_MANUAL == 0)
		{
/*			GetCMPS11_Angle8Bit();
			if(CMPS11_Angle<R4AB_THRESHOLD_UPPER || CMPS11_Angle>R4AB_THRESHOLD_LOWER)
			{
				while(CMPS11_Angle<(R4AB_THRESHOLD_UPPER-7) || CMPS11_Angle>R4AB_THRESHOLD_LOWER)
				{
		//		lcd_display_clear();
		//		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		//		lcd_gotoxy(4,1);sprintf(lcd,"ROTATE CORRECTION ");lcd_putstr(lcd);
				Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				delay_ms(50);
				GetCMPS11_Angle8Bit();
				}
			}*/
/*			BW_COMPASS_CORRECTION(ROOM_4B_TURN_CORRECTION);
			BW_COMPASS_CORRECTION(ROOM_4B_TURN_CORRECTION);*/
		}

		if(Ping[PING_RIGHT] > 14)
		{
			Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
		}
		else if(Ping[PING_RIGHT] <= 14 || Ping[PING_ASKEW_RIGHT] <= 14)
		{
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL5);
		}

		if(CAT_FLAG_A == CAT_NOT_DETECTED && CAT_FLAG_B == CAT_NOT_DETECTED && CAT_FLAG_C == CAT_NOT_DETECTED)
		{
			CAT_DETECTOR = CAT_ACTIVATED;
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
		}

		if(CAT_FLAG == CAT_NOT_DETECTED && SHIFT_ALGORITHM_FLAG == SHIFT_ALGORITHM_ACTIVE)
		{
			BW_PID_Init_FAR();
			Dynamx_MovFwd4cm_Interpolate(4, LEVEL3, IKCALC_ENABLE);
			Cat_Avoider();
			if(CAT_FLAG == CAT_DETECTED)
			{
				SHIFT_ALGORITHM_FLAG = SHIFT_ALGORITHM_INACTIVE;
			}
			if(CAT_FLAG == CAT_NOT_DETECTED)
			{
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL3, IKCALC_ENABLE);
				Cat_Avoider();
				if(CAT_FLAG == CAT_DETECTED)
				{
					SHIFT_ALGORITHM_FLAG = SHIFT_ALGORITHM_INACTIVE;
				}
			}
		}

		if(CAT_FLAG == CAT_NOT_DETECTED)
		{
			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);
		}

		if (CAT_FLAG==CAT_DETECTED)
		{
			CAT_DETECTOR=CAT_DIACTIVATED;
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

			Dynamx_MovBwd_Interpolate(6, LEVEL5, IKCALC_DISABLE);
//			Dynamx_Rot_Right_Interpolate(LEVEL3, HEXSTEP_FAR, IKCALC_DISABLE);
//			Dynamx_Rot_Right_Interpolate(LEVEL3, HEXSTEP_FAR, IKCALC_DISABLE);

			Nav_TurnAround(TURN_RIGHT);

/*			while(Ping[PING_FRONT]<20)
			{
				Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
			}

			while(Ping[PING_FRONT]<20)
			{
				Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
			}*/

			//NEXT ROOM = ROOM3
			if( (ROOM[1]==ROOM_1A) || (ROOM[1]==ROOM_2B) || (ROOM[1]==ROOM_2A) || (ROOM[1]==ROOM_1B) || (ROOM[1]==ROOM_1C))
			{

				BW_Buzz(1);
				lcd_display_clear();
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"SPECIAL");lcd_putstr(lcd);
				lcd_gotoxy(8,2);sprintf(lcd,"ROUTE");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"R4A TO R3");lcd_putstr(lcd);
				delay_ms(100);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

				BW_Buzz(1);
				BW_PID_Init();
				while(Ping[PING_FRONT] > 17)
				{
					BW_FollowCounter_Left(1);
				}

				BW_Buzz(1);
				BW_PID_Init();
				while(Ping[PING_REAR_RIGHT] > 20 || Ping[PING_RIGHT] > 20)
				{
					BW_FollowCounter_Left(1);
				}

//				Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

//				Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
				Dynamx_Rot_Right_Interpolate(LEVEL3, HEXSTEP_MED, IKCALC_DISABLE);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);
//				BW_FollowCounter_Right(1);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

				Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_MED,IKCALC_ENABLE);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

				Dynamx_Rot_Right_Interpolate(LEVEL3, HEXSTEP_MED, IKCALC_DISABLE);

				Nav_TurnAround(TURN_RIGHT);

				BW_Buzz(1);
				BW_PID_Init();
				BW_FollowTracer_Left_Interpolate();
			}
			else
			{
				BW_Buzz(1);
				lcd_display_clear();
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"ALTERNATE");lcd_putstr(lcd);
				lcd_gotoxy(8,2);sprintf(lcd,"ROUTE");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"R4A TO R1A");lcd_putstr(lcd);
				delay_ms(100);

				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
				ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_INACTIVE;

				BW_Buzz(1);
				BW_PID_Init();
				BW_FollowTracer_Left_Interpolate();

				ROOM4A_FLAG=ROOM4AFLAG_ACTIVE;
				ROOM1A_SP_EXIT_FLAG=ROOM1A_SP_EXIT_FLAG_ACTIVE;

				//ACTIVATING SPECIAL ROUTE
				R2TO4A_SP_ROUTE=R2TO4A_SP_ACTIVE;

				FIREROOM_R1A_FLAG=FIREROOM_R1A_ACTIVE;

			}
		}

		else
		{
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
			ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_INACTIVE;

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowTracer_Right_Interpolate();

			REVERSE_FLAG=REVERSEFLAG_INACTIVE;
			ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_INACTIVE;
		}
	}

}


void Nav_4A_To_1BC(void)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R4A TO R1BC");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(Ping[PING_FRONT]>17 && TCS3200_SLV_DATA[1] != COLOUR_GRAY)
	{
		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
	}

	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(Ping[PING_FRONT]>17 && TCS3200_SLV_DATA[1] != COLOUR_GRAY)
	{
		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
	}

	Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
	Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_CLOSE,IKCALC_DISABLE);

	BW_PID_Init();
	while(Ping[PING_FRONT] < 17)
	{
		BW_FollowCounter_Left(1);
	}

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"COUNTER");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"ON");lcd_putstr(lcd);

	BW_PID_Init();
	BW_FollowCounter_Left(4);

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"FOLLOW CARPET");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"HITAM1");lcd_putstr(lcd);

	BW_PID_Init();
	BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);


	Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);


	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"FOLLOW CARPET");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"ABU 1");lcd_putstr(lcd);

//		Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
	Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_MED,IKCALC_DISABLE);
	if(Ping[PING_RIGHT] > 16)
	{
		Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL5);
	}

//		Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);

	BW_Buzz(1);
	BW_PID_Init();
	BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

//		BW_PID_Init();
//		BW_FollowCounter_Right(1);

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"FOLLOW CARPET");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"HITAM 2");lcd_putstr(lcd);

	BW_Buzz(1);
	BW_PID_Init();
	BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

//		if(Ping[PING_LEFT] > 17 || Ping[PING_ASKEW_LEFT] > 16)Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"FOLLOW CARPET");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"ABU 2");lcd_putstr(lcd);

	BW_Buzz(1);
	BW_PID_Init();
	BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"JUNCTION");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"ARRIVED");lcd_putstr(lcd);

	Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_MED,IKCALC_DISABLE);

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"FOLLOW CARPET");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"HITAM 3");lcd_putstr(lcd);

	BW_Buzz(1);
	BW_PID_Init();
	BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);


	if(Ping[PING_RIGHT] > 30 || Ping[PING_ASKEW_RIGHT] > 30)
	{
		BW_Buzz(1);
		BW_PID_Init();
		Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSPD_MED,IKCALC_DISABLE);
		BW_FollowTracer_Left_Interpolate();
		SP_FIRE_1B=SP_FIRE_ACTIVE;
	}
	else
	{
		BW_PID_Init();
		BW_FollowTracer_Left_Interpolate();
		SP_FIRE_1C=SP_FIRE_ACTIVE;
	}



}

void Nav_4A_To_1A(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R4A TO R1A");lcd_putstr(lcd);
	delay_ms(100);

	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	while(TCS3200_SLV_DATA[1]==COLOUR_GRAY)
	{
		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
	}

	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(Ping[PING_FRONT]>17 && TCS3200_SLV_DATA[1] != COLOUR_GRAY)
	{
		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
	}

	TCS3200_Transmit(UART5, CMD_GET_TRACER);
	if(Ping[PING_FRONT]>17 && TCS3200_SLV_DATA[1] != COLOUR_GRAY)
	{
		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
	}

	ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;

	Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);

	while(Ping[PING_FRONT] < 20)
	{
		Dynamx_Rot_Left_Interpolate(LEVEL3, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
	}

	if(CAT_FLAG_B == CAT_NOT_DETECTED && CAT_FLAG_C == CAT_NOT_DETECTED && CAT_FLAG_A == CAT_NOT_DETECTED)
	{
		if((Ping[PING_REAR_RIGHT]) > (Ping[PING_ASKEW_RIGHT]))
		{
			Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
		}
		if((Ping[PING_REAR_RIGHT]) > (Ping[PING_ASKEW_RIGHT]))
		{
			Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
		}
	}

	if(CAT_FLAG_B==CAT_DETECTED || CAT_FLAG_C == CAT_DETECTED)
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
	}
	else
	{
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
	}

	if(CAT_FLAG == CAT_NOT_DETECTED && SHIFT_ALGORITHM_FLAG == SHIFT_ALGORITHM_ACTIVE)
	{
		BW_PID_Init_FAR();
		Dynamx_MovFwd4cm_Interpolate(4, LEVEL3, IKCALC_ENABLE);
		Cat_Avoider();
		if(CAT_FLAG == CAT_DETECTED)
		{
			SHIFT_ALGORITHM_FLAG = SHIFT_ALGORITHM_INACTIVE;
		}
		if(CAT_FLAG == CAT_NOT_DETECTED)
		{
			Dynamx_MovFwd4cm_Interpolate(4, LEVEL3, IKCALC_ENABLE);
			Cat_Avoider();
			if(CAT_FLAG == CAT_DETECTED)
			{
				SHIFT_ALGORITHM_FLAG = SHIFT_ALGORITHM_INACTIVE;
			}
		}
	}
	if(SHIFT_ALGORITHM_FLAG == SHIFT_ALGORITHM_ACTIVE)
	{
		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"CAT DETECTOR");lcd_putstr(lcd);
		lcd_gotoxy(3,1);sprintf(lcd,"SEARCH");lcd_putstr(lcd);
		if(Ping[PING_RIGHT] >= 12)
		{
			Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL4);
		}
		BW_PID_Init();
		CAT_DETECTOR = CAT_ACTIVATED;
		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		while(TCS3200_SLV_DATA[1] != COLOUR_GRAY && CAT_FLAG == CAT_NOT_DETECTED)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1] == COLOUR_GRAY)break;
			Cat_Avoider();
			if(CAT_FLAG == CAT_DETECTED)break;
			BW_FollowCounter_Right(1);
		}
	}

	if(CAT_FLAG == CAT_NOT_DETECTED)
	{
		lcd_gotoxy(3,0);sprintf(lcd,"CAT DETECTOR");lcd_putstr(lcd);
		lcd_gotoxy(3,1);sprintf(lcd,"NO CAT");lcd_putstr(lcd);
		BW_Buzz(1);

		BW_PID_Init_FAR();
		BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

	}

	if(CAT_FLAG == CAT_NOT_DETECTED)
	{
		Cat_Avoider();
	}

	if (CAT_FLAG==CAT_DETECTED)
	{
		CAT_DETECTOR=CAT_DIACTIVATED;
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
		CAT_FLAG_A = CAT_DETECTED;

		Dynamx_MovBwd_Interpolate(4,LEVEL5,IKCALC_ENABLE);

		Nav_TurnAround(TURN_RIGHT);

		BW_PID_Init();
		BW_FollowTracer_Left_Interpolate();

		ROOM4A_FLAG=ROOM4AFLAG_ACTIVE;
		ROOM1A_SP_EXIT_FLAG=ROOM1A_SP_EXIT_FLAG_ACTIVE;

		//ACTIVATING SPECIAL ROUTE
		R2TO4A_SP_ROUTE=R2TO4A_SP_ACTIVE;
	}

	else
	{
		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"COUNTER 1");lcd_putstr(lcd);
		lcd_gotoxy(3,1);sprintf(lcd,"ON");lcd_putstr(lcd);
		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

		Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);

		CAT_FLAG=CAT_NOT_DETECTED;
		ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

		if(CAT_FLAG_B==CAT_DETECTED)
		{
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
		}
		else
		{
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
		}

		BW_PID_Init();
		BW_FollowCounter_Left(2);

		if(Ping[PING_LEFT] < 11)
		{
			Dynamx_Slide_Right_Interpolate(HEXSTEP_CLOSE, LEVEL4);
		}
		else if(Ping[PING_LEFT] > 17)
		{
			Dynamx_Slide_Left_Interpolate(HEXSTEP_CLOSE, LEVEL4);
		}

		lcd_display_clear();
		lcd_gotoxy(3,0);sprintf(lcd,"GO");lcd_putstr(lcd);
		lcd_gotoxy(3,1);sprintf(lcd,"R1A");lcd_putstr(lcd);

		BW_PID_Init_FAR();
		BWFollowCarpet_Left_Interpolate(COLOUR_GRAY, INVERSE);

		if (CAT_FLAG==CAT_DETECTED)
		{
			CAT_DETECTOR=CAT_DIACTIVATED;
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
			CAT_FLAG_C = CAT_DETECTED;

			Dynamx_MovBwd_Interpolate(4,LEVEL5,IKCALC_ENABLE);

			Nav_TurnAround(TURN_LEFT);

//			Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
			Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowTracer_Left_Interpolate();

		}
		else
		{
			CAT_FLAG_B=CAT_DETECTED;
			BW_PID_Init();
			BWFollowCarpet_Right_Interpolate(COLOUR_BLACK, INVERSE);
			Dynamx_Rot_Right_Interpolate(LEVEL3, HEXSTEP_CLOSE, IKCALC_DISABLE);
			BW_PID_Init();
			BW_FollowTracer_Right_Interpolate();
		}
	}
	FIREROOM_R1A_FLAG=FIREROOM_R1A_ACTIVE;
	ROOM4A_FLAG=ROOM4AFLAG_ACTIVE;
	ROOM1A_SP_EXIT_FLAG=ROOM1A_SP_EXIT_FLAG_ACTIVE;
}

/* func      : void Nav_4A_To_2(void)
 * brief     : Navigate from Room 4A to Room 2
 * param     : N/A
 * retval    : N/A
 * Ver       : 3
 * written By: Ryan (Thursday, March 29th 2016)
 * Revised BY: Ver2  : Hafidin (Friday, Feb 24th 2017)
 * 			   Ver 3.: Ryan (Friday, April 21th, 2017)
 * 			   			ADDED SPECIAL ROUTE WHEN CAT ALREADY SPOTTED IN EARLIER NAVIGATION
 * programmer's Note:
 */
void Nav_4A_To_2(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R4A TO R2");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	/*
	 * SPECIAL ROUTE WHEN CAT ALREADY SPOTTED IN EARLIER NAVIGATION
	 */

	TCS3200_Transmit(UART5,CMD_GET_TRACER);
	while(TCS3200_SLV_DATA[1]==COLOUR_GRAY)
	{
		TCS3200_Transmit(UART5,CMD_GET_TRACER);
		Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
	}

	if(R4ATO2_SP_ROUTE==SP_ROUTE_ACTIVE)
	{
		BW_Buzz(1);
		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(Ping[PING_FRONT]>17 && TCS3200_SLV_DATA[1] != COLOUR_GRAY)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
		}

		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(Ping[PING_FRONT]>17 && TCS3200_SLV_DATA[1] != COLOUR_GRAY)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
		}


		Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);

		while(Ping[PING_FRONT]<20)
		{
			Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
		}

		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(2,2);sprintf(lcd,"R4A TO R2");lcd_putstr(lcd);
		lcd_gotoxy(2,3);sprintf(lcd,"Step 1");lcd_putstr(lcd);
		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(2,2);sprintf(lcd,"R4A TO R2");lcd_putstr(lcd);
		lcd_gotoxy(2,3);sprintf(lcd,"Step 2");lcd_putstr(lcd);
		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(2,2);sprintf(lcd,"R4A TO R2");lcd_putstr(lcd);
		lcd_gotoxy(2,3);sprintf(lcd,"Step 3");lcd_putstr(lcd);
		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(2,2);sprintf(lcd,"R4A TO R2");lcd_putstr(lcd);
		lcd_gotoxy(2,3);sprintf(lcd,"Step 4");lcd_putstr(lcd);
		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(2,2);sprintf(lcd,"R4A TO R2");lcd_putstr(lcd);
		lcd_gotoxy(2,3);sprintf(lcd,"Step 5");lcd_putstr(lcd);
		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(2,2);sprintf(lcd,"R4A TO R2");lcd_putstr(lcd);
		lcd_gotoxy(2,3);sprintf(lcd,"Step 6");lcd_putstr(lcd);
		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);


		Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);


		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(2,2);sprintf(lcd,"R4A TO R2");lcd_putstr(lcd);
		lcd_gotoxy(2,3);sprintf(lcd,"Step 8");lcd_putstr(lcd);
		BW_Buzz(1);
		BW_PID_Init();
		BW_FollowTracer_Right_Interpolate();

	}

	else if((CAT_FLAG_B==CAT_DETECTED)||(CAT_FLAG_C==CAT_DETECTED))
	{
		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(Ping[PING_FRONT]>17 && TCS3200_SLV_DATA[1] != COLOUR_GRAY)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
		}

		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(Ping[PING_FRONT]>17 && TCS3200_SLV_DATA[1] != COLOUR_GRAY)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
		}


		Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
		Dynamx_Rot_Left_Interpolate(LEVEL4, HEXSTEP_CLOSE, IKCALC_DISABLE);

		while(Ping[PING_FRONT]<18)
		{
			Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
		}

		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

		Nav_TurnAround(TURN_LEFT);

		Dynamx_Rot_Right_Interpolate(LEVEL4, HEXSTEP_CLOSE, IKCALC_DISABLE);

		if(Ping[PING_RIGHT] >= 16)
		{
			Dynamx_Slide_Right_Interpolate(HEXSTEP_CLOSE, LEVEL4);
		}



		BW_Buzz(1);
		BW_PID_Init();
		BW_FollowTracer_Right_Interpolate();
	}
//	Default route (CHECKING CAT CONFIG A FIRST
	else
	{
		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(Ping[PING_FRONT]>17 && TCS3200_SLV_DATA[1] != COLOUR_GRAY)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
		}

		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(Ping[PING_FRONT]>17 && TCS3200_SLV_DATA[1] != COLOUR_GRAY)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
		}

		Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);

		while(Ping[PING_FRONT]<25)
		{
			Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
		}

		if(Ping[PING_REAR_RIGHT] > (Ping[PING_ASKEW_RIGHT]+6))
		{
			Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
			if(Ping[PING_REAR_RIGHT] > (Ping[PING_ASKEW_RIGHT]+6))
			{
					Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
			}
		}
		else
		{
			Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
			if((Ping[PING_REAR_RIGHT]+6) > (Ping[PING_ASKEW_RIGHT]))
			{
				Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
			}
		}

		if(Ping[PING_REAR_RIGHT] > (Ping[PING_ASKEW_RIGHT]+6))
		{
			Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
			if(Ping[PING_REAR_RIGHT] > (Ping[PING_ASKEW_RIGHT]+6))
			{
					Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
			}
		}
		else
		{
			Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
			if((Ping[PING_REAR_RIGHT]+6) < (Ping[PING_ASKEW_RIGHT]))
			{
				Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
			}
		}

		if(Ping[PING_REAR_RIGHT] > (Ping[PING_ASKEW_RIGHT]+6))
		{
			Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
			if(Ping[PING_REAR_RIGHT] > (Ping[PING_ASKEW_RIGHT]+6))
			{
					Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
			}
		}
		else
		{
			Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
			if((Ping[PING_REAR_RIGHT]+6) < (Ping[PING_ASKEW_RIGHT]))
			{
				Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
			}
		}


		if(Ping[PING_RIGHT] > 16)
		{
			Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
		}
		else if(Ping[PING_RIGHT] <= 10 || Ping[PING_ASKEW_RIGHT] <= 10)
		{
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
		}

		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;
		ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;

		BW_Buzz(1);
		BW_PID_Init();
		BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

		if(CAT_FLAG==CAT_NOT_DETECTED)
		{
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

			Nav_TurnAround(TURN_LEFT);

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowTracer_Right_Interpolate();
		}

		if(CAT_FLAG==CAT_DETECTED)
		{
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
			CAT_FLAG_A = CAT_DETECTED;

			Dynamx_MovBwd_Interpolate(12,LEVEL5,IKCALC_ENABLE);

			while(Ping[PING_RIGHT]<20)
			{
				Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
			}

			Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);

			while(Ping[PING_FRONT]<20)
			{
				Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
			}

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowCounter_Left(10);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

			Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowTracer_Right_Interpolate();
		}
	}


}


void Nav_4B_To_HallwaySC(void)
{
	int HOME = 0;
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R4B TO SC");lcd_putstr(lcd);
	delay_ms(50);

//	if(Ping[PING_FRONT] >= FRONT_THRESHOLD)
//	{
//		Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);
//		if(Ping[PING_FRONT] >= FRONT_THRESHOLD)
//		{
//			Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);
//		}
//	}
//
//	BW_PID_Init();
//	BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);
//
//	Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);
//	Dynamx_Slide_Right_Interpolate(HEXSPD_MED,LEVEL5);
//	Dynamx_Slide_Right_Interpolate(HEXSPD_MED,LEVEL5);
//	Dynamx_Slide_Right_Interpolate(HEXSPD_MED,LEVEL5);
//
//	Dynamx_Rot_Right_Interpolate(LEVEL6,HEXSTEP_FAR,IKCALC_DISABLE);
//	Dynamx_Rot_Right_Interpolate(LEVEL6,HEXSTEP_MED,IKCALC_DISABLE);

	BW_PID_Init();
	BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

	BW_PID_Init();
	BW_FollowCounter_Right(6);

	BW_PID_Init();
	while ((Ping[PING_FRONT] >= FRONT_THRESHOLD))
	{
		if ((Ping[PING_FRONT] <= FRONT_THRESHOLD) && (SHARP[IR_FRONT] <= 13))break;
		BW_FollowCounter_Left(1);
		if ((Ping[PING_FRONT] <= FRONT_THRESHOLD) && (SHARP[IR_FRONT] <= 13))break;
	}
}

/* func      : void Nav_4B_To_1(void)
 * brief     : Navigate from Room 4B to Room 1
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, March 29th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
void Nav_4B_To_1A(void)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R4B TO R1A");lcd_putstr(lcd);
	delay_ms(100);

	if(CAT_FLAG_A == CAT_DETECTED || CAT_FLAG_B== CAT_DETECTED)
	{
		if(Ping[PING_FRONT]>18)
		{
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL3,IKCALC_ENABLE);
		}
		if(Ping[PING_FRONT]>18)
		{
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL3,IKCALC_ENABLE);
		}

		Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_MED,IKCALC_DISABLE);

		SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

		BW_PID_Init();
		BWFollowCarpet_Right_Interpolate(COLOUR_GRAY, INVERSE);

		BW_PID_Init();
		BWFollowCarpet_Right_Interpolate(COLOUR_BLACK, INVERSE);

		Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_MED, IKCALC_DISABLE);

		BW_PID_Init();
		BW_FollowTracer_Right_Interpolate();

		FIREROOM_R1A_FLAG=FIREROOM_R1A_ACTIVE;

	}
	else
	{
	ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;
	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	if(Ping[PING_FRONT] > 17)
	{
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
	}
	if(Ping[PING_FRONT] > 17)
	{
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
	}
	Dynamx_Rot_Right_Interpolate(LEVEL3, HEXSTEP_FAR, IKCALC_DISABLE);
	Dynamx_Rot_Right_Interpolate(LEVEL3, HEXSTEP_MED, IKCALC_DISABLE);
//	Dynamx_Rot_Right_Interpolate(LEVEL3, HEXSTEP_CLOSE, IKCALC_DISABLE);

	BW_PID_Init();
	BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

	Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
	Dynamx_Rot_Right_Interpolate(LEVEL3, HEXSTEP_MED, IKCALC_DISABLE);

//	BW_PID_Init();
//	BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);
//	Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"COUNTER");lcd_putstr(lcd);

//	Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);

	if(FOUR_WAY_MANUAL == 0)
	{
/*	GetCMPS11_Angle8Bit();
	if(CMPS11_Angle > R4AB_THRESHOLD_UPPER)
	{
		while(CMPS11_Angle > R4AB_THRESHOLD_UPPER)
		{
			Dynamx_Rot_Right_Interpolate(LEVEL4, HEXSTEP_MED, IKCALC_DISABLE);
			delay_ms(20);
			GetCMPS11_Angle8Bit();
		}
		Dynamx_Rot_Right_Interpolate(LEVEL4, HEXSTEP_CLOSE, IKCALC_DISABLE);
	}*/
/*		BW_COMPASS_CORRECTION(ROOM_4B_TURN_CORRECTION);
		BW_COMPASS_CORRECTION(ROOM_4B_TURN_CORRECTION);*/
		//Dynamx_Rot_Right_Interpolate(LEVEL4, HEXSTEP_MED, IKCALC_DISABLE);
	}

/*	GetCMPS11_Angle8Bit();
	if(CMPS11_Angle >= R4AB_THRESHOLD_UPPER - 20)
	{
		Dynamx_Rot_Right_Interpolate(LEVEL4, HEXSTEP_MED, IKCALC_DISABLE);
	}*/
//================ rot right hpus, mov fwd active
//	Dynamx_Slide_Right_Interpolate(HEXSTEP_CLOSE,LEVEL3);
//	Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
//	Dynamx_Rot_Right_Interpolate(LEVEL3, HEXSTEP_MED, IKCALC_DISABLE);
//	Dynamx_Rot_Right_Interpolate(LEVEL5, HEXSTEP_CLOSE, IKCALC_DISABLE);
//	Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
	BW_PID_Init();
	BW_FollowCounter_Right(5);

//	while(Ping[PING_ASKEW_LEFT] < 30 || Ping[PING_LEFT] < 30)
//	{
//		BW_FollowCounter_Right(1);
//	}

	//=================
//	BW_PID_Init();
//	while((Ping[PING_LEFT] > 25 && Ping[PING_REAR_LEFT] > 25) || (Ping[PING_RIGHT] > 25))
//	{
//		BW_FollowCounter_Right(1);
//		if(SHARP[SHARP_FRONT_L] < 11 && Ping[PING_ASKEW_RIGHT] > 20)
//		{
//			Dynamx_MovBwd_Interpolate(3, LEVEL3, IKCALC_DISABLE);
//			Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);
////			BW_COMPASS_CORRECTION(ROOM_2_1BC_CORRECTION);
//			Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
//		}
//	}

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"COUNTER 2");lcd_putstr(lcd);

	BW_Buzz(1);
	BW_PID_Init_FAR();
//	BW_PID_Init();

	if(EXTINGUISHED_FIRE == 0)
	{
		while((Ping[PING_FRONT] > 24))
		{
			Cat_Avoider();
			if(CAT_FLAG == CAT_DETECTED)break;
			BW_FollowCounter_Left(1);
			Cat_Avoider();
			if(CAT_FLAG == CAT_DETECTED)break;
		}

		if(Ping[PING_LEFT] > 13)
		{
			Dynamx_Slide_Left_Interpolate(HEXSTEP_CLOSE, LEVEL3);
		}

		if(Ping[PING_LEFT] > 14)
		{
			Dynamx_Slide_Left_Interpolate(HEXSTEP_CLOSE, LEVEL3);
		}

		Dynamx_Rot_Right_Interpolate(LEVEL3, HEXSTEP_FAR, IKCALC_DISABLE);
		Dynamx_Rot_Right_Interpolate(LEVEL3, HEXSTEP_MED, IKCALC_DISABLE);

		SHIFT_ALGORITHM_FLAG = SHIFT_ALGORITHM_ACTIVE;
		ROOM4A_CAT_AVOIDER = ROOM4A_CAT_AVOIDER_ACTIVE;

		BW_Buzz(1);
		CAT_DETECTOR = CAT_ACTIVATED;

		BW_PID_Init_FAR();
		BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

	if(CAT_FLAG==CAT_DETECTED)
		{
			CAT_DETECTOR=CAT_DIACTIVATED;
			R4ATO1_SP_ROUTE=SP_ROUTE_INACTIVE;
			CAT_FLAG_A=CAT_DETECTED;

			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
			//Activate special route
			R4ATO3_SP_ROUTE=R4ATO3_SP_ACTIVE;
			R4ATO2_SP_ROUTE=SP_ROUTE_ACTIVE;

			Dynamx_MovBwd_Interpolate(12,LEVEL5,IKCALC_ENABLE);

			Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
			Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
			while(Ping[PING_RIGHT] > 30)
			{
				Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_CLOSE,IKCALC_DISABLE);
			}


			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"COUNTER ON");lcd_putstr(lcd);
			BW_PID_Init();
			int h = 0;
			while(h < 6)
			{
				if(Ping[PING_LEFT] < 30 && Ping[PING_REAR_LEFT] < 30)
				{
					break;
				}
				BW_FollowCounter_Right(1);
				h++;
				if(h>=6)break;
			}

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"COUNTER OFF");lcd_putstr(lcd);

			if(Ping[PING_LEFT] > 17)
			{
				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
			}

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

			if(Ping[PING_ASKEW_RIGHT] >= 20 || Ping[PING_RIGHT] >= 20)
			{
				Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);
			}

			BW_PID_Init();

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

			Dynamx_Rot_Right_Interpolate(LEVEL3, HEXSTEP_MED, IKCALC_DISABLE);

			BW_Buzz(1);
			BW_PID_Init();
			BW_FollowTracer_Right_Interpolate();
			FIREROOM_R1A_FLAG=FIREROOM_R1A_ACTIVE;

		}
		else
		{
			ROOM4A_CAT_AVOIDER=ROOM4A_CAT_AVOIDER_ACTIVE;
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

			BW_Buzz(1);
			BW_PID_Init();
			BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

			BW_PID_Init_FAR();
			while(Ping[PING_FRONT] > 17)
			{
				BW_FollowCounter_Left(1);
			}

			Dynamx_Rot_Right_Interpolate(LEVEL3, HEXSTEP_FAR, IKCALC_DISABLE);
			Dynamx_Rot_Right_Interpolate(LEVEL3, HEXSTEP_MED, IKCALC_DISABLE);
			BW_PID_Init_FAR();
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_ACTIVE;

			for(i = 0; i <= 8; i++)
			{
				Cat_Avoider();
				if(CAT_FLAG == CAT_NOT_DETECTED)
				{
					BW_FollowCounter_Left(1);
				}
				else break;

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)break;
			}

			if(CAT_FLAG==CAT_DETECTED)
			{
				CAT_DETECTOR=CAT_DIACTIVATED;
				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
				CAT_FLAG_B=CAT_DETECTED;

				Dynamx_MovBwd_Interpolate(12,LEVEL5,IKCALC_ENABLE);

				Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_MED,IKCALC_DISABLE);
				while(Ping[PING_RIGHT] > 30)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
				}

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);
				Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

				Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

				BW_Buzz(1);
				BW_PID_Init();
				BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

//				Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);

				Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_MED,IKCALC_DISABLE);

				BW_Buzz(1);
				BW_PID_Init();
				BW_FollowTracer_Right_Interpolate();

				FIREROOM_R1A_FLAG=FIREROOM_R1A_ACTIVE;
			}
			else
			{
				SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

				BW_Buzz(1);
				BW_PID_Init();
				BW_FollowTracer_Left_Interpolate();

				FIREROOM_R1A_FLAG=FIREROOM_R1A_ACTIVE;

			}

		}
		}
		else
		{
			BW_PID_Init();
			BW_FollowTracer_Left_Interpolate();
		}
		}
}

/* func      : void Nav_4B_To_1(void)
 * brief     : Navigate from Room 4B to Room 1
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (Thursday, Feb 23th 2017)
 * Revised BY: N/A
 * programmer's Note:
 */

void Nav_4B_To_1BC(void)
{
	int g;
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R4B TO R1BC");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	for(g=0;g<=3;g++)
	{
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);
		if(Ping[PING_FRONT]<=15)break;
	}

	while(Ping[PING_FRONT]<18)
	{
		Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
	}

	BW_Buzz(1);
	BW_PID_Init();
	BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

	BW_Buzz(1);
	BW_PID_Init();
	BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

	if(Ping[PING_LEFT]>=15)
	{
		Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
	}

	if(Ping[PING_LEFT]>=30)
	{
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL3,IKCALC_DISABLE);
		if(Ping[PING_ASKEW_LEFT]>=30)
		{
			SP_FIRE_1B=SP_FIRE_ACTIVE;
		}
		Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_MED,IKCALC_DISABLE);
	}
	else
	{
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL3,IKCALC_DISABLE);

		SP_FIRE_1C=SP_FIRE_ACTIVE;
	}

	BW_Buzz(1);
	BW_PID_Init();
	BW_FollowTracer_Left_Interpolate();

}


/* func      : void Nav_4B_To_2(void)
 * brief     : Navigate from Room 4B to Room 3
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Thursday, March 29th 2016)
 * Revised BY: Ver2 : Hafidin (Thursday, Feb 23th 2017)
 * programmer's Note:
 */
void Nav_4B_To_2(void)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R4B TO R2");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	while(Ping[PING_FRONT]>=17)
	{
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
	}

	Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR2,IKCALC_DISABLE);

	BW_PID_Init();
	BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

	Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_CLOSE,IKCALC_DISABLE);

	BW_PID_Init();
	BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

	if(Ping[PING_RIGHT] > 15 || Ping[PING_ASKEW_RIGHT] >17)
	{
		Dynamx_Slide_Right_Interpolate(HEXSTEP_CLOSE,LEVEL3);
	}

	BW_PID_Init();
	BW_FollowTracer_Right_Interpolate();
}

void Nav_4B_To_2_V2(void)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R4B TO R2");lcd_putstr(lcd);
	delay_ms(100);

//	if(Ping[PING_FRONT] >= FRONT_THRESHOLD)
//	{
//		Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);
//		if(Ping[PING_FRONT] >= FRONT_THRESHOLD)
//		{
//			Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);
//		}
//	}

//	if(Ping[PING_FRONT] <= FRONT_THRESHOLD)
//	{
//		Dynamx_Rot_Right_IK(LEVEL6,STEP4);
//	}

	Dynamx_MovFwd4cm_Interpolate(16,LEVEL6,IKCALC_ENABLE);

	if(Ping[PING_FRONT] <= FRONT_THRESHOLD)
	{
		Dynamx_Rot_Right_IK(LEVEL6,STEP4);
	}

	Dynamx_MovFwd4cm_Interpolate(20,LEVEL6,IKCALC_ENABLE);

	Dynamx_Slide_Left_Interpolate(HEXSPD_MED,LEVEL3);

	Dynamx_Rot_Left_IK(LEVEL6,STEP4);

	Dynamx_MovFwd4cm_Interpolate(4,LEVEL6,IKCALC_ENABLE);

	BW_PID_Init();
	BW_FollowTracer_Right_Interpolate();

	FLAG_ROOM_2 = FLAG_ROOM_ACTIVE;

	if(TCS3200_SLV_BUF[0] == TRACER_WHITE)
	{
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL6,IKCALC_ENABLE);
	}
}

/* func      : void Nav_4B_To_3(void)
 * brief     : Navigate from Room 4B to Room 3
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Thursday, March 29th 2016)
 * Revised BY: Ver2 : Hafidin (Thursday, Feb 23th 2017)
 * programmer's Note:
 */
void Nav_4B_To_3(void)
{
	BW_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"R4B TO R3");lcd_putstr(lcd);
	delay_ms(100);

	SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;

	if(Ping[PING_FRONT]>18)
	{
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL3,IKCALC_ENABLE);
	}
		Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_MED,IKCALC_DISABLE);

	BW_Buzz(1);
	BW_PID_Init();
	BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,INVERSE);

	Dynamx_Rot_Left_Interpolate(LEVEL3, HEXSTEP_MED, IKCALC_DISABLE);

	BW_Buzz(1);
	BW_PID_Init();
	BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,INVERSE);

	if(FOUR_WAY_MANUAL == 0)
	{

	}


	Nav_TurnAround(TURN_RIGHT);

	BW_Buzz(1);
	BW_PID_Init();
	BW_FollowTracer_Left_Interpolate();
}

/* func      : void TCSlave_Check(void)
 * brief     : Detecting white lines with Photodiode Tracer and TCS3200 Processor
 * param     : N/A
 * retval    : N/A
 * Ver       : 3
 * written By: Ryan (Thursday, March 30th 2016)
 * Revised BY: Ver. 2 -> Ryan (Thursday, April 21st 2016
 * 					Configured for the new Hybrid TCS3200+Tracer Processor
 * 			   Ver. 3 -> Ryan  (Monday, April 4th 2017
 * 			        Optimization for Photodiode Tracer Readings
 * programmer's Note:
 */
void TCSlave_Check(void)
{
	if( (HOME_CIRCLE_FLAG == HOME_CIRCLE_NOT_DETECTED) && (FOLLOWHOME_FLAG==FOLLOWHOME_INACTIVE))
	{
		if(FOLLOWMODE_FLAG==FOLLOW_TRACER_WHITE)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(	(TCS3200_SLV_DATA[1]==TRACER_WHITE)  )
			{
				TRACER_STAT= TRACER_WHITE;
			}

			TCS3200_Transmit(UART5, CMD_GET_TRACER);

			if( (TCS3200_SLV_DATA[1]==TRACER_WHITE)  )

			{	TRACER_STAT= TRACER_WHITE;	}

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(
				(TCS3200_SLV_DATA[1]==TRACER_WHITE)
			  )
			{
				TRACER_STAT= TRACER_WHITE;
			}
		}


		else if(FOLLOWMODE_FLAG==FOLLOW_CARPET_ACTIVE)
		{
			TCS3200_Transmit(UART5, CMD_GET_TCS3200);
			if(
				(TCS3200_SLV_DATA[0]==COLOUR_WHITE)
			  )
			{
						TRACER_STAT= TRACER_WHITE;
			}
		}
	}
}

void H_Exit_Room_V1(void)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(1,1);sprintf(lcd,"FIRE NOT FOUND");lcd_putstr(lcd);
	lcd_gotoxy(2,2);sprintf(lcd,"EXIT  ROOM");lcd_putstr(lcd);
	lcd_gotoxy(3,3);sprintf(lcd,"INITIATE");lcd_putstr(lcd);
	delay_ms(50);

	if (FLAG_ROOM_1B == FLAG_ROOM_ACTIVE)
	{
		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(2,1);sprintf(lcd,"ROOM 1 FLAG");lcd_putstr(lcd);
		lcd_gotoxy(2,2);sprintf(lcd,"EXIT  ROOM");lcd_putstr(lcd);
		lcd_gotoxy(3,3);sprintf(lcd,"INITIATE");lcd_putstr(lcd);
		delay_ms(50);

		Nav_TurnAround(TURN_RIGHT);

		BW_PID_Init();
		BW_FollowTracer_Left_Interpolate();

		FLAG_ROOM_1B = FLAG_ROOM_INACTIVE;
	}

	else if(FLAG_ROOM_2 == FLAG_ROOM_ACTIVE)
	{
		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(2,1);sprintf(lcd,"ROOM 2 FLAG");lcd_putstr(lcd);
		lcd_gotoxy(2,2);sprintf(lcd,"EXIT  ROOM");lcd_putstr(lcd);
		lcd_gotoxy(3,3);sprintf(lcd,"INITIATE");lcd_putstr(lcd);
		delay_ms(50);

		Nav_TurnAround(TURN_LEFT);

		BW_PID_Init();
		BW_FollowTracer_Right_Interpolate();

		FLAG_ROOM_2 = FLAG_ROOM_INACTIVE;
	}

	else if(FLAG_ROOM_3 == FLAG_ROOM_ACTIVE)
	{
		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(2,1);sprintf(lcd,"ROOM 3 FLAG");lcd_putstr(lcd);
		lcd_gotoxy(2,2);sprintf(lcd,"EXIT  ROOM");lcd_putstr(lcd);
		lcd_gotoxy(3,3);sprintf(lcd,"INITIATE");lcd_putstr(lcd);
		delay_ms(50);

		Nav_TurnAround(TURN_LEFT);

		BW_PID_Init();
		BW_FollowTracer_Right_Interpolate();

		FLAG_ROOM_3 = FLAG_ROOM_INACTIVE;
	}

	else if (FLAG_ROOM_4B == FLAG_ROOM_ACTIVE)
	{
		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(2,1);sprintf(lcd,"ROOM 4B FLAG");lcd_putstr(lcd);
		lcd_gotoxy(2,2);sprintf(lcd,"EXIT  ROOM");lcd_putstr(lcd);
		lcd_gotoxy(3,3);sprintf(lcd,"INITIATE");lcd_putstr(lcd);
		delay_ms(50);

		Nav_TurnAround(TURN_LEFT);

		BW_PID_Init();
		BW_FollowTracer_Right_Interpolate();

		FLAG_ROOM_4B = FLAG_ROOM_INACTIVE;
	}

	else
	{
		lcd_display_clear();
		lcd_gotoxy(0,3);sprintf(lcd,"DEFAULT EXIT");lcd_putstr(lcd);
		Nav_TurnAround(TURN_LEFT);

		BW_PID_Init_Room();
		BW_FollowTracer_Right_Interpolate();
	}
}

/* func      : void Exit_No_Fire(void)
 * brief     : BW Escape ROOM when fire is not present
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (*MISSING NOTES*, Legacy codes from BW 2015)
 * Revised BY: N/A
 * programmer's Note:
 *
 */
void Exit_No_Fire(void)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(1,1);sprintf(lcd,"FIRE NOT FOUND");lcd_putstr(lcd);
	lcd_gotoxy(2,2);sprintf(lcd,"EXIT  ROOM");lcd_putstr(lcd);
	lcd_gotoxy(3,3);sprintf(lcd,"INITIATE");lcd_putstr(lcd);
	delay_ms(100);

	if( (ROOM1_FLAG==ROOM1FLAG_ACTIVE) )
	{
		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(2,1);sprintf(lcd,"ROOM 1 FLAG");lcd_putstr(lcd);
		lcd_gotoxy(2,2);sprintf(lcd,"EXIT  ROOM");lcd_putstr(lcd);
		lcd_gotoxy(3,3);sprintf(lcd,"INITIATE");lcd_putstr(lcd);
		delay_ms(100);

		if (ROOM[2]==ROOM_1C)
		{
			lcd_gotoxy(0,1);sprintf(lcd,"RETURN PARAM");lcd_putstr(lcd);
			lcd_gotoxy(0,3);sprintf(lcd,"ROOM1C MODE");lcd_putstr(lcd);

			Nav_TurnAround(TURN_RIGHT);

			BW_PID_Init();
			BW_FollowTracer_Left_Interpolate();
		}
		else if(ROOM[2]==ROOM_1B)
		{
			lcd_gotoxy(0,1);sprintf(lcd,"RETURN PARAM");lcd_putstr(lcd);
			lcd_gotoxy(0,3);sprintf(lcd,"ROOM1B MODE");lcd_putstr(lcd);

			Nav_TurnAround(TURN_LEFT);

			BW_PID_Init();
			BW_FollowTracer_Right_Interpolate();
		}
		else if( (Ping[PING_LEFT]<30) && (Ping[PING_ASKEW_LEFT]<30) && (Ping[PING_REAR_LEFT]<30)  )
		{
			lcd_gotoxy(0,3);sprintf(lcd,"ROOM1B MODE");lcd_putstr(lcd);
			Nav_TurnAround(TURN_LEFT);

			BW_PID_Init();
			BW_FollowTracer_Right_Interpolate();
		}
				else if( (Ping[PING_RIGHT]<30) && (Ping[PING_ASKEW_RIGHT]<30) && (Ping[PING_REAR_RIGHT]<30)  )
						{
							lcd_gotoxy(0,3);sprintf(lcd,"ROOM1C MODE");lcd_putstr(lcd);
							Nav_TurnAround(TURN_RIGHT);

							BW_PID_Init();
							//BW_PID_Init_Room();
							BW_FollowTracer_Left_Interpolate();
						}

		else
		{
			lcd_gotoxy(0,3);sprintf(lcd,"DEFAULT MODE");lcd_putstr(lcd);
			while(Ping[PING_LEFT]<25)
			{
				Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
			}

			Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);

			if(Ping[PING_FRONT]>18)
			{
				Dynamx_MovFwd4cm_Interpolate(8,LEVEL6,IKCALC_ENABLE);
			}

			while(Ping[PING_FRONT]<25)
			{
				Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
			}

			BW_PID_Init();
			BW_FollowTracer_Right_Interpolate();
		}
		ROOM1_FLAG=ROOM1FLAG_INACTIVE;
	}

	//ENTER FROM R1A, EXIT FROM RIBC
	else if(SP_FIRE_R3==SP_FIRE_ACTIVE)
	{
		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"EXIT NO FIRE");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"ROOM 3 DEFAULT");lcd_putstr(lcd);
		delay_ms(100);

		Nav_TurnAround(TURN_LEFT);

		BW_PID_Init();
		BW_FollowTracer_Right_Interpolate();
	}
	else if(UV_R2FLAG==UV_R2FLAG_ACTIVE)
	{
		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"EXIT NO FIRE");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"ROOM 2 DEFAULT");lcd_putstr(lcd);
		delay_ms(100);

		Nav_TurnAround(TURN_LEFT);

		BW_PID_Init();
		BW_FollowTracer_Right_Interpolate();
	}
	//ENTER FROM R1A, EXIT FROM RIBC
	else if(ROOM1A_SP_EXIT_FLAG==ROOM1A_SP_EXIT_FLAG_ACTIVE)
	{
		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"R 4A TO 1A FLAG");lcd_putstr(lcd);
		lcd_gotoxy(2,2);sprintf(lcd,"EXIT  ROOM");lcd_putstr(lcd);
		lcd_gotoxy(3,3);sprintf(lcd,"INITIATE");lcd_putstr(lcd);
		delay_ms(100);

		UV_R2FLAG=UV_R2FLAG_ACTIVE;
		FOLLOW_FLAG=KIRI;

		lcd_display_clear();
		lcd_gotoxy(0,1);sprintf(lcd,"FOLLOW COUNTER 1A");lcd_putstr(lcd);

		if(Ping[PING_LEFT]>15)
		{	Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
			if(Ping[PING_LEFT]>15)
			{	Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);}
		}

		BW_PID_Init_Room();
		for(i = 0; i < 20; i++)
		{
			TCSlave_Check();
			if (TRACER_STAT==TRACER_WHITE)break;
			BW_FollowCounter_Left(1);
			Get_UV();
			if((UV_state==UVSTATE_ACTIVE) && ((FlameSenseDigi[0]==7) || (FlameSenseDigi[0]==6)))
			{
				ROOM[2]=ROOM_1C;
				Dynamx_MovBwd_Interpolate(4,LEVEL5,IKCALC_ENABLE);
				Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_display_clear();
				lcd_gotoxy(0,1);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);

			}
			else if((UV_state==UVSTATE_ACTIVE) && ((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3)))
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_display_clear();
				lcd_gotoxy(0,1);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
			}
			if(UV_Lock==UVLOCK_ACTIVE)break;

		}

		lcd_display_clear();
		lcd_gotoxy(0,1);sprintf(lcd,"RE-CHECK FIRE 1A");lcd_putstr(lcd);
		TRACER_STAT=TRACER_BLACK;
		TCSlave_Check();
		int i;
		lcd_display_clear();
		BW_PID_Init();
		for(i=0;i<10;i++)
		{
			TCSlave_Check();
			if (TRACER_STAT==TRACER_WHITE)break;
			Get_UV();
			if((UV_state==UVSTATE_ACTIVE) && ((FlameSenseDigi[0]==7) || (FlameSenseDigi[0]==6)))
			{
				ROOM[2]=ROOM_1C;
				Dynamx_MovBwd_Interpolate(4,LEVEL5,IKCALC_ENABLE);
				Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_display_clear();
				lcd_gotoxy(0,1);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);

			}
			else if((UV_state==UVSTATE_ACTIVE) && ((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3)))
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_display_clear();
				lcd_gotoxy(0,1);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
			}
			if(UV_Lock==UVLOCK_ACTIVE)break;
			TCSlave_Check();
			if (TRACER_STAT==TRACER_WHITE)break;
			BW_FollowCounter_Left(1);
			if(UV_Lock==UVLOCK_ACTIVE)break;
			if(FIRE==FIRE_ON)break;
			TCSlave_Check();
			if (TRACER_STAT==TRACER_WHITE)break;
		}

		if(FIRE==FIRE_ON)
		{
			lcd_display_clear();
			lcd_gotoxy(0,1);sprintf(lcd,"API DETECT 1A");lcd_putstr(lcd);

			FIREROOM_R1A_FLAG=ROOM1A_SP_MIDDLE_FLAG;
			FIRESCAN_DIRECTION=SCAN_RIGHT;

			BW_FireFight_V2();

			FIRE_LED_BLINK_OFF;
			FIRE_LED_OFF;
			FIRE=FIRE_SUCCESS;

			//FIRE OFF
			Dynamx_MovBwd_Interpolate(4,LEVEL5,IKCALC_ENABLE);

			if ((ROOM[2]==ROOM_4A) || (ROOM[2]==ROOM_4B) || (ROOM[2]==ROOM_3))// || (ROOM[2]==ROOM_2A) || (ROOM[2]==ROOM_2B))
			{
				FOLLOW_FLAG=KANAN;
				Nav_TurnAround(TURN_LEFT);
				BW_PID_Init();
				BW_FollowTracer_Right_Interpolate();
			}
			else if ((ROOM[2]==ROOM_2A) || (ROOM[2]==ROOM_2B))
			{
				Nav_TurnAround(TURN_LEFT);
				BW_PID_Init();
				if(Ping[PING_RIGHT]>30)BW_FollowTracer_Left_Interpolate();
				else BW_FollowTracer_Right_Interpolate();
			}
			else if (ROOM[2]==ROOM_1C)
			{
				FOLLOW_FLAG=KANAN;
				while(Ping[PING_FRONT]>14)
				{
					Furniture_Avoider();
					Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
				}
				Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
				BW_PID_Init();
				BW_FollowTracer_Right_Interpolate();
			}
			else if (ROOM[2]==ROOM_1B)
			{
				FOLLOW_FLAG=KIRI;
				while(Ping[PING_FRONT]>14)
				{
					Furniture_Avoider();

					Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
				}
				BW_PID_Init();
				BW_FollowTracer_Left_Interpolate();
			}
			else if (ROOM[2]==ROOM_1A)
			{
				FOLLOW_FLAG=KANAN;
				while(Ping[PING_FRONT]>14)
				{
					Furniture_Avoider();

					Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
				}
				BW_PID_Init();
				BW_FollowTracer_Right_Interpolate();
			}

			else if(
					(Ping[PING_LEFT]+Ping[PING_ASKEW_LEFT]+Ping[PING_REAR_LEFT])
					<
					(Ping[PING_RIGHT]+Ping[PING_ASKEW_RIGHT]+Ping[PING_REAR_RIGHT])
				)
			{
				FOLLOW_FLAG=KANAN;
				Nav_TurnAround(TURN_LEFT);
				BW_PID_Init();
				BW_FollowTracer_Right_Interpolate();

			}
			else
			{
				FOLLOW_FLAG=KIRI;
				Nav_TurnAround(TURN_RIGHT);
				BW_PID_Init();
	//			BW_PID_Init_Room();
				BW_FollowTracer_Left_Interpolate();
			}
	//		End of changes
	//		Some codes was omitted in this changes
	//===============================================================
			FOLLOW_FLAG=KOSONG;
			ROOM1A_SP_EXIT_FLAG=ROOM1A_SP_EXIT_FLAG_INACTIVE;
			UV_R2FLAG=UV_R2FLAG_INACTIVE;
		}
		else
		{
			lcd_display_clear();
			lcd_gotoxy(0,1);sprintf(lcd,"API KOSONG R 1A");lcd_putstr(lcd);

			BW_PID_Init_Room();
			BW_FollowTracer_Left_Interpolate();
			FOLLOW_FLAG=KOSONG;
			ROOM1A_SP_EXIT_FLAG=ROOM1A_SP_EXIT_FLAG_INACTIVE;
			UV_R2FLAG=UV_R2FLAG_INACTIVE;
		}
	}

	else if (ROOM4B_EXIT_FLAG==ROOM4BFLAG_EXIT_ACTIVE)
	{
		lcd_gotoxy(0,3);sprintf(lcd,"ROOM4B EXIT");lcd_putstr(lcd);

		if((Ping[PING_ASKEW_LEFT]<25) && (Ping[PING_LEFT]<25))
		{
			while(Ping[PING_LEFT]<25)
			{
				Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
			}

			Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);

			while(Ping[PING_FRONT]>18)
			{
				Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
			}

			while(Ping[PING_FRONT]<25)
			{
				Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
			}

			BW_PID_Init_Room();
			BW_FollowTracer_Right_Interpolate();
		}

		else
		{
			while(Ping[PING_LEFT]<25)
			{
				Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
			}

			Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);

			while(Ping[PING_FRONT]>18)
			{
				Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
			}

			while(Ping[PING_FRONT]<25)
			{
				Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
			}

			BW_PID_Init();
			BW_FollowTracer_Right_Interpolate();
		}
		ROOM4B_EXIT_FLAG=ROOM4BFLAG_EXIT_INACTIVE;
	}

	//DEFAULT EXIT NO FIRE ROUTINES
	else
	{
			lcd_gotoxy(0,3);sprintf(lcd,"DEFAULT EXIT");lcd_putstr(lcd);
			Nav_TurnAround(TURN_LEFT);

			BW_PID_Init_Room();
			BW_FollowTracer_Right_Interpolate();
	}
}

void BW_Climbing_Stairs(void)
{
	CLIMBING_FLAG = 1;
	CLIMBING_INTERRUPT_FLAG = 1;
	int BUFF = 0;

//	Dynamx_Mov_Static_Stairs(LEVEL3,0);
	delay_ms(200);

	while (1)
	{
		if (BW_CMPS11.PitchKF < -10 ){BUFF = 1;}
		if((BW_CMPS11.PitchKF >=-3 && BW_CMPS11.PitchKF <=4 ) && BUFF == 1){break;}

		lcd_display_clear();

		if((BW_CMPS11.PitchKF > 1 && BW_CMPS11.PitchKF < 12))
		{
			lcd_gotoxy(0,0);sprintf(lcd,"MOVEMENT 1");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"PICH : %d",BW_CMPS11.PitchKF);lcd_putstr(lcd);

			Dynamx_Mov_Climbing_Interpolate(1500,1,1);
		}

		else if(BW_CMPS11.PitchKF >= 12)
		{
			lcd_gotoxy(0,0);sprintf(lcd,"MOVEMENT 2");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"PICH : %d",BW_CMPS11.PitchKF);lcd_putstr(lcd);

			Dynamx_Mov_Climbing_Interpolate(1500,1,2);
		}

		else if ((BW_CMPS11.PitchKF < -4)&&(BW_CMPS11.PitchKF > -11))
		{
			lcd_gotoxy(0,0);sprintf(lcd,"MOVEMENT 3");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"PICH : %d",BW_CMPS11.PitchKF);lcd_putstr(lcd);

			Dynamx_Mov_Climbing_Interpolate(1500,1,3);
		}

		else if(BW_CMPS11.PitchKF < -10)
		{
			lcd_gotoxy(0,0);sprintf(lcd,"MOVEMENT 4");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"PICH : %d",BW_CMPS11.PitchKF);lcd_putstr(lcd);

			Dynamx_Mov_Climbing_Interpolate(1500,1,0);
		}

		else
		{
			lcd_gotoxy(0,0);sprintf(lcd,"MOVEMENT 0");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"PICH : %d",BW_CMPS11.PitchKF);lcd_putstr(lcd);

			Dynamx_Mov_Climbing_Interpolate(1500,1,0);
		}

		if (BW_CMPS11.PitchKF < -10 ){BUFF = 1;}
		if((BW_CMPS11.PitchKF >=-3 && BW_CMPS11.PitchKF <=4 ) && BUFF == 1){break;}
	}

	lcd_display_clear();

	CLIMBING_FLAG = 0;
	CLIMBING_INTERRUPT_FLAG = 0;

	lcd_gotoxy(0,0);sprintf(lcd,"CLIMBING SELESAI");lcd_putstr(lcd);
	Dynamx_Mov_Static_Interpolate(LEVEL3,IKCALC_ENABLE);
	delay_ms(200);

}

/* func      : int BW_ReturnTrip(void)
 * brief     : BW Return Trip Routines
 * param     : N/A
 * retval    : int error codes
 * 				0 	-> SUCCESS
 * 				-1 	-> ERROR, EXTINGUISHED_FIRE==0 / !=1
 * Ver       : 1
 * written By: Ryan (Thursday, March 31th 2016)
 * Revised BY: N/A
 * programmer's Note:
 */
int BW_ReturnTrip(void)
{
	if(EXTINGUISHED_FIRE==1)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"RETURN TRIP");lcd_putstr(lcd);
		delay_ms(100);

		if( (ROOM[2]== ROOM_1A) )
		{
			if( (ROOM[1] == HALLWAY_SC) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R1A TO SC");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_1A,HALLWAY_SC);
			}

			else if( (ROOM[1] == ROOM_2A) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R1A TO R2A");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_1A,ROOM_2A);
			}

			else if( (ROOM[1] == ROOM_2B) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R1A TO R2B");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_1A,ROOM_2B);
			}

			else if(ROOM[1] == ROOM_3)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R1A TO R3");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_1A,ROOM_3);
			}

			else if(ROOM[1] == ROOM_4A)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R1A TO R4A");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_1A,ROOM_4A);
			}

			else if(ROOM[1] == ROOM_4B)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R1A TO R4B");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_1A,ROOM_4B);
			}
		}

		else if( (ROOM[2]== ROOM_1B) || (ROOM[2]== ROOM_1C) )
		{
			if( (ROOM[1] == HALLWAY_SC) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R1C TO SC");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_1C,HALLWAY_SC);
			}

			else if(ROOM[1] == ROOM_3)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R1C TO R3");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_1C,ROOM_3);
			}

			else if( (ROOM[1] == ROOM_2A) || (ROOM[1] == ROOM_2B) )
			{
				if(ROOM[2]== ROOM_1B)
				{
					lcd_gotoxy(0,1);sprintf(lcd,"R1B TO R2A");lcd_putstr(lcd);
					delay_ms(100);
					BW_Navi(ROOM_1B,ROOM_2A);
				}

				else if(ROOM[2]== ROOM_1C)
				{
					lcd_gotoxy(0,1);sprintf(lcd,"R1C TO R2A");lcd_putstr(lcd);
					delay_ms(100);
					BW_Navi(ROOM_1C,ROOM_2A);
				}

			}

			else if(ROOM[1] == ROOM_4A)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R1C TO R4A");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_1C,ROOM_4A);
			}
			else if(ROOM[1] == ROOM_4B)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R1C TO R4B");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_1C,ROOM_4B);
			}
		}

		//ROOM[ROOM_COUNTER] == ROOM_2AB
		else if ( (ROOM[2]== ROOM_2A) || (ROOM[2]== ROOM_2B) )
		{
			if( (ROOM[1] == HALLWAY_SC) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R2A TO SC");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_2A,HALLWAY_SC);
			}

			else if( (ROOM[1] == ROOM_1A) || (ROOM[1] == ROOM_1B) || (ROOM[1] == ROOM_1C) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R2AB TO R1BC");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_2B,ROOM_1B);

			}

			else if(ROOM[1] == ROOM_3)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R2A TO R3");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_2A,ROOM_3);

			}

			else if(ROOM[1] == ROOM_4A)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R2A TO R4A");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_2A,ROOM_4A);
			}
			else if(ROOM[1] == ROOM_4B)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R2A TO R4B");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_2A,ROOM_4B);
			}
		}

		//ROOM[ROOM_COUNTER] == ROOM_3
		else if (ROOM[2]== ROOM_3)
		{
			if( (ROOM[1] == HALLWAY_SC) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R3 TO SC");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_3,HALLWAY_SC);
			}

			else if ( (ROOM[1] == ROOM_1A) || (ROOM[1] == ROOM_1B) || (ROOM[1] == ROOM_1C) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R3 TO R1B");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_3,ROOM_1B);

			}

			else if( (ROOM[1] == ROOM_2A) || (ROOM[1] == ROOM_2B) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R3 TO R2A");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_3,ROOM_2A);

			}

			else if(ROOM[1] == ROOM_4A)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R3 TO R4A");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_3,ROOM_4A);

			}

			else if(ROOM[1] == ROOM_4B)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R3 TO R4B");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_3,ROOM_4B);

			}
		}

		//ROOM[ROOM_COUNTER] == ROOM_4A
		else if (ROOM[2]== ROOM_4A)
		{
			if( (ROOM[1] == HALLWAY_SC) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R4A TO SC");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_4A,HALLWAY_SC);
			}

			else if ( (ROOM[1] == ROOM_1A) || (ROOM[1] == ROOM_1B) || (ROOM[1] == ROOM_1C) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R4A TO R1A");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_4A,ROOM_1A);

			}

			else if( (ROOM[1] == ROOM_2A) || (ROOM[1] == ROOM_2B) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R4A TO R2A");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_4A,ROOM_2A);

			}

			else if(ROOM[1] == ROOM_3)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R4A TO R3");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_4A,ROOM_3);

			}
		}

		//ROOM[ROOM_COUNTER] == ROOM_4B
		else if (ROOM[2]== ROOM_4B)
		{
			if( (ROOM[1] == HALLWAY_SC) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R4B TO SC");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_4B,HALLWAY_SC);
			}

			else if ( (ROOM[1] == ROOM_1A) || (ROOM[1] == ROOM_1B) || (ROOM[1] == ROOM_1C) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R4B TO R1A");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_4B,ROOM_1B);

			}

			else if( (ROOM[1] == ROOM_2A) || (ROOM[1] == ROOM_2B) )
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R4B TO R2A");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_4B,ROOM_2A);

			}

			else if(ROOM[1] == ROOM_3)
			{
				lcd_gotoxy(0,1);sprintf(lcd,"R4B TO R3");lcd_putstr(lcd);
				delay_ms(100);
				BW_Navi(ROOM_4B,ROOM_3);

			}
		}

		// Everything's Alright~ *I hope
		return 0;
	}

	//Return Error Code
	else
	{
		BW_Buzz(2);
		lcd_gotoxy(0,1);sprintf(lcd,"ROUTE ERROR");lcd_putstr(lcd);
		delay_ms(100);

		while(1)
		{
			BW_Buzz(1);
			Dynamx_Mov_Static_Interpolate(HEXSPD_ULTRAFAST,IKCALC_ENABLE);
		}

		//BW MAP UPDATE
		RoomDetector(ROOM_COUNTER);
		BW_ReturnTrip();

		return -1;
	}
}


void BW_FlameFollowDemo_Dynamixel(void)
{
	if(Ping[PING_ASKEW_LEFT] <= 30 || Ping[PING_LEFT] <= 30)
	{
		BW_PID_Init();
		Get_UV();
		if(UV_state == UVSTATE_INACTIVE)
		{
			while(UV_state == UVSTATE_INACTIVE)
			{

				if(UV_state == UVSTATE_ACTIVE)break;

				BW_FollowCounter_Left(1);

				if(UV_state == UVSTATE_ACTIVE)break;
			}
		}
	}
	else if(Ping[PING_ASKEW_RIGHT] <= 30 || Ping[PING_RIGHT] <= 30)
	{
		BW_PID_Init();
		Get_UV();
		if(UV_state == UVSTATE_INACTIVE)
		{
			while(UV_state == UVSTATE_INACTIVE)
			{

				if(UV_state == UVSTATE_ACTIVE)break;
//				if(FlameFrontDigi[0] == 4)break;
//				if(FlameSenseDigi[0] != 0)break;
				BW_FollowCounter_Right(1);

				if(UV_state == UVSTATE_ACTIVE)break;
//				if(FlameFrontDigi[0] == 4)break;
//				if(FlameSenseDigi[0] != 0)break;

			}
		}
	}

	FlameSenseDigi_PID_Init();

	while(UV_state==UVSTATE_INACTIVE)
	{
		Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_FAR,IKCALC_DISABLE);
	}

	CANDLE_STICK=0;
	CANDLE_FIRE=0;
	FIRE_LED_BLINK_ON;

	BW_Buzz(1);
	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
	delay_ms(100);

		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"BW FIREFIGHT");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"TRACKING");lcd_putstr(lcd);
		delay_ms(100);

		for(x=0;x<=1;x++)
		{
				FlameTracking_Center();

				while(SHARP[SHARP_FRONT_R]>30 && SHARP[SHARP_FRONT_L]>30)
				{
//					if(FlameFrontDigi[0]==4 || FlameSenseDigi[0] == 1 || FlameSenseDigi[0] == 2 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 4 || SHARP[SHARP_FRONT_R]<40 )break;
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"MAJU KE API");lcd_putstr(lcd);

					Dynamx_MovFwd4cm_Interpolate(8,LEVEL4,IKCALC_ENABLE);

					Furniture_Avoider();


					if(FlameFrontDigi[0]==4 || FlameSenseDigi[0] == 1 || FlameSenseDigi[0] == 2 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 4 || SHARP[SHARP_FRONT_R]<40 )break;
				}


				if(UV_state==1)break;

				FlameTracking_Center();



				while(SHARP[SHARP_FRONT_R]>30 && SHARP[SHARP_FRONT_L]>30)
				{
//					if(FlameFrontDigi[0]==4 || FlameSenseDigi[0] == 1 || FlameSenseDigi[0] == 2 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 4 || SHARP[SHARP_FRONT_R]<40 )break;
					lcd_gotoxy(0,0);sprintf(lcd,"MAJU KE API");lcd_putstr(lcd);

					Dynamx_MovFwd4cm_Interpolate(8,LEVEL4,IKCALC_ENABLE);

					Furniture_Avoider();


					if(FlameFrontDigi[0]==4 || FlameSenseDigi[0] == 1 || FlameSenseDigi[0] == 2 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 4 || SHARP[SHARP_FRONT_R]<40 )break;
				}

		}

	UV_R2FLAG=UV_R2FLAG_INACTIVE;

	UVLock_Refresh();
	if(UV_Lock==UVLOCK_ACTIVE)
	{
		BW_Buzz(1);
		lcd_display_clear();
		lcd_gotoxy(0,1);sprintf(lcd,"EXTINGUISH 1.0");lcd_putstr(lcd);
		delay_ms(100);
		FlameTracking_Ver3();

		FlameTracking_Center();

		while(SHARP[SHARP_FRONT_L] > 25 || Ping[PING_FRONT] > 25)
		{
//			if(FlameFrontDigi[0]==4 || FlameSenseDigi[0] == 1 || FlameSenseDigi[0] == 2 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 4 || SHARP[SHARP_FRONT_R]<40 )break;
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL3,IKCALC_DISABLE);
			if(FlameFrontDigi[0]==4 || FlameSenseDigi[0] == 1 || FlameSenseDigi[0] == 2 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 4 || SHARP[SHARP_FRONT_R]<40 )break;
		}

		if(FlameFrontDigi[0]!=4 && FlameSenseDigi[0] != 4)
		{
			FlameTracking_Center();
		}
		FlameTracking_Center();
		Dynamx_Mov_Static_Interpolate(LEVEL5,IKCALC_ENABLE);
		BW_HydroPump_V10();
//		BW_HydroPump_2();
	}

	delay_ms(2000);

	UVLock_Refresh();
	if(UV_Lock==UVLOCK_ACTIVE)
	{
		BW_Buzz(1);
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"EXTINGUISH 2.0");lcd_putstr(lcd);
		delay_ms(100);

//		BW_HydroPump_2();
		BW_HydroPump_V10();
	}

	delay_ms(2000);

	UVLock_Refresh();
	if(UV_Lock==UVLOCK_ACTIVE)
	{
//		Dynamx_Mov_Tracking(HEXSPD_SLOW);
		lcd_gotoxy(0,0);sprintf(lcd,"TRACKING AGAIN ");lcd_putstr(lcd);
		delay_ms(100);
		while(((SHARP[SHARP_FRONT_R]>40) && (SHARP[SHARP_FRONT_L]>40)))
		{
//			if(FlameFrontDigi[0]==4 || FlameSenseDigi[0] == 1 || FlameSenseDigi[0] == 2 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 4 || SHARP[SHARP_FRONT_R]<40 )break;
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FIRE MOVE FORWARD ");lcd_putstr(lcd);
			delay_ms(100);

			Furniture_Avoider();


			if(FlameFrontDigi[0]==4 || FlameSenseDigi[0] == 1 || FlameSenseDigi[0] == 2 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 4 || SHARP[SHARP_FRONT_R]<40 )break;
		}
	}
	delay_ms(2000);


	UVLock_Refresh();
	delay_ms(300);
	UVLock_Refresh();
	delay_ms(2000);


	if(UV_Lock==UVLOCK_ACTIVE)
	{
		BW_Buzz(1);
		lcd_display_clear();
		lcd_gotoxy(0,1);sprintf(lcd,"EXTINGUISH 1.1");lcd_putstr(lcd);
		delay_ms(100);
		FlameTracking_Ver3();

		BW_HydroPump_V10();
	}
	delay_ms(2000);

	UVLock_Refresh();
	if(UV_Lock==UVLOCK_ACTIVE)
	{
		BW_Buzz(1);
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"EXTINGUISH 2.1");lcd_putstr(lcd);
		delay_ms(100);

		BW_HydroPump_V10();
	}
	delay_ms(2000);

	UVLock_Refresh();
	if(UV_Lock==UVLOCK_ACTIVE)
	{
		lcd_gotoxy(0,0);sprintf(lcd,"TRACKING AGAIN ");lcd_putstr(lcd);
		delay_ms(100);

		while((SHARP[SHARP_FRONT_R]>40) /*&& (SHARP[SHARP_FRONT_L]>30))*/)
		{
//			if(FlameFrontDigi[0]==4 || FlameSenseDigi[0] == 1 || FlameSenseDigi[0] == 2 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 4 || SHARP[SHARP_FRONT_R]<40 )break;
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL3,IKCALC_DISABLE);

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FIRE MOVE FORWARD ");lcd_putstr(lcd);
			delay_ms(100);


			Furniture_Avoider();


			if(FlameFrontDigi[0]==4 || FlameSenseDigi[0] == 1 || FlameSenseDigi[0] == 2 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 4 || SHARP[SHARP_FRONT_R]<40 )break;
		}
	}

	delay_ms(2000);
	UVLock_Refresh();
	while(UV_Lock==UVLOCK_ACTIVE)
	{
		BW_TurnAround=INACTIVE;

		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) break;

		UVLock_Refresh();
		if(UV_Lock==UVLOCK_ACTIVE)
		{

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_ACTIVE)
			{
				BW_Buzz(1);
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
				delay_ms(100);
				FlameTracking_Center();
			}

/////////////////////////////////////////////////////////////////////////////////

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_ACTIVE)
			{
				BW_Buzz(1);
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"EXTINGUISH 3");lcd_putstr(lcd);
				delay_ms(100);

				BW_HydroPump_V10();
			}

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_ACTIVE)
			{
				BW_Buzz(1);
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"EXTINGUISH 4");lcd_putstr(lcd);
				delay_ms(100);

				BW_HydroPump_V10();
			}

			UVLock_Refresh();
			if(UV_Lock==UVLOCK_ACTIVE)
			{
//				Dynamx_Mov_Tracking(HEXSPD_SLOW);

				lcd_gotoxy(0,0);sprintf(lcd,"TRACKING AGAIN ");lcd_putstr(lcd);
				delay_ms(100);

				while((SHARP[SHARP_FRONT_R]>40) /*&& (SHARP[SHARP_FRONT_L]>30))*/ )
				{
//					if(FlameFrontDigi[0]==4 || FlameSenseDigi[0] == 1 || FlameSenseDigi[0] == 2 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 4 || SHARP[SHARP_FRONT_R]<40 )break;
					Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);

					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"FIRE MOVE FORWARD ");lcd_putstr(lcd);
					delay_ms(100);


					Furniture_Avoider();


					if(FlameFrontDigi[0]==4 || FlameSenseDigi[0] == 1 || FlameSenseDigi[0] == 2 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 4 || SHARP[SHARP_FRONT_R]<40 )break;
				}
			}
			UVLock_Refresh();
			if(UV_Lock==UVLOCK_ACTIVE)
			{

				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
				delay_ms(100);

				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"EXTINGUISH 5");lcd_putstr(lcd);
				delay_ms(100);

				BW_HydroPump_V10();

				UVLock_Refresh();
				if(UV_Lock==UVLOCK_ACTIVE)
				{
					BW_Buzz(1);
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"EXTINGUISH 6");lcd_putstr(lcd);
					delay_ms(100);

					BW_HydroPump_V10();
				}
			}
		}
		UVLock_Refresh();
		if(UV_Lock==UVLOCK_INACTIVE) break;
	}

EXTINGUISHER_OFF;
EXTINGUISHED_FIRE=1;

BW_Buzz(2);
lcd_display_clear();
lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
lcd_gotoxy(2,1);sprintf(lcd,"FIREFIGHTING");lcd_putstr(lcd);
lcd_gotoxy(3,2);sprintf(lcd,"SUCCESS!!!");lcd_putstr(lcd);
delay_ms(200);
FIRE_LED_BLINK_OFF;
while(UV_state==UVSTATE_INACTIVE)
	{
		Dynamx_Mov_Static_Interpolate(LEVEL5,IKCALC_ENABLE);
		if(BUTTON_A_CLICKED)
		{
			while(BUTTON_A_CLICKED){}
			break;
		}
	}
}

/*
 *  Param: TURN_LEFT, TURN_RIGHT
 */
void Nav_TurnAround(int ORIENTATION)
{
	switch(ORIENTATION)
	{
		case 1:
		{
			while ((Ping[PING_LEFT]>15))
			{
				if (Ping[PING_REAR_LEFT] < 13)break;
				else if (Ping[PING_ASKEW_LEFT]<13)break;
				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL6);
				if (Ping[PING_REAR_LEFT] < 13)break;
				else if (Ping[PING_ASKEW_LEFT]<13)break;
			}

			if(EXTINGUISHED_FIRE==1)
			{
				Dynamx_Rot_Left_Interpolate(LEVEL7,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Rot_Left_Interpolate(LEVEL7,HEXSTEP_FAR,IKCALC_DISABLE);
			}
			else
			{
				while((Ping[PING_LEFT]<20) || (Ping[PING_FRONT]>25))
				{
					Dynamx_Rot_Left_Interpolate(LEVEL7,HEXSTEP_FAR,IKCALC_DISABLE);
				}
			}
			if(Ping[PING_FRONT]>18)
			{
				Dynamx_MovFwd4cm_Interpolate(8,LEVEL7,IKCALC_ENABLE);
			}

			while(Ping[PING_FRONT]<20)
			{
				Dynamx_Rot_Left_Interpolate(LEVEL7,HEXSTEP_FAR2,IKCALC_DISABLE);
			}

			if(Ping[PING_RIGHT]>20)
			{
				Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL6);
			}

			if ((Ping[PING_RIGHT]+4) > (Ping[PING_ASKEW_RIGHT]))
			{
				Dynamx_Rot_Left_Interpolate(LEVEL7,HEXSTEP_CLOSE,IKCALC_DISABLE);
			}

			if ((Ping[PING_RIGHT]+4) > (Ping[PING_REAR_RIGHT]))
			{
				Dynamx_Rot_Right_Interpolate(LEVEL7,HEXSTEP_CLOSE,IKCALC_DISABLE);
			}
		}break;

		case 2:
		{
			while ((Ping[PING_RIGHT]>20))
			{
				if (Ping[PING_REAR_RIGHT] < 13)break;
				else if (Ping[PING_ASKEW_RIGHT]<13)break;
				Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL6);
				if (Ping[PING_ASKEW_RIGHT]<13)break;
				else if (Ping[PING_REAR_RIGHT] < 13)break;
			}

			if(EXTINGUISHED_FIRE==1)
			{
				Dynamx_Rot_Right_Interpolate(LEVEL6,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Rot_Right_Interpolate(LEVEL6,HEXSTEP_FAR,IKCALC_DISABLE);
			}
			else
			{
				while((Ping[PING_RIGHT]<20) || (Ping[PING_FRONT]>25))
				{
					Dynamx_Rot_Right_Interpolate(LEVEL6,HEXSTEP_FAR,IKCALC_DISABLE);
				}
			}

			while(Ping[PING_FRONT]<20)
			{
				Dynamx_Rot_Right_Interpolate(LEVEL6,HEXSTEP_FAR,IKCALC_DISABLE);
			}

			if(Ping[PING_LEFT]>20)
			{
				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL6);
			}

			if ((Ping[PING_LEFT]+4) > (Ping[PING_ASKEW_LEFT]))
			{
				Dynamx_Rot_Right_Interpolate(LEVEL6,HEXSTEP_CLOSE,IKCALC_DISABLE);
			}

			if ((Ping[PING_LEFT]+4) > (Ping[PING_REAR_LEFT]))
			{
				Dynamx_Rot_Left_Interpolate(LEVEL6,HEXSTEP_CLOSE,IKCALC_DISABLE);
			}
		}break;
	}
}


void FlameSenseDigi_PID_Init(void)
{
	//BW PID WALL FOLLOWING RIGHT RULE
	PID_FLAME.P[0]=0;
	PID_FLAME.P[1]=0;
	PID_FLAME.P[2]=0;
	PID_FLAME.I[0]=0;
	PID_FLAME.I[1]=0;
	PID_FLAME.I[2]=0;
	PID_FLAME.D[0]=0;
	PID_FLAME.D[1]=0;
	PID_FLAME.D[2]=0;

	PID_FLAME.Kp=4;
	PID_FLAME.Ki=0;
	PID_FLAME.Kd=0;

	PID_FLAME.Ts=1;

	PID_FLAME.set_point=4;

	PID_FLAME.error[0]=0;
	PID_FLAME.error[1]=0;
	PID_FLAME.error[2]=0;
	PID_FLAME.pid_value[0]=0;
	PID_FLAME.pid_value[1]=0;
	PID_FLAME.pid_value[2]=0;
}

/*
 * func      : void PID_Calc(void)
 * brief     : PID Controller Calculations
 * param     : N/A
 * Written By: Ryan
 * Ver       : 1
 * Programmer's Note: PID Formula rewritten with guidance from KRPAI Senior, Desta.
 * 					  This function should be called everytime PID function executed
 */
void FlameSense_PID_Calc_Ver3(void)
{
	/*
	 * Update Nilai Variable PID & Set-Point Error
	 */
	PID_FLAME.pid_value[2]=PID_FLAME.pid_value[1];
	PID_FLAME.pid_value[1]=PID_FLAME.pid_value[0];

	PID_FLAME.error[2]=PID_FLAME.error[1];
	PID_FLAME.error[1]=PID_FLAME.error[0];

	if (FlameSenseDigi[0]==PID_FLAME.set_point) {PID_FLAME.error[0]=0;}

	else if ( FlameSenseDigi[0] > PID_FLAME.set_point)
		{
			PID_FLAME.error[0] = FlameSenseDigi[0] - PID_FLAME.set_point;
		}

	else if (FlameSenseDigi[0] < PID_FLAME.set_point)
		{
			PID_FLAME.error[0] = PID_FLAME.set_point - FlameSenseDigi[0];
		}

	/*
	 * PID FORMULA
	 */
	PID_FLAME.P[2]= PID_FLAME.error[0]-PID_FLAME.error[2];
	PID_FLAME.P[1]= PID_FLAME.Kp;
	PID_FLAME.P[0]= PID_FLAME.P[1]*PID_FLAME.P[2]; //Proportional Controller

	PID_FLAME.I[2]= PID_FLAME.Ki*PID_FLAME.Ts/2;
	PID_FLAME.I[1]= PID_FLAME.error[0]+(2*PID_FLAME.error[1])+PID_FLAME.error[2];
	PID_FLAME.I[0]= PID_FLAME.I[2]*PID_FLAME.I[1]; //Integral Controller

	PID_FLAME.D[2]= 2*PID_FLAME.Kd/PID_FLAME.Ts;
	PID_FLAME.D[1]= PID_FLAME.error[0]-(2*PID_FLAME.error[1])+PID_FLAME.error[2];
	PID_FLAME.D[0]= PID_FLAME.D[2]*PID_FLAME.D[1]; //Derivative Controller

	PID_FLAME.pid_value[0]= PID_FLAME.pid_value[2] + PID_FLAME.P[0] + PID_FLAME.I[0] + PID_FLAME.D[0];
}


int FlameTracking_Ver3(void)
{
	int flametrack_cnt=0;
	Get_UV();

	while( (FlameSenseDigi[0]!=4) && (FlameFrontDigi[0] != 4) && (UV_state == UVSTATE_ACTIVE))
	{
		Get_UV();
		if(UV_state == UVSTATE_INACTIVE)break;
//		PID_FlameTracking_Ver3();

		flametrack_cnt++;
		lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"flametrack: %d",flametrack_cnt);lcd_putstr(lcd);
		if(flametrack_cnt>=24)
		{
			flametrack_cnt=0;
			BW_Buzz(1);
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"FLAMETRACKING");lcd_putstr(lcd);
			lcd_gotoxy(4,0);sprintf(lcd,"OVERFLOW");lcd_putstr(lcd);
			delay_ms(100);
			int counts_flametracking = 0, follow_mode_ft = 0, init_pid_ft = 0;
			Get_UV();
			while(FlameSenseDigi[0] != 4 && UV_state == UVSTATE_ACTIVE)
			{
				Get_UV();
				if(UV_state == UVSTATE_INACTIVE)break;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1] == COLOUR_WHITE || TRACER_STAT == TRACER_WHITE)
				{
					TRACER_STAT = TRACER_BLACK;
					init_pid_ft = 1;
					Dynamx_MovBwd_Interpolate(15,LEVEL5,IKCALC_DISABLE);
					Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
					Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
					Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_MED,IKCALC_DISABLE);
					Get_UV();
					if(UV_state == UVSTATE_INACTIVE)break;
				}
				if(init_pid_ft == 1)
				{
					BW_PID_Init_Room();
					init_pid_ft = 0;
				}
				if(follow_mode_ft == 0)
				{
					BW_FollowCounter_Left(1);
				}
				else BW_FollowCounter_Right(1);
				if(FlameSenseDigi[0] != 0 || FlameFrontDigi[0] != 0)break;
//				if ((FlameFrontDigi[0]==4) && (FlameSenseDigi[0] == 4))break;
				counts_flametracking++;
				Get_UV();
				if(UV_state == UVSTATE_INACTIVE)break;
			}
			break;
		}
		if ((FlameFrontDigi[0]==4) && (FlameSenseDigi[0] == 4))break;

	}
	EXTINGUISHER_OFF;
	return 0;
}

/* func      : 	void FlameTracking_Center(void)
 * brief     : 	Dynamixel Hexapod Flame Tracking Center
 * param     :
 * retval    : N/A
 * Ver       : 1
 * written By: Hafidin (Wed, March 1 2017)
 * Revised By:
 *
 */

int FlameTracking_Center(void)
{
	int CNT=0;
	int CNT_LONG=0;
	Get_UV();
	UV_state = 0;
	lcd_display_clear();
	while((FlameFrontDigi[0]!=4) && (FlameSenseDigi[0]!=4) && (UV_state == 0))
	{
		lcd_gotoxy(0,0);sprintf(lcd,"FLAME CENTER");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
		if((FlameFrontDigi[0]==4) || (FlameSenseDigi[0]==4))break;
		while((FlameSenseDigi[0]!=5) || (FlameSenseDigi[0]!=6))
		{
			if((FlameFrontDigi[0]==4) || FlameSenseDigi[0]==4)break;
			if((FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==6))break;

			Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_VERYCLOSE,IKCALC_DISABLE); // flame dibalik

			CNT++;
			if(CNT>24)
			{
				Get_UV();
				if(UV_state==1){CNT=0;CNT_LONG=1;break;}
			}

			if(FIRE==1)break;
			if((FlameFrontDigi[0]==4) || FlameSenseDigi[0]==4)break;
			if((FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==6))break;
		}
		if((FlameFrontDigi[0]==4) || (FlameSenseDigi[0]==4))break;
		if(CNT_LONG==1)break;
		else CNT=0;
		lcd_display_clear();
		while((FlameSenseDigi[0]!=3) || (FlameSenseDigi[0]!=2))
		{
			if((FlameFrontDigi[0]==4) || (FlameSenseDigi[0]==4))break;
			if((FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==2))break;

			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"CENTERING");lcd_putstr(lcd);

			Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

			CNT++;
			if(CNT>24)
				{
				Get_UV();
					if(UV_state==1){CNT=0;CNT_LONG=1;break;}
				}

			if((FlameFrontDigi[0]==4)|| (FlameSenseDigi[0]==4))break;
			if((FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==2))break;
			Get_UV();
			if(UV_state == 1)break;
		}

		while((FlameSenseDigi[0]!=4)|| (FlameFrontDigi[0]!=4))
		{
			if((FlameFrontDigi[0]==4) || (FlameSenseDigi[0]==4))break;

			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"CENTERING");lcd_putstr(lcd);

			if(FlameSenseDigi[0] > 4)
			{
				while(FlameSenseDigi[0] > 4)
				{
					Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if(FlameFrontDigi[0] == 4 || FlameSenseDigi[0]==4)break;
				}
			}
			if(FlameSenseDigi[0] < 4)
			{
				while(FlameSenseDigi[0] < 4)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if(FlameFrontDigi[0] == 4 || FlameSenseDigi[0]==4)break;
				}
			}
			if((FlameFrontDigi[0]==4) || (FlameSenseDigi[0]==4))break;
			CNT++;
			if(CNT>24)
			{
				Get_UV();
				if(UV_state==1){CNT=0;CNT_LONG=1;break;}
			}

			if((FlameFrontDigi[0]==4)|| (FlameSenseDigi[0]==4))break;
			Get_UV();
			if(UV_state == 1)break;
		}
		if(CNT_LONG==1)break;
		else CNT=0;
		if((FlameFrontDigi[0]==4) || (FlameSenseDigi[0]==4))break;
		Get_UV();
		if(UV_state==1)break;
	}
	return 0;
}


int PID_FlameTracking_Ver3(void)
{
	//OVERCOMING BLIND SPOTS
	if(FlameSenseDigi[0]==0) FlameSenseDigi[0]=10;

	FlameSense_PID_Calc_Ver3();

	//KONDISI ROBOT SESUAI
	if ( FlameSenseDigi[0]==PID_FLAME.set_point)
	{
		FlameTrack_Flag=FLAG_ACTIVE;
	}

	else if(FlameSenseDigi[0]==10)
	{
		if ( (FlameSenseDigi[1]==10) || (FlameSenseDigi[1]==0) )
		{
			Dynamx_Rot_Right_PID_Interpolate(LEVEL3,HEXSTEP_CLOSE,&PID_FLAME.pid_value[0],IKCALC_DISABLE);
		}
		else if( (FlameSenseDigi[1]==1) )
		{
			UVLock_Refresh();
//			Rot_Left_PID(FAST, CLOSE, &DUMMY_PIDVALUE);
			Dynamx_Rot_Left_PID_Interpolate(LEVEL3,HEXSTEP_CLOSE,&PID_FLAME.pid_value[0],IKCALC_DISABLE);
//			Sendto_PC(USART1,"WINDUP ROT LEFT NARROW ACTIVATED \r");
		}
		else if( (FlameSenseDigi[1]==7) )
		{
			UVLock_Refresh();
//			Rot_Right_PID(FAST, CLOSE, &DUMMY_PIDVALUE);
			Dynamx_Rot_Right_PID_Interpolate(LEVEL3,HEXSTEP_CLOSE,&PID_FLAME.pid_value[0],IKCALC_DISABLE);
//			Sendto_PC(USART1,"WINDUP ROT RIGHT NARROW ACTIVATED \r");
		}

		else if ( FlameSenseDigi[1] > PID_FLAME.set_point )
		{
//			Rot_Right_PID(FAST, CLOSE, &PID_FLAME.pid_value[0]);
			Dynamx_Rot_Right_PID_Interpolate(LEVEL3,HEXSTEP_CLOSE,&PID_FLAME.pid_value[0],IKCALC_DISABLE);
//			Sendto_PC(USART1,"WINDUP ROT RIGHT CLOSE REACH ACTIVATED \r");
		}

		else if ( FlameSenseDigi[1] < PID_FLAME.set_point )
		{
//			Rot_Left_PID(FAST, CLOSE, &PID_FLAME.pid_value[0]);
			Dynamx_Rot_Left_PID_Interpolate(LEVEL3,HEXSTEP_CLOSE,&PID_FLAME.pid_value[0],IKCALC_DISABLE);
//			Sendto_PC(USART1,"WINDUP ROT LEFT CLOSE REACH ACTIVATED \r");
		}
	}

	//KONDISI ROBOT JAUH DARI DINDING
	else if ( FlameSenseDigi[0] > PID_FLAME.set_point )
	{
//		Rot_Right_PID(FAST, CLOSE, &PID_FLAME.pid_value[0]);
		Dynamx_Rot_Right_PID_Interpolate(LEVEL3,HEXSTEP_CLOSE,&PID_FLAME.pid_value[0],IKCALC_DISABLE);
		FlameSenseDigi[1]=7;

	}

	//KONDISI ROBOT DEKAT DENGAN DINDING
	else if ( FlameSenseDigi[0] < PID_FLAME.set_point )
	{
		FlameSenseDigi[1]=1;
//		Rot_Left_PID(FAST, CLOSE, &PID_FLAME.pid_value[0]);
		Dynamx_Rot_Left_PID_Interpolate(LEVEL3,HEXSTEP_CLOSE,&PID_FLAME.pid_value[0],IKCALC_DISABLE);

	}
	return 0;
}

void H_2021_Algorithm(void)
{
	int Error_Code=1;

	EXTINGUISHER_OFF;

	REVERSE_FLAG=REVERSEFLAG_INACTIVE;
	SP_FIRE_1B=SP_FIRE_INACTIVE;

	BW_LOCATION[0]= LOCATION_ROOM;
	ROOM_COUNTER = 1;

		RoomTypeDetector();

		BW_Home_Detection_2021();

		//TES POINT 1
//		lcd_display_clear();
//		lcd_gotoxy(0,0);sprintf(lcd,"TES POINT 1");lcd_putstr(lcd);
//		delay_ms(50);
//
//		Dynamx_Mov_Static_Interpolate(LEVEL3,IKCALC_ENABLE);
//		while(1){};

		if(ROOM_TYPE != GRAY_ROOM && HOME_POS != TENGAH)
		{
			if(Ping[PING_RIGHT] > 30 && Ping[PING_LEFT] < 20 && Ping[PING_FRONT] < 20 && Ping[PING_REAR] < 20)
			{
				Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);
				Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);
				Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);

				if(Ping[PING_REAR] >= 20 && Ping[PING_REAR] > Ping[PING_FRONT])
				{
					Dynamx_Rot_Right_Interpolate(LEVEL4, HEXSTEP_FAR, IKCALC_DISABLE);
					Dynamx_Rot_Right_Interpolate(LEVEL4, HEXSTEP_MED, IKCALC_DISABLE);
					FOLLOW_FLAG = KIRI;
				}
				else if(Ping[PING_FRONT] >= 20 && Ping[PING_REAR] < Ping[PING_FRONT])
				{
					Dynamx_Rot_Right_Interpolate(LEVEL4, HEXSTEP_FAR, IKCALC_DISABLE);
					Dynamx_Rot_Right_Interpolate(LEVEL4, HEXSTEP_MED, IKCALC_DISABLE);
					FOLLOW_FLAG = KANAN;
				}
			}

			else if(Ping[PING_FRONT] > 30 && Ping[PING_LEFT] < 20 && Ping[PING_RIGHT] < 20 && Ping[PING_REAR] < 20)
			{
				if(Ping[PING_ASKEW_LEFT] > 23 && Ping[PING_ASKEW_RIGHT] < 20)
				{
					FOLLOW_FLAG = KANAN;
				}

				else if(Ping[PING_ASKEW_RIGHT] > 23 && Ping[PING_ASKEW_LEFT] < 20)
				{
					FOLLOW_FLAG = KIRI;
				}
				else
				{
					Dynamx_MovFwd4cm_Interpolate(8, LEVEL3, IKCALC_DISABLE);

					if(Ping[PING_LEFT] >= 20 && Ping[PING_LEFT] > Ping[PING_RIGHT])
					{
						if(Ping[PING_RIGHT] <= 9)
						{
							Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
						}
						else if(Ping[PING_RIGHT] >= 17)
						{
							Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);
						}
						FOLLOW_FLAG = KANAN;
					}
					else if(Ping[PING_RIGHT] >= 20 && Ping[PING_LEFT] < Ping[PING_RIGHT])
					{
						if(Ping[PING_LEFT] <= 9)
						{
							Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);
						}
						else if(Ping[PING_LEFT] >= 17)
						{
							Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
						}
						FOLLOW_FLAG = KIRI;
					}
				}
			}

			else if(Ping[PING_REAR] > 30 && Ping[PING_LEFT] < 20 && Ping[PING_RIGHT] < 20 && Ping[PING_FRONT] < 20)
			{
				Dynamx_MovBwd_Interpolate(9, LEVEL3, IKCALC_ENABLE);

				if(Ping[PING_RIGHT] >= 20 && Ping[PING_LEFT] < Ping[PING_RIGHT])
				{
					Nav_TurnAround(TURN_LEFT);
					FOLLOW_FLAG = KANAN;
				}
				else if(Ping[PING_LEFT] >= 20 && Ping[PING_LEFT] > Ping[PING_RIGHT])
				{
					Nav_TurnAround(TURN_RIGHT);
					FOLLOW_FLAG = KIRI;
				}
			}

			else if(Ping[PING_LEFT] > 30 && Ping[PING_RIGHT] < 20 && Ping[PING_REAR] < 20 && Ping[PING_FRONT] < 20)
			{
				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);

				if(Ping[PING_FRONT] >= 20 && Ping[PING_REAR] < Ping[PING_FRONT])
				{
					Dynamx_Rot_Left_Interpolate(LEVEL4, HEXSTEP_FAR, IKCALC_DISABLE);
					FOLLOW_FLAG = KIRI;
				}
				else if(Ping[PING_REAR] >= 20 && Ping[PING_REAR] > Ping[PING_FRONT])
				{
					Dynamx_Rot_Left_Interpolate(LEVEL4, HEXSTEP_FAR, IKCALC_DISABLE);
					FOLLOW_FLAG = KANAN;
				}
			}

			else if(Ping[PING_ASKEW_RIGHT] < 25 && Ping[PING_RIGHT] >= 25 && (Ping[PING_ASKEW_LEFT] < 20 || Ping[PING_LEFT] < 20))
			{
				FOLLOW_FLAG = KIRI;
			}

			else if(Ping[PING_ASKEW_LEFT] < 25 && Ping[PING_LEFT] >= 25 && (Ping[PING_ASKEW_RIGHT] < 20 || Ping[PING_RIGHT] < 20))
			{
				FOLLOW_FLAG = KANAN;
			}

			else if((Ping[PING_FRONT] > 25 || Ping[PING_UP_RIGHT] > 25) && Ping[PING_UP_LEFT] < 25 && Ping[PING_LEFT] >= 25)
			{
				Dynamx_Rot_Left_Interpolate(LEVEL4, HEXSTEP_FAR, IKCALC_DISABLE);
				FOLLOW_FLAG = KIRI;
			}

			else if((Ping[PING_FRONT] > 25 || Ping[PING_UP_LEFT] > 25) && Ping[PING_UP_RIGHT] < 25 && Ping[PING_RIGHT] >= 25)
			{
				Dynamx_Rot_Right_Interpolate(LEVEL4, HEXSTEP_FAR, IKCALC_DISABLE);
				FOLLOW_FLAG = KANAN;
			}
		}

			if(FOLLOW_FLAG==KIRI)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW TRACER :");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"LEFT");lcd_putstr(lcd);
				delay_ms(50);

				BW_PID_Init_Room();
				BW_FollowTracer_Left_Interpolate();
			}
			else
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW TRACER :");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"RIGHT");lcd_putstr(lcd);
				delay_ms(50);

				BW_PID_Init_Room();
				BW_FollowTracer_Right_Interpolate();

				Dynamx_MovFwd4cm_Interpolate(4,LEVEL6,IKCALC_ENABLE);
			}

			ROOM_MOVEMENT = 0;

//			//TES POINT 2
//			lcd_display_clear();
//			lcd_gotoxy(0,2);sprintf(lcd,"TES POINT 2");lcd_putstr(lcd);
//			delay_ms(50);
//
//			Dynamx_Mov_Static_Interpolate(LEVEL3,IKCALC_ENABLE);
//			while(1){};

//===============================================HOME CHECK=====================================//
			if(ROOM_TYPE == GRAY_ROOM)
			{
				if((Ping[PING_RIGHT] < Ping[PING_LEFT]) || Ping[PING_ASKEW_RIGHT] < Ping[PING_ASKEW_LEFT] || Ping[PING_REAR_RIGHT] < Ping[PING_REAR_LEFT])
				{
					if((Ping[PING_RIGHT]+4)<(Ping[PING_REAR_RIGHT]) || (Ping[PING_ASKEW_RIGHT]+6)<(Ping[PING_REAR_RIGHT]))
					{
						Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					}
					else
					{
						if((Ping[PING_RIGHT])>(Ping[PING_REAR_RIGHT]+6))
						{
							Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						}
						if((Ping[PING_RIGHT])>(Ping[PING_REAR_RIGHT]+4))
						{
							Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						}
					}
				}
				Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
			}

			else
			{
				if((Ping[PING_RIGHT] < Ping[PING_LEFT]) || Ping[PING_ASKEW_RIGHT] < Ping[PING_ASKEW_LEFT] || Ping[PING_REAR_RIGHT] < Ping[PING_REAR_LEFT])
				{
					if(((Ping[PING_RIGHT]+4)<(Ping[PING_REAR_RIGHT])) && Ping[PING_REAR_RIGHT] < 60)
					{
						Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					}

					else
					{
						if(((Ping[PING_RIGHT])>(Ping[PING_REAR_RIGHT] + 4)) && Ping[PING_RIGHT] < 60)
						{
							Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						}
					}
				}
				else
				{
					if((Ping[PING_LEFT]+4)<(Ping[PING_REAR_LEFT]) && Ping[PING_REAR_LEFT] < 60)
					{
						Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

						if((Ping[PING_LEFT]+4)<(Ping[PING_REAR_LEFT]) && Ping[PING_REAR_LEFT] < 60)
						{
							Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						}
					}
					else
					{
						if(((Ping[PING_LEFT])>(Ping[PING_REAR_LEFT]+4)) && Ping[PING_LEFT] < 60)
						{
							Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						}
					}
				}
			}

		if(FOLLOW_FLAG==KIRI)
		{
			Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL4);
			Dynamx_Rot_Right_Interpolate(LEVEL3, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
		}

		if(ROOM_TYPE != GRAY_ROOM)
		{
			GetCMPS11_Angle8Bit();
			if(
			   (CMPS11_Angle > R4A_THRESHOLD_MIDDLE && CMPS11_Angle < R4A_THRESHOLD_LOWER)
			   	    ||
			   (CMPS11_Angle < R4A_THRESHOLD_MIDDLE && CMPS11_Angle > R4A_THRESHOLD_LOWER)
			   	   	||
			   (CMPS11_Angle < R4AB_THRESHOLD_LOWER  && CMPS11_Angle > R4A_THRESHOLD_LOWER)
			   	   	||
			   (CMPS11_Angle > R4AB_THRESHOLD_LOWER  && CMPS11_Angle < R4A_THRESHOLD_LOWER)

			   )
			{
				if(Ping[PING_RIGHT] <= 30 && Ping[PING_FRONT] >= 50 && Ping[PING_LEFT] >= 30)
				{
					Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
				}
				else
				{
					Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
				}
			}
		}

		else if (  (CMPS11_Angle > R4B_THRESHOLD_MIDDLE && CMPS11_Angle < R4B_THRESHOLD_LOWER)
				   	    ||
				   (CMPS11_Angle < R4B_THRESHOLD_MIDDLE && CMPS11_Angle > R4B_THRESHOLD_LOWER)
				   	   	||
				   (CMPS11_Angle < R4B_THRESHOLD_LOWER  && CMPS11_Angle > R4B_THRESHOLD_UPPER)
				   	   	||
				   (CMPS11_Angle > R4B_THRESHOLD_LOWER  && CMPS11_Angle < R4B_THRESHOLD_UPPER)	)
		{
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);

			if(Ping[PING_RIGHT] <= 30 && Ping[PING_FRONT] >= 50 && Ping[PING_LEFT] >= 30)
			{
				Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
			}
			else
			{
				Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
			}
			TCS3200_Transmit(UART5,CMD_GET_TRACER);

			if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)
			{
				Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
			}
		}

		COMPASS_INTERRUPT = 0;

		FOLLOW_FLAG=KOSONG;

		// JIKA KELUAR MIRING DI RUANG 4
		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1]==COLOUR_GRAY)
			{
				Dynamx_Rot_Left_Interpolate(LEVEL7,HEXSTEP_MED,IKCALC_DISABLE);
				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,100);
				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,100);
			}

	BW_LOCATION[1]=BW_LOCATION[0];
	BW_LOCATION[0]=LOCATION_CORRIDOR;

//	//TES POINT 3
//	lcd_display_clear();
//	lcd_gotoxy(0,1);sprintf(lcd,"TES POINT 3");lcd_putstr(lcd);
//	delay_ms(50);
//
//	Dynamx_Mov_Static_Interpolate(LEVEL4, IKCALC_ENABLE);
//	while(1){};

		delay_ms(400);
		GetCMPS11_Angle8Bit();
		RoomDetector(ROOM_COUNTER);

		//TES POINT 4
//		lcd_display_clear();
//		lcd_gotoxy(0,1);sprintf(lcd,"TES POINT 4");lcd_putstr(lcd);
//		delay_ms(50);

//		Dynamx_Mov_Static_Interpolate(LEVEL4, IKCALC_ENABLE);
//		while(1){};

	while(EXTINGUISHED_FIRE==0)
		{
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"STRATEGY");lcd_putstr(lcd);
			lcd_gotoxy(0,3);sprintf(lcd,"CNT= %d",cnt);lcd_putstr(lcd);

				if(ROOM[ROOM_COUNTER]==ROOM_1A)
				{
					H_ROOM_1A();
				}
				else if(ROOM[ROOM_COUNTER]==ROOM_1B)
				{
					H_ROOM_1BC();
				}
				else if(ROOM[ROOM_COUNTER]==ROOM_1C)
				{
					H_ROOM_1BC();
				}
				else if(ROOM[ROOM_COUNTER]== ROOM_2A)
				{
					H_ROOM_2();
				}
				else if (ROOM[ROOM_COUNTER]==ROOM_2B)
				{
					H_ROOM_2();
				}
				else if(ROOM[ROOM_COUNTER]== ROOM_3)
				{
					H_ROOM_3();
				}
				else if(ROOM[ROOM_COUNTER]==ROOM_4A)
				{
					H_ROOM_4A();
				}
				else if(ROOM[ROOM_COUNTER]==ROOM_4B)
				{
					H_ROOM_4B();
				}
				else if(cnt>10)
				{
					RoomDetector(ROOM_COUNTER);
				}
				cnt++;
		}

		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;

		if((Ping[PING_RIGHT] < Ping[PING_LEFT]) || Ping[PING_ASKEW_RIGHT] < Ping[PING_ASKEW_LEFT] || Ping[PING_REAR_RIGHT] < Ping[PING_REAR_LEFT])
		{
			if((Ping[PING_RIGHT]+5)<(Ping[PING_REAR_RIGHT]) || (Ping[PING_ASKEW_RIGHT]+5)<(Ping[PING_REAR_RIGHT]))
			{
				Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_RIGHT]+5)<(Ping[PING_REAR_RIGHT]))
				{	Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
			}

			else
			{
				if((Ping[PING_RIGHT])>(Ping[PING_REAR_RIGHT] + 4))
				{
					Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				}
				if((Ping[PING_RIGHT])>(Ping[PING_REAR_RIGHT] + 4))
				{
					Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				}
			}
		}

		else
		{
			if((Ping[PING_LEFT]+4)<(Ping[PING_REAR_LEFT]) || (Ping[PING_ASKEW_LEFT]+4)<(Ping[PING_REAR_LEFT]))
			{
				Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

				if((Ping[PING_LEFT]+4)<(Ping[PING_REAR_LEFT]) || (Ping[PING_ASKEW_LEFT]+4)<(Ping[PING_REAR_LEFT]))
				{
					Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				}
			}
			else
			{
				if((Ping[PING_LEFT])>(Ping[PING_REAR_LEFT]+4) || (Ping[PING_ASKEW_LEFT])>(Ping[PING_REAR_LEFT]+4))
				{
					Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				}
				if((Ping[PING_LEFT])>(Ping[PING_REAR_LEFT]+4) || (Ping[PING_ASKEW_LEFT])>(Ping[PING_REAR_LEFT]+4))
				{
					Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				}
			}
		}

		FOLLOW_FLAG=KOSONG;

		Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);

		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)
		{
			Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
		}

		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)
		{
			Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
		}

		if((ROOM[2]==ROOM_1A) || (ROOM[2]==ROOM_1B) || (ROOM[2]==ROOM_1C))
		{
			if(Ping[PING_FRONT]>40)
			{
				GetCMPS11_Angle8Bit();

				BW_COMPASS_CORRECTION(ROOM_1C_DETECT_NAV);
				if(ROOM[2] != ROOM_1C)
				{
					if(Ping[PING_RIGHT] <= 24 && ROOM[2] != ROOM_1C)
					{
						ROOM[2]=ROOM_1A;
					}
					else
					{
						ROOM[2]=ROOM_1C;
					}
				}
			}
			else
			{
				ROOM[2]=ROOM_1B;

			}
		}

		Error_Code= BW_ReturnTrip();

		if(ROOM[1]!=HALLWAY_SC)
		{
			if(ROOM[1]==ROOM_2A)
			{
				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
				if(Ping[PING_LEFT]>10)
				{
					Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
				}
				if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
					{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);			}
				}
			}
			SHIFT_ALGORITHM_FLAG=SHIFT_ALGORITHM_INACTIVE;
			BW_PID_Init();
			if(ROOM[1] == ROOM_4A || ROOM[1] == ROOM_4B)
			{
				while(Ping[PING_FRONT] > 17)
				{
					BW_FollowCounter_Left(1);
					Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
					Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
				}
			}

			else
			{
				BW_FollowCounter_Left(8);
			}

			SND_ACT_LED_OFF;	//turn off sound led indicator
		}

		if(Error_Code==0)
		{
			BW_Buzz(5);
			int j=15;

			Dynamx_Mov_Static_Interpolate(LEVEL5,IKCALC_ENABLE);
			delay_ms(1000);
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(j,0);sprintf(lcd,"BHATARA WIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(j,1);sprintf(lcd,"MISSION");lcd_putstr(lcd);
				lcd_gotoxy(j,2);sprintf(lcd,"ACCOMPLISHED!");lcd_putstr(lcd);
				delay_ms(50);
				j--;
				if(j==0)j=15;

				Dynamx_Mov_Static_Interpolate(LEVEL5,IKCALC_ENABLE);
			}
		}

		else
		{
			int j=15;

			Dynamx_Mov_Static_Interpolate(LEVEL5,IKCALC_ENABLE);
			delay_ms(1000);
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(j,0);sprintf(lcd,"BHATARA WIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(j,1);sprintf(lcd,"MISSION");lcd_putstr(lcd);
				lcd_gotoxy(j,2);sprintf(lcd,"FAILED");lcd_putstr(lcd);
				delay_ms(50);
				j--;
				if(j==0)j=15;
				BW_Buzz(1);
				Dynamx_Mov_Static_Interpolate(LEVEL5,IKCALC_ENABLE);
			}
		}
}

void H_2021_Algorithm_V1(void)
{
	BW_LOCATION[1]= BW_LOCATION[0];
	BW_LOCATION[0]= LOCATION_CORRIDOR;

	Home_HallwaySC_Detector();

	BW_Home_Start_Right();

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"STRATEGY");lcd_putstr(lcd);
	lcd_gotoxy(0,3);sprintf(lcd,"SESI 1");lcd_putstr(lcd);
	delay_ms(200);

	H_SESI_1();

	Dynamx_Mov_Static_Interpolate(LEVEL5,IKCALC_ENABLE);

	SND_ACT_LED_OFF;

	lcd_display_clear();
	lcd_gotoxy(0,2);sprintf(lcd,"SESI 1 COMPLETED");lcd_putstr(lcd);
	delay_ms(200);
}

void H_2021_Algorithm_V2(void)
{
	int flag_2 = 1;
	BW_LOCATION[1]= BW_LOCATION[0];
	BW_LOCATION[0]= LOCATION_CORRIDOR;

	Home_HallwaySC_Detector();

	BW_Home_Start_Right();

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"STRATEGY");lcd_putstr(lcd);
	lcd_gotoxy(0,3);sprintf(lcd,"SESI 2");lcd_putstr(lcd);
	delay_ms(200);

	H_SESI_2();

	Dynamx_Mov_Static_Interpolate(LEVEL5,IKCALC_ENABLE);

	lcd_display_clear();
	lcd_gotoxy(0,2);sprintf(lcd,"SESI 2 COMPLETED");lcd_putstr(lcd);
	delay_ms(200);

}

void H_2021_Algorithm_V3(void)
{
	int flag_3 = 1;
	BW_LOCATION[1]= BW_LOCATION[0];
	BW_LOCATION[0]= LOCATION_CORRIDOR;

	Home_HallwaySC_Detector();

	BW_Home_Start_Right();

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"STRATEGY");lcd_putstr(lcd);
	lcd_gotoxy(0,3);sprintf(lcd,"SESI 3");lcd_putstr(lcd);
	delay_ms(200);

	H_SESI_3();

	Dynamx_Mov_Static_Interpolate(LEVEL5,IKCALC_ENABLE);

	lcd_display_clear();
	lcd_gotoxy(0,2);sprintf(lcd,"SESI 3 COMPLETED");lcd_putstr(lcd);
	delay_ms(200);

}

void Instant_Trial(void)
{
	while(BW_BUTTON_CLICKED);
	delay_ms(500);
	while(1)
	{
		GetCMPS11_Angle8Bit();
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"R4A TENGAH");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"Angle : %d", CMPS11_Angle);lcd_putstr(lcd);
		delay_ms(200);
		if(BW_BUTTON_CLICKED)break;
	}
	R4A_THRESHOLD_MIDDLE = CMPS11_Angle;
	while(BW_BUTTON_CLICKED);

	while(1)
	{
		GetCMPS11_Angle8Bit();
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"R4A SERONG KANAN");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"Angle : %d", CMPS11_Angle);lcd_putstr(lcd);
		delay_ms(200);
		if(BW_BUTTON_CLICKED)break;
	}
	R4A_THRESHOLD_LOWER = CMPS11_Angle;
	while(BW_BUTTON_CLICKED);

	while(1)
	{
		GetCMPS11_Angle8Bit();
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"R4A SERONG KIRI");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"Angle : %d", CMPS11_Angle);lcd_putstr(lcd);
		delay_ms(200);
		if(BW_BUTTON_CLICKED)break;
	}
	R4A_THRESHOLD_UPPER = CMPS11_Angle;
	while(BW_BUTTON_CLICKED);

	while(1)
	{
		GetCMPS11_Angle8Bit();
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"R4A KANAN");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"Angle : %d", CMPS11_Angle);lcd_putstr(lcd);
		delay_ms(200);
		if(BW_BUTTON_CLICKED)break;
	}
	R4AB_THRESHOLD_LOWER = CMPS11_Angle;
	while(BW_BUTTON_CLICKED);

	while(1)
	{
		GetCMPS11_Angle8Bit();
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"R4A KIRI");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"Angle : %d", CMPS11_Angle);lcd_putstr(lcd);
		delay_ms(200);
		if(BW_BUTTON_CLICKED)break;
	}
	R4AB_THRESHOLD_UPPER = CMPS11_Angle;
	while(BW_BUTTON_CLICKED);

	while(1)
	{
		GetCMPS11_Angle8Bit();
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"R4B SERONG KANAN");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"Angle : %d", CMPS11_Angle);lcd_putstr(lcd);
		delay_ms(200);
		if(BW_BUTTON_CLICKED)break;
	}
	R4B_THRESHOLD_UPPER = CMPS11_Angle;
	while(BW_BUTTON_CLICKED);

	while(1)
	{
		GetCMPS11_Angle8Bit();
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"R4B SERONG KIRI");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"Angle : %d", CMPS11_Angle);lcd_putstr(lcd);
		delay_ms(200);
		if(BW_BUTTON_CLICKED)break;
	}
	R4B_THRESHOLD_LOWER = CMPS11_Angle;
	while(BW_BUTTON_CLICKED);

	while(1)
	{
		GetCMPS11_Angle8Bit();
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"R4B TENGAH");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"Angle : %d", CMPS11_Angle);lcd_putstr(lcd);
		delay_ms(200);
		if(BW_BUTTON_CLICKED)break;
	}
	R4B_THRESHOLD_MIDDLE = CMPS11_Angle;
	while(BW_BUTTON_CLICKED);

	while(1)
	{
		GetCMPS11_Angle8Bit();
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"START MID");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"Angle : %d", CMPS11_Angle);lcd_putstr(lcd);
		delay_ms(200);
		if(BW_BUTTON_CLICKED)break;
	}
	START_MIDDLE = CMPS11_Angle;
	while(BW_BUTTON_CLICKED);

	while(1)
	{
		GetCMPS11_Angle8Bit();
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"R1BC");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"Angle : %d", CMPS11_Angle);lcd_putstr(lcd);
		delay_ms(200);
		if(BW_BUTTON_CLICKED)break;
	}
	R1BC_THRESHOLD_MIDDLE = CMPS11_Angle;
	while(BW_BUTTON_CLICKED);
}

void H_IN_Room (void)
{
	USART3_PutChar(IN_ROOM_STAT);
	int SPRAY_CO2 = 0;

	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"BHATARA WIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,1);sprintf(lcd,"LOCATION :");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"ROOM");lcd_putstr(lcd);

	if (FLAG_ROOM_3 == FLAG_ROOM_ACTIVE)
	{
		if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)
		{
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
		}

		BW_PID_Init_Room();
		BW_FollowCounter_Left(1);

		if (Ping[PING_LEFT]<12)
		{
			Dynamx_Slide_Right_Interpolate(HEXSPD_MED,LEVEL4);
		}

		SPRAY_CO2 = 1;
	}

	else if (FLAG_ROOM_2 == FLAG_ROOM_ACTIVE)
	{
		if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)
		{
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
		}

		BW_PID_Init_Room();
		BW_FollowCounter_Left(2);

		if(Ping[PING_LEFT] > 15)
		{
			Dynamx_Slide_Left_Interpolate(HEXSPD_MED,LEVEL4);
			if(Ping[PING_LEFT] > 15)
			{
				Dynamx_Slide_Left_Interpolate(HEXSPD_MED,LEVEL4);
			}
		}

		SPRAY_CO2 = 1;
	}

	else if (FLAG_ROOM_1A == FLAG_ROOM_ACTIVE)
	{
		if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)
		{
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
		}

		BW_PID_Init_Room();
		BW_FollowCounter_Left(2);

		if(Ping[PING_LEFT]>20)
		{
			Dynamx_Slide_Left_Interpolate(HEXSPD_MED,LEVEL5);
			if(Ping[PING_LEFT]>20)
			{
				Dynamx_Slide_Left_Interpolate(HEXSPD_MED,LEVEL5);
			}
		}

		SPRAY_CO2 = 1;
	}

	else if (FLAG_ROOM_4B == FLAG_ROOM_ACTIVE)
	{
		if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)
		{
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
		}

		BW_PID_Init_Room();
		BW_FollowCounter_Left(1);

		if(Ping[PING_LEFT]<12)
		{
			Dynamx_Slide_Right_Interpolate(HEXSPD_MED,LEVEL5);
		}

		SPRAY_CO2 = 1;
	}

	if ( SPRAY_CO2 == 1)
	{
		Dynamx_Rot_Left_IK(LEVEL6,STEP3);
		Dynamx_Rot_Right_IK(LEVEL6,STEP4);
		Dynamx_Rot_Right_IK(LEVEL6,STEP3);
		Dynamx_Rot_Left_IK(LEVEL6,STEP4);

//		BW_CO2_EXTINGUISH(30,250);
		SPRAY_CO2 = 0;
	}

	USART3_PutChar(NOT_IN_ROOM_STAT);
	Exit_No_Fire();
	Dynamx_Mov_Static_Interpolate(LEVEL5,IKCALC_ENABLE);
}

void H_In_Room_V3(void)
{
	USART3_PutChar(IN_ROOM_STAT);
	int m,l,cont=1;

	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"BHATARA WIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,1);sprintf(lcd,"LOCATION :");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"ROOM");lcd_putstr(lcd);

	if(FLAG_ROOM_4B==FLAG_ROOM_ACTIVE)
	{
		lcd_gotoxy(0,3);sprintf(lcd,"R4AB ACTIVE");lcd_putstr(lcd);
	}

	if(FLAG_ROOM_1C == FLAG_ROOM_ACTIVE)
	{
		BW_PID_Init();
		BW_FollowCounter_Right(3);
		Get_UV();
		if(UV_state==UVSTATE_ACTIVE)
		{
			FIRE=FIRE_ON;
			UV_Lock=UVLOCK_ACTIVE;
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
		}
		else
		{
			BW_FollowCounter_Right(3);
		}
		Get_UV();
		if(UV_state==UVSTATE_ACTIVE)
		{
			FIRE=FIRE_ON;
			UV_Lock=UVLOCK_ACTIVE;
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
		}
	}

	else if(FLAG_ROOM_1B==FLAG_ROOM_ACTIVE)
	{
		FLAG_ROOM_1B=FLAG_ROOM_INACTIVE;

		BW_FollowCounter_Right(3);
		Get_UV();
		if(UV_state==UVSTATE_ACTIVE)
		{
			FIRE=FIRE_ON;
			UV_Lock=UVLOCK_ACTIVE;
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
		}

		lcd_display_clear();
		for(l=0;l<=1;l++)
		{
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
			}
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL4, IKCALC_ENABLE);
		}
		FLAG_ROOM_1B=FLAG_ROOM_ACTIVE;
	}

	else if(FLAG_ROOM_3 == FLAG_ROOM_ACTIVE)
	{
		Get_UV();
		if(UV_state==UVSTATE_ACTIVE)
		{
			FIRE=FIRE_ON;
			UV_Lock=UVLOCK_ACTIVE;
			lcd_display_clear();
			lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
		}

		BW_PID_Init_Room();
		BW_FollowCounter_Left(3);

		Get_UV();
		if(UV_state==UVSTATE_INACTIVE)
		{
			Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
			Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
		}
		delay_ms(500);

		Get_UV();
		if(UV_state==UVSTATE_ACTIVE)
		{
			FIRE=FIRE_ON;
			UV_Lock=UVLOCK_ACTIVE;
			lcd_display_clear();
			lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
			delay_ms(50);
		}
		delay_ms(200);
		Get_UV();
		if(UV_state==UVSTATE_ACTIVE)
		{
			FIRE=FIRE_ON;
			UV_Lock=UVLOCK_ACTIVE;
			lcd_display_clear();
			lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
			delay_ms(50);
		}
		Get_UV();
		if(UV_state==UVSTATE_INACTIVE)
		{
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
		}
	}

	else if(FLAG_ROOM_2 == FLAG_ROOM_ACTIVE)
	{
		lcd_display_clear();

		Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);

		Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
		Get_UV();
		if(UV_state==UVSTATE_ACTIVE)
		{
			FIRE=FIRE_ON;
			UV_Lock=UVLOCK_ACTIVE;
			lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
			delay_ms(50);
		}

		if(UV_Lock == UVLOCK_INACTIVE || (UV_Lock == UVLOCK_ACTIVE && FlameSenseDigi[0] != 5 && FlameSenseDigi[0] != 6 && FlameSenseDigi[0] != 4))
		{
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL4);
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL4);
		}

		delay_ms(200);
		lcd_display_clear();

		Get_UV();
		if(UV_state==UVSTATE_ACTIVE)
		{
			FIRE=FIRE_ON;
			UV_Lock=UVLOCK_ACTIVE;
			lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
			delay_ms(50);
		}

		Get_UV();
		if(UV_state==UVSTATE_ACTIVE)
		{
			FIRE=FIRE_ON;
			UV_Lock=UVLOCK_ACTIVE;
			lcd_display_clear();
			lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
			delay_ms(50);
		}

		if(UV_Lock == UVLOCK_INACTIVE || (UV_Lock == UVLOCK_ACTIVE && FlameSenseDigi[0] != 5 && FlameSenseDigi[0] != 6 && FlameSenseDigi[0] != 4))
		{
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL4);
		}

		Get_UV();
		if(UV_state==UVSTATE_ACTIVE)
		{
			FIRE=FIRE_ON;
			UV_Lock=UVLOCK_ACTIVE;
			lcd_display_clear();
			lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
			delay_ms(50);
		}

		if(UV_Lock == UVLOCK_INACTIVE)
		{
			Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
		}
	}

	else
	{
		if(FLAG_ROOM_1A == FLAG_ROOM_ACTIVE)
		{
			BW_PID_Init_Room();
			BW_FollowCounter_Left(1);
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_display_clear();
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
			}

			else
			{
				BW_PID_Init_Room();
				BW_FollowCounter_Left(1);
			}
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_display_clear();
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
			}

			else
			{
				BW_PID_Init_Room();
				BW_FollowCounter_Left(1);
			}

			if(UV_Lock == UVLOCK_INACTIVE)
			{
				Dynamx_Rot_Right_Interpolate(LEVEL4, HEXSTEP_MED, IKCALC_DISABLE);
				Dynamx_Rot_Right_Interpolate(LEVEL4, HEXSTEP_MED, IKCALC_DISABLE);
				Get_UV();
				if(UV_state==UVSTATE_ACTIVE)
				{
					FIRE=FIRE_ON;
					UV_Lock=UVLOCK_ACTIVE;
					lcd_display_clear();
					lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				}

				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL4);
				Get_UV();
				if(UV_state==UVSTATE_ACTIVE)
				{
					FIRE=FIRE_ON;
					UV_Lock=UVLOCK_ACTIVE;
					lcd_display_clear();
					lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);

				}
				Dynamx_Rot_Left_Interpolate(LEVEL4, HEXSTEP_MED, IKCALC_DISABLE);

				delay_ms(100);

				Get_UV();
				if(UV_state==UVSTATE_ACTIVE)
				{
					FIRE=FIRE_ON;
					UV_Lock=UVLOCK_ACTIVE;
					lcd_display_clear();
					lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				}

				Dynamx_Rot_Left_Interpolate(LEVEL4, HEXSTEP_MED, IKCALC_DISABLE);
			}
			Get_UV();

			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_display_clear();
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
			}
		}
		Get_UV();
		if(UV_state==UVSTATE_ACTIVE)
		{
			FIRE=FIRE_ON;
			UV_Lock=UVLOCK_ACTIVE;
			lcd_display_clear();
			lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
		}
		delay_ms(100);

		lcd_display_clear();
		for(l=0;l<=1;l++)
		{
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_gotoxy(0,1);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
			}
			delay_ms(100);

			if(ROOM[2] == ROOM_4B || ROOM[2] == ROOM_4A)
			{
				Get_UV();
				if(UV_state==UVSTATE_ACTIVE)
				{
					FIRE=FIRE_ON;
					UV_Lock=UVLOCK_ACTIVE;
					lcd_gotoxy(0,1);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
					if(Ping[PING_FRONT] > 10)
					{
						Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
					}
				}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				while(TCS3200_SLV_DATA[1] == COLOUR_WHITE)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					BW_FollowCounter_Left(1);
				}
				if(UV_Lock == UVLOCK_ACTIVE && ((FlameSenseDigi[0] == 7) || (FlameSenseDigi[0] == 6) || (FlameSenseDigi[0] == 5)))
				{
					if(FlameSenseDigi[0] == 4 || FlameFrontDigi[0] == 4)
					{
						if(SHARP[SHARP_FRONT_L] > 30)
						{
							Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
						}
					}
					if(FlameSenseDigi[0] == 4 || FlameFrontDigi[0] == 4)
					{
						if(SHARP[SHARP_FRONT_L] > 30)
						{
							Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
						}
						break;
					}
					Dynamx_Rot_Right_Interpolate(LEVEL4, HEXSTEP_MED, IKCALC_DISABLE);
				}
				else if(UV_Lock == UVLOCK_INACTIVE)
				{
					Dynamx_MovFwd4cm_Interpolate(4,LEVEL6,IKCALC_DISABLE);
					if(Ping[PING_FRONT] > 15)
					{
						Dynamx_MovFwd4cm_Interpolate(4,LEVEL6,IKCALC_DISABLE);
					}

					if(Ping[PING_FRONT] > 15)
					{
						Dynamx_MovFwd4cm_Interpolate(4,LEVEL6,IKCALC_DISABLE);
					}
				}

			}
			if(Ping[PING_FRONT]<=25)break;
		}
	}

	if(UV_Lock==UVLOCK_INACTIVE)
	{
		if(FLAG_ROOM_1B == FLAG_ROOM_ACTIVE)
		{
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				delay_ms(50);
			}

			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				delay_ms(50);
			}

			Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);
			Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);

			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				delay_ms(50);
			}

			Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);

			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				delay_ms(50);
			}

			lcd_display_clear();
			for(m=0;m<=1;m++)
			{
				Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
				Get_UV();
				if(UV_state==UVSTATE_ACTIVE)
				{
					FIRE=FIRE_ON;
					UV_Lock=UVLOCK_ACTIVE;
					lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
					lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
					delay_ms(50);
				}
			}

			Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_MED,IKCALC_DISABLE);

			lcd_display_clear();
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				delay_ms(50);
			}
			Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_MED,IKCALC_DISABLE);

			lcd_display_clear();
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				delay_ms(50);
			}
			FLAG_ROOM_1B = FLAG_ROOM_ACTIVE;
		}

		if(FLAG_ROOM_1C == FLAG_ROOM_ACTIVE)
		{
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);

			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				delay_ms(50);
			}
			else
			{
				Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);
				Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);
			}

			lcd_display_clear();
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				delay_ms(50);
			}

			lcd_display_clear();
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				delay_ms(50);
			}
			else
			{
				Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
			}


			lcd_display_clear();
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				delay_ms(50);
			}
			FLAG_ROOM_1C = FLAG_ROOM_ACTIVE;
		}

		else if(FLAG_ROOM_4B == FLAG_ROOM_ACTIVE)
		{
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_display_clear();
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				delay_ms(50);
			}
			delay_ms(100);

			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_display_clear();
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				delay_ms(50);
			}

			Dynamx_Rot_Right_Interpolate(LEVEL3, HEXSTEP_MED, IKCALC_DISABLE);
			delay_ms(100);
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_display_clear();
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				delay_ms(50);
			}

			Dynamx_Rot_Left_Interpolate(LEVEL3, HEXSTEP_MED, IKCALC_DISABLE);
		}
	}

	if(FIRE==FIRE_ON)
	{
		EXTINGUISHER_OFF;
		UV_Lock=UVLOCK_ACTIVE;
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"BW");lcd_putstr(lcd);
		lcd_gotoxy(6,1);sprintf(lcd,"FIREFIGHT");lcd_putstr(lcd);
		delay_ms(100);

		if(FLAG_ROOM_1B == FLAG_ROOM_ACTIVE)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"SP FIRE 1B");lcd_putstr(lcd);

			if((FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==6) || (FlameSenseDigi[0]==7))
			{
				FIRESCAN_DIRECTION=SCAN_RIGHT;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"SCAN RIGHT");lcd_putstr(lcd);
				delay_ms(100);
			}
			else
			{
				FIRESCAN_DIRECTION=SCAN_LEFT;

				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"SCAN LEFT");lcd_putstr(lcd);
				delay_ms(100);

				if(Ping[PING_FRONT]<20)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
					Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
				}
				else
				{
					Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
					Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
					Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_MED,IKCALC_DISABLE);
				}

				FIRESCAN_DIRECTION=SCAN_LEFT;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"SCAN LEFT");lcd_putstr(lcd);
				delay_ms(100);
			}
				FLAG_ROOM_1B = FLAG_ROOM_ACTIVE;
		}
		else if(FLAG_ROOM_1C == FLAG_ROOM_ACTIVE)
		{
			FIRESCAN_DIRECTION=SCAN_LEFT;
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"SP FIRE 1C");lcd_putstr(lcd);
			delay_ms(100);

			Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

			if((FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==2) || (FlameFrontDigi[0]==4))
			{
				Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
			}
			else
			{

			Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);

			if((FlameSenseDigi[0]!=2) || (FlameSenseDigi[0]!=1))
			{
				Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

				if((FlameSenseDigi[0]==2) || (FlameSenseDigi[0]==1))
				{
					Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
					Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_CLOSE,IKCALC_DISABLE);

					Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
					Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);

					FIRESCAN_DIRECTION=SCAN_LEFT;
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"SP FIRE 1C");lcd_putstr(lcd);
					delay_ms(50);
				}
				else
				{
					Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
					Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
					Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);

					if((Ping[PING_FRONT]<30) || (Ping[PING_RIGHT]>20))
					{
						Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
						Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
					}
				}
			}
			}

			FLAG_ROOM_1C = FLAG_ROOM_ACTIVE;
		}
		else if(FLAG_ROOM_1A == FLAG_ROOM_ACTIVE)
		{
			FIRESCAN_DIRECTION=SCAN_RIGHT;
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"SP FIRE 1A");lcd_putstr(lcd);

			if((FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==2))
			{

			}
			else
			{
				int z = 0;
				if(FlameSenseDigi[0]!=4)
				{
/*					Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);*/

					if(z==0 && (Ping[PING_RIGHT] > 10 && Ping[PING_ASKEW_RIGHT] > 10))Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
//					if((FlameSenseDigi[0]==4 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 5) && z == 0)z=1;
					if(z==0 && (Ping[PING_RIGHT] > 10 && Ping[PING_ASKEW_RIGHT] > 10))Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
//					if((FlameSenseDigi[0]==4 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 5) && z == 0)z=1;
					if(z==0 && (Ping[PING_RIGHT] > 10 && Ping[PING_ASKEW_RIGHT] > 10))Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
//					if((FlameSenseDigi[0]==4 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 5) && z == 0)z=1;
					if(z==0 && (Ping[PING_RIGHT] > 10 && Ping[PING_ASKEW_RIGHT] > 10))Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
//					if((FlameSenseDigi[0]==4 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 5) && z == 0)z=1;
					if(z==0 && (Ping[PING_RIGHT] > 10 && Ping[PING_ASKEW_RIGHT] > 10))Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
//					if((FlameSenseDigi[0]==4 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 5) && z == 0)z=1;
					if(z==0 && (Ping[PING_RIGHT] > 10 && Ping[PING_ASKEW_RIGHT] > 10))Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
				}

				if((FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==2) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==5))
				{
					FIRESCAN_DIRECTION=SCAN_RIGHT;
				}
				else
				{
//					Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_MED,IKCALC_DISABLE);
					if((FlameSenseDigi[0]==7) || (FlameSenseDigi[0]==6) || (FlameSenseDigi[0]==5))
					{
						if((FlameSenseDigi[0]==7) || (FlameSenseDigi[0]==6)|| (FlameSenseDigi[0]==5))
						{
//							Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);

							FIRESCAN_DIRECTION=SCAN_RIGHT;
/*							if(z==0 && (Ping[PING_LEFT] > 10 && Ping[PING_ASKEW_LEFT] > 10))Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
//							if((FlameSenseDigi[0]==4 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 5) && z == 0)z=1;
							if(z==0 && (Ping[PING_LEFT] > 10 && Ping[PING_ASKEW_LEFT] > 10))Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
//							if((FlameSenseDigi[0]==4 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 5) && z == 0)z=1;
							if(z==0 && (Ping[PING_LEFT] > 10 && Ping[PING_ASKEW_LEFT] > 10))Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
//							if((FlameSenseDigi[0]==4 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 5) && z == 0)z=1;
							if(z==0 && (Ping[PING_LEFT] > 10 && Ping[PING_ASKEW_LEFT] > 10))Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
//							if((FlameSenseDigi[0]==4 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 5) && z == 0)z=1;
							if(z==0 && (Ping[PING_LEFT] > 10 && Ping[PING_ASKEW_LEFT] > 10))Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);*/
						}

						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
						lcd_gotoxy(0,1);sprintf(lcd,"SP FIRE 1A");lcd_putstr(lcd);
						delay_ms(50);
					}
					else
					{
						z=0;
//						Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_CLOSE,IKCALC_DISABLE);
						if(FlameSenseDigi[0]!=4)
						{
							if(z==0 && (Ping[PING_LEFT] > 10 && Ping[PING_ASKEW_LEFT] > 10))Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
//							if((FlameSenseDigi[0]==4 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 5) && z == 0)z=1;
							if(z==0 && (Ping[PING_LEFT] > 10 && Ping[PING_ASKEW_LEFT] > 10))Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
//							if((FlameSenseDigi[0]==4 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 5) && z == 0)z=1;
							if(z==0 && (Ping[PING_LEFT] > 10 && Ping[PING_ASKEW_LEFT] > 10))Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
//							if((FlameSenseDigi[0]==4 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 5) && z == 0)z=1;
							if(z==0 && (Ping[PING_LEFT] > 10 && Ping[PING_ASKEW_LEFT] > 10))Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
//							if((FlameSenseDigi[0]==4 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 5) && z == 0)z=1;
							if(z==0 && (Ping[PING_LEFT] > 10 && Ping[PING_ASKEW_LEFT] > 10))Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
							if(Ping[PING_LEFT]>15)
							{
								Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
								if(Ping[PING_LEFT]>15)
								{
									Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
								}
							}
						}
						if(FlameSenseDigi[0]!=4)
						{
							//Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
						}
					}
				}
			}
			FIREROOM_R1A_FLAG=FIREROOM_R1A_ACTIVE;
		}
		else if(SP_FIRE_R3==SP_FIRE_ACTIVE)
		{
			FIRESCAN_DIRECTION=SCAN_RIGHT;
			int CNT_R3=0;

			BW_PID_Init_Furniture();
			lcd_display_clear();
			while((FlameSenseDigi[0]!=6) && (FlameSenseDigi[0]!=5) && (FlameSenseDigi[0]!=7) && (CNT_R3 < 10))
			{
				if((FlameSenseDigi[0]==6) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==7) || (FlameSenseDigi[0]==4))break;
				if((Ping[PING_FRONT]>15) && (CNT_R3 < 5))
				{
					lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"SP FIRE R3");lcd_putstr(lcd);

					BW_FollowCounter_Left(1);
					if((FlameSenseDigi[0]==3)||(FlameSenseDigi[0]==2) || (FlameSenseDigi[0]==4)){Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_MED,IKCALC_DISABLE);break;}
				}
				else
				{
					lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"SP FIRE R3");lcd_putstr(lcd);

					BW_FollowCounter_Left(1);
					if(CNT_R3>5 && FlameSenseDigi[0]!=0)break;// || FlameSenseDigi[0]==5 || FlameSenseDigi[0]==3))break;
				}
				CNT_R3++;
			}
		}
		else
		{
			FIRESCAN_DIRECTION=SCAN_RIGHT;
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"SCAN RIGHT");lcd_putstr(lcd);
			delay_ms(100);

			if(FIREROOM_R4AB_FLAG != FIREROOM_R4AB_ACTIVE)
			{
				Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
			}
		}

		//============================//
		//		EXTINGUISH ROUTINE	  //
		//============================//

		BW_FireFight_V2();

		//============================//

//=======APRIL, 27th 2017======//
//		RoomTypeDetector();

		USART3_PutChar(NOT_IN_ROOM_STAT);
		FIRE_LED_BLINK_OFF;
		FIRE_LED_OFF;
		FIRE=FIRE_SUCCESS;



		//old ALGORITHM
//		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//===============================================================

		Dynamx_Mov_Static_Interpolate(LEVEL5,IKCALC_ENABLE);
		delay_ms(50);
		Dynamx_MovBwd_Interpolate(4,LEVEL4,IKCALC_ENABLE);

		if ((ROOM[2]==ROOM_4A) || (ROOM[2]==ROOM_4B) || (ROOM[2]==ROOM_3))// || (ROOM[2]==ROOM_2A) || (ROOM[2]==ROOM_2B))
		{
			FOLLOW_FLAG=KANAN;
			if(ROOM[2] == ROOM_3)
			{
				Nav_TurnAround(TURN_LEFT);
				BW_FollowTracer_Right_Interpolate();
				if(Ping[PING_FRONT] > 13)
				{
					Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
				}
				if(Ping[PING_FRONT] > 13)
				{
					Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
				}
			}
			else if(ROOM[2] == ROOM_4A)
			{
				if(Ping[PING_LEFT] < Ping[PING_RIGHT])
				{
					Nav_TurnAround(TURN_LEFT);
					BW_PID_Init();
					BW_FollowTracer_Right_Interpolate();
				}
				else
				{
					Nav_TurnAround(TURN_RIGHT);
					BW_PID_Init();
					BW_FollowTracer_Left_Interpolate();
				}
			}

			else if(ROOM[2] == ROOM_4B)
			{
				if(Ping[PING_LEFT] < Ping[PING_RIGHT])
				{
					Nav_TurnAround(TURN_LEFT);
					BW_PID_Init();
					BW_FollowTracer_Right_Interpolate();
				}
				else
				{
					Nav_TurnAround(TURN_RIGHT);
					BW_PID_Init();
					BW_FollowTracer_Left_Interpolate();
				}
			}

			if((Ping[PING_RIGHT]+4)<(Ping[PING_REAR_RIGHT]))
			{
				Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_RIGHT]+4)<(Ping[PING_REAR_RIGHT]))
				{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				}
			}
		}
		else if ((ROOM[2]==ROOM_2A) || (ROOM[2]==ROOM_2B))
		{
			Nav_TurnAround(TURN_LEFT);
			BW_PID_Init();
			BW_FollowTracer_Right_Interpolate();
			Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
		}

		else if (ROOM[2]==ROOM_1C)
		{
			FOLLOW_FLAG=/*KANAN*/KIRI;

			GetCMPS11_Angle8Bit();
			if(ROOM_1A_RETURN_MANUAL == 0)
			{
//				COMPASS_INTERRUPT = 1;
				if((CMPS11_Angle>(START_MIDDLE)))
				{
					while((CMPS11_Angle>(START_MIDDLE)))
					{
						GetCMPS11_Angle8Bit();
						if(CMPS11_Angle < START_MIDDLE)break;
						Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"POS : MIDDLE");lcd_putstr(lcd);
						lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
						GetCMPS11_Angle8Bit();
						if(CMPS11_Angle < START_MIDDLE)break;

					}

					if(CMPS11_Angle < START_MIDDLE)
					{
						while(CMPS11_Angle < START_MIDDLE)
						{
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle > START_MIDDLE)break;
							Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"CORRECTION 1");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle > START_MIDDLE)break;
						}
					}

					if(CMPS11_Angle > START_MIDDLE)
					{
						while(CMPS11_Angle > START_MIDDLE)
						{
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle == START_MIDDLE)break;
							Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"CORRECTION 2");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
								GetCMPS11_Angle8Bit();
							if(CMPS11_Angle == START_MIDDLE)break;
						}
						//GetCMPS11_Angle8Bit();
					}
				}
				else if(((CMPS11_Angle<(START_MIDDLE))))
				{
					while((CMPS11_Angle<(START_MIDDLE))&&(CMPS11_Angle>R4A_THRESHOLD_MIDDLE))
					{
						GetCMPS11_Angle8Bit();
						Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"POS : MIDDLE");lcd_putstr(lcd);
						lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
						GetCMPS11_Angle8Bit();

					}

					if(CMPS11_Angle > START_MIDDLE)
					{
						while(CMPS11_Angle > START_MIDDLE)
						{
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle < START_MIDDLE)break;
							Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"CORECTION 1");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle < START_MIDDLE)break;
						}

					}

					if(CMPS11_Angle < START_MIDDLE)
					{
						while(CMPS11_Angle < START_MIDDLE)
						{
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle == START_MIDDLE)break;
							Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"CORECTION 2");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle == START_MIDDLE)break;
						}
					}
				}

			}
//			COMPASS_INTERRUPT = 0;

			int stat = 0;
			if(ROOM_1A_RETURN_MANUAL == 0)
			{
			while(Ping[PING_FRONT]>15 && SHARP[SHARP_FRONT_L] > 12 && Ping[PING_UP_LEFT] > 12 && Ping[PING_UP_RIGHT] > 12)
			{
				Furniture_Avoider();
				Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
			}
			}
			else
			{
				Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
			}

			BW_PID_Init_FAR();

			BW_FollowTracer_Left_Interpolate();
			Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[0] == COLOUR_WHITE)
			{
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
			}

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[0] == COLOUR_WHITE)
			{
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
			}

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[0] == COLOUR_WHITE)
			{
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
			}
		}

		else if (ROOM[2]==ROOM_1B)
		{
			FOLLOW_FLAG=/*KANAN*/KIRI;

			GetCMPS11_Angle8Bit();
			if(ROOM_1A_RETURN_MANUAL == 0)
			{
				if((CMPS11_Angle>(START_MIDDLE)))
				{
					while((CMPS11_Angle>(START_MIDDLE)))
					{
						GetCMPS11_Angle8Bit();
						if(CMPS11_Angle < START_MIDDLE)break;
						Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"POS : MIDDLE");lcd_putstr(lcd);
						lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
						GetCMPS11_Angle8Bit();
						if(CMPS11_Angle < START_MIDDLE)break;

					}

					if(CMPS11_Angle < START_MIDDLE)
					{
						while(CMPS11_Angle < START_MIDDLE)
						{
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle > START_MIDDLE)break;
							Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"CORRECTION 1");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle > START_MIDDLE)break;
						}
					}

					if(CMPS11_Angle > START_MIDDLE)
					{
						while(CMPS11_Angle > START_MIDDLE)
						{
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle == START_MIDDLE)break;
							Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"CORRECTION 2");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle == START_MIDDLE)break;
						}
						//GetCMPS11_Angle8Bit();
					}
				}
				else if(((CMPS11_Angle<(START_MIDDLE))))
				{
					while((CMPS11_Angle<(START_MIDDLE))&&(CMPS11_Angle>R4A_THRESHOLD_MIDDLE))
					{
						GetCMPS11_Angle8Bit();
						Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"POS : MIDDLE");lcd_putstr(lcd);
						lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
						GetCMPS11_Angle8Bit();

					}

					if(CMPS11_Angle > START_MIDDLE)
					{
						while(CMPS11_Angle > START_MIDDLE)
						{
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle < START_MIDDLE)break;
							Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"CORECTION 1");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle < START_MIDDLE)break;
						}

					}

					if(CMPS11_Angle < START_MIDDLE)
					{
						while(CMPS11_Angle < START_MIDDLE)
						{
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle == START_MIDDLE)break;
							Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"CORECTION 2");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle == START_MIDDLE)break;
						}
					}
				}
			}

			int stat = 0;;
			if(ROOM_1A_RETURN_MANUAL == 0)
			{
			while(Ping[PING_FRONT]>15 && SHARP[SHARP_FRONT_L] > 12 && Ping[PING_UP_LEFT] > 12 && Ping[PING_UP_RIGHT] > 12)
			{
				Furniture_Avoider();

				Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
			}
			}
			BW_FollowTracer_Left_Interpolate();
			Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[0] == COLOUR_WHITE)
			{
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
			}

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[0] == COLOUR_WHITE)
			{
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
			}

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[0] == COLOUR_WHITE)
			{
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
			}
		}

		else if (ROOM[2]==ROOM_1A)
		{

			FOLLOW_FLAG=KANAN;

			if(ROOM_1A_RETURN_MANUAL == 0)
			{
				GetCMPS11_Angle8Bit();
				COMPASS_INTERRUPT = 1;
				if((CMPS11_Angle>(START_MIDDLE)))
				{
					while((CMPS11_Angle>(START_MIDDLE)))
					{
						GetCMPS11_Angle8Bit();
						if(CMPS11_Angle < START_MIDDLE)break;
						Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"POS : MIDDLE");lcd_putstr(lcd);
						lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
						GetCMPS11_Angle8Bit();
						if(CMPS11_Angle < START_MIDDLE)break;
					}

					if(CMPS11_Angle < START_MIDDLE)
					{
						while(CMPS11_Angle < START_MIDDLE)
						{
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle > START_MIDDLE)break;
							Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"CORRECTION 1");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle > START_MIDDLE)break;
						}
					}

					if(CMPS11_Angle > START_MIDDLE)
					{
						while(CMPS11_Angle > START_MIDDLE)
						{
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle == START_MIDDLE)break;
							Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"CORRECTION 2");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle == START_MIDDLE)break;
						}
					}
				}
				else if(((CMPS11_Angle<(START_MIDDLE))))
				{
					while((CMPS11_Angle<(START_MIDDLE))&&(CMPS11_Angle>R4A_THRESHOLD_MIDDLE))
					{
						GetCMPS11_Angle8Bit();
						Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"POS : MIDDLE");lcd_putstr(lcd);
						lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
						GetCMPS11_Angle8Bit();
					}

					if(CMPS11_Angle > START_MIDDLE)
					{
						while(CMPS11_Angle > START_MIDDLE)
						{
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle < START_MIDDLE)break;
							Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"CORECTION 1");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle < START_MIDDLE)break;
						}

					}

					if(CMPS11_Angle < START_MIDDLE)
					{
						while(CMPS11_Angle < START_MIDDLE)
						{
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle == START_MIDDLE)break;
							Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"CORECTION 2");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle == START_MIDDLE)break;
						}
					}
				}
			}

			if(ROOM_1A_RETURN_MANUAL == 0)
			{
			int stat = 0;
			while(Ping[PING_FRONT]>15 && SHARP[SHARP_FRONT_L] > 12 && Ping[PING_UP_LEFT] > 12 && Ping[PING_UP_RIGHT] > 12)
			{
				Furniture_Avoider();

				Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
			}
			}

			BW_PID_Init_FAR();
			BW_FollowTracer_Left_Interpolate();
			Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[0] == COLOUR_WHITE)
			{
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
			}

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[0] == COLOUR_WHITE)
			{
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
			}

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[0] == COLOUR_WHITE)
			{
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
			}
		}

		else if(
				(Ping[PING_LEFT]+Ping[PING_ASKEW_LEFT]+Ping[PING_REAR_LEFT])
				<
				(Ping[PING_RIGHT]+Ping[PING_ASKEW_RIGHT]+Ping[PING_REAR_RIGHT])
			)
		{
			FOLLOW_FLAG=KANAN;
			Nav_TurnAround(TURN_LEFT);
			BW_PID_Init();
			BW_FollowTracer_Right_Interpolate();

		}
		else
		{
			FOLLOW_FLAG=KIRI;
			Nav_TurnAround(TURN_RIGHT);
			BW_PID_Init();
			BW_FollowTracer_Left_Interpolate();
		}
//		End of changes
//		Some codes was omitted in this changes
//===============================================================
	}

	else
	{
		USART3_PutChar(NOT_IN_ROOM_STAT);
		FIRE=FIRE_OFF;
		Exit_No_Fire();
		if(ROOM4AB_FLAG==ROOM4AB_ACTIVE)
		{
			ROOM4AB_FLAG=ROOM4AB_INACTIVE;
		}
	}
}

void H_2021_Room (void)
{
	USART3_PutChar(IN_ROOM_STAT);
	int m,l,cont=1;

	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"BHATARA WIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,1);sprintf(lcd,"LOCATION :");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"ROOM");lcd_putstr(lcd);

	if(ROOM4AB_FLAG==ROOM4AB_ACTIVE)
	{
		lcd_gotoxy(0,3);sprintf(lcd,"R4AB ACTIVE");lcd_putstr(lcd);
	}

	if(SP_FIRE_1C == SP_FIRE_ACTIVE)
	{
		BW_PID_Init();
		BW_FollowCounter_Right(3);
		Get_UV();
		if(UV_state==UVSTATE_ACTIVE)
		{
			FIRE=FIRE_ON;
			UV_Lock=UVLOCK_ACTIVE;
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
		}
		else
		{
			BW_FollowCounter_Right(3);
		}
		Get_UV();
		if(UV_state==UVSTATE_ACTIVE)
		{
			FIRE=FIRE_ON;
			UV_Lock=UVLOCK_ACTIVE;
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
		}
	}

	else if(SP_FIRE_1B==SP_FIRE_ACTIVE)
	{
		SP_FIRE_1B=SP_FIRE_INACTIVE;

		BW_FollowCounter_Right(3);
		Get_UV();
		if(UV_state==UVSTATE_ACTIVE)
		{
			FIRE=FIRE_ON;
			UV_Lock=UVLOCK_ACTIVE;
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
		}

		lcd_display_clear();
		for(l=0;l<=1;l++)
		{
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
			}
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL4, IKCALC_ENABLE);
		}
		SP_FIRE_1B=SP_FIRE_ACTIVE;
	}

	else if(SP_FIRE_R3 == SP_FIRE_ACTIVE)
	{
		Get_UV();
		if(UV_state==UVSTATE_ACTIVE)
		{
			FIRE=FIRE_ON;
			UV_Lock=UVLOCK_ACTIVE;
			lcd_display_clear();
			lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
		}

		BW_PID_Init_Room();
		BW_FollowCounter_Left(3);
		Get_UV();
		if(UV_state==UVSTATE_INACTIVE)
		{
			Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
			Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
		}
		delay_ms(500);
		Get_UV();
		if(UV_state==UVSTATE_ACTIVE)
		{
			FIRE=FIRE_ON;
			UV_Lock=UVLOCK_ACTIVE;
			lcd_display_clear();
			lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
			delay_ms(50);
		}
		delay_ms(200);
		Get_UV();
		if(UV_state==UVSTATE_ACTIVE)
		{
			FIRE=FIRE_ON;
			UV_Lock=UVLOCK_ACTIVE;
			lcd_display_clear();
			lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
			delay_ms(50);
		}
		Get_UV();
		if(UV_state==UVSTATE_INACTIVE)
		{
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
		}
	}

	else if(UV_R2FLAG==UV_R2FLAG_ACTIVE)
	{
		lcd_display_clear();

		Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);

		Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
		Get_UV();
		if(UV_state==UVSTATE_ACTIVE)
		{
			FIRE=FIRE_ON;
			UV_Lock=UVLOCK_ACTIVE;
			lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
			delay_ms(50);
		}

		if(UV_Lock == UVLOCK_INACTIVE || (UV_Lock == UVLOCK_ACTIVE && FlameSenseDigi[0] != 5 && FlameSenseDigi[0] != 6 && FlameSenseDigi[0] != 4))
		{
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL4);
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL4);
		}

		delay_ms(200);
		lcd_display_clear();
		Get_UV();
		if(UV_state==UVSTATE_ACTIVE)
		{
			FIRE=FIRE_ON;
			UV_Lock=UVLOCK_ACTIVE;
			lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
			delay_ms(50);
		}
		Get_UV();
		if(UV_state==UVSTATE_ACTIVE)
		{
			FIRE=FIRE_ON;
			UV_Lock=UVLOCK_ACTIVE;
			lcd_display_clear();
			lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
			delay_ms(50);
		}

		if(UV_Lock == UVLOCK_INACTIVE || (UV_Lock == UVLOCK_ACTIVE && FlameSenseDigi[0] != 5 && FlameSenseDigi[0] != 6 && FlameSenseDigi[0] != 4))
		{
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL4);
		}
		Get_UV();
		if(UV_state==UVSTATE_ACTIVE)
		{
			FIRE=FIRE_ON;
			UV_Lock=UVLOCK_ACTIVE;
			lcd_display_clear();
			lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
			delay_ms(50);
		}

		if(UV_Lock == UVLOCK_INACTIVE)
		{
			Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
		}
	}

	else
	{
		if(FIREROOM_R1A_FLAG == FIREROOM_R1A_ACTIVE)
		{
			BW_PID_Init_Room();
			BW_FollowCounter_Left(1);
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_display_clear();
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
			}

			else
			{
				BW_PID_Init_Room();
				BW_FollowCounter_Left(1);
			}
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_display_clear();
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
			}

			else
			{
				BW_PID_Init_Room();
				BW_FollowCounter_Left(1);
			}

			if(UV_Lock == UVLOCK_INACTIVE)
			{
				Dynamx_Rot_Right_Interpolate(LEVEL4, HEXSTEP_MED, IKCALC_DISABLE);
				Dynamx_Rot_Right_Interpolate(LEVEL4, HEXSTEP_MED, IKCALC_DISABLE);
				Get_UV();
				if(UV_state==UVSTATE_ACTIVE)
				{
					FIRE=FIRE_ON;
					UV_Lock=UVLOCK_ACTIVE;
					lcd_display_clear();
					lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				}

				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL4);
				Get_UV();
				if(UV_state==UVSTATE_ACTIVE)
				{
					FIRE=FIRE_ON;
					UV_Lock=UVLOCK_ACTIVE;
					lcd_display_clear();
					lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);

				}
				Dynamx_Rot_Left_Interpolate(LEVEL4, HEXSTEP_MED, IKCALC_DISABLE);

				delay_ms(100);

				Get_UV();
				if(UV_state==UVSTATE_ACTIVE)
				{
					FIRE=FIRE_ON;
					UV_Lock=UVLOCK_ACTIVE;
					lcd_display_clear();
					lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				}

				Dynamx_Rot_Left_Interpolate(LEVEL4, HEXSTEP_MED, IKCALC_DISABLE);
			}
			Get_UV();

			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_display_clear();
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
			}
		}
		Get_UV();
		if(UV_state==UVSTATE_ACTIVE)
		{
			FIRE=FIRE_ON;
			UV_Lock=UVLOCK_ACTIVE;
			lcd_display_clear();
			lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
		}
		delay_ms(100);

		lcd_display_clear();
		for(l=0;l<=1;l++)
		{
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_gotoxy(0,1);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
			}
			delay_ms(100);

			if(ROOM[2] == ROOM_4B || ROOM[2] == ROOM_4A)
			{
				Get_UV();
				if(UV_state==UVSTATE_ACTIVE)
				{
					FIRE=FIRE_ON;
					UV_Lock=UVLOCK_ACTIVE;
					lcd_gotoxy(0,1);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
					if(Ping[PING_FRONT] > 10)
					{
						Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
					}
				}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				while(TCS3200_SLV_DATA[1] == COLOUR_WHITE)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					BW_FollowCounter_Left(1);
				}
				if(UV_Lock == UVLOCK_ACTIVE && ((FlameSenseDigi[0] == 7) || (FlameSenseDigi[0] == 6) || (FlameSenseDigi[0] == 5)))
				{
					if(FlameSenseDigi[0] == 4 || FlameFrontDigi[0] == 4)
					{
						if(SHARP[SHARP_FRONT_L] > 30)
						{
							Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
						}
					}
					if(FlameSenseDigi[0] == 4 || FlameFrontDigi[0] == 4)
					{
						if(SHARP[SHARP_FRONT_L] > 30)
						{
							Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
						}
						break;
					}
					Dynamx_Rot_Right_Interpolate(LEVEL4, HEXSTEP_MED, IKCALC_DISABLE);
				}
				else if(UV_Lock == UVLOCK_INACTIVE)
				{
					Dynamx_MovFwd4cm_Interpolate(4,LEVEL6,IKCALC_DISABLE);
					if(Ping[PING_FRONT] > 15)
					{
						Dynamx_MovFwd4cm_Interpolate(4,LEVEL6,IKCALC_DISABLE);
					}

					if(Ping[PING_FRONT] > 15)
					{
						Dynamx_MovFwd4cm_Interpolate(4,LEVEL6,IKCALC_DISABLE);
					}
				}

			}
			if(Ping[PING_FRONT]<=25)break;
		}
	}

	if(UV_Lock==UVLOCK_INACTIVE)
	{
		if(SP_FIRE_1B==SP_FIRE_ACTIVE)
		{
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				delay_ms(50);
			}

			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				delay_ms(50);
			}

			Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);
			Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				delay_ms(50);
			}

			Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				delay_ms(50);
			}

			lcd_display_clear();
			for(m=0;m<=1;m++)
			{
				Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
				Get_UV();
				if(UV_state==UVSTATE_ACTIVE)
				{
					FIRE=FIRE_ON;
					UV_Lock=UVLOCK_ACTIVE;
					lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
					lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
					delay_ms(50);
				}
			}

			Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_MED,IKCALC_DISABLE);


			lcd_display_clear();
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				delay_ms(50);
			}
			Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_MED,IKCALC_DISABLE);


			lcd_display_clear();
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				delay_ms(50);
			}
			SP_FIRE_1B=SP_FIRE_ACTIVE;

		}

		if(SP_FIRE_1C == SP_FIRE_ACTIVE)
		{

			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);

			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				delay_ms(50);
			}
			else
			{
				Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);
				Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);
			}

			lcd_display_clear();
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				delay_ms(50);
			}

			lcd_display_clear();
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				delay_ms(50);
			}
			else
			{
				Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
			}


			lcd_display_clear();
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				delay_ms(50);
			}
			SP_FIRE_1C = SP_FIRE_ACTIVE;
		}

		else if(ROOM4AB_FLAG == ROOM4AB_ACTIVE)
		{
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_display_clear();
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				delay_ms(50);
			}
			delay_ms(100);

			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_display_clear();
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				delay_ms(50);
			}

			Dynamx_Rot_Right_Interpolate(LEVEL3, HEXSTEP_MED, IKCALC_DISABLE);
			delay_ms(100);
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_display_clear();
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				delay_ms(50);
			}

			Dynamx_Rot_Left_Interpolate(LEVEL3, HEXSTEP_MED, IKCALC_DISABLE);
		}
	}

	if(FIRE==FIRE_ON)
	{
		EXTINGUISHER_OFF;
		UV_Lock=UVLOCK_ACTIVE;
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"BW");lcd_putstr(lcd);
		lcd_gotoxy(6,1);sprintf(lcd,"FIREFIGHT");lcd_putstr(lcd);
		delay_ms(100);

		if(SP_FIRE_1B==SP_FIRE_ACTIVE)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"SP FIRE 1B");lcd_putstr(lcd);

			if((FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==6) || (FlameSenseDigi[0]==7))
			{
				FIRESCAN_DIRECTION=SCAN_RIGHT;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"SCAN RIGHT");lcd_putstr(lcd);
				delay_ms(100);
			}
			else
			{
				FIRESCAN_DIRECTION=SCAN_LEFT;

				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"SCAN LEFT");lcd_putstr(lcd);
				delay_ms(100);

				if(Ping[PING_FRONT]<20)
				{
					Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
					Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
				}
				else
				{
					Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
					Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
					Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_MED,IKCALC_DISABLE);
				}

				FIRESCAN_DIRECTION=SCAN_LEFT;
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"SCAN LEFT");lcd_putstr(lcd);
				delay_ms(100);
			}
				SP_FIRE_1B=SP_FIRE_ACTIVE;
		}
		else if(SP_FIRE_1C==SP_FIRE_ACTIVE)
		{
			FIRESCAN_DIRECTION=SCAN_LEFT;
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"SP FIRE 1C");lcd_putstr(lcd);
			delay_ms(100);

			Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

			if((FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==2) || (FlameFrontDigi[0]==4))
			{
				Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
			}
			else
			{

			Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);

			if((FlameSenseDigi[0]!=2) || (FlameSenseDigi[0]!=1))
			{
				Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);

				if((FlameSenseDigi[0]==2) || (FlameSenseDigi[0]==1))
				{
					Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
					Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_CLOSE,IKCALC_DISABLE);

					Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
					Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);

					FIRESCAN_DIRECTION=SCAN_LEFT;
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"SP FIRE 1C");lcd_putstr(lcd);
					delay_ms(50);
				}
				else
				{
					Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
					Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
					Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);

					if((Ping[PING_FRONT]<30) || (Ping[PING_RIGHT]>20))
					{
						Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
						Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
					}
				}
			}
			}

			SP_FIRE_1C=SP_FIRE_ACTIVE;
		}
		else if(FIREROOM_R1A_FLAG==FIREROOM_R1A_ACTIVE)
		{
			FIRESCAN_DIRECTION=SCAN_RIGHT;
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"SP FIRE 1A");lcd_putstr(lcd);

			if((FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==2))
			{

			}
			else
			{
				int z = 0;
				if(FlameSenseDigi[0]!=4)
				{
/*					Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);*/

					if(z==0 && (Ping[PING_RIGHT] > 10 && Ping[PING_ASKEW_RIGHT] > 10))Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
//					if((FlameSenseDigi[0]==4 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 5) && z == 0)z=1;
					if(z==0 && (Ping[PING_RIGHT] > 10 && Ping[PING_ASKEW_RIGHT] > 10))Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
//					if((FlameSenseDigi[0]==4 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 5) && z == 0)z=1;
					if(z==0 && (Ping[PING_RIGHT] > 10 && Ping[PING_ASKEW_RIGHT] > 10))Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
//					if((FlameSenseDigi[0]==4 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 5) && z == 0)z=1;
					if(z==0 && (Ping[PING_RIGHT] > 10 && Ping[PING_ASKEW_RIGHT] > 10))Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
//					if((FlameSenseDigi[0]==4 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 5) && z == 0)z=1;
					if(z==0 && (Ping[PING_RIGHT] > 10 && Ping[PING_ASKEW_RIGHT] > 10))Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
//					if((FlameSenseDigi[0]==4 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 5) && z == 0)z=1;
					if(z==0 && (Ping[PING_RIGHT] > 10 && Ping[PING_ASKEW_RIGHT] > 10))Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
				}

				if((FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==2) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==5))
				{
					FIRESCAN_DIRECTION=SCAN_RIGHT;
				}
				else
				{
//					Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_MED,IKCALC_DISABLE);
					if((FlameSenseDigi[0]==7) || (FlameSenseDigi[0]==6) || (FlameSenseDigi[0]==5))
					{
						if((FlameSenseDigi[0]==7) || (FlameSenseDigi[0]==6)|| (FlameSenseDigi[0]==5))
						{
//							Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);

							FIRESCAN_DIRECTION=SCAN_RIGHT;
/*							if(z==0 && (Ping[PING_LEFT] > 10 && Ping[PING_ASKEW_LEFT] > 10))Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
//							if((FlameSenseDigi[0]==4 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 5) && z == 0)z=1;
							if(z==0 && (Ping[PING_LEFT] > 10 && Ping[PING_ASKEW_LEFT] > 10))Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
//							if((FlameSenseDigi[0]==4 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 5) && z == 0)z=1;
							if(z==0 && (Ping[PING_LEFT] > 10 && Ping[PING_ASKEW_LEFT] > 10))Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
//							if((FlameSenseDigi[0]==4 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 5) && z == 0)z=1;
							if(z==0 && (Ping[PING_LEFT] > 10 && Ping[PING_ASKEW_LEFT] > 10))Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
//							if((FlameSenseDigi[0]==4 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 5) && z == 0)z=1;
							if(z==0 && (Ping[PING_LEFT] > 10 && Ping[PING_ASKEW_LEFT] > 10))Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);*/
						}

						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
						lcd_gotoxy(0,1);sprintf(lcd,"SP FIRE 1A");lcd_putstr(lcd);
						delay_ms(50);
					}
					else
					{
						z=0;
//						Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_CLOSE,IKCALC_DISABLE);
						if(FlameSenseDigi[0]!=4)
						{
							if(z==0 && (Ping[PING_LEFT] > 10 && Ping[PING_ASKEW_LEFT] > 10))Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
//							if((FlameSenseDigi[0]==4 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 5) && z == 0)z=1;
							if(z==0 && (Ping[PING_LEFT] > 10 && Ping[PING_ASKEW_LEFT] > 10))Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
//							if((FlameSenseDigi[0]==4 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 5) && z == 0)z=1;
							if(z==0 && (Ping[PING_LEFT] > 10 && Ping[PING_ASKEW_LEFT] > 10))Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
//							if((FlameSenseDigi[0]==4 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 5) && z == 0)z=1;
							if(z==0 && (Ping[PING_LEFT] > 10 && Ping[PING_ASKEW_LEFT] > 10))Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
//							if((FlameSenseDigi[0]==4 || FlameSenseDigi[0] == 3 || FlameSenseDigi[0] == 5) && z == 0)z=1;
							if(z==0 && (Ping[PING_LEFT] > 10 && Ping[PING_ASKEW_LEFT] > 10))Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
							if(Ping[PING_LEFT]>15)
							{
								Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
								if(Ping[PING_LEFT]>15)
								{
									Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
								}
							}
						}
						if(FlameSenseDigi[0]!=4)
						{
							//Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
						}
					}
				}
			}
			FIREROOM_R1A_FLAG=FIREROOM_R1A_ACTIVE;
		}
		else if(SP_FIRE_R3==SP_FIRE_ACTIVE)
		{
			FIRESCAN_DIRECTION=SCAN_RIGHT;
			int CNT_R3=0;

			BW_PID_Init_Furniture();
			lcd_display_clear();
			while((FlameSenseDigi[0]!=6) && (FlameSenseDigi[0]!=5) && (FlameSenseDigi[0]!=7) && (CNT_R3 < 10))
			{
				if((FlameSenseDigi[0]==6) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==7) || (FlameSenseDigi[0]==4))break;
				if((Ping[PING_FRONT]>15) && (CNT_R3 < 5))
				{
					lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"SP FIRE R3");lcd_putstr(lcd);

					BW_FollowCounter_Left(1);
					if((FlameSenseDigi[0]==3)||(FlameSenseDigi[0]==2) || (FlameSenseDigi[0]==4)){Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_MED,IKCALC_DISABLE);break;}
				}
				else
				{
					lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
					lcd_gotoxy(0,1);sprintf(lcd,"SP FIRE R3");lcd_putstr(lcd);

					BW_FollowCounter_Left(1);
					if(CNT_R3>5 && FlameSenseDigi[0]!=0)break;// || FlameSenseDigi[0]==5 || FlameSenseDigi[0]==3))break;
				}
				CNT_R3++;
			}
		}
		else
		{
			FIRESCAN_DIRECTION=SCAN_RIGHT;
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"SCAN RIGHT");lcd_putstr(lcd);
			delay_ms(100);

			if(FIREROOM_R4AB_FLAG != FIREROOM_R4AB_ACTIVE)
			{
				Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
			}
		}

		//============================//
		//		EXTINGUISH ROUTINE	  //
		//============================//

		BW_FireFight_V2();

		//============================//

//=======APRIL, 27th 2017======//
//		RoomTypeDetector();

		USART3_PutChar(NOT_IN_ROOM_STAT);
		FIRE_LED_BLINK_OFF;
		FIRE_LED_OFF;
		FIRE=FIRE_SUCCESS;



		//old ALGORITHM
//		Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//===============================================================

		Dynamx_Mov_Static_Interpolate(LEVEL5,IKCALC_ENABLE);
		delay_ms(50);
		Dynamx_MovBwd_Interpolate(4,LEVEL4,IKCALC_ENABLE);

		if ((ROOM[2]==ROOM_4A) || (ROOM[2]==ROOM_4B) || (ROOM[2]==ROOM_3))// || (ROOM[2]==ROOM_2A) || (ROOM[2]==ROOM_2B))
		{
			FOLLOW_FLAG=KANAN;
			if(ROOM[2] == ROOM_3)
			{
				Nav_TurnAround(TURN_LEFT);
				BW_FollowTracer_Right_Interpolate();
				if(Ping[PING_FRONT] > 13)
				{
					Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
				}
				if(Ping[PING_FRONT] > 13)
				{
					Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
				}
			}
			else if(ROOM[2] == ROOM_4A)
			{
				if(Ping[PING_LEFT] < Ping[PING_RIGHT])
				{
					Nav_TurnAround(TURN_LEFT);
					BW_PID_Init();
					BW_FollowTracer_Right_Interpolate();
				}
				else
				{
					Nav_TurnAround(TURN_RIGHT);
					BW_PID_Init();
					BW_FollowTracer_Left_Interpolate();
				}
			}

			else if(ROOM[2] == ROOM_4B)
			{
				if(Ping[PING_LEFT] < Ping[PING_RIGHT])
				{
					Nav_TurnAround(TURN_LEFT);
					BW_PID_Init();
					BW_FollowTracer_Right_Interpolate();
				}
				else
				{
					Nav_TurnAround(TURN_RIGHT);
					BW_PID_Init();
					BW_FollowTracer_Left_Interpolate();
				}
			}

			if((Ping[PING_RIGHT]+4)<(Ping[PING_REAR_RIGHT]))
			{
				Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_RIGHT]+4)<(Ping[PING_REAR_RIGHT]))
				{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				}
			}
		}
		else if ((ROOM[2]==ROOM_2A) || (ROOM[2]==ROOM_2B))
		{
			Nav_TurnAround(TURN_LEFT);
			BW_PID_Init();
			BW_FollowTracer_Right_Interpolate();
			Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
		}

		else if (ROOM[2]==ROOM_1C)
		{
			FOLLOW_FLAG=/*KANAN*/KIRI;

			GetCMPS11_Angle8Bit();
			if(ROOM_1A_RETURN_MANUAL == 0)
			{
//				COMPASS_INTERRUPT = 1;
				if((CMPS11_Angle>(START_MIDDLE)))
				{
					while((CMPS11_Angle>(START_MIDDLE)))
					{
						GetCMPS11_Angle8Bit();
						if(CMPS11_Angle < START_MIDDLE)break;
						Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"POS : MIDDLE");lcd_putstr(lcd);
						lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
						GetCMPS11_Angle8Bit();
						if(CMPS11_Angle < START_MIDDLE)break;

					}

					if(CMPS11_Angle < START_MIDDLE)
					{
						while(CMPS11_Angle < START_MIDDLE)
						{
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle > START_MIDDLE)break;
							Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"CORRECTION 1");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle > START_MIDDLE)break;
						}
					}

					if(CMPS11_Angle > START_MIDDLE)
					{
						while(CMPS11_Angle > START_MIDDLE)
						{
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle == START_MIDDLE)break;
							Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"CORRECTION 2");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
								GetCMPS11_Angle8Bit();
							if(CMPS11_Angle == START_MIDDLE)break;
						}
						//GetCMPS11_Angle8Bit();
					}
				}
				else if(((CMPS11_Angle<(START_MIDDLE))))
				{
					while((CMPS11_Angle<(START_MIDDLE))&&(CMPS11_Angle>R4A_THRESHOLD_MIDDLE))
					{
						GetCMPS11_Angle8Bit();
						Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"POS : MIDDLE");lcd_putstr(lcd);
						lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
						GetCMPS11_Angle8Bit();

					}

					if(CMPS11_Angle > START_MIDDLE)
					{
						while(CMPS11_Angle > START_MIDDLE)
						{
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle < START_MIDDLE)break;
							Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"CORECTION 1");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle < START_MIDDLE)break;
						}

					}

					if(CMPS11_Angle < START_MIDDLE)
					{
						while(CMPS11_Angle < START_MIDDLE)
						{
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle == START_MIDDLE)break;
							Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"CORECTION 2");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle == START_MIDDLE)break;
						}
					}
				}

			}
//			COMPASS_INTERRUPT = 0;

			int stat = 0;
			if(ROOM_1A_RETURN_MANUAL == 0)
			{
			while(Ping[PING_FRONT]>15 && SHARP[SHARP_FRONT_L] > 12 && Ping[PING_UP_LEFT] > 12 && Ping[PING_UP_RIGHT] > 12)
			{
				Furniture_Avoider();
				Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
			}
			}
			else
			{
				Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
			}

			BW_PID_Init_FAR();

			BW_FollowTracer_Left_Interpolate();
			Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[0] == COLOUR_WHITE)
			{
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
			}

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[0] == COLOUR_WHITE)
			{
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
			}

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[0] == COLOUR_WHITE)
			{
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
			}
		}

		else if (ROOM[2]==ROOM_1B)
		{
			FOLLOW_FLAG=/*KANAN*/KIRI;

			GetCMPS11_Angle8Bit();
			if(ROOM_1A_RETURN_MANUAL == 0)
			{
				if((CMPS11_Angle>(START_MIDDLE)))
				{
					while((CMPS11_Angle>(START_MIDDLE)))
					{
						GetCMPS11_Angle8Bit();
						if(CMPS11_Angle < START_MIDDLE)break;
						Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"POS : MIDDLE");lcd_putstr(lcd);
						lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
						GetCMPS11_Angle8Bit();
						if(CMPS11_Angle < START_MIDDLE)break;

					}

					if(CMPS11_Angle < START_MIDDLE)
					{
						while(CMPS11_Angle < START_MIDDLE)
						{
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle > START_MIDDLE)break;
							Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"CORRECTION 1");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle > START_MIDDLE)break;
						}
					}

					if(CMPS11_Angle > START_MIDDLE)
					{
						while(CMPS11_Angle > START_MIDDLE)
						{
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle == START_MIDDLE)break;
							Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"CORRECTION 2");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle == START_MIDDLE)break;
						}
						//GetCMPS11_Angle8Bit();
					}
				}
				else if(((CMPS11_Angle<(START_MIDDLE))))
				{
					while((CMPS11_Angle<(START_MIDDLE))&&(CMPS11_Angle>R4A_THRESHOLD_MIDDLE))
					{
						GetCMPS11_Angle8Bit();
						Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"POS : MIDDLE");lcd_putstr(lcd);
						lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
						GetCMPS11_Angle8Bit();

					}

					if(CMPS11_Angle > START_MIDDLE)
					{
						while(CMPS11_Angle > START_MIDDLE)
						{
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle < START_MIDDLE)break;
							Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"CORECTION 1");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle < START_MIDDLE)break;
						}

					}

					if(CMPS11_Angle < START_MIDDLE)
					{
						while(CMPS11_Angle < START_MIDDLE)
						{
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle == START_MIDDLE)break;
							Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"CORECTION 2");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle == START_MIDDLE)break;
						}
					}
				}
			}

			int stat = 0;;
			if(ROOM_1A_RETURN_MANUAL == 0)
			{
			while(Ping[PING_FRONT]>15 && SHARP[SHARP_FRONT_L] > 12 && Ping[PING_UP_LEFT] > 12 && Ping[PING_UP_RIGHT] > 12)
			{
				Furniture_Avoider();

				Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
			}
			}
			BW_FollowTracer_Left_Interpolate();
			Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[0] == COLOUR_WHITE)
			{
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
			}

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[0] == COLOUR_WHITE)
			{
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
			}

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[0] == COLOUR_WHITE)
			{
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
			}
		}

		else if (ROOM[2]==ROOM_1A)
		{

			FOLLOW_FLAG=KANAN;

			if(ROOM_1A_RETURN_MANUAL == 0)
			{
				GetCMPS11_Angle8Bit();
				COMPASS_INTERRUPT = 1;
				if((CMPS11_Angle>(START_MIDDLE)))
				{
					while((CMPS11_Angle>(START_MIDDLE)))
					{
						GetCMPS11_Angle8Bit();
						if(CMPS11_Angle < START_MIDDLE)break;
						Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"POS : MIDDLE");lcd_putstr(lcd);
						lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
						GetCMPS11_Angle8Bit();
						if(CMPS11_Angle < START_MIDDLE)break;
					}

					if(CMPS11_Angle < START_MIDDLE)
					{
						while(CMPS11_Angle < START_MIDDLE)
						{
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle > START_MIDDLE)break;
							Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"CORRECTION 1");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle > START_MIDDLE)break;
						}
					}

					if(CMPS11_Angle > START_MIDDLE)
					{
						while(CMPS11_Angle > START_MIDDLE)
						{
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle == START_MIDDLE)break;
							Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"CORRECTION 2");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle == START_MIDDLE)break;
						}
					}
				}
				else if(((CMPS11_Angle<(START_MIDDLE))))
				{
					while((CMPS11_Angle<(START_MIDDLE))&&(CMPS11_Angle>R4A_THRESHOLD_MIDDLE))
					{
						GetCMPS11_Angle8Bit();
						Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
						lcd_display_clear();
						lcd_gotoxy(0,0);sprintf(lcd,"POS : MIDDLE");lcd_putstr(lcd);
						lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
						GetCMPS11_Angle8Bit();
					}

					if(CMPS11_Angle > START_MIDDLE)
					{
						while(CMPS11_Angle > START_MIDDLE)
						{
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle < START_MIDDLE)break;
							Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"CORECTION 1");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle < START_MIDDLE)break;
						}

					}

					if(CMPS11_Angle < START_MIDDLE)
					{
						while(CMPS11_Angle < START_MIDDLE)
						{
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle == START_MIDDLE)break;
							Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"CORECTION 2");lcd_putstr(lcd);
							lcd_gotoxy(0,1);sprintf(lcd,"ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);
							GetCMPS11_Angle8Bit();
							if(CMPS11_Angle == START_MIDDLE)break;
						}
					}
				}
			}

			if(ROOM_1A_RETURN_MANUAL == 0)
			{
			int stat = 0;
			while(Ping[PING_FRONT]>15 && SHARP[SHARP_FRONT_L] > 12 && Ping[PING_UP_LEFT] > 12 && Ping[PING_UP_RIGHT] > 12)
			{
				Furniture_Avoider();

				Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
			}
			}

			BW_PID_Init_FAR();
			BW_FollowTracer_Left_Interpolate();
			Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[0] == COLOUR_WHITE)
			{
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
			}

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[0] == COLOUR_WHITE)
			{
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
			}

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[0] == COLOUR_WHITE)
			{
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
			}
		}

		else if(
				(Ping[PING_LEFT]+Ping[PING_ASKEW_LEFT]+Ping[PING_REAR_LEFT])
				<
				(Ping[PING_RIGHT]+Ping[PING_ASKEW_RIGHT]+Ping[PING_REAR_RIGHT])
			)
		{
			FOLLOW_FLAG=KANAN;
			Nav_TurnAround(TURN_LEFT);
			BW_PID_Init();
			BW_FollowTracer_Right_Interpolate();

		}
		else
		{
			FOLLOW_FLAG=KIRI;
			Nav_TurnAround(TURN_RIGHT);
			BW_PID_Init();
			BW_FollowTracer_Left_Interpolate();
		}
//		End of changes
//		Some codes was omitted in this changes
//===============================================================
	}

	else
	{
		USART3_PutChar(NOT_IN_ROOM_STAT);
		FIRE=FIRE_OFF;
		Exit_No_Fire();
		if(ROOM4AB_FLAG==ROOM4AB_ACTIVE)
		{
			ROOM4AB_FLAG=ROOM4AB_INACTIVE;
		}
	}
}

void H_SESI_1(void)
{
	Nav_HallwaySC_To_3();

	BW_LOCATION[1]= BW_LOCATION[0];
	BW_LOCATION[0]= LOCATION_ROOM;

	H_IN_Room();

	BW_LOCATION[1]= BW_LOCATION[0];
	BW_LOCATION[0]= LOCATION_CORRIDOR;

	Nav_3_To_2();

	BW_LOCATION[1]= BW_LOCATION[0];
	BW_LOCATION[0]= LOCATION_ROOM;

	H_IN_Room();

	BW_LOCATION[1]= BW_LOCATION[0];
	BW_LOCATION[0]= LOCATION_CORRIDOR;

	Nav_2A_To_1BC();

	BW_LOCATION[1]= BW_LOCATION[0];
	BW_LOCATION[0]= LOCATION_ROOM;

	H_IN_Room();

	BW_LOCATION[1]= BW_LOCATION[0];
	BW_LOCATION[0]= LOCATION_CORRIDOR;

	Nav_1_To_4();

	BW_LOCATION[1]= BW_LOCATION[0];
	BW_LOCATION[0]= LOCATION_ROOM;

	H_IN_Room();

	BW_LOCATION[1]= BW_LOCATION[0];
	BW_LOCATION[0]= LOCATION_CORRIDOR;

	Nav_4B_To_HallwaySC();
}

void H_SESI_2(void)
{
	Nav_HallwaySC_To_1B();

	BW_LOCATION[1]= BW_LOCATION[0];
	BW_LOCATION[0]= LOCATION_ROOM;

	H_IN_Room();

	BW_LOCATION[1]= BW_LOCATION[0];
	BW_LOCATION[0]= LOCATION_CORRIDOR;

	Nav_1_To_3_V2();

	BW_LOCATION[1]= BW_LOCATION[0];
	BW_LOCATION[0]= LOCATION_ROOM;

	H_IN_Room();

	BW_LOCATION[1]= BW_LOCATION[0];
	BW_LOCATION[0]= LOCATION_CORRIDOR;

	Nav_3_To_4B_V2();

	BW_LOCATION[1]= BW_LOCATION[0];
	BW_LOCATION[0]= LOCATION_ROOM;

	H_IN_Room();

	BW_LOCATION[1]= BW_LOCATION[0];
	BW_LOCATION[0]= LOCATION_CORRIDOR;

	Nav_4B_To_2_V2();

	BW_LOCATION[1]= BW_LOCATION[0];
	BW_LOCATION[0]= LOCATION_ROOM;

	H_IN_Room();

	BW_LOCATION[1]= BW_LOCATION[0];
	BW_LOCATION[0]= LOCATION_CORRIDOR;

	Nav_2_To_HallwaySC();
}

void H_SESI_3(void)
{
	Nav_HallwaySC_To_3_V3();

	BW_LOCATION[1]= BW_LOCATION[0];
	BW_LOCATION[0]= LOCATION_ROOM;

	H_2021_Room();

	BW_LOCATION[1]= BW_LOCATION[0];
	BW_LOCATION[0]= LOCATION_CORRIDOR;

	Nav_3_To_2();

	BW_LOCATION[1]= BW_LOCATION[0];
	BW_LOCATION[0]= LOCATION_ROOM;

	H_2021_Room();

	BW_LOCATION[1]= BW_LOCATION[0];
	BW_LOCATION[0]= LOCATION_CORRIDOR;

	Nav_2A_To_1BC();

	BW_LOCATION[1]= BW_LOCATION[0];
	BW_LOCATION[0]= LOCATION_ROOM;

	H_2021_Room();

	BW_LOCATION[1]= BW_LOCATION[0];
	BW_LOCATION[0]= LOCATION_CORRIDOR;

	Nav_1A_To_HallwaySC();
}


/* func      : void H_ROOM_1A (void)
 * brief     : BW 2017 Navigation Routine. Home== R1A
 * param     : N/A
 * retval    : N/A
 * Ver       : 3
 * written By: Hafidin (MISSING NOTES)
 * Revised BY: Hafidin (April, 27th 2017)
 * programmer's Note:
 */
void H_ROOM_1A (void)
{
	while(EXTINGUISHED_FIRE==0)
	{
		ROOM4AB_FLAG=ROOM4AB_ACTIVE;

		Nav_1A_To_4A();

		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							GetCMPS11_Angle8Bit();
//GED C						if((CMPS11_Angle>R4AB_THRESHOLD_LOWER) && (CMPS11_Angle<R4AB_THRESHOLD_UPPER))
							if(ROOM_4A_MANUAL == 0)
							{
								delay_ms(200);
								BW_COMPASS_CORRECTION(ROOM_4A_DETECT_IN);
								if(ROOM[2] != ROOM_4A)
								{
									ROOM[2] = ROOM_4B;
								}
							}

						//BW IN ROOM
						H_2021_Room();

						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

				ROOM4B_FLAG = ROOM4BFLAG_INACTIVE;
				ROOM4A_FLAG = ROOM4AFLAG_INACTIVE;
				ROOM4AB_FLAG=ROOM4AB_INACTIVE;

		//=======ROOM 4 KE ROOM 3=======//
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);

		if(ROOM[2]==ROOM_4B)
		{
			if((Ping[PING_REAR_RIGHT])>(Ping[PING_RIGHT])+4)
					{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if((Ping[PING_REAR_RIGHT])>(Ping[PING_RIGHT]+4))
						{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
							if((Ping[PING_REAR_RIGHT])>(Ping[PING_RIGHT]+4))
							{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
						}
					}

			Nav_4B_To_2();
			Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
			if(Ping[PING_LEFT]>10)
			{	Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
				if(Ping[PING_LEFT]>10)
				{	Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);}
			}
			if(Ping[PING_REAR_LEFT] < (Ping[PING_ASKEW_LEFT]+3))
			{
				Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
				if(Ping[PING_REAR_LEFT] > (Ping[PING_ASKEW_LEFT]+3))
				{
						Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
				}
			}

			UV_R2FLAG=UV_R2FLAG_ACTIVE;
			//=======ROOM 2=======//
			//UPDATE BW LOCATION
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_ROOM;

			//RETURN TRIP NEEDED
			if(Ping[PING_REAR]<40)
			{
				ROOM[2]=ROOM_2B;
			}
			else
			{
				ROOM[2]=ROOM_2A;
			}

			//BW IN ROOM
			H_2021_Room();
			if(EXTINGUISHED_FIRE==1)break;

			//BW IN CORRIDOR
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_CORRIDOR;
			UV_R2FLAG=UV_R2FLAG_INACTIVE;

			Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);

			Nav_2_To_3();
			Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);

			SP_FIRE_R3=SP_FIRE_ACTIVE;
			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				}
			}
					//=======ROOM 3=======//
					//UPDATE BW LOCATION
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_ROOM;

								//RETURN TRIP NEEDED
								ROOM[2]=ROOM_3;

							//BW IN ROOM
							BW_Buzz(1);
							H_2021_Room();
							if(EXTINGUISHED_FIRE==1)break;

					//BW IN CORRIDOR
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_CORRIDOR;

			SP_FIRE_R3=SP_FIRE_INACTIVE;

			//==========================//
			//		RE-CHECK ROUTINE	//
			//==== RE CHECK  ROOM 3 ====//

			Dynamx_MovBwd_Interpolate(15,LEVEL6,IKCALC_ENABLE);
			Nav_TurnAround(TURN_RIGHT);

			SP_FIRE_R3=SP_FIRE_ACTIVE;

			//=======ROOM 3=======//
			//UPDATE BW LOCATION
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_ROOM;

			//RETURN TRIP NEEDED
			ROOM[2]=ROOM_3;

			//BW IN ROOM
			H_2021_Room();
			if(EXTINGUISHED_FIRE==1)break;

			//BW IN CORRIDOR
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_CORRIDOR;

			SP_FIRE_R3=SP_FIRE_INACTIVE;

			//=======ROOM 3 KE ROOM 2=======//
			Dynamx_MovFwd4cm_Interpolate(8,LEVEL4,IKCALC_ENABLE);

			Nav_3_To_2();
			Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);

			if(Ping[PING_LEFT]>10)
			{	Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
				if(Ping[PING_LEFT]>10)
				{	Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);}
			}

			if((Ping[PING_REAR_LEFT])>(Ping[PING_LEFT]+4))
			{
				Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])>(Ping[PING_LEFT]+4))
				{
					Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				}
			}

			else
			{
				Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])<(Ping[PING_LEFT]+4))
				{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);}
			}

					//=======ROOM 2=======//
					//UPDATE BW LOCATION
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_ROOM;

								//RETURN TRIP NEEDED
								if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
								{
									ROOM[2]=ROOM_2B;
								}
								else
								{
									ROOM[2]=ROOM_2A;
								}

							//BW IN ROOM
							H_2021_Room();
							if(EXTINGUISHED_FIRE==1)break;

					//BW IN CORRIDOR
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_CORRIDOR;

					Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
					Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);

					Nav_2_To_4A();

					ROOM4AB_FLAG=ROOM4AB_ACTIVE;
						//=======ROOM 4=======//
						//UPDATE BW LOCATION
						BW_LOCATION[1]= BW_LOCATION[0];
						BW_LOCATION[0]= LOCATION_ROOM;

						//RETURN TRIP NEEDED
						GetCMPS11_Angle8Bit();
						if(ROOM_4A_MANUAL == 0)
						{
							delay_ms(200);
							BW_COMPASS_CORRECTION(ROOM_4A_DETECT_IN);
							if(ROOM[2] != ROOM_4A)
							{
								ROOM[2] = ROOM_4B;
							}
						}

						//BW IN ROOM
						H_2021_Room();
						if(EXTINGUISHED_FIRE==1)break;

						//BW IN CORRIDOR
						BW_LOCATION[1]= BW_LOCATION[0];
						BW_LOCATION[0]= LOCATION_CORRIDOR;

						ROOM4AB_FLAG=ROOM4AB_INACTIVE;
		}
		else
		{
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);

			Nav_4A_To_3();
			Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);

			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				}
			}
			SP_FIRE_R3=SP_FIRE_ACTIVE;

			//=======ROOM 3=======//
			//UPDATE BW LOCATION
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_ROOM;

			//RETURN TRIP NEEDED
			ROOM[2]=ROOM_3;

			//BW IN ROOM
			H_2021_Room();
			if(EXTINGUISHED_FIRE==1)break;

			//BW IN CORRIDOR
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_CORRIDOR;

			SP_FIRE_R3=SP_FIRE_INACTIVE;
			//=======ROOM 3 KE ROOM 2=======//
			Dynamx_MovFwd4cm_Interpolate(8,LEVEL4,IKCALC_ENABLE);

			Nav_3_To_2();
			UV_R2FLAG = UV_R2FLAG_ACTIVE;
			Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
			if(Ping[PING_LEFT]>10)
			{	Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
				if(Ping[PING_LEFT]>10)
				{
					Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
				}
			}

			if((Ping[PING_REAR_LEFT])>(Ping[PING_LEFT]+4))
			{
				Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])>(Ping[PING_LEFT]+4))
				{	Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);}
			}
			else
			{
				Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])<(Ping[PING_LEFT]+4))
				{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);}
			}

	//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

					//=======ROOM 2=======//
					//UPDATE BW LOCATION
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_ROOM;

								//RETURN TRIP NEEDED
								if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
								{
									ROOM[2]=ROOM_2B;
								}
								else
								{
									ROOM[2]=ROOM_2A;
								}

							//BW IN ROOM
							H_2021_Room();
							if(EXTINGUISHED_FIRE==1)break;

					//BW IN CORRIDOR
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_CORRIDOR;

			//==========================//
			//		RE-CHECK ROUTINE	//
			//==== RE CHECK  ROOM 2 ====//

			Dynamx_MovBwd_Interpolate(12, LEVEL6, IKCALC_ENABLE);
			Nav_TurnAround(TURN_RIGHT);

				//=======ROOM 2=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
							{
								ROOM[2]=ROOM_2B;
							}
							else
							{
								ROOM[2]=ROOM_2A;
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2021_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;


			//=======ROOM 2 KE ROOM 3=======//
			if((Ping[PING_RIGHT])<=10)
			{
				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
			}

			Dynamx_MovFwd4cm_Interpolate(8,LEVEL4,IKCALC_ENABLE);

			Nav_2_To_3();
			Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);

				//=======ROOM 3=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							ROOM[2]=ROOM_3;

						//BW IN ROOM
						H_2021_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

			//=======ROOM 3 KE ROOM 4=======//
				if((Ping[PING_RIGHT])<=10)
				{
					Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
					if((Ping[PING_RIGHT])<=10)
					{
						Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
					}
				}
				if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
					{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
						{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
					}
				}
			Dynamx_MovFwd4cm_Interpolate(8,LEVEL4,IKCALC_ENABLE);

			Nav_3_To_4A();

					//=======ROOM 4=======//
	//				ROOM4_FLAG=ROOM4FLAG_ACTIVE;

					//UPDATE BW LOCATION
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_ROOM;

								//RETURN TRIP NEEDED
								GetCMPS11_Angle8Bit();
	//							if((CMPS11_Angle<R4AB_THRESHOLD_LOWER) || (CMPS11_Angle>R4AB_THRESHOLD_UPPER))
								if(ROOM_4A_MANUAL == 0)
								{
/*	GOR						if((CMPS11_Angle>R4AB_THRESHOLD_UPPER) && (CMPS11_Angle<R4AB_THRESHOLD_LOWER))
								{
									ROOM[2]=ROOM_4A;
								}
								else
								{
									ROOM[2]=ROOM_4B;
								}*/
									delay_ms(200);
									BW_COMPASS_CORRECTION(ROOM_4A_DETECT_IN);
									if(ROOM[2] != ROOM_4A)
									{
										ROOM[2] = ROOM_4B;
									}
								}

							//BW IN ROOM
							BW_Buzz(1);
							H_2021_Room();
							if(EXTINGUISHED_FIRE==1)break;

					//BW IN CORRIDOR
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_CORRIDOR;
		}

	}
}


void H_ROOM_1BC(void)
{
	while(EXTINGUISHED_FIRE==0)
	{
		//=======ROOM 1 KE ROOM 2=======//
		Nav_1C_To_3();
		Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);

		if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
		{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			}
		}

		SP_FIRE_R3=SP_FIRE_ACTIVE;

				//=======ROOM 2=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

				//RETURN TRIP NEEDED
				ROOM[2]=ROOM_3;

						//BW IN ROOM
						BW_Buzz(1);
						H_2021_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

				SP_FIRE_R3=SP_FIRE_INACTIVE;

		//=======ROOM 3 KE ROOM 2=======//
		if((Ping[PING_RIGHT])<=10)
		{
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
		}

		Dynamx_MovFwd4cm_Interpolate(8,LEVEL4,IKCALC_ENABLE);

		if(Ping[PING_FRONT] > 15)
		{
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
		}

		Nav_3_To_2();
		if(Ping[PING_LEFT]>10)
		{	Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
			if(Ping[PING_LEFT]>10)
			{	Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);}
		}
		Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);

		if(Ping[PING_REAR_LEFT] < (Ping[PING_ASKEW_LEFT]+3))
		{
			Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
			if(Ping[PING_REAR_LEFT] > (Ping[PING_ASKEW_LEFT]+3))
			{
					Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
			}
		}

		//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

		//=======ROOM 2=======//
		//UPDATE BW LOCATION
		UV_R2FLAG=UV_R2FLAG_ACTIVE;
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_ROOM;

				//RETURN TRIP NEEDED
//				if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
//				{
//					ROOM[2]=ROOM_2B;
//				}
//				else
//				{
					ROOM[2]=ROOM_2A;
//				}

				//BW IN ROOM
				BW_Buzz(1);
				H_2021_Room();
				if(EXTINGUISHED_FIRE==1)break;

		//BW IN CORRIDOR
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;

		UV_R2FLAG=UV_R2FLAG_INACTIVE;
		//=======ROOM 2 KE ROOM 4=======//
		/*
		 * 	ACTIVATE ROOM4AB_FLAG
		 */
//		Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

		if((Ping[PING_RIGHT])< 10)
		{
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
		}
//		if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//		{
//			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//			if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//			{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//				if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
//				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
//			}
//		}
		Dynamx_MovFwd4cm_Interpolate(8,LEVEL4,IKCALC_ENABLE);
		ROOM4AB_FLAG=ROOM4AB_ACTIVE;

		Nav_2_To_4A();

				//=======ROOM 4=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

				//RETURN TRIP NEEDED
				GetCMPS11_Angle8Bit();
//							if((CMPS11_Angle<R4AB_THRESHOLD_LOWER) || (CMPS11_Angle>R4AB_THRESHOLD_UPPER))
//GED C						if((CMPS11_Angle>R4AB_THRESHOLD_LOWER) && (CMPS11_Angle<R4AB_THRESHOLD_UPPER))
				if(ROOM_4A_MANUAL==0)
				{
/*GOR						if((CMPS11_Angle>R4AB_THRESHOLD_UPPER) && (CMPS11_Angle<R4AB_THRESHOLD_LOWER))
							{
								ROOM[2]=ROOM_4A;
							}
							else
							{
								ROOM[2]=ROOM_4B;
							}*/
					delay_ms(200);
					BW_COMPASS_CORRECTION(ROOM_4A_DETECT_IN);
					if(ROOM[2] != ROOM_4A)
					{
						ROOM[2] = ROOM_4B;
					}
				}

				//BW IN ROOM
				BW_Buzz(1);
				H_2021_Room();
				if(EXTINGUISHED_FIRE==1)break;

				// Check Ulang
				while(1)
				{
					Dynamx_MovBwd_Interpolate(15, LEVEL6, IKCALC_DISABLE);
					Nav_TurnAround(TURN_RIGHT);

					ROOM4AB_FLAG=ROOM4AB_ACTIVE;
					H_2021_Room();
					if(EXTINGUISHED_FIRE==1)break;
				}

		//BW IN CORRIDOR
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;
		ROOM4AB_FLAG=ROOM4AB_INACTIVE;

		break;

	}
}


/* func      : void H_ROOM_2_NEW_VER2 (void)
 * brief     : BW 2017 Navigation Routine. Home== R2
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Toni
 * Revised BY:
 * programmer's Note:
 */
void H_ROOM_2(void)
{
	while(EXTINGUISHED_FIRE==0)
	{
		Nav_2_To_4A();

		if(FIREROOM_R1A_FLAG==FIREROOM_R1A_ACTIVE)
		{
			if(Ping[PING_LEFT]>15)
			FIREROOM_R1A_FLAG = FIREROOM_R1A_ACTIVE;
			{
				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
			}
			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
			}
			}
			else if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
			}
			}

			//=======ROOM 1=======//
					//UPDATE BW LOCATION
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_ROOM;

			//RETURN TRIP NEEDED
			ROOM[2]=ROOM_1A;

			//BW IN ROOM
			H_2021_Room();
			if(EXTINGUISHED_FIRE==1)break;

			//BW IN CORRIDOR
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_CORRIDOR;

			FIREROOM_R1A_FLAG=FIREROOM_R1A_INACTIVE;

			//=======ROOM 1 KE ROOM 4=======//
			/*
			 * 	ACTIVATE ROOM4AB_FLAG
			 */

			Dynamx_MovFwd4cm_Interpolate(8,LEVEL4,IKCALC_ENABLE);

			ROOM4AB_FLAG=ROOM4AB_ACTIVE;
			CAT_FLAG_C=CAT_DETECTED;
			CAT_FLAG_B=CAT_NOT_DETECTED;
			CAT_FLAG_A=CAT_NOT_DETECTED;

			Nav_1A_To_4A();

			if(Ping[PING_RIGHT]>10)
			{
				Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
			}

			//		Nav_1A_To_3();

			//=======ROOM 4=======//
			//				ROOM4_FLAG=ROOM4FLAG_ACTIVE;

			//UPDATE BW LOCATION
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_ROOM;


			//RETURN TRIP NEEDED
			if(ROOM_4A_MANUAL == 0)
			{
				delay_ms(200);
				BW_COMPASS_CORRECTION(ROOM_4A_DETECT_IN);
				if(ROOM[2] != ROOM_4A)
				{
					ROOM[2] = ROOM_4B;
				}
			}

			H_2021_Room();
			if(EXTINGUISHED_FIRE==1)break;

			//BW IN CORRIDOR
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_CORRIDOR;

			ROOM4B_FLAG = ROOM4BFLAG_INACTIVE;
			ROOM4A_FLAG = ROOM4AFLAG_INACTIVE;
			ROOM4AB_FLAG=ROOM4AB_INACTIVE;
			//=======ROOM 4 KE ROOM 3=======//

			if((Ping[PING_REAR_RIGHT])>(Ping[PING_RIGHT])+4)
			{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			if((Ping[PING_REAR_RIGHT])>(Ping[PING_RIGHT]+4))
			{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			if((Ping[PING_REAR_RIGHT])>(Ping[PING_RIGHT]+4))
			{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
			}
			}
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);

			if(ROOM[2]==ROOM_4B)
			{
				//			Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
				Nav_4B_To_3();
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
			}
			else
			{
				Nav_4A_To_3();
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
			}

			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			}
			}
			SP_FIRE_R3=SP_FIRE_ACTIVE;

			//=======ROOM 3=======//
			//UPDATE BW LOCATION
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_ROOM;

			//RETURN TRIP NEEDED
			ROOM[2]=ROOM_3;

			//BW IN ROOM
			BW_Buzz(1);
			H_2021_Room();
			if(EXTINGUISHED_FIRE==1)break;

			//Check ulang room 3
			Dynamx_MovBwd_Interpolate(6, LEVEL3, IKCALC_DISABLE);
			Nav_TurnAround(TURN_RIGHT);
			SP_FIRE_R3=SP_FIRE_ACTIVE;

			H_2021_Room();
			if(EXTINGUISHED_FIRE==1)break;

			//BW IN CORRIDOR
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_CORRIDOR;

			SP_FIRE_R3=SP_FIRE_INACTIVE;

		}
		else {

			ROOM4AB_FLAG=ROOM4AB_ACTIVE;
				//=======ROOM 4=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							GetCMPS11_Angle8Bit();
//							if((CMPS11_Angle<R4AB_THRESHOLD_LOWER) || (CMPS11_Angle>R4AB_THRESHOLD_UPPER))
//GED C						if((CMPS11_Angle>R4AB_THRESHOLD_LOWER) && (CMPS11_Angle<R4AB_THRESHOLD_UPPER))
							if(ROOM_4A_MANUAL == 0)
							{

								delay_ms(200);
								BW_COMPASS_CORRECTION(ROOM_4A_DETECT_IN);
								if(ROOM[2] != ROOM_4A)
								{
									ROOM[2] = ROOM_4B;
								}
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2021_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

				ROOM4AB_FLAG=ROOM4AB_INACTIVE;
		//=======ROOM 4 KE ROOM 3=======//
		Dynamx_MovFwd4cm_Interpolate(8,LEVEL5,IKCALC_ENABLE);

	//		Nav_3_To_4A();
		if(ROOM[2]==ROOM_4B)
		{
			Nav_4B_To_3();
			Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
		}
		else
		{
			Nav_4A_To_3();
			Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
		}

		if((Ping[PING_LEFT])>10)
		{
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
		}
		if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
					{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//						if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
//						{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);	}
					}
				}
		SP_FIRE_R3=SP_FIRE_ACTIVE;
				//=======ROOM 3=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							ROOM[2]=ROOM_3;

						//BW IN ROOM
						BW_Buzz(1);
						H_2021_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

				SP_FIRE_R3=SP_FIRE_INACTIVE;
		//=======ROOM 3 KE ROOM 1=======//
		ROOM1_FLAG=ROOM1FLAG_ACTIVE;

		Dynamx_MovFwd4cm_Interpolate(8,LEVEL5,IKCALC_ENABLE);

		Nav_3_To_1BC();
		Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);

			if(SP_FIRE_1B==SP_FIRE_ACTIVE)		//eksekusi persyaratan ada di nav 4b to 1bc
			{
				SP_FIRE_1B=SP_FIRE_ACTIVE;
			}
			else
			{
				Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
				if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
						{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
							if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
							{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
						}
				}
				SP_FIRE_1C=SP_FIRE_ACTIVE;
			}

				//=======ROOM 1=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							if(SP_FIRE_1B==SP_FIRE_ACTIVE)
							{
								ROOM[2]=ROOM_1B;
							}
							else
							{
								ROOM[2]=ROOM_1C;
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2021_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;


		//==========================//
		//		RE-CHECK ROUTINE	//
		//==== RE CHECK  ROOM 1 ====//

		if(ROOM[2]==ROOM_1C)
		{
			Dynamx_MovBwd_Interpolate(15, LEVEL6, IKCALC_DISABLE);
			Nav_TurnAround(TURN_LEFT);
		}
		else
		{
			while(Ping[PING_FRONT]<40)
			{
				Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
			}
			Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
			while((Ping[PING_RIGHT]<40) || (Ping[PING_ASKEW_RIGHT]<40))
			{
				Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
			}
			Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
		}

				//=======ROOM 1=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							if(SP_FIRE_1B==SP_FIRE_ACTIVE)
							{
								ROOM[2]=ROOM_1B;
							}
							else
							{
								ROOM[2]=ROOM_1C;
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2021_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

				SP_FIRE_1B=SP_FIRE_INACTIVE;
				SP_FIRE_1C=SP_FIRE_INACTIVE;

			//=======ROOM 1 KE ROOM 4=======//
			Dynamx_MovFwd4cm_Interpolate(8,LEVEL5,IKCALC_ENABLE);

			Nav_1C_To_4A();

			SP_FIRE_1B=SP_FIRE_INACTIVE;
			SP_FIRE_1C=SP_FIRE_INACTIVE;

					//=======ROOM 4=======//
	//				ROOM4_FLAG=ROOM4FLAG_ACTIVE;
					//UPDATE BW LOCATION
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_ROOM;

								//RETURN TRIP NEEDED
					if(ROOM_4A_MANUAL == 0)
					{
						delay_ms(200);
						BW_COMPASS_CORRECTION(ROOM_4A_DETECT_IN);
						if(ROOM[2] != ROOM_4A)
						{
							ROOM[2] = ROOM_4B;
						}
/*								GetCMPS11_Angle8Bit();
	//							if((CMPS11_Angle<R4AB_THRESHOLD_LOWER) || (CMPS11_Angle>R4AB_THRESHOLD_UPPER))
	GOR						if((CMPS11_Angle>R4AB_THRESHOLD_UPPER) && (CMPS11_Angle<R4AB_THRESHOLD_LOWER))
								{
									ROOM[2]=ROOM_4A;
								}
								else
								{
									ROOM[2]=ROOM_4B;
								}*/
					}

							//BW IN ROOM
							BW_Buzz(1);
							H_2021_Room();
							if(EXTINGUISHED_FIRE==1)break;

					//BW IN CORRIDOR
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_CORRIDOR;

			//=======ROOM 4 KE ROOM 3=======//
			Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);

			Dynamx_MovFwd4cm_Interpolate(8,LEVEL5,IKCALC_ENABLE);

			if(ROOM[2]==ROOM_4B)
			{
				Nav_4B_To_3();
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
			}
			else
			{
				Nav_4A_To_3();
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
			}

			SP_FIRE_R3=SP_FIRE_ACTIVE;
					//=======ROOM 3=======//
					//UPDATE BW LOCATION
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_ROOM;


								//RETURN TRIP NEEDED
								ROOM[2]=ROOM_3;

							//BW IN ROOM
							BW_Buzz(1);
							H_2021_Room();
							if(EXTINGUISHED_FIRE==1)break;

					//BW IN CORRIDOR
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_CORRIDOR;
			SP_FIRE_R3=SP_FIRE_INACTIVE;
		}
	}
}

/* func      : void H_ROOM_3_VER2 (void)
 * brief     : BW 2017 Navigation Routine. Home== R3
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Hafidin (MISSING NOTES)
 * Revised BY:
 * programmer's Note:
 */
void H_ROOM_3 (void)
{
	while(EXTINGUISHED_FIRE==0)
	{
		//=======ROOM 3 KE ROOM 1=======//
		Nav_3_To_1A();

		if(FIREROOM_R1A_FLAG==FIREROOM_R1A_ACTIVE)
		{
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL3,IKCALC_ENABLE);
			if(Ping[PING_LEFT]>15)
			{
				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
			}
			if((Ping[PING_REAR_LEFT]+4)<(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT]+4)<(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT]+4)<(Ping[PING_ASKEW_LEFT]))
					{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
				}
			}
			else if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]+4))
			{	Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]+4))
				{	Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]+4))
					{	Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
				}
			}

			ROOM1A_SP_EXIT_FLAG=ROOM1A_SP_EXIT_FLAG_ACTIVE;

			//=======ROOM 1=======//
			//UPDATE BW LOCATION
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_ROOM;

			//RETURN TRIP NEEDED
			ROOM[2]=ROOM_1A;

			//BW IN ROOM
			H_2021_Room();
			if(EXTINGUISHED_FIRE==1)break;

			//BW IN CORRIDOR
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_CORRIDOR;

		//=======ROOM 1 KE ROOM 2=======//
		ROOM1A_SP_EXIT_FLAG=ROOM1A_SP_EXIT_FLAG_INACTIVE;
		FIREROOM_R1A_FLAG=FIREROOM_R1A_INACTIVE;

		Dynamx_MovFwd4cm_Interpolate(8,LEVEL4,IKCALC_ENABLE);

		if(Ping[PING_ASKEW_LEFT] < 10)
		{
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
		}

		BW_COMPASS_CORRECTION(ROOM_1C_DETECT_NAV);
		if(Ping[PING_FRONT]<40 && ROOM[2] == ROOM_1C)
		{
			ROOM[2] = ROOM_1B;
			Nav_1B_To_2();

			Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
			if(Ping[PING_LEFT]>10)
			{	Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
				if(Ping[PING_LEFT]>10)
				{	Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);}
			}
			if(Ping[PING_REAR_LEFT] < (Ping[PING_ASKEW_LEFT]+3))
			{
				Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
				if(Ping[PING_REAR_LEFT] > (Ping[PING_ASKEW_LEFT]+3))
				{
						Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
				}
			}
		}
		else if(ROOM[2] == ROOM_1C && Ping[PING_FRONT] >= 40)
		{
			Nav_1C_To_2();
			Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
			if(Ping[PING_LEFT]>10)
			{	Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
				if(Ping[PING_LEFT]>10)
				{	Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);}
			}
			if(Ping[PING_REAR_LEFT] < (Ping[PING_ASKEW_LEFT]+3))
			{
				Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
				if(Ping[PING_REAR_LEFT] > (Ping[PING_ASKEW_LEFT]+3))
				{
						Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
				}
			}
		}
		else
		{
			if(Ping[PING_LEFT] < 24)
			{
				Nav_1C_To_2();
			}
			else
			{
				Nav_1A_To_2();
			}
		}
		//=======ROOM 2=======//
		//UPDATE BW LOCATION
		UV_R2FLAG = UV_R2FLAG_ACTIVE;
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_ROOM;

		ROOM[2]=ROOM_2A;


		//BW IN ROOM
		BW_Buzz(1);
		H_2021_Room();
		UV_R2FLAG = UV_R2FLAG_INACTIVE;
		if(EXTINGUISHED_FIRE==1)break;

		//BW IN CORRIDOR
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;

		//=======ROOM 2 KE ROOM 4=======//
		/*
		 * 	ACTIVATE ROOM4AB_FLAG
		 */
		ROOM4AB_FLAG=ROOM4AB_ACTIVE;

		Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
		ROOM4AB_FLAG=ROOM4AB_ACTIVE;

//		Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL5,IKCALC_ENABLE);

		Nav_2_To_4A();

		//=======ROOM 4=======//
		//UPDATE BW LOCATION
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_ROOM;

		//RETURN TRIP NEEDED
		if(ROOM_4A_MANUAL == 0)
		{
			delay_ms(200);
			BW_COMPASS_CORRECTION(ROOM_4A_DETECT_IN);
			if(ROOM[2] != ROOM_4A)
			{
				ROOM[2] = ROOM_4B;
			}

		}

		//BW IN ROOM
		BW_Buzz(1);
		H_2021_Room();
		if(EXTINGUISHED_FIRE==1)break;

		Dynamx_MovBwd_Interpolate(6, LEVEL6, IKCALC_DISABLE);
		Nav_TurnAround(TURN_RIGHT);
		ROOM4AB_FLAG=ROOM4AB_ACTIVE;
		H_2021_Room();
		if(EXTINGUISHED_FIRE==1)break;



		//BW IN CORRIDOR
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;

		ROOM4AB_FLAG=ROOM4AB_INACTIVE;

		}
		else
		{
			//=======ROOM 4 KE ROOM 1A=======//
			ROOM4AB_FLAG=ROOM4AB_ACTIVE;
			//=======ROOM 4=======//
			//UPDATE BW LOCATION
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_ROOM;

			//RETURN TRIP NEEDED
			if(ROOM_4A_MANUAL == 0)
			{
				delay_ms(200);
				BW_COMPASS_CORRECTION(ROOM_4A_DETECT_IN);
				if(ROOM[2] != ROOM_4A)
				{
					ROOM[2] = ROOM_4B;
				}
			}

			H_2021_Room();
			if(EXTINGUISHED_FIRE==1)break;

			//BW IN CORRIDOR
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_CORRIDOR;

			ROOM4AB_FLAG=ROOM4AB_INACTIVE;

			//=======ROOM 4 KE ROOM 1=======//
			Dynamx_MovFwd4cm_Interpolate(8,LEVEL4,IKCALC_ENABLE);

			if(ROOM[2]==ROOM_4A)
			{
				Nav_4A_To_1A();
			}
			else
			{
				Nav_4B_To_1A();
			}

			if(Ping[PING_LEFT]>15)
			{
				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
				if(Ping[PING_LEFT]>15)
				{
					Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
				}
			}
			if((Ping[PING_REAR_LEFT]+4)<(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT]+4)<(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT]+4)<(Ping[PING_ASKEW_LEFT]))
					{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
				}
			}
			else if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]+4))
			{	Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]+4))
				{	Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]+4))
					{	Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
				}
			}

			ROOM1A_SP_EXIT_FLAG=ROOM1A_SP_EXIT_FLAG_ACTIVE;

					//=======ROOM 1=======//
					//UPDATE BW LOCATION
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_ROOM;

					//RETURN TRIP NEEDED
					ROOM[2]=ROOM_1A;
					H_2021_Room();
					if(EXTINGUISHED_FIRE==1)break;

					//BW IN CORRIDOR
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_CORRIDOR;

			//=======ROOM 1 KE ROOM 2=======//
			ROOM1A_SP_EXIT_FLAG=ROOM1A_SP_EXIT_FLAG_INACTIVE;
			FIREROOM_R1A_FLAG=FIREROOM_R1A_INACTIVE;

			Dynamx_MovFwd4cm_Interpolate(8,LEVEL4,IKCALC_ENABLE);

			if(Ping[PING_FRONT]<40)
			{
				Nav_1B_To_2();
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
				if(Ping[PING_LEFT]>10)
				{	Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
					if(Ping[PING_LEFT]>10)
					{	Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);}
				}
				if(Ping[PING_REAR_LEFT] < (Ping[PING_ASKEW_LEFT]+3))
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
					if(Ping[PING_REAR_LEFT] > (Ping[PING_ASKEW_LEFT]+3))
					{
							Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
					}
				}
			}
			else
			{
				Nav_1C_To_2();
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
				if(Ping[PING_LEFT]>10)
				{	Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
					if(Ping[PING_LEFT]>10)
					{	Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);}
				}
				if(Ping[PING_REAR_LEFT] < (Ping[PING_ASKEW_LEFT]+3))
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
					if(Ping[PING_REAR_LEFT] > (Ping[PING_ASKEW_LEFT]+3))
					{
							Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
					}
				}
			}

			UV_R2FLAG=UV_R2FLAG_ACTIVE;
					//=======ROOM 2=======//
					//UPDATE BW LOCATION
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_ROOM;

								//RETURN TRIP NEEDED
								if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
								{
									ROOM[2]=ROOM_2B;
								}
								else
								{
									ROOM[2]=ROOM_2A;
								}

							//BW IN ROOM
							BW_Buzz(1);
							H_2021_Room();
							if(EXTINGUISHED_FIRE==1)break;

					Dynamx_MovBwd_Interpolate(6, LEVEL6, IKCALC_ENABLE);
					Nav_TurnAround(TURN_RIGHT);
					UV_R2FLAG=UV_R2FLAG_ACTIVE;
					H_2021_Room();
					if(EXTINGUISHED_FIRE==1)break;

					//BW IN CORRIDOR
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_CORRIDOR;

					UV_R2FLAG=UV_R2FLAG_INACTIVE;
		}
	}
}


void H_ROOM_4A (void)
{
	while(EXTINGUISHED_FIRE==0)
	{
		Nav_4A_To_1A();

		if(Ping[PING_LEFT]>15)
		{
			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
		}

		ROOM1A_SP_EXIT_FLAG=ROOM1A_SP_EXIT_FLAG_ACTIVE;
		FIREROOM_R1A_FLAG=FIREROOM_R1A_ACTIVE;

		//=======ROOM 1=======//
		//UPDATE BW LOCATION
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_ROOM;

					//RETURN TRIP NEEDED
					ROOM[2]=ROOM_1A;

				//BW IN ROOM
				H_2021_Room();
				if(EXTINGUISHED_FIRE==1)break;

		//BW IN CORRIDOR
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;

		//=======ROOM 1 KE ROOM 2=======//
		ROOM1A_SP_EXIT_FLAG=ROOM1A_SP_EXIT_FLAG_INACTIVE;
		FIREROOM_R1A_FLAG=FIREROOM_R1A_INACTIVE;

//		Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);

		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)
		{
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
		}

		BW_COMPASS_CORRECTION(ROOM_1C_DETECT_NAV);
		if(ROOM[2] == ROOM_1C)
		{
			Nav_1C_To_3();
		}
		else
		{
			Nav_1A_To_3();
		}
		Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);

		SP_FIRE_R3=SP_FIRE_ACTIVE;

		if((Ping[PING_LEFT])>10)
		{	Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
			if((Ping[PING_LEFT])>10)
			{	Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
			}
		}

		if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
		{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			}
		}

		//=======ROOM 3=======//
		//UPDATE BW LOCATION
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_ROOM;

					//RETURN TRIP NEEDED
					ROOM[2]=ROOM_3;

				//BW IN ROOM
				H_2021_Room();
				if(EXTINGUISHED_FIRE==1)break;

		//BW IN CORRIDOR
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;

		SP_FIRE_R3=SP_FIRE_INACTIVE;

		//========ROOM 2=======//
		UV_R2FLAG=UV_R2FLAG_ACTIVE;

		Dynamx_MovFwd4cm_Interpolate(8,LEVEL4,IKCALC_ENABLE);

		Nav_3_To_2();
		Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
		if(Ping[PING_LEFT]>10)
		{	Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
			if(Ping[PING_LEFT]>10)
			{	Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);}
		}
		if(Ping[PING_REAR_LEFT] < (Ping[PING_ASKEW_LEFT]+3))
		{
			Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
			if(Ping[PING_REAR_LEFT] > (Ping[PING_ASKEW_LEFT]+3))
			{
					Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
			}
		}

//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

				//=======ROOM 2=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							//if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
							if(Ping[PING_REAR_LEFT]<70)
							{
								ROOM[2]=ROOM_2B;
							}
							else
							{
								ROOM[2]=ROOM_2A;
							}

						//BW IN ROOM
						BW_Buzz(1);
						H_2021_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

		UV_R2FLAG=UV_R2FLAG_INACTIVE;

//===============================================================================================//

		//==========================//
		//		RE-CHECK ROUTINE	//
		//==== RE CHECK  ROOM 2 ====//

		UV_R2FLAG=UV_R2FLAG_ACTIVE;

		Dynamx_MovBwd_Interpolate(15, LEVEL6, IKCALC_DISABLE);
		Nav_TurnAround(TURN_RIGHT);

		//=======ROOM 3=======//
		//UPDATE BW LOCATION
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_ROOM;

			//RETURN TRIP NEEDED
			ROOM[2]=ROOM_3;

				//BW IN ROOM
				BW_Buzz(1);
				H_2021_Room();
				if(EXTINGUISHED_FIRE==1)break;

		//BW IN CORRIDOR
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;

		UV_R2FLAG=UV_R2FLAG_INACTIVE;


		//=======ROOM 2 KE ROOM 3=======//

		SP_FIRE_R3=SP_FIRE_ACTIVE;

		Nav_2_To_3();
		Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);

		//=======ROOM 3=======//
		//UPDATE BW LOCATION
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_ROOM;

					//RETURN TRIP NEEDED
					ROOM[2]=ROOM_3;

				//BW IN ROOM
				BW_Buzz(1);
				H_2021_Room();
				if(EXTINGUISHED_FIRE==1)break;

		//BW IN CORRIDOR
		BW_LOCATION[1]= BW_LOCATION[0];
		BW_LOCATION[0]= LOCATION_CORRIDOR;

	SP_FIRE_R3=SP_FIRE_INACTIVE;

	//=======ROOM 3 KE ROOM 1=======//
	ROOM1_FLAG=ROOM1FLAG_ACTIVE;

	Dynamx_MovFwd4cm_Interpolate(8,LEVEL4,IKCALC_ENABLE);

	Nav_3_To_1BC();
	Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);

		if(SP_FIRE_1B==SP_FIRE_ACTIVE)		//eksekusi persyaratan ada di nav 4b to 1bc
		{
			SP_FIRE_1B=SP_FIRE_ACTIVE;
		}
		else
		{
			Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
			if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
			{
				Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
					{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
						{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
					}
			}
			SP_FIRE_1C=SP_FIRE_ACTIVE;
		}

			//=======ROOM 1=======//
			//UPDATE BW LOCATION
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_ROOM;

						//RETURN TRIP NEEDED
						if(SP_FIRE_1B==SP_FIRE_ACTIVE)
						{
							ROOM[2]=ROOM_1B;
						}
						else
						{
							ROOM[2]=ROOM_1C;
						}

					//BW IN ROOM
					BW_Buzz(1);
					H_2021_Room();
					if(EXTINGUISHED_FIRE==1)break;

			//BW IN CORRIDOR
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_CORRIDOR;
	}
}


/* func      : void H_ROOM_4B_VER2 (void)
 * brief     : BW 2017 Navigation Routine. Home== R4B Exclusive
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Toni ( Wednesday, November 22th 2017)
 * Revised BY:
 * programmer's Note:
 */
void H_ROOM_4B (void)
{
	while(EXTINGUISHED_FIRE==0)
	{
		//=======ROOM 4 KE ROOM 1=======//
//		ROOM1_FLAG=ROOM1FLAG_ACTIVE;
		Nav_4B_To_1A();

		if(CAT_FLAG_A==CAT_DETECTED || CAT_FLAG_B==CAT_DETECTED)
		{
			if(Ping[PING_LEFT]>15)
			{
				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
			}
			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
					{	Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
				}
			}
			else if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
					{	Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
				}
			}

		ROOM1A_SP_EXIT_FLAG=ROOM1A_SP_EXIT_FLAG_ACTIVE;
		FIREROOM_R1A_FLAG=FIREROOM_R1A_ACTIVE;

				//=======ROOM 1=======//
				//UPDATE BW LOCATION
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_ROOM;

							//RETURN TRIP NEEDED
							ROOM[2]=ROOM_1A;

						//BW IN ROOM
						BW_Buzz(1);
						H_2021_Room();
						if(EXTINGUISHED_FIRE==1)break;

				//BW IN CORRIDOR
				BW_LOCATION[1]= BW_LOCATION[0];
				BW_LOCATION[0]= LOCATION_CORRIDOR;

			ROOM1A_SP_EXIT_FLAG=ROOM1A_SP_EXIT_FLAG_INACTIVE;
			FIREROOM_R1A_FLAG=FIREROOM_R1A_INACTIVE;

			Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);

			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)
			{
				Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
			}

			//=======ROOM 1 KE ROOM 2=======//
			BW_COMPASS_CORRECTION(ROOM_1C_DETECT_NAV);
			if(ROOM[2] == ROOM_1C)
			{
				Nav_1C_To_3();
			}
			else
			{
				Nav_1A_To_3();
			}
			Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);

			SP_FIRE_R3=SP_FIRE_ACTIVE;

			if((Ping[PING_LEFT])>10)
			{	Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
				if((Ping[PING_LEFT])>10)
				{Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
				}
			}

			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				}
			}
					//=======ROOM 3=======//
					//UPDATE BW LOCATION
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_ROOM;

					//RETURN TRIP NEEDED
					ROOM[2]=ROOM_3;

							//BW IN ROOM
							BW_Buzz(1);
							H_2021_Room();
							if(EXTINGUISHED_FIRE==1)break;

					//BW IN CORRIDOR
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_CORRIDOR;

			SP_FIRE_R3=SP_FIRE_INACTIVE;
					//=======ROOM 3 KE ROOM 2=======//
			if((Ping[PING_RIGHT])<=10)
				{
					Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
				}
	//		if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
	//			{
	//				Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//				if((Ping[PING_REAR_RIGHT])>(Ping[PING_ASKEW_RIGHT]))
	//				{	Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
	//				}
	//			}
			Dynamx_MovFwd4cm_Interpolate(8,LEVEL4,IKCALC_ENABLE);

			UV_R2FLAG=UV_R2FLAG_ACTIVE;
			Nav_3_To_2();
			Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);
			if(Ping[PING_LEFT]>10)
			{	Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
				if(Ping[PING_LEFT]>10)
				{	Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);}
			}
			if(Ping[PING_REAR_LEFT] < (Ping[PING_ASKEW_LEFT]+3))
			{
				Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
				if(Ping[PING_REAR_LEFT] > (Ping[PING_ASKEW_LEFT]+3))
				{
						Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
				}
			}


			//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

			//=======ROOM 2=======//
			//UPDATE BW LOCATION
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_ROOM;

					//RETURN TRIP NEEDED
					if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
					{
						ROOM[2]=ROOM_2B;
					}
					else
					{
						ROOM[2]=ROOM_2A;
					}

					//BW IN ROOM
					BW_Buzz(1);
					H_2021_Room();
					if(EXTINGUISHED_FIRE==1)break;

					// Check Room 2
					Dynamx_MovBwd_Interpolate(6, LEVEL6, IKCALC_DISABLE);
					Nav_TurnAround(TURN_RIGHT);

					UV_R2FLAG=UV_R2FLAG_ACTIVE;
					H_2021_Room();
					if(EXTINGUISHED_FIRE==1)break;


			//BW IN CORRIDOR
			BW_LOCATION[1]= BW_LOCATION[0];
			BW_LOCATION[0]= LOCATION_CORRIDOR;

			UV_R2FLAG=UV_R2FLAG_INACTIVE;
		}
		else
		{
			if(Ping[PING_LEFT]>15)
			{
				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
				if(Ping[PING_LEFT]>15)
				{
					Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
				}
			}
			if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
					{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
				}
			}
			else if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
			{	Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT])>(Ping[PING_ASKEW_LEFT]))
					{	Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);	}
				}
			}

					//=======ROOM 1=======//
					//UPDATE BW LOCATION
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_ROOM;

								//RETURN TRIP NEEDED
								ROOM[2]=ROOM_1A;

							//BW IN ROOM
							BW_Buzz(1);
							H_2021_Room();
							if(EXTINGUISHED_FIRE==1)break;

					//BW IN CORRIDOR
					BW_LOCATION[1]= BW_LOCATION[0];
					BW_LOCATION[0]= LOCATION_CORRIDOR;

				ROOM1A_SP_EXIT_FLAG=ROOM1A_SP_EXIT_FLAG_INACTIVE;

				Dynamx_MovFwd4cm_Interpolate(8,LEVEL4,IKCALC_ENABLE);

				//=======ROOM 1A KE ROOM 3=======//
				Nav_1A_To_3();
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);

				if((Ping[PING_LEFT])>10)
				{	Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
					if((Ping[PING_LEFT])>10)
					{Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
					}
				}

				if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
				{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					if((Ping[PING_REAR_LEFT])<(Ping[PING_ASKEW_LEFT]))
					{	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					}
				}

				SP_FIRE_R3=SP_FIRE_ACTIVE;
						//=======ROOM 3=======//
						//UPDATE BW LOCATION
						BW_LOCATION[1]= BW_LOCATION[0];
						BW_LOCATION[0]= LOCATION_ROOM;

									//RETURN TRIP NEEDED
									ROOM[2]=ROOM_3;

								//BW IN ROOM
								BW_Buzz(1);
								H_2021_Room();
								if(EXTINGUISHED_FIRE==1)break;

						//BW IN CORRIDOR
						BW_LOCATION[1]= BW_LOCATION[0];
						BW_LOCATION[0]= LOCATION_CORRIDOR;

				SP_FIRE_R3=SP_FIRE_INACTIVE;
				//=======ROOM 3 KE ROOM 2=======//
				Dynamx_MovFwd4cm_Interpolate(8,LEVEL4,IKCALC_ENABLE);

				Nav_3_To_2();
				Dynamx_MovFwd4cm_Interpolate(4, LEVEL5, IKCALC_ENABLE);

				if(Ping[PING_LEFT]>10)
				{	Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
					if(Ping[PING_LEFT]>10)
					{	Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);}
				}

				if(Ping[PING_REAR_LEFT] < (Ping[PING_ASKEW_LEFT]+3))
				{
					Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
					if(Ping[PING_REAR_LEFT] > (Ping[PING_ASKEW_LEFT]+3))
					{
							Dynamx_Rot_Left_Interpolate(LEVEL5, HEXSTEP_VERYCLOSE, IKCALC_DISABLE);
					}
				}

		//		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);

						//=======ROOM 2=======//
						//UPDATE BW LOCATION
						BW_LOCATION[1]= BW_LOCATION[0];
						BW_LOCATION[0]= LOCATION_ROOM;

									//RETURN TRIP NEEDED
									if(INFRARED[IR_UPPER_RIGHT]==IR_DETECTED)
									{
										ROOM[2]=ROOM_2B;
									}
									else
									{
										ROOM[2]=ROOM_2A;
									}

								//BW IN ROOM
								BW_Buzz(1);
								H_2021_Room();
								if(EXTINGUISHED_FIRE==1)break;

								Dynamx_MovBwd_Interpolate(15, LEVEL6, IKCALC_ENABLE);
								Nav_TurnAround(TURN_RIGHT);

								UV_R2FLAG=UV_R2FLAG_ACTIVE;
								H_2021_Room();
								if(EXTINGUISHED_FIRE==1)break;

						//BW IN CORRIDOR
						BW_LOCATION[1]= BW_LOCATION[0];
						BW_LOCATION[0]= LOCATION_CORRIDOR;

		}
	}
}


void Furniture_Avoider(void)
{
//	int g,CNT=0;
//	if(BW_LOCATION[0]==LOCATION_ROOM)
//	{
//		if((FIRESCAN_DIRECTION==SCAN_RIGHT) || (FOLLOW_FLAG==KIRI))
//		{
//			if(((Ping[PING_UP_RIGHT] <= 10 && Ping[PING_ASKEW_RIGHT] > 30) && (Ping[PING_FRONT]>25) && (Ping[PING_ASKEW_LEFT]<12)) && (Ping[PING_RIGHT]>20))
//			{
//				Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
//
//				if(((Ping[PING_UP_RIGHT] <= 10 && Ping[PING_ASKEW_RIGHT] > 30) && (Ping[PING_FRONT]>25) && (Ping[PING_ASKEW_LEFT]<12)) && (Ping[PING_RIGHT]>20))
//				{
//					if(Ping[PING_ASKEW_RIGHT]<10)
//					{
//						Dynamx_MovBwd_Interpolate(4,LEVEL3,IKCALC_ENABLE);
//					}
//
//					Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
//
//					while(Ping[PING_FRONT]>20)
//					{
//						Dynamx_Slide_Right_Interpolate(HEXSPD_MED,LEVEL3);
//						CNT++;
//						if(CNT>=4){CNT=0;break;}
//					}
//					while(Ping[PING_FRONT]<20)
//					{
//						Dynamx_Slide_Right_Interpolate(HEXSPD_MED,LEVEL3);
//						CNT++;
//						if(CNT>=4){CNT=0;break;}
//					}
//						Dynamx_MovFwd4cm_Interpolate(4,LEVEL3,IKCALC_ENABLE);
//						Dynamx_MovFwd4cm_Interpolate(4,LEVEL3,IKCALC_ENABLE);
//
//					if(UV_Lock==UVLOCK_ACTIVE)
//					{
//						TRACER_STAT=TRACER_BLACK;
//						BW_PID_Init_Furniture();
//						for(g=0;g<=5;g++)
//						{
//							BW_FollowCounter_Left(1);
//
//							TCSlave_Check();
//							if (TRACER_STAT==TRACER_WHITE)
//							{
//								lcd_display_clear();
//								lcd_gotoxy(0,0);sprintf(lcd,"TRACER STATS");lcd_putstr(lcd);
//								lcd_gotoxy(0,1);sprintf(lcd,"WHITE");lcd_putstr(lcd);
//								delay_ms(50);
//								Dynamx_MovBwd_Interpolate(8,LEVEL3,IKCALC_ENABLE);
//								Nav_TurnAround(TURN_RIGHT);
//								Dynamx_MovFwd4cm_Interpolate(4,LEVEL3,IKCALC_ENABLE);
//								TRACER_STAT=TRACER_BLACK;
//							}
//							TCSlave_Check();
//							if (TRACER_STAT==TRACER_WHITE)
//							{
//								lcd_display_clear();
//								lcd_gotoxy(0,0);sprintf(lcd,"TRACER STATS");lcd_putstr(lcd);
//								lcd_gotoxy(0,1);sprintf(lcd,"WHITE");lcd_putstr(lcd);
//								delay_ms(50);
//								Dynamx_MovBwd_Interpolate(8,LEVEL3,IKCALC_ENABLE);
//								Nav_TurnAround(TURN_RIGHT);
//								Dynamx_MovFwd4cm_Interpolate(4,LEVEL3,IKCALC_ENABLE);
//								TRACER_STAT=TRACER_BLACK;
//							}
//							if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==6))break;
//							if((FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==2)){Dynamx_MovFwd4cm_Interpolate(4,50,IKCALC_DISABLE);break;}
//							if(FlameFrontDigi[0]==4)break;
//						}
//					}
//
//				}
//
//			}
//
//
//		}
//		else if((FIRESCAN_DIRECTION==SCAN_LEFT) || (FOLLOW_FLAG==KANAN))
//		{
//			if(((Ping[PING_UP_LEFT] <= 10 && Ping[PING_ASKEW_LEFT] > 30) && (Ping[PING_FRONT]>25) && (Ping[PING_ASKEW_RIGHT]<12)) && (Ping[PING_LEFT]>20))
//			{
//				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
//
//				if(((Ping[PING_UP_LEFT] <= 10 && Ping[PING_ASKEW_LEFT] > 30) && (Ping[PING_FRONT]>25) && (Ping[PING_ASKEW_RIGHT]<12)) && (Ping[PING_LEFT]>20))
//				{
//					if(Ping[PING_ASKEW_LEFT]<10)
//					{
//						Dynamx_MovBwd_Interpolate(4,LEVEL4,IKCALC_ENABLE);
//					}
//
//					Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_CLOSE,IKCALC_DISABLE);
//
//					while(Ping[PING_FRONT]>20)
//					{
//						Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
//						CNT++;
//						if(CNT>=4){CNT=0;break;}
//					}
//					while(Ping[PING_FRONT]<20)
//					{
//						Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
//						CNT++;
//						if(CNT>=4){CNT=0;break;}
//					}
//
//						Dynamx_MovFwd4cm_Interpolate(4,LEVEL3,IKCALC_ENABLE);
//						Dynamx_MovFwd4cm_Interpolate(4,LEVEL3,IKCALC_ENABLE);
//
//					if(UV_Lock==UVLOCK_ACTIVE)
//					{
//						TRACER_STAT=TRACER_BLACK;
//						BW_PID_Init_Furniture();
//						for(g=0;g<=5;g++)
//						{
//							BW_FollowCounter_Right(1);
//
//							TCSlave_Check();
//							if (TRACER_STAT==TRACER_WHITE)
//								{
//									lcd_display_clear();
//									lcd_gotoxy(0,0);sprintf(lcd,"TRACER STATS");lcd_putstr(lcd);
//									lcd_gotoxy(0,1);sprintf(lcd,"WHITE");lcd_putstr(lcd);
//									delay_ms(50);
//
//									Dynamx_MovBwd_Interpolate(8,LEVEL6,IKCALC_ENABLE);
//									Nav_TurnAround(TURN_LEFT);
//									Dynamx_MovFwd4cm_Interpolate(4,LEVEL3,IKCALC_ENABLE);
//									TRACER_STAT=TRACER_BLACK;
//
//								}
//
//							if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==1) || (FlameSenseDigi[0]==7))break;
//							if(FlameFrontDigi[0]==4)break;
//						}
//					}
//				}
//			}
//		}
//	}
}


/* func      : void PID_BWFollowTracer_Right(void)
 * brief     : PID Calculation and actuate control signal
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Thursday, February 9th 2017)
 * Revised BY: Hafidin (Wed, Feb 22th 2017)
 * 			   Ver.2 -> Toni (Mon, November 6th 2017)
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */
void BW_FollowTracer_Right_Interpolate(void)
{
	FOLLOW_TRACER_STATE = 1;
	RIGHT_FOLLOW_STATE = 1;

	TRACER_STAT=TRACER_BLACK;

	FOLLOW_CALC=KANAN;
	FOLLOWMODE_FLAG=FOLLOW_TRACER_WHITE;

	while((TCS3200_SLV_DATA[1]!=COLOUR_BLACK))
	{
		TCS3200_Transmit(UART5,CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)break;

		if(TRACER_STAT == TRACER_BLACK)break;

		if ((Ping[PING_FRONT]<=FRONT_THRESHOLD))
		{
			TCS3200_Transmit(UART5,CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)break;

			Dynamx_Rot_Left_IK(800,STEP3);
		}

		else
		{
			if (TRACER_STAT==TRACER_BLACK)break;

			TCS3200_Transmit(UART5,CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)break;

			PID_BWFollowTracer_Right_Interpolate();

			TCS3200_Transmit(UART5,CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)break;

			if (TRACER_STAT==TRACER_WHITE)break;
		}
		TCS3200_Transmit(UART5,CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)break;

	}
	FOLLOW_CALC=KOSONG;
	RIGHT_FOLLOW_STATE = 0;
	FOLLOW_TRACER_STATE = 0;
}


void PID_BWFollowTracer_Right_Interpolate(void)
{
	int OVERRIDE=0;

	while(OVERRIDE==0)
	{
		TCS3200_Transmit(UART5,CMD_GET_TRACER);
		if (TRACER_STAT==TRACER_BLACK)break;
		if (TCS3200_SLV_DATA[1] == COLOUR_BLACK)break;

		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			if ( (Ping[PING_ASKEW_RIGHT]<=PID_F_R.set_point_upper) && (Ping[PING_ASKEW_RIGHT]>=PID_F_R.set_point_lower) )
				{
					if ((Ping[PING_FRONT]<=FRONT_THRESHOLD))
					{
						Dynamx_Rot_Left_IK(800,STEP3);

						TCS3200_Transmit(UART5,CMD_GET_TRACER);
						if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)break;
					}

					if(OVERRIDE==1){break;}

					TCS3200_Transmit(UART5,CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)break;

					if (OVERRIDE==0)
					{
						TCS3200_Transmit(UART5,CMD_GET_TRACER);
						if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)break;
						if (TRACER_STAT==TRACER_BLACK)break;

						if(BW_LOCATION[0]==LOCATION_ROOM)
						{
							Dynamx_MovFwd_Interpolate_6S(4,400,IKCALC_ENABLE);
						}
						else
						{
							if(SHIFT_ALGORITHM_FLAG == SHIFT_ALGORITHM_ACTIVE)
							{
								Dynamx_MovFwd_Interpolate_6S(4, 400, IKCALC_ENABLE);
							}
							else
							{
								Dynamx_MovFwd_Interpolate_6S(4, 400, IKCALC_ENABLE);
							}
						}
						if (TRACER_STAT==TRACER_BLACK)break;
						OVERRIDE=1;
					}

				}

			//KONDISI ROBOT JAUH DARI DINDING
			else if ( Ping[PING_ASKEW_RIGHT]>PID_F_R.set_point_upper )
				{
					if ((Ping[PING_FRONT]<=FRONT_THRESHOLD))
					{
						Dynamx_Rot_Left_IK(800,STEP3);

						TCS3200_Transmit(UART5,CMD_GET_TRACER);
						if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)break;
					}

					if(OVERRIDE==1){break;}

					TCS3200_Transmit(UART5,CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)break;

					if (OVERRIDE==0)
					{
						TCS3200_Transmit(UART5,CMD_GET_TRACER);
						if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)break;

						TCS3200_Transmit(UART5,CMD_GET_TRACER);
						if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)break;

						if(BW_LOCATION[0]==LOCATION_ROOM)
						{
							Dynamx_MoveCurveRight_IK(400,1,&PID_F_R.pid_value[0]);

							TCS3200_Transmit(UART5,CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)break;
						}
						else
						{
							if(SHIFT_ALGORITHM_FLAG == SHIFT_ALGORITHM_ACTIVE)
							{
								Dynamx_MoveCurveRight_IK(400,1,&PID_F_R.pid_value[0]);

								TCS3200_Transmit(UART5,CMD_GET_TRACER);
								if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)break;
							}
							else
							{
								Dynamx_MoveCurveRight_IK(400,1,&PID_F_R.pid_value[0]);

								TCS3200_Transmit(UART5,CMD_GET_TRACER);
								if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)break;
							}

						}
						TCS3200_Transmit(UART5,CMD_GET_TRACER);
						if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)break;
						OVERRIDE=1;
					}

				}

			//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( Ping[PING_ASKEW_RIGHT]<PID_F_R.set_point_lower )
				{
					if ((Ping[PING_FRONT]<=FRONT_THRESHOLD))
					{
						Dynamx_Rot_Left_IK(800,STEP3);

						TCS3200_Transmit(UART5,CMD_GET_TRACER);
						if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)break;
					}

					TCS3200_Transmit(UART5,CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)break;

					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						TCS3200_Transmit(UART5,CMD_GET_TRACER);
						if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)break;

						TCS3200_Transmit(UART5,CMD_GET_TRACER);
						if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)break;

						if(BW_LOCATION[0]==LOCATION_ROOM)
						{
							Dynamx_MoveCurveLeft_IK(400,1,&PID_F_R.pid_value[0]);

							TCS3200_Transmit(UART5,CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)break;
						}
						else
						{
							if(SHIFT_ALGORITHM_FLAG == SHIFT_ALGORITHM_ACTIVE)
							{
								Dynamx_MoveCurveLeft_IK(400,1,&PID_F_R.pid_value[0]);

								TCS3200_Transmit(UART5,CMD_GET_TRACER);
								if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)break;
							}
							else
							{
								Dynamx_MoveCurveLeft_IK(400,1,&PID_F_R.pid_value[0]);

								TCS3200_Transmit(UART5,CMD_GET_TRACER);
								if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)break;
							}

						}
						TCS3200_Transmit(UART5,CMD_GET_TRACER);
						if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)break;
						OVERRIDE=1;
					}

				}
		}
	}
}


void BW_FollowTracer_Left_Interpolate(void)
{
	LEFT_FOLLOW_STATE = 1;
	FOLLOW_TRACER_STATE = 1;

	TRACER_STAT=TRACER_BLACK;

	FOLLOW_CALC=KIRI;
	FOLLOWMODE_FLAG=FOLLOW_TRACER_WHITE;

	while((TCS3200_SLV_DATA[1]!=COLOUR_WHITE))
	{
		TCS3200_Transmit(UART5,CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)break;
		if(TRACER_STAT == TRACER_WHITE)break;

		if ((Ping[PING_FRONT]<=FRONT_THRESHOLD))
		{
			if (TRACER_STAT==TRACER_WHITE)break;

			TCS3200_Transmit(UART5,CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)break;

			Dynamx_Rot_Right_IK(800,STEP3);

		}
		else
		{
			TCS3200_Transmit(UART5,CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)break;
			if(TRACER_STAT == TRACER_WHITE)break;

			PID_BWFollowTracer_Left_Interpolate();

			TCS3200_Transmit(UART5,CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)break;
			if(TRACER_STAT == TRACER_WHITE)break;
		}

		TCS3200_Transmit(UART5,CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)break;
	}
	FOLLOW_CALC=KOSONG;
	LEFT_FOLLOW_STATE = 0;
	FOLLOW_TRACER_STATE = 0;
}


void PID_BWFollowTracer_Left_Interpolate(void)
{
	int OVERRIDE=0;

	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			TCS3200_Transmit(UART5,CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)break;

			//KONDISI ROBOT SESUAI
			if ( (Ping[PING_ASKEW_LEFT]<=PID_F_L.set_point_upper) && (Ping[PING_ASKEW_LEFT]>=PID_F_L.set_point_lower) )
				{
					if ((Ping[PING_FRONT]<=FRONT_THRESHOLD))
					{
						Dynamx_Rot_Right_IK(800,STEP3);

						TCS3200_Transmit(UART5,CMD_GET_TRACER);
						if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)break;

					}
					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						TCS3200_Transmit(UART5,CMD_GET_TRACER);
						if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)break;

						if(BW_LOCATION[0]==LOCATION_ROOM)
						{
							Dynamx_MovFwd_Interpolate_6S(4,400,IKCALC_ENABLE);
						}
						else
						{
							if(SHIFT_ALGORITHM_FLAG == SHIFT_ALGORITHM_ACTIVE)
							{
								Dynamx_MovFwd_Interpolate_6S(4, 400, IKCALC_ENABLE);
							}
							else
							{
								Dynamx_MovFwd_Interpolate_6S(4, 400, IKCALC_ENABLE);
							}
						}
						TCS3200_Transmit(UART5,CMD_GET_TRACER);
						if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)break;
						OVERRIDE=1;
					}
				}

//KONDISI ROBOT DEKAT DARI DINDING
			else if ( Ping[PING_ASKEW_LEFT]<PID_F_L.set_point_lower )
				{
					if ((Ping[PING_FRONT]<=FRONT_THRESHOLD))
					{
						TCS3200_Transmit(UART5,CMD_GET_TRACER);
						if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)break;

						Dynamx_Rot_Right_IK(800,STEP3);
					}

					if(OVERRIDE==1){break;}

					TCS3200_Transmit(UART5,CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)break;

					if (OVERRIDE==0)
					{
						TCS3200_Transmit(UART5,CMD_GET_TRACER);
						if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)break;

						if(BW_LOCATION[0]==LOCATION_ROOM)
						{
							Dynamx_MoveCurveRight_IK(400,1,&PID_F_L.pid_value[0]);

							TCS3200_Transmit(UART5,CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)break;
						}
						else
						{
							if(SHIFT_ALGORITHM_FLAG == SHIFT_ALGORITHM_ACTIVE)
							{
								Dynamx_MoveCurveRight_IK(400,1,&PID_F_L.pid_value[0]);

								TCS3200_Transmit(UART5,CMD_GET_TRACER);
								if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)break;
							}
							else
							{
								Dynamx_MoveCurveRight_IK(400,1,&PID_F_L.pid_value[0]);

								TCS3200_Transmit(UART5,CMD_GET_TRACER);
								if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)break;
							}
						}

						TCS3200_Transmit(UART5,CMD_GET_TRACER);
						if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)break;
						OVERRIDE=1;
					}
				}


//KONDISI ROBOT JAUH DENGAN DINDING
			else if ( Ping[PING_ASKEW_LEFT]>PID_F_L.set_point_upper)
				{
					if ((Ping[PING_FRONT]<=FRONT_THRESHOLD))
					{
						Dynamx_Rot_Right_IK(800,STEP3);

						TCS3200_Transmit(UART5,CMD_GET_TRACER);
						if(TCS3200_SLV_DATA[1]==COLOUR_WHITE)break;
						if (TRACER_STAT==TRACER_WHITE)break;
					}

					if(OVERRIDE==1){break;}

					TCS3200_Transmit(UART5,CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)break;

					if (OVERRIDE==0)
					{
						TCS3200_Transmit(UART5,CMD_GET_TRACER);
						if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)break;

						if(BW_LOCATION[0]==LOCATION_ROOM)
						{
							Dynamx_MoveCurveLeft_IK(400,1,&PID_F_L.pid_value[0]);

							TCS3200_Transmit(UART5,CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)break;
						}
						else
						{
							if(SHIFT_ALGORITHM_FLAG == SHIFT_ALGORITHM_ACTIVE)
							{
								Dynamx_MoveCurveLeft_IK(400,1,&PID_F_L.pid_value[0]);

								TCS3200_Transmit(UART5,CMD_GET_TRACER);
								if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)break;
							}
							else
							{
								Dynamx_MoveCurveLeft_IK(400,1,&PID_F_L.pid_value[0]);

								TCS3200_Transmit(UART5,CMD_GET_TRACER);
								if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)break;
							}
						}

						TCS3200_Transmit(UART5,CMD_GET_TRACER);
						if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)break;
						OVERRIDE=1;
					}
				}
			}
		}
}


/* func      : void BWFollowCarpet_Right(int CARPET_CODE, int FOLLOW_MODE)
 * brief     : Hexapod Dynamixel Wall Following Right Rule using PID controller until BW detects desired carpet
 * param     : 	int CARPET CODE:
 * 					COLOUR_NONE		-> 0
 * 					COLOUR_BLACK 	-> 1
 * 					COLOUR_GRAY		-> 2
 * 					COLOUR_WHITE	-> 3
 * 					COLOUR_RED		-> 4
 * 					COLOUR_BLUE		-> 5
 *
 * 				int FOLLOW_MODE:
 * 					NORMAL 	-> 1
 * 					INVERSE -> 2
 * retval    : N/A
 * Ver       : 3
 * written By: Ryan (Friday, February 10th 2017)
 * Revised By: Ver.2 -> Hafidin (Wed, Feb 22th 2017)
 * 			   Ver.3 -> Ryan (Mon, April 4th 2017)
 * 					FOLLOWMODE OPTIMIZATION ADDED
 * 			   Ver.4 -> Toni (Mon, November 6th 2017)
 * programmer's Note:
 *
 */

// fungsi yang masih dipakai yogi

void BWFollowCarpet_Right_Interpolate(unsigned int CARPET_CODE, int FOLLOW_MODE)
{
	TCS3200_Transmit(UART5,CMD_GET_TRACER);
	RIGHT_FOLLOW_STATE = 1;
	COLOUR_BUF = CARPET_CODE;
	FOLLOW_CARPET_MODE = FOLLOW_MODE;

	FOLLOWMODE_FLAG=FOLLOW_CARPET_ACTIVE;
	FOLLOW_CALC=KANAN;

	switch(FOLLOW_MODE)
	{
		case NORMAL:
				{
					while( (TCS3200_SLV_DATA[1]==CARPET_CODE)/* && (CAT_FLAG==CAT_NOT_DETECTED)*/ )
					{
						TCS3200_Transmit(UART5,CMD_GET_TRACER);
						if(TCS3200_SLV_DATA[1] != CARPET_CODE){break;}

						if ((Ping[PING_FRONT]<=FRONT_THRESHOLD) && (SHARP[IR_FRONT] <= FRONT_THRESHOLD))
						{
							TCS3200_Transmit(UART5,CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1] != CARPET_CODE){break;}

							Dynamx_Rot_Left_IK(LEVEL6,STEP4);
						}
						else
						{
							TCS3200_Transmit(UART5,CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1] != CARPET_CODE){break;}

							PID_BWFollowCarpet_Right_Interpolate(CARPET_CODE, FOLLOW_MODE);

							TCS3200_Transmit(UART5,CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1] != CARPET_CODE)break;
						}

						TCS3200_Transmit(UART5,CMD_GET_TRACER);
						if(TCS3200_SLV_DATA[1] != CARPET_CODE){break;}
					}
				}break;


		case INVERSE:
				{
					while( (TCS3200_SLV_DATA[1]!=CARPET_CODE) /*&& (CAT_FLAG==CAT_NOT_DETECTED)*/ )
					{
						TCS3200_Transmit(UART5,CMD_GET_TRACER);
						if(TCS3200_SLV_DATA[1] == CARPET_CODE){break;}

						TCS3200_Transmit(UART5,CMD_GET_TRACER);
						if(TCS3200_SLV_DATA[1] == CARPET_CODE){break;}

						if ((Ping[PING_FRONT]<=FRONT_THRESHOLD) && (SHARP[IR_FRONT] <= FRONT_THRESHOLD))
						{
							TCS3200_Transmit(UART5,CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1] == CARPET_CODE){break;}

							Dynamx_Rot_Left_IK(LEVEL6,STEP4);						}
						else
						{
							TCS3200_Transmit(UART5,CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]== CARPET_CODE){break;}

							PID_BWFollowCarpet_Right_Interpolate(CARPET_CODE, FOLLOW_MODE);

							TCS3200_Transmit(UART5,CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1] == CARPET_CODE){break;}
						}
						TCS3200_Transmit(UART5,CMD_GET_TRACER);
						if(TCS3200_SLV_DATA[1]== CARPET_CODE){break;}
					}
				}break;
	}
	FOLLOW_CALC=KOSONG;
	COLOUR_BUF = 4;
	FOLLOW_CARPET_MODE = 4;
	RIGHT_FOLLOW_STATE = 0;
}


/* func      : void PID_BWFollowCarpet_Right(void)
 * brief     : PID Calculation and actuate control signal
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Friday, February 10th 2017)
 * Revised BY: Hafidin (Wed, Feb 22th 2017)
 * 			   Ver.2 -> Toni (Mon, November 6th 2017)
 * programmer's Note: This function MUST be called int the corresponding wall following algorithm
 *
 */

// fungsi nya masih dipakai yogi

void PID_BWFollowCarpet_Right_Interpolate(unsigned int CARPET_CODE, unsigned int MODE)
{
	int OVERRIDE=0;

	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;

	while(OVERRIDE==0)
	{
		TCS3200_Transmit(UART5,CMD_GET_TRACER);
		if(MODE == INVERSE)
		{
			if(TCS3200_SLV_DATA[1] == CARPET_CODE)break;
		}
		else if(MODE == NORMAL)
		{
			if(TCS3200_SLV_DATA[1] != CARPET_CODE)break;

		}

		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			if ( (Ping[PING_ASKEW_RIGHT]<=PID_F_R.set_point_upper) && (Ping[PING_ASKEW_RIGHT]>=PID_F_R.set_point_lower) )
			{
				if ((Ping[PING_FRONT]<=FRONT_THRESHOLD) && (SHARP[IR_FRONT] <= FRONT_THRESHOLD))
				{
					Dynamx_Rot_Left_IK(LEVEL6,STEP4);
				}

				if(OVERRIDE==1){break;}

				if (OVERRIDE==0)
				{
					TCS3200_Transmit(UART5,CMD_GET_TRACER);
					if(MODE == INVERSE)
					{
						if(TCS3200_SLV_DATA[1] == CARPET_CODE)break;
					}
					else if(MODE == NORMAL)
					{
						if(TCS3200_SLV_DATA[1] != CARPET_CODE)break;
					}

					if(SHIFT_ALGORITHM_FLAG == SHIFT_ALGORITHM_ACTIVE)
					{
						TCS3200_Transmit(UART5,CMD_GET_TRACER);
						if(MODE == INVERSE)
						{
							if(TCS3200_SLV_DATA[1] == CARPET_CODE)break;
						}
						else if(MODE == NORMAL)
						{
							if(TCS3200_SLV_DATA[1] != CARPET_CODE)break;
						}

						Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
					}
					else
					{
						TCS3200_Transmit(UART5,CMD_GET_TRACER);
						if(MODE == INVERSE)
						{
							if(TCS3200_SLV_DATA[1] == CARPET_CODE)break;
						}
						else if(MODE == NORMAL)
						{
							if(TCS3200_SLV_DATA[1] != CARPET_CODE)break;
						}
						Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
					}
					OVERRIDE=1;
				}

			}

//KONDISI ROBOT JAUH DARI DINDING
			else if ( Ping[PING_ASKEW_RIGHT]>PID_F_R.set_point_upper )
				{
					if ((Ping[PING_FRONT]<=FRONT_THRESHOLD) && (SHARP[IR_FRONT] <= FRONT_THRESHOLD))
					{
						Dynamx_Rot_Left_IK(LEVEL6,STEP4);
					}

					if(OVERRIDE==1){break;}

					TCS3200_Transmit(UART5,CMD_GET_TRACER);
					if(MODE == INVERSE)
					{
						if(TCS3200_SLV_DATA[1] == CARPET_CODE)break;
					}
					else if(MODE == NORMAL)
					{
						if(TCS3200_SLV_DATA[1] != CARPET_CODE)break;
					}

					if (OVERRIDE==0)
					{
						TCS3200_Transmit(UART5,CMD_GET_TRACER);

						if(MODE == INVERSE)
						{
							if(TCS3200_SLV_DATA[1] == CARPET_CODE)break;
						}
						else if(MODE == NORMAL)
						{
							if(TCS3200_SLV_DATA[1] != CARPET_CODE)break;
						}

						if(SHIFT_ALGORITHM_FLAG == SHIFT_ALGORITHM_ACTIVE)
						{
							TCS3200_Transmit(UART5,CMD_GET_TRACER);
							if(MODE == INVERSE)
							{
								if(TCS3200_SLV_DATA[1] == CARPET_CODE)break;
							}
							else if(MODE == NORMAL)
							{
								if(TCS3200_SLV_DATA[1] != CARPET_CODE)break;
							}
							Dynamx_MoveCurveRight_IK(LEVEL6,1,&PID_F_R.pid_value[0]);
						}
						else
						{
							TCS3200_Transmit(UART5,CMD_GET_TRACER);
							if(MODE == INVERSE)
							{
								if(TCS3200_SLV_DATA[1] == CARPET_CODE)break;
							}
							else if(MODE == NORMAL)
							{
								if(TCS3200_SLV_DATA[1] != CARPET_CODE)break;
							}
							Dynamx_MoveCurveRight_IK(LEVEL6,1,&PID_F_R.pid_value[0]);
						}
						OVERRIDE = 1;
					}

				}

//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( Ping[PING_ASKEW_RIGHT]<PID_F_R.set_point_lower )
				{
					if ((Ping[PING_FRONT]<=FRONT_THRESHOLD) && (SHARP[IR_FRONT] <= FRONT_THRESHOLD))
					{
						Dynamx_Rot_Left_IK(LEVEL6,STEP4);
					}

					TCS3200_Transmit(UART5,CMD_GET_TRACER);
					if(MODE == INVERSE)
					{
						if(TCS3200_SLV_DATA[1] == CARPET_CODE)break;
					}
					else if(MODE == NORMAL)
					{
						if(TCS3200_SLV_DATA[1] != CARPET_CODE)break;

					}
					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						TCS3200_Transmit(UART5,CMD_GET_TRACER);

						if(MODE == INVERSE)
						{
							if(TCS3200_SLV_DATA[1] == CARPET_CODE)break;
						}
						else if(MODE == NORMAL)
						{
							if(TCS3200_SLV_DATA[1] != CARPET_CODE)break;
						}

						if(SHIFT_ALGORITHM_FLAG == SHIFT_ALGORITHM_ACTIVE)
						{
							TCS3200_Transmit(UART5,CMD_GET_TRACER);
							if(MODE == INVERSE)
							{
								if(TCS3200_SLV_DATA[1] == CARPET_CODE)break;
							}
							else if(MODE == NORMAL)
							{
								if(TCS3200_SLV_DATA[1] != CARPET_CODE)break;
							}
							Dynamx_MoveCurveLeft_IK(LEVEL6,1,&PID_F_R.pid_value[0]);
						}
						else
						{
							TCS3200_Transmit(UART5,CMD_GET_TRACER);
							if(MODE == INVERSE)
							{
								if(TCS3200_SLV_DATA[1] == CARPET_CODE)break;
							}
							else if(MODE == NORMAL)
							{
								if(TCS3200_SLV_DATA[1] != CARPET_CODE)break;
							}
							Dynamx_MoveCurveLeft_IK(LEVEL6,1,&PID_F_R.pid_value[0]);
						}
						OVERRIDE=1;
					}

				}
			}
		}

	}

/* func      : void BWFollowCarpet_Left(int CARPET_CODE, int FOLLOW_MODE)
 * brief     : Hexapod Dynamixel Wall Following Left Rule using PID controller until BW detects desired carpet
 * param     : 	int CARPET CODE:
 * 					COLOUR_NONE		-> 0
 * 					COLOUR_BLACK 	-> 1
 * 					COLOUR_GRAY		-> 2
 * 					COLOUR_WHITE	-> 3
 * 					COLOUR_RED		-> 4
 * 					COLOUR_BLUE		-> 5
 *
 * 				int FOLLOW_MODE:
 * 					NORMAL 	-> 1
 * 					INVERSE -> 2
 * retval    : N/A
 * Ver       : 3
 * written By: Ryan (Friday, February 10th 2017)
 * Revised By: Ver. 2 -> Hafidin (Wed, Feb 22th 2017)
 * 				Ver.3 -> Ryan (Mon, April 4th 2017)
 * 					FOLLOWMODE OPTIMIZATION ADDED
 * 				Ver.4 -> Toni (Mon, November 6th 2017)
 * programmer's Note:
 *
 */

void BWFollowCarpet_Left_Interpolate(int CARPET_CODE, int FOLLOW_MODE)
{
//	FOLLOWMODE_FLAG=FOLLOW_CARPET_ACTIVE;
	LEFT_FOLLOW_STATE = 1;
	COLOUR_BUF = CARPET_CODE;
	FOLLOW_CARPET_MODE = FOLLOW_MODE;
	FOLLOW_CALC=KIRI;

	switch(FOLLOW_MODE)
	{
		case NORMAL:
				{
					while((TCS3200_SLV_DATA[1]==CARPET_CODE))
					{
						TCS3200_Transmit(UART5,CMD_GET_TRACER);
						if(TCS3200_SLV_DATA[1]!= CARPET_CODE){break;}

						if ((Ping[PING_FRONT]<=FRONT_THRESHOLD) && (SHARP[IR_FRONT] <= FRONT_THRESHOLD))
						{
							TCS3200_Transmit(UART5,CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]!= CARPET_CODE){break;}

							Dynamx_Rot_Right_IK(LEVEL6,STEP4);
						}
						else
						{
							TCS3200_Transmit(UART5,CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]!= CARPET_CODE){break;}

							PID_BWFollowCarpet_Left_Interpolate(CARPET_CODE, FOLLOW_MODE);

							TCS3200_Transmit(UART5,CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1]!= CARPET_CODE){break;}
						}

						TCS3200_Transmit(UART5,CMD_GET_TRACER);
						if(TCS3200_SLV_DATA[1]!= CARPET_CODE){break;}
					}
				}break;

		case INVERSE:
				{
					while((TCS3200_SLV_DATA[1]!=CARPET_CODE))
					{
						TCS3200_Transmit(UART5,CMD_GET_TRACER);
						if(TCS3200_SLV_DATA[1]== CARPET_CODE){break;}
						if ((Ping[PING_FRONT]<=FRONT_THRESHOLD) && (SHARP[IR_FRONT] <= FRONT_THRESHOLD))
						{
							TCS3200_Transmit(UART5,CMD_GET_TRACER);
							if(TCS3200_SLV_DATA[1] == CARPET_CODE){break;}

							Dynamx_Rot_Right_IK(LEVEL6,STEP4);
						}
						else
						{
							TCS3200_Transmit(UART5,CMD_GET_TRACER);
						    if(TCS3200_SLV_DATA[1]== CARPET_CODE){break;}

							PID_BWFollowCarpet_Left_Interpolate(CARPET_CODE, FOLLOW_MODE);

							TCS3200_Transmit(UART5,CMD_GET_TRACER);
						    if(TCS3200_SLV_DATA[1]== CARPET_CODE){break;}
						}

						TCS3200_Transmit(UART5,CMD_GET_TRACER);
						if(TCS3200_SLV_DATA[1]== CARPET_CODE){break;}
					}
				}break;
	}

	FOLLOW_CALC=KOSONG;
	FOLLOW_CARPET_MODE = 4;
	COLOUR_BUF = 4;
	LEFT_FOLLOW_STATE = 0;
}

void PID_BWFollowCarpet_Left_Interpolate(unsigned int CARPET_CODE, unsigned int FOLLOW_MODE)
{
	int OVERRIDE=0;

	static int WINDUP_RIGHT_COUNTER=0;
	static int WINDUP_LEFT_COUNTER=0;

	while(OVERRIDE==0)
	{
		TCS3200_Transmit(UART5,CMD_GET_TRACER);
		if(MODE == INVERSE)
		{
			if(TCS3200_SLV_DATA[1] == CARPET_CODE)break;
		}
		else if(MODE == NORMAL)
		{
			if(TCS3200_SLV_DATA[1] != CARPET_CODE)break;

		}

		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			if ( (Ping[PING_ASKEW_LEFT]<=PID_F_R.set_point_upper) && (Ping[PING_ASKEW_LEFT]>=PID_F_R.set_point_lower) )
			{
				if ((Ping[PING_FRONT]<=FRONT_THRESHOLD) && (SHARP[IR_FRONT] <= FRONT_THRESHOLD))
				{
					Dynamx_Rot_Right_IK(LEVEL6,STEP4);
				}

				if(OVERRIDE==1){break;}

				if (OVERRIDE==0)
				{
					TCS3200_Transmit(UART5,CMD_GET_TRACER);
					if(MODE == INVERSE)
					{
						if(TCS3200_SLV_DATA[1] == CARPET_CODE)break;
					}
					else if(MODE == NORMAL)
					{
						if(TCS3200_SLV_DATA[1] != CARPET_CODE)break;
					}

					if(SHIFT_ALGORITHM_FLAG == SHIFT_ALGORITHM_ACTIVE)
					{
						TCS3200_Transmit(UART5,CMD_GET_TRACER);
						if(MODE == INVERSE)
						{
							if(TCS3200_SLV_DATA[1] == CARPET_CODE)break;
						}
						else if(MODE == NORMAL)
						{
							if(TCS3200_SLV_DATA[1] != CARPET_CODE)break;
						}

						Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
					}
					else
					{
						TCS3200_Transmit(UART5,CMD_GET_TRACER);
						if(MODE == INVERSE)
						{
							if(TCS3200_SLV_DATA[1] == CARPET_CODE)break;
						}
						else if(MODE == NORMAL)
						{
							if(TCS3200_SLV_DATA[1] != CARPET_CODE)break;
						}
						Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);
					}
					OVERRIDE=1;
				}

			}

//KONDISI ROBOT JAUH DARI DINDING
			else if ( Ping[PING_ASKEW_LEFT]>PID_F_R.set_point_upper )
				{
					if ((Ping[PING_FRONT]<=FRONT_THRESHOLD) && (SHARP[IR_FRONT] <= FRONT_THRESHOLD))
					{
						Dynamx_Rot_Right_IK(LEVEL6,STEP4);
					}

					if(OVERRIDE==1){break;}

					TCS3200_Transmit(UART5,CMD_GET_TRACER);
					if(MODE == INVERSE)
					{
						if(TCS3200_SLV_DATA[1] == CARPET_CODE)break;
					}
					else if(MODE == NORMAL)
					{
						if(TCS3200_SLV_DATA[1] != CARPET_CODE)break;
					}

					if (OVERRIDE==0)
					{
						TCS3200_Transmit(UART5,CMD_GET_TRACER);

						if(MODE == INVERSE)
						{
							if(TCS3200_SLV_DATA[1] == CARPET_CODE)break;
						}
						else if(MODE == NORMAL)
						{
							if(TCS3200_SLV_DATA[1] != CARPET_CODE)break;
						}

						if(SHIFT_ALGORITHM_FLAG == SHIFT_ALGORITHM_ACTIVE)
						{
							TCS3200_Transmit(UART5,CMD_GET_TRACER);
							if(MODE == INVERSE)
							{
								if(TCS3200_SLV_DATA[1] == CARPET_CODE)break;
							}
							else if(MODE == NORMAL)
							{
								if(TCS3200_SLV_DATA[1] != CARPET_CODE)break;
							}
							Dynamx_MoveCurveLeft_IK(LEVEL6,1,&PID_F_L.pid_value[0]);
						}
						else
						{
							TCS3200_Transmit(UART5,CMD_GET_TRACER);
							if(MODE == INVERSE)
							{
								if(TCS3200_SLV_DATA[1] == CARPET_CODE)break;
							}
							else if(MODE == NORMAL)
							{
								if(TCS3200_SLV_DATA[1] != CARPET_CODE)break;
							}
							Dynamx_MoveCurveLeft_IK(LEVEL6,1,&PID_F_L.pid_value[0]);
						}
						OVERRIDE = 1;
					}

				}

//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( Ping[PING_ASKEW_LEFT]<PID_F_R.set_point_lower )
				{
					if ((Ping[PING_FRONT]<=FRONT_THRESHOLD) && (SHARP[IR_FRONT] <= FRONT_THRESHOLD))
					{
						Dynamx_Rot_Right_IK(LEVEL6,STEP4);
					}

					TCS3200_Transmit(UART5,CMD_GET_TRACER);
					if(MODE == INVERSE)
					{
						if(TCS3200_SLV_DATA[1] == CARPET_CODE)break;
					}
					else if(MODE == NORMAL)
					{
						if(TCS3200_SLV_DATA[1] != CARPET_CODE)break;

					}
					if(OVERRIDE==1){break;}

					if (OVERRIDE==0)
					{
						TCS3200_Transmit(UART5,CMD_GET_TRACER);

						if(MODE == INVERSE)
						{
							if(TCS3200_SLV_DATA[1] == CARPET_CODE)break;
						}
						else if(MODE == NORMAL)
						{
							if(TCS3200_SLV_DATA[1] != CARPET_CODE)break;
						}

						if(SHIFT_ALGORITHM_FLAG == SHIFT_ALGORITHM_ACTIVE)
						{
							TCS3200_Transmit(UART5,CMD_GET_TRACER);
							if(MODE == INVERSE)
							{
								if(TCS3200_SLV_DATA[1] == CARPET_CODE)break;
							}
							else if(MODE == NORMAL)
							{
								if(TCS3200_SLV_DATA[1] != CARPET_CODE)break;
							}
							Dynamx_MoveCurveRight_IK(LEVEL6,1,&PID_F_L.pid_value[0]);
						}
						else
						{
							TCS3200_Transmit(UART5,CMD_GET_TRACER);
							if(MODE == INVERSE)
							{
								if(TCS3200_SLV_DATA[1] == CARPET_CODE)break;
							}
							else if(MODE == NORMAL)
							{
								if(TCS3200_SLV_DATA[1] != CARPET_CODE)break;
							}
							Dynamx_MoveCurveRight_IK(LEVEL6,1,&PID_F_L.pid_value[0]);
						}
						OVERRIDE=1;
					}

				}
			}
		}

	}
