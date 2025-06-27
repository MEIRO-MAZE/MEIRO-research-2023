#include "bw_global_var.h"

/*
 * BW TCS3200 GLOBAL VARIABLES
 */

//OBSTAICLE VARIABLE
unsigned int OBSTAICLE_STAT = 0;

char tcs3200;

unsigned int COLOUR_BLACK	= 0;
unsigned int COLOUR_GRAY	= 1;
unsigned int COLOUR_WHITE	= 2;
unsigned int COLOUR_RED	    = 4;
unsigned int COLOUR_BLUE    = 5;

unsigned int F_DETECTED_COLOUR=0;
unsigned int M_DETECTED_COLOUR=0;

float F_sum_red=0, F_sum_blue=0, F_sum_white=0,F_sum_green, F_THRESHOLD=0, F_TOTAL_SUM=0;
float M_sum_red=0, M_sum_blue=0, M_sum_white=0,M_sum_green, M_THRESHOLD=0, M_TOTAL_SUM=0;

//TCS3200 MODE
unsigned int FRONT_TCS3200 = 1;
unsigned int MID_TCS3200   = 2;

//TRACER FLAG
//unsigned int TRACER_STAT=0;
unsigned int COLOUR_STAT;
unsigned int CANDLE_CIRCLE_FLAG = 0;
unsigned int CANDLE_CIRCLE_DETECTED =1;

int F_TRACER,M_TRACER,TRACER_FLAG;

/*
 * BW FOLLOW CARPET MACROS
 */
//unsigned int NORMAL  = 1;
//unsigned int INVERSE = 2;

/*
 *  BW HOME AND ZONE FLAG
 */


unsigned int INITIAL_ZONE=0;
unsigned int ZONE=0;

unsigned int ZONE_BLACK = 1;
unsigned int ZONE_RED   = 2;
unsigned int ZONE_BLUE  = 3;
unsigned int TRACER     = 4;

unsigned int BW_CROSS_MODE = 0;

//BW START MODE
unsigned int START_MODE=0;
enum BW_START_MODE {NON_ARBITRARY_START = 1, ARBITRARY_START = 2};


/*
 * BW ROOM AND CORRIDOR VARIABLES
 */
unsigned int BW_LOCATION[2]={1,0};
unsigned int LOCATION_CORRIDOR=0;
unsigned int LOCATION_ROOM=1;

unsigned int TANDA_FOLLOW[3]={0,0,0};
unsigned int FOLLOW_KIRI=1;
unsigned int FOLLOW_KANAN=2;

/*
 * BW FIRE FIGHTING VARIABLES
 */
unsigned int EXTINGUISHED_FIRE= 0;
unsigned int FIRE_PUTOFF=0;



/*
 * BW ROTARY SWITCH GLOBAL VARIABLES
 */
uint16_t rot_switch_mode;

/*
 * BW CAT OBSTACLE VARIABLES
 */
unsigned int CAT_FOUND[2]={0,0};
unsigned int CAT_SHIFT_FOLLOW=0;
unsigned int SHIFT_FOLLOW=1;
unsigned int NO_SHIFT=0;
volatile int coba_timer = 0;
int LEFT_FOLLOW_STATE = 0;
int RIGHT_FOLLOW_STATE = 0;
int FOLLOW_CARPET_MODE = 4;
int COLOUR_BUF = 4;
int ZERO_ERROR = 0;
int FOLLOW_TRACER_STATE = 0;


unsigned int CAT_FLAG			= 0;
unsigned int CAT_FLAG_A			= 0;
unsigned int CAT_FLAG_B			= 0;
unsigned int CAT_FLAG_C			= 0;
unsigned int CAT_DETECTED 		= 1;
unsigned int CAT_NOT_DETECTED 	= 0;

unsigned int CAT_DETECTOR = 0;
unsigned int CAT_ACTIVATED = 1;
unsigned int CAT_DIACTIVATED =0;
unsigned int CAT_IR1 = 0;
unsigned int CAT_IR2 = 0;

unsigned volatile int STAIRS_IR = 0;
unsigned int STAIRS_FLAG =0;
unsigned int STAIRS_DETECTOR=0;
unsigned const int STAIRS_DETECTED = 1;
unsigned const int STAIRS_NOT_DETECTED =0;
unsigned const int STAIRS_DETECTOR_ACTIVATED= 1;
unsigned const int STAIRS_DETECTOR_DEACTIVATED =0;

volatile unsigned int FOLLOW_MARK_L = 0, FOLLOW_MARK_R = 0;
/*
 * BW INFRARED PROXIMITY SENSOR
 */

int INFRARED[9];

/*
 * BW SOUND ACTIVATION VARIABLES
 */
uint16_t BW_Sound_Activate=0;

/*
 * BW REGULAR ACTIVATION VARIABLES
 */
uint16_t BW_START=0;
/*
 * BW HAMAMATSU UV-TRON GLOBAL VARIABLES
 */
unsigned int UV_state;
unsigned int UV_Lock=0;

unsigned int UV_R2FLAG=0;
unsigned int UV_R2FLAG_ACTIVE=1;
unsigned int UV_R2FLAG_INACTIVE=0;

/*
 * BW ROTARY SWITCH
 */
unsigned int ADCResult;

/*
 * BW LED BLINK INTERRUPT
 */
uint16_t led_counter=1;
uint16_t led_off_counter=0;
uint16_t led_snd_off_counter=0;

//--------Variable TPA n Servo---------//
int DATA;
int sudut_servo=0;
int PWM_FIRE;


//--------Variable UV tpa---------//
unsigned char sensor_UV_front=1,sensor_UV_back=1;
unsigned char sensor_UV_lock=0;
unsigned char fight=0;
unsigned char hitung=0;
unsigned int panas=0;
int regs;
int i=0, temp=0;
unsigned char suhu_ruang=0, suhu_pixel[8], pixel[10];



unsigned int FIRE=0;
unsigned int IK_CLIMBING = 0;


//USART COMM VARIABLES
char received_string[MAX_STRLEN],buf[16],data1_lcd[16],data2_lcd[16],tampil_adc[16];
int Ping[10] = {0,0,0,0,0,0,0,0,0,0},USART_Count=0;
unsigned int USARTFlame_Counter=0;
unsigned int USARTFlameDigi_Counter=0;
unsigned int USARTVL_Counter=0;
unsigned int USART_Bluetooth_Count=0;
unsigned int COMMAND_FLAG_A = 0x3C;
unsigned int COMMAND_FLAG_B = 0x3E;
unsigned int COMMAND_COMPLETED = 0x7C;
unsigned int COMMAND_NOT_RECEIVED = 0x3F;
char command_code[5];
unsigned int PING_F, PING_AR, PING_AL, PING_L, PING_R, PING_RR, PING_RL, PING_RE, PING_UR, PING_UL;

// BATAS JARAK DEPAN FOLLOW
unsigned int FRONT_THRESHOLD = 0;
unsigned int REAR_THRESHOLD = 14;

//SHARP IR RANGEFINDER
unsigned int SHARP[10];
unsigned int SHARP_GRIPPER[1]={0};

int counts,SHARP_FL_BUFFER,SHARP_BR_BUFFER,SHARP_BL_BUFFER;

int PING_ERROR[8] = {0,0,0,0,0,0,0,0}, ping_count = 0;
unsigned int Flame_Stat = 0;

//UV CONTROL SIGNAL TO STM32F1
int IN_ROOM_STAT = 1, NOT_IN_ROOM_STAT = 0;

int FWD_BREAK = 0;
int BWD_BREAK = 0;
//NEW VAR
unsigned int GERAK=0;

				  	 //COXA,FEMUR,TIBIA
int SUDUT_STATIC[18]={  90 ,  10 , 90 ,//FR
					    90 ,  13 , 101 ,//ML
					    90 ,  10 , 90 ,//RR

					    90 ,  10 , 90 ,//FL
					    90 ,  13 , 101 ,//MR
					    90 ,  10 , 90};//RL

	 //COXA,FEMUR,TIBIA
int SUDUT_STATIC_BWD[18]={  90 ,  15 , 105 ,	//FR
							90 ,  15 , 105 ,	//ML
							90 ,  15 , 105 ,	//RR

							90 ,  15 , 105 ,	//FL
							90 ,  15 , 105 ,	//MR
							90 ,  15 , 105 };	//RL

int SUDUT_ANGKAT=20;
int LIFT_ANGLE[3]= {9,16,21};
int DG_GRIP_DOWN = 175;
int DG_GRIP_UP = 145;

// ID
const unsigned int FRONT_LEFT_DX_COXA =	1;
const unsigned int FRONT_LEFT_DX_FEMUR=	2; //
const unsigned int FRONT_LEFT_DX_TIBIA=	3;

const unsigned int MIDDLE_LEFT_DX_COXA =	4;
const unsigned int MIDDLE_LEFT_DX_FEMUR=	5; //
const unsigned int MIDDLE_LEFT_DX_TIBIA=	6;

