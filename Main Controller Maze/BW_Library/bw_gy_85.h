/*==============================================================================================
								 	 PROJECT BW Ver.1.0
								  	 BW GY-85 IMU LIBRARY
==============================================================================================*/

#ifndef BW_GY_85_H
#define BW_GY_85_H

#include "main.h"

/*
 * ADXL345 ACCELEROMETER MACRO REGISTER ADDRESSES
 */

#define ADXL345_DEVICE (0x53)    // ADXL345 device address
#define ADXL345_TO_READ (6)      // num of bytes we are going to read each time (two bytes for each axis)


/* ------- Register names ------- */
#define ADXL345_DEVID 0x00
#define ADXL345_RESERVED1 0x01
#define ADXL345_THRESH_TAP 0x1D
#define ADXL345_OFSX 0x1E
#define ADXL345_OFSY 0x1F
#define ADXL345_OFSZ 0x20
#define ADXL345_DUR 0x21
#define ADXL345_LATENT 0x22
#define ADXL345_WINDOW 0x23
#define ADXL345_THRESH_ACT 0x24
#define ADXL345_THRESH_INACT 0x25
#define ADXL345_TIME_INACT 0x26
#define ADXL345_ACT_INACT_CTL 0x27
#define ADXL345_THRESH_FF 0x28
#define ADXL345_TIME_FF 0x29
#define ADXL345_TAP_AXES 0x2A
#define ADXL345_ACT_TAP_STATUS 0x2B
#define ADXL345_BW_RATE 0x2C
#define ADXL345_POWER_CTL 0x2D
#define ADXL345_INT_ENABLE 0x2E
#define ADXL345_INT_MAP 0x2F
#define ADXL345_INT_SOURCE 0x30
#define ADXL345_DATA_FORMAT 0x31
#define ADXL345_DATAX0 0x32
#define ADXL345_DATAX1 0x33
#define ADXL345_DATAY0 0x34
#define ADXL345_DATAY1 0x35
#define ADXL345_DATAZ0 0x36
#define ADXL345_DATAZ1 0x37
#define ADXL345_FIFO_CTL 0x38
#define ADXL345_FIFO_STATUS 0x39

#define ADXL345_BW_1600 0xF // 1111
#define ADXL345_BW_800  0xE // 1110
#define ADXL345_BW_400  0xD // 1101
#define ADXL345_BW_200  0xC // 1100
#define ADXL345_BW_100  0xB // 1011
#define ADXL345_BW_50   0xA // 1010
#define ADXL345_BW_25   0x9 // 1001
#define ADXL345_BW_12   0x8 // 1000
#define ADXL345_BW_6    0x7 // 0111
#define ADXL345_BW_3    0x6 // 0110

/*
 Interrupt PINs
 INT1: 0
 INT2: 1
 */
#define ADXL345_INT1_PIN 0x00
#define ADXL345_INT2_PIN 0x01

/*
 Interrupt bit position
 */
#define ADXL345_INT_DATA_READY_BIT 0x07
#define ADXL345_INT_SINGLE_TAP_BIT 0x06
#define ADXL345_INT_DOUBLE_TAP_BIT 0x05
#define ADXL345_INT_ACTIVITY_BIT   0x04
#define ADXL345_INT_INACTIVITY_BIT 0x03
#define ADXL345_INT_FREE_FALL_BIT  0x02
#define ADXL345_INT_WATERMARK_BIT  0x01
#define ADXL345_INT_OVERRUNY_BIT   0x00

#define ADXL345_DATA_READY 0x07
#define ADXL345_SINGLE_TAP 0x06
#define ADXL345_DOUBLE_TAP 0x05
#define ADXL345_ACTIVITY   0x04
#define ADXL345_INACTIVITY 0x03
#define ADXL345_FREE_FALL  0x02
#define ADXL345_WATERMARK  0x01
#define ADXL345_OVERRUNY   0x00

#define ADXL345_OK    1 // no error
#define ADXL345_ERROR 0 // indicates error is predent

#define ADXL345_NO_ERROR   0 // initial state
#define ADXL345_READ_ERROR 1 // problem reading accel
#define ADXL345_BAD_ARG    2 // bad method argument


/*=========================================================================
    I2C ADDRESS/BITS
    -----------------------------------------------------------------------*/
    #define ADXL345_ADDRESS                 (0x53)    // Assumes ALT address pin low
/*=========================================================================*/

