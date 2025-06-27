/*==============================================================================================
								  	 PROJECT BW Ver.1.0
								  	 BW PID CONTROLLER
==============================================================================================*/

#include "bw_pid_controller.h"
// PID FOLLOW VARIABLES


//int count=1;


void Fuzzy_Follow_kanan(void)
{
	selisih = Ping[PING_ASKEW_RIGHT] - Fuzzy_FKR_SP;
	if((selisih == 1) || (selisih == -1)){selisih = 0;}
//	else{selisih = abs(selisih);}
	selisih = abs(selisih);

	//Error kecil
	if(selisih <= 3 ){ERROR_DATA[0] = 1; }
	else if(selisih > 3 && selisih <= 4.75)
	{
		ERROR_DATA[0]= ((float)selisih - 3.0)/(4.75-3.0);
	}
	else if(selisih > 4.75 && selisih <= 6.75)
	{
		ERROR_DATA[0]= ((float)selisih - 4.75)/(6.75-4.75);
	}
	else{ERROR_DATA[0] = 0;}

	//Error med kecil
	if(selisih <= 3){ERROR_DATA[1]=0;}
	else if(selisih > 3 && selisih <= 4.75)
	{
		ERROR_DATA[1]= ((float)selisih - 3.0)/(4.75-3.0);
	}
	else{ERROR_DATA[1]= 0;}

	//Error sedang
	if(selisih <= 4.75){ERROR_DATA[2] = 0;}
	else if(selisih > 4.75 && selisih <= 6.5)
	{
		ERROR_DATA[2]= ((float)selisih - 4.75)/(6.5-4.75);
	}
	else if(selisih > 6.5 && selisih <= 8.25)
	{
		ERROR_DATA[2]= ((float)selisih - 6.5)/(8.25-6.5);
	}
	else{ERROR_DATA[2] = 0;}

	//Error med besar
	if(selisih <= 8.25){ERROR_DATA[3]=0;}
		else if(selisih > 8.25 && selisih <= 10)
		{
			ERROR_DATA[3]= ((float)selisih - 8.25)/(10.0-8.25);
		}
		else{ERROR_DATA[3]= 0;}

	//Error besar
	if(selisih <= 6.5){ERROR_DATA[2] = 0;}
	else if(selisih > 6.5 && selisih <= 8.25)
	{
		ERROR_DATA[4]= ((float)selisih - 6.5)/(8.25-6.5);
	}
	else if(selisih > 8.25 && selisih <= 10)
	{
		ERROR_DATA[4]= ((float)selisih - 8.25)/(10-8.25);
	}

	else{ERROR_DATA[4] = 1;}

	final_angel[RIGHT_FOLLOW] = (ERROR_DATA[0]*angel_low)  + (ERROR_DATA[1]*angel_med_low)  + (ERROR_DATA[2]*angel_medium) + (ERROR_DATA[3]*angel_med_high) + (ERROR_DATA[4]*angel_high);
	Defuzzy_follow_kanan = ERROR_DATA[0] + ERROR_DATA[1] + ERROR_DATA[2] + ERROR_DATA[3] + ERROR_DATA[4];
	final_angel[RIGHT_FOLLOW] = final_angel[RIGHT_FOLLOW]/Defuzzy_follow_kanan;
}


void Fuzzy_Follow_kiri(void)
{
	selisih = Ping[PING_ASKEW_LEFT] - Fuzzy_FKR_SP;
	if((selisih == 1) || (selisih == -1)){selisih = 0;}
//	else{selisih = abs(selisih);}
	selisih = abs(selisih);

		//Error kecil
		if(selisih <= 3 ){ERROR_DATA[0] = 1; }
		else if(selisih > 3 && selisih <= 4.75)
		{
			ERROR_DATA[0]= ((float)selisih - 3.0)/(4.75-3.0);
		}
		else if(selisih > 4.75 && selisih <= 6.75)
		{
			ERROR_DATA[0]= ((float)selisih - 4.75)/(6.75-4.75);
		}
		else{ERROR_DATA[0] = 0;}

		//Error med kecil
		if(selisih <= 3){ERROR_DATA[1]=0;}
		else if(selisih > 3 && selisih <= 4.75)
		{
			ERROR_DATA[1]= ((float)selisih - 3.0)/(4.75-3.0);
		}
		else{ERROR_DATA[1]= 0;}

		//Error sedang
		if(selisih <= 4.75){ERROR_DATA[2] = 0;}
		else if(selisih > 4.75 && selisih <= 6.5)
		{
			ERROR_DATA[2]= ((float)selisih - 4.75)/(6.5-4.75);
		}
		else if(selisih > 6.5 && selisih <= 8.25)
		{
			ERROR_DATA[2]= ((float)selisih - 6.5)/(8.25-6.5);
		}
		else{ERROR_DATA[2] = 0;}

		//Error med besar
		if(selisih <= 8.25){ERROR_DATA[3]=0;}
			else if(selisih > 8.25 && selisih <= 10)
			{
				ERROR_DATA[3]= ((float)selisih - 8.25)/(10.0-8.25);
			}
			else{ERROR_DATA[3]= 0;}

		//Error besar
		if(selisih <= 6.5){ERROR_DATA[2] = 0;}
		else if(selisih > 6.5 && selisih <= 8.25)
		{
			ERROR_DATA[4]= ((float)selisih - 6.5)/(8.25-6.5);
		}
		else if(selisih > 8.25 && selisih <= 10)
		{
			ERROR_DATA[4]= ((float)selisih - 8.25)/(10-8.25);
		}

		else{ERROR_DATA[4] = 1;}

		final_angel[LEFT_FOLLOW] = (ERROR_DATA[0]*angel_low)  + (ERROR_DATA[1]*angel_med_low)  + (ERROR_DATA[2]*angel_medium) + (ERROR_DATA[3]*angel_med_high) + (ERROR_DATA[4]*angel_high);
		Defuzzy_follow_kiri = ERROR_DATA[0] + ERROR_DATA[1] + ERROR_DATA[2] + ERROR_DATA[3] + ERROR_DATA[4];
		final_angel[LEFT_FOLLOW] = final_angel[LEFT_FOLLOW]/Defuzzy_follow_kiri;
}

