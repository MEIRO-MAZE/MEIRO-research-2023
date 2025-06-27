/*==============================================================================================
								  	  PROJECT BW Ver.1.0
								  	 BW ROTARY SWITCH ADC
==============================================================================================*/

#ifndef BW_ROTARY_SWITCH_H
#define BW_ROTARY_SWITCH_H

#include "main.h"
/*
 * ROTARY SWITCH PINOUT
 */

#define RCC_AHB1Periph_ROT_SWITCH RCC_AHB1Periph_GPIOC
#define ROT_SWITCH_PORT GPIOC
#define ROT_SWITCH_PIN GPIO_Pin_4

extern uint16_t rot_switch_mode;
extern unsigned int ADCResult;

void RotSwitch_Init(void);
void RotSwitch_Sampling(void);
void Display_MODE(void);


#endif
