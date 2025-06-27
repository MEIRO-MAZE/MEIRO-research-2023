#include "TCS_Tracer2023.h"
#include "Tracer_2023.h"
#include "stm32f10x_tim.h"


uint16_t TCS_DATA[3] = {0,0,0};
uint16_t TCS_DATA_2 = 0;
uint8_t data_byte=0;
uint16_t ERROR_DATA=0;
uint8_t ERROR_WRITE1=0;
uint8_t ERROR_WRITE2=0;
uint8_t ERROR_WRITE3=0;
uint8_t ERROR_WRITE4=0;
uint8_t ERROR_WRITE5=0;
uint8_t ERROR_WRITE6=0;
uint8_t data_H = 0;
uint8_t data_L = 0;
uint8_t final_data = 0;

unsigned int Tracer_front_R_H=0;
unsigned int Tracer_front_R_L=0;
unsigned int Tracer_front_G_H=0;
unsigned int Tracer_front_G_L=0;
unsigned int Tracer_front_B_H=0;
unsigned int Tracer_front_B_L=0;

unsigned int Tracer_back_R_H=0;
unsigned int Tracer_back_R_L=0;
unsigned int Tracer_back_G_H=0;
unsigned int Tracer_back_G_L=0;
unsigned int Tracer_back_B_H=0;
unsigned int Tracer_back_B_L=0;


uint8_t I2C2_TimeOut_LCD(I2C_TypeDef *I2Cx,uint8_t VALUE)
{
	uint8_t RetVal= VALUE;

//	Stop and reset
	I2C_GenerateSTOP(I2Cx,ENABLE);
	I2C_SoftwareResetCmd(I2Cx,ENABLE);
	I2C_SoftwareResetCmd(I2Cx, DISABLE);
	I2C_SoftwareResetCmd(I2Cx, DISABLE);

// I2C De-Init
	I2C_DeInit(I2Cx);

//	I2C Re-Init
	I2C_Initialize(I2Cx);

    return(RetVal);
}

uint8_t TCS34725_Write_Data(I2C_TypeDef *I2Cx,unsigned char Command,unsigned char data)
{
//	uint16_t RetVal=0;
	uint32_t TimeOut=I2C1_TIMEOUT;

	//Start Sequences
	I2C_GenerateSTART(I2Cx, ENABLE);

	TimeOut=I2C1_TIMEOUT;
	while(!I2C_GetFlagStatus(I2Cx, I2C_FLAG_SB))
	{
		if(TimeOut!=0) TimeOut--;
		else return (I2C1_TimeOut_LCD(I2Cx,1));
	}

	// Slave Address Send (write)
	I2C_Send7bitAddress(I2Cx,TCS34725_ADDRESS<<1,I2C_Direction_Transmitter);

	TimeOut=I2C1_TIMEOUT;
	while(!I2C_GetFlagStatus(I2Cx, I2C_FLAG_ADDR))
	{
		if(TimeOut!=0) TimeOut--;
		else return (I2C1_TimeOut_LCD(I2Cx,2));
	}

	// Clear ADDR Flag
	I2Cx->SR2;

	TimeOut=I2C1_TIMEOUT;
	while(!I2C_GetFlagStatus(I2Cx, I2C_FLAG_TXE))
	{
		if(TimeOut!=0) TimeOut--;
		else return (I2C1_TimeOut_LCD(I2Cx,3));
	}

	// Address Send
	I2C_SendData(I2Cx, Command);

	TimeOut=I2C1_TIMEOUT;
	while(!I2C_GetFlagStatus(I2Cx, I2C_FLAG_TXE))
	{
		if(TimeOut!=0) TimeOut--;
		else return (I2C1_TimeOut_LCD(I2Cx,4));
	}

	//Send Data
	I2C_SendData(I2Cx, data);

	TimeOut=I2C1_TIMEOUT;

	while ((!I2C_GetFlagStatus(I2Cx, I2C_FLAG_TXE)))
	{
		if(TimeOut!=0) TimeOut--;
		else return (I2C1_TimeOut_LCD(I2Cx,5));
	}

	// Stop Sequences
	I2C_GenerateSTOP(I2Cx, ENABLE);

	// Everything's... Alright~ ;) *I hope
}

