/*===========================================================================================================================*
*===========================================================================================================================*
										PROJECT BHATARA WIJAYA 3.17 Ver.1.0
								BW DYNAMIXEL AX-12A SMART SERVO HEXAPOD LOCOMOTION LIBRARY
@Author  : Ryan (Batch 2013)
@Company : Brawijaya University Robotics Team
@Division: Intelligent Fire-Fighting Robot Division
@Team    : Project YUME (Legged Robot Sub-Division)
@E-mail	 : achnaf13@gmail.com
@Version : ALPHA RELEASE (ON PROGRESS)
@IDE	 : CooCox IDE 1.7.8

<================= UPDATE LOGS

<=== Version 1.0
@Date:


<=== Version 2.0
@Date:

<================= LIBRARY DEPENDENCIES
	bw_dynamixel_ax_12a.c
	bw_dynamixel_ax_12a.h


*===========================================================================================================================*
============================================================================================================================*/

#include "main.h"

#ifndef BW_DYNAMIXEL_HEXAPOD_CMD_H
#define BW_DYNAMIXEL_HEXAPOD_CMD_H

#define EQ_1 0
#define EQ_2 1
#define MOVEMENT_NORMAL 0
#define MOVEMENT_ASKEW	1

// DYNAMIXEL ID
extern const unsigned int FRONT_LEFT_DX_COXA;
extern const unsigned int FRONT_LEFT_DX_FEMUR;
extern const unsigned int FRONT_LEFT_DX_TIBIA;

extern const unsigned int MIDDLE_LEFT_DX_COXA;
extern const unsigned int MIDDLE_LEFT_DX_FEMUR;
extern const unsigned int MIDDLE_LEFT_DX_TIBIA;

extern const unsigned int REAR_LEFT_DX_COXA;
extern const unsigned int REAR_LEFT_DX_FEMUR;
extern const unsigned int REAR_LEFT_DX_TIBIA;

extern const unsigned int FRONT_RIGHT_DX_COXA;
extern const unsigned int FRONT_RIGHT_DX_FEMUR;
extern const unsigned int FRONT_RIGHT_DX_TIBIA;

extern const unsigned int MIDDLE_RIGHT_DX_COXA;
extern const unsigned int MIDDLE_RIGHT_DX_FEMUR;
extern const unsigned int MIDDLE_RIGHT_DX_TIBIA;

extern const unsigned int REAR_RIGHT_DX_COXA;
extern const unsigned int REAR_RIGHT_DX_FEMUR;
extern const unsigned int REAR_RIGHT_DX_TIBIA;

extern const unsigned int GRIPPER_UP;
extern const unsigned int GRIPPER_CLIP;

extern const unsigned int CLEANER;

extern const unsigned int DYNA_EXT_ID;

extern int DynamxCorrection[];

#define link_A  			5       // besar La
#define link_B  			8       // besar Lb
#define L_junction  		3.5     // besar L_junction
#define RAD2DEG  			57.29
#define ANGLE_CORRECTION    45      //koreksi sudut 0 di teta3, karena sudut 0 sbenarnya adalah sejajar teta2 shg jangkauan servo kurang

#define Length1 5			//femur
#define Length2 7 //6.5		//tibia
struct {
        int ThetaCoxa;
        int ThetaFemur;
        int ThetaTibia;
       }JointAngle;

struct{
    	int Coxa;
    	int Femur;
    	int Tibia;
    	float CoxaBuf;
    	float FemurBuf;
    	float TibiaBuf;
	   }tetha;
extern float leg_static_length;
extern int SUPPORT_FASE;
extern int SWING_FASE;
extern float Dynamx_LinkFemur;
extern float Dynamx_LinkTibia;
extern int CURVE_LEFT_STAT;
extern int CURVE_RIGHT_STAT;
extern int FOWARD_STAT;
extern int BACKWARD_STAT;

/*
 * SPEED TRIGONOMETRY
 */

extern double PI;
//extern float PIby2;
#define MAX_UINT  65535
#define MIN_INT -32768
#define MAX_INT  32767

#define DEC1 10
#define DEC2 100
#define DEC3 1000
#define DEC4 10000

#define NO_CORRECTION	3

