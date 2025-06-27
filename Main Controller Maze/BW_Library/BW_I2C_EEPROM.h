#ifndef BW_I2C_EEPROM_H
#define BW_I2C_EEPROM_H

#include "main.h"

#define ADDRESS_EEPROM 				0x50
#define PAGE_R4A_TENGAH_H			1
#define PAGE_R4A_TENGAH_L			2
#define PAGE_R4B_TENGAH_H			15
#define PAGE_R4B_TENGAH_L			16
#define PAGE_R4A_SERONG_KANAN_H		3
#define PAGE_R4A_SERONG_KANAN_L		4
#define PAGE_R4A_SERONG_KIRI_H		5
#define PAGE_R4A_SERONG_KIRI_L		6
#define PAGE_R4B_SERONG_KANAN_H		11
#define PAGE_R4B_SERONG_KANAN_L		12
#define PAGE_R4B_SERONG_KIRI_H		13
#define PAGE_R4B_SERONG_KIRI_L		14
#define PAGE_R4A_KANAN_H			7
#define PAGE_R4A_KANAN_L			8
#define PAGE_R4A_KIRI_H				9
#define PAGE_R4A_KIRI_L				10
#define PAGE_START_MID_H			17
#define PAGE_START_MID_L			18
#define PAGE_R1BC_H					19
#define PAGE_R1BC_L					20
#define PAGE_CAT_MIN_RANGE			21
#define PAGE_TRACER_RULE_UP			22
#define PAGE_TRACER_RULE_DOWN		23

int16_t BW_Write_I2C_EEPROM(uint8_t ADDRESS, uint8_t VALUE, uint8_t eeaddress);
int16_t BW_Read_I2C2(uint8_t ADDRESS, uint8_t REGISTER, uint8_t eeaddress);
uint8_t BW_ReadMultiByte_I2C(uint8_t ADDRESS, uint8_t REGISTER, uint8_t BYTE);
void Save_CMPS12_DATA(void);
int16_t Load_CMPS_DATA(void);
void display_EEPROM_DATA(void);
void Load_CAT_MIN_DATA(void);
void CAT_CALIBRATION(void);
void copy_EEPROM_data(void);
void BW_COPY_TRACER_DATA(void);
void BW_LOAD_TRACER_DATA(void);
int16_t I2C2_TimeOut(int16_t VALUE);

extern int R4A_TENGAH_H;
extern int R4A_TENGAH_L;
extern int R4B_TENGAH_H;
extern int R4B_TENGAH_L;
extern int R4A_SERONG_KANAN_H;
extern int R4A_SERONG_KANAN_L;
extern int R4A_SERONG_KIRI_H;
extern int R4A_SERONG_KIRI_L;
extern int R4B_SERONG_KANAN_H;
extern int R4B_SERONG_KANAN_L;
extern int R4B_SERONG_KIRI_H;
extern int R4B_SERONG_KIRI_L;
extern int R4A_KANAN_H;
extern int R4A_KANAN_L;
extern int R4A_KIRI_H;
extern int R4A_KIRI_L;
extern int START_MID_H;
extern int START_MID_L;
extern int R1BC_H;
extern int R1BC_L;


#endif