void BW_PID_Init(void)
{
	Fuzzy_FKR_SP = 17;
	CAT_DETECTOR=CAT_DIACTIVATED;
	CALC_EN = 1;
	RIGHT_COUNTER = 0;
	LEFT_COUNTER = 0;
	speed_cnt = 0;

	//BW PID WALL FOLLOWING RIGHT RULE
	PID_F_R.P[0]=0;
	PID_F_R.P[1]=0;
	PID_F_R.P[2]=0;
	PID_F_R.I[0]=0;
	PID_F_R.I[1]=0;
	PID_F_R.I[2]=0;
	PID_F_R.D[0]=0;
	PID_F_R.D[1]=0;
	PID_F_R.D[2]=0;

	//fix
	PID_F_R.Kp=3.5;//3.2;//2.1;//2.6;//2.5;//15.3;//15;
	PID_F_R.Ki= 2.5;//1.8;//2.0;//2.1;
	PID_F_R.Kd=0;

	PID_F_R.Ts=0.005;

	//===FIX 11/10/16===//
	PID_F_R.set_point_upper=16;
	PID_F_R.set_point_lower=15;
	PID_F_R.set_point=15;

	PID_F_R_OLD.error[0]=PID_F_R.error[0];
	PID_F_R_OLD.error[1]=PID_F_R.error[1];
	PID_F_R_OLD.error[2]=PID_F_R.error[2];
	PID_F_R.error[0]=0;
	PID_F_R.error[1]=0;
	PID_F_R.error[2]=0;
	PID_F_R.pid_value[0]=0;
	PID_F_R.pid_value[1]=0;
	PID_F_R.pid_value[2]=0;
	PID_F_L.P[1]=0;
	PID_F_L.P[2]=0;
	PID_F_L.I[0]=0;
	PID_F_L.I[1]=0;
	PID_F_L.I[2]=0;
	PID_F_L.D[0]=0;
	PID_F_L.D[1]=0;
	PID_F_L.D[2]=0;

//	fix baterai bintang
	PID_F_L.Kp=3.5;//3.0;//2.1;//2.6;//2.5;//15.3;//15;
	PID_F_L.Ki=2.5;//1.8;//2.1;
	PID_F_L.Kd=0;

	PID_F_L.Ts=0.005;

	PID_F_L_OLD.error[0]=PID_F_L.error[0];
	PID_F_L_OLD.error[1]=PID_F_L.error[1];
	PID_F_L_OLD.error[2]=PID_F_L.error[2];
	PID_F_L.error[0]=0;
	PID_F_L.error[1]=0;
	PID_F_L.error[2]=0;

	PID_F_L.pid_value[0]=0;
	PID_F_L.pid_value[1]=0;
	PID_F_L.pid_value[2]=0;

	PID_F_L.set_point_upper=16;
	PID_F_L.set_point_lower=15;
	PID_F_L.set_point=15;

	//BW PID WALL CENTERING DEFLECT RIGHT RULE
	PID_DFL_R.P[0]=0;
	PID_DFL_R.P[1]=0;
	PID_DFL_R.P[2]=0;
	PID_DFL_R.I[0]=0;
	PID_DFL_R.I[1]=0;
	PID_DFL_R.I[2]=0;
	PID_DFL_R.D[0]=0;
	PID_DFL_R.D[1]=0;
	PID_DFL_R.D[2]=0;
	PID_DFL_R.Kp=4;
	PID_DFL_R.Ki=4;
	PID_DFL_R.Kd=3;
	PID_DFL_R.Ts=1;
	PID_DFL_R.error[0]=0;
	PID_DFL_R.error[1]=0;
	PID_DFL_R.error[2]=0;
	PID_DFL_R.pid_value[0]=0;
	PID_DFL_R.pid_value[1]=0;
	PID_DFL_R.pid_value[2]=0;
	PID_DFL_R.set_point=16;

	//BW PID WALL CENTERING DEFLECT RIGHT RULE
	PID_DFL_L.P[0]=0;
	PID_DFL_L.P[1]=0;
	PID_DFL_L.P[2]=0;
	PID_DFL_L.I[0]=0;
	PID_DFL_L.I[1]=0;
	PID_DFL_L.I[2]=0;
	PID_DFL_L.D[0]=0;
	PID_DFL_L.D[1]=0;
	PID_DFL_L.D[2]=0;
	PID_DFL_L.Kp=1;
	PID_DFL_L.Ki=0;
	PID_DFL_L.Kd=0;
	PID_DFL_L.Ts=1;
	PID_DFL_L.error[0]=0;
	PID_DFL_L.error[1]=0;
	PID_DFL_L.error[2]=0;
	PID_DFL_L.pid_value[0]=0;
	PID_DFL_L.pid_value[1]=0;
	PID_DFL_L.pid_value[2]=0;
	PID_DFL_L.set_point=16;
}

/*
 * func : void BW_PID_Init_Revers(void)
 * brief: initialize PID variables
 * param: N/A
 * Programmer's Note: This function only required to be called once in the early initialization
 * 					  Call this function in the BW_Initialization function
 */
void BW_PID_Init_Reverse(void)
{
	Fuzzy_FKR_SP = 17;
	CAT_DETECTOR=CAT_DIACTIVATED;
	CALC_EN = 1;
	RIGHT_COUNTER = 0;
	LEFT_COUNTER = 0;
	speed_cnt = 0;

	//BW PID WALL FOLLOWING RIGHT RULE
	PID_F_R.P[0]=0;
	PID_F_R.P[1]=0;
	PID_F_R.P[2]=0;
	PID_F_R.I[0]=0;
	PID_F_R.I[1]=0;
	PID_F_R.I[2]=0;
	PID_F_R.D[0]=0;
	PID_F_R.D[1]=0;
	PID_F_R.D[2]=0;

	//fix
	PID_F_R.Kp=3.2;//2.1;//2.6;//2.5;//15.3;//15;
	PID_F_R.Ki=2.0;//2.1;
	PID_F_R.Kd=0;

	PID_F_R.Ts=0.005;

	//===FIX 11/10/16===//
	PID_F_R.set_point_upper=17;
	PID_F_R.set_point_lower=16;
	PID_F_R.set_point=16;

	PID_F_R_OLD.error[0]=PID_F_R.error[0];
	PID_F_R_OLD.error[1]=PID_F_R.error[1];
	PID_F_R_OLD.error[2]=PID_F_R.error[2];
	PID_F_R.error[0]=0;
	PID_F_R.error[1]=0;
	PID_F_R.error[2]=0;
	PID_F_R.pid_value[0]=0;
	PID_F_R.pid_value[1]=0;
	PID_F_R.pid_value[2]=0;
	PID_F_L.P[1]=0;
	PID_F_L.P[2]=0;
	PID_F_L.I[0]=0;
	PID_F_L.I[1]=0;
	PID_F_L.I[2]=0;
	PID_F_L.D[0]=0;
	PID_F_L.D[1]=0;
	PID_F_L.D[2]=0;

//	fix baterai bintang
	PID_F_L.Kp=3.0;//2.1;//2.6;//2.5;//15.3;//15;
	PID_F_L.Ki=1.8;//2.1;
	PID_F_L.Kd=0;

	PID_F_L.Ts=0.005;

	PID_F_L_OLD.error[0]=PID_F_L.error[0];
	PID_F_L_OLD.error[1]=PID_F_L.error[1];
	PID_F_L_OLD.error[2]=PID_F_L.error[2];
	PID_F_L.error[0]=0;
	PID_F_L.error[1]=0;
	PID_F_L.error[2]=0;

	PID_F_L.pid_value[0]=0;
	PID_F_L.pid_value[1]=0;
	PID_F_L.pid_value[2]=0;

	PID_F_L.set_point_upper=17;
	PID_F_L.set_point_lower=16;
	PID_F_L.set_point=16;

	//BW PID WALL CENTERING DEFLECT RIGHT RULE
	PID_DFL_R.P[0]=0;
	PID_DFL_R.P[1]=0;
	PID_DFL_R.P[2]=0;
	PID_DFL_R.I[0]=0;
	PID_DFL_R.I[1]=0;
	PID_DFL_R.I[2]=0;
	PID_DFL_R.D[0]=0;
	PID_DFL_R.D[1]=0;
	PID_DFL_R.D[2]=0;
	PID_DFL_R.Kp=4;
	PID_DFL_R.Ki=4;
	PID_DFL_R.Kd=3;
	PID_DFL_R.Ts=1;
	PID_DFL_R.error[0]=0;
	PID_DFL_R.error[1]=0;
	PID_DFL_R.error[2]=0;
	PID_DFL_R.pid_value[0]=0;
	PID_DFL_R.pid_value[1]=0;
	PID_DFL_R.pid_value[2]=0;
	PID_DFL_R.set_point=16;

	//BW PID WALL CENTERING DEFLECT RIGHT RULE
	PID_DFL_L.P[0]=0;
	PID_DFL_L.P[1]=0;
	PID_DFL_L.P[2]=0;
	PID_DFL_L.I[0]=0;
	PID_DFL_L.I[1]=0;
	PID_DFL_L.I[2]=0;
	PID_DFL_L.D[0]=0;
	PID_DFL_L.D[1]=0;
	PID_DFL_L.D[2]=0;
	PID_DFL_L.Kp=1;
	PID_DFL_L.Ki=0;
	PID_DFL_L.Kd=0;
	PID_DFL_L.Ts=1;
	PID_DFL_L.error[0]=0;
	PID_DFL_L.error[1]=0;
	PID_DFL_L.error[2]=0;
	PID_DFL_L.pid_value[0]=0;
	PID_DFL_L.pid_value[1]=0;
	PID_DFL_L.pid_value[2]=0;
	PID_DFL_L.set_point=16;
}