extern const float SIN_TABLE[];
extern const int ACOS_TABLE[];

/*
 * BW DYNAMIXEL HEXAPOD VARIABLES
 */
extern int SUDUT_STATIC[];
extern int SUDUT_STATIC_BWD[];
extern int SUDUT_ANGKAT;
extern int DG_GRIP_DOWN;
extern int DG_GRIP_UP;
extern int LIFT_ANGLE[];
// MOV FWD ZCOXA = 35 and Z TIBIA = 25
extern int IKFWD_COXA_R[];
extern int IKFWD_TIBIA_R[];
extern int IKFWD_COXA_L[];
extern int IKFWD_TIBIA_L[];

// MOV FWD ZCOXA = 15 and Z TIBIA = 15
extern int IKFWD_COXA_R1[];
extern int IKFWD_TIBIA_R1[];
extern int IKFWD_COXA_L1[];
extern int IKFWD_TIBIA_L1[];

// MOV FWD ZCOXA = 10 and Z TIBIA = 10
extern int IKFWD_COXA_R2[];
extern int IKFWD_TIBIA_R2[];
extern int IKFWD_COXA_L2[];
extern int IKFWD_TIBIA_L2[];

// MOV FWD ZCOXA = 5 and Z TIBIA = 5
extern int IKFWD_COXA_R3[];
extern int IKFWD_TIBIA_R3[];
extern int IKFWD_COXA_L3[];
extern int IKFWD_TIBIA_L3[];

//// MOV FWD ZCOXA = 15 and Z TIBIA = 15
//extern int IKFWD_COXA_R2[];
//extern int IKFWD_TIBIA_R2[];
//extern int IKFWD_COXA_L2[];
//extern int IKFWD_TIBIA_L2[];

// MOV ROT ZCOXA_L = 15
extern int IKROT_COXA[];

// MOV ROT ZCOXA_L = 10
extern int IKROT_COXA1[];

// MOV ROT ZCOXA_L = 5
extern int IKROT_COXA2[];

//SLOW
// MOV CURVE RIGHT SLOW ZCOXA_L = 35, ZCOXA_R = 5 and ZTIBIA_L = 25, ZTIBIA_R = 5
extern int IKCRVR_COXA_R2[];
extern int IKCRVR_TIBIA_R2[];
extern int IKCRVR_COXA_L2[];
extern int IKCRVR_TIBIA_L2[];

// MOV PID CURVE RIGHT SLOW ZCOXA_L = 35, ZCOXA_R = 5 and ZTIBIA_L = 25, ZTIBIA_R = 5
extern int IKRPID_COXA_R2[];
extern int IKRPID_TIBIA_R2[];

// MOV CURVE RIGHT ZCOXA_L = 35 ZCOXA_R = 5 and ZTIBIA_L = 25 ZTIBIA_R = 5
extern int IKCRVR_COXA_R[];
extern int IKCRVR_TIBIA_R[];
extern int IKCRVR_COXA_L[];
extern int IKCRVR_TIBIA_L[];

// MOV CURVE PID RIGHT ZCOXA_L = 35, ZCOXA_R = 5 and ZTIBIA_L = 25, ZTIBIA_R = 5
extern int IKRPID_COXA_R[];
extern int IKRPID_TIBIA_R[];

// MOV SLIDE RIGHT X = 20
extern int IKSLR_COXA[];
extern int IKSLR_TIBIA[];

// MOV SLIDE RIGHT X = 15
extern int IKSLR_COXA1[];
extern int IKSLR_TIBIA1[];

// MOV SLIDE RIGHT X = 10
extern int IKSLR_COXA2[];
extern int IKSLR_TIBIA2[];

// MOV CURVE LEFT ZCOXA_R = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 35
extern int IKCRVL_COXA_R[];
extern int IKCRVL_TIBIA_R[];
extern int IKCRVL_COXA_L[];
extern int IKCRVL_TIBIA_L[];

// MOV CURVE PID LEFT ZCOXA_L = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 25
extern int IKLPID_COXA_L[];
extern int IKLPID_TIBIA_L[];

//SLOW
// MOV CURVE LEFT SLOW ZCOXA_R = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 35
extern int IKCRVL_COXA_R2[];
extern int IKCRVL_TIBIA_R2[];
extern int IKCRVL_COXA_L2[];
extern int IKCRVL_TIBIA_L2[];

