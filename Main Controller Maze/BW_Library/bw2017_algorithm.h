/*==============================================================================================
								   PROJECT BW 2017 Ver.1.0
								     BW ALGORITHM LIBRARY
===============================================================================================*/


#ifndef BW2016_ALGORITHM_H
#define BW2016_ALGORITHM_H

#include "main.h"

/*==============================================================================================
							LEGACY FEATURES FROM BW Ver.1.0
===============================================================================================*/

/*
 * BW FOLLOW CARPET COMMAND CODE
 */
#define NORMAL 	1
#define INVERSE 2

/* BW SCAN FLAME FLAG
 *
 */
#define INACTIVE 0
#define SCAN_LEFT 1
#define SCAN_RIGHT 2
#define NO_WALL_PARAM 3


#define UVSTATE_ACTIVE 		0
#define UVSTATE_INACTIVE 	1

#define UVLOCK_ACTIVE 		1
#define UVLOCK_INACTIVE 	0

/*
 * BW FLAME FOLLOWER VARIABLES
 */
extern unsigned int FlameSense[2];
extern unsigned int FollowFlame_Flag;
extern unsigned int FlameTrack_Flag;
extern unsigned int FlameScan_Flag;
extern unsigned int FlameExtinguish_Flag;
extern unsigned int FlameApproach_Flag;

#define FLAG_INACTIVE 0
#define FLAG_ACTIVE   1


/*
 * BW PING))) RECEIVER VARIABLES
 */
//extern unsigned int Ping[10];
extern unsigned int usart_count;
extern unsigned int FRONT_THRESHOLD;
extern unsigned int REAR_THRESHOLD;


//BW ROOM AND CORRIDOR VARIABLES
extern unsigned int BW_LOCATION[];
extern unsigned int LOCATION_CORRIDOR;
extern unsigned int LOCATION_ROOM;
#define PRESENT_LOC 0
#define LAST_LOC 1

extern unsigned int TANDA_FOLLOW[];
extern unsigned int FOLLOW_KIRI;
extern unsigned int FOLLOW_KANAN;
extern int BLALA;

//UV TRON CONDITION
extern unsigned int FIRE;
#define FIRE_DETECTED 0
#define NO_FIRE 1

//ADDITIONAL FLAME SENSOR
extern unsigned int FLAME_SIDE;

//INFRARED PROXIMITY VARIABLES
extern int INFRARED[];
//#define MID_LEFT 2
//#define MID_RIGHT 3
//#define IR_FRONT_LEFT    0
//#define IR_FRONT_RIGHT   1
//#define IR_MID_LEFT      2
//#define IR_MID_RIGHT     3
//#define IR_FRONT_SUB     5

/*
 *  BW BUMPER VARIABLES;
 */
extern unsigned int BUMPER[];

/*
 * BW FOLLOW CARPET VARIABLES
 */
//extern unsigned int NORMAL;
//extern unsigned int INVERSE;
#define NORMAL 1
#define INVERSE 2

/*
 * BW CAT OBSTACLE VARIABLES
 */
extern unsigned int CAT_FOUND[];
#define CAT_PREVIOUS 1
#define CAT_PRESENT  0
extern unsigned int CAT_SHIFT_FOLLOW;
extern unsigned int SHIFT_FOLLOW;
extern unsigned int NO_SHIFT;

extern unsigned int CAT_FLAG;
extern unsigned int CAT_FLAG_A;
extern unsigned int CAT_FLAG_B;
extern unsigned int CAT_FLAG_C;
extern unsigned int CAT_DETECTED;
extern unsigned int CAT_NOT_DETECTED;

extern unsigned int CAT_DETECTOR;
extern unsigned int CAT_ACTIVATED;
extern unsigned int CAT_DIACTIVATED;

//extern unsigned int STAIRS_FLAG;
extern unsigned const int STAIRS_DETECTOR_ACTIVATED;
extern unsigned const int STAIRS_DETECTOR_DEACTIVATED;

/*
 * BW ROOM COUNTER
 */
