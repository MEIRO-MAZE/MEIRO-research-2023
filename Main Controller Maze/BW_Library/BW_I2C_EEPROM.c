#include "BW_I2C_EEPROM.h"

void BW_I2C_EEPROM_Init(void)
{
		/*  GPIO Setup  */
	    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	    // dulu B8 B9
	    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
	    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	    GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
	    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	    GPIO_Init(GPIOB, &GPIO_InitStructure);

	    //I2C_DeInit(I2C1);
	    /*  I2C Setup  */
	    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C2, ENABLE);
	    I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
	    I2C_InitStructure.I2C_ClockSpeed = 50000; //100kHz
	//    I2C_InitStructure.I2C_ClockSpeed = 400000; //400kHz
	    I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
	    I2C_InitStructure.I2C_OwnAddress1 = 0x00;
	    I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
	    I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;

	    I2C_Cmd(I2C2, ENABLE);
	    I2C_Init(I2C2, &I2C_InitStructure);

	    /* Connect PXx to I2C_SCL*/
	    GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_I2C2);

	    /* Connect PXx to I2C_SDA*/
	    GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_I2C2);
}

int16_t BW_Read_I2C2(uint8_t ADDRESS, uint8_t REGISTER, uint8_t eeaddress)
{
	  int16_t RetVal=0;
	  uint32_t TimeOut=I2C2_TIMEOUT;

	  //Start Sequences
	  I2C_GenerateSTART(I2C2, ENABLE);

	  TimeOut=I2C2_TIMEOUT;
	  while(!I2C_GetFlagStatus(I2C2, I2C_FLAG_SB))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C2_TimeOut(1));
	  }

	  // Slave Address Send (write)
	  I2C_Send7bitAddress(I2C2,(ADDRESS << 1),I2C_Direction_Transmitter);

	  TimeOut=I2C2_TIMEOUT;
	  while(!I2C_GetFlagStatus(I2C2, I2C_FLAG_ADDR))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C2_TimeOut(2));
	  }

	  // Clear ADDR Flag
	  I2C2->SR2;

	  TimeOut=I2C2_TIMEOUT;
	  while(!I2C_GetFlagStatus(I2C2, I2C_FLAG_TXE))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C2_TimeOut(3));
	  }

	  I2C_SendData(I2C2, (int)(eeaddress >> 8));

	  TimeOut=I2C2_TIMEOUT;

	  while ((!I2C_GetFlagStatus(I2C2, I2C_FLAG_TXE)) || (!I2C_GetFlagStatus(I2C2, I2C_FLAG_BTF)))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C2_TimeOut(5));
	  }

	  I2C_SendData(I2C2, (int)(eeaddress & 0xFF));

	  TimeOut=I2C2_TIMEOUT;

	  while ((!I2C_GetFlagStatus(I2C2, I2C_FLAG_TXE)) || (!I2C_GetFlagStatus(I2C2, I2C_FLAG_BTF)))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C2_TimeOut(5));
	  }

			I2C_GenerateSTOP(I2C2, ENABLE);

		I2C_GenerateSTART(I2C2, ENABLE);

		TimeOut = I2C2_TIMEOUT;
		while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT))
		{
			  if(TimeOut!=0) TimeOut--;
			  else return (I2C2_TimeOut(5));
		}

		I2C_Send7bitAddress(I2C2,(ADDRESS<<1)|0x01,I2C_Direction_Receiver);

		TimeOut = I2C2_TIMEOUT;
		while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED))
		{
			  if(TimeOut!=0) TimeOut--;
			  else return (I2C2_TimeOut(1));
		}

		I2C_AcknowledgeConfig(I2C2, DISABLE);
		I2C_GenerateSTOP(I2C2, ENABLE);

		TimeOut = I2C2_TIMEOUT;
		while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_RECEIVED))
		{
			  if(TimeOut!=0) TimeOut--;
			  else return (I2C2_TimeOut(1));
		}

		DATA=I2C_ReceiveData(I2C2);
		I2C_AcknowledgeConfig(I2C2, ENABLE);

		return 0;
}

