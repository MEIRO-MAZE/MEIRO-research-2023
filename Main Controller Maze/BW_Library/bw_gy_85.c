/*==============================================================================================
								 	 PROJECT BW Ver.1.0
								  	 BW GY-85 IMU LIBRARY
==============================================================================================*/

#include "bw_gy_85.h"

void GY_85_I2C_Init (void);
void BW_GY_85_Init (void)
{
	GY_85_I2C_Init();
//	ADXL345_Init();
}
void GY_85_I2C_Init (void)
{
    //GY-85 I2C INIT
	/*  GPIO Setup  */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    /*  I2C Setup  */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C2, ENABLE);
    I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
    I2C_InitStructure.I2C_ClockSpeed = 400000; //400kHz
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

void Write_I2C2(int Address, int Register, int Data)
{
	if((MPU_ACTIVE_MODE&&1)==1)
	{
		while (I2C_GetFlagStatus(I2C2, I2C_FLAG_BUSY))
		{
			;
		}

		I2C_GenerateSTART(I2C2, ENABLE);

		while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT))
		{
			;
		}
		I2C_Send7bitAddress(I2C2,Address<<1,I2C_Direction_Transmitter);

		while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
		{
			;
		}

		I2C_SendData(I2C2,Register);

		while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
		{
			;
		}

		I2C_SendData(I2C2,Data);
		while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
		{
			;
		}

		I2C_GenerateSTOP(I2C2, ENABLE);
	}
}


void Read_I2C2(int Address, int Register)
{
	if((MPU_ACTIVE_MODE&&1)==1)
	{
		while (I2C_GetFlagStatus(I2C2, I2C_FLAG_BUSY))
		{
			;
		}

		I2C_GenerateSTART(I2C2, ENABLE);
		while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT))
		{
			;
		}

		I2C_Send7bitAddress(I2C2, Address<<1,I2C_Direction_Transmitter);

		while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
		{
			;
		}

		I2C_Cmd(I2C2, ENABLE);

		I2C_SendData(I2C2,Register);

		while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
		{
			;
		}

		I2C_GenerateSTART(I2C2, ENABLE);

		while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT))
		{
			;
		}

		I2C_Send7bitAddress(I2C2,Address<<1,I2C_Direction_Receiver);
		while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED))
		{
			;
		}

		I2C_AcknowledgeConfig(I2C2, DISABLE);
		I2C_GenerateSTOP(I2C2, ENABLE);

		while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_RECEIVED))
		{
			;
		}

		DATA=I2C_ReceiveData(I2C2);
		I2C_AcknowledgeConfig(I2C2, ENABLE);
	}
}

