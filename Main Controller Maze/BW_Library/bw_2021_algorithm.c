/*==============================================================================================
								   PROJECT BW 2021 Ver.1.0
								     BW ALGORITHM LIBRARY
===============================================================================================*/

#include "bw_2021_algorithm.h"
#include "bw_global_var.h"
#include "main.h"

void BW_Test_Menu(void)
{
	while(1)
	{
		while(BW_BUTTON_UNCLICKED)
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

			if(BW_BUTTON_CLICKED)break;

			switch(cntt)
			{
			case 0:
			{
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
				lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(5,2);sprintf(lcd,"NORMAL");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
			}break;

			case 1:
			{
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
				lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(3,2);sprintf(lcd,"OBSTAICLE");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
			}break;

			case 2:
			{
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
				lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(4,2);sprintf(lcd,"CAMPURAN");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
			}break;
			}

			if (cntt != buff){lcd_display_clear();}

			if (cntt > 2){ cntt = 0;}
			if (cntt < 0){ cntt = 2;}

			if(BW_BUTTON_CLICKED){break;}
		}

		delay_ms(100);

		while(1)
		{
			switch(cntt)
			{
			case 0:
			{
				Menu_Normal();
			}break;

			case 1:
			{
				Menu_Obstaicle();
			}break;

			case 2:
			{
				Menu_Umum();
			}break;
			}

		}
	}

}

void Menu_Normal(void)
{
	cntt = 0;
	while(1)
	{
		while(BW_BUTTON_UNCLICKED)
		{
			Dynamx_Mov_Static_Interpolate(LEVEL2,IKCALC_ENABLE);

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

			if(BW_BUTTON_CLICKED)break;

			switch(cntt)
			{
			case 0:
			{
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
				lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"MOVE FORWARD");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
			}break;

			case 1:
			{
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
				lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"F.COUNTER L");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
			}break;

			case 2:
			{
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
				lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"F.COUNTER R");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
			}break;

			case 3:
			{
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
				lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"SLIDE RIGHT");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
			}break;

			case 4:
			{
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
				lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"SLIDE LEFT");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
			}break;

			case 5:
			{
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
				lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"ROTASI KANAN");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
			}break;

			case 6:
			{
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
				lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"ROTASI KIRI");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
			}break;

			case 7:
			{
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
				lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"MOVE BACK");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
			}break;

			case 8:
			{
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
				lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"MOVE CURVE RIGHT");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
			}break;

			case 9:
			{
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
				lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"MOVE LEAN");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
			}break;

			case 10:
			{
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
				lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"FLW CLIMB R");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
			}break;

			case 11:
			{
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
				lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"MOV FWD MIRING");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
			}break;

			}

			if (cntt != buff){lcd_display_clear();}

			if (cntt > 11){ cntt = 0;}
			if (cntt < 0){ cntt = 11;}

			if(BW_BUTTON_CLICKED){break;}
		}

		delay_ms(100);

		while(BW_BUTTON_UNCLICKED)
		{
			if(BW_BUTTON_CLICKED)break;

			switch(cntt)
			{
			case 0:
			{
//				Dynamx_MovFwd4cm_Interpolate(400,800,IKCALC_ENABLE);
				Dynamx_MovFwd_Interpolate_6S(400,2500,IKCALC_ENABLE);
			}break;

			case 1:
			{
				if (taek == 0)
				{
					BW_PID_Init();
					taek = 63;
				}

				BW_FollowCounter_Left(100);
				if(BW_BUTTON_CLICKED){break;}
			}break;

			case 2:
			{
				if (taek == 0)
				{
					BW_PID_Init();
					taek = 63;
				}

				BW_FollowCounter_Right(100);
				if(BW_BUTTON_CLICKED){break;}

			}break;

			case 3:
			{
				Dynamx_Slide_Right_IK(100, 3000);
				if(BW_BUTTON_CLICKED){break;}
			}break;

			case 4:
			{
				Dynamx_Slide_Left_IK(100, 3000);
				if(BW_BUTTON_CLICKED){break;}

			}break;

			case 5:
			{
//				Dynamx_Rot_Right_IK(2000,STEP1);
				Dynamx_Rot_Right_IK(2000,STEP4);
				while(1){Dynamx_Mov_Static_Interpolate(LEVEL2,IKCALC_ENABLE);}
			}break;

			case 6:
			{
				Dynamx_Rot_Left_IK(2000,STEP4);
			}break;

			case 7:
			{
				Dynamx_MovBwd_Interpolate(400,2000,IKCALC_ENABLE);
			}break;

			case 8:
			{
				if (taek == 0)
				{
					BW_PID_Init();
					taek = 63;
				}
				Dynamx_MoveCurveRight_IK(2000,1,&PID_F_R.pid_value[0]);
			}break;

			case 9:
			{
				MODE_CAPIT=MODE_K1;
				Dynamx_Mov_Static_Interpolate(LEVEL2,IKCALC_ENABLE);
				Gripper_Down_K1();
				GRIPPER_LED_ON;
				Gripper_Open_K1();
				delay_ms(1000);
				Dynamx_MovLeanFwd_Interpolate(5000,1);
				Dynamx_Mov_Static_Interpolate(LEVEL2,IKCALC_ENABLE);
				MODE_CAPIT=MODE_NONE;
			}break;

			case 10:
			{
				STATIC_CLIMBING=0;
				while(1)
				{
					if (taek == 0)
					{
						BW_PID_Init_Obs();
						taek = 63;
					}
					BW_FollowCounter_Right_Climbing(1000);
				}
			}break;

			case 11:
			{
				STATIC_CLIMBING=0;
				while(1)
				{
					Dynamx_MovFwdMiring_Interpolate(OBS_LVL3,100,4);
				}
			}break;

			}

			if(BW_BUTTON_CLICKED)break;
		}
		delay_ms(100);
	}

}

void Menu_Obstaicle(void)
{
	cntt = 0;
	while(1)
	{
		while(BW_BUTTON_UNCLICKED)
		{
			int buff = cntt;
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

			Dynamx_Mov_Static_Obs(LEVEL3);
			if(BW_BUTTON_CLICKED)break;


			switch(cntt)
			{
			case 0:
			{
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
				lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"MAJU OBS");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
			}break;

			case 1:
			{
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
				lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"CURVE RIGHT");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
			}break;

			case 2:
			{
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
				lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"CURVE LEFT");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
			}break;

			case 3:
			{
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
				lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"F.Counter Right");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
			}break;

			case 4:
			{
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
				lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"F.Counter Left");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
			}break;

			case 5:
			{
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
				lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"Rot Obs Left");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
			}break;

			case 6:
			{
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
				lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"Rot Obs Right");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
			}break;

			case 7:
			{
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT MZ");lcd_putstr(lcd);
				lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"MOV BWD OBS");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
			}break;

			case 8:
			{
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT MZ");lcd_putstr(lcd);
				lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"MOV SLD-R OBS");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
			}break;

			case 9:
			{
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT MZ");lcd_putstr(lcd);
				lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"MOV SLD-L OBS");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
			}break;

			case 10:
			{
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT MZ");lcd_putstr(lcd);
				lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"LEAN FWD OBS");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
			}break;
			}

			if (cntt != buff){lcd_display_clear();}

			if (cntt > 10){ cntt = 0;}
			if (cntt < 0){ cntt = 10;}

			if(BW_BUTTON_CLICKED){break;}
		}

		delay_ms(200);

		while(BW_BUTTON_UNCLICKED)
		{
			if(BW_BUTTON_CLICKED)break;

			switch(cntt)
			{
			case 0:
			{
				Dynamx_MovFwd_Obstaicle_Interpolate(2000,100);
			}break;

			case 1:
			{
				if (taek == 0)
				{
					BW_PID_Init_Obs();
					taek = 63;
				}
				FOLLOW_CALC=KANAN_OBS;
				float oke = 100;

				Dynamx_MoveCurveRight_Obstaicle(1500,1,&oke);
			}break;

			case 2:
			{
				if (taek == 0)
				{
					BW_PID_Init_Obs();
					taek = 63;
				}
				FOLLOW_CALC=KIRI_OBS;
				float oke = 100;

				Dynamx_MoveCurveLeft_Obstaicle(1500,1,&oke);
			}break;

			case 3:
			{
				if (taek == 0)
				{
					BW_PID_Init_Obs();
					taek = 63;
				}

				BW_FollowCounter_Right_Obs(100);
				if(BW_BUTTON_CLICKED){break;}
			}break;

			case 4:
			{
				if (taek == 0)
				{
					BW_PID_Init_Obs();
					taek = 63;
				}

				BW_FollowCounter_Left_Obs(100);
				if(BW_BUTTON_CLICKED){break;}

			}break;

			case 5:
				{
					Dynamx_Rot_Obs_Left_IK(OBS_LVL4,STEP5);
					while(1){}
					if(BW_BUTTON_CLICKED){break;}

				}break;

			case 6:
				{
					Dynamx_Rot_Obs_Right_IK(OBS_LVL4,STEP3);
					while(1){}
					if(BW_BUTTON_CLICKED){break;}

				}break;

			case 7:
			{
				Dynamx_MovBwd_Obs_Interpolate(4,2500,IKCALC_ENABLE);
			}break;

			case 8:
			{
				Dynamx_Slide_Obs_Right_IK(100,OBS_LVL3);
			}break;

			case 9:
			{
				Dynamx_Slide_Obs_Left_IK(100,OBS_LVL3);
			}break;

			case 10:
			{
				Dynamx_Mov_Static_Obs(LEVEL2);
				Gripper_Down_K1();
				Gripper_Open_K1();
				Dynamx_MovLeanFwd_Obstaicle_Interpolate(OBS_LVL5,1);
				Dynamx_Mov_Static_Obs(LEVEL2);
			}break;

			}

			if(BW_BUTTON_CLICKED)break;
		}

		delay_ms(200);
	}
}

void Menu_Umum(void)
{
	cntt = 0;
	while(1)
	{
		while(BW_BUTTON_UNCLICKED)
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

			if(BW_BUTTON_CLICKED)break;

			switch(cntt)
			{
			case 0:
			{
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
				lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"FLAME TRACKING");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
			}break;

			case 1:
			{
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
				lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"EXTINGUISHER");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
			}break;

			case 2:
			{
				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
				lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"KOSONG");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
			}break;
			}

			if (cntt != buff){lcd_display_clear();}

			if (cntt > 2){ cntt = 0;}
			if (cntt < 0){ cntt = 2;}

			if(BW_BUTTON_CLICKED){break;}
		}

		delay_ms(200);

		while(1)
		{
			switch(cntt)
			{
			case 0:
			{
				lcd_display_clear();

				FlameTracking_Center();

				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FLAME MANTAP");lcd_putstr(lcd);

				while(BW_BUTTON_UNCLICKED)
				{
					Dynamx_Mov_Static_Interpolate(LEVEL5,IKCALC_ENABLE);
					if(BW_BUTTON_CLICKED)
					{
						while(BW_BUTTON_CLICKED){};
						break;
					}
				}
			}break;

			case 1:
			{
				FIRESCAN_DIRECTION = SCAN_RIGHT;
				FIREROOM_R1A_FLAG = FIREROOM_R1A_ACTIVE;

				BW_FireFight_V2();
			}break;

			}

		}

		delay_ms(200);
	}

}

void BW_Algorithm1_2023(void)
{
//	BW_LOCATION[1]= BW_LOCATION[0];
//	BW_LOCATION[0]= LOCATION_CORRIDOR;

//	Home_HallwaySC_Detector();

	BW_Start_Compas_Correction_S2();

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT MAZE");lcd_putstr(lcd);
	lcd_gotoxy(4,2);sprintf(lcd,"STRATEGY");lcd_putstr(lcd);
	lcd_gotoxy(6,3);sprintf(lcd,"K1");lcd_putstr(lcd);
	delay_ms(100);

	Home_To_K1_S2(HOME_FLAG_NEW);

	SZ1_To_K2_S2();
	SZ2_To_K3_S2();
	K3_To_SZ4();
	K5_To_Finish();

	SND_ACT_LED_OFF;

	lcd_display_clear();
	lcd_gotoxy(0,2);sprintf(lcd,"ALGORITHM 1 COMPLETED");lcd_putstr(lcd);
	delay_ms(200);
}

void BW_Algorithm2_2021(void)
{
	TRIAL2_2021();
}

void TRIAL2_2021(void)
{
	Nav_2_To_home();
	//	Nav_1_To_2();

	while (1)
	{
		Dynamx_Mov_Static_Interpolate(LEVEL5,IKCALC_ENABLE);
		lcd_gotoxy(0,0);sprintf(lcd,"TEST POINT OK");lcd_putstr(lcd);
	}

	BW_LOCATION[1]= BW_LOCATION[0];
	BW_LOCATION[0]= LOCATION_ROOM;

	H_IN_Room();

	BW_LOCATION[1]= BW_LOCATION[0];
	BW_LOCATION[0]= LOCATION_CORRIDOR;
}

void TRIAL1_2021(void)
{
	Nav_Home_To_1();

	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"BHATARA WIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,1);sprintf(lcd,"LOCATION :");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"ROOM 1");lcd_putstr(lcd);
	delay_ms(2000);
	lcd_display_clear();

	if(Ping[PING_LEFT])
	{
		Dynamx_Slide_Right_Interpolate(HEXSPD_MED,LEVEL4);
	}

	ROOM_NOW = ROOM1;

	H_Room_2021();

	ROOM_NOW = HALLWAY;

	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"BHATARA WIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,1);sprintf(lcd,"LOCATION :");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"HALLWAY 1");lcd_putstr(lcd);
	delay_ms(2000);
	lcd_display_clear();

	Nav_1_To_2();

	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"BHATARA WIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,1);sprintf(lcd,"LOCATION :");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"ROOM 2");lcd_putstr(lcd);
	delay_ms(2000);
	lcd_display_clear();

	ROOM_NOW = ROOM2;

//	H_Room_2();
	H_Room_2021();

	ROOM_NOW = HALLWAY;

	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"BHATARA WIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,1);sprintf(lcd,"LOCATION :");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"HALLWAY 2");lcd_putstr(lcd);
	delay_ms(2000);
	lcd_display_clear();

	Nav_2_To_home();

	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"BHATARA WIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,1);sprintf(lcd,"LOCATION :");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"HOME");lcd_putstr(lcd);
	delay_ms(2000);
	lcd_display_clear();
}

void SESI_2(void)
{

}

void Nav_Home_To_1(void)
{
	BW_PID_Init();
	BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,NORMAL);

	BW_PID_Init();

	for (int i=0; i<15; i++)
	{
		if (Ping[PING_FRONT] <= 24)break;
		BW_FollowCounter_Right(1);
		if (Ping[PING_FRONT] <= 24)break;
	}

//	if (Ping[PING_RIGHT] <= 14)
//	{
//		Dynamx_Slide_Left_Interpolate(HEXSPD_MED,LEVEL3);
//	}

	if(Ping[PING_R]>=20){
		Dynamx_Slide_Right_Interpolate(HEXSTEP_CLOSE,LEVEL3);
	}

	Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);

	Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR2,IKCALC_DISABLE);
	Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);

	while(Ping[PING_ASKEW_RIGHT]>=28){
		if(Ping[PING_ASKEW_RIGHT]<24)break;
		Dynamx_Rot_Right_IK(LEVEL2,HEXSTEP_VERYCLOSE);
		if(Ping[PING_ASKEW_RIGHT]<28)break;
	}

