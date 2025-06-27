/*==============================================================================================
								  PROJECT BW Ver.1.0
								  BW MPU6050 LIBRARY
==============================================================================================*/

#include "bw_mpu6050.h"


/*
 * MPU 6050 6 DOF Gyro Accelerometer
 */

char IMU_Stat[100];

//
void MPU6050_Address_Init(void)
{
	RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_ADDRESS, ENABLE);
	GPIO_InitStructure.GPIO_Pin = ADDRESS_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;       // Pin ini memiliki Mode Ouput
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 		// Pin bersifat Push Pull (Pull-up, down or no Pull)
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; 	// kecepatan clock(2, 25, 50 or 100 MHz)
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; 	// pin tidak diberikan pull up
	GPIO_Init(ADDRESS_PORT, &GPIO_InitStructure); 		// inisialisasi periperal GPIO sesuai parameter typdef diatas
}
//void Write_I2C2(int Address, int Register, int Data)
//{
//	if((MPU_ACTIVE_MODE&&1)==1)
//	{
//		while (I2C_GetFlagStatus(I2C2, I2C_FLAG_BUSY))
//		{
//			;
//		}
//
//		I2C_GenerateSTART(I2C2, ENABLE);
//
//		while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT))
//		{
//			;
//		}
//		I2C_Send7bitAddress(I2C2,Address<<1,I2C_Direction_Transmitter);
//
//		while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
//		{
//			;
//		}
//
//		I2C_SendData(I2C2,Register);
//
//		while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
//		{
//			;
//		}
//
//		I2C_SendData(I2C2,Data);
//		while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
//		{
//			;
//		}
//
//		I2C_GenerateSTOP(I2C2, ENABLE);
//	}
//}
//
//void Read_I2C2(int Address, int Register)
//{
//	if((MPU_ACTIVE_MODE&&1)==1)
//	{
//		while (I2C_GetFlagStatus(I2C2, I2C_FLAG_BUSY))
//		{
//			;
//		}
//
//		I2C_GenerateSTART(I2C2, ENABLE);
//		while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT))
//		{
//			;
//		}
//
//		I2C_Send7bitAddress(I2C2, Address<<1,I2C_Direction_Transmitter);
//
//		while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
//		{
//			;
//		}
//
//		I2C_Cmd(I2C2, ENABLE);
//
//		I2C_SendData(I2C2,Register);
//
//		while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
//		{
//			;
//		}
//
//		I2C_GenerateSTART(I2C2, ENABLE);
//
//		while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT))
//		{
//			;
//		}
//
//		I2C_Send7bitAddress(I2C2,Address<<1,I2C_Direction_Receiver);
//		while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED))
//		{
//			;
//		}
//
//		I2C_AcknowledgeConfig(I2C2, DISABLE);
//		I2C_GenerateSTOP(I2C2, ENABLE);
//
//		while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_RECEIVED))
//		{
//			;
//		}
//
//		DATA=I2C_ReceiveData(I2C2);
//		I2C_AcknowledgeConfig(I2C2, ENABLE);
//	}
//}