////--------------------------------------------------------------
//// Internal Function
//// Called when TIMEOUT occurs
//// STOP, RESET, and RE-INIT the I2C Interface
////--------------------------------------------------------------
//int16_t I2C2_TimeOut(int16_t VALUE)
//{
////  int16_t ret_wert=wert;
//	int16_t RetVal= VALUE;
//
////	I2C_GenerateSTOP(I2C1, ENABLE);
////	I2C_SoftwareResetCmd(I2C1, ENABLE);
////	I2C_SoftwareResetCmd(I2C1, DISABLE);
////	Stop and reset
//	I2C_GenerateSTOP(I2C2,ENABLE);
//	I2C_SoftwareResetCmd(I2C2,ENABLE);
//	I2C_SoftwareResetCmd(I2C1, DISABLE);
//
//	// I2C deinit
////	I2C_DeInit(I2C1);
//	I2C_DeInit(I2C2);
//
////	I2C Init
//
//	GY_85_I2C_Init ();
//
//    return(RetVal);
//}
//
////int16_t UB_I2C1_ReadMultiByte(uint8_t slave_adr, uint8_t adr, uint8_t cnt);
///*
// * ADDRESS  : I2C Slave Device Address
// * REGISTER : Start register address
// * BYTE     : Number of requested byte
// */
//int16_t ReadMultiByte_I2C2(uint8_t ADDRESS, uint8_t REGISTER, uint8_t BYTE)
//{
//	  int16_t RetVal=0;
//	  uint32_t TimeOut=I2C2_TIMEOUT;
//	  uint8_t Value,counter;
//
////	  if(cnt==0) return(-8);
////	  if(cnt>I2C1_MULTIBYTE_ANZ) return(-9);
//	  if(BYTE==0) return (-8);
//	  if(BYTE>I2C2_MULTIBYTE_MAX) return(-9);
//
//
////	  // Start-Sequenz
////	  I2C_GenerateSTART(I2C1, ENABLE);
//
////	  Start Sequences
//	  I2C_GenerateSTART(I2C2, ENABLE);
//
//
////	  timeout=I2C1_TIMEOUT;
//	  TimeOut= I2C2_TIMEOUT;
//
////	  while (!I2C_GetFlagStatus(I2C1, I2C_FLAG_SB)) {
////	    if(timeout!=0) timeout--; else return(P_I2C1_timeout(-1));
////	  }
//
//	  while(!I2C_GetFlagStatus(I2C2,I2C_FLAG_SB))
//	  {
//		  if(TimeOut!=0) TimeOut--;
//		  else return (I2C2_TimeOut(-1));
//	  }
//
////	  if(cnt==1) {
////	    // ACK disable
////	    I2C_AcknowledgeConfig(I2C1, DISABLE);
////	  }
//	  if(BYTE==1)
//	  {
////		  ACK Disable
//		  I2C_AcknowledgeConfig(I2C2, DISABLE);
//	  }
//
//
////	  else {
////		// ACK enable
////		I2C_AcknowledgeConfig(I2C1, ENABLE);
////	  }
//	  else
//	  {
//		// ACK enable
//		I2C_AcknowledgeConfig(I2C2, ENABLE);
//	  }
//
//	  // Slave-Adresse senden (write)
////	  I2C_Send7bitAddress(I2C1, slave_adr, I2C_Direction_Transmitter);
//	  I2C_Send7bitAddress(I2C2, ADDRESS, I2C_Direction_Transmitter);
//
////	  timeout=I2C1_TIMEOUT;
//	  TimeOut=I2C2_TIMEOUT;
//
//
////	  while (!I2C_GetFlagStatus(I2C1, I2C_FLAG_ADDR)) {
////	    if(timeout!=0) timeout--; else return(P_I2C1_timeout(-2));
////	  }
//	  while(!I2C_GetFlagStatus(I2C2, I2C_FLAG_ADDR))
//	  {
//		  if(TimeOut!=0) TimeOut--;
//		  else return (I2C2_TimeOut(-2));
//	  }
//
//	  // Clear ADDR Flag
//	  I2C2->SR2;
//
////	  timeout=I2C1_TIMEOUT;
//	  TimeOut=I2C2_TIMEOUT;
//
//
////	  while (!I2C_GetFlagStatus(I2C1, I2C_FLAG_TXE)) {
////	    if(timeout!=0) timeout--; else return(P_I2C1_timeout(-3));
////	  }
//	  while (!I2C_GetFlagStatus(I2C2, I2C_FLAG_TXE))
//	  {
//		  if(TimeOut!=0) TimeOut--;
//		  else return (I2C2_TimeOut(-3));
//	  }
//
//	  // Send REGISTER ADDRESS
//	  I2C_SendData(I2C2, REGISTER);
//
////	  timeout=I2C1_TIMEOUT;
////	  while ((!I2C_GetFlagStatus(I2C1, I2C_FLAG_TXE)) || (!I2C_GetFlagStatus(I2C1, I2C_FLAG_BTF))) {
////	    if(timeout!=0) timeout--; else return(P_I2C1_timeout(-4));
////	  }
//	  TimeOut=I2C2_TIMEOUT;
//	  while ((!I2C_GetFlagStatus(I2C2, I2C_FLAG_TXE)) || (!I2C_GetFlagStatus(I2C2, I2C_FLAG_BTF)))
//	  {
//		  if(TimeOut!=0) TimeOut--;
//		  else return (I2C2_TimeOut(-4));
//	  }
//
//	  // Start Sequence
//	  I2C_GenerateSTART(I2C2, ENABLE);
//
////	  timeout=I2C1_TIMEOUT;
////	  while (!I2C_GetFlagStatus(I2C1, I2C_FLAG_SB)) {
////	    if(timeout!=0) timeout--; else return(P_I2C1_timeout(-5));
////	  }
//	  TimeOut=I2C2_TIMEOUT;
//	  while (!I2C_GetFlagStatus(I2C2, I2C_FLAG_SB))
//	  {
//		  if(TimeOut!=0) TimeOut--;
//		  else return (I2C2_TimeOut(-5));
//	  }
//
//
//	  // Slave Address Send (read
//	  I2C_Send7bitAddress(I2C2, ADDRESS, I2C_Direction_Receiver);
//
////	  timeout=I2C1_TIMEOUT;
////	  while (!I2C_GetFlagStatus(I2C1, I2C_FLAG_ADDR)) {
////	    if(timeout!=0) timeout--; else return(P_I2C1_timeout(-6));
////	  }
//	  TimeOut=I2C2_TIMEOUT;
//	  while (!I2C_GetFlagStatus(I2C2, I2C_FLAG_ADDR))
//	  {
//		  if(TimeOut!=0) TimeOut--;
//		  else return (I2C2_TimeOut(-6));
//	  }
//
//
//	  // Clear ADDR Flag
//	  I2C2->SR2;
//
////	  // alle Daten auslesen
////	  for(n=0;n<cnt;n++) {
////
////	    if((n+1)>=cnt) {
////	      // ACK disable
////	      I2C_AcknowledgeConfig(I2C1, DISABLE);
////	      // Stop-Sequenz
////	      I2C_GenerateSTOP(I2C1, ENABLE);
////	    }
////
////	    timeout=I2C1_TIMEOUT;
////	    while (!I2C_GetFlagStatus(I2C1, I2C_FLAG_RXNE)) {
////	      if(timeout!=0) timeout--; else return(P_I2C1_timeout(-7));
////	    }
////
////	    // Daten auslesen
////	    wert=I2C_ReceiveData(I2C1);
////
////	    // Daten in Array speichern
////	    I2C1_DATA[n]=wert;
////	  }
//
////	  Read ALL DATA
//	  for(counter=0;counter<BYTE;counter++)
//	  {
//		  if( (counter+1)>=BYTE)
//		  {
//			  // Disable ACK
//			  I2C_AcknowledgeConfig(I2C2, DISABLE);
//
//			  // Stop Sequences
//			  I2C_GenerateSTOP(I2C2, ENABLE);
//		  }
//
//		  TimeOut=I2C2_TIMEOUT;
//
//		  while (!I2C_GetFlagStatus(I2C2, I2C_FLAG_RXNE))
//		  {
//			  if(TimeOut!=0) TimeOut--;
//			  else return (I2C2_TimeOut(-7));
//		  }
//
//		  // Read data
//		  Value=I2C_ReceiveData(I2C2);
//
//		  // Store received data in array
//		  I2C2_DATA[counter]=Value;
//	  }
//
//
//	  // ACK enable
//	  I2C_AcknowledgeConfig(I2C2, ENABLE);
//
//	  // Everything's... Alright~ ;) *I hope
//	  RetVal=0;
//
//	  return(RetVal);
//}