/*
 * func : void BW_PID_Init(void)
 * brief: initialize PID variables
 * param: N/A
 * Programmer's Note: This function only required to be called once in the early initialization
 * 					  Call this function in the BW_Initialization function
 */

void BW_PID_Init_FAR(void)
{
	Fuzzy_FKR_SP = 17;
	CAT_DETECTOR=CAT_ACTIVATED;
	CALC_EN = 1;
	RIGHT_COUNTER = 0;
	LEFT_COUNTER = 0;
	speed_cnt = 0;

	//BW PID WALL FOLLOWING RIGHT RULE
	PID_F_R.P[0]=0;
	PID_F_R.P[1]=0;
	PID_F_R.P[2]=0;
	PID_F_R.I[0]=0;
	PID_F_R.I[1]=0;
	PID_F_R.I[2]=0;
	PID_F_R.D[0]=0;
	PID_F_R.D[1]=0;
	PID_F_R.D[2]=0;


	PID_F_R.Kp=3.1;//2.4;//2.4;//17;
	PID_F_R.Ki=2.0;
	PID_F_R.Kd=0.0;

	PID_F_R.Ts=0.05;

	//===FIX 11/10/16===//
	PID_F_R.set_point_upper=17;
	PID_F_R.set_point_lower=16;
	PID_F_R.set_point=16;

	PID_F_R_OLD.error[0]=PID_F_R.error[0];
	PID_F_R_OLD.error[1]=PID_F_R.error[1];
	PID_F_R_OLD.error[2]=PID_F_R.error[2];
	PID_F_R.error[0]=0;
	PID_F_R.error[1]=0;
	PID_F_R.error[2]=0;
	PID_F_R.pid_value[0]=0;
	PID_F_R.pid_value[1]=0;
	PID_F_R.pid_value[2]=0;
	PID_F_L.P[1]=0;
	PID_F_L.P[2]=0;
	PID_F_L.I[0]=0;
	PID_F_L.I[1]=0;
	PID_F_L.I[2]=0;
	PID_F_L.D[0]=0;
	PID_F_L.D[1]=0;
	PID_F_L.D[2]=0;


	//baterai bintang
	PID_F_L.Kp=2.9;//2.4;//2.4;//2.4;//17;
	PID_F_L.Ki=2.1;
	PID_F_L.Kd=0;


	PID_F_L.Ts=0.005;


	PID_F_L_OLD.error[0]=PID_F_L.error[0];
	PID_F_L_OLD.error[1]=PID_F_L.error[1];
	PID_F_L_OLD.error[2]=PID_F_L.error[2];
	PID_F_L.error[0]=0;
	PID_F_L.error[1]=0;
	PID_F_L.error[2]=0;

	PID_F_L.pid_value[0]=0;
	PID_F_L.pid_value[1]=0;
	PID_F_L.pid_value[2]=0;

	PID_F_L.set_point=17;
	PID_F_L.set_point_upper=18;
	PID_F_L.set_point_lower=17;

	//BW PID WALL CENTERING DEFLECT RIGHT RULE
	PID_DFL_R.P[0]=0;
	PID_DFL_R.P[1]=0;
	PID_DFL_R.P[2]=0;
	PID_DFL_R.I[0]=0;
	PID_DFL_R.I[1]=0;
	PID_DFL_R.I[2]=0;
	PID_DFL_R.D[0]=0;
	PID_DFL_R.D[1]=0;
	PID_DFL_R.D[2]=0;
	PID_DFL_R.Kp=4;
	PID_DFL_R.Ki=4;
	PID_DFL_R.Kd=3;
	PID_DFL_R.Ts=1;
	PID_DFL_R.error[0]=0;
	PID_DFL_R.error[1]=0;
	PID_DFL_R.error[2]=0;
	PID_DFL_R.pid_value[0]=0;
	PID_DFL_R.pid_value[1]=0;
	PID_DFL_R.pid_value[2]=0;
	PID_DFL_R.set_point=16;

	//BW PID WALL CENTERING DEFLECT RIGHT RULE
	PID_DFL_L.P[0]=0;
	PID_DFL_L.P[1]=0;
	PID_DFL_L.P[2]=0;
	PID_DFL_L.I[0]=0;
	PID_DFL_L.I[1]=0;
	PID_DFL_L.I[2]=0;
	PID_DFL_L.D[0]=0;
	PID_DFL_L.D[1]=0;
	PID_DFL_L.D[2]=0;
	PID_DFL_L.Kp=1;
	PID_DFL_L.Ki=0;
	PID_DFL_L.Kd=0;
	PID_DFL_L.Ts=1;
	PID_DFL_L.error[0]=0;
	PID_DFL_L.error[1]=0;
	PID_DFL_L.error[2]=0;
	PID_DFL_L.pid_value[0]=0;
	PID_DFL_L.pid_value[1]=0;
	PID_DFL_L.pid_value[2]=0;
	PID_DFL_L.set_point=16;
	delay_ms(15);
}

