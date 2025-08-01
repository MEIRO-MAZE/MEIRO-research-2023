#ifndef __DELAY_H
#define __DELAY_H

#include "Tracer_2019.h"

void SysTick_Handler(void);
void DelayInit(void);
void DelayUs(uint32_t us);
void DelayMs(uint32_t ms);

#endif
