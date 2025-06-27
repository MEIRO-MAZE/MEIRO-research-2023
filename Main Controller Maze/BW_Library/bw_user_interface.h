/*==============================================================================================
								 	 PROJECT BW Ver.1.0
								  	 USER INTERFACE LIBRARY
==============================================================================================*/
#ifndef BW_USER_INTERFACE_H
#define BW_USER_INTERFACE_H

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "bw_macro_lib.h"
#include <bw_systick_delay.h>
#include "bw_global_var.h"

#define RCC_AHB1Periph_BUTTON RCC_AHB1Periph_GPIOE
#define BUTTON_PORT GPIOE
#define BUTTON_PIN GPIO_Pin_5
#define BW_BUTTON_INPUT GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_5)
#define BW_BUTTON_CLICKED GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_5)==1
#define BW_BUTTON_UNCLICKED   GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_5)==0

void Button_Init(void);

void StartButton_Init(void);
void UserButton_Init(void);
void SND_ACT_LED_Init(void);
void FIRE_LED_Init(void);
void TCS_GRIPPER_LED_Init(void);
void BW_LED_Interrupt_Init(void);

#define RCC_AHB1Periph_USERBUTTON_A 	RCC_AHB1Periph_GPIOE
#define USERBUTTON_A_PORT 				GPIOE
#define USERBUTTON_A_PIN 				GPIO_Pin_6
#define BUTTON_A_INPUT 					GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_6)
#define BUTTON_A_CLICKED 				GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_6)==1
#define BUTTON_A_UNCLICKED   			GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_6)==0

//USER BUTTON B
#define RCC_AHB1Periph_USERBUTTON_B 	RCC_AHB1Periph_GPIOE
#define USERBUTTON_B_PORT 				GPIOE
#define USERBUTTON_B_PIN 				GPIO_Pin_4
#define BUTTON_B_INPUT 					GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4)
#define BUTTON_B_CLICKED 				GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4)==1
#define BUTTON_B_UNCLICKED   			GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4)==0

#define BUTTON_IDLE (BW_BUTTON_INPUT|BUTTON_A_INPUT|BUTTON_B_INPUT)==0

/*
 * BW BUZZER
 */
#define RCC_AHB1Periph_BUZZER 			RCC_AHB1Periph_GPIOC
#define BUZZER_PORT 					GPIOC
#define BUZZER_PIN 						GPIO_Pin_13
#define BUZZ_ON 						GPIO_SetBits(BUZZER_PORT, BUZZER_PIN);
#define BUZZ_OFF 						GPIO_ResetBits (BUZZER_PORT, BUZZER_PIN);


void Buzzer_Init(void);
void BW_Buzz(int counter);

/*
 * BW LED
 */
#define RCC_AHB1Periph_LED RCC_AHB1Periph_GPIOD
#define LED_PORT 	GPIOD
#define LED_PIN 	GPIO_Pin_13

#define BW_LED_ON GPIO_SetBits(LED_PORT, LED_PIN);
#define BW_LED_OFF GPIO_ResetBits(LED_PORT, LED_PIN);

#define BW_LED_BLINK_ON TIM_ITConfig(TIM5, TIM_IT_Update, ENABLE);
#define BW_LED_BLINK_OFF TIM_ITConfig(TIM5, TIM_IT_Update, DISABLE);

/*
 * BW FIRE INDICATOR LED (RED LED)
 */
#define RCC_AHB1Periph_FIRE_LED RCC_AHB1Periph_GPIOD
#define FIRE_LED_PORT GPIOA
#define FIRE_LED_PIN GPIO_Pin_1

#define FIRE_LED_OFF 	GPIO_ResetBits(FIRE_LED_PORT, FIRE_LED_PIN);
#define FIRE_LED_ON 	GPIO_SetBits(FIRE_LED_PORT, FIRE_LED_PIN);

#define FIRE_LED_BLINK_ON TIM_ITConfig(TIM5, TIM_IT_Update, ENABLE);
#define FIRE_LED_BLINK_OFF TIM_ITConfig(TIM5, TIM_IT_Update, DISABLE);

/*
 * MZ TCS GRIPPER LED (WHITE LED)
 */
#define RCC_AHB1Periph_GRIPPER_LED RCC_AHB1Periph_GPIOE
#define GRIPPER_LED_PORT GPIOE
#define GRIPPER_LED_PIN GPIO_Pin_0

#define GRIPPER_LED_OFF 	GPIO_ResetBits(GRIPPER_LED_PORT, GRIPPER_LED_PIN);
#define GRIPPER_LED_ON 		GPIO_SetBits(GRIPPER_LED_PORT, GRIPPER_LED_PIN);

/*
 * BW SOUND ACTIVATION INDICATOR (GREEN LED) ditukar led api
 */

#define RCC_AHB1Periph_SND_ACT_LED 	RCC_AHB1Periph_GPIOA
#define SND_ACT_LED_PORT 			GPIOA
#define SND_ACT_LED_PIN 			GPIO_Pin_5

#define SND_ACT_LED_OFF 	GPIO_ResetBits(SND_ACT_LED_PORT, SND_ACT_LED_PIN);
#define SND_ACT_LED_ON 		GPIO_SetBits(SND_ACT_LED_PORT, SND_ACT_LED_PIN);

/*
 * BW COMPUTER VISION INDICATOR (GREEN LED)
 */
#define RCC_AHB1Periph_COMVISION_LED 	RCC_AHB1Periph_GPIOD
#define COMVISION_LED_PORT 				GPIOD
#define COMVISION_LED_PIN 				GPIO_Pin_13

#define COMVISION_LED_ON 	GPIO_SetBits(COMVISION_LED_PORT, COMVISION_LED_PIN);
#define COMVISION_LED_OFF 	GPIO_ResetBits(COMVISION_LED_PORT, COMVISION_LED_PIN);


extern uint16_t led_counter;
extern uint16_t led_off_counter;
extern uint16_t led_snd_off_counter;

void BW_Initial_Setup(int BW_MODE);
void Led_Blink(void);
void Test_Mode_6(void);
extern int cntt;
extern int taek;
extern int MENU_VAR;


#endif
