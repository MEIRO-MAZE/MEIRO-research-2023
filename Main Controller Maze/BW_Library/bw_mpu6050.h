/*==============================================================================================
								  PROJECT BW Ver.1.0
								  BW MPU6050 LIBRARY
==============================================================================================*/
#include "main.h"

#ifndef BW_MPU6050_H
#define BW_MPU6050_H

/*
 *  MPU 6050
 */
/* Gyro sensitivities in °/s */
#define MPU6050_GYRO_SENS_250		((float) 131)
#define MPU6050_GYRO_SENS_500		((float) 65.5)
#define MPU6050_GYRO_SENS_1000		((float) 32.8)
#define MPU6050_GYRO_SENS_2000		((float) 16.4)

/* Acce sensitivities in g */
#define MPU6050_ACCE_SENS_2			((float) 16384)
#define MPU6050_ACCE_SENS_4			((float) 8192)
#define MPU6050_ACCE_SENS_8			((float) 4096)
#define MPU6050_ACCE_SENS_16		((float) 2048)

//#define MPU6050_RA_ACCEL_XOUT_H     0x3B
//#define MPU6050_RA_ACCEL_XOUT_L     0x3C
//#define MPU6050_RA_ACCEL_YOUT_H     0x3D
//#define MPU6050_RA_ACCEL_YOUT_L     0x3E
//#define MPU6050_RA_ACCEL_ZOUT_H     0x3F
//#define MPU6050_RA_ACCEL_ZOUT_L     0x40
//#define MPU6050_RA_TEMP_OUT_H       0x41
//#define MPU6050_RA_TEMP_OUT_L       0x42
//#define MPU6050_RA_GYRO_XOUT_H      0x43
//#define MPU6050_RA_GYRO_XOUT_L      0x44
//#define MPU6050_RA_GYRO_YOUT_H      0x45
//#define MPU6050_RA_GYRO_YOUT_L      0x46
//#define MPU6050_RA_GYRO_ZOUT_H      0x47
//#define MPU6050_RA_GYRO_ZOUT_L      0x48

//MPU6050 ACCELEROMETER REGISTER
#define MPU6050_ACCEL_XOUT_H		0x3B
#define MPU6050_ACCEL_XOUT_L		0x3C
#define MPU6050_ACCEL_YOUT_H		0x3D
#define MPU6050_ACCEL_YOUT_L		0x3E
#define MPU6050_ACCEL_ZOUT_H		0x3F
#define MPU6050_ACCEL_ZOUT_L		0x40

#define MPU6050_TEMP_OUT_H			0x41
#define MPU6050_TEMP_OUT_L			0x42

//MPU6050 GYROSCOPE REGISTER
#define MPU6050_GYRO_XOUT_H			0x43
#define MPU6050_GYRO_XOUT_L 		0X44
#define MPU6050_GYRO_YOUT_H			0x45
#define MPU6050_GYRO_YOUT_L			0x46
#define MPU6050_GYRO_ZOUT_H			0x47
#define MPU6050_GYRO_ZOUT_L			0x48


int ACC_XH,ACC_XL, ACC_YH, ACC_YL, ACC_ZH, ACC_ZL;
int GYRO_XH,GYRO_XL,GYRO_YH,GYRO_YL,GYRO_ZH,GYRO_ZL;
int GYRO_XH100,GYRO_XL100,GYRO_YH100,GYRO_YL100,GYRO_ZH100,GYRO_ZL100;
int GYRO_COUNTER;
int GYRO_X_OFFSET,GYRO_Y_OFFSET,GYRO_Z_OFFSET;
int GYRO_X,GYRO_Y,GYRO_Z;
float RATE_GYRO_X,RATE_GYRO_Y,RATE_GYRO_Z;
int GYRO_ANGLE_X,GYRO_ANGLE_Y,GYRO_ANGLE_Z;
int FLT_GYRO_X,FLT_GYRO_Y,FLT_GYRO_Z;
float PITCH, ROLL;

int LPF_ACCEL_X,LPF_ACCEL_Y,LPF_ACCEL_Z;
float COMPLEMENTARY_PITCH, COMPLEMENTARY_ROLL,COMPLEMENTARY_YAW;


int GYRO_XOUT_OFFSET_1000SUM,GYRO_YOUT_OFFSET_1000SUM,GYRO_ZOUT_OFFSET_1000SUM;
extern unsigned int MPU6050_PWR_MGMT_1;
extern unsigned int MPU6050_GYRO_CONFIG;
extern unsigned int Gyro_Sensitivity_250s;
extern unsigned int Accelerometer_Range;
extern float Gyro_Mult;

//ACCELEROMETER REGISTER
extern float Acce_Mult;
extern unsigned int MPU6050_ACCEL_CONFIG;

extern char lcd[];
//uint8_t temp;

struct BW_MPU6050_t
{
	/* Private */
	uint8_t Address;         /*!< I2C address of device. Only for private use */
	float Gyro_Mult;         /*!< Gyroscope corrector from raw data to "degrees/s". Only for private use */
	float Acce_Mult;         /*!< Accelerometer corrector from raw data to "g". Only for private use */
	/* Public */
	int16_t Accelerometer_X; /*!< Accelerometer value X axis */
	int16_t Accelerometer_Y; /*!< Accelerometer value Y axis */
	int16_t Accelerometer_Z; /*!< Accelerometer value Z axis */
	int16_t Gyroscope_X;     /*!< Gyroscope value X axis */
	int16_t Gyroscope_Y;     /*!< Gyroscope value Y axis */
	int16_t Gyroscope_Z;     /*!< Gyroscope value Z axis */
	float Temperature;       /*!< Temperature in degrees */
} BW_MPU6050;

//CONVERTED IMU VALUES
extern float ACCEL_DEG;
extern float GYRO_DEG;

extern double PI;
extern double GRAVITY;

#define ACCELEROMETER_SENSITIVITY 8192.0
#define GYROSCOPE_SENSITIVITY 65.536


#define RAD_TO_DEG 57.295
#define dt 0.1							//10 ms sample rate!


extern float pitch;
extern float roll;

#define RCC_AHB1Periph_ADDRESS RCC_AHB1Periph_GPIOE
#define ADDRESS_PORT GPIOE
#define ADDRESS_PIN GPIO_Pin_0
#define ADDRESS_ON GPIO_SetBits(ADDRESS_PORT, ADDRESS_PIN);
#define ADDRESS_D0 GPIO_ResetBits (ADDRESS_PORT, ADDRESS_PIN);

float Accel_Angle_X,Accel_Angle_Y,Accel_Angle_Z;

/*
 * BW MPU6050 FUNCTION PROTOTYPE
 */
void Write_I2C2(int Address, int Register, int Data);
void Read_I2C2(int Address, int Register);
void MPU_6050_Init(void);
void Read_Gyro(void);
void Read_Accelerometer(void);
int bw_get_distance_x(void);
void Gyro_Calibration(void);
void Read_Gyroscope(void);
void ComplementaryFilter(void);


#endif
