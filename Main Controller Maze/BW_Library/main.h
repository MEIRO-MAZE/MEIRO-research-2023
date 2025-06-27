/*==============================================================================================
								 PROJECT BW Ver.1.0
								  	 MAIN LIBRARY
==============================================================================================*/

#ifndef MAIN_H
#define MAIN_H

/*
 * BW STANDARD LIBRARY
 */
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_adc.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_usart.h"
#include "stm32f4xx_i2c.h"
#include "stm32f4xx_dma.h"
#include "misc.h"
#include <math.h>

#include "stdio.h"
#include "stdlib.h"
//#include "stdint.h"
#include "string.h"
#include "stdarg.h"
#include "stdbool.h"

//-------------------------------------KRPAI Library-------------------------------------------//
//#include "delay.h"
//#include "lcd.h"

//ESSENTIAL GLOBALLY
#include <bw_macro_lib.h>
#include <bw_global_var.h>
#include <bw_systick_delay.h>


//============NEW LIBRARY (PHOENIX CODE)============//
#include "BW_Hex_Cfg.h"
#include "BW_Phoenix.h"
#include "BW_Phoenix_Code.h"
#include "BW_Phoenix_Driver_AX12.h"


//USER INTERFACES
#include <bw_user_interface.h>
#include <bw_rotary_switch.h>
#include <bw_lcd.h>
//#include "bw_i2c_lcd.h"

//GRIPPER
#include <bw_gripper_2021.h>
#include "mz_servo_pwm.h"

//BW SOUND ACTIVATION
#include "bw_sound_activation.h"

//Hydro Pump Extinguisher
#include "bw_extinguisher.h"

#include "bw_ping_receiver.h"

//BW HEXAPOD COMMAND
#include "bw_hexapod_cmd.h"

//BW USART COMMUNICATION
#include "bw_usart_comm.h"

//BW MPU6050 IMU
//#include "bw_mpu6050.h"
//#include "bw_gy_85.h"
#include <bw_cmps11.h>

//PID CONTROLLER
#include <bw_pid_controller.h>

//BW DYNAMIXEL XL-320
#include "bw_dynamixel_xl_320.h"
#include "KRSI_stm32f4xx_dyna.h"

#include "bw2017_algorithm.h"
#include "bw_2021_algorithm.h"

//BW ADDITIONAL FLAME SENSOR SIDE
#include "bw_flame_sensor.h"

//BW DYNAMIXEL AX-12A LIBRARY
#include "bw_dynamixel_ax_12a.h"

//BW DYNAMIXEL HEXAPOD LOCOMOTION LIBRARY
#include "bw_dynamixel_hexapod_cmd.h"

//BW MPU6050 RECEIVER
#include "bw_mpu6050_receiver.h"

//BW TCS3200
#include "bw_tcs3200_receiver.h"

#include "BW_I2C_EEPROM.h"

#include "bw_UV-TRON.h"

//Global Typedef
GPIO_InitTypeDef  			GPIO_InitStructure, GPIO_I2C,GPIO_InitStructure;
I2C_InitTypeDef  			I2C_InitStructure;
TIM_TimeBaseInitTypeDef     TIM_TimeBaseStructure;
TIM_OCInitTypeDef           TIM_OCInitStructure;

#define BW_MODE_DEFAULT 0
#define BW_MODE_1 1
#define BW_MODE_2 2
#define BW_MODE_3 3
#define BW_MODE_4 4
#define BW_MODE_5 5
#define BW_MODE_6 6

#define YOGI 12


extern unsigned int BW_LOCATION[];
extern unsigned int LOCATION_CORRIDOR;
extern unsigned int LOCATION_ROOM;
#define PRESENT_LOC 0
#define LAST_LOC 1


extern unsigned int INITIAL_ZONE;
extern unsigned int ZONE;

extern unsigned int ZONE_BLACK;
extern unsigned int ZONE_RED;
extern unsigned int ZONE_BLUE;
extern unsigned int TRACER;
extern unsigned int FIRE_PUTOFF;

extern unsigned int COLOUR_STAT;

extern unsigned int ZONE;
extern unsigned int ZONE_RED;
extern unsigned int ZONE_BLUE;

/*
 * BW CAT COLLISION SHIFT FOLLOW
 */
extern unsigned int CAT_SHIFT_FOLLOW;
extern unsigned int SHIFT_FOLLOW;
extern unsigned int NO_SHIFT;

extern uint16_t led_off_counter;
extern uint16_t led_snd_off_counter;

/*
 * BW CROSS_ZONE VARIABLES
 */
extern unsigned int BW_CROSSING_AUTHORITY;
extern unsigned int CROSS_DISABLED;
extern unsigned int CROSS_ENABLED;
extern unsigned int BW_CROSSING_STATUS;
extern unsigned int NO_CROSSING;
extern unsigned int CROSSING_SUCCESS;
extern unsigned int CROSSING_FAILED;


/*
 * BW SOUND SCAN
 */
#define SOUND_SCAN   GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)


//CARPET CODE
extern unsigned int COLOUR_NONE;
extern unsigned int COLOUR_BLACK;
extern unsigned int COLOUR_GRAY;
extern unsigned int COLOUR_WHITE;
extern unsigned int COLOUR_RED;
extern unsigned int COLOUR_BLUE;


//FIRE FLAG
extern unsigned int FIRE;
//MANDATORY COMMAND HYBRID IMU PROCESSOR
extern const int IMU_CMD_SEND_RAW; //DATA
extern unsigned int BW_SOUND_ACTIVATED;
//SOUND
extern const int SOUNDCHECK;

#endif