extern unsigned int ROOM_COUNTER;

/*
 * BW WARZONE FLAG
 */
extern unsigned int WARZONE_FLAG;
extern unsigned int SPECIAL_ZONE_FLAG;

/*
 * BW HOME CIRCLE FLAG
 */
extern unsigned int HOME_CIRCLE_FLAG;
extern unsigned int HOME_CIRCLE_DETECTED;
extern unsigned int HOME_CIRCLE_NOT_DETECTED;

/*
 * BW FOLLOWHOME FLAG
 */
extern unsigned int FOLLOWHOME_FLAG;
extern unsigned int FOLLOWHOME_INACTIVE;
extern unsigned int FOLLOWHOME_ACTIVE;

/*
 * BW CAT OBSTACLE VARIABLES
 */
extern unsigned int CAT_FOUND[];
#define CAT_PREVIOUS 1
#define CAT_PRESENT  0
extern unsigned int CAT_SHIFT_FOLLOW;
extern unsigned int SHIFT_FOLLOW;
extern unsigned int NO_SHIFT;

/*
 * FIRST CAT ENCOUNTER
 */
extern unsigned int FIRST_CAT_ENCOUNTER;
extern unsigned int CAT_NOT_DETECTED;
extern unsigned int CAT_DETECTED;
extern unsigned const int STAIRS_DETECTED;
extern unsigned const int STAIRS_NOT_DETECTED;

//NEW COMMAND DATA
extern unsigned int TCS_CMD_SEND_FRONT;
extern unsigned int TCS_CMD_SEND_MIDDLE;
extern unsigned int TCS_CMD_SEND_CONCLUSION;
extern unsigned int TCS_CMD_SAVE_EEPROM;
extern unsigned int TCS_CMD_SHOW_EEPROM;

/*
 *  NEW COMMAND FOR OPTIMIZATION
 */
extern unsigned int CMD_GET_TCS3200;
extern unsigned int CMD_GET_TRACER;

/*
 * FOLLOWMODE FLAG
 */
extern unsigned int FOLLOWMODE_FLAG;
extern const unsigned int FOLLOW_TRACER_WHITE;
extern const unsigned int FOLLOW_CARPET_ACTIVE;
extern const unsigned int FOLLOW_COLOUR_DISABLE;
extern int FOLLOW_CARPET_MODE;
extern int COLOUR_BUF;
extern int LEFT_FOLLOW_STATE ;
extern int RIGHT_FOLLOW_STATE;
extern int FOLLOW_TRACER_STATE;



//CARPET CODE
extern unsigned int COLOUR_NONE;
extern unsigned int COLOUR_BLACK;
extern unsigned int COLOUR_GRAY;
extern unsigned int COLOUR_WHITE;
extern unsigned int COLOUR_RED;
extern unsigned int COLOUR_BLUE;

/*
 * RETURN COUNTER
 */
extern unsigned int RETURN_COUNTER;

/*
 * BW VARIABLE DOOR
 */
extern unsigned int VARIABLE_DOOR;
extern unsigned int VAR_DOOR_NOT_DETECTED;
extern unsigned int VAR_DOOR_DETECTED;
extern unsigned int VAR_DOOR_SCAN;





/*
 * TRACER DETECTED IN BUMPER HANDLER ROUTINES
 */

extern unsigned int TRACER_IN_BUMPER;
extern unsigned int TRC_BMP_ACTIVE;
extern unsigned int TRC_BMP_INACTIVE;

/*
 * TRACER STATUS VARIABLES
 */
//extern unsigned int TRACER_STAT;
//extern unsigned int TRACER_WHITE;
//extern unsigned int TRACER_BLACK;

extern unsigned int TRACER_STAT;
extern unsigned int TRACER_WHITE;
extern unsigned int TRACER_BLACK;
extern unsigned int TRACER_GRAY;
extern unsigned int TRACER_BREAK;

/*
 *	NAVIGATION MACRO
 */