const unsigned int REAR_LEFT_DX_COXA 	=7;
const unsigned int REAR_LEFT_DX_FEMUR	=8; //
const unsigned int REAR_LEFT_DX_TIBIA	=9;

const unsigned int FRONT_RIGHT_DX_COXA =	10;
const unsigned int FRONT_RIGHT_DX_FEMUR=	11; //
const unsigned int FRONT_RIGHT_DX_TIBIA=	12;

const unsigned int MIDDLE_RIGHT_DX_COXA =	13;
const unsigned int MIDDLE_RIGHT_DX_FEMUR=	14; //
const unsigned int MIDDLE_RIGHT_DX_TIBIA=	15;

const unsigned int REAR_RIGHT_DX_COXA 	=16;
const unsigned int REAR_RIGHT_DX_FEMUR	=17; //
const unsigned int REAR_RIGHT_DX_TIBIA	=18;

const unsigned int GRIPPER_UP = 20;
const unsigned int GRIPPER_CLIP = 21;

const unsigned int CLEANER = 19;

const unsigned int DYNA_EXT_ID	=63;


int DX_count = 0;

int ESCAPE_HOME_FOLLOW = 0;
int HOME_FOLLOW_FLAG = 0;
int FOLLOW_HOME_KANAN = 0;
int FOLLOW_HOME_KIRI = 1;

int R4A_MID_FOLLOW = 0;
int R4B_MID_FOLLOW = 1;
int R4AB_KIRI_FOLLOW = 2;
int R4AB_KANAN_FOLLOW = 3;
int COMPASS_FOLLOW = 0;

int CURVE_STAT = 0; // 0 -> KIRI 1 -> KANAN


// MOV FWD ZCOXA = 30 and Z TIBIA = 30
int IKFWD_COXA_R[3]={18,27,28};
int IKFWD_TIBIA_R[3]={18,18,21};
int IKFWD_COXA_L[3]={18,27,28};
int IKFWD_TIBIA_L[3]={18,18,21};

//		Sementara
// MOV FWD ZCOXA = 20 and Z TIBIA = 20
int IKFWD_COXA_R1[3]={13,19,20};
int IKFWD_TIBIA_R1[3]={15,15,15};
int IKFWD_COXA_L1[3]={13,19,20};
int IKFWD_TIBIA_L1[3]={15,15,15};


// MOV FWD ZCOXA = 10 and Z TIBIA = 10
int IKFWD_COXA_R2[3]={6,11,8};
int IKFWD_TIBIA_R2[3]={9,1,11};
int IKFWD_COXA_L2[3]={6,11,8};
int IKFWD_TIBIA_L2[3]={9,1,11};

// MOV FWD ZCOXA = 5 and Z TIBIA = 5
int IKFWD_COXA_R3[3]={3,6,3};
int IKFWD_TIBIA_R3[3]={5,0,5};
int IKFWD_COXA_L3[3]={3,6,3};
int IKFWD_TIBIA_L3[3]={5,0,5};

float DELTA_TEST = 0;

// MOV ROT ZCOXA_L = 15
int IKROT_COXA[2]={0,0};

// MOV ROT ZCOXA_L = 10
int IKROT_COXA1[2]={0,0};

// MOV ROT ZCOXA_L = 5
int IKROT_COXA2[2]={0,0};

//SLOW
// MOV FWD SLOW ZCOXA = 20 and Z TIBIA = 20
//int IKFWD_COXA_R2[3]={8,22,17};
//int IKFWD_TIBIA_R2[3]={15,5,26};
//int IKFWD_COXA_L2[3]={8,22,17};
//int IKFWD_TIBIA_L2[3]={15,5,26};

// MOV CURVE RIGHT SLOW ZCOXA_L = 35, ZCOXA_R = 5 and ZTIBIA_L = 25, ZTIBIA_R = 5
int IKCRVR_COXA_R2[3]={3,6,3};
int IKCRVR_TIBIA_R2[3]={5,0,5};
int IKCRVR_COXA_L2[3]={8,22,17};
int IKCRVR_TIBIA_L2[3]={15,5,26};

// MOV PID CURVE RIGHT SLOW ZCOXA_L = 35, ZCOXA_R = 5 and ZTIBIA_L = 25, ZTIBIA_R = 5
int IKRPID_COXA_R2[3]={5,16,14};
int IKRPID_TIBIA_R2[3]={10,5,21};


// MOV CURVE RIGHT ZCOXA_L = 35, ZCOXA_R = 5 and ZTIBIA_L = 25, ZTIBIA_R = 5
int IKCRVR_COXA_R[3]={3,6,3};
int IKCRVR_TIBIA_R[3]={5,0,5};
int IKCRVR_COXA_L[3]={12,35,42};
int IKCRVR_TIBIA_L[3]={17,7,36};

// MOV PID CURVE RIGHT ZCOXA_L = 35, ZCOXA_R = 5 and ZTIBIA_L = 25, ZTIBIA_R = 5
int IKRPID_COXA_R[3]={9,29,39};
int IKRPID_TIBIA_R[3]={12,7,31};

// MOV SLIDE RIGHT X = 20
int IKSLR_COXA[3]={16,0,23};
int IKSLR_TIBIA[4]={7,18,30,17};

// MOV SLIDE RIGHT X = 15
int IKSLR_COXA1[3]={13,0,17};
int IKSLR_TIBIA1[4]={6,14,21,12};

// MOV SLIDE RIGHT X = 10
int IKSLR_COXA2[3]={9,0,11};
int IKSLR_TIBIA2[4]={5,10,13,7};

// MOV CURVE LEFT ZCOXA_R = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 35
int IKCRVL_COXA_R[3]={12,35,42};
int IKCRVL_TIBIA_R[3]={17,7,36};
int IKCRVL_COXA_L[3]={3,6,3};
int IKCRVL_TIBIA_L[3]={5,0,5};

// MOV PID CURVE LEFT ZCOXA_L = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 25
int IKLPID_COXA_L[3]={9,29,39};
int IKLPID_TIBIA_L[3]={12,7,31};

//SLOW
// MOV CURVE LEFT SLOW ZCOXA_R = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 35
int IKCRVL_COXA_R2[3]={8,22,17};
int IKCRVL_TIBIA_R2[3]={15,5,26};
int IKCRVL_COXA_L2[3]={3,6,3};
int IKCRVL_TIBIA_L2[3]={5,0,5};

// MOV PID CURVE LEFT SLOW ZCOXA_L = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 25
int IKLPID_COXA_L2[3]={5,16,14};
int IKLPID_TIBIA_L2[3]={10,5,21};

// MOV SLIDE LEFT X = 20
int IKSLL_COXA[3]={16,0,23};
int IKSLL_TIBIA[4]={7,18,30,17};

// MOV SLIDE LEFT X = 15
int IKSLL_COXA1[3]={13,0,17};
int IKSLL_TIBIA1[4]={6,14,21,12};

// MOV SLIDE LEFT X = 10
int IKSLL_COXA2[3]={9,0,11};
int IKSLL_TIBIA2[4]={5,10,13,7};

//// MIRING SPEED ULTRAFAST
//// MOV SLIDE LEFT X = 15
//int IKSLL_COXA[3]={13,0,17};
//int IKSLL_TIBIA[4]={6,14,21,12};
//
//// MOV SLIDE LEFT X = 10
//int IKSLL_COXA1[3]={9,0,11};
//int IKSLL_TIBIA1[4]={5,10,13,7};
//
//// MOV SLIDE LEFT X = 5
//int IKSLL_COXA2[3]={5,0,5};
//int IKSLL_TIBIA2[4]={2,5,6,3};


//// MOV BWD ZCOXA = 35 and Z TIBIA = 25
//int IKBWD_COXA_R[3]={12,35,42};
//int IKBWD_TIBIA_R[3]={17,7,36};
//int IKBWD_COXA_L[3]={12,35,42};
//int IKBWD_TIBIA_L[3]={17,7,36};

// MOV BWD ZCOXA = 15 and Z TIBIA = 15
int IKBWD_COXA_R[3]={7,17,12};
int IKBWD_TIBIA_R[3]={12,3,18};
int IKBWD_COXA_L[3]={7,17,12};
int IKBWD_TIBIA_L[3]={12,3,18};

//// MOV CURVE RIGHT REVERSE ZCOXA_L = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 25
//int IKCRVRR_COXA_L[3]={3,6,3};
//int IKCRVRR_TIBIA_L[3]={5,0,5};
//int IKCRVRR_COXA_R[3]={12,35,42};
//int IKCRVRR_TIBIA_R[3]={17,7,36};
//
//// MOV PID CURVE RIGHT REVERSE ZCOXA_L = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 25
//int IKPIDR_COXA_L[3]={9,29,39};
//int IKPIDR_TIBIA_L[3]={12,7,31};
//
//// MOV CURVE LEFT REVERSE ZCOXA_R = 35, ZCOXA_R = 5 and ZTIBIA_L = 25, ZTIBIA_R = 5
//int IKCRVLR_COXA_L[3]={12,35,42};
//int IKCRVLR_TIBIA_L[3]={17,7,36};
//int IKCRVLR_COXA_R[3]={3,6,3};
//int IKCRVLR_TIBIA_R[3]={5,0,5};
//
//// MOV PID CURVE LEFT REVERSE ZCOXA_L = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 25
//int IKPIDR_COXA_R[3]={9,29,39};
//int IKPIDR_TIBIA_R[3]={12,7,31};

