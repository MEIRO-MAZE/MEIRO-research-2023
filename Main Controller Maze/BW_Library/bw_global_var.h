/*==============================================================================================
								  PROJECT BW Ver.1.0
								  GLOBAL VARIABLE LIBRARY
==============================================================================================*/

#ifndef BW_GLOBAL_VAR_H
#define BW_GLOBAL_VAR_H
#include "main.h"

//OBSTAICLE VARIABLE
extern unsigned int OBSTAICLE_STAT;

extern int aku;
unsigned int start_compas_flag;

#define UVSTATE_ACTIVE 		0
#define UVSTATE_INACTIVE 	1

#define INACTIVE 0
#define ACTIVE 1

#define UVLOCK_ACTIVE 		1
#define UVLOCK_INACTIVE 	0

#define FIRE_OFF		0
#define FIRE_ON 		1
#define FIRE_SUCCESS	2

extern unsigned int UV_state;
extern unsigned int UV_Lock;

extern unsigned int UV_R2FLAG;
extern unsigned int UV_R2FLAG_ACTIVE;
extern unsigned int UV_R2FLAG_INACTIVE;
extern int UV_VARIABLE;
extern int UV_VARIABLE2;
extern int ENABLE_UV1;
extern int ENABLE_UV2;
extern int DUMMY_VAR;
extern int IN_ROOM_STAT, NOT_IN_ROOM_STAT;

extern int FWD_BREAK;
extern int BWD_BREAK;

extern unsigned int IK_CLIMBING;

extern int DATA;

extern uint8_t    I2C1_DATA[10];
extern uint8_t    I2C2_DATA[10];
extern uint8_t	   I2C3_DATA[10];

/*
 * BW 2016 INFRARED SENSOR PIN MAPPING
 */

#define RCC_AHB1Periph_IR_A RCC_AHB1Periph_GPIOA
#define IR_PORT_A GPIOA

#define RCC_AHB1Periph_IR_C RCC_AHB1Periph_GPIOC
#define IR_PORT_C GPIOC

#define RCC_AHB1Periph_IR_D RCC_AHB1Periph_GPIOD
#define IR_PORT_D GPIOD

#define RCC_AHB1Periph_IR_B RCC_AHB1Periph_GPIOB
#define IR_PORT_B GPIOB

#define RCC_AHB1Periph_IR_E RCC_AHB1Periph_GPIOE
#define IR_PORT_E GPIOE

/*
 * 			LEFT					RIGHT
 * 		FRONT 	PA15			FRONT	PA4
 * 		MIDDLE 	PC8				MIDDLE  PC4
 * 		REAR 	PD10			REAR	PC5
 * 		BUMPER  PA6				BUMPER  PA7
 *
 */

//LEFT
#define IR_PIN_FRONT_LEFT  		GPIO_Pin_15
#define IR_PIN_MID_LEFT   		GPIO_Pin_8
#define IR_PIN_UPPER_LEFT		GPIO_Pin_10
//#define IR_PIN_BUMPER_LEFT		GPIO_Pin_6
#define IR_PIN_BUMPER_LEFT		GPIO_Pin_1

#define INFRARED_FRONT_LEFT    	GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_15)
#define INFRARED_MID_LEFT      	GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_8)
#define INFRARED_UPPER_LEFT  	GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_10)
//#define INFRARED_BUMPER_LEFT  	GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_6)
#define INFRARED_BUMPER_RIGHT  	GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5)


//RIGHT
#define IR_PIN_FRONT_RIGHT 		GPIO_Pin_4
//#define IR_PIN_MID_RIGHT  		GPIO_Pin_4
#define IR_PIN_MID_RIGHT  		GPIO_Pin_4
//#define IR_PIN_UPPER_RIGHT		GPIO_Pin_5
#define IR_PIN_UPPER_RIGHT		GPIO_Pin_6
#define IR_PIN_BUMPER_RIGHT		GPIO_Pin_7
//#define IR_PIN_BUMPER_RIGHT		GPIO_Pin_5


