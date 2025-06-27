#ifndef	MAIN_H
#define MAIN_H

#include <stm32f10x_gpio.h>
#include <stm32f10x_rcc.h>
#include <stm32f10x.h>
#include <misc.h>
#include <stm32f10x_tim.h>
#include <stm32f10x_usart.h>
#include "Init_Ping)).h"
#include "delay.h"
#include <stdint.h>
#include "adc_comp.h"
#include <stm32f10x_i2c.h>
#include <stdbool.h>
#include "i2c_VL53L0X.h"
#include <stdlib.h>
#include <stm32f10x_dma.h>

GPIO_InitTypeDef GPIO_InitStructure;
TIM_TimeBaseInitTypeDef	TIM_InitStructure;
NVIC_InitTypeDef NVIC_InitStructure;
I2C_InitTypeDef I2C_InitStructure;
USART_InitTypeDef USART_InitStructure;



// Variables

#endif