void MPU_6050_I2C_Init (void)
{
    //TPA 81
	/*  GPIO Setup  */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    //I2C_DeInit(I2C2);
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

void MPU_6050_Init(void)
{
		MPU6050_Address_Init();
		ADDRESS_D0;

		//Format I2C Address
		//BW_MPU6050.Address = MPU6050_I2C_ADDR | 1;

		BW_MPU6050.Address=0x68;

		//Setup I2C
//		Setup_I2C();
		MPU_6050_I2C_Init ();


		Write_I2C2(0x68, MPU6050_PWR_MGMT_1, 0x6B);

		Write_I2C2(0x68, MPU6050_PWR_MGMT_1, 0x00);

		/* Config gyroscope */
		//	temp = TM_I2C_Read(MPU6050_I2C, DataStruct->Address, MPU6050_GYRO_CONFIG);
		Read_I2C2(0x68, MPU6050_GYRO_CONFIG); //store data in 'DATA'

		//	temp = (temp & 0xE7) | (uint8_t)GyroscopeSensitivity << 3;
		DATA = (DATA & 0xE7) | Gyro_Sensitivity_250s << 3;

		//write shifted DATA to GYRO_CONFIG register
		//	TM_I2C_Write(MPU6050_I2C, DataStruct->Address, MPU6050_GYRO_CONFIG, temp);
		Write_I2C2(0x68, 0x1B, DATA);


		//DataStruct->Gyro_Mult = (float)1 / MPU6050_GYRO_SENS_250;
		Gyro_Mult= (float) 1/MPU6050_GYRO_SENS_250;

//		//ACCELEROMETER INIT
		/* Config accelerometer */
		//temp = TM_I2C_Read(MPU6050_I2C, DataStruct->Address, MPU6050_ACCEL_CONFIG);
		Read_I2C2(0x68,MPU6050_ACCEL_CONFIG);

		//temp = (temp & 0xE7) | (uint8_t)AccelerometerSensitivity << 3;
		DATA= (DATA & 0xE7)|(uint8_t)Accelerometer_Range <<3;

		//TM_I2C_Write(MPU6050_I2C, DataStruct->Address, MPU6050_ACCEL_CONFIG, temp);
		Write_I2C2(0X68,MPU6050_ACCEL_CONFIG,DATA);

		Acce_Mult = (float) 1/ MPU6050_ACCE_SENS_2;


////========= I2C 1 VERSION
//
//		MPU6050_Address_Init();
//		ADDRESS_D0;
//
//		//Format I2C Address
//		//BW_MPU6050.Address = MPU6050_I2C_ADDR | 1;
//
//		BW_MPU6050.Address=0x68;
//
//		Setup_I2C();
//
//		Write_I2C(0x68, MPU6050_PWR_MGMT_1, 0x6B);
//		Write_I2C(0x68, MPU6050_PWR_MGMT_1, 0x00);
//
//		/* Config gyroscope */
//		//	temp = TM_I2C_Read(MPU6050_I2C, DataStruct->Address, MPU6050_GYRO_CONFIG);
//		Read_I2C(0x68, MPU6050_GYRO_CONFIG); //store data in 'DATA'
//
//		//	temp = (temp & 0xE7) | (uint8_t)GyroscopeSensitivity << 3;
//		DATA = (DATA & 0xE7) | Gyro_Sensitivity_250s << 3;
//
//		//write shifted DATA to GYRO_CONFIG register
//		//	TM_I2C_Write(MPU6050_I2C, DataStruct->Address, MPU6050_GYRO_CONFIG, temp);
//		Write_I2C(0x68, 0x1B, DATA);
//
//
//		//DataStruct->Gyro_Mult = (float)1 / MPU6050_GYRO_SENS_250;
//		Gyro_Mult= (float) 1/MPU6050_GYRO_SENS_250;
//
////		//ACCELEROMETER INIT
//		/* Config accelerometer */
//		//temp = TM_I2C_Read(MPU6050_I2C, DataStruct->Address, MPU6050_ACCEL_CONFIG);
//		Read_I2C(0x68,MPU6050_ACCEL_CONFIG);
//
//		//temp = (temp & 0xE7) | (uint8_t)AccelerometerSensitivity << 3;
//		DATA= (DATA & 0xE7)|(uint8_t)Accelerometer_Range <<3;
//
//		//TM_I2C_Write(MPU6050_I2C, DataStruct->Address, MPU6050_ACCEL_CONFIG, temp);
//		Write_I2C(0X68,MPU6050_ACCEL_CONFIG,DATA);
//		Acce_Mult = (float) 1/ MPU6050_ACCE_SENS_2;

}


void Read_Gyro(void)
{
	int count;
	uint8_t data[6];

	for (count=0;count<=5;count++)
	{
		//Read_I2C(shifted_address,regs);
		Read_I2C2(0x68, MPU6050_GYRO_XOUT_H); //Aslinya 0xD0, tapi hasilnya digeser satu bit ke kanan
//		Read_I2C(0x68, MPU6050_GYRO_XOUT_H); //Aslinya 0xD0, tapi hasilnya digeser satu bit ke kanan
		data[count]=DATA;
	}

	/* Format */
	BW_MPU6050.Gyroscope_X = (int16_t)(data[0] << 8 | data[1]);
	BW_MPU6050.Gyroscope_Y = (int16_t)(data[2] << 8 | data[3]);
	BW_MPU6050.Gyroscope_Z = (int16_t)(data[4] << 8 | data[5]);



	//Read_Gyro();
//	lcd_display_clear();
//	sprintf(lcd,"X: %d Y: %d Z: %d",BW_MPU6050.Gyroscope_X,BW_MPU6050.Gyroscope_Y,BW_MPU6050.Gyroscope_Z);
//	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);

	//printf(lcd);
}

//Converts the already acquired accelerometer data into 3D euler angles
void Read_Accelerometer(void)
{
	int count;
	uint8_t data[6];

	/* Read accelerometer data */
	//TM_I2C_ReadMulti(MPU6050_I2C, DataStruct->Address, MPU6050_ACCEL_XOUT_H, data, 6);


	for (count=0;count<=5;count++)
	{
		//Read_I2C(shifted_address,regs);
		if(count==0) Read_I2C2(0x68, MPU6050_ACCEL_XOUT_H); //Aslinya 0xD0, tapi hasilnya digeser satu bit ke kanan
		else if(count==1)Read_I2C(0x68, MPU6050_ACCEL_XOUT_L);
		else if(count==2)Read_I2C2(0x68, MPU6050_ACCEL_YOUT_H);
		else if(count==3)Read_I2C(0x68, MPU6050_ACCEL_YOUT_L);
		else if(count==4)Read_I2C2(0x68, MPU6050_ACCEL_ZOUT_H);
		else if(count==5)Read_I2C(0x68, MPU6050_ACCEL_ZOUT_L);
		data[count]=DATA;
	}


	/* Format */
	BW_MPU6050.Accelerometer_X = (int16_t)(data[0] << 8 | data[1]);
	BW_MPU6050.Accelerometer_Y = (int16_t)(data[2] << 8 | data[3]);
	BW_MPU6050.Accelerometer_Z = (int16_t)(data[4] << 8 | data[5]);

	/*
	 * METHOD 1
	 */
	//axx_sudut_x =(float) 57.295*atan((float)axx_y/ sqrt(pow((float)axx_z,2)+pow((float)axx_x,2)));

	Accel_Angle_X= (float) 57.295 * atan((float)BW_MPU6050.Accelerometer_Y / sqrt (pow((float)BW_MPU6050.Accelerometer_Z,2) + pow((float)BW_MPU6050.Accelerometer_X,2)));

	Accel_Angle_Y= (float) 57.295 * atan((float)-BW_MPU6050.Accelerometer_X / sqrt(pow((float)BW_MPU6050.Accelerometer_Z,2) + pow((float)BW_MPU6050.Accelerometer_Y,2)));
	//axx_sudut_y =(float) 57.295*atan((float)-axx_x/ sqrt(pow((float)axx_z,2)+pow((float)axx_y,2)));

	Accel_Angle_Z= (float) 57.295 * atan(sqrt (pow((float)BW_MPU6050.Accelerometer_X,2) + pow((float)BW_MPU6050.Accelerometer_Y,2) / (float)BW_MPU6050.Accelerometer_Z));
	//axx_sudut_z =(float) 57.295*atan(sqrt(pow((float)axx_x,2)+pow((float)axx_y,2))/(float)axx_z);

	/*
	 * METHOD 2
	 */
	LPF_ACCEL_X= BW_MPU6050.Accelerometer_X * ALPHA + (LPF_ACCEL_X * (1.0 - ALPHA));
	LPF_ACCEL_Y= BW_MPU6050.Accelerometer_Y * ALPHA + (LPF_ACCEL_Y * (1.0 - ALPHA));
	LPF_ACCEL_Z= BW_MPU6050.Accelerometer_Z * ALPHA + (LPF_ACCEL_Z * (1.0 - ALPHA));

	ROLL= (float) (atan2(-LPF_ACCEL_Y,LPF_ACCEL_Z)*180.0)/M_PI;
	PITCH= (float) (atan2(-LPF_ACCEL_X, sqrt( (LPF_ACCEL_Y*LPF_ACCEL_Y)+(LPF_ACCEL_Z*LPF_ACCEL_Z)))*180)/M_PI;

	// implementasi komplementari filter
//	comp_roll = 0.93 * (comp_roll + roll) + (0.07 * sudut_ax);
//	comp_pitch = 0.93 * (comp_pitch + pitch) + (0.07 * sudut_ay);

	COMPLEMENTARY_ROLL= 0.93 * (COMPLEMENTARY_ROLL + ROLL) + (0.07 * Accel_Angle_X);
	COMPLEMENTARY_PITCH= 0.93 * (COMPLEMENTARY_PITCH + PITCH) + (0.07 * Accel_Angle_Y);

	delay_ms(10);

}

void ComplementaryFilter(void)
{

//	sudut = (a)*(sudut+out_gyro*dt)+(1-a)*(sudut_acc);
//
//	Dimana:
//	a          =  koefisien filter
//	dt         =  waktu sampling, disesuaikan dengan waktu sampling nilai sensor
//	sudut      =  sudut keluaran complementary filter
//	out_gyro   =  keluaran sensor gyroscope berupa kecepatan sudut
//	sudut_acc  =  keluaran sensor accelerometer yang sudah berupa sudut

//	τ=(a*dt)/(1-a)
//	dimana:
//	a=koefisien filter
//	dt=waktu sampling

	COMPLEMENTARY_YAW= (0.97 * (COMPLEMENTARY_YAW+GYRO_Z*dt) ) + (0.03*LPF_ACCEL_Z);


}


void Gyro_Calibration(void)
{

	Sendto_PC(USART1,"BW Gyroscope Calibration Initializing \r");

	for(GYRO_COUNTER=0;GYRO_COUNTER<1000;GYRO_COUNTER++)
	{
		Read_I2C(0x68, MPU6050_GYRO_XOUT_H);
		GYRO_XH=DATA;

		Read_I2C(0x68, MPU6050_GYRO_XOUT_L);
		GYRO_XL=DATA;

		Read_I2C(0x68, MPU6050_GYRO_YOUT_H);
		GYRO_YH=DATA;

		Read_I2C(0x68, MPU6050_GYRO_YOUT_L);
		GYRO_YL=DATA;

		Read_I2C(0x68, MPU6050_GYRO_ZOUT_H);
		GYRO_ZH=DATA;

		Read_I2C(0x68, MPU6050_GYRO_ZOUT_L);
		GYRO_ZL=DATA;

		GYRO_XOUT_OFFSET_1000SUM += ((GYRO_XH<<8)|GYRO_XL);
		GYRO_YOUT_OFFSET_1000SUM += ((GYRO_YH<<8)|GYRO_YL);
		GYRO_ZOUT_OFFSET_1000SUM += ((GYRO_ZH<<8)|GYRO_ZL);

		delay_ms(1);
	}
	GYRO_X_OFFSET = GYRO_XOUT_OFFSET_1000SUM/1000;
	GYRO_Y_OFFSET = GYRO_YOUT_OFFSET_1000SUM/1000;
	GYRO_Z_OFFSET = GYRO_ZOUT_OFFSET_1000SUM/1000;


	Sendto_PC(USART1,"BW Gyroscope Calibration Success! \r ");
}

void Read_Gyroscope(void)
{
	Read_I2C(0x68, MPU6050_GYRO_XOUT_H);
	GYRO_XH=DATA;

	Read_I2C(0x68, MPU6050_GYRO_XOUT_L);
	GYRO_XL=DATA;

	Read_I2C(0x68, MPU6050_GYRO_YOUT_H);
	GYRO_YH=DATA;

	Read_I2C(0x68, MPU6050_GYRO_YOUT_L);
	GYRO_YL=DATA;

	Read_I2C(0x68, MPU6050_GYRO_ZOUT_H);
	GYRO_ZH=DATA;

	Read_I2C(0x68, MPU6050_GYRO_ZOUT_L);
	GYRO_ZL=DATA;

//	GYRO_XOUT = ((GYRO_XOUT_H<<8)|GYRO_XOUT_L) - GYRO_XOUT_OFFSET;
//	GYRO_YOUT = ((GYRO_YOUT_H<<8)|GYRO_YOUT_L) - GYRO_YOUT_OFFSET;
//	GYRO_ZOUT = ((GYRO_ZOUT_H<<8)|GYRO_ZOUT_L) - GYRO_ZOUT_OFFSET;
//
//
//	GYRO_XRATE = (float)GYRO_XOUT/gyro_xsensitivity;
//	GYRO_YRATE = (float)GYRO_YOUT/gyro_ysensitivity;
//	GYRO_ZRATE = (float)GYRO_ZOUT/gyro_zsensitivity;

	GYRO_X= ((GYRO_XH<<8)|GYRO_XL) - GYRO_X_OFFSET;
	GYRO_Y= ((GYRO_YH<<8)|GYRO_YL) - GYRO_Y_OFFSET;
	GYRO_Z= ((GYRO_ZH<<8)|GYRO_ZL) - GYRO_Z_OFFSET;

	RATE_GYRO_X= (float) GYRO_X/MPU6050_GYRO_SENS_250;
	RATE_GYRO_Y= (float) GYRO_Y/MPU6050_GYRO_SENS_250;
	RATE_GYRO_Z= (float) GYRO_Z/MPU6050_GYRO_SENS_250;

	GYRO_ANGLE_X+= RATE_GYRO_X * dt;
	GYRO_ANGLE_Y+= RATE_GYRO_Y * dt;
	GYRO_ANGLE_Z+= RATE_GYRO_Z * dt;


}
//var distance_X = 0
//var velocity_X = 0
//
//function update_acceleration_X (acceleration_X) {
//    velocity_X = velocity_X + acceleration_X
//    distance_X = distance_X + velocity_X
//}
//
//// To use the distance value just read the distance_X variable:
//function get_distance_X_and_reset () {
//    x = distance_X
//    distance_X = 0
//    return x
//}
int distance_x = 0;
int velocity_x = 0;

int bw_get_distance_x(void)
{
	int ret_val=0;
	velocity_x = velocity_x + BW_MPU6050.Accelerometer_X;
	distance_x = distance_x + velocity_x;
	ret_val = distance_x;
	distance_x=0;

	return ret_val;
}

double Accel2mms(double accel, double freq)
{
    double result = 0;
    result = (GRAVITY*accel)/(2*PI*freq);
    return result;
}