void ADXL345_Init(void)
{

//	int avg_counter;

	int DeviceID;

	Read_I2C2(ADXL345_DEVICE,ADXL345_REG_DEVID);

	DeviceID= DATA;
	if(DeviceID== 0xE5)
	{
		Sendto_PC(USART1,"ADXL345 Accelerometer Found. Calibration Initializing \r");
		Write_I2C2(ADXL345_DEVICE,ADXL345_POWER_CTL,0x08);
	}

	else
	{
		Sendto_PC(USART1,"WARNING, ADXL345 Accelerometer NOT FOUND! \r");
		Sendto_PC(USART1,"Device ID: %d \r",DeviceID);
		while(1)
		{

		}
	}

//	//Turning on the ADXL345
//	writeTo(ADXL345_POWER_CTL, 0);
//	writeTo(ADXL345_POWER_CTL, 16);
//	writeTo(ADXL345_POWER_CTL, 8);


//	Write_I2C2(ADXL345_DEVICE,ADXL345_POWER_CTL,0x0B);
//	Write_I2C2(ADXL345_DEVICE,ADXL345_POWER_CTL,0x09);

//	byte data = 0x08;
//	writeRegister(ADXL345::POWER_CTL, 1, &data);
//	Write_I2C2(ADXL345_DEVICE,ADXL345_POWER_CTL,0x00);
//	Write_I2C2(ADXL345_DEVICE,ADXL345_DATA_FORMAT,0x0B);
//	Write_I2C2(ADXL345_DEVICE,ADXL345_BW_RATE,0x09);

//	writeTo(ACC, 0x2D, 1<<3);
//	writeTo(ACC, 0x31, 0x0B);
//	writeTo(ACC, 0x2C, 0x09);
	//by default the device is in +-2g range reading

//	Write_I2C2(ADXL345_DEVICE,ADXL345_POWER_CTL,0x00);
//	Write_I2C2(ADXL345_DEVICE,ADXL345_DATA_FORMAT,0x0B);
//	Write_I2C2(ADXL345_DEVICE,ADXL345_BW_RATE,0x09);


	/*
	 * ADXL345 Accelerometer Calibration
	 */
//    for (avg_counter=0; avg_counter<=200; avg_counter++)
//    {
//    	ReadAccel_ADXL345();
//
//    	if(avg_counter==0)
//    	{
//    		AccelOffset_X= Accel_X;
//    		AccelOffset_Y= Accel_Y;
//    		AccelOffset_Z= Accel_Z;
//    	}
//
//    	if(avg_counter>=1)
//    	{
//    		AccelOffset_X= (Accel_X + AccelOffset_X) / 2;
//    		AccelOffset_Y= (Accel_Y + AccelOffset_Y) / 2;
//    		AccelOffset_Z= (Accel_Z + AccelOffset_Z) / 2;
//    	}
//
//    }

}