// MOV PID CURVE LEFT SLOW ZCOXA_L = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 25
extern int IKLPID_COXA_L2[];
extern int IKLPID_TIBIA_L2[];

// MOV SLIDE LEFT X = 20
extern int IKSLL_COXA[];
extern int IKSLL_TIBIA[];

// MOV SLIDE LEFT X = 15
extern int IKSLL_COXA1[];
extern int IKSLL_TIBIA1[];

// MOV SLIDE LEFT X = 10
extern int IKSLL_COXA2[];
extern int IKSLL_TIBIA2[];

// MOV BWD ZCOXA = 35 and Z TIBIA = 25
extern int IKBWD_COXA_R[];
extern int IKBWD_TIBIA_R[];
extern int IKBWD_COXA_L[];
extern int IKBWD_TIBIA_L[];

// MOV CURVE RIGHT REVERSE ZCOXA_L = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 25
extern int IKCRVRR_COXA_L[];
extern int IKCRVRR_TIBIA_L[];
extern int IKCRVRR_COXA_R[];
extern int IKCRVRR_TIBIA_R[];

// MOV PID CURVE RIGHT REVERSE ZCOXA_L = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 25
extern int IKPIDR_COXA_L[];
extern int IKPIDR_TIBIA_L[];

// MOV CURVE LEFT REVERSE ZCOXA_R = 35, ZCOXA_R = 5 and ZTIBIA_L = 25, ZTIBIA_R = 5
extern int IKCRVLR_COXA_L[];
extern int IKCRVLR_TIBIA_L[];
extern int IKCRVLR_COXA_R[];
extern int IKCRVLR_TIBIA_R[];

// MOV PID CURVE LEFT REVERSE ZCOXA_L = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 25
extern int IKPIDR_COXA_R[];
extern int IKPIDR_TIBIA_R[];

extern float Y_Sampling[12];
extern float Y1_Sampling[12];
extern float Y2_Sampling[12];
extern float Z_Sampling[12];
extern float Z1_Sampling[12];
extern float Z2_Sampling[12];
extern float Z3_Sampling[12];
extern float Z4_Sampling[12];
extern float X1_Sampling[6];
extern float X2_Sampling[6];
extern float X3_Sampling[6];
extern float X4_Sampling[6];
extern float X5_Sampling[6];

extern float DELTA_TEST;

struct DEG_DATA
{
	int COXA_NEW;
	int COXA_OLD;
	int FEMUR_NEW;
	int FEMUR_OLD;
	int TIBIA_NEW;
	int TIBIA_OLD;
}F_R, F_L, M_L, M_R, R_L, R_R;

/*
 *   CONVERSION FROM OLD ALGORITHM
 */
extern int sudut_target[];
extern int sudut_awal[];
extern int x;
extern int z_A[];
extern int pembagi;
extern int y_A[];
extern int sudut_tahap1[];
extern int sudut_tahap2[];

//float gamma[6];
extern int leg;
extern int ww[];
extern float beta[];
extern float leg_next[];
extern float A_body;			// translasi pusat badan
extern float A_leg[];			// translasi setiap pangkal kaki
extern float P_body;			// jarak titik pusat robot ke titik imajiner putar
extern int epsilon_body;		// besar sudut vektor hadap thdp vektor poros-imajiner
extern float phi[];
extern float lambpsi[];		//lambda / psi temporal
extern float P_leg[];			// jarak titik pusat kaki ke titik imajiner putar
extern float epsilon[];		// epsilon tiap N
extern float rad_teta1;//coxa in radiant
extern float rad_teta2;//femur in radiant
extern float rad_teta3;//tibia in radiant
extern float deg_teta1;
extern float deg_teta2;
extern float deg_teta3;
extern float X_rotgoal[];
extern float Y_rotgoal[];
extern float X1_IK[];
extern float X2_IK[];
extern float X3_IK[];
extern float X4_IK[];
extern float X5_IK[];
extern float Y_IK[];
extern float Y1_IK[];
extern float Z_IK[];
extern float Z1_IK[];
extern float Z2_IK[];
extern float Z3_IK[];
extern float Z4_IK[];
extern float delta_X_leg[];
extern float delta_Y_leg[];
extern float X_IK_OBS[];
extern float X_IK_BEGIN[];
extern float Y_IK_BEGIN[];
extern float Z_IK_BEGIN[];
extern float Z_IK_BEGIN_BWD[];