#define NAV_HALLWAY_SC 	0
#define NAV_ROOM_1A		1
#define NAV_ROOM_1B		2
#define NAV_ROOM_1C		3
#define NAV_ROOM_2A		4
#define NAV_ROOM_2B		5
#define NAV_ROOM_3		6
#define NAV_ROOM_4A		7
#define NAV_ROOM_4B		8

/*
 * ROOM IDENTIFIER VARIABLES
 */
extern unsigned int HOME;

extern unsigned int ROOM[];

extern unsigned int ROOM_1A;
extern unsigned int ROOM_1B;
extern unsigned int ROOM_1C;

extern unsigned int ROOM_2A;
extern unsigned int ROOM_2B;

extern unsigned int ROOM_3;

extern unsigned int ROOM_4A;
extern unsigned int ROOM_4B;

//#define ROOM_1A 1
//#define ROOM_1B 2
//#define ROOM_1C 3
//
//#define ROOM_2A 4
//#define ROOM_2B 5
//
//#define ROOM_3 6
//
//#define ROOM_4A 7
//#define ROOM_4B 8


extern unsigned int HALLWAY_SC;

extern unsigned int ROOM_TYPE;
extern unsigned int NORMAL_ROOM;
extern unsigned int GRAY_ROOM;

extern unsigned int HOME_POS;
extern unsigned int TENGAH;
extern unsigned int POJOK;



/*
 * BW FIRE FIGHTING VARIABLES
 */
extern unsigned int EXTINGUISHED_FIRE;
extern unsigned int FIRE_PUTOFF;


extern unsigned int FLAME_SENSOR[];

/*
 *  BW ROOM COUNTER
 */
extern unsigned int ROOM_COUNTER;

/*
 *  BW EXIT NO FIRE
 */
void Exit_No_Fire(void);
void H_Exit_Room_V1(void);

void BW_Home_Detection_2021(void);
void BW_Home_Start_Right(void);
void BW_Home_Start_Left(void);
void Home_HallwaySC_Detector(void);
void RoomTypeDetector(void);;


/*
 *  BW PID WALL FOLLOWING UNTIL TRACER NEW ALGORITHM
 */
void follow_right_new(void);
void PID_follow_right_new(void);
void curve_left_new(int SPEED, int STEP, volatile float *COMMAND_LOOP);
void curve_right_new(int SPEED, int STEP, volatile float *COMMAND_LOOP);

void FlameSense_PID_Init(void);

void FollowTracer_Right_Reverse(void);



/*
 * BW NAVIGATION FUNCTION PROTOTYPE
 */
void BW_Navi(int STARTING_POINT, int DESTINATION);

//STARTING POINT = HALLWAY SC
void Nav_HallwaySC_To_3(void);
void Nav_HallwaySC_To_3_V3(void);
void Nav_HallwaySC_To_2(void);
void Nav_HallwaySC_To_4B(void);
void Nav_HallwaySC_To_4A(void);
void Nav_HallwaySC_To_1A(int OPTION);
void Nav_HallwaySC_To_1B(void);

//STARTING POINT = 1A
void Nav_1A_To_HallwaySC(void);
void Nav_1A_To_2(void);
void Nav_1A_To_3(void);
void Nav_1A_To_4B(void);
void Nav_1A_To_4A(void);

//STARTING POINT = 1B
void Nav_1B_To_2(void);

//STARTING POINT = 1C
void Nav_1C_To_HallwaySC(void);
void Nav_1C_To_2(void);
void Nav_1C_To_3(void);
void Nav_1C_To_4A(void);
void Nav_1C_To_4B(void);
void Nav_1_To_4(void);

//FUNGSI UNTUK V2
void Nav_1_To_3_V2(void);

//STARTING POINT = 2
void Nav_2_To_HallwaySC(void);
void Nav_2B_To_1BC(void);
void Nav_2_To_1A(void);
void Nav_2_To_1BC(void);
void Nav_2_To_3(void);
void Nav_2_To_4A(void);
void Nav_2_To_4B(void);