void BW_PID_Init_Room(void)
{
	Fuzzy_FKR_SP = 11;
	CALC_EN = 1;
	RIGHT_COUNTER = 0;
	LEFT_COUNTER = 0;
	speed_cnt = 0;

	//BW PID WALL FOLLOWING RIGHT RULE
	PID_F_R.P[0]=0;
	PID_F_R.P[1]=0;
	PID_F_R.P[2]=0;
	PID_F_R.I[0]=0;
	PID_F_R.I[1]=0;
	PID_F_R.I[2]=0;
	PID_F_R.D[0]=0;
	PID_F_R.D[1]=0;
	PID_F_R.D[2]=0;

	//DEFAULT
	PID_F_R.Kp=3.1;//2.8;//14.7;//17;
	PID_F_R.Ki=2.1;
	PID_F_R.Kd=0;

	PID_F_R.Ts=0.005;

	//===FIX 11/10/16===//
	PID_F_R.set_point_upper=13;
	PID_F_R.set_point_lower=12;
	PID_F_R.set_point=12;

	PID_F_R_OLD.error[0]=PID_F_R.error[0];
	PID_F_R_OLD.error[1]=PID_F_R.error[1];
	PID_F_R_OLD.error[2]=PID_F_R.error[2];
	PID_F_R.error[0]=0;
	PID_F_R.error[1]=0;
	PID_F_R.error[2]=0;
	PID_F_R.pid_value[0]=0;
	PID_F_R.pid_value[1]=0;
	PID_F_R.pid_value[2]=0;
	PID_F_L.P[1]=0;
	PID_F_L.P[2]=0;
	PID_F_L.I[0]=0;
	PID_F_L.I[1]=0;
	PID_F_L.I[2]=0;
	PID_F_L.D[0]=0;
	PID_F_L.D[1]=0;
	PID_F_L.D[2]=0;

	//baterai bintang
	PID_F_L.Kp=3.0;//2.8;//14.7;//17;
	PID_F_L.Ki=2.0;
	PID_F_L.Kd=0;

	PID_F_L.Ts=0.005;

	PID_F_L_OLD.error[0]=PID_F_L.error[0];
	PID_F_L_OLD.error[1]=PID_F_L.error[1];
	PID_F_L_OLD.error[2]=PID_F_L.error[2];
	PID_F_L.error[0]=0;
	PID_F_L.error[1]=0;
	PID_F_L.error[2]=0;

	PID_F_L.pid_value[0]=0;
	PID_F_L.pid_value[1]=0;
	PID_F_L.pid_value[2]=0;

	PID_F_L.set_point_upper=13;
	PID_F_L.set_point_lower=12;
	PID_F_L.set_point=12;

	//BW PID WALL CENTERING DEFLECT RIGHT RULE
	PID_DFL_R.P[0]=0;
	PID_DFL_R.P[1]=0;
	PID_DFL_R.P[2]=0;
	PID_DFL_R.I[0]=0;
	PID_DFL_R.I[1]=0;
	PID_DFL_R.I[2]=0;
	PID_DFL_R.D[0]=0;
	PID_DFL_R.D[1]=0;
	PID_DFL_R.D[2]=0;
	PID_DFL_R.Kp=4;
	PID_DFL_R.Ki=4;
	PID_DFL_R.Kd=3;
	PID_DFL_R.Ts=1;
	PID_DFL_R.error[0]=0;
	PID_DFL_R.error[1]=0;
	PID_DFL_R.error[2]=0;
	PID_DFL_R.pid_value[0]=0;
	PID_DFL_R.pid_value[1]=0;
	PID_DFL_R.pid_value[2]=0;
	PID_DFL_R.set_point=16;

	//BW PID WALL CENTERING DEFLECT RIGHT RULE
	PID_DFL_L.P[0]=0;
	PID_DFL_L.P[1]=0;
	PID_DFL_L.P[2]=0;
	PID_DFL_L.I[0]=0;
	PID_DFL_L.I[1]=0;
	PID_DFL_L.I[2]=0;
	PID_DFL_L.D[0]=0;
	PID_DFL_L.D[1]=0;
	PID_DFL_L.D[2]=0;
	PID_DFL_L.Kp=1;
	PID_DFL_L.Ki=0;
	PID_DFL_L.Kd=0;
	PID_DFL_L.Ts=1;
	PID_DFL_L.error[0]=0;
	PID_DFL_L.error[1]=0;
	PID_DFL_L.error[2]=0;
	PID_DFL_L.pid_value[0]=0;
	PID_DFL_L.pid_value[1]=0;
	PID_DFL_L.pid_value[2]=0;
	PID_DFL_L.set_point=16;
}

void BW_PID_Init_Furniture(void)
{
	Fuzzy_FKR_SP = 10;
	CALC_EN = 1;
	RIGHT_COUNTER = 0;
	LEFT_COUNTER = 0;
	speed_cnt = 0;
	//BW PID WALL FOLLOWING RIGHT RULE
	PID_F_R.P[0]=0;
	PID_F_R.P[1]=0;
	PID_F_R.P[2]=0;
	PID_F_R.I[0]=0;
	PID_F_R.I[1]=0;
	PID_F_R.I[2]=0;
	PID_F_R.D[0]=0;
	PID_F_R.D[1]=0;
	PID_F_R.D[2]=0;

	//DEFAULT
	PID_F_R.Kp=3.2;//6.5;
	PID_F_R.Ki=2.1;
	PID_F_R.Kd=0;

//	PID_F_R.Kp=2;
//	PID_F_R.Ki=2;
//	PID_F_R.Kd=1;

	PID_F_R.Ts=0.005;

	//NEW METHOD
//	PID_F_R.Kp=6;
//	PID_F_R.Ki=1;
//	PID_F_R.Kd=1;
//	PID_F_R.Ts=1;

	//===FIX 11/10/16===//
	PID_F_R.set_point_upper=12;
	PID_F_R.set_point_lower=11;
	PID_F_R.set_point=11;

//	PID_F_R.set_point_upper=20;
//	PID_F_R.set_point_lower=16;
//	PID_F_R.set_point=16;
	//==================//
//	PID_F_R.set_point_upper=20;
//	PID_F_R.set_point_lower=16;
//	PID_F_R.set_point=16;

/*	PID_F_R.error[0]=0;
	PID_F_R.error[1]=0;
	PID_F_R.error[2]=0;*/
	PID_F_R_OLD.error[0]=PID_F_R.error[0];
	PID_F_R_OLD.error[1]=PID_F_R.error[1];
	PID_F_R_OLD.error[2]=PID_F_R.error[2];
	PID_F_R.error[0]=0;
	PID_F_R.error[1]=0;
	PID_F_R.error[2]=0;
	PID_F_R.pid_value[0]=0;
	PID_F_R.pid_value[1]=0;
	PID_F_R.pid_value[2]=0;
	PID_F_L.P[1]=0;
	PID_F_L.P[2]=0;
	PID_F_L.I[0]=0;
	PID_F_L.I[1]=0;
	PID_F_L.I[2]=0;
	PID_F_L.D[0]=0;
	PID_F_L.D[1]=0;
	PID_F_L.D[2]=0;

	PID_F_L.Kp=3.2;//6.5;
	PID_F_L.Ki=1.7;
	PID_F_L.Kd=0;
	PID_F_L.Ts=0.005;

/*	PID_F_L.error[0]=0;
	PID_F_L.error[1]=0;
	PID_F_L.error[2]=0;*/

	PID_F_L_OLD.error[0]=PID_F_L.error[0];
	PID_F_L_OLD.error[1]=PID_F_L.error[1];
	PID_F_L_OLD.error[2]=PID_F_L.error[2];
	PID_F_L.error[0]=0;
	PID_F_L.error[1]=0;
	PID_F_L.error[2]=0;

	PID_F_L.pid_value[0]=0;
	PID_F_L.pid_value[1]=0;
	PID_F_L.pid_value[2]=0;

	PID_F_L.set_point_upper=12;
	PID_F_L.set_point=11;
	PID_F_L.set_point_lower=11;

	//BW PID WALL CENTERING DEFLECT RIGHT RULE
	PID_DFL_R.P[0]=0;
	PID_DFL_R.P[1]=0;
	PID_DFL_R.P[2]=0;
	PID_DFL_R.I[0]=0;
	PID_DFL_R.I[1]=0;
	PID_DFL_R.I[2]=0;
	PID_DFL_R.D[0]=0;
	PID_DFL_R.D[1]=0;
	PID_DFL_R.D[2]=0;
	PID_DFL_R.Kp=4;
	PID_DFL_R.Ki=4;
	PID_DFL_R.Kd=3;
	PID_DFL_R.Ts=1;
	PID_DFL_R.error[0]=0;
	PID_DFL_R.error[1]=0;
	PID_DFL_R.error[2]=0;
	PID_DFL_R.pid_value[0]=0;
	PID_DFL_R.pid_value[1]=0;
	PID_DFL_R.pid_value[2]=0;
	PID_DFL_R.set_point=16;

	//BW PID WALL CENTERING DEFLECT RIGHT RULE
	PID_DFL_L.P[0]=0;
	PID_DFL_L.P[1]=0;
	PID_DFL_L.P[2]=0;
	PID_DFL_L.I[0]=0;
	PID_DFL_L.I[1]=0;
	PID_DFL_L.I[2]=0;
	PID_DFL_L.D[0]=0;
	PID_DFL_L.D[1]=0;
	PID_DFL_L.D[2]=0;
	PID_DFL_L.Kp=1;
	PID_DFL_L.Ki=0;
	PID_DFL_L.Kd=0;
	PID_DFL_L.Ts=1;
	PID_DFL_L.error[0]=0;
	PID_DFL_L.error[1]=0;
	PID_DFL_L.error[2]=0;
	PID_DFL_L.pid_value[0]=0;
	PID_DFL_L.pid_value[1]=0;
	PID_DFL_L.pid_value[2]=0;
	PID_DFL_L.set_point=16;
}

