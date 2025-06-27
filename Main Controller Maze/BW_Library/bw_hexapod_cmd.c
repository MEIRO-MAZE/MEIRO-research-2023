/*==============================================================================================
								  PROJECT BW Ver.1.0
							BW HEXAPOD COMMAND LIBRARY
==============================================================================================*/

//USER DEFINED LIBRARIES
#include "bw_hexapod_cmd.h"

/*****************************************************
Project   : BW* Servo Controller / Hexapod Gait Generator
Version   : 2.0
Year      : 2015
Date      :
Author    : Ryan
University: University of Brawijaya
Department: Electrical Engineering Department, Engineering Faculty
Division  : Legged Fire-Fighting Division (KRPAI)
Comments  : *Dreams/aspirations, in Japanese language

Board Type: STM32F4 Discovery Board
Chip      : STM32F407VG
*****************************************************/


//HEXAPOD GAIT MODE PARAMETER
const int STATIC_LOW_CLEARANCE  = 0;
const int STATIC_MED_CLEARANCE  = 1;
const int STATIC_HIGH_CLEARANCE = 2;
const int SEARCH_FIRE           = 3;
const int FORWARD 				= 4;
const int BACKWARD 				= 5;
const int ROTATE_RIGHT 			= 6;
const int ROTATE_LEFT 			= 7;
const int CURVE_RIGHT 			= 8;
const int CURVE_LEFT 			= 9;
const int ASKEW_RIGHT 			= 10;
const int ASKEW_LEFT 			= 11;
const int FWD_RIPPLE			= 12;
const int FWD_WAVE				= 13;

uint32_t CCR1_Val;
uint32_t CCR2_Val;
uint32_t CCR3_Val;

