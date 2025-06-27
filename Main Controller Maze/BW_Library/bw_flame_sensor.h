/*==============================================================================================
								  PROJECT BW 2016 Ver.1.0
								BW FLAME SENSOR LIBRARY
==============================================================================================*/

#ifndef BW_FLAME_SENSOR_H
#define BW_FLAME_SENSOR_H

#include "main.h"


#define RCC_AHB1Periph_FLAME RCC_AHB1Periph_GPIOC
#define IR_PORT_FLAME GPIOC

#define FLAME_ANALOG_PIN		GPIO_Pin_1

extern unsigned int FLAME_SENSOR[];
extern int INFRARED[];

#define FLM_ANALOG 0
#define FLAME_DETECTED 	1
#define FLAME_NOT_DETECTED 0


/*
 * MOV FLAME SENSOR SIDE
 */
extern unsigned int FIRE;
extern unsigned int FLAME_SIDE;
#define FLAME_LEFT_DETECTED  		1
#define FLAME_RIGHT_DETECTED 		2
#define FLAME_NOT_DETECTED 			0

void GetFlame(void);
void Fwd_FlameSide(int distance, int SPEED);
void FlameSensor_Init(void);
void ADC1_config(void);
#endif