uint8_t TCS34725_Read_data(I2C_TypeDef *I2Cx,unsigned char Command)
{
	uint32_t TimeOut=I2C1_TIMEOUT;
 	//Start Sequences
    I2C_GenerateSTART(I2Cx, ENABLE);
    /* Test on start flag */
    TimeOut= I2C1_TIMEOUT;
    while(!I2C_GetFlagStatus(I2Cx,I2C_FLAG_SB))
    {
  	  if(TimeOut!=0) TimeOut--;
  	  else return (I2C1_TimeOut_LCD(I2Cx,1));
    }

    I2C_AcknowledgeConfig(I2Cx, ENABLE);

    /* Send device address for write */
    I2C_Send7bitAddress(I2Cx, TCS34725_ADDRESS<<1, I2C_Direction_Transmitter);

    TimeOut= I2C1_TIMEOUT;
    while(!I2C_GetFlagStatus(I2Cx, I2C_FLAG_ADDR))
    {
  	  if(TimeOut!=0) TimeOut--;
  	  else return (I2C1_TimeOut_LCD(I2Cx,2));
    }
    I2Cx -> SR2;
    /* Test on master Flag */
    /* Send the device's internal address to write to */
    TimeOut=I2C1_TIMEOUT;
    while (!I2C_GetFlagStatus(I2Cx, I2C_FLAG_TXE))
    {
  	  if(TimeOut!=0) TimeOut--;
  	  else return (I2C1_TimeOut_LCD(I2C1,3));
    }

    I2C_SendData(I2Cx,Command);

    TimeOut=I2C1_TIMEOUT;
    while ((!I2C_GetFlagStatus(I2Cx, I2C_FLAG_TXE)))
    {
  	  if(TimeOut!=0) TimeOut--;
  	  else return (I2C1_TimeOut_LCD(I2Cx,4));
    }

//  /*=====================================================*/
//        /* Send START condition a second time (Re-Start) */
    I2C_GenerateSTART(I2Cx, ENABLE);

    TimeOut=I2C1_TIMEOUT;
    while (!I2C_GetFlagStatus(I2Cx, I2C_FLAG_SB))
    {
  	  if(TimeOut!=0) TimeOut--;
  	  else return (I2C1_TimeOut_LCD(I2Cx,5));
    }
    /* Test start flag */
    /* Send address for read */
    I2C_Send7bitAddress(I2Cx, TCS34725_ADDRESS<<1, I2C_Direction_Receiver);

    TimeOut= I2C1_TIMEOUT;
    while(!I2C_GetFlagStatus(I2Cx, I2C_FLAG_ADDR))
    {
  	  if(TimeOut!=0) TimeOut--;
  	  else return (I2C1_TimeOut_LCD(I2Cx,6));
    }
    I2Cx -> SR2;
    /* Test Receive mode Flag */
    /* load in all 6 registers */
    while (!I2C_GetFlagStatus(I2Cx, I2C_FLAG_RXNE))
    {
  	  if(TimeOut!=0) TimeOut--;
  	  else return (I2C1_TimeOut_LCD(I2Cx,8));
    }

    I2C_GenerateSTOP(I2Cx, ENABLE);

    data_byte = I2C_ReceiveData(I2Cx);

//      I2C_NACKPositionConfig(I2C1, I2C_NACKPosition_Current);
    I2C_AcknowledgeConfig(I2Cx, DISABLE);

  final_data = data_byte;
  return final_data;
}

void TCS_GetRealData(int section)
{
	uint16_t ERROR_DATA;

	switch(section)
	{
		case SECTION_FRONT:
		{
			ERROR_DATA = TCS34725_Read_data(I2C1,TCS34725_READ_CLEARDATA_L);
			TCS_CLEAR_FRONT.DATA_L = data_byte;

			ERROR_DATA = TCS34725_Read_data(I2C1,TCS34725_READ_CLEARDATA_H);
			TCS_CLEAR_FRONT.DATA_H = data_byte;

			TCS_DATA[SECTION_FRONT]=(TCS_CLEAR_FRONT.DATA_H << 8) | TCS_CLEAR_FRONT.DATA_L;
			if(TCS_DATA[SECTION_FRONT] >= Tracer_Upper_Threshold)
			{
				Tracer_Stat[SECTION_FRONT] = COLOUR_WHITE;
			}
			else if(TCS_DATA[SECTION_FRONT] > Tracer_Lower_Threshold && TCS_DATA[SECTION_FRONT] < Tracer_Upper_Threshold)
			{
				Tracer_Stat[SECTION_FRONT] = COLOUR_GRAY;
			}
			else
			{
				Tracer_Stat[SECTION_FRONT] = COLOUR_BLACK;
			}
		}break;

		case SECTION_BACK:
		{
			ERROR_DATA = TCS34725_Read_data(I2C2,TCS34725_READ_CLEARDATA_L);
			TCS_CLEAR_BACK.DATA_L = data_byte;


			ERROR_DATA = TCS34725_Read_data(I2C2,TCS34725_READ_CLEARDATA_H);
			TCS_CLEAR_BACK.DATA_H = data_byte;


			TCS_DATA[SECTION_BACK]=(TCS_CLEAR_BACK.DATA_H << 8) | TCS_CLEAR_BACK.DATA_L;
			if(TCS_DATA[SECTION_BACK] >= Tracer_Upper_Threshold)
			{
				Tracer_Stat[SECTION_BACK] = COLOUR_WHITE;
			}
			else if(TCS_DATA[SECTION_BACK] > Tracer_Lower_Threshold && TCS_DATA[SECTION_BACK] < Tracer_Upper_Threshold)
			{
				Tracer_Stat[SECTION_BACK] = COLOUR_GRAY;
			}
			else
			{
				Tracer_Stat[SECTION_BACK] = COLOUR_BLACK;
			}
		}break;
	}


}

