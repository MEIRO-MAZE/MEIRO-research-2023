/*==============================================================================================
								  	  PROJECT BW Ver.2.0
								  	 BW SOUND ACTIVATION LIBRARY
==============================================================================================*/

#ifndef BW_SOUND_ACTIVATION_H
#define BW_SOUND_ACTIVATION_H

#include "main.h"

/*
 * SOUND ACTIVATION PINOUT
 */

#define RCC_AHB1Periph_SOUND_ACT RCC_AHB1Periph_GPIOA
#define SOUND_ACT_PORT GPIOA
#define SOUND_ACT_PIN GPIO_Pin_0

extern uint16_t BW_Sound_Activate;
extern uint16_t BW_START;

void BW_Sound_Activation_Init(void);
void BW_Sound_Activation(void);

#define NO_SIGNAL 0
#define SIGNAL_DETECTED 1
#define SOUND_SCAN   GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)

#define SOUND_ACTIVATED   GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)==0 //ACTIVE LOW
#define SOUND_INACTIVE    GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)==1

void BW_Sound_Activation(void);
void BW_Sound_Activation_Init(void);
#endif