//STARTING POINT = 3
void Nav_3_To_HallwaySC(void);
void Nav_2A_To_1BC(void);
void Nav_3_To_1A(void);
void Nav_3_To_1BC(void);
void Nav_3_To_2(void);
void Nav_3_To_4A(void);
void Nav_3_To_4B(void);
void Nav_3_To_4B_V2(void);
void Nav_3_To_4AB(void);


//STARTING POINT = 4A
void Nav_4A_To_HallwaySC(void);
void Nav_4A_To_3(void);
void Nav_4A_To_1A(void);
void Nav_4A_To_2(void);
void Nav_4A_To_2_NEW(void);
void Nav_4A_To_1BC(void);

//STARTING POINT = 4B
void Nav_4B_To_HallwaySC(void);
void Nav_4B_To_1A(void);
void Nav_4B_To_1BC(void);
void Nav_4B_To_2(void);
void Nav_4B_To_2_V2(void);
void Nav_4B_To_3(void);


//TCS3200 SLAVE STATUS CHECK
void TCSlave_Check(void);

int BW_ReturnTrip(void);
void Furniture_Avoider(void);
void Cat_Avoider(void);
void RoomDetector(int ROOM_COUNTER);

void FlameSenseDigi_PID_Init(void);

void BW_FireFight_V2(void);

void UVLock_Refresh(void);
int FlameTracking_Ver3(void);
int FlameTracking_Center(void);
int PID_FlameTracking_Ver3(void);
void BW_FlameFollowDemo_Dynamixel(void);
void Nav_Test_Menu(void);

void H_2021_Algorithm (void);
void H_2021_Algorithm_V1(void);
void H_2021_Algorithm_V2(void);
void H_2021_Algorithm_V3(void);
void H_2021_Room (void);
void H_In_Room_V3(void);
void H_IN_Room (void);
void H_ROOM_1A (void);
void H_ROOM_1BC(void);
void H_ROOM_2(void);
void H_ROOM_3(void);
void H_ROOM_4A(void);
void H_ROOM_4B(void);

//fungsi baru rule 2020 buatan yogi
void H_SESI_1(void);
void H_SESI_2(void);
void H_SESI_3(void);

void BW_FollowTracer_Right_Reverse(void);
void PID_BWFollowTracer_Right_Reverse(void);
void BW_FollowTracer_Left_Reverse(void);
void PID_BWFollowTracer_Left_Reverse(void);
void BWFollowCarpet_Right_Reverse(int CARPET_CODE, int FOLLOW_MODE);
void PID_BWFollowCarpet_Right_Reverse(void);
void BWFollowCarpet_Left_Reverse(int CARPET_CODE, int FOLLOW_MODE);
void PID_BWFollowCarpet_Left_Reverse(void);
void BW_FollowCounter_Right_Reverse(int limit);
void PID_BW_FollowCounter_Right_Reverse(void);
void BW_FollowCounter_Left_Reverse(int limit);
void PID_BW_FollowCounter_Left_Reverse(void);

void BW_FollowTracer_Right_Interpolate(void);
void PID_BWFollowTracer_Right_Interpolate(void);
void BW_FollowTracer_Left_Interpolate(void);
void PID_BWFollowTracer_Left_Interpolate(void);
void BWFollowCarpet_Left_Interpolate(int CARPET_CODE, int FOLLOW_MODE);
void PID_BWFollowCarpet_Left_Interpolate(unsigned int CARPET_CODE, unsigned int MODE);
void BWFollowCarpet_Right_Interpolate(unsigned int CARPET_CODE, int FOLLOW_MODE);
void PID_BWFollowCarpet_Right_Interpolate(unsigned int CARPET_CODE, unsigned int MODE);
void Stairs_Detector(void);
void BW_COMPASS_CORRECTION(int SECTION);
void Instant_Trial(void);
void BW_Settings_2019(void);
void BWFollowCarpet_Right_ALG(unsigned int CARPET_CODE, unsigned int MODE);
void BW_Climbing_Stairs(void);


