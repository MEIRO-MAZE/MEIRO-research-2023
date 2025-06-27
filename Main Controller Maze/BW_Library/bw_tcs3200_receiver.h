/*==============================================================================================
								PROJECT BW 2016 Ver.1.0
							  BW TCS3200 RECEIVER LIBRARY
==============================================================================================*/
#ifndef BW_TCS3200_RECEIVER_H
#define BW_TCS3200_RECEIVER_H

#include "main.h"

/*
 *  TCS3200 SLAVE VARIABLES
 */
extern unsigned int TCS3200_SLV_CNT;
extern unsigned int TCS34725_SLV_CNT;
extern unsigned int TCS3200_SLV_STAT[];
extern unsigned int TCS34725_SLV_STAT[];
extern unsigned int TCS3200_SLV_DATA[];
extern unsigned int TCS34725_SLV_DATA[];
extern unsigned int FRONT_PRESENT;
extern unsigned int FRONT_PREVIOUS;
extern unsigned int MIDDLE_PRESENT;
extern unsigned int MIDDLE_PREVIOUS;

extern unsigned int TCS3200_CMD_CODE[];
//TCS3200 SLAVE COMMAND FLAG
extern unsigned int COMMAND_FLAG_A;
extern unsigned int COMMAND_FLAG_B;

extern unsigned int DUMMY_DATA_A;
extern unsigned int DUMMY_DATA_G;

extern unsigned int TRIAL_MODE;
extern unsigned int CALIBRATION_MODE;
extern unsigned int BUTTON_A;
extern unsigned int BUTTON_B;
extern unsigned int CMD_COMPLETED;
extern unsigned int CMD_IDLE;

unsigned int START_BUTTON_CMD;

//RECEIVED DATA
unsigned int RCV_IDLE;
unsigned int RCV_START;
unsigned int RCV_BUTTON_A;
unsigned int RCV_BUTTON_B;


//NEW COMMAND DATA
extern unsigned int TCS_CMD_SEND_RAW;
extern unsigned int TCS_CMD_SEND_CONCLUSION;
extern unsigned int TCS_CMD_SAVE_EEPROM;



extern unsigned int HYBRID_CMD_SEND_THRESHOLD;


#define IDLE 			0
#define SEND_CONCLUSION 1
#define SEND_FRONT		2
#define SEND_MIDDLE		3
#define SAVE_EEPROM 	4
#define SEND_EEPROM		5


#define RED 	0
#define GREEN 	1
#define BLUE	2
#define WHITE	3
#define SUM		4

extern unsigned int COLOUR_NONE;
extern unsigned int COLOUR_BLACK;
extern unsigned int COLOUR_GRAY;
extern unsigned int COLOUR_WHITE;
extern unsigned int COLOUR_RED;
extern unsigned int COLOUR_BLUE;
extern unsigned int NO_FOLLOW;

//CALIBRATION COMMAND
extern const int TCS_CALIBRATE_WHITE;
extern const int TCS_CALIBRATE_BLACK;
extern const int TCS_CALIBRATE_GRAY;
extern const int TCS_CALIBRATE_GETRULE;

extern const int TCS_FRONT_SHOW_THRESHOLD;
extern const int TCS_MIDDLE_SHOW_THRESHOLD;

/*
 *  PHOTODIODE TRACER CALIBRATION COMMAND
 */

//BLACK/WHITE PHOTODIODE TRACER PROCESSOR COMMAND
extern unsigned int TRACER_CMD_SEND_RAW;
extern const int TRACER_CALIBRATE_GRAY;
extern const int TRACER_CALIBRATE_WHITE;
extern const int TRACER_CALIBRATE_BLACK;
extern const int TRACER_CALIBRATE_GETRULE;

/*
 *  NEW COMMAND FOR OPTIMIZATION
 */
extern unsigned int CMD_GET_TCS3200;
extern unsigned int CMD_GET_TRACER;
extern unsigned int CMD_TRACER_COPY_DATA;
//TCS3200_Transmit(UART5, CMD_GET_TCS3200);
//TCS3200_Transmit(UART5, CMD_GET_TRACER);


void Hybrid_TCS3200Tracer_MainMenu(void);
void Display_Threshold_Raw(void);
void Display_Threshold_RGB(void);
void Tracer_Calibration(void);
void Tracer_Cal_DisplayStat(int MODE);
void Display_Tracer_Data(void);
void Display_Raw_Data(void);
void Display_tracer_stat(void);
void Display_RGB_Data(unsigned int Tracer);
#endif
