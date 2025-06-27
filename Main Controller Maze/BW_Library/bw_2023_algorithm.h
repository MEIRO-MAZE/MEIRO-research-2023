/*==============================================================================================
								   PROJECT BW 2021 Ver.1.0
								     BW ALGORITHM LIBRARY
===============================================================================================*/

#ifndef BW_2021_ALGORITHM_H
#define BW_2021_ALGORITHM_H

#include "main.h"

//isi variable
extern unsigned int NORTH_UP;
extern unsigned int NORTH_LOW;
extern unsigned int SOUTH_UP;
extern unsigned int SOUTH_LOW;
extern unsigned int EAST_UP;
extern unsigned int EAST_LOW;
extern unsigned int WEST_UP;
extern unsigned int WEST_LOW;
extern unsigned int NORTH;
extern unsigned int SOUTH;
extern unsigned int EAST;
extern unsigned int WEST;


void BW_Test_Menu(void);
void Menu_Normal(void);
void Menu_Obstaicle(void);
void Menu_Umum(void);
void BW_Algorithm2_2021(void);
void BW_Algorithm1_2021(void);

void TRIAL1_2021(void);
void TRIAL2_2021(void);
void SESI_2(void);

void Nav_Home_To_1(void);
void Nav_Home_To_2(void);
void Nav_1_To_2(void);
void Nav_1_To_Home(void);
void Nav_2_To_1(void);
void Nav_2_To_home(void);

void H_Room_2021(void);
void H_Room_2(void);

void BW_Trial_Grip(void);

void Sensor_Menu(void);
void H_Room1_2021(void);
void BW_FireFight_2021(void);

void BW_FollowCounter_Right(int limit);
void PID_BW_FollowCounter_Right(void);
void BW_FollowCounter_Left(int limit);
void PID_BW_FollowCounter_Left(void);

void BW_FollowCounter_Left_Obs(int limit);
void PID_BW_FollowCounter_Left_Obs(void);
void BW_FollowCounter_Right_Obs(int limit);
void PID_BW_FollowCounter_Right_Obs(void);

void PID_BW_FollowCarpet_Left_Obs(unsigned int CARPET_CODE, unsigned int FOLLOW_MODE);
void PID_BW_FollowCarpet_Right_Obs(unsigned int CARPET_CODE, unsigned int FOLLOW_MODE);
void BW_FollowCarpet_left_Obs(int CARPET_CODE, int FOLLOW_MODE);
void BW_FollowCarpet_Right_Obs(int CARPET_CODE, int FOLLOW_MODE);

void BW_Start_Compas_Correction(void);
void BW_Mode_2(void);

void BW_FollowCarpet_Left_Straight(int CARPET_CODE, int FOLLOW_MODE);
void PID_BWFollowCarpet_Left_Straight(unsigned int CARPET_CODE, unsigned int FOLLOW_MODE);

#endif