extern float Z_IK_STAIRS[];
extern float Z_IK_S_BUFF[];

extern float Z_IK_OBS[];

extern float Z0_IK_STAIRS[];
extern float Z1_IK_STAIRS[];
extern float Z2_IK_STAIRS[];
extern float Z3_IK_STAIRS[];
extern float Z4_IK_STAIRS[];
extern float Z5_IK_STAIRS[];

extern float Z_IK_STAIRS2[];
extern float Z_IK_STAIRS3[];
extern float Z_IK_STAIRS4[];
extern int X_STATIC_IK[];
extern int Y_STATIC_IK[];
extern int Z_STATIC_IK[];

extern int X_STATIC_IK_S[];
extern int Y_STATIC_IK_S[];
extern int Z_STATIC_IK_S[];

extern const float X_BODY_OFFSET[]; //panjang femur
extern const float Y_BODY_OFFSET[]; //pangjang tibia
extern const float X_STATIC_OFFSET; //panjang femur
extern const float Y_STATIC_OFFSET ; //pangjang tibia
extern float tetha_offset[]  ; //atan2(8.5,3.7)
extern float X_Body_Offset_final[];
extern float Y_Body_Offset_final[];
extern float X_Trans_Leg[];
extern float Y_Trans_Leg[];
extern float X_Leg_PosFinal[];
extern float Y_Leg_PosFinal[];
extern float rotation_matriks[];
extern float rotation_matriks_6S[];
extern int SLIDE_FLAG;
extern int ROTATION_FLAG;
extern float step;
extern float leg_length_total;
extern float X_Diff;
extern float Y_Diff;
extern int STATIC_ANGLE;
extern int STATIC_CLIMBING;
extern int STATIC_OBS;
extern int STATIC_OBS_HIGH;
extern int IK_CALCULATED_OBS;
extern int IK_CALCULATED_FWD_OBS;
extern int IK_CALCULATED_BWD_OBS;
extern int IK_CALCULATED_FWD;
extern int IK_CALCULATED_CLMB;
extern int IK_CALCULATED_CRV_R_CLMB;
extern int IK_CALCULATED_CRV_L_CLMB;
extern int IK_CALCULATED_ASK_R;
extern int IK_CALCULATED_ASK_L;
extern int IK_CALCULATED_BWD;
extern int IK_CALCULATED_SLP;
extern int IK_CALCULATED_SLD_L;
extern int IK_CALCULATED_SLD_R;
extern int IK_CALCULATED_SLD_L_OBS;
extern int IK_CALCULATED_SLD_R_OBS;
extern int IK_CALCULATED_ROT_R;
extern int IK_CALCULATED_ROT_L;
extern int IK_CALCULATED_CRV_R;
extern int IK_CALCULATED_CRV_L;
extern int IK_CALCULATED_CRV_R_OBS;
extern int IK_CALCULATED_CRV_L_OBS;
extern int IK_CALCULATED_CRV_R_REVERSE;
extern int IK_CALCULATED_CRV_L_REVERSE;
extern int IK_CALCULATED_LEAN_FWD_OBS;
extern int IK_CALCULATED_LEAN_BWD_OBS;
extern int IK_CALCULATED_LEAN_FWD;
extern int IK_CALCULATED_LEAN_BWD;

extern int COXA_D[];
extern int NCOXA_D[];
extern int FEMUR_D[];
extern int NFEMUR_D[];
extern int TIBIA_D[];
extern int NTIBIA_D[];
extern int TIBIA_D_R[];
extern int NTIBIA_D_R[];

extern int COXA_A[];
extern int FEMUR_A[];
extern int TIBIA_A[];
extern int TIBIA_A_R[];
extern int NTIBIA_A_R[];
extern int NTIBIA_ASK_L[];
extern int NTIBIA_ASK_R[];
extern int TIBIA_A_RB[];
extern int NCOXA_A[];
extern int NFEMUR_A[];
extern int NTIBIA_A[];
extern int TIBIA_ASK_L[];
extern int TIBIA_ASK_R[];
extern int TIBIA_ASK[];