int16_t BW_Write_I2C_EEPROM(uint8_t ADDRESS, uint8_t VALUE, uint8_t eeaddress)
{
	  int16_t RetVal=0;
	  uint32_t TimeOut=I2C2_TIMEOUT;

	  //Start Sequences
	  I2C_GenerateSTART(I2C2, ENABLE);

	  TimeOut=I2C2_TIMEOUT;
	  while(!I2C_GetFlagStatus(I2C2, I2C_FLAG_SB))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C2_TimeOut(-1));
	  }

	  // Slave Address Send (write)
	  I2C_Send7bitAddress(I2C2,(ADDRESS << 1),I2C_Direction_Transmitter);

	  TimeOut=I2C2_TIMEOUT;
	  while(!I2C_GetFlagStatus(I2C2, I2C_FLAG_ADDR))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C2_TimeOut(-2));
	  }

	  // Clear ADDR Flag
	  I2C2->SR2;

	  TimeOut=I2C2_TIMEOUT;
	  while(!I2C_GetFlagStatus(I2C2, I2C_FLAG_TXE))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C2_TimeOut(-3));
	  }

	  I2C_SendData(I2C2, (int)(eeaddress >> 8));

	  TimeOut=I2C2_TIMEOUT;

	  while ((!I2C_GetFlagStatus(I2C2, I2C_FLAG_TXE)) || (!I2C_GetFlagStatus(I2C2, I2C_FLAG_BTF)))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C2_TimeOut(-5));
	  }

	  I2C_SendData(I2C2, (int)(eeaddress & 0xFF));

	  TimeOut=I2C2_TIMEOUT;

	  while ((!I2C_GetFlagStatus(I2C2, I2C_FLAG_TXE)) || (!I2C_GetFlagStatus(I2C2, I2C_FLAG_BTF)))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C2_TimeOut(-5));
	  }

	  //Send Data
	  I2C_SendData(I2C2, VALUE);

	  TimeOut=I2C2_TIMEOUT;

	  while ((!I2C_GetFlagStatus(I2C2, I2C_FLAG_TXE)) || (!I2C_GetFlagStatus(I2C2, I2C_FLAG_BTF)))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C2_TimeOut(-5));
	  }

	  // Stop Sequences
	  I2C_GenerateSTOP(I2C2, ENABLE);

	  // Everything's... Alright~ ;) *I hope
	  RetVal=0;

	  return (RetVal);
}