//	if(Ping[PING_ASKEW_RIGHT]+4 <= Ping[PING_RIGHT])
//	{
//		Dynamx_Rot_Left_Interpolate(LEVEL3,HEXSTEP_CLOSE,IKCALC_DISABLE);
//	}

	Dynamx_Mov_Static_Obs(LEVEL4);

	BW_PID_Init_Obs();
	for (int i=0; i<10; i++)
	{
		TCS3200_Transmit(UART5,CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)break;

		BW_FollowCounter_Right_Obs(1);

		TCS3200_Transmit(UART5,CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1] == COLOUR_WHITE)break;
	}

	BW_PID_Init_Obs_Far();
	for (int i=0; i<100; i++)
	{
		TCS3200_Transmit(UART5,CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)break;
		if (Ping[PING_LEFT] >= 45)break;

		BW_FollowCounter_Right_Obs(1);

		if (Ping[PING_LEFT] >= 45)break;
		TCS3200_Transmit(UART5,CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1] == COLOUR_BLACK)break;
	}

	BW_PID_Init_Obs_Far();
	BW_FollowCounter_Right_Obs(2);

	Dynamx_Mov_Static_Interpolate(LEVEL5,IKCALC_ENABLE);
	delay_ms(200);

	if(Ping[PING_RIGHT]<= 12)
	{
		Dynamx_Slide_Left_Interpolate(HEXSPD_MED,LEVEL4);
	}

	Dynamx_Rot_Left_IK(LEVEL5,HEXSTEP_FAR);


	BW_PID_Init();
	BWFollowCarpet_Left_Interpolate(COLOUR_BLACK,NORMAL);

	Dynamx_Slide_Left_Interpolate(HEXSTEP_FAR,LEVEL3);
	BW_PID_Init();
	BWFollowCarpet_Left_Interpolate(COLOUR_GRAY,NORMAL);

	BW_PID_Init();
	BW_FollowTracer_Left_Interpolate();
}

void Nav_Home_To_2(void)
{

}

void Nav_1_To_2(void)
{
	BW_PID_Init();
	BWFollowCarpet_Right_Interpolate(COLOUR_GRAY,INVERSE);

	BW_PID_Init();
	BW_FollowCounter_Right(3);

	BW_PID_Init();
	BWFollowCarpet_Right_Interpolate(COLOUR_BLACK,INVERSE);

	Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);

	Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_FAR,IKCALC_DISABLE);
	Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_FAR,IKCALC_DISABLE);
	Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_CLOSE,IKCALC_DISABLE);
//	Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_FAR,IKCALC_DISABLE);



//	Dynamx_Slide_Left_Interpolate(HEXSTEP_FAR,LEVEL3);

	if(Ping[PING_FRONT]<=FRONT_THRESHOLD)
	{
		Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
		if(Ping[PING_FRONT]<=FRONT_THRESHOLD)
		{
			Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
		}
	}

//	Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_FAR2,IKCALC_DISABLE);

	if(Ping[PING_RIGHT]+4 <= Ping[PING_ASKEW_RIGHT])
	{
		Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_MED,IKCALC_DISABLE);
		if(Ping[PING_RIGHT]+4 <= Ping[PING_ASKEW_RIGHT])
		{
			Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_MED,IKCALC_DISABLE);
		}
	}

	Dynamx_Mov_Static_Obs(LEVEL5);

	BW_PID_Init_Obs();
	BW_FollowCounter_Right_Obs(50);

	Dynamx_Mov_Static_Interpolate(LEVEL5,IKCALC_ENABLE);

	if(Ping[PING_RIGHT]<=18)
	{
		Dynamx_Slide_Left_Interpolate(HEXSPD_MED,LEVEL5);
	}

	Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_FAR2,IKCALC_DISABLE);

	Dynamx_Mov_Static_Interpolate(LEVEL5,IKCALC_ENABLE);
	delay_ms(100);
}

void Nav_1_To_Home(void)
{

}

void Nav_2_To_1(void)
{

}

void Nav_2_To_home(void)
{
	Dynamx_Mov_Static_Obs(LEVEL5);

	BW_PID_Init_Obs_Far();
	BW_FollowCounter_Left_Obs(50);

	BW_PID_Init_Obs_Far();
	while(Ping[PING_FRONT]>= 20)
	{
		if(Ping[PING_FRONT]<= 20)break;
		BW_FollowCounter_Left_Obs(1);
		if(Ping[PING_FRONT]<= 20)break;
	}

	Dynamx_Mov_Static_Interpolate(LEVEL3,IKCALC_ENABLE);

	Dynamx_MovFwd4cm_Interpolate(3,LEVEL4,IKCALC_DISABLE);

	TCS3200_Transmit(UART5,CMD_GET_TRACER);
	while(TCS3200_SLV_DATA[1]!=COLOUR_GRAY){
		TCS3200_Transmit(UART5,CMD_GET_TRACER);
		if (TCS3200_SLV_DATA[1]==COLOUR_GRAY)break;
		Dynamx_Slide_Right_Interpolate(HEXSTEP_CLOSE,LEVEL3);
		TCS3200_Transmit(UART5,CMD_GET_TRACER);
		if (TCS3200_SLV_DATA[1]==COLOUR_GRAY)break;
	}

	Dynamx_Slide_Right_Interpolate(HEXSTEP_FAR2,LEVEL3);

//	if(Ping[PING_LEFT]<= 20)
//	{
//		Dynamx_Slide_Right_Interpolate(HEXSPD_MED,LEVEL4);
//		if(Ping[PING_LEFT]<= 20)
//		{
//			Dynamx_Slide_Right_Interpolate(HEXSPD_MED,LEVEL4);
//		}
//	}
//
//	Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_FAR2,IKCALC_DISABLE);
//
//	if ((Ping[PING_LEFT]+4) <= (Ping[PING_ASKEW_LEFT]))
//	{
//		Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_MED,IKCALC_DISABLE);
//	}
//
//	BW_PID_Init();
//	BW_FollowCarpet_Left_Straight(COLOUR_BLACK,NORMAL);
//
//	BW_PID_Init();
//	BW_FollowCounter_Left(1);
//
//	BW_PID_Init();
//	BW_FollowCarpet_Left_Straight(COLOUR_BLACK,NORMAL);
//
//	BW_PID_Init();
//	BW_FollowCounter_Left(3);
//
////	Dynamx_Slide_Right_Interpolate(HEXSPD_MED,LEVEL4);
////	Dynamx_Slide_Right_Interpolate(HEXSPD_MED,LEVEL4);
//
//	Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_FAR2,IKCALC_DISABLE);

	Dynamx_Mov_Static_Interpolate(LEVEL4,IKCALC_ENABLE);
}

void H_Room_2021(void)
{
	USART3_PutChar(IN_ROOM_STAT);

	if (ROOM_NOW == ROOM1)
	{
		Dynamx_MovFwd4cm_Interpolate(12,LEVEL3,IKCALC_ENABLE);
		Dynamx_Rot_Right_IK(LEVEL3,HEXSTEP_FAR);
//		Dynamx_Rot_Left_IK(LEVEL3,HEXSTEP_FAR2);
//		Dynamx_Rot_Left_IK(LEVEL3,HEXSTEP_MED);

				Get_UV();
				while(UV_state==UVSTATE_INACTIVE){
					Get_UV();
					if (UV_state==UVSTATE_ACTIVE)break;
					Dynamx_Rot_Right_IK(LEVEL2,HEXSTEP_VERYCLOSE);
					Get_UV();
					if (UV_state==UVSTATE_ACTIVE)break;
				}

//				Dynamx_Rot_Right_IK(LEVEL3,HEXSTEP_FAR);

		lcd_display_clear();
		Get_UV();

		if(UV_state == UVSTATE_ACTIVE)
		{
			FIRE=FIRE_ON;
			UV_Lock=UVLOCK_ACTIVE;
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG ROOM1");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
		}
		else
		{
			BW_FollowCounter_Right(2);
		}

		Get_UV();

		if(UV_state==UVSTATE_ACTIVE)
		{
			FIRE=FIRE_ON;
			UV_Lock=UVLOCK_ACTIVE;
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG ROOM2");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
		}
	}

	else if(ROOM_NOW == ROOM2)
	{
		BW_PID_Init();
		BW_FollowCounter_Right(2);
		lcd_display_clear();
		Get_UV();

		if(UV_state == UVSTATE_ACTIVE)
		{
			FIRE=FIRE_ON;
			UV_Lock=UVLOCK_ACTIVE;
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG ROOM2");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
		}
		else
		{
			BW_FollowCounter_Right(2);
		}

		Get_UV();

		if(UV_state==UVSTATE_ACTIVE)
		{
			FIRE=FIRE_ON;
			UV_Lock=UVLOCK_ACTIVE;
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG ROOM2");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
		}
	}

	if(UV_Lock == UVLOCK_INACTIVE)
	{
		if(ROOM_NOW == ROOM1)
		{

//			Dynamx_Slide_Right_Interpolate(HEXSTEP_MED, LEVEL3);

			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG ROOM1");lcd_putstr(lcd);
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
				lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG ROOM1");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				delay_ms(50);
			}

			lcd_display_clear();
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG ROOM1");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				delay_ms(50);
			}
			else
			{
				Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR,IKCALC_DISABLE);
				Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_MED,IKCALC_DISABLE);
			}

			lcd_display_clear();
		}

		if(ROOM_NOW == ROOM2)
		{
//			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);
//			Dynamx_Slide_Left_Interpolate(HEXSTEP_MED, LEVEL3);

			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG ROOM2");lcd_putstr(lcd);
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
				lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG ROOM2");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				delay_ms(50);
			}

			lcd_display_clear();
			Get_UV();
			if(UV_state==UVSTATE_ACTIVE)
			{
				FIRE=FIRE_ON;
				UV_Lock=UVLOCK_ACTIVE;
				lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG ROOM2");lcd_putstr(lcd);
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
				lcd_gotoxy(0,0);sprintf(lcd,"SP FLAG ROOM2");lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"UV DETECTED");lcd_putstr(lcd);
				delay_ms(50);
			}
		}
	}

	if(FIRE == FIRE_ON)
	{
		EXTINGUISHER_OFF;
		UV_Lock=UVLOCK_ACTIVE;
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"BW");lcd_putstr(lcd);
		lcd_gotoxy(6,1);sprintf(lcd,"FIREFIGHT");lcd_putstr(lcd);
		delay_ms(100);

		if(ROOM_NOW == ROOM1)
		{
			FIRESCAN_DIRECTION=SCAN_RIGHT;
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"ROOM 1");lcd_putstr(lcd);
			delay_ms(100);


			Dynamx_Rot_Left_IK(LEVEL3,HEXSTEP_MED);

		if(Ping[PING_LEFT]+4 >= Ping[PING_ASKEW_LEFT])
		{
			Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_CLOSE,IKCALC_DISABLE);
			if(Ping[PING_LEFT]+4 <= Ping[PING_ASKEW_LEFT])
			{
				Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			}
		}

//		================================FLAME==========================
		FlameSenseDigi_PID_Init();

		while(FlameFrontDigi[0]!=4 && FlameSenseDigi[0]!=4 ){
			if(FlameFrontDigi[0]==4 && FlameSenseDigi[0]==4 )break;
			if(FlameFrontDigi[0]!=4 && FlameSenseDigi[0]<4 ){
				Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			}

			else if(FlameFrontDigi[0]!=4 && FlameSenseDigi[0]>4 ){
				Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
			}

			if(FlameFrontDigi[0]==4 && FlameSenseDigi[0]==4 )break;

			}

			BW_HydroPump_V10();
//			BW_HydroPump_2021_1();
			delay_ms(1000);

			FIRE=FIRE_OFF;

			Get_UV();

			if(UV_state==UVSTATE_ACTIVE){
				FIRE=FIRE_ON;
				FlameSenseDigi_PID_Init();

				while(FlameFrontDigi[0]!=4 && FlameSenseDigi[0]!=4 ){
					if(FlameFrontDigi[0]==4 && FlameSenseDigi[0]==4 )break;
					if(FlameFrontDigi[0]!=4 && FlameSenseDigi[0]<4 ){
						Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					}

					else if(FlameFrontDigi[0]!=4 && FlameSenseDigi[0]>4 ){
						Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
					}

					if(FlameFrontDigi[0]==4 && FlameSenseDigi[0]==4 )break;

					}
				BW_HydroPump_V10();

				FIRE = FIRE_OFF;
			}


//			BW_HydroPump_2021_2();
//			delay_ms(1000);

//			if((FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==2) || (FlameFrontDigi[0]==4))
//			{
//				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
//			}
//			else
//			{
//				Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
//			}
//			BW_FireFight_2021();

		}

		else if(ROOM_NOW == ROOM2)
		{

			FIRESCAN_DIRECTION=SCAN_RIGHT;
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"ROOM 2");lcd_putstr(lcd);
			delay_ms(100);


			BW_PID_Init();
			BW_FollowCounter_Right(5);

			while(Ping[PING_ASKEW_RIGHT]<12){
				if(Ping[PING_ASKEW_RIGHT]>=12)break;
				Dynamx_Rot_Left_IK(LEVEL2,HEXSTEP_VERYCLOSE);
				if(Ping[PING_ASKEW_RIGHT]>=12)break;
			}

			while(Ping[PING_ASKEW_RIGHT]>30){
				if(Ping[PING_ASKEW_RIGHT]>=30)break;
				Dynamx_Rot_Right_IK(LEVEL2,HEXSTEP_VERYCLOSE);
				if(Ping[PING_ASKEW_RIGHT]>=30)break;
			}

//			Dynamx_Rot_Right_IK(LEVEL3,HEXSTEP_FAR2);
//			Dynamx_Rot_Right_IK(LEVEL3,HEXSTEP_FAR);
//
//			Get_UV();
//			while(UV_state==UVSTATE_INACTIVE){
//				Get_UV();
//				if (UV_state==UVSTATE_ACTIVE)break;
//				Dynamx_Rot_Left_IK(LEVEL2,HEXSTEP_VERYCLOSE);
//				Get_UV();
//				if (UV_state==UVSTATE_ACTIVE)break;
//			}

			FlameSenseDigi_PID_Init();

					while(FlameFrontDigi[0]!=4 && FlameSenseDigi[0]!=4 ){
						if(FlameFrontDigi[0]==4 && FlameSenseDigi[0]==4 )break;
						if(FlameFrontDigi[0]!=4 && FlameSenseDigi[0]<4 ){
							Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						}

						else if(FlameFrontDigi[0]!=4 && FlameSenseDigi[0]>4 ){
							Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						}

						if(FlameFrontDigi[0]==4 && FlameSenseDigi[0]==4 )break;

						}

			BW_HydroPump_V10();
//			BW_HydroPump_2021_2();
			delay_ms(1000);

			FIRE=FIRE_OFF;