extern int COXA_B[];
extern int NCOXA_B[];
extern int COXA_B_R[];
extern int NCOXA_B_R[];
extern int FEMUR_B[];
extern int NFEMUR_B[];
extern int TIBIA_B[];
extern int TIBIA_B_R[];
extern int NTIBIA_B[];
extern int NTIBIA_B_R[];

extern int COXA_E[];
extern int NCOXA_E[];
extern int COXA_E_R[];
extern int NCOXA_E_R[];
extern int FEMUR_E[];
extern int NFEMUR_E[];
extern int TIBIA_E[];
extern int TIBIA_E_R[];
extern int NTIBIA_E[];
extern int NTIBIA_E_R[];

extern int COXA_C[];
extern int NCOXA_C[];
extern int FEMUR_C[];
extern int NFEMUR_C[];
extern int TIBIA_C[];
extern int TIBIA_C_R[];
extern int NTIBIA_C[];
extern int NTIBIA_C_R[];
extern int R_TIBIA_C[];
extern int R_NTIBIA_C[];
extern int L_TIBIA_C[];
extern int L_NTIBIA_C[];

extern int COXA_O[];
extern int NCOXA_O[];
extern int FEMUR_O[];
extern int NFEMUR_O[];
extern int TIBIA_O[];
extern int TIBIA_O_R[];
extern int NTIBIA_O[];
extern int NTIBIA_O_R[];
extern int R_TIBIA_O[];
extern int R_NTIBIA_O[];
extern int L_TIBIA_O[];
extern int L_NTIBIA_O[];

extern int COXA_R[];
extern int NCOXA_R[];
extern int FEMUR_R[];
extern int NFEMUR_R[];
extern int TIBIA_R[];
extern int TIBIA_R_O[];
extern int NTIBIA_R[];
extern int NTIBIA_R_O[];

//variable climbing stairs
extern int COXA_S[];
extern int NCOXA_S[];

extern int FEMUR_S_F[];
extern int NFEMUR_S_F[];
extern int FEMUR_S_M[];
extern int NFEMUR_S_M[];
extern int FEMUR_S_R[];
extern int NFEMUR_S_R[];

extern int FEMUR_S_KI[];
extern int NFEMUR_S_KI[];
extern int FEMUR_S_KA[];
extern int NFEMUR_S_KA[];

extern int TIBIA_S[];
extern int NTIBIA_S[];
extern int TIBIA_S_R[];
extern int NTIBIA_S_R[];

extern int TIBIA_S_KI[];
extern int NTIBIA_S_KI[];
extern int TIBIA_S_R_KI[];
extern int NTIBIA_S_R_KI[];

extern int FEMUR_G[];
extern int NFEMUR_G[];
extern int COXA_G[];
extern int NCOXA_G[];
extern int TIBIA_G[];
extern int NTIBIA_G[];
extern int TIBIA_GS[];
extern int NTIBIA_GS[];

extern int FEMUR_H[];
extern int NFEMUR_H[];
extern int COXA_H[];
extern int NCOXA_H[];
extern int TIBIA_H[];
extern int NTIBIA_H[];
extern int TIBIA_HS[];
extern int NTIBIA_HS[];

extern int FEMUR_SLP[];
extern int NFEMUR_SLP[];
extern int COXA_SLP[];
extern int NCOXA_SLP[];
extern int TIBIA_SLP[];
extern int NTIBIA_SLP[];

extern int IK_Count;
extern int IK_step;
extern int ROOM_MOVEMENT;

extern unsigned int sudut[];

extern unsigned char y;
extern unsigned char a;
extern unsigned char b;
extern unsigned char c;
extern unsigned char d;
extern unsigned char v;
extern unsigned char index_bantu;
extern unsigned char index_servo2;
extern unsigned char index_servo3;
extern uint32_t PrescalerValue;

extern const float A_const[];

extern const int B_const[];

extern float correct[]; //EDITED

extern const float leg_1[];	//L1
extern const float leg_norm[]; //L2
extern const float alpha[];	//alpha