// MOV CURVE RIGHT REVERSE ZCOXA_L = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 25
int IKCRVRR_COXA_L[3]={3,6,3};
int IKCRVRR_TIBIA_L[3]={5,0,5};
int IKCRVRR_COXA_R[3]={7,17,12};
int IKCRVRR_TIBIA_R[3]={12,3,18};

// MOV PID CURVE RIGHT REVERSE ZCOXA_L = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 25
int IKPIDR_COXA_L[3]={4,11,9};
int IKPIDR_TIBIA_L[3]={7,3,13};

// MOV CURVE LEFT REVERSE ZCOXA_R = 35, ZCOXA_R = 5 and ZTIBIA_L = 25, ZTIBIA_R = 5
int IKCRVLR_COXA_L[3]={7,17,12};
int IKCRVLR_TIBIA_L[3]={12,3,18};
int IKCRVLR_COXA_R[3]={3,6,3};
int IKCRVLR_TIBIA_R[3]={5,0,5};

// MOV PID CURVE LEFT REVERSE ZCOXA_L = 5, ZCOXA_R = 35 and ZTIBIA_L = 5, ZTIBIA_R = 25
int IKPIDR_COXA_R[3]={4,11,9};
int IKPIDR_TIBIA_R[3]={7,3,13};

/*
 * BW HEXAPOD VARIABLES
 */

//uint32_t CCR1_Val, CCR2_Val, CCR3_Val;
uint32_t Count;
uint32_t nCount;

int sudut_target[18],sudut_awal[18],x=0,z_A[18],pembagi,y_A[18],sudut_tahap1[18],sudut_tahap2[18];

//float gamma[6];
int leg;
int ww[6];
float beta[6];
float leg_next[6];
float A_body;			// translasi pusat badan
float A_leg[6];			// translasi setiap pangkal kaki
float P_body;			// jarak titik pusat robot ke titik imajiner putar
int epsilon_body;		// besar sudut vektor hadap thdp vektor poros-imajiner
float phi[6];
float lambpsi[6];		//lambda / psi temporal
float P_leg[6];			// jarak titik pusat kaki ke titik imajiner putar
float epsilon[6];		// epsilon tiap N

unsigned int sudut[18]= {4915,4915,4915,4915,4915,4915,    	//3615 == 1 ms   4915 == 1,5 ms
						 4915,4915,4915,4915,4915,4915,			//6550 == 2 ms
						 4915,4915,4915,4915,4915,4915};

unsigned char y,a,b,c,d,v,index_bantu,index_servo3,index_servo2;
uint32_t PrescalerValue;

    const float A_const[18] ={26.68,26.68,26.68,26.68,26.68,26.68,
    		 	 	 	 	  26.68,26.68,26.68,26.68,26.68,26.68,
    		 	 	 	 	  26.68,26.68,26.68,26.68,26.68,26.68
    						  /*13.33,50,13.33,13.33,50,13.33,
                              18.18,18.18,18.18,18.18,18.18,18.18,
                              18.18,18.18,18.18,18.18,18.18,18.18*/ };

    const int B_const[18]   ={2681,2681,2681,2681,2681,2681,
    		2681,2681,2681,2681,2681,2681,
    		2681,2681,2681,2681,2681,2681
			  	  	  	  	  /*1800,-1500,1800
							  ,1800,-1500,1800,
                              1364,1364,1364,1364,1364,1364,
                              1364,1364,1364,1364,1364,1364*/};

    //LAST REVISED BY RYAN: MON, APRIL 2nd, 2015
     float correct[18]        ={/*0,0,0,0,0,0,					0,0,0,0,0,0
			  	  	  	  	  0,0,0,0,0,0,						100,35,93,43,105,37
			  	  	  	  	  0,0,0,0,0,0						121,41,103,37,102,30*/
    							/*
//JANGAN ADA NILAI (-)			* LEFT SECTION
    		    				* Coxa,Femur,Tibia
    		    				* Coxa ditambah makin ke belakang
    		    				* Femur ditambah makin turun
    		    				* Tibia ditambah makin masuk ke dalam
    		    				*
    		    				*/
//    		 	 	 	 	 	10,40,40,	//FRONT LEFT LEG
//    		 	 	 	 	 	19,40,40,	//FRONT LEFT LEG
    		 	 	 	 	 	24,100,13,	//FRONT LEFT LEG

//    		 	 	 	 	 	10,42,31,	//MIDDLE LEFT LEG
//    		 	 	 	 	 	16,42,31,	//MIDDLE LEFT LEG
    		 	 	 	 	 	22,124,22,	//MIDDLE LEFT LEG

//    		 	 	 	 	 	10,25,24,	//REAR LEFT LEG
//    		 	 	 	 	 	44,25,24,	//REAR LEFT LEG
    		 	 	 	 	 	0,98,6,	//REAR LEFT LEG

    		    		 	 	 /* RIGHT SECTION
    		    		 	 	 * Coxa,Femur,Tibia
    		    		 	 	 * Coxa ditambah makin ke belakang
    		    		 	 	 * Femur ditambah makin turun
    		    		 	 	 * Tibia ditambah makin masuk ke dalam
    		    		 	 	 */

//    		 	 	 	 	 	 10,40,22,	//FRONT RIGHT LEG
//    		 	 	 	 	 	 37,40,22,	//FRONT RIGHT LEG
    		 	 	 	 	 	 35,53,14,	//FRONT RIGHT LEG

//    		 	 	 	 	 	 10,20,105,	//MIDDLE RIGHT LEG
//    		 	 	 	 	 	 28,20,105,	//MIDDLE RIGHT LEG
    		 	 	 	 	 	 30,115,13,	//MIDDLE RIGHT LEG

//    		 	 	 	 	 	 10,55,19,	//REAR RIGHT LEG
//    		 	 	 	 	 	 65,55,19,	//REAR RIGHT LEG
    		 	 	 	 	 	 38,94,6,	//REAR RIGHT LEG
    						  };
/*
    const float leg_1[6]	=	{8.2802,4.5,8.2802,8.2802,4.5,8.2802};	//L1
    const float leg_norm[6]	=	{9.5,9.5,9.5,9.5,9.5,9.5};				//L2
    const float alpha[6]	=	{30,90,150,30,90,150};					//alpha
*/
     const float leg_1[6]	=	{7.27,5.06,7.27,7.27,5.06,7.27};	//L1
//     const float leg_norm[6]=	{11,11,11,11,11,11};				//L2
     const float leg_norm[6]=	{8,8,8,8,8,8};				//L2
     const float alpha[6]	=	{30,90,150,30,90,150};					//alpha


float c1,c2;
float Lsem,c3,c4;
int i;
float temp_var,temp_var2;


/*
 * MPU6050 GYRO ACCELEROMETER VARIABLES
 */

unsigned int MPU6050_PWR_MGMT_1  = 0x6B;
unsigned int MPU6050_GYRO_CONFIG = 0x1B;
unsigned int MPU6050_ACCEL_CONFIG = 0x1C;
float Gyro_Mult;
//GYROSCOPE SENSITIVITY
unsigned int Gyro_Sensitivity_250s = 0x00;  /*!< Range is +- 250 degrees/s */
unsigned int Gyro_Sensitivity_500s = 0x01;  /*!< Range is +- 500 degrees/s */
const unsigned int Gyro_Sensitivity_1000s = 0x02; /*!< Range is +- 1000 degrees/s */
const unsigned int Gyro_Sensitivity_2000s = 0x03;  /*!< Range is +- 2000 degrees/s */

//ACCELEROMETER RANGE
unsigned int Accelerometer_Range = 0x00;
float Acce_Mult;

float ACCEL_DEG;
float GYRO_DEG;

//MPU6050 RECEIVER VARIABLEs
unsigned int IMU_SLAVE_DATA[4] = {0,0,0,0};
int YAW_IMU;
int PITCH_IMU;
int ROLL_IMU;
/*
 * CALCULATING DISTANCE
 */
double PI = 3.1415926535897932384626433832795;
double GRAVITY = 9806.65;

float dummy_correct[18];
unsigned int TEST = 0x5A;

/*
 * BW RUNTIME CALIBRATION VARIABLES
 */
int CALIBRATION_STAT=1;

/*
 *  BW ROOM COUNTER
 */

unsigned int ROOM_COUNTER=0;

/*
 * BW WARZONE FLAG
 */
unsigned int WARZONE_FLAG=0;
unsigned int SPECIAL_ZONE_FLAG=0;

/*
 * BW HOME CIRCLE
 */
unsigned int HOME_CIRCLE_FLAG 			= 0;
unsigned int HOME_CIRCLE_DETECTED 		= 1;
unsigned int HOME_CIRCLE_NOT_DETECTED 	= 0;

/*
 * FOLLOW HOME FLAG
 */