//
			Get_UV();

				if(UV_state==UVSTATE_ACTIVE){
					FIRE=FIRE_ON;
					FlameSenseDigi_PID_Init();

					while(FlameFrontDigi[0]!=4 && FlameSenseDigi[0]!=4 ){
						if(FlameFrontDigi[0]==4 && FlameSenseDigi[0]==4 )break;
						if(FlameFrontDigi[0]!=4 && FlameSenseDigi[0]<4 ){
							Dynamx_Rot_Left_Interpolate(LEVEL4,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						}

						else if(FlameFrontDigi[0]!=4 && FlameSenseDigi[0]>4 ){
							Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
						}

						if(FlameFrontDigi[0]==4 && FlameSenseDigi[0]==4 )break;

						}
					BW_HydroPump_V10();
			}

			FIRE = FIRE_OFF;

			delay_ms(1000);
//
//			BW_HydroPump_2021_1();
//
//			if((FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==5) || (FlameSenseDigi[0]==6) || (FlameFrontDigi[0]==4))
//			{
//				Dynamx_Slide_Left_Interpolate(HEXSTEP_MED,LEVEL3);
//			}
//			else
//			{
//				Dynamx_MovFwd4cm_Interpolate(4,LEVEL4,IKCALC_ENABLE);
//			}

		}

		else
		{
			FIRESCAN_DIRECTION=SCAN_RIGHT;
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"SCAN RIGHT");lcd_putstr(lcd);
			delay_ms(100);
		}

		//============================//
		//		EXTINGUISH ROUTINE	  //
		//============================//

//		BW_FireFight_2021();

		//============================//

//=======AGUSTUS, 16th 2021======//
//		RoomTypeDetector();

		FIRE_LED_BLINK_OFF;
		FIRE_LED_OFF;
		FIRE=FIRE_SUCCESS;

//------------------------ FIREFIGHT COMPLETED ----------------------------

		Dynamx_Mov_Static_Interpolate(LEVEL5,IKCALC_ENABLE);
		delay_ms(50);



	}

	//taruh program untuk evakuasi korban disini

	if(ROOM_NOW == ROOM1)
	{

		Dynamx_Rot_Left_IK(LEVEL3,HEXSTEP_FAR);
		Dynamx_Rot_Left_IK(LEVEL3,HEXSTEP_MED);

		BW_PID_Init();
		BW_FollowTracer_Right_Interpolate();


//		while(Ping[IPNG_R]<60 ){
//			if(Ping[PING_R]>85 )break;
//			Dynamx_Rot_Right_IK(LEVEL2,HEXSTEP_VERYCLOSE);
//			if(Ping[PING_R]<85)break;
//		}
//
//		while(Ping[PING_R]<60 ){
//			if(Ping[PING_R]<60 )break;
//			Dynamx_Slide_Right_Interpolate(HEXSTEP_MED,LEVEL3);
//			if(Ping[PING_R]<60)break;
//		}
//		while(TCS3200_SLV_DATA[1]!=COLOUR_WHITE){
//			if(TCS3200_SLV_DATA[1]==COLOUR_WHITE)break;
//			Dynamx_MovFwd4cm_Interpolate(2,LEVEL4,IKCALC_ENABLE);
//			if(TCS3200_SLV_DATA[1]==COLOUR_WHITE)break;
//		}

	}

	else if (ROOM_NOW == ROOM2)
	{

//		BW_FollowCounter_Right(4);
//
//		BW_HydroPump_V10();
//
//		BW_PID_Init();
//		Dynamx_Rot_Right_IK(LEVEL4,HEXSTEP_FAR2);
//		Dynamx_Rot_Right_IK(LEVEL4,HEXSTEP_FAR2);
//
//		BW_FollowCounter_Left(10);



		BW_PID_Init();
		Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_FAR2, IKCALC_DISABLE);
		Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_FAR2, IKCALC_DISABLE);
		Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_FAR2, IKCALC_DISABLE);
//		Dynamx_Rot_Right_Interpolate(LEVEL4,HEXSTEP_CLOSE, IKCALC_DISABLE);

		while(Ping[PING_ASKEW_LEFT]>16){
			if(Ping[PING_ASKEW_LEFT]<=16)break;
			Dynamx_Rot_Left_IK(LEVEL2,HEXSTEP_VERYCLOSE);
			if(Ping[PING_ASKEW_LEFT]<=16)break;
		}




		while(Ping[PING_FRONT]>FRONT_THRESHOLD ){
			if(Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
			BW_FollowCounter_Left(2);
			if (Ping[PING_LEFT]>=10) {
						Dynamx_Slide_Left_Interpolate(HEXSTEP_CLOSE,LEVEL3);

					}
			if(Ping[PING_FRONT]<=FRONT_THRESHOLD )break;
		}


		Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_FAR,IKCALC_DISABLE);
		Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_FAR,IKCALC_DISABLE);

		while(Ping[PING_ASKEW_LEFT]>18){
			if(Ping[PING_ASKEW_LEFT]<=18)break;
			Dynamx_Rot_Left_IK(LEVEL2,HEXSTEP_VERYCLOSE);
			if(Ping[PING_ASKEW_LEFT]<=18)break;
		}

//		BW_FollowCounter_Left(15);
//		if(Ping[PING_LEFT]+4 >= Ping[PING_ASKEW_LEFT])
//		{
//			Dynamx_Rot_Right_Interpolate(LEVEL5,HEXSTEP_CLOSE,IKCALC_DISABLE);
//			if(Ping[PING_LEFT]+4 <= Ping[PING_ASKEW_LEFT])
//			{
//				Dynamx_Rot_Left_Interpolate(LEVEL5,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
//			}
//		}


	}
	USART3_PutChar(NOT_IN_ROOM_STAT);

}

void H_Room_2(void){

	USART3_PutChar(IN_ROOM_STAT);

	if (ROOM_NOW == ROOM2){
	BW_FollowCounter_Right(4);

	BW_HydroPump_V10();
	delay_ms(1000);

	FIRE=FIRE_SUCCESS;

	BW_PID_Init();
	Dynamx_Rot_Right_IK(LEVEL4,HEXSTEP_FAR2);
	Dynamx_Rot_Right_IK(LEVEL4,HEXSTEP_FAR2);

	BW_FollowCounter_Left(10);
	}

	USART3_PutChar(NOT_IN_ROOM_STAT);


}

void BW_Trial_Grip(void)
{
	Down_Grip(MEDIUM_LEVEL);

	Dynamx_MovBwd_Interpolate(8,LEVEL3,IKCALC_ENABLE);
	Dynamx_Mov_Static_Interpolate(LEVEL5,IKCALC_ENABLE);
	delay_ms(1000);

	Open_Grip(MEDIUM_LEVEL);
	delay_ms(3000);
	Close_Grip(HIGH_LEVEL);
	delay_ms(500);
	Lift_Grip(MEDIUM_LEVEL);
	delay_ms(1000);

	BW_PID_Init_Room();
	for (int i=0; i<20; i++)
	{
		if(Ping[PING_FRONT] <= 20)break;
		BW_FollowCounter_Right(1);
		if(Ping[PING_FRONT] <= 20)break;
	}

	Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR2,IKCALC_DISABLE);
	Dynamx_Rot_Right_Interpolate(LEVEL3,HEXSTEP_FAR2,IKCALC_DISABLE);

	Down_Grip(MEDIUM_LEVEL);
	delay_ms(500);
	Open_Grip(HIGH_LEVEL);
	delay_ms(1000);

	BW_PID_Init_Room();
	BW_FollowCounter_Left(10);

	Dynamx_Mov_Static_Interpolate(LEVEL3,IKCALC_ENABLE);
	DynaGrip(130,0);
}

void Sensor_Menu(void)
{
	int counter;
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

	if(MENU_VAR>10) MENU_VAR=0;
	else if (MENU_VAR<0) MENU_VAR=10;

	switch(MENU_VAR)
	{
	case 0:
	{
		Display_Ping_Status();
	}break;

	case 1:
	{
		Display_Yaw_Angle();
	}break;
	case 2:
	{
		Display_Pitch_Data();
	}break;
	case 3:
	{
		Display_Roll_Data();
	}break;
	case 4:
	{
		Display_Fix_Direction();
	}break;
	case 5:
	{
		TCS3200_Transmit(UART5, TRACER_CMD_SEND_RGB);
		Display_RGB_Data(TRACER_BOTTOM);
	}break;
	case 6:
	{
		TCS3200_Transmit(UART5, HYBRID_CMD_SEND_THRESHOLD);
		Display_Threshold_Raw();
	}break;
	case 7:
	{
		TCS3200_Transmit(UART5, HYBRID_CMD_SEND_THRESHOLD);
		Display_Threshold_RGB();
	}break;
	case 8:
	{
		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		Display_tracer_stat();
	}break;
	case 9:
	{
		Display_RGB_Data(TRACER_GRIPPER);
		if(BW_BUTTON_CLICKED){counter=1;}
		if(counter==1)
		{
			Gripper_Open_K1();
			GRIPPER_LED_ON;
			Servo_PWM_Set_Angle(SERVO_2, 2250);
			Servo_PWM_Set_Angle(SERVO_3, 750);
		}
	}break;

	case 10:
	{
		Dynamx_Mov_Static_Obs(LEVEL2);
		Display_Fix_Direction();
	}break;
	}
}

void H_Room1_2021(void)
{
	USART3_PutChar(IN_ROOM_STAT);
	int ROOM1_FLAG = 1;

	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"BHATARA WIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,1);sprintf(lcd,"LOCATION :");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"ROOM 1");lcd_putstr(lcd);

	if (ROOM1_FLAG == 1)
	{
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
			BW_FollowCounter_Left(3);
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

	if(FIRE == FIRE_ON)
	{
		EXTINGUISHER_OFF;
		UV_Lock=UVLOCK_ACTIVE;
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"BW");lcd_putstr(lcd);
		lcd_gotoxy(6,1);sprintf(lcd,"FIREFIGHT");lcd_putstr(lcd);
		delay_ms(100);

		if(ROOM1_FLAG == 1)
		{

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"FLAME SENSE= %d",FlameSenseDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"ROOM 1");lcd_putstr(lcd);

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
		}

		//============================//
		//		EXTINGUISH ROUTINE	  //
		//============================//

		BW_FireFight_V2();
		BW_FireFight_2021();

		USART3_PutChar(NOT_IN_ROOM_STAT);
		FIRE_LED_BLINK_OFF;
		FIRE_LED_OFF;
		FIRE=FIRE_SUCCESS;
	}
}


void BW_FireFight_2021(void)
{
	FlameSenseDigi_PID_Init();

	FIRE_LED_BLINK_ON;

	FlameTracking_Center();

	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"BW FIREFIGHT");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"TRACKING");lcd_putstr(lcd);
	delay_ms(100);

	if(ROOM_NOW == ROOM1)
	{

	}

	else if(ROOM_NOW = ROOM2)
	{
		for(x=0;x<=3;x++)
		{
			FlameTracking_Center();

			while(SHARP[IR_FRONT]>60)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"MAJU KE API");lcd_putstr(lcd);

				Dynamx_MovFwd4cm_Interpolate(4,LEVEL3,IKCALC_DISABLE);

				if(FlameFrontDigi[0]!=4)break;
			}

			FlameTracking_Center();


			while(SHARP[IR_FRONT]>60)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"MAJU KE API");lcd_putstr(lcd);

				Dynamx_MovFwd4cm_Interpolate(4,LEVEL3,IKCALC_DISABLE);

				if(FlameFrontDigi[0]!=4)break;
			}
		}
	}

	FlameTracking_Center();

	UVLock_Refresh();

	if(1)
	{
		lcd_display_clear();
		lcd_gotoxy(0,1);sprintf(lcd,"EXTINGUISH 1.0");lcd_putstr(lcd);
		Dynamx_Mov_Static_Interpolate(LEVEL5,IKCALC_ENABLE);
		delay_ms(50);

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

	delay_ms(1000);

	if(UV_Lock==UVLOCK_ACTIVE)
	{
		UVLock_Refresh();
		delay_ms(1000);
	}

	if(UV_Lock==UVLOCK_ACTIVE)
	{
		FlameTracking_Center();
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
		FlameTracking_Center();
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

void BW_FollowCounter_Right(int limit)
{
	int counter;
	FOLLOW_CALC=KANAN;

	for(counter=1;counter<=limit;counter++)
	{
		if ((Ping[PING_FRONT]<=FRONT_THRESHOLD))
		{
			Dynamx_Rot_Left_IK(1000,STEP4);
		}
		else
		{
			PID_BW_FollowCounter_Right();
		}
	}

	FOLLOW_CALC=KOSONG;
}

void PID_BW_FollowCounter_Right(void)
{
	int OVERRIDE=0;

	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			if ( (Ping[PING_ASKEW_RIGHT]<=PID_F_R.set_point_upper) && (Ping[PING_ASKEW_RIGHT]>=PID_F_R.set_point_lower) )
			{
				if ((Ping[PING_FRONT]<=FRONT_THRESHOLD))
				{
					Dynamx_Rot_Left_IK(1000,STEP4);
				}

				if(OVERRIDE==1){break;}

				if (OVERRIDE==0)
				{
					if(SHIFT_ALGORITHM_FLAG == SHIFT_ALGORITHM_ACTIVE)
					{
//						Dynamx_MovFwd4cm_Interpolate(4, 800, IKCALC_ENABLE);
						Dynamx_MovFwd_Interpolate_6S(4, 400, IKCALC_ENABLE);
					}
					else
					{
//						Dynamx_MovFwd4cm_Interpolate(4, 800, IKCALC_ENABLE);
						Dynamx_MovFwd_Interpolate_6S(4, 400, IKCALC_ENABLE);
					}
					OVERRIDE=1;
				}
			}

			//KONDISI ROBOT JAUH DARI DINDING
			else if ( Ping[PING_ASKEW_RIGHT]>PID_F_R.set_point_upper )
			{
				if ((Ping[PING_FRONT]<=FRONT_THRESHOLD))
				{
					Dynamx_Rot_Left_IK(1000,STEP4);
				}

				if(OVERRIDE==1){break;}

				if (OVERRIDE==0)
				{
					if(SHIFT_ALGORITHM_FLAG == SHIFT_ALGORITHM_ACTIVE)
					{
						Dynamx_MoveCurveRight_IK(400,1,&PID_F_R.pid_value[0]);
					}
					else
					{
						Dynamx_MoveCurveRight_IK(400,1,&PID_F_R.pid_value[0]);
					}
					OVERRIDE=1;
				}
			}

			//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( Ping[PING_ASKEW_RIGHT]<PID_F_R.set_point_lower )
			{
				if ((Ping[PING_FRONT]<=FRONT_THRESHOLD))
				{
					Dynamx_Rot_Left_IK(1000,STEP4);
				}

				if(OVERRIDE==1){break;}

				if (OVERRIDE==0)
				{
					if(SHIFT_ALGORITHM_FLAG == SHIFT_ALGORITHM_ACTIVE)
					{
						Dynamx_MoveCurveLeft_IK(400,1,&PID_F_R.pid_value[0]);
					}
					else
					{
						Dynamx_MoveCurveLeft_IK(400,1,&PID_F_R.pid_value[0]);
					}
					OVERRIDE=1;
				}
			}
		}
	}
}