extern float c1;
extern float c2;
extern float Lsem;
extern float c3;
extern float c4;
extern int i;
extern float temp_var;
extern float temp_var2;
extern int CLIMBING_FLAG;
extern int CLIMBING_INTERRUPT_FLAG;
extern int SIKLUS_FLAG;

//LEG POSITION MACRO
#define FRONT_LEFT_DX      1
#define FRONT_RIGHT_DX     2
#define MIDDLE_LEFT_DX     3
#define MIDDLE_RIGHT_DX    4
#define REAR_LEFT_DX       5
#define REAR_RIGHT_DX      6

#define IKCALC_ENABLE	1
#define IKCALC_DISABLE	0



extern char command_code[];

enum DYNAMX_HEX_SPEED {HEXSPD_ULTRASLOW=80, HEXSPD_SLOW=300, HEXSPD_MED=500, HEXSPD_MEDFAST=650,  HEXSPD_FAST=800, HEXSPD_ULTRAFAST=1000, HEXSPD_EXPERIMENTAL=760};
enum DYNAMX_STEP {STEP1 = 1, STEP2 =2, STEP3 = 3, STEP4 = 4, STEP5 = 5, STEP6 = 6, STEP7 = 7, STEP8 = 8};

enum DYNAMX_HEX_STEP	{HEXSTEP_VERYCLOSE=1, HEXSTEP_CLOSE= 2, HEXSTEP_MED=3, HEXSTEP_FAR=4, HEXSTEP_FAR2=5};
//enum DYNAMX_INTERPOLATE {LEVEL1 = 300, LEVEL2 = 150, LEVEL3 = 100, LEVEL4 = 70, LEVEL5 = 48, LEVEL6 = 24, LEVEL_MAX = 18};
enum DYNAMX_INTERPOLATE {LEVEL1 = 380, LEVEL2 = 300, LEVEL3 = 220, LEVEL4 = 200, LEVEL5 = 180, LEVEL6 = 160, LEVEL7 = 140, LEVEL_MAX = 50}; // OK
enum DYNAMX_OBS {OBS_LVL1 = 1000, OBS_LVL2 = 1500, OBS_LVL3= 2000, OBS_LVL4=2500, OBS_LVL5=3000};

extern unsigned int CAT_BREAK, TRACER_COLOR_BREAK;
extern int CURVE_STAT;

void Dynamx_MovFwd_Obstaicle_Interpolate(int SPEED, int limit);