void TCS_Get_RGB(int section)
{
	switch(section)
	{
		case SECTION_FRONT:
		{
			ERROR_DATA = TCS34725_Read_data(I2C1,TCS34725_READ_REDDATA_L);
			TCS_RED_FRONT.DATA_L = data_byte;


			ERROR_DATA = TCS34725_Read_data(I2C1,TCS34725_READ_REDDATA_H);
			TCS_RED_FRONT.DATA_H = data_byte;


			ERROR_DATA = TCS34725_Read_data(I2C1,TCS34725_READ_GREENDATA_L);
			TCS_GREEN_FRONT.DATA_L = data_byte;


			ERROR_DATA = TCS34725_Read_data(I2C1,TCS34725_READ_GREENDATA_H);
			TCS_GREEN_FRONT.DATA_H = data_byte;


			ERROR_DATA = TCS34725_Read_data(I2C1,TCS34725_READ_BLUEDATA_L);
			TCS_BLUE_FRONT.DATA_L = data_byte;


			ERROR_DATA = TCS34725_Read_data(I2C1,TCS34725_READ_BLUEDATA_H);
			TCS_BLUE_FRONT.DATA_H = data_byte;

			TCS_F.RedData   = (TCS_RED_FRONT.DATA_H << 8) | TCS_RED_FRONT.DATA_L;
			TCS_F.GreenData = (TCS_GREEN_FRONT.DATA_H << 8) | TCS_GREEN_FRONT.DATA_L;
			TCS_F.BlueData  = (TCS_BLUE_FRONT.DATA_H << 8) | TCS_BLUE_FRONT.DATA_L;

			if(((TCS_F.GreenData >= RGB_Threshold_front_up) && (TCS_F.BlueData >= RGB_Threshold_front_up) )/*|| (TCS_F.RedData >= R_White_Threshold)*/)
			{
				Tracer_Stat[SECTION_FRONT] = COLOUR_WHITE;
			}
			else if(((TCS_F.GreenData <  RGB_Threshold_front_up) && (TCS_F.GreenData >  RGB_Threshold_front_low))
																	&&
					((TCS_F.BlueData <  RGB_Threshold_front_up) && (TCS_F.BlueData >  RGB_Threshold_front_low))
					)
			{
				Tracer_Stat[SECTION_FRONT] = COLOUR_GRAY;
			}
			else if((TCS_F.GreenData <= RGB_Threshold_front_low) && (TCS_F.BlueData <= RGB_Threshold_front_low))
			{
				Tracer_Stat[SECTION_FRONT] = COLOUR_BLACK;
			}
			else
			{
				Tracer_Stat[SECTION_FRONT] = COLOUR_BLACK;
			}
		}break;

		case SECTION_BACK:
		{
			ERROR_DATA = TCS34725_Read_data(I2C2,TCS34725_READ_REDDATA_L);
			TCS_RED_BACK.DATA_L = data_byte;


			ERROR_DATA = TCS34725_Read_data(I2C2,TCS34725_READ_REDDATA_H);
			TCS_RED_BACK.DATA_H = data_byte;


			ERROR_DATA = TCS34725_Read_data(I2C2,TCS34725_READ_GREENDATA_L);
			TCS_GREEN_BACK.DATA_L = data_byte;


			ERROR_DATA = TCS34725_Read_data(I2C2,TCS34725_READ_GREENDATA_H);
			TCS_GREEN_BACK.DATA_H = data_byte;


			ERROR_DATA = TCS34725_Read_data(I2C2,TCS34725_READ_BLUEDATA_L);
			TCS_BLUE_BACK.DATA_L = data_byte;


			ERROR_DATA = TCS34725_Read_data(I2C2,TCS34725_READ_BLUEDATA_H);
			TCS_BLUE_BACK.DATA_H = data_byte;

			TCS_B.RedData   = (TCS_RED_BACK.DATA_H << 8) | TCS_RED_BACK.DATA_L;
			TCS_B.GreenData = (TCS_GREEN_BACK.DATA_H << 8) | TCS_GREEN_BACK.DATA_L;
			TCS_B.BlueData  = (TCS_BLUE_BACK.DATA_H << 8) | TCS_BLUE_BACK.DATA_L;

			if(((TCS_B.GreenData >= RGB_Threshold_back_up) && (TCS_B.BlueData >= RGB_Threshold_back_up)) /*|| (TCS_B.RedData >= R_White_Threshold)*/)
			{
				Tracer_Stat[SECTION_BACK] = COLOUR_WHITE;
			}
			else if(((TCS_B.GreenData <  RGB_Threshold_back_up) && (TCS_B.GreenData >  RGB_Threshold_back_low))
																	&&
					((TCS_B.BlueData <  RGB_Threshold_back_up) && (TCS_B.BlueData >  RGB_Threshold_back_low))
					)
			{
				Tracer_Stat[SECTION_BACK] = COLOUR_GRAY;
			}
			else if((TCS_B.GreenData <= RGB_Threshold_back_low) && (TCS_B.BlueData <= RGB_Threshold_back_low))
			{
				Tracer_Stat[SECTION_BACK] = COLOUR_BLACK;
			}
			else
			{
				Tracer_Stat[SECTION_BACK] = COLOUR_BLACK;
			}

		}break;
	}
}