void BW_FollowCounter_Left(int limit)
{
	int counter;
	FOLLOW_CALC=KIRI;

	for(counter=1;counter<=limit;counter++)
	{
		if ((Ping[PING_FRONT]<=FRONT_THRESHOLD))
		{
			Dynamx_Rot_Right_IK(1000,STEP4);
		}
		else
		{
			PID_BW_FollowCounter_Left();
		}
	}
	FOLLOW_CALC=KOSONG;
}

void PID_BW_FollowCounter_Left(void)
{
	int OVERRIDE=0;
	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			if ( (Ping[PING_ASKEW_LEFT]<=PID_F_L.set_point_upper) && (Ping[PING_ASKEW_LEFT]>=PID_F_L.set_point_lower) )
			{
				if ((Ping[PING_FRONT]<=FRONT_THRESHOLD))
				{
					Dynamx_Rot_Right_IK(1000,STEP4);
				}

				if(OVERRIDE==1){break;}

				if (OVERRIDE==0)
				{
					if(SHIFT_ALGORITHM_FLAG == SHIFT_ALGORITHM_ACTIVE)
					{
//						Dynamx_MovFwd4cm_Interpolate(4, 400, IKCALC_ENABLE);
						Dynamx_MovFwd_Interpolate_6S(4, 400, IKCALC_ENABLE);
					}
					else
					{
						Dynamx_MovFwd_Interpolate_6S(4, 400, IKCALC_ENABLE);
//						Dynamx_MovFwd4cm_Interpolate(4, 400, IKCALC_ENABLE);
					}
					OVERRIDE=1;
				}
			}

			//KONDISI ROBOT DEKAT DARI DINDING
			else if ( Ping[PING_ASKEW_LEFT]<PID_F_L.set_point_lower )
			{
				if ((Ping[PING_FRONT]<=FRONT_THRESHOLD))
				{
					Dynamx_Rot_Right_IK(1000,STEP4);
				}

				if(OVERRIDE==1){break;}

				if (OVERRIDE==0)
				{
					if(SHIFT_ALGORITHM_FLAG == SHIFT_ALGORITHM_ACTIVE)
					{
						Dynamx_MoveCurveRight_IK(400,1,&PID_F_L.pid_value[0]);
					}
					else
					{
						Dynamx_MoveCurveRight_IK(400,1,&PID_F_L.pid_value[0]);
					}
					OVERRIDE=1;
				}
			}

			//KONDISI ROBOT JAUH DENGAN DINDING
			else if ( Ping[PING_ASKEW_LEFT]>PID_F_L.set_point_upper )
			{
				if ((Ping[PING_FRONT]<=FRONT_THRESHOLD))
				{
					Dynamx_Rot_Right_IK(1000,STEP4);
				}

				if(OVERRIDE==1){break;}

				if (OVERRIDE==0)
				{
					if(SHIFT_ALGORITHM_FLAG == SHIFT_ALGORITHM_ACTIVE)
					{
						Dynamx_MoveCurveLeft_IK(400,1,&PID_F_L.pid_value[0]);
					}
					else
					{
						Dynamx_MoveCurveLeft_IK(400,1,&PID_F_L.pid_value[0]);
					}
					OVERRIDE=1;
				}
			}
		}
	}
}

void BW_FollowCounter_Left_Obs(int limit)
{
	int counter;
	FOLLOW_CALC=KIRI_OBS;

	for(counter=1;counter<=limit;counter++)
	{
		if ((Ping[PING_FRONT]<=FRONT_THRESHOLD))
		{
			//Dynamx_Rot_Right_IK(LEVEL6,STEP4);
		}
		else
		{
			PID_BW_FollowCounter_Left_Obs();
		}
	}
	FOLLOW_CALC=KOSONG;

}

void PID_BW_FollowCounter_Left_Obs(void)
{
	int OVERRIDE=0;
	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			if ( (Ping[PING_ASKEW_LEFT]<=PID_F_L.set_point_upper) && (Ping[PING_ASKEW_LEFT]>=PID_F_L.set_point_lower) )
			{
				if ((Ping[PING_FRONT]<=FRONT_THRESHOLD))
				{
					//Dynamx_Rot_Right_IK(LEVEL6,STEP4);
				}

				if(OVERRIDE==1){break;}

				if (OVERRIDE==0)
				{
					Dynamx_MovFwd_Obstaicle_Interpolate(OBS_LVL2,1);
					OVERRIDE=1;
				}
			}

			//KONDISI ROBOT DEKAT DARI DINDING
			else if ( Ping[PING_ASKEW_LEFT]<PID_F_L.set_point_lower )
			{
				if ((Ping[PING_FRONT]<=FRONT_THRESHOLD))
				{
					//Dynamx_Rot_Right_IK(LEVEL6,STEP4);
				}

				if(OVERRIDE==1){break;}

				if (OVERRIDE==0)
				{
					Dynamx_MoveCurveRight_Obstaicle(OBS_LVL2,1,&PID_F_L.pid_value[0]);
					OVERRIDE=1;
				}
			}

			//KONDISI ROBOT JAUH DENGAN DINDING
			else if ( Ping[PING_ASKEW_LEFT]>PID_F_L.set_point_upper )
			{
				if ((Ping[PING_FRONT]<=FRONT_THRESHOLD))
				{
					//Dynamx_Rot_Right_IK(LEVEL6,STEP4);
				}

				if(OVERRIDE==1){break;}

				if (OVERRIDE==0)
				{
					Dynamx_MoveCurveLeft_Obstaicle(OBS_LVL2,1,&PID_F_L.pid_value[0]);
					OVERRIDE=1;
				}
			}
		}
	}
}

void BW_FollowCounter_Right_Obs(int limit)
{
	int counter;
	FOLLOW_CALC=KANAN_OBS;

	for(counter=1;counter<=limit;counter++)
	{
		if ((Ping[PING_FRONT]<=FRONT_THRESHOLD))
		{
			break;
		}
		else
		{
			PID_BW_FollowCounter_Right_Obs();
		}
	}

	FOLLOW_CALC=KOSONG;
}

void PID_BW_FollowCounter_Right_Obs(void)
{
	int OVERRIDE=0;

	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			if ( (Ping[PING_ASKEW_RIGHT]<=PID_F_R.set_point_upper) && (Ping[PING_ASKEW_RIGHT]>=PID_F_R.set_point_lower) )
			{
				if ((Ping[PING_FRONT]<=FRONT_THRESHOLD))
				{
					break;
				}

				if(OVERRIDE==1){break;}

				if (OVERRIDE==0)
				{
					if(mode_follow==MODE_FOLLOW_K5)
					{
						Dynamx_MovFwd_Obstaicle_Interpolate(OBS_LVL5,1);
						OVERRIDE=1;
					}
					else if(mode_follow==MODE_FOLLOW_FAST)
					{
						Dynamx_MovFwd_Obstaicle_Interpolate(OBS_LVL2,1);
						OVERRIDE=1;
					}
					else
					{
						Dynamx_MovFwd_Obstaicle_Interpolate(OBS_LVL3,1);
						OVERRIDE=1;
					}
				}
			}

			//KONDISI ROBOT JAUH DARI DINDING
			else if ( Ping[PING_ASKEW_RIGHT]>PID_F_R.set_point_upper )
			{
				if ((Ping[PING_FRONT]<=FRONT_THRESHOLD))
				{
					break;
				}

				if(OVERRIDE==1){break;}

				if (OVERRIDE==0)
				{
					if(mode_follow==MODE_FOLLOW_K5)
					{
						Dynamx_MoveCurveRight_Obstaicle(OBS_LVL5,1,&PID_F_R.pid_value[0]);
						OVERRIDE=1;
					}
					else if(mode_follow==MODE_FOLLOW_FAST)
					{
						Dynamx_MoveCurveRight_Obstaicle(OBS_LVL2,1,&PID_F_R.pid_value[0]);
						OVERRIDE=1;
					}
					else
					{
						Dynamx_MoveCurveRight_Obstaicle(OBS_LVL3,1,&PID_F_R.pid_value[0]);
						OVERRIDE=1;
					}
				}
			}

			//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( Ping[PING_ASKEW_RIGHT]<PID_F_R.set_point_lower )
			{
				if ((Ping[PING_FRONT]<=FRONT_THRESHOLD))
				{
					break;
				}

				if(OVERRIDE==1){break;}

				if (OVERRIDE==0)
				{
					if(mode_follow==MODE_FOLLOW_K5)
					{
						Dynamx_MoveCurveLeft_Obstaicle(OBS_LVL5,1,&PID_F_R.pid_value[0]);
						OVERRIDE=1;
					}
					if(mode_follow==MODE_FOLLOW_FAST)
					{
						Dynamx_MoveCurveLeft_Obstaicle(OBS_LVL2,1,&PID_F_R.pid_value[0]);
						OVERRIDE=1;
					}
					else
					{
						Dynamx_MoveCurveLeft_Obstaicle(OBS_LVL3,1,&PID_F_R.pid_value[0]);
						OVERRIDE=1;
					}
				}
			}
		}
	}
}

void BW_FollowCarpet_left_Obs(int CARPET_CODE, int FOLLOW_MODE)
{

	LEFT_FOLLOW_STATE = 1;
	COLOUR_BUF = CARPET_CODE;
	FOLLOW_CARPET_MODE = FOLLOW_MODE;
	FOLLOW_CALC = KIRI_OBS;


	switch(FOLLOW_MODE)
	{
	case NORMAL:
	{
		while((TCS3200_SLV_DATA[1]==CARPET_CODE))
		{
			TCS3200_Transmit(UART5,CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]!= CARPET_CODE){break;}

			PID_BW_FollowCarpet_Left_Obs(CARPET_CODE,FOLLOW_MODE);

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

			PID_BW_FollowCarpet_Left_Obs(CARPET_CODE,FOLLOW_MODE);

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

void PID_BW_FollowCarpet_Left_Obs(unsigned int CARPET_CODE, unsigned int FOLLOW_MODE)
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

					Dynamx_MovFwd_Obstaicle_Interpolate(OBS_LVL2,1);
					OVERRIDE=1;
				}

			}

			//KONDISI ROBOT JAUH DARI DINDING
			else if ( Ping[PING_ASKEW_LEFT]>PID_F_R.set_point_upper )
			{

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

					Dynamx_MoveCurveLeft_Obstaicle(OBS_LVL2,1,&PID_F_L.pid_value[0]);
					OVERRIDE = 1;
				}

			}

			//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( Ping[PING_ASKEW_LEFT]<PID_F_R.set_point_lower )
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

					Dynamx_MoveCurveRight_Obstaicle(OBS_LVL2,1,&PID_F_L.pid_value[0]);
					OVERRIDE=1;
				}

			}
		}
	}
}

void BW_FollowCarpet_Right_Obs(int CARPET_CODE, int FOLLOW_MODE)
{
	RIGHT_FOLLOW_STATE = 1;
	COLOUR_BUF = CARPET_CODE;
	FOLLOW_CARPET_MODE = FOLLOW_MODE;

	FOLLOWMODE_FLAG=FOLLOW_CARPET_ACTIVE;
	FOLLOW_CALC=KANAN_OBS;

	switch(FOLLOW_MODE)
	{
	case NORMAL:
	{
		while( (TCS3200_SLV_DATA[1]==CARPET_CODE)/* && (CAT_FLAG==CAT_NOT_DETECTED)*/ )
		{
			TCS3200_Transmit(UART5,CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1] != CARPET_CODE){break;}

			PID_BW_FollowCarpet_Right_Obs(CARPET_CODE, FOLLOW_MODE);

			TCS3200_Transmit(UART5,CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1] != CARPET_CODE)break;
		}
	}break;


	case INVERSE:
	{
		while( (TCS3200_SLV_DATA[1]!=CARPET_CODE) /*&& (CAT_FLAG==CAT_NOT_DETECTED)*/ )
		{
			TCS3200_Transmit(UART5,CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]== CARPET_CODE){break;}

			PID_BW_FollowCarpet_Right_Obs(CARPET_CODE, FOLLOW_MODE);

			TCS3200_Transmit(UART5,CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1] == CARPET_CODE){break;}
		}
	}break;
	}

	FOLLOW_CALC=KOSONG;
	COLOUR_BUF = 4;
	FOLLOW_CARPET_MODE = 4;
	RIGHT_FOLLOW_STATE = 0;
}

void PID_BW_FollowCarpet_Right_Obs(unsigned int CARPET_CODE, unsigned int FOLLOW_MODE)
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

					Dynamx_MovFwd_Obstaicle_Interpolate(OBS_LVL2,1);
					OVERRIDE=1;
				}

			}

			//KONDISI ROBOT JAUH DARI DINDING
			else if ( Ping[PING_ASKEW_RIGHT]>PID_F_R.set_point_upper )
			{

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

					Dynamx_MoveCurveRight_Obstaicle(OBS_LVL2,1,&PID_F_R.pid_value[0]);
					OVERRIDE = 1;
				}

			}

			//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( Ping[PING_ASKEW_RIGHT]<PID_F_R.set_point_lower )
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

					Dynamx_MoveCurveLeft_Obstaicle(OBS_LVL2,1,&PID_F_R.pid_value[0]);
					OVERRIDE=1;
				}

			}
		}
	}
}

void BW_Start_Compas_Correction_S1(void)
{
	int compas_flag = 0;
	while(start_compas_flag == 0)
	{
		GetCMPS11_Angle8Bit();
		if((CMPS11_Angle>K1_NORTH_LOW) && (CMPS11_Angle<K1_NORTH_UP))
		{
			Dynamx_Rot_Left_IK(1000,STEP4);
			start_compas_flag = 1;
			break;
		}
		else if((CMPS11_Angle>K1_SOUTH_LOW) && (CMPS11_Angle<K1_SOUTH_UP))
		{
			Dynamx_Rot_Right_IK(1000,STEP4);
			start_compas_flag = 1;
			break;
		}

	}
}

void BW_Start_Compas_Correction_S2(void)
{
	while(start_compas_flag == 0)
	{
		GetCMPS11_Angle8Bit();
		if((CMPS11_Angle>=K1_NORTH_LOW) && (CMPS11_Angle<=K1_NORTH_UP))
		{
			HOME_FLAG_NEW = 1;
			start_compas_flag = 1;
			break;
		}
		else if((CMPS11_Angle>=K1_SOUTH_LOW) && (CMPS11_Angle<=K1_SOUTH_UP))
		{
			HOME_FLAG_NEW = 2;
			start_compas_flag = 1;
			break;
		}
	}
}

