/*
 * |----------------------------------------------------------------------
 *
 * Edited by  :
 * Tim KRSI - 2018 Teknik Elektro Universitas Brawijaya
 * Tahun      : 2018
 * Software   : Stefanus Dion          (2014)(penanggung jawab)
 *              Abyyunda Yudha Pratama (2015)
 *              Yosef Kresna           (2016)
 *
 * 04/07/2015 : Change the variables in each functions as global variables
 * 				Give comments for each functions
 * |-----------------------------------------------------------------------
 */

#ifndef DYNA_H
#define DYNA_H

//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------
#include "main.h"

//--------------------------------------------------------------------
// EEPROM area
//--------------------------------------------------------------------
#define XL_MODEL_NUMBER				0
#define XL_VERSION					2
#define XL_ID						3
#define XL_BAUDRATE					4
#define XL_RETURN_DELAY_TIME        5
#define XL_CW_ANGLE_LIMIT			6
#define XL_CCW_ANGLE_LIMIT			8
#define XL_CONTROL_MODE				11
#define XL_LIMIT_TEMPERATURE		12
#define XL_LOW_LIMIT_VOLTAGE		13
#define XL_UP_LIMIT_VOLTAGE			14
#define XL_MAX_TORQUE				15
#define XL_RETURN_LEVEL             17
#define XL_ALARM_SHUTDOWN           18

//--------------------------------------------------------------------
//RAM area
//--------------------------------------------------------------------
#define XL_TORQUE_ENABLE            24
#define XL_LED                      25
#define XL_D_GAIN					27
#define XL_I_GAIN					28
#define XL_P_GAIN					29
#define XL_GOAL_POSITION			30
#define XL_GOAL_SPEED				32
#define XL_GOAL_TORQUE				35
#define XL_PRESENT_POSITION			37
#define XL_PRESENT_SPEED			39
#define XL_PRESENT_LOAD				41
#define XL_PRESENT_VOLTAGE          45
#define XL_PRESENT_TEMPERATURE      46
#define XL_REGISTERED_INSTRUCTION   47
#define XL_MOVING                   49
#define XL_ERROR_STATUS				50
#define XL_PUNCH					51

//--------------------------------------------------------------------
//Status return
//--------------------------------------------------------------------
#define XL_RETURN_NONE              0
#define XL_RETURN_READ              1
#define XL_RETURN_ALL               2

//--------------------------------------------------------------------
//Instruction set
//--------------------------------------------------------------------
#define XL_PING                     0x01
#define XL_READ_DATA                0x02
#define XL_WRITE_DATA               0x03
#define XL_REG_WRITE                0x04
#define XL_ACTION                   0x05
#define XL_RESET                    0x06
#define XL_REBOOT					0x08
#define XL_STATUS					0x55
#define XL_SYNC_READ				0x82
#define XL_SYNC_WRITE               0x83
#define XL_BULK_READ				0x92
#define XL_BULK_WRITE				0x93

//--------------------------------------------------------------------
//Special
//--------------------------------------------------------------------
#define OFF                         0
#define ON                          1
#define LEFT					    0
#define RIGTH                       1
#define WHEEL_MODE					1
#define JOINT_MODE					2

#define XL_ID_LENGTH				6
#define XL_GOAL_SP_LENGTH			9
#define XL_GOAL_P_LENGTH			7
#define XL_GOAL_S_LENGTH			7
#define XL_MODE_LENGTH				6
#define XL_DELAYTIME_LENGTH			6
#define XL_BAUDRATE_LENGTH			6
#define XL_RESET_LENGTH				4
#define BROADCAST_ID                254
#define XL_START1	                0xFF
#define XL_START2					0xFD
#define XL_RESERVED					0x00
#define CRC_ACCUM					0
#define TIME_OUT                    10
//#define TX_DELAY_TIME1		    	150

//--------------------------------------------------------------------
//Set Direction Pin
//--------------------------------------------------------------------
GPIO_TypeDef * GPIOx;
uint16_t DirPin;

//--------------------------------------------------------------------
//Data EEPROM
//--------------------------------------------------------------------
unsigned char MODEL,			// Model number
			  VERSION,			// Information on the version of firmware
			  ID,				// ID of the dynamixel
			  BAUDRATE,			// Baudrate of the dynamixel
			  R_DELAYTIME,		// Return delay time
			  CW_LIMIT_L,		// Clockwise angle limit
			  CW_LIMIT_H,
			  CCW_LIMIT_L,		// Counterclockwise angle limit
			  CCW_LIMIT_H,
			  MODE,				// Control mode (Wheel mode or Joint mode)
			  TEMPERATURE_LIMIT,// Internal temperature limit
			  V_L_LIMIT,		// Lowest limit voltage
			  V_U_LIMIT,		// Upper limit voltage
			  MAX_TORQUE_L,		// Lowest byte of maximum torque
			  MAX_TORQUE_H,
			  R_LEVEL,			// Return level
			  ALARM;			// Shutdown for alarm

//--------------------------------------------------------------------
//Data RAM READ/WRITE
//--------------------------------------------------------------------
unsigned char TOR_EN,			// Torque on/off
			  LED,				// LED on/off
			  D_GAIN,			// D gain
			  I_GAIN,			// I gain
			  P_GAIN,			// P gain
			  POS_L,			// Goal position
			  POS_H,
			  SPEED_L,			// Goal speed
			  SPEED_H,
			  TORQ_L,			// Goal Torque
			  TORQ_H;

//--------------------------------------------------------------------
//Data RAM READ
//--------------------------------------------------------------------
unsigned char C_POS,			// Current position
			  C_POS_L,
			  C_POS_H,
			  C_SPEED,			// Current speed
			  C_SPEED_L,
			  C_SPEED_H,
			  C_LOAD,			// Current load
			  C_LOAD_L,
			  C_LOAD_H,
			  C_VOLT,			// Current voltage
			  C_TEMP,			// Present temperature
			  C_INST,			// Registered instruction
			  C_MOV,			// Moving
			  ERROR_STAT;		// Hardware error status

//--------------------------------------------------------------------
//Instruction Packet
//--------------------------------------------------------------------
unsigned char XL_ADDRESS_L,
			  XL_ADDRESS_H,
			  XL_LENGTH_L,
			  XL_LENGTH_H,
			  CRC_L,
			  CRC_H;
uint16_t CRC_X;
char count;
unsigned char Packet_Length;

void DirPin_Init();
void Dyna_move(unsigned char ID, int Position);
void Dyna_movespeed(unsigned char ID, int Position, int Speed,int delay_time);
void Dyna_setID(unsigned char ID, unsigned char newID);
void Dyna_setmode(unsigned char ID, uint8_t Mode);
void Dyna_movewheel(unsigned char ID, int Speed);
void Dyna_delaytime(unsigned char ID, unsigned char delaytime);
void Dyna_baudrate(unsigned char ID, unsigned char baudrate);
unsigned short update_crc(unsigned short crc_accum, unsigned char *data_blk_ptr, unsigned short data_blk_size);

#endif