// BW COMPASS SECTION CORRECTION VARIABLES
extern int FOUR_WAY_CORRECTION;
extern int ROOM_2_1BC_CORRECTION;
extern int ROOM_1A_CORRECTION;
extern int ROOM_4B_TURN_CORRECTION;
extern int START_MID_CORRECTION;
extern int ROOM_1A_RETURN;
extern int ROOM_4A_DETECT;
extern int ROOM_4B_DETECT;
extern int ROOM_1B_DETECT;
extern int ROOM_1C_DETECT;
extern int ROOM_4A_DETECT_IN;
extern int ROOM_4B_DETECT_IN;
extern int ROOM_1B_DETECT_NAV;
extern int ROOM_1C_DETECT_NAV;
extern int FOUR_WAY_INV;
extern int DIFF_4A_1BC;
extern int R4A_RETURN;
extern int R4B_RETURN;
extern int selisih_CMPS;
extern int STAIRS_DIRECTION_4B;
extern int STAIRS_DIRECTION_4A;

extern int CAT_MIN_RANGE;
extern int STAIRS_MIN_RANGE;

//TURNING SPEED CONTROL
extern int speed_cnt;

/*
 *  BW CANDLE TRACKER VARIABLES;
 */
extern unsigned int CANDLE_STAT;
extern unsigned int CANDLE_STICK;
extern unsigned int CANDLE_FIRE;
extern unsigned int CANDLE_STAT;

extern unsigned int SP_FIRE_1B;
extern unsigned int SP_FIRE_1C;
extern unsigned int SP_FIRE_R3;
extern unsigned int SP_FIRE_ACTIVE;
extern unsigned int SP_FIRE_INACTIVE;

//flag masuk ruangan
extern unsigned int FLAG_ROOM_1A;
extern unsigned int FLAG_ROOM_1B;
extern unsigned int FLAG_ROOM_1C;
extern unsigned int FLAG_ROOM_2;
extern unsigned int FLAG_ROOM_3;
extern unsigned int FLAG_ROOM_4A;
extern unsigned int FLAG_ROOM_4B;
extern unsigned int FLAG_ROOM_ACTIVE;
extern unsigned int FLAG_ROOM_INACTIVE;

/*
 *  EXIT FLAG
 */

extern unsigned int EXIT_FLAG;
extern unsigned int EXIT_ACTIVE;
extern unsigned int EXIT_INACTIVE;

extern unsigned int FOLLOW_FLAG;
extern unsigned int FLAME;
extern unsigned int KANAN_BELAKANG;
extern unsigned int KIRI_BELAKANG;
extern unsigned int KANAN;
extern unsigned int KIRI;
extern unsigned int KOSONG;
extern unsigned int KANAN_OBS;
extern unsigned int KIRI_OBS;

extern unsigned int FOLLOW_BREAK;
extern unsigned int FOLLOW_CALC;
/*
 *  ROOM 1 FLAG
 */

extern unsigned int ROOM1_FLAG;
extern unsigned int ROOM1FLAG_ACTIVE;
extern unsigned int ROOM1FLAG_INACTIVE;

/*
 *  ROOM 1BC FLAG
 */

extern unsigned int ROOM1BC_FLAG;
extern unsigned int ROOM1BCFLAG_ACTIVE;
extern unsigned int ROOM1BCFLAG_INACTIVE;

/*
 * ROOM 2B FLAG
 */
extern unsigned int ROOM2B_FLAG;
extern unsigned int ROOM2BFLAG_ACTIVE;
extern unsigned int ROOM2BFLAG_INACTIVE;

/*
 * ROOM 4 FLAG
 */
extern unsigned int ROOM4_FLAG;
extern unsigned int ROOM4FLAG_ACTIVE;
extern unsigned int ROOM4FLAG_INACTIVE;

/*
 * ROOM 4A FLAG
 */
extern unsigned int ROOM4A_FLAG;
extern unsigned int ROOM4AFLAG_ACTIVE;
extern unsigned int ROOM4AFLAG_INACTIVE;