void BW_Mode_2(void)
{
	int MENU_VAR=0;
	while(1)
	{
		while(BW_BUTTON_UNCLICKED)
		{
			if(BW_BUTTON_CLICKED)break;

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

			if(BW_BUTTON_CLICKED)break;

			if(MENU_VAR>7) MENU_VAR=0;
			else if (MENU_VAR<0) MENU_VAR=7;

			switch (MENU_VAR)
			{
			case 0:
			{
				lcd_display_clear();
				lcd_gotoxy(3,0);sprintf(lcd,"ME:ZE 2023");lcd_putstr(lcd);
				lcd_gotoxy(2,1);sprintf(lcd,"TES NAVIGASI");lcd_putstr(lcd);
				lcd_gotoxy(3,2);sprintf(lcd,"ALGORITM 1");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"DTE FT-UB 63");lcd_putstr(lcd);
				delay_ms(100);
			}break;

			case 1:
			{
				lcd_display_clear();
				lcd_gotoxy(3,0);sprintf(lcd,"MZ  2023");lcd_putstr(lcd);
				lcd_gotoxy(2,1);sprintf(lcd,"TES SCAN");lcd_putstr(lcd);
				lcd_gotoxy(3,2);sprintf(lcd,"    -   ");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
				delay_ms(100);
			}break;

			case 2:
			{
				lcd_display_clear();
				lcd_gotoxy(3,0);sprintf(lcd,"MZ  2023");lcd_putstr(lcd);
				lcd_gotoxy(2,1);sprintf(lcd,"TES SCAN O");lcd_putstr(lcd);
				lcd_gotoxy(3,2);sprintf(lcd,"    -   ");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
				delay_ms(100);
			}break;

			case 3:
			{
				lcd_display_clear();
				lcd_gotoxy(3,0);sprintf(lcd,"MZ  2021");lcd_putstr(lcd);
				lcd_gotoxy(2,1);sprintf(lcd,"SZ1 to K2");lcd_putstr(lcd);
				lcd_gotoxy(3,2);sprintf(lcd,"    -   ");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
				delay_ms(100);
			}break;

			case 4:
			{
				lcd_display_clear();
				lcd_gotoxy(3,0);sprintf(lcd,"MZ  2023");lcd_putstr(lcd);
				lcd_gotoxy(2,1);sprintf(lcd,"TES ROT CMPS");lcd_putstr(lcd);
				lcd_gotoxy(3,2);sprintf(lcd,"     -     ");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
				delay_ms(100);
			}break;

			case 5:
			{
				lcd_display_clear();
				lcd_gotoxy(3,0);sprintf(lcd,"MZ  2023");lcd_putstr(lcd);
				lcd_gotoxy(2,1);sprintf(lcd,"SZ2 to K3");lcd_putstr(lcd);
				lcd_gotoxy(3,2);sprintf(lcd,"     -     ");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
				delay_ms(100);
			}break;

			case 6:
			{
				lcd_display_clear();
				lcd_gotoxy(3,0);sprintf(lcd,"MZ  2023");lcd_putstr(lcd);
				lcd_gotoxy(2,1);sprintf(lcd,"K3 to K4");lcd_putstr(lcd);
				lcd_gotoxy(3,2);sprintf(lcd,"     -     ");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
				delay_ms(100);
			}break;

			case 7:
			{
				lcd_display_clear();
				lcd_gotoxy(3,0);sprintf(lcd,"MZ  2023");lcd_putstr(lcd);
				lcd_gotoxy(2,1);sprintf(lcd,"K5 to Finish");lcd_putstr(lcd);
				lcd_gotoxy(3,2);sprintf(lcd,"     -     ");lcd_putstr(lcd);
				lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
				delay_ms(100);
			}break;

			}

			if(BW_BUTTON_CLICKED)break;
		}

		delay_ms(500);

		while(1)
		{
			switch(MENU_VAR)
			{
			case 0:
			{
				BW_Algorithm1_2023();
			}break;

			case 1:
			{
//				Nav_1_To_2();
				Gripper_Down_New();
//				GRIPPER_LED_ON;
				Gripper_Open_K1();
				SCAN_KORBAN();
			}break;

			case 2:
			{
				Gripper_Down_New();
//				GRIPPER_LED_ON;
				Gripper_Open_K1();
				SCAN_KORBAN_OBS_S2();
			}break;

			case 3:
			{
				SZ1_To_K2_S2();

				SZ2_To_K3_S2();

				K3_To_SZ4();

				K5_To_Finish();

			}break;

			case 4:
			{
				TES_ROT_CMPS();
			}break;

			case 5:
			{
				SZ2_To_K3_S2();

				K3_To_SZ4();

				K5_To_Finish();
			}break;

			case 6:
			{
				K3_To_SZ4();

				K5_To_Finish();
			}break;

			case 7:
			{
				K5_To_Finish();
			}break;

			}

			while (1)
			{
				Dynamx_Mov_Static_Interpolate(LEVEL5,IKCALC_ENABLE);
			}
		}
	}

}

void BW_FollowCarpet_Left_Straight(int CARPET_CODE, int FOLLOW_MODE)
{
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

			PID_BWFollowCarpet_Left_Interpolate(CARPET_CODE, FOLLOW_MODE);

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

			PID_BWFollowCarpet_Left_Straight(CARPET_CODE, FOLLOW_MODE);

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

void PID_BWFollowCarpet_Left_Straight(unsigned int CARPET_CODE, unsigned int FOLLOW_MODE)
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

					Dynamx_MovFwd4cm_Interpolate(4, LEVEL6, IKCALC_ENABLE);

					OVERRIDE=1;
				}

			}

			//KONDISI ROBOT JAUH DARI DINDING
			else if ( Ping[PING_ASKEW_LEFT]>PID_F_R.set_point_upper )
			{
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

					Dynamx_MoveCurveLeft_IK(LEVEL6,1,&PID_F_L.pid_value[0]);

					OVERRIDE = 1;
				}
			}

			//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( Ping[PING_ASKEW_LEFT]<PID_F_R.set_point_lower )
			{
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

					Dynamx_MoveCurveRight_IK(LEVEL6,1,&PID_F_L.pid_value[0]);

					OVERRIDE=1;
				}

			}
		}
	}
}

void BW_FollowCounter_Right_Climbing(int limit)
{
	int counter;
	FOLLOW_CALC=KANAN_OBS;

	for(counter=1;counter<=limit;counter++)
	{
		if ((Ping[PING_FRONT]<=FRONT_THRESHOLD))
		{
			break;
		}
		else
		{
			PID_BW_FollowCounter_Right_Climbing();
		}
	}

	FOLLOW_CALC=KOSONG;
}

void PID_BW_FollowCounter_Right_Climbing(void)
{
	int OVERRIDE=0;

	while(OVERRIDE==0)
	{
		if(OVERRIDE==0)
		{
			//KONDISI ROBOT SESUAI
			if ( (Ping[PING_ASKEW_RIGHT]<=PID_F_R.set_point_upper) && (Ping[PING_ASKEW_RIGHT]>=PID_F_R.set_point_lower) )
			{
				if ((Ping[PING_FRONT]<=FRONT_THRESHOLD))
				{
					break;
				}

				if(OVERRIDE==1){break;}

				if (OVERRIDE==0)
				{
					Dynamx_MovFwdClimbing_Interpolate(OBS_LVL2,1,2);
					OVERRIDE=1;
				}
			}

			//KONDISI ROBOT JAUH DARI DINDING
			else if ( Ping[PING_ASKEW_RIGHT]>PID_F_R.set_point_upper )
			{
				if ((Ping[PING_FRONT]<=FRONT_THRESHOLD))
				{
					break;
				}

				if(OVERRIDE==1){break;}

				if (OVERRIDE==0)
				{
					Dynamx_MovCrvRight_Climbing_Interpolate(OBS_LVL2,1,2,&PID_F_R.pid_value[0]);
					OVERRIDE=1;
				}
			}

			//KONDISI ROBOT DEKAT DENGAN DINDING
			else if ( Ping[PING_ASKEW_RIGHT]<PID_F_R.set_point_lower )
			{
				if ((Ping[PING_FRONT]<=FRONT_THRESHOLD))
				{
					break;
				}

				if(OVERRIDE==1){break;}

				if (OVERRIDE==0)
				{
					Dynamx_MovCrvLeft_Climbing_Interpolate(OBS_LVL2,1,2,&PID_F_R.pid_value[0]);
					OVERRIDE=1;
				}
			}
		}
	}
}


