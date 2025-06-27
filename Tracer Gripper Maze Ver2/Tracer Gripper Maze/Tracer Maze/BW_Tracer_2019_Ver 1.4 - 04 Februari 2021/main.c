#include "Tracer_2019.h"
#include "i2c_vl530x.h"
#include "MZ_VL53L0X.h"
#include <stdio.h>

struct VL53L0X myTOFsensor = {.io_2v8 = true, .address = 0b0101001, .io_timeout = 500, .did_timeout = false};
uint16_t dist;
char buffer [25];

unsigned int STATUS, ADC_DATA_F, ADC_DATA_M,ADC_DATA_R;
char data[30];
int Reset = 0;


int main(void)
{
	setclockto72();
	USART1_Init(1000000);
	BW_ADC_Init();
	I2C_Initialize(I2C2);
	DelayInit();
	TCS_Config();
	TIM_Init();

	init_i2c1();

	VL53L0X_init(&myTOFsensor,1);

	VL53L0X_setSignalRateLimit(&myTOFsensor, 0.1);
	VL53L0X_setVcselPulsePeriod(&myTOFsensor,VcselPeriodPreRange, 18);
	VL53L0X_setVcselPulsePeriod(&myTOFsensor,VcselPeriodFinalRange, 14);

	VL53L0X_setMeasurementTimingBudget(&myTOFsensor, 200000);

	VL53L0X_startContinuous(&myTOFsensor, 0);

    while(1)
    {
	    	dist = VL53L0X_readRangeContinuousMillimeters(&myTOFsensor);
	    	DelayMs(10);

	    	Distance_VL_H = dist >> 8;
	    	Distance_VL_L = dist & 0xFF;

			Tracer_front_R_H = TCS_F.RedData >> 8;
			Tracer_front_R_L = TCS_F.RedData & 0xFF;

			Tracer_front_G_H = TCS_F.GreenData >> 8;
			Tracer_front_G_L = TCS_F.GreenData & 0xFF;

			Tracer_front_B_H = TCS_F.BlueData >> 8;
			Tracer_front_B_L = TCS_F.BlueData & 0xFF;

			USART_Send(USART1,COMMAND_FLAG_A);				//case -
			USART_Send(USART1,COMMAND_FLAG_B);				//case -
			USART_Send(USART1,RGB_VAL_FLAG);				//case 1
			USART_Send(USART1,Tracer_front_R_H);			//case 2
			USART_Send(USART1,Tracer_front_R_L);			//case 3
			USART_Send(USART1,Tracer_front_G_H);			//case 4
			USART_Send(USART1,Tracer_front_G_L);			//case 5
			USART_Send(USART1,Tracer_front_B_H);			//case 6
			USART_Send(USART1,Tracer_front_B_L);			//case 7
			USART_Send(USART1,Tracer_Stat[FINAL]);			//case 8
			USART_Send(USART1,Distance_VL_H);				//case 9
			USART_Send(USART1,Distance_VL_L);				//case 10
//			SHARP_IR_read(IR_FRONT);USART_Send(USART1,sharp_data[IR_FRONT]); //case 11
    }
}