void Save_CMPS12_DATA(void)
{
	while(BW_BUTTON_CLICKED);
	delay_ms(500);
	while(1)
	{
		GetCMPS11_Angle8Bit();
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"R4A TENGAH");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"Angle : %d", CMPS11_Angle);lcd_putstr(lcd);
		delay_ms(200);
		if(BW_BUTTON_CLICKED)break;
	}
	BW_Write_I2C_EEPROM(0x50,(char)(CMPS11_Angle >> 8),1);
	delay_ms(100);
	BW_Write_I2C_EEPROM(0x50,(char)CMPS11_Angle,2);
	delay_ms(100);
	while(BW_BUTTON_CLICKED);

	while(1)
	{
		GetCMPS11_Angle8Bit();
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"R4A SERONG KANAN");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"Angle : %d", CMPS11_Angle);lcd_putstr(lcd);
		delay_ms(200);
		if(BW_BUTTON_CLICKED)break;
	}
	BW_Write_I2C_EEPROM(0x50,(char)(CMPS11_Angle >> 8),3);
	delay_ms(100);
	BW_Write_I2C_EEPROM(0x50,(char)CMPS11_Angle,4);
	delay_ms(100);
	while(BW_BUTTON_CLICKED);

	while(1)
	{
		GetCMPS11_Angle8Bit();
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"R4A SERONG KIRI");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"Angle : %d", CMPS11_Angle);lcd_putstr(lcd);
		delay_ms(200);
		if(BW_BUTTON_CLICKED)break;
	}
	BW_Write_I2C_EEPROM(0x50,(char)(CMPS11_Angle >> 8),5);
	delay_ms(100);
	BW_Write_I2C_EEPROM(0x50,(char)CMPS11_Angle,6);
	delay_ms(100);
	while(BW_BUTTON_CLICKED);

	while(1)
	{
		GetCMPS11_Angle8Bit();
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"R4A KANAN");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"Angle : %d", CMPS11_Angle);lcd_putstr(lcd);
		delay_ms(200);
		if(BW_BUTTON_CLICKED)break;
	}
	BW_Write_I2C_EEPROM(0x50,(char)(CMPS11_Angle >> 8),7);
	delay_ms(100);
	BW_Write_I2C_EEPROM(0x50,(char)CMPS11_Angle,8);
	delay_ms(100);
	while(BW_BUTTON_CLICKED);

	while(1)
	{
		GetCMPS11_Angle8Bit();
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"R4A KIRI");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"Angle : %d", CMPS11_Angle);lcd_putstr(lcd);
		delay_ms(200);
		if(BW_BUTTON_CLICKED)break;
	}
	BW_Write_I2C_EEPROM(0x50,(char)(CMPS11_Angle >> 8),9);
	delay_ms(100);
	BW_Write_I2C_EEPROM(0x50,(char)CMPS11_Angle,10);
	delay_ms(100);
	while(BW_BUTTON_CLICKED);

	while(1)
	{
		GetCMPS11_Angle8Bit();
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"R4B SERONG KANAN");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"Angle : %d", CMPS11_Angle);lcd_putstr(lcd);
		delay_ms(200);
		if(BW_BUTTON_CLICKED)break;
	}
	BW_Write_I2C_EEPROM(0x50,(char)(CMPS11_Angle >> 8),11);
	delay_ms(100);
	BW_Write_I2C_EEPROM(0x50,(char)CMPS11_Angle,12);
	delay_ms(100);
	while(BW_BUTTON_CLICKED);

	while(1)
	{
		GetCMPS11_Angle8Bit();
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"R4B SERONG KIRI");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"Angle : %d", CMPS11_Angle);lcd_putstr(lcd);
		delay_ms(200);
		if(BW_BUTTON_CLICKED)break;
	}
	BW_Write_I2C_EEPROM(0x50,(char)(CMPS11_Angle >> 8),13);
	delay_ms(100);
	BW_Write_I2C_EEPROM(0x50,(char)CMPS11_Angle,14);
	delay_ms(100);
	while(BW_BUTTON_CLICKED);

	while(1)
	{
		GetCMPS11_Angle8Bit();
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"R4B TENGAH");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"Angle : %d", CMPS11_Angle);lcd_putstr(lcd);
		delay_ms(200);
		if(BW_BUTTON_CLICKED)break;
	}
	BW_Write_I2C_EEPROM(0x50,(char)(CMPS11_Angle >> 8),15);
	delay_ms(100);
	BW_Write_I2C_EEPROM(0x50,(char)CMPS11_Angle,16);
	delay_ms(100);
	while(BW_BUTTON_CLICKED);

	while(1)
	{
		GetCMPS11_Angle8Bit();
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"START MID");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"Angle : %d", CMPS11_Angle);lcd_putstr(lcd);
		delay_ms(200);
		if(BW_BUTTON_CLICKED)break;
	}
	BW_Write_I2C_EEPROM(0x50,(char)(CMPS11_Angle >> 8),17);
	delay_ms(100);
	BW_Write_I2C_EEPROM(0x50,(char)CMPS11_Angle,18);
	delay_ms(100);
	while(BW_BUTTON_CLICKED);

	while(1)
	{
		GetCMPS11_Angle8Bit();
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"R1BC");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"Angle : %d", CMPS11_Angle);lcd_putstr(lcd);
		delay_ms(200);
		if(BW_BUTTON_CLICKED)break;
	}
	BW_Write_I2C_EEPROM(0x50,(char)(CMPS11_Angle >> 8),19);
	delay_ms(100);
	BW_Write_I2C_EEPROM(0x50,(char)CMPS11_Angle,20);
	delay_ms(100);
	while(BW_BUTTON_CLICKED);
	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"DATA SAVED !");lcd_putstr(lcd);
	delay_ms(500);
}