void BW_Climbing_Slope(void)
{
//	CLIMBING_FLAG = 1;
	CLIMBING_INTERRUPT_FLAG = 1;
	int BUFF = 0;

	BW_PID_Init_Obs();

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

void Home_To_K1_S1()
{
	int count1 = 0;
	int compas_flag_1 = 0;
	int VL_flag_1 = 0;

	Dynamx_Mov_Static_Interpolate(LEVEL2,IKCALC_ENABLE);

	//Corridor Home to K1
	BW_PID_Init();
	while((Ping[PING_FRONT]>= 15)&&(count1==0))
	{
		if(Ping[PING_ASKEW_LEFT]>= 25){count1= 1;break;}
		BW_FollowCounter_Right(1);
		if(Ping[PING_ASKEW_LEFT]>= 25){count1= 1;break;}
	}

	//counter move forward go in front of K1
	for(int i=0;i<3;i++)
	{
		Dynamx_MovFwd_Interpolate_6S(4, 1000, IKCALC_ENABLE);
	}

	//Rotate to K1
	Dynamx_Mov_Static_Interpolate(LEVEL2,IKCALC_ENABLE);
	delay_ms(1000);
//	while(compas_flag_1==0)
//	{
//		GetCMPS11_Angle8Bit();
//		if((CMPS11_Angle>K1_SOUTH_LOW)&&(CMPS11_Angle<K1_SOUTH_UP)){break;}
//		Dynamx_Rot_Left_IK(1000,STEP1);
//		if((CMPS11_Angle>K1_SOUTH_LOW)&&(CMPS11_Angle<K1_SOUTH_UP)){break;}
//	}

	Dynamx_Rot_Left_IK(1000,STEP4);

	compas_flag_1 = 1;

	//Grip the victim
	Dynamx_Mov_Static_Interpolate(LEVEL2,IKCALC_ENABLE);
	Gripper_Down_K1();
	Gripper_Open_K1();
	delay_ms(500);
	while(VL_flag_1==0)
	{
		if((VL_SENSOR[0]<100)&&(TCS34725_SLV_DATA[0]>=120)){break;}
		Dynamx_MovFwd_Interpolate_6S(4, 3000, IKCALC_ENABLE);
		if((VL_SENSOR[0]<100)&&(TCS34725_SLV_DATA[0]>=120)){break;}
	}
	VL_flag_1 = 1;

	Dynamx_Mov_Static_Interpolate(LEVEL2,IKCALC_ENABLE);
	delay_ms(1000);

	Gripper_Close_K1();
	Gripper_Up_K1();

	while(compas_flag_1==1)
	{
		GetCMPS11_Angle8Bit();
		if((CMPS11_Angle>K1_NORTH_LOW)&&(CMPS11_Angle<K1_NORTH_UP)){break;}
		Dynamx_Rot_Right_IK(1000,STEP1);
		if((CMPS11_Angle>K1_NORTH_LOW)&&(CMPS11_Angle<K1_NORTH_UP)){break;}
	}
	compas_flag_1 = 2;

	Dynamx_Mov_Static_Interpolate(LEVEL2,IKCALC_ENABLE);
	for(int i=0;i<4;i++)
	{
		Dynamx_MovFwd_Interpolate_6S(4,400,IKCALC_ENABLE);
	}
	Dynamx_Mov_Static_Interpolate(LEVEL2,IKCALC_ENABLE);

	while(compas_flag_1==2)
	{
		GetCMPS11_Angle8Bit();
		if((CMPS11_Angle>K1_WEST_LOW)&&(CMPS11_Angle<K1_WEST_UP)){break;}
		Dynamx_Rot_Left_IK(1000,STEP1);
		if((CMPS11_Angle>K1_WEST_LOW)&&(CMPS11_Angle<K1_WEST_UP)){break;}
	}
	compas_flag_1 = 3;

	Dynamx_Mov_Static_Interpolate(LEVEL2,IKCALC_ENABLE);

	//OBS R1
	Dynamx_Mov_Static_Obs(LEVEL2);
	BW_PID_Init_Obs();
	while(Ping[PING_FRONT]>= 15)
	{
		if(Ping[PING_FRONT]<= 15)break;
		BW_FollowCounter_Right_Obs(1);
		if(Ping[PING_FRONT]<= 15)break;
	}
}

void Home_To_K1_S2(int HOME_FLAG)
{
	int count_K1 = 0;
	int VL_flag_1 = 0;
	int compas_flag_1 = 0;
	int count_pitch = 0;
	int R4_flag = 0;
	int SZ1_flag = 0;

	if(HOME_FLAG==1)
	{
		Dynamx_Rot_Left_IK(800,STEP4);
		Dynamx_Mov_Static_Interpolate(LEVEL2,IKCALC_ENABLE);
		Dynamx_Rot_Left_IK(800,STEP4);
		Dynamx_Mov_Static_Interpolate(LEVEL2,IKCALC_ENABLE);

		while(count_K1==0)
		{
			if(Ping[PING_FRONT]>=25)break;
			Dynamx_Slide_Right_IK(1,800);
			if(Ping[PING_FRONT]>=25)break;
		}
		count_K1 = 1;
	}
	else if(HOME_FLAG==2)
	{
		while(count_K1==0)
		{
			if(Ping[PING_FRONT]>=25)break;
			Dynamx_Slide_Right_IK(1,800);
			if(Ping[PING_FRONT]>=25)break;
		}
		count_K1 = 1;
	}

	for(int i=0;i<3;i++)
	{
		Dynamx_Slide_Right_IK(1,800);
	}
	Dynamx_Mov_Static_Interpolate(LEVEL2,IKCALC_ENABLE);
	delay_ms(100);

	Gripper_Down_New();
	GRIPPER_LED_ON;
	Gripper_Open_K1();

	if(HOME_FLAG==1)
	{
		for(int i=0;i<1;i++)
		{
			Dynamx_MovFwd_Interpolate_6S(4, 1000, IKCALC_ENABLE);
		}
		delay_ms(100);
	}
	else if(HOME_FLAG==2)
	{
		for(int i=0;i<1;i++)
		{
			Dynamx_MovFwd_Interpolate_6S(4, 1000, IKCALC_ENABLE);
		}
		delay_ms(100);
	}

	mode_scan=MODE_K1;
	SCAN_KORBAN();
	mode_scan=MODE_NONE;

	mode_korban=MODE_K1;
	MODE_CAPIT=MODE_K1;

//	while(VL_flag_1==0)
//	{
//		if((VL_SENSOR[0]<150)&&(TCS34725_SLV_DATA[2]<300)&&(SHARP_GRIPPER[0]<10)){break;}
//		Dynamx_MovFwd_Interpolate_6S(4, 3000, IKCALC_ENABLE);
//		if((VL_SENSOR[0]<150)&&(TCS34725_SLV_DATA[2]<300)&&(SHARP_GRIPPER[0]<10)){break;}
//	}
//	VL_flag_1 = 1;

	Dynamx_Mov_Static_Interpolate(LEVEL2,IKCALC_ENABLE);
	delay_ms(100);
	Dynamx_MovLeanFwd_Interpolate(5000,1);
	MODE_CAPIT=MODE_NONE;
	mode_korban=MODE_NONE;

	Dynamx_Mov_Static_Interpolate(LEVEL2,IKCALC_ENABLE);
	delay_ms(100);

//	Gripper_Close_K1();
//	GRIPPER_LED_OFF;
//	Gripper_Up_K1();

//	Dynamx_Rot_Right_IK(1000,STEP4);
//	Dynamx_Rot_Right_IK(1000,STEP4);

	while(count_K1==1)
	{
		if(Ping[PING_REAR]<=13)break;
//		Dynamx_MovFwd_Interpolate_6S(4, 400, IKCALC_ENABLE);
		Dynamx_MovBwd_Interpolate(4,800,IKCALC_ENABLE);
		if(Ping[PING_REAR]<=13)break;
	}
	count_K1=2;
	Dynamx_Mov_Static_Interpolate(LEVEL2,IKCALC_ENABLE);

//	while(compas_flag_1==0)
//	{
//		GetCMPS11_Angle8Bit();
//		if((CMPS11_Angle>=K1_WEST_LOW)&&(CMPS11_Angle<=K1_WEST_UP)){break;}
		Dynamx_Rot_Right_IK(OBS_LVL2,STEP4);
//		if((CMPS11_Angle>=K1_WEST_LOW)&&(CMPS11_Angle<=K1_WEST_UP)){break;}
//	}
	compas_flag_1 = 1;

	Dynamx_Mov_Static_Obs(LEVEL2);

	mode_obs=MODE_OBS;
	BW_PID_Init_Obs();
	while(R4_flag==0)
	{
		GetCMPS11_Pitch(KF_ACTIVE);
		if(Ping[PING_FRONT]<= 11)
		{
			Dynamx_Rot_Obs_Left_IK(OBS_LVL2,STEP5);
			Dynamx_Mov_Static_Obs(LEVEL2);
		}
		if(BW_CMPS11.PitchKF > 10){count_pitch=1;}

		BW_FollowCounter_Right_Obs(1);

		GetCMPS11_Pitch(KF_ACTIVE);
		if(Ping[PING_FRONT]<= 11)
		{
			Dynamx_Rot_Obs_Left_IK(OBS_LVL2,STEP5);
			Dynamx_Mov_Static_Obs(LEVEL2);
		}
		if(BW_CMPS11.PitchKF > 10){count_pitch=1;mode_follow=MODE_FOLLOW_FAST;}

		while(count_pitch==1)
		{
			GetCMPS11_Pitch(KF_ACTIVE);
			if(Ping[PING_FRONT]<= 11)
			{
				Dynamx_Rot_Obs_Left_IK(OBS_LVL2,STEP5);
				Dynamx_Mov_Static_Obs(LEVEL2);
			}
			if(BW_CMPS11.PitchKF < 3){count_pitch=2;R4_flag=1;break;}

			BW_FollowCounter_Right_Obs(1);

			GetCMPS11_Pitch(KF_ACTIVE);
			if(Ping[PING_FRONT]<= 11)
			{
				Dynamx_Rot_Obs_Left_IK(OBS_LVL2,STEP5);
				Dynamx_Mov_Static_Obs(LEVEL2);
			}
			if(BW_CMPS11.PitchKF < 3){count_pitch=2;R4_flag=1;break;}
		}
	}

	mode_obs=MODE_NONE;
	IK_CALCULATED_FWD_OBS=0;

	Dynamx_Mov_Static_Obs(LEVEL2);
	while(R4_flag==1)
	{
		if((Ping[PING_FRONT]<= 14)&&(Ping[PING_ASKEW_RIGHT]<=17))break;
		if((Ping[PING_FRONT]<= 14)&&(Ping[PING_ASKEW_RIGHT]>20)){Dynamx_Rot_Obs_Left_IK(OBS_LVL2,STEP5);}
		BW_FollowCounter_Right_Obs(1);
		if((Ping[PING_FRONT]<= 14)&&(Ping[PING_ASKEW_RIGHT]<=17))break;
		if((Ping[PING_FRONT]<= 14)&&(Ping[PING_ASKEW_RIGHT]>20)){Dynamx_Rot_Obs_Left_IK(OBS_LVL2,STEP5);}
	}
	R4_flag=2;

	mode_follow=MODE_NONE;

	Dynamx_Mov_Static_Interpolate(LEVEL2,IKCALC_ENABLE);
	while(SZ1_flag==0)
	{
		if(Ping[PING_ASKEW_RIGHT]<=15)break;
		Dynamx_Slide_Right_IK(1,1000);
		if(Ping[PING_ASKEW_RIGHT]<=15)break;
	}
	SZ1_flag=1;

	Dynamx_Mov_Static_Interpolate(LEVEL2,IKCALC_ENABLE);
	Dynamx_Rot_Right_IK(800,STEP2);
	Dynamx_Mov_Static_Obs(LEVEL2);

	for(int i=0;i<1;i++)
	{
		Dynamx_MovBwd_Obs_Interpolate(4,OBS_LVL2,IKCALC_ENABLE);
	}
	Dynamx_Mov_Static_Obs(LEVEL2);
	Gripper_Down_K1();
//	for(int i=0;i<1;i++)
//	{
//		Dynamx_MovFwd_Obstaicle_Interpolate(OBS_LVL3,1);
//	}
//	Dynamx_Mov_Static_Obs(LEVEL2);

	MODE_CAPIT=MODE_SZ1;
	Dynamx_MovLeanFwd_Obstaicle_Interpolate(OBS_LVL3,1);
	MODE_CAPIT=MODE_NONE;

	Dynamx_Mov_Static_Obs(LEVEL2);

	for(int i=0;i<1;i++)
	{
		Dynamx_MovBwd_Obs_Interpolate(4,OBS_LVL2,IKCALC_ENABLE);
	}

	Gripper_Up_K1();
	Gripper_Close_K1();

//	Dynamx_Mov_Static_Interpolate(LEVEL2,IKCALC_ENABLE);

}

void SZ1_To_K2_S2()
{
	int cmps_flag = 0;
	int VL_CNT = 0;
	int R5_flag = 0;

	Dynamx_Mov_Static_Obs(LEVEL2);

	Dynamx_Rot_Obs_Left_IK(OBS_LVL2,STEP2);

	while(Ping[PING_FRONT]>15)
	{
		if(Ping[PING_FRONT]<=15)break;
		Dynamx_MovFwd_Obstaicle_Interpolate(OBS_LVL3,1);
		if(Ping[PING_FRONT]<=15)break;
	}

//	delay_ms(500);

	Dynamx_Rot_Obs_Left_IK(OBS_LVL2,STEP5);

	Dynamx_Mov_Static_Obs(LEVEL2);
	BW_PID_Init_Obs();
	while(Ping[PING_ASKEW_LEFT]>22)
	{
		if(Ping[PING_ASKEW_LEFT]<=22)break;
		BW_FollowCounter_Right_Obs(1);
		if(Ping[PING_ASKEW_LEFT]<=22)break;
	}

	BW_PID_Init_Obs();
	for(int i=0;i<8;i++)
	{
		if((Ping[PING_FRONT]<=15)&&(Ping[PING_ASKEW_RIGHT]>20)){Dynamx_Rot_Obs_Left_IK(OBS_LVL2,STEP5);}
		if((Ping[PING_FRONT]<=45)&&(Ping[PING_FRONT]>38)&&(Ping[PING_REAR]>=40))break;
		BW_FollowCounter_Right_Obs(1);
		if((Ping[PING_FRONT]<=15)&&(Ping[PING_ASKEW_RIGHT]>20)){Dynamx_Rot_Obs_Left_IK(OBS_LVL2,STEP5);}
		if((Ping[PING_FRONT]<=45)&&(Ping[PING_FRONT]>38)&&(Ping[PING_REAR]>=40))break;
	}
//	for(int i=0;i<7;i++)
//	{
//		BW_FollowCounter_Right_Obs(1);
//	}

	Dynamx_Mov_Static_Obs(LEVEL2);
	mode_cmps=MODE_CMPS_EAST;
	while(cmps_flag==0)
	{
		GetCMPS11_Angle8Bit();
		if((CMPS11_Angle>=K2_EAST_LOW) && (CMPS11_Angle<=K2_EAST_UP)){cmps_flag=1;}
		Dynamx_Rot_Obs_Left_IK(OBS_LVL2,STEP1);
		if((CMPS11_Angle>=K2_EAST_LOW) && (CMPS11_Angle<=K2_EAST_UP)){cmps_flag=1;}
	}
	mode_cmps=MODE_NONE;
//	Dynamx_Rot_Obs_Left_IK(OBS_LVL4,STEP5);

	Dynamx_Mov_Static_Obs(LEVEL2);
	Gripper_Down_New();
	GRIPPER_LED_ON;
	Gripper_Open_K1();

	for(int i=0;i<3;i++)
	{
		Dynamx_MovFwd_Obstaicle_Interpolate(OBS_LVL3,1);
	}

	Dynamx_Mov_Static_Obs(LEVEL2);


	mode_korban=MODE_K2;
	while(VL_CNT==0)
	{
		GetCMPS11_Angle8Bit();
		if((VL_SENSOR[0]<285)&&(TCS34725_SLV_DATA[2]>=210)&&(CMPS11_Angle<90)){samping_flag_K2=1;break;}//samping kanan

		if((VL_SENSOR[0]<200)&&((TCS34725_SLV_DATA[2]>185)&&(TCS34725_SLV_DATA[2]<230))){break;}//pas

		GetCMPS11_Angle8Bit();
		if(((VL_SENSOR[0]>230)&&(VL_SENSOR[0]<300))&&(TCS34725_SLV_DATA[2]>210)&&(CMPS11_Angle>110)){samping_flag_K2=2;break;}//samping kiri
		if(VL_SENSOR[0]>450)//loss kanan
		{
			Dynamx_Mov_Static_Obs(LEVEL2);
			Dynamx_Rot_Obs_Left_IK(OBS_LVL5,STEP8);
			Dynamx_Mov_Static_Obs(LEVEL2);
			IK_CALCULATED_FWD_OBS=0;
			rot_flag_K2=1;
			break;
		}

		Dynamx_MovFwd_Obstaicle_Interpolate(OBS_LVL5,1);

		GetCMPS11_Angle8Bit();
		if((VL_SENSOR[0]<285)&&(TCS34725_SLV_DATA[2]>=210)&&(CMPS11_Angle<90)){samping_flag_K2=1;break;}//samping kanan

		if((VL_SENSOR[0]<200)&&((TCS34725_SLV_DATA[2]>185)&&(TCS34725_SLV_DATA[2]<230))){break;}//pas

		GetCMPS11_Angle8Bit();
		if(((VL_SENSOR[0]>230)&&(VL_SENSOR[0]<300))&&(TCS34725_SLV_DATA[2]>210)&&(CMPS11_Angle>110)){samping_flag_K2=2;break;}//samping kiri
		if(VL_SENSOR[0]>450)//loss kanan
		{
			Dynamx_Mov_Static_Obs(LEVEL2);
			Dynamx_Rot_Obs_Left_IK(OBS_LVL5,STEP8);
			Dynamx_Mov_Static_Obs(LEVEL2);
			IK_CALCULATED_FWD_OBS=0;
			rot_flag_K2=1;
			break;
		}
	}
	VL_CNT = 1;
	mode_korban=MODE_NONE;

//	if(samping_flag_K2==1)
//	{
//		while(1)
//		{
//			if((VL_SENSOR[0]<220)&&((TCS34725_SLV_DATA[2]>200)&&(TCS34725_SLV_DATA[2]<240))&&(SHARP_GRIPPER[0]<10)){break;}
//			Dynamx_MovFwd_Obstaicle_Interpolate(OBS_LVL5,1);
//			if((VL_SENSOR[0]<220)&&((TCS34725_SLV_DATA[2]>200)&&(TCS34725_SLV_DATA[2]<240))&&(SHARP_GRIPPER[0]<10)){break;}
//		}
//	}

	delay_ms(100);

	Dynamx_Mov_Static_Obs(LEVEL2);

	mode_scan=MODE_K2;
	mode_korban=MODE_K1;
	SCAN_KORBAN_OBS();
	mode_scan=MODE_NONE;
	mode_korban=MODE_NONE;

	Dynamx_Mov_Static_Obs(LEVEL2);

	mode_korban=MODE_K2_Next;
	if(samping_flag_K2==1 || samping_flag_K2==2 || rot_flag_K2==1)
	{
		int count=0;
		while(1)
		{
			if((VL_SENSOR[0]<200)&&((TCS34725_SLV_DATA[2]>190)&&(TCS34725_SLV_DATA[2]<240))){break;}
			Dynamx_MovFwd_Obstaicle_Interpolate(OBS_LVL5,1);
			if((VL_SENSOR[0]<200)&&((TCS34725_SLV_DATA[2]>190)&&(TCS34725_SLV_DATA[2]<240))){break;}

			count+=1;
			if(count==2)break;
		}
	}
	mode_korban=MODE_NONE;

	Dynamx_Mov_Static_Obs(LEVEL2);

	mode_korban=MODE_K1;
	MODE_CAPIT=MODE_K2;
	Dynamx_MovLeanFwd_Obstaicle_Interpolate(4000,1);
	MODE_CAPIT=MODE_NONE;
	mode_korban=MODE_NONE;

	delay_ms(100);

	if((TCS34725_SLV_DATA[0]<100)||(TCS34725_SLV_DATA[1]<200)||(TCS34725_SLV_DATA[2]<200))
	{
		mode_loss=MODE_LOSS_KORBAN;
	}

	delay_ms(100);

	GRIPPER_LED_OFF;

	//=======================================MODE KORBAN BERHASIL================================//
	if(mode_loss==0)
	{
		Dynamx_Mov_Static_Obs(LEVEL2);

		if(rot_flag_K2==1)
		{
			Dynamx_Rot_Obs_Right_IK(OBS_LVL3,STEP8);
		}

		Dynamx_Mov_Static_Obs(LEVEL2);

		delay_ms(100);

		while(Ping[PING_REAR] > 10)
		{
			if(Ping[PING_REAR]<10)break;
			Dynamx_MovBwd_Obs_Interpolate(4,OBS_LVL2,IKCALC_ENABLE);
			if(Ping[PING_REAR]<10)break;
		}
		IK_CALCULATED_FWD_OBS=0;

	//	delay_ms(500);
		Dynamx_Mov_Static_Obs(LEVEL2);

		Dynamx_Rot_Obs_Right_IK(OBS_LVL2,STEP5);

		Dynamx_Mov_Static_Obs(LEVEL2);


		IK_CALCULATED_FWD_OBS=0;
		IK_CALCULATED_CRV_L_OBS=0;
		IK_CALCULATED_CRV_R_OBS=0;
		mode_follow=MODE_FOLLOW_FAST;
		BW_PID_Init_Obs();
		while(Ping[PING_FRONT]>=15)
		{
			IK_CALCULATED_FWD_OBS=0;
			IK_CALCULATED_CRV_L_OBS=0;
			IK_CALCULATED_CRV_R_OBS=0;
			if((Ping[PING_FRONT]<=15)&&(Ping[PING_ASKEW_RIGHT]>20)){Dynamx_Rot_Obs_Left_IK(OBS_LVL2,STEP5);}
			if((Ping[PING_FRONT]<=15)&&(Ping[PING_ASKEW_RIGHT]<=18))break;
			BW_FollowCounter_Right_Obs(1);
			if((Ping[PING_FRONT]<=15)&&(Ping[PING_ASKEW_RIGHT]>20)){Dynamx_Rot_Obs_Left_IK(OBS_LVL2,STEP5);}
			if((Ping[PING_FRONT]<=15)&&(Ping[PING_ASKEW_RIGHT]<=18))break;
		}

		mode_follow=MODE_NONE;

		Dynamx_Mov_Static_Obs(LEVEL2);

		for(int i=0;i<2;i++)
		{
			Dynamx_Slide_Obs_Left_IK(1,OBS_LVL2);
		}

		Dynamx_Mov_Static_Obs(LEVEL2);
		delay_ms(100);
		Dynamx_Rot_Obs_Right_IK(OBS_LVL2,STEP8);
		delay_ms(100);

		Dynamx_Mov_Static_Obs(LEVEL2);
		IK_CALCULATED_BWD_OBS=0;
		for(int i=0;i<1;i++)
		{
			Dynamx_MovBwd_Obs_Interpolate(4,OBS_LVL2,IKCALC_ENABLE);
		}

		Gripper_Down_New();
		delay_ms(100);
		Dynamx_Mov_Static_Obs(LEVEL2);

	//	mode_korban=MODE_SZ2;
		for(int i=0;i<1;i++)
		{
			Dynamx_MovFwd_Obstaicle_Interpolate(OBS_LVL2,1);
		}
		mode_korban=MODE_NONE;

		delay_ms(100);

		Dynamx_Mov_Static_Obs(LEVEL2);
		MODE_CAPIT=MODE_SZ1;
		Dynamx_MovLeanFwd_Obstaicle_Interpolate(OBS_LVL2,1);
		MODE_CAPIT=MODE_NONE;
	}
	//=================================MODE LOSS KORBAN========================================//
	else if(mode_loss==MODE_LOSS_KORBAN)
	{
		Dynamx_Mov_Static_Obs(LEVEL2);

		if(rot_flag_K2==1)
		{
			Dynamx_Rot_Obs_Right_IK(OBS_LVL3,STEP8);
		}

		Dynamx_Mov_Static_Obs(LEVEL2);

		delay_ms(100);

		while(Ping[PING_REAR] > 10)
		{
			if(Ping[PING_REAR]<10)break;
			Dynamx_MovBwd_Obs_Interpolate(4,OBS_LVL2,IKCALC_ENABLE);
			if(Ping[PING_REAR]<10)break;
		}
		IK_CALCULATED_FWD_OBS=0;

	//	delay_ms(500);
		Dynamx_Mov_Static_Obs(LEVEL2);

		Dynamx_Rot_Obs_Right_IK(OBS_LVL2,STEP5);

		Dynamx_Mov_Static_Obs(LEVEL2);


		IK_CALCULATED_FWD_OBS=0;
		IK_CALCULATED_CRV_L_OBS=0;
		IK_CALCULATED_CRV_R_OBS=0;
		mode_follow=MODE_FOLLOW_FAST;
		BW_PID_Init_Obs();
		while(Ping[PING_FRONT]>=15)
		{
			IK_CALCULATED_FWD_OBS=0;
			IK_CALCULATED_CRV_L_OBS=0;
			IK_CALCULATED_CRV_R_OBS=0;
			if((Ping[PING_FRONT]<=15)&&(Ping[PING_ASKEW_RIGHT]>20)){Dynamx_Rot_Obs_Left_IK(OBS_LVL2,STEP5);}
			if((Ping[PING_FRONT]<=15)&&(Ping[PING_ASKEW_RIGHT]<=18))break;
			BW_FollowCounter_Right_Obs(1);
			if((Ping[PING_FRONT]<=15)&&(Ping[PING_ASKEW_RIGHT]>20)){Dynamx_Rot_Obs_Left_IK(OBS_LVL2,STEP5);}
			if((Ping[PING_FRONT]<=15)&&(Ping[PING_ASKEW_RIGHT]<=18))break;
		}

		mode_follow=MODE_NONE;

	}

}

void SZ2_To_K3_S2()
{
	int VL_CNT = 0;

	Dynamx_Mov_Static_Obs(LEVEL2);

	if(mode_loss==0)
	{
		for(int i=0;i<1;i++)
		{
			Dynamx_MovBwd_Obs_Interpolate(4,OBS_LVL2,IKCALC_ENABLE);
		}

		Gripper_Close_K1();
		Gripper_Up_New();

		Dynamx_Mov_Static_Obs(LEVEL2);
		Dynamx_Rot_Obs_Left_IK(OBS_LVL2,STEP8);
		Dynamx_Mov_Static_Obs(LEVEL2);
	}

	while(Ping[PING_FRONT]>=15)
	{
		if(Ping[PING_FRONT]<=15){break;}
		Dynamx_MovFwd_Obstaicle_Interpolate(OBS_LVL2,1);
		if(Ping[PING_FRONT]<=15){break;}
	}
	Dynamx_Mov_Static_Obs(LEVEL2);
	Dynamx_Rot_Obs_Left_IK(OBS_LVL2,STEP6);

	mode_follow=MODE_FOLLOW_FAST;
	BW_PID_Init_Obs();
	while(Ping[PING_FRONT]>=15)
	{
		if(Ping[PING_FRONT]<=15){Dynamx_Rot_Obs_Left_IK(OBS_LVL3,STEP4);Dynamx_MovFwd_Obstaicle_Interpolate(OBS_LVL2,2);}
		if((Ping[PING_ASKEW_RIGHT]>30)&&(SHARP[IR_RIGHT]>=13)){break;}
		BW_FollowCounter_Right_Obs(1);
		if(Ping[PING_FRONT]<=15){Dynamx_Rot_Obs_Left_IK(OBS_LVL3,STEP4);Dynamx_MovFwd_Obstaicle_Interpolate(OBS_LVL2,2);}
		if((Ping[PING_ASKEW_RIGHT]>30)&&(SHARP[IR_RIGHT]>=13)){break;}
	}
	mode_follow=MODE_NONE;

	for(int i=0;i<3;i++)
	{
		if(i==1)
		{
			Dynamx_Slide_Obs_Right_IK(2,OBS_LVL2);
		}
		Dynamx_MovFwd_Obstaicle_Interpolate(OBS_LVL2,1);
	}

	BW_PID_Init_Obs();
	while(Ping[PING_FRONT]>=15)
	{
		if(Ping[PING_FRONT]<=15){break;}
		BW_FollowCounter_Left_Obs(1);
		if(Ping[PING_FRONT]<=15){break;}
	}

	Dynamx_Mov_Static_Obs(LEVEL2);
	Dynamx_Rot_Obs_Right_IK(OBS_LVL2,STEP3);
	Dynamx_Mov_Static_Obs(LEVEL2);

	mode_follow=MODE_FOLLOW_R6;
	Dynamx_Mov_Static_Obs_High(LEVEL2);
	BW_PID_Init_Obs();
	for(int i=0;i<6;i++)
	{
		BW_FollowCounter_Left_Obs(1);
	}
//	while(Ping[PING_FRONT]>=43)
//	{
//		if(Ping[PING_FRONT]<43)break;
//		BW_FollowCounter_Left_Obs(1);
//		if(Ping[PING_FRONT]<43)break;
//	}

//	Dynamx_Mov_Static_Obs(LEVEL2);
//	Dynamx_Rot_Obs_Right_IK(OBS_LVL3,STEP5);
//	Dynamx_Mov_Static_Obs(LEVEL2);

//	Gripper_Down_New();
//	GRIPPER_LED_ON;
//	Gripper_Open_K3();

//	for(int i=0;i<4;i++)
//	{
//		Dynamx_MovFwd_Obstaicle_Interpolate(OBS_LVL5,1);
//	}
//
//	mode_korban=MODE_K2;
//	while(VL_CNT==0)
//	{
//		if((VL_SENSOR[0]<270)&&(TCS34725_SLV_DATA[2]>=160)&&(SHARP_GRIPPER[0]<=14)){break;}
//		Dynamx_MovFwd_Obstaicle_Interpolate(OBS_LVL5,1);
//		if((VL_SENSOR[0]<270)&&(TCS34725_SLV_DATA[2]>=160)&&(SHARP_GRIPPER[0]<=14)){break;}
//	}
//	VL_CNT = 1;
//	mode_korban=MODE_NONE;
//
//	for(int i=0;i<1;i++)
//	{
//		Dynamx_MovFwd_Obstaicle_Interpolate(OBS_LVL5,1);
//	}
//
//	Dynamx_Mov_Static_Obs(LEVEL2);
//
//	MODE_CAPIT=MODE_K2;
//	Dynamx_MovLeanFwd_Obstaicle_Interpolate(5000,1);
//	MODE_CAPIT=MODE_NONE;
//
//	Dynamx_Mov_Static_Obs(LEVEL2);
//
//	IK_CALCULATED_BWD_OBS=0;
//	for(int i=0;i<2;i++)
//	{
//		Dynamx_MovBwd_Obs_Interpolate(4,OBS_LVL4,IKCALC_ENABLE);
//	}

//	Dynamx_Mov_Static_Obs(LEVEL2);
//	Dynamx_Rot_Obs_Left_IK(OBS_LVL3,STEP5);
//	Dynamx_Mov_Static_Obs(LEVEL2);
}

void K3_To_SZ4()
{
	int R9_flag=0;
	int VL_flag=0;
	int cmps_flag=0;

//	Dynamx_Mov_Static_Obs(LEVEL2);
//	for(int i=0;i<1;i++)
//	{
//		Dynamx_MovFwd_Obstaicle_Interpolate(OBS_LVL3,1);
//	}

	Dynamx_Mov_Static_Obs_High(LEVEL2);
	BW_PID_Init_Obs();
	while(Ping[PING_FRONT]>15)
	{
		if(Ping[PING_FRONT]<=15)break;
		BW_FollowCounter_Left_Obs(1);
		if(Ping[PING_FRONT]<=15)break;
	}

	mode_follow=MODE_NONE;

	Dynamx_Mov_Static_Obs(LEVEL2);

//	for(int i=0;i<7;i++)
//	{
//		Dynamx_Slide_Obs_Right_IK(1,OBS_LVL2);
//	}

//	mode_cmps=MODE_CMPS_EAST;
//	while(cmps_flag==0)
//	{
//		GetCMPS11_Angle8Bit();
//		if((CMPS11_Angle >= R9_SOUTH_LOW) && (CMPS11_Angle <= R9_SOUTH_UP))break;
//		Dynamx_Rot_Obs_Right_IK(OBS_LVL3,STEP1);
//		if((CMPS11_Angle >= R9_SOUTH_LOW) && (CMPS11_Angle <= R9_SOUTH_UP))break;
//	}
//	cmps_flag=1;
//	mode_cmps=MODE_NONE;

	Dynamx_Rot_Obs_Right_IK(OBS_LVL2,STEP3);

	Dynamx_Mov_Static_Obs(LEVEL2);

	BW_PID_Init_Obs();
	while(Ping[PING_FRONT]>15)
	{
		if(Ping[PING_FRONT]<=15)break;
		BW_FollowCounter_Left_Obs(1);
		if(Ping[PING_FRONT]<=15)break;
	}

	Dynamx_Mov_Static_Obs(LEVEL2);
	Dynamx_Rot_Obs_Left_IK(OBS_LVL2,STEP3);
	Dynamx_Mov_Static_Obs(LEVEL2);

//	while(Ping[PING_FRONT]>15)
//	{
//		if(Ping[PING_FRONT]<=15)break;
//		Dynamx_MovFwd_Obstaicle_Interpolate(OBS_LVL3,1);
//		if(Ping[PING_FRONT]<=15)break;
//	}
//
//	Dynamx_Mov_Static_Obs(LEVEL2);
//	Dynamx_Rot_Obs_Left_IK(OBS_LVL3,STEP6);
//	Dynamx_Mov_Static_Obs(LEVEL2);

//	while(R9_flag==0)
//	{
//		GetCMPS11_Angle8Bit();
//		if(CMPS11_Angle < R9_EAST_LOW)
//		{
//			Dynamx_Rot_Obs_Left_IK(OBS_LVL3,STEP1);
//		}
//		else if(CMPS11_Angle > R9_EAST_UP)
//		{
//			Dynamx_Rot_Obs_Right_IK(OBS_LVL3,STEP1);
//		}
//		if((CMPS11_Angle <= R9_EAST_UP) && (CMPS11_Angle >= R9_EAST_LOW))break;
//	}
	R9_flag=1;

//	Dynamx_Mov_Static_Obs(LEVEL2);

//	IK_CALCULATED_FWD_OBS=0;
//	for(int i=0;i<2;i++)
//	{
//		Dynamx_MovFwd_Obstaicle_Interpolate(OBS_LVL3,1);
//	}

	Dynamx_Mov_Static_Obs(LEVEL2);

	BW_PID_Init_Obs();
	while(R9_flag==1)
	{
		GetCMPS11_Pitch(KF_ACTIVE);
		if(BW_CMPS11.PitchKF <= -10){break;}
		BW_FollowCounter_Left_Obs(1);
		if(BW_CMPS11.PitchKF <= -10){break;}
	}
	R9_flag=2;

	Dynamx_Mov_Static_Obs(LEVEL2);

	BW_PID_Init_Obs();
	IK_CALCULATED_CLMB=0;
	for(int i=0;i<8;i++)
	{
		BW_FollowCounter_Right_Climbing(1);
	}

	while(R9_flag==2)
	{
		GetCMPS11_Pitch(KF_ACTIVE);
		if(BW_CMPS11.PitchKF >= 3){break;}
		BW_FollowCounter_Right_Climbing(1);
		if(BW_CMPS11.PitchKF >= 3){break;}
	}
	R9_flag=3;

	STATIC_OBS=0;
	Dynamx_Mov_Static_Obs(LEVEL2);
	BW_PID_Init_Obs();
	while(R9_flag==3)
	{
		if(Ping[PING_FRONT]<30)break;
		BW_FollowCounter_Right_Obs(1);
		if(Ping[PING_FRONT]<30)break;
	}
	R9_flag=4;

	Dynamx_Mov_Static_Obs(LEVEL2);

//	for(int i=0;i<3;i++)
//	{
//		Dynamx_Slide_Obs_Left_IK(1,OBS_LVL3);
//	}

//	Dynamx_Mov_Static_Obs(LEVEL2);
//	Dynamx_Rot_Obs_Left_IK(OBS_LVL3,STEP2);
//	Dynamx_Mov_Static_Obs(LEVEL2);

//	Dynamx_Mov_Static_Interpolate(LEVEL2,IKCALC_ENABLE);

	Gripper_Down_New();
	GRIPPER_LED_ON;
	Gripper_Open_K1();

	mode_korban=MODE_K5;
	mode_follow=MODE_FOLLOW_K5;
	while(VL_flag==0)
	{
		GetCMPS11_Angle8Bit();
		if(((VL_SENSOR[0]<340)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)&&(CMPS11_Angle<85)){mode_scan_K5=MODE_SCAN_K5_RIGHT;break;}//samping kanan

		if((VL_SENSOR[0]<190)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<230))){break;}//pas

		if(((VL_SENSOR[0]<300)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)){mode_scan_K5=MODE_SCAN_K5_LEFT;break;}//samping kiri

		BW_FollowCounter_Right_Obs(1);

		GetCMPS11_Angle8Bit();
		if(((VL_SENSOR[0]<340)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)&&(CMPS11_Angle<85)){mode_scan_K5=MODE_SCAN_K5_RIGHT;break;}//samping kanan

		if((VL_SENSOR[0]<190)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<230))){break;}//pas

		if(((VL_SENSOR[0]<300)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)){mode_scan_K5=MODE_SCAN_K5_LEFT;break;}//samping kiri
	}
	VL_flag = 1;
	mode_follow=MODE_NONE;
	mode_korban=MODE_NONE;