//for (count=0;count<=5;count++)
//{
//	//Read_I2C(shifted_address,regs);
//	if(count==0) Read_I2C2(0x68, MPU6050_ACCEL_XOUT_H); //Aslinya 0xD0, tapi hasilnya digeser satu bit ke kanan
//	else if(count==1)Read_I2C(0x68, MPU6050_ACCEL_XOUT_L);
//	else if(count==2)Read_I2C2(0x68, MPU6050_ACCEL_YOUT_H);
//	else if(count==3)Read_I2C(0x68, MPU6050_ACCEL_YOUT_L);
//	else if(count==4)Read_I2C2(0x68, MPU6050_ACCEL_ZOUT_H);
//	else if(count==5)Read_I2C(0x68, MPU6050_ACCEL_ZOUT_L);
//	data[count]=DATA;
//}
//acc.readAccel(&ax, &ay, &az);

//accel.setRange(ADXL345_RANGE_4_G);

void ADXL345_RangeConfig(range_t range)
{
	 uint8_t format;

	/* Red the data format register to preserve bits */
//	  uint8_t format = readRegister(ADXL345_REG_DATA_FORMAT);
	  Read_I2C2(ADXL345_ADDRESS,ADXL345_REG_DATA_FORMAT);
	  format= DATA;

	  Sendto_PC(USART1,"READ ADXL_REG_DATA_FORMAT: %d \r",(int)format);

	  /* Update the data rate */
	  format &= ~0x0F;
	  format |= range;

	  /* Make sure that the FULL-RES bit is enabled for range scaling */
	  format |= 0x08;

	  /* Write the register back to the IC */
//	  writeRegister(ADXL345_REG_DATA_FORMAT, format);
	  Write_I2C2(ADXL345_ADDRESS,ADXL345_REG_DATA_FORMAT,format);
//	  Sendto_PC(USART1,"WRITE ADXL_REG_DATA_FORMAT: %d \r",(int)format);


	  /* Keep track of the current range (to avoid readbacks) */
//	  _range = range;
}
void ADXL345_GetRange (void)
{
	int Range;
	Read_I2C2(ADXL345_ADDRESS,ADXL345_REG_DATA_FORMAT);
	Range = DATA;
	Range &= 0x03;
	Sendto_PC(USART1,"ADXL Range: %d \r",(int)Range);
}

void ADXL_DataRate_Config(dataRate_t dataRate)
{
//	 writeRegister(ADXL345_REG_BW_RATE, dataRate);
	 Write_I2C2(ADXL345_ADDRESS,ADXL345_REG_BW_RATE,dataRate);

}

