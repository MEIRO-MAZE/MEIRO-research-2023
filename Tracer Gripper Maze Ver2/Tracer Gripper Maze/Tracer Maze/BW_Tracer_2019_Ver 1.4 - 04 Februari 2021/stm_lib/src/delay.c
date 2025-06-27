#include "Tracer_2019.h"

// For store tick counts in us

volatile uint32_t sysTick_Time;

// SysTick_Handler function will be called every 1 us
void SysTick_Handler(void)
{
	if (sysTick_Time != 0)
	{
		sysTick_Time--;
	}
}

void DelayInit(void)
{
	// Update SystemCoreClock value
	SystemCoreClockUpdate();
	// Configure the SysTick timer to overflow every 1 us
	SysTick_Config(SystemCoreClock / 1000000);
}

void DelayUs(uint32_t us)
{
	// Reload us value
	sysTick_Time = us;
	// Wait until usTick reach zero
	while (sysTick_Time);
}

void DelayMs(uint32_t ms)
{
	// Wait until ms reach zero
	while (ms--)
	{
		// Delay 1ms
		DelayUs(1000);
	}
}