unsigned int FOLLOWHOME_FLAG			= 0;
unsigned int FOLLOWHOME_INACTIVE		= 0;
unsigned int FOLLOWHOME_ACTIVE			= 1;


/*
 * BW FIRE TRACKER COUNTER
 */
unsigned int firetrack_counter=0;


/*
 * BW FOUND FIRE OVERRIDE
 */
unsigned int BW_FOUND_FIRE_OVERRIDE=0;

/*
 * BW EXTINGUISHER FLAG
 */
unsigned int EXTINGUISHER_FLAG=0;

/*
 * BW ROOM 1 FLAG
 */
unsigned int ROOM1_FLAG=0;

/*
 * BW ROOM 1BC FLAG
 */
unsigned int ROOM1BC_FLAG=0;

/*
 * BW ROOM 2B FLAG
 */
unsigned int ROOM2B_FLAG=0;

/*
 * BW WARZONE COUNTER
 */
unsigned int WARZONE_COUNTER=0;

/*
 * BW GLOBAL COUNTER
 */
unsigned int global_counter=0;

/*
 * BW CROSS_ZONE VARIABLES
 */
unsigned int BW_CROSSING_AUTHORITY=0;
unsigned int CROSS_DISABLED=0;
unsigned int CROSS_ENABLED=1;
unsigned int BW_CROSSING_STATUS=0;
unsigned int NO_CROSSING=0;
unsigned int CROSSING_SUCCESS=1;
unsigned int CROSSING_FAILED=2;

/*
 *  BW STEAL ENEMY FIRE VARIABLES
 */
unsigned int STEAL_FIRE_STAT=0;
unsigned int STEAL_FIRE_COUNTER=0;
unsigned int STEALFIRE_SUCCESS=1;
unsigned int STEALFIRE_FAILED=2;
unsigned int ENEMY_ZONE_STAT=0;
unsigned int ENEMY_ZONE=1;
unsigned int COMFORT_ZONE=0;

/*
 * BW SPECIAL_CONDITION_FLAG
 */
unsigned int SPECIAL_CONDITION_FLAG=0;
unsigned int SPECIAL_CONDITION_ENABLED=1;
unsigned int SPECIAL_CONDITION_DISABLED=0;
unsigned int SPECIAL_CONDITION_COUNTER=0;
/*
 * BW ROOM FLAG
 */
//DEFAULT: PREVIOUS & PRESENT: OTHER ROOM
unsigned int ROOM_FLAG[2]={1,1};
unsigned int PRESENT_ROOM=0;
unsigned int PREVIOUS_ROOM=1;
unsigned int OTHER_ROOM=1;
unsigned int ROOM_ONE=2;
unsigned int WARZONE=3;

/*
 * BW VARIABLE DOOR
 */
unsigned int VARIABLE_DOOR=0;
unsigned int VAR_DOOR_NOT_DETECTED=0;
unsigned int VAR_DOOR_DETECTED=1;
unsigned int VAR_DOOR_SCAN=2;

/*
 * FIRST CAT ENCOUNTER
 */
unsigned int FIRST_CAT_ENCOUNTER=0;


/*
 * RETURN COUNTER
 */
unsigned int RETURN_COUNTER=0;

/*
 * FOLLOW CARPET FLAG
 */
unsigned int FOLLOW_CARPET_FLAG=0;
unsigned int FOLLOW_CARPET_ENABLED=1;
unsigned int FOLLOW_CARPET_DISABLED=0;
unsigned int FOLLOW_CARPET_ESCAPE_TRAP=2;

/*
 * RETURN
 */
//unsigned int RETURN_FLAG;
//unsigned int RETURN_ENABLED;
//unsigned int RETURN_DISABLED;

// MOVEMENT BREAK
//unsigned int CAT_BREAK = 0, TRACER_COLOR_BREAK = 0;


/*
 * BW ARTICULATED MANIPULATOR VARIABLES
 */

int Arm_Angle[3]={0,0,0};
int Arm_Correction[3]= {0,0,0};

uint32_t ARM_CCR1_Val, ARM_CCR2_Val, ARM_CCR3_Val;

/*
 * I2C MULTIBYTE READ
 */
uint8_t    I2C1_DATA[10];
uint8_t    I2C2_DATA[10];
uint8_t	   I2C3_DATA[10];
/*
 * CMPS11 VARIABLES
 */
/*
 *  CMPS-11 SERIAL COMMANDS
 */

unsigned int GET_VERSION 			= 0x11;
unsigned int GET_ANGLE_8_BIT 		= 0x12;
unsigned int GET_ANGLE_16_BIT		= 0x13;
unsigned int GET_PITCH 				= 0x14;
unsigned int GET_ROLL 				= 0x15;
unsigned int GET_PITCH_NO_KF 		= 0x16;
unsigned int GET_ROLL_NO_KF 		= 0x17;
unsigned int GET_MAG_RAW 			= 0x19;
unsigned int GET_ACCEL_RAW 			= 0x20;
unsigned int GET_GYRO_RAW 			= 0x21;
unsigned int GET_TEMP     		   	= 0x22;
unsigned int GET_ALL      		   	= 0x23;
unsigned int CALIBRATE_BYTE_1 	   	= 0xF0;
unsigned int CALIBRATE_BYTE_2 	   	= 0xF5;
unsigned int CALIBRATE_BYTE_3_FULL 	= 0xF6;
unsigned int CALIBRATE_BYTE_3_FLAT 	= 0xF7;
unsigned int CALIBRATE_EXIT       	= 0xF8;
unsigned int RESTORE_1             	= 0x6A;
unsigned int RESTORE_2             	= 0x7C;
unsigned int RESTORE_3             	= 0x81;
unsigned int BAUD_19200            	= 0xA0;
unsigned int BAUD_38400            	= 0xA1;

unsigned int USART2_DATA[6]={0,0,0,0,0,0};
unsigned int CMPS11_COMPASS_ANGLE =0;

int CMPS11_Angle;
int CMPS11_Angle16bit;
int8_t CMPS11_Pitch=0;
volatile int COMPASS_INTERRUPT = 0;
int Calibration_Status;
int selisih_CMPS;
/*
 * RETURN TRIP FLAG
 */
unsigned int RETURN_TRIP_FLAG=0;

/*
 * FLAME SENSOR VARIABLES
 */
unsigned int FlameSense[2]={0,0};
unsigned int FollowFlame_Flag=0,FlameTrack_Flag=0,FlameScan_Flag=0,FlameExtinguish_Flag=0,FlameApproach_Flag=0;

unsigned int FlameSenseDigi[2]={0,0};
unsigned int FlameFrontDigi[2]={0,0};

char FlameValueNew[6]={'A','B','C','D','E','F'};
char FlameState;

int UV_VARIABLE=0;
int UV_VARIABLE2=0;
int RANK[8] = {0,0,0,0,0,0,0,0};

int ENABLE_UV1 = 1;
int ENABLE_UV2 = 1;
int DUMMY_VAR = 0;

//VL VARIABLE
//unsigned int VL_SENSOR[1]={0};

/*
 * 	BW CONTACT BUMPER
 */
unsigned int BUMPER[2]={0,0};


/*
 * BW TCS3200 SLAVE VARIABLES
 */

unsigned int TRACER_GRIPPER = 1;
unsigned int TRACER_BOTTOM = 2;
unsigned int TCS3200_SLV_CNT=0;
unsigned int TCS34725_SLV_CNT=0;
unsigned int TCS3200_SLV_STAT[4]={0,0,0,0};
unsigned int TCS34725_SLV_STAT[4]={0,0,0,0};
unsigned int FRONT_PRESENT        = 0;
unsigned int FRONT_PREVIOUS       = 1;
unsigned int MIDDLE_PRESENT       = 2;
unsigned int MIDDLE_PREVIOUS      = 3;
unsigned int TCS3200_SLV_DATA[11]={0,0,0,0,0,0,0,0,0,0,0};
unsigned int TCS3200_SLV_BUF[14]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
unsigned int TCS34725_SLV_BUF[14]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};
unsigned int TCS34725_SLV_DATA[11]={0,0,0,0,0,0,0,0,0,0,0};
unsigned int VL_SENSOR[1]={0};
unsigned int VL_Value[2]={0,0};
unsigned int Done;

unsigned int DUMMY_DATA_A= 0x41;
unsigned int DUMMY_DATA_G= 0x47;

unsigned int TCS3200_CMD_CODE[5]={0,0,0,0,0};

const int TCS_CALIBRATE_WHITE           = 0x46;
const int TCS_CALIBRATE_BLACK           = 0x47;
const int TCS_CALIBRATE_GRAY            = 0x48;
const int TCS_CALIBRATE_GETRULE         = 0x49;

const int TCS_FRONT_SHOW_THRESHOLD      = 0x4A;
const int TCS_MIDDLE_SHOW_THRESHOLD     = 0x4B;

unsigned int TRIAL_MODE			= 0x41;
unsigned int CALIBRATION_MODE	= 0x42;

