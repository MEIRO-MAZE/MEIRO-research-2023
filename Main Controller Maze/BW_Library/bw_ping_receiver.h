/*==============================================================================================
								  PROJECT BW Ver.1.0
							BW PING))) RANGEFINDER RECEIVER
==============================================================================================*/

#ifndef BW_PING_RECEIVER_H
#define BW_PING_RECEIVER_H

#include "main.h"


//USART COMM MACRO
#define ON_Ping 0x01
#define OFF_Ping 0x02
#define TO 0x04
#define USART_ACTIVE_MODE 1
#define MAX_STRLEN 10000

//USART COMM VARIABLES
extern char received_string[MAX_STRLEN];
extern char buf[16];
extern char data1_lcd[16];
extern char data2_lcd[16];
extern char tampil_adc[16];
extern unsigned int PING_F, PING_AR, PING_AL, PING_L, PING_R, PING_RR, PING_RL, PING_RE, PING_UR, PING_UL;

extern int Ping[10],USART_Count;
extern unsigned int COMMAND_FLAG_A;
extern unsigned int COMMAND_FLAG_B;
extern unsigned int COMMAND_COMPLETED;
extern unsigned int COMMAND_NOT_RECEIVED;

extern int counts,SHARP_FL_BUFFER,SHARP_BR_BUFFER,SHARP_BL_BUFFER;
extern int PING_ERROR[8], ping_count;

//Pin PING
#define PING_LEFT 			0
#define PING_RIGHT 			1
#define PING_FRONT 			2
#define PING_ASKEW_LEFT 	3
#define PING_ASKEW_RIGHT 	4
#define PING_REAR 			8
#define PING_REAR_LEFT 		6
#define PING_REAR_RIGHT 	7
#define PING_UP_RIGHT		9
#define PING_UP_LEFT 		5

//SHARP IR RANGEFINDER
extern unsigned int SHARP[];
extern unsigned int SHARP_GRIPPER[];


//Pin SHARP IR
#define IR_FRONT		0
#define IR_STAIRS		1
#define IR_ASKEW_FR		2
#define IR_RIGHT		3
#define IR_ASKEW_RR		4
#define IR_ASKEW_FL		5
#define IR_LEFT			6
#define IR_ASKEW_RL		7


#define SHARP_FRONT_R 0
#define SHARP_FRONT_L 1
#define SHARP_BUMPER_LEFT	2
#define SHARP_BUMPER_RIGHT	3


/*
 * USART PING
 */
void Display_Ping_Status (void);
void Display_Sharp_Status (void);

void USART3_Init(uint32_t baudrate); //TO RANGEFINDER uCU;
void USART3_PutChar(char DATA);

#endif


