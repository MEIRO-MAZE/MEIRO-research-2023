/*==============================================================================================
								  PROJECT BW Ver.1.0
							THERMOPHILE ARRAY AND SERVO LIBRARY
==============================================================================================*/
#ifndef BW_USART_COMM_H
#define BW_USART_COMM_H

#include "main.h"

/*
 * BW USART VARIABLES
 */
#define RAW_VAL_FLAG 0x52
#define STAT_DATA 0x11
#define TH_DATA 0x12
#define RGB_VAL_FLAG 0x13
extern char command_code[];
extern unsigned int USART_Bluetooth_Count;
extern unsigned int COMMAND_FLAG_A;
extern unsigned int COMMAND_FLAG_B;
extern unsigned int TRACER_CMD_SEND_RGB;
extern unsigned int COMMAND_COMPLETED;
extern unsigned int COMMAND_NOT_RECEIVED;
/*
 *  TCS3200 RAW VALUE FLAG
 */


//CALIBRATION COMMAND
extern const int TCS_CALIBRATE_WHITE;
extern const int TCS_CALIBRATE_BLACK;
extern const int TCS_CALIBRATE_GRAY;
extern const int TCS_CALIBRATE_GETRULE;

void USART1_Init(uint32_t baudrate);
void USART2_Init(uint32_t baudrate);

void Sendto_PC(USART_TypeDef* USARTx, const char *pFormat, ... );

void Display_FlameSense(void);

void TCS3200_Transmit(USART_TypeDef* USARTx, int DATA);
void TCS34725_Transmit(USART_TypeDef* USARTx, int DATA);

extern unsigned int USART2_DATA[];
extern unsigned int FlameSense[];
extern unsigned int USARTFlame_Counter;
extern unsigned int USARTFlameDigi_Counter;
extern unsigned int USARTVL_Counter;

extern unsigned int FlameSenseDigi[];

extern unsigned int FlameFrontDigi[];

extern unsigned int FLAME_SENSOR[];

extern unsigned int TCS3200_SLV_BUF[];

extern unsigned int TCS34725_SLV_BUF[];


extern unsigned int VL_SENSOR[];
extern unsigned int VL_Value[];
extern unsigned int Done;

/*
 *  TCS3200 SLAVE VARIABLES
 */
extern unsigned int TCS3200_SLV_CNT;
extern unsigned int TCS3200_SLV_STAT[];
extern unsigned int TCS3200_SLV_DATA[];
extern unsigned int TCS34725_SLV_CNT;
extern unsigned int TCS34725_SLV_STAT[];
extern unsigned int TCS34725_SLV_DATA[];
extern unsigned int FRONT_PRESENT;
extern unsigned int FRONT_PREVIOUS;
extern unsigned int MIDDLE_PRESENT;
extern unsigned int MIDDLE_PREVIOUS;

extern unsigned int TCS3200_CMD_CODE[];

extern volatile unsigned int DATA_TRACER_READY;
extern volatile unsigned int DATA_TRACER_GRIP_READY;

//CARPET CODE
extern unsigned int COLOUR_NONE;
extern unsigned int COLOUR_BLACK;
extern unsigned int COLOUR_GRAY;
extern unsigned int COLOUR_WHITE;
extern unsigned int COLOUR_RED;
extern unsigned int COLOUR_BLUE;

/*
 * FOLLOW TRACER FLAG VARIABLES
 */
extern unsigned int FOLLOWTRACER_FLAG;
extern unsigned int FOLLOWTRACER_ENABLE;
extern unsigned int FOLLOWTRACER_DISABLE;

//extern unsigned int UV_state;

extern unsigned int TRACER_VALUE[];
extern int RANK[8];
extern unsigned int Flame_Stat;
extern uint8_t data_coba;

extern char FlameValueNew[6];
extern char FlameState;

extern unsigned int SHARP_FRONT[];

//void UART4_Init_Flame(uint32_t baudrate);
//void USART6_Init_Flame(uint32_t baudrate);
void USART1_Init_Tracer(uint32_t baudrate);
void USART6_Init_Tracer_Grip(uint32_t baudrate);

#endif