//unsigned int CALIBRATE_BLACK    = 0x43;
//unsigned int CALIBRATE_GRAY     = 0x44;
//unsigned int CALIBRATE_WHITE	= 0x45;

unsigned int START_BUTTON_CMD	= 0x53;
unsigned int BUTTON_A			= 0x41;
unsigned int BUTTON_B			= 0x42;
unsigned int CMD_COMPLETED		= 0x58;
unsigned int CMD_IDLE			= 0x5E;
unsigned int TRACER_CMD_SEND_RGB= 0x70;

//SENT COMMAND DATA
//unsigned int TCS_CMD_SEND_FRONT  	 = 0x41;
//unsigned int TCS_CMD_SEND_MIDDLE 	 = 0x42;
unsigned int TCS_CMD_SEND_RAW		 = 0x41;
unsigned int TRACER_CMD_SEND_RAW	 = 0x42;
const int IMU_CMD_SEND_RAW			 = '1';
const int SOUNDCHECK		 		 = '2';
unsigned int TCS_CMD_SEND_CONCLUSION = 0x43;
unsigned int TCS_CMD_SAVE_EEPROM     = 0x5A;
unsigned int BW_SOUND_ACTIVATED		 = 0x77;

unsigned int HYBRID_CMD_SEND_THRESHOLD= 0x58;

volatile unsigned int DATA_TRACER_READY = 0;
volatile unsigned int DATA_TRACER_GRIP_READY = 0;


/*
 * TCS3200+TRACER NEW COMMAND FOR OPTMIZATION
 */
unsigned int CMD_GET_TCS3200		= 0x52;
unsigned int CMD_GET_TRACER		= 0x53;
unsigned int CMD_TRACER_COPY_DATA = 0xFE;

/*
 * FOLLOWMODE FLAG
 */
unsigned int FOLLOWMODE_FLAG= 0;
const unsigned int FOLLOW_TRACER_WHITE= 1;
const unsigned int FOLLOW_CARPET_ACTIVE= 2;
const unsigned int FOLLOW_COLOUR_DISABLE= 0;

/*
 *  PHOTODIODE TRACER CALIBRATION COMMAND
 */

//BLACK/WHITE PHOTODIODE TRACER PROCESSOR COMMAND
const int TRACER_CALIBRATE_GRAY             = 0x4A;
const int TRACER_CALIBRATE_WHITE            = 0x4B;
const int TRACER_CALIBRATE_BLACK            = 0x4D;
const int TRACER_CALIBRATE_GETRULE          = 0x4C;

//RECEIVED DATA
unsigned int RCV_IDLE  		= 94;
unsigned int RCV_START 		= 53;
unsigned int RCV_BUTTON_A 	= 41;
unsigned int RCV_BUTTON_B	= 42;



/*
 * ROOM IDENTIFIER VARIABLES
 */

unsigned int HOME;

//ROOM[0] == DUMMY DATA / UNUSED
unsigned int ROOM[6]={99,13,13,13,13,13};

unsigned int HALLWAY_SC = 0;

unsigned int ROOM_1A 	= 1;
unsigned int ROOM_1B	= 2;
unsigned int ROOM_1C	= 3;

unsigned int ROOM_2A 	= 4;
unsigned int ROOM_2B	= 5;

unsigned int ROOM_3 	= 6;

unsigned int ROOM_4A 	= 7;
unsigned int ROOM_4B	= 8;





unsigned int ROOM_TYPE		= 0;
unsigned int NORMAL_ROOM	= 2;
unsigned int GRAY_ROOM 		= 1;

unsigned int HOME_POS	=0;
unsigned int TENGAH		=1;
unsigned int POJOK		=2;



/*
 * TRACER DETECTED IN BUMPER HANDLER ROUTINES
 */
unsigned int TRACER_IN_BUMPER;
unsigned int TRC_BMP_ACTIVE=1;
unsigned int TRC_BMP_INACTIVE=0;

/*	NASIPNAL
 * TRACER STATUS VARIABLES

unsigned int TRACER_STAT=0;
unsigned int TRACER_WHITE=1;					// diganti dengan TRACER_WHITE, GRAY dan BLACK untuk board yang pakai tracer aja
unsigned int TRACER_INACTIVE=0;
*/
/*
 * TRACER STATUS VARIABLES
 */
unsigned int TRACER_STAT=0;
unsigned int TRACER_WHITE=2;
unsigned int TRACER_BLACK=0;
unsigned int TRACER_GRAY=1;
unsigned int TRACER_BREAK=0;
unsigned int NO_FOLLOW = 3;
/*
 * FOLLOW TRACER FLAG VARIABLES
 */
unsigned int FOLLOWTRACER_FLAG=0;
unsigned int FOLLOWTRACER_ENABLE=1;
unsigned int FOLLOWTRACER_DISABLE=0;

/*
 * FLAME SENSOR VARIABLES
 */

unsigned int FLAME_SENSOR[2];

/*
 * MOV FLAME SENSOR SIDE
 */
unsigned int FLAME_SIDE;

/*
 * CANDLE STATUS
 */
unsigned int CANDLE_STICK=0;
unsigned int CANDLE_FIRE=0;
unsigned int CANDLE_STAT=0;

unsigned int SP_FIRE_1B;
unsigned int SP_FIRE_1C;
unsigned int SP_FIRE_R3;
unsigned int SP_FIRE_ACTIVE=1;
unsigned int SP_FIRE_INACTIVE=0;

//flag masuk ruangan
unsigned int FLAG_ROOM_1A;
unsigned int FLAG_ROOM_1B;
unsigned int FLAG_ROOM_1C;
unsigned int FLAG_ROOM_2;
unsigned int FLAG_ROOM_3;
unsigned int FLAG_ROOM_4A;
unsigned int FLAG_ROOM_4B;
unsigned int FLAG_ROOM_ACTIVE=1;
unsigned int FLAG_ROOM_INACTIVE=0;


/*
 *  EXIT FLAG
 */
unsigned int EXIT_FLAG;
unsigned int EXIT_ACTIVE=1;
unsigned int EXIT_INACTIVE=0;

unsigned int FOLLOW_FLAG;
unsigned int FLAME=5;
unsigned int KANAN_BELAKANG=4;
unsigned int KIRI_BELAKANG=3;
unsigned int KANAN=2;
unsigned int KIRI=1;
unsigned int KOSONG=0;
unsigned int KANAN_OBS = 6;
unsigned int KIRI_OBS = 7;

unsigned int FOLLOW_BREAK;
unsigned int FOLLOW_CALC;


/*
 *  ROOM 2 FLAG
 */
unsigned int ROOM1_FLAG;
unsigned int ROOM1FLAG_ACTIVE=1;
unsigned int ROOM1FLAG_INACTIVE=0;

/*
 *  ROOM 1BC FLAG
 */
unsigned int ROOM1BC_FLAG;
unsigned int ROOM1BCFLAG_ACTIVE=1;
unsigned int ROOM1BCFLAG_INACTIVE=0;

/*
 * ROOM 2B FLAG
 */
unsigned int ROOM2B_FLAG;
unsigned int ROOM2BFLAG_ACTIVE=1;
unsigned int ROOM2BFLAG_INACTIVE=0;

/*
 * ROOM 4 FLAG
 */
unsigned int ROOM4_FLAG;
unsigned int ROOM4FLAG_ACTIVE=1;
unsigned int ROOM4FLAG_INACTIVE=0;

/*
 * ROOM 4A FLAG
 */
unsigned int ROOM4A_FLAG;
unsigned int ROOM4AFLAG_ACTIVE=1;
unsigned int ROOM4AFLAG_INACTIVE=0;

/*
 * ROOM 4B FLAG
 */
unsigned int ROOM4B_FLAG;
unsigned int ROOM4BFLAG_ACTIVE=1;
unsigned int ROOM4BFLAG_INACTIVE=0;

/*
 * ROOM 4B_EXIT FLAG
 */
unsigned int ROOM4B_EXIT_FLAG;
unsigned int ROOM4BFLAG_EXIT_ACTIVE=1;
unsigned int ROOM4BFLAG_EXIT_INACTIVE=0;

/*
 * ROOM1A SPECIAL EXIT FLAG
 */
unsigned int ROOM1A_SP_EXIT_FLAG;
unsigned int ROOM1A_SP_EXIT_FLAG_ACTIVE=1;
unsigned int ROOM1A_SP_EXIT_FLAG_INACTIVE=0;

/*
 * ROOM4A CAT AVOIDER
 */
unsigned int ROOM4A_CAT_AVOIDER;
unsigned int ROOM4A_CAT_AVOIDER_ACTIVE = 1;
unsigned int ROOM4A_CAT_AVOIDER_INACTIVE = 0;


/*
 * SPECIAL ROUTE FOR RETURN TRIP R2 TO R4A
 * HOME: R4A
 * FIRE ROOM: R2
 * CAT CONFIG: A
 */
unsigned int R2TO4A_SP_ROUTE=0;
unsigned int R2TO4A_SP_ACTIVE=1;
unsigned int R2TO4A_SP_INACTIVE=0;