/*=========================================================================
    REGISTERS
    -----------------------------------------------------------------------*/
    #define ADXL345_REG_DEVID               (0x00)    // Device ID
    #define ADXL345_REG_THRESH_TAP          (0x1D)    // Tap threshold
    #define ADXL345_REG_OFSX                (0x1E)    // X-axis offset
    #define ADXL345_REG_OFSY                (0x1F)    // Y-axis offset
    #define ADXL345_REG_OFSZ                (0x20)    // Z-axis offset
    #define ADXL345_REG_DUR                 (0x21)    // Tap duration
    #define ADXL345_REG_LATENT              (0x22)    // Tap latency
    #define ADXL345_REG_WINDOW              (0x23)    // Tap window
    #define ADXL345_REG_THRESH_ACT          (0x24)    // Activity threshold
    #define ADXL345_REG_THRESH_INACT        (0x25)    // Inactivity threshold
    #define ADXL345_REG_TIME_INACT          (0x26)    // Inactivity time
    #define ADXL345_REG_ACT_INACT_CTL       (0x27)    // Axis enable control for activity and inactivity detection
    #define ADXL345_REG_THRESH_FF           (0x28)    // Free-fall threshold
    #define ADXL345_REG_TIME_FF             (0x29)    // Free-fall time
    #define ADXL345_REG_TAP_AXES            (0x2A)    // Axis control for single/double tap
    #define ADXL345_REG_ACT_TAP_STATUS      (0x2B)    // Source for single/double tap
    #define ADXL345_REG_BW_RATE             (0x2C)    // Data rate and power mode control
    #define ADXL345_REG_POWER_CTL           (0x2D)    // Power-saving features control
    #define ADXL345_REG_INT_ENABLE          (0x2E)    // Interrupt enable control
    #define ADXL345_REG_INT_MAP             (0x2F)    // Interrupt mapping control
    #define ADXL345_REG_INT_SOURCE          (0x30)    // Source of interrupts
    #define ADXL345_REG_DATA_FORMAT         (0x31)    // Data format control
    #define ADXL345_REG_DATAX0              (0x32)    // X-axis data 0
    #define ADXL345_REG_DATAX1              (0x33)    // X-axis data 1
    #define ADXL345_REG_DATAY0              (0x34)    // Y-axis data 0
    #define ADXL345_REG_DATAY1              (0x35)    // Y-axis data 1
    #define ADXL345_REG_DATAZ0              (0x36)    // Z-axis data 0
    #define ADXL345_REG_DATAZ1              (0x37)    // Z-axis data 1
    #define ADXL345_REG_FIFO_CTL            (0x38)    // FIFO control
    #define ADXL345_REG_FIFO_STATUS         (0x39)    // FIFO status
/*=========================================================================*/

/*=========================================================================
    REGISTERS
    -----------------------------------------------------------------------*/
    #define ADXL345_MG2G_MULTIPLIER (0.004)  // 4mg per lsb
/*=========================================================================*/

/* Used with register 0x2C (ADXL345_REG_BW_RATE) to set bandwidth */
typedef enum
{
  ADXL345_DATARATE_3200_HZ    = 0b1111, // 1600Hz Bandwidth   140µA IDD
  ADXL345_DATARATE_1600_HZ    = 0b1110, //  800Hz Bandwidth    90µA IDD
  ADXL345_DATARATE_800_HZ     = 0b1101, //  400Hz Bandwidth   140µA IDD
  ADXL345_DATARATE_400_HZ     = 0b1100, //  200Hz Bandwidth   140µA IDD
  ADXL345_DATARATE_200_HZ     = 0b1011, //  100Hz Bandwidth   140µA IDD
  ADXL345_DATARATE_100_HZ     = 0b1010, //   50Hz Bandwidth   140µA IDD
  ADXL345_DATARATE_50_HZ      = 0b1001, //   25Hz Bandwidth    90µA IDD
  ADXL345_DATARATE_25_HZ      = 0b1000, // 12.5Hz Bandwidth    60µA IDD
  ADXL345_DATARATE_12_5_HZ    = 0b0111, // 6.25Hz Bandwidth    50µA IDD
  ADXL345_DATARATE_6_25HZ     = 0b0110, // 3.13Hz Bandwidth    45µA IDD
  ADXL345_DATARATE_3_13_HZ    = 0b0101, // 1.56Hz Bandwidth    40µA IDD
  ADXL345_DATARATE_1_56_HZ    = 0b0100, // 0.78Hz Bandwidth    34µA IDD
  ADXL345_DATARATE_0_78_HZ    = 0b0011, // 0.39Hz Bandwidth    23µA IDD
  ADXL345_DATARATE_0_39_HZ    = 0b0010, // 0.20Hz Bandwidth    23µA IDD
  ADXL345_DATARATE_0_20_HZ    = 0b0001, // 0.10Hz Bandwidth    23µA IDD
  ADXL345_DATARATE_0_10_HZ    = 0b0000  // 0.05Hz Bandwidth    23µA IDD (default value)
} dataRate_t;

/* Used with register 0x31 (ADXL345_REG_DATA_FORMAT) to set g range */
typedef enum
{
  ADXL345_RANGE_16_G          = 0b11,   // +/- 16g
  ADXL345_RANGE_8_G           = 0b10,   // +/- 8g
  ADXL345_RANGE_4_G           = 0b01,   // +/- 4g
  ADXL345_RANGE_2_G           = 0b00    // +/- 2g (default value)
} range_t;


float AccelOffset_X, AccelOffset_Y, AccelOffset_Z;
int Accel_X, Accel_Y, Accel_Z;
int AccelBuffer[6];
int ACC_XH,ACC_XL, ACC_YH, ACC_YL, ACC_ZH, ACC_ZL;

float Accel_RollRad, Accel_PitchRad;
float Accel_RollDeg, Accel_PitchDeg;

extern double PI;
extern double GRAVITY;
extern int DATA;

////--------------------------------------------------------------
//// MultiByte defines
////--------------------------------------------------------------
//#define    I2C2_MULTIBYTE_MAX   10
//extern uint8_t    I2C2_DATA[];
//
////--------------------------------------------------------------
//// I2C TIMEOUT Defines
////--------------------------------------------------------------
//#define   I2C2_TIMEOUT     0x3000

#endif
