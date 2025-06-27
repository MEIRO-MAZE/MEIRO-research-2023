/*==============================================================================================
								 	 PROJECT BW Ver.1.0
					    BW DEVANTECH CMPS-11 MAGNETIC COMPASS LIBRARY
==============================================================================================*/

#ifndef BW_CMPS11_H
#define BW_CMPS11_H

#include "main.h"

/*
 *  CMPS-11 UART SERIAL COMMANDS
 */
extern unsigned int GET_VERSION;
extern unsigned int GET_ANGLE_8_BIT;
extern unsigned int GET_ANGLE_16_BIT;
extern unsigned int GET_PITCH;
extern unsigned int GET_ROLL;
extern unsigned int GET_PITCH_NO_KF;
extern unsigned int GET_ROLL_NO_KF;
extern unsigned int GET_MAG_RAW;
extern unsigned int GET_ACCEL_RAW;
extern unsigned int GET_GYRO_RAW;
extern unsigned int GET_TEMP;
extern unsigned int GET_ALL;
extern unsigned int CALIBRATE_BYTE_1;
extern unsigned int CALIBRATE_BYTE_2;
extern unsigned int CALIBRATE_BYTE_3_FULL;
extern unsigned int CALIBRATE_BYTE_3_FLAT;
extern unsigned int CALIBRATE_EXIT;
extern unsigned int RESTORE_1;
extern unsigned int RESTORE_2;
extern unsigned int RESTORE_3;
extern unsigned int BAUD_19200;
extern unsigned int BAUD_38400;

extern int CMPS11_Angle;
extern int8_t CMPS11_Pitch;
extern int Calibration_Status;
extern volatile int COMPASS_INTERRUPT;

struct BW_IMU_t
{
	/*
	 * Pitch & Roll Angle with Kalman Filter
	 */
	int8_t PitchKF;
	int8_t RollKF;

	/*
	 * Pitch & Roll Angle without Kalman Filter
	 */
	int8_t PitchNoKF;
	int8_t RollNoKF;

	/*
	 * Compass Bearing with 8 Bit & 16 Bit Resolution Data
	 */
	int Compass8Bit;
	int8_t Compass16Bit[3];

	/*
	 * Magnetometer Raw Data
	 */
	int8_t MagX[3];
	int8_t MagY[3];
	int8_t MagZ[3];

	/*
	 * Accelerometer Raw Data
	 */
	int8_t AccX[3];
	int8_t AccY[3];
	int8_t AccZ[3];

	/*
	 * Gyroscope Raw Data
	 */
	int8_t GyroX[3];
	int8_t GyroY[3];
	int8_t GyroZ[3];

	/*
	 * Temperature Data (in Degrees)
	 */
	int8_t Temperature[3];

	/*
	 * Pitch & Roll with Complementary Filter
	 */
	float PitchComp, RollComp;
	float PitchComp2, RollComp2;

	// Calibration Status Byte
	int Calibration_Status;


} BW_CMPS11;

#define HIGH   0
#define LOW    1
#define MERGED 2


/*
 * Pitch Angle Kalman Filter Status
 */
#define KF_ACTIVE   0
#define KF_INACTIVE 1

/*
 * CMPS-11 I2C REGISTER
 */

//#define CMPS11_ADDRESS					0x60 //Aslinya C0, tapi digeser 1 bit ke kanan
#define CMPS11_ADDRESS					0xC0 //Default CMPS-11 DEVICE ADDRESS


#define CMPS11_CMD_REGISTER 			0x00 // Command register (write) / Software version (read)


#define CMPS11_BEARING_8BIT 			0x01 // 0-255
#define CMPS11_BEARING_16BIT_H 			0x02 // HIGH BYTE 0-3599 representing 0-355.9 degrees
#define CMPS11_BEARING_16BIT_L 			0x03 // LOW BYTE
#define CMPS11_PITCH_KF					0x04 // PITCH angle Kalman Filtered
#define CMPS11_ROLL_KF					0x05 // ROLL angle Kalman Filtered

#define CMPS12_CAL_REGISTER				0x1E // Calibration Status Register

/*
 * MAGNETOMETER RAW OUTPUT
 */
#define CMPS11_MAG_XH					0x06
#define CMPS11_MAG_XL					0x07
#define CMPS11_MAG_YH					0x08
#define CMPS11_MAG_YL					0x09
#define CMPS11_MAG_ZH					0x0A
#define CMPS11_MAG_ZL					0x0B