unsigned int R4ATO3_SP_ROUTE=0;
unsigned int R4ATO3_SP_ACTIVE=1;
unsigned int R4ATO3_SP_INACTIVE=0;


unsigned int SP_ROUTE_ACTIVE=1;
unsigned int SP_ROUTE_INACTIVE=0;

/*
 *  SPECIAL ROUTE FOR RETURN TRIP R4A TO R2
 *  HOME: R2
 *  FIRE ROOM: R4A
 *  CAT CONFIG: A
 */
unsigned int R4ATO2_SP_ROUTE=0;

/*
 *  SPECIAL ROUTE FOR RETURN TRIP R4A TO R1
 *  HOME: R1
 *  FIRE ROOM: R4A
 *  CAT CONFIG: B
 */
unsigned int R4ATO1_SP_ROUTE=0;


/*
 * CAT SHIFT ALGORITHM FLAG
 */
unsigned int SHIFT_ALGORITHM_FLAG;
unsigned int SHIFT_ALGORITHM_ACTIVE=1;
unsigned int SHIFT_ALGORITHM_INACTIVE=0;


/*
 *  DEFLECT WALL OVERFLOW COUNTER
 */

int RIGHT_OVERFLOW_COUNTER=0;
int LEFT_OVERFLOW_COUNTER=0;


/*
 *  BW TURNAROUND NAVIGATION
 */
unsigned int TURN_LEFT  = 1;
unsigned int TURN_RIGHT = 2;


/*
 * BW FIRE SCAN DIRECTION FLAG
 */
unsigned int FIRESCAN_DIRECTION=0;
#define SCAN_LEFT 1
#define SCAN_RIGHT  2
#define NO_WALL_PARAM 3

/*
 * BW FIREFIGHT SUCCESS TURN AROUND
 */
unsigned int BW_TurnAround = 0;

#define INACTIVE 0
#define ACTIVE 1

/*
 * BW FOWARD REVERSE FLAG
 */
unsigned int REVERSE_FLAG;
unsigned int REVERSEFLAG_ACTIVE=1;
unsigned int REVERSEFLAG_INACTIVE=0;

int cnt=0;
int FRONT, MIDDLE, REAR;
int BACA[4]={0,0,0,0};
int KONSTANTA[2]={0,0};
int VALUE;

//=============================================================================================//
//					CAUTION! THESE VARIABLES NEEDS TO BE CALIBRATED CORRECTLY                  //
//=============================================================================================//
/*
 *  COMPASS ARENA FLAG
 */
unsigned int CMPS_ACTIVE	=1;
unsigned int CMPS_INACTIVE	=0;
unsigned int ARENA_FLAG		=0;
unsigned int TRESH_UPPER	=1;
unsigned int TRESH_LOWER	=2;
unsigned int TRESH_FLAG		=0;

unsigned int NORTH_THRESHOLD_UPPER=178;
unsigned int NORTH_THRESHOLD_LOWER=152;
unsigned int NORTH_THRESHOLD_MIDDLE=(178+152)/2;
unsigned int WEST_THRESHOLD_UPPER=248;
unsigned int WEST_THRESHOLD_LOWER=222;
unsigned int WEST_THRESHOLD_MIDDLE=(248+222)/2;
unsigned int SOUTH_THRESHOLD_UPPER=358;
unsigned int SOUTH_THRESHOLD_LOWER=328;
unsigned int SOUTH_THRESHOLD_MIDDLE=(358+332)/2;
unsigned int EAST_THRESHOLD_UPPER=113;
unsigned int EAST_THRESHOLD_LOWER=87;
unsigned int EAST_THRESHOLD_MIDDLE= (113+87)/2;

unsigned int NORTH_UP = 0;
unsigned int NORTH_LOW = 0;
unsigned int SOUTH_UP = 0;
unsigned int SOUTH_LOW = 0;
unsigned int EAST_UP = 0;
unsigned int EAST_LOW = 0;
unsigned int WEST_UP = 0;
unsigned int WEST_LOW = 0;
unsigned int NORTH = 0;
unsigned int SOUTH = 0;
unsigned int EAST = 0;
unsigned int WEST = 0;

//2023 LABROBOT GED C
unsigned int K1_NORTH = 0;
unsigned int K1_NORTH_UP = 0;
unsigned int K1_NORTH_LOW = 0;
unsigned int K1_SOUTH = 0;
unsigned int K1_SOUTH_UP = 0;
unsigned int K1_SOUTH_LOW = 0;
unsigned int K1_EAST = 0;
unsigned int K1_EAST_UP = 0;
unsigned int K1_EAST_LOW = 0;
unsigned int K1_WEST = 0;
unsigned int K1_WEST_UP = 0;
unsigned int K1_WEST_LOW = 0;

unsigned int K2_NORTH = 0;
unsigned int K2_NORTH_UP = 0;
unsigned int K2_NORTH_LOW = 0;
unsigned int K2_SOUTH = 0;
unsigned int K2_SOUTH_UP = 0;
unsigned int K2_SOUTH_LOW = 0;
unsigned int K2_EAST = 0;
unsigned int K2_EAST_UP = 0;
unsigned int K2_EAST_LOW = 0;
unsigned int K2_WEST = 0;
unsigned int K2_WEST_UP = 0;
unsigned int K2_WEST_LOW = 0;

unsigned int R9_NORTH = 0;
unsigned int R9_NORTH_UP = 0;
unsigned int R9_NORTH_LOW = 0;
unsigned int R9_SOUTH = 0;
unsigned int R9_SOUTH_UP = 0;
unsigned int R9_SOUTH_LOW = 0;
unsigned int R9_EAST = 0;
unsigned int R9_EAST_UP = 0;
unsigned int R9_EAST_LOW = 0;
unsigned int R9_WEST = 0;
unsigned int R9_WEST_UP = 0;
unsigned int R9_WEST_LOW = 0;

int aku =0;

// GEDUNG C
unsigned int R4AB_THRESHOLD_UPPER = 0; // kiri dari 4A
unsigned int R4AB_THRESHOLD_LOWER = 0; // kanan dari 4A
unsigned int R4AB_THRESHOLD_MIDDLE;
unsigned int R4A_THRESHOLD_UPPER = 0;	//kiri 4A
unsigned int R4A_THRESHOLD_LOWER = 0;	//kanan 4A
unsigned int R4B_THRESHOLD_LOWER = 0;	//kiri 4B
unsigned int R4B_THRESHOLD_UPPER = 0;	//kanan 4B
//unsigned int R4A_THRESHOLD_MIDDLE=(160+210)/2;
unsigned int R4A_THRESHOLD_MIDDLE=0;
unsigned int R4B_THRESHOLD_MIDDLE=0;
unsigned int START_MIDDLE = 0;
unsigned int R1BC_THRESHOLD_MIDDLE =0;
unsigned int STAIRS_THRESHOLD_4B_UPPER =0;
unsigned int STAIRS_THRESHOLD_4B_LOWER =0;
unsigned int STAIRS_THRESHOLD_4A_UPPER =0;
unsigned int STAIRS_THRESHOLD_4A_LOWER =0;
unsigned int STAIRS_THRESHOLD_4B_MIDDLE =0;
unsigned int STAIRS_THRESHOLD_4A_MIDDLE =0;

uint8_t data_coba = 0;


unsigned int RIGHT_COUNTER = 0,LEFT_COUNTER = 0;

/*FLAG UNTUK MENGAKTIFKAN KOREKSI MANUAL PADA DAERAH TERTENTU
APABILA CMPS11 TERGANGGU
APABILA ADA MALFUNGSI DI R4A ATAU R4B AKTIFKAN KEDUANYA*/

unsigned int START_MID_MANUAL=0; // MALFUNGSI START MID
unsigned int FOUR_WAY_MANUAL=0; // MALFUNGSI PEREMPATAN
unsigned int ROOM_1A_MANUAL=0; // MALFUNGSI DI DEPAN R1A
unsigned int ROOM_2_1BC_MANUAL=0; // MALFUNGSI DI DAERAH R 2 1BC
unsigned int ROOM_4A_MANUAL=0; // MALFUNGSI DI R 4A
unsigned int ROOM_4B_ROT_MANUAL=0; // MALFUNGSI DI DAERAH PEREMPATAN 4B KE KUCING A
unsigned int ROOM_1A_RETURN_MANUAL=0; // MALFUNGSI KEMBALI DARI R 1
unsigned int ROOM_4B_MANUAL=0; // MALFUNGSI DI DEPAN R4B

int FOUR_WAY_CORRECTION = 1;
int ROOM_2_1BC_CORRECTION = 2;
int ROOM_1A_CORRECTION = 3;
int ROOM_4B_TURN_CORRECTION = 4; // bisa dipakai di daerah 4A ke kucing A
int START_MID_CORRECTION = 5;
int ROOM_1A_RETURN = 6;
int ROOM_4A_DETECT = 7;	// ketika start
int ROOM_4B_DETECT = 8; // ketika start
int ROOM_1B_DETECT = 9; // ketika start
int ROOM_1C_DETECT = 10; // ketika start
int ROOM_4A_DETECT_IN = 11;	// BW setelah start
int ROOM_4B_DETECT_IN = 12; // BW setelah start
int ROOM_1B_DETECT_NAV = 13; // BW setelah start
int ROOM_1C_DETECT_NAV = 14; // BW setelah start
int FOUR_WAY_INV = 15;
int R4A_RETURN = 16;
int R4B_RETURN = 17;
int STAIRS_DIRECTION_4B = 18;
int STAIRS_DIRECTION_4A = 19;