void TCS_Config(void)
{
	ERROR_WRITE1 = TCS34725_Write_Data(I2C2,TCS34725_WRITE_CONTROL,SET_GAIN_1);
	DelayMs(5);
	ERROR_WRITE2 = TCS34725_Write_Data(I2C2,TCS34725_WRITE_RGBC,RGBC_MIN_RESOLUTION);
	DelayMs(5);
	ERROR_WRITE3 = TCS34725_Write_Data(I2C2,TCS34725_WRITE_ENABLE,TRACER_START);
	DelayMs(5);
}

void TCS_Get_RAW(int section)
{
	switch(section)
	{
		case SECTION_FRONT:
		{
			if(TCS_DATA[SECTION_FRONT] >= Tracer_Upper_Threshold)
			{
				Tracer_Stat[SECTION_FRONT] = COLOUR_WHITE;
			}
			else if(TCS_DATA[SECTION_FRONT] > Tracer_Lower_Threshold && TCS_DATA[SECTION_FRONT] < Tracer_Upper_Threshold)
			{
				Tracer_Stat[SECTION_FRONT] = COLOUR_GRAY;
			}
			else
			{
				Tracer_Stat[SECTION_FRONT] = COLOUR_BLACK;
			}
		}break;

		case SECTION_BACK:
		{
			if(TCS_DATA[SECTION_BACK] >= Tracer_Upper_Threshold)
			{
				Tracer_Stat[SECTION_BACK] = COLOUR_WHITE;
			}
			else if(TCS_DATA[SECTION_BACK] > Tracer_Lower_Threshold && TCS_DATA[SECTION_BACK] < Tracer_Upper_Threshold)
			{
				Tracer_Stat[SECTION_BACK] = COLOUR_GRAY;
			}
			else
			{
				Tracer_Stat[SECTION_BACK] = COLOUR_BLACK;
			}
		}break;
	}
}

void TCS_Get_Colour()
{
	if(Tracer_Stat[SECTION_FRONT] == COLOUR_WHITE || Tracer_Stat[SECTION_BACK] == COLOUR_WHITE)
	{
		Tracer_Stat[FINAL] = COLOUR_WHITE;
	}
	else if(Tracer_Stat[SECTION_FRONT] == COLOUR_GRAY || Tracer_Stat[SECTION_BACK] == COLOUR_GRAY)
	{
		Tracer_Stat[FINAL] = COLOUR_GRAY;
	}
	else if(Tracer_Stat[SECTION_FRONT] == COLOUR_BLACK || Tracer_Stat[SECTION_BACK] == COLOUR_BLACK)
	{
		Tracer_Stat[FINAL] = COLOUR_BLACK;
	}
	else
	{
		Tracer_Stat[FINAL] = COLOUR_BLACK;
	}
}

void TCS_Get_Rule(int mode)
{
	switch(mode)
	{
		case TCS34725_GET_CLEAR:
		{
			TCS_GetRealData(SECTION_FRONT);
			TCS_GetRealData(SECTION_BACK);
			TCS_Get_Colour();
		}break;

		case TCS34725_GET_RGB:
		{
			TCS_Get_RGB(SECTION_FRONT);
			TCS_Get_RGB(SECTION_BACK);
			TCS_Get_Colour();
		}break;

	}
}

void IWDG_Reset_Init()
{
	RCC_LSICmd(ENABLE);
	/* Wait till LSI is ready */
	while (RCC_GetFlagStatus(RCC_FLAG_LSIRDY) == RESET)
	{}

	/* Enable Watchdog*/
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	IWDG_SetPrescaler(IWDG_Prescaler_4); // 4, 8, 16 ... 256
	IWDG_SetReload(0x0000);//This parameter must be a number between 0 and 0x0FFF.
	IWDG_ReloadCounter();
	IWDG_Enable();
}