/*
 * ROOM 4B FLAG
 */
extern unsigned int ROOM4B_FLAG;
extern unsigned int ROOM4BFLAG_ACTIVE;
extern unsigned int ROOM4BFLAG_INACTIVE;

/*
 * ROOM 4B_EXIT FLAG
 */
extern unsigned int ROOM4B_EXIT_FLAG;
extern unsigned int ROOM4BFLAG_EXIT_ACTIVE;
extern unsigned int ROOM4BFLAG_EXIT_INACTIVE;

/*
 * ROOM1A SPECIAL EXIT FLAG
 */
extern unsigned int ROOM1A_SP_EXIT_FLAG;
extern unsigned int ROOM1A_SP_EXIT_FLAG_ACTIVE;
extern unsigned int ROOM1A_SP_EXIT_FLAG_INACTIVE;


/*
 * ROOM4A CAT AVOIDER
 */
extern unsigned int ROOM4A_CAT_AVOIDER;
extern unsigned int ROOM4A_CAT_AVOIDER_ACTIVE;
extern unsigned int ROOM4A_CAT_AVOIDER_INACTIVE;


/*
 * CAT SHIFT ALGORITHM FLAG
 */
extern unsigned int SHIFT_ALGORITHM_FLAG;
extern unsigned int SHIFT_ALGORITHM_ACTIVE;
extern unsigned int SHIFT_ALGORITHM_INACTIVE;
extern unsigned int CAT_IR1;
extern unsigned int CAT_IR2;
extern unsigned volatile int STAIRS_IR;
extern unsigned int STAIRS_FLAG;

/*
 *  DEFLECT WALL OVERFLOW COUNTER
 */
extern int RIGHT_OVERFLOW_COUNTER;
extern int LEFT_OVERFLOW_COUNTER;

/*
 * SPECIAL ROUTE FOR RETURN TRIP R2 TO R4A
 * HOME: R4A
 * FIRE ROOM: R2
 * CAT CONFIG: A
 */
extern unsigned int R2TO4A_SP_ROUTE;
extern unsigned int R2TO4A_SP_ACTIVE;
extern unsigned int R2TO4A_SP_INACTIVE;

extern unsigned int R4ATO3_SP_ROUTE;
extern unsigned int R4ATO3_SP_ACTIVE;
extern unsigned int R4ATO3_SP_INACTIVE;

/*
 *  BW TURNAROUND NAVIGATION
 */
extern unsigned int TURN_LEFT;
extern unsigned int TURN_RIGHT;


//SHARP IR RANGEFINDER
extern unsigned int SHARP[];
extern unsigned int SHARP_GRIPPER[];
extern unsigned int SHARP_FRONT[];


/*
 * BW FIRE SCAN DIRECTION FLAG
 */
extern unsigned int FIRESCAN_DIRECTION;

/*
 * BW FIREFIGHT SUCCESS TURN AROUND
 */
extern unsigned int BW_TurnAround;

/*
 * BW FOWARD REVERSE FLAG
 */
extern unsigned int REVERSE_FLAG;
extern unsigned int REVERSEFLAG_ACTIVE;
extern unsigned int REVERSEFLAG_INACTIVE;

extern int cnt;
extern int FRONT, MIDDLE, REAR;
extern int BACA[4];
extern int KONSTANTA[2];
extern int VALUE;


/*
 * 	CMPS11 ANGLE
 */
extern int CMPS11_Angle;
extern int CMPS11_Angle16bit;

void Nav_TurnAround(int ORIENTATION);


/*
 *  SPECIAL ROUTE FLAG WHEN CAT DETECTED
 */

extern unsigned int SP_ROUTE_ACTIVE;
extern unsigned int SP_ROUTE_INACTIVE;

/*FLAG UNTUK MEMATIKAN PENGGUNAAN CMPS11 PADA DAERAH TERTENTU*/