int R4A_TENGAH_H;
int R4A_TENGAH_L;
int R4B_TENGAH_H;
int R4B_TENGAH_L;
int R4A_SERONG_KANAN_H;
int R4A_SERONG_KANAN_L;
int R4A_SERONG_KIRI_H;
int R4A_SERONG_KIRI_L;
int R4B_SERONG_KANAN_H;
int R4B_SERONG_KANAN_L;
int R4B_SERONG_KIRI_H;
int R4B_SERONG_KIRI_L;
int R4A_KANAN_H;
int R4A_KANAN_L;
int R4A_KIRI_H;
int R4A_KIRI_L;
int START_MID_H;
int START_MID_L;
int R1BC_H;
int R1BC_L;

int CAT_MIN_RANGE = 9;
int STAIRS_MIN_RANGE = 12;

int DIFF_4A_1BC = 0;

float speed_slow = 336;
float speed_med_slow =261.5;
float speed_medium = 187;
float speed_med_fast = 112.5;
float speed_fast = 38;
float angel_low=0;
float angel_med_low=2.75;
float angel_medium=5.5;
float angel_med_high=8.25;
float angel_high=11;
float jarak[5];
float final_speed;
float final_angel[2];
float rule[3];
float Defuzzy_foward;
float Defuzzy_follow_kiri;
float Defuzzy_follow_kanan;
int Fuzzy_FKR_SP = 16;
float ERROR_DATA[5];
int selisih;
int selisih_kanan;

const int LEFT_FOLLOW = 0;
const int RIGHT_FOLLOW = 1;

float rad_teta1;
float rad_teta2;
float  rad_teta3;

float  deg_teta1;
float  deg_teta2;
float deg_teta3;

//CLIMBING
float X1_IK_C[6];
float X2_IK_C[6];
float Y_IK_C[6];
float Z_IK_C[6];

float X_rotgoal[6];
float Y_rotgoal[6];
float X1_IK[6];
float X2_IK[6];
float X3_IK[6];
float X4_IK[6];
float X5_IK[6];
float Y_IK[12];
float Y1_IK[12];
float Z_IK[12];
float Z1_IK[12];
float Z2_IK[12];
float Z3_IK[12];
float Z4_IK[12];
float delta_X_leg[6];
float delta_Y_leg[6];
//const float X_BODY_OFFSET[6] = {3.7 , 3.7 , 5.2 , 5.2 , 3.7 , 3.7}; //panjang femur
//const float Y_BODY_OFFSET[6] = {7.3 , 7.3 , 0 , 0 , 7.3 , 7.3}; //pangjang tibia
//const float X_STATIC_OFFSET = 4.7; //panjang femur
//const float Y_STATIC_OFFSET = 4.7; //pangjang tibia
const float X_BODY_OFFSET[6] = {5.25 , 5.25 , 6.56 , 6.56 , 5.25 , 5.25}; //panjang femur
const float Y_BODY_OFFSET[6] = {6.75 , 6.75 , 0 , 0 , 6.75 , 6.75}; //pangjang tibia
const float X_STATIC_OFFSET = 4.5; //panjang femur
const float Y_STATIC_OFFSET = 4.5; //pangjang tibia

float tetha_offset[6] ={0 , 0 , 0 , 0 ,0 , 0} ; //atan2(8.5,3.7)
float X_Body_Offset_final[6]={0,0,0,0,0,0};
float Y_Body_Offset_final[6]={0,0,0,0,0,0};
float X_Trans_Leg[6]={0,0,0,0,0,0};
float Y_Trans_Leg[6]={0,0,0,0,0,0};
float X_Leg_PosFinal[6];
float Y_Leg_PosFinal[6];
float rotation_matriks[4]={0,0,0,0};
float rotation_matriks_6S[4]={0,0,0,0};
float X_Diff;
float Y_Diff;
float leg_length_total=0;


float X_IK_BEGIN[6] = {0 , 0 , 0 , 0 , 0 , 0};
float Y_IK_BEGIN[6] = {0 , 0 , 0 , 0 , 0 , 0};
float Z_IK_BEGIN[6] = {4.7 , 4.7 , 4.7 , 4.7 , 4.7 , 4.7};
//float Z_IK_BEGIN[6] = {6 , 6 , 6 , 6 , 6 , 6};
//float Z_IK_BEGIN[6] = {5 , 5 , 5 , 5 , 5 , 5};
float Z_IK_BEGIN_BWD[6] = {5 , 5 , 5 , 5 , 5 , 5};

float Z_IK_STAIRS[6] ={7.2 , 7.2 , 7.2 , 7.2 , 7.2 , 7.2};
//float Z_IK_STAIRS[6] ={7 , 7 , 7 , 7 , 7 , 7};
float Z_IK_S_BUFF[6] = {0,0,0,0,0,0};

float X_IK_OBS[6] = {5, 5, 5, 5, 5, 5};
float Z_IK_OBS[6] ={6 , 6 , 6 , 6 , 6 , 6};
//float Z_IK_OBS[6] ={6.2 , 6.2 , 6.2 , 6.2 , 6.2 , 6.2}; //fix

float Z0_IK_STAIRS[6] ={5.6 , 5.6 , 5.6 , 5.6 , 5.6 , 5.6};
float Z1_IK_STAIRS[6] ={5.8 , 5.8 , 5.8 , 5.8 , 5.8 , 5.8};
float Z2_IK_STAIRS[6] ={6 , 6 , 6 , 6 , 6 , 6};
float Z3_IK_STAIRS[6] ={6.2 , 6.2 , 6.2 , 6.2 , 6.2 , 6.2};
float Z4_IK_STAIRS[6] ={6.4 , 6.4 , 6.4 , 6.4 , 6.4 , 6.4};
float Z5_IK_STAIRS[6] ={6.6 , 6.6 , 6.6 , 6.6 , 6.6 , 6.6};

float Z_IK_STAIRS4[6] ={6.5 , 6.5 , 6.5 , 6.5 , 6.5 , 6.5};
float Z_IK_STAIRS2[6] ={8 , 8 , 8 , 8 , 8 , 8};
float Z_IK_STAIRS3[6] ={2 , 2 , 2 , 2 , 2 , 2};

int SLIDE_FLAG = 1;
int CLIMBING_FLAG = 0;
int CLIMBING_INTERRUPT_FLAG = 0;
int PYRAMID_INTERRUPT_FLAG = 0;
int SIKLUS_FLAG = 0;
int ROTATION_FLAG = 0;
int SUPPORT_FASE=0;
int SWING_FASE=0;
int IK_CALCULATED_OBS =0;
int IK_CALCULATED_FWD_OBS =0;
int IK_CALCULATED_BWD_OBS =0;
int IK_CALCULATED_FWD =0;
int IK_CALCULATED_BWD =0;
int IK_CALCULATED_CLMB =0;
int IK_CALCULATED_CRV_R_CLMB =0;
int IK_CALCULATED_CRV_L_CLMB =0;
int IK_CALCULATED_ASK_R =0;
int IK_CALCULATED_ASK_L =0;
int IK_CALCULATED_SLD_L=0;
int IK_CALCULATED_SLD_R=0;
int IK_CALCULATED_SLD_L_OBS=0;
int IK_CALCULATED_SLD_R_OBS=0;
int IK_CALCULATED_ROT_R=0;
int IK_CALCULATED_ROT_L=0;
int IK_CALCULATED_CRV_R=0;
int IK_CALCULATED_CRV_L=0;
int IK_CALCULATED_CRV_R_OBS=0;
int IK_CALCULATED_CRV_L_OBS=0;
int IK_CALCULATED_CRV_R_REVERSE=0;
int IK_CALCULATED_CRV_L_REVERSE=0;
int IK_CALCULATED_SLP =0;
int IK_CALCULATED_LEAN_FWD_OBS =0;
int IK_CALCULATED_LEAN_BWD_OBS =0;
int IK_CALCULATED_LEAN_FWD =0;
int IK_CALCULATED_LEAN_BWD =0;
int STATIC_ANGLE = 0;
int STATIC_CLIMBING = 0;
int STATIC_OBS = 0;
int STATIC_OBS_HIGH = 0;
int IK_Count = 0;
int IK_step = 0;
int CURVE_LEFT_STAT = 0;
int CURVE_RIGHT_STAT = 0;
int FOWARD_STAT = 0;
int BACKWARD_STAT = 0;
float leg_static_length=0;
float step;
float Y_Sampling[12];
float Y1_Sampling[12];
float Y2_Sampling[12];
float Z_Sampling[12];
float Z1_Sampling[12];
float Z2_Sampling[12];
float Z3_Sampling[12];
float Z4_Sampling[12];
float X1_Sampling[6];
float X2_Sampling[6];
float X3_Sampling[6];
float X4_Sampling[6];
float X5_Sampling[6];