void CAT_CALIBRATION(void)
{
	while(1)
	{
	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"CAT : %d",SHARP[SHARP_FRONT_L]);lcd_putstr(lcd);
	if(BW_BUTTON_CLICKED)
	{
		while(BW_BUTTON_CLICKED);
		BW_Write_I2C_EEPROM(0x50,SHARP[SHARP_FRONT_L],PAGE_CAT_MIN_RANGE);
		delay_ms(100);
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"SAVED");lcd_putstr(lcd);
		delay_ms(200);
		break;
	}
	delay_ms(100);
	}
}

int16_t Load_CMPS_DATA(void)
{
	int data_buf,stat;
//	lcd_display_clear();
//	lcd_gotoxy(0,0);sprintf(lcd,"LOADING DATA");lcd_putstr(lcd);

	stat = BW_Read_I2C2(ADDRESS_EEPROM,1,PAGE_R4A_TENGAH_H);
	data_buf = (DATA << 8);
	BW_Read_I2C2(ADDRESS_EEPROM,1,PAGE_R4A_TENGAH_L);
	data_buf = data_buf | DATA;
	R4A_THRESHOLD_MIDDLE = data_buf;
	delay_ms(100);

	BW_Read_I2C2(ADDRESS_EEPROM,1,PAGE_R4A_SERONG_KANAN_H);
	data_buf = (DATA << 8);
	BW_Read_I2C2(ADDRESS_EEPROM,1,PAGE_R4A_SERONG_KANAN_L);
	data_buf = data_buf | DATA;
	R4A_THRESHOLD_LOWER = data_buf;
	delay_ms(100);

	BW_Read_I2C2(ADDRESS_EEPROM,1,PAGE_R4A_SERONG_KIRI_H);
	data_buf = (DATA << 8);
	BW_Read_I2C2(ADDRESS_EEPROM,1,PAGE_R4A_SERONG_KIRI_L);
	data_buf = data_buf | DATA;
	R4A_THRESHOLD_UPPER = data_buf;
	delay_ms(100);

	BW_Read_I2C2(ADDRESS_EEPROM,1,PAGE_R4B_SERONG_KANAN_H);
	data_buf = (DATA << 8);
	BW_Read_I2C2(ADDRESS_EEPROM,1,PAGE_R4B_SERONG_KANAN_L);
	data_buf = data_buf | DATA;
	R4B_THRESHOLD_UPPER = data_buf;
	delay_ms(100);

	BW_Read_I2C2(ADDRESS_EEPROM,1,PAGE_R4B_SERONG_KIRI_H);
	data_buf = (DATA << 8);
	BW_Read_I2C2(ADDRESS_EEPROM,1,PAGE_R4B_SERONG_KIRI_L);
	data_buf = data_buf | DATA;
	R4B_THRESHOLD_LOWER = data_buf;
	delay_ms(100);

	BW_Read_I2C2(ADDRESS_EEPROM,1,PAGE_R4B_TENGAH_H);
	data_buf = (DATA << 8);
	BW_Read_I2C2(ADDRESS_EEPROM,1,PAGE_R4B_TENGAH_L);
	data_buf = data_buf | DATA;
	R4B_THRESHOLD_MIDDLE = data_buf;
	delay_ms(100);

	BW_Read_I2C2(ADDRESS_EEPROM,1,PAGE_R4A_KANAN_H);
	data_buf = (DATA << 8);
	BW_Read_I2C2(ADDRESS_EEPROM,1,PAGE_R4A_KANAN_L);
	data_buf = data_buf | DATA;
	R4AB_THRESHOLD_LOWER = data_buf;
	delay_ms(100);

	BW_Read_I2C2(ADDRESS_EEPROM,1,PAGE_R4A_KIRI_H);
	data_buf = (DATA << 8);
	BW_Read_I2C2(ADDRESS_EEPROM,1,PAGE_R4A_KIRI_L);
	data_buf = data_buf | DATA;
	R4AB_THRESHOLD_UPPER = data_buf;
	delay_ms(100);

	BW_Read_I2C2(ADDRESS_EEPROM,1,PAGE_START_MID_H);
	data_buf = (DATA << 8);
	BW_Read_I2C2(ADDRESS_EEPROM,1,PAGE_START_MID_L);
	data_buf = data_buf | DATA;
	START_MIDDLE = data_buf;
	delay_ms(100);

	BW_Read_I2C2(ADDRESS_EEPROM,1,PAGE_R1BC_H);
	data_buf = (DATA << 8);
	BW_Read_I2C2(ADDRESS_EEPROM,1,PAGE_R1BC_L);
	data_buf = data_buf | DATA;
	R1BC_THRESHOLD_MIDDLE = data_buf;
	delay_ms(100);

//	lcd_display_clear();
//	lcd_gotoxy(0,0);sprintf(lcd,"LOAD COMPLETE");lcd_putstr(lcd);
//	delay_ms(500);
	return stat;
}

