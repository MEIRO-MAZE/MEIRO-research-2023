/*==============================================================================================
								  PROJECT BW Ver.1.0
							THERMOPHILE ARRAY AND SERVO LIBRARY
==============================================================================================*/
#ifndef BW_TPA_SERVO_H
#define BW_TPA_SERVO_H

//Linking Global Libraries
#include "main.h"
#include "bw_hexapod_cmd.h"


#define PWM_servo 	TIM12->CCR2
#define PWM4_Servo	TIM4->CCR1

extern int PWM_FIRE;
//aktivasi i2c
#define MPU_ACTIVE_MODE 1

extern unsigned char sensor_UV_lock;
extern unsigned char fight;
extern unsigned char hitung;
extern unsigned int panas;
extern int regs;
extern int i, temp;
extern unsigned char suhu_ruang, suhu_pixel[8], pixel[10];
extern int DATA;
extern unsigned int FIRE;

//SERVO CONTROLLER SPEED PARAMETER
extern unsigned int SPEED_SLOW ;
extern unsigned int SPEED_MED  ;
extern unsigned int SPEED_FAST ;



//SERVO CONTROLLER STEP PARAMETER
extern unsigned int STEP_NARROW ;
extern unsigned int STEP_FAR    ;



//I2C
void Setup_I2C();
void Write_I2C(int Address, int Register, int Data);
int16_t Read_I2C(int Address, int Register);


//TPA Servo
void TIM12_PWM_Configuration(void);
void PanServo_Init(void);
unsigned char BW_TPA_Check(char val_or_flag);
//unsigned char BW_TPA_Check(char val_or_flag);
//TPA Init
void BW_TPA81_I2C_Init (void);
void BW_Thermopile_Init(void);
unsigned char BW_TPA_Check(char val_or_flag);
void Get_TPA81(void);
void Display_TPA81(void);

//BW Search Fire Sequences
//unsigned int BW_Search_Fire(void);

extern uint8_t    I2C1_DATA[];
//--------------------------------------------------------------
// MultiByte defines
//--------------------------------------------------------------
#define    I2C1_MULTIBYTE_MAX   10
#define    I2C2_MULTIBYTE_MAX	10
extern uint8_t    I2C1_DATA[];

#define ALPHA 0.5

//--------------------------------------------------------------
// I2C TIMEOUT Defines
//--------------------------------------------------------------
#define   I2C1_TIMEOUT     0x3000


#define TPA81_ADDRESS					0xD0 //Default CMPS-11 DEVICE ADDRESS
#define TPA81_TEMPERATURE				0x01
#define TPA81_REQUESTED_BYTE			9

#endif
