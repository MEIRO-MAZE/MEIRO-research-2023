/*========================================================================================
								   PROJECT BW 2.16 Ver.1.0
								  BW Hydro Extinguisher Library
==============================================================================================*/
#ifndef BW_EXTINGUISHER_H
#define BW_EXTINGUISHER_H

#include "main.h"
/*
 * BW BUZZER
 */
#define RCC_AHB1Periph_EXTINGUISHER RCC_AHB1Periph_GPIOB
#define EXTINGUISHER_PORT GPIOB
#define EXTINGUISHER_PIN GPIO_Pin_13
#define CO2_EXTI_ID			19
#define Dynamx_CO2_Open 	115
#define Dynamx_CO2_Static	90
//#define EXTINGUISHER_PORT GPIOD
//#define EXTINGUISHER_PIN GPIO_Pin_8

//#define EXTINGUISHER_PORT GPIOD			PIN REGIONAL
//#define EXTINGUISHER_PIN GPIO_Pin_12

//#define EXTINGUISHER_ON GPIO_SetBits (EXTINGUISHER_PORT, EXTINGUISHER_PIN);
#define EXTINGUISHER_OFF 	GPIO_ResetBits(EXTINGUISHER_PORT, EXTINGUISHER_PIN);
#define EXTINGUISHER_ON 	GPIO_SetBits(EXTINGUISHER_PORT, EXTINGUISHER_PIN);
#define EXT_1_ON				GPIO_SetBits(GPIOB, GPIO_Pin_13);
#define EXT_1_OFF				GPIO_ResetBits(GPIOB, GPIO_Pin_13);
#define CO2_EXTI_ON		Dyna_Actuate(CO2_EXTI_ID, Dynamx_CO2_Open, 800, 1200);
#define CO2_EXTI_OFF	Dyna_Actuate(CO2_EXTI_ID, Dynamx_CO2_Static, 800, 1200);
//#define EXTINGUISHER_OFF GPIO_ResetBits (EXTINGUISHER_PORT, EXTINGUISHER_PIN);
//#define EXTINGUISHER_ON GPIO_SetBits(EXTINGUISHER_PORT, EXTINGUISHER_PIN);


void BW_Extinguisher_Init(void);
void BW_HydroPump (void);
void Pump_GPIOInit(void);
void PushTo_Burst (void);
void TEST_CO2_EXTI(int degree);
void BW_CO2_TEST(void);
void BW_CO2_EXTINGUISH(int open_degree,int time);
/*void CO2_LAUNCHER(void);*/
void DynaExt(int Degree);
void BW_HydroPump_V10(void);
void BW_HydroPump_2021_1(void);
void BW_HydroPump_2021_2(void);
void CO2_LAUNCHER_V2(int EXTEND_DEG, int delay_val);
void CO2_LAUNCHER_V3(int EXTEND_DEG, int delay_val);
void CO2_LAUNCHER(int EXTEND_DEG, int delay_val);
void DynaCleaner(int Degree);

extern uint16_t BW_START;

void BW_Pump_R4(void);

#endif