void ReadAccel_ADXL345(void)
{
	int AccelCounter;


//	for(AccelCounter=0;AccelCounter<=5;AccelCounter++)
//	{
//		switch(AccelCounter)
//		{
//			case 0: { Read_I2C2(ADXL345_DEVICE, ADXL345_DATAX0);}
//			case 1: { Read_I2C2(ADXL345_DEVICE, ADXL345_DATAX1);}
//			case 2: { Read_I2C2(ADXL345_DEVICE, ADXL345_DATAY0);}
//			case 3: { Read_I2C2(ADXL345_DEVICE, ADXL345_DATAY1);}
//			case 4: { Read_I2C2(ADXL345_DEVICE, ADXL345_DATAZ0);}
//			case 5: { Read_I2C2(ADXL345_DEVICE, ADXL345_DATAZ1);}
//		}
//		AccelBuffer[AccelCounter]=DATA;
//	}
	I2C2_ReadMultiByte(ADXL345_DEVICE, ADXL345_DATAX0, 6);

	for(AccelCounter=0;AccelCounter<=5;AccelCounter++)
	{
		AccelBuffer[AccelCounter]=I2C2_DATA[AccelCounter];
	}

	//each axis reading comes in 10 bit resolution, ie 2 bytes.  Least Significat Byte first!!
	//thus we are converting both bytes in to one int
	Accel_X= (( (int)AccelBuffer[1])<< 8) | AccelBuffer[0];
	Accel_Y= (( (int)AccelBuffer[3])<< 8) | AccelBuffer[2];
	Accel_Z= (( (int)AccelBuffer[5])<< 8) | AccelBuffer[4];

	Sendto_PC(USART1,"Accel_X: %d \r",(int)Accel_X);
	Sendto_PC(USART1,"Accel_Y: %d \r",(int)Accel_Y);
	Sendto_PC(USART1,"Accel_Z: %d \r",(int)Accel_Z);

}


void GetOrientation (void)
{
	int rawX, rawY, rawZ;
	float X, Y, Z;

	ReadAccel_ADXL345();

	rawX = Accel_X - AccelOffset_X;
	rawY = Accel_Y - AccelOffset_Y;
	rawZ = Accel_Z - (255 - AccelOffset_Z);

	/*
	 * Used for angle calculations
	 */
	X = rawX/256.00;
	Y = rawY/256.00;
	Z = rawZ/256.00;

	/*
	 * Calculating angle in radians
	 */
	Accel_RollRad  = atan (Y / sqrt(X*X + Z*Z));
	Accel_PitchRad = atan (X / sqrt(Y*Y + Z*Z));

	/*
	 * Calculating angle in degrees
	 */

	Accel_RollDeg  = 180 * (atan ( Y / sqrt(X*X + Z*Z)))/PI;
	Accel_PitchDeg = 180 * (atan ( X / sqrt(Y*Y + Z*Z)))/PI;

	Sendto_PC(USART1,"Accel_RollDeg: %d \r",(int)Accel_RollDeg);
	Sendto_PC(USART1,"Accel_PitchDeg: %d \r",(int)Accel_PitchDeg);

}

//void ADXL345_LowPassFilter (void)
//{
//	/*
//	 * METHOD 2
//	 */
//	LPF_ACCEL_X= BW_MPU6050.Accelerometer_X * ALPHA + (LPF_ACCEL_X * (1.0 - ALPHA));
//	LPF_ACCEL_Y= BW_MPU6050.Accelerometer_Y * ALPHA + (LPF_ACCEL_Y * (1.0 - ALPHA));
//	LPF_ACCEL_Z= BW_MPU6050.Accelerometer_Z * ALPHA + (LPF_ACCEL_Z * (1.0 - ALPHA));
//
//	ROLL= (float) (atan2(-LPF_ACCEL_Y,LPF_ACCEL_Z)*180.0)/M_PI;
//	PITCH= (float) (atan2(-LPF_ACCEL_X, sqrt( (LPF_ACCEL_Y*LPF_ACCEL_Y)+(LPF_ACCEL_Z*LPF_ACCEL_Z)))*180)/M_PI;
//}

//void ADXL345::readFrom(byte address, int num, byte _buff[]) {
//	Wire.beginTransmission(ADXL345_DEVICE); // start transmission to device
//	Wire.write(address);             // sends address to read from
//	Wire.endTransmission();         // end transmission
//
//	Wire.beginTransmission(ADXL345_DEVICE); // start transmission to device
//	Wire.requestFrom(ADXL345_DEVICE, num);    // request 6 bytes from device
//
//	int i = 0;
//	while(Wire.available())         // device may send less than requested (abnormal)
//	{
//		_buff[i] = Wire.read();    // receive a byte
//		i++;
//	}
//	if(i != num){
//		status = ADXL345_ERROR;
//		error_code = ADXL345_READ_ERROR;
//	}
//	Wire.endTransmission();         // end transmission
//}

//void ADXL345::writeTo(byte address, byte val)
//{
//	Wire.beginTransmission(ADXL345_DEVICE); // start transmission to device
//	Wire.write(address);             // send register address
//	Wire.write(val);                 // send value to write
//	Wire.endTransmission();         // end transmission
//}