void BW_PID_Init_Obs(void)
{
	Fuzzy_FKR_SP = 17;
	CAT_DETECTOR=CAT_DIACTIVATED;
	CALC_EN = 1;
	RIGHT_COUNTER = 0;
	LEFT_COUNTER = 0;
	speed_cnt = 0;

	//BW PID WALL FOLLOWING RIGHT RULE
	PID_F_R.P[0]=0;
	PID_F_R.P[1]=0;
	PID_F_R.P[2]=0;
	PID_F_R.I[0]=0;
	PID_F_R.I[1]=0;
	PID_F_R.I[2]=0;
	PID_F_R.D[0]=0;
	PID_F_R.D[1]=0;
	PID_F_R.D[2]=0;

	//fix
	PID_F_R.Kp=3.0;//3.2;//2.1;//2.6;//2.5;//15.3;//15;
	PID_F_R.Ki=2.5;//2.0;//2.1;
	PID_F_R.Kd=0;

	PID_F_R.Ts=0.005;

	//===FIX 11/10/16===//
	PID_F_R.set_point_upper=17;//17
	PID_F_R.set_point_lower=15;//15
	PID_F_R.set_point=15;//15

	PID_F_R_OLD.error[0]=PID_F_R.error[0];
	PID_F_R_OLD.error[1]=PID_F_R.error[1];
	PID_F_R_OLD.error[2]=PID_F_R.error[2];
	PID_F_R.error[0]=0;
	PID_F_R.error[1]=0;
	PID_F_R.error[2]=0;
	PID_F_R.pid_value[0]=0;
	PID_F_R.pid_value[1]=0;
	PID_F_R.pid_value[2]=0;
	PID_F_L.P[1]=0;
	PID_F_L.P[2]=0;
	PID_F_L.I[0]=0;
	PID_F_L.I[1]=0;
	PID_F_L.I[2]=0;
	PID_F_L.D[0]=0;
	PID_F_L.D[1]=0;
	PID_F_L.D[2]=0;

//	fix baterai bintang
	PID_F_L.Kp=3.0;//3.0;//2.1;//2.6;//2.5;//15.3;//15;
	PID_F_L.Ki=2.5;//1.8;//2.1;
	PID_F_L.Kd=0;

	PID_F_L.Ts=0.005;

	PID_F_L_OLD.error[0]=PID_F_L.error[0];
	PID_F_L_OLD.error[1]=PID_F_L.error[1];
	PID_F_L_OLD.error[2]=PID_F_L.error[2];
	PID_F_L.error[0]=0;
	PID_F_L.error[1]=0;
	PID_F_L.error[2]=0;

	PID_F_L.pid_value[0]=0;
	PID_F_L.pid_value[1]=0;
	PID_F_L.pid_value[2]=0;

	PID_F_L.set_point_upper=17;//17
	PID_F_L.set_point_lower=15;//15
	PID_F_L.set_point=15;//15

}

void BW_PID_Init_Obs_Far(void)
{

	Fuzzy_FKR_SP = 17;
	CAT_DETECTOR=CAT_DIACTIVATED;
	CALC_EN = 1;
	RIGHT_COUNTER = 0;
	LEFT_COUNTER = 0;
	speed_cnt = 0;

	//BW PID WALL FOLLOWING RIGHT RULE
	PID_F_R.P[0]=0;
	PID_F_R.P[1]=0;
	PID_F_R.P[2]=0;
	PID_F_R.I[0]=0;
	PID_F_R.I[1]=0;
	PID_F_R.I[2]=0;
	PID_F_R.D[0]=0;
	PID_F_R.D[1]=0;
	PID_F_R.D[2]=0;

	//fix
	PID_F_R.Kp=2.5;//3.2;//2.1;//2.6;//2.5;//15.3;//15;
	PID_F_R.Ki=1.8;//2.0;//2.1;
	PID_F_R.Kd=0;

	PID_F_R.Ts=0.005;

	//===FIX 11/10/16===//
	PID_F_R.set_point_upper=19;
	PID_F_R.set_point_lower=18;
	PID_F_R.set_point=18;

	PID_F_R_OLD.error[0]=PID_F_R.error[0];
	PID_F_R_OLD.error[1]=PID_F_R.error[1];
	PID_F_R_OLD.error[2]=PID_F_R.error[2];
	PID_F_R.error[0]=0;
	PID_F_R.error[1]=0;
	PID_F_R.error[2]=0;
	PID_F_R.pid_value[0]=0;
	PID_F_R.pid_value[1]=0;
	PID_F_R.pid_value[2]=0;
	PID_F_L.P[1]=0;
	PID_F_L.P[2]=0;
	PID_F_L.I[0]=0;
	PID_F_L.I[1]=0;
	PID_F_L.I[2]=0;
	PID_F_L.D[0]=0;
	PID_F_L.D[1]=0;
	PID_F_L.D[2]=0;

//	fix baterai bintang
	PID_F_L.Kp=2.3;//3.0;//2.1;//2.6;//2.5;//15.3;//15;
	PID_F_L.Ki=1.7;//1.8;//2.1;
	PID_F_L.Kd=0;

	PID_F_L.Ts=0.005;

	PID_F_L_OLD.error[0]=PID_F_L.error[0];
	PID_F_L_OLD.error[1]=PID_F_L.error[1];
	PID_F_L_OLD.error[2]=PID_F_L.error[2];
	PID_F_L.error[0]=0;
	PID_F_L.error[1]=0;
	PID_F_L.error[2]=0;

	PID_F_L.pid_value[0]=0;
	PID_F_L.pid_value[1]=0;
	PID_F_L.pid_value[2]=0;

	PID_F_L.set_point_upper=19;
	PID_F_L.set_point_lower=18;
	PID_F_L.set_point=18;
}


/*
 * func      : void PID_Calc_LeftRule(void)
 * brief     : PID Controller Calculations
 * param     : N/A
 * Written By: Ryan
 * Revised By: Reyhan
 * Ver       : 1
 * Programmer's Note: PID Formula rewritten with guidance from KRPAI Senior, Desta.
 * 					  This function should be called everytime PID function executed.
 *
 * Rev. Notes :	Function Rewritten for decreasing sensitivity, which reduce oscilliation
 *				and increasing movement speed.
 */
void PID_Calc_RightRule(void)
{
	PID_F_R.pid_value[2]=PID_F_R.pid_value[1];
	PID_F_R.pid_value[1]=PID_F_R.pid_value[0];

	PID_F_R.error[2]=PID_F_R.error[1];
	PID_F_R.error[1]=PID_F_R.error[0];

	if ((Ping[PING_ASKEW_RIGHT] >= (PID_F_R.set_point)) && (Ping[PING_ASKEW_RIGHT]) <= PID_F_R.set_point_upper) {PID_F_R.error[0]=0;}
	else PID_F_R.error[0] = Ping[PING_ASKEW_RIGHT] - PID_F_R.set_point;


	if(PID_F_R.error[0] < 0)
	{
		PID_F_R.error[0]*=1.3;
	}

	PID_F_R.P[2]= PID_F_R.error[0]/*-PID_F_R.error[2]*/;
	PID_F_R.P[1]= PID_F_R.Kp;
	PID_F_R.P[0]= PID_F_R.P[1]*PID_F_R.P[2]; //Proportional Controller

	PID_F_R.I[2]= PID_F_R.Ki*PID_F_R.Ts;
	PID_F_R.I[1]= PID_F_R.error[0]+PID_F_R.error[2];
	PID_F_R.I[0]= PID_F_R.I[2]*PID_F_R.I[1]; //Integral Controller

//	PID_F_R.D[2]= (PID_F_R.Kd/PID_F_R.Ts)/100;
//	PID_F_R.D[1]= PID_F_R.error[0]-PID_F_R.error[2];
//	PID_F_R.D[0]= PID_F_R.D[2]*PID_F_R.D[1]; //Derivative Controller

	PID_F_R.pid_value[0]= PID_F_R.P[0] + PID_F_R.I[0];// + PID_F_R.D[0];
	PID_F_R.pid_value[0]=fabsf(PID_F_R.pid_value[0]);
}