//	Dynamx_Mov_Static_Obs(LEVEL2);
	Dynamx_Mov_Static_Interpolate(LEVEL5,IKCALC_ENABLE);

	mode_scan=MODE_K5;
	SCAN_KORBAN_K5();
	mode_scan=MODE_NONE;

	Dynamx_Mov_Static_Interpolate(LEVEL5,IKCALC_ENABLE);

	mode_korban=MODE_K5;

	int count=0;
	while(1)
	{
		if((VL_SENSOR[0]<190)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<270))){break;}//pas
		Dynamx_MovFwd_Interpolate_6S(4,2000,IKCALC_ENABLE);
		if((VL_SENSOR[0]<190)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<260))){break;}//pas

		count+=1;
		if(count==2)break;
	}
	mode_korban=MODE_NONE;


	MODE_CAPIT=MODE_K1;
//	Dynamx_MovLeanFwd_Obstaicle_Interpolate(OBS_LVL5,1);
	Dynamx_MovLeanFwd_Interpolate(OBS_LVL5,1);
	MODE_CAPIT=MODE_NONE;

}

void K5_To_Finish()
{
	///////////K5 to SZ5/////////////

	int R11_flag=0;

	Dynamx_Mov_Static_Obs(LEVEL2);
	Dynamx_Rot_Obs_Left_IK(OBS_LVL2,STEP4);
	Dynamx_Mov_Static_Obs(LEVEL2);

	for(int i=0;i<1;i++)
	{
		Dynamx_Slide_Obs_Left_IK(1,OBS_LVL1);
	}

	Dynamx_Mov_Static_Obs(LEVEL2);

//	IK_CALCULATED_CLMB=0;
//	STATIC_CLIMBING=0;
	while(R11_flag==0)
	{
		int flag;

		GetCMPS11_Angle8Bit();
		if(Ping[PING_FRONT]<15)break;
		if((Ping[PING_ASKEW_LEFT]<22)&&(SHARP[IR_LEFT]<18))break;
		if((CMPS11_Angle > (R9_NORTH_UP+2)))
		{
			Dynamx_Mov_Static_Obs(LEVEL2);
			Dynamx_Rot_Obs_Right_IK(OBS_LVL3,STEP8);
			Dynamx_Mov_Static_Obs(LEVEL2);
		}//rotasi ke kanan dikit

		GetCMPS11_Angle8Bit();
		if((CMPS11_Angle<=R9_NORTH_UP)&&(CMPS11_Angle>=R9_NORTH_LOW))
		{
			Dynamx_MovFwd_Obstaicle_Interpolate(OBS_LVL3,2);
		}

		Dynamx_MovFwd_Obstaicle_Interpolate(OBS_LVL3,2);

		if(Ping[PING_FRONT]<15)break;
		if((Ping[PING_ASKEW_LEFT]<21)&&(SHARP[IR_LEFT]<17))break;
		GetCMPS11_Angle8Bit();
		if((CMPS11_Angle < R9_NORTH_LOW))
		{
			Dynamx_Mov_Static_Obs(LEVEL2);
			Dynamx_Rot_Obs_Left_IK(OBS_LVL3,STEP8);
			Dynamx_Mov_Static_Obs(LEVEL2);
		}//rotasi ke kiri dikit

		GetCMPS11_Angle8Bit();
		if((CMPS11_Angle<=R9_NORTH_UP)&&(CMPS11_Angle>=R9_NORTH_LOW))
		{
			Dynamx_MovFwd_Obstaicle_Interpolate(OBS_LVL3,2);
		}
	}
	R11_flag=1;

	BW_PID_Init_Obs();
	while(Ping[PING_FRONT]>15)
	{
		if(Ping[PING_FRONT]<=15)break;
		BW_FollowCounter_Left_Obs(1);
		if(Ping[PING_FRONT]<=15)break;
	}

	Dynamx_Mov_Static_Obs(LEVEL2);
	Dynamx_Rot_Obs_Right_IK(OBS_LVL2,STEP3);
	Dynamx_Mov_Static_Obs(LEVEL2);

	BW_PID_Init_Obs();
	while(Ping[PING_FRONT]>25)
	{
		if(Ping[PING_FRONT]<=25)break;
		BW_FollowCounter_Left_Obs(1);
		if(Ping[PING_FRONT]<=25)break;
	}

	Dynamx_Mov_Static_Obs(LEVEL2);

	mode_slide_finish=MODE_SLIDE_FINISH;
	for(int i=0;i<1;i++)
	{
		Dynamx_Slide_Obs_Right_IK(1,OBS_LVL1);
	}
	mode_slide_finish=MODE_NONE;

	Dynamx_Mov_Static_Obs(LEVEL2);

	MODE_CAPIT=MODE_SZ5;
	Dynamx_MovLeanFwd_Obstaicle_Interpolate(OBS_LVL2,1);
	MODE_CAPIT=MODE_NONE;

	Dynamx_Mov_Static_Obs(LEVEL2);

	while(Ping[PING_REAR]>10)
	{
		if(Ping[PING_REAR]<=10)break;
		Dynamx_MovBwd_Obs_Interpolate(4,OBS_LVL2,IKCALC_ENABLE);
		if(Ping[PING_REAR]<=10)break;
	}
}

