/*========================================================================================
								   PROJECT BW 2.21 Ver.1.0
								  BW Hydro Extinguisher Library
==============================================================================================*/
#ifndef BW_GRIPPER_2021_H
#define BW_GRIPPER_2021_H

#include "main.h"

extern int LOW_LEVEL;
extern int MEDIUM_LEVEL;
extern int HIGH_LEVEL;

void DynaGrip (int Degree1, int Degree2);
void Grip( int Dg1, int Dg2, int movement);
void Lift_Grip(int movement);
void Close_Grip(int movement);
void Down_Grip(int movement);
void Open_Grip(int movement);

void Aktuator_Monitor(void);
void Grippler_Trial_Button(void);

#endif
