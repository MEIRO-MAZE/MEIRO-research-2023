#ifndef _MZ_SERVO_PWM_H
#define _MZ_SERVO_PWM_H


#include "main.h"


#define SERVO_PWM_1_Type			GPIOD
#define SERVO_PWM_1_Pin				GPIO_Pin_12
#define SERVO_PWM_1_PinSource		GPIO_PinSource12
#define SERVO_PWM_2_Type			GPIOD
#define SERVO_PWM_2_Pin				GPIO_Pin_13
#define SERVO_PWM_2_PinSource		GPIO_PinSource13
#define SERVO_PWM_3_Type			GPIOD
#define SERVO_PWM_3_Pin				GPIO_Pin_14
#define SERVO_PWM_3_PinSource		GPIO_PinSource14
#define SERVO_PWM_4_Type			GPIOD
#define SERVO_PWM_4_Pin				GPIO_Pin_15
#define SERVO_PWM_4_PinSource		GPIO_PinSource15

#define SERVO_1  					1
#define SERVO_2  					2
#define SERVO_3  					3
#define SERVO_4  					4

#define degree_0					600
#define degree_15					750
#define degree_30					900
#define degree_60					1200
#define degree_90					1500
#define degree_120					1800
#define degree_150					2100
#define degree_165					2250
#define degree_180					2400


void Servo_PWM_Config(void);
void Servo_PWM_Set_Angle(int SERVO, int Angle);
void CO2_Launcher_PWM_Servo(void);
void Gripper_PWM_Capit(void);
void Gripper_PWM_Up(void);
void Gripper_PWM_Down(void);
void Gripper_Down_K1(void);
void Gripper_Up_K1(void);
void Gripper_Open_K1(void);
void Gripper_Open_K3(void);
void Gripper_Close_K1(void);
void Gripper_Up_Calibration(void);
void Gripper_Down_Calibration(void);
void Gripper_Close_Calibration(void);
void Gripper_Open_Calibration(void);
void Gripper_Down_New(void);
void Gripper_Up_New(void);
void Gripper_Up_Dikit(void);
void Gripper_Up_Full(void);

#endif