#define INFRARED_FRONT_RIGHT   		GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_4)
//#define INFRARED_MID_RIGHT     		GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_4)
#define INFRARED_MID_RIGHT     		GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4) //FRONT LEFT
//#define INFRARED_UPPER_RIGHT    	GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_5)
#define INFRARED_UPPER_RIGHT    	GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_6) //FRONT RIGHT
//#define INFRARED_BUMPER_RIGHT  		GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_7)
#define INFRARED_BUMPER_LEFT 		GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_7)


//MIDDLE
#define IR_PIN_FRONT_MIDDLE		GPIO_Pin_9
#define INFRARED_FRONT_MIDDLE	GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_9)


//NEW MACRO
#define IR_FRONT_LEFT    0
#define IR_FRONT_RIGHT   1
#define IR_MID_LEFT      2
#define IR_MID_RIGHT     3
#define IR_UPPER_LEFT	 4
#define IR_UPPER_RIGHT	 5
#define IR_FRONT_MIDDLE  6
#define IR_BUMPER_LEFT   7
#define IR_BUMPER_RIGHT  8


#define IR_DETECTED 0
#define IR_NOT_DETECTED 1

#define FRONT_MID_DETECTED 1
#define FRONT_MID_NOT_DETECTED 0

#define IR_MID_DETECTED 	1
#define IR_MID_NOT_DETECTED 0

extern int INFRARED[];

//CLIMBING

extern float X1_IK_C[];
extern float X2_IK_C[];
extern float Y_IK_C[];
extern float Z_IK_C[];

extern int ROOM_NOW;
extern int ROOM1;
extern int ROOM2;
extern int HALLWAY;

extern int PYRAMID_INTERRUPT_FLAG;

extern int count_tracer_obs2;
extern int count_pitch_obs2;

extern unsigned int TRACER_GRIPPER;
extern unsigned int TRACER_BOTTOM;

extern int HOME_FLAG_NEW;
extern int HOME_FLAG_1;
extern int HOME_FLAG_2;

extern unsigned int mode_korban;
extern unsigned int mode_scan;
extern unsigned int MODE_K1;
extern unsigned int MODE_K2;
extern unsigned int MODE_K2_Next;
extern unsigned int MODE_K5;
extern unsigned int MODE_SZ1;
extern unsigned int MODE_SZ2;
extern unsigned int MODE_SZ5;
extern unsigned int MODE_NONE;
extern unsigned int MODE_CAPIT;
extern unsigned int mode_cmps;
extern unsigned int MODE_CMPS_EAST;
extern unsigned int mode_obs;
extern unsigned int MODE_OBS;
extern unsigned int MODE_SCAN_K5_LEFT;
extern unsigned int MODE_SCAN_K5_RIGHT;
extern unsigned int mode_scan_K5;
extern unsigned int mode_loss;
extern unsigned int MODE_LOSS_KORBAN;

extern unsigned int mode_slide_finish;
extern unsigned int MODE_SLIDE_FINISH;


extern unsigned int mode_follow;
extern unsigned int MODE_FOLLOW_K5;
extern unsigned int MODE_FOLLOW_FAST;
extern unsigned int MODE_FOLLOW_R6;

extern unsigned int rot_flag_K2;
extern unsigned int samping_flag_K2;

extern unsigned int TCSG_R_THRESHOLD;
extern unsigned int TCSG_G_THRESHOLD;
extern unsigned int TCSG_B_THRESHOLD;

extern unsigned int TCSG_R_THRESHOLD_LOW;
extern unsigned int TCSG_R_THRESHOLD_HIGH;
extern unsigned int TCSG_G_THRESHOLD_LOW;
extern unsigned int TCSG_G_THRESHOLD_HIGH;
extern unsigned int TCSG_B_THRESHOLD_LOW;
extern unsigned int TCSG_B_THRESHOLD_HIGH;

//extern unsigned int SHARP_FRONT[];

#endif