int COXA_D[6];
int NCOXA_D[6];
int FEMUR_D[6];
int NFEMUR_D[6];
int TIBIA_D[6];
int NTIBIA_D[6];
int TIBIA_D_R[6];
int NTIBIA_D_R[6];


int COXA_A[4];
int FEMUR_A[4];
int TIBIA_A[4];
int TIBIA_A_R[4];
int TIBIA_A_RB[4];
int NTIBIA_A_R[4];
int NTIBIA_ASK_L[4];
int NTIBIA_ASK_R[4];
int NCOXA_A[4];
int NFEMUR_A[4];
int NTIBIA_A[4];
int TIBIA_ASK_L[4];
int TIBIA_ASK_R[4];
int TIBIA_ASK[3];

int COXA_B[4];
int NCOXA_B[4];
int COXA_B_R[4];
int NCOXA_B_R[4];
int FEMUR_B[4];
int NFEMUR_B[4];
int TIBIA_B[4];
int TIBIA_B_R[4];
int NTIBIA_B[4];
int NTIBIA_B_R[4];

int COXA_E[4];
int NCOXA_E[4];
int COXA_E_R[4];
int NCOXA_E_R[4];
int FEMUR_E[4];
int NFEMUR_E[4];
int TIBIA_E[4];
int TIBIA_E_R[4];
int NTIBIA_E[4];
int NTIBIA_E_R[4];

int COXA_C[6];
int NCOXA_C[6];
int FEMUR_C[6];
int NFEMUR_C[6];
int TIBIA_C[6];
int TIBIA_C_R[6];
int NTIBIA_C[6];
int NTIBIA_C_R[6];
int R_TIBIA_C[6];
int R_NTIBIA_C[6];
int L_TIBIA_C[6];
int L_NTIBIA_C[6];

int COXA_O[4];
int NCOXA_O[4];
int FEMUR_O[4];
int NFEMUR_O[4];
int TIBIA_O[4];
int TIBIA_O_R[4];
int NTIBIA_O[4];
int NTIBIA_O_R[4];
int R_TIBIA_O[4];
int R_NTIBIA_O[4];
int L_TIBIA_O[4];
int L_NTIBIA_O[4];

int COXA_R[4];
int NCOXA_R[4];
int FEMUR_R[4];
int NFEMUR_R[4];
int TIBIA_R[4];
int TIBIA_R_O[4];
int NTIBIA_R[4];
int NTIBIA_R_O[4];

int COXA_S[4];
int NCOXA_S[4];

int FEMUR_S_F[4];
int NFEMUR_S_F[4];
int FEMUR_S_M[4];
int NFEMUR_S_M[4];
int FEMUR_S_R[4];
int NFEMUR_S_R[4];

int FEMUR_S_KI[4];
int NFEMUR_S_KI[4];
int FEMUR_S_KA[4];
int NFEMUR_S_KA[4];

int TIBIA_S[4];
int NTIBIA_S[4];
int TIBIA_S_R[4];
int NTIBIA_S_R[4];

int TIBIA_S_KI[4];
int NTIBIA_S_KI[4];
int TIBIA_S_R_KI[4];
int NTIBIA_S_R_KI[4];

int FEMUR_G[4];
int NFEMUR_G[4];
int COXA_G[4];
int NCOXA_G[4];
int TIBIA_G[4];
int NTIBIA_G[4];
int TIBIA_GS[4];
int NTIBIA_GS[4];

int FEMUR_H[4];
int NFEMUR_H[4];
int COXA_H[4];
int NCOXA_H[4];
int TIBIA_H[4];
int NTIBIA_H[4];
int TIBIA_HS[4];
int NTIBIA_HS[4];

int FEMUR_SLP[4];
int NFEMUR_SLP[4];
int COXA_SLP[4];
int NCOXA_SLP[4];
int TIBIA_SLP[4];
int NTIBIA_SLP[4];

int X_STATIC_IK[6];
int Y_STATIC_IK[6];
int Z_STATIC_IK[6];

int X_STATIC_IK_S[6];
int Y_STATIC_IK_S[6];
int Z_STATIC_IK_S[6];

int ROOM_MOVEMENT=0;

float FR_LEG[3];
float R_LEG[3];
float RR_LEG[3];
float FL_LEG[3];
float L_LEG[3];
float RL_LEG[3];
//TURN SPEED CONTROL
int speed_cnt;

unsigned int R1B_THRESHOLD=175;
unsigned int R1C_THRESHOLD=175;
unsigned int R1A_R4A_THRESHOLD_MIDDLE=193;
unsigned int R1A_THRESHOLD=175;
unsigned int R2_THRESHOLD=175;
unsigned int R3_R4B_THRESHOLD_MIDDLE=320;
unsigned int R4A_THRESHOLD=175;
unsigned int R4B_THRESHOLD=175;


//=============================================================================================//

/*
 * 	FIREFIGHT FLAG FOR ROOM4AB
 */
unsigned int ROOM4AB_FLAG=0;
unsigned int ROOM4AB_ACTIVE=1;
unsigned int ROOM4AB_INACTIVE=0;

unsigned int FIREROOM_R4AB_FLAG=0;
unsigned int FIREROOM_R4AB_ACTIVE=1;
unsigned int FIREROOM_R4AB_INACTIVE=0;

unsigned int FIREROOM_R1A_FLAG=0;
unsigned int FIREROOM_R1A_ACTIVE=1;
unsigned int FIREROOM_R1A_INACTIVE=0;
unsigned int ROOM1A_SP_MIDDLE_FLAG=2; // CEK ulang R1A ditengah ruang

unsigned char DataBuffer[255];
int JumlahData_RT=0;

int DynamxCorrection[18]=
							{

									0,0,0, //Front Left Leg
									0,0,0, //Middle Left Leg
									0,0,0, //Rear Left Leg

									0,0,0, //Front Right Leg
									0,0,0, //Middle Right Leg
									0,0,0, //Rear Right Leg

////									0,0,-2, //Front Left Leg
//									0,0,-2, //Front Left Leg
//									0,0,0, //Middle Left Leg
////									0,-2,-1, //Rear Left Leg
//									0,0,0, //Rear Left Leg
//
//									0,0,5, //Front Right Leg
////									0,-6,-1, //Middle Right Leg
//									0,0,1, //Middle Right Leg
//									0,0,0, //Rear Right Leg

							};


float Dynamx_LinkFemur= 4;
float Dynamx_LinkTibia= 8;

unsigned int start_compas_flag = 0;

int ROOM_NOW = 0;
int ROOM1 = 1;
int ROOM2 = 2;
int HALLWAY = 3;

int count_tracer_obs2 = 0;
int count_pitch_obs2 = 0;

int HOME_FLAG_NEW = 0;
int HOME_FLAG_1 = 1;
int HOME_FLAG_2 = 2;



unsigned int mode_scan_K5 = 0;
unsigned int MODE_SCAN_K5_LEFT = 8;
unsigned int MODE_SCAN_K5_RIGHT = 9;

unsigned int mode_cmps = 0;
unsigned int MODE_CMPS_EAST = 11;

unsigned int mode_obs = 0;
unsigned int MODE_OBS = 6;

unsigned int mode_korban = 0;
unsigned int MODE_CAPIT = 0;
unsigned int mode_scan = 0;
unsigned int MODE_K1 = 1;
unsigned int MODE_K2 = 2;
unsigned int MODE_K2_Next = 22;
unsigned int MODE_K5 = 7;
unsigned int MODE_SZ1 = 3;
unsigned int MODE_SZ2 = 4;
unsigned int MODE_SZ5 = 5;

unsigned int MODE_NONE = 0;

unsigned int mode_loss = 0;
unsigned int MODE_LOSS_KORBAN = 1;

unsigned int mode_slide_finish = 0;
unsigned int MODE_SLIDE_FINISH = 1;

unsigned int mode_follow = 0;
unsigned int MODE_FOLLOW_K5 = 1;
unsigned int MODE_FOLLOW_FAST = 2;
unsigned int MODE_FOLLOW_R6 = 3;

unsigned int rot_flag_K2 = 0;
unsigned int samping_flag_K2 = 0;

//THRESHOLD TCS 34725 GRIPPER
unsigned int TCSG_R_THRESHOLD = 0;
unsigned int TCSG_G_THRESHOLD = 0;
unsigned int TCSG_B_THRESHOLD = 0;

unsigned int TCSG_R_THRESHOLD_LOW = 0;
unsigned int TCSG_R_THRESHOLD_HIGH = 0;
unsigned int TCSG_G_THRESHOLD_LOW = 0;
unsigned int TCSG_G_THRESHOLD_HIGH = 0;
unsigned int TCSG_B_THRESHOLD_LOW = 0;
unsigned int TCSG_B_THRESHOLD_HIGH = 0;



//SHARP FRONT TRACER GRIP
unsigned int SHARP_FRONT[10];