/*
 * ACCELEROMETER RAW OUTPUT
 */
#define CMPS11_ACC_XH					0x0C
#define CMPS11_ACC_XL					0x0D
#define CMPS11_ACC_YH					0x0E
#define CMPS11_ACC_YL					0x0F
#define CMPS11_ACC_ZH					0x10
#define CMPS11_ACC_ZL					0x11

/*
 * GYROSCOPE RAW OUTPUT
 */
#define CMPS11_GYRO_XH					0x12
#define CMPS11_GYRO_XL					0x13
#define CMPS11_GYRO_YH					0x14
#define CMPS11_GYRO_YL					0x15
#define CMPS11_GYRO_ZH					0x16
#define CMPS11_GYRO_ZL					0x17

/*
 * TEMPERATURE RAW OUTPUT
 */
#define CMPS11_TEMP_H					0x18
#define CMPS11_TEMP_L					0x19

/*
 * PITCH AND ROLL WITHOUT KALMAN FILTER
 */
#define CMPS11_PITCH_NO_KF				0x20
#define CMPS11_ROLL_NO_KF				0x21

extern unsigned int CMPS11_COMPASS_ANGLE;
extern uint8_t    I2C2_DATA[];
//--------------------------------------------------------------
// MultiByte defines
//--------------------------------------------------------------
#define    I2C3_MULTIBYTE_MAX   10
extern uint8_t    I2C2_DATA[];
extern uint8_t	  I2C3_DATA[];

#define ALPHA 0.5

//--------------------------------------------------------------
// I2C TIMEOUT Defines
//--------------------------------------------------------------
#define   I2C2_TIMEOUT     0x3000
#define   I2C3_TIMEOUT		0x3000


/*
 *  COMPASS ARENA FLAG
 */
extern unsigned int CMPS_ACTIVE;
extern unsigned int CMPS_INACTIVE;
extern unsigned int ARENA_FLAG;
extern unsigned int TRESH_UPPER;
extern unsigned int TRESH_LOWER;
extern unsigned int TRESH_FLAG;
extern unsigned int NORTH_THRESHOLD_UPPER;
extern unsigned int NORTH_THRESHOLD_LOWER;
extern unsigned int NORTH_THRESHOLD_MIDDLE;
extern unsigned int WEST_THRESHOLD_UPPER;
extern unsigned int WEST_THRESHOLD_LOWER;
extern unsigned int WEST_THRESHOLD_MIDDLE;
extern unsigned int SOUTH_THRESHOLD_UPPER;
extern unsigned int SOUTH_THRESHOLD_LOWER;
extern unsigned int SOUTH_THRESHOLD_MIDDLE;
extern unsigned int EAST_THRESHOLD_UPPER;
extern unsigned int EAST_THRESHOLD_LOWER;
extern unsigned int EAST_THRESHOLD_MIDDLE;

extern unsigned int R4AB_THRESHOLD_UPPER;
extern unsigned int R4AB_THRESHOLD_LOWER;
extern unsigned int R4AB_THRESHOLD_MIDDLE;

extern unsigned int R4A_THRESHOLD_UPPER;
extern unsigned int R4A_THRESHOLD_LOWER;
extern unsigned int R4B_THRESHOLD_UPPER;
extern unsigned int R4B_THRESHOLD_LOWER;

/*
 * FUNCTION PROTOTYPES
 */
void GetCMPS11_Angle8Bit(void);
void GetCMPS11_Angle8bit_Debug(void);
void GetCMPS11_Angle16Bit(void);
void BW_CMPS11_Init (void);
void Display_CMPS11_Angle(void);
void Display_Yaw_Angle(void);
void Display_Roll_Data(void);
void Fix_Direction(void);
void Display_Fix_Direction(void);
void Display_Fix_Direction_16bit(void);
int16_t I2C2_ReadMultiByte(uint8_t ADDRESS, uint8_t REGISTER, uint8_t BYTE);

int16_t I2C3_ReadByte(uint8_t ADDRESS, uint8_t REGISTER);
void CMPS12_I2C_Store_Profile(void);
void CMPS12_I2C_Delete_Profile(void);
int CMPS11_Check(void);
void I2C3_Test(void);
void CMPS11_I2C_Calibration(void);
void GetCMPS11_Pitch(int KF_STATUS);
void Display_Pitch_Data(void);
void Cmps11_Interrupt_Init(void);
#endif