void PID_Calc_RightObs(void)
{
	PID_F_R.pid_value[2]=PID_F_R.pid_value[1];
	PID_F_R.pid_value[1]=PID_F_R.pid_value[0];

	PID_F_R.error[2]=PID_F_R.error[1];
	PID_F_R.error[1]=PID_F_R.error[0];

	if ((Ping[PING_ASKEW_RIGHT] >= (PID_F_R.set_point)) && (Ping[PING_ASKEW_RIGHT]) <= PID_F_R.set_point_upper) {PID_F_R.error[0]=0;}
	else PID_F_R.error[0] = Ping[PING_ASKEW_RIGHT] - PID_F_R.set_point;


	if(PID_F_R.error[0] < 0)
	{
		PID_F_R.error[0]*=1.3;
	}

	PID_F_R.P[2]= PID_F_R.error[0]/*-PID_F_R.error[2]*/;
	PID_F_R.P[1]= PID_F_R.Kp;
	PID_F_R.P[0]= PID_F_R.P[1]*PID_F_R.P[2]; //Proportional Controller

	PID_F_R.I[2]= PID_F_R.Ki*PID_F_R.Ts;
	PID_F_R.I[1]= PID_F_R.error[0]+PID_F_R.error[2];
	PID_F_R.I[0]= PID_F_R.I[2]*PID_F_R.I[1]; //Integral Controller

//	PID_F_R.D[2]= (PID_F_R.Kd/PID_F_R.Ts)/100;
//	PID_F_R.D[1]= PID_F_R.error[0]-PID_F_R.error[2];
//	PID_F_R.D[0]= PID_F_R.D[2]*PID_F_R.D[1]; //Derivative Controller

	PID_F_R.pid_value[0]= PID_F_R.P[0] + PID_F_R.I[0];// + PID_F_R.D[0];
	PID_F_R.pid_value[0]=fabsf(PID_F_R.pid_value[0]);

}



/*
 * func      : void PID_Calc_Reverse(void)
 * brief     : PID Controller Calculations
 * param     : N/A
 * Written By: Hafidin
 * Ver       : 1
 * Programmer's Note: PID Formula rewritten with guidance from KRPAI Senior, Desta.
 * 					  This function should be called everytime PID function executed
 */
void PID_Calc_RightRule_Reverse(void)
{
	PID_F_R.pid_value[2]=PID_F_R.pid_value[1];
	PID_F_R.pid_value[1]=PID_F_R.pid_value[0];

	PID_F_R.error[2]=PID_F_R.error[1];
	PID_F_R.error[1]=PID_F_R.error[0];

	if ((Ping[PING_REAR_RIGHT] >= (PID_F_R.set_point)) && (Ping[PING_REAR_RIGHT]) <= PID_F_R.set_point_upper) {PID_F_R.error[0]=0;}
	else PID_F_R.error[0] = Ping[PING_REAR_RIGHT] - PID_F_R.set_point;


	if(PID_F_R.error[0] < 0)
	{
		PID_F_R.error[0]*=1.3;
	}

	PID_F_R.P[2]= PID_F_R.error[0]/*-PID_F_R.error[2]*/;
	PID_F_R.P[1]= PID_F_R.Kp;
	PID_F_R.P[0]= PID_F_R.P[1]*PID_F_R.P[2]; //Proportional Controller

	PID_F_R.I[2]= PID_F_R.Ki*PID_F_R.Ts;
	PID_F_R.I[1]= PID_F_R.error[0]+PID_F_R.error[2];
	PID_F_R.I[0]= PID_F_R.I[2]*PID_F_R.I[1]; //Integral Controller

//	PID_F_R.D[2]= (PID_F_R.Kd/PID_F_R.Ts)/100;
//	PID_F_R.D[1]= PID_F_R.error[0]-PID_F_R.error[2];
//	PID_F_R.D[0]= PID_F_R.D[2]*PID_F_R.D[1]; //Derivative Controller

	PID_F_R.pid_value[0]= PID_F_R.P[0] + PID_F_R.I[0];// + PID_F_R.D[0];
	PID_F_R.pid_value[0]=fabsf(PID_F_R.pid_value[0]);
}

/*
 * PID FOLLOW LEFT RULE
 */

/*
 * func      : void PID_Calc_LeftRule(void)
 * brief     : PID Controller Calculations
 * param     : N/A
 * Written By: Ryan
 * Revised By: Reyhan
 * Ver       : 1
 * Programmer's Note: PID Formula rewritten with guidance from KRPAI Senior, Desta.
 * 					  This function should be called everytime PID function executed.
 *
 * Rev. Notes :	Function Rewritten for decreasing sensitivity, which reduce oscilliation
 * 				and increasing movement speed.
 */
void PID_Calc_LeftRule(void)
{
	PID_F_L.pid_value[2]=PID_F_L.pid_value[1];
	PID_F_L.pid_value[1]=PID_F_L.pid_value[0];

	PID_F_L.error[2]=PID_F_L.error[1];
	PID_F_L.error[1]=PID_F_L.error[0];

	if ((Ping[PING_ASKEW_LEFT] <= (PID_F_L.set_point_upper)) && (Ping[PING_ASKEW_LEFT]) >= PID_F_L.set_point){PID_F_L.error[0]=0;}
	else PID_F_L.error[0] = Ping[PING_ASKEW_LEFT] - PID_F_L.set_point;

	if(PID_F_L.error[0] < 0)
	{
		PID_F_L.error[0]*=1.3;
	}

	PID_F_L.P[2]= PID_F_L.error[0]/*-PID_F_L.error[2]*/;
	PID_F_L.P[1]= PID_F_L.Kp;
	PID_F_L.P[0]= PID_F_L.P[1]*PID_F_L.P[2]; //Proportional Controller

	PID_F_L.I[2]= PID_F_L.Ki*PID_F_L.Ts;
	PID_F_L.I[1]= PID_F_L.error[0]+PID_F_L.error[2];
	PID_F_L.I[0]= PID_F_L.I[2]*PID_F_L.I[1]; //Integral Controller

//	PID_F_L.D[2]= (PID_F_L.Kd/PID_F_L.Ts)/100;
//	PID_F_L.D[1]= PID_F_L.error[0]-PID_F_L.error[2];
//	PID_F_L.D[0]= PID_F_L.D[2]*PID_F_L.D[1]; //Derivative Controller

	PID_F_L.pid_value[0]= PID_F_L.P[0] + PID_F_L.I[0];// + PID_F_L.D[0];
	PID_F_L.pid_value[0]=fabsf(PID_F_L.pid_value[0]);
}