extern unsigned int START_MID_MANUAL;
extern unsigned int FOUR_WAY_MANUAL;
extern unsigned int ROOM_1A_MANUAL;
extern unsigned int ROOM_2_1BC_MANUAL;
extern unsigned int ROOM_4A_MANUAL;
extern unsigned int ROOM_4B_ROT_MANUAL;
extern unsigned int ROOM_1A_RETURN_MANUAL;
extern unsigned int ROOM_4B_MANUAL;
/*
 *  SPECIAL ROUTE FOR RETURN TRIP R4A TO R2
 *  HOME: R2
 *  FIRE ROOM: R4A
 *  CAT CONFIG: A
 */
extern unsigned int R4ATO2_SP_ROUTE;


/*
 *  SPECIAL ROUTE FOR RETURN TRIP R4A TO R1
 *  HOME: R1
 *  FIRE ROOM: R4A
 *  CAT CONFIG: B
 */
extern unsigned int R4ATO1_SP_ROUTE;



/*
 *  COMPASS ARENA FLAG
 */
extern unsigned int CMPS_ACTIVE;
extern unsigned int CMPS_INACTIVE;
extern unsigned int ARENA_FLAG;
extern unsigned int TRESH_UPPER;
extern unsigned int TRESH_LOWER;
extern unsigned int TRESH_FLAG;
extern unsigned int NORTH_THRESHOLD_UPPER;
extern unsigned int NORTH_THRESHOLD_LOWER;
extern unsigned int NORTH_THRESHOLD_MIDDLE;
extern unsigned int WEST_THRESHOLD_UPPER;
extern unsigned int WEST_THRESHOLD_LOWER;
extern unsigned int WEST_THRESHOLD_MIDDLE;
extern unsigned int SOUTH_THRESHOLD_UPPER;
extern unsigned int SOUTH_THRESHOLD_LOWER;
extern unsigned int SOUTH_THRESHOLD_MIDDLE;
extern unsigned int EAST_THRESHOLD_UPPER;
extern unsigned int EAST_THRESHOLD_LOWER;
extern unsigned int EAST_THRESHOLD_MIDDLE;

extern unsigned int R4AB_THRESHOLD_UPPER;
extern unsigned int R4AB_THRESHOLD_LOWER;
extern unsigned int R4AB_THRESHOLD_MIDDLE;

extern unsigned int R4A_THRESHOLD_UPPER;
extern unsigned int R4A_THRESHOLD_LOWER;
extern unsigned int R4B_THRESHOLD_UPPER;
extern unsigned int R4B_THRESHOLD_LOWER;
extern unsigned int R4A_THRESHOLD_MIDDLE;
extern unsigned int R4B_THRESHOLD_MIDDLE;
extern unsigned int START_MIDDLE;
extern unsigned int R1BC_THRESHOLD_MIDDLE;
extern unsigned int STAIRS_THRESHOLD_4B_UPPER;
extern unsigned int STAIRS_THRESHOLD_4B_LOWER;
extern unsigned int STAIRS_THRESHOLD_4A_UPPER;
extern unsigned int STAIRS_THRESHOLD_4A_LOWER;
extern unsigned int STAIRS_THRESHOLD_4B_MIDDLE;
extern unsigned int STAIRS_THRESHOLD_4A_MIDDLE;

/*
 * 	FIREFIGHT FLAG FOR ROOM4AB
 */
extern unsigned int ROOM4AB_FLAG;
extern unsigned int ROOM4AB_ACTIVE;
extern unsigned int ROOM4AB_INACTIVE;

extern unsigned int FIREROOM_R4AB_FLAG;
extern unsigned int FIREROOM_R4AB_ACTIVE;
extern unsigned int FIREROOM_R4AB_INACTIVE;

extern unsigned int FIREROOM_R1A_FLAG;
extern unsigned int FIREROOM_R1A_ACTIVE;
extern unsigned int FIREROOM_R1A_INACTIVE;
extern unsigned int ROOM1A_SP_MIDDLE_FLAG; // CEK ulang R1A ditengah ruang

extern unsigned int RIGHT_COUNTER,LEFT_COUNTER;
#endif
