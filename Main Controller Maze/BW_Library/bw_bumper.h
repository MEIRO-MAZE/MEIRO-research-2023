/*==============================================================================================
								 	 PROJECT BW Ver.1.0
							  BW CONTACT BUMPER SENSOR LIBRARY
==============================================================================================*/

#ifndef BW_BUMPER_H
#define BW_BUMPER_H

#include "main.h"

#define RCC_AHB1Periph_BUMPER_LEFT RCC_AHB1Periph_GPIOC
#define BUMPER_PORT_LEFT GPIOC

#define RCC_AHB1Periph_BUMPER_RIGHT RCC_AHB1Periph_GPIOA
#define BUMPER_PORT_RIGHT GPIOA

/*
 * 			LEFT					RIGHT
 * 		BUMPER  PC2				BUMPER  PA7
 *
 */

#define PIN_BUMPER_LEFT				GPIO_Pin_2
#define BUMPER_LEFT  				GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_2)

#define PIN_BUMPER_RIGHT			GPIO_Pin_7
#define BUMPER_RIGHT  				GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_7)

extern unsigned int BUMPER[];
#define LEFT	0
#define RIGHT	1


void Bumper_Init(void);
void GetBumper(void);
void Display_Bumper_Stat(void);
void Display_Cat_VAR(void);


extern unsigned int UV_Lock;

#endif
