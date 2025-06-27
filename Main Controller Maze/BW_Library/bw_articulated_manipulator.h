/*==============================================================================================
								  PROJECT BW 2.16 Ver.1.0
								  BW ARTICULATED MANIPULATOR
==============================================================================================*/

#include "main.h"

#ifndef BW_ARTICULATED_MANIPULATOR_H
#define BW_ARTICULATED_MANIPULATOR_H



//BW ARTICULATED MANIPULATOR SERVO GPIO
void BW_Manipulator_Initialization(void);

void Manipulator_Servo_Init(void);
void Manipulator_Interrupt_Init(void);
void Manipulator_TIM_Init(void);

//SHOULDER SERVO GPIO
#define RCC_AHB1Periph_SHOULDER RCC_AHB1Periph_GPIOE
#define SHOULDER_PORT GPIOE
#define SHOULDER_PIN  GPIO_Pin_3

//ELBOW SERVO GPIO
#define RCC_AHB1Periph_ELBOW    RCC_AHB1Periph_GPIOC
#define ELBOW_PORT GPIOC
#define ELBOW_PIN  GPIO_Pin_13

//GRIPPER SERVO GPIO
#define RCC_AHB1Periph_GRIPPER  RCC_AHB1Periph_GPIOD
#define GRIPPER_PORT GPIOD
#define GRIPPER_PIN  GPIO_Pin_6

//BW ARTICULATED MANIPULATOR TIMER

#define MANIPULATOR_TIMER         TIM2
#define MANIPULATOR_TIM_PERIOD    65535
#define MANIPULATOR_TIM_PRESCALER 21


//ARM ROBOT SERVO CHANNEL
#define ARM_CHANNEL_0 	GPIOE,GPIO_Pin_3  //SHOULDER
#define ARM_CHANNEL_1   GPIOC,GPIO_Pin_13 //ELBOW
#define ARM_CHANNEL_2   GPIOD,GPIO_Pin_6  //GRIPPER

extern int Arm_Angle[];
extern int Arm_Correction[];

extern uint32_t ARM_CCR1_Val, ARM_CCR2_Val, ARM_CCR3_Val;


#define SHOULDER 0
#define ELBOW    1
#define GRIPPER  2

int arm_counter;



//#define SHOULDER_SERVO
#endif
