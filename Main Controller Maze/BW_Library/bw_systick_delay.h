/*==============================================================================================
								      PROJECT BW Ver.2.0
								      SYSTICK DELAY LIBRARY
==============================================================================================*/

#ifndef __BW_SYSTICK_DELAY_H
#define __BW_SYSTICK_DELAY_H
#include "stm32f4xx.h"

//SYSTICK DELAY PROTOTYPE

void SysTick_Init(void);
void TimeTick_Decrement(void);
void delay_us(u32 n);
void delay_1ms(void);
void delay_ms(u32 n);

#endif