void Dynamx_Mov_Climbing_Interpolate(int SPEED, int limit, int movement);
void Dynamx_MovSlope_Interpolate(int distance, int SPEED, int IKCALC_STAT);
void Dynamx_Rot_Left_Reverse(int SPEED,  int STEP);
void Dynamx_Rot_Right_Reverse(int SPEED,  int STEP);
void Dynamx_CurveRight_PID_Reverse(int SPEED, int STEP, volatile float *ACTUATE_SIGNAL, int IKCALC_STAT);
void Dynamx_CurveLeft_PID_Reverse(int SPEED, int STEP, volatile float *ACTUATE_SIGNAL, int IKCALC_STAT);
void kinematik_invers(unsigned int leg_position,int *SPEED,float x,float y,float z);
void HexJoint_Actuate_Interpolate(unsigned char DYNA_ID, int INV_VALUE, int Time_ms);
void Dynamx_MoveLeg_Interpolate(unsigned int leg_position, int *SPEED, unsigned int ThetaCoxa, int ThetaFemur, unsigned int ThetaTibia);
void Dynamx_MovFwd4cm_Interpolate(unsigned int distance, int SPEED, int IKCALC_STAT);
void Dynamx_Mov_Static_Interpolate(int SPEED, unsigned int IK_STAT);
void Dynamx_Mov_Static_Obs(int SPEED);
void Dynamx_Mov_Static_Obs_High(int SPEED);
void Dynamx_Rot_Left_Interpolate(int SPEED,  int STEP, int IKCALC_STAT);
void Dynamx_Rot_Left_IK(int SPEED, int STEP);
void Dynamx_Rot_Right_IK(int SPEED, int STEP);
void Dynamx_Rot_Obs_Left_IK(int SPEED, int STEP);
void Dynamx_Rot_Obs_Right_IK(int SPEED, int STEP);
void Dynamx_MovBwd_Interpolate(int distance, int SPEED, int IKCALC_STAT);
void Dynamx_MovBwd_Obs_Interpolate(int distance, int SPEED, int IKCALC_STAT);
void Dynamx_Slide_Right_Interpolate(int STEP, int SPEED);
void Dynamx_Slide_Left_Interpolate(int STEP, int SPEED);
void Dynamx_Slide_Right_IK(int distance, int SPEED);
void Dynamx_Slide_Left_IK(int distance, int SPEED);
void Dynamx_Slide_Obs_Right_IK(int distance, int SPEED);
void Dynamx_Slide_Obs_Left_IK(int distance, int SPEED);
void Trajectory_Test(int SPEED);
void Dynamx_IKCALC( float x,float y, float z,int mode, int leg);
void Dyna_IK_VER2(float x, float y, float z, int leg);
void Dyna_IKCALC_NEW(int leg, float x, float y, float z , int *SPEED);
void Dyna_IKCALC_Obs(int leg, float x, float y, float z , int *SPEED);
double RadtoDeg(double a);
double sin_deg(double a);
double cos_deg(double a);
double acos_deg(double a);
double atan2_deg(double a, double b);
double H_Elips(double y,double z_max, double goal_pos);
void Translation(float x_trans,float y_trans,int leg);
void Rotation(float x_offset, float y_offset, int leg );
void Generate_Body(float X, float Y);
void HexJoint_Actuate_New(unsigned char DYNA_ID, int INV_VALUE, int Time_ms);
void HexJoint_Actuate_Climbing(unsigned char DYNA_ID, int INV_VALUE, int Time_ms);
void Dyna_IKCalc_Only(float x, float y, float z );
void Dyna_IKCalc_Only_Static_Climbing(int leg, float x, float y, float z, int *SPEED);
void Dynamx_MoveLeg_Interpolate_NEW(int leg_position, int *SPEED, int ThetaCoxa, int ThetaFemur, int ThetaTibia);
void Dynamx_MoveCurveRight_IK(int SPEED,int limit,volatile float *ACTUATE_SIGNAL);
void Dynamx_MoveCurveLeft_IK(int SPEED,int limit,volatile float *ACTUATE_SIGNAL);
void Dynamx_MoveCurveRight_Obstaicle(int SPEED,int limit,volatile float *ACTUATE_SIGNAL);
void Dynamx_MoveCurveLeft_Obstaicle(int SPEED,int limit,volatile float *ACTUATE_SIGNAL);
void Dynamx_MoveCurveRight_IK_Reverse(int SPEED,int limit,volatile float *ACTUATE_SIGNAL);
void Dynamx_MoveCurveLeft_IK_Reverse(int SPEED,int limit,volatile float *ACTUATE_SIGNAL);
void Trajectory_Generator_NEW(float x, float y, float z_max, float sampling, int movement);
void Trajectory_Generator_Obs(float x, float y, float z_max, float sampling, int movement);
void Trajectory_Generator_Climbing(float x, float y, float z_max, float sampling, int movement);
void Trajectory_Generator_Obs_6S(float x, float y, float z_max, float sampling, int movement);
void Trajectory_Generator_Lean(float x, float y, float z_max, float sampling, int movement);

void Dynamx_Rot_Right_Cmps(int SPEED);

void Dynamx_MovFwd_Interpolate_6S(unsigned int distance, int SPEED, int IKCALC_STAT);
void Trajectory_Generator_6S(float x, float y, float z_max, float sampling, int movement);

void Dynamx_MovLeanFwd_Obstaicle_Interpolate(int SPEED, int limit);
void Dynamx_MovFwdClimbing_Interpolate(int SPEED, int limit, int movement);
void Dynamx_MovCrvRight_Climbing_Interpolate(int SPEED, int limit, int movement, volatile float *ACTUATE_SIGNAL);
void Dynamx_MovCrvLeft_Climbing_Interpolate(int SPEED, int limit, int movement, volatile float *ACTUATE_SIGNAL);
void Dynamx_MovFwdMiring_Interpolate(int SPEED, int limit, int movement);

#endif
