/*==============================================================================================
								  	  PROJECT BW 2.16 Ver.1.0
								  	 BW SHARP INFRARED DISTANCE SENSOR
==============================================================================================*/

#ifndef BW_SHARP_IR_H
#define BW_SHARP_IR_H

#include "main.h"

#define RCC_AHB1Periph_SHARP RCC_AHB1Periph_GPIOC
#define SHARP_IR_PORT GPIOC
#define SHARP_IR_PIN GPIO_Pin_3

/*
 * 	SHARP INFRARED SENSOR GP2Y0A41SK0F
 *
 * 	[ Vo(DATA)]
 *  [   GND   ]
 *  [   VCC   ]
 */
void SHARP_IR_Init(void);
void SHARP_IR_Sampling(void);


#endif