void PID_Calc_LeftObs(void)
{

	PID_F_L.pid_value[2]=PID_F_L.pid_value[1];
	PID_F_L.pid_value[1]=PID_F_L.pid_value[0];

	PID_F_L.error[2]=PID_F_L.error[1];
	PID_F_L.error[1]=PID_F_L.error[0];

	if ((Ping[PING_ASKEW_LEFT] <= (PID_F_L.set_point_upper)) && (Ping[PING_ASKEW_LEFT]) >= PID_F_L.set_point){PID_F_L.error[0]=0;}
	else PID_F_L.error[0] = Ping[PING_ASKEW_LEFT] - PID_F_L.set_point;

	if(PID_F_L.error[0] < 0)
	{
		PID_F_L.error[0]*=1.3;
	}

	PID_F_L.P[2]= PID_F_L.error[0]/*-PID_F_L.error[2]*/;
	PID_F_L.P[1]= PID_F_L.Kp;
	PID_F_L.P[0]= PID_F_L.P[1]*PID_F_L.P[2]; //Proportional Controller

	PID_F_L.I[2]= PID_F_L.Ki*PID_F_L.Ts;
	PID_F_L.I[1]= PID_F_L.error[0]+PID_F_L.error[2];
	PID_F_L.I[0]= PID_F_L.I[2]*PID_F_L.I[1]; //Integral Controller

//	PID_F_L.D[2]= (PID_F_L.Kd/PID_F_L.Ts)/100;
//	PID_F_L.D[1]= PID_F_L.error[0]-PID_F_L.error[2];
//	PID_F_L.D[0]= PID_F_L.D[2]*PID_F_L.D[1]; //Derivative Controller

	PID_F_L.pid_value[0]= PID_F_L.P[0] + PID_F_L.I[0];// + PID_F_L.D[0];
	PID_F_L.pid_value[0]=fabsf(PID_F_L.pid_value[0]);
}


/*
 * func      : void PID_Calc_Reverse(void)
 * brief     : PID Controller Calculations
 * param     : N/A
 * Written By: Hafidin
 * Ver       : 1
 * Programmer's Note: PID Formula rewritten with guidance from KRPAI Senior, Desta.
 * 					  This function should be called everytime PID function executed
 */
void PID_Calc_LeftRule_Reverse(void)
{
	PID_F_L.pid_value[2]=PID_F_L.pid_value[1];
	PID_F_L.pid_value[1]=PID_F_L.pid_value[0];

	PID_F_L.error[2]=PID_F_L.error[1];
	PID_F_L.error[1]=PID_F_L.error[0];

	if ((Ping[PING_REAR_LEFT] <= (PID_F_L.set_point_upper)) && (Ping[PING_REAR_LEFT]) >= PID_F_L.set_point){PID_F_L.error[0]=0;}
	else PID_F_L.error[0] = Ping[PING_REAR_LEFT] - PID_F_L.set_point;

	if(PID_F_L.error[0] < 0)
	{
		PID_F_L.error[0]*=1.3;
	}

	PID_F_L.P[2]= PID_F_L.error[0]/*-PID_F_L.error[2]*/;
	PID_F_L.P[1]= PID_F_L.Kp;
	PID_F_L.P[0]= PID_F_L.P[1]*PID_F_L.P[2]; //Proportional Controller

	PID_F_L.I[2]= PID_F_L.Ki*PID_F_L.Ts;
	PID_F_L.I[1]= PID_F_L.error[0]+PID_F_L.error[2];
	PID_F_L.I[0]= PID_F_L.I[2]*PID_F_L.I[1]; //Integral Controller

//	PID_F_L.D[2]= (PID_F_L.Kd/PID_F_L.Ts)/100;
//	PID_F_L.D[1]= PID_F_L.error[0]-PID_F_L.error[2];
//	PID_F_L.D[0]= PID_F_L.D[2]*PID_F_L.D[1]; //Derivative Controller

	PID_F_L.pid_value[0]= PID_F_L.P[0] + PID_F_L.I[0];// + PID_F_L.D[0];
	PID_F_L.pid_value[0]=fabsf(PID_F_L.pid_value[0]);
}

/*	============= PID FOLLOW FLAME ===============
 * func      : void PID_Calc_FlameRule(void)
 * brief     : PID Controller Calculations
 * param     : N/A
 * Written By: Toni
 * Ver       : 1
 * Programmer's Note: PID Formula rewritten with guidance from KRPAI Senior, Desta.
 * 					  This function should be called everytime PID function executed
 */
void PID_Calc_FlameRule(void)
{
	/*
	 * Update Nilai Variable PID & Set-Point Error
	 */
	PID_F_R.pid_value[2]=PID_F_R.pid_value[1];
	PID_F_R.pid_value[1]=PID_F_R.pid_value[0];

	PID_F_R.error[2]=PID_F_R.error[1];
	PID_F_R.error[1]=PID_F_R.error[0];

	if (FlameSenseDigi[0]==PID_F_R.set_point) {PID_F_R.error[0]=0;}
	else if (FlameSenseDigi[0] > PID_F_R.set_point)
		{
			PID_F_R.error[0] = FlameSenseDigi[0] - PID_F_R.set_point;
		}

	else if (FlameSenseDigi[0] < PID_F_R.set_point)
		{
			PID_F_R.error[0] = PID_F_R.set_point - FlameSenseDigi[0];
		}

	/*
	 * PID FORMULA
	 */
	PID_F_R.P[2]= PID_F_R.error[0]-PID_F_R.error[2];
	PID_F_R.P[1]= PID_F_R.Kp;
	PID_F_R.P[0]= PID_F_R.P[1]*PID_F_R.P[2]; //Proportional Controller

	PID_F_R.I[2]= PID_F_R.Ki*PID_F_R.Ts/2;
	PID_F_R.I[1]= PID_F_R.error[0]+(2*PID_F_R.error[1])+PID_F_R.error[2];
	PID_F_R.I[0]= PID_F_R.I[2]*PID_F_R.I[1]; //Integral Controller


	PID_F_R.D[2]= 2*PID_F_R.Kd/PID_F_R.Ts;
	PID_F_R.D[1]= PID_F_R.error[0]-(2*PID_F_R.error[1])+PID_F_R.error[2];
	PID_F_R.D[0]= PID_F_R.D[2]*PID_F_R.D[1]; //Derivative Controller

//	PID_F_R.I= ( (PID_F_R.Ki*PID_F_R.Ts/2)*(PID_F_R.error[0]+(2*PID_F_R.error[1])+PID_F_R.error[2]) );
//	PID_F_R.D= ( (2*PID_F_R.Kd/PID_F_R.Ts)*(PID_F_R.error[0]-(2*PID_F_R.error[1])+PID_F_R.error[2]));

	PID_F_R.pid_value[0]= PID_F_R.pid_value[2] + PID_F_R.P[0] + PID_F_R.I[0] + PID_F_R.D[0];
}


/* func      : void PID_Calculate_RightRule_Interrupt_Init(void)
 * brief     : PID Calculate RightRule Timer Interrupt Initialization
 * retval    : N/A
 * Ver       : 1
 * written By: Toni
 * revise By : Reyhan
 * Programmer's Note: PID Calculate RightRule Initialization using timer 3
 * Revision note :
 */
void PID_Calculate_Rule_Interrupt_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

	TIM_TimeBaseStructure.TIM_Prescaler = 8399;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period = 49;//249;//
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
	TIM_Cmd(TIM3, ENABLE);
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);

    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

/* func      : void TIM3_IRQHandler(void)
 * brief     : PID_Calculate_RightRule Timer Handler
 * retval    : N/A
 * Ver       : 1
 * written By: Toni
 * Revised By: Reyhan
 * Programmer's Note: PID_Calculate_RightRule Handler
 */
