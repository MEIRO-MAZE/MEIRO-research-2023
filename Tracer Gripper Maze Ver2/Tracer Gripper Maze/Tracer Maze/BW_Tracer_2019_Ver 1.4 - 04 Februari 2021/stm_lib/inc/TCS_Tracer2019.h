#ifndef TCS_TRACER2019_H
#define TCS_TRACER2019_H

#include <stm32f10x_i2c.h>
#define TCS34725_ADDRESS 0x29
#define I2C1_TIMEOUT     0x13880

#define TCS34725_GET_RGB 1
#define TCS34725_GET_CLEAR 0

#define RGB_Threshold_front_up 158
#define RGB_Threshold_front_low 113
#define RGB_Threshold_back_up 158
#define RGB_Threshold_back_low 98
#define R_White_Threshold 100

#define TCS34725_WRITE_ENABLE 0x80
#define TCS34725_WRITE_RGBC 0x81
#define TCS34725_WRITE_CONTROL 0x8F
#define TCS34725_READ_CLEARDATA_L 0x94
#define TCS34725_READ_CLEARDATA_H 0x95
#define TCS34725_READ_REDDATA_L 0x96
#define TCS34725_READ_REDDATA_H 0x97
#define TCS34725_READ_GREENDATA_L 0x98
#define TCS34725_READ_GREENDATA_H 0x99
#define TCS34725_READ_BLUEDATA_L 0x9A
#define TCS34725_READ_BLUEDATA_H 0x9B
#define TCS34725_READ_ID 0x92

#define RGBC_TIMING 0xFF
#define TRACER_START 0x03
#define RGBC_MAX_RESOLUTION 0x00
#define RGBC_HIGH_RESOLUTION 0xC0
#define RGBC_MED_RESOLUTION 0xD5
#define RGBC_LOW_RESOLUTION 0xF6
#define RGBC_MIN_RESOLUTION 0xFF
#define RGBC_TRY1_RESOLUTION 0xD6
#define RGBC_TRY2_RESOLUTION 0xFC
#define SET_GAIN_1 0x00

extern uint16_t TCS_DATA[];
extern uint16_t TCS_DATA_2;
extern uint8_t data_byte;
extern uint16_t ERROR_DATA;
extern uint8_t ERROR_WRITE1;
extern uint8_t ERROR_WRITE2;
extern uint8_t ERROR_WRITE3;
extern uint8_t ERROR_WRITE4;
extern uint8_t ERROR_WRITE5;
extern uint8_t ERROR_WRITE6;
extern uint8_t data_H;
extern uint8_t data_L;
extern uint8_t final_data;

extern unsigned int Tracer_front_R_H;
extern unsigned int Tracer_front_R_L;
extern unsigned int Tracer_front_G_H;
extern unsigned int Tracer_front_G_L;
extern unsigned int Tracer_front_B_H;
extern unsigned int Tracer_front_B_L;

extern unsigned int Distance_VL_H;
extern unsigned int Distance_VL_L;

extern	unsigned int Tracer_back_R_H;
extern	unsigned int Tracer_back_R_L;
extern	unsigned int Tracer_back_G_H;
extern	unsigned int Tracer_back_G_L;
extern	unsigned int Tracer_back_B_H;
extern	unsigned int Tracer_back_B_L;

struct TCS34725_DATA{
	uint8_t DATA_H;
	uint8_t DATA_L;
	uint16_t BlueData;
	uint16_t GreenData;
	uint16_t RedData;
}TCS_CLEAR_FRONT,TCS_CLEAR_BACK,TCS_RED_FRONT,TCS_RED_BACK,TCS_GREEN_FRONT,TCS_GREEN_BACK,TCS_BLUE_FRONT,TCS_BLUE_BACK,TCS_F,TCS_B;

uint8_t TCS34725_Read_data(I2C_TypeDef *I2Cx,unsigned char Command);
uint8_t I2C1_TimeOut_LCD(I2C_TypeDef *I2Cx,uint8_t VALUE);
uint8_t TCS34725_Write_Data(I2C_TypeDef *I2Cx,unsigned char Command,unsigned char data);
void TCS_Get_RAW(int section);
void TCS_Get_Colour();
void TCS_Get_Rule(int mode);
void IWDG_Reset_Init();
void TCS_GetRealData(int section);
void TCS_Get_RGB(int section);

#endif