void Obs1_to_Obs2()
{
	Dynamx_Mov_Static_Obs(LEVEL2);
	//Corridor Obs1 to Obs2
	BW_PID_Init_Obs();
	while(Ping[PING_FRONT]>= 20)
	{
		if(Ping[PING_FRONT]<= 20)break;
		BW_FollowCounter_Right_Obs(1);
		if(Ping[PING_FRONT]<= 20)break;
	}
	Dynamx_Mov_Static_Interpolate(LEVEL2,IKCALC_ENABLE);
	Dynamx_Rot_Left_IK(800,STEP4);
//	Dynamx_Mov_Static_Obs(LEVEL2);
}

void Obs2_to_Room1()
{
	int count_obs2_pitch = 0;
	int count_obs2_tracer = 0;
	int param_obs2 = 0;
	int count_obs2_cmps = 0;
	int count_obs2_cmps2 = 0;

	Dynamx_Mov_Static_Obs(LEVEL2);
	//Corridor Obs1 to Obs2
	BW_PID_Init_Obs();

	BW_FollowCounter_Right_Obs(15);

	while(count_obs2_pitch==0)
	{
		CLIMBING_INTERRUPT_FLAG = 1;
		if(BW_CMPS11.PitchKF > 5){count_obs2_pitch=1;}

		BW_FollowCounter_Left_Obs(1);

		lcd_display_clear();
		lcd_gotoxy(0,1);sprintf(lcd,"OBS2 TO ROOM1");lcd_putstr(lcd);
//		lcd_gotoxy(0,2);sprintf(lcd,"Pitch : %d",BW_CMPS11.PitchKF);lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"Pitch : %d",count_obs2_pitch);lcd_putstr(lcd);
//		lcd_gotoxy(0,3);sprintf(lcd,"Tracer: %d",TCS3200_SLV_DATA[1]);lcd_putstr(lcd);
		delay_ms(10);
	}

	Dynamx_Mov_Static_Interpolate(LEVEL2,IKCALC_ENABLE);

	BW_PID_Init();

	while(param_obs2==0)
	{
		TCS3200_Transmit(UART5,CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1]==COLOUR_BLACK){count_obs2_tracer=1;}

		if((count_obs2_pitch==1) && (count_obs2_tracer==1)){param_obs2=1;}

		Dynamx_MovFwd4cm_Interpolate(12,800,IKCALC_ENABLE);
	}

	Dynamx_Mov_Static_Interpolate(LEVEL2,IKCALC_ENABLE);

//	Dynamx_Rot_Left_IK(800,STEP4);

	while(count_obs2_cmps==0)
	{
		GetCMPS11_Angle8Bit();
		if((CMPS11_Angle>=150) && (CMPS11_Angle<=160)){count_obs2_cmps=1;}
		Dynamx_Rot_Left_IK(800,STEP1);
		if((CMPS11_Angle>=150) && (CMPS11_Angle<=160)){count_obs2_cmps=1;}
	}

	Dynamx_Mov_Static_Interpolate(LEVEL2,IKCALC_ENABLE);
	Dynamx_MovFwd4cm_Interpolate(40,800,IKCALC_ENABLE);
	Dynamx_Mov_Static_Interpolate(LEVEL2,IKCALC_ENABLE);

	while(count_obs2_cmps2==0)
	{
		GetCMPS11_Angle8Bit();
		if((CMPS11_Angle>=133) && (CMPS11_Angle<=143)){count_obs2_cmps2=1;}
		Dynamx_Rot_Left_IK(800,STEP1);
		if((CMPS11_Angle>=133) && (CMPS11_Angle<=143)){count_obs2_cmps2=1;}
	}

	Dynamx_Mov_Static_Obs(LEVEL2);
	Dynamx_MovFwd_Obstaicle_Interpolate(OBS_LVL3,5);
	Dynamx_Mov_Static_Obs(LEVEL2);

	while(Ping[PING_FRONT]>= 28)
	{
		if(Ping[PING_FRONT]<= 28)break;
		BW_FollowCounter_Left_Obs(1);
		if(Ping[PING_FRONT]<= 28)break;
	}

	Dynamx_Mov_Static_Obs(LEVEL2);
	delay_ms(1000);
}

void MENU_NEW(void)
{
	coba1:
	while(1)
	{
		goto coba1;
	}
}

void SCAN_KORBAN(void)
{
	int counter_scan=0;
	int counter_loss=0;

	Dynamx_Mov_Static_Interpolate(LEVEL2,IKCALC_ENABLE);
	if(counter_scan==0)
	{
		for(int i=0;i<3;i++)
		{
			if((VL_SENSOR[0] < 200) && (SHARP_GRIPPER[0] < 10)){counter_scan=1;}
			Dynamx_Rot_Left_IK(1500,STEP1);
			if((VL_SENSOR[0] < 200) && (SHARP_GRIPPER[0] < 10)){counter_scan=1;}

			if(counter_scan==1){counter_loss=1;break;}
		}
	}
//	Dynamx_Rot_Left_IK(1500,STEP6);

	Dynamx_Mov_Static_Interpolate(LEVEL2,IKCALC_ENABLE);

	if(counter_loss==0)
	{
		for(int i=0;i<3;i++)
		{
			if((VL_SENSOR[0] < 200) && (SHARP_GRIPPER[0] < 10)){counter_scan=2;break;}
			Dynamx_Rot_Right_IK(1500,STEP1);
			if((VL_SENSOR[0] < 200) && (SHARP_GRIPPER[0] < 10)){counter_scan=2;break;}

			if(counter_scan==2){counter_loss=2;break;}
		}
	}
	mode_scan=MODE_NONE;
	Dynamx_Mov_Static_Interpolate(LEVEL2,IKCALC_ENABLE);
}

void SCAN_KORBAN_K5(void)
{
	int counter_scan=0;
	int counter_loss=0;

	Dynamx_Mov_Static_Interpolate(LEVEL2,IKCALC_ENABLE);
	if(mode_scan_K5==MODE_SCAN_K5_RIGHT)
	{
		for(int i=0;i<4;i++)
		{
			if((VL_SENSOR[0]<220)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<250))){counter_scan=1;break;}//pas
			Dynamx_Rot_Left_IK(1500,STEP1);
			if((VL_SENSOR[0]<220)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<250))){counter_scan=1;break;}//pas

			if(counter_scan==1){break;}
		}
	}
	Dynamx_Mov_Static_Interpolate(LEVEL2,IKCALC_ENABLE);

	if(mode_scan_K5==MODE_SCAN_K5_LEFT)
	{
		for(int i=0;i<4;i++)
		{
			if((VL_SENSOR[0]<220)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<250))){counter_scan=1;break;}//pas
			Dynamx_Rot_Right_IK(1500,STEP1);
			if((VL_SENSOR[0]<220)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<250))){counter_scan=1;break;}//pas

			if(counter_scan==1){break;}
		}
	}
	Dynamx_Mov_Static_Interpolate(LEVEL2,IKCALC_ENABLE);
}


void SCAN_KORBAN_OBS(void)
{
	int counter_scan=0;
	int counter_loss=0;

	Dynamx_Mov_Static_Obs(LEVEL2);
	if(samping_flag_K2==1)
	{
		for(int i=0;i<4;i++)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10)){counter_scan=1;}
			Dynamx_Rot_Obs_Left_IK(OBS_LVL5,STEP1);
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10)){counter_scan=1;}

			if(counter_scan==1){break;}
		}
	}

	Dynamx_Mov_Static_Obs(LEVEL2);

	if(samping_flag_K2==2)
	{
		for(int i=0;i<4;i++)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10)){counter_scan=2;break;}
			Dynamx_Rot_Obs_Right_IK(OBS_LVL5,STEP1);
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10)){counter_scan=2;break;}

			if(counter_scan==2){break;}
		}
	}
	Dynamx_Mov_Static_Obs(LEVEL2);
}

void SCAN_KORBAN_OBS_S2(void)
{
	int counter_scan = 0;
	int counter_loss = 0;

	Dynamx_Mov_Static_Obs(LEVEL2);

	if (counter_scan == 0)
	{
		for (int i = 0; i < 2; i++)
		{
			if ((VL_SENSOR[0] < 200) && (SHARP_GRIPPER[0] < 10))
			{
				counter_scan = 1;
				break;
			}
			Dynamx_Rot_Obs_Left_IK(OBS_LVL5, STEP1);
		}

		if (counter_scan == 1)
		{
			counter_loss = 1;
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				if ((VL_SENSOR[0] < 200) && (SHARP_GRIPPER[0] < 10))
				{
					counter_scan = 1;
					counter_loss = 0;
					break;
				}
				Dynamx_Rot_Obs_Right_IK(OBS_LVL5, STEP1);
			}

			if (counter_scan == 1)
			{
				counter_loss = 2;
			}
		}
	}

	Dynamx_Mov_Static_Obs(LEVEL2);
}

void TES_ROT_CMPS()
{
	int flag=0;

	Dynamx_Mov_Static_Obs(LEVEL2);
	while(flag==0)
	{
		GetCMPS11_Angle8Bit();
		if((CMPS11_Angle>=K2_EAST_LOW) && (CMPS11_Angle<=K2_EAST_UP)){flag=1;}
		Dynamx_Rot_Obs_Left_IK(OBS_LVL5,STEP1);
		if((CMPS11_Angle>=K2_EAST_LOW) && (CMPS11_Angle<=K2_EAST_UP)){flag=1;}
	}
	Dynamx_Mov_Static_Obs(LEVEL2);
}