void Load_CAT_MIN_DATA(void)
{
	BW_Read_I2C2(ADDRESS_EEPROM,1,PAGE_CAT_MIN_RANGE);
	CAT_MIN_RANGE = (DATA);
	delay_ms(100);
}

void display_EEPROM_DATA(void)
{
	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"R4A_MID:%d", R4A_THRESHOLD_MIDDLE);lcd_putstr(lcd);

	lcd_gotoxy(0,1);sprintf(lcd,"R4B_MID : %d", R4B_THRESHOLD_MIDDLE);lcd_putstr(lcd);

	lcd_gotoxy(0,2);sprintf(lcd,"R4AB_L : %d", R4AB_THRESHOLD_UPPER);lcd_putstr(lcd);

	lcd_gotoxy(0,3);sprintf(lcd,"R4AB_R : %d", R4AB_THRESHOLD_LOWER);lcd_putstr(lcd);
	delay_ms(200);

	if(BW_BUTTON_CLICKED)
	{
		while(BW_BUTTON_CLICKED)
		while(1)
		{
			lcd_display_clear();
			lcd_gotoxy(0,0);sprintf(lcd,"R4A_UP : %d", R4A_THRESHOLD_UPPER);lcd_putstr(lcd);

			lcd_gotoxy(0,1);sprintf(lcd,"R4B_UP : %d", R4B_THRESHOLD_UPPER);lcd_putstr(lcd);

			lcd_gotoxy(0,2);sprintf(lcd,"R4A_LO : %d", R4A_THRESHOLD_LOWER);lcd_putstr(lcd);

			lcd_gotoxy(0,3);sprintf(lcd,"R4B_LO : %d", R4B_THRESHOLD_LOWER);lcd_putstr(lcd);
			delay_ms(200);
			if(BW_BUTTON_CLICKED)
			{
				while(BW_BUTTON_CLICKED)
				while(1)
				{
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"R1BC : %d", R1BC_THRESHOLD_MIDDLE);lcd_putstr(lcd);

					lcd_gotoxy(0,1);sprintf(lcd,"CAT RANGE : %d", CAT_MIN_RANGE);lcd_putstr(lcd);
					delay_ms(100);
					if(BW_BUTTON_CLICKED)
					{
						while(BW_BUTTON_CLICKED)
							break;
					}
				}
			}
		}
	}
}