void TIM3_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
    {
    	if(FOLLOW_CALC==KANAN)
    	{
    		PID_Calc_RightRule();
    	}
    	else if(FOLLOW_CALC==KANAN_BELAKANG)
    	{
    		PID_Calc_RightRule_Reverse();
    	}
    	else if(FOLLOW_CALC==KANAN_OBS)
    	{
    		PID_Calc_RightObs();
    	}
    	else if(FOLLOW_CALC==KIRI)
    	{
    		PID_Calc_LeftRule();
    	}
    	else if(FOLLOW_CALC==KIRI_BELAKANG)
    	{
    		PID_Calc_LeftRule_Reverse();
    	}
    	else if(FOLLOW_CALC==KIRI_OBS)
    	{
    		PID_Calc_LeftObs();
    	}
    	else if(FOLLOW_CALC==FLAME)
    	{
    		PID_Calc_FlameRule();
    	}
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
    }
}

void Restore_Old_Error_Right(void)
{
	PID_F_R.error[0]=PID_F_R_OLD.error[0];
	PID_F_R.error[1]=PID_F_R_OLD.error[1];
	PID_F_R.error[2]=PID_F_R_OLD.error[2];
}

void Restore_Old_Error_Left(void)
{
	PID_F_L.error[0]=PID_F_L_OLD.error[0];
	PID_F_L.error[1]=PID_F_L_OLD.error[1];
	PID_F_L.error[2]=PID_F_L_OLD.error[2];
}

void Kp_Tuning_R(void)
{
	while(BW_BUTTON_UNCLICKED)
	{
		if(BUTTON_A_CLICKED)
		{
			while(BUTTON_A_CLICKED){};
			PID_F_R.Kp += 0.1;
		}
		if(BUTTON_B_CLICKED)
		{
			while(BUTTON_B_CLICKED){};
			PID_F_R.Kp -= 0.1;
		}

		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"PID_F_R.Kp: %.1f",PID_F_R.Kp);lcd_putstr(lcd);
		delay_ms(100);
	}
}

void Ki_Tuning_R(void)
{
	while(BW_BUTTON_UNCLICKED)
	{
		if(BUTTON_A_CLICKED)
		{
			while(BUTTON_A_CLICKED){};
			PID_F_R.Ki += 0.1;
		}
		if(BUTTON_B_CLICKED)
		{
			while(BUTTON_B_CLICKED){};
			PID_F_R.Ki -= 0.1;
		}

		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"PID_F_R.Ki: %.1f",PID_F_R.Ki);lcd_putstr(lcd);
		delay_ms(100);
	}
}

void Kd_Tuning_R(void)
{
	while(BW_BUTTON_UNCLICKED)
	{
		if(BUTTON_A_CLICKED)
		{
			BW_Buzz(2);
			while(BUTTON_A_CLICKED){};
			PID_F_R.Kd += 0.1;
		}
		if(BUTTON_B_CLICKED)
		{
			BW_Buzz(1);
			while(BUTTON_B_CLICKED){};
			PID_F_R.Kd -= 0.1;
		}

		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"PID_F_R.Kd: %.1f",PID_F_R.Kd);lcd_putstr(lcd);
		delay_ms(100);
	}
}

void Kp_Tuning_L(void)
{

	while(BW_BUTTON_UNCLICKED)
	{
		if(BUTTON_A_CLICKED)
		{
			BW_Buzz(2);
			while(BUTTON_A_CLICKED){};
			PID_F_L.Kp+=0.1;
		}
		if(BUTTON_B_CLICKED)
		{
			BW_Buzz(1);
			while(BUTTON_B_CLICKED){};
			PID_F_L.Kp-=0.1;
		}

		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"PID_F_L.Kp: %.2f",PID_F_L.Kp);lcd_putstr(lcd);
		delay_ms(100);
	}

}

void Ki_Tuning_L(void)
{

	while(BW_BUTTON_UNCLICKED)
	{
		if(BUTTON_A_CLICKED)
		{
			BW_Buzz(2);
			while(BUTTON_A_CLICKED){};
			PID_F_L.Ki+=0.1;
		}
		if(BUTTON_B_CLICKED)
		{
			BW_Buzz(1);
			while(BUTTON_B_CLICKED){};
			PID_F_L.Ki-=0.1;
		}

		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"PID_F_L.Ki: %.2f",PID_F_L.Ki);lcd_putstr(lcd);
		delay_ms(100);
	}
}

void Kd_Tuning_L(void)
{

	while(BW_BUTTON_UNCLICKED)
	{
		if(BUTTON_A_CLICKED)
		{
			BW_Buzz(2);
			while(BUTTON_A_CLICKED){};
			PID_F_L.Kd+=0.1;
		}
		if(BUTTON_B_CLICKED)
		{
			BW_Buzz(1);
			while(BUTTON_B_CLICKED){};
			PID_F_L.Kd-=0.1;
		}

		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"PID_F_L.Kd: %.2f",PID_F_L.Kd);lcd_putstr(lcd);
		delay_ms(100);
	}

}


void Kp_Tuning_R_Obs(void){
	while(BW_BUTTON_UNCLICKED)
		{
			if(BUTTON_A_CLICKED)
			{
				BW_Buzz(2);
				while(BUTTON_A_CLICKED){};
				PID_F_R.Kp+=0.1;
			}
			if(BUTTON_B_CLICKED)
			{
				BW_Buzz(1);
				while(BUTTON_B_CLICKED){};
				PID_F_R.Kp-=0.1;
			}

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"PID_F_R.Kp: %.2f",PID_F_R.Kp);lcd_putstr(lcd);
			delay_ms(100);
		}
}

void Ki_Tuning_R_Obs(void){
	while(BW_BUTTON_UNCLICKED)
		{
			if(BUTTON_A_CLICKED)
			{
				BW_Buzz(2);
				while(BUTTON_A_CLICKED){};
				PID_F_R.Ki+=0.1;
			}
			if(BUTTON_B_CLICKED)
			{
				BW_Buzz(1);
				while(BUTTON_B_CLICKED){};
				PID_F_R.Ki-=0.1;
			}

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"PID_F_R.Ki: %.2f",PID_F_R.Ki);lcd_putstr(lcd);
			delay_ms(100);
		}
}

void Kd_Tuning_R_Obs(void){
	while(BW_BUTTON_UNCLICKED)
		{
			if(BUTTON_A_CLICKED)
			{
				BW_Buzz(2);
				while(BUTTON_A_CLICKED){};
				PID_F_R.Kd+=0.1;
			}
			if(BUTTON_B_CLICKED)
			{
				BW_Buzz(1);
				while(BUTTON_B_CLICKED){};
				PID_F_R.Kd-=0.1;
			}

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"PID_F_R.Kd: %.2f",PID_F_R.Kd);lcd_putstr(lcd);
			delay_ms(100);
		}
}
void Kp_Tuning_L_Obs(void){
	while(BW_BUTTON_UNCLICKED)
		{
			if(BUTTON_A_CLICKED)
			{
				BW_Buzz(2);
				while(BUTTON_A_CLICKED){};
				PID_F_L.Kp+=0.1;
			}
			if(BUTTON_B_CLICKED)
			{
				BW_Buzz(1);
				while(BUTTON_B_CLICKED){};
				PID_F_L.Kp-=0.1;
			}

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"PID_F_L.Kp: %.2f",PID_F_L.Kp);lcd_putstr(lcd);
			delay_ms(100);
		}
}

void Ki_Tuning_L_Obs(void){
	while(BW_BUTTON_UNCLICKED)
		{
			if(BUTTON_A_CLICKED)
			{
				BW_Buzz(2);
				while(BUTTON_A_CLICKED){};
				PID_F_L.Ki+=0.1;
			}
			if(BUTTON_B_CLICKED)
			{
				BW_Buzz(1);
				while(BUTTON_B_CLICKED){};
				PID_F_L.Ki-=0.1;
			}

			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"PID_F_L.Ki: %.2f",PID_F_L.Ki);lcd_putstr(lcd);
			delay_ms(100);
		}
}


