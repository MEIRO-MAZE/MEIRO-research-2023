/*==============================================================================================
								 	 PROJECT BW Ver.1.0
								BW INFRARED PROXIMITY LIBRARY
==============================================================================================*/

#ifndef BW_INFRARED_PROXIMITY_H
#define BW_INFRARED_PROXIMITY_H

#include "main.h"

/*
 * NEW PIN NON CONTACT BUMPER ( LEFT C14 & RIGHT C15)
 */

/*
 * OLD BW INFRARED SENSOR PIN
 */
//#define RCC_AHB1Periph_IR_C RCC_AHB1Periph_GPIOC
//#define IR_PORT_C GPIOC
//
//#define RCC_AHB1Periph_IR_D RCC_AHB1Periph_GPIOD
//#define IR_PORT_D GPIOD
//
//#define IR_PIN_FRONT_LEFT  	GPIO_Pin_1
//#define IR_PIN_FRONT_RIGHT 	GPIO_Pin_2
//#define IR_PIN_MID_LEFT   	GPIO_Pin_4
//#define IR_PIN_MID_RIGHT  	GPIO_Pin_5
//#define IR_PIN_FRONT_MIDDLE GPIO_Pin_6
//#define IR_PIN_FRONT_SUB 	GPIO_Pin_7
//
////NON CONTACT BUMPER
//#define  IR_PIN_BUMPER_LEFT  GPIO_Pin_14
//#define  IR_PIN_BUMPER_RIGHT GPIO_Pin_15
//
//#define INFRARED_FRONT_LEFT    GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_1)
//#define INFRARED_FRONT_RIGHT   GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_2)
//#define INFRARED_MID_LEFT      GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_4)
//#define INFRARED_MID_RIGHT     GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_5)
//#define INFRARED_FRONT_MIDDLE  GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_6)
//#define INFRARED_FRONT_SUB     GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_7)
//
////NON CONTACT BUMPER
//#define INFRARED_BUMPER_LEFT   GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_14)
//#define INFRARED_BUMPER_RIGHT  GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_15)
//
//
//#define IR_FRONT_LEFT    0
//#define IR_FRONT_RIGHT   1
//#define IR_MID_LEFT      2
//#define IR_MID_RIGHT     3
//#define IR_FRONT_MIDDLE  4
//#define IR_FRONT_SUB     5
//#define IR_BUMPER_LEFT   6
//#define IR_BUMPER_RIGHT  7
//
//#define IR_DETECTED 0
//#define IR_NOT_DETECTED 1
//
//#define FRONT_MID_DETECTED 1
//#define FRONT_MID_NOT_DETECTED 0
//
//#define IR_MID_DETECTED 	1
//#define IR_MID_NOT_DETECTED 0


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

//OLD MACRO
//#define IR_FRONT_MIDDLE  4
//#define IR_FRONT_SUB     5


#define IR_DETECTED 0
#define IR_NOT_DETECTED 1

#define FRONT_MID_DETECTED 1
#define FRONT_MID_NOT_DETECTED 0

#define IR_MID_DETECTED 	1
#define IR_MID_NOT_DETECTED 0

extern int INFRARED[];
void IR_Proximity_Init(void);
void Get_IR(void);
void IR_Interrupt_Init(void);
void Get_IR_Right(void);
void Get_IR_Left(void);
void Display_IR_Stat(void);

#endif