void copy_EEPROM_data(void)
{
	BW_Write_I2C_EEPROM(0x50,(char)(R4A_THRESHOLD_MIDDLE >> 8),1);
	delay_ms(100);
	BW_Write_I2C_EEPROM(0x50,(char)R4A_THRESHOLD_MIDDLE,2);
	delay_ms(100);

	BW_Write_I2C_EEPROM(0x50,(char)(R4A_THRESHOLD_LOWER >> 8),3);
	delay_ms(100);
	BW_Write_I2C_EEPROM(0x50,(char)R4A_THRESHOLD_LOWER,4);
	delay_ms(100);

	BW_Write_I2C_EEPROM(0x50,(char)(R4A_THRESHOLD_UPPER >> 8),5);
	delay_ms(100);
	BW_Write_I2C_EEPROM(0x50,(char)R4A_THRESHOLD_UPPER,6);
	delay_ms(100);

	BW_Write_I2C_EEPROM(0x50,(char)(R4AB_THRESHOLD_LOWER >> 8),7);
	delay_ms(100);
	BW_Write_I2C_EEPROM(0x50,(char)R4AB_THRESHOLD_LOWER,8);
	delay_ms(100);

	BW_Write_I2C_EEPROM(0x50,(char)(R4AB_THRESHOLD_UPPER >> 8),9);
	delay_ms(100);
	BW_Write_I2C_EEPROM(0x50,(char)R4AB_THRESHOLD_UPPER,10);
	delay_ms(100);

	BW_Write_I2C_EEPROM(0x50,(char)(R4B_THRESHOLD_UPPER >> 8),11);
	delay_ms(100);
	BW_Write_I2C_EEPROM(0x50,(char)R4B_THRESHOLD_UPPER,12);
	delay_ms(100);

	BW_Write_I2C_EEPROM(0x50,(char)(R4B_THRESHOLD_LOWER >> 8),13);
	delay_ms(100);
	BW_Write_I2C_EEPROM(0x50,(char)R4B_THRESHOLD_LOWER,14);
	delay_ms(100);

	BW_Write_I2C_EEPROM(0x50,(char)(R4B_THRESHOLD_MIDDLE >> 8),15);
	delay_ms(100);
	BW_Write_I2C_EEPROM(0x50,(char)R4B_THRESHOLD_MIDDLE,16);
	delay_ms(100);

	BW_Write_I2C_EEPROM(0x50,(char)(START_MIDDLE >> 8),17);
	delay_ms(100);
	BW_Write_I2C_EEPROM(0x50,(char)START_MIDDLE,18);
	delay_ms(100);

	BW_Write_I2C_EEPROM(0x50,(char)(R1BC_THRESHOLD_MIDDLE >> 8),19);
	delay_ms(100);
	BW_Write_I2C_EEPROM(0x50,(char)R1BC_THRESHOLD_MIDDLE,20);
	delay_ms(100);

	BW_Write_I2C_EEPROM(0x50,CAT_MIN_RANGE,PAGE_CAT_MIN_RANGE);

	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"COPY DONE");lcd_putstr(lcd);
	delay_ms(500);
}

void BW_COPY_TRACER_DATA(void)
{
	TCS3200_Transmit(UART5, HYBRID_CMD_SEND_THRESHOLD);
	BW_Write_I2C_EEPROM(0x50,(char)TCS3200_SLV_DATA[5],PAGE_TRACER_RULE_UP);
	BW_Write_I2C_EEPROM(0x50,(char)TCS3200_SLV_DATA[6],PAGE_TRACER_RULE_DOWN);
	delay_ms(500);
	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"COPY DONE");lcd_putstr(lcd);
}

int16_t I2C2_TimeOut(int16_t VALUE)
{
	int16_t RetVal= VALUE;

//	Stop and reset
	I2C_GenerateSTOP(I2C2,ENABLE);
	I2C_SoftwareResetCmd(I2C2,ENABLE);
	I2C_SoftwareResetCmd(I2C2, DISABLE);

	// I2C De-Init
	I2C_DeInit(I2C2);

//	I2C Re-Init
//	BW_TPA81_I2C_Init();

    return(RetVal);
}
