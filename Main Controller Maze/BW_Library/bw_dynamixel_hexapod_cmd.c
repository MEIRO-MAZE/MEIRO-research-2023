/*==============================================================================================
							PROJECT BHATARA WIJAYA 3.17 Ver.1.0
					BW DYNAMIXEL AX-18A SMART SERVO HEXAPOD LOCOMOTION LIBRARY
==============================================================================================*/

#include "bw_dynamixel_hexapod_cmd.h"

void HexJoint_Actuate_Interpolate(unsigned char DYNA_ID, int INV_VALUE, int Time_ms)
{
		unsigned int TRUE_MOVE_DATA;
		unsigned int DX_ID = DYNA_ID;

		if(Time_ms <= 0)
		{
			Time_ms = 1;
		}
		switch(DX_ID)
		{
			case 1 :
				F_L.COXA_NEW = abs(INV_VALUE - F_L.COXA_OLD);
				F_L.COXA_OLD = INV_VALUE;
				TRUE_MOVE_DATA = F_L.COXA_NEW;
				break;

			case 2 :
				F_L.FEMUR_NEW = abs(INV_VALUE - F_L.FEMUR_OLD);
				F_L.FEMUR_OLD = INV_VALUE;
				TRUE_MOVE_DATA = F_L.FEMUR_NEW;
				break;

			case 3 :
				F_L.TIBIA_NEW = abs(INV_VALUE - F_L.TIBIA_OLD);
				F_L.TIBIA_OLD = INV_VALUE;
				TRUE_MOVE_DATA = F_L.TIBIA_NEW;
				break;
		// FRONT RIGHT
			case 10 :
				F_R.COXA_NEW = abs(INV_VALUE - F_R.COXA_OLD);
				F_R.COXA_OLD = INV_VALUE;
				TRUE_MOVE_DATA = F_R.COXA_NEW;
				break;

			case 11 :
				F_R.FEMUR_NEW = abs(INV_VALUE - F_R.FEMUR_OLD);
				F_R.FEMUR_OLD = INV_VALUE;
				TRUE_MOVE_DATA = F_R.FEMUR_NEW;
				break;

			case 12 :
				F_R.TIBIA_NEW = abs(INV_VALUE - F_R.TIBIA_OLD);
				F_R.TIBIA_OLD = INV_VALUE;
				TRUE_MOVE_DATA = F_R.TIBIA_NEW;
				break;

			case 4 :
				M_L.COXA_NEW = abs(INV_VALUE - M_L.COXA_OLD);
				M_L.COXA_OLD = INV_VALUE;
				TRUE_MOVE_DATA = M_L.COXA_NEW;
				break;

			case 5 :
				M_L.FEMUR_NEW = abs(INV_VALUE - M_L.FEMUR_OLD);
				M_L.FEMUR_OLD = INV_VALUE;
				TRUE_MOVE_DATA = M_L.FEMUR_NEW;
				break;

			case 6 :
				M_L.TIBIA_NEW = abs(INV_VALUE - M_L.TIBIA_OLD);
				M_L.TIBIA_OLD = INV_VALUE;
				TRUE_MOVE_DATA = M_L.TIBIA_NEW;
				break;

			case 13 :
				M_R.COXA_NEW = abs(INV_VALUE - M_R.COXA_OLD);
				M_R.COXA_OLD = INV_VALUE;
				TRUE_MOVE_DATA = M_R.COXA_NEW;
				break;

			case 14 :
				M_R.FEMUR_NEW = abs(INV_VALUE - M_R.FEMUR_OLD);
				M_R.FEMUR_OLD = INV_VALUE;
				TRUE_MOVE_DATA = M_R.FEMUR_NEW;
				break;

			case 15 :
				M_R.TIBIA_NEW = abs(INV_VALUE - M_R.TIBIA_OLD);
				M_R.TIBIA_OLD = INV_VALUE;
				TRUE_MOVE_DATA = M_R.TIBIA_NEW;
				break;

			case 7 :
				R_L.COXA_NEW = abs(INV_VALUE - R_L.COXA_OLD);
				R_L.COXA_OLD = INV_VALUE;
				TRUE_MOVE_DATA = R_L.COXA_NEW;
				break;

			case 8 :
				R_L.FEMUR_NEW = abs(INV_VALUE - R_L.FEMUR_OLD);
				R_L.FEMUR_OLD = INV_VALUE;
				TRUE_MOVE_DATA = R_L.FEMUR_NEW;
				break;

			case 9 :
				R_L.TIBIA_NEW = abs(INV_VALUE - R_L.TIBIA_OLD);
				R_L.TIBIA_OLD = INV_VALUE;
				TRUE_MOVE_DATA = R_L.TIBIA_NEW;
				break;

			case 16 :
				R_R.COXA_NEW = abs(INV_VALUE - R_R.COXA_OLD);
				R_R.COXA_OLD = INV_VALUE;
				TRUE_MOVE_DATA = R_R.COXA_NEW;
				break;

			case 17 :
				R_R.FEMUR_NEW = abs(INV_VALUE - R_R.FEMUR_OLD);
				R_R.FEMUR_OLD = INV_VALUE;
				TRUE_MOVE_DATA = R_R.FEMUR_NEW;
				break;

			case 18 :
				R_R.TIBIA_NEW = abs(INV_VALUE - R_R.TIBIA_OLD);
				R_R.TIBIA_OLD = INV_VALUE;
				TRUE_MOVE_DATA = R_R.TIBIA_NEW;
				break;
		}

		int SPEED = 10000*TRUE_MOVE_DATA/(6*Time_ms); //10000 is constant obtained from Mr. Zenta's Research on Phoenix Algorithm

		if(SPEED > 1023)
		{
		    INV_VALUE= INV_VALUE*1023;
		    INV_VALUE= INV_VALUE/300;
		    if(INV_VALUE!=0) {INV_VALUE-=1;}

			SPEED = 1023;
			pos_array[(DX_ID)-1] = INV_VALUE;
			speed_array[(DX_ID)-1] = SPEED;
		}
		else if((DX_ID == 17 || DX_ID == 8 || DX_ID == 14 || DX_ID == 5 || DX_ID == 11 || DX_ID == 2))
		{
		    INV_VALUE= INV_VALUE*1024;
		    INV_VALUE= INV_VALUE/300;
		    if(INV_VALUE!=0) {INV_VALUE-=1;}
		    if(CURVE_STAT == 0 && (DX_ID == 2 || DX_ID == 5 || DX_ID == 8))
		    {
		    	SPEED = 250;
		    }
		    else if(CURVE_STAT == 1 && (DX_ID == 17 || DX_ID == 14 || DX_ID == 11))
		    {
		    	SPEED = 250;
		    }
		    else
		    {
				SPEED = 300;
		    }
			pos_array[(DX_ID)-1] = INV_VALUE;
			speed_array[(DX_ID)-1] = SPEED;
		}
		else
		{
		    INV_VALUE= INV_VALUE*1024;
		    INV_VALUE= INV_VALUE/300;
		    if(INV_VALUE!=0) {INV_VALUE-=1;}

			pos_array[(DX_ID)-1] = INV_VALUE;
			speed_array[(DX_ID)-1] = SPEED;
		}
}

void HexJoint_Actuate_Climbing(unsigned char DYNA_ID, int INV_VALUE, int Time_ms)
{
	unsigned int TRUE_MOVE_DATA;
	unsigned int DX_ID = DYNA_ID;

	if(Time_ms <= 0)
	{
		Time_ms = 1;
	}
	switch(DX_ID)
	{
	// FRONT LEFT
	case 1 :
		F_L.COXA_NEW = abs(INV_VALUE - F_L.COXA_OLD);
		F_L.COXA_OLD = INV_VALUE;
		TRUE_MOVE_DATA = F_L.COXA_NEW;
		break;

	case 2 :
		F_L.FEMUR_NEW = abs(INV_VALUE - F_L.FEMUR_OLD);
		F_L.FEMUR_OLD = INV_VALUE;
		TRUE_MOVE_DATA = F_L.FEMUR_NEW;
		break;

	case 3 :
		F_L.TIBIA_NEW = abs(INV_VALUE - F_L.TIBIA_OLD);
		F_L.TIBIA_OLD = INV_VALUE;
		TRUE_MOVE_DATA = F_L.TIBIA_NEW;
		break;
		// FRONT RIGHT
	case 10 :
		F_R.COXA_NEW = abs(INV_VALUE - F_R.COXA_OLD);
		F_R.COXA_OLD = INV_VALUE;
		TRUE_MOVE_DATA = F_R.COXA_NEW;
		break;

	case 11 :
		F_R.FEMUR_NEW = abs(INV_VALUE - F_R.FEMUR_OLD);
		F_R.FEMUR_OLD = INV_VALUE;
		TRUE_MOVE_DATA = F_R.FEMUR_NEW;
		break;

	case 12 :
		F_R.TIBIA_NEW = abs(INV_VALUE - F_R.TIBIA_OLD);
		F_R.TIBIA_OLD = INV_VALUE;
		TRUE_MOVE_DATA = F_R.TIBIA_NEW;
		break;
		//MIDDLE LEFT
	case 4 :
		M_L.COXA_NEW = abs(INV_VALUE - M_L.COXA_OLD);
		M_L.COXA_OLD = INV_VALUE;
		TRUE_MOVE_DATA = M_L.COXA_NEW;
		break;

	case 5 :
		M_L.FEMUR_NEW = abs(INV_VALUE - M_L.FEMUR_OLD);
		M_L.FEMUR_OLD = INV_VALUE;
		TRUE_MOVE_DATA = M_L.FEMUR_NEW;
		break;

	case 6 :
		M_L.TIBIA_NEW = abs(INV_VALUE - M_L.TIBIA_OLD);
		M_L.TIBIA_OLD = INV_VALUE;
		TRUE_MOVE_DATA = M_L.TIBIA_NEW;
		break;
		// MIDDLE RIGHT
	case 13 :
		M_R.COXA_NEW = abs(INV_VALUE - M_R.COXA_OLD);
		M_R.COXA_OLD = INV_VALUE;
		TRUE_MOVE_DATA = M_R.COXA_NEW;
		break;

	case 14 :
		M_R.FEMUR_NEW = abs(INV_VALUE - M_R.FEMUR_OLD);
		M_R.FEMUR_OLD = INV_VALUE;
		TRUE_MOVE_DATA = M_R.FEMUR_NEW;
		break;

	case 15 :
		M_R.TIBIA_NEW = abs(INV_VALUE - M_R.TIBIA_OLD);
		M_R.TIBIA_OLD = INV_VALUE;
		TRUE_MOVE_DATA = M_R.TIBIA_NEW;
		break;
		// REAR LEFT
	case 7 :
		R_L.COXA_NEW = abs(INV_VALUE - R_L.COXA_OLD);
		R_L.COXA_OLD = INV_VALUE;
		TRUE_MOVE_DATA = R_L.COXA_NEW;
		break;

	case 8 :
		R_L.FEMUR_NEW = abs(INV_VALUE - R_L.FEMUR_OLD);
		R_L.FEMUR_OLD = INV_VALUE;
		TRUE_MOVE_DATA = R_L.FEMUR_NEW;
		break;

	case 9 :
		R_L.TIBIA_NEW = abs(INV_VALUE - R_L.TIBIA_OLD);
		R_L.TIBIA_OLD = INV_VALUE;
		TRUE_MOVE_DATA = R_L.TIBIA_NEW;
		break;
		// REAR RIGHT
	case 16 :
		R_R.COXA_NEW = abs(INV_VALUE - R_R.COXA_OLD);
		R_R.COXA_OLD = INV_VALUE;
		TRUE_MOVE_DATA = R_R.COXA_NEW;
		break;

	case 17 :
		R_R.FEMUR_NEW = abs(INV_VALUE - R_R.FEMUR_OLD);
		R_R.FEMUR_OLD = INV_VALUE;
		TRUE_MOVE_DATA = R_R.FEMUR_NEW;
		break;

	case 18 :
		R_R.TIBIA_NEW = abs(INV_VALUE - R_R.TIBIA_OLD);
		R_R.TIBIA_OLD = INV_VALUE;
		TRUE_MOVE_DATA = R_R.TIBIA_NEW;
		break;
	}

		int SPEED = 10000*TRUE_MOVE_DATA/(6*Time_ms);


		if(SPEED >= 1023)
		{
			SPEED = 1023;
		}

		if((DX_ID == 17 || DX_ID == 8 || DX_ID == 14 || DX_ID == 5 || DX_ID == 11 || DX_ID == 2))
		{
			SPEED = 150;
		}

		else
		{
			SPEED = SPEED;
		}


	INV_VALUE= INV_VALUE*1024;
	INV_VALUE= INV_VALUE/300;
	if(INV_VALUE!=0) {INV_VALUE-=1;}

	pos_array[(DX_ID)-1] = INV_VALUE;
	speed_array[(DX_ID)-1] = SPEED;
}

void HexJoint_Actuate_New(unsigned char DYNA_ID, int INV_VALUE, int Time_ms)
{
	unsigned int TRUE_MOVE_DATA;
	unsigned int DX_ID = DYNA_ID;

	if(Time_ms <= 0)
	{
		Time_ms = 1;
	}
	switch(DX_ID)
	{
	// FRONT LEFT
	case 1 :
		F_L.COXA_NEW = abs(INV_VALUE - F_L.COXA_OLD);
		F_L.COXA_OLD = INV_VALUE;
		TRUE_MOVE_DATA = F_L.COXA_NEW;
		break;

	case 2 :
		F_L.FEMUR_NEW = abs(INV_VALUE - F_L.FEMUR_OLD);
		F_L.FEMUR_OLD = INV_VALUE;
		TRUE_MOVE_DATA = F_L.FEMUR_NEW;
		break;

	case 3 :
		F_L.TIBIA_NEW = abs(INV_VALUE - F_L.TIBIA_OLD);
		F_L.TIBIA_OLD = INV_VALUE;
		TRUE_MOVE_DATA = F_L.TIBIA_NEW;
		break;
		// FRONT RIGHT
	case 10 :
		F_R.COXA_NEW = abs(INV_VALUE - F_R.COXA_OLD);
		F_R.COXA_OLD = INV_VALUE;
		TRUE_MOVE_DATA = F_R.COXA_NEW;
		break;

	case 11 :
		F_R.FEMUR_NEW = abs(INV_VALUE - F_R.FEMUR_OLD);
		F_R.FEMUR_OLD = INV_VALUE;
		TRUE_MOVE_DATA = F_R.FEMUR_NEW;
		break;

	case 12 :
		F_R.TIBIA_NEW = abs(INV_VALUE - F_R.TIBIA_OLD);
		F_R.TIBIA_OLD = INV_VALUE;
		TRUE_MOVE_DATA = F_R.TIBIA_NEW;
		break;
		//MIDDLE LEFT
	case 4 :
		M_L.COXA_NEW = abs(INV_VALUE - M_L.COXA_OLD);
		M_L.COXA_OLD = INV_VALUE;
		TRUE_MOVE_DATA = M_L.COXA_NEW;
		break;

	case 5 :
		M_L.FEMUR_NEW = abs(INV_VALUE - M_L.FEMUR_OLD);
		M_L.FEMUR_OLD = INV_VALUE;
		TRUE_MOVE_DATA = M_L.FEMUR_NEW;
		break;

	case 6 :
		M_L.TIBIA_NEW = abs(INV_VALUE - M_L.TIBIA_OLD);
		M_L.TIBIA_OLD = INV_VALUE;
		TRUE_MOVE_DATA = M_L.TIBIA_NEW;
		break;
		// MIDDLE RIGHT
	case 13 :
		M_R.COXA_NEW = abs(INV_VALUE - M_R.COXA_OLD);
		M_R.COXA_OLD = INV_VALUE;
		TRUE_MOVE_DATA = M_R.COXA_NEW;
		break;

	case 14 :
		M_R.FEMUR_NEW = abs(INV_VALUE - M_R.FEMUR_OLD);
		M_R.FEMUR_OLD = INV_VALUE;
		TRUE_MOVE_DATA = M_R.FEMUR_NEW;
		break;

	case 15 :
		M_R.TIBIA_NEW = abs(INV_VALUE - M_R.TIBIA_OLD);
		M_R.TIBIA_OLD = INV_VALUE;
		TRUE_MOVE_DATA = M_R.TIBIA_NEW;
		break;
		// REAR LEFT
	case 7 :
		R_L.COXA_NEW = abs(INV_VALUE - R_L.COXA_OLD);
		R_L.COXA_OLD = INV_VALUE;
		TRUE_MOVE_DATA = R_L.COXA_NEW;
		break;

	case 8 :
		R_L.FEMUR_NEW = abs(INV_VALUE - R_L.FEMUR_OLD);
		R_L.FEMUR_OLD = INV_VALUE;
		TRUE_MOVE_DATA = R_L.FEMUR_NEW;
		break;

	case 9 :
		R_L.TIBIA_NEW = abs(INV_VALUE - R_L.TIBIA_OLD);
		R_L.TIBIA_OLD = INV_VALUE;
		TRUE_MOVE_DATA = R_L.TIBIA_NEW;
		break;
		// REAR RIGHT
	case 16 :
		R_R.COXA_NEW = abs(INV_VALUE - R_R.COXA_OLD);
		R_R.COXA_OLD = INV_VALUE;
		TRUE_MOVE_DATA = R_R.COXA_NEW;
		break;

	case 17 :
		R_R.FEMUR_NEW = abs(INV_VALUE - R_R.FEMUR_OLD);
		R_R.FEMUR_OLD = INV_VALUE;
		TRUE_MOVE_DATA = R_R.FEMUR_NEW;
		break;

	case 18 :
		R_R.TIBIA_NEW = abs(INV_VALUE - R_R.TIBIA_OLD);
		R_R.TIBIA_OLD = INV_VALUE;
		TRUE_MOVE_DATA = R_R.TIBIA_NEW;
		break;
	}

	int SPEED = 10000*TRUE_MOVE_DATA/(6*Time_ms);

	if(SPEED > 1023)
	{
		SPEED = 1023;
	}
	if(CLIMBING_FLAG == 1)
	{
		if(SPEED <= 0)
		{
			SPEED = 100;
		}
		else
		{
			if((DX_ID == 17 || DX_ID == 8 || DX_ID == 14 || DX_ID == 5 || DX_ID == 11 || DX_ID == 2))
			{
				SPEED = 300;
			}

		}
	}
	else
	{
		if((DX_ID == 17 || DX_ID == 8 || DX_ID == 14 || DX_ID == 5 || DX_ID == 11 || DX_ID == 2))
		{
			SPEED = 300;
		}
	}

	INV_VALUE= INV_VALUE*1023;
	INV_VALUE= INV_VALUE/300;
	if(INV_VALUE!=0) {INV_VALUE-=1;}

	pos_array[(DX_ID)-1] = INV_VALUE;
	speed_array[(DX_ID)-1] = SPEED;
}


void Dynamx_MovFwd_Interpolate_6S(unsigned int distance, int SPEED, int IKCALC_STAT)
{
	int limit= distance/4;
	int loop;
	int cek_value = 0;

	if(IKCALC_STAT == IKCALC_ENABLE)
	{
		if(IK_CALCULATED_FWD == 0)
		{
			Generate_Body(0,1.5);
			Trajectory_Generator_6S(X_Diff, Y_Diff, -2, 6,MOVEMENT_NORMAL);
			for(i=0;i<=5;i++)
			{
				Dyna_IKCalc_Only((X_IK_BEGIN[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]+Z_IK[i]));
				FEMUR_D[i] = tetha.Femur;
				COXA_D[i] = tetha.Coxa;
				NFEMUR_D[i] = (tetha.Femur*-1);
				NCOXA_D[i] = (tetha.Coxa*-1);

				Dyna_IKCalc_Only((X_IK_BEGIN[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
				TIBIA_D[i] = tetha.Tibia;

				Dyna_IKCalc_Only((X_IK_BEGIN[0]-X4_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
				NTIBIA_D[i] = tetha.Tibia;

				Dyna_IKCalc_Only((X_IK_BEGIN[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
				NTIBIA_D_R[i] = tetha.Tibia;

				Dyna_IKCalc_Only((X_IK_BEGIN[0]+X4_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
				TIBIA_D_R[i] = tetha.Tibia;
			}
			IK_CALCULATED_BWD = 0;
			IK_CALCULATED_FWD = 1;
		}
	}

	SPEED = SPEED/45;

	if (cek_value==1)
	{
		lcd_display_clear();
//		lcd_gotoxy(0,0);sprintf(lcd,"COXA VALUE");lcd_putstr(lcd);
//		lcd_gotoxy(0,1);sprintf(lcd,"%d|%d|%d",COXA_D[0],COXA_D[1],COXA_D[2]);lcd_putstr(lcd);
//		lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d",COXA_D[3],COXA_D[4],COXA_D[5]);lcd_putstr(lcd);

		lcd_gotoxy(0,0);sprintf(lcd,"FEMUR VALUE");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"%d|%d|%d",FEMUR_D[0],FEMUR_D[1],FEMUR_D[2]);lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d",FEMUR_D[3],FEMUR_D[4],FEMUR_D[5]);lcd_putstr(lcd);

//		lcd_gotoxy(0,0);sprintf(lcd,"TIBIA VALUE");lcd_putstr(lcd);
//		lcd_gotoxy(0,1);sprintf(lcd,"%d|%d|%d",TIBIA_D[0],TIBIA_D[1],TIBIA_D[2]);lcd_putstr(lcd);
//		lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d",TIBIA_D[3],TIBIA_D[4],TIBIA_D[5]);lcd_putstr(lcd);

		while(1){}

	}

	switch(IKCALC_STAT)
	{
		case IKCALC_ENABLE:
		{
			FOWARD_STAT = 1;
			for(loop=1;loop<=limit;loop++)
			{
				if(mode_korban==MODE_K1)
				{
					if((VL_SENSOR[0]<150)&&(TCS34725_SLV_DATA[2]<300)&&(SHARP_GRIPPER[0]<10))break;
				}
				if(mode_korban==MODE_K2)
				{
					if((VL_SENSOR[0]<200)&&(TCS34725_SLV_DATA[0]>=120)&&(SHARP_GRIPPER[0]<10))break;
				}
				if(mode_korban==MODE_K5)
				{
					if((VL_SENSOR[0]<190)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<270))){break;}//pas
				}

				//SIKLUS 1
				//	1
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_D[0]),(FEMUR_D[5]),(TIBIA_D[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_D[0]),(FEMUR_D[5]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_D[0]),(FEMUR_D[5]),(NTIBIA_D_R[0]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_D[0]),(Z_STATIC_IK[0]),(NTIBIA_D[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_D[0]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_D[0]),(Z_STATIC_IK[4]),(TIBIA_D_R[0]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);
				// 2
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_D[1]),(FEMUR_D[4]),(TIBIA_D[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_D[1]),(FEMUR_D[4]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_D[1]),(FEMUR_D[4]),(NTIBIA_D_R[1]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_D[1]),(Z_STATIC_IK[0]),(NTIBIA_D[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_D[1]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_D[1]),(Z_STATIC_IK[4]),(TIBIA_D_R[1]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);
				// 3
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_D[2]),(FEMUR_D[3]),(TIBIA_D[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_D[2]),(FEMUR_D[3]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_D[2]),(FEMUR_D[3]),(NTIBIA_D_R[2]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_D[2]),(Z_STATIC_IK[0]),(NTIBIA_D[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_D[2]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_D[2]),(Z_STATIC_IK[4]),(TIBIA_D_R[2]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);
				//	4
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_D[3]),(FEMUR_D[2]),(TIBIA_D[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_D[3]),(FEMUR_D[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_D[3]),(FEMUR_D[2]),(NTIBIA_D_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_D[3]),(Z_STATIC_IK[0]),(NTIBIA_D[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_D[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_D[3]),(Z_STATIC_IK[4]),(TIBIA_D_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);
				//	5
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_D[4]),(FEMUR_D[1]),(TIBIA_D[4]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_D[4]),(FEMUR_D[1]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_D[4]),(FEMUR_D[1]),(NTIBIA_D_R[4]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_D[4]),(Z_STATIC_IK[0]),(NTIBIA_D[4]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_D[4]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_D[4]),(Z_STATIC_IK[4]),(TIBIA_D_R[4]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);
				//	6
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_D[5]),(FEMUR_D[0]),(TIBIA_D[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_D[5]),(FEMUR_D[0]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_D[5]),(FEMUR_D[0]),(NTIBIA_D_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[0]),(NTIBIA_D[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[4]),(TIBIA_D_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				if(mode_korban==MODE_K1)
				{
					if((VL_SENSOR[0]<150)&&(TCS34725_SLV_DATA[2]<300)&&(SHARP_GRIPPER[0]<10))break;
				}
				if(mode_korban==MODE_K2)
				{
					if((VL_SENSOR[0]<200)&&(TCS34725_SLV_DATA[0]>=120)&&(SHARP_GRIPPER[0]<10))break;
				}
				if(mode_korban==MODE_K5)
				{
					if((VL_SENSOR[0]<190)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<270))){break;}//pas
				}


				//SIKLUS 2
				//	1
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_D[5]),(Z_STATIC_IK[1]),(TIBIA_D[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_D[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_D[5]),(Z_STATIC_IK[5]),(NTIBIA_D_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[0]),(NTIBIA_D[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[4]),(TIBIA_D_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//	2
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_D[5]),(Z_STATIC_IK[1]),(TIBIA_D[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_D[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_D[5]),(Z_STATIC_IK[5]),(NTIBIA_D_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[0]),(NTIBIA_D[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[4]),(TIBIA_D_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//	3
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_D[5]),(Z_STATIC_IK[1]),(TIBIA_D[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_D[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_D[5]),(Z_STATIC_IK[5]),(NTIBIA_D_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[0]),(NTIBIA_D[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[4]),(TIBIA_D_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//	4
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_D[5]),(Z_STATIC_IK[1]),(TIBIA_D[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_D[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_D[5]),(Z_STATIC_IK[5]),(NTIBIA_D_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[0]),(NTIBIA_D[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[4]),(TIBIA_D_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//	5
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_D[5]),(Z_STATIC_IK[1]),(TIBIA_D[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_D[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_D[5]),(Z_STATIC_IK[5]),(NTIBIA_D_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[0]),(NTIBIA_D[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[4]),(TIBIA_D_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//	6
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_D[5]),(Z_STATIC_IK[1]),(TIBIA_D[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_D[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_D[5]),(Z_STATIC_IK[5]),(NTIBIA_D_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[0]),(NTIBIA_D[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[4]),(TIBIA_D_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				if(mode_korban==MODE_K1)
				{
					if((VL_SENSOR[0]<150)&&(TCS34725_SLV_DATA[2]<300)&&(SHARP_GRIPPER[0]<10))break;
				}
				if(mode_korban==MODE_K2)
				{
					if((VL_SENSOR[0]<200)&&(TCS34725_SLV_DATA[0]>=120)&&(SHARP_GRIPPER[0]<10))break;
				}
				if(mode_korban==MODE_K5)
				{
					if((VL_SENSOR[0]<190)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<270))){break;}//pas
				}


				//SIKLUS 3
				//	1
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_D[4]),(Z_STATIC_IK[1]),(TIBIA_D[4]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_D[4]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_D[4]),(Z_STATIC_IK[5]),(NTIBIA_D_R[4]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_D[4]),(FEMUR_D[0]),(NTIBIA_D[4]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_D[4]),(FEMUR_D[0]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_D[4]),(FEMUR_D[0]),(TIBIA_D_R[4]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//	2
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_D[3]),(Z_STATIC_IK[1]),(TIBIA_D[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_D[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_D[3]),(Z_STATIC_IK[5]),(NTIBIA_D_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_D[3]),(FEMUR_D[1]),(NTIBIA_D[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_D[3]),(FEMUR_D[1]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_D[3]),(FEMUR_D[1]),(TIBIA_D_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//	3
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_D[2]),(Z_STATIC_IK[1]),(TIBIA_D[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_D[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_D[2]),(Z_STATIC_IK[5]),(NTIBIA_D_R[2]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_D[2]),(FEMUR_D[2]),(NTIBIA_D[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_D[2]),(FEMUR_D[2]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_D[2]),(FEMUR_D[2]),(TIBIA_D_R[2]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//	4
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_D[1]),(Z_STATIC_IK[1]),(TIBIA_D[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_D[1]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_D[1]),(Z_STATIC_IK[5]),(NTIBIA_D_R[1]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_D[1]),(FEMUR_D[3]),(NTIBIA_D[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_D[1]),(FEMUR_D[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_D[1]),(FEMUR_D[3]),(TIBIA_D_R[1]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//	5
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_D[0]),(Z_STATIC_IK[1]),(TIBIA_D[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_D[0]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_D[0]),(Z_STATIC_IK[5]),(NTIBIA_D_R[0]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_D[0]),(FEMUR_D[4]),(NTIBIA_D[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_D[0]),(FEMUR_D[4]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_D[0]),(FEMUR_D[4]),(TIBIA_D_R[0]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//	6
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK[1]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK[5]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK[0]),(FEMUR_D[5]),(X_STATIC_IK[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(FEMUR_D[5]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK[4]),(FEMUR_D[5]),(X_STATIC_IK[4]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				if(mode_korban==MODE_K1)
				{
					if((VL_SENSOR[0]<150)&&(TCS34725_SLV_DATA[2]<300)&&(SHARP_GRIPPER[0]<10))break;
				}
				if(mode_korban==MODE_K2)
				{
					if((VL_SENSOR[0]<200)&&(TCS34725_SLV_DATA[0]>=120)&&(SHARP_GRIPPER[0]<10))break;
				}
				if(mode_korban==MODE_K5)
				{
					if((VL_SENSOR[0]<190)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<270))){break;}//pas
				}


				//SIKLUS 4
				//	1
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_D[0]),(Z_STATIC_IK[1]),(NTIBIA_D[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_D[0]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_D[0]),(Z_STATIC_IK[5]),(TIBIA_D_R[0]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_D[0]),(FEMUR_D[5]),(TIBIA_D[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_D[0]),(FEMUR_D[5]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_D[0]),(FEMUR_D[5]),(NTIBIA_D_R[0]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//	2
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_D[1]),(Z_STATIC_IK[1]),(NTIBIA_D[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_D[1]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_D[1]),(Z_STATIC_IK[5]),(TIBIA_D_R[1]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_D[1]),(FEMUR_D[4]),(TIBIA_D[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_D[1]),(FEMUR_D[4]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_D[1]),(FEMUR_D[4]),(NTIBIA_D_R[1]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//	3
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_D[2]),(Z_STATIC_IK[1]),(NTIBIA_D[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_D[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_D[2]),(Z_STATIC_IK[5]),(TIBIA_D_R[2]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_D[2]),(FEMUR_D[3]),(TIBIA_D[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_D[2]),(FEMUR_D[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_D[2]),(FEMUR_D[3]),(NTIBIA_D_R[2]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//	4
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_D[3]),(Z_STATIC_IK[1]),(NTIBIA_D[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_D[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_D[3]),(Z_STATIC_IK[5]),(TIBIA_D_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_D[3]),(FEMUR_D[2]),(TIBIA_D[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_D[3]),(FEMUR_D[2]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_D[3]),(FEMUR_D[2]),(NTIBIA_D_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//	5
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_D[4]),(Z_STATIC_IK[1]),(NTIBIA_D[4]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_D[4]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_D[4]),(Z_STATIC_IK[5]),(TIBIA_D_R[4]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_D[4]),(FEMUR_D[1]),(TIBIA_D[4]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_D[4]),(FEMUR_D[1]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_D[4]),(FEMUR_D[1]),(NTIBIA_D_R[4]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//	6
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[1]),(NTIBIA_D[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[5]),(TIBIA_D_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_D[5]),(FEMUR_D[0]),(TIBIA_D[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_D[5]),(FEMUR_D[0]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_D[5]),(FEMUR_D[0]),(NTIBIA_D_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				if(mode_korban==MODE_K1)
				{
					if((VL_SENSOR[0]<150)&&(TCS34725_SLV_DATA[2]<300)&&(SHARP_GRIPPER[0]<10))break;
				}
				if(mode_korban==MODE_K2)
				{
					if((VL_SENSOR[0]<200)&&(TCS34725_SLV_DATA[0]>=120)&&(SHARP_GRIPPER[0]<10))break;
				}
				if(mode_korban==MODE_K5)
				{
					if((VL_SENSOR[0]<190)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<270))){break;}//pas
				}


				//SIKLUS 5
				//	1
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[1]),(NTIBIA_D[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[5]),(TIBIA_D_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_D[5]),(Z_STATIC_IK[0]),(TIBIA_D[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_D[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_D[5]),(Z_STATIC_IK[4]),(NTIBIA_D_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//	2
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[1]),(NTIBIA_D[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[5]),(TIBIA_D_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_D[5]),(Z_STATIC_IK[0]),(TIBIA_D[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_D[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_D[5]),(Z_STATIC_IK[4]),(NTIBIA_D_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//	3
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[1]),(NTIBIA_D[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[5]),(TIBIA_D_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_D[5]),(Z_STATIC_IK[0]),(TIBIA_D[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_D[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_D[5]),(Z_STATIC_IK[4]),(NTIBIA_D_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//	4
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[1]),(NTIBIA_D[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[5]),(TIBIA_D_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_D[5]),(Z_STATIC_IK[0]),(TIBIA_D[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_D[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_D[5]),(Z_STATIC_IK[4]),(NTIBIA_D_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//	5
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[1]),(NTIBIA_D[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[5]),(TIBIA_D_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_D[5]),(Z_STATIC_IK[0]),(TIBIA_D[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_D[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_D[5]),(Z_STATIC_IK[4]),(NTIBIA_D_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//	6
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[1]),(NTIBIA_D[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_D[5]),(Z_STATIC_IK[5]),(TIBIA_D_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_D[5]),(Z_STATIC_IK[0]),(TIBIA_D[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_D[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_D[5]),(Z_STATIC_IK[4]),(NTIBIA_D_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				if(mode_korban==MODE_K1)
				{
					if((VL_SENSOR[0]<150)&&(TCS34725_SLV_DATA[2]<300)&&(SHARP_GRIPPER[0]<10))break;
				}
				if(mode_korban==MODE_K2)
				{
					if((VL_SENSOR[0]<200)&&(TCS34725_SLV_DATA[0]>=120)&&(SHARP_GRIPPER[0]<10))break;
				}
				if(mode_korban==MODE_K5)
				{
					if((VL_SENSOR[0]<190)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<270))){break;}//pas
				}


				//SIKLUS 6
				//	1
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_D[4]),(FEMUR_D[0]),(NTIBIA_D[4]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_D[4]),(FEMUR_D[0]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_D[4]),(FEMUR_D[0]),(TIBIA_D_R[4]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_D[4]),(Z_STATIC_IK[0]),(TIBIA_D[4]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_D[4]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_D[4]),(Z_STATIC_IK[4]),(NTIBIA_D_R[4]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//	2
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_D[3]),(FEMUR_D[1]),(NTIBIA_D[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_D[3]),(FEMUR_D[1]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_D[3]),(FEMUR_D[1]),(TIBIA_D_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_D[3]),(Z_STATIC_IK[0]),(TIBIA_D[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_D[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_D[3]),(Z_STATIC_IK[4]),(NTIBIA_D_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//	3
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_D[2]),(FEMUR_D[2]),(NTIBIA_D[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_D[2]),(FEMUR_D[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_D[2]),(FEMUR_D[2]),(TIBIA_D_R[2]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_D[2]),(Z_STATIC_IK[0]),(TIBIA_D[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_D[2]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_D[2]),(Z_STATIC_IK[4]),(NTIBIA_D_R[2]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//	4
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_D[1]),(FEMUR_D[3]),(NTIBIA_D[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_D[1]),(FEMUR_D[3]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_D[1]),(FEMUR_D[3]),(TIBIA_D_R[1]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_D[1]),(Z_STATIC_IK[0]),(TIBIA_D[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_D[1]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_D[1]),(Z_STATIC_IK[4]),(NTIBIA_D_R[1]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//	5
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_D[0]),(FEMUR_D[4]),(NTIBIA_D[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_D[0]),(FEMUR_D[4]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_D[0]),(FEMUR_D[4]),(TIBIA_D_R[0]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_D[0]),(Z_STATIC_IK[0]),(TIBIA_D[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_D[0]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_D[0]),(Z_STATIC_IK[4]),(NTIBIA_D_R[0]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//	6
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK[1]),(FEMUR_D[5]),(X_STATIC_IK[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(FEMUR_D[5]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK[5]),(FEMUR_D[5]),(X_STATIC_IK[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK[0]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK[4]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				if(mode_korban==MODE_K1)
				{
					if((VL_SENSOR[0]<150)&&(TCS34725_SLV_DATA[2]<300)&&(SHARP_GRIPPER[0]<10))break;
				}
				if(mode_korban==MODE_K2)
				{
					if((VL_SENSOR[0]<200)&&(TCS34725_SLV_DATA[0]>=120)&&(SHARP_GRIPPER[0]<10))break;
				}
				if(mode_korban==MODE_K5)
				{
					if((VL_SENSOR[0]<190)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<270))){break;}//pas
				}


			}
		}break;

		case IKCALC_DISABLE:
		{
			for (loop=1;loop<=limit;loop++)
				{

				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//2
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
				//BW_Tracer_Check();

				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//3
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R3[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R3[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L3[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R3[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R3[2]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L3[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R3[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L3[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L3[0]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//3
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R2[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R2[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R2[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R2[2]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L2[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L2[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L2[0]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//3
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R1[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R1[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L1[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R1[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R1[2]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L1[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L1[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L1[0]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//3
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R[2]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//3
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R[2]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);


				if(CAT_DETECTOR==CAT_ACTIVATED)
							{
								Cat_Avoider();
								if(CAT_FLAG ==CAT_DETECTED)break;
							}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//4
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]);
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//belakang angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//4
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L1[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R1[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L1[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L1[0]);
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R1[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//belakang angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R1[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//4
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L2[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L2[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L2[0]);
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R2[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//belakang angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R2[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//4
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L3[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R3[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L3[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L3[0]);
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R3[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L3[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//belakang angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R3[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				if(CAT_DETECTOR==CAT_ACTIVATED)
							{
								Cat_Avoider();
								if(CAT_FLAG ==CAT_DETECTED)break;
							}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//5
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);//tengah angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				if(CAT_DETECTOR==CAT_ACTIVATED)
							{
								Cat_Avoider();
								if(CAT_FLAG ==CAT_DETECTED)break;
							}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
				//BW_Tracer_Check();

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//6
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R3[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L3[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R3[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R3[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L3[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L3[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R3[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L3[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L3[2]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//6
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R2[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R2[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R2[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L2[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L2[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L2[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L2[2]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//6
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R1[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R1[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R1[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L1[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L1[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R1[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L1[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L1[2]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//6
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L[2]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//6
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L[2]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);


				if(CAT_DETECTOR==CAT_ACTIVATED)
							{
								Cat_Avoider();
								if(CAT_FLAG ==CAT_DETECTED)break;
							}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//1
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//belakang angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//1
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R1[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L1[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R1[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R1[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L1[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//belakang angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L1[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//1
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R2[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R2[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R2[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L2[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//belakang angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L2[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//1
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R3[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L3[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R3[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R3[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L3[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R3[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//belakang angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L3[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}

				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				}
		}break;
		FOWARD_STAT = 0;
	}

}


void Dynamx_MovFwd4cm_Interpolate(unsigned int distance, int SPEED, int IKCALC_STAT)
{
	int limit= distance/4;
	int loop;
	int cek_value = 0;

	if(IKCALC_STAT == IKCALC_ENABLE)
	{
		if(IK_CALCULATED_FWD == 0)
		{
			Generate_Body(0,1.5);
			Trajectory_Generator_NEW(X_Diff, Y_Diff, -2, 4,MOVEMENT_NORMAL);
			for(i=0;i<=3;i++)
			{
				Dyna_IKCalc_Only((X_IK_BEGIN[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]+Z_IK[i]));
				FEMUR_A[i] = tetha.Femur;
				COXA_A[i] = tetha.Coxa;
				NFEMUR_A[i] = (tetha.Femur*-1);
				NCOXA_A[i] = (tetha.Coxa*-1);

				Dyna_IKCalc_Only((X_IK_BEGIN[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
				TIBIA_A[i] = tetha.Tibia;

				Dyna_IKCalc_Only((X_IK_BEGIN[0]-X4_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
				NTIBIA_A[i] = tetha.Tibia;

				Dyna_IKCalc_Only((X_IK_BEGIN[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
				NTIBIA_A_R[i] = tetha.Tibia;

				Dyna_IKCalc_Only((X_IK_BEGIN[0]+X4_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
				TIBIA_A_R[i] = tetha.Tibia;
			}
			IK_CALCULATED_BWD = 0;
			IK_CALCULATED_FWD = 1;
		}
	}

	SPEED = SPEED/45;

	if (cek_value==1)
	{
		lcd_display_clear();
//		lcd_gotoxy(0,0);sprintf(lcd,"COXA VALUE");lcd_putstr(lcd);
//		lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d|%d",COXA_A[0],COXA_A[1],COXA_A[2],COXA_A[3]);lcd_putstr(lcd);
//		lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d|%d",NCOXA_A[0],NCOXA_A[1],NCOXA_A[2],NCOXA_A[3]);lcd_putstr(lcd);

//		lcd_gotoxy(0,0);sprintf(lcd,"FEMUR VALUE");lcd_putstr(lcd);
//		lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d|%d",FEMUR_A[0],FEMUR_A[1],FEMUR_A[2],FEMUR_A[3]);lcd_putstr(lcd);
//		lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d|%d",NFEMUR_A[0],NFEMUR_A[1],NFEMUR_A[2],NFEMUR_A[3]);lcd_putstr(lcd);

//		lcd_gotoxy(0,0);sprintf(lcd,"FEMUR VALUE");lcd_putstr(lcd);
		lcd_gotoxy(0,0);sprintf(lcd,"%d|%d|%d|%d",TIBIA_A[0],TIBIA_A[1],TIBIA_A[2],TIBIA_A[3]);lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"%d|%d|%d|%d",NTIBIA_A[0],NTIBIA_A[1],NTIBIA_A[2],NTIBIA_A[3]);lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d|%d",TIBIA_A_R[0],TIBIA_A_R[1],TIBIA_A_R[2],TIBIA_A_R[3]);lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d|%d",NTIBIA_A_R[0],NTIBIA_A_R[1],NTIBIA_A_R[2],NTIBIA_A_R[3]);lcd_putstr(lcd);

		while(1){}

	}

	switch(IKCALC_STAT)
	{
		case IKCALC_ENABLE:
		{
			FOWARD_STAT = 1;
			for(loop=1;loop<=limit;loop++)
			{
				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}

				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
				{
					Stairs_Detector();
					if(STAIRS_FLAG == STAIRS_DETECTED)break;
				}

				if(FOLLOW_TRACER_STATE == 1)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
				}

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}

				if(FOLLOW_CARPET_MODE == NORMAL)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

				}
				else if(FOLLOW_CARPET_MODE == INVERSE)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

				}

				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				//SIKLUS 1
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[0]),(FEMUR_A[3]),(TIBIA_A[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[0]),(FEMUR_A[3]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[0]),(FEMUR_A[3]),(NTIBIA_A_R[0]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[0]),(Z_STATIC_IK[0]),(NTIBIA_A[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[0]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[0]),(Z_STATIC_IK[4]),(TIBIA_A_R[0]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[1]),(FEMUR_A[2]),(TIBIA_A[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[1]),(FEMUR_A[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[1]),(FEMUR_A[2]),(NTIBIA_A_R[1]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[1]),(Z_STATIC_IK[0]),(NTIBIA_A[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[1]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[1]),(Z_STATIC_IK[4]),(TIBIA_A_R[1]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[2]),(FEMUR_A[1]),(TIBIA_A[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[2]),(FEMUR_A[1]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[2]),(FEMUR_A[1]),(NTIBIA_A_R[2]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[2]),(Z_STATIC_IK[0]),(NTIBIA_A[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[2]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[2]),(Z_STATIC_IK[4]),(TIBIA_A_R[2]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[3]),(FEMUR_A[0]),(TIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[3]),(FEMUR_A[0]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[3]),(FEMUR_A[0]),(NTIBIA_A_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[0]),(NTIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[4]),(TIBIA_A_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

//				while(1)
//				{
//					lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 1");lcd_putstr(lcd);
//					if(BW_BUTTON_CLICKED)break;
//				}
//
//				lcd_display_clear();

				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
				{
					Stairs_Detector();
					if(STAIRS_FLAG == STAIRS_DETECTED)break;
				}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				if(FOLLOW_TRACER_STATE == 1)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
				}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				if(FOLLOW_CARPET_MODE == NORMAL)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

				}
				else if(FOLLOW_CARPET_MODE == INVERSE)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

				}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				//SIKLUS 2
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[1]),(TIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[3]),(Z_STATIC_IK[5]),(NTIBIA_A_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[0]),(NTIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[4]),(TIBIA_A_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[1]),(TIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[3]),(Z_STATIC_IK[5]),(NTIBIA_A_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[0]),(NTIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[4]),(TIBIA_A_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[1]),(TIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[3]),(Z_STATIC_IK[5]),(NTIBIA_A_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[0]),(NTIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[4]),(TIBIA_A_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[1]),(TIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[3]),(Z_STATIC_IK[5]),(NTIBIA_A_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[0]),(NTIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[4]),(TIBIA_A_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				if (cek_value==1)
				{
					lcd_gotoxy(0,0);sprintf(lcd,"COXA VALUE");lcd_putstr(lcd);
					lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d|%d",COXA_A[0],COXA_A[1],COXA_A[2],COXA_A[3]);lcd_putstr(lcd);
					lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d|%d",NCOXA_A[0],NCOXA_A[1],NCOXA_A[2],NCOXA_A[3]);lcd_putstr(lcd);
					delay_ms(100);
					lcd_display_clear();
				}

//				while(1)
//				{
//					lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 2");lcd_putstr(lcd);
//					if(BW_BUTTON_CLICKED)break;
//				}
//
//				lcd_display_clear();


				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
				{
					Stairs_Detector();
					if(STAIRS_FLAG == STAIRS_DETECTED)break;
				}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				if(FOLLOW_TRACER_STATE == 1)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
				}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}

				if(FOLLOW_CARPET_MODE == NORMAL)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

				}
				else if(FOLLOW_CARPET_MODE == INVERSE)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

				}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				//SIKLUS 3
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[2]),(Z_STATIC_IK[1]),(TIBIA_A[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[2]),(Z_STATIC_IK[5]),(NTIBIA_A_R[2]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[2]),(FEMUR_A[0]),(NTIBIA_A[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[2]),(FEMUR_A[0]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[2]),(FEMUR_A[0]),(TIBIA_A_R[2]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);


				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[1]),(Z_STATIC_IK[1]),(TIBIA_A[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[1]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[1]),(Z_STATIC_IK[5]),(NTIBIA_A_R[1]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[1]),(FEMUR_A[1]),(NTIBIA_A[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[1]),(FEMUR_A[1]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[1]),(FEMUR_A[1]),(TIBIA_A_R[1]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[0]),(Z_STATIC_IK[1]),(TIBIA_A[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[0]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[0]),(Z_STATIC_IK[5]),(NTIBIA_A_R[0]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[0]),(FEMUR_A[2]),(NTIBIA_A[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[0]),(FEMUR_A[2]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[0]),(FEMUR_A[2]),(TIBIA_A_R[0]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK[1]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK[5]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK[0]),(FEMUR_A[3]),(X_STATIC_IK[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(FEMUR_A[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK[4]),(FEMUR_A[3]),(X_STATIC_IK[4]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				if (cek_value==1)
				{
					lcd_gotoxy(0,0);sprintf(lcd,"COXA VALUE");lcd_putstr(lcd);
					lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d|%d",COXA_A[0],COXA_A[1],COXA_A[2],COXA_A[3]);lcd_putstr(lcd);
					lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d|%d",NCOXA_A[0],NCOXA_A[1],NCOXA_A[2],NCOXA_A[3]);lcd_putstr(lcd);
					delay_ms(100);
					lcd_display_clear();
				}

//				while(1)
//				{
//					lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 3");lcd_putstr(lcd);
//					if(BW_BUTTON_CLICKED)break;
//				}
//
//				lcd_display_clear();

				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
				{
					Stairs_Detector();
					if(STAIRS_FLAG == STAIRS_DETECTED)break;
				}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				if(FOLLOW_TRACER_STATE == 1)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
				}

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				if(FOLLOW_CARPET_MODE == NORMAL)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

				}
				else if(FOLLOW_CARPET_MODE == INVERSE)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

				}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				//SIKLUS 4

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[0]),(Z_STATIC_IK[1]),(NTIBIA_A[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[0]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[0]),(Z_STATIC_IK[5]),(TIBIA_A_R[0]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[0]),(FEMUR_A[3]),(TIBIA_A[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[0]),(FEMUR_A[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[0]),(FEMUR_A[3]),(NTIBIA_A_R[0]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[1]),(Z_STATIC_IK[1]),(NTIBIA_A[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[1]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[1]),(Z_STATIC_IK[5]),(TIBIA_A_R[1]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[1]),(FEMUR_A[2]),(TIBIA_A[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[1]),(FEMUR_A[2]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[1]),(FEMUR_A[2]),(NTIBIA_A_R[1]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[2]),(Z_STATIC_IK[1]),(NTIBIA_A[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[2]),(Z_STATIC_IK[5]),(TIBIA_A_R[2]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[2]),(FEMUR_A[1]),(TIBIA_A[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[2]),(FEMUR_A[1]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[2]),(FEMUR_A[1]),(NTIBIA_A_R[2]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[1]),(NTIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[5]),(TIBIA_A_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[3]),(FEMUR_A[0]),(TIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[3]),(FEMUR_A[0]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[3]),(FEMUR_A[0]),(NTIBIA_A_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				if (cek_value==1)
				{
					lcd_gotoxy(0,0);sprintf(lcd,"COXA VALUE");lcd_putstr(lcd);
					lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d|%d",COXA_A[0],COXA_A[1],COXA_A[2],COXA_A[3]);lcd_putstr(lcd);
					lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d|%d",NCOXA_A[0],NCOXA_A[1],NCOXA_A[2],NCOXA_A[3]);lcd_putstr(lcd);
					delay_ms(100);
					lcd_display_clear();
				}

//				while(1)
//				{
//					//lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 4");lcd_putstr(lcd);
//					if(BW_BUTTON_CLICKED)break;
//				}
//
//				lcd_display_clear();

				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}

				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
				{
					Stairs_Detector();
					if(STAIRS_FLAG == STAIRS_DETECTED)break;
				}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				if(FOLLOW_TRACER_STATE == 1)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
				}

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				if(FOLLOW_CARPET_MODE == NORMAL)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

				}
				else if(FOLLOW_CARPET_MODE == INVERSE)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

				}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				//SIKLUS 5
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[1]),(NTIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[5]),(TIBIA_A_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[3]),(Z_STATIC_IK[0]),(TIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[3]),(Z_STATIC_IK[4]),(NTIBIA_A_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[1]),(NTIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[5]),(TIBIA_A_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[3]),(Z_STATIC_IK[0]),(TIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[3]),(Z_STATIC_IK[4]),(NTIBIA_A_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[1]),(NTIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[5]),(TIBIA_A_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[3]),(Z_STATIC_IK[0]),(TIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[3]),(Z_STATIC_IK[4]),(NTIBIA_A_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[1]),(NTIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[5]),(TIBIA_A_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[3]),(Z_STATIC_IK[0]),(TIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[3]),(Z_STATIC_IK[4]),(NTIBIA_A_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				if (cek_value==1)
				{
					lcd_gotoxy(0,0);sprintf(lcd,"COXA VALUE");lcd_putstr(lcd);
					lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d|%d",COXA_A[0],COXA_A[1],COXA_A[2],COXA_A[3]);lcd_putstr(lcd);
					lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d|%d",NCOXA_A[0],NCOXA_A[1],NCOXA_A[2],NCOXA_A[3]);lcd_putstr(lcd);
					delay_ms(100);
					lcd_display_clear();
				}

//				while(1)
//				{
//					lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 5");lcd_putstr(lcd);
//					if(BW_BUTTON_CLICKED)break;
//				}
//
//				lcd_display_clear();

				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
				{
					Stairs_Detector();
					if(STAIRS_FLAG == STAIRS_DETECTED)break;
				}

				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				if(FOLLOW_TRACER_STATE == 1)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
				}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				if(FOLLOW_CARPET_MODE == NORMAL)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

				}
				else if(FOLLOW_CARPET_MODE == INVERSE)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

				}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				//SIKLUS 6
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[2]),(FEMUR_A[0]),(NTIBIA_A[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[2]),(FEMUR_A[0]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[2]),(FEMUR_A[0]),(TIBIA_A_R[2]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[2]),(Z_STATIC_IK[0]),(TIBIA_A[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[2]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[2]),(Z_STATIC_IK[4]),(NTIBIA_A_R[2]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[1]),(FEMUR_A[1]),(NTIBIA_A[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[1]),(FEMUR_A[1]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[1]),(FEMUR_A[1]),(TIBIA_A_R[1]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[1]),(Z_STATIC_IK[0]),(TIBIA_A[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[1]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[1]),(Z_STATIC_IK[4]),(NTIBIA_A_R[1]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[0]),(FEMUR_A[2]),(NTIBIA_A[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[0]),(FEMUR_A[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[0]),(FEMUR_A[2]),(TIBIA_A_R[0]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[0]),(Z_STATIC_IK[0]),(TIBIA_A[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[0]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[0]),(Z_STATIC_IK[4]),(NTIBIA_A_R[0]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK[1]),(FEMUR_A[3]),(X_STATIC_IK[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(FEMUR_A[3]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK[5]),(FEMUR_A[3]),(X_STATIC_IK[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK[0]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK[4]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				if (cek_value==1)
				{
					lcd_gotoxy(0,0);sprintf(lcd,"COXA VALUE");lcd_putstr(lcd);
					lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d|%d",COXA_A[0],COXA_A[1],COXA_A[2],COXA_A[3]);lcd_putstr(lcd);
					lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d|%d",NCOXA_A[0],NCOXA_A[1],NCOXA_A[2],NCOXA_A[3]);lcd_putstr(lcd);
					delay_ms(100);
					lcd_display_clear();
				}

//				while(1)
//				{
//					lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 6");lcd_putstr(lcd);
//					if(BW_BUTTON_CLICKED)break;
//				}
//
//				lcd_display_clear();

				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
				{
					Stairs_Detector();
					if(STAIRS_FLAG == STAIRS_DETECTED)break;
				}

				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				if(FOLLOW_TRACER_STATE == 1)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
				}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				if(FOLLOW_CARPET_MODE == NORMAL)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

				}
				else if(FOLLOW_CARPET_MODE == INVERSE)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

				}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
			}
		}break;

		case IKCALC_DISABLE:
		{
			for (loop=1;loop<=limit;loop++)
				{

				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//2
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
				//BW_Tracer_Check();

				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//3
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R3[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R3[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L3[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R3[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R3[2]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L3[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R3[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L3[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L3[0]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//3
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R2[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R2[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R2[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R2[2]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L2[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L2[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L2[0]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//3
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R1[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R1[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L1[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R1[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R1[2]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L1[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L1[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L1[0]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//3
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R[2]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//3
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R[2]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);


				if(CAT_DETECTOR==CAT_ACTIVATED)
							{
								Cat_Avoider();
								if(CAT_FLAG ==CAT_DETECTED)break;
							}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//4
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]);
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//belakang angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//4
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L1[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R1[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L1[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L1[0]);
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R1[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//belakang angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R1[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//4
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L2[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L2[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L2[0]);
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R2[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//belakang angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R2[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//4
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L3[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R3[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L3[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L3[0]);
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R3[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L3[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//belakang angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R3[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				if(CAT_DETECTOR==CAT_ACTIVATED)
							{
								Cat_Avoider();
								if(CAT_FLAG ==CAT_DETECTED)break;
							}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//5
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);//tengah angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				if(CAT_DETECTOR==CAT_ACTIVATED)
							{
								Cat_Avoider();
								if(CAT_FLAG ==CAT_DETECTED)break;
							}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
				//BW_Tracer_Check();

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//6
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R3[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L3[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R3[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R3[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L3[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L3[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R3[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L3[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L3[2]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//6
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R2[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R2[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R2[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L2[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L2[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L2[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L2[2]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//6
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R1[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R1[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R1[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L1[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L1[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R1[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L1[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L1[2]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//6
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L[2]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//6
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L[2]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);


				if(CAT_DETECTOR==CAT_ACTIVATED)
							{
								Cat_Avoider();
								if(CAT_FLAG ==CAT_DETECTED)break;
							}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//1
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//belakang angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//1
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R1[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L1[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R1[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R1[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L1[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//belakang angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L1[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//1
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R2[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R2[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R2[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L2[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//belakang angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L2[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//1
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R3[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L3[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R3[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R3[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L3[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R3[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//belakang angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L3[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}

				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				}
		}break;
		FOWARD_STAT = 0;
	}

}


/*
void Dynamx_MovFwd4cm_Interpolate(unsigned int distance, int SPEED, int IKCALC_STAT)
{
	int limit= distance/4;
	int loop;

	if(IKCALC_STAT == IKCALC_ENABLE)
	{
		if(IK_CALCULATED_FWD == 0)
		{
			Generate_Body(0,1.5);
			Trajectory_Generator_NEW(X_Diff, Y_Diff, -1.5, 4,MOVEMENT_NORMAL);
			for(i=0;i<=3;i++)
			{
				Dyna_IKCalc_Only((X_IK_BEGIN[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]+Z_IK[i]));
				FEMUR_A[i] = tetha.Femur;
				COXA_A[i] = tetha.Coxa;
				NFEMUR_A[i] = (tetha.Femur*-1);
				NCOXA_A[i] = (tetha.Coxa*-1);

				Dyna_IKCalc_Only((X_IK_BEGIN[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
				TIBIA_A[i] = tetha.Tibia;

				Dyna_IKCalc_Only((X_IK_BEGIN[0]-X4_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
				NTIBIA_A[i] = tetha.Tibia;

				Dyna_IKCalc_Only((X_IK_BEGIN[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
				NTIBIA_A_R[i] = tetha.Tibia;

				Dyna_IKCalc_Only((X_IK_BEGIN[0]+X4_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
				TIBIA_A_R[i] = tetha.Tibia;
			}
			IK_CALCULATED_BWD = 0;
			IK_CALCULATED_FWD = 1;
		}
	}

	SPEED = SPEED/45;
//
//	switch(IKCALC_STAT)
//	{
//		case IKCALC_ENABLE:
//		{
//			FOWARD_STAT = 1;
//			for(loop=1;loop<=limit;loop++)
//			{
//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//
//				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//				{
//					Stairs_Detector();
//					if(STAIRS_FLAG == STAIRS_DETECTED)break;
//				}
//
//				if(FOLLOW_TRACER_STATE == 1)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//				}
//
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//				if(FOLLOW_CARPET_MODE == NORMAL)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//				}
//				else if(FOLLOW_CARPET_MODE == INVERSE)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//				}

				// if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				//SIKLUS 1
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[0]),(FEMUR_A[3]),(TIBIA_A[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[0]),(FEMUR_A[3]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[0]),(FEMUR_A[3]),(NTIBIA_A_R[0]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[0]),(Z_STATIC_IK[0]),(NTIBIA_A[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[0]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[0]),(Z_STATIC_IK[4]),(TIBIA_A_R[0]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[1]),(FEMUR_A[2]),(TIBIA_A[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[1]),(FEMUR_A[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[1]),(FEMUR_A[2]),(NTIBIA_A_R[1]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[1]),(Z_STATIC_IK[0]),(NTIBIA_A[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[1]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[1]),(Z_STATIC_IK[4]),(TIBIA_A_R[1]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[2]),(FEMUR_A[1]),(TIBIA_A[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[2]),(FEMUR_A[1]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[2]),(FEMUR_A[1]),(NTIBIA_A_R[2]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[2]),(Z_STATIC_IK[0]),(NTIBIA_A[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[2]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[2]),(Z_STATIC_IK[4]),(TIBIA_A_R[2]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[3]),(FEMUR_A[0]),(TIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[3]),(FEMUR_A[0]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[3]),(FEMUR_A[0]),(NTIBIA_A_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[0]),(NTIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[4]),(TIBIA_A_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

////				while(1)
////				{
////					lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 1");lcd_putstr(lcd);
////					if(BW_BUTTON_CLICKED)break;
////				}
////
////				lcd_display_clear();
//
//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//				{
//					Stairs_Detector();
//					if(STAIRS_FLAG == STAIRS_DETECTED)break;
//				}
				// if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

//				if(FOLLOW_TRACER_STATE == 1)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//				}
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//				if(FOLLOW_CARPET_MODE == NORMAL)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//				}
//				else if(FOLLOW_CARPET_MODE == INVERSE)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//				}
				// if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				//SIKLUS 2
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[1]),(TIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[3]),(Z_STATIC_IK[5]),(NTIBIA_A_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[0]),(NTIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[4]),(TIBIA_A_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[1]),(TIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[3]),(Z_STATIC_IK[5]),(NTIBIA_A_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[0]),(NTIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[4]),(TIBIA_A_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[1]),(TIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[3]),(Z_STATIC_IK[5]),(NTIBIA_A_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[0]),(NTIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[4]),(TIBIA_A_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[1]),(TIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[3]),(Z_STATIC_IK[5]),(NTIBIA_A_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[0]),(NTIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[4]),(TIBIA_A_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

////				while(1)
////				{
////					lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 2");lcd_putstr(lcd);
////					if(BW_BUTTON_CLICKED)break;
////				}
////
////				lcd_display_clear();
//
//
//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//				{
//					Stairs_Detector();
//					if(STAIRS_FLAG == STAIRS_DETECTED)break;
//				}
				// if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

//				if(FOLLOW_TRACER_STATE == 1)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//				}
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//				if(FOLLOW_CARPET_MODE == NORMAL)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//				}
//				else if(FOLLOW_CARPET_MODE == INVERSE)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//				}
//				 if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				//SIKLUS 3
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[2]),(Z_STATIC_IK[1]),(TIBIA_A[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[2]),(Z_STATIC_IK[5]),(NTIBIA_A_R[2]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[2]),(FEMUR_A[0]),(NTIBIA_A[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[2]),(FEMUR_A[0]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[2]),(FEMUR_A[0]),(TIBIA_A_R[2]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);


				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[1]),(Z_STATIC_IK[1]),(TIBIA_A[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[1]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[1]),(Z_STATIC_IK[5]),(NTIBIA_A_R[1]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[1]),(FEMUR_A[1]),(NTIBIA_A[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[1]),(FEMUR_A[1]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[1]),(FEMUR_A[1]),(TIBIA_A_R[1]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[0]),(Z_STATIC_IK[1]),(TIBIA_A[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[0]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[0]),(Z_STATIC_IK[5]),(NTIBIA_A_R[0]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[0]),(FEMUR_A[2]),(NTIBIA_A[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[0]),(FEMUR_A[2]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[0]),(FEMUR_A[2]),(TIBIA_A_R[0]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK[1]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK[5]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK[0]),(FEMUR_A[3]),(X_STATIC_IK[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(FEMUR_A[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK[4]),(FEMUR_A[3]),(X_STATIC_IK[4]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

////				while(1)
////				{
////					lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 3");lcd_putstr(lcd);
////					if(BW_BUTTON_CLICKED)break;
////				}
////
////				lcd_display_clear();
//
//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//				{
//					Stairs_Detector();
//					if(STAIRS_FLAG == STAIRS_DETECTED)break;
//				}
				// if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

//				if(FOLLOW_TRACER_STATE == 1)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//				}
//
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//				if(FOLLOW_CARPET_MODE == NORMAL)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//				}
//				else if(FOLLOW_CARPET_MODE == INVERSE)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//				}
				// if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				//SIKLUS 4

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[0]),(Z_STATIC_IK[1]),(NTIBIA_A[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[0]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[0]),(Z_STATIC_IK[5]),(TIBIA_A_R[0]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[0]),(FEMUR_A[3]),(TIBIA_A[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[0]),(FEMUR_A[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[0]),(FEMUR_A[3]),(NTIBIA_A_R[0]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[1]),(Z_STATIC_IK[1]),(NTIBIA_A[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[1]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[1]),(Z_STATIC_IK[5]),(TIBIA_A_R[1]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[1]),(FEMUR_A[2]),(TIBIA_A[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[1]),(FEMUR_A[2]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[1]),(FEMUR_A[2]),(NTIBIA_A_R[1]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[2]),(Z_STATIC_IK[1]),(NTIBIA_A[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[2]),(Z_STATIC_IK[5]),(TIBIA_A_R[2]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[2]),(FEMUR_A[1]),(TIBIA_A[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[2]),(FEMUR_A[1]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[2]),(FEMUR_A[1]),(NTIBIA_A_R[2]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[1]),(NTIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[5]),(TIBIA_A_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[3]),(FEMUR_A[0]),(TIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[3]),(FEMUR_A[0]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[3]),(FEMUR_A[0]),(NTIBIA_A_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

////				while(1)
////				{
////					//lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 4");lcd_putstr(lcd);
////					if(BW_BUTTON_CLICKED)break;
////				}
////
////				lcd_display_clear();
//
//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//
//				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//				{
//					Stairs_Detector();
//					if(STAIRS_FLAG == STAIRS_DETECTED)break;
//				}
				// if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

//				if(FOLLOW_TRACER_STATE == 1)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//				}
//
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//				if(FOLLOW_CARPET_MODE == NORMAL)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//				}
//				else if(FOLLOW_CARPET_MODE == INVERSE)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//				}
				// if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				//SIKLUS 5
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[1]),(NTIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[5]),(TIBIA_A_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[3]),(Z_STATIC_IK[0]),(TIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[3]),(Z_STATIC_IK[4]),(NTIBIA_A_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[1]),(NTIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[5]),(TIBIA_A_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[3]),(Z_STATIC_IK[0]),(TIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[3]),(Z_STATIC_IK[4]),(NTIBIA_A_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[1]),(NTIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[5]),(TIBIA_A_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[3]),(Z_STATIC_IK[0]),(TIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[3]),(Z_STATIC_IK[4]),(NTIBIA_A_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[1]),(NTIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[5]),(TIBIA_A_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[3]),(Z_STATIC_IK[0]),(TIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[3]),(Z_STATIC_IK[4]),(NTIBIA_A_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

////				while(1)
////				{
////					lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 5");lcd_putstr(lcd);
////					if(BW_BUTTON_CLICKED)break;
////				}
////
////				lcd_display_clear();
//
//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//				{
//					Stairs_Detector();
//					if(STAIRS_FLAG == STAIRS_DETECTED)break;
//				}

				// if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

//				if(FOLLOW_TRACER_STATE == 1)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//				}
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//				if(FOLLOW_CARPET_MODE == NORMAL)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//				}
//				else if(FOLLOW_CARPET_MODE == INVERSE)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//				}
				// if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				//SIKLUS 6
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[2]),(FEMUR_A[0]),(NTIBIA_A[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[2]),(FEMUR_A[0]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[2]),(FEMUR_A[0]),(TIBIA_A_R[2]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[2]),(Z_STATIC_IK[0]),(TIBIA_A[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[2]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[2]),(Z_STATIC_IK[4]),(NTIBIA_A_R[2]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[1]),(FEMUR_A[1]),(NTIBIA_A[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[1]),(FEMUR_A[1]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[1]),(FEMUR_A[1]),(TIBIA_A_R[1]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[1]),(Z_STATIC_IK[0]),(TIBIA_A[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[1]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[1]),(Z_STATIC_IK[4]),(NTIBIA_A_R[1]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[0]),(FEMUR_A[2]),(NTIBIA_A[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[0]),(FEMUR_A[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[0]),(FEMUR_A[2]),(TIBIA_A_R[0]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[0]),(Z_STATIC_IK[0]),(TIBIA_A[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[0]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[0]),(Z_STATIC_IK[4]),(NTIBIA_A_R[0]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK[1]),(FEMUR_A[3]),(X_STATIC_IK[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(FEMUR_A[3]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK[5]),(FEMUR_A[3]),(X_STATIC_IK[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK[0]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK[4]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

////				while(1)
////				{
////					lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 6");lcd_putstr(lcd);
////					if(BW_BUTTON_CLICKED)break;
////				}
////
////				lcd_display_clear();
//
//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//				{
//					Stairs_Detector();
//					if(STAIRS_FLAG == STAIRS_DETECTED)break;
//				}

				// if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

//				if(FOLLOW_TRACER_STATE == 1)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//				}
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//				if(FOLLOW_CARPET_MODE == NORMAL)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//				}
//				else if(FOLLOW_CARPET_MODE == INVERSE)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//				}
				// if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
//			}
//		}break;

//		case IKCALC_DISABLE:
//		{
//			for (loop=1;loop<=limit;loop++)
//				{
//
//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//				//2
//				//TRIPOD A
//				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
//				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
//				//TRIPOD B
//				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);
//				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
//				//BW_Tracer_Check();
//
//				Start_Pose_SYNC();
//				delay_ms(SPEED+2);
//
//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//				// if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//				//3
//				//TRIPOD A
//				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R3[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R3[0]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L3[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
//				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R3[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R3[2]);
//				//TRIPOD B
//				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L3[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R3[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//depan angkat
//				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L3[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L3[0]);
////				delay_ms(500);
//				Start_Pose_SYNC();
//				delay_ms(SPEED+2);
//
//				//3
//				//TRIPOD A
//				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R2[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R2[0]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
//				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R2[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R2[2]);
//				//TRIPOD B
//				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L2[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//depan angkat
//				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L2[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L2[0]);
////				delay_ms(500);
//				Start_Pose_SYNC();
//				delay_ms(SPEED+2);
//
//				//3
//				//TRIPOD A
//				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R1[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R1[0]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L1[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
//				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R1[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R1[2]);
//				//TRIPOD B
//				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L1[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//depan angkat
//				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L1[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L1[0]);
////				delay_ms(500);
//				Start_Pose_SYNC();
//				delay_ms(SPEED+2);
//
//				//3
//				//TRIPOD A
//				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R[0]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
//				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R[2]);
//				//TRIPOD B
//				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//depan angkat
//				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]);
////				delay_ms(500);
//				Start_Pose_SYNC();
//				delay_ms(SPEED+2);
//
//				//3
//				//TRIPOD A
//				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R[0]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
//				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R[2]);
//				//TRIPOD B
//				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//depan angkat
//				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]);
////				delay_ms(500);
//				Start_Pose_SYNC();
//				delay_ms(SPEED+2);
//
//
//				if(CAT_DETECTOR==CAT_ACTIVATED)
//							{
//								Cat_Avoider();
//								if(CAT_FLAG ==CAT_DETECTED)break;
//							}
//				// if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
//				//BW_Tracer_Check();
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//				//4
//				//TRIPOD B
//				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
//				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]);
//				//TRIPOD A
//				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//belakang angkat
//				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
////				delay_ms(500);
//				Start_Pose_SYNC();
//				delay_ms(SPEED+2);
//
//				//4
//				//TRIPOD B
//				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L1[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R1[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
//				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L1[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L1[0]);
//				//TRIPOD A
//				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R1[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//belakang angkat
//				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R1[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
////				delay_ms(500);
//				Start_Pose_SYNC();
//				delay_ms(SPEED+2);
//
//				//4
//				//TRIPOD B
//				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L2[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
//				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L2[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L2[0]);
//				//TRIPOD A
//				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R2[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//belakang angkat
//				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R2[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
////				delay_ms(500);
//				Start_Pose_SYNC();
//				delay_ms(SPEED+2);
//
//				//4
//				//TRIPOD B
//				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L3[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R3[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
//				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L3[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L3[0]);
//				//TRIPOD A
//				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R3[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L3[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//belakang angkat
//				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R3[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
////				delay_ms(500);
//				Start_Pose_SYNC();
//				delay_ms(SPEED+2);
//
//				if(CAT_DETECTOR==CAT_ACTIVATED)
//							{
//								Cat_Avoider();
//								if(CAT_FLAG ==CAT_DETECTED)break;
//							}
//				// if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
//				//BW_Tracer_Check();
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//				//5
//				//TRIPOD A
//				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);//tengah angkat
//				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
//				//TRIPOD B
//				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
//				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);
////				delay_ms(500);
//				Start_Pose_SYNC();
//				delay_ms(SPEED+2);
//
//				if(CAT_DETECTOR==CAT_ACTIVATED)
//							{
//								Cat_Avoider();
//								if(CAT_FLAG ==CAT_DETECTED)break;
//							}
//				// if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
//				//BW_Tracer_Check();
//
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//				//6
//				//TRIPOD A
//				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R3[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L3[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
//				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R3[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R3[0]);
//				//TRIPOD B
//				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L3[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L3[0]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R3[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
//				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L3[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L3[2]);
////				delay_ms(500);
//				Start_Pose_SYNC();
//				delay_ms(SPEED+2);
//
//				//6
//				//TRIPOD A
//				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R2[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
//				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R2[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R2[0]);
//				//TRIPOD B
//				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L2[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L2[0]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
//				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L2[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L2[2]);
////				delay_ms(500);
//				Start_Pose_SYNC();
//				delay_ms(SPEED+2);
//
//				//6
//				//TRIPOD A
//				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R1[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
//				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R1[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R1[0]);
//				//TRIPOD B
//				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L1[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L1[0]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R1[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
//				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L1[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L1[2]);
////				delay_ms(500);
//				Start_Pose_SYNC();
//				delay_ms(SPEED+2);
//
//				//6
//				//TRIPOD A
//				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
//				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]);
//				//TRIPOD B
//				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L[0]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
//				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L[2]);
////				delay_ms(500);
//				Start_Pose_SYNC();
//				delay_ms(SPEED+2);
//
//				//6
//				//TRIPOD A
//				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan angkat
//				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]);
//				//TRIPOD B
//				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L[0]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
//				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L[2]);
////				delay_ms(500);
//				Start_Pose_SYNC();
//				delay_ms(SPEED+2);
//
//
//				if(CAT_DETECTOR==CAT_ACTIVATED)
//							{
//								Cat_Avoider();
//								if(CAT_FLAG ==CAT_DETECTED)break;
//							}
//				// if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
//				//BW_Tracer_Check();
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//				//1
//				//TRIPOD A
//				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
//				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]);
//				//TRIPOD B
//				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//belakang angkat
//				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
////				delay_ms(500);
//				Start_Pose_SYNC();
//				delay_ms(SPEED+2);
//
//				//1
//				//TRIPOD A
//				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R1[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L1[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
//				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R1[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R1[0]);
//				//TRIPOD B
//				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L1[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//belakang angkat
//				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L1[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
////				delay_ms(500);
//				Start_Pose_SYNC();
//				delay_ms(SPEED+2);
//
//				//1
//				//TRIPOD A
//				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R2[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
//				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R2[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R2[0]);
//				//TRIPOD B
//				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L2[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//belakang angkat
//				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L2[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
////				delay_ms(500);
//				Start_Pose_SYNC();
//				delay_ms(SPEED+2);
//
//				//1
//				//TRIPOD A
//				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R3[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L3[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
//				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R3[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R3[0]);
//				//TRIPOD B
//				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L3[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
//				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R3[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//belakang angkat
//				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L3[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
////				delay_ms(500);
//				Start_Pose_SYNC();
//				delay_ms(SPEED+2);
//
//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//
//				// if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//				}
//		}break;
//		FOWARD_STAT = 0;
//	}

}
*/


void Trajectory_Test(int SPEED)
{
	SPEED = SPEED/24;

	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+30/5,SUDUT_STATIC[10]+SUDUT_ANGKAT*5/5,SUDUT_STATIC[11]);
	delay_ms(SPEED);
	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+30*2/5,SUDUT_STATIC[10]+SUDUT_ANGKAT*4/5,SUDUT_STATIC[11]);
	delay_ms(SPEED);
	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+30*3/5,SUDUT_STATIC[10]+SUDUT_ANGKAT*3/5,SUDUT_STATIC[11]);
	delay_ms(SPEED);
	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+30*4/5,SUDUT_STATIC[10]+SUDUT_ANGKAT*2/5,SUDUT_STATIC[11]);
	delay_ms(SPEED);
	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+30*5/5,SUDUT_STATIC[10]+SUDUT_ANGKAT/5,SUDUT_STATIC[11]);
	delay_ms(SPEED);

	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+30,SUDUT_STATIC[10],SUDUT_STATIC[11]);
	delay_ms(SPEED);

	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+30*5/5,SUDUT_STATIC[10],SUDUT_STATIC[11]);
	delay_ms(SPEED);
	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+30*4/5,SUDUT_STATIC[10],SUDUT_STATIC[11]);
	delay_ms(SPEED);
	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+30*3/5,SUDUT_STATIC[10],SUDUT_STATIC[11]);
	delay_ms(SPEED);
	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+30*2/5,SUDUT_STATIC[10],SUDUT_STATIC[11]);
	delay_ms(SPEED);
	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+30*1/5,SUDUT_STATIC[10],SUDUT_STATIC[11]);
	delay_ms(SPEED);

	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
	delay_ms(SPEED);

	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-30/5,SUDUT_STATIC[10],SUDUT_STATIC[11]);
	delay_ms(SPEED);
	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-30*2/5,SUDUT_STATIC[10],SUDUT_STATIC[11]);
	delay_ms(SPEED);
	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-30*3/5,SUDUT_STATIC[10],SUDUT_STATIC[11]);
	delay_ms(SPEED);
	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-30*4/5,SUDUT_STATIC[10],SUDUT_STATIC[11]);
	delay_ms(SPEED);
	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-30*5/5,SUDUT_STATIC[10],SUDUT_STATIC[11]);
	delay_ms(SPEED);

	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-30*5/5,SUDUT_STATIC[10],SUDUT_STATIC[11]);
	delay_ms(SPEED);

	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-30*5/5,SUDUT_STATIC[10]+SUDUT_ANGKAT*1/5,SUDUT_STATIC[11]);
	delay_ms(SPEED);
	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-30*4/5,SUDUT_STATIC[10]+SUDUT_ANGKAT*2/5,SUDUT_STATIC[11]);
	delay_ms(SPEED);
	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-30*3/5,SUDUT_STATIC[10]+SUDUT_ANGKAT*3/5,SUDUT_STATIC[11]);
	delay_ms(SPEED);
	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-30*2/5,SUDUT_STATIC[10]+SUDUT_ANGKAT*4/5,SUDUT_STATIC[11]);
	delay_ms(SPEED);
	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-30*1/5,SUDUT_STATIC[10]+SUDUT_ANGKAT*5/5,SUDUT_STATIC[11]);
	delay_ms(SPEED);

	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT*5/5,SUDUT_STATIC[11]);
	delay_ms(SPEED);

}

void Dynamx_Mov_Static_Obs(int SPEED)
{
	if (STATIC_OBS == 0)
	{
		Generate_Body(0,0);
	}

	Dyna_IKCALC_Obs(FRONT_RIGHT_DX,   X_IK_OBS[1], Y_IK_BEGIN[1],Z_IK_OBS[1],&SPEED);
	Dyna_IKCALC_Obs(MIDDLE_LEFT_DX,   X_IK_OBS[2], Y_IK_BEGIN[2],Z_IK_OBS[2],&SPEED);
	Dyna_IKCALC_Obs(REAR_RIGHT_DX,    X_IK_OBS[5], Y_IK_BEGIN[5],Z_IK_OBS[5],&SPEED);

	Dyna_IKCALC_Obs(FRONT_LEFT_DX,    X_IK_OBS[0], Y_IK_BEGIN[0],Z_IK_OBS[0],&SPEED);
	Dyna_IKCALC_Obs(MIDDLE_RIGHT_DX,  X_IK_OBS[3], Y_IK_BEGIN[3],Z_IK_OBS[3],&SPEED);
	Dyna_IKCALC_Obs(REAR_LEFT_DX,     X_IK_OBS[4], Y_IK_BEGIN[4],Z_IK_OBS[4],&SPEED);

	Start_Pose_SYNC();
	delay_ms(SPEED);
	STATIC_OBS = 1;
	STATIC_OBS_HIGH=0;
}

void Dynamx_Mov_Static_Obs_High(int SPEED)
{
	if (STATIC_OBS_HIGH == 0)
	{
		Generate_Body(0,0);
	}

	Dyna_IKCALC_Obs(FRONT_RIGHT_DX,   X_IK_OBS[1], Y_IK_BEGIN[1],Z_IK_STAIRS[1],&SPEED);
	Dyna_IKCALC_Obs(MIDDLE_LEFT_DX,   X_IK_OBS[2], Y_IK_BEGIN[2],Z_IK_STAIRS[2],&SPEED);
	Dyna_IKCALC_Obs(REAR_RIGHT_DX,    X_IK_OBS[5], Y_IK_BEGIN[5],Z_IK_STAIRS[5],&SPEED);

	Dyna_IKCALC_Obs(FRONT_LEFT_DX,    X_IK_OBS[0], Y_IK_BEGIN[0],Z_IK_STAIRS[0],&SPEED);
	Dyna_IKCALC_Obs(MIDDLE_RIGHT_DX,  X_IK_OBS[3], Y_IK_BEGIN[3],Z_IK_STAIRS[3],&SPEED);
	Dyna_IKCALC_Obs(REAR_LEFT_DX,     X_IK_OBS[4], Y_IK_BEGIN[4],Z_IK_STAIRS[4],&SPEED);

	Start_Pose_SYNC();
	delay_ms(SPEED);
	STATIC_OBS_HIGH = 1;
	STATIC_OBS=0;
}


void Dynamx_Mov_Static_Interpolate(int SPEED, unsigned int IK_STAT)
{
	switch(IK_STAT)
	{
		case IKCALC_ENABLE:
		{
			if(STATIC_ANGLE == 0)
			{
				Generate_Body(0,0);
			}

			Dyna_IKCALC_NEW(FRONT_RIGHT_DX,   X_IK_BEGIN[1], Y_IK_BEGIN[1],Z_IK_BEGIN[1],&SPEED);
			Dyna_IKCALC_NEW(MIDDLE_LEFT_DX,   X_IK_BEGIN[2], Y_IK_BEGIN[2],Z_IK_BEGIN[2],&SPEED);
			Dyna_IKCALC_NEW(REAR_RIGHT_DX,    X_IK_BEGIN[5], Y_IK_BEGIN[5],Z_IK_BEGIN[5],&SPEED);

			Dyna_IKCALC_NEW(FRONT_LEFT_DX,    X_IK_BEGIN[0], Y_IK_BEGIN[0],Z_IK_BEGIN[0],&SPEED);
			Dyna_IKCALC_NEW(MIDDLE_RIGHT_DX,  X_IK_BEGIN[3], Y_IK_BEGIN[3],Z_IK_BEGIN[3],&SPEED);
			Dyna_IKCALC_NEW(REAR_LEFT_DX,     X_IK_BEGIN[4], Y_IK_BEGIN[4],Z_IK_BEGIN[4],&SPEED);
			Start_Pose_SYNC();
			delay_ms(SPEED);
			STATIC_ANGLE = 1;

		}break;

		case IKCALC_DISABLE:
		{
			//===FIX=== body agak turun ====
			Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
			Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);

			Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
			Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);
			Start_Pose_SYNC();
			delay_ms(SPEED);
		}break;
	}

}


void Dynamx_MoveLeg_Interpolate(unsigned int leg_position, int *SPEED, unsigned int ThetaCoxa, int ThetaFemur, unsigned int ThetaTibia)
{
	switch(leg_position)
	{
		case FRONT_LEFT_DX      :
							 	 HexJoint_Actuate_Interpolate(FRONT_LEFT_DX_COXA, 150-90+ThetaCoxa, *SPEED);
							 	 HexJoint_Actuate_Interpolate(FRONT_LEFT_DX_FEMUR, 150+ThetaFemur, *SPEED);
							 	 HexJoint_Actuate_Interpolate(FRONT_LEFT_DX_TIBIA, 150+ThetaTibia, *SPEED);
							 	 break;

		case FRONT_RIGHT_DX     :
								 HexJoint_Actuate_Interpolate(FRONT_RIGHT_DX_COXA, 150+90-ThetaCoxa, *SPEED);
								 HexJoint_Actuate_Interpolate(FRONT_RIGHT_DX_FEMUR, 150-ThetaFemur, *SPEED);
								 HexJoint_Actuate_Interpolate(FRONT_RIGHT_DX_TIBIA, 150-ThetaTibia, *SPEED);
							 	 break;

		case MIDDLE_LEFT_DX     :
								 HexJoint_Actuate_Interpolate(MIDDLE_LEFT_DX_COXA, 150-90+ThetaCoxa, *SPEED);
								 HexJoint_Actuate_Interpolate(MIDDLE_LEFT_DX_FEMUR, 150+ThetaFemur, *SPEED);
								 HexJoint_Actuate_Interpolate(MIDDLE_LEFT_DX_TIBIA, 150+ThetaTibia, *SPEED);
							 	 break;

		case MIDDLE_RIGHT_DX    :
								 HexJoint_Actuate_Interpolate(MIDDLE_RIGHT_DX_COXA, 150+90-ThetaCoxa, *SPEED);
								 HexJoint_Actuate_Interpolate(MIDDLE_RIGHT_DX_FEMUR, 150-ThetaFemur, *SPEED);
								 HexJoint_Actuate_Interpolate(MIDDLE_RIGHT_DX_TIBIA, 150-ThetaTibia, *SPEED);
							 	 break;

		case REAR_LEFT_DX       :
								 HexJoint_Actuate_Interpolate(REAR_LEFT_DX_COXA, 150-90+ThetaCoxa, *SPEED);
								 HexJoint_Actuate_Interpolate(REAR_LEFT_DX_FEMUR, 150+ThetaFemur, *SPEED);
								 HexJoint_Actuate_Interpolate(REAR_LEFT_DX_TIBIA, 150+ThetaTibia, *SPEED);
							 	 break;

		case REAR_RIGHT_DX      :
								 HexJoint_Actuate_Interpolate(REAR_RIGHT_DX_COXA, 150+90-ThetaCoxa, *SPEED);
								 HexJoint_Actuate_Interpolate(REAR_RIGHT_DX_FEMUR, 150-ThetaFemur, *SPEED);
								 HexJoint_Actuate_Interpolate(REAR_RIGHT_DX_TIBIA, 150-ThetaTibia, *SPEED);
							 	 break;
	}

}


void Dynamx_IK(char leg_pos,int *SPEED, float x, float w, float z)
{}

void Dynamx_MoveCurveRight_IK_Reverse(int SPEED,int limit,volatile float *ACTUATE_SIGNAL)
{
	CURVE_RIGHT_STAT = 1;
	int loop;
	int MAX_SIGNAL = 15;

	if(IK_CALCULATED_CRV_R_REVERSE == 0)
	{
		Generate_Body(0,-1.5);
		Trajectory_Generator_NEW(X_Diff, Y_Diff, -2.5, 4,MOVEMENT_NORMAL);
		for(i=0;i<=3;i++)
		{
				Dyna_IKCalc_Only((X_IK_BEGIN[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]+Z_IK[i]));
				FEMUR_C[i] = tetha.Femur;
				COXA_C[i] = tetha.Coxa;
				NFEMUR_C[i] = (tetha.Femur*-1);
				NCOXA_C[i] = (tetha.Coxa*-1);

				Dyna_IKCalc_Only((X_IK_BEGIN[0]+X4_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
				TIBIA_C[i] = tetha.Tibia;

				Dyna_IKCalc_Only((X_IK_BEGIN[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
				NTIBIA_C[i] = tetha.Tibia;
				NTIBIA_C_R[i] = tetha.Tibia;

				Dyna_IKCalc_Only((X_IK_BEGIN[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
				TIBIA_C_R[i] = tetha.Tibia;
		}

		IK_CALCULATED_CRV_L = 0;
		IK_CALCULATED_CRV_R = 0;
		IK_CALCULATED_CRV_L_REVERSE = 0;
		IK_CALCULATED_CRV_R_REVERSE = 1;
	}

	SPEED = SPEED/45;

	int a = 0;
	int b = 0, c = 0;

	float signal=*ACTUATE_SIGNAL/3;
	float error_L;//femur_L,tibia_L;
	float error_R;//femur_R,tibia_R;
	float error_R2;

	if (signal>=MAX_SIGNAL){error_R=MAX_SIGNAL;error_R2=MAX_SIGNAL;}
	else {error_R=signal;error_R2=signal;}

	float DELTA_R= (1 * error_R);
	float DELTA_R2 = (1 * error_R2);

	int LEFT_EXT1 = 0;
	int LEFT_EXT2 = 0;

	int CURVE[4];
	int NCURVE[4];

	CURVE[0] = (int)((DELTA_R*(float)COXA_C[0])/((float)(MAX_SIGNAL)));
	CURVE[1] = (int)((DELTA_R*(float)COXA_C[1])/((float)(MAX_SIGNAL)));
	CURVE[2] = (int)((DELTA_R*(float)COXA_C[2])/((float)(MAX_SIGNAL)));
	CURVE[3] = (int)((DELTA_R*(float)COXA_C[3])/((float)(MAX_SIGNAL)));

	NCURVE[0] = (int)((DELTA_R2*(float)NCOXA_C[0])/((float)(MAX_SIGNAL)));
	NCURVE[1] = (int)((DELTA_R2*(float)NCOXA_C[1])/((float)(MAX_SIGNAL)));
	NCURVE[2] = (int)((DELTA_R2*(float)NCOXA_C[2])/((float)(MAX_SIGNAL)));
	NCURVE[3] = (int)((DELTA_R2*(float)NCOXA_C[3])/((float)(MAX_SIGNAL)));

	int n;
	for(n=0;n<=3;n++)
	{
		NCURVE[i] = (NCURVE[i]*-1);
	}

	for(loop=1;loop<=limit;loop++)
	{
		if (Ping[PING_REAR]<=REAR_THRESHOLD)break;
		if(FOLLOW_TRACER_STATE == 1)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
		}

		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}

		if(FOLLOW_CARPET_MODE == NORMAL)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

		}

		else if(FOLLOW_CARPET_MODE == INVERSE)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

		}

		if (Ping[PING_REAR]<=REAR_THRESHOLD)break;

		//SIKLUS 1
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[0]-CURVE[0]),(FEMUR_C[3]),(TIBIA_C[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[0]),(FEMUR_C[3]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[0]-CURVE[0]),(FEMUR_C[3]),(NTIBIA_C_R[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[0]),(Z_STATIC_IK[0]),(NTIBIA_C[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[0]-NCURVE[0]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[0]),(Z_STATIC_IK[4]),(TIBIA_C_R[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[1]-CURVE[1]),(FEMUR_C[2]),(TIBIA_C[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[1]),(FEMUR_C[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[1]-CURVE[1]),(FEMUR_C[2]),(NTIBIA_C_R[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[1]),(Z_STATIC_IK[0]),(NTIBIA_C[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[1]-NCURVE[1]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[1]),(Z_STATIC_IK[4]),(TIBIA_C_R[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);


		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[2]-CURVE[2]),(FEMUR_C[1]),(TIBIA_C[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[2]),(FEMUR_C[1]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[2]-CURVE[2]),(FEMUR_C[1]),(NTIBIA_C_R[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[2]),(Z_STATIC_IK[0]),(NTIBIA_C[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[2]-NCURVE[2]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[2]),(Z_STATIC_IK[4]),(TIBIA_C_R[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);


		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[3]-CURVE[3]),(FEMUR_C[0]),(TIBIA_C[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[3]),(FEMUR_C[0]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[3]-CURVE[3]),(FEMUR_C[0]),(NTIBIA_C_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[0]),(NTIBIA_C[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[4]),(TIBIA_C_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);


		if (Ping[PING_REAR]<=REAR_THRESHOLD)break;

		if(FOLLOW_TRACER_STATE == 1)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
		}

		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
		if(FOLLOW_CARPET_MODE == NORMAL)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

		}
		else if(FOLLOW_CARPET_MODE == INVERSE)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

		}
		if (Ping[PING_REAR]<=REAR_THRESHOLD)break;

		//SIKLUS 2
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[3]-CURVE[3]),(Z_STATIC_IK[1]),(TIBIA_C[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[3]-CURVE[3]),(Z_STATIC_IK[5]),(NTIBIA_C_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[0]),(NTIBIA_C[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[4]),(TIBIA_C_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[3]-CURVE[3]),(Z_STATIC_IK[1]),(TIBIA_C[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[3]-CURVE[3]),(Z_STATIC_IK[5]),(NTIBIA_C_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[0]),(NTIBIA_C[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[4]),(TIBIA_C_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[3]-CURVE[3]),(Z_STATIC_IK[1]),(TIBIA_C[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[3]-CURVE[3]),(Z_STATIC_IK[5]),(NTIBIA_C_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[0]),(NTIBIA_C[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[4]),(TIBIA_C_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[3]-CURVE[3]),(Z_STATIC_IK[1]),(TIBIA_C[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[3]-CURVE[3]),(Z_STATIC_IK[5]),(NTIBIA_C_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[0]),(NTIBIA_C[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[4]),(TIBIA_C_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if (Ping[PING_REAR]<=REAR_THRESHOLD)break;
		if(FOLLOW_TRACER_STATE == 1)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
		}

		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
		if(FOLLOW_CARPET_MODE == NORMAL)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

		}
		else if(FOLLOW_CARPET_MODE == INVERSE)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

		}
		if (Ping[PING_REAR]<=REAR_THRESHOLD)break;

		//SIKLUS 3
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[2]-CURVE[2]),(Z_STATIC_IK[1]),(TIBIA_C[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[2]-CURVE[2]),(Z_STATIC_IK[5]),(NTIBIA_C_R[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[2]),(FEMUR_C[0]),(NTIBIA_C[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[2]-NCURVE[2]),(FEMUR_C[0]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[2]),(FEMUR_C[0]),(TIBIA_C_R[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[1]-CURVE[1]),(Z_STATIC_IK[1]),(TIBIA_C[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[1]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[1]-CURVE[1]),(Z_STATIC_IK[5]),(NTIBIA_C_R[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[1]),(FEMUR_C[1]),(NTIBIA_C[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[1]-NCURVE[1]),(FEMUR_C[1]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[1]),(FEMUR_C[1]),(TIBIA_C_R[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[0]-CURVE[0]),(Z_STATIC_IK[1]),(TIBIA_C[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[0]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[0]-CURVE[0]),(Z_STATIC_IK[5]),(NTIBIA_C_R[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[0]),(FEMUR_C[2]),(NTIBIA_C[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[0]-NCURVE[0]),(FEMUR_C[2]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[0]),(FEMUR_C[2]),(TIBIA_C_R[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK[1]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK[5]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK[0]),(FEMUR_C[3]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(FEMUR_C[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK[4]),(FEMUR_C[3]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if (Ping[PING_REAR]<=REAR_THRESHOLD)break;
		if(FOLLOW_TRACER_STATE == 1)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
		}

		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
		if(FOLLOW_CARPET_MODE == NORMAL)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

		}
		else if(FOLLOW_CARPET_MODE == INVERSE)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

		}
		if (Ping[PING_REAR]<=REAR_THRESHOLD)break;

		//SIKLUS 4
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[0]-NCURVE[0]),(Z_STATIC_IK[1]),(NTIBIA_C[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[0]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[0]-NCURVE[0]),(Z_STATIC_IK[5]),(TIBIA_C_R[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[0]),(FEMUR_C[3]),(TIBIA_C[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[0]-CURVE[0]),(FEMUR_C[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[0]),(FEMUR_C[3]),(NTIBIA_C_R[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[1]-NCURVE[1]),(Z_STATIC_IK[1]),(NTIBIA_C[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[1]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[1]-NCURVE[1]),(Z_STATIC_IK[5]),(TIBIA_C_R[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[1]),(FEMUR_C[2]),(TIBIA_C[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[1]-CURVE[1]),(FEMUR_C[2]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[1]),(FEMUR_C[2]),(NTIBIA_C_R[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[2]-NCURVE[2]),(Z_STATIC_IK[1]),(NTIBIA_C[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[2]-NCURVE[2]),(Z_STATIC_IK[5]),(TIBIA_C_R[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[2]),(FEMUR_C[1]),(TIBIA_C[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[2]-CURVE[2]),(FEMUR_C[1]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[2]),(FEMUR_C[1]),(NTIBIA_C_R[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[1]),(NTIBIA_C[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[5]),(TIBIA_C_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[3]),(FEMUR_C[0]),(TIBIA_C[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[3]-CURVE[3]),(FEMUR_C[0]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[3]),(FEMUR_C[0]),(NTIBIA_C_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if (Ping[PING_REAR]<=REAR_THRESHOLD)break;

		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}

		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}

		if(FOLLOW_CARPET_MODE == NORMAL)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

		}
		else if(FOLLOW_CARPET_MODE == INVERSE)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

		}
		if (Ping[PING_REAR]<=REAR_THRESHOLD)break;

		//SIKLUS 5
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[1]),(NTIBIA_C[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[5]),(TIBIA_C_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[3]),(Z_STATIC_IK[0]),(TIBIA_C[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[3]-CURVE[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[3]),(Z_STATIC_IK[4]),(NTIBIA_C_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[1]),(NTIBIA_C[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[5]),(TIBIA_C_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[3]),(Z_STATIC_IK[0]),(TIBIA_C[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[3]-CURVE[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[3]),(Z_STATIC_IK[4]),(NTIBIA_C_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[1]),(NTIBIA_C[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[5]),(TIBIA_C_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[3]),(Z_STATIC_IK[0]),(TIBIA_C[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[3]-CURVE[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[3]),(Z_STATIC_IK[4]),(NTIBIA_C_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[1]),(NTIBIA_C[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[5]),(TIBIA_C_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[3]),(Z_STATIC_IK[0]),(TIBIA_C[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[3]-CURVE[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[3]),(Z_STATIC_IK[4]),(NTIBIA_C_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if (Ping[PING_REAR]<=REAR_THRESHOLD)break;

		if(FOLLOW_TRACER_STATE == 1)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
		}

		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}

		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}

		if(FOLLOW_CARPET_MODE == NORMAL)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

		}
		else if(FOLLOW_CARPET_MODE == INVERSE)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

		}
		if (Ping[PING_REAR]<=REAR_THRESHOLD)break;

		//SIKLUS6
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[2]-NCURVE[2]),(FEMUR_C[0]),(NTIBIA_C[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[2]),(FEMUR_C[0]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[2]-NCURVE[2]),(FEMUR_C[0]),(TIBIA_C_R[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[2]),(Z_STATIC_IK[0]),(TIBIA_C[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[2]-CURVE[2]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[2]),(Z_STATIC_IK[4]),(NTIBIA_C_R[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[1]-NCURVE[1]),(FEMUR_C[1]),(NTIBIA_C[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[1]),(FEMUR_C[1]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[1]-NCURVE[1]),(FEMUR_C[1]),(TIBIA_C_R[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[1]),(Z_STATIC_IK[0]),(TIBIA_C[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[1]-CURVE[1]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[1]),(Z_STATIC_IK[4]),(NTIBIA_C_R[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[0]-NCURVE[0]),(FEMUR_C[2]),(NTIBIA_C[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[0]),(FEMUR_C[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[0]-NCURVE[0]),(FEMUR_C[2]),(TIBIA_C_R[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[0]),(Z_STATIC_IK[0]),(TIBIA_C[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[0]-CURVE[0]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[0]),(Z_STATIC_IK[4]),(NTIBIA_C_R[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK[1]),(FEMUR_C[3]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(FEMUR_C[3]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK[5]),(FEMUR_C[3]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK[0]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK[4]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if (Ping[PING_REAR]<=REAR_THRESHOLD)break;

		if(FOLLOW_TRACER_STATE == 1)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
		}
		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
		TCS3200_Transmit(UART5, CMD_GET_TRACER);
		if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
		if(FOLLOW_CARPET_MODE == NORMAL)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

		}
		else if(FOLLOW_CARPET_MODE == INVERSE)
		{
			TCS3200_Transmit(UART5, CMD_GET_TRACER);
			if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

		}
		if (Ping[PING_REAR]<=REAR_THRESHOLD)break;
	}
	CURVE_RIGHT_STAT = 0;
}

void Dynamx_MoveCurveRight_IK(int SPEED,int limit,volatile float *ACTUATE_SIGNAL)
{
	CURVE_RIGHT_STAT = 1;
	int loop;
	int MAX_SIGNAL = 15;
	int cek_value = 0;

	if(IK_CALCULATED_CRV_R == 0)
	{
		Generate_Body(0,1.5);
		Trajectory_Generator_6S(X_Diff, Y_Diff, -2, 6,MOVEMENT_NORMAL);
		for(i=0;i<=5;i++)
		{
				Dyna_IKCalc_Only((X_IK_BEGIN[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]+Z_IK[i]));
				FEMUR_C[i] = tetha.Femur;
				COXA_C[i] = tetha.Coxa;
				NFEMUR_C[i] = (tetha.Femur*-1);
				NCOXA_C[i] = (tetha.Coxa*-1);

				Dyna_IKCalc_Only((X_IK_BEGIN[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
				TIBIA_C[i] = tetha.Tibia;

				Dyna_IKCalc_Only((X_IK_BEGIN[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
				NTIBIA_C[i] = tetha.Tibia;
				NTIBIA_C_R[i] = tetha.Tibia;

				Dyna_IKCalc_Only((X_IK_BEGIN[0]+X4_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
				TIBIA_C_R[i] = tetha.Tibia;
		}

		IK_CALCULATED_CRV_L = 0;
		IK_CALCULATED_CRV_R = 1;
		IK_CALCULATED_CRV_L_REVERSE = 0;
		IK_CALCULATED_CRV_R_REVERSE = 0;
	}

	SPEED = SPEED/45;

	int a = 0;
	int b = 0, c = 0;

	float signal=*ACTUATE_SIGNAL/3;
	float error_L;//femur_L,tibia_L;
	float error_R;//femur_R,tibia_R;
	float error_R2;

	if (signal>=MAX_SIGNAL){error_R=MAX_SIGNAL;error_R2=MAX_SIGNAL;}
	else {error_R=signal;error_R2=signal;}

	float DELTA_R= (1 * error_R);
	float DELTA_R2 = (1 * error_R2);

	int LEFT_EXT1 = 0;
	int LEFT_EXT2 = 0;

	int CURVE[6];
	int NCURVE[6];

	CURVE[0] = (int)((DELTA_R*(float)COXA_C[0])/((float)(MAX_SIGNAL)));
	CURVE[1] = (int)((DELTA_R*(float)COXA_C[1])/((float)(MAX_SIGNAL)));
	CURVE[2] = (int)((DELTA_R*(float)COXA_C[2])/((float)(MAX_SIGNAL)));
	CURVE[3] = (int)((DELTA_R*(float)COXA_C[3])/((float)(MAX_SIGNAL)));
	CURVE[4] = (int)((DELTA_R*(float)COXA_C[4])/((float)(MAX_SIGNAL)));
	CURVE[5] = (int)((DELTA_R*(float)COXA_C[5])/((float)(MAX_SIGNAL)));

	NCURVE[0] = (int)((DELTA_R2*(float)NCOXA_C[0])/((float)(MAX_SIGNAL)));
	NCURVE[1] = (int)((DELTA_R2*(float)NCOXA_C[1])/((float)(MAX_SIGNAL)));
	NCURVE[2] = (int)((DELTA_R2*(float)NCOXA_C[2])/((float)(MAX_SIGNAL)));
	NCURVE[3] = (int)((DELTA_R2*(float)NCOXA_C[3])/((float)(MAX_SIGNAL)));
	NCURVE[4] = (int)((DELTA_R2*(float)NCOXA_C[4])/((float)(MAX_SIGNAL)));
	NCURVE[5] = (int)((DELTA_R2*(float)NCOXA_C[5])/((float)(MAX_SIGNAL)));

	if (cek_value==1)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"CURVE VALUE");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d",CURVE[0],CURVE[1],CURVE[2]);lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d",CURVE[3],CURVE[4],CURVE[5]);lcd_putstr(lcd);

//		lcd_gotoxy(0,0);sprintf(lcd,"FEMUR VALUE R");lcd_putstr(lcd);
//		lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d",FEMUR_C[0],FEMUR_C[1],FEMUR_C[2]);lcd_putstr(lcd);
//		lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d",FEMUR_C[3],FEMUR_C[4],FEMUR_C[5]);lcd_putstr(lcd);


		while(1){}
	}

	int n;
	for(n=0;n<=5;n++)
	{
		NCURVE[i] = (NCURVE[i]*-1);
	}

			for(loop=1;loop<=limit;loop++)
			{
				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}

				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
				{
					Stairs_Detector();
					if(STAIRS_FLAG == STAIRS_DETECTED)break;
				}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
				if(FOLLOW_TRACER_STATE == 1)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
				}

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}

				if(FOLLOW_CARPET_MODE == NORMAL)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

				}

				else if(FOLLOW_CARPET_MODE == INVERSE)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

				}

				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				//SIKLUS 1
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[0]-CURVE[0]),(FEMUR_C[5]),(TIBIA_C[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[0]),(FEMUR_C[5]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[0]-CURVE[0]),(FEMUR_C[5]),(NTIBIA_C_R[0]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[0]),(Z_STATIC_IK[0]),(NTIBIA_C[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[0]-NCURVE[0]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[0]),(Z_STATIC_IK[4]),(TIBIA_C_R[0]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[1]-CURVE[1]),(FEMUR_C[4]),(TIBIA_C[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[1]),(FEMUR_C[4]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[1]-CURVE[1]),(FEMUR_C[4]),(NTIBIA_C_R[1]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[1]),(Z_STATIC_IK[0]),(NTIBIA_C[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[1]-NCURVE[1]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[1]),(Z_STATIC_IK[4]),(TIBIA_C_R[1]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);


				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[2]-CURVE[2]),(FEMUR_C[3]),(TIBIA_C[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[2]),(FEMUR_C[3]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[2]-CURVE[2]),(FEMUR_C[3]),(NTIBIA_C_R[2]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[2]),(Z_STATIC_IK[0]),(NTIBIA_C[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[2]-NCURVE[2]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[2]),(Z_STATIC_IK[4]),(TIBIA_C_R[2]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);


				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[3]-CURVE[3]),(FEMUR_C[2]),(TIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[3]),(FEMUR_C[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[3]-CURVE[3]),(FEMUR_C[2]),(NTIBIA_C_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[0]),(NTIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[4]),(TIBIA_C_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);


				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[4]-CURVE[4]),(FEMUR_C[1]),(TIBIA_C[4]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[4]),(FEMUR_C[1]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[4]-CURVE[4]),(FEMUR_C[1]),(NTIBIA_C_R[4]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[4]),(Z_STATIC_IK[0]),(NTIBIA_C[4]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[4]-NCURVE[4]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[4]),(Z_STATIC_IK[4]),(TIBIA_C_R[4]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);


				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[5]-CURVE[5]),(FEMUR_C[0]),(TIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[5]),(FEMUR_C[0]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[5]-CURVE[5]),(FEMUR_C[0]),(NTIBIA_C_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[0]),(NTIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[4]),(TIBIA_C_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
				{
					Stairs_Detector();
					if(STAIRS_FLAG == STAIRS_DETECTED)break;
				}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
				if(FOLLOW_TRACER_STATE == 1)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
				}

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				if(FOLLOW_CARPET_MODE == NORMAL)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

				}
				else if(FOLLOW_CARPET_MODE == INVERSE)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

				}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				//SIKLUS 2
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[1]),(TIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[5]),(NTIBIA_C_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[0]),(NTIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[5]-NCURVE[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[4]),(TIBIA_C_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[1]),(TIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[5]),(NTIBIA_C_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[0]),(NTIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[5]-NCURVE[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[4]),(TIBIA_C_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[1]),(TIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[5]),(NTIBIA_C_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[0]),(NTIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[5]-NCURVE[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[4]),(TIBIA_C_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[1]),(TIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[5]),(NTIBIA_C_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[0]),(NTIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[5]-NCURVE[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[4]),(TIBIA_C_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[1]),(TIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[5]),(NTIBIA_C_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[0]),(NTIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[5]-NCURVE[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[4]),(TIBIA_C_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[1]),(TIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[5]),(NTIBIA_C_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[0]),(NTIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[5]-NCURVE[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[4]),(TIBIA_C_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);


				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}

				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
				{
					Stairs_Detector();
					if(STAIRS_FLAG == STAIRS_DETECTED)break;
				}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
				if(FOLLOW_TRACER_STATE == 1)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
				}

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				if(FOLLOW_CARPET_MODE == NORMAL)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

				}
				else if(FOLLOW_CARPET_MODE == INVERSE)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

				}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				//SIKLUS 3
				//1
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[4]-CURVE[4]),(Z_STATIC_IK[1]),(TIBIA_C[4]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[4]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[4]-CURVE[4]),(Z_STATIC_IK[5]),(NTIBIA_C_R[4]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[4]),(FEMUR_C[0]),(NTIBIA_C[4]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[4]-NCURVE[4]),(FEMUR_C[0]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[4]),(FEMUR_C[0]),(TIBIA_C_R[4]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//2
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[3]-CURVE[3]),(Z_STATIC_IK[1]),(TIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[3]-CURVE[3]),(Z_STATIC_IK[5]),(NTIBIA_C_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[3]),(FEMUR_C[1]),(NTIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[3]-NCURVE[3]),(FEMUR_C[1]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[3]),(FEMUR_C[1]),(TIBIA_C_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//3
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[2]-CURVE[2]),(Z_STATIC_IK[1]),(TIBIA_C[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[2]-CURVE[2]),(Z_STATIC_IK[5]),(NTIBIA_C_R[2]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[2]),(FEMUR_C[2]),(NTIBIA_C[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[2]-NCURVE[2]),(FEMUR_C[2]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[2]),(FEMUR_C[2]),(TIBIA_C_R[2]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//4
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[1]-CURVE[1]),(Z_STATIC_IK[1]),(TIBIA_C[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[1]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[1]-CURVE[1]),(Z_STATIC_IK[5]),(NTIBIA_C_R[1]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[1]),(FEMUR_C[3]),(NTIBIA_C[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[1]-NCURVE[1]),(FEMUR_C[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[1]),(FEMUR_C[3]),(TIBIA_C_R[1]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//5
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[0]-CURVE[0]),(Z_STATIC_IK[1]),(TIBIA_C[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[0]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[0]-CURVE[0]),(Z_STATIC_IK[5]),(NTIBIA_C_R[0]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[0]),(FEMUR_C[4]),(NTIBIA_C[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[0]-NCURVE[0]),(FEMUR_C[4]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[0]),(FEMUR_C[4]),(TIBIA_C_R[0]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//6
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK[1]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK[5]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK[0]),(FEMUR_C[5]),(X_STATIC_IK[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(FEMUR_C[5]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK[4]),(FEMUR_C[5]),(X_STATIC_IK[4]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
				{
					Stairs_Detector();
					if(STAIRS_FLAG == STAIRS_DETECTED)break;
				}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
				if(FOLLOW_TRACER_STATE == 1)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
				}

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				if(FOLLOW_CARPET_MODE == NORMAL)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

				}
				else if(FOLLOW_CARPET_MODE == INVERSE)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

				}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				//SIKLUS 4
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[0]-NCURVE[0]),(Z_STATIC_IK[1]),(NTIBIA_C[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[0]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[0]-NCURVE[0]),(Z_STATIC_IK[5]),(TIBIA_C_R[0]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[0]),(FEMUR_C[5]),(TIBIA_C[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[0]-CURVE[0]),(FEMUR_C[5]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[0]),(FEMUR_C[5]),(NTIBIA_C_R[0]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[1]-NCURVE[1]),(Z_STATIC_IK[1]),(NTIBIA_C[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[1]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[1]-NCURVE[1]),(Z_STATIC_IK[5]),(TIBIA_C_R[1]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[1]),(FEMUR_C[4]),(TIBIA_C[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[1]-CURVE[1]),(FEMUR_C[4]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[1]),(FEMUR_C[4]),(NTIBIA_C_R[1]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[2]-NCURVE[2]),(Z_STATIC_IK[1]),(NTIBIA_C[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[2]-NCURVE[2]),(Z_STATIC_IK[5]),(TIBIA_C_R[2]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[2]),(FEMUR_C[3]),(TIBIA_C[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[2]-CURVE[2]),(FEMUR_C[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[2]),(FEMUR_C[3]),(NTIBIA_C_R[2]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[1]),(NTIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[5]),(TIBIA_C_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[3]),(FEMUR_C[2]),(TIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[3]-CURVE[3]),(FEMUR_C[2]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[3]),(FEMUR_C[2]),(NTIBIA_C_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[4]-NCURVE[4]),(Z_STATIC_IK[1]),(NTIBIA_C[4]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[4]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[4]-NCURVE[4]),(Z_STATIC_IK[5]),(TIBIA_C_R[4]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[4]),(FEMUR_C[1]),(TIBIA_C[4]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[4]-CURVE[4]),(FEMUR_C[1]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[4]),(FEMUR_C[1]),(NTIBIA_C_R[4]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[1]),(NTIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[5]),(TIBIA_C_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[5]),(FEMUR_C[0]),(TIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[5]-CURVE[5]),(FEMUR_C[0]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[5]),(FEMUR_C[0]),(NTIBIA_C_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
				{
					Stairs_Detector();
					if(STAIRS_FLAG == STAIRS_DETECTED)break;
				}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}

				if(FOLLOW_CARPET_MODE == NORMAL)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

				}
				else if(FOLLOW_CARPET_MODE == INVERSE)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

				}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				//SIKLUS 5
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[1]),(NTIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[5]),(TIBIA_C_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[5]),(Z_STATIC_IK[0]),(TIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[5]),(Z_STATIC_IK[4]),(NTIBIA_C_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[1]),(NTIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[5]),(TIBIA_C_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[5]),(Z_STATIC_IK[0]),(TIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[5]),(Z_STATIC_IK[4]),(NTIBIA_C_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[1]),(NTIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[5]),(TIBIA_C_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[5]),(Z_STATIC_IK[0]),(TIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[5]),(Z_STATIC_IK[4]),(NTIBIA_C_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[1]),(NTIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[5]),(TIBIA_C_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[5]),(Z_STATIC_IK[0]),(TIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[5]),(Z_STATIC_IK[4]),(NTIBIA_C_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[1]),(NTIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[5]),(TIBIA_C_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[5]),(Z_STATIC_IK[0]),(TIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[5]),(Z_STATIC_IK[4]),(NTIBIA_C_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[1]),(NTIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[5]),(TIBIA_C_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[5]),(Z_STATIC_IK[0]),(TIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[5]),(Z_STATIC_IK[4]),(NTIBIA_C_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
				{
					Stairs_Detector();
					if(STAIRS_FLAG == STAIRS_DETECTED)break;
				}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				if(FOLLOW_TRACER_STATE == 1)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
				}

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}

				if(FOLLOW_CARPET_MODE == NORMAL)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

				}
				else if(FOLLOW_CARPET_MODE == INVERSE)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

				}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				//SIKLUS 6
				//1
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[4]-NCURVE[4]),(FEMUR_C[0]),(NTIBIA_C[4]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[4]),(FEMUR_C[0]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[4]-NCURVE[4]),(FEMUR_C[0]),(TIBIA_C_R[4]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[4]),(Z_STATIC_IK[0]),(TIBIA_C[4]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[4]-CURVE[4]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[4]),(Z_STATIC_IK[4]),(NTIBIA_C_R[4]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//2
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[3]-NCURVE[3]),(FEMUR_C[1]),(NTIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[3]),(FEMUR_C[1]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[3]-NCURVE[3]),(FEMUR_C[1]),(TIBIA_C_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[3]),(Z_STATIC_IK[0]),(TIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[3]-CURVE[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[3]),(Z_STATIC_IK[4]),(NTIBIA_C_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//3
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[2]-NCURVE[2]),(FEMUR_C[2]),(NTIBIA_C[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[2]),(FEMUR_C[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[2]-NCURVE[2]),(FEMUR_C[2]),(TIBIA_C_R[2]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[2]),(Z_STATIC_IK[0]),(TIBIA_C[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[2]-CURVE[2]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[2]),(Z_STATIC_IK[4]),(NTIBIA_C_R[2]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//4
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[1]-NCURVE[1]),(FEMUR_C[3]),(NTIBIA_C[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[1]),(FEMUR_C[3]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[1]-NCURVE[1]),(FEMUR_C[3]),(TIBIA_C_R[1]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[1]),(Z_STATIC_IK[0]),(TIBIA_C[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[1]-CURVE[1]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[1]),(Z_STATIC_IK[4]),(NTIBIA_C_R[1]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//5
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[0]-NCURVE[0]),(FEMUR_C[4]),(NTIBIA_C[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[0]),(FEMUR_C[4]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[0]-NCURVE[0]),(FEMUR_C[4]),(TIBIA_C_R[0]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[0]),(Z_STATIC_IK[0]),(TIBIA_C[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[0]-CURVE[0]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[0]),(Z_STATIC_IK[4]),(NTIBIA_C_R[0]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				// 6
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK[1]),(FEMUR_C[5]),(X_STATIC_IK[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(FEMUR_C[5]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK[5]),(FEMUR_C[5]),(X_STATIC_IK[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK[0]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK[4]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
				{
					Stairs_Detector();
					if(STAIRS_FLAG == STAIRS_DETECTED)break;
				}

				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				if(FOLLOW_TRACER_STATE == 1)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
				}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				if(FOLLOW_CARPET_MODE == NORMAL)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

				}
				else if(FOLLOW_CARPET_MODE == INVERSE)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

				}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
			}
			CURVE_RIGHT_STAT = 0;
}

void Dynamx_MoveCurveRight_Obstaicle(int SPEED,int limit,volatile float *ACTUATE_SIGNAL)
{
	CURVE_RIGHT_STAT = 1;
	int loop;
	int MAX_SIGNAL = 15;

	if(IK_CALCULATED_CRV_R_OBS == 0)
	{
		Generate_Body(0,1.8);
		Trajectory_Generator_Obs(X_Diff, Y_Diff, -3.75, 4,MOVEMENT_NORMAL);
		for(i=0;i<=3;i++)
		{
			if(mode_follow==MODE_FOLLOW_R6)
			{
				Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_STAIRS[1]+Z_IK[i]));
				FEMUR_O[i] = tetha.Femur;
				COXA_O[i] = tetha.Coxa;
				NFEMUR_O[i] = (tetha.Femur*-1);
				NCOXA_O[i] = (tetha.Coxa*-1);

				Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_STAIRS[1]));
				TIBIA_O[i] = tetha.Tibia;

				Dyna_IKCalc_Only((X_IK_OBS[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_STAIRS[1]));
				NTIBIA_O[i] = tetha.Tibia;
				NTIBIA_O_R[i] = tetha.Tibia;

				Dyna_IKCalc_Only((X_IK_OBS[0]+X2_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_STAIRS[1]));
				TIBIA_O_R[i] = tetha.Tibia;
			}
			else
			{
				Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_OBS[1]+Z_IK[i]));
				FEMUR_O[i] = tetha.Femur;
				COXA_O[i] = tetha.Coxa;
				NFEMUR_O[i] = (tetha.Femur*-1);
				NCOXA_O[i] = (tetha.Coxa*-1);

				Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_OBS[1]));
				TIBIA_O[i] = tetha.Tibia;

				Dyna_IKCalc_Only((X_IK_OBS[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_OBS[1]));
				NTIBIA_O[i] = tetha.Tibia;
				NTIBIA_O_R[i] = tetha.Tibia;

				Dyna_IKCalc_Only((X_IK_OBS[0]+X2_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_OBS[1]));
				TIBIA_O_R[i] = tetha.Tibia;
			}
		}
		IK_CALCULATED_CRV_R_OBS = 1;
		IK_CALCULATED_CRV_L_OBS = 0;
	}

		SPEED = SPEED/45;

		int a = 0;
		int b = 0, c = 0;

		float signal=*ACTUATE_SIGNAL/3;
		float error_L;//femur_L,tibia_L;
		float error_R;//femur_R,tibia_R;
		float error_R2;

		if (signal>=MAX_SIGNAL){error_R=MAX_SIGNAL;error_R2=MAX_SIGNAL;}
		else {error_R=signal;error_R2=signal;}

		float DELTA_R= (1 * error_R);
		float DELTA_R2 = (1 * error_R2);

		int LEFT_EXT1 = 0;
		int LEFT_EXT2 = 0;

		int CURVE[6];
		int NCURVE[6];

		CURVE[0] = (int)((DELTA_R*(float)COXA_O[0])/((float)(MAX_SIGNAL)));
		CURVE[1] = (int)((DELTA_R*(float)COXA_O[1])/((float)(MAX_SIGNAL)));
		CURVE[2] = (int)((DELTA_R*(float)COXA_O[2])/((float)(MAX_SIGNAL)));
		CURVE[3] = (int)((DELTA_R*(float)COXA_O[3])/((float)(MAX_SIGNAL)));
		CURVE[4] = (int)((DELTA_R*(float)COXA_O[4])/((float)(MAX_SIGNAL)));
		CURVE[5] = (int)((DELTA_R*(float)COXA_O[5])/((float)(MAX_SIGNAL)));

		NCURVE[0] = (int)((DELTA_R2*(float)NCOXA_O[0])/((float)(MAX_SIGNAL)));
		NCURVE[1] = (int)((DELTA_R2*(float)NCOXA_O[1])/((float)(MAX_SIGNAL)));
		NCURVE[2] = (int)((DELTA_R2*(float)NCOXA_O[2])/((float)(MAX_SIGNAL)));
		NCURVE[3] = (int)((DELTA_R2*(float)NCOXA_O[3])/((float)(MAX_SIGNAL)));
		NCURVE[4] = (int)((DELTA_R2*(float)NCOXA_O[4])/((float)(MAX_SIGNAL)));
		NCURVE[5] = (int)((DELTA_R2*(float)NCOXA_O[5])/((float)(MAX_SIGNAL)));

		int n;
		for(n=0;n<=5;n++)
		{
			NCURVE[i] = (NCURVE[i]*-1);
		}

		for(loop=1;loop<=limit;loop++)
		{

//			if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//			{
//				Stairs_Detector();
//				if(STAIRS_FLAG == STAIRS_DETECTED)break;
//			}
//			if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
//
//			if(FOLLOW_TRACER_STATE == 1)
//			{
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//			}
//
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//			if(FOLLOW_CARPET_MODE == NORMAL)
//			{
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//			}
//
//			else if(FOLLOW_CARPET_MODE == INVERSE)
//			{
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//			}
//
//			if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

			if(mode_korban==MODE_K5)
			{
				GetCMPS11_Angle8Bit();
				if(((VL_SENSOR[0]<340)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)&&(CMPS11_Angle<85)){mode_scan_K5=MODE_SCAN_K5_RIGHT;break;}//samping kanan

				if((VL_SENSOR[0]<190)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<230))){break;}//pas

				if(((VL_SENSOR[0]<300)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)){mode_scan_K5=MODE_SCAN_K5_LEFT;break;}//samping kiri
			}

			//SIKLUS  1
			Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[0]-CURVE[0]),(FEMUR_O[3]),(TIBIA_O[0]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[0]),(FEMUR_O[3]),(X_STATIC_IK_S[2]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[0]-CURVE[0]),(FEMUR_O[3]),(NTIBIA_O_R[0]));

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[0]),(Z_STATIC_IK_S[0]),(NTIBIA_O[0]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[0]-NCURVE[0]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[0]),(Z_STATIC_IK_S[4]),(TIBIA_O_R[0]));
			Start_Pose_SYNC();
			delay_ms(SPEED+4);

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[1]-CURVE[1]),(FEMUR_O[2]),(TIBIA_O[1]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[1]),(FEMUR_O[2]),(X_STATIC_IK_S[2]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[1]-CURVE[1]),(FEMUR_O[2]),(NTIBIA_O_R[1]));

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[1]),(Z_STATIC_IK_S[0]),(NTIBIA_O[1]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[1]-NCURVE[1]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[1]),(Z_STATIC_IK_S[4]),(TIBIA_O_R[1]));
			Start_Pose_SYNC();
			delay_ms(SPEED+4);


			Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[2]-CURVE[2]),(FEMUR_O[1]),(TIBIA_O[2]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[2]),(FEMUR_O[1]),(X_STATIC_IK_S[2]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[2]-CURVE[2]),(FEMUR_O[1]),(NTIBIA_O_R[2]));

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[2]),(Z_STATIC_IK_S[0]),(NTIBIA_O[2]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[2]-NCURVE[2]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[2]),(Z_STATIC_IK_S[4]),(TIBIA_O_R[2]));
			Start_Pose_SYNC();
			delay_ms(SPEED+4);


			Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[3]-CURVE[3]),(FEMUR_O[0]),(TIBIA_O[3]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[3]),(FEMUR_O[0]),(X_STATIC_IK_S[2]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[3]-CURVE[3]),(FEMUR_O[0]),(NTIBIA_O_R[3]));

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[0]),(NTIBIA_O[3]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[3]-NCURVE[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[4]),(TIBIA_O_R[3]));
			Start_Pose_SYNC();
			delay_ms(SPEED+4);

//			if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//			{
//				Stairs_Detector();
//				if(STAIRS_FLAG == STAIRS_DETECTED)break;
//			}
//
//			if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
//
//			if(FOLLOW_TRACER_STATE == 1)
//			{
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//			}
//
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//			if(FOLLOW_CARPET_MODE == NORMAL)
//			{
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//			}
//			else if(FOLLOW_CARPET_MODE == INVERSE)
//			{
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//			}
//			if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

			if(mode_korban==MODE_K5)
			{
				GetCMPS11_Angle8Bit();
				if(((VL_SENSOR[0]<340)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)&&(CMPS11_Angle<85)){mode_scan_K5=MODE_SCAN_K5_RIGHT;break;}//samping kanan

				if((VL_SENSOR[0]<190)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<230))){break;}//pas

				if(((VL_SENSOR[0]<300)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)){mode_scan_K5=MODE_SCAN_K5_LEFT;break;}//samping kiri
			}

			//SIKLUS 2
			Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[3]-CURVE[3]),(Z_STATIC_IK_S[1]),(TIBIA_O[3]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[3]-CURVE[3]),(Z_STATIC_IK_S[5]),(NTIBIA_O_R[3]));

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[0]),(NTIBIA_O[3]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[3]-NCURVE[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[4]),(TIBIA_O_R[3]));
			Start_Pose_SYNC();
			delay_ms(SPEED+4);

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[3]-CURVE[3]),(Z_STATIC_IK_S[1]),(TIBIA_O[3]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[3]-CURVE[3]),(Z_STATIC_IK_S[5]),(NTIBIA_O_R[3]));

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[0]),(NTIBIA_O[3]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[3]-NCURVE[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[4]),(TIBIA_O_R[3]));
			Start_Pose_SYNC();
			delay_ms(SPEED+4);

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[3]-CURVE[3]),(Z_STATIC_IK_S[1]),(TIBIA_O[3]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[3]-CURVE[3]),(Z_STATIC_IK_S[5]),(NTIBIA_O_R[3]));

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[0]),(NTIBIA_O[3]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[3]-NCURVE[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[4]),(TIBIA_O_R[3]));
			Start_Pose_SYNC();
			delay_ms(SPEED+4);

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[3]-CURVE[3]),(Z_STATIC_IK_S[1]),(TIBIA_O[3]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[3]-CURVE[3]),(Z_STATIC_IK_S[5]),(NTIBIA_O_R[3]));

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[0]),(NTIBIA_O[3]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[3]-NCURVE[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[4]),(TIBIA_O_R[3]));
			Start_Pose_SYNC();
			delay_ms(SPEED+4);

//			if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//			{
//				Stairs_Detector();
//				if(STAIRS_FLAG == STAIRS_DETECTED)break;
//			}
//			if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
//			if(FOLLOW_TRACER_STATE == 1)
//			{
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//			}
//
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//			if(FOLLOW_CARPET_MODE == NORMAL)
//			{
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//			}
//			else if(FOLLOW_CARPET_MODE == INVERSE)
//			{
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//			}
//			if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

			if(mode_korban==MODE_K5)
			{
				GetCMPS11_Angle8Bit();
				if(((VL_SENSOR[0]<340)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)&&(CMPS11_Angle<85)){mode_scan_K5=MODE_SCAN_K5_RIGHT;break;}//samping kanan

				if((VL_SENSOR[0]<190)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<230))){break;}//pas

				if(((VL_SENSOR[0]<300)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)){mode_scan_K5=MODE_SCAN_K5_LEFT;break;}//samping kiri
			}

			//SIKLUS 3
			Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[2]-CURVE[2]),(Z_STATIC_IK_S[1]),(TIBIA_O[2]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[2]-CURVE[2]),(Z_STATIC_IK_S[5]),(NTIBIA_O_R[2]));

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[2]),(FEMUR_O[0]),(NTIBIA_O[2]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[2]-NCURVE[2]),(FEMUR_O[0]),(X_STATIC_IK_S[3]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[2]),(FEMUR_O[0]),(TIBIA_O_R[2]));
			Start_Pose_SYNC();
			delay_ms(SPEED+4);


			Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[1]-CURVE[1]),(Z_STATIC_IK_S[1]),(TIBIA_O[1]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[1]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[1]-CURVE[1]),(Z_STATIC_IK_S[5]),(NTIBIA_O_R[1]));

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[1]),(FEMUR_O[1]),(NTIBIA_O[1]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[1]-NCURVE[1]),(FEMUR_O[1]),(X_STATIC_IK_S[3]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[1]),(FEMUR_O[1]),(TIBIA_O_R[1]));
			Start_Pose_SYNC();
			delay_ms(SPEED+4);

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[0]-CURVE[0]),(Z_STATIC_IK_S[1]),(TIBIA_O[0]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[0]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[0]-CURVE[0]),(Z_STATIC_IK_S[5]),(NTIBIA_O_R[0]));

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[0]),(FEMUR_O[2]),(NTIBIA_O[0]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[0]-NCURVE[0]),(FEMUR_O[2]),(X_STATIC_IK_S[3]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[0]),(FEMUR_O[2]),(TIBIA_O_R[0]));
			Start_Pose_SYNC();
			delay_ms(SPEED+4);

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[1]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK_S[5]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK_S[0]),(FEMUR_O[3]),(X_STATIC_IK_S[0]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(FEMUR_O[3]),(X_STATIC_IK_S[3]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK_S[4]),(FEMUR_O[3]),(X_STATIC_IK_S[4]));
			Start_Pose_SYNC();
			delay_ms(SPEED+4);

//			if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//			{
//				Stairs_Detector();
//				if(STAIRS_FLAG == STAIRS_DETECTED)break;
//			}
//			if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
//			if(FOLLOW_TRACER_STATE == 1)
//			{
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//			}
//
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//			if(FOLLOW_CARPET_MODE == NORMAL)
//			{
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//			}
//			else if(FOLLOW_CARPET_MODE == INVERSE)
//			{
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//			}
//			if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

			if(mode_korban==MODE_K5)
			{
				GetCMPS11_Angle8Bit();
				if(((VL_SENSOR[0]<340)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)&&(CMPS11_Angle<85)){mode_scan_K5=MODE_SCAN_K5_RIGHT;break;}//samping kanan

				if((VL_SENSOR[0]<190)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<230))){break;}//pas

				if(((VL_SENSOR[0]<300)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)){mode_scan_K5=MODE_SCAN_K5_LEFT;break;}//samping kiri
			}

			//SIKLUS 4
			Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[0]-NCURVE[0]),(Z_STATIC_IK_S[1]),(NTIBIA_O[0]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[0]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[0]-NCURVE[0]),(Z_STATIC_IK_S[5]),(TIBIA_O_R[0]));

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[0]),(FEMUR_O[3]),(TIBIA_O[0]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[0]-CURVE[0]),(FEMUR_O[3]),(X_STATIC_IK_S[3]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[0]),(FEMUR_O[3]),(NTIBIA_O_R[0]));
			Start_Pose_SYNC();
			delay_ms(SPEED+4);

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[1]-NCURVE[1]),(Z_STATIC_IK_S[1]),(NTIBIA_O[1]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[1]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[1]-NCURVE[1]),(Z_STATIC_IK_S[5]),(TIBIA_O_R[1]));

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[1]),(FEMUR_O[2]),(TIBIA_O[1]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[1]-CURVE[1]),(FEMUR_O[2]),(X_STATIC_IK_S[3]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[1]),(FEMUR_O[2]),(NTIBIA_O_R[1]));
			Start_Pose_SYNC();
			delay_ms(SPEED+4);

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[2]-NCURVE[2]),(Z_STATIC_IK_S[1]),(NTIBIA_O[2]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[2]-NCURVE[2]),(Z_STATIC_IK_S[5]),(TIBIA_O_R[2]));

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[2]),(FEMUR_O[1]),(TIBIA_O[2]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[2]-CURVE[2]),(FEMUR_O[1]),(X_STATIC_IK_S[3]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[2]),(FEMUR_O[1]),(NTIBIA_O_R[2]));
			Start_Pose_SYNC();
			delay_ms(SPEED+4);

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[3]-NCURVE[3]),(Z_STATIC_IK_S[1]),(NTIBIA_O[3]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[3]-NCURVE[3]),(Z_STATIC_IK_S[5]),(TIBIA_O_R[3]));

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[3]),(FEMUR_O[0]),(TIBIA_O[3]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[3]-CURVE[3]),(FEMUR_O[0]),(X_STATIC_IK_S[3]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[3]),(FEMUR_O[0]),(NTIBIA_O_R[3]));
			Start_Pose_SYNC();
			delay_ms(SPEED+4);

//			if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//			{
//				Stairs_Detector();
//				if(STAIRS_FLAG == STAIRS_DETECTED)break;
//			}
//			if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
//
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//			if(FOLLOW_CARPET_MODE == NORMAL)
//			{
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//			}
//			else if(FOLLOW_CARPET_MODE == INVERSE)
//			{
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//			}
//			if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

			if(mode_korban==MODE_K5)
			{
				GetCMPS11_Angle8Bit();
				if(((VL_SENSOR[0]<340)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)&&(CMPS11_Angle<85)){mode_scan_K5=MODE_SCAN_K5_RIGHT;break;}//samping kanan

				if((VL_SENSOR[0]<190)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<230))){break;}//pas

				if(((VL_SENSOR[0]<300)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)){mode_scan_K5=MODE_SCAN_K5_LEFT;break;}//samping kiri
			}

			//SIKLUS 5
			Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[3]-NCURVE[3]),(Z_STATIC_IK_S[1]),(NTIBIA_O[3]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[3]-NCURVE[3]),(Z_STATIC_IK_S[5]),(TIBIA_O_R[3]));

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[0]),(TIBIA_O[3]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[3]-CURVE[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[4]),(NTIBIA_O_R[3]));
			Start_Pose_SYNC();
			delay_ms(SPEED+4);

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[3]-NCURVE[3]),(Z_STATIC_IK_S[1]),(NTIBIA_O[3]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[3]-NCURVE[3]),(Z_STATIC_IK_S[5]),(TIBIA_O_R[3]));

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[0]),(TIBIA_O[3]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[3]-CURVE[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[4]),(NTIBIA_O_R[3]));
			Start_Pose_SYNC();
			delay_ms(SPEED+4);

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[3]-NCURVE[3]),(Z_STATIC_IK_S[1]),(NTIBIA_O[3]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[3]-NCURVE[3]),(Z_STATIC_IK_S[5]),(TIBIA_O_R[3]));

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[0]),(TIBIA_O[3]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[3]-CURVE[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[4]),(NTIBIA_O_R[3]));
			Start_Pose_SYNC();
			delay_ms(SPEED+4);

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[3]-NCURVE[3]),(Z_STATIC_IK_S[1]),(NTIBIA_O[3]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[3]-NCURVE[3]),(Z_STATIC_IK_S[5]),(TIBIA_O_R[3]));

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[0]),(TIBIA_O[3]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[3]-CURVE[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[4]),(NTIBIA_O_R[3]));
			Start_Pose_SYNC();
			delay_ms(SPEED+4);


//			if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//			{
//				Stairs_Detector();
//				if(STAIRS_FLAG == STAIRS_DETECTED)break;
//			}
//			if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
//
//			if(FOLLOW_TRACER_STATE == 1)
//			{
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//			}
//
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//			if(FOLLOW_CARPET_MODE == NORMAL)
//			{
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//			}
//			else if(FOLLOW_CARPET_MODE == INVERSE)
//			{
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//			}
//			if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

			if(mode_korban==MODE_K5)
			{
				GetCMPS11_Angle8Bit();
				if(((VL_SENSOR[0]<340)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)&&(CMPS11_Angle<85)){mode_scan_K5=MODE_SCAN_K5_RIGHT;break;}//samping kanan

				if((VL_SENSOR[0]<190)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<230))){break;}//pas

				if(((VL_SENSOR[0]<300)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)){mode_scan_K5=MODE_SCAN_K5_LEFT;break;}//samping kiri
			}

			//SIKLUS6
			Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[2]-NCURVE[2]),(FEMUR_O[0]),(NTIBIA_O[2]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[2]),(FEMUR_O[0]),(X_STATIC_IK_S[2]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[2]-NCURVE[2]),(FEMUR_O[0]),(TIBIA_O_R[2]));

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[2]),(Z_STATIC_IK_S[0]),(TIBIA_O[2]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[2]-CURVE[2]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[2]),(Z_STATIC_IK_S[4]),(NTIBIA_O_R[2]));
			Start_Pose_SYNC();
			delay_ms(SPEED+4);

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[1]-NCURVE[1]),(FEMUR_O[1]),(NTIBIA_O[1]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[1]),(FEMUR_O[1]),(X_STATIC_IK_S[2]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[1]-NCURVE[1]),(FEMUR_O[1]),(TIBIA_O_R[1]));

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[1]),(Z_STATIC_IK_S[0]),(TIBIA_O[1]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[1]-CURVE[1]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[1]),(Z_STATIC_IK_S[4]),(NTIBIA_O_R[1]));
			Start_Pose_SYNC();
			delay_ms(SPEED+4);

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[0]-NCURVE[0]),(FEMUR_O[2]),(NTIBIA_O[0]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[0]),(FEMUR_O[2]),(X_STATIC_IK_S[2]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[0]-NCURVE[0]),(FEMUR_O[2]),(TIBIA_O_R[0]));

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[0]),(Z_STATIC_IK_S[0]),(TIBIA_O[0]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[0]-CURVE[0]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[0]),(Z_STATIC_IK_S[4]),(NTIBIA_O_R[0]));
			Start_Pose_SYNC();
			delay_ms(SPEED+4);

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[1]),(FEMUR_O[3]),(X_STATIC_IK_S[1]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(FEMUR_O[3]),(X_STATIC_IK_S[2]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK_S[5]),(FEMUR_O[3]),(X_STATIC_IK_S[5]));

			Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK_S[0]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
			Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
			Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK_S[4]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
			Start_Pose_SYNC();
			delay_ms(SPEED+4);

//			if(CAT_DETECTOR==CAT_ACTIVATED)
//			{
//				Cat_Avoider();
//				if(CAT_FLAG ==CAT_DETECTED)break;
//			}
//			if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//			{
//				Stairs_Detector();
//				if(STAIRS_FLAG == STAIRS_DETECTED)break;
//			}
//
//			if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
//
//			if(FOLLOW_TRACER_STATE == 1)
//			{
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//			}
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//			if(FOLLOW_CARPET_MODE == NORMAL)
//			{
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//			}
//			else if(FOLLOW_CARPET_MODE == INVERSE)
//			{
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//			}
//			if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

			if(mode_korban==MODE_K5)
			{
				GetCMPS11_Angle8Bit();
				if(((VL_SENSOR[0]<340)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)&&(CMPS11_Angle<85)){mode_scan_K5=MODE_SCAN_K5_RIGHT;break;}//samping kanan

				if((VL_SENSOR[0]<190)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<230))){break;}//pas

				if(((VL_SENSOR[0]<300)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)){mode_scan_K5=MODE_SCAN_K5_LEFT;break;}//samping kiri
			}
		}
		CURVE_RIGHT_STAT = 0;
}

void Dynamx_MoveCurveLeft_Obstaicle(int SPEED,int limit,volatile float *ACTUATE_SIGNAL)
{
	CURVE_LEFT_STAT = 1;
	int loop;
	int MAX_SIGNAL = 15;

	if(IK_CALCULATED_CRV_L_OBS == 0)
	{
		Generate_Body(0,1.8);
		Trajectory_Generator_Obs(X_Diff, Y_Diff, -3.75, 4,MOVEMENT_NORMAL);
		for(i=0;i<=3;i++)
		{
			if(mode_follow==MODE_FOLLOW_R6)
			{
				Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_STAIRS[1]+Z_IK[i]));
				FEMUR_O[i] = tetha.Femur;
				COXA_O[i] = tetha.Coxa;
				NFEMUR_O[i] = (tetha.Femur*-1);
				NCOXA_O[i] = (tetha.Coxa*-1);

				Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_STAIRS[1]));
				TIBIA_O[i] = tetha.Tibia;

				Dyna_IKCalc_Only((X_IK_OBS[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_STAIRS[1]));
				NTIBIA_O[i] = tetha.Tibia;
				NTIBIA_O_R[i] = tetha.Tibia;

				Dyna_IKCalc_Only((X_IK_OBS[0]+X2_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_STAIRS[1]));
				TIBIA_O_R[i] = tetha.Tibia;
			}
			else
			{
				Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_OBS[1]+Z_IK[i]));
				FEMUR_O[i] = tetha.Femur;
				COXA_O[i] = tetha.Coxa;
				NFEMUR_O[i] = (tetha.Femur*-1);
				NCOXA_O[i] = (tetha.Coxa*-1);

				Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_OBS[1]));
				TIBIA_O[i] = tetha.Tibia;

				Dyna_IKCalc_Only((X_IK_OBS[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_OBS[1]));
				NTIBIA_O[i] = tetha.Tibia;
				NTIBIA_O_R[i] = tetha.Tibia;

				Dyna_IKCalc_Only((X_IK_OBS[0]+X2_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_OBS[1]));
				TIBIA_O_R[i] = tetha.Tibia;
			}
		}
		IK_CALCULATED_CRV_L_OBS = 1;
		IK_CALCULATED_CRV_R_OBS = 0;
	}

	SPEED = SPEED/45;

	int a = 0;
	int b = 0, c = 0;

	float signal=*ACTUATE_SIGNAL/3;
	float error_L;//femur_L,tibia_L;
	float error_R;//femur_R,tibia_R;
	float error_R2;

	if (signal>=MAX_SIGNAL){error_R=MAX_SIGNAL;error_R2=MAX_SIGNAL;}
	else {error_R=signal;error_R2=signal;}

	float DELTA_R= (1 * error_R);
	float DELTA_R2 = (1 * error_R2);

	int LEFT_EXT1 = 0;
	int LEFT_EXT2 = 0;

	int CURVE[6];
	int NCURVE[6];

	CURVE[0] = (int)((DELTA_R*(float)COXA_O[0])/((float)(MAX_SIGNAL)));
	CURVE[1] = (int)((DELTA_R*(float)COXA_O[1])/((float)(MAX_SIGNAL)));
	CURVE[2] = (int)((DELTA_R*(float)COXA_O[2])/((float)(MAX_SIGNAL)));
	CURVE[3] = (int)((DELTA_R*(float)COXA_O[3])/((float)(MAX_SIGNAL)));
	CURVE[4] = (int)((DELTA_R*(float)COXA_O[4])/((float)(MAX_SIGNAL)));
	CURVE[5] = (int)((DELTA_R*(float)COXA_O[5])/((float)(MAX_SIGNAL)));

	NCURVE[0] = (int)((DELTA_R2*(float)NCOXA_O[0])/((float)(MAX_SIGNAL)));
	NCURVE[1] = (int)((DELTA_R2*(float)NCOXA_O[1])/((float)(MAX_SIGNAL)));
	NCURVE[2] = (int)((DELTA_R2*(float)NCOXA_O[2])/((float)(MAX_SIGNAL)));
	NCURVE[3] = (int)((DELTA_R2*(float)NCOXA_O[3])/((float)(MAX_SIGNAL)));
	NCURVE[4] = (int)((DELTA_R2*(float)NCOXA_O[4])/((float)(MAX_SIGNAL)));
	NCURVE[5] = (int)((DELTA_R2*(float)NCOXA_O[5])/((float)(MAX_SIGNAL)));


	int n;
	for(n=0;n<=5;n++)
	{
		NCURVE[i] = (NCURVE[i]*-1);
	}
	for(loop=1;loop<=limit;loop++)
	{
//		if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//		{
//			Stairs_Detector();
//			if(STAIRS_FLAG == STAIRS_DETECTED)break;
//		}
//
//		if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
//		if(FOLLOW_TRACER_STATE == 1)
//		{
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//		}
//
//		TCS3200_Transmit(UART5, CMD_GET_TRACER);
//		if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//		TCS3200_Transmit(UART5, CMD_GET_TRACER);
//		if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//		if(FOLLOW_CARPET_MODE == NORMAL)
//		{
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//		}
//		else if(FOLLOW_CARPET_MODE == INVERSE)
//		{
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//		}
//		if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

		if(mode_korban==MODE_K5)
		{
			GetCMPS11_Angle8Bit();
			if(((VL_SENSOR[0]<340)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)&&(CMPS11_Angle<85)){mode_scan_K5=MODE_SCAN_K5_RIGHT;break;}//samping kanan

			if((VL_SENSOR[0]<190)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<230))){break;}//pas

			if(((VL_SENSOR[0]<300)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)){mode_scan_K5=MODE_SCAN_K5_LEFT;break;}//samping kiri
		}

		//SIKLUS1
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[0]),(FEMUR_O[3]),(TIBIA_O[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[0]-CURVE[0]),(FEMUR_O[3]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[0]),(FEMUR_O[3]),(NTIBIA_O_R[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[0]-NCURVE[0]),(Z_STATIC_IK_S[0]),(NTIBIA_O[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[0]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[0]-NCURVE[0]),(Z_STATIC_IK_S[4]),(TIBIA_O_R[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[1]),(FEMUR_O[2]),(TIBIA_O[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[1]-CURVE[1]),(FEMUR_O[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[1]),(FEMUR_O[2]),(NTIBIA_O_R[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[1]-NCURVE[1]),(Z_STATIC_IK_S[0]),(NTIBIA_O[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[1]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[1]-NCURVE[1]),(Z_STATIC_IK_S[4]),(TIBIA_O_R[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[2]),(FEMUR_O[1]),(TIBIA_O[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[2]-CURVE[2]),(FEMUR_O[1]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[2]),(FEMUR_O[1]),(NTIBIA_O_R[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[2]-NCURVE[2]),(Z_STATIC_IK_S[0]),(NTIBIA_O[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[2]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[2]-NCURVE[2]),(Z_STATIC_IK_S[4]),(TIBIA_O_R[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[3]),(FEMUR_O[0]),(TIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[3]-CURVE[3]),(FEMUR_O[0]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[3]),(FEMUR_O[0]),(NTIBIA_O_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[3]-NCURVE[3]),(Z_STATIC_IK_S[0]),(NTIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[3]-NCURVE[3]),(Z_STATIC_IK_S[4]),(TIBIA_O_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

//		if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//		{
//			Stairs_Detector();
//			if(STAIRS_FLAG == STAIRS_DETECTED)break;
//		}
//
//		if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
//
//		if(FOLLOW_TRACER_STATE == 1)
//		{
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//		}
//
//		TCS3200_Transmit(UART5, CMD_GET_TRACER);
//		if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//		TCS3200_Transmit(UART5, CMD_GET_TRACER);
//		if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//		if(FOLLOW_CARPET_MODE == NORMAL)
//		{
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//		}
//		else if(FOLLOW_CARPET_MODE == INVERSE)
//		{
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//		}
//
//		if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

		if(mode_korban==MODE_K5)
		{
			GetCMPS11_Angle8Bit();
			if(((VL_SENSOR[0]<340)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)&&(CMPS11_Angle<85)){mode_scan_K5=MODE_SCAN_K5_RIGHT;break;}//samping kanan

			if((VL_SENSOR[0]<190)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<230))){break;}//pas

			if(((VL_SENSOR[0]<300)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)){mode_scan_K5=MODE_SCAN_K5_LEFT;break;}//samping kiri
		}

		//SIKLUS 2
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[1]),(TIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[3]-CURVE[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[5]),(NTIBIA_O_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[3]-NCURVE[3]),(Z_STATIC_IK_S[0]),(NTIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[3]-NCURVE[3]),(Z_STATIC_IK_S[4]),(TIBIA_O_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[1]),(TIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[3]-CURVE[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[5]),(NTIBIA_O_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[3]-NCURVE[3]),(Z_STATIC_IK_S[0]),(NTIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[3]-NCURVE[3]),(Z_STATIC_IK_S[4]),(TIBIA_O_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[1]),(TIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[3]-CURVE[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[5]),(NTIBIA_O_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[3]-NCURVE[3]),(Z_STATIC_IK_S[0]),(NTIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[3]-NCURVE[3]),(Z_STATIC_IK_S[4]),(TIBIA_O_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[1]),(TIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[3]-CURVE[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[5]),(NTIBIA_O_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[3]-NCURVE[3]),(Z_STATIC_IK_S[0]),(NTIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[3]-NCURVE[3]),(Z_STATIC_IK_S[4]),(TIBIA_O_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

//		if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//		{
//			Stairs_Detector();
//			if(STAIRS_FLAG == STAIRS_DETECTED)break;
//		}
//
//		if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
//
//		if(FOLLOW_TRACER_STATE == 1)
//		{
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//		}
//
//		TCS3200_Transmit(UART5, CMD_GET_TRACER);
//		if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//		TCS3200_Transmit(UART5, CMD_GET_TRACER);
//		if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//		if(FOLLOW_CARPET_MODE == NORMAL)
//		{
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//		}
//		else if(FOLLOW_CARPET_MODE == INVERSE)
//		{
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//		}
//		if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

		if(mode_korban==MODE_K5)
		{
			GetCMPS11_Angle8Bit();
			if(((VL_SENSOR[0]<340)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)&&(CMPS11_Angle<85)){mode_scan_K5=MODE_SCAN_K5_RIGHT;break;}//samping kanan

			if((VL_SENSOR[0]<190)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<230))){break;}//pas

			if(((VL_SENSOR[0]<300)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)){mode_scan_K5=MODE_SCAN_K5_LEFT;break;}//samping kiri
		}

		//SIKLUS 3
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[2]),(Z_STATIC_IK_S[1]),(TIBIA_O[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[2]-CURVE[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[2]),(Z_STATIC_IK_S[5]),(NTIBIA_O_R[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[2]-NCURVE[2]),(FEMUR_O[0]),(NTIBIA_O[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[2]),(FEMUR_O[0]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[2]-NCURVE[2]),(FEMUR_O[0]),(TIBIA_O_R[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[1]),(Z_STATIC_IK_S[1]),(TIBIA_O[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[1]-CURVE[1]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[1]),(Z_STATIC_IK_S[5]),(NTIBIA_O_R[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[1]-NCURVE[1]),(FEMUR_O[1]),(NTIBIA_O[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[1]),(FEMUR_O[1]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[1]-NCURVE[1]),(FEMUR_O[1]),(TIBIA_O_R[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[0]),(Z_STATIC_IK_S[1]),(TIBIA_O[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[0]-CURVE[0]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[0]),(Z_STATIC_IK_S[5]),(NTIBIA_O_R[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[0]-NCURVE[0]),(FEMUR_O[2]),(NTIBIA_O[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[0]),(FEMUR_O[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[0]-NCURVE[0]),(FEMUR_O[2]),(TIBIA_O_R[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[1]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK_S[5]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK_S[0]),(FEMUR_O[3]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(FEMUR_O[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK_S[4]),(FEMUR_O[3]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

//		if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//		{
//			Stairs_Detector();
//			if(STAIRS_FLAG == STAIRS_DETECTED)break;
//		}
//
//		if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
//
//		if(FOLLOW_TRACER_STATE == 1)
//		{
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//		}
//		TCS3200_Transmit(UART5, CMD_GET_TRACER);
//		if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//		TCS3200_Transmit(UART5, CMD_GET_TRACER);
//		if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//		if(FOLLOW_CARPET_MODE == NORMAL)
//		{
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//		}
//		else if(FOLLOW_CARPET_MODE == INVERSE)
//		{
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//		}
//		if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

		if(mode_korban==MODE_K5)
		{
			GetCMPS11_Angle8Bit();
			if(((VL_SENSOR[0]<340)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)&&(CMPS11_Angle<85)){mode_scan_K5=MODE_SCAN_K5_RIGHT;break;}//samping kanan

			if((VL_SENSOR[0]<190)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<230))){break;}//pas

			if(((VL_SENSOR[0]<300)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)){mode_scan_K5=MODE_SCAN_K5_LEFT;break;}//samping kiri
		}

		//SIKLUS 4
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[0]),(Z_STATIC_IK_S[1]),(NTIBIA_O[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[0]-NCURVE[0]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[0]),(Z_STATIC_IK_S[5]),(TIBIA_O_R[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[0]-CURVE[0]),(FEMUR_O[3]),(TIBIA_O[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[0]),(FEMUR_O[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[0]-CURVE[0]),(FEMUR_O[3]),(NTIBIA_O_R[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[1]),(Z_STATIC_IK_S[1]),(NTIBIA_O[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[1]-NCURVE[1]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[1]),(Z_STATIC_IK_S[5]),(TIBIA_O_R[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[1]-CURVE[1]),(FEMUR_O[2]),(TIBIA_O[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[1]),(FEMUR_O[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[1]-CURVE[1]),(FEMUR_O[2]),(NTIBIA_O_R[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[2]),(Z_STATIC_IK_S[1]),(NTIBIA_O[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[2]-NCURVE[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[2]),(Z_STATIC_IK_S[5]),(TIBIA_O_R[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[2]-CURVE[2]),(FEMUR_O[1]),(TIBIA_O[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[2]),(FEMUR_O[1]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[2]-CURVE[2]),(FEMUR_O[1]),(NTIBIA_O_R[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[1]),(NTIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[3]-NCURVE[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[5]),(TIBIA_O_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[3]-CURVE[3]),(FEMUR_O[0]),(TIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[3]),(FEMUR_O[0]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[3]-CURVE[3]),(FEMUR_O[0]),(NTIBIA_O_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

//		if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//		{
//			Stairs_Detector();
//			if(STAIRS_FLAG == STAIRS_DETECTED)break;
//		}
//
//		if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
//
//		if(FOLLOW_TRACER_STATE == 1)
//		{
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//		}
//
//		TCS3200_Transmit(UART5, CMD_GET_TRACER);
//		if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//		TCS3200_Transmit(UART5, CMD_GET_TRACER);
//		if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//		if(FOLLOW_CARPET_MODE == NORMAL)
//		{
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//		}
//		else if(FOLLOW_CARPET_MODE == INVERSE)
//		{
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//		}
//
//		if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

		if(mode_korban==MODE_K5)
		{
			GetCMPS11_Angle8Bit();
			if(((VL_SENSOR[0]<340)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)&&(CMPS11_Angle<85)){mode_scan_K5=MODE_SCAN_K5_RIGHT;break;}//samping kanan

			if((VL_SENSOR[0]<190)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<230))){break;}//pas

			if(((VL_SENSOR[0]<300)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)){mode_scan_K5=MODE_SCAN_K5_LEFT;break;}//samping kiri
		}

		//SIKLUS 5
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[1]),(NTIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[3]-NCURVE[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[5]),(TIBIA_O_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[3]-CURVE[3]),(Z_STATIC_IK_S[0]),(TIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[3]-CURVE[3]),(Z_STATIC_IK_S[4]),(NTIBIA_O_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[1]),(NTIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[3]-NCURVE[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[5]),(TIBIA_O_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[3]-CURVE[3]),(Z_STATIC_IK_S[0]),(TIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[3]-CURVE[3]),(Z_STATIC_IK_S[4]),(NTIBIA_O_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[1]),(NTIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[3]-NCURVE[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[5]),(TIBIA_O_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[3]-CURVE[3]),(Z_STATIC_IK_S[0]),(TIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[3]-CURVE[3]),(Z_STATIC_IK_S[4]),(NTIBIA_O_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[1]),(NTIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[3]-NCURVE[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[5]),(TIBIA_O_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[3]-CURVE[3]),(Z_STATIC_IK_S[0]),(TIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[3]-CURVE[3]),(Z_STATIC_IK_S[4]),(NTIBIA_O_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

//		if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//		{
//			Stairs_Detector();
//			if(STAIRS_FLAG == STAIRS_DETECTED)break;
//		}
//
//		if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
//
//		if(FOLLOW_TRACER_STATE == 1)
//		{
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//		}
//
//		TCS3200_Transmit(UART5, CMD_GET_TRACER);
//		if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//		TCS3200_Transmit(UART5, CMD_GET_TRACER);
//		if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//		if(FOLLOW_CARPET_MODE == NORMAL)
//		{
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//		}
//		else if(FOLLOW_CARPET_MODE == INVERSE)
//		{
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//		}
//		if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

		if(mode_korban==MODE_K5)
		{
			GetCMPS11_Angle8Bit();
			if(((VL_SENSOR[0]<340)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)&&(CMPS11_Angle<85)){mode_scan_K5=MODE_SCAN_K5_RIGHT;break;}//samping kanan

			if((VL_SENSOR[0]<190)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<230))){break;}//pas

			if(((VL_SENSOR[0]<300)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)){mode_scan_K5=MODE_SCAN_K5_LEFT;break;}//samping kiri
		}

		//SIKLUS6
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[2]),(FEMUR_O[0]),(NTIBIA_O[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[2]-NCURVE[2]),(FEMUR_O[0]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[2]),(FEMUR_O[0]),(TIBIA_O_R[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[2]-CURVE[2]),(Z_STATIC_IK_S[0]),(TIBIA_O[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[2]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[2]-CURVE[2]),(Z_STATIC_IK_S[4]),(NTIBIA_O_R[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[1]),(FEMUR_O[1]),(NTIBIA_O[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[1]-NCURVE[1]),(FEMUR_O[1]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[1]),(FEMUR_O[1]),(TIBIA_O_R[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[1]-CURVE[1]),(Z_STATIC_IK_S[0]),(TIBIA_O[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[1]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[1]-CURVE[1]),(Z_STATIC_IK_S[4]),(NTIBIA_O_R[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[0]),(FEMUR_O[2]),(NTIBIA_O[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[0]-NCURVE[0]),(FEMUR_O[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[0]),(FEMUR_O[2]),(TIBIA_O_R[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[0]-CURVE[0]),(Z_STATIC_IK_S[0]),(TIBIA_O[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[0]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[0]-CURVE[0]),(Z_STATIC_IK_S[4]),(NTIBIA_O_R[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[1]),(FEMUR_O[3]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(FEMUR_O[3]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK_S[5]),(FEMUR_O[3]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK_S[0]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK_S[4]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

//		if(CAT_DETECTOR==CAT_ACTIVATED)
//		{
//			Cat_Avoider();
//			if(CAT_FLAG ==CAT_DETECTED)break;
//		}
//		if(CAT_DETECTOR==CAT_ACTIVATED)
//		{
//			Cat_Avoider();
//			if(CAT_FLAG ==CAT_DETECTED)break;
//		}
//		if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//		{
//			Stairs_Detector();
//			if(STAIRS_FLAG == STAIRS_DETECTED)break;
//		}
//
//		if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
//		if(FOLLOW_TRACER_STATE == 1)
//		{
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//		}
//		if(FOLLOW_TRACER_STATE == 1)
//		{
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//		}
//		TCS3200_Transmit(UART5, CMD_GET_TRACER);
//		if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//		TCS3200_Transmit(UART5, CMD_GET_TRACER);
//		if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//		if(FOLLOW_CARPET_MODE == NORMAL)
//		{
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//		}
//		else if(FOLLOW_CARPET_MODE == INVERSE)
//		{
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//		}
//		if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

		if(mode_korban==MODE_K5)
		{
			GetCMPS11_Angle8Bit();
			if(((VL_SENSOR[0]<340)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)&&(CMPS11_Angle<85)){mode_scan_K5=MODE_SCAN_K5_RIGHT;break;}//samping kanan

			if((VL_SENSOR[0]<190)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<230))){break;}//pas

			if(((VL_SENSOR[0]<300)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)){mode_scan_K5=MODE_SCAN_K5_LEFT;break;}//samping kiri
		}
	}
	CURVE_LEFT_STAT = 0;
}


void Dynamx_Mov_Climbing_Interpolate(int SPEED, int limit, int movement)
{
	int cek_siklus = 1;
	int cek_value = 0;
	Generate_Body(0,1.5);
	Trajectory_Generator_Climbing(X_Diff, Y_Diff, -3.75, 4,MOVEMENT_NORMAL);
	SPEED = SPEED/33;

	switch (movement)
	{
		case 0:
		{
			for (int j=0; j<6; j++)
			{
				Z_IK_S_BUFF[j] = Z_IK_STAIRS[j];
			}

		}break;

		case 1:
		{
			for (int j=0; j<6; j++)
			{
				if ((j == 4) || (j == 5))//belakang
				{
					Z_IK_S_BUFF[j] = Z_IK_STAIRS[j];
				}

				else if ((j == 2) || (j == 3))//tengah
				{
					Z_IK_S_BUFF[j] = Z_IK_STAIRS[j];
				}

				else//depan
				{
					Z_IK_S_BUFF[j] = Z_IK_STAIRS[j];
				}
			}

		}break;

		case 2:
		{
			for (int j=0; j<6; j++)
			{
				if ((j == 4) || (j == 5))//belakang
				{
					Z_IK_S_BUFF[j] = Z_IK_STAIRS[j]+3.75;
				}

				else if ((j == 2) || (j == 3))//tengah
				{
					Z_IK_S_BUFF[j] = Z_IK_STAIRS[j]+0.25;
				}

				else//depan
				{
					Z_IK_S_BUFF[j] = Z_IK_STAIRS[j]-2.75;
				}
			}
		}break;

		case 3:
		{
			for (int j=0; j<6; j++)
			{
				if ((j == 4) || (j == 5))//belakang
				{
					Z_IK_S_BUFF[j] = Z_IK_STAIRS[j];
				}

				else if ((j == 2) || (j == 3))//tengah
				{
					Z_IK_S_BUFF[j] = Z_IK_STAIRS[j];
				}

				else//depan
				{
					Z_IK_S_BUFF[j] = Z_IK_STAIRS[j];
				}
			}
		}break;
	}

	if (STATIC_CLIMBING == 0)
	{
		Dyna_IKCalc_Only_Static_Climbing(FRONT_RIGHT_DX,   X_IK_OBS[1], Y_IK_BEGIN[1],Z_IK_S_BUFF[1], &SPEED);
		Dyna_IKCalc_Only_Static_Climbing(MIDDLE_LEFT_DX,   X_IK_OBS[2], Y_IK_BEGIN[2],Z_IK_S_BUFF[2], &SPEED);
		Dyna_IKCalc_Only_Static_Climbing(REAR_RIGHT_DX,    X_IK_OBS[5], Y_IK_BEGIN[5],Z_IK_S_BUFF[5], &SPEED);

		Dyna_IKCalc_Only_Static_Climbing(FRONT_LEFT_DX,    X_IK_OBS[0], Y_IK_BEGIN[0],Z_IK_S_BUFF[0], &SPEED);
		Dyna_IKCalc_Only_Static_Climbing(MIDDLE_RIGHT_DX,  X_IK_OBS[3], Y_IK_BEGIN[3],Z_IK_S_BUFF[3], &SPEED);
		Dyna_IKCalc_Only_Static_Climbing(REAR_LEFT_DX,     X_IK_OBS[4], Y_IK_BEGIN[4],Z_IK_S_BUFF[4], &SPEED);
		Start_Pose_SYNC();
		delay_ms(SPEED);

		if(cek_siklus==1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"STATIC CLIMB");lcd_putstr(lcd);
				if(BW_BUTTON_CLICKED)break;
			}
		}
		STATIC_CLIMBING = 1;
	}

	for(i=0;i<=3;i++)
	{
		Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[1]+Z_IK[i]));
		FEMUR_S_F[i] = tetha.Femur;
		NFEMUR_S_F[i] = (tetha.Femur*-1);

		Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[2]+Z_IK[i]));
		FEMUR_S_M[i] = tetha.Femur;
		NFEMUR_S_M[i] = (tetha.Femur*-1);

		Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[5]+Z_IK[i]));
		FEMUR_S_R[i] = tetha.Femur;
		NFEMUR_S_R[i] = (tetha.Femur*-1);

		Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_STAIRS[1]+Z_IK[i]));
		COXA_S[i] = tetha.Coxa;
		NCOXA_S[i] = (tetha.Coxa*-1);

//		Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_STAIRS[1]));
		Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[1]));
		TIBIA_S[i] = tetha.Tibia;

//		Dyna_IKCalc_Only((X_IK_OBS[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_STAIRS[1]));
		Dyna_IKCalc_Only((X_IK_OBS[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[1]));
		NTIBIA_S[i] = tetha.Tibia;

		Dyna_IKCalc_Only((X_IK_OBS[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[4]));
		NTIBIA_S_R[i] = tetha.Tibia;

		Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[5]));
		TIBIA_S_R[i] = tetha.Tibia;
	}

	if(cek_value==1)
	{
		while(1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"STATIC IK S");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"%d|%d|%d",X_STATIC_IK_S[0],X_STATIC_IK_S[2],X_STATIC_IK_S[4]);lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d",Y_STATIC_IK_S[0],Y_STATIC_IK_S[2],Y_STATIC_IK_S[4]);lcd_putstr(lcd);
				lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d",Z_STATIC_IK_S[0],Z_STATIC_IK_S[2],Z_STATIC_IK_S[4]);lcd_putstr(lcd);
				delay_ms(100);
				if(BW_BUTTON_CLICKED)break;
			}

			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"COXA TIBIA|R");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"%d|%d|%d|%d",COXA_S[0],COXA_S[1],COXA_S[2],COXA_S[3]);lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d|%d",TIBIA_S[0],TIBIA_S[1],TIBIA_S[2],TIBIA_S[3]);lcd_putstr(lcd);
				lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d|%d",TIBIA_S_R[0],TIBIA_S_R[1],TIBIA_S_R[2],TIBIA_S_R[3]);lcd_putstr(lcd);
				delay_ms(100);
				if(BW_BUTTON_CLICKED)break;
			}

			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FEMUR");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"%d|%d|%d|%d",FEMUR_S_F[0],FEMUR_S_F[1],FEMUR_S_F[2],FEMUR_S_F[3]);lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d|%d",FEMUR_S_M[0],FEMUR_S_M[1],FEMUR_S_M[2],FEMUR_S_M[3]);lcd_putstr(lcd);
				lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d|%d",FEMUR_S_R[0],FEMUR_S_R[1],FEMUR_S_R[2],FEMUR_S_R[3]);lcd_putstr(lcd);
				delay_ms(100);
				if(BW_BUTTON_CLICKED)break;
			}
		}
	}

	for (int i =0; i<limit; i++)
	{
		//SIKLUS 1
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[0]),(FEMUR_S_F[3]),(TIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[0]),(FEMUR_S_M[3]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[0]),(FEMUR_S_R[3]),(NTIBIA_S_R[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[0]),(Z_STATIC_IK_S[0]),(NTIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[0]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[0]),(Z_STATIC_IK_S[4]),(TIBIA_S_R[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[1]),(FEMUR_S_F[2]),(TIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[1]),(FEMUR_S_M[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[1]),(FEMUR_S_R[2]),(NTIBIA_S_R[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[1]),(Z_STATIC_IK_S[0]),(NTIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[1]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[1]),(Z_STATIC_IK_S[4]),(TIBIA_S_R[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[2]),(FEMUR_S_F[1]),(TIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[2]),(FEMUR_S_M[1]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[2]),(FEMUR_S_R[1]),(NTIBIA_S_R[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[2]),(Z_STATIC_IK_S[0]),(NTIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[2]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[2]),(Z_STATIC_IK_S[4]),(TIBIA_S_R[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[3]),(FEMUR_S_F[0]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[3]),(FEMUR_S_M[0]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[3]),(FEMUR_S_R[0]),(NTIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[0]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[4]),(TIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 1");lcd_putstr(lcd);
				if(BW_BUTTON_CLICKED)break;
			}

			lcd_display_clear();

		}

		//SIKLUS 2
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[1]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[0]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[4]),(TIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[1]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[0]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[4]),(TIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[1]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[0]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[4]),(TIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[1]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[0]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[4]),(TIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 2");lcd_putstr(lcd);
				if(BW_BUTTON_CLICKED)break;
			}

			lcd_display_clear();

		}



		//SIKLUS 3
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[2]),(Z_STATIC_IK_S[1]),(TIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[2]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[2]),(FEMUR_S_F[0]),(NTIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[2]),(FEMUR_S_M[0]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[2]),(FEMUR_S_R[0]),(TIBIA_S_R[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);


		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[1]),(Z_STATIC_IK_S[1]),(TIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[1]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[1]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[1]),(FEMUR_S_F[1]),(NTIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[1]),(FEMUR_S_M[1]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[1]),(FEMUR_S_R[1]),(TIBIA_S_R[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[0]),(Z_STATIC_IK_S[1]),(TIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[0]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[0]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[0]),(FEMUR_S_F[2]),(NTIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[0]),(FEMUR_S_M[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[0]),(FEMUR_S_R[2]),(TIBIA_S_R[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[1]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK_S[5]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK_S[0]),(FEMUR_S_F[3]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(FEMUR_S_M[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK_S[4]),(FEMUR_S_R[3]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 3");lcd_putstr(lcd);
				if(BW_BUTTON_CLICKED)break;
			}

			lcd_display_clear();

		}


		//SIKLUS 4
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[0]),(Z_STATIC_IK_S[1]),(NTIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[0]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[0]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[0]),(FEMUR_S_F[3]),(TIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[0]),(FEMUR_S_M[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[0]),(FEMUR_S_R[3]),(NTIBIA_S_R[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[1]),(Z_STATIC_IK_S[1]),(NTIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[1]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[1]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[1]),(FEMUR_S_F[2]),(TIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[1]),(FEMUR_S_M[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[1]),(FEMUR_S_R[2]),(NTIBIA_S_R[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[2]),(Z_STATIC_IK_S[1]),(NTIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[2]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[2]),(FEMUR_S_F[1]),(TIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[2]),(FEMUR_S_M[1]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[2]),(FEMUR_S_R[1]),(NTIBIA_S_R[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[1]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[3]),(FEMUR_S_F[0]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[3]),(FEMUR_S_M[0]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[3]),(FEMUR_S_R[0]),(NTIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 4");lcd_putstr(lcd);
				if(BW_BUTTON_CLICKED)break;
			}

			lcd_display_clear();

		}



		//SIKLUS 5
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[1]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[0]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[1]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[0]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[1]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[0]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[1]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[0]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 5");lcd_putstr(lcd);
				if(BW_BUTTON_CLICKED)break;
			}

			lcd_display_clear();

		}



		//SIKLUS 6
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[2]),(FEMUR_S_F[0]),(NTIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[2]),(FEMUR_S_M[0]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[2]),(FEMUR_S_R[0]),(TIBIA_S_R[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[2]),(Z_STATIC_IK_S[0]),(TIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[2]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[2]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[1]),(FEMUR_S_F[1]),(NTIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[1]),(FEMUR_S_M[1]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[1]),(FEMUR_S_R[1]),(TIBIA_S_R[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[1]),(Z_STATIC_IK_S[0]),(TIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[1]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[1]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[0]),(FEMUR_S_F[2]),(NTIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[0]),(FEMUR_S_M[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[0]),(FEMUR_S_R[2]),(TIBIA_S_R[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[0]),(Z_STATIC_IK_S[0]),(TIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[0]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[0]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[1]),(FEMUR_S_F[3]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(FEMUR_S_M[3]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK_S[5]),(FEMUR_S_R[3]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK_S[0]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK_S[4]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 6");lcd_putstr(lcd);
				if(BW_BUTTON_CLICKED)break;
			}
			lcd_display_clear();

		}


	}

}

void Dynamx_MovSlope_Interpolate(int distance, int SPEED, int IKCALC_STAT)
{
	int limit = distance/4;
	int loop;

	if(IKCALC_STAT == IKCALC_ENABLE)
	{
		if(IK_CALCULATED_SLP == 0)
		{
			Generate_Body(0,-1);
			Trajectory_Generator_NEW(X_Diff, Y_Diff, -2, 4, MOVEMENT_NORMAL);
			for(i=0;i<=3;i++)
			{
				Dyna_IKCalc_Only((X_IK_BEGIN[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[i]+Z_IK[i]));
				FEMUR_SLP[i] = tetha.Femur;

				Dyna_IKCalc_Only((X_IK_BEGIN[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[i]));

				Dyna_IKCalc_Only((X_IK_BEGIN[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[i]));



			}
		}
	}
}


void Dynamx_MovFwd_Obstaicle_Interpolate(int SPEED, int limit)
{
	int cek_value = 0;
	int cek_siklus = 0;
	if(IK_CALCULATED_FWD_OBS == 0)
	{

		Generate_Body(0,1.8);
		Trajectory_Generator_Obs(X_Diff, Y_Diff, -3.75, 4,MOVEMENT_NORMAL);
		for(i=0;i<=3;i++)
		{
			if(mode_follow==MODE_FOLLOW_R6)
			{
				Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_STAIRS[1]+Z_IK[i]));
				FEMUR_O[i] = tetha.Femur;
				COXA_O[i] = tetha.Coxa;
				NFEMUR_O[i] = (tetha.Femur*-1);
				NCOXA_O[i] = (tetha.Coxa*-1);

				Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_STAIRS[1]));
				TIBIA_O[i] = tetha.Tibia;

				Dyna_IKCalc_Only((X_IK_OBS[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_STAIRS[1]));
				NTIBIA_O[i] = tetha.Tibia;
				NTIBIA_O_R[i] = tetha.Tibia;

				Dyna_IKCalc_Only((X_IK_OBS[0]+X2_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_STAIRS[1]));
				TIBIA_O_R[i] = tetha.Tibia;
			}
			else
			{
				Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_OBS[1]+Z_IK[i]));
				FEMUR_O[i] = tetha.Femur;
				COXA_O[i] = tetha.Coxa;
				NFEMUR_O[i] = (tetha.Femur*-1);
				NCOXA_O[i] = (tetha.Coxa*-1);

				Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_OBS[1]));
				TIBIA_O[i] = tetha.Tibia;

				Dyna_IKCalc_Only((X_IK_OBS[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_OBS[1]));
				NTIBIA_O[i] = tetha.Tibia;
				NTIBIA_O_R[i] = tetha.Tibia;

				Dyna_IKCalc_Only((X_IK_OBS[0]+X2_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_OBS[1]));
				TIBIA_O_R[i] = tetha.Tibia;
			}
		}
		IK_CALCULATED_FWD_OBS = 1;
		IK_CALCULATED_BWD_OBS = 0;
	}

	SPEED = SPEED/45;

	if (cek_value==1)
	{
		lcd_display_clear();
//		lcd_gotoxy(0,0);sprintf(lcd,"COXA VALUE");lcd_putstr(lcd);
//		lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d|%d",COXA_A[0],COXA_A[1],COXA_A[2],COXA_A[3]);lcd_putstr(lcd);
//		lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d|%d",NCOXA_A[0],NCOXA_A[1],NCOXA_A[2],NCOXA_A[3]);lcd_putstr(lcd);

		lcd_gotoxy(0,0);sprintf(lcd,"FEMUR VALUE");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d",FEMUR_O[0],FEMUR_O[1],FEMUR_O[2]);lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d",FEMUR_O[3],FEMUR_O[4],FEMUR_O[5]);lcd_putstr(lcd);

//		lcd_gotoxy(0,0);sprintf(lcd,"FEMUR VALUE");lcd_putstr(lcd);
//		lcd_gotoxy(0,0);sprintf(lcd,"%d|%d|%d|%d",TIBIA_A[0],TIBIA_A[1],TIBIA_A[2],TIBIA_A[3]);lcd_putstr(lcd);
//		lcd_gotoxy(0,1);sprintf(lcd,"%d|%d|%d|%d",NTIBIA_A[0],NTIBIA_A[1],NTIBIA_A[2],NTIBIA_A[3]);lcd_putstr(lcd);
//		lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d|%d",TIBIA_A_R[0],TIBIA_A_R[1],TIBIA_A_R[2],TIBIA_A_R[3]);lcd_putstr(lcd);
//		lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d|%d",NTIBIA_A_R[0],NTIBIA_A_R[1],NTIBIA_A_R[2],NTIBIA_A_R[3]);lcd_putstr(lcd);

		while(1){}

	}

	for (int i =0; i<limit; i++)
	{
		if(mode_korban==MODE_K1)
		{
			if((VL_SENSOR[0]<100)&&(TCS34725_SLV_DATA[0]>=120)&&(SHARP_GRIPPER[0]<10))break;
		}
		if(mode_korban==MODE_K2)
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
			}
		}
		if(mode_korban==MODE_K5)
		{
			GetCMPS11_Angle8Bit();
			if(((VL_SENSOR[0]<340)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)&&(CMPS11_Angle<85)){mode_scan_K5=MODE_SCAN_K5_RIGHT;break;}//samping kanan

			if((VL_SENSOR[0]<190)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<230))){break;}//pas

			if(((VL_SENSOR[0]<300)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)){mode_scan_K5=MODE_SCAN_K5_LEFT;break;}//samping kiri
		}

		if(mode_korban==MODE_K2_Next)
		{
			if((VL_SENSOR[0]<200)&&((TCS34725_SLV_DATA[2]>190)&&(TCS34725_SLV_DATA[2]<240))){break;}
		}


		//SIKLUS 1
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[0]),(FEMUR_O[3]),(TIBIA_O[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[0]),(FEMUR_O[3]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[0]),(FEMUR_O[3]),(NTIBIA_O_R[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[0]),(Z_STATIC_IK_S[0]),(NTIBIA_O[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[0]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[0]),(Z_STATIC_IK_S[4]),(TIBIA_O_R[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[1]),(FEMUR_O[2]),(TIBIA_O[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[1]),(FEMUR_O[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[1]),(FEMUR_O[2]),(NTIBIA_O_R[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[1]),(Z_STATIC_IK_S[0]),(NTIBIA_O[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[1]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[1]),(Z_STATIC_IK_S[4]),(TIBIA_O_R[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[2]),(FEMUR_O[1]),(TIBIA_O[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[2]),(FEMUR_O[1]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[2]),(FEMUR_O[1]),(NTIBIA_O_R[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[2]),(Z_STATIC_IK_S[0]),(NTIBIA_O[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[2]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[2]),(Z_STATIC_IK_S[4]),(TIBIA_O_R[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[3]),(FEMUR_O[0]),(TIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[3]),(FEMUR_O[0]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[3]),(FEMUR_O[0]),(NTIBIA_O_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[0]),(NTIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[4]),(TIBIA_O_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 1");lcd_putstr(lcd);
			delay_ms(5000);
		}

		if(mode_korban==MODE_K1)
		{
			if((VL_SENSOR[0]<100)&&(TCS34725_SLV_DATA[0]>=120)&&(SHARP_GRIPPER[0]<10))break;
		}
		if(mode_korban==MODE_K2)
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
			}
		}
		if(mode_korban==MODE_K5)
		{
			GetCMPS11_Angle8Bit();
			if(((VL_SENSOR[0]<340)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)&&(CMPS11_Angle<85)){mode_scan_K5=MODE_SCAN_K5_RIGHT;break;}//samping kanan

			if((VL_SENSOR[0]<190)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<230))){break;}//pas

			if(((VL_SENSOR[0]<300)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)){mode_scan_K5=MODE_SCAN_K5_LEFT;break;}//samping kiri
		}
		if(mode_korban==MODE_K2_Next)
		{
			if((VL_SENSOR[0]<200)&&((TCS34725_SLV_DATA[2]>190)&&(TCS34725_SLV_DATA[2]<240))){break;}
		}

		//SIKLUS 2
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[1]),(TIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[5]),(NTIBIA_O_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[0]),(NTIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[4]),(TIBIA_O_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[1]),(TIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[5]),(NTIBIA_O_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[0]),(NTIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[4]),(TIBIA_O_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[1]),(TIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[5]),(NTIBIA_O_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[0]),(NTIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[4]),(TIBIA_O_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[1]),(TIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[5]),(NTIBIA_O_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[0]),(NTIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[4]),(TIBIA_O_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 2");lcd_putstr(lcd);
			delay_ms(5000);
		}

		if(mode_korban==MODE_K1)
		{
			if((VL_SENSOR[0]<100)&&(TCS34725_SLV_DATA[0]>=120)&&(SHARP_GRIPPER[0]<10))break;
		}
		if(mode_korban==MODE_K2)
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
			}
		}
		if(mode_korban==MODE_K5)
		{
			GetCMPS11_Angle8Bit();
			if(((VL_SENSOR[0]<340)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)&&(CMPS11_Angle<85)){mode_scan_K5=MODE_SCAN_K5_RIGHT;break;}//samping kanan

			if((VL_SENSOR[0]<190)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<230))){break;}//pas

			if(((VL_SENSOR[0]<300)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)){mode_scan_K5=MODE_SCAN_K5_LEFT;break;}//samping kiri
		}
		if(mode_korban==MODE_K2_Next)
		{
			if((VL_SENSOR[0]<200)&&((TCS34725_SLV_DATA[2]>190)&&(TCS34725_SLV_DATA[2]<240))){break;}
		}

		//SIKLUS 3
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[2]),(Z_STATIC_IK_S[1]),(TIBIA_O[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[2]),(Z_STATIC_IK_S[5]),(NTIBIA_O_R[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[2]),(FEMUR_O[0]),(NTIBIA_O[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[2]),(FEMUR_O[0]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[2]),(FEMUR_O[0]),(TIBIA_O_R[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);


		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[1]),(Z_STATIC_IK_S[1]),(TIBIA_O[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[1]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[1]),(Z_STATIC_IK_S[5]),(NTIBIA_O_R[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[1]),(FEMUR_O[1]),(NTIBIA_O[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[1]),(FEMUR_O[1]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[1]),(FEMUR_O[1]),(TIBIA_O_R[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[0]),(Z_STATIC_IK_S[1]),(TIBIA_O[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[0]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[0]),(Z_STATIC_IK_S[5]),(NTIBIA_O_R[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[0]),(FEMUR_O[2]),(NTIBIA_O[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[0]),(FEMUR_O[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[0]),(FEMUR_O[2]),(TIBIA_O_R[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[1]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK_S[5]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK_S[0]),(FEMUR_O[3]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(FEMUR_O[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK_S[4]),(FEMUR_O[3]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 3");lcd_putstr(lcd);
			delay_ms(5000);
		}

		if(mode_korban==MODE_K1)
		{
			if((VL_SENSOR[0]<100)&&(TCS34725_SLV_DATA[0]>=120)&&(SHARP_GRIPPER[0]<10))break;
		}
		if(mode_korban==MODE_K2)
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
			}
		}
		if(mode_korban==MODE_SZ2)
		{
			break;
		}
		if(mode_korban==MODE_K5)
		{
			GetCMPS11_Angle8Bit();
			if(((VL_SENSOR[0]<340)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)&&(CMPS11_Angle<85)){mode_scan_K5=MODE_SCAN_K5_RIGHT;break;}//samping kanan

			if((VL_SENSOR[0]<190)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<230))){break;}//pas

			if(((VL_SENSOR[0]<300)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)){mode_scan_K5=MODE_SCAN_K5_LEFT;break;}//samping kiri
		}
		if(mode_korban==MODE_K2_Next)
		{
			if((VL_SENSOR[0]<200)&&((TCS34725_SLV_DATA[2]>190)&&(TCS34725_SLV_DATA[2]<240))){break;}
		}
		//SIKLUS 4
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[0]),(Z_STATIC_IK_S[1]),(NTIBIA_O[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[0]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[0]),(Z_STATIC_IK_S[5]),(TIBIA_O_R[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[0]),(FEMUR_O[3]),(TIBIA_O[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[0]),(FEMUR_O[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[0]),(FEMUR_O[3]),(NTIBIA_O_R[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[1]),(Z_STATIC_IK_S[1]),(NTIBIA_O[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[1]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[1]),(Z_STATIC_IK_S[5]),(TIBIA_O_R[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[1]),(FEMUR_O[2]),(TIBIA_O[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[1]),(FEMUR_O[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[1]),(FEMUR_O[2]),(NTIBIA_O_R[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[2]),(Z_STATIC_IK_S[1]),(NTIBIA_O[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[2]),(Z_STATIC_IK_S[5]),(TIBIA_O_R[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[2]),(FEMUR_O[1]),(TIBIA_O[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[2]),(FEMUR_O[1]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[2]),(FEMUR_O[1]),(NTIBIA_O_R[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[1]),(NTIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[5]),(TIBIA_O_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[3]),(FEMUR_O[0]),(TIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[3]),(FEMUR_O[0]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[3]),(FEMUR_O[0]),(NTIBIA_O_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 4");lcd_putstr(lcd);
			delay_ms(5000);
		}

		if(mode_korban==MODE_K1)
		{
			if((VL_SENSOR[0]<100)&&(TCS34725_SLV_DATA[0]>=120)&&(SHARP_GRIPPER[0]<10))break;
		}
		if(mode_korban==MODE_K2)
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
			}
		}
		if(mode_korban==MODE_K5)
		{
			GetCMPS11_Angle8Bit();
			if(((VL_SENSOR[0]<340)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)&&(CMPS11_Angle<85)){mode_scan_K5=MODE_SCAN_K5_RIGHT;break;}//samping kanan

			if((VL_SENSOR[0]<190)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<230))){break;}//pas

			if(((VL_SENSOR[0]<300)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)){mode_scan_K5=MODE_SCAN_K5_LEFT;break;}//samping kiri
		}
		if(mode_korban==MODE_K2_Next)
		{
			if((VL_SENSOR[0]<200)&&((TCS34725_SLV_DATA[2]>190)&&(TCS34725_SLV_DATA[2]<240))){break;}
		}
		//SIKLUS 5
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[1]),(NTIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[5]),(TIBIA_O_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[0]),(TIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[4]),(NTIBIA_O_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[1]),(NTIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[5]),(TIBIA_O_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[0]),(TIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[4]),(NTIBIA_O_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[1]),(NTIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[5]),(TIBIA_O_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[0]),(TIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[4]),(NTIBIA_O_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[1]),(NTIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[5]),(TIBIA_O_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[0]),(TIBIA_O[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[4]),(NTIBIA_O_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 5");lcd_putstr(lcd);
			delay_ms(5000);
		}

		if(mode_korban==MODE_K1)
		{
			if((VL_SENSOR[0]<100)&&(TCS34725_SLV_DATA[0]>=120)&&(SHARP_GRIPPER[0]<10))break;
		}
		if(mode_korban==MODE_K2)
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
			}
		}
		if(mode_korban==MODE_K5)
		{
			GetCMPS11_Angle8Bit();
			if(((VL_SENSOR[0]<340)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)&&(CMPS11_Angle<85)){mode_scan_K5=MODE_SCAN_K5_RIGHT;break;}//samping kanan

			if((VL_SENSOR[0]<190)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<230))){break;}//pas

			if(((VL_SENSOR[0]<300)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)){mode_scan_K5=MODE_SCAN_K5_LEFT;break;}//samping kiri
		}
		if(mode_korban==MODE_K2_Next)
		{
			if((VL_SENSOR[0]<200)&&((TCS34725_SLV_DATA[2]>190)&&(TCS34725_SLV_DATA[2]<240))){break;}
		}
		//SIKLUS 6
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[2]),(FEMUR_O[0]),(NTIBIA_O[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[2]),(FEMUR_O[0]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[2]),(FEMUR_O[0]),(TIBIA_O_R[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[2]),(Z_STATIC_IK_S[0]),(TIBIA_O[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[2]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[2]),(Z_STATIC_IK_S[4]),(NTIBIA_O_R[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[1]),(FEMUR_O[1]),(NTIBIA_O[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[1]),(FEMUR_O[1]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[1]),(FEMUR_O[1]),(TIBIA_O_R[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[1]),(Z_STATIC_IK_S[0]),(TIBIA_O[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[1]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[1]),(Z_STATIC_IK_S[4]),(NTIBIA_O_R[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[0]),(FEMUR_O[2]),(NTIBIA_O[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[0]),(FEMUR_O[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[0]),(FEMUR_O[2]),(TIBIA_O_R[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[0]),(Z_STATIC_IK_S[0]),(TIBIA_O[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[0]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[0]),(Z_STATIC_IK_S[4]),(NTIBIA_O_R[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[1]),(FEMUR_O[3]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(FEMUR_O[3]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK_S[5]),(FEMUR_O[3]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK_S[0]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK_S[4]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 6");lcd_putstr(lcd);
			delay_ms(5000);
		}

		if(mode_korban==MODE_K1)
		{
			if((VL_SENSOR[0]<100)&&(TCS34725_SLV_DATA[0]>=120)&&(SHARP_GRIPPER[0]<10))break;
		}
		if(mode_korban==MODE_K2)
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
			}
		}
		if(mode_korban==MODE_K5)
		{
			GetCMPS11_Angle8Bit();
			if(((VL_SENSOR[0]<340)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)&&(CMPS11_Angle<85)){mode_scan_K5=MODE_SCAN_K5_RIGHT;break;}//samping kanan

			if((VL_SENSOR[0]<190)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<230))){break;}//pas

			if(((VL_SENSOR[0]<300)&&(VL_SENSOR[0]>200))&&(TCS34725_SLV_DATA[2]>270)){mode_scan_K5=MODE_SCAN_K5_LEFT;break;}//samping kiri
		}
		if(mode_korban==MODE_K2_Next)
		{
			if((VL_SENSOR[0]<200)&&((TCS34725_SLV_DATA[2]>190)&&(TCS34725_SLV_DATA[2]<240))){break;}
		}
	}
}


void Dynamx_MovBwd_Interpolate(int distance, int SPEED, int IKCALC_STAT)
{
	int limit= distance/4;
	int loop;
	int cek_value = 0;

	if(IKCALC_STAT == IKCALC_ENABLE)
	{
		if(IK_CALCULATED_BWD == 0)
		{
			Generate_Body(0,-1.5);
			Trajectory_Generator_NEW(X_Diff, Y_Diff, -2, 4,MOVEMENT_NORMAL);
			for(i=0;i<=3;i++)
			{
				Dyna_IKCalc_Only((X_IK_BEGIN[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]+Z_IK[i]));
				FEMUR_A[i] = tetha.Femur;
				COXA_A[i] = tetha.Coxa;
				NFEMUR_A[i] = (tetha.Femur*-1);
				NCOXA_A[i] = (tetha.Coxa*-1);

				Dyna_IKCalc_Only((X_IK_BEGIN[0]+X4_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
				TIBIA_A[i] = tetha.Tibia;

				Dyna_IKCalc_Only((X_IK_BEGIN[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
				NTIBIA_A[i] = tetha.Tibia;

				Dyna_IKCalc_Only((X_IK_BEGIN[0]-X4_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
				NTIBIA_A_R[i] = tetha.Tibia;

				Dyna_IKCalc_Only((X_IK_BEGIN[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
				TIBIA_A_R[i] = tetha.Tibia;
			}
			IK_CALCULATED_BWD = 1;
			IK_CALCULATED_FWD = 0;
		}
	}

	if (cek_value==1)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"COXA VALUE");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d|%d",COXA_A[0],COXA_A[1],COXA_A[2],COXA_A[3]);lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d|%d",NCOXA_A[0],NCOXA_A[1],NCOXA_A[2],NCOXA_A[3]);lcd_putstr(lcd);
	}

	SPEED = SPEED/45;

	switch(IKCALC_STAT)
	{
		case IKCALC_ENABLE:
		{
			FOWARD_STAT = 1;
			for(loop=1;loop<=limit;loop++)
			{
//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//
//				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//				{
//					Stairs_Detector();
//					if(STAIRS_FLAG == STAIRS_DETECTED)break;
//				}
//
//				if(FOLLOW_TRACER_STATE == 1)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//				}
//
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//				if(FOLLOW_CARPET_MODE == NORMAL)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//				}
//				else if(FOLLOW_CARPET_MODE == INVERSE)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//				}
//
//				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;

				//SIKLUS 1
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[0]),(FEMUR_A[3]),(TIBIA_A[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[0]),(FEMUR_A[3]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[0]),(FEMUR_A[3]),(NTIBIA_A_R[0]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[0]),(Z_STATIC_IK[0]),(NTIBIA_A[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[0]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[0]),(Z_STATIC_IK[4]),(TIBIA_A_R[0]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[1]),(FEMUR_A[2]),(TIBIA_A[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[1]),(FEMUR_A[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[1]),(FEMUR_A[2]),(NTIBIA_A_R[1]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[1]),(Z_STATIC_IK[0]),(NTIBIA_A[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[1]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[1]),(Z_STATIC_IK[4]),(TIBIA_A_R[1]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[2]),(FEMUR_A[1]),(TIBIA_A[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[2]),(FEMUR_A[1]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[2]),(FEMUR_A[1]),(NTIBIA_A_R[2]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[2]),(Z_STATIC_IK[0]),(NTIBIA_A[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[2]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[2]),(Z_STATIC_IK[4]),(TIBIA_A_R[2]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[3]),(FEMUR_A[0]),(TIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[3]),(FEMUR_A[0]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[3]),(FEMUR_A[0]),(NTIBIA_A_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[0]),(NTIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[4]),(TIBIA_A_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

//				while(1)
//				{
//					lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 1");lcd_putstr(lcd);
//					if(BW_BUTTON_CLICKED)break;
//				}
//
//				lcd_display_clear();

//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//				{
//					Stairs_Detector();
//					if(STAIRS_FLAG == STAIRS_DETECTED)break;
//				}
//				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;
//
//				if(FOLLOW_TRACER_STATE == 1)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//				}
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//				if(FOLLOW_CARPET_MODE == NORMAL)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//				}
//				else if(FOLLOW_CARPET_MODE == INVERSE)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//				}
//				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;

				//SIKLUS 2
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[1]),(TIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[3]),(Z_STATIC_IK[5]),(NTIBIA_A_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[0]),(NTIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[4]),(TIBIA_A_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[1]),(TIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[3]),(Z_STATIC_IK[5]),(NTIBIA_A_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[0]),(NTIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[4]),(TIBIA_A_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[1]),(TIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[3]),(Z_STATIC_IK[5]),(NTIBIA_A_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[0]),(NTIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[4]),(TIBIA_A_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[1]),(TIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[3]),(Z_STATIC_IK[5]),(NTIBIA_A_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[0]),(NTIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[4]),(TIBIA_A_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

//				while(1)
//				{
//					lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 2");lcd_putstr(lcd);
//					if(BW_BUTTON_CLICKED)break;
//				}
//
//				lcd_display_clear();


//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//				{
//					Stairs_Detector();
//					if(STAIRS_FLAG == STAIRS_DETECTED)break;
//				}
//				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;
//
//				if(FOLLOW_TRACER_STATE == 1)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//				}
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//				if(FOLLOW_CARPET_MODE == NORMAL)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//				}
//				else if(FOLLOW_CARPET_MODE == INVERSE)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//				}
//				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;

				//SIKLUS 3
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[2]),(Z_STATIC_IK[1]),(TIBIA_A[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[2]),(Z_STATIC_IK[5]),(NTIBIA_A_R[2]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[2]),(FEMUR_A[0]),(NTIBIA_A[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[2]),(FEMUR_A[0]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[2]),(FEMUR_A[0]),(TIBIA_A_R[2]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);


				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[1]),(Z_STATIC_IK[1]),(TIBIA_A[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[1]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[1]),(Z_STATIC_IK[5]),(NTIBIA_A_R[1]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[1]),(FEMUR_A[1]),(NTIBIA_A[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[1]),(FEMUR_A[1]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[1]),(FEMUR_A[1]),(TIBIA_A_R[1]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[0]),(Z_STATIC_IK[1]),(TIBIA_A[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[0]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[0]),(Z_STATIC_IK[5]),(NTIBIA_A_R[0]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[0]),(FEMUR_A[2]),(NTIBIA_A[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[0]),(FEMUR_A[2]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[0]),(FEMUR_A[2]),(TIBIA_A_R[0]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK[1]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK[5]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK[0]),(FEMUR_A[3]),(X_STATIC_IK[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(FEMUR_A[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK[4]),(FEMUR_A[3]),(X_STATIC_IK[4]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

//				while(1)
//				{
//					lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 3");lcd_putstr(lcd);
//					if(BW_BUTTON_CLICKED)break;
//				}
//
//				lcd_display_clear();

//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//				{
//					Stairs_Detector();
//					if(STAIRS_FLAG == STAIRS_DETECTED)break;
//				}
//				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;
//
//				if(FOLLOW_TRACER_STATE == 1)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//				}
//
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//				if(FOLLOW_CARPET_MODE == NORMAL)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//				}
//				else if(FOLLOW_CARPET_MODE == INVERSE)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//				}
//				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;

				//SIKLUS 4

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[0]),(Z_STATIC_IK[1]),(NTIBIA_A[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[0]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[0]),(Z_STATIC_IK[5]),(TIBIA_A_R[0]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[0]),(FEMUR_A[3]),(TIBIA_A[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[0]),(FEMUR_A[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[0]),(FEMUR_A[3]),(NTIBIA_A_R[0]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[1]),(Z_STATIC_IK[1]),(NTIBIA_A[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[1]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[1]),(Z_STATIC_IK[5]),(TIBIA_A_R[1]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[1]),(FEMUR_A[2]),(TIBIA_A[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[1]),(FEMUR_A[2]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[1]),(FEMUR_A[2]),(NTIBIA_A_R[1]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[2]),(Z_STATIC_IK[1]),(NTIBIA_A[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[2]),(Z_STATIC_IK[5]),(TIBIA_A_R[2]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[2]),(FEMUR_A[1]),(TIBIA_A[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[2]),(FEMUR_A[1]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[2]),(FEMUR_A[1]),(NTIBIA_A_R[2]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[1]),(NTIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[5]),(TIBIA_A_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[3]),(FEMUR_A[0]),(TIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[3]),(FEMUR_A[0]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[3]),(FEMUR_A[0]),(NTIBIA_A_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

//				while(1)
//				{
//					//lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 4");lcd_putstr(lcd);
//					if(BW_BUTTON_CLICKED)break;
//				}
//
//				lcd_display_clear();

//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//
//				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//				{
//					Stairs_Detector();
//					if(STAIRS_FLAG == STAIRS_DETECTED)break;
//				}
//				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;
//
//				if(FOLLOW_TRACER_STATE == 1)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//				}
//
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//				if(FOLLOW_CARPET_MODE == NORMAL)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//				}
//				else if(FOLLOW_CARPET_MODE == INVERSE)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//				}
//				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;

				//SIKLUS 5
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[1]),(NTIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[5]),(TIBIA_A_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[3]),(Z_STATIC_IK[0]),(TIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[3]),(Z_STATIC_IK[4]),(NTIBIA_A_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[1]),(NTIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[5]),(TIBIA_A_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[3]),(Z_STATIC_IK[0]),(TIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[3]),(Z_STATIC_IK[4]),(NTIBIA_A_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[1]),(NTIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[5]),(TIBIA_A_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[3]),(Z_STATIC_IK[0]),(TIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[3]),(Z_STATIC_IK[4]),(NTIBIA_A_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[1]),(NTIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[5]),(TIBIA_A_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[3]),(Z_STATIC_IK[0]),(TIBIA_A[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[3]),(Z_STATIC_IK[4]),(NTIBIA_A_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

//				while(1)
//				{
//					lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 5");lcd_putstr(lcd);
//					if(BW_BUTTON_CLICKED)break;
//				}
//
//				lcd_display_clear();

//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//				{
//					Stairs_Detector();
//					if(STAIRS_FLAG == STAIRS_DETECTED)break;
//				}
//
//				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;
//
//				if(FOLLOW_TRACER_STATE == 1)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//				}
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//				if(FOLLOW_CARPET_MODE == NORMAL)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//				}
//				else if(FOLLOW_CARPET_MODE == INVERSE)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//				}
//				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;

				//SIKLUS 6
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[2]),(FEMUR_A[0]),(NTIBIA_A[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[2]),(FEMUR_A[0]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[2]),(FEMUR_A[0]),(TIBIA_A_R[2]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[2]),(Z_STATIC_IK[0]),(TIBIA_A[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[2]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[2]),(Z_STATIC_IK[4]),(NTIBIA_A_R[2]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[1]),(FEMUR_A[1]),(NTIBIA_A[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[1]),(FEMUR_A[1]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[1]),(FEMUR_A[1]),(TIBIA_A_R[1]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[1]),(Z_STATIC_IK[0]),(TIBIA_A[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[1]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[1]),(Z_STATIC_IK[4]),(NTIBIA_A_R[1]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[0]),(FEMUR_A[2]),(NTIBIA_A[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[0]),(FEMUR_A[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[0]),(FEMUR_A[2]),(TIBIA_A_R[0]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[0]),(Z_STATIC_IK[0]),(TIBIA_A[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[0]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[0]),(Z_STATIC_IK[4]),(NTIBIA_A_R[0]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK[1]),(FEMUR_A[3]),(X_STATIC_IK[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(FEMUR_A[3]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK[5]),(FEMUR_A[3]),(X_STATIC_IK[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK[0]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK[4]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

//				while(1)
//				{
//					lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 6");lcd_putstr(lcd);
//					if(BW_BUTTON_CLICKED)break;
//				}
//
//				lcd_display_clear();

//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//				{
//					Stairs_Detector();
//					if(STAIRS_FLAG == STAIRS_DETECTED)break;
//				}
//
//				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;
//
//				if(FOLLOW_TRACER_STATE == 1)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//				}
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//				if(FOLLOW_CARPET_MODE == NORMAL)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//				}
//				else if(FOLLOW_CARPET_MODE == INVERSE)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//				}
//				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;
			}
		}break;

		case IKCALC_DISABLE:
		{
			for (loop=1;loop<=limit;loop++)
				{

				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//2
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
				//BW_Tracer_Check();

				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//3
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R3[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R3[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L3[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R3[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R3[2]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L3[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R3[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L3[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L3[0]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//3
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R2[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R2[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R2[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R2[2]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L2[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L2[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L2[0]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//3
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R1[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R1[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L1[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R1[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R1[2]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L1[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L1[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L1[0]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//3
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R[2]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//3
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R[2]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);


				if(CAT_DETECTOR==CAT_ACTIVATED)
							{
								Cat_Avoider();
								if(CAT_FLAG ==CAT_DETECTED)break;
							}
				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//4
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]);
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//belakang angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//4
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L1[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R1[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L1[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L1[0]);
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R1[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//belakang angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R1[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//4
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L2[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L2[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L2[0]);
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R2[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//belakang angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R2[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//4
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L3[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R3[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L3[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L3[0]);
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R3[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L3[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//belakang angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R3[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				if(CAT_DETECTOR==CAT_ACTIVATED)
							{
								Cat_Avoider();
								if(CAT_FLAG ==CAT_DETECTED)break;
							}
				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//5
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);//tengah angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				if(CAT_DETECTOR==CAT_ACTIVATED)
							{
								Cat_Avoider();
								if(CAT_FLAG ==CAT_DETECTED)break;
							}
				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;
				//BW_Tracer_Check();

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//6
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R3[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L3[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R3[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R3[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L3[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L3[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R3[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L3[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L3[2]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//6
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R2[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R2[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R2[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L2[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L2[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L2[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L2[2]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//6
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R1[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R1[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R1[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L1[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L1[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R1[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L1[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L1[2]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//6
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L[2]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//6
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L[2]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);


				if(CAT_DETECTOR==CAT_ACTIVATED)
							{
								Cat_Avoider();
								if(CAT_FLAG ==CAT_DETECTED)break;
							}
				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//1
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//belakang angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//1
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R1[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L1[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R1[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R1[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L1[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//belakang angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L1[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//1
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R2[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R2[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R2[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L2[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//belakang angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L2[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//1
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R3[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L3[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R3[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R3[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L3[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R3[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//belakang angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L3[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}

				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				}
		}break;
		FOWARD_STAT = 0;
	}

}

void Dynamx_MovBwd_Obs_Interpolate(int distance, int SPEED, int IKCALC_STAT)
{
	int limit= distance/4;
	int loop;
	int cek_value = 0;

	if(IKCALC_STAT == IKCALC_ENABLE)
	{
		if(IK_CALCULATED_BWD_OBS == 0)
		{
			Generate_Body(0,-1.5);
			Trajectory_Generator_Obs(X_Diff, Y_Diff, -3, 4,MOVEMENT_NORMAL);
			for(i=0;i<=3;i++)
			{
				Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_OBS[1]+Z_IK[i]));
				FEMUR_O[i] = tetha.Femur;
				COXA_O[i] = tetha.Coxa;
				NFEMUR_O[i] = (tetha.Femur*-1);
				NCOXA_O[i] = (tetha.Coxa*-1);

				Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_OBS[1]));
				TIBIA_O[i] = tetha.Tibia;

				Dyna_IKCalc_Only((X_IK_OBS[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_OBS[1]));
				NTIBIA_O[i] = tetha.Tibia;
				NTIBIA_O_R[i] = tetha.Tibia;

				Dyna_IKCalc_Only((X_IK_OBS[0]+X2_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_OBS[1]));
				TIBIA_O_R[i] = tetha.Tibia;
			}
			IK_CALCULATED_BWD_OBS = 1;
			IK_CALCULATED_FWD_OBS = 0;
		}
	}

	if (cek_value==1)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"COXA VALUE");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d|%d",COXA_A[0],COXA_A[1],COXA_A[2],COXA_A[3]);lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d|%d",NCOXA_A[0],NCOXA_A[1],NCOXA_A[2],NCOXA_A[3]);lcd_putstr(lcd);
	}

	SPEED = SPEED/45;

	switch(IKCALC_STAT)
	{
		case IKCALC_ENABLE:
		{
//			FOWARD_STAT = 1;
			for(loop=1;loop<=limit;loop++)
			{
//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//
//				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//				{
//					Stairs_Detector();
//					if(STAIRS_FLAG == STAIRS_DETECTED)break;
//				}
//
//				if(FOLLOW_TRACER_STATE == 1)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//				}
//
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//				if(FOLLOW_CARPET_MODE == NORMAL)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//				}
//				else if(FOLLOW_CARPET_MODE == INVERSE)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//				}
//
//				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;

				//SIKLUS 1
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[0]),(FEMUR_O[3]),(TIBIA_O[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[0]),(FEMUR_O[3]),(X_STATIC_IK_S[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[0]),(FEMUR_O[3]),(NTIBIA_O_R[0]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[0]),(Z_STATIC_IK_S[0]),(NTIBIA_O[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[0]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[0]),(Z_STATIC_IK_S[4]),(TIBIA_O_R[0]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[1]),(FEMUR_O[2]),(TIBIA_O[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[1]),(FEMUR_O[2]),(X_STATIC_IK_S[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[1]),(FEMUR_O[2]),(NTIBIA_O_R[1]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[1]),(Z_STATIC_IK_S[0]),(NTIBIA_O[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[1]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[1]),(Z_STATIC_IK_S[4]),(TIBIA_O_R[1]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[2]),(FEMUR_O[1]),(TIBIA_O[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[2]),(FEMUR_O[1]),(X_STATIC_IK_S[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[2]),(FEMUR_O[1]),(NTIBIA_O_R[2]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[2]),(Z_STATIC_IK_S[0]),(NTIBIA_O[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[2]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[2]),(Z_STATIC_IK_S[4]),(TIBIA_O_R[2]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[3]),(FEMUR_O[0]),(TIBIA_O[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[3]),(FEMUR_O[0]),(X_STATIC_IK_S[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[3]),(FEMUR_O[0]),(NTIBIA_O_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[0]),(NTIBIA_O[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[4]),(TIBIA_O_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

//				while(1)
//				{
//					lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 1");lcd_putstr(lcd);
//					if(BW_BUTTON_CLICKED)break;
//				}
//
//				lcd_display_clear();

//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//				{
//					Stairs_Detector();
//					if(STAIRS_FLAG == STAIRS_DETECTED)break;
//				}
//				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;
//
//				if(FOLLOW_TRACER_STATE == 1)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//				}
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//				if(FOLLOW_CARPET_MODE == NORMAL)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//				}
//				else if(FOLLOW_CARPET_MODE == INVERSE)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//				}
//				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;

				//SIKLUS 2
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[1]),(TIBIA_O[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[5]),(NTIBIA_O_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[0]),(NTIBIA_O[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[4]),(TIBIA_O_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[1]),(TIBIA_O[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[5]),(NTIBIA_O_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[0]),(NTIBIA_O[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[4]),(TIBIA_O_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[1]),(TIBIA_O[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[5]),(NTIBIA_O_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[0]),(NTIBIA_O[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[4]),(TIBIA_O_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[1]),(TIBIA_O[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[5]),(NTIBIA_O_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[0]),(NTIBIA_O[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[4]),(TIBIA_O_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

//				while(1)
//				{
//					lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 2");lcd_putstr(lcd);
//					if(BW_BUTTON_CLICKED)break;
//				}
//
//				lcd_display_clear();


//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//				{
//					Stairs_Detector();
//					if(STAIRS_FLAG == STAIRS_DETECTED)break;
//				}
//				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;
//
//				if(FOLLOW_TRACER_STATE == 1)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//				}
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//				if(FOLLOW_CARPET_MODE == NORMAL)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//				}
//				else if(FOLLOW_CARPET_MODE == INVERSE)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//				}
//				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;

				//SIKLUS 3
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[2]),(Z_STATIC_IK_S[1]),(TIBIA_O[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[2]),(Z_STATIC_IK_S[5]),(NTIBIA_O_R[2]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[2]),(FEMUR_O[0]),(NTIBIA_O[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[2]),(FEMUR_O[0]),(X_STATIC_IK_S[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[2]),(FEMUR_O[0]),(TIBIA_O_R[2]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);


				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[1]),(Z_STATIC_IK_S[1]),(TIBIA_O[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[1]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[1]),(Z_STATIC_IK_S[5]),(NTIBIA_O_R[1]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[1]),(FEMUR_O[1]),(NTIBIA_O[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[1]),(FEMUR_O[1]),(X_STATIC_IK_S[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[1]),(FEMUR_O[1]),(TIBIA_O_R[1]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[0]),(Z_STATIC_IK_S[1]),(TIBIA_O[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[0]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[0]),(Z_STATIC_IK_S[5]),(NTIBIA_O_R[0]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[0]),(FEMUR_O[2]),(NTIBIA_O[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[0]),(FEMUR_O[2]),(X_STATIC_IK_S[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[0]),(FEMUR_O[2]),(TIBIA_O_R[0]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[1]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK_S[5]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK_S[0]),(FEMUR_O[3]),(X_STATIC_IK_S[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(FEMUR_O[3]),(X_STATIC_IK_S[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK_S[4]),(FEMUR_O[3]),(X_STATIC_IK_S[4]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

//				while(1)
//				{
//					lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 3");lcd_putstr(lcd);
//					if(BW_BUTTON_CLICKED)break;
//				}
//
//				lcd_display_clear();

//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//				{
//					Stairs_Detector();
//					if(STAIRS_FLAG == STAIRS_DETECTED)break;
//				}
//				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;
//
//				if(FOLLOW_TRACER_STATE == 1)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//				}
//
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//				if(FOLLOW_CARPET_MODE == NORMAL)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//				}
//				else if(FOLLOW_CARPET_MODE == INVERSE)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//				}
//				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;

				//SIKLUS 4

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[0]),(Z_STATIC_IK_S[1]),(NTIBIA_O[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[0]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[0]),(Z_STATIC_IK_S[5]),(TIBIA_O_R[0]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[0]),(FEMUR_O[3]),(TIBIA_O[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[0]),(FEMUR_O[3]),(X_STATIC_IK_S[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[0]),(FEMUR_O[3]),(NTIBIA_O_R[0]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[1]),(Z_STATIC_IK_S[1]),(NTIBIA_O[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[1]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[1]),(Z_STATIC_IK_S[5]),(TIBIA_O_R[1]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[1]),(FEMUR_O[2]),(TIBIA_O[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[1]),(FEMUR_O[2]),(X_STATIC_IK_S[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[1]),(FEMUR_O[2]),(NTIBIA_O_R[1]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[2]),(Z_STATIC_IK_S[1]),(NTIBIA_O[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[2]),(Z_STATIC_IK_S[5]),(TIBIA_O_R[2]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[2]),(FEMUR_O[1]),(TIBIA_O[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[2]),(FEMUR_O[1]),(X_STATIC_IK_S[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[2]),(FEMUR_O[1]),(NTIBIA_O_R[2]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[1]),(NTIBIA_O[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[5]),(TIBIA_O_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[3]),(FEMUR_O[0]),(TIBIA_O[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[3]),(FEMUR_O[0]),(X_STATIC_IK_S[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[3]),(FEMUR_O[0]),(NTIBIA_O_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

//				while(1)
//				{
//					//lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 4");lcd_putstr(lcd);
//					if(BW_BUTTON_CLICKED)break;
//				}
//
//				lcd_display_clear();

//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//
//				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//				{
//					Stairs_Detector();
//					if(STAIRS_FLAG == STAIRS_DETECTED)break;
//				}
//				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;
//
//				if(FOLLOW_TRACER_STATE == 1)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//				}
//
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//				if(FOLLOW_CARPET_MODE == NORMAL)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//				}
//				else if(FOLLOW_CARPET_MODE == INVERSE)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//				}
//				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;

				//SIKLUS 5
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[1]),(NTIBIA_O[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[5]),(TIBIA_O_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[0]),(TIBIA_O[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[4]),(NTIBIA_O_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[1]),(NTIBIA_O[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[5]),(TIBIA_O_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[0]),(TIBIA_O[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[4]),(NTIBIA_O_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[1]),(NTIBIA_O[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[5]),(TIBIA_O_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[0]),(TIBIA_O[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[4]),(NTIBIA_O_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[1]),(NTIBIA_O[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[5]),(TIBIA_O_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[0]),(TIBIA_O[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[4]),(NTIBIA_O_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

//				while(1)
//				{
//					lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 5");lcd_putstr(lcd);
//					if(BW_BUTTON_CLICKED)break;
//				}
//
//				lcd_display_clear();

//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//				{
//					Stairs_Detector();
//					if(STAIRS_FLAG == STAIRS_DETECTED)break;
//				}
//
//				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;
//
//				if(FOLLOW_TRACER_STATE == 1)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//				}
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//				if(FOLLOW_CARPET_MODE == NORMAL)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//				}
//				else if(FOLLOW_CARPET_MODE == INVERSE)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//				}
//				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;

				//SIKLUS 6
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[2]),(FEMUR_O[0]),(NTIBIA_O[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[2]),(FEMUR_O[0]),(X_STATIC_IK_S[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[2]),(FEMUR_O[0]),(TIBIA_O_R[2]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[2]),(Z_STATIC_IK_S[0]),(TIBIA_O[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[2]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[2]),(Z_STATIC_IK_S[4]),(NTIBIA_O_R[2]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[1]),(FEMUR_O[1]),(NTIBIA_O[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[1]),(FEMUR_O[1]),(X_STATIC_IK_S[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[1]),(FEMUR_O[1]),(TIBIA_O_R[1]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[1]),(Z_STATIC_IK_S[0]),(TIBIA_O[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[1]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[1]),(Z_STATIC_IK_S[4]),(NTIBIA_O_R[1]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[0]),(FEMUR_O[2]),(NTIBIA_O[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[0]),(FEMUR_O[2]),(X_STATIC_IK_S[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[0]),(FEMUR_O[2]),(TIBIA_O_R[0]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[0]),(Z_STATIC_IK_S[0]),(TIBIA_O[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[0]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[0]),(Z_STATIC_IK_S[4]),(NTIBIA_O_R[0]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[1]),(FEMUR_O[3]),(X_STATIC_IK_S[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(FEMUR_O[3]),(X_STATIC_IK_S[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK_S[5]),(FEMUR_O[3]),(X_STATIC_IK_S[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK_S[0]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK_S[4]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

//				while(1)
//				{
//					lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 6");lcd_putstr(lcd);
//					if(BW_BUTTON_CLICKED)break;
//				}
//
//				lcd_display_clear();

//				if(CAT_DETECTOR==CAT_ACTIVATED)
//				{
//					Cat_Avoider();
//					if(CAT_FLAG ==CAT_DETECTED)break;
//				}
//				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
//				{
//					Stairs_Detector();
//					if(STAIRS_FLAG == STAIRS_DETECTED)break;
//				}
//
//				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;
//
//				if(FOLLOW_TRACER_STATE == 1)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
//				}
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//				TCS3200_Transmit(UART5, CMD_GET_TRACER);
//				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
//				if(FOLLOW_CARPET_MODE == NORMAL)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;
//
//				}
//				else if(FOLLOW_CARPET_MODE == INVERSE)
//				{
//					TCS3200_Transmit(UART5, CMD_GET_TRACER);
//					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;
//
//				}
//				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;
			}
		}break;

		case IKCALC_DISABLE:
		{
			for (loop=1;loop<=limit;loop++)
				{

				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//2
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
				//BW_Tracer_Check();

				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//3
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R3[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R3[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L3[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R3[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R3[2]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L3[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R3[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L3[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L3[0]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//3
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R2[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R2[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R2[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R2[2]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L2[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L2[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L2[0]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//3
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R1[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R1[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L1[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R1[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R1[2]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L1[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L1[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L1[0]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//3
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R[2]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//3
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R[2]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);


				if(CAT_DETECTOR==CAT_ACTIVATED)
							{
								Cat_Avoider();
								if(CAT_FLAG ==CAT_DETECTED)break;
							}
				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//4
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L[0]);
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//belakang angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//4
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L1[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R1[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L1[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L1[0]);
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R1[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//belakang angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R1[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//4
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L2[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L2[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L2[0]);
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R2[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//belakang angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R2[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//4
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKFWD_COXA_L3[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKFWD_COXA_R3[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKFWD_COXA_L3[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L3[0]);
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKFWD_COXA_R3[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKFWD_COXA_L3[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//belakang angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKFWD_COXA_R3[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				if(CAT_DETECTOR==CAT_ACTIVATED)
							{
								Cat_Avoider();
								if(CAT_FLAG ==CAT_DETECTED)break;
							}
				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//5
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);//tengah angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				if(CAT_DETECTOR==CAT_ACTIVATED)
							{
								Cat_Avoider();
								if(CAT_FLAG ==CAT_DETECTED)break;
							}
				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;
				//BW_Tracer_Check();

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//6
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R3[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L3[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R3[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R3[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L3[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L3[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R3[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L3[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L3[2]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//6
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R2[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R2[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R2[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L2[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L2[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L2[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L2[2]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//6
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R1[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R1[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R1[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L1[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L1[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R1[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L1[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L1[2]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//6
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L[2]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//6
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan angkat
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L[0]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L[2]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);


				if(CAT_DETECTOR==CAT_ACTIVATED)
							{
								Cat_Avoider();
								if(CAT_FLAG ==CAT_DETECTED)break;
							}
				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;
				//BW_Tracer_Check();
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				//1
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//belakang angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//1
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R1[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L1[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R1[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R1[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L1[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//belakang angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L1[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//1
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R2[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R2[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R2[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L2[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//belakang angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L2[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				//1
				//TRIPOD A
				Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKFWD_COXA_R3[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKFWD_COXA_L3[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
				Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKFWD_COXA_R3[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R3[0]);
				//TRIPOD B
				Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKFWD_COXA_L3[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
				Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKFWD_COXA_R3[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//belakang angkat
				Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKFWD_COXA_L3[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
//				delay_ms(500);
				Start_Pose_SYNC();
				delay_ms(SPEED+2);

				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}

				if (Ping[PING_REAR]<=FRONT_THRESHOLD)break;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

				}
		}break;
		FOWARD_STAT = 0;
	}

}

void Dynamx_Rot_Right_Interpolate(int SPEED,  int STEP, int IKCALC_STAT)
{
	int limit;

	if(IKCALC_STAT == IKCALC_ENABLE)
	{
		SPEED = SPEED/45;
	}

	else
	{
		SPEED = SPEED/14+4;
	}

	switch(IKCALC_STAT)
	{

		case IKCALC_ENABLE:
		{

		}break;

		case IKCALC_DISABLE:
		{
			if (STEP==HEXSTEP_FAR2)
			{
				IKROT_COXA[0]=17;IKROT_COXA[1]=18;// MOV ROT ZCOXA_L = 15
				IKROT_COXA1[0]=12;IKROT_COXA1[1]=12;// MOV ROT ZCOXA_L = 10
				IKROT_COXA2[0]=6;IKROT_COXA2[1]=6;// MOV ROT ZCOXA_L = 5
				limit = 2;

			}
			else if(STEP==HEXSTEP_FAR)
			{
				IKROT_COXA[0]=17;IKROT_COXA[1]=18;// MOV ROT ZCOXA_L = 15
				IKROT_COXA1[0]=12;IKROT_COXA1[1]=12;// MOV ROT ZCOXA_L = 10
				IKROT_COXA2[0]=6;IKROT_COXA2[1]=6;// MOV ROT ZCOXA_L = 5
				limit = 1;
			}
			else if(STEP==HEXSTEP_MED)
			{
				IKROT_COXA[0]=15;IKROT_COXA[1]=15;// MOV ROT ZCOXA_L = 10
				IKROT_COXA1[0]=10;IKROT_COXA1[1]=10;// MOV ROT ZCOXA_L = 6
				IKROT_COXA2[0]=5;IKROT_COXA2[1]=5;// MOV ROT ZCOXA_L = 3
				limit = 1;
			}
			else if(STEP==HEXSTEP_CLOSE)
			{
				IKROT_COXA[0]=10;IKROT_COXA[1]=10;// MOV ROT ZCOXA_L = 5
				IKROT_COXA1[0]=6;IKROT_COXA1[1]=6;// MOV ROT ZCOXA_L = 3
				IKROT_COXA2[0]=2;IKROT_COXA2[1]=2;// MOV ROT ZCOXA_L = 1
				limit = 1;

			}
			else
			{
				IKROT_COXA[0]=7;IKROT_COXA[1]=6;// MOV ROT ZCOXA_L = 3
				IKROT_COXA1[0]=4;IKROT_COXA1[1]=4;// MOV ROT ZCOXA_L = 2
				IKROT_COXA2[0]=2;IKROT_COXA2[1]=2;// MOV ROT ZCOXA_L = 1
				limit = 1;
			}

			for (int z=0; z<limit; z++)
			{

			Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
			Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);

			Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);
			Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
			Start_Pose_SYNC();
			delay_ms(SPEED);
			//3
			//TRIPOD A
			Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA2[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
			Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA2[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA2[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//depan angkat
			Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA2[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
			Start_Pose_SYNC();
			delay_ms(SPEED);

			//3
			//TRIPOD A
			Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA1[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA1[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
			Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA1[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA1[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//depan angkat
			Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA1[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
			Start_Pose_SYNC();
			delay_ms(SPEED);

			//3
			//TRIPOD A
			Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
			Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//depan angkat
			Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
			Start_Pose_SYNC();
			delay_ms(SPEED);

			//3
			//TRIPOD A
			Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
			Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//depan angkat
			Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
//			delay_ms(5000);
			Start_Pose_SYNC();
			delay_ms(SPEED);

			//4
			//TRIPOD A
			Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//belakang angkat
			Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);

			//TRIPOD B
			Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
			Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
//			delay_ms(5000);
			Start_Pose_SYNC();
			delay_ms(SPEED);

			//4
			//TRIPOD A
			Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA1[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//belakang angkat
			Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA1[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA1[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA1[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
			Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA1[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
			//			delay_ms(5000);
			Start_Pose_SYNC();
			delay_ms(SPEED);

			//4
			//TRIPOD A
			Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA2[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//belakang angkat
			Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA2[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA2[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
			Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA2[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);

			//			delay_ms(5000);
			Start_Pose_SYNC();
			delay_ms(SPEED);

			//5
			//TRIPOD A
			Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);//tengah angkat
			Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
			Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);
//			delay_ms(5000);
			Start_Pose_SYNC();
			delay_ms(SPEED);

			//6
			//TRIPOD A
			Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA2[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
			Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA2[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA2[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
			Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA2[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
//			delay_ms(5000);
			Start_Pose_SYNC();
			delay_ms(SPEED);

			//6
			//TRIPOD A
			Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA1[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
			Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA1[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA1[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA1[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
			Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA1[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
//			delay_ms(5000);
			Start_Pose_SYNC();
			delay_ms(SPEED);

			//6
			//TRIPOD A
			Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
			Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
			Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
//			delay_ms(5000);
			Start_Pose_SYNC();
			delay_ms(SPEED);

			//6
			//TRIPOD A
			Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan angkat
			Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
			Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
//			delay_ms(5000);
			Start_Pose_SYNC();
			delay_ms(SPEED);

			//1
			//TRIPOD A
			Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
			Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//belakang angkat
			Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
//			delay_ms(5000);
			Start_Pose_SYNC();
			delay_ms(SPEED);

			//1
			//TRIPOD A
			Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA1[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA1[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
			Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA1[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA1[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//belakang angkat
			Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA1[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
//			delay_ms(5000);
			Start_Pose_SYNC();
			delay_ms(SPEED);

			//1
			//TRIPOD A
			Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA2[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
			Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA2[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA2[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//belakang angkat
			Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA2[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
//			delay_ms(5000);
			Start_Pose_SYNC();
			delay_ms(SPEED);

			}

		}break;
	}

}

void Dynamx_Rot_Right_Cmps(int SPEED)
{
	SPEED = SPEED/14+4;

	IKROT_COXA[0]=17;IKROT_COXA[1]=18;// MOV ROT ZCOXA_L = 15
	IKROT_COXA1[0]=12;IKROT_COXA1[1]=12;// MOV ROT ZCOXA_L = 10
	IKROT_COXA2[0]=6;IKROT_COXA2[1]=6;// MOV ROT ZCOXA_L = 5

	for (int z=0; z<1; z++)
	{
		Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
		Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
		Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);

		Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
		Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);
		Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
		Start_Pose_SYNC();
		delay_ms(SPEED);

		GetCMPS11_Angle8Bit();
		if((CMPS11_Angle>WEST_LOW) && (CMPS11_Angle<WEST_UP))
		{
			start_compas_flag = 1;
			break;
		}
		else if((CMPS11_Angle>SOUTH_LOW) && (CMPS11_Angle<SOUTH_UP))
		{
			start_compas_flag = 1;
			break;
		}

		//3
		//TRIPOD A
		Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA2[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
		Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
		Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA2[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
		//TRIPOD B
		Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA2[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
		Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//depan angkat
		Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA2[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
		//			delay_ms(5000);
		Start_Pose_SYNC();
		delay_ms(SPEED);

		GetCMPS11_Angle8Bit();
		if((CMPS11_Angle>WEST_LOW) && (CMPS11_Angle<WEST_UP))
		{
			start_compas_flag = 1;
			break;
		}
		else if((CMPS11_Angle>SOUTH_LOW) && (CMPS11_Angle<SOUTH_UP))
		{
			start_compas_flag = 1;
			break;
		}

		//3
		//TRIPOD A
		Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA1[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
		Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA1[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
		Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA1[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
		//TRIPOD B
		Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA1[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
		Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//depan angkat
		Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA1[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
		Start_Pose_SYNC();
		delay_ms(SPEED);

		GetCMPS11_Angle8Bit();
		if((CMPS11_Angle>WEST_LOW) && (CMPS11_Angle<WEST_UP))
		{
			start_compas_flag = 1;
			break;
		}
		else if((CMPS11_Angle>SOUTH_LOW) && (CMPS11_Angle<SOUTH_UP))
		{
			start_compas_flag = 1;
			break;
		}
		//3
		//TRIPOD A
		Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
		Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
		Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
		//TRIPOD B
		Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
		Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//depan angkat
		Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
		Start_Pose_SYNC();
		delay_ms(SPEED);

		GetCMPS11_Angle8Bit();
		if((CMPS11_Angle>WEST_LOW) && (CMPS11_Angle<WEST_UP))
		{
			start_compas_flag = 1;
			break;
		}
		else if((CMPS11_Angle>SOUTH_LOW) && (CMPS11_Angle<SOUTH_UP))
		{
			start_compas_flag = 1;
			break;
		}

		//3
		//TRIPOD A
		Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
		Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
		Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
		//TRIPOD B
		Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
		Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//depan angkat
		Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
		//			delay_ms(5000);
		Start_Pose_SYNC();
		delay_ms(SPEED);

		GetCMPS11_Angle8Bit();
		if((CMPS11_Angle>WEST_LOW) && (CMPS11_Angle<WEST_UP))
		{
			start_compas_flag = 1;
			break;
		}
		else if((CMPS11_Angle>SOUTH_LOW) && (CMPS11_Angle<SOUTH_UP))
		{
			start_compas_flag = 1;
			break;
		}
		//4
		//TRIPOD B
		Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
		Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
		Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
		//TRIPOD A
		Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
		Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//belakang angkat
		Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
		//			delay_ms(5000);
		Start_Pose_SYNC();
		delay_ms(SPEED);

		GetCMPS11_Angle8Bit();
		if((CMPS11_Angle>WEST_LOW) && (CMPS11_Angle<WEST_UP))
		{
			start_compas_flag = 1;
			break;
		}
		else if((CMPS11_Angle>SOUTH_LOW) && (CMPS11_Angle<SOUTH_UP))
		{
			start_compas_flag = 1;
			break;
		}
		//4
		//TRIPOD B
		Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA1[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
		Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA1[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
		Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA1[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
		//TRIPOD A
		Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA1[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
		Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//belakang angkat
		Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA1[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
		//			delay_ms(5000);
		Start_Pose_SYNC();
		delay_ms(SPEED);

		GetCMPS11_Angle8Bit();
		if((CMPS11_Angle>WEST_LOW) && (CMPS11_Angle<WEST_UP))
		{
			start_compas_flag = 1;
			break;
		}
		else if((CMPS11_Angle>SOUTH_LOW) && (CMPS11_Angle<SOUTH_UP))
		{
			start_compas_flag = 1;
			break;
		}
		//4
		//TRIPOD B
		Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA2[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
		Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
		Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA2[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
		//TRIPOD A
		Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA2[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
		Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//belakang angkat
		Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA2[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
		//			delay_ms(5000);
		Start_Pose_SYNC();
		delay_ms(SPEED);

		GetCMPS11_Angle8Bit();
		if((CMPS11_Angle>WEST_LOW) && (CMPS11_Angle<WEST_UP))
		{
			start_compas_flag = 1;
			break;
		}
		else if((CMPS11_Angle>SOUTH_LOW) && (CMPS11_Angle<SOUTH_UP))
		{
			start_compas_flag = 1;
			break;
		}
		//5
		//TRIPOD A
		Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
		Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);//tengah angkat
		Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
		//TRIPOD B
		Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
		Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
		Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);
		//			delay_ms(5000);
		Start_Pose_SYNC();
		delay_ms(SPEED);

		GetCMPS11_Angle8Bit();
		if((CMPS11_Angle>WEST_LOW) && (CMPS11_Angle<WEST_UP))
		{
			start_compas_flag = 1;
			break;
		}
		else if((CMPS11_Angle>SOUTH_LOW) && (CMPS11_Angle<SOUTH_UP))
		{
			start_compas_flag = 1;
			break;
		}
		//6
		//TRIPOD A
		Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA2[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
		Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
		Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA2[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
		//TRIPOD B
		Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA2[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
		Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
		Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA2[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
		//			delay_ms(5000);
		Start_Pose_SYNC();
		delay_ms(SPEED);

		GetCMPS11_Angle8Bit();
		if((CMPS11_Angle>WEST_LOW) && (CMPS11_Angle<WEST_UP))
		{
			start_compas_flag = 1;
			break;
		}
		else if((CMPS11_Angle>SOUTH_LOW) && (CMPS11_Angle<SOUTH_UP))
		{
			start_compas_flag = 1;
			break;
		}
		//6
		//TRIPOD A
		Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA1[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
		Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
		Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA1[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
		//TRIPOD B
		Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA1[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
		Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA1[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
		Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA1[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
		//			delay_ms(5000);
		Start_Pose_SYNC();
		delay_ms(SPEED);

		GetCMPS11_Angle8Bit();
		if((CMPS11_Angle>WEST_LOW) && (CMPS11_Angle<WEST_UP))
		{
			start_compas_flag = 1;
			break;
		}
		else if((CMPS11_Angle>SOUTH_LOW) && (CMPS11_Angle<SOUTH_UP))
		{
			start_compas_flag = 1;
			break;
		}

		//6
		//TRIPOD A
		Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
		Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
		Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
		//TRIPOD B
		Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
		Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
		Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
		//			delay_ms(5000);
		Start_Pose_SYNC();
		delay_ms(SPEED);
		GetCMPS11_Angle8Bit();
		if((CMPS11_Angle>WEST_LOW) && (CMPS11_Angle<WEST_UP))
		{
			start_compas_flag = 1;
			break;
		}
		else if((CMPS11_Angle>SOUTH_LOW) && (CMPS11_Angle<SOUTH_UP))
		{
			start_compas_flag = 1;
			break;
		}

		//6
		//TRIPOD A
		Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
		Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan angkat
		Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
		//TRIPOD B
		Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
		Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
		Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
		//			delay_ms(5000);
		Start_Pose_SYNC();
		delay_ms(SPEED);

		GetCMPS11_Angle8Bit();
		if((CMPS11_Angle>WEST_LOW) && (CMPS11_Angle<WEST_UP))
		{
			start_compas_flag = 1;
			break;
		}
		else if((CMPS11_Angle>SOUTH_LOW) && (CMPS11_Angle<SOUTH_UP))
		{
			start_compas_flag = 1;
			break;
		}
		//1
		//TRIPOD A
		Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
		Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
		Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
		//TRIPOD B
		Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
		Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//belakang angkat
		Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
		//			delay_ms(5000);
		Start_Pose_SYNC();
		delay_ms(SPEED);

		GetCMPS11_Angle8Bit();
		if((CMPS11_Angle>WEST_LOW) && (CMPS11_Angle<WEST_UP))
		{
			start_compas_flag = 1;
			break;
		}
		else if((CMPS11_Angle>SOUTH_LOW) && (CMPS11_Angle<SOUTH_UP))
		{
			start_compas_flag = 1;
			break;
		}
		//1
		//TRIPOD A
		Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA1[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
		Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA1[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
		Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA1[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
		//TRIPOD B
		Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA1[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
		Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//belakang angkat
		Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA1[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
		//			delay_ms(5000);
		Start_Pose_SYNC();
		delay_ms(SPEED);

		GetCMPS11_Angle8Bit();
		if((CMPS11_Angle>WEST_LOW) && (CMPS11_Angle<WEST_UP))
		{
			start_compas_flag = 1;
			break;
		}
		else if((CMPS11_Angle>SOUTH_LOW) && (CMPS11_Angle<SOUTH_UP))
		{
			start_compas_flag = 1;
			break;
		}
		//1
		//TRIPOD A
		Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA2[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
		Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
		Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA2[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
		//TRIPOD B
		Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA2[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
		Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//belakang angkat
		Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA2[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
		//			delay_ms(5000);
		Start_Pose_SYNC();
		delay_ms(SPEED);

		GetCMPS11_Angle8Bit();
		if((CMPS11_Angle>WEST_LOW) && (CMPS11_Angle<WEST_UP))
		{
			start_compas_flag = 1;
			break;
		}
		else if((CMPS11_Angle>SOUTH_LOW) && (CMPS11_Angle<SOUTH_UP))
		{
			start_compas_flag = 1;
			break;
		}
	}
}

void Dynamx_Rot_Left_IK(int SPEED, int STEP)
{
	int loop;
	int limit;
	SPEED = SPEED/48;

	if (STEP == STEP1)
	{
		Generate_Body(0,0.75);
		Trajectory_Generator_NEW(X_Diff, Y_Diff, -1.5, 4,MOVEMENT_NORMAL);
		limit = 1;
	}

	else if (STEP == STEP2)
	{
		Generate_Body(0,1.5);
		Trajectory_Generator_NEW(X_Diff, Y_Diff, -2, 4,MOVEMENT_NORMAL);
		limit = 2;
	}

	else if (STEP == STEP3)
	{
		Generate_Body(0,2.5);
		Trajectory_Generator_NEW(X_Diff, Y_Diff, -2, 4,MOVEMENT_NORMAL);
		limit = 2;
	}

	else if (STEP == STEP4)
	{
		Generate_Body(0,2.25);
		Trajectory_Generator_NEW(X_Diff, Y_Diff, -2, 4,MOVEMENT_NORMAL);
		limit = 3;
	}

	else if (STEP == STEP5)
	{
		Generate_Body(0,2);
		Trajectory_Generator_NEW(X_Diff, Y_Diff, -2, 4,MOVEMENT_NORMAL);
		limit = 3;
	}
	else if (STEP == STEP6)
	{
		Generate_Body(0,0.5);
		Trajectory_Generator_NEW(X_Diff, Y_Diff, -2, 4,MOVEMENT_NORMAL);
		limit = 1;
	}

	for(i=0;i<=3;i++)
	{
		Dyna_IKCalc_Only((X_IK_BEGIN[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]+Z_IK[i]));
		FEMUR_A[i] = tetha.Femur;
		COXA_A[i] = tetha.Coxa;
		NFEMUR_A[i] = (tetha.Femur*-1);
		NCOXA_A[i] = (tetha.Coxa*-1);
	}

	for(loop=1;loop<=limit;loop++)
	{

		if(mode_scan==MODE_K1)
		{
			if((VL_SENSOR[0] < 200) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K2)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K5)
		{
			if((VL_SENSOR[0]<220)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<250))){break;}//pas
		}

		//SIKLUS 1
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[0]),(FEMUR_A[3]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[0]),(FEMUR_A[3]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[0]),(FEMUR_A[3]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[0]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[0]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[0]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[1]),(FEMUR_A[2]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[1]),(FEMUR_A[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[1]),(FEMUR_A[2]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[1]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[1]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[1]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[2]),(FEMUR_A[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[2]),(FEMUR_A[1]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[2]),(FEMUR_A[1]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[2]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[2]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[2]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[3]),(FEMUR_A[0]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[3]),(FEMUR_A[0]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[3]),(FEMUR_A[0]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[3]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[3]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(mode_scan==MODE_K1)
		{
			if((VL_SENSOR[0] < 200) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K2)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K5)
		{
			if((VL_SENSOR[0]<220)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<250))){break;}//pas
		}

		//SIKLUS 2
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[3]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[3]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[3]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[3]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[3]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[3]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[3]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[3]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[3]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[3]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[3]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[3]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(mode_scan==MODE_K1)
		{
			if((VL_SENSOR[0] < 200) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K2)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K5)
		{
			if((VL_SENSOR[0]<220)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<250))){break;}//pas
		}


		//SIKLUS 3
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[2]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[2]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[2]),(FEMUR_A[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[2]),(FEMUR_A[0]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[2]),(FEMUR_A[0]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);


		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[1]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[1]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[1]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[1]),(FEMUR_A[1]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[1]),(FEMUR_A[1]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[1]),(FEMUR_A[1]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[0]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[0]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[0]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[0]),(FEMUR_A[2]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[0]),(FEMUR_A[2]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[0]),(FEMUR_A[2]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK[1]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK[5]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK[0]),(FEMUR_A[3]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(FEMUR_A[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK[4]),(FEMUR_A[3]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(mode_scan==MODE_K1)
		{
			if((VL_SENSOR[0] < 200) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K2)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K5)
		{
			if((VL_SENSOR[0]<220)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<250))){break;}//pas
		}

		//SIKLUS 4

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[0]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[0]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[0]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[0]),(FEMUR_A[3]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[0]),(FEMUR_A[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[0]),(FEMUR_A[3]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[1]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[1]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[1]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[1]),(FEMUR_A[2]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[1]),(FEMUR_A[2]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[1]),(FEMUR_A[2]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[2]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[2]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[2]),(FEMUR_A[1]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[2]),(FEMUR_A[1]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[2]),(FEMUR_A[1]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[3]),(FEMUR_A[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[3]),(FEMUR_A[0]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[3]),(FEMUR_A[0]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(mode_scan==MODE_K1)
		{
			if((VL_SENSOR[0] < 200) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K2)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K5)
		{
			if((VL_SENSOR[0]<220)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<250))){break;}//pas
		}

		//SIKLUS 5
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(mode_scan==MODE_K1)
		{
			if((VL_SENSOR[0] < 200) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K2)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K5)
		{
			if((VL_SENSOR[0]<220)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<250))){break;}//pas
		}

		//SIKLUS 6
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[2]),(FEMUR_A[0]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[2]),(FEMUR_A[0]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[2]),(FEMUR_A[0]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[2]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[2]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[2]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[1]),(FEMUR_A[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[1]),(FEMUR_A[1]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[1]),(FEMUR_A[1]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[1]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[1]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[1]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[0]),(FEMUR_A[2]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[0]),(FEMUR_A[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[0]),(FEMUR_A[2]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[0]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[0]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[0]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK[1]),(FEMUR_A[3]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(FEMUR_A[3]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK[5]),(FEMUR_A[3]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK[0]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK[4]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(mode_scan==MODE_K1)
		{
			if((VL_SENSOR[0] < 200) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K2)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K5)
		{
			if((VL_SENSOR[0]<220)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<250))){break;}//pas
		}

	}

}

void Dynamx_Rot_Right_IK(int SPEED, int STEP)
{
	int loop;
	int limit;
	SPEED = SPEED/48;

	if (STEP == STEP1)
	{
		Generate_Body(0,1);
		Trajectory_Generator_NEW(X_Diff, Y_Diff, -2, 4,MOVEMENT_NORMAL);
		limit = 2;
	}

	else if (STEP == STEP2)
	{
		Generate_Body(0,1.5);
		Trajectory_Generator_NEW(X_Diff, Y_Diff, -2, 4,MOVEMENT_NORMAL);
		limit = 2;
	}

	else if (STEP == STEP3)
	{
		Generate_Body(0,2.5);
		Trajectory_Generator_NEW(X_Diff, Y_Diff, -2, 4,MOVEMENT_NORMAL);
		limit = 2;
	}

	else if (STEP == STEP4)
	{
		Generate_Body(0,2.4);
		Trajectory_Generator_NEW(X_Diff, Y_Diff, -2, 4,MOVEMENT_NORMAL);
		limit = 3;
	}

	for(i=0;i<=3;i++)
	{
		Dyna_IKCalc_Only((X_IK_BEGIN[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]+Z_IK[i]));
		FEMUR_A[i] = tetha.Femur;
		COXA_A[i] = tetha.Coxa;
		NFEMUR_A[i] = (tetha.Femur*-1);
		NCOXA_A[i] = (tetha.Coxa*-1);
	}

	for(loop=1;loop<=limit;loop++)
	{
		if(mode_scan==MODE_K1)
		{
			if((VL_SENSOR[0] < 200) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K2)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K5)
		{
			if((VL_SENSOR[0]<220)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<250))){break;}//pas
		}


		//SIKLUS 1
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[0]),(FEMUR_A[3]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[0]),(FEMUR_A[3]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[0]),(FEMUR_A[3]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[0]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[0]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[0]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[1]),(FEMUR_A[2]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[1]),(FEMUR_A[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[1]),(FEMUR_A[2]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[1]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[1]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[1]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[2]),(FEMUR_A[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[2]),(FEMUR_A[1]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[2]),(FEMUR_A[1]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[2]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[2]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[2]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[3]),(FEMUR_A[0]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[3]),(FEMUR_A[0]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[3]),(FEMUR_A[0]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(mode_scan==MODE_K1)
		{
			if((VL_SENSOR[0] < 200) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K2)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K5)
		{
			if((VL_SENSOR[0]<220)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<250))){break;}//pas
		}


		//SIKLUS 2
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(mode_scan==MODE_K1)
		{
			if((VL_SENSOR[0] < 200) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K2)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K5)
		{
			if((VL_SENSOR[0]<220)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<250))){break;}//pas
		}


		//SIKLUS 3
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[2]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[2]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[2]),(FEMUR_A[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[2]),(FEMUR_A[0]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[2]),(FEMUR_A[0]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);


		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[1]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[1]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[1]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[1]),(FEMUR_A[1]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[1]),(FEMUR_A[1]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[1]),(FEMUR_A[1]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_A[0]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_A[0]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_A[0]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_A[0]),(FEMUR_A[2]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_A[0]),(FEMUR_A[2]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_A[0]),(FEMUR_A[2]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK[1]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK[5]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK[0]),(FEMUR_A[3]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(FEMUR_A[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK[4]),(FEMUR_A[3]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(mode_scan==MODE_K1)
		{
			if((VL_SENSOR[0] < 200) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K2)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K5)
		{
			if((VL_SENSOR[0]<220)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<250))){break;}//pas
		}

		//SIKLUS 4

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[0]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[0]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[0]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[0]),(FEMUR_A[3]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[0]),(FEMUR_A[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[0]),(FEMUR_A[3]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[1]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[1]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[1]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[1]),(FEMUR_A[2]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[1]),(FEMUR_A[2]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[1]),(FEMUR_A[2]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[2]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[2]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[2]),(FEMUR_A[1]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[2]),(FEMUR_A[1]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[2]),(FEMUR_A[1]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[3]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[3]),(FEMUR_A[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[3]),(FEMUR_A[0]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[3]),(FEMUR_A[0]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(mode_scan==MODE_K1)
		{
			if((VL_SENSOR[0] < 200) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K2)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K5)
		{
			if((VL_SENSOR[0]<220)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<250))){break;}//pas
		}

		//SIKLUS 5
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[3]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[3]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[3]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[3]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[3]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[3]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[3]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[3]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[3]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[3]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[3]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[3]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[3]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(mode_scan==MODE_K1)
		{
			if((VL_SENSOR[0] < 200) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K2)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K5)
		{
			if((VL_SENSOR[0]<220)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<250))){break;}//pas
		}

		//SIKLUS 6
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[2]),(FEMUR_A[0]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[2]),(FEMUR_A[0]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[2]),(FEMUR_A[0]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[2]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[2]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[2]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[1]),(FEMUR_A[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[1]),(FEMUR_A[1]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[1]),(FEMUR_A[1]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[1]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[1]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[1]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_A[0]),(FEMUR_A[2]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_A[0]),(FEMUR_A[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_A[0]),(FEMUR_A[2]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_A[0]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_A[0]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_A[0]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK[1]),(FEMUR_A[3]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(FEMUR_A[3]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK[5]),(FEMUR_A[3]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK[0]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK[4]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(mode_scan==MODE_K1)
		{
			if((VL_SENSOR[0] < 200) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K2)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K5)
		{
			if((VL_SENSOR[0]<220)&&((TCS34725_SLV_DATA[2]>180)&&(TCS34725_SLV_DATA[2]<250))){break;}//pas
		}

	}
}


void Dynamx_Rot_Left_Interpolate(int SPEED,  int STEP, int IKCALC_STAT)
{
	int loop;
	int limit;

	if(IKCALC_STAT == IKCALC_DISABLE)
	{
		SPEED = SPEED/14+4;
	}
	else
	{
		SPEED = SPEED/45;
	}

	switch(IKCALC_STAT)
	{
		case IKCALC_ENABLE:
		{}break;

		case IKCALC_DISABLE:
		{
			if (STEP==HEXSTEP_FAR2)
			{
				IKROT_COXA[0]=16;IKROT_COXA[1]=18;// MOV ROT ZCOXA_L = 15
				IKROT_COXA1[0]=12;IKROT_COXA1[1]=10;// MOV ROT ZCOXA_L = 10
				IKROT_COXA2[0]=6;IKROT_COXA2[1]=6;// MOV ROT ZCOXA_L = 5
				limit = 2;
			}
			else if(STEP==HEXSTEP_FAR)
			{
				IKROT_COXA[0]=17;IKROT_COXA[1]=18;// MOV ROT ZCOXA_L = 15
				IKROT_COXA1[0]=12;IKROT_COXA1[1]=10;// MOV ROT ZCOXA_L = 10
				IKROT_COXA2[0]=6;IKROT_COXA2[1]=6;// MOV ROT ZCOXA_L = 5
				limit = 1;
			}
			else if(STEP==HEXSTEP_MED)
			{
				IKROT_COXA[0]=15;IKROT_COXA[1]=15;// MOV ROT ZCOXA_L = 10
				IKROT_COXA1[0]=10;IKROT_COXA1[1]=10;// MOV ROT ZCOXA_L = 6
				IKROT_COXA2[0]=5;IKROT_COXA2[1]=5;// MOV ROT ZCOXA_L = 3
				limit = 1;
			}
			else if(STEP==HEXSTEP_CLOSE)
			{
				IKROT_COXA[0]=10;IKROT_COXA[1]=10;// MOV ROT ZCOXA_L = 5
				IKROT_COXA1[0]=6;IKROT_COXA1[1]=6;// MOV ROT ZCOXA_L = 3
				IKROT_COXA2[0]=2;IKROT_COXA2[1]=2;// MOV ROT ZCOXA_L = 1
				limit = 1;
			}
			else
			{
				IKROT_COXA[0]=7;IKROT_COXA[1]=6;// MOV ROT ZCOXA_L = 3
				IKROT_COXA1[0]=4;IKROT_COXA1[1]=4;// MOV ROT ZCOXA_L = 2
				IKROT_COXA2[0]=2;IKROT_COXA2[1]=2;// MOV ROT ZCOXA_L = 1
				limit = 1;
			}

			for (int y=0; y<limit; y++)
			{
			//2
			//TRIPOD A
			Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
			Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);
			Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
			Start_Pose_SYNC();
			delay_ms(SPEED+2);

			//3
			//TRIPOD A
			Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA2[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
			Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA2[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA2[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//depan angkat
			Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA2[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
			Start_Pose_SYNC();
			delay_ms(SPEED+2);

			//3
			//TRIPOD A
			Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA1[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA1[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
			Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA1[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA1[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//depan angkat
			Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA1[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
//			delay_ms(5000);
			Start_Pose_SYNC();
			delay_ms(SPEED+2);

			//3
			//TRIPOD A
			Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
			Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//depan angkat
			Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
//			delay_ms(5000);
			Start_Pose_SYNC();
			delay_ms(SPEED+2);

			//3
			//TRIPOD A
			Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//belakang menapak
			Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//depan angkat
			Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
//			delay_ms(5000);
			Start_Pose_SYNC();
			delay_ms(SPEED+2);

			//4
			//TRIPOD B
			Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
			Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
			//TRIPOD A
			Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//belakang angkat
			Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
//			delay_ms(5000);
			Start_Pose_SYNC();
			delay_ms(SPEED+2);

			//4
			//TRIPOD B
			Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA1[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA1[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
			Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA1[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
			//TRIPOD A
			Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA1[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//belakang angkat
			Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA1[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
			Start_Pose_SYNC();
			delay_ms(SPEED+2);

			//4
			//TRIPOD B
			Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKROT_COXA2[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]+IKROT_COXA2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);		//depan menapak
			Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKROT_COXA2[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
			//TRIPOD A
			Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKROT_COXA2[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]+IKROT_COXA2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//belakang angkat
			Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKROT_COXA2[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
			Start_Pose_SYNC();
			delay_ms(SPEED+2);

			//5
			//TRIPOD A
			Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);//tengah angkat
			Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
			Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);
//			delay_ms(5000);
			Start_Pose_SYNC();
			delay_ms(SPEED+2);

			//6
			//TRIPOD A
			Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA2[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
			Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA2[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA2[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
			Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA2[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
//			delay_ms(5000);
			Start_Pose_SYNC();
			delay_ms(SPEED+2);

			//6
			//TRIPOD A
			Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA1[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
			Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA1[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA1[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA1[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
			Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA1[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
//			delay_ms(5000);
			Start_Pose_SYNC();
			delay_ms(SPEED+2);

			//6
			//TRIPOD A
			Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]);	//depan angkat
			Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
			Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
//			delay_ms(5000);
			Start_Pose_SYNC();
			delay_ms(SPEED+2);

			//6
			//TRIPOD A
			Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan angkat
			Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA[0],SUDUT_STATIC[10],SUDUT_STATIC[11]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA[1],SUDUT_STATIC[13],SUDUT_STATIC[14]);	//belakang menapak
			Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA[0],SUDUT_STATIC[16],SUDUT_STATIC[17]);
//			delay_ms(5000);
			Start_Pose_SYNC();
			delay_ms(SPEED+2);

			//1
			//TRIPOD A
			Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
			Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//belakang angkat
			Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
//			delay_ms(5000);
			Start_Pose_SYNC();
			delay_ms(SPEED+2);

			//1
			//TRIPOD A
			Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA1[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA1[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
			Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA1[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA1[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//belakang angkat
			Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA1[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
//			delay_ms(5000);
			Start_Pose_SYNC();
			delay_ms(SPEED+2);

			//1
			//TRIPOD A
			Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKROT_COXA2[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]-IKROT_COXA2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]);	//depan menapak
			Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKROT_COXA2[0],SUDUT_STATIC[7],SUDUT_STATIC[8]);
			//TRIPOD B
			Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKROT_COXA2[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]);
			Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]-IKROT_COXA2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]);	//belakang angkat
			Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKROT_COXA2[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]);
//			delay_ms(5000);
			Start_Pose_SYNC();
			delay_ms(SPEED+2);
			}
		}break;
	}

}

void Dynamx_Rot_Obs_Left_IK(int SPEED, int STEP)
{
	int loop;
	int limit;
	SPEED = SPEED/48;

	if (STEP == STEP1)
	{
		Generate_Body(0,0.75);
		Trajectory_Generator_Obs(X_Diff, Y_Diff, -3.5, 4,MOVEMENT_NORMAL);
		limit = 1;
	}

	else if (STEP == STEP2)
	{
		Generate_Body(0,1.5);
		Trajectory_Generator_Obs(X_Diff, Y_Diff, -3.5, 4,MOVEMENT_NORMAL);
		limit = 2;
	}

	else if (STEP == STEP3)
	{
		Generate_Body(0,2.5);
		Trajectory_Generator_Obs(X_Diff, Y_Diff, -3.5, 4,MOVEMENT_NORMAL);
		limit = 2;
	}

	else if (STEP == STEP4)
	{
		Generate_Body(0,2.4);
		Trajectory_Generator_Obs(X_Diff, Y_Diff, -3.5, 4,MOVEMENT_NORMAL);
		limit = 3;
	}

	else if (STEP == STEP5)
	{
		Generate_Body(0,2);
		Trajectory_Generator_Obs(X_Diff, Y_Diff, -3.5, 4,MOVEMENT_NORMAL);
		limit = 3;
	}

	else if (STEP == STEP6)
	{
		Generate_Body(0,2.25);
		Trajectory_Generator_Obs(X_Diff, Y_Diff, -3.5, 4,MOVEMENT_NORMAL);
		limit = 3;
	}

	else if (STEP == STEP7)
	{
		Generate_Body(0,0.25);
		Trajectory_Generator_Obs(X_Diff, Y_Diff, -3.5, 4,MOVEMENT_NORMAL);
		limit = 1;
	}

	else if (STEP == STEP8)
	{
		Generate_Body(0,2.4);
		Trajectory_Generator_Obs(X_Diff, Y_Diff, -3.5, 4,MOVEMENT_NORMAL);
		limit = 1;
	}


	for(i=0;i<=3;i++)
	{
//		Dyna_IKCalc_Only((X_IK_BEGIN[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]+Z_IK[i]));
		Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_OBS[1]+Z_IK[i]));
		FEMUR_O[i] = tetha.Femur;
		COXA_O[i] = tetha.Coxa;
		NFEMUR_O[i] = (tetha.Femur*-1);
		NCOXA_O[i] = (tetha.Coxa*-1);
	}

	for(loop=1;loop<=limit;loop++)
	{
		if(mode_scan==MODE_K1)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K2)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_cmps==MODE_CMPS_EAST)
		{
			GetCMPS11_Angle8Bit();
			if((CMPS11_Angle>=K2_EAST_LOW) && (CMPS11_Angle<=K2_EAST_UP))break;
		}
		//SIKLUS 1
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[0]),(FEMUR_O[3]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[0]),(FEMUR_O[3]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[0]),(FEMUR_O[3]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[0]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[0]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[0]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[1]),(FEMUR_O[2]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[1]),(FEMUR_O[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[1]),(FEMUR_O[2]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[1]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[1]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[1]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[2]),(FEMUR_O[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[2]),(FEMUR_O[1]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[2]),(FEMUR_O[1]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[2]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[2]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[2]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[3]),(FEMUR_O[0]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[3]),(FEMUR_O[0]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[3]),(FEMUR_O[0]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(mode_scan==MODE_K1)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K2)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_cmps==MODE_CMPS_EAST)
		{
			GetCMPS11_Angle8Bit();
			if((CMPS11_Angle>=K2_EAST_LOW) && (CMPS11_Angle<=K2_EAST_UP))break;
		}

		//SIKLUS 2
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(mode_scan==MODE_K1)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K2)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_cmps==MODE_CMPS_EAST)
		{
			GetCMPS11_Angle8Bit();
			if((CMPS11_Angle>=K2_EAST_LOW) && (CMPS11_Angle<=K2_EAST_UP))break;
		}

		//SIKLUS 3
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[2]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[2]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[2]),(FEMUR_O[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[2]),(FEMUR_O[0]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[2]),(FEMUR_O[0]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);


		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[1]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[1]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[1]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[1]),(FEMUR_O[1]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[1]),(FEMUR_O[1]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[1]),(FEMUR_O[1]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_O[0]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_O[0]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_O[0]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_O[0]),(FEMUR_O[2]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_O[0]),(FEMUR_O[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_O[0]),(FEMUR_O[2]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[1]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK_S[5]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK_S[0]),(FEMUR_O[3]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(FEMUR_O[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK_S[4]),(FEMUR_O[3]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(mode_scan==MODE_K1)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K2)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_cmps==MODE_CMPS_EAST)
		{
			GetCMPS11_Angle8Bit();
			if((CMPS11_Angle>=K2_EAST_LOW) && (CMPS11_Angle<=K2_EAST_UP))break;
		}

		//SIKLUS 4

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[0]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[0]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[0]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[0]),(FEMUR_O[3]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[0]),(FEMUR_O[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[0]),(FEMUR_O[3]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[1]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[1]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[1]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[1]),(FEMUR_O[2]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[1]),(FEMUR_O[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[1]),(FEMUR_O[2]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[2]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[2]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[2]),(FEMUR_O[1]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[2]),(FEMUR_O[1]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[2]),(FEMUR_O[1]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[3]),(FEMUR_O[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[3]),(FEMUR_O[0]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[3]),(FEMUR_O[0]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(mode_scan==MODE_K1)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K2)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_cmps==MODE_CMPS_EAST)
		{
			GetCMPS11_Angle8Bit();
			if((CMPS11_Angle>=K2_EAST_LOW) && (CMPS11_Angle<=K2_EAST_UP))break;
		}

		//SIKLUS 5
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[3]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(mode_scan==MODE_K1)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K2)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_cmps==MODE_CMPS_EAST)
		{
			GetCMPS11_Angle8Bit();
			if((CMPS11_Angle>=K2_EAST_LOW) && (CMPS11_Angle<=K2_EAST_UP))break;
		}

		//SIKLUS 6
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[2]),(FEMUR_O[0]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[2]),(FEMUR_O[0]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[2]),(FEMUR_O[0]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[2]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[2]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[2]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[1]),(FEMUR_O[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[1]),(FEMUR_O[1]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[1]),(FEMUR_O[1]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[1]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[1]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[1]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_O[0]),(FEMUR_O[2]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_O[0]),(FEMUR_O[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_O[0]),(FEMUR_O[2]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_O[0]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_O[0]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_O[0]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[1]),(FEMUR_O[3]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(FEMUR_O[3]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK_S[5]),(FEMUR_O[3]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK_S[0]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK_S[4]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(mode_scan==MODE_K1)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K2)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_cmps==MODE_CMPS_EAST)
		{
			GetCMPS11_Angle8Bit();
			if((CMPS11_Angle>=K2_EAST_LOW) && (CMPS11_Angle<=K2_EAST_UP))break;
		}

	}
}

void Dynamx_Rot_Obs_Right_IK(int SPEED, int STEP)
{
	int loop;
	int limit;
	SPEED = SPEED/48;

	if (STEP == STEP1)
	{
		Generate_Body(0,0.75);
		Trajectory_Generator_Obs(X_Diff, Y_Diff, -3.5, 4,MOVEMENT_NORMAL);
		limit = 2;
	}

	else if (STEP == STEP2)
	{
		Generate_Body(0,1.5);
		Trajectory_Generator_Obs(X_Diff, Y_Diff, -3.5, 4,MOVEMENT_NORMAL);
		limit = 2;
	}

	else if (STEP == STEP3)
	{
		Generate_Body(0,2.5);
		Trajectory_Generator_Obs(X_Diff, Y_Diff, -3.5, 4,MOVEMENT_NORMAL);
		limit = 2;
	}

	else if (STEP == STEP4)
	{
		Generate_Body(0,2.4);
		Trajectory_Generator_Obs(X_Diff, Y_Diff, -3.5, 4,MOVEMENT_NORMAL);
		limit = 3;
	}

	else if (STEP == STEP5)
	{
		Generate_Body(0,2);
		Trajectory_Generator_Obs(X_Diff, Y_Diff, -3.5, 4,MOVEMENT_NORMAL);
		limit = 3;
	}

	else if (STEP == STEP6)
	{
		Generate_Body(0,2.25);
		Trajectory_Generator_Obs(X_Diff, Y_Diff, -3.5, 4,MOVEMENT_NORMAL);
		limit = 3;
	}

	else if (STEP == STEP8)
	{
		Generate_Body(0,2.4);
		Trajectory_Generator_Obs(X_Diff, Y_Diff, -3.5, 4,MOVEMENT_NORMAL);
		limit = 1;
	}

	for(i=0;i<=3;i++)
	{
//		Dyna_IKCalc_Only((X_IK_BEGIN[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]+Z_IK[i]));
		Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_OBS[1]+Z_IK[i]));
		FEMUR_R[i] = tetha.Femur;
		COXA_R[i] = tetha.Coxa;
		NFEMUR_R[i] = (tetha.Femur*-1);
		NCOXA_R[i] = (tetha.Coxa*-1);
	}

	for(loop=1;loop<=limit;loop++)
	{
		if(mode_scan==MODE_K1)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K2)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_cmps==MODE_CMPS_EAST)
		{
			GetCMPS11_Angle8Bit();
			if((CMPS11_Angle >= R9_SOUTH_LOW) && (CMPS11_Angle <= R9_SOUTH_UP))break;
		}
		//SIKLUS 1
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_R[0]),(FEMUR_R[3]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_R[0]),(FEMUR_R[3]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_R[0]),(FEMUR_R[3]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_R[0]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_R[0]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_R[0]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_R[1]),(FEMUR_R[2]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_R[1]),(FEMUR_R[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_R[1]),(FEMUR_R[2]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_R[1]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_R[1]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_R[1]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_R[2]),(FEMUR_R[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_R[2]),(FEMUR_R[1]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_R[2]),(FEMUR_R[1]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_R[2]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_R[2]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_R[2]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_R[3]),(FEMUR_R[0]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_R[3]),(FEMUR_R[0]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_R[3]),(FEMUR_R[0]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_R[3]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_R[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_R[3]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(mode_scan==MODE_K1)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K2)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_cmps==MODE_CMPS_EAST)
		{
			GetCMPS11_Angle8Bit();
			if((CMPS11_Angle >= R9_SOUTH_LOW) && (CMPS11_Angle <= R9_SOUTH_UP))break;
		}

		//SIKLUS 2
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_R[3]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_R[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_R[3]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_R[3]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_R[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_R[3]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_R[3]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_R[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_R[3]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_R[3]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_R[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_R[3]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_R[3]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_R[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_R[3]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_R[3]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_R[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_R[3]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_R[3]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_R[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_R[3]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_R[3]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_R[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_R[3]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(mode_scan==MODE_K1)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K2)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_cmps==MODE_CMPS_EAST)
		{
			GetCMPS11_Angle8Bit();
			if((CMPS11_Angle >= R9_SOUTH_LOW) && (CMPS11_Angle <= R9_SOUTH_UP))break;
		}

		//SIKLUS 3
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_R[2]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_R[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_R[2]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_R[2]),(FEMUR_R[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_R[2]),(FEMUR_R[0]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_R[2]),(FEMUR_R[0]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);


		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_R[1]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_R[1]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_R[1]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_R[1]),(FEMUR_R[1]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_R[1]),(FEMUR_R[1]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_R[1]),(FEMUR_R[1]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_R[0]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_R[0]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_R[0]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_R[0]),(FEMUR_R[2]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_R[0]),(FEMUR_R[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_R[0]),(FEMUR_R[2]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[1]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK_S[5]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK_S[0]),(FEMUR_R[3]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(FEMUR_R[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK_S[4]),(FEMUR_R[3]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(mode_scan==MODE_K1)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K2)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_cmps==MODE_CMPS_EAST)
		{
			GetCMPS11_Angle8Bit();
			if((CMPS11_Angle >= R9_SOUTH_LOW) && (CMPS11_Angle <= R9_SOUTH_UP))break;
		}

		//SIKLUS 4
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_R[0]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_R[0]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_R[0]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_R[0]),(FEMUR_R[3]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_R[0]),(FEMUR_R[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_R[0]),(FEMUR_R[3]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_R[1]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_R[1]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_R[1]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_R[1]),(FEMUR_R[2]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_R[1]),(FEMUR_R[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_R[1]),(FEMUR_R[2]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_R[2]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_R[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_R[2]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_R[2]),(FEMUR_R[1]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_R[2]),(FEMUR_R[1]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_R[2]),(FEMUR_R[1]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_R[3]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_R[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_R[3]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_R[3]),(FEMUR_R[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_R[3]),(FEMUR_R[0]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_R[3]),(FEMUR_R[0]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(mode_scan==MODE_K1)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K2)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_cmps==MODE_CMPS_EAST)
		{
			GetCMPS11_Angle8Bit();
			if((CMPS11_Angle >= R9_SOUTH_LOW) && (CMPS11_Angle <= R9_SOUTH_UP))break;
		}

		//SIKLUS 5
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_R[3]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_R[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_R[3]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_R[3]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_R[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_R[3]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_R[3]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_R[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_R[3]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_R[3]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_R[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_R[3]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_R[3]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_R[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_R[3]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_R[3]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_R[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_R[3]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_R[3]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_R[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_R[3]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_R[3]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_R[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_R[3]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(mode_scan==MODE_K1)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K2)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_cmps==MODE_CMPS_EAST)
		{
			GetCMPS11_Angle8Bit();
			if((CMPS11_Angle >= R9_SOUTH_LOW) && (CMPS11_Angle <= R9_SOUTH_UP))break;
		}

		//SIKLUS 6
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_R[2]),(FEMUR_R[0]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_R[2]),(FEMUR_R[0]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_R[2]),(FEMUR_R[0]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_R[2]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_R[2]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_R[2]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_R[1]),(FEMUR_R[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_R[1]),(FEMUR_R[1]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_R[1]),(FEMUR_R[1]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_R[1]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_R[1]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_R[1]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_R[0]),(FEMUR_R[2]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_R[0]),(FEMUR_R[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_R[0]),(FEMUR_R[2]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_R[0]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_R[0]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_R[0]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[1]),(FEMUR_R[3]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(FEMUR_R[3]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK_S[5]),(FEMUR_R[3]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK_S[0]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK_S[4]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(mode_scan==MODE_K1)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_scan==MODE_K2)
		{
			if((VL_SENSOR[0] < 250) && (SHARP_GRIPPER[0] < 10))break;
		}
		if(mode_cmps==MODE_CMPS_EAST)
		{
			GetCMPS11_Angle8Bit();
			if((CMPS11_Angle >= R9_SOUTH_LOW) && (CMPS11_Angle <= R9_SOUTH_UP))break;
		}
	}
}

void Dynamx_Slide_Left_Interpolate(int STEP, int SPEED)
{
	SPEED = SPEED/14+4;

	//TRIPOD A
	Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
	Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
	Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
	//TRIPOD B
	Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
	Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);
	Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
	Start_Pose_SYNC();
	delay_ms(SPEED);

	//TRIPOD A
	Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKSLR_COXA2[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKSLR_TIBIA2[0]);
	Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4],SUDUT_STATIC[5]-IKSLR_TIBIA2[2]);	//kiri menapak
	Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKSLR_COXA2[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKSLR_TIBIA2[0]);
	//TRIPOD B
	Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKSLR_COXA2[2] ,SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+IKSLR_TIBIA2[0]+5);
	Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKSLR_TIBIA2[2]-5);	//kanan angkat
	Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKSLR_COXA2[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKSLR_TIBIA2[0]+5);
	Start_Pose_SYNC();
	delay_ms(SPEED);

	//TRIPOD A
	Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKSLR_COXA1[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKSLR_TIBIA1[0]);
	Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4],SUDUT_STATIC[5]-IKSLR_TIBIA1[2]);	//kiri menapak
	Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKSLR_COXA1[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKSLR_TIBIA1[0]);
	//TRIPOD B
	Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKSLR_COXA1[2] ,SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+IKSLR_TIBIA1[0]+5);
	Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKSLR_TIBIA1[2]-5);	//kanan angkat
	Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKSLR_COXA1[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKSLR_TIBIA1[0]+5);
	Start_Pose_SYNC();
	delay_ms(SPEED);

	//TRIPOD A
	Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKSLR_COXA[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKSLR_TIBIA[0]);
	Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4],SUDUT_STATIC[5]-IKSLR_TIBIA[2]);	//kiri menapak
	Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKSLR_COXA[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKSLR_TIBIA[0]);
	//TRIPOD B
	Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKSLR_COXA[2] ,SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+IKSLR_TIBIA[0]+5);
	Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKSLR_TIBIA[2]-5);	//kanan angkat
	Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKSLR_COXA[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKSLR_TIBIA[0]+5);
	Start_Pose_SYNC();
	delay_ms(SPEED);

	//TRIPOD A
	Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKSLR_COXA[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKSLR_TIBIA[0]);
	Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4],SUDUT_STATIC[5]-IKSLR_TIBIA[2]);	//kiri menapak
	Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKSLR_COXA[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKSLR_TIBIA[0]);
	//TRIPOD B
	Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKSLR_COXA[2] ,SUDUT_STATIC[10],SUDUT_STATIC[11]+IKSLR_TIBIA[0]+5);
	Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13],SUDUT_STATIC[14]-IKSLR_TIBIA[2]-5);	//kanan angkat
	Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKSLR_COXA[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKSLR_TIBIA[0]+5);
	Start_Pose_SYNC();
	delay_ms(SPEED);

	//TRIPOD B
	Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKSLR_COXA[2] ,SUDUT_STATIC[10],SUDUT_STATIC[11]+IKSLR_TIBIA[0]);
	Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13],SUDUT_STATIC[14]-IKSLR_TIBIA[2]); //kanan menapak
	Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKSLR_COXA[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKSLR_TIBIA[0]);
	//TRIPOD A
	Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKSLR_COXA[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
	Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//kiri angkat
	Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKSLR_COXA[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
	Start_Pose_SYNC();
	delay_ms(SPEED);

	//TRIPOD B
	Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKSLR_COXA1[2] ,SUDUT_STATIC[10],SUDUT_STATIC[11]+IKSLR_TIBIA1[0]);
	Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13],SUDUT_STATIC[14]-IKSLR_TIBIA1[2]); //kanan menapak
	Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKSLR_COXA1[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKSLR_TIBIA1[0]);
	//TRIPOD A
	Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKSLR_COXA1[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
	Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//kiri angkat
	Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKSLR_COXA1[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
	Start_Pose_SYNC();
	delay_ms(SPEED);

	//TRIPOD B
	Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKSLR_COXA2[2] ,SUDUT_STATIC[10],SUDUT_STATIC[11]+IKSLR_TIBIA2[0]);
	Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13],SUDUT_STATIC[14]-IKSLR_TIBIA2[2]); //kanan menapak
	Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKSLR_COXA2[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKSLR_TIBIA2[0]);
	//TRIPOD A
	Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKSLR_COXA2[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
	Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//kiri angkat
	Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKSLR_COXA2[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
	Start_Pose_SYNC();
	delay_ms(SPEED);

	//TRIPOD A
	Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
	Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);//tengah angkat
	Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
	//TRIPOD B
	Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
	Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
	Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);
	Start_Pose_SYNC();
	delay_ms(SPEED);

	//TRIPOD A
	Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKSLR_COXA2[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKSLR_TIBIA2[3]-5);
	Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+IKSLR_TIBIA2[1]+5);	//kanan angkat
	Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKSLR_COXA2[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]-IKSLR_TIBIA2[3]-5);
	//TRIPOD B
	Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKSLR_COXA2[0] ,SUDUT_STATIC[10],SUDUT_STATIC[11]-IKSLR_TIBIA2[3]);
	Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13],SUDUT_STATIC[14]+IKSLR_TIBIA2[1]);	//kiri menapak
	Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKSLR_COXA2[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKSLR_TIBIA2[3]);
	Start_Pose_SYNC();
	delay_ms(SPEED);

	//TRIPOD A
	Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKSLR_COXA1[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKSLR_TIBIA1[3]-5);
	Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+IKSLR_TIBIA1[1]+5);	//kanan angkat
	Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKSLR_COXA1[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]-IKSLR_TIBIA1[3]-5);
	//TRIPOD B
	Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKSLR_COXA1[0] ,SUDUT_STATIC[10],SUDUT_STATIC[11]-IKSLR_TIBIA1[3]);
	Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13],SUDUT_STATIC[14]+IKSLR_TIBIA1[1]);	//kiri menapak
	Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKSLR_COXA1[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKSLR_TIBIA1[3]);
	Start_Pose_SYNC();
	delay_ms(SPEED);

	//TRIPOD A
	Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKSLR_COXA[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKSLR_TIBIA[3]-5);
	Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+IKSLR_TIBIA[1]+5);	//kanan angkat
	Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKSLR_COXA[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]-IKSLR_TIBIA[3]-5);
	//TRIPOD B
	Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKSLR_COXA[0] ,SUDUT_STATIC[10],SUDUT_STATIC[11]-IKSLR_TIBIA[3]);
	Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13],SUDUT_STATIC[14]+IKSLR_TIBIA[1]);	//kiri menapak
	Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKSLR_COXA[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKSLR_TIBIA[3]);
	Start_Pose_SYNC();
	delay_ms(SPEED);

	//TRIPOD A
	Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKSLR_COXA[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKSLR_TIBIA[3]);
	Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4],SUDUT_STATIC[5]+IKSLR_TIBIA[1]);	//kanan menapak
	Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKSLR_COXA[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKSLR_TIBIA[3]);
	//TRIPOD B
	Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKSLR_COXA[0] ,SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
	Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]			    ,SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//kiri angkat
	Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKSLR_COXA[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
	Start_Pose_SYNC();
	delay_ms(SPEED);

	//TRIPOD A
	Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKSLR_COXA[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKSLR_TIBIA[3]);
	Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4],SUDUT_STATIC[5]+IKSLR_TIBIA[1]);	//kanan menapak
	Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKSLR_COXA[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKSLR_TIBIA[3]);
	//TRIPOD B
	Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKSLR_COXA[0] ,SUDUT_STATIC[10],SUDUT_STATIC[11]+SUDUT_ANGKAT);
	Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]			    ,SUDUT_STATIC[13],SUDUT_STATIC[14]+SUDUT_ANGKAT);	//kiri angkat
	Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKSLR_COXA[0],SUDUT_STATIC[16],SUDUT_STATIC[17]+SUDUT_ANGKAT);
	Start_Pose_SYNC();
	delay_ms(SPEED);

	//TRIPOD A
	Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKSLR_COXA1[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKSLR_TIBIA1[3]);
	Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4],SUDUT_STATIC[5]+IKSLR_TIBIA1[1]);	//kanan menapak
	Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKSLR_COXA1[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKSLR_TIBIA1[3]);
	//TRIPOD B
	Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKSLR_COXA1[0] ,SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
	Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]			    ,SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//kiri angkat
	Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKSLR_COXA1[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
	Start_Pose_SYNC();
	delay_ms(SPEED);

	//TRIPOD A
	Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKSLR_COXA2[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKSLR_TIBIA2[3]);
	Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4],SUDUT_STATIC[5]+IKSLR_TIBIA2[1]);	//kanan menapak
	Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKSLR_COXA2[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKSLR_TIBIA2[3]);
	//TRIPOD B
	Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKSLR_COXA2[0] ,SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
	Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]			    ,SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//kiri angkat
	Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKSLR_COXA2[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
	Start_Pose_SYNC();
	delay_ms(SPEED);
}

void Dynamx_Slide_Right_Interpolate(int STEP, int SPEED)
{
	SPEED = SPEED/14+4;

	//TRIPOD A
	Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2]);
	Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5]);
	Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]);
	//TRIPOD B
	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
	Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);
	Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
	Start_Pose_SYNC();
	delay_ms(SPEED);

	//TRIPOD A
	Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKSLR_COXA2[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKSLR_TIBIA2[0]);
	Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4],SUDUT_STATIC[5]-IKSLR_TIBIA2[2]);	//kiri menapak
	Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKSLR_COXA2[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKSLR_TIBIA2[0]);
	//TRIPOD B
	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKSLR_COXA2[2] ,SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+IKSLR_TIBIA2[0]+5);
	Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKSLR_TIBIA2[2]-5);	//kanan angkat
	Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKSLR_COXA2[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKSLR_TIBIA2[0]+5);
	Start_Pose_SYNC();
	delay_ms(SPEED);

	//TRIPOD A
	Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKSLR_COXA1[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKSLR_TIBIA1[0]);
	Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4],SUDUT_STATIC[5]-IKSLR_TIBIA1[2]);	//kiri menapak
	Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKSLR_COXA1[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKSLR_TIBIA1[0]);
	//TRIPOD B
	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKSLR_COXA1[2] ,SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+IKSLR_TIBIA1[0]+5);
	Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKSLR_TIBIA1[2]-5);	//kanan angkat
	Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKSLR_COXA1[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKSLR_TIBIA1[0]+5);
	Start_Pose_SYNC();
	delay_ms(SPEED);

	//TRIPOD A
	Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKSLR_COXA[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKSLR_TIBIA[0]);
	Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4],SUDUT_STATIC[5]-IKSLR_TIBIA[2]);	//kiri menapak
	Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKSLR_COXA[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKSLR_TIBIA[0]);
	//TRIPOD B
	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKSLR_COXA[2] ,SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+IKSLR_TIBIA[0]+5);
	Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKSLR_TIBIA[2]-5);	//kanan angkat
	Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKSLR_COXA[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKSLR_TIBIA[0]+5);
	Start_Pose_SYNC();
	delay_ms(SPEED);

	//TRIPOD A
	Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKSLR_COXA[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKSLR_TIBIA[0]);
	Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4],SUDUT_STATIC[5]-IKSLR_TIBIA[2]);	//kiri menapak
	Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKSLR_COXA[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKSLR_TIBIA[0]);
	//TRIPOD B
	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKSLR_COXA[2] ,SUDUT_STATIC[10],SUDUT_STATIC[11]+IKSLR_TIBIA[0]+5);
	Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13],SUDUT_STATIC[14]-IKSLR_TIBIA[2]-5);	//kanan angkat
	Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKSLR_COXA[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKSLR_TIBIA[0]+5);
	Start_Pose_SYNC();
	delay_ms(SPEED);

	//TRIPOD B
	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKSLR_COXA[2] ,SUDUT_STATIC[10],SUDUT_STATIC[11]+IKSLR_TIBIA[0]);
	Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13],SUDUT_STATIC[14]-IKSLR_TIBIA[2]); //kanan menapak
	Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKSLR_COXA[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKSLR_TIBIA[0]);
	//TRIPOD A
	Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKSLR_COXA[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
	Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//kiri angkat
	Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKSLR_COXA[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
	Start_Pose_SYNC();
	delay_ms(SPEED);

	//TRIPOD B
	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKSLR_COXA1[2] ,SUDUT_STATIC[10],SUDUT_STATIC[11]+IKSLR_TIBIA1[0]);
	Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13],SUDUT_STATIC[14]-IKSLR_TIBIA1[2]); //kanan menapak
	Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKSLR_COXA1[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKSLR_TIBIA1[0]);
	//TRIPOD A
	Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKSLR_COXA1[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
	Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//kiri angkat
	Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKSLR_COXA1[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
	Start_Pose_SYNC();
	delay_ms(SPEED);

	//TRIPOD B
	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]+IKSLR_COXA2[2] ,SUDUT_STATIC[10],SUDUT_STATIC[11]+IKSLR_TIBIA2[0]);
	Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13],SUDUT_STATIC[14]-IKSLR_TIBIA2[2]); //kanan menapak
	Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]-IKSLR_COXA2[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKSLR_TIBIA2[0]);
	//TRIPOD A
	Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]+IKSLR_COXA2[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
	Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);	//kiri angkat
	Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]-IKSLR_COXA2[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
	Start_Pose_SYNC();
	delay_ms(SPEED);

	//TRIPOD A
	Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT);
	Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT);//tengah angkat
	Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT);
	//TRIPOD B
	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11]);
	Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14]);
	Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17]);
	Start_Pose_SYNC();
	delay_ms(SPEED);

	//TRIPOD A
	Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKSLR_COXA2[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKSLR_TIBIA2[3]-5);
	Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+IKSLR_TIBIA2[1]+5);	//kanan angkat
	Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKSLR_COXA2[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]-IKSLR_TIBIA2[3]-5);
	//TRIPOD B
	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKSLR_COXA2[0] ,SUDUT_STATIC[10],SUDUT_STATIC[11]-IKSLR_TIBIA2[3]);
	Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13],SUDUT_STATIC[14]+IKSLR_TIBIA2[1]);	//kiri menapak
	Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKSLR_COXA2[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKSLR_TIBIA2[3]);
	Start_Pose_SYNC();
	delay_ms(SPEED);

	//TRIPOD A
	Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKSLR_COXA1[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKSLR_TIBIA1[3]-5);
	Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+IKSLR_TIBIA1[1]+5);	//kanan angkat
	Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKSLR_COXA1[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]-IKSLR_TIBIA1[3]-5);
	//TRIPOD B
	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKSLR_COXA1[0] ,SUDUT_STATIC[10],SUDUT_STATIC[11]-IKSLR_TIBIA1[3]);
	Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13],SUDUT_STATIC[14]+IKSLR_TIBIA1[1]);	//kiri menapak
	Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKSLR_COXA1[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKSLR_TIBIA1[3]);
	Start_Pose_SYNC();
	delay_ms(SPEED);

	//TRIPOD A
	Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKSLR_COXA[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKSLR_TIBIA[3]-5);
	Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+IKSLR_TIBIA[1]+5);	//kanan angkat
	Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKSLR_COXA[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]-IKSLR_TIBIA[3]-5);
	//TRIPOD B
	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKSLR_COXA[0] ,SUDUT_STATIC[10],SUDUT_STATIC[11]-IKSLR_TIBIA[3]);
	Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]				,SUDUT_STATIC[13],SUDUT_STATIC[14]+IKSLR_TIBIA[1]);	//kiri menapak
	Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKSLR_COXA[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKSLR_TIBIA[3]);
	Start_Pose_SYNC();
	delay_ms(SPEED);

	//TRIPOD A
	Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKSLR_COXA[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKSLR_TIBIA[3]);
	Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4],SUDUT_STATIC[5]+IKSLR_TIBIA[1]);	//kanan menapak
	Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKSLR_COXA[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKSLR_TIBIA[3]);
	//TRIPOD B
	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKSLR_COXA[0] ,SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
	Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]			    ,SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//kiri angkat
	Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKSLR_COXA[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
	Start_Pose_SYNC();
	delay_ms(SPEED);

	//TRIPOD A
	Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKSLR_COXA[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKSLR_TIBIA[3]);
	Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4],SUDUT_STATIC[5]+IKSLR_TIBIA[1]);	//kanan menapak
	Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKSLR_COXA[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKSLR_TIBIA[3]);
	//TRIPOD B
	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKSLR_COXA[0] ,SUDUT_STATIC[10],SUDUT_STATIC[11]+SUDUT_ANGKAT);
	Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]			    ,SUDUT_STATIC[13],SUDUT_STATIC[14]+SUDUT_ANGKAT);	//kiri angkat
	Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKSLR_COXA[0],SUDUT_STATIC[16],SUDUT_STATIC[17]+SUDUT_ANGKAT);
	Start_Pose_SYNC();
	delay_ms(SPEED);

	//TRIPOD A
	Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKSLR_COXA1[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKSLR_TIBIA1[3]);
	Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4],SUDUT_STATIC[5]+IKSLR_TIBIA1[1]);	//kanan menapak
	Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKSLR_COXA1[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKSLR_TIBIA1[3]);
	//TRIPOD B
	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKSLR_COXA1[0] ,SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
	Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]			    ,SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//kiri angkat
	Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKSLR_COXA1[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
	Start_Pose_SYNC();
	delay_ms(SPEED);

	//TRIPOD A
	Dynamx_MoveLeg_Interpolate(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC[0]-IKSLR_COXA2[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKSLR_TIBIA2[3]);
	Dynamx_MoveLeg_Interpolate(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC[3]			   ,SUDUT_STATIC[4],SUDUT_STATIC[5]+IKSLR_TIBIA2[1]);	//kanan menapak
	Dynamx_MoveLeg_Interpolate(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC[6]+IKSLR_COXA2[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKSLR_TIBIA2[3]);
	//TRIPOD B
	Dynamx_MoveLeg_Interpolate(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC[9]-IKSLR_COXA2[0] ,SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT);
	Dynamx_MoveLeg_Interpolate(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC[12]			    ,SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT);	//kiri angkat
	Dynamx_MoveLeg_Interpolate(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC[15]+IKSLR_COXA2[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT);
	Start_Pose_SYNC();
	delay_ms(SPEED);
}

void Dynamx_Slide_Right_IK(int distance, int SPEED)
{
	int limit = distance;
	int loop;
	int cek_value = 0;

	if(IK_CALCULATED_SLD_R == 0)
	{
		Generate_Body(0,1.5);
		Trajectory_Generator_NEW(X_Diff, Y_Diff, -1.5, 4,MOVEMENT_NORMAL);
		for(i=0;i<=3;i++)
		{
			Dyna_IKCalc_Only((X_IK_BEGIN[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]+Z_IK[i]));
			FEMUR_G[i] = tetha.Femur;
			COXA_G[i] = tetha.Coxa;
			NFEMUR_G[i] = (tetha.Femur*-1);
			NCOXA_G[i] = (tetha.Coxa*-1);

			Dyna_IKCalc_Only((X_IK_BEGIN[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
			TIBIA_G[i] = tetha.Tibia;

			Dyna_IKCalc_Only((X_IK_BEGIN[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
			NTIBIA_G[i] = tetha.Tibia;

			Dyna_IKCalc_Only((X_IK_BEGIN[0]+X4_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
			TIBIA_GS[i] = tetha.Tibia;

			Dyna_IKCalc_Only((X_IK_BEGIN[0]-X4_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
			NTIBIA_GS[i] = tetha.Tibia;
		}
		IK_CALCULATED_SLD_R = 1;
		IK_CALCULATED_SLD_L = 0;
	}

	if (cek_value==1)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"TIBIA");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"%d|%d|%d|%d",FEMUR_G[0],FEMUR_G[1],FEMUR_G[2],FEMUR_G[3]);lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"Z STATIC");lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"%d|%d",Z_STATIC_IK[2],Z_STATIC_IK[3]);lcd_putstr(lcd);
		while(1){}
	}

	SPEED = SPEED/45;

	for(loop=0;loop<limit;loop++)
	{
		//SIKLUS 1
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_G[0]),(FEMUR_G[3]),(TIBIA_G[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(FEMUR_G[3]),(NTIBIA_G[0]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_G[0]),(FEMUR_G[3]),(TIBIA_G[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_G[0]),(Z_STATIC_IK[0]),(TIBIA_G[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(NTIBIA_G[0]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_G[0]),(Z_STATIC_IK[4]),(TIBIA_G[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_G[1]),(FEMUR_G[2]),(TIBIA_G[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(FEMUR_G[2]),(NTIBIA_G[1]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_G[1]),(FEMUR_G[2]),(TIBIA_G[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_G[1]),(Z_STATIC_IK[0]),(TIBIA_G[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(NTIBIA_G[1]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_G[1]),(Z_STATIC_IK[4]),(TIBIA_G[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_G[2]),(FEMUR_G[1]),(TIBIA_G[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(FEMUR_G[1]),(NTIBIA_G[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_G[2]),(FEMUR_G[1]),(TIBIA_G[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_G[2]),(Z_STATIC_IK[0]),(TIBIA_G[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(NTIBIA_G[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_G[2]),(Z_STATIC_IK[4]),(TIBIA_G[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_G[3]),(FEMUR_G[0]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(FEMUR_G[0]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_G[3]),(FEMUR_G[0]),(TIBIA_G[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[0]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_G[3]),(Z_STATIC_IK[4]),(TIBIA_G[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		//SIKLUS 2
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[1]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_G[3]),(Z_STATIC_IK[5]),(TIBIA_G[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[0]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_G[3]),(Z_STATIC_IK[4]),(TIBIA_G[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[1]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_G[3]),(Z_STATIC_IK[5]),(TIBIA_G[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[0]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_G[3]),(Z_STATIC_IK[4]),(TIBIA_G[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[1]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_G[3]),(Z_STATIC_IK[5]),(TIBIA_G[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[0]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_G[3]),(Z_STATIC_IK[4]),(TIBIA_G[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[1]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_G[3]),(Z_STATIC_IK[5]),(TIBIA_G[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[0]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_G[3]),(Z_STATIC_IK[4]),(TIBIA_G[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		//SIKLUS 3
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_G[2]),(Z_STATIC_IK[1]),(TIBIA_G[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(NTIBIA_G[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_G[2]),(Z_STATIC_IK[5]),(TIBIA_G[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_G[2]),(FEMUR_G[0]),(TIBIA_G[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(FEMUR_G[0]),(NTIBIA_G[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_G[2]),(FEMUR_G[0]),(TIBIA_G[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_G[1]),(Z_STATIC_IK[1]),(TIBIA_G[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(NTIBIA_G[1]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_G[1]),(Z_STATIC_IK[5]),(TIBIA_G[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_G[1]),(FEMUR_G[1]),(TIBIA_G[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(FEMUR_G[1]),(NTIBIA_G[1]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_G[1]),(FEMUR_G[1]),(TIBIA_G[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_G[0]),(Z_STATIC_IK[1]),(TIBIA_G[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(NTIBIA_G[0]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_G[0]),(Z_STATIC_IK[5]),(TIBIA_G[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_G[0]),(FEMUR_G[2]),(TIBIA_G[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(FEMUR_G[2]),(NTIBIA_G[0]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_G[0]),(FEMUR_G[2]),(TIBIA_G[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK[1]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK[5]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK[0]),(FEMUR_G[3]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(FEMUR_G[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK[4]),(FEMUR_G[3]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		//SIKLUS 4
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_G[0]),(Z_STATIC_IK[1]),(NTIBIA_G[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(TIBIA_G[0]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_G[0]),(Z_STATIC_IK[5]),(NTIBIA_G[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_G[0]),(FEMUR_G[3]),(NTIBIA_G[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(FEMUR_G[3]),(TIBIA_G[0]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_G[4]),(FEMUR_G[3]),(NTIBIA_G[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_G[1]),(Z_STATIC_IK[1]),(NTIBIA_G[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(TIBIA_G[1]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_G[1]),(Z_STATIC_IK[5]),(NTIBIA_G[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_G[1]),(FEMUR_G[2]),(NTIBIA_G[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(FEMUR_G[2]),(TIBIA_G[1]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_G[1]),(FEMUR_G[2]),(NTIBIA_G[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_G[2]),(Z_STATIC_IK[1]),(NTIBIA_G[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(TIBIA_G[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_G[2]),(Z_STATIC_IK[5]),(NTIBIA_G[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_G[2]),(FEMUR_G[1]),(NTIBIA_G[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(FEMUR_G[1]),(TIBIA_G[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_G[2]),(FEMUR_G[1]),(NTIBIA_G[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_G[3]),(Z_STATIC_IK[1]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[5]),(NTIBIA_G[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_G[3]),(FEMUR_G[0]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(FEMUR_G[0]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_G[3]),(FEMUR_G[0]),(NTIBIA_G[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		//SIKLUS 5
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_G[3]),(Z_STATIC_IK[1]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[5]),(NTIBIA_G[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_G[3]),(Z_STATIC_IK[0]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[4]),(NTIBIA_G[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_G[3]),(Z_STATIC_IK[1]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[5]),(NTIBIA_G[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_G[3]),(Z_STATIC_IK[0]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[4]),(NTIBIA_G[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_G[3]),(Z_STATIC_IK[1]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[5]),(NTIBIA_G[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_G[3]),(Z_STATIC_IK[0]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[4]),(NTIBIA_G[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_G[3]),(Z_STATIC_IK[1]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[5]),(NTIBIA_G[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_G[3]),(Z_STATIC_IK[0]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[4]),(NTIBIA_G[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		//SIKLUS 6
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_G[2]),(FEMUR_G[0]),(NTIBIA_G[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(FEMUR_G[0]),(TIBIA_G[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_G[2]),(FEMUR_G[0]),(NTIBIA_G[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_G[2]),(Z_STATIC_IK[0]),(NTIBIA_G[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(TIBIA_G[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_G[2]),(Z_STATIC_IK[4]),(NTIBIA_G[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_G[1]),(FEMUR_G[1]),(NTIBIA_G[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(FEMUR_G[1]),(TIBIA_G[1]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_G[1]),(FEMUR_G[1]),(NTIBIA_G[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_G[1]),(Z_STATIC_IK[0]),(NTIBIA_G[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(TIBIA_G[1]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_G[1]),(Z_STATIC_IK[4]),(NTIBIA_G[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_G[0]),(FEMUR_G[2]),(NTIBIA_G[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(FEMUR_G[2]),(TIBIA_G[0]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_G[0]),(FEMUR_G[2]),(NTIBIA_G[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_G[0]),(Z_STATIC_IK[0]),(NTIBIA_G[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(TIBIA_G[0]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_G[0]),(Z_STATIC_IK[4]),(NTIBIA_G[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK[1]),(FEMUR_G[3]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(FEMUR_G[3]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK[5]),(FEMUR_G[3]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK[0]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK[4]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

	}
}

void Dynamx_Slide_Left_IK(int distance, int SPEED)
{
	int limit = distance;
	int loop;

	if(IK_CALCULATED_SLD_L == 0)
	{
		Generate_Body(0,1.5);
		Trajectory_Generator_NEW(X_Diff, Y_Diff, -1.5, 4,MOVEMENT_NORMAL);
		for(i=0;i<=3;i++)
		{
			Dyna_IKCalc_Only((X_IK_BEGIN[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]+Z_IK[i]));
			FEMUR_G[i] = tetha.Femur;
			COXA_G[i] = tetha.Coxa;
			NFEMUR_G[i] = (tetha.Femur*-1);
			NCOXA_G[i] = (tetha.Coxa*-1);

			Dyna_IKCalc_Only((X_IK_BEGIN[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
			TIBIA_G[i] = tetha.Tibia;

			Dyna_IKCalc_Only((X_IK_BEGIN[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
			NTIBIA_G[i] = tetha.Tibia;

			Dyna_IKCalc_Only((X_IK_BEGIN[0]+X4_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
			TIBIA_GS[i] = tetha.Tibia;

			Dyna_IKCalc_Only((X_IK_BEGIN[0]-X4_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
			NTIBIA_GS[i] = tetha.Tibia;
		}
		IK_CALCULATED_SLD_R = 0;
		IK_CALCULATED_SLD_L = 1;
	}

	SPEED = SPEED/45;

	for(loop=0;loop<limit;loop++)
	{
		//SIKLUS 1
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_G[0]),(FEMUR_G[3]),(NTIBIA_G[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(FEMUR_G[3]),(TIBIA_G[0]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_G[0]),(FEMUR_G[3]),(NTIBIA_G[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_G[0]),(Z_STATIC_IK[0]),(NTIBIA_G[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(TIBIA_G[0]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_G[0]),(Z_STATIC_IK[4]),(NTIBIA_G[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_G[1]),(FEMUR_G[2]),(NTIBIA_G[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(FEMUR_G[2]),(TIBIA_G[1]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_G[1]),(FEMUR_G[2]),(NTIBIA_G[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_G[1]),(Z_STATIC_IK[0]),(NTIBIA_G[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(TIBIA_G[1]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_G[1]),(Z_STATIC_IK[4]),(NTIBIA_G[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_G[2]),(FEMUR_G[1]),(NTIBIA_G[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(FEMUR_G[1]),(TIBIA_G[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_G[2]),(FEMUR_G[1]),(NTIBIA_G[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_G[2]),(Z_STATIC_IK[0]),(NTIBIA_G[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(TIBIA_G[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_G[2]),(Z_STATIC_IK[4]),(NTIBIA_G[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_G[3]),(FEMUR_G[0]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(FEMUR_G[0]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_G[3]),(FEMUR_G[0]),(NTIBIA_G[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_G[3]),(Z_STATIC_IK[0]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[4]),(NTIBIA_G[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		//SIKLUS 2
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_G[3]),(Z_STATIC_IK[1]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[5]),(NTIBIA_G[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_G[3]),(Z_STATIC_IK[0]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[4]),(NTIBIA_G[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_G[3]),(Z_STATIC_IK[1]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[5]),(NTIBIA_G[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_G[3]),(Z_STATIC_IK[0]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[4]),(NTIBIA_G[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_G[3]),(Z_STATIC_IK[1]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[5]),(NTIBIA_G[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_G[3]),(Z_STATIC_IK[0]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[4]),(NTIBIA_G[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_G[3]),(Z_STATIC_IK[1]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[5]),(NTIBIA_G[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_G[3]),(Z_STATIC_IK[0]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[4]),(NTIBIA_G[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		//SIKLUS 3
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_G[2]),(Z_STATIC_IK[1]),(NTIBIA_G[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(TIBIA_G[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_G[2]),(Z_STATIC_IK[5]),(NTIBIA_G[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_G[2]),(FEMUR_G[0]),(NTIBIA_G[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(FEMUR_G[0]),(TIBIA_G[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_G[2]),(FEMUR_G[0]),(NTIBIA_G[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_G[1]),(Z_STATIC_IK[1]),(NTIBIA_G[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(TIBIA_G[1]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_G[1]),(Z_STATIC_IK[5]),(NTIBIA_G[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_G[1]),(FEMUR_G[1]),(NTIBIA_G[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(FEMUR_G[1]),(TIBIA_G[1]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_G[1]),(FEMUR_G[1]),(NTIBIA_G[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_G[0]),(Z_STATIC_IK[1]),(NTIBIA_G[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(TIBIA_G[0]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_G[0]),(Z_STATIC_IK[5]),(NTIBIA_G[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_G[0]),(FEMUR_G[2]),(NTIBIA_G[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(FEMUR_G[2]),(TIBIA_G[0]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_G[0]),(FEMUR_G[2]),(NTIBIA_G[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK[1]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK[5]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK[0]),(FEMUR_G[3]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(FEMUR_G[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK[4]),(FEMUR_G[3]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		//SIKLUS 4
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_G[0]),(Z_STATIC_IK[1]),(TIBIA_G[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(NTIBIA_G[0]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_G[0]),(Z_STATIC_IK[5]),(TIBIA_G[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_G[0]),(FEMUR_G[3]),(TIBIA_G[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(FEMUR_G[3]),(NTIBIA_G[0]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_G[4]),(FEMUR_G[3]),(TIBIA_G[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_G[1]),(Z_STATIC_IK[1]),(TIBIA_G[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(NTIBIA_G[1]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_G[1]),(Z_STATIC_IK[5]),(TIBIA_G[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_G[1]),(FEMUR_G[2]),(TIBIA_G[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(FEMUR_G[2]),(NTIBIA_G[1]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_G[1]),(FEMUR_G[2]),(TIBIA_G[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_G[2]),(Z_STATIC_IK[1]),(TIBIA_G[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(NTIBIA_G[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_G[2]),(Z_STATIC_IK[5]),(TIBIA_G[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_G[2]),(FEMUR_G[1]),(TIBIA_G[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(FEMUR_G[1]),(NTIBIA_G[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_G[2]),(FEMUR_G[1]),(TIBIA_G[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[1]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_G[3]),(Z_STATIC_IK[5]),(TIBIA_G[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_G[3]),(FEMUR_G[0]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(FEMUR_G[0]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_G[3]),(FEMUR_G[0]),(TIBIA_G[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		//SIKLUS 5
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[1]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_G[3]),(Z_STATIC_IK[5]),(TIBIA_G[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[0]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_G[3]),(Z_STATIC_IK[4]),(TIBIA_G[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[1]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_G[3]),(Z_STATIC_IK[5]),(TIBIA_G[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[0]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_G[3]),(Z_STATIC_IK[4]),(TIBIA_G[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[1]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_G[3]),(Z_STATIC_IK[5]),(TIBIA_G[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[0]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_G[3]),(Z_STATIC_IK[4]),(TIBIA_G[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[1]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_G[3]),(Z_STATIC_IK[5]),(TIBIA_G[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_G[3]),(Z_STATIC_IK[0]),(TIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(NTIBIA_G[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_G[3]),(Z_STATIC_IK[4]),(TIBIA_G[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		//SIKLUS 6
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_G[2]),(FEMUR_G[0]),(TIBIA_G[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(FEMUR_G[0]),(NTIBIA_G[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_G[2]),(FEMUR_G[0]),(TIBIA_G[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_G[2]),(Z_STATIC_IK[0]),(TIBIA_G[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(NTIBIA_G[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_G[2]),(Z_STATIC_IK[4]),(TIBIA_G[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_G[1]),(FEMUR_G[1]),(TIBIA_G[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(FEMUR_G[1]),(NTIBIA_G[1]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_G[1]),(FEMUR_G[1]),(TIBIA_G[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_G[1]),(Z_STATIC_IK[0]),(TIBIA_G[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(NTIBIA_G[1]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_G[1]),(Z_STATIC_IK[4]),(TIBIA_G[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_G[0]),(FEMUR_G[2]),(TIBIA_G[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(FEMUR_G[2]),(NTIBIA_G[0]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_G[0]),(FEMUR_G[2]),(TIBIA_G[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_G[0]),(Z_STATIC_IK[0]),(TIBIA_G[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(NTIBIA_G[0]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_G[0]),(Z_STATIC_IK[4]),(TIBIA_G[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK[1]),(FEMUR_G[3]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(FEMUR_G[3]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK[5]),(FEMUR_G[3]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK[0]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK[4]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);


	}


}

void Dynamx_Slide_Obs_Right_IK(int distance, int SPEED)
{
	int limit = distance;
	int loop;

	if(IK_CALCULATED_SLD_R_OBS == 0)
	{
		if(mode_slide_finish==MODE_SLIDE_FINISH)
		{
			Generate_Body(0,1);
		}
		else
		{
			Generate_Body(0,1.5);
		}
		Trajectory_Generator_Obs(X_Diff, Y_Diff, -2.5, 4,MOVEMENT_NORMAL);
		for(i=0;i<=3;i++)
		{
			Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_OBS[1]+Z_IK[i]));
			FEMUR_H[i] = tetha.Femur;
			COXA_H[i] = tetha.Coxa;
			NFEMUR_H[i] = (tetha.Femur*-1);
			NCOXA_H[i] = (tetha.Coxa*-1);

			Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_OBS[1]));
			TIBIA_H[i] = tetha.Tibia;

			Dyna_IKCalc_Only((X_IK_OBS[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_OBS[1]));
			NTIBIA_H[i] = tetha.Tibia;

			Dyna_IKCalc_Only((X_IK_OBS[0]+X4_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_OBS[1]));
			TIBIA_HS[i] = tetha.Tibia;

			Dyna_IKCalc_Only((X_IK_OBS[0]-X4_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_OBS[1]));
			NTIBIA_HS[i] = tetha.Tibia;
		}
		IK_CALCULATED_SLD_R_OBS = 1;
		IK_CALCULATED_SLD_L_OBS = 0;
	}

	SPEED = SPEED/45;

	for(loop=0;loop<limit;loop++)
	{
		//SIKLUS 1
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_H[0]),(FEMUR_H[3]),(TIBIA_H[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(FEMUR_H[3]),(NTIBIA_H[0]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_H[0]),(FEMUR_H[3]),(TIBIA_H[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_H[0]),(Z_STATIC_IK_S[0]),(TIBIA_H[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(NTIBIA_H[0]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_H[0]),(Z_STATIC_IK_S[4]),(TIBIA_H[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_H[1]),(FEMUR_H[2]),(TIBIA_H[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(FEMUR_H[2]),(NTIBIA_H[1]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_H[1]),(FEMUR_H[2]),(TIBIA_H[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_H[1]),(Z_STATIC_IK_S[0]),(TIBIA_H[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(NTIBIA_H[1]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_H[1]),(Z_STATIC_IK_S[4]),(TIBIA_H[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_H[2]),(FEMUR_H[1]),(TIBIA_H[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(FEMUR_H[1]),(NTIBIA_H[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_H[2]),(FEMUR_H[1]),(TIBIA_H[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_H[2]),(Z_STATIC_IK_S[0]),(TIBIA_H[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(NTIBIA_H[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_H[2]),(Z_STATIC_IK_S[4]),(TIBIA_H[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_H[3]),(FEMUR_H[0]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(FEMUR_H[0]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_H[3]),(FEMUR_H[0]),(TIBIA_H[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[0]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[4]),(TIBIA_H[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		//SIKLUS 2
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[1]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[5]),(TIBIA_H[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[0]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[4]),(TIBIA_H[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[1]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[5]),(TIBIA_H[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[0]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[4]),(TIBIA_H[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[1]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[5]),(TIBIA_H[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[0]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[4]),(TIBIA_H[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[1]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[5]),(TIBIA_H[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[0]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[4]),(TIBIA_H[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		//SIKLUS 3
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_H[2]),(Z_STATIC_IK_S[1]),(TIBIA_H[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(NTIBIA_H[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_H[2]),(Z_STATIC_IK_S[5]),(TIBIA_H[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_H[2]),(FEMUR_H[0]),(TIBIA_H[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(FEMUR_H[0]),(NTIBIA_H[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_H[2]),(FEMUR_H[0]),(TIBIA_H[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_H[1]),(Z_STATIC_IK_S[1]),(TIBIA_H[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(NTIBIA_H[1]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_H[1]),(Z_STATIC_IK_S[5]),(TIBIA_H[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_H[1]),(FEMUR_H[1]),(TIBIA_H[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(FEMUR_H[1]),(NTIBIA_H[1]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_H[1]),(FEMUR_H[1]),(TIBIA_H[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_H[0]),(Z_STATIC_IK_S[1]),(TIBIA_H[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(NTIBIA_H[0]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_H[0]),(Z_STATIC_IK_S[5]),(TIBIA_H[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_H[0]),(FEMUR_H[2]),(TIBIA_H[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(FEMUR_H[2]),(NTIBIA_H[0]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_H[0]),(FEMUR_H[2]),(TIBIA_H[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[1]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK_S[5]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK_S[0]),(FEMUR_H[3]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(FEMUR_H[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK_S[4]),(FEMUR_H[3]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		//SIKLUS 4
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_H[0]),(Z_STATIC_IK_S[1]),(NTIBIA_H[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(TIBIA_H[0]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_H[0]),(Z_STATIC_IK_S[5]),(NTIBIA_H[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_H[0]),(FEMUR_H[3]),(NTIBIA_H[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(FEMUR_H[3]),(TIBIA_H[0]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_H[4]),(FEMUR_H[3]),(NTIBIA_H[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_H[1]),(Z_STATIC_IK_S[1]),(NTIBIA_H[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(TIBIA_H[1]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_H[1]),(Z_STATIC_IK_S[5]),(NTIBIA_H[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_H[1]),(FEMUR_H[2]),(NTIBIA_H[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(FEMUR_H[2]),(TIBIA_H[1]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_H[1]),(FEMUR_H[2]),(NTIBIA_H[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_H[2]),(Z_STATIC_IK_S[1]),(NTIBIA_H[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(TIBIA_H[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_H[2]),(Z_STATIC_IK_S[5]),(NTIBIA_H[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_H[2]),(FEMUR_H[1]),(NTIBIA_H[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(FEMUR_H[1]),(TIBIA_H[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_H[2]),(FEMUR_H[1]),(NTIBIA_H[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[1]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[5]),(NTIBIA_H[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_H[3]),(FEMUR_H[0]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(FEMUR_H[0]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_H[3]),(FEMUR_H[0]),(NTIBIA_H[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		//SIKLUS 5
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[1]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[5]),(NTIBIA_H[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[0]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[4]),(NTIBIA_H[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[1]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[5]),(NTIBIA_H[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[0]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[4]),(NTIBIA_H[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[1]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[5]),(NTIBIA_H[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[0]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[4]),(NTIBIA_H[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[1]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[5]),(NTIBIA_H[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[0]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[4]),(NTIBIA_H[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		//SIKLUS 6
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_H[2]),(FEMUR_H[0]),(NTIBIA_H[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(FEMUR_H[0]),(TIBIA_H[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_H[2]),(FEMUR_H[0]),(NTIBIA_H[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_H[2]),(Z_STATIC_IK_S[0]),(NTIBIA_H[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(TIBIA_H[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_H[2]),(Z_STATIC_IK_S[4]),(NTIBIA_H[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_H[1]),(FEMUR_H[1]),(NTIBIA_H[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(FEMUR_H[1]),(TIBIA_H[1]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_H[1]),(FEMUR_H[1]),(NTIBIA_H[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_H[1]),(Z_STATIC_IK_S[0]),(NTIBIA_H[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(TIBIA_H[1]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_H[1]),(Z_STATIC_IK_S[4]),(NTIBIA_H[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_H[0]),(FEMUR_H[2]),(NTIBIA_H[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(FEMUR_H[2]),(TIBIA_H[0]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_H[0]),(FEMUR_H[2]),(NTIBIA_H[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_H[0]),(Z_STATIC_IK_S[0]),(NTIBIA_H[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(TIBIA_H[0]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_H[0]),(Z_STATIC_IK_S[4]),(NTIBIA_H[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[1]),(FEMUR_H[3]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(FEMUR_H[3]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK_S[5]),(FEMUR_H[3]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK_S[0]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK_S[4]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

	}
}

void Dynamx_Slide_Obs_Left_IK(int distance, int SPEED)
{
	int limit = distance;
	int loop;

	if(IK_CALCULATED_SLD_L_OBS == 0)
	{
		Generate_Body(0,1.5);
		Trajectory_Generator_Obs(X_Diff, Y_Diff, -2.5, 4,MOVEMENT_NORMAL);
		for(i=0;i<=3;i++)
		{
			Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_OBS[1]+Z_IK[i]));
			FEMUR_H[i] = tetha.Femur;
			COXA_H[i] = tetha.Coxa;
			NFEMUR_H[i] = (tetha.Femur*-1);
			NCOXA_H[i] = (tetha.Coxa*-1);

			Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_OBS[1]));
			TIBIA_H[i] = tetha.Tibia;

			Dyna_IKCalc_Only((X_IK_OBS[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_OBS[1]));
			NTIBIA_H[i] = tetha.Tibia;

			Dyna_IKCalc_Only((X_IK_OBS[0]+X4_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_OBS[1]));
			TIBIA_HS[i] = tetha.Tibia;

			Dyna_IKCalc_Only((X_IK_OBS[0]-X4_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_OBS[1]));
			NTIBIA_HS[i] = tetha.Tibia;
		}
		IK_CALCULATED_SLD_R_OBS = 0;
		IK_CALCULATED_SLD_L_OBS = 1;
	}

	SPEED = SPEED/45;

	for(loop=0;loop<limit;loop++)
	{
		//SIKLUS 1
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_H[0]),(FEMUR_H[3]),(NTIBIA_H[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(FEMUR_H[3]),(TIBIA_H[0]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_H[0]),(FEMUR_H[3]),(NTIBIA_H[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_H[0]),(Z_STATIC_IK_S[0]),(NTIBIA_H[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(TIBIA_H[0]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_H[0]),(Z_STATIC_IK_S[4]),(NTIBIA_H[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_H[1]),(FEMUR_H[2]),(NTIBIA_H[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(FEMUR_H[2]),(TIBIA_H[1]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_H[1]),(FEMUR_H[2]),(NTIBIA_H[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_H[1]),(Z_STATIC_IK_S[0]),(NTIBIA_H[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(TIBIA_H[1]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_H[1]),(Z_STATIC_IK_S[4]),(NTIBIA_H[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_H[2]),(FEMUR_H[1]),(NTIBIA_H[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(FEMUR_H[1]),(TIBIA_H[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_H[2]),(FEMUR_H[1]),(NTIBIA_H[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_H[2]),(Z_STATIC_IK_S[0]),(NTIBIA_H[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(TIBIA_H[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_H[2]),(Z_STATIC_IK_S[4]),(NTIBIA_H[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_H[3]),(FEMUR_H[0]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(FEMUR_H[0]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_H[3]),(FEMUR_H[0]),(NTIBIA_H[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[0]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[4]),(NTIBIA_H[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		//SIKLUS 2
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[1]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[5]),(NTIBIA_H[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[0]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[4]),(NTIBIA_H[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[1]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[5]),(NTIBIA_H[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[0]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[4]),(NTIBIA_H[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[1]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[5]),(NTIBIA_H[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[0]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[4]),(NTIBIA_H[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[1]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[5]),(NTIBIA_H[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[0]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[4]),(NTIBIA_H[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		//SIKLUS 3
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_H[2]),(Z_STATIC_IK_S[1]),(NTIBIA_H[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(TIBIA_H[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_H[2]),(Z_STATIC_IK_S[5]),(NTIBIA_H[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_H[2]),(FEMUR_H[0]),(NTIBIA_H[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(FEMUR_H[0]),(TIBIA_H[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_H[2]),(FEMUR_H[0]),(NTIBIA_H[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_H[1]),(Z_STATIC_IK_S[1]),(NTIBIA_H[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(TIBIA_H[1]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_H[1]),(Z_STATIC_IK_S[5]),(NTIBIA_H[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_H[1]),(FEMUR_H[1]),(NTIBIA_H[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(FEMUR_H[1]),(TIBIA_H[1]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_H[1]),(FEMUR_H[1]),(NTIBIA_H[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_H[0]),(Z_STATIC_IK_S[1]),(NTIBIA_H[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(TIBIA_H[0]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_H[0]),(Z_STATIC_IK_S[5]),(NTIBIA_H[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_H[0]),(FEMUR_H[2]),(NTIBIA_H[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(FEMUR_H[2]),(TIBIA_H[0]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_H[0]),(FEMUR_H[2]),(NTIBIA_H[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[1]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK_S[5]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK_S[0]),(FEMUR_H[3]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(FEMUR_H[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK_S[4]),(FEMUR_H[3]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		//SIKLUS 4
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_H[0]),(Z_STATIC_IK_S[1]),(TIBIA_H[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(NTIBIA_H[0]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_H[0]),(Z_STATIC_IK_S[5]),(TIBIA_H[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_H[0]),(FEMUR_H[3]),(TIBIA_H[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(FEMUR_H[3]),(NTIBIA_H[0]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_H[4]),(FEMUR_H[3]),(TIBIA_H[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_H[1]),(Z_STATIC_IK_S[1]),(TIBIA_H[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(NTIBIA_H[1]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_H[1]),(Z_STATIC_IK_S[5]),(TIBIA_H[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_H[1]),(FEMUR_H[2]),(TIBIA_H[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(FEMUR_H[2]),(NTIBIA_H[1]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_H[1]),(FEMUR_H[2]),(TIBIA_H[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_H[2]),(Z_STATIC_IK_S[1]),(TIBIA_H[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(NTIBIA_H[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_H[2]),(Z_STATIC_IK_S[5]),(TIBIA_H[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_H[2]),(FEMUR_H[1]),(TIBIA_H[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(FEMUR_H[1]),(NTIBIA_H[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_H[2]),(FEMUR_H[1]),(TIBIA_H[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[1]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[5]),(TIBIA_H[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_H[3]),(FEMUR_H[0]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(FEMUR_H[0]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_H[3]),(FEMUR_H[0]),(TIBIA_H[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		//SIKLUS 5
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[1]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[5]),(TIBIA_H[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[0]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[4]),(TIBIA_H[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[1]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[5]),(TIBIA_H[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[0]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[4]),(TIBIA_H[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[1]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[5]),(TIBIA_H[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[0]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[4]),(TIBIA_H[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[1]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[5]),(TIBIA_H[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_H[3]),(Z_STATIC_IK_S[0]),(TIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(NTIBIA_H[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_H[3]),(Z_STATIC_IK_S[4]),(TIBIA_H[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		//SIKLUS 6
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_H[2]),(FEMUR_H[0]),(TIBIA_H[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(FEMUR_H[0]),(NTIBIA_H[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_H[2]),(FEMUR_H[0]),(TIBIA_H[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_H[2]),(Z_STATIC_IK_S[0]),(TIBIA_H[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(NTIBIA_H[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_H[2]),(Z_STATIC_IK_S[4]),(TIBIA_H[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_H[1]),(FEMUR_H[1]),(TIBIA_H[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(FEMUR_H[1]),(NTIBIA_H[1]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_H[1]),(FEMUR_H[1]),(TIBIA_H[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_H[1]),(Z_STATIC_IK_S[0]),(TIBIA_H[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(NTIBIA_H[1]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_H[1]),(Z_STATIC_IK_S[4]),(TIBIA_H[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_H[0]),(FEMUR_H[2]),(TIBIA_H[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(FEMUR_H[2]),(NTIBIA_H[0]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_H[0]),(FEMUR_H[2]),(TIBIA_H[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_H[0]),(Z_STATIC_IK_S[0]),(TIBIA_H[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(NTIBIA_H[0]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_H[0]),(Z_STATIC_IK_S[4]),(TIBIA_H[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[1]),(FEMUR_H[3]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(FEMUR_H[3]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK_S[5]),(FEMUR_H[3]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK_S[0]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK_S[4]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);
	}
}

void Dynamx_MoveCurveLeft_IK_Reverse(int SPEED,int limit,volatile float *ACTUATE_SIGNAL)
{
	CURVE_LEFT_STAT = 1;
	int loop;
	int MAX_SIGNAL = 15;

	if(IK_CALCULATED_CRV_L_REVERSE == 0)
	{
		Generate_Body(0,-1.5);
		Trajectory_Generator_NEW(X_Diff, Y_Diff, -2.5, 4,MOVEMENT_NORMAL);
		for(i=0;i<=3;i++)
		{
			Dyna_IKCalc_Only((X_IK_BEGIN[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]+Z_IK[i]));
			FEMUR_C[i] = tetha.Femur;
			COXA_C[i] = tetha.Coxa;
			NFEMUR_C[i] = (tetha.Femur*-1);
			NCOXA_C[i] = (tetha.Coxa*-1);

			Dyna_IKCalc_Only((X_IK_BEGIN[0]+X4_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
			TIBIA_C[i] = tetha.Tibia;

			Dyna_IKCalc_Only((X_IK_BEGIN[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
			NTIBIA_C[i] = tetha.Tibia;
			NTIBIA_C_R[i] = tetha.Tibia;

			Dyna_IKCalc_Only((X_IK_BEGIN[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
			TIBIA_C_R[i] = tetha.Tibia;
		}

		IK_CALCULATED_CRV_R = 0;
		IK_CALCULATED_CRV_L = 0;
		IK_CALCULATED_CRV_R_REVERSE = 0;
		IK_CALCULATED_CRV_L_REVERSE = 1;
	}

	SPEED = SPEED/45;

	int a = 0;
	int b = 0, c = 0;

	float signal=*ACTUATE_SIGNAL/3;
	float error_L;//femur_L,tibia_L;
	float error_R;//femur_R,tibia_R;
	float error_R2;

	if (signal>=MAX_SIGNAL){error_R=MAX_SIGNAL;error_R2=MAX_SIGNAL;}
	else {error_R=signal;error_R2=signal;}

	float DELTA_R= (1 * error_R);
	float DELTA_R2 = (1 * error_R2);

	int LEFT_EXT1 = 0;
	int LEFT_EXT2 = 0;

	int CURVE[4];
	int NCURVE[4];

	CURVE[0] = (int)((DELTA_R*(float)COXA_C[0])/((float)(MAX_SIGNAL)));
	CURVE[1] = (int)((DELTA_R*(float)COXA_C[1])/((float)(MAX_SIGNAL)));
	CURVE[2] = (int)((DELTA_R*(float)COXA_C[2])/((float)(MAX_SIGNAL)));
	CURVE[3] = (int)((DELTA_R*(float)COXA_C[3])/((float)(MAX_SIGNAL)));

	NCURVE[0] = (int)((DELTA_R2*(float)NCOXA_C[0])/((float)(MAX_SIGNAL)));
	NCURVE[1] = (int)((DELTA_R2*(float)NCOXA_C[1])/((float)(MAX_SIGNAL)));
	NCURVE[2] = (int)((DELTA_R2*(float)NCOXA_C[2])/((float)(MAX_SIGNAL)));
	NCURVE[3] = (int)((DELTA_R2*(float)NCOXA_C[3])/((float)(MAX_SIGNAL)));

	int n;
	for(n=0;n<=3;n++)
	{
		NCURVE[i] = (NCURVE[i]*-1);
	}
			for(loop=1;loop<=limit;loop++)
			{

				if (Ping[PING_REAR]<=REAR_THRESHOLD)break;
				if(FOLLOW_TRACER_STATE == 1)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
				}

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				if(FOLLOW_CARPET_MODE == NORMAL)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

				}
				else if(FOLLOW_CARPET_MODE == INVERSE)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

				}
				if (Ping[PING_REAR]<=REAR_THRESHOLD)break;

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[0]),(FEMUR_C[3]),(TIBIA_C[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[0]-CURVE[0]),(FEMUR_C[3]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[0]),(FEMUR_C[3]),(NTIBIA_C_R[0]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[0]-NCURVE[0]),(Z_STATIC_IK[0]),(NTIBIA_C[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[0]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[0]-NCURVE[0]),(Z_STATIC_IK[4]),(TIBIA_C_R[0]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[1]),(FEMUR_C[2]),(TIBIA_C[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[1]-CURVE[1]),(FEMUR_C[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[1]),(FEMUR_C[2]),(NTIBIA_C_R[1]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[1]-NCURVE[1]),(Z_STATIC_IK[0]),(NTIBIA_C[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[1]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[1]-NCURVE[1]),(Z_STATIC_IK[4]),(TIBIA_C_R[1]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[2]),(FEMUR_C[1]),(TIBIA_C[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[2]-CURVE[2]),(FEMUR_C[1]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[2]),(FEMUR_C[1]),(NTIBIA_C_R[2]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[2]-NCURVE[2]),(Z_STATIC_IK[0]),(NTIBIA_C[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[2]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[2]-NCURVE[2]),(Z_STATIC_IK[4]),(TIBIA_C_R[2]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[3]),(FEMUR_C[0]),(TIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[3]-CURVE[3]),(FEMUR_C[0]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[3]),(FEMUR_C[0]),(NTIBIA_C_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[0]),(NTIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[4]),(TIBIA_C_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				if (Ping[PING_REAR]<=REAR_THRESHOLD)break;
				if(FOLLOW_TRACER_STATE == 1)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
				}

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				if(FOLLOW_CARPET_MODE == NORMAL)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

				}
				else if(FOLLOW_CARPET_MODE == INVERSE)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

				}

				if (Ping[PING_REAR]<=REAR_THRESHOLD)break;

				//SIKLUS 2
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[3]),(Z_STATIC_IK[1]),(TIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[3]-CURVE[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[3]),(Z_STATIC_IK[5]),(NTIBIA_C_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[0]),(NTIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[4]),(TIBIA_C_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[3]),(Z_STATIC_IK[1]),(TIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[3]-CURVE[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[3]),(Z_STATIC_IK[5]),(NTIBIA_C_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[0]),(NTIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[4]),(TIBIA_C_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[3]),(Z_STATIC_IK[1]),(TIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[3]-CURVE[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[3]),(Z_STATIC_IK[5]),(NTIBIA_C_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[0]),(NTIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[4]),(TIBIA_C_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[3]),(Z_STATIC_IK[1]),(TIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[3]-CURVE[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[3]),(Z_STATIC_IK[5]),(NTIBIA_C_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[0]),(NTIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[4]),(TIBIA_C_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);


				if (Ping[PING_REAR]<=REAR_THRESHOLD)break;
				if(FOLLOW_TRACER_STATE == 1)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
				}

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				if(FOLLOW_CARPET_MODE == NORMAL)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

				}
				else if(FOLLOW_CARPET_MODE == INVERSE)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

				}
				if (Ping[PING_REAR]<=REAR_THRESHOLD)break;

				//SIKLUS 3
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[2]),(Z_STATIC_IK[1]),(TIBIA_C[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[2]-CURVE[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[2]),(Z_STATIC_IK[5]),(NTIBIA_C_R[2]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[2]-NCURVE[2]),(FEMUR_C[0]),(NTIBIA_C[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[2]),(FEMUR_C[0]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[2]-NCURVE[2]),(FEMUR_C[0]),(TIBIA_C_R[2]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[1]),(Z_STATIC_IK[1]),(TIBIA_C[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[1]-CURVE[1]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[1]),(Z_STATIC_IK[5]),(NTIBIA_C_R[1]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[1]-NCURVE[1]),(FEMUR_C[1]),(NTIBIA_C[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[1]),(FEMUR_C[1]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[1]-NCURVE[1]),(FEMUR_C[1]),(TIBIA_C_R[1]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[0]),(Z_STATIC_IK[1]),(TIBIA_C[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[0]-CURVE[0]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[0]),(Z_STATIC_IK[5]),(NTIBIA_C_R[0]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[0]-NCURVE[0]),(FEMUR_C[2]),(NTIBIA_C[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[0]),(FEMUR_C[2]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[0]-NCURVE[0]),(FEMUR_C[2]),(TIBIA_C_R[0]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK[1]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK[5]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK[0]),(FEMUR_C[3]),(X_STATIC_IK[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(FEMUR_C[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK[4]),(FEMUR_C[3]),(X_STATIC_IK[4]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				if (Ping[PING_REAR]<=REAR_THRESHOLD)break;

				if(FOLLOW_TRACER_STATE == 1)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
				}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				if(FOLLOW_CARPET_MODE == NORMAL)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

				}
				else if(FOLLOW_CARPET_MODE == INVERSE)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

				}
				if (Ping[PING_REAR]<=REAR_THRESHOLD)break;

				//SIKLUS 4
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[0]),(Z_STATIC_IK[1]),(NTIBIA_C[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[0]-NCURVE[0]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[0]),(Z_STATIC_IK[5]),(TIBIA_C_R[0]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[0]-CURVE[0]),(FEMUR_C[3]),(TIBIA_C[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[0]),(FEMUR_C[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[0]-CURVE[0]),(FEMUR_C[3]),(NTIBIA_C_R[0]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[1]),(Z_STATIC_IK[1]),(NTIBIA_C[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[1]-NCURVE[1]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[1]),(Z_STATIC_IK[5]),(TIBIA_C_R[1]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[1]-CURVE[1]),(FEMUR_C[2]),(TIBIA_C[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[1]),(FEMUR_C[2]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[1]-CURVE[1]),(FEMUR_C[2]),(NTIBIA_C_R[1]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[2]),(Z_STATIC_IK[1]),(NTIBIA_C[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[2]-NCURVE[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[2]),(Z_STATIC_IK[5]),(TIBIA_C_R[2]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[2]-CURVE[2]),(FEMUR_C[1]),(TIBIA_C[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[2]),(FEMUR_C[1]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[2]-CURVE[2]),(FEMUR_C[1]),(NTIBIA_C_R[2]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[1]),(NTIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[5]),(TIBIA_C_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[3]-CURVE[3]),(FEMUR_C[0]),(TIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[3]),(FEMUR_C[0]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[3]-CURVE[3]),(FEMUR_C[0]),(NTIBIA_C_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				if (Ping[PING_REAR]<=REAR_THRESHOLD)break;
				if(FOLLOW_TRACER_STATE == 1)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
				}

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				if(FOLLOW_CARPET_MODE == NORMAL)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

				}
				else if(FOLLOW_CARPET_MODE == INVERSE)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

				}
				if (Ping[PING_REAR]<=REAR_THRESHOLD)break;

				//SIKLUS 5
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[1]),(NTIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[5]),(TIBIA_C_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[3]-CURVE[3]),(Z_STATIC_IK[0]),(TIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[3]-CURVE[3]),(Z_STATIC_IK[4]),(NTIBIA_C_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[1]),(NTIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[5]),(TIBIA_C_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[3]-CURVE[3]),(Z_STATIC_IK[0]),(TIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[3]-CURVE[3]),(Z_STATIC_IK[4]),(NTIBIA_C_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[1]),(NTIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[5]),(TIBIA_C_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[3]-CURVE[3]),(Z_STATIC_IK[0]),(TIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[3]-CURVE[3]),(Z_STATIC_IK[4]),(NTIBIA_C_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[1]),(NTIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[5]),(TIBIA_C_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[3]-CURVE[3]),(Z_STATIC_IK[0]),(TIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[3]-CURVE[3]),(Z_STATIC_IK[4]),(NTIBIA_C_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				if (Ping[PING_REAR]<=REAR_THRESHOLD)break;

				if(FOLLOW_TRACER_STATE == 1)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
				}

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				if(FOLLOW_CARPET_MODE == NORMAL)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

				}
				else if(FOLLOW_CARPET_MODE == INVERSE)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

				}
				if (Ping[PING_REAR]<=REAR_THRESHOLD)break;

				//SIKLUS
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[2]),(FEMUR_C[0]),(NTIBIA_C[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[2]-NCURVE[2]),(FEMUR_C[0]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[2]),(FEMUR_C[0]),(TIBIA_C_R[2]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[2]-CURVE[2]),(Z_STATIC_IK[0]),(TIBIA_C[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[2]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[2]-CURVE[2]),(Z_STATIC_IK[4]),(NTIBIA_C_R[2]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[1]),(FEMUR_C[1]),(NTIBIA_C[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[1]-NCURVE[1]),(FEMUR_C[1]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[1]),(FEMUR_C[1]),(TIBIA_C_R[1]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[1]-CURVE[1]),(Z_STATIC_IK[0]),(TIBIA_C[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[1]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[1]-CURVE[1]),(Z_STATIC_IK[4]),(NTIBIA_C_R[1]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[0]),(FEMUR_C[2]),(NTIBIA_C[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[0]-NCURVE[0]),(FEMUR_C[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[0]),(FEMUR_C[2]),(TIBIA_C_R[0]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[0]-CURVE[0]),(Z_STATIC_IK[0]),(TIBIA_C[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[0]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[0]-CURVE[0]),(Z_STATIC_IK[4]),(NTIBIA_C_R[0]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK[1]),(FEMUR_C[3]),(X_STATIC_IK[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(FEMUR_C[3]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK[5]),(FEMUR_C[3]),(X_STATIC_IK[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK[0]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK[4]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				if (Ping[PING_REAR]<=REAR_THRESHOLD)break;
				if(FOLLOW_TRACER_STATE == 1)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
				}
				if(FOLLOW_TRACER_STATE == 1)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
				}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				if(FOLLOW_CARPET_MODE == NORMAL)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

				}
				else if(FOLLOW_CARPET_MODE == INVERSE)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

				}
				if (Ping[PING_REAR]<=REAR_THRESHOLD)break;
			}
			CURVE_LEFT_STAT = 0;
}


void Dynamx_MoveCurveLeft_IK(int SPEED,int limit,volatile float *ACTUATE_SIGNAL)
{
	CURVE_LEFT_STAT = 1;
	int loop;
	int MAX_SIGNAL = 15;
	int cek_value = 0;

	if(IK_CALCULATED_CRV_L == 0)
	{
		Generate_Body(0,1.7);
		Trajectory_Generator_6S(X_Diff, Y_Diff, -2, 6,MOVEMENT_NORMAL);
		for(i=0;i<=5;i++)
		{
			Dyna_IKCalc_Only((X_IK_BEGIN[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]+Z_IK[i]));
			FEMUR_C[i] = tetha.Femur;
			COXA_C[i] = tetha.Coxa;
			NFEMUR_C[i] = (tetha.Femur*-1);
			NCOXA_C[i] = (tetha.Coxa*-1);

			Dyna_IKCalc_Only((X_IK_BEGIN[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
			TIBIA_C[i] = tetha.Tibia;

			Dyna_IKCalc_Only((X_IK_BEGIN[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
			NTIBIA_C[i] = tetha.Tibia;
			NTIBIA_C_R[i] = tetha.Tibia;

			Dyna_IKCalc_Only((X_IK_BEGIN[0]+X4_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]));
			TIBIA_C_R[i] = tetha.Tibia;
		}

		IK_CALCULATED_CRV_R = 0;
		IK_CALCULATED_CRV_L = 1;
		IK_CALCULATED_CRV_R_REVERSE = 0;
		IK_CALCULATED_CRV_L_REVERSE = 0;
	}

	SPEED = SPEED/45;

	int a = 0;
	int b = 0, c = 0;

	float signal=*ACTUATE_SIGNAL/3;
	float error_L;//femur_L,tibia_L;
	float error_R;//femur_R,tibia_R;
	float error_R2;

	if (signal>=MAX_SIGNAL){error_R=MAX_SIGNAL;error_R2=MAX_SIGNAL;}
	else {error_R=signal;error_R2=signal;}

	float DELTA_R= (1 * error_R);
	float DELTA_R2 = (1 * error_R2);

	int LEFT_EXT1 = 0;
	int LEFT_EXT2 = 0;

	int CURVE[6];
	int NCURVE[6];

	CURVE[0] = (int)((DELTA_R*(float)COXA_C[0])/((float)(MAX_SIGNAL)));
	CURVE[1] = (int)((DELTA_R*(float)COXA_C[1])/((float)(MAX_SIGNAL)));
	CURVE[2] = (int)((DELTA_R*(float)COXA_C[2])/((float)(MAX_SIGNAL)));
	CURVE[3] = (int)((DELTA_R*(float)COXA_C[3])/((float)(MAX_SIGNAL)));
	CURVE[4] = (int)((DELTA_R*(float)COXA_C[4])/((float)(MAX_SIGNAL)));
	CURVE[5] = (int)((DELTA_R*(float)COXA_C[5])/((float)(MAX_SIGNAL)));


	NCURVE[0] = (int)((DELTA_R2*(float)NCOXA_C[0])/((float)(MAX_SIGNAL)));
	NCURVE[1] = (int)((DELTA_R2*(float)NCOXA_C[1])/((float)(MAX_SIGNAL)));
	NCURVE[2] = (int)((DELTA_R2*(float)NCOXA_C[2])/((float)(MAX_SIGNAL)));
	NCURVE[3] = (int)((DELTA_R2*(float)NCOXA_C[3])/((float)(MAX_SIGNAL)));
	NCURVE[4] = (int)((DELTA_R2*(float)NCOXA_C[4])/((float)(MAX_SIGNAL)));
	NCURVE[5] = (int)((DELTA_R2*(float)NCOXA_C[5])/((float)(MAX_SIGNAL)));

	if (cek_value==1)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"CURVE VALUE");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d",CURVE[0],CURVE[1],CURVE[2]);lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d",CURVE[3],CURVE[4],CURVE[5]);lcd_putstr(lcd);

//		lcd_gotoxy(0,0);sprintf(lcd,"FEMUR VALUE L");lcd_putstr(lcd);
//		lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d",FEMUR_C[0],FEMUR_C[1],FEMUR_C[2]);lcd_putstr(lcd);
//		lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d",FEMUR_C[3],FEMUR_C[4],FEMUR_C[5]);lcd_putstr(lcd);

		while(1){}
	}

	int n;
	for(n=0;n<=5;n++)
	{
		NCURVE[i] = (NCURVE[i]*-1);
	}
			for(loop=1;loop<=limit;loop++)
			{
				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
				{
					Stairs_Detector();
					if(STAIRS_FLAG == STAIRS_DETECTED)break;
				}

				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
				if(FOLLOW_TRACER_STATE == 1)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
				}

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				if(FOLLOW_CARPET_MODE == NORMAL)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

				}
				else if(FOLLOW_CARPET_MODE == INVERSE)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

				}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				//SIKLUS 1
				//1
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[0]),(FEMUR_C[5]),(TIBIA_C[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[0]-CURVE[0]),(FEMUR_C[5]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[0]),(FEMUR_C[5]),(NTIBIA_C_R[0]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[0]-NCURVE[0]),(Z_STATIC_IK[0]),(NTIBIA_C[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[0]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[0]-NCURVE[0]),(Z_STATIC_IK[4]),(TIBIA_C_R[0]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//2
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[1]),(FEMUR_C[4]),(TIBIA_C[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[1]-CURVE[1]),(FEMUR_C[4]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[1]),(FEMUR_C[4]),(NTIBIA_C_R[1]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[1]-NCURVE[1]),(Z_STATIC_IK[0]),(NTIBIA_C[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[1]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[1]-NCURVE[1]),(Z_STATIC_IK[4]),(TIBIA_C_R[1]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//3
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[2]),(FEMUR_C[3]),(TIBIA_C[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[2]-CURVE[2]),(FEMUR_C[3]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[2]),(FEMUR_C[3]),(NTIBIA_C_R[2]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[2]-NCURVE[2]),(Z_STATIC_IK[0]),(NTIBIA_C[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[2]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[2]-NCURVE[2]),(Z_STATIC_IK[4]),(TIBIA_C_R[2]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//4
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[3]),(FEMUR_C[2]),(TIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[3]-CURVE[3]),(FEMUR_C[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[3]),(FEMUR_C[2]),(NTIBIA_C_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[0]),(NTIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[4]),(TIBIA_C_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//5
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[4]),(FEMUR_C[1]),(TIBIA_C[4]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[4]-CURVE[4]),(FEMUR_C[1]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[4]),(FEMUR_C[1]),(NTIBIA_C_R[4]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[4]-NCURVE[4]),(Z_STATIC_IK[0]),(NTIBIA_C[4]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[4]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[4]-NCURVE[4]),(Z_STATIC_IK[4]),(TIBIA_C_R[4]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//6
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[5]),(FEMUR_C[0]),(TIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[5]-CURVE[5]),(FEMUR_C[0]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[5]),(FEMUR_C[0]),(NTIBIA_C_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[0]),(NTIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[4]),(TIBIA_C_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
				{
					Stairs_Detector();
					if(STAIRS_FLAG == STAIRS_DETECTED)break;
				}

				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
				if(FOLLOW_TRACER_STATE == 1)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
				}

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				if(FOLLOW_CARPET_MODE == NORMAL)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

				}
				else if(FOLLOW_CARPET_MODE == INVERSE)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

				}

				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				//SIKLUS 2
				//1
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[5]),(Z_STATIC_IK[1]),(TIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[5]),(Z_STATIC_IK[5]),(NTIBIA_C_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[0]),(NTIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[4]),(TIBIA_C_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//2
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[5]),(Z_STATIC_IK[1]),(TIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[5]),(Z_STATIC_IK[5]),(NTIBIA_C_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[0]),(NTIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[4]),(TIBIA_C_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//3
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[5]),(Z_STATIC_IK[1]),(TIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[5]),(Z_STATIC_IK[5]),(NTIBIA_C_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[0]),(NTIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[4]),(TIBIA_C_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//4
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[5]),(Z_STATIC_IK[1]),(TIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[5]),(Z_STATIC_IK[5]),(NTIBIA_C_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[0]),(NTIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[4]),(TIBIA_C_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//5
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[5]),(Z_STATIC_IK[1]),(TIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[5]),(Z_STATIC_IK[5]),(NTIBIA_C_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[0]),(NTIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[4]),(TIBIA_C_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//6
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[5]),(Z_STATIC_IK[1]),(TIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[5]),(Z_STATIC_IK[5]),(NTIBIA_C_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[0]),(NTIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[4]),(TIBIA_C_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
				{
					Stairs_Detector();
					if(STAIRS_FLAG == STAIRS_DETECTED)break;
				}

				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
				if(FOLLOW_TRACER_STATE == 1)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
				}

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				if(FOLLOW_CARPET_MODE == NORMAL)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

				}
				else if(FOLLOW_CARPET_MODE == INVERSE)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

				}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				//SIKLUS 3
				//1
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[4]),(Z_STATIC_IK[1]),(TIBIA_C[4]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[4]-CURVE[4]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[4]),(Z_STATIC_IK[5]),(NTIBIA_C_R[4]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[4]-NCURVE[4]),(FEMUR_C[0]),(NTIBIA_C[4]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[4]),(FEMUR_C[0]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[4]-NCURVE[4]),(FEMUR_C[0]),(TIBIA_C_R[4]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//2
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[3]),(Z_STATIC_IK[1]),(TIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[3]-CURVE[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[3]),(Z_STATIC_IK[5]),(NTIBIA_C_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[3]-NCURVE[3]),(FEMUR_C[1]),(NTIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[3]),(FEMUR_C[1]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[3]-NCURVE[3]),(FEMUR_C[1]),(TIBIA_C_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//3
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[2]),(Z_STATIC_IK[1]),(TIBIA_C[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[2]-CURVE[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[2]),(Z_STATIC_IK[5]),(NTIBIA_C_R[2]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[2]-NCURVE[2]),(FEMUR_C[2]),(NTIBIA_C[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[2]),(FEMUR_C[2]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[2]-NCURVE[2]),(FEMUR_C[2]),(TIBIA_C_R[2]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//4
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[1]),(Z_STATIC_IK[1]),(TIBIA_C[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[1]-CURVE[1]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[1]),(Z_STATIC_IK[5]),(NTIBIA_C_R[1]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[1]-NCURVE[1]),(FEMUR_C[3]),(NTIBIA_C[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[1]),(FEMUR_C[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[1]-NCURVE[1]),(FEMUR_C[3]),(TIBIA_C_R[1]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//5
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_C[0]),(Z_STATIC_IK[1]),(TIBIA_C[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_C[0]-CURVE[0]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_C[0]),(Z_STATIC_IK[5]),(NTIBIA_C_R[0]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_C[0]-NCURVE[0]),(FEMUR_C[4]),(NTIBIA_C[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_C[0]),(FEMUR_C[4]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_C[0]-NCURVE[0]),(FEMUR_C[4]),(TIBIA_C_R[0]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//6
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK[1]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK[5]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK[0]),(FEMUR_C[5]),(X_STATIC_IK[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(FEMUR_C[5]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK[4]),(FEMUR_C[5]),(X_STATIC_IK[4]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);


				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
				{
					Stairs_Detector();
					if(STAIRS_FLAG == STAIRS_DETECTED)break;
				}

				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				if(FOLLOW_TRACER_STATE == 1)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
				}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				if(FOLLOW_CARPET_MODE == NORMAL)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

				}
				else if(FOLLOW_CARPET_MODE == INVERSE)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

				}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				//SIKLUS 4
				//1
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[0]),(Z_STATIC_IK[1]),(NTIBIA_C[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[0]-NCURVE[0]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[0]),(Z_STATIC_IK[5]),(TIBIA_C_R[0]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[0]-CURVE[0]),(FEMUR_C[5]),(TIBIA_C[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[0]),(FEMUR_C[5]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[0]-CURVE[0]),(FEMUR_C[5]),(NTIBIA_C_R[0]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//2
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[1]),(Z_STATIC_IK[1]),(NTIBIA_C[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[1]-NCURVE[1]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[1]),(Z_STATIC_IK[5]),(TIBIA_C_R[1]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[1]-CURVE[1]),(FEMUR_C[4]),(TIBIA_C[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[1]),(FEMUR_C[4]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[1]-CURVE[1]),(FEMUR_C[4]),(NTIBIA_C_R[1]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//3
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[2]),(Z_STATIC_IK[1]),(NTIBIA_C[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[2]-NCURVE[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[2]),(Z_STATIC_IK[5]),(TIBIA_C_R[2]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[2]-CURVE[2]),(FEMUR_C[3]),(TIBIA_C[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[2]),(FEMUR_C[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[2]-CURVE[2]),(FEMUR_C[3]),(NTIBIA_C_R[2]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//4
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[1]),(NTIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[3]-NCURVE[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[3]),(Z_STATIC_IK[5]),(TIBIA_C_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[3]-CURVE[3]),(FEMUR_C[2]),(TIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[3]),(FEMUR_C[2]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[3]-CURVE[3]),(FEMUR_C[2]),(NTIBIA_C_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//5
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[4]),(Z_STATIC_IK[1]),(NTIBIA_C[4]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[4]-NCURVE[4]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[4]),(Z_STATIC_IK[5]),(TIBIA_C_R[4]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[4]-CURVE[4]),(FEMUR_C[1]),(TIBIA_C[4]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[4]),(FEMUR_C[1]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[4]-CURVE[4]),(FEMUR_C[1]),(NTIBIA_C_R[4]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//6
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[1]),(NTIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[5]),(TIBIA_C_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[5]-CURVE[5]),(FEMUR_C[0]),(TIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[5]),(FEMUR_C[0]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[5]-CURVE[5]),(FEMUR_C[0]),(NTIBIA_C_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
				{
					Stairs_Detector();
					if(STAIRS_FLAG == STAIRS_DETECTED)break;
				}

				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
				if(FOLLOW_TRACER_STATE == 1)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
				}

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				if(FOLLOW_CARPET_MODE == NORMAL)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

				}
				else if(FOLLOW_CARPET_MODE == INVERSE)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

				}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				//SIKLUS 5
				//1
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[1]),(NTIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[5]),(TIBIA_C_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[0]),(TIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[5]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[4]),(NTIBIA_C_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//2
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[1]),(NTIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[5]),(TIBIA_C_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[0]),(TIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[5]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[4]),(NTIBIA_C_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//3
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[1]),(NTIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[5]),(TIBIA_C_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[0]),(TIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[5]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[4]),(NTIBIA_C_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//4
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[1]),(NTIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[5]),(TIBIA_C_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[0]),(TIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[5]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[4]),(NTIBIA_C_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//5
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[1]),(NTIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[5]),(TIBIA_C_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[0]),(TIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[5]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[4]),(NTIBIA_C_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//6
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[1]),(NTIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[5]-NCURVE[5]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[5]),(Z_STATIC_IK[5]),(TIBIA_C_R[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[0]),(TIBIA_C[5]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[5]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[5]-CURVE[5]),(Z_STATIC_IK[4]),(NTIBIA_C_R[5]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
				{
					Stairs_Detector();
					if(STAIRS_FLAG == STAIRS_DETECTED)break;
				}

				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				if(FOLLOW_TRACER_STATE == 1)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
				}

				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				if(FOLLOW_CARPET_MODE == NORMAL)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

				}
				else if(FOLLOW_CARPET_MODE == INVERSE)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

				}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;

				//SIKLUS6
				//1
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[4]),(FEMUR_C[0]),(NTIBIA_C[4]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[4]-NCURVE[4]),(FEMUR_C[0]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[4]),(FEMUR_C[0]),(TIBIA_C_R[4]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[4]-CURVE[4]),(Z_STATIC_IK[0]),(TIBIA_C[4]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[4]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[4]-CURVE[4]),(Z_STATIC_IK[4]),(NTIBIA_C_R[4]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//2
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[3]),(FEMUR_C[1]),(NTIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[3]-NCURVE[3]),(FEMUR_C[1]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[3]),(FEMUR_C[1]),(TIBIA_C_R[3]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[3]-CURVE[3]),(Z_STATIC_IK[0]),(TIBIA_C[3]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[3]-CURVE[3]),(Z_STATIC_IK[4]),(NTIBIA_C_R[3]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//3
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[2]),(FEMUR_C[2]),(NTIBIA_C[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[2]-NCURVE[2]),(FEMUR_C[2]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[2]),(FEMUR_C[2]),(TIBIA_C_R[2]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[2]-CURVE[2]),(Z_STATIC_IK[0]),(TIBIA_C[2]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[2]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[2]-CURVE[2]),(Z_STATIC_IK[4]),(NTIBIA_C_R[2]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//4
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[1]),(FEMUR_C[3]),(NTIBIA_C[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[1]-NCURVE[1]),(FEMUR_C[3]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[1]),(FEMUR_C[3]),(TIBIA_C_R[1]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[1]-CURVE[1]),(Z_STATIC_IK[0]),(TIBIA_C[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[1]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[1]-CURVE[1]),(Z_STATIC_IK[4]),(NTIBIA_C_R[1]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//5
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_C[0]),(FEMUR_C[4]),(NTIBIA_C[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_C[0]-NCURVE[0]),(FEMUR_C[4]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_C[0]),(FEMUR_C[4]),(TIBIA_C_R[0]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_C[0]-CURVE[0]),(Z_STATIC_IK[0]),(TIBIA_C[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_C[0]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_C[0]-CURVE[0]),(Z_STATIC_IK[4]),(NTIBIA_C_R[0]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				//6
				Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK[1]),(FEMUR_C[5]),(X_STATIC_IK[1]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(FEMUR_C[5]),(X_STATIC_IK[2]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK[5]),(FEMUR_C[5]),(X_STATIC_IK[5]));

				Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK[0]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
				Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
				Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK[4]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
				Start_Pose_SYNC();
				delay_ms(SPEED+4);

				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if(CAT_DETECTOR==CAT_ACTIVATED)
				{
					Cat_Avoider();
					if(CAT_FLAG ==CAT_DETECTED)break;
				}
				if(STAIRS_DETECTOR == STAIRS_DETECTOR_ACTIVATED)
				{
					Stairs_Detector();
					if(STAIRS_FLAG == STAIRS_DETECTED)break;
				}

				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
				if(FOLLOW_TRACER_STATE == 1)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
				}
				if(FOLLOW_TRACER_STATE == 1)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]== COLOUR_WHITE)break;
				}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				TCS3200_Transmit(UART5, CMD_GET_TRACER);
				if(TCS3200_SLV_DATA[1]==TRACER_WHITE) {TRACER_STAT= TRACER_WHITE;}
				if(FOLLOW_CARPET_MODE == NORMAL)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1]!= COLOUR_BUF)break;

				}
				else if(FOLLOW_CARPET_MODE == INVERSE)
				{
					TCS3200_Transmit(UART5, CMD_GET_TRACER);
					if(TCS3200_SLV_DATA[1] == COLOUR_BUF)break;

				}
				if (Ping[PING_FRONT]<=FRONT_THRESHOLD)break;
			}
			CURVE_LEFT_STAT = 0;
}

void Dynamx_MovLeanFwd_Interpolate(int SPEED, int limit)
{
	int cek_value = 0;
	int cek_siklus = 0;

	if(IK_CALCULATED_LEAN_FWD == 0)
	{

		Generate_Body(0,2);
		Trajectory_Generator_Lean(X_Diff, Y_Diff, -3.5, 4,MOVEMENT_NORMAL);
		for(i=0;i<=3;i++)
		{
			Dyna_IKCalc_Only((X_IK_BEGIN[0]+X4_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]+Z_IK[i]));
			COXA_E[i] = tetha.Coxa;
			NCOXA_E[i] = (tetha.Coxa*-1);

			Dyna_IKCalc_Only((X_IK_BEGIN[0]+X3_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_BEGIN[1]+Z_IK[i]));
			COXA_E_R[i] = tetha.Coxa;
			NCOXA_E_R[i] = (tetha.Coxa*-1);

		}
		IK_CALCULATED_LEAN_FWD = 1;
		IK_CALCULATED_LEAN_FWD_OBS = 0;
	}

	SPEED = SPEED/45;

	if (cek_value==1)
	{
		lcd_display_clear();
//		lcd_gotoxy(0,0);sprintf(lcd,"COXA VALUE");lcd_putstr(lcd);
//		lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d|%d",COXA_B[0],COXA_B[1],COXA_B[2],COXA_B[3]);lcd_putstr(lcd);
//		lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d|%d",NCOXA_B[0],NCOXA_B[1],NCOXA_B[2],NCOXA_B[3]);lcd_putstr(lcd);

		lcd_gotoxy(0,0);sprintf(lcd,"COXA VALUE");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d|%d",COXA_E[0],COXA_E[1],COXA_E[2],COXA_E[3]);lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d|%d",COXA_E_R[0],COXA_E_R[1],COXA_E_R[2],COXA_E_R[3]);lcd_putstr(lcd);

//		lcd_gotoxy(0,0);sprintf(lcd,"FEMUR VALUE");lcd_putstr(lcd);
//		lcd_gotoxy(0,0);sprintf(lcd,"%d|%d|%d|%d",TIBIA_A[0],TIBIA_A[1],TIBIA_A[2],TIBIA_A[3]);lcd_putstr(lcd);
//		lcd_gotoxy(0,1);sprintf(lcd,"%d|%d|%d|%d",NTIBIA_A[0],NTIBIA_A[1],NTIBIA_A[2],NTIBIA_A[3]);lcd_putstr(lcd);
//		lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d|%d",TIBIA_A_R[0],TIBIA_A_R[1],TIBIA_A_R[2],TIBIA_A_R[3]);lcd_putstr(lcd);
//		lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d|%d",NTIBIA_A_R[0],NTIBIA_A_R[1],NTIBIA_A_R[2],NTIBIA_A_R[3]);lcd_putstr(lcd);

		while(1){}

	}

	for (int i =0; i<limit; i++)
	{
		//SIKLUS 1
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_E[0]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_E[0]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_E_R[0]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_E[0]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_E[0]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_E_R[0]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_E[1]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_E[1]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_E_R[1]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_E[1]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_E[1]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_E_R[1]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_E[2]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_E[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_E_R[2]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_E[2]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_E[2]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_E_R[2]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_E[3]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_E[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_E_R[3]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_E[3]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_E[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_E_R[3]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 1");lcd_putstr(lcd);
			delay_ms(5000);
		}

		//SIKLUS 2
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_E[3]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_E[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_E_R[3]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_E[3]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_E[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_E_R[3]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_E[3]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_E[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_E_R[3]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_E[3]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_E[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_E_R[3]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_E[3]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_E[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_E_R[3]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_E[3]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_E[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_E_R[3]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_E[3]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_E[3]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_E_R[3]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_E[3]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_E[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_E_R[3]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 2");lcd_putstr(lcd);
			delay_ms(5000);
		}

		if(MODE_CAPIT==MODE_K1)
		{
			delay_ms(100);
			Gripper_Close_K1();
			GRIPPER_LED_OFF;
			Gripper_Up_Dikit();
		}


		//SIKLUS 3
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_E[2]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_E[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_E_R[2]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_E[2]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_E[2]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_E_R[2]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);


		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_E[1]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_E[1]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_E_R[1]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_E[1]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_E[1]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_E_R[1]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_E[0]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_E[0]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_E_R[0]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_E[0]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_E[0]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_E_R[0]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK[1]),(Z_STATIC_IK[1]),(X_STATIC_IK[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK[2]),(Z_STATIC_IK[2]),(X_STATIC_IK[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK[5]),(Z_STATIC_IK[5]),(X_STATIC_IK[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK[0]),(Z_STATIC_IK[0]),(X_STATIC_IK[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK[3]),(Z_STATIC_IK[3]),(X_STATIC_IK[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK[4]),(Z_STATIC_IK[4]),(X_STATIC_IK[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 3");lcd_putstr(lcd);
			delay_ms(5000);
		}

		if(MODE_CAPIT==MODE_K1)
		{
			delay_ms(100);
			Gripper_Up_Full();
		}

	}

}

void Dynamx_MovLeanFwd_Obstaicle_Interpolate(int SPEED, int limit)
{
	int cek_value = 0;
	int cek_siklus = 0;

	if(IK_CALCULATED_LEAN_FWD_OBS == 0)
	{

		Generate_Body(0,2);
		Trajectory_Generator_Lean(X_Diff, Y_Diff, -3.5, 4,MOVEMENT_NORMAL);
		for(i=0;i<=3;i++)
		{
			Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_OBS[1]+Z_IK[i]));
			COXA_B[i] = tetha.Coxa;
			NCOXA_B[i] = (tetha.Coxa*-1);

			Dyna_IKCalc_Only((X_IK_OBS[0]+X2_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_OBS[1]+Z_IK[i]));
			COXA_B_R[i] = tetha.Coxa;
			NCOXA_B_R[i] = (tetha.Coxa*-1);

		}
		IK_CALCULATED_LEAN_FWD_OBS = 1;
		IK_CALCULATED_LEAN_FWD = 0;
	}

	SPEED = SPEED/45;

	if (cek_value==1)
	{
		lcd_display_clear();
//		lcd_gotoxy(0,0);sprintf(lcd,"COXA VALUE");lcd_putstr(lcd);
//		lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d|%d",COXA_B[0],COXA_B[1],COXA_B[2],COXA_B[3]);lcd_putstr(lcd);
//		lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d|%d",NCOXA_B[0],NCOXA_B[1],NCOXA_B[2],NCOXA_B[3]);lcd_putstr(lcd);

		lcd_gotoxy(0,0);sprintf(lcd,"COXA R VALUE");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d|%d",COXA_B_R[0],COXA_B_R[1],COXA_B_R[2],COXA_B_R[3]);lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d|%d",NCOXA_B_R[0],NCOXA_B_R[1],NCOXA_B_R[2],NCOXA_B_R[3]);lcd_putstr(lcd);

//		lcd_gotoxy(0,0);sprintf(lcd,"FEMUR VALUE");lcd_putstr(lcd);
//		lcd_gotoxy(0,0);sprintf(lcd,"%d|%d|%d|%d",TIBIA_A[0],TIBIA_A[1],TIBIA_A[2],TIBIA_A[3]);lcd_putstr(lcd);
//		lcd_gotoxy(0,1);sprintf(lcd,"%d|%d|%d|%d",NTIBIA_A[0],NTIBIA_A[1],NTIBIA_A[2],NTIBIA_A[3]);lcd_putstr(lcd);
//		lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d|%d",TIBIA_A_R[0],TIBIA_A_R[1],TIBIA_A_R[2],TIBIA_A_R[3]);lcd_putstr(lcd);
//		lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d|%d",NTIBIA_A_R[0],NTIBIA_A_R[1],NTIBIA_A_R[2],NTIBIA_A_R[3]);lcd_putstr(lcd);

		while(1){}

	}

	for (int i =0; i<limit; i++)
	{
		//SIKLUS 1
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_B[0]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_B[0]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_B_R[0]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_B[0]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_B[0]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_B_R[0]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_B[1]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_B[1]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_B_R[1]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_B[1]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_B[1]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_B_R[1]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_B[2]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_B[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_B_R[2]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_B[2]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_B[2]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_B_R[2]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_B[3]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_B[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_B_R[3]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_B[3]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_B[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_B_R[3]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 1");lcd_putstr(lcd);
			delay_ms(5000);
		}

		//SIKLUS 2
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_B[3]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_B[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_B_R[3]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_B[3]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_B[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_B_R[3]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_B[3]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_B[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_B_R[3]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_B[3]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_B[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_B_R[3]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_B[3]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_B[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_B_R[3]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_B[3]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_B[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_B_R[3]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_B[3]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_B[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_B_R[3]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_B[3]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_B[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_B_R[3]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 2");lcd_putstr(lcd);
			delay_ms(5000);
		}

		if(MODE_CAPIT==MODE_K1)
		{
			delay_ms(100);
			Gripper_Close_K1();
			GRIPPER_LED_OFF;
			Gripper_Up_New();
		}
		if(MODE_CAPIT==MODE_K2)
		{
			delay_ms(100);
			Gripper_Close_K1();
			GRIPPER_LED_ON;
			Gripper_Up_Dikit();
		}
		if(MODE_CAPIT==MODE_SZ1)
		{
			delay_ms(100);
			Gripper_Open_K1();
		}
		if(MODE_CAPIT==MODE_SZ5)
		{
			Gripper_Down_New();
			delay_ms(100);
			Gripper_Open_K1();
		}

		//SIKLUS 3
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_B[2]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_B[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_B_R[2]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_B[2]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_B[2]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_B_R[2]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);


		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_B[1]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_B[1]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_B_R[1]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_B[1]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_B[1]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_B_R[1]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_B[0]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_B[0]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_B_R[0]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_B[0]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_B[0]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_B_R[0]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[1]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK_S[5]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK_S[0]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK_S[4]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 3");lcd_putstr(lcd);
			delay_ms(5000);
		}

		if(MODE_CAPIT==MODE_K2)
		{
			delay_ms(100);
			Gripper_Up_Full();
		}
	}
}


/* func      : 	void Dynamx_Rot_Right_Reverse(int degree, int SPEED)
 * brief     : 	Dynamixel Hexapod Rotate Right locomotion using tripod gait
 * param     :	unsigned int SPEED		-> HEX_SLOW, HEX_MED, HEX_FAST, HEX_ULTRAFAST
 * 				unsigned int STEP	  	-> HEXSTEP_CLOSE, HEXSTEP_MED, HEXSTEP_FAR
 * retval    : 	N/A
 * Ver       : 1
 * written By: Hafidin (Friday, March 3 2017)
 * Revised By:
 *
 * Programmer's Note:
 *
 */

void Dynamx_Rot_Right_Reverse(int SPEED,  int STEP)
{
	delay_ms(50);

    //Tripod A
    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[5],4,leg-1); //BELAKANG MENAPAK
    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1],4,leg-1); 				//DEPAN MENAPAK
    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[3],4,leg-1);  //BELAKANG MENAPAK

    //Tripod B
    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[2],1,leg-2);
    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4],1,leg-2);
    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[0],1,leg-2);

    //Tripod A
    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,4,leg-1); //TENGAH MENAPAK
    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,4,leg-1); 						//TENGAH MENAPAK
    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,4,leg-1); //TENGAH MENAPAK

    //Tripod B
    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,1,leg-2);
    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,1,leg-2);
    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90,1,leg-2);

//		    delay_ms(1000);

    Sendto_PC(USART1,"<======== STEP 3 \r");
    //3
    //Tripod A
    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[5],4,leg-1); //DEPAN MENAPAK
    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1],4,leg-1); 				//BELAKANG MENAPAK
    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[3],4,leg-1); //DEPAN MENAPAK

    //Tripod B
    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[2],1,leg-2);
    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4],1,leg-2);
    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[0],1,leg-2);

//		    delay_ms(1000);

    Sendto_PC(USART1,"<======== STEP 4 \r");
    //4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU
    //Tripod B
    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[2],4,leg-1);
    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4],4,leg-1);
    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[0],4,leg-1);
    //Tripod A
    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[5],1,leg-2); //DEPAN ANGKAT
    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1],1,leg-2); 				//BELAKANG ANGKAT
    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[3],1,leg-2); //DEPAN ANGKAT

//		    delay_ms(1000);

    Sendto_PC(USART1,"<======== STEP 5 \r");
    //5
    //Tripod A
    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,1,leg-2); //TENGAH ANGKAT
    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,1,leg-2); 						//TENGAH ANGKAT
    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,1,leg-2); //TENGAH ANGKAT

    //Tripod B
    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,4,leg-1);
    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,4,leg-1);
    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90,4,leg-1);

//		    delay_ms(1000);

    Sendto_PC(USART1,"<======== STEP 6 \r");
    //6
    //Tripod A
    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[5],1,leg-2); //BELAKANG ANGKAT
    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1],1,leg-2); 				//BELAKANG ANGKAT
    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[3],1,leg-2);  //BELAKANG ANGKAT

    //Tripod B
    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[2],4,leg-1);
    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4],4,leg-1);
    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[0],4,leg-1);

//		    delay_ms(1000);

    Sendto_PC(USART1,"================ END OF ROTATE RIGHT TRIPOD GAIT SEQUENCES ================ \r\r");
}

/* func      : 	void Dynamx_Rot_Left_Reverse(int degree, int SPEED)
 * brief     : 	Dynamixel Hexapod Rotate Right locomotion using tripod gait
 * param     :	unsigned int SPEED		-> HEX_SLOW, HEX_MED, HEX_FAST, HEX_ULTRAFAST
 * 				unsigned int STEP	  	-> HEXSTEP_CLOSE, HEXSTEP_MED, HEXSTEP_FAR
 * retval    : 	N/A
 * Ver       : 1
 * written By: Hafidin (Friday, March 3 2017)
 * Revised By:
 *
 * Programmer's Note:
 *
 */
void Dynamx_Rot_Left_Reverse(int SPEED,  int STEP)
{
	Sendto_PC(USART1,"================ START OF ROTATE LEFT TRIPOD GAIT SEQUENCES ================ \r");

	Sendto_PC(USART1,"<======== STEP 1 \r");
	//1
    //Tripod A
    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[5],4,leg-1); //DEPAN MENAPAK
    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1],4,leg-1); //BELAKANG MENAPAK
    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[3],4,leg-1);  //DEPAN MENAPAK

    //Tripod B
    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[2],1,leg-2);
    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4],1,leg-2);
    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[0],1,leg-2);

    Sendto_PC(USART1,"<======== STEP 2 \r");
    //2
    //Tripod A
    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,4,leg-1); //TENGAH MENAPAK
    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,4,leg-1); //TENGAH MENAPAK
    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,4,leg-1);  //TENGAH MENAPAK

    //Tripod B
    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,1,leg-2);
    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,1,leg-2);
    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90,1,leg-2);

    Sendto_PC(USART1,"<======== STEP 3 \r");
    //3
    //Tripod A
    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[5],4,leg-1); //BELAKANG MENAPAK
    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1],4,leg-1); //DEPAN MENAPAK
    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[3],4,leg-1);  //BELAKANG MENAPAK

    //Tripod B
    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[2],1,leg-2);
    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4],1,leg-2);
    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[0],1,leg-2);

    Sendto_PC(USART1,"<======== STEP 4 \r");
    //4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU

    //Tripod B
    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[2],4,leg-1);
    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4],4,leg-1);
    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[0],4,leg-1);

    //Tripod A
    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[5],1,leg-2); //BELAKANG ANGKAT
    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1],1,leg-2); //DEPAN ANGKAT
    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[3],1,leg-2);  //BELAKANG ANGKAT



    Sendto_PC(USART1,"<======== STEP 5 \r");
    //5
    //Tripod A
    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90,1,leg-2); //TENGAH ANGKAT
    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90,1,leg-2); //TENGAH ANGKAT
    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90,1,leg-2);  //TENGAH ANGKAT

    //Tripod B
    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90,4,leg-1);
    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90,4,leg-1);
    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90,4,leg-1);

    Sendto_PC(USART1,"<======== STEP 6 \r");
    //6
    //Tripod A
    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[5],1,leg-2); //DEPAN ANGKAT
    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1],1,leg-2); //BELAKANG ANGKAT
    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[3],1,leg-2);  //DEPAN ANGKAT

    //Tripod B
    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[2],4,leg-1);
    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4],4,leg-1);
    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[0],4,leg-1);

    Sendto_PC(USART1,"================ END OF ROTATE LEFT TRIPOD GAIT SEQUENCES ================ \r\r");
}


/* func      : 	void Dynamx_CurveRight_PID_Reverse(int SPEED, int STEP, float *ACTUATE_SIGNAL)
 * brief     : 	Dynamixel Hexapod Curve Right locomotion using tripod gait
 * param     :	unsigned int SPEED		-> HEX_SLOW, HEX_MED, HEX_FAST, HEX_ULTRAFAST
 * 				unsigned int STEP	  	-> HEX_CLOSE, HEX_MED, HEX_FAR
 * 				float *ACTUATE_SIGNAL	-> PID Value from PID calculations
 *
 * retval    : 	N/A
 * Ver       : 1
 * written By: Hafidin (Friday, March 3 2017)
 * Revised By: Toni (Monday, October 30 2017)
 * Programmer's Note:
 *
 */
void Dynamx_CurveRight_PID_Reverse(int SPEED, int STEP, volatile float *ACTUATE_SIGNAL, int IKCALC_STAT)
{
//	Sendto_PC(USART1,"BW Curve Right PID \r");
//
//	float signal=*ACTUATE_SIGNAL/5;
//	float error_L=0,error=0;
//	if (signal>=IKPIDR_TIBIA_L[2]){error_L=IKPIDR_TIBIA_L[2];}
//	else {error_L=signal;}
//
//	float DELTA_L=0 + (1 * error_L);
//
//	int DELTA_L0 = (DELTA_L/IKPIDR_TIBIA_L[2])*IKPIDR_COXA_L[0];
//	int DELTA_L1 = (DELTA_L/IKPIDR_TIBIA_L[2])*IKPIDR_COXA_L[1];
//	int DELTA_L2 = (DELTA_L/IKPIDR_TIBIA_L[2])*IKPIDR_COXA_L[2];
//	int DELTA_L3 = (DELTA_L/IKPIDR_TIBIA_L[2])*IKPIDR_TIBIA_L[0];
//	int DELTA_L4 = (DELTA_L/IKPIDR_TIBIA_L[2])*IKPIDR_TIBIA_L[1];
//	int DELTA_L5 = (DELTA_L/IKPIDR_TIBIA_L[2])*IKPIDR_TIBIA_L[2];
//
//	float DELTA_FL=5 + (1 * error);
//	float DELTA_FR=0 + (1 * error);
//	float DELTA_ML=5 + (1 * error);
//	float DELTA_MR=0 + (1 * error);
//	float DELTA_RL=5 + (1 * error);
//	float DELTA_RR=0 + (1 * error);
//
////	lcd_gotoxy(0,0);sprintf(lcd,"act signal: %f",*ACTUATE_SIGNAL);lcd_putstr(lcd);
////	lcd_gotoxy(0,1);sprintf(lcd,"signal: %f",signal);lcd_putstr(lcd);
////	lcd_gotoxy(0,2);sprintf(lcd,"FL: %f",DELTA_FL);lcd_putstr(lcd);
////	lcd_gotoxy(7,2);sprintf(lcd,"FR: %f",DELTA_FR);lcd_putstr(lcd);
////	lcd_gotoxy(3,3);sprintf(lcd,"CURVE LEFT");lcd_putstr(lcd);
//
//	switch(IKCALC_STAT)
//	{
//
//		case IKCALC_ENABLE:
//		{
//			Sendto_PC(USART1,"================ START OF CURVE LEFT TRIPOD GAIT SEQUENCES ================ \r");
//
//			Sendto_PC(USART1,"<======== STEP 1 \r");
//			//1
//		    //Tripod A
//		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[5]-DELTA_FR,4,leg-1);
//		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1]+DELTA_ML,4,leg-1);
//		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[3]-DELTA_RR,4,leg-1);
//
//		    //Tripod B
//		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[2],1,leg-2);
//		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4],1,leg-2);
//		    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[0],1,leg-2);
//
//		//    delay_ms(1000);
//			//BW_Tracer_Check();
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//		    Sendto_PC(USART1,"<======== STEP 2 \r");
//		    //2
//		    //Tripod A
//		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+DELTA_FR,4,leg-1);
//		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-DELTA_ML,4,leg-1); //TENGAH MENAPAK
//		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+DELTA_RR,4,leg-1);
//
//		    //Tripod B
//		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+DELTA_FL,1,leg-2);
//		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-DELTA_MR,1,leg-2);
//		    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+DELTA_RL,1,leg-2);
//
//		//    delay_ms(1000);
//			//BW_Tracer_Check();
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//		    Sendto_PC(USART1,"<======== STEP 3 \r");
//		    //3
//		    //Tripod A
//		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[5]+DELTA_FR,4,leg-1);
//		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1]-DELTA_ML,4,leg-1); //BELAKANG MENAPAK
//		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[3]+DELTA_RR,4,leg-1);
//
//		    //Tripod B
//		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[2]+DELTA_FL,1,leg-2);
//		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4]-DELTA_MR,1,leg-2);
//		    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[0]+DELTA_RL,1,leg-2);
//
//		//    delay_ms(1000);
//			//BW_Tracer_Check();
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//		    Sendto_PC(USART1,"<======== STEP 4 \r"); //PERGANTIAN TRIPOD PENYANGGA HARUS KAKI MENAPAK DULU
//		    //4
//		    //Tripod B
//		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[2]+DELTA_FL,4,leg-1);
//		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4]-DELTA_MR,4,leg-1);
//		    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[0]+DELTA_RL,4,leg-1);
//
//		    //Tripod A
//		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[5],1,leg-2);
//		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1],1,leg-2); //BELAKANG ANGKAT
//		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[3],1,leg-2);
//
//		//    delay_ms(1000);
//			//BW_Tracer_Check();
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//		    Sendto_PC(USART1,"<======== STEP 5 \r");
//		    //5
//		    //Tripod A
//		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-DELTA_FR,1,leg-2);
//		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+DELTA_ML,1,leg-2); //TENGAH ANGKAT
//		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-DELTA_RR,1,leg-2);
//
//		    //Tripod B
//		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-DELTA_FL,4,leg-1);
//		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+DELTA_MR,4,leg-1);
//		    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-DELTA_RL,4,leg-1);
//
//		//    delay_ms(1000);
//			//BW_Tracer_Check();
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//		    Sendto_PC(USART1,"<======== STEP 6 \r");
//		    //6
//		    //Tripod A
//		    Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[5]-DELTA_FR,1,leg-2);
//		    Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1]+DELTA_ML,1,leg-2); //DEPAN ANGKAT
//		    Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[3]-DELTA_RR,1,leg-2);
//
//		    //Tripod B
//		    Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[2]-DELTA_FL,4,leg-1);
//		    Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4]+DELTA_MR,4,leg-1);
//		    Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[0]-DELTA_RL,4,leg-1);
//
//		//    delay_ms(1000);
//			//BW_Tracer_Check();
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//		    Sendto_PC(USART1,"================ END OF CURVE LEFT TRIPOD GAIT SEQUENCES ================ \r\r");
//		}break;
//
//		case IKCALC_DISABLE:
//		{
//
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//			//5
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]+SUDUT_ANGKAT);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3],SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]+SUDUT_ANGKAT);//tengah angkat
//			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+SUDUT_ANGKAT);
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15],SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12],SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]);
//			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9],SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]);
//
//
//			if (Ping[PING_REAR]<=15)break;
//			//BW_Tracer_Check();
//
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//
//			//4
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKBWD_COXA_L[2]-DELTA_L2,SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]+IKBWD_TIBIA_L[0]-DELTA_L3);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]+IKBWD_COXA_R[1],SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]-IKBWD_TIBIA_R[1]);		//depan menapak
//			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKBWD_COXA_L[0]-DELTA_L0,SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]-IKBWD_TIBIA_L[2]+DELTA_L5);
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKBWD_COXA_R[0],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]-IKBWD_TIBIA_R[2]-5);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]-IKBWD_COXA_L[1]+DELTA_L1,SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]-IKBWD_TIBIA_L[1]+DELTA_L4-5);	//belakang angkat
//			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKBWD_COXA_R[2],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+IKBWD_TIBIA_R[0]+5);
//			//					delay_ms(2000);
//
//			//4
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKBWD_COXA_L[2]-DELTA_L2,SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]+IKBWD_TIBIA_L[0]-DELTA_L3);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]+IKBWD_COXA_R[1],SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]-IKBWD_TIBIA_R[1]);		//depan menapak
//			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKBWD_COXA_L[0]-DELTA_L0,SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]-IKBWD_TIBIA_L[2]+DELTA_L5);
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKBWD_COXA_R[0],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]-IKBWD_TIBIA_R[2]-5);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]-IKBWD_COXA_L[1]+DELTA_L1,SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]-IKBWD_TIBIA_L[1]+DELTA_L4-5);	//belakang angkat
//			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKBWD_COXA_R[2],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+IKBWD_TIBIA_R[0]+5);
//			//					delay_ms(2000);
//
//			if (Ping[PING_REAR]<=15)break;
//			//BW_Tracer_Check();
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//			//3
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKBWD_COXA_R[0],SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]-IKBWD_TIBIA_R[2]);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]-IKBWD_COXA_L[1]+DELTA_L1,SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]-IKBWD_TIBIA_L[1]+DELTA_L4);	//belakang menapak
//			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKBWD_COXA_R[2],SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]+IKBWD_TIBIA_R[0]);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKBWD_COXA_L[2]-DELTA_L2,SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]+SUDUT_ANGKAT);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]+IKBWD_COXA_R[1],SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]+SUDUT_ANGKAT);	//depan angkat
//			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKBWD_COXA_L[0]-DELTA_L0,SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+SUDUT_ANGKAT);
//
//			//3
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKBWD_COXA_R[0],SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]-IKBWD_TIBIA_R[2]);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]-IKBWD_COXA_L[1]+DELTA_L1,SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]-IKBWD_TIBIA_L[1]+DELTA_L4);	//belakang menapak
//			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKBWD_COXA_R[2],SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]+IKBWD_TIBIA_R[0]);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKBWD_COXA_L[2]-DELTA_L2,SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]+SUDUT_ANGKAT);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]+IKBWD_COXA_R[1],SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]+SUDUT_ANGKAT);	//depan angkat
//			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKBWD_COXA_L[0]-DELTA_L0,SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+SUDUT_ANGKAT);
//
//			if (Ping[PING_REAR]<=15)break;
//			//BW_Tracer_Check();
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//			//2
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6],SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3],SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]);
//			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0],SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]+SUDUT_ANGKAT);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12],SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]+SUDUT_ANGKAT);
//			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9],SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+SUDUT_ANGKAT);
//
//			if (Ping[PING_REAR]<=15)break;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//			//1
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]+IKBWD_COXA_R[2],SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]+IKBWD_TIBIA_R[0]);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]+IKBWD_COXA_L[1]-DELTA_L1,SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]-IKBWD_TIBIA_L[1]+DELTA_L4); //depan menapak
//			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]+IKBWD_COXA_R[0],SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]-IKBWD_TIBIA_R[2]);
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]-IKBWD_COXA_L[0]+DELTA_L0,SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]-IKBWD_TIBIA_L[2]+DELTA_L5-5);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]-IKBWD_COXA_R[1],SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]-IKBWD_TIBIA_R[1]-5);	//belakang angkat
//			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]-IKBWD_COXA_L[2]+DELTA_L2,SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+IKBWD_TIBIA_L[0]-DELTA_L3+5);
//
//			//1
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]+IKBWD_COXA_R[2],SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]+IKBWD_TIBIA_R[0]);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]+IKBWD_COXA_L[1]-DELTA_L1,SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]-IKBWD_TIBIA_L[1]+DELTA_L4); //depan menapak
//			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]+IKBWD_COXA_R[0],SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]-IKBWD_TIBIA_R[2]);
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]-IKBWD_COXA_L[0]+DELTA_L0,SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]-IKBWD_TIBIA_L[2]+DELTA_L5-5);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]-IKBWD_COXA_R[1],SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]-IKBWD_TIBIA_R[1]-5);	//belakang angkat
//			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]-IKBWD_COXA_L[2]+DELTA_L2,SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+IKBWD_TIBIA_L[0]-DELTA_L3+5);
//			//BW_Tracer_Check();
//
//			if (Ping[PING_REAR]<=15)break;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//			//6
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]+IKBWD_COXA_R[2],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]+SUDUT_ANGKAT);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]+IKBWD_COXA_L[1]-DELTA_L1,SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]+SUDUT_ANGKAT);	//depan angkat
//			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]+IKBWD_COXA_R[0],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+SUDUT_ANGKAT);
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]-IKBWD_COXA_L[0]+DELTA_L0,SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]-IKBWD_TIBIA_L[2]+DELTA_L5);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]-IKBWD_COXA_R[1],SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]-IKBWD_TIBIA_R[1]);	//belakang menapak
//			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]-IKBWD_COXA_L[2]+DELTA_L2,SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]+IKBWD_TIBIA_L[0]-DELTA_L3);
//
//			//6
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]+IKBWD_COXA_R[2],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]+SUDUT_ANGKAT);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]+IKBWD_COXA_L[1]-DELTA_L1,SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]+SUDUT_ANGKAT);	//depan angkat
//			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]+IKBWD_COXA_R[0],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+SUDUT_ANGKAT);
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]-IKBWD_COXA_L[0]+DELTA_L0,SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]-IKBWD_TIBIA_L[2]+DELTA_L5);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]-IKBWD_COXA_R[1],SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]-IKBWD_TIBIA_R[1]);	//belakang menapak
//			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]-IKBWD_COXA_L[2]+DELTA_L2,SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]+IKBWD_TIBIA_L[0]-DELTA_L3);
//
//			if (Ping[PING_REAR]<=15)break;
//			//BW_Tracer_Check();
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
///*
//			//	zR = 15 ZL = 12
//			//5
//			//TRIPOD A
//			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,90,38,126);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,90,35,120);
//			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,90,35,126);
//			//TRIPOD B
//			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,90,20,107);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,20,110);
//			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,90,24,105);
//
//			//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU
//
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83,35,85);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,76+DELTA_L118,35,98+DELTA_L117); //belakang angkat
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78,38,125);
//			//					delay_ms(2000);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,99-DELTA_L116,24,117-DELTA_L115);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107,20,103); //depan menapak
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,96-DELTA_L113,20,91+DELTA_L119);
//			//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU
//
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83,35,85);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,76+DELTA_L118,35,98+DELTA_L117); //belakang angkat
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78,38,125);
//			//					delay_ms(2000);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,99-DELTA_L116,24,117-DELTA_L115);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107,20,103); //depan menapak
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,96-DELTA_L113,20,91+DELTA_L119);
//
//			//3
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83,20,90);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,76+DELTA_L118,20,103+DELTA_L112); //belakang menapak
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78,23,120);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,99-DELTA_L116,39,120);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107,35,128); //depan angkat
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,96-DELTA_L113,35,122);
//
//			//					delay_ms(2000);
//
//			//3
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83,20,90);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,76+DELTA_L118,20,103+DELTA_L112); //belakang menapak
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78,23,120);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,99-DELTA_L116,39,120);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107,35,128); //depan angkat
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,96-DELTA_L113,35,122);
//
//			//					delay_ms(2000);
//
//
//			//TRIPOD A kaki 5cm
//
//			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,90,20,108);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,90,20,105);
//			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,90,23,108);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,90,39,120);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,35,128);
//			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,90,35,122);
//			//BW_Tracer_Check();
//
//			//1
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102,20,120);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,104-DELTA_L118,20,103+DELTA_L112); //depan menapak
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97,23,90);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,84+DELTA_L113,39,89+DELTA_L);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73,35,102); //belakang angkat
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,81+DELTA_L116,35,122-DELTA_L1110);
//			//					delay_ms(2000);
//			//BW_Tracer_Check();
//
//			//1
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102,20,120);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,104-DELTA_L118,20,103+DELTA_L112); //depan menapak
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97,23,90);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,84+DELTA_L113,39,89+DELTA_L);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73,35,102); //belakang angkat
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,81+DELTA_L116,35,122-DELTA_L1110);
//			//					delay_ms(2000);
//			//BW_Tracer_Check();
//
//
//			//BW_Tracer_Check();
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//			//6
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102,35,126);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,104-DELTA_L118,35,120); //depan angkat
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97,38,126);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,84+DELTA_L113,24,91+DELTA_L119);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73,20,107); //belakang menapak
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,81+DELTA_L116,20,115-DELTA_L113);
//			//					delay_ms(2000);
//
//			//6
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102,35,126);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,104-DELTA_L118,35,120); //depan angkat
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97,38,126);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,84+DELTA_L113,24,91+DELTA_L119);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73,20,107); //belakang menapak
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,81+DELTA_L116,20,115-DELTA_L113);
//
//			//					delay_ms(2000);
//*/
////===========================================================================================///
///*			//	zR = 15 ZL = 5
//						//5
//						//TRIPOD A
//						Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,90,38,126);
//						Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,90,35,120);
//						Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,90,35,126);
//						//TRIPOD B
//						Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,90,20,107);
//						Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,20,110);
//						Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,90,24,105);
//
//						//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU
//
//						//TRIPOD A
//						Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83,35,85);
//						Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,84,35,105); //belakang angkat
//						Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78,38,125);
//						//					delay_ms(2000);
//
//						//TRIPOD B
//						Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,93,24,112);
//						Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107,20,103); //depan menapak
//						Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,93,20,100);
//
//						//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU
//
//						//TRIPOD A
//						Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83,35,85);
//						Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,84,35,105); //belakang angkat
//						Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78,38,125);
//						//					delay_ms(2000);
//
//						//TRIPOD B
//						Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,93,24,112);
//						Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107,20,103); //depan menapak
//						Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,93,20,100);
//
//						//3
//						//TRIPOD A
//						Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83,20,90);
//						Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,84,20,105); //belakang menapak
//						Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78,23,120);
//
//						//TRIPOD B
//						Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,93,39,120);
//						Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107,35,128); //depan angkat
//						Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,93,35,122);
//
//						//					delay_ms(2000);
//
//						//3
//						//TRIPOD A
//						Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83,20,90);
//						Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,84,20,105); //belakang menapak
//						Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78,23,120);
//
//						//TRIPOD B
//						Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,93,39,120);
//						Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107,35,128); //depan angkat
//						Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,93,35,122);
//
//						//					delay_ms(2000);
//
//
//						//TRIPOD A kaki 5cm
//
//						Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,90,20,108);
//						Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,90,20,105);
//						Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,90,23,108);
//
//						//TRIPOD B
//						Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,90,39,120);
//						Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,35,128);
//						Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,90,35,122);
//						//BW_Tracer_Check();
//
//						//1
//						//TRIPOD A
//						Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102,20,120);
//						Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,96,20,105); //depan menapak
//						Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97,23,90);
//
//						//TRIPOD B
//						Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,87,39,100);
//						Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73,35,102); //belakang angkat
//						Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,87,35,112);
//						//					delay_ms(2000);
//						//BW_Tracer_Check();
//
//						//1
//						//TRIPOD A
//						Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102,20,120);
//						Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,96,20,105); //depan menapak
//						Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97,23,90);
//
//						//TRIPOD B
//						Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,87,39,95);
//						Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73,35,102); //belakang angkat
//						Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,87,35,117);
//						//					delay_ms(2000);
//						//BW_Tracer_Check();
//
//						//6
//						//TRIPOD A
//						Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102,35,126);
//						Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,96,35,120); //depan angkat
//						Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97,38,126);
//
//						//TRIPOD B
//						Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,87,24,100);
//						Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73,20,107); //belakang menapak
//						Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,87,20,112);
//
//						//					delay_ms(2000);
//
//						//6
//						//TRIPOD A
//						Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102,35,126);
//						Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,96,35,120); //depan angkat
//						Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97,38,126);
//
//						//TRIPOD B
//						Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,87,24,100);
//						Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73,20,107); //belakang menapak
//						Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,87,20,112);
//
//						//					delay_ms(2000);
//*/
//	///===========================================================================================//
//
///*			//1
//			//TRIPOD A
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,81-DELTA_FR,14,108);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,69+DELTA_ML,14,108);
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,74-DELTA_FR,14,108);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,98,32,114);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,110,32,114);
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,105,32,114);
//
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//			//2
//			//TRIPOD A
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,90+DELTA_FR,14,108);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,90-DELTA_ML,14,108);
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,90+DELTA_FR,14,108);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,90+DELTA_FR,32,114);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90-DELTA_ML,32,114);
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,90+DELTA_FR,32,114);
//
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//			//3
//			//TRIPOD A
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,98+DELTA_FR,14,108);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,110-DELTA_ML,14,108);
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,105+DELTA_FR,14,108);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,81+DELTA_FR,32,114);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,69-DELTA_ML,32,114);
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,74+DELTA_FR,32,114);
//
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//			//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU
//			//TRIPOD B
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,81+DELTA_FR,14,108);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,69-DELTA_MR,14,108);
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,74+DELTA_FR,14,108);
//
//			//TRIPOD A
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,98,32,114);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,110,32,114);
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,105,32,114);
//
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//			//5
//			//TRIPOD A
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,90-DELTA_MR,32,114);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,90+DELTA_ML,32,114);
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,90-DELTA_MR,32,114);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,90-DELTA_MR,14,108);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90+DELTA_ML,14,108);
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,90-DELTA_MR,14,108);
//
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//			//6
//			//TRIPOD A
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,81-DELTA_FR,32,114);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,69+DELTA_ML,32,114);
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,74-DELTA_FR,32,114);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,98-DELTA_FR,14,108);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,110+DELTA_ML,14,108);
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,105-DELTA_FR,14,108);
//
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//*/
//		}break;
//	}
//
}

/* func      : 	void Dynamx_CurveLeft_PID_Reverse(int SPEED, int STEP, float *ACTUATE_SIGNAL)
 * brief     : 	Dynamixel Hexapod Curve Right locomotion using tripod gait
 * param     :	unsigned int SPEED		-> HEX_SLOW, HEX_MED, HEX_FAST, HEX_ULTRAFAST
 * 				unsigned int STEP	  	-> HEX_CLOSE, HEX_MED, HEX_FAR
 * 				float *ACTUATE_SIGNAL	-> PID Value from PID calculations
 *
 * retval    : 	N/A
 * Ver       : 1
 * written By: Hafidin (Friday, March 3 2017)
 * Revised By: Toni (Monday, October 30 2017)
 * Programmer's Note:
 *
 */
void Dynamx_CurveLeft_PID_Reverse(int SPEED, int STEP, volatile float *ACTUATE_SIGNAL, int IKCALC_STAT)
{
//	float signal=*ACTUATE_SIGNAL/5;
//	float error_L,error_R,error;
////	if (signal>=18){error_R=18;}
////	if (signal>=5){error_L=5;}
//	if (signal>=IKPIDR_TIBIA_R[2]){error_R=IKPIDR_TIBIA_R[2];}
//	//if (signal>=7){error_L=7;}
//	else {error_R=signal;}
//
//	float DELTA_R=0 + (1 * error_R);
//
//	int DELTA_R0 = (DELTA_R/IKPIDR_TIBIA_R[2])*IKPIDR_COXA_R[0];
//	int DELTA_R1 = (DELTA_R/IKPIDR_TIBIA_R[2])*IKPIDR_COXA_R[1];
//	int DELTA_R2 = (DELTA_R/IKPIDR_TIBIA_R[2])*IKPIDR_COXA_R[2];
//	int DELTA_R3 = (DELTA_R/IKPIDR_TIBIA_R[2])*IKPIDR_TIBIA_R[0];
//	int DELTA_R4 = (DELTA_R/IKPIDR_TIBIA_R[2])*IKPIDR_TIBIA_R[1];
//	int DELTA_R5 = (DELTA_R/IKPIDR_TIBIA_R[2])*IKPIDR_TIBIA_R[2];
//
//	float DELTA_FL=0 + (1 * error);
//	float DELTA_FR=5 + (1 * error);
//	float DELTA_ML=0 + (1 * error);
//	float DELTA_MR=5 + (1 * error);
//	float DELTA_RL=0 + (1 * error);
//	float DELTA_RR=5 + (1 * error);
//
////	lcd_gotoxy(0,0);sprintf(lcd,"act signal: %f",*ACTUATE_SIGNAL);lcd_putstr(lcd);
////	lcd_gotoxy(0,1);sprintf(lcd,"signal: %f",signal);lcd_putstr(lcd);
////	lcd_gotoxy(0,2);sprintf(lcd,"FL: %f",DELTA_FL);lcd_putstr(lcd);
////	lcd_gotoxy(7,2);sprintf(lcd,"FR: %f",DELTA_FR);lcd_putstr(lcd);
////	lcd_gotoxy(3,3);sprintf(lcd,"CURVE RIGHT");lcd_putstr(lcd);
//
//	switch(IKCALC_STAT)
//	{
//
//		case IKCALC_ENABLE:
//		{
//
//			Sendto_PC(USART1,"<======== STEP 1 \r");
//			//1
//			//Tripod A
//			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[5]+DELTA_FR,4,leg-1);
//			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1]-DELTA_ML,4,leg-1); //DEPAN MENAPAK
//			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[3]+DELTA_RR,4,leg-1);
//
//			//Tripod B
//			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[2],1,leg-2);
//			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4],1,leg-2);
//			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[0],1,leg-2);
//
//		//    delay_ms(1000);
//			//BW_Tracer_Check();
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
////			Tracer_Check();
//
//			Sendto_PC(USART1,"<======== STEP 2 \r");
//			//2
//			//Tripod A
//			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-DELTA_FR,4,leg-1);
//			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+DELTA_ML,4,leg-1); //TENGAH MENAPAK
//			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-DELTA_RR,4,leg-1);
//
//			//Tripod B
//			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-DELTA_FL,1,leg-2);
//			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+DELTA_MR,1,leg-2);
//			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-DELTA_RL,1,leg-2);
//
//		//    delay_ms(1000);
//			//BW_Tracer_Check();
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
////			Tracer_Check();
//
//			Sendto_PC(USART1,"<======== STEP 3 \r");
//			//3
//			//Tripod A
//			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[5]-DELTA_FR,4,leg-1);
//			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1]+DELTA_ML,4,leg-1); //BELAKANG MENAPAK
//			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[3]-DELTA_RR,4,leg-1);
//
//			//Tripod B
//			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[2]-DELTA_FL,1,leg-2);
//			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4]+DELTA_MR,1,leg-2);
//			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[0]-DELTA_RL,1,leg-2);
//
//		//    delay_ms(1000);
//			//BW_Tracer_Check();
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
////			Tracer_Check();
//
//			Sendto_PC(USART1,"<======== STEP 4 \r"); //PERGANTIAN TRIPOD PENYANGGA HARUS KAKI MENAPAK DULU
//			//4
//			//Tripod B
//			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90-beta[2]-DELTA_FL,4,leg-1);
//			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-beta[4]+DELTA_MR,4,leg-1);
//			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90-beta[0]-DELTA_RL,4,leg-1);
//
//			//Tripod A
//			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+beta[5],1,leg-2);
//			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90+beta[1],1,leg-2); //BELAKANG ANGKAT
//			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+beta[3],1,leg-2);
//
//		//    delay_ms(1000);
//			//BW_Tracer_Check();
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
////			Tracer_Check();
//
//			Sendto_PC(USART1,"<======== STEP 5 \r");
//			//5
//			//Tripod A
//			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90+DELTA_FR,1,leg-2);
//			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-DELTA_ML,1,leg-2); //TENGAH ANGKAT
//			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90+DELTA_RR,1,leg-2);
//
//			//Tripod B
//			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+DELTA_FL,4,leg-1);
//			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90-DELTA_MR,4,leg-1);
//			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+DELTA_RL,4,leg-1);
//
//		//    delay_ms(1000);
//			//BW_Tracer_Check();
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
////			Tracer_Check();
//
//			Sendto_PC(USART1,"<======== STEP 6 \r");
//			//6
//			//Tripod A
//			Dynamx_IK(FRONT_RIGHT_DX,	&SPEED,90-beta[5]+DELTA_FR,1,leg-2);
//			Dynamx_IK(MIDDLE_LEFT_DX,	&SPEED,90-beta[1]-DELTA_ML,1,leg-2); //DEPAN ANGKAT
//			Dynamx_IK(REAR_RIGHT_DX,	&SPEED,90-beta[3]+DELTA_RR,1,leg-2);
//
//			//Tripod B
//			Dynamx_IK(FRONT_LEFT_DX,	&SPEED,90+beta[2]+DELTA_FL,4,leg-1);
//			Dynamx_IK(MIDDLE_RIGHT_DX,	&SPEED,90+beta[4]-DELTA_MR,4,leg-1);
//			Dynamx_IK(REAR_LEFT_DX,	&SPEED,90+beta[0]+DELTA_RL,4,leg-1);
//
//		//    delay_ms(1000);
//			//BW_Tracer_Check();
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
////			Tracer_Check();
//
//			Sendto_PC(USART1,"================ END OF CURVE RIGHT TRIPOD GAIT SEQUENCES ================ \r\r");
//		}break;
//
//		case IKCALC_DISABLE:
//		{
//
//			//				====== Z=35 TIBIA Z=25 ======
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//			//5
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6],SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]+SUDUT_ANGKAT);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3],SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]+SUDUT_ANGKAT);//tengah angkat
//			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0],SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+SUDUT_ANGKAT);
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15],SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12],SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]);
//			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9],SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]);
//
//
//			if (Ping[PING_REAR]<=15)break;
//			//BW_Tracer_Check();
//
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//			//4
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKBWD_COXA_L[2],SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]+IKBWD_TIBIA_L[0]);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]+IKBWD_COXA_R[1]-DELTA_R1,SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]-IKBWD_TIBIA_R[1]+DELTA_R4);		//depan menapak
//			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKBWD_COXA_L[0],SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]-IKBWD_TIBIA_L[2]);
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKBWD_COXA_R[0]+DELTA_R0,SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]-IKBWD_TIBIA_R[2]+DELTA_R5-5);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]-IKBWD_COXA_L[1],SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]-IKBWD_TIBIA_L[1]-5);	//belakang angkat
//			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKBWD_COXA_R[2]+DELTA_R2,SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+IKBWD_TIBIA_R[0]-DELTA_R3+5);
//			//					delay_ms(2000);
//
//			//4
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKBWD_COXA_L[2],SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]+IKBWD_TIBIA_L[0]);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]+IKBWD_COXA_R[1]-DELTA_R1,SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]-IKBWD_TIBIA_R[1]+DELTA_R4);		//depan menapak
//			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKBWD_COXA_L[0],SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]-IKBWD_TIBIA_L[2]);
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKBWD_COXA_R[0]+DELTA_R0,SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]-IKBWD_TIBIA_R[2]+DELTA_R5-5);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]-IKBWD_COXA_L[1],SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]-IKBWD_TIBIA_L[1]-5);	//belakang angkat
//			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKBWD_COXA_R[2]+DELTA_R2,SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+IKBWD_TIBIA_R[0]-DELTA_R3+5);
//			//					delay_ms(2000);
//
//			if (Ping[PING_REAR]<=15)break;
//			//BW_Tracer_Check();
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//			//3
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKBWD_COXA_R[0]+DELTA_R0,SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]-IKBWD_TIBIA_R[2]+DELTA_R5);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]-IKBWD_COXA_L[1],SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]-IKBWD_TIBIA_L[1]);	//belakang menapak
//			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKBWD_COXA_R[2]+DELTA_R2,SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]+IKBWD_TIBIA_R[0]-DELTA_R3);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKBWD_COXA_L[2],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]+SUDUT_ANGKAT);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]+IKBWD_COXA_R[1]-DELTA_R1,SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]+SUDUT_ANGKAT);	//depan angkat
//			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKBWD_COXA_L[0],SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+SUDUT_ANGKAT);
//
//			//3
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]-IKBWD_COXA_R[0]+DELTA_R0,SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]-IKBWD_TIBIA_R[2]+DELTA_R5);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]-IKBWD_COXA_L[1],SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]-IKBWD_TIBIA_L[1]);	//belakang menapak
//			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]-IKBWD_COXA_R[2]+DELTA_R2,SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]+IKBWD_TIBIA_R[0]-DELTA_R3);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]+IKBWD_COXA_L[2],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]+SUDUT_ANGKAT);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]+IKBWD_COXA_R[1]-DELTA_R1,SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]+SUDUT_ANGKAT);	//depan angkat
//			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]+IKBWD_COXA_L[0],SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+SUDUT_ANGKAT);
//
//			if (Ping[PING_REAR]<=15)break;
//			//BW_Tracer_Check();
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//			//2
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6],SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3],SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]);
//			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0],SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]+SUDUT_ANGKAT);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12],SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]+SUDUT_ANGKAT);
//			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9],SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+SUDUT_ANGKAT);
//
//			if (Ping[PING_REAR]<=15)break;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//			//1
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]+IKBWD_COXA_R[2]-DELTA_R2,SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]+IKBWD_TIBIA_R[0]-DELTA_R3);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]+IKBWD_COXA_L[1],SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]-IKBWD_TIBIA_L[1]); //depan menapak
//			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]+IKBWD_COXA_R[0]-DELTA_R0,SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]-IKBWD_TIBIA_R[2]+DELTA_R5);
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]-IKBWD_COXA_L[0],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]-IKBWD_TIBIA_L[2]-5);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]-IKBWD_COXA_R[1]+DELTA_R1,SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]-IKBWD_TIBIA_R[1]+DELTA_R4-5);	//belakang angkat
//			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]-IKBWD_COXA_L[2],SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+IKBWD_TIBIA_L[0]+5);
//
//			//1
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]+IKBWD_COXA_R[2]-DELTA_R2,SUDUT_STATIC_BWD[7],SUDUT_STATIC_BWD[8]+IKBWD_TIBIA_R[0]-DELTA_R3);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]+IKBWD_COXA_L[1],SUDUT_STATIC_BWD[4],SUDUT_STATIC_BWD[5]-IKBWD_TIBIA_L[1]); //depan menapak
//			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]+IKBWD_COXA_R[0]-DELTA_R0,SUDUT_STATIC_BWD[1],SUDUT_STATIC_BWD[2]-IKBWD_TIBIA_R[2]+DELTA_R5);
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]-IKBWD_COXA_L[0],SUDUT_STATIC_BWD[16]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[17]-IKBWD_TIBIA_L[2]-5);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]-IKBWD_COXA_R[1]+DELTA_R1,SUDUT_STATIC_BWD[13]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[14]-IKBWD_TIBIA_R[1]+DELTA_R4-5);	//belakang angkat
//			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]-IKBWD_COXA_L[2],SUDUT_STATIC_BWD[10]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[11]+IKBWD_TIBIA_L[0]+5);
//			//BW_Tracer_Check();
//
//			if (Ping[PING_REAR]<=15)break;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//			//6
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]+IKBWD_COXA_R[2]-DELTA_R2,SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]+SUDUT_ANGKAT);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]+IKBWD_COXA_L[1],SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]+SUDUT_ANGKAT);	//depan angkat
//			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]+IKBWD_COXA_R[0]-DELTA_R0,SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+SUDUT_ANGKAT);
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]-IKBWD_COXA_L[0],SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]-IKBWD_TIBIA_L[2]);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]-IKBWD_COXA_R[1]+DELTA_R1,SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]-IKBWD_TIBIA_R[1]+DELTA_R4);	//belakang menapak
//			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]-IKBWD_COXA_L[2],SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]+IKBWD_TIBIA_L[0]);
//
//			//6
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,SUDUT_STATIC_BWD[6]+IKBWD_COXA_R[2]-DELTA_R2,SUDUT_STATIC_BWD[7]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[8]+SUDUT_ANGKAT);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,SUDUT_STATIC_BWD[3]+IKBWD_COXA_L[1],SUDUT_STATIC_BWD[4]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[5]+SUDUT_ANGKAT);	//depan angkat
//			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,SUDUT_STATIC_BWD[0]+IKBWD_COXA_R[0]-DELTA_R0,SUDUT_STATIC_BWD[1]+SUDUT_ANGKAT,SUDUT_STATIC_BWD[2]+SUDUT_ANGKAT);
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,SUDUT_STATIC_BWD[15]-IKBWD_COXA_L[0],SUDUT_STATIC_BWD[16],SUDUT_STATIC_BWD[17]-IKBWD_TIBIA_L[2]);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,SUDUT_STATIC_BWD[12]-IKBWD_COXA_R[1]+DELTA_R1,SUDUT_STATIC_BWD[13],SUDUT_STATIC_BWD[14]-IKBWD_TIBIA_R[1]+DELTA_R4);	//belakang menapak
//			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,SUDUT_STATIC_BWD[9]-IKBWD_COXA_L[2],SUDUT_STATIC_BWD[10],SUDUT_STATIC_BWD[11]+IKBWD_TIBIA_L[0]);
//
//			if (Ping[PING_REAR]<=15)break;
//			//BW_Tracer_Check();
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
///*
//			//	zR = 15 ZL = 12
//			//5
//			//TRIPOD A
//			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,90,38,126);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,90,35,120);
//			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,90,35,126);
//			//TRIPOD B
//			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,90,20,107);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,20,110);
//			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,90,24,105);
//
//			//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU
//
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83+DELTA_R184,35,85+DELTA_R);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,76-DELTA_L53,35,98-DELTA_L51); //belakang angkat
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78+DELTA_R189,38,125-DELTA_R1812);
//			//					delay_ms(2000);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,99+DELTA_L53,24,117+DELTA_L52);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107-DELTA_R1811,20,103+DELTA_R182); //depan menapak
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,96+DELTA_L51,20,91-DELTA_L54);
//
//			//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU
//
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83+DELTA_R184,35,85+error_R);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,76-DELTA_L53,35,98-DELTA_L51); //belakang angkat
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78+DELTA_R189,38,125-DELTA_R1812);
//			//					delay_ms(2000);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,99+DELTA_L53,24,117+DELTA_L52);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107-DELTA_R1811,20,103+DELTA_R182); //depan menapak
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,96+DELTA_L51,20,91-DELTA_L54);
//
//			//3
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83+DELTA_R184,20,90+DELTA_R1813);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,76-DELTA_L53,20,103-DELTA_L51); //belakang menapak
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78+DELTA_R1811,23,120-DELTA_R187);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,99+DELTA_L53,39,120);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107-DELTA_R1811,35,128); //depan angkat
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,96+DELTA_L51,35,122);
//
//			//					delay_ms(2000);
//
//			//3
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,83+DELTA_R184,20,90+DELTA_R1813);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,76-DELTA_L53,20,103-DELTA_L51); //belakang menapak
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,78+DELTA_R1811,23,120-DELTA_R187);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,99+DELTA_L53,39,120);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,107-DELTA_R1811,35,128); //depan angkat
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,96+DELTA_L51,35,122);
//
//			//					delay_ms(2000);
//
//			//TRIPOD A kaki 5cm
//
//			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,90,20,108);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,90,20,105);
//			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,90,23,108);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,90,39,120);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,35,128);
//			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,90,35,122);
//			//BW_Tracer_Check();
//
//			//1
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102-DELTA_R189,20,120-DELTA_R187);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,104+DELTA_L53,20,103); //depan menapak
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97-DELTA_R184,23,90+DELTA_R1813);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,84-DELTA_L51,39,89-DELTA_L);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73+DELTA_R1811,35,102); //belakang angkat
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,81-DELTA_L53,35,122-DELTA_L);
//			//					delay_ms(2000);
//			//BW_Tracer_Check();
//
//			//1
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102-DELTA_R189,20,120-DELTA_R187);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,104+DELTA_L53,20,103); //depan menapak
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97-DELTA_R184,23,90+DELTA_R1813);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,84-DELTA_L51,39,89-DELTA_L);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73+DELTA_R1811,35,102); //belakang angkat
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,81-DELTA_L53,35,122-DELTA_L);
//			//					delay_ms(2000);
//			//BW_Tracer_Check();
//
//
//			//BW_Tracer_Check();
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//			//6
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102-DELTA_R189,35,126);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,104+DELTA_L53,35,120); //depan angkat
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97-DELTA_R184,38,126);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,84-DELTA_L51,24,91-DELTA_L52);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73+DELTA_R1811,20,107); //belakang menapak
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,81-DELTA_L53,20,115+DELTA_L52);
//
//			//					delay_ms(2000);
//
//			//6
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,102-DELTA_R189,35,126);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,104+DELTA_L53,35,120); //depan angkat
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,97-DELTA_R184,38,126);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,84-DELTA_L51,24,91-DELTA_L52);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,73+DELTA_R1811,20,107); //belakang menapak
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,81-DELTA_L53,20,115+DELTA_L52);
//
//			//					delay_ms(2000);
//*/
////==================================================================================//
///*			//	zR = 5 ZL = 15
//			//5
//			//TRIPOD A
//			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,90,38,126);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,90,35,120);
//			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,90,35,126);
//			//TRIPOD B
//			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,90,20,107);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,20,110);
//			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,90,24,105);
//
//			//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU
//
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,87,35,103);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,73,35,97); //belakang angkat
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,87,38,113);
//			//					delay_ms(2000);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,102,24,119);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,96,20,105); //depan menapak
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,97,20,87);
//
//			//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU
//
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,87,35,103);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,73,35,102); //belakang angkat
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,87,38,113);
//			//					delay_ms(2000);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,102,24,119);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,96,20,105); //depan menapak
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,97,20,87);
//
//			//3
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,87,20,103);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,73,20,102); //belakang menapak
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,87,23,113);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,102,39,120);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,96,35,128); //depan angkat
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,97,35,122);
//
//			//					delay_ms(2000);
//
//			//3
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,87,20,103);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,73,20,102); //belakang menapak
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,87,23,113);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,102,39,120);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,96,35,128); //depan angkat
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,97,35,122);
//
//			//					delay_ms(2000);
//
//
//			//TRIPOD A kaki 5cm
//
//			Dynamx_MoveLeg(REAR_RIGHT_DX,  &SPEED,90,20,108);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX, &SPEED,90,20,105);
//			Dynamx_MoveLeg(FRONT_RIGHT_DX, &SPEED,90,23,108);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,   &SPEED,90,39,120);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90,35,128);
//			Dynamx_MoveLeg(FRONT_LEFT_DX,  &SPEED,90,35,122);
//			//BW_Tracer_Check();
//
//			//1
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,93,20,113);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,107,20,102); //depan menapak
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,93,23,90);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,83,39,84);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,84,35,105); //belakang angkat
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,78,35,122);
//			//					delay_ms(2000);
//			//BW_Tracer_Check();
//
//			//1
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,93,20,113);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,107,20,102); //depan menapak
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,93,23,103);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,83,39,84);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,84,35,105); //belakang angkat
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,78,35,122);
//			//					delay_ms(2000);
//			//BW_Tracer_Check();
//
//			//6
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,93,35,126);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,107,35,120); //depan angkat
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,93,38,126);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,83,24,89);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,84,20,105); //belakang menapak
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,78,20,117);
//
//			//					delay_ms(2000);
//
//			//6
//			//TRIPOD A
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,93,35,126);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,107,35,120); //depan angkat
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,93,38,126);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,83,24,89);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,	&SPEED,84,20,105); //belakang menapak
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,78,20,117);
//
//			//					delay_ms(2000);
//
//*/
////============================================================================================//
///*			//1
//			//TRIPOD A
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,81+DELTA_FR,14,108);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,69-DELTA_ML,14,108);
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,74+DELTA_FR,14,108);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,98,32,114);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,110,32,114);
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,105,32,114);
//
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//			//2
//			//TRIPOD A
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,90-DELTA_FR,14,108);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,90+DELTA_ML,14,108);
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,90-DELTA_FR,14,108);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,90-DELTA_FR,32,114);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90+DELTA_ML,32,114);
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,90-DELTA_FR,32,114);
//
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//			//3
//			//TRIPOD A
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,98-DELTA_FR,14,108);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,110+DELTA_ML,14,108);
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,105-DELTA_FR,14,108);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,81-DELTA_FR,32,114);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,69+DELTA_ML,32,114);
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,74-DELTA_FR,32,114);
//
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//			//4 PERGANTIAN TRIPOD HARUS KAKI MENAPAK TERLEBIH DAHULU
//			//TRIPOD B
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,81-DELTA_FR,14,108);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,69+DELTA_MR,14,108);
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,74-DELTA_FR,14,108);
//
//			//TRIPOD A
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,98,32,114);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,110,32,114);
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,105,32,114);
//
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//			//5
//			//TRIPOD A
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,90+DELTA_MR,32,114);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,90-DELTA_ML,32,114);
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,90+DELTA_MR,32,114);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,90+DELTA_MR,14,108);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,90-DELTA_ML,14,108);
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,90+DELTA_MR,14,108);
//
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//
//			//6
//			//TRIPOD A
//			Dynamx_MoveLeg(FRONT_RIGHT_DX,	&SPEED,81+DELTA_FR,32,114);
//			Dynamx_MoveLeg(MIDDLE_LEFT_DX,	&SPEED,69-DELTA_ML,32,114);
//			Dynamx_MoveLeg(REAR_RIGHT_DX,	&SPEED,74+DELTA_FR,32,114);
//
//			//TRIPOD B
//			Dynamx_MoveLeg(FRONT_LEFT_DX,	&SPEED,98+DELTA_FR,14,108);
//			Dynamx_MoveLeg(MIDDLE_RIGHT_DX,&SPEED,110-DELTA_ML,14,108);
//			Dynamx_MoveLeg(REAR_LEFT_DX,	&SPEED,105+DELTA_FR,14,108);
//
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//			TCS3200_Transmit(UART5, CMD_GET_TRACER);
//			if(TCS3200_SLV_DATA[1]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
//*/
//		}break;
//	}
}

void Dynamx_MovFwdClimbing_Interpolate(int SPEED, int limit, int movement)
{
	int cek_siklus = 0;
	int cek_value = 0;
	SPEED = SPEED/33;

	if(IK_CALCULATED_CLMB==0)
	{
		Generate_Body(0,1.5);
		Trajectory_Generator_Climbing(X_Diff, Y_Diff, -3.75, 4,MOVEMENT_NORMAL);

		switch (movement)
		{
			case 0:
			{
				for (int j=0; j<6; j++)
				{
					Z_IK_S_BUFF[j] = Z_IK_STAIRS[j];
				}

			}break;

			case 1:
			{
				for (int j=0; j<6; j++)
				{
					if ((j == 4) || (j == 5))//belakang
					{
						Z_IK_S_BUFF[j] = Z_IK_STAIRS[j];
					}

					else if ((j == 2) || (j == 3))//tengah
					{
						Z_IK_S_BUFF[j] = Z_IK_STAIRS[j];
					}

					else//depan
					{
						Z_IK_S_BUFF[j] = Z_IK_STAIRS[j];
					}
				}

			}break;

			case 2:
			{
				for (int j=0; j<6; j++)
				{
					if ((j == 4) || (j == 5))//belakang
					{
						Z_IK_S_BUFF[j] = Z_IK_STAIRS[j]+3.65;//3.65
					}

					else if ((j == 2) || (j == 3))//tengah
					{
						Z_IK_S_BUFF[j] = Z_IK_STAIRS[j]+0.25;//0.25
					}

					else//depan
					{
						Z_IK_S_BUFF[j] = Z_IK_STAIRS[j]-2.75;//-2.75
					}
				}
			}break;

			case 3:
			{
				for (int j=0; j<6; j++)
				{
					if ((j == 4) || (j == 5))//belakang
					{
						Z_IK_S_BUFF[j] = Z_IK_STAIRS[j];
					}

					else if ((j == 2) || (j == 3))//tengah
					{
						Z_IK_S_BUFF[j] = Z_IK_STAIRS[j];
					}

					else//depan
					{
						Z_IK_S_BUFF[j] = Z_IK_STAIRS[j];
					}
				}
			}break;
		}

		if (STATIC_CLIMBING == 0)
		{
			Dyna_IKCalc_Only_Static_Climbing(FRONT_RIGHT_DX,   X_IK_OBS[1], Y_IK_BEGIN[1],Z_IK_S_BUFF[1], &SPEED);
			Dyna_IKCalc_Only_Static_Climbing(MIDDLE_LEFT_DX,   X_IK_OBS[2], Y_IK_BEGIN[2],Z_IK_S_BUFF[2], &SPEED);
			Dyna_IKCalc_Only_Static_Climbing(REAR_RIGHT_DX,    X_IK_OBS[5], Y_IK_BEGIN[5],Z_IK_S_BUFF[5], &SPEED);

			Dyna_IKCalc_Only_Static_Climbing(FRONT_LEFT_DX,    X_IK_OBS[0], Y_IK_BEGIN[0],Z_IK_S_BUFF[0], &SPEED);
			Dyna_IKCalc_Only_Static_Climbing(MIDDLE_RIGHT_DX,  X_IK_OBS[3], Y_IK_BEGIN[3],Z_IK_S_BUFF[3], &SPEED);
			Dyna_IKCalc_Only_Static_Climbing(REAR_LEFT_DX,     X_IK_OBS[4], Y_IK_BEGIN[4],Z_IK_S_BUFF[4], &SPEED);
			Start_Pose_SYNC();
			delay_ms(SPEED);

			if(cek_siklus==1)
			{
				while(1)
				{
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"STATIC CLIMB");lcd_putstr(lcd);
					if(BW_BUTTON_CLICKED)break;
				}
			}
			STATIC_CLIMBING = 1;
		}

		for(i=0;i<=3;i++)
		{
			Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[1]+Z_IK[i]));
			FEMUR_S_F[i] = tetha.Femur;
			NFEMUR_S_F[i] = (tetha.Femur*-1);

			Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[2]+Z_IK[i]));
			FEMUR_S_M[i] = tetha.Femur;
			NFEMUR_S_M[i] = (tetha.Femur*-1);

			Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[5]+Z_IK[i]));
			FEMUR_S_R[i] = tetha.Femur;
			NFEMUR_S_R[i] = (tetha.Femur*-1);

			Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_STAIRS[1]+Z_IK[i]));
			COXA_S[i] = tetha.Coxa;
			NCOXA_S[i] = (tetha.Coxa*-1);

	//		Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_STAIRS[1]));
			Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[1]));
			TIBIA_S[i] = tetha.Tibia;

	//		Dyna_IKCalc_Only((X_IK_OBS[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_STAIRS[1]));
			Dyna_IKCalc_Only((X_IK_OBS[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[1]));
			NTIBIA_S[i] = tetha.Tibia;

			Dyna_IKCalc_Only((X_IK_OBS[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[4]));
			NTIBIA_S_R[i] = tetha.Tibia;

			Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[5]));
			TIBIA_S_R[i] = tetha.Tibia;
		}
		IK_CALCULATED_CLMB = 1;
	}


	if(cek_value==1)
	{
		while(1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"STATIC IK S");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"%d|%d|%d",X_STATIC_IK_S[0],X_STATIC_IK_S[2],X_STATIC_IK_S[4]);lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d",Y_STATIC_IK_S[0],Y_STATIC_IK_S[2],Y_STATIC_IK_S[4]);lcd_putstr(lcd);
				lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d",Z_STATIC_IK_S[0],Z_STATIC_IK_S[2],Z_STATIC_IK_S[4]);lcd_putstr(lcd);
				delay_ms(100);
				if(BW_BUTTON_CLICKED)break;
			}

			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"COXA TIBIA|R");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"%d|%d|%d|%d",COXA_S[0],COXA_S[1],COXA_S[2],COXA_S[3]);lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d|%d",TIBIA_S[0],TIBIA_S[1],TIBIA_S[2],TIBIA_S[3]);lcd_putstr(lcd);
				lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d|%d",TIBIA_S_R[0],TIBIA_S_R[1],TIBIA_S_R[2],TIBIA_S_R[3]);lcd_putstr(lcd);
				delay_ms(100);
				if(BW_BUTTON_CLICKED)break;
			}

			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FEMUR");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"%d|%d|%d|%d",FEMUR_S_F[0],FEMUR_S_F[1],FEMUR_S_F[2],FEMUR_S_F[3]);lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d|%d",FEMUR_S_M[0],FEMUR_S_M[1],FEMUR_S_M[2],FEMUR_S_M[3]);lcd_putstr(lcd);
				lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d|%d",FEMUR_S_R[0],FEMUR_S_R[1],FEMUR_S_R[2],FEMUR_S_R[3]);lcd_putstr(lcd);
				delay_ms(100);
				if(BW_BUTTON_CLICKED)break;
			}
		}
	}

	for (int i =0; i<limit; i++)
	{
		//SIKLUS 1
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[0]),(FEMUR_S_F[3]),(TIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[0]),(FEMUR_S_M[3]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[0]),(FEMUR_S_R[3]),(NTIBIA_S_R[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[0]),(Z_STATIC_IK_S[0]),(NTIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[0]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[0]),(Z_STATIC_IK_S[4]),(TIBIA_S_R[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[1]),(FEMUR_S_F[2]),(TIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[1]),(FEMUR_S_M[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[1]),(FEMUR_S_R[2]),(NTIBIA_S_R[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[1]),(Z_STATIC_IK_S[0]),(NTIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[1]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[1]),(Z_STATIC_IK_S[4]),(TIBIA_S_R[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[2]),(FEMUR_S_F[1]),(TIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[2]),(FEMUR_S_M[1]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[2]),(FEMUR_S_R[1]),(NTIBIA_S_R[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[2]),(Z_STATIC_IK_S[0]),(NTIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[2]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[2]),(Z_STATIC_IK_S[4]),(TIBIA_S_R[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[3]),(FEMUR_S_F[0]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[3]),(FEMUR_S_M[0]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[3]),(FEMUR_S_R[0]),(NTIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[0]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[4]),(TIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 1");lcd_putstr(lcd);
				if(BW_BUTTON_CLICKED)break;
			}

			lcd_display_clear();

		}

		//SIKLUS 2
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[1]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[0]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[4]),(TIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[1]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[0]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[4]),(TIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[1]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[0]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[4]),(TIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[1]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[0]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[4]),(TIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 2");lcd_putstr(lcd);
				if(BW_BUTTON_CLICKED)break;
			}

			lcd_display_clear();

		}

		//SIKLUS 3
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[2]),(Z_STATIC_IK_S[1]),(TIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[2]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[2]),(FEMUR_S_F[0]),(NTIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[2]),(FEMUR_S_M[0]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[2]),(FEMUR_S_R[0]),(TIBIA_S_R[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);


		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[1]),(Z_STATIC_IK_S[1]),(TIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[1]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[1]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[1]),(FEMUR_S_F[1]),(NTIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[1]),(FEMUR_S_M[1]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[1]),(FEMUR_S_R[1]),(TIBIA_S_R[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[0]),(Z_STATIC_IK_S[1]),(TIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[0]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[0]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[0]),(FEMUR_S_F[2]),(NTIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[0]),(FEMUR_S_M[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[0]),(FEMUR_S_R[2]),(TIBIA_S_R[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[1]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK_S[5]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK_S[0]),(FEMUR_S_F[3]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(FEMUR_S_M[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK_S[4]),(FEMUR_S_R[3]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 3");lcd_putstr(lcd);
				if(BW_BUTTON_CLICKED)break;
			}

			lcd_display_clear();

		}


		//SIKLUS 4
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[0]),(Z_STATIC_IK_S[1]),(NTIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[0]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[0]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[0]),(FEMUR_S_F[3]),(TIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[0]),(FEMUR_S_M[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[0]),(FEMUR_S_R[3]),(NTIBIA_S_R[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[1]),(Z_STATIC_IK_S[1]),(NTIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[1]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[1]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[1]),(FEMUR_S_F[2]),(TIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[1]),(FEMUR_S_M[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[1]),(FEMUR_S_R[2]),(NTIBIA_S_R[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[2]),(Z_STATIC_IK_S[1]),(NTIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[2]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[2]),(FEMUR_S_F[1]),(TIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[2]),(FEMUR_S_M[1]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[2]),(FEMUR_S_R[1]),(NTIBIA_S_R[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[1]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[3]),(FEMUR_S_F[0]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[3]),(FEMUR_S_M[0]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[3]),(FEMUR_S_R[0]),(NTIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 4");lcd_putstr(lcd);
				if(BW_BUTTON_CLICKED)break;
			}

			lcd_display_clear();

		}



		//SIKLUS 5
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[1]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[0]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[1]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[0]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[1]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[0]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[1]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[0]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 5");lcd_putstr(lcd);
				if(BW_BUTTON_CLICKED)break;
			}

			lcd_display_clear();

		}



		//SIKLUS 6
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[2]),(FEMUR_S_F[0]),(NTIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[2]),(FEMUR_S_M[0]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[2]),(FEMUR_S_R[0]),(TIBIA_S_R[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[2]),(Z_STATIC_IK_S[0]),(TIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[2]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[2]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[1]),(FEMUR_S_F[1]),(NTIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[1]),(FEMUR_S_M[1]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[1]),(FEMUR_S_R[1]),(TIBIA_S_R[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[1]),(Z_STATIC_IK_S[0]),(TIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[1]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[1]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[0]),(FEMUR_S_F[2]),(NTIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[0]),(FEMUR_S_M[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[0]),(FEMUR_S_R[2]),(TIBIA_S_R[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[0]),(Z_STATIC_IK_S[0]),(TIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[0]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[0]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[1]),(FEMUR_S_F[3]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(FEMUR_S_M[3]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK_S[5]),(FEMUR_S_R[3]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK_S[0]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK_S[4]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 6");lcd_putstr(lcd);
				if(BW_BUTTON_CLICKED)break;
			}
			lcd_display_clear();

		}


	}

}

void Dynamx_MovCrvRight_Climbing_Interpolate(int SPEED, int limit, int movement, volatile float *ACTUATE_SIGNAL)
{
	int cek_siklus = 0;
	int cek_value = 0;

	CURVE_RIGHT_STAT = 1;
	int MAX_SIGNAL = 15;
	SPEED = SPEED/33;

	if(IK_CALCULATED_CRV_R_CLMB==0)
	{
		Generate_Body(0,1.5);
		Trajectory_Generator_Climbing(X_Diff, Y_Diff, -3.75, 4,MOVEMENT_NORMAL);

		switch (movement)
		{
			case 0:
			{
				for (int j=0; j<6; j++)
				{
					Z_IK_S_BUFF[j] = Z_IK_STAIRS[j];
				}

			}break;

			case 1:
			{
				for (int j=0; j<6; j++)
				{
					if ((j == 4) || (j == 5))//belakang
					{
						Z_IK_S_BUFF[j] = Z_IK_STAIRS[j];
					}

					else if ((j == 2) || (j == 3))//tengah
					{
						Z_IK_S_BUFF[j] = Z_IK_STAIRS[j];
					}

					else//depan
					{
						Z_IK_S_BUFF[j] = Z_IK_STAIRS[j];
					}
				}

			}break;

			case 2:
			{
				for (int j=0; j<6; j++)
				{
					if ((j == 4) || (j == 5))//belakang
					{
						Z_IK_S_BUFF[j] = Z_IK_STAIRS[j]+3.65;
					}

					else if ((j == 2) || (j == 3))//tengah
					{
						Z_IK_S_BUFF[j] = Z_IK_STAIRS[j]+0.25;
					}

					else//depan
					{
						Z_IK_S_BUFF[j] = Z_IK_STAIRS[j]-2.75;
					}
				}
			}break;

			case 3:
			{
				for (int j=0; j<6; j++)
				{
					if ((j == 4) || (j == 5))//belakang
					{
						Z_IK_S_BUFF[j] = Z_IK_STAIRS[j];
					}

					else if ((j == 2) || (j == 3))//tengah
					{
						Z_IK_S_BUFF[j] = Z_IK_STAIRS[j];
					}

					else//depan
					{
						Z_IK_S_BUFF[j] = Z_IK_STAIRS[j];
					}
				}
			}break;
		}

		if (STATIC_CLIMBING == 0)
		{
			Dyna_IKCalc_Only_Static_Climbing(FRONT_RIGHT_DX,   X_IK_OBS[1], Y_IK_BEGIN[1],Z_IK_S_BUFF[1], &SPEED);
			Dyna_IKCalc_Only_Static_Climbing(MIDDLE_LEFT_DX,   X_IK_OBS[2], Y_IK_BEGIN[2],Z_IK_S_BUFF[2], &SPEED);
			Dyna_IKCalc_Only_Static_Climbing(REAR_RIGHT_DX,    X_IK_OBS[5], Y_IK_BEGIN[5],Z_IK_S_BUFF[5], &SPEED);

			Dyna_IKCalc_Only_Static_Climbing(FRONT_LEFT_DX,    X_IK_OBS[0], Y_IK_BEGIN[0],Z_IK_S_BUFF[0], &SPEED);
			Dyna_IKCalc_Only_Static_Climbing(MIDDLE_RIGHT_DX,  X_IK_OBS[3], Y_IK_BEGIN[3],Z_IK_S_BUFF[3], &SPEED);
			Dyna_IKCalc_Only_Static_Climbing(REAR_LEFT_DX,     X_IK_OBS[4], Y_IK_BEGIN[4],Z_IK_S_BUFF[4], &SPEED);
			Start_Pose_SYNC();
			delay_ms(SPEED);

			if(cek_siklus==1)
			{
				while(1)
				{
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"STATIC CLIMB");lcd_putstr(lcd);
					if(BW_BUTTON_CLICKED)break;
				}
			}
			STATIC_CLIMBING = 1;
		}

		for(i=0;i<=3;i++)
		{
			Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[1]+Z_IK[i]));
			FEMUR_S_F[i] = tetha.Femur;
			NFEMUR_S_F[i] = (tetha.Femur*-1);

			Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[2]+Z_IK[i]));
			FEMUR_S_M[i] = tetha.Femur;
			NFEMUR_S_M[i] = (tetha.Femur*-1);

			Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[5]+Z_IK[i]));
			FEMUR_S_R[i] = tetha.Femur;
			NFEMUR_S_R[i] = (tetha.Femur*-1);

			Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_STAIRS[1]+Z_IK[i]));
			COXA_S[i] = tetha.Coxa;
			NCOXA_S[i] = (tetha.Coxa*-1);

	//		Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_STAIRS[1]));
			Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[1]));
			TIBIA_S[i] = tetha.Tibia;

	//		Dyna_IKCalc_Only((X_IK_OBS[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_STAIRS[1]));
			Dyna_IKCalc_Only((X_IK_OBS[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[1]));
			NTIBIA_S[i] = tetha.Tibia;

			Dyna_IKCalc_Only((X_IK_OBS[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[4]));
			NTIBIA_S_R[i] = tetha.Tibia;

			Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[5]));
			TIBIA_S_R[i] = tetha.Tibia;
		}
		IK_CALCULATED_CRV_R_CLMB = 1;
		IK_CALCULATED_CRV_L_CLMB = 0;
	}

	int a = 0;
	int b = 0, c = 0;

	float signal=*ACTUATE_SIGNAL/3;
	float error_L;//femur_L,tibia_L;
	float error_R;//femur_R,tibia_R;
	float error_R2;

	if (signal>=MAX_SIGNAL){error_R=MAX_SIGNAL;error_R2=MAX_SIGNAL;}
	else {error_R=signal;error_R2=signal;}

	float DELTA_R= (1 * error_R);
	float DELTA_R2 = (1 * error_R2);

	int LEFT_EXT1 = 0;
	int LEFT_EXT2 = 0;

	int CURVE[4];
	int NCURVE[4];

	CURVE[0] = (int)((DELTA_R*(float)COXA_S[0])/((float)(MAX_SIGNAL)));
	CURVE[1] = (int)((DELTA_R*(float)COXA_S[1])/((float)(MAX_SIGNAL)));
	CURVE[2] = (int)((DELTA_R*(float)COXA_S[2])/((float)(MAX_SIGNAL)));
	CURVE[3] = (int)((DELTA_R*(float)COXA_S[3])/((float)(MAX_SIGNAL)));


	NCURVE[0] = (int)((DELTA_R2*(float)NCOXA_S[0])/((float)(MAX_SIGNAL)));
	NCURVE[1] = (int)((DELTA_R2*(float)NCOXA_S[1])/((float)(MAX_SIGNAL)));
	NCURVE[2] = (int)((DELTA_R2*(float)NCOXA_S[2])/((float)(MAX_SIGNAL)));
	NCURVE[3] = (int)((DELTA_R2*(float)NCOXA_S[3])/((float)(MAX_SIGNAL)));


	int n;
	for(n=0;n<=3;n++)
	{
		NCURVE[i] = (NCURVE[i]*-1);
	}


	if(cek_value==1)
	{
		while(1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"STATIC IK S");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"%d|%d|%d",X_STATIC_IK_S[0],X_STATIC_IK_S[2],X_STATIC_IK_S[4]);lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d",Y_STATIC_IK_S[0],Y_STATIC_IK_S[2],Y_STATIC_IK_S[4]);lcd_putstr(lcd);
				lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d",Z_STATIC_IK_S[0],Z_STATIC_IK_S[2],Z_STATIC_IK_S[4]);lcd_putstr(lcd);
				delay_ms(100);
				if(BW_BUTTON_CLICKED)break;
			}

			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"COXA TIBIA|R");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"%d|%d|%d|%d",COXA_S[0],COXA_S[1],COXA_S[2],COXA_S[3]);lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d|%d",TIBIA_S[0],TIBIA_S[1],TIBIA_S[2],TIBIA_S[3]);lcd_putstr(lcd);
				lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d|%d",TIBIA_S_R[0],TIBIA_S_R[1],TIBIA_S_R[2],TIBIA_S_R[3]);lcd_putstr(lcd);
				delay_ms(100);
				if(BW_BUTTON_CLICKED)break;
			}

			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FEMUR");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"%d|%d|%d|%d",FEMUR_S_F[0],FEMUR_S_F[1],FEMUR_S_F[2],FEMUR_S_F[3]);lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d|%d",FEMUR_S_M[0],FEMUR_S_M[1],FEMUR_S_M[2],FEMUR_S_M[3]);lcd_putstr(lcd);
				lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d|%d",FEMUR_S_R[0],FEMUR_S_R[1],FEMUR_S_R[2],FEMUR_S_R[3]);lcd_putstr(lcd);
				delay_ms(100);
				if(BW_BUTTON_CLICKED)break;
			}
		}
	}

	for (int i =0; i<limit; i++)
	{
		//SIKLUS 1
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[0]-CURVE[0]),(FEMUR_S_F[3]),(TIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[0]),(FEMUR_S_M[3]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[0]-CURVE[0]),(FEMUR_S_R[3]),(NTIBIA_S_R[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[0]),(Z_STATIC_IK_S[0]),(NTIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[0]-NCURVE[0]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[0]),(Z_STATIC_IK_S[4]),(TIBIA_S_R[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[1]-CURVE[1]),(FEMUR_S_F[2]),(TIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[1]),(FEMUR_S_M[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[1]-CURVE[1]),(FEMUR_S_R[2]),(NTIBIA_S_R[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[1]),(Z_STATIC_IK_S[0]),(NTIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[1]-NCURVE[1]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[1]),(Z_STATIC_IK_S[4]),(TIBIA_S_R[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[2]-CURVE[2]),(FEMUR_S_F[1]),(TIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[2]),(FEMUR_S_M[1]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[2]-CURVE[2]),(FEMUR_S_R[1]),(NTIBIA_S_R[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[2]),(Z_STATIC_IK_S[0]),(NTIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[2]-NCURVE[2]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[2]),(Z_STATIC_IK_S[4]),(TIBIA_S_R[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[3]-CURVE[3]),(FEMUR_S_F[0]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[3]),(FEMUR_S_M[0]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[3]-CURVE[3]),(FEMUR_S_R[0]),(NTIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[0]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[3]-NCURVE[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[4]),(TIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 1");lcd_putstr(lcd);
				if(BW_BUTTON_CLICKED)break;
			}

			lcd_display_clear();

		}

		//SIKLUS 2
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[3]-CURVE[3]),(Z_STATIC_IK_S[1]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[3]-CURVE[3]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[0]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[3]-NCURVE[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[4]),(TIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[3]-CURVE[3]),(Z_STATIC_IK_S[1]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[3]-CURVE[3]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[0]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[3]-NCURVE[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[4]),(TIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[3]-CURVE[3]),(Z_STATIC_IK_S[1]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[3]-CURVE[3]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[0]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[3]-NCURVE[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[4]),(TIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[3]-CURVE[3]),(Z_STATIC_IK_S[1]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[3]-CURVE[3]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[0]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[3]-NCURVE[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[4]),(TIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 2");lcd_putstr(lcd);
				if(BW_BUTTON_CLICKED)break;
			}

			lcd_display_clear();

		}

		//SIKLUS 3
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[2]-CURVE[2]),(Z_STATIC_IK_S[1]),(TIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[2]-CURVE[2]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[2]),(FEMUR_S_F[0]),(NTIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[2]-NCURVE[2]),(FEMUR_S_M[0]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[2]),(FEMUR_S_R[0]),(TIBIA_S_R[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);


		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[1]-CURVE[1]),(Z_STATIC_IK_S[1]),(TIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[1]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[1]-CURVE[1]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[1]),(FEMUR_S_F[1]),(NTIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[1]-NCURVE[1]),(FEMUR_S_M[1]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[1]),(FEMUR_S_R[1]),(TIBIA_S_R[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[0]-CURVE[0]),(Z_STATIC_IK_S[1]),(TIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[0]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[0]-CURVE[0]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[0]),(FEMUR_S_F[2]),(NTIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[0]-NCURVE[0]),(FEMUR_S_M[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[0]),(FEMUR_S_R[2]),(TIBIA_S_R[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[1]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK_S[5]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK_S[0]),(FEMUR_S_F[3]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(FEMUR_S_M[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK_S[4]),(FEMUR_S_R[3]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 3");lcd_putstr(lcd);
				if(BW_BUTTON_CLICKED)break;
			}

			lcd_display_clear();

		}


		//SIKLUS 4
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[0]-NCURVE[0]),(Z_STATIC_IK_S[1]),(NTIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[0]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[0]-NCURVE[0]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[0]),(FEMUR_S_F[3]),(TIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[0]-CURVE[0]),(FEMUR_S_M[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[0]),(FEMUR_S_R[3]),(NTIBIA_S_R[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[1]-NCURVE[1]),(Z_STATIC_IK_S[1]),(NTIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[1]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[1]-NCURVE[1]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[1]),(FEMUR_S_F[2]),(TIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[1]-CURVE[1]),(FEMUR_S_M[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[1]),(FEMUR_S_R[2]),(NTIBIA_S_R[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[2]-NCURVE[2]),(Z_STATIC_IK_S[1]),(NTIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[2]-NCURVE[2]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[2]),(FEMUR_S_F[1]),(TIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[2]-CURVE[2]),(FEMUR_S_M[1]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[2]),(FEMUR_S_R[1]),(NTIBIA_S_R[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[3]-NCURVE[3]),(Z_STATIC_IK_S[1]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[3]-NCURVE[3]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[3]),(FEMUR_S_F[0]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[3]-CURVE[3]),(FEMUR_S_M[0]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[3]),(FEMUR_S_R[0]),(NTIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 4");lcd_putstr(lcd);
				if(BW_BUTTON_CLICKED)break;
			}

			lcd_display_clear();

		}



		//SIKLUS 5
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[3]-NCURVE[3]),(Z_STATIC_IK_S[1]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[3]-NCURVE[3]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[0]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[3]-CURVE[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[3]-NCURVE[3]),(Z_STATIC_IK_S[1]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[3]-NCURVE[3]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[0]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[3]-CURVE[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[3]-NCURVE[3]),(Z_STATIC_IK_S[1]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[3]-NCURVE[3]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[0]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[3]-CURVE[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[3]-NCURVE[3]),(Z_STATIC_IK_S[1]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[3]-NCURVE[3]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[0]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[3]-CURVE[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 5");lcd_putstr(lcd);
				if(BW_BUTTON_CLICKED)break;
			}

			lcd_display_clear();

		}



		//SIKLUS 6
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[2]-NCURVE[2]),(FEMUR_S_F[0]),(NTIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[2]),(FEMUR_S_M[0]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[2]-NCURVE[2]),(FEMUR_S_R[0]),(TIBIA_S_R[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[2]),(Z_STATIC_IK_S[0]),(TIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[2]-CURVE[2]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[2]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[1]-NCURVE[1]),(FEMUR_S_F[1]),(NTIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[1]),(FEMUR_S_M[1]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[1]-NCURVE[1]),(FEMUR_S_R[1]),(TIBIA_S_R[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[1]),(Z_STATIC_IK_S[0]),(TIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[1]-CURVE[1]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[1]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[0]-NCURVE[0]),(FEMUR_S_F[2]),(NTIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[0]),(FEMUR_S_M[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[0]-NCURVE[0]),(FEMUR_S_R[2]),(TIBIA_S_R[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[0]),(Z_STATIC_IK_S[0]),(TIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[0]-CURVE[0]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[0]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[1]),(FEMUR_S_F[3]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(FEMUR_S_M[3]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK_S[5]),(FEMUR_S_R[3]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK_S[0]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK_S[4]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 6");lcd_putstr(lcd);
				if(BW_BUTTON_CLICKED)break;
			}
			lcd_display_clear();

		}


	}
	CURVE_RIGHT_STAT = 0;
}

void Dynamx_MovCrvLeft_Climbing_Interpolate(int SPEED, int limit, int movement, volatile float *ACTUATE_SIGNAL)
{
	int cek_siklus = 0;
	int cek_value = 0;

	CURVE_LEFT_STAT = 1;
	int MAX_SIGNAL = 15;
	SPEED = SPEED/33;

	if(IK_CALCULATED_CRV_L_CLMB==0)
	{
		Generate_Body(0,1.5);
		Trajectory_Generator_Climbing(X_Diff, Y_Diff, -3.75, 4,MOVEMENT_NORMAL);

		switch (movement)
		{
			case 0:
			{
				for (int j=0; j<6; j++)
				{
					Z_IK_S_BUFF[j] = Z_IK_STAIRS[j];
				}

			}break;

			case 1:
			{
				for (int j=0; j<6; j++)
				{
					if ((j == 4) || (j == 5))//belakang
					{
						Z_IK_S_BUFF[j] = Z_IK_STAIRS[j];
					}

					else if ((j == 2) || (j == 3))//tengah
					{
						Z_IK_S_BUFF[j] = Z_IK_STAIRS[j];
					}

					else//depan
					{
						Z_IK_S_BUFF[j] = Z_IK_STAIRS[j];
					}
				}

			}break;

			case 2:
			{
				for (int j=0; j<6; j++)
				{
					if ((j == 4) || (j == 5))//belakang
					{
						Z_IK_S_BUFF[j] = Z_IK_STAIRS[j]+3.65;
					}

					else if ((j == 2) || (j == 3))//tengah
					{
						Z_IK_S_BUFF[j] = Z_IK_STAIRS[j]+0.25;
					}

					else//depan
					{
						Z_IK_S_BUFF[j] = Z_IK_STAIRS[j]-2.75;
					}
				}
			}break;

			case 3:
			{
				for (int j=0; j<6; j++)
				{
					if ((j == 4) || (j == 5))//belakang
					{
						Z_IK_S_BUFF[j] = Z_IK_STAIRS[j];
					}

					else if ((j == 2) || (j == 3))//tengah
					{
						Z_IK_S_BUFF[j] = Z_IK_STAIRS[j];
					}

					else//depan
					{
						Z_IK_S_BUFF[j] = Z_IK_STAIRS[j];
					}
				}
			}break;
		}

		if (STATIC_CLIMBING == 0)
		{
			Dyna_IKCalc_Only_Static_Climbing(FRONT_RIGHT_DX,   X_IK_OBS[1], Y_IK_BEGIN[1],Z_IK_S_BUFF[1], &SPEED);
			Dyna_IKCalc_Only_Static_Climbing(MIDDLE_LEFT_DX,   X_IK_OBS[2], Y_IK_BEGIN[2],Z_IK_S_BUFF[2], &SPEED);
			Dyna_IKCalc_Only_Static_Climbing(REAR_RIGHT_DX,    X_IK_OBS[5], Y_IK_BEGIN[5],Z_IK_S_BUFF[5], &SPEED);

			Dyna_IKCalc_Only_Static_Climbing(FRONT_LEFT_DX,    X_IK_OBS[0], Y_IK_BEGIN[0],Z_IK_S_BUFF[0], &SPEED);
			Dyna_IKCalc_Only_Static_Climbing(MIDDLE_RIGHT_DX,  X_IK_OBS[3], Y_IK_BEGIN[3],Z_IK_S_BUFF[3], &SPEED);
			Dyna_IKCalc_Only_Static_Climbing(REAR_LEFT_DX,     X_IK_OBS[4], Y_IK_BEGIN[4],Z_IK_S_BUFF[4], &SPEED);
			Start_Pose_SYNC();
			delay_ms(SPEED);

			if(cek_siklus==1)
			{
				while(1)
				{
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"STATIC CLIMB");lcd_putstr(lcd);
					if(BW_BUTTON_CLICKED)break;
				}
			}
			STATIC_CLIMBING = 1;
		}

		for(i=0;i<=3;i++)
		{
			Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[1]+Z_IK[i]));
			FEMUR_S_F[i] = tetha.Femur;
			NFEMUR_S_F[i] = (tetha.Femur*-1);

			Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[2]+Z_IK[i]));
			FEMUR_S_M[i] = tetha.Femur;
			NFEMUR_S_M[i] = (tetha.Femur*-1);

			Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[5]+Z_IK[i]));
			FEMUR_S_R[i] = tetha.Femur;
			NFEMUR_S_R[i] = (tetha.Femur*-1);

			Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_STAIRS[1]+Z_IK[i]));
			COXA_S[i] = tetha.Coxa;
			NCOXA_S[i] = (tetha.Coxa*-1);

	//		Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_STAIRS[1]));
			Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[1]));
			TIBIA_S[i] = tetha.Tibia;

	//		Dyna_IKCalc_Only((X_IK_OBS[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_STAIRS[1]));
			Dyna_IKCalc_Only((X_IK_OBS[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[1]));
			NTIBIA_S[i] = tetha.Tibia;

			Dyna_IKCalc_Only((X_IK_OBS[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[4]));
			NTIBIA_S_R[i] = tetha.Tibia;

			Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[5]));
			TIBIA_S_R[i] = tetha.Tibia;
		}
		IK_CALCULATED_CRV_L_CLMB = 1;
		IK_CALCULATED_CRV_R_CLMB = 0;
	}

	int a = 0;
	int b = 0, c = 0;

	float signal=*ACTUATE_SIGNAL/3;
	float error_L;//femur_L,tibia_L;
	float error_R;//femur_R,tibia_R;
	float error_R2;

	if (signal>=MAX_SIGNAL){error_R=MAX_SIGNAL;error_R2=MAX_SIGNAL;}
	else {error_R=signal;error_R2=signal;}

	float DELTA_R= (1 * error_R);
	float DELTA_R2 = (1 * error_R2);

	int LEFT_EXT1 = 0;
	int LEFT_EXT2 = 0;

	int CURVE[4];
	int NCURVE[4];

	CURVE[0] = (int)((DELTA_R*(float)COXA_S[0])/((float)(MAX_SIGNAL)));
	CURVE[1] = (int)((DELTA_R*(float)COXA_S[1])/((float)(MAX_SIGNAL)));
	CURVE[2] = (int)((DELTA_R*(float)COXA_S[2])/((float)(MAX_SIGNAL)));
	CURVE[3] = (int)((DELTA_R*(float)COXA_S[3])/((float)(MAX_SIGNAL)));


	NCURVE[0] = (int)((DELTA_R2*(float)NCOXA_S[0])/((float)(MAX_SIGNAL)));
	NCURVE[1] = (int)((DELTA_R2*(float)NCOXA_S[1])/((float)(MAX_SIGNAL)));
	NCURVE[2] = (int)((DELTA_R2*(float)NCOXA_S[2])/((float)(MAX_SIGNAL)));
	NCURVE[3] = (int)((DELTA_R2*(float)NCOXA_S[3])/((float)(MAX_SIGNAL)));


	int n;
	for(n=0;n<=3;n++)
	{
		NCURVE[i] = (NCURVE[i]*-1);
	}


	if(cek_value==1)
	{
		while(1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"STATIC IK S");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"%d|%d|%d",X_STATIC_IK_S[0],X_STATIC_IK_S[2],X_STATIC_IK_S[4]);lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d",Y_STATIC_IK_S[0],Y_STATIC_IK_S[2],Y_STATIC_IK_S[4]);lcd_putstr(lcd);
				lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d",Z_STATIC_IK_S[0],Z_STATIC_IK_S[2],Z_STATIC_IK_S[4]);lcd_putstr(lcd);
				delay_ms(100);
				if(BW_BUTTON_CLICKED)break;
			}

			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"COXA TIBIA|R");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"%d|%d|%d|%d",COXA_S[0],COXA_S[1],COXA_S[2],COXA_S[3]);lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d|%d",TIBIA_S[0],TIBIA_S[1],TIBIA_S[2],TIBIA_S[3]);lcd_putstr(lcd);
				lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d|%d",TIBIA_S_R[0],TIBIA_S_R[1],TIBIA_S_R[2],TIBIA_S_R[3]);lcd_putstr(lcd);
				delay_ms(100);
				if(BW_BUTTON_CLICKED)break;
			}

			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FEMUR");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"%d|%d|%d|%d",FEMUR_S_F[0],FEMUR_S_F[1],FEMUR_S_F[2],FEMUR_S_F[3]);lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d|%d",FEMUR_S_M[0],FEMUR_S_M[1],FEMUR_S_M[2],FEMUR_S_M[3]);lcd_putstr(lcd);
				lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d|%d",FEMUR_S_R[0],FEMUR_S_R[1],FEMUR_S_R[2],FEMUR_S_R[3]);lcd_putstr(lcd);
				delay_ms(100);
				if(BW_BUTTON_CLICKED)break;
			}
		}
	}

	for (int i =0; i<limit; i++)
	{
		//SIKLUS 1
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[0]),(FEMUR_S_F[3]),(TIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[0]-CURVE[0]),(FEMUR_S_M[3]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[0]),(FEMUR_S_R[3]),(NTIBIA_S_R[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[0]-NCURVE[0]),(Z_STATIC_IK_S[0]),(NTIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[0]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[0]-NCURVE[0]),(Z_STATIC_IK_S[4]),(TIBIA_S_R[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[1]),(FEMUR_S_F[2]),(TIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[1]-CURVE[1]),(FEMUR_S_M[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[1]),(FEMUR_S_R[2]),(NTIBIA_S_R[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[1]-NCURVE[1]),(Z_STATIC_IK_S[0]),(NTIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[1]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[1]-NCURVE[1]),(Z_STATIC_IK_S[4]),(TIBIA_S_R[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[2]),(FEMUR_S_F[1]),(TIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[2]-CURVE[2]),(FEMUR_S_M[1]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[2]),(FEMUR_S_R[1]),(NTIBIA_S_R[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[2]-NCURVE[2]),(Z_STATIC_IK_S[0]),(NTIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[2]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[2]-NCURVE[2]),(Z_STATIC_IK_S[4]),(TIBIA_S_R[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[3]),(FEMUR_S_F[0]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[3]-CURVE[3]),(FEMUR_S_M[0]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[3]),(FEMUR_S_R[0]),(NTIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[3]-NCURVE[3]),(Z_STATIC_IK_S[0]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[3]-NCURVE[3]),(Z_STATIC_IK_S[4]),(TIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 1");lcd_putstr(lcd);
				if(BW_BUTTON_CLICKED)break;
			}

			lcd_display_clear();

		}

		//SIKLUS 2
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[1]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[3]-CURVE[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[3]-NCURVE[3]),(Z_STATIC_IK_S[0]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[3]-NCURVE[3]),(Z_STATIC_IK_S[4]),(TIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[1]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[3]-CURVE[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[3]-NCURVE[3]),(Z_STATIC_IK_S[0]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[3]-NCURVE[3]),(Z_STATIC_IK_S[4]),(TIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[1]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[3]-CURVE[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[3]-NCURVE[3]),(Z_STATIC_IK_S[0]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[3]-NCURVE[3]),(Z_STATIC_IK_S[4]),(TIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[1]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[3]-CURVE[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[3]-NCURVE[3]),(Z_STATIC_IK_S[0]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[3]-NCURVE[3]),(Z_STATIC_IK_S[4]),(TIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 2");lcd_putstr(lcd);
				if(BW_BUTTON_CLICKED)break;
			}

			lcd_display_clear();

		}

		//SIKLUS 3
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[2]),(Z_STATIC_IK_S[1]),(TIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[2]-CURVE[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[2]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[2]-NCURVE[2]),(FEMUR_S_F[0]),(NTIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[2]),(FEMUR_S_M[0]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[2]-NCURVE[2]),(FEMUR_S_R[0]),(TIBIA_S_R[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);


		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[1]),(Z_STATIC_IK_S[1]),(TIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[1]-CURVE[1]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[1]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[1]-NCURVE[1]),(FEMUR_S_F[1]),(NTIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[1]),(FEMUR_S_M[1]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[1]-NCURVE[1]),(FEMUR_S_R[1]),(TIBIA_S_R[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[0]),(Z_STATIC_IK_S[1]),(TIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[0]-CURVE[0]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[0]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[0]-NCURVE[0]),(FEMUR_S_F[2]),(NTIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[0]),(FEMUR_S_M[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[0]-NCURVE[0]),(FEMUR_S_R[2]),(TIBIA_S_R[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[1]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK_S[5]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK_S[0]),(FEMUR_S_F[3]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(FEMUR_S_M[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK_S[4]),(FEMUR_S_R[3]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 3");lcd_putstr(lcd);
				if(BW_BUTTON_CLICKED)break;
			}

			lcd_display_clear();

		}


		//SIKLUS 4
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[0]),(Z_STATIC_IK_S[1]),(NTIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[0]-NCURVE[0]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[0]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[0]-CURVE[0]),(FEMUR_S_F[3]),(TIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[0]),(FEMUR_S_M[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[0]-CURVE[0]),(FEMUR_S_R[3]),(NTIBIA_S_R[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[1]),(Z_STATIC_IK_S[1]),(NTIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[1]-NCURVE[1]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[1]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[1]-CURVE[1]),(FEMUR_S_F[2]),(TIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[1]),(FEMUR_S_M[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[1]-CURVE[1]),(FEMUR_S_R[2]),(NTIBIA_S_R[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[2]),(Z_STATIC_IK_S[1]),(NTIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[2]-NCURVE[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[2]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[2]-CURVE[2]),(FEMUR_S_F[1]),(TIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[2]),(FEMUR_S_M[1]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[2]-CURVE[2]),(FEMUR_S_R[1]),(NTIBIA_S_R[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[1]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[3]-NCURVE[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[3]-CURVE[3]),(FEMUR_S_F[0]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[3]),(FEMUR_S_M[0]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[3]-CURVE[3]),(FEMUR_S_R[0]),(NTIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 4");lcd_putstr(lcd);
				if(BW_BUTTON_CLICKED)break;
			}

			lcd_display_clear();

		}



		//SIKLUS 5
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[1]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[3]-NCURVE[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[3]-CURVE[3]),(Z_STATIC_IK_S[0]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[3]-CURVE[3]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[1]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[3]-NCURVE[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[3]-CURVE[3]),(Z_STATIC_IK_S[0]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[3]-CURVE[3]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[1]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[3]-NCURVE[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[3]-CURVE[3]),(Z_STATIC_IK_S[0]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[3]-CURVE[3]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[1]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[3]-NCURVE[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[3]-CURVE[3]),(Z_STATIC_IK_S[0]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[3]-CURVE[3]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 5");lcd_putstr(lcd);
				if(BW_BUTTON_CLICKED)break;
			}

			lcd_display_clear();

		}


		//SIKLUS 6
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[2]),(FEMUR_S_F[0]),(NTIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[2]-NCURVE[2]),(FEMUR_S_M[0]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[2]),(FEMUR_S_R[0]),(TIBIA_S_R[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[2]-CURVE[2]),(Z_STATIC_IK_S[0]),(TIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[2]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[2]-CURVE[2]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[1]),(FEMUR_S_F[1]),(NTIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[1]-NCURVE[1]),(FEMUR_S_M[1]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[1]),(FEMUR_S_R[1]),(TIBIA_S_R[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[1]-CURVE[1]),(Z_STATIC_IK_S[0]),(TIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[1]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[1]-CURVE[1]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[0]),(FEMUR_S_F[2]),(NTIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[0]-NCURVE[0]),(FEMUR_S_M[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[0]),(FEMUR_S_R[2]),(TIBIA_S_R[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[0]-CURVE[0]),(Z_STATIC_IK_S[0]),(TIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[0]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[0]-CURVE[0]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[1]),(FEMUR_S_F[3]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(FEMUR_S_M[3]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK_S[5]),(FEMUR_S_R[3]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK_S[0]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK_S[4]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 6");lcd_putstr(lcd);
				if(BW_BUTTON_CLICKED)break;
			}
			lcd_display_clear();

		}
	}
	CURVE_LEFT_STAT = 0;
}

void Dynamx_MovFwdMiring_Interpolate(int SPEED, int limit, int movement)
{
	int cek_siklus = 0;
	int cek_value = 0;
	SPEED = SPEED/33;

	if(IK_CALCULATED_CLMB==0)
	{
		Generate_Body(0,1.5);
		Trajectory_Generator_Climbing(X_Diff, Y_Diff, -3.5, 4,MOVEMENT_NORMAL);

		switch (movement)
		{
			case 0:
			{
				for (int j=0; j<6; j++)
				{
					Z_IK_S_BUFF[j] = Z2_IK_STAIRS[j];
				}

			}break;

			case 1:
			{
				for (int j=0; j<6; j++)
				{
					if ((j == 4) || (j == 5))//belakang
					{
						Z_IK_S_BUFF[j] = Z2_IK_STAIRS[j];
					}

					else if ((j == 2) || (j == 3))//tengah
					{
						Z_IK_S_BUFF[j] = Z2_IK_STAIRS[j];
					}

					else//depan
					{
						Z_IK_S_BUFF[j] = Z2_IK_STAIRS[j];
					}
				}

			}break;

			case 2:
			{
				for (int j=0; j<6; j++)
				{
					if ((j == 4) || (j == 5))//belakang
					{
						Z_IK_S_BUFF[j] = Z2_IK_STAIRS[j]+3.65;//3.65
					}

					else if ((j == 2) || (j == 3))//tengah
					{
						Z_IK_S_BUFF[j] = Z2_IK_STAIRS[j]+0.25;//0.25
					}

					else//depan
					{
						Z_IK_S_BUFF[j] = Z2_IK_STAIRS[j]-2.75;//-2.75
					}
				}
			}break;

			case 3:
			{
				for (int j=0; j<6; j++)
				{
					if ((j == 4) || (j == 5))//belakang
					{
						Z_IK_S_BUFF[j] = Z2_IK_STAIRS[j];
					}

					else if ((j == 2) || (j == 3))//tengah
					{
						Z_IK_S_BUFF[j] = Z2_IK_STAIRS[j];
					}

					else//depan
					{
						Z_IK_S_BUFF[j] = Z2_IK_STAIRS[j];
					}
				}
			}break;

			case 4:
			{
				for (int j=0; j<6; j++)
				{
					if ((j == 0) || (j == 2) || (j == 4))//kiri
					{
						Z_IK_S_BUFF[j] = Z2_IK_STAIRS[j]+1.75;
					}

					else//kanan
					{
						Z_IK_S_BUFF[j] = Z2_IK_STAIRS[j];
					}
				}
			}break;

		}

		if (STATIC_CLIMBING == 0)
		{
			Dyna_IKCalc_Only_Static_Climbing(FRONT_RIGHT_DX,   X_IK_OBS[1], Y_IK_BEGIN[1],Z_IK_S_BUFF[1], &SPEED);
			Dyna_IKCalc_Only_Static_Climbing(MIDDLE_LEFT_DX,   X_IK_OBS[2], Y_IK_BEGIN[2],Z_IK_S_BUFF[2], &SPEED);
			Dyna_IKCalc_Only_Static_Climbing(REAR_RIGHT_DX,    X_IK_OBS[5], Y_IK_BEGIN[5],Z_IK_S_BUFF[5], &SPEED);

			Dyna_IKCalc_Only_Static_Climbing(FRONT_LEFT_DX,    X_IK_OBS[0], Y_IK_BEGIN[0],Z_IK_S_BUFF[0], &SPEED);
			Dyna_IKCalc_Only_Static_Climbing(MIDDLE_RIGHT_DX,  X_IK_OBS[3], Y_IK_BEGIN[3],Z_IK_S_BUFF[3], &SPEED);
			Dyna_IKCalc_Only_Static_Climbing(REAR_LEFT_DX,     X_IK_OBS[4], Y_IK_BEGIN[4],Z_IK_S_BUFF[4], &SPEED);
			Start_Pose_SYNC();
			delay_ms(SPEED);

			if(cek_siklus==1)
			{
				while(1)
				{
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"STATIC CLIMB");lcd_putstr(lcd);
					if(BW_BUTTON_CLICKED)break;
				}
			}
			STATIC_CLIMBING = 1;
		}

		for(i=0;i<=3;i++)
		{
			Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[0]+Z_IK[i]));
			FEMUR_S_KI[i] = tetha.Femur;
			NFEMUR_S_KI[i] = (tetha.Femur*-1);

			Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[1]+Z_IK[i]));
			FEMUR_S_KA[i] = tetha.Femur;
			NFEMUR_S_KA[i] = (tetha.Femur*-1);

			Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z2_IK_STAIRS[1]+Z_IK[i]));
			COXA_S[i] = tetha.Coxa;
			NCOXA_S[i] = (tetha.Coxa*-1);

	//		Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_STAIRS[1]));
			Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[1]));
			TIBIA_S[i] = tetha.Tibia;

			Dyna_IKCalc_Only((X_IK_OBS[0]+X3_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[0]));
			TIBIA_S_KI[i] = tetha.Tibia;

	//		Dyna_IKCalc_Only((X_IK_OBS[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_STAIRS[1]));
			Dyna_IKCalc_Only((X_IK_OBS[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[1]));
			NTIBIA_S[i] = tetha.Tibia;

			Dyna_IKCalc_Only((X_IK_OBS[0]-X3_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[0]));
			NTIBIA_S_KI[i] = tetha.Tibia;

			Dyna_IKCalc_Only((X_IK_OBS[0]-X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[5]));
			NTIBIA_S_R[i] = tetha.Tibia;

			Dyna_IKCalc_Only((X_IK_OBS[0]-X4_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[4]));
			NTIBIA_S_R_KI[i] = tetha.Tibia;

			Dyna_IKCalc_Only((X_IK_OBS[0]+X1_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[5]));
			TIBIA_S_R[i] = tetha.Tibia;

			Dyna_IKCalc_Only((X_IK_OBS[0]+X4_IK[i]),(Y_IK_BEGIN[i]+Y_IK[i]),(Z_IK_S_BUFF[4]));
			TIBIA_S_R_KI[i] = tetha.Tibia;

		}
		IK_CALCULATED_CLMB = 1;
	}


	if(cek_value==1)
	{
		while(1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"STATIC IK S");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"%d|%d|%d",X_STATIC_IK_S[0],X_STATIC_IK_S[2],X_STATIC_IK_S[4]);lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d",Y_STATIC_IK_S[0],Y_STATIC_IK_S[2],Y_STATIC_IK_S[4]);lcd_putstr(lcd);
				lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d",Z_STATIC_IK_S[0],Z_STATIC_IK_S[2],Z_STATIC_IK_S[4]);lcd_putstr(lcd);
				delay_ms(100);
				if(BW_BUTTON_CLICKED)break;
			}

			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"COXA TIBIA|R");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"%d|%d|%d|%d",COXA_S[0],COXA_S[1],COXA_S[2],COXA_S[3]);lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d|%d",TIBIA_S[0],TIBIA_S[1],TIBIA_S[2],TIBIA_S[3]);lcd_putstr(lcd);
				lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d|%d",TIBIA_S_R[0],TIBIA_S_R[1],TIBIA_S_R[2],TIBIA_S_R[3]);lcd_putstr(lcd);
				delay_ms(100);
				if(BW_BUTTON_CLICKED)break;
			}

			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"FEMUR");lcd_putstr(lcd);
				lcd_gotoxy(0,1);sprintf(lcd,"%d|%d|%d|%d",FEMUR_S_F[0],FEMUR_S_F[1],FEMUR_S_F[2],FEMUR_S_F[3]);lcd_putstr(lcd);
				lcd_gotoxy(0,2);sprintf(lcd,"%d|%d|%d|%d",FEMUR_S_M[0],FEMUR_S_M[1],FEMUR_S_M[2],FEMUR_S_M[3]);lcd_putstr(lcd);
				lcd_gotoxy(0,3);sprintf(lcd,"%d|%d|%d|%d",FEMUR_S_R[0],FEMUR_S_R[1],FEMUR_S_R[2],FEMUR_S_R[3]);lcd_putstr(lcd);
				delay_ms(100);
				if(BW_BUTTON_CLICKED)break;
			}
		}
	}

	for (int i =0; i<limit; i++)
	{
		//SIKLUS 1
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[0]),(FEMUR_S_KA[3]),(TIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[0]),(FEMUR_S_KI[3]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[0]),(FEMUR_S_KA[3]),(NTIBIA_S_R[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[0]),(Z_STATIC_IK_S[0]),(NTIBIA_S_KI[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[0]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[0]),(Z_STATIC_IK_S[4]),(TIBIA_S_R_KI[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[1]),(FEMUR_S_KA[2]),(TIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[1]),(FEMUR_S_KI[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[1]),(FEMUR_S_KA[2]),(NTIBIA_S_R[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[1]),(Z_STATIC_IK_S[0]),(NTIBIA_S_KI[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[1]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[1]),(Z_STATIC_IK_S[4]),(TIBIA_S_R_KI[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[2]),(FEMUR_S_KA[1]),(TIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[2]),(FEMUR_S_KI[1]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[2]),(FEMUR_S_KA[1]),(NTIBIA_S_R[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[2]),(Z_STATIC_IK_S[0]),(NTIBIA_S_KI[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[2]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[2]),(Z_STATIC_IK_S[4]),(TIBIA_S_R_KI[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[3]),(FEMUR_S_KA[0]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[3]),(FEMUR_S_KI[0]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[3]),(FEMUR_S_KA[0]),(NTIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[0]),(NTIBIA_S_KI[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[4]),(TIBIA_S_R_KI[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 1");lcd_putstr(lcd);
				if(BW_BUTTON_CLICKED)break;
			}

			lcd_display_clear();

		}

		//SIKLUS 2
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[1]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[0]),(NTIBIA_S_KI[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[4]),(TIBIA_S_R_KI[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[1]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[0]),(NTIBIA_S_KI[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[4]),(TIBIA_S_R_KI[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[1]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[0]),(NTIBIA_S_KI[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[4]),(TIBIA_S_R_KI[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[1]),(TIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[0]),(NTIBIA_S_KI[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[4]),(TIBIA_S_R_KI[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 2");lcd_putstr(lcd);
				if(BW_BUTTON_CLICKED)break;
			}

			lcd_display_clear();

		}

		//SIKLUS 3
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[2]),(Z_STATIC_IK_S[1]),(TIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[2]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[2]),(FEMUR_S_KI[0]),(NTIBIA_S_KI[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[2]),(FEMUR_S_KA[0]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[2]),(FEMUR_S_KI[0]),(TIBIA_S_R_KI[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);


		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[1]),(Z_STATIC_IK_S[1]),(TIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[1]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[1]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[1]),(FEMUR_S_KI[1]),(NTIBIA_S_KI[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[1]),(FEMUR_S_KA[1]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[1]),(FEMUR_S_KI[1]),(TIBIA_S_R_KI[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(COXA_S[0]),(Z_STATIC_IK_S[1]),(TIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(COXA_S[0]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(COXA_S[0]),(Z_STATIC_IK_S[5]),(NTIBIA_S_R[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(NCOXA_S[0]),(FEMUR_S_KI[2]),(NTIBIA_S_KI[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(NCOXA_S[0]),(FEMUR_S_KA[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(NCOXA_S[0]),(FEMUR_S_KI[2]),(TIBIA_S_R_KI[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[1]),(Z_STATIC_IK_S[1]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK_S[5]),(Z_STATIC_IK_S[5]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK_S[0]),(FEMUR_S_KI[3]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(FEMUR_S_KA[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK_S[4]),(FEMUR_S_KI[3]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 3");lcd_putstr(lcd);
				if(BW_BUTTON_CLICKED)break;
			}

			lcd_display_clear();

		}


		//SIKLUS 4
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[0]),(Z_STATIC_IK_S[1]),(NTIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[0]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[0]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[0]),(FEMUR_S_KI[3]),(TIBIA_S_KI[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[0]),(FEMUR_S_KA[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[0]),(FEMUR_S_KI[3]),(NTIBIA_S_R_KI[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[1]),(Z_STATIC_IK_S[1]),(NTIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[1]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[1]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[1]),(FEMUR_S_KI[2]),(TIBIA_S_KI[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[1]),(FEMUR_S_KA[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[1]),(FEMUR_S_KI[2]),(NTIBIA_S_R_KI[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[2]),(Z_STATIC_IK_S[1]),(NTIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[2]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[2]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[2]),(FEMUR_S_KI[1]),(TIBIA_S_KI[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[2]),(FEMUR_S_KA[1]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[2]),(FEMUR_S_KI[1]),(NTIBIA_S_R_KI[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[1]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[3]),(FEMUR_S_KI[0]),(TIBIA_S_KI[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[3]),(FEMUR_S_KA[0]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[3]),(FEMUR_S_KI[0]),(NTIBIA_S_R_KI[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 4");lcd_putstr(lcd);
				if(BW_BUTTON_CLICKED)break;
			}

			lcd_display_clear();

		}



		//SIKLUS 5
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[1]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[0]),(TIBIA_S_KI[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R_KI[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[1]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[0]),(TIBIA_S_KI[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R_KI[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[1]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[0]),(TIBIA_S_KI[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R_KI[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[1]),(NTIBIA_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[3]),(Z_STATIC_IK_S[5]),(TIBIA_S_R[3]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[0]),(TIBIA_S_KI[3]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[3]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R_KI[3]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 5");lcd_putstr(lcd);
				if(BW_BUTTON_CLICKED)break;
			}

			lcd_display_clear();

		}



		//SIKLUS 6
		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[2]),(FEMUR_S_KA[0]),(NTIBIA_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[2]),(FEMUR_S_KI[0]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[2]),(FEMUR_S_KA[0]),(TIBIA_S_R[2]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[2]),(Z_STATIC_IK_S[0]),(TIBIA_S_KI[2]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[2]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[2]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R_KI[2]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[1]),(FEMUR_S_KA[1]),(NTIBIA_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[1]),(FEMUR_S_KI[1]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[1]),(FEMUR_S_KA[1]),(TIBIA_S_R[1]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[1]),(Z_STATIC_IK_S[0]),(TIBIA_S_KI[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[1]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[1]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R_KI[1]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(NCOXA_S[0]),(FEMUR_S_KA[2]),(NTIBIA_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(NCOXA_S[0]),(FEMUR_S_KI[2]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(NCOXA_S[0]),(FEMUR_S_KA[2]),(TIBIA_S_R[0]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(COXA_S[0]),(Z_STATIC_IK_S[0]),(TIBIA_S_KI[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(COXA_S[0]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(COXA_S[0]),(Z_STATIC_IK_S[4]),(NTIBIA_S_R_KI[0]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[1]),(FEMUR_S_KA[3]),(X_STATIC_IK_S[1]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_LEFT_DX, &SPEED,(Y_STATIC_IK_S[2]),(FEMUR_S_KI[3]),(X_STATIC_IK_S[2]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_RIGHT_DX,  &SPEED,(Y_STATIC_IK_S[5]),(FEMUR_S_KA[3]),(X_STATIC_IK_S[5]));

		Dynamx_MoveLeg_Interpolate_NEW(FRONT_LEFT_DX,   &SPEED,(Y_STATIC_IK_S[0]),(Z_STATIC_IK_S[0]),(X_STATIC_IK_S[0]));
		Dynamx_MoveLeg_Interpolate_NEW(MIDDLE_RIGHT_DX, &SPEED,(Y_STATIC_IK_S[3]),(Z_STATIC_IK_S[3]),(X_STATIC_IK_S[3]));
		Dynamx_MoveLeg_Interpolate_NEW(REAR_LEFT_DX,    &SPEED,(Y_STATIC_IK_S[4]),(Z_STATIC_IK_S[4]),(X_STATIC_IK_S[4]));
		Start_Pose_SYNC();
		delay_ms(SPEED+4);

		if(cek_siklus==1)
		{
			while(1)
			{
				lcd_display_clear();
				lcd_gotoxy(0,0);sprintf(lcd,"SIKLUS 6");lcd_putstr(lcd);
				if(BW_BUTTON_CLICKED)break;
			}
			lcd_display_clear();

		}


	}

}


float           L1 = 4,	   //panjang lengan
                L2 = 5;
float           tetha_1,	//coxa //dalam radian
                tetha_2,	//femur
                tetha_3;	//tibia
int             degree_1, //dalam sudut
                degree_2,
                degree_3;


double RadtoDeg(double a)
{
	double angle = a;
	double f_angel = angle*57.295;
	return f_angel;
}

double sin_deg(double a)
{
	double angle = a/RAD2DEG;
	double val = sin(angle);
	return val;
}

double cos_deg(double a)
{
	double angle = a/RAD2DEG;
	double val = cos(angle);
	return val;
}

double acos_deg(double a)
{
	double val = a;
	double f_angel = acos(val);
	f_angel = f_angel*RAD2DEG;
	return f_angel;
}

double atan2_deg(double a, double b)
{
	double val1 = a;
	double val2 = b;
	float f_angel = atan2(val1,val2);
	f_angel = f_angel*RAD2DEG;
	return f_angel;
}

void Dyna_IKCALC_Obs(int leg, float x, float y, float z , int *SPEED)
{
	tetha.CoxaBuf = 0;//reset value
	tetha.FemurBuf = 0;//reset value
	tetha.TibiaBuf = 0;//reset value
	tetha.Coxa = 0;//reset value
	tetha.Femur = 0;//reset value
	tetha.Tibia = 0;//reset value

	tetha.CoxaBuf = atan2_deg(y,x);

	float buf3 = pow(z,2);
	float buf4 = pow(x,2);
	float buf5 = buf3 + buf4 ;
	float leg_resultant = sqrt(buf5);

	float A1 = acos_deg(z/leg_resultant);

	float buf6 = (pow(Length2,2)) - (pow(Length1,2))- (pow(leg_resultant,2));
	float buf7 = -2*Length1*leg_resultant;
	float buf8 = buf6/buf7;
	float A2 = acos_deg(buf8);
	float buf12 = 90-A1;
	//FEMUR ANGLE
	tetha.FemurBuf =(A2-buf12);
	//tetha.FemurBuf =(A2+A1);

	float buf9 = (pow(leg_resultant,2)) - (pow(Length2,2)) - (pow(Length1,2));
	float buf10 = -2*Length1*Length2;
	float buf11 = buf9/buf10;
	float B1 = acos_deg(buf11);

	//TIBIA ANGLE
	tetha.TibiaBuf = 180 - (B1);

	tetha.Coxa = (tetha.CoxaBuf);
	tetha.Femur = (tetha.FemurBuf);
	tetha.Tibia = (tetha.TibiaBuf);

	if(STATIC_ANGLE == 0)
	{
		X_STATIC_IK[leg-1] = tetha.Tibia;
		Y_STATIC_IK[leg-1] = tetha.Coxa;
		Z_STATIC_IK[leg-1] = tetha.Femur;
	}

	if(STATIC_OBS == 0)
	{
		X_STATIC_IK_S[leg-1] = tetha.Tibia;
		Y_STATIC_IK_S[leg-1] = tetha.Coxa;
		Z_STATIC_IK_S[leg-1] = tetha.Femur;
	}

	if(STATIC_OBS_HIGH == 0)
	{
		X_STATIC_IK_S[leg-1] = tetha.Tibia;
		Y_STATIC_IK_S[leg-1] = tetha.Coxa;
		Z_STATIC_IK_S[leg-1] = tetha.Femur;
	}

		switch(leg)
		{
		case FRONT_RIGHT_DX:
		{
			HexJoint_Actuate_Climbing(FRONT_RIGHT_DX_COXA, 150-tetha.Coxa, *SPEED);
			HexJoint_Actuate_Climbing(FRONT_RIGHT_DX_FEMUR, 150+tetha.Femur, *SPEED);
			HexJoint_Actuate_Climbing(FRONT_RIGHT_DX_TIBIA, 150+tetha.Tibia, *SPEED);
			break;

		}

		case MIDDLE_RIGHT_DX:
		{
			HexJoint_Actuate_Climbing(MIDDLE_RIGHT_DX_COXA, 150-tetha.Coxa, *SPEED);
			HexJoint_Actuate_Climbing(MIDDLE_RIGHT_DX_FEMUR, 150+tetha.Femur, *SPEED);
			HexJoint_Actuate_Climbing(MIDDLE_RIGHT_DX_TIBIA, 150+tetha.Tibia, *SPEED);
			break;
		}

		case REAR_RIGHT_DX:
		{
			HexJoint_Actuate_Climbing(REAR_RIGHT_DX_COXA, 150-tetha.Coxa, *SPEED);
			HexJoint_Actuate_Climbing(REAR_RIGHT_DX_FEMUR, 150+tetha.Femur, *SPEED);
			HexJoint_Actuate_Climbing(REAR_RIGHT_DX_TIBIA, 150+tetha.Tibia, *SPEED);
			break;
		}

		case FRONT_LEFT_DX:
		{
			HexJoint_Actuate_Climbing(FRONT_LEFT_DX_COXA, 150+tetha.Coxa, *SPEED);
			HexJoint_Actuate_Climbing(FRONT_LEFT_DX_FEMUR, 150+tetha.Femur,*SPEED);
			HexJoint_Actuate_Climbing(FRONT_LEFT_DX_TIBIA, 150+tetha.Tibia, *SPEED);
			break;
		}

		case MIDDLE_LEFT_DX:
		{
			HexJoint_Actuate_Climbing(MIDDLE_LEFT_DX_COXA, 150+tetha.Coxa, *SPEED);
			HexJoint_Actuate_Climbing(MIDDLE_LEFT_DX_FEMUR, 150+tetha.Femur, *SPEED);
			HexJoint_Actuate_Climbing(MIDDLE_LEFT_DX_TIBIA, 150+tetha.Tibia,*SPEED);
			break;
		}

		case REAR_LEFT_DX:
		{
			HexJoint_Actuate_Climbing(REAR_LEFT_DX_COXA, 150+tetha.Coxa, *SPEED);
			HexJoint_Actuate_Climbing(REAR_LEFT_DX_FEMUR, 150+tetha.Femur, *SPEED);
			HexJoint_Actuate_Climbing(REAR_LEFT_DX_TIBIA, 150+tetha.Tibia, *SPEED);
			break;
		}
	}
}


void Dyna_IKCALC_NEW(int leg, float x, float y, float z , int *SPEED)
{
	tetha.CoxaBuf = 0;//reset value
	tetha.FemurBuf = 0;//reset value
	tetha.TibiaBuf = 0;//reset value
	tetha.Coxa = 0;//reset value
	tetha.Femur = 0;//reset value
	tetha.Tibia = 0;//reset value

	tetha.CoxaBuf = atan2_deg(y,x);

	float buf3 = pow(z,2);
	float buf4 = pow(x,2);
	float buf5 = buf3 + buf4 ;
	float leg_resultant = sqrt(buf5);

	float A1 = acos_deg(z/leg_resultant);

	float buf6 = (pow(Length2,2)) - (pow(Length1,2))- (pow(leg_resultant,2));
	float buf7 = -2*Length1*leg_resultant;
	float buf8 = buf6/buf7;
	float A2 = acos_deg(buf8);
	float buf12 = 90-A1;
	//FEMUR ANGLE
	tetha.FemurBuf =(A2-buf12);
	//tetha.FemurBuf =(A2+A1);

	float buf9 = (pow(leg_resultant,2)) - (pow(Length2,2)) - (pow(Length1,2));
	float buf10 = -2*Length1*Length2;
	float buf11 = buf9/buf10;
	float B1 = acos_deg(buf11);

	//TIBIA ANGLE
	tetha.TibiaBuf = 180 - (B1);

	tetha.Coxa = (tetha.CoxaBuf);
	tetha.Femur = (tetha.FemurBuf);
	tetha.Tibia = (tetha.TibiaBuf);

	if(STATIC_ANGLE == 0)
	{
		X_STATIC_IK[leg-1] = tetha.Tibia;
		Y_STATIC_IK[leg-1] = tetha.Coxa;
		Z_STATIC_IK[leg-1] = tetha.Femur;
	}

		switch(leg)
		{
		case FRONT_RIGHT_DX:
		{
			HexJoint_Actuate_New(FRONT_RIGHT_DX_COXA, 150-tetha.Coxa, *SPEED);
			HexJoint_Actuate_New(FRONT_RIGHT_DX_FEMUR, 150+tetha.Femur, *SPEED);
			HexJoint_Actuate_New(FRONT_RIGHT_DX_TIBIA, 150+tetha.Tibia, *SPEED);
			break;

		}

		case MIDDLE_RIGHT_DX:
		{
			HexJoint_Actuate_New(MIDDLE_RIGHT_DX_COXA, 150-tetha.Coxa, *SPEED);
			HexJoint_Actuate_New(MIDDLE_RIGHT_DX_FEMUR, 150+tetha.Femur, *SPEED);
			HexJoint_Actuate_New(MIDDLE_RIGHT_DX_TIBIA, 150+tetha.Tibia, *SPEED);
			break;
		}

		case REAR_RIGHT_DX:
		{
			HexJoint_Actuate_New(REAR_RIGHT_DX_COXA, 150-tetha.Coxa, *SPEED);
			HexJoint_Actuate_New(REAR_RIGHT_DX_FEMUR, 150+tetha.Femur, *SPEED);
			HexJoint_Actuate_New(REAR_RIGHT_DX_TIBIA, 150+tetha.Tibia, *SPEED);
			break;
		}

		case FRONT_LEFT_DX:
		{
			HexJoint_Actuate_New(FRONT_LEFT_DX_COXA, 150+tetha.Coxa, *SPEED);
			HexJoint_Actuate_New(FRONT_LEFT_DX_FEMUR, 150+tetha.Femur,*SPEED);
			HexJoint_Actuate_New(FRONT_LEFT_DX_TIBIA, 150+tetha.Tibia, *SPEED);
			break;
		}

		case MIDDLE_LEFT_DX:
		{
			HexJoint_Actuate_New(MIDDLE_LEFT_DX_COXA, 150+tetha.Coxa, *SPEED);
			HexJoint_Actuate_New(MIDDLE_LEFT_DX_FEMUR, 150+tetha.Femur, *SPEED);
			HexJoint_Actuate_New(MIDDLE_LEFT_DX_TIBIA, 150+tetha.Tibia,*SPEED);
			break;
		}

		case REAR_LEFT_DX:
		{
			HexJoint_Actuate_New(REAR_LEFT_DX_COXA, 150+tetha.Coxa, *SPEED);
			HexJoint_Actuate_New(REAR_LEFT_DX_FEMUR, 150+tetha.Femur, *SPEED);
			HexJoint_Actuate_New(REAR_LEFT_DX_TIBIA, 150+tetha.Tibia, *SPEED);
			break;
		}
	}
}

void Dyna_IKCalc_Only_Static_Climbing(int leg, float x, float y, float z, int *SPEED)
{
	tetha.CoxaBuf = 0;//reset value
	tetha.FemurBuf = 0;//reset value
	tetha.TibiaBuf = 0;//reset value
	tetha.Coxa = 0;//reset value
	tetha.Femur = 0;//reset value
	tetha.Tibia = 0;//reset value

	//COXA ANGLE
	tetha.CoxaBuf = atan2_deg(y,x);

	float buf3 = pow(z,2);
	float buf4 = pow(x,2);
	float buf5 = buf3 + buf4 ;
	float leg_resultant = sqrt(buf5);

	float A1 = acos_deg(z/leg_resultant);

	float buf6 = (pow(Length2,2)) - (pow(Length1,2))- (pow(leg_resultant,2));
	float buf7 = -2*Length1*leg_resultant;
	float buf8 = buf6/buf7;
	float A2 = acos_deg(buf8);
	float buf12 = 90-A1;
	//FEMUR ANGLE
	tetha.FemurBuf =(A2-buf12);

	float buf9 = (pow(leg_resultant,2)) - (pow(Length2,2)) - (pow(Length1,2));
	float buf10 = -2*Length1*Length2;
	float buf11 = buf9/buf10;
	float B1 = acos_deg(buf11);

	//TIBIA ANGLE
	tetha.TibiaBuf = 180 - (B1);

	tetha.Coxa = (tetha.CoxaBuf);
	tetha.Femur = (tetha.FemurBuf);
	tetha.Tibia = (tetha.TibiaBuf);

	X_STATIC_IK_S[leg-1] = tetha.Tibia;
	Y_STATIC_IK_S[leg-1] = tetha.Coxa;
	Z_STATIC_IK_S[leg-1] = tetha.Femur;

	switch(leg)
	{
		case FRONT_RIGHT_DX:
		{
			HexJoint_Actuate_Climbing(FRONT_RIGHT_DX_COXA, 150-tetha.Coxa, *SPEED);
			HexJoint_Actuate_Climbing(FRONT_RIGHT_DX_FEMUR, 150+tetha.Femur, *SPEED);
			HexJoint_Actuate_Climbing(FRONT_RIGHT_DX_TIBIA, 150+tetha.Tibia, *SPEED);
			break;

		}

		case MIDDLE_RIGHT_DX:
		{
			HexJoint_Actuate_Climbing(MIDDLE_RIGHT_DX_COXA, 150-tetha.Coxa, *SPEED);
			HexJoint_Actuate_Climbing(MIDDLE_RIGHT_DX_FEMUR, 150+tetha.Femur, *SPEED);
			HexJoint_Actuate_Climbing(MIDDLE_RIGHT_DX_TIBIA, 150+tetha.Tibia, *SPEED);
			break;
		}

		case REAR_RIGHT_DX:
		{
			HexJoint_Actuate_Climbing(REAR_RIGHT_DX_COXA, 150-tetha.Coxa, *SPEED);
			HexJoint_Actuate_Climbing(REAR_RIGHT_DX_FEMUR, 150+tetha.Femur, *SPEED);
			HexJoint_Actuate_Climbing(REAR_RIGHT_DX_TIBIA, 150+tetha.Tibia, *SPEED);
			break;
		}

		case FRONT_LEFT_DX:
		{
			HexJoint_Actuate_Climbing(FRONT_LEFT_DX_COXA, 150+tetha.Coxa, *SPEED);
			HexJoint_Actuate_Climbing(FRONT_LEFT_DX_FEMUR, 150+tetha.Femur,*SPEED);
			HexJoint_Actuate_Climbing(FRONT_LEFT_DX_TIBIA, 150+tetha.Tibia, *SPEED);
			break;
		}

		case MIDDLE_LEFT_DX:
		{
			HexJoint_Actuate_Climbing(MIDDLE_LEFT_DX_COXA, 150+tetha.Coxa, *SPEED);
			HexJoint_Actuate_Climbing(MIDDLE_LEFT_DX_FEMUR, 150+tetha.Femur, *SPEED);
			HexJoint_Actuate_Climbing(MIDDLE_LEFT_DX_TIBIA, 150+tetha.Tibia,*SPEED);
			break;
		}

		case REAR_LEFT_DX:
		{
			HexJoint_Actuate_Climbing(REAR_LEFT_DX_COXA, 150+tetha.Coxa, *SPEED);
			HexJoint_Actuate_Climbing(REAR_LEFT_DX_FEMUR, 150+tetha.Femur, *SPEED);
			HexJoint_Actuate_Climbing(REAR_LEFT_DX_TIBIA, 150+tetha.Tibia, *SPEED);
			break;
		}
	}
}


void Dyna_IKCalc_Only(float x, float y, float z )
{
	tetha.CoxaBuf = 0;//reset value
	tetha.FemurBuf = 0;//reset value
	tetha.TibiaBuf = 0;//reset value
	tetha.Coxa = 0;//reset value
	tetha.Femur = 0;//reset value
	tetha.Tibia = 0;//reset value

	//COXA ANGLE
	tetha.CoxaBuf = atan2_deg(y,x);

//	x = fabsf(x);
//	y = fabsf(y);
//	z = fabsf(z);

	float buf3 = pow(z,2);
	float buf4 = pow(x,2);
	float buf5 = buf3 + buf4 ;
	float leg_resultant = sqrt(buf5);

	float A1 = acos_deg(z/leg_resultant);

	float buf6 = (pow(Length2,2)) - (pow(Length1,2))- (pow(leg_resultant,2));
	float buf7 = -2*Length1*leg_resultant;
	float buf8 = buf6/buf7;
	float A2 = acos_deg(buf8);
	float buf12 = 90-A1;
	//FEMUR ANGLE
	tetha.FemurBuf =(A2-buf12);

	float buf9 = (pow(leg_resultant,2)) - (pow(Length2,2)) - (pow(Length1,2));
	float buf10 = -2*Length1*Length2;
	float buf11 = buf9/buf10;
	float B1 = acos_deg(buf11);

	//TIBIA ANGLE
	tetha.TibiaBuf = 180 - (B1);

	tetha.Coxa = (tetha.CoxaBuf);
	tetha.Femur = (tetha.FemurBuf);
	tetha.Tibia = (tetha.TibiaBuf);
}

void Translation(float x_trans,float y_trans,int leg)
{
	 X_Body_Offset_final[leg-1]=X_BODY_OFFSET[leg-1]+X_STATIC_OFFSET;
	 Y_Body_Offset_final[leg-1]=Y_BODY_OFFSET[leg-1]+Y_STATIC_OFFSET;
	 X_Leg_PosFinal[leg-1] = X_Body_Offset_final[leg-1] + x_trans;
	 Y_Leg_PosFinal[leg-1] = Y_Body_Offset_final[leg-1] + y_trans;
	 X_Trans_Leg[leg-1] = x_trans;
	 Y_Trans_Leg[leg-1] = y_trans;
	 float buf1 = X_Leg_PosFinal[leg-1] - X_BODY_OFFSET[leg-1];
	 float buf2 = Y_Leg_PosFinal[leg-1] - Y_BODY_OFFSET[leg-1];
	 float buf3 = pow(buf1,2);
	 float buf4 = pow(buf2,2);
	 leg_length_total = sqrt(buf3+buf4);
}

void Rotation(float x_offset, float y_offset, int leg )
{
	int i;
	for(i=0;i<=3;i++)
	{
		if(i == 0)
		{
			rotation_matriks[0]=cos_deg(tetha_offset[leg-1]);
		}
		else if(i == 1)
		{
			rotation_matriks[1]=sin_deg(tetha_offset[leg-1]);
		}
		else if(i == 2)
		{
			rotation_matriks[2]=sin_deg(tetha_offset[leg-1]*-1);
		}
		else if(i == 3)
		{
			rotation_matriks[3]=cos_deg(tetha_offset[leg-1]);
		}
	}

	X_rotgoal[leg-1] = (rotation_matriks[0]*x_offset)  +  (rotation_matriks[1]*y_offset);
	Y_rotgoal[leg-1] = (rotation_matriks[2]*x_offset)  +  (rotation_matriks[3]*y_offset);
}

void Generate_Body(float X, float Y)
{
	int leg = 1;

	for(leg = 1; leg<=6; leg++)
	{
		Translation(X,Y,leg);
		Rotation(leg_length_total,Y_Trans_Leg[leg-1],leg);
	}
	Y_Diff = Y_rotgoal[0];
	X_Diff = leg_length_total - leg_static_length;

	if((X==0 && Y==0) && (STATIC_ANGLE == 0))
	{
		int i;
		for(i=0;i<=5;i++)
		{
			if(i == 2 )
			{
				X_IK_BEGIN[i]=X_Diff-1;
			}
			else if(i == 3)
			{
				X_IK_BEGIN[i]=X_Diff-1;
			}

			else
			{
				X_IK_BEGIN[i]=X_Diff;
			}

			Y_IK_BEGIN[i]=Y_Diff;
			leg_static_length = leg_length_total;
		}
	}
}

double H_Elips(double y,double z_max,double goal_pos)
{
	double z_final,a,b;
	a=goal_pos;
	float buf1 = pow(y,2);
	float buf2 = pow(a,2);
	float buf3 = (buf1/buf2);
	float buf4 = (1-buf3);
	buf4=fabs(buf4);
	z_final = (sqrt(buf4))*z_max;
	return z_final;
}

void Trajectory_Generator_Obs_6S(float x, float y, float z_max, float sampling, int movement)
{
	float step_y,step_y1,step_x1,step_x3,step_x2,step_x5,step_z,step_x4;
	float x1,x2,y1;
	float trans_y_pos = 0,trans_y_neg = 0,trans_y1 = 0,trans_x1 = 0,trans_x2=0,trans_x3=0,trans_x4=0,trans_z=0,trans_x5=0;

	x1 = x-0.8;
	x2 = x-1.5;

	y1 = y;

	step_y = (y)/sampling;
	step_y1 = y1/sampling;
	step_x2 = x2/(sampling);
	step_x1 = x1/(sampling);

	trans_y_neg = (y*-1);

	int j=0,i=0;
	for(i=0;i<sampling;i++)
	{
		trans_x1 += step_x1;
		trans_x2 += step_x2;
		trans_y1 += step_y1;

		X1_Sampling[i] = trans_x1;
		X2_Sampling[i] = trans_x2;

		trans_y_pos += step_y;
		trans_y_neg += step_y;

		Y_Sampling[i] = trans_y_pos;
		Y1_Sampling[i] = trans_y1;
		Y2_Sampling[i] = trans_y_neg;
		Z_Sampling[i] = H_Elips(Y2_Sampling[i],z_max,y);
	}

	for(j=0;j<sampling;j++)
	{
		Y_IK[j]= Y_Sampling[j];
		Y1_IK[j] = Y1_Sampling[j];
		Z_IK[j]= Z_Sampling[j];

		X1_IK[j] = X1_Sampling[j];
		X2_IK[j] = X2_Sampling[j];
	}
}


void Trajectory_Generator_Obs(float x, float y, float z_max, float sampling, int movement)
{
	float step_y,step_y1,step_x1,step_x3,step_x2,step_x5,step_z,step_x4;
	float x1,x2,x3,x4,y1;
	float trans_y_pos = 0,trans_y_neg = 0,trans_y1 = 0,trans_x1 = 0,trans_x2=0,trans_x3=0,trans_x4=0,trans_z=0,trans_x5=0;

	x1 = x-0.8;
	x2 = x-1.5;
	x3 = x-4;
	x4 = x-1.5;

	y1 = y;

	step_y = (y)/sampling;
	step_y1 = y1/sampling;
	step_x2 = x2/(sampling);
	step_x1 = x1/(sampling);
	step_x3 = x3/(sampling);
	step_x4 = x4/(sampling);

	trans_y_neg = (y*-1);

	int j=0,i=0;
	for(i=0;i<sampling;i++)
	{
		trans_x1 += step_x1;
		trans_x2 += step_x2;
		trans_x3 += step_x3;
		trans_x4 += step_x4;
		trans_y1 += step_y1;

		X1_Sampling[i] = trans_x1;
		X2_Sampling[i] = trans_x2;
		X3_Sampling[i] = trans_x3;
		X4_Sampling[i] = trans_x4;

		trans_y_pos += step_y;
		trans_y_neg += step_y;

		Y_Sampling[i] = trans_y_pos;
		Y1_Sampling[i] = trans_y1;
		Y2_Sampling[i] = trans_y_neg;
		Z_Sampling[i] = H_Elips(Y2_Sampling[i],z_max,y);
	}

	for(j=0;j<sampling;j++)
	{
		Y_IK[j]= Y_Sampling[j];
		Y1_IK[j] = Y1_Sampling[j];
		Z_IK[j]= Z_Sampling[j];

		X1_IK[j] = X1_Sampling[j];
		X2_IK[j] = X2_Sampling[j];
		X3_IK[j] = X3_Sampling[j];
		X4_IK[j] = X4_Sampling[j];
	}
}


void Trajectory_Generator_Climbing(float x, float y, float z_max, float sampling, int movement)
{
	float step_y,step_y1,step_x1,step_x3,step_x2,step_x5,step_z,step_x4;
	float x1,x2,x3,x4,y1;
	float trans_y_pos = 0,trans_y_neg = 0,trans_y1 = 0,trans_x1 = 0,trans_x2=0,trans_x3=0,trans_x4=0,trans_z=0,trans_x5=0;

	x1 = x-0.8;
	x2 = x-1;
	x3 = x-0.2;
	x4 = x-1.5;

	y1 = y;

	step_y = (y)/sampling;
	step_y1 = y1/sampling;
	step_x2 = x2/(sampling);
	step_x1 = x1/(sampling);
	step_x3 = x3/(sampling);
	step_x4 = x4/(sampling);

	trans_y_neg = (y*-1);

	int j=0,i=0;
	for(i=0;i<sampling;i++)
	{
		trans_x1 += step_x1;
		trans_x2 += step_x2;
		trans_x3 += step_x3;
		trans_x4 += step_x4;
		trans_y1 += step_y1;

		X1_Sampling[i] = trans_x1;
		X2_Sampling[i] = trans_x2;
		X3_Sampling[i] = trans_x3;
		X4_Sampling[i] = trans_x4;


		trans_y_pos += step_y;
		trans_y_neg += step_y;

		Y_Sampling[i] = trans_y_pos;
		Y1_Sampling[i] = trans_y1;
		Y2_Sampling[i] = trans_y_neg;
		Z_Sampling[i] = H_Elips(Y2_Sampling[i],z_max,y);
	}

	for(j=0;j<sampling;j++)
	{
		Y_IK[j]= Y_Sampling[j];
		Y1_IK[j] = Y1_Sampling[j];
		Z_IK[j]= Z_Sampling[j];

		X1_IK[j] = X1_Sampling[j];
		X2_IK[j] = X2_Sampling[j];
		X3_IK[j] = X3_Sampling[j];
		X4_IK[j] = X4_Sampling[j];
	}
}

void Trajectory_Generator_6S(float x, float y, float z_max, float sampling, int movement)
{
		float step_y,step_y2,step_x1,step_x3,step_x2,step_x5,step_z,step_x4,x2,x3,x4,x5,x6;
		float trans_y = 0,trans_y2=0, trans_x1 = 0,trans_x2=0,trans_x3=0,trans_x4=0,trans_z=0,trans_x5=0;

		x5 = x-0.5;
		x4 = x-1.4;//1.4;
		x3 = x-1.5;
		x2 = x;
		x6 = x-0.6;
		step_y = (y)/sampling;
		step_x2 = x2/(sampling);
		step_x1 = x/(sampling);
		step_x3 = x3/(sampling);
		step_x4 = x4/(sampling);
		step_x5 = x5/ (sampling);
		trans_y = (y*-1);

		int j=0,i=0;
		for(i=0;i<6;i++)
		{
			trans_x1 += step_x1;
			trans_x2 += step_x2;
			trans_x3 += step_x3;
			trans_x4 += step_x4;
			trans_x5 += step_x5;
			trans_y2 += step_y;

			X1_Sampling[i] = trans_x1;
			X2_Sampling[i] = trans_x2;
			X3_Sampling[i] = trans_x3;
			X4_Sampling[i] = trans_x4;
			X5_Sampling[i] = trans_x5;
			Y2_Sampling[i] = trans_y2;

			trans_y += step_y;
			Y_Sampling[i] = trans_y;
			Z_Sampling[i] = H_Elips(Y_Sampling[i],z_max,y);
		}

		for(j=0;j<6;j++)
		{
			Y_IK[j]= Y2_Sampling[j];
			Z_IK[j]= Z_Sampling[j];

			X1_IK[j] = X1_Sampling[j];
			X2_IK[j] = X2_Sampling[j];
			X3_IK[j] = X3_Sampling[j];
			X4_IK[j] = X4_Sampling[j];
			X5_IK[j] = X5_Sampling[j];
		}
}


void Trajectory_Generator_NEW(float x, float y, float z_max, float sampling, int movement)
{
		float step_y,step_y2,step_x1,step_x3,step_x2,step_x5,step_z,step_x4,x2,x3,x4,x5,x6;
		float trans_y = 0,trans_y2=0, trans_x1 = 0,trans_x2=0,trans_x3=0,trans_x4=0,trans_z=0,trans_x5=0;

		x5 = x-0.5;
		x4 = x-1.4;//1.4;
		x4 = x;
		x3 = x-1.5;
		x2 = x;
		x6 = x-0.6;
		step_y = (y)/sampling;
		step_x2 = x2/(sampling);
		step_x1 = x/(sampling);
		step_x3 = x3/(sampling);
		step_x4 = x4/(sampling);
		step_x5 = x5/ (sampling);
		trans_y = (y*-1);

		int j=0,i=0;
		for(i=0;i<4;i++)
		{
			trans_x1 += step_x1;
			trans_x2 += step_x2;
			trans_x3 += step_x3;
			trans_x4 += step_x4;
			trans_x5 += step_x5;
			trans_y2 += step_y;

			X1_Sampling[i] = trans_x1;
			X2_Sampling[i] = trans_x2;
			X3_Sampling[i] = trans_x3;
			X4_Sampling[i] = trans_x4;
			X5_Sampling[i] = trans_x5;
			Y2_Sampling[i] = trans_y2;

			trans_y += step_y;
			Y_Sampling[i] = trans_y;
			Z_Sampling[i] = H_Elips(Y_Sampling[i],z_max,y);
		}

		for(j=0;j<4;j++)
		{
			Y_IK[j]= Y2_Sampling[j];
			Z_IK[j]= Z_Sampling[j];

			X1_IK[j] = X1_Sampling[j];
			X2_IK[j] = X2_Sampling[j];
			X3_IK[j] = X3_Sampling[j];
			X4_IK[j] = X4_Sampling[j];
			X5_IK[j] = X5_Sampling[j];
		}
}

void Trajectory_Generator_Lean(float x, float y, float z_max, float sampling, int movement)
{
		float step_y,step_y2,step_x1,step_x3,step_x2,step_x5,step_z,step_x4,x2,x3,x4,x5,x6,x1;
		float trans_y = 0,trans_y2=0, trans_x1 = 0,trans_x2=0,trans_x3=0,trans_x4=0,trans_z=0,trans_x5=0;

		x2 = x-2;
		x1 = x-4;
		x3 = x-3;
		x4 = x-6;

		step_y = (y)/sampling;
		step_x2 = x2/(sampling);
		step_x1 = x1/(sampling);
		step_x3 = x3/(sampling);
		step_x4 = x4/(sampling);
		trans_y = (y*-1);

		int j=0,i=0;
		for(i=0;i<4;i++)
		{
			trans_x1 += step_x1;
			trans_x2 += step_x2;
			trans_x3 += step_x3;
			trans_x4 += step_x4;
			trans_y2 += step_y;

			X1_Sampling[i] = trans_x1;
			X2_Sampling[i] = trans_x2;
			X3_Sampling[i] = trans_x3;
			X4_Sampling[i] = trans_x4;
			Y2_Sampling[i] = trans_y2;

			trans_y += step_y;
			Y_Sampling[i] = trans_y;
			Z_Sampling[i] = H_Elips(Y_Sampling[i],z_max,y);
		}

		for(j=0;j<4;j++)
		{
			Y_IK[j]= Y2_Sampling[j];
			Z_IK[j]= Z_Sampling[j];

			X1_IK[j] = X1_Sampling[j];
			X2_IK[j] = X2_Sampling[j];
			X3_IK[j] = X3_Sampling[j];
			X4_IK[j] = X4_Sampling[j];
		}
}

void Dynamx_MoveLeg_Interpolate_NEW(int leg_position, int *SPEED, int ThetaCoxa, int ThetaFemur, int ThetaTibia)
{
	switch(leg_position)
		{
		case FRONT_RIGHT_DX:
		{
			HexJoint_Actuate_New(FRONT_RIGHT_DX_COXA, 150-ThetaCoxa, *SPEED);
			HexJoint_Actuate_New(FRONT_RIGHT_DX_FEMUR, 150+ThetaFemur, *SPEED);
			HexJoint_Actuate_New(FRONT_RIGHT_DX_TIBIA, 150+ThetaTibia, *SPEED);

		}break;

		case MIDDLE_RIGHT_DX:
		{
			HexJoint_Actuate_New(MIDDLE_RIGHT_DX_COXA, 150-ThetaCoxa, *SPEED);
			HexJoint_Actuate_New(MIDDLE_RIGHT_DX_FEMUR, 150+ThetaFemur, *SPEED);
			HexJoint_Actuate_New(MIDDLE_RIGHT_DX_TIBIA, 150+ThetaTibia, *SPEED);
		}break;

		case REAR_RIGHT_DX:
		{
			HexJoint_Actuate_New(REAR_RIGHT_DX_COXA, 150-ThetaCoxa, *SPEED);
			HexJoint_Actuate_New(REAR_RIGHT_DX_FEMUR, 150+ThetaFemur, *SPEED);
			HexJoint_Actuate_New(REAR_RIGHT_DX_TIBIA, 150+ThetaTibia, *SPEED);
		}break;

		case FRONT_LEFT_DX:
		{
			HexJoint_Actuate_New(FRONT_LEFT_DX_COXA, 150+ThetaCoxa, *SPEED);
			HexJoint_Actuate_New(FRONT_LEFT_DX_FEMUR, 150+ThetaFemur,*SPEED);
			HexJoint_Actuate_New(FRONT_LEFT_DX_TIBIA, 150+ThetaTibia, *SPEED);
		}break;

		case MIDDLE_LEFT_DX:
		{
			HexJoint_Actuate_New(MIDDLE_LEFT_DX_COXA, 150+ThetaCoxa, *SPEED);
			HexJoint_Actuate_New(MIDDLE_LEFT_DX_FEMUR, 150+ThetaFemur, *SPEED);
			HexJoint_Actuate_New(MIDDLE_LEFT_DX_TIBIA, 150+ThetaTibia,*SPEED);
		}break;

		case REAR_LEFT_DX:
		{
			HexJoint_Actuate_New(REAR_LEFT_DX_COXA, 150+ThetaCoxa, *SPEED);
			HexJoint_Actuate_New(REAR_LEFT_DX_FEMUR, 150+ThetaFemur, *SPEED);
			HexJoint_Actuate_New(REAR_LEFT_DX_TIBIA, 150+ThetaTibia, *SPEED);
		}break;
	}
}
