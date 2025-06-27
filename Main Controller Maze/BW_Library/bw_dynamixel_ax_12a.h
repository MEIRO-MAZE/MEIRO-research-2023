/*===========================================================================================================================*
*===========================================================================================================================*
								  	  	  	  	PROJECT YUME 3.17 Ver.1.0
								  	 YUME DYNAMIXEL AX-12A SMART SERVO CONTROL LIBRARY
@Author  : Ryan (Batch 2013)
@Company : Brawijaya University Robotics Team
@Division: Intelligent Fire-Fighting Robot Division
@Team    : Project YUME (Legged Robot Sub-Division)
@E-mail	 : achnaf13@gmail.com
@Version : ALPHA RELEASE (ON PROGRESS)
@IDE	 : CooCox IDE 1.7.8

<================= UPDATE LOGS

<=== Version 1.0
@Date:


<=== Version 2.0
@Date:

<================= LIBRARY DEPENDENCIES



*===========================================================================================================================*
============================================================================================================================*/

#include "main.h"

#ifndef BW_DYNAMIXEL_AX_12A_H
#define BW_DYNAMIXEL_AX_12A_H

/*
 *<=================== INSTRUCTION PACKET STRUCTURE
 *
 * [HEADER] [ID] [PACKET_LENGTH] [INSTRUCTION] [PARAMETER] [16BIT CRC]
 * HEADER       : 0xFF 0xFF 	   	-> FIELD INDICATING START OF AN INCOMING PACKET
 *
 * ID           :					-> Unique ID of an Dynamixel Unit designated for instruction packet processing
 * 									 		Value Range		: 0 ~ 253 (0x00 ~ 0xFD) 254 unique value
 * 									 		Broadcasting ID : 254(0xFE)
 * 									 							-> Control ALL connected Dynamixel Unit
 * 									 						  	-> Will not return any status packet
 * 									 		Prohibited ID	: 255(0xFF)
 * 									 							-> Value used in Packet Header
 *
 * PACKET LENGTH: LENGTH     		-> Length of packet (Number of parameter (N)+2)
 * INSTRUCTION  : INST				-> Dynamixel data packet's command field
 * PARAMETER    : PARAM_1...PARAM_N -> Used when auxiliary data is required. Depends on the instruction
 * CHECK SUM    : CHECKSUM          -> Used to check for damages on data packet
 * 										-> Computation Method
 * 											CHECK SUM = ~(ID+LENGTH+INSTRUCTION+PARAMETER_1+...+PARAMETER_N
 * 											~ represent NOT logic operation
 *
 * 																             INSTRUCTION PACKET STRUCTURE ===================>
 */

/*
 *<=================== STATUS PACKET / RETURN PACKET STRUCTURE
 * STATUS PACKET is the response packet from Dynamixel unit to the Main Controller after receiving an instruction packet.
 * it follows the following structure:
 *
 * [HEADER] [ID] [PACKET_LENGTH] [ERROR] [PARAMETER1] [PARAMETER2]... [PARAMETERN][16BIT CRC]
 * HEADER       : 0xFF 0xFF 	   	-> FIELD INDICATING START OF AN INCOMING PACKET
 *
 * ID           :					-> Unique ID of an Dynamixel Unit designated for instruction packet processing
 * 									 		Value Range		: 0 ~ 253 (0x00 ~ 0xFD) 254 unique value
 * 									 		Broadcasting ID : 254(0xFE)
 * 									 							-> Control ALL connected Dynamixel Unit
 * 									 						  	-> Will not return any status packet
 * 									 		Prohibited ID	: 255(0xFF)
 * 									 							-> Value used in Packet Header
 *
 * PACKET LENGTH: LENGTH     		-> Length of packet (Number of parameter (N)+2)
 * INSTRUCTION  : ERROR				-> Byte representing errors sent from the Dynamixel unit. It has meaning as the following:
 *
 * 									<==== BIT ========= NAME ===================== DETAILS
 * 								    <==  Bit 7 |                    |                -
 * 								    <==  Bit 6 | Instruction Error |  Set to 1 if and undefined instruction is sent or
 * 								                                        an action instruction is sent without Reg_Write
 * 								                                        instruction
 * 								    <==  Bit 5 |   Overload Error  |
 * 								    <==  Bit 4 |  Checksum Error   |
 * 								    <==  Bit 3 |   Range Error     |
 * 								    <==  Bit 2 |   Overheating Error|
 * 								    <==  Bit 1 |  Angle Limit      |
 * 								    <==  Bit 0 |  Input Voltage Error
 * PARAMETER    : PARAM_1...PARAM_N -> Used when auxiliary data is required. Depends on the instruction
 * CHECK SUM    : CHECKSUM          -> Used to check for damages on data packet
 * 										-> Computation Method
 * 											CHECK SUM = ~(ID+LENGTH+INSTRUCTION+PARAMETER_1+...+PARAMETER_N
 * 											~ represent NOT logic operation
 *
 * 																             INSTRUCTION PACKET STRUCTURE ===================>
 */

/*
 *<=================== AVAILABLE DYNAMIXEL'S OUTPUT SHAFT ANGULAR POSITION
 *
 *  ANGLE(DEGREE)	:		VALUE
 *  	 0 			:		0x000 (0)
 *  	150 		:		0x1FF (511)
 *  	300			:		0x3FF (1023)
 *
 * <=== NOTE
 * 		RECOMMENDED ANGLE FOR CALIBRATION: 150 degree
 *
 * 		Angle to Value Calculation:
 * 			Value: (Desired Angle/300 * 1024) - 1
 *
 *
 * 													  AVAILABLE DYNAMIXEL'S OUTPUT SHAFT ANGULAR POSITION ===================>
 */

//buffer flush


#define AX_HEADER                   255 // 0xFF

#define AX_MODEL_NUMBER_L           0
#define AX_MODEL_NUMBER_H           1
#define AX_VERSION                  2
#define AX_ID                       3
#define AX_BAUD_RATE                4
#define AX_RETURN_DELAY_TIME        5
#define AX_CW_ANGLE_LIMIT_L         6
#define AX_CW_ANGLE_LIMIT_H         7
#define AX_CCW_ANGLE_LIMIT_L        8
#define AX_CCW_ANGLE_LIMIT_H        9
#define AX_SYSTEM_DATA2             10
#define AX_LIMIT_TEMPERATURE        11
#define AX_DOWN_LIMIT_VOLTAGE       12
#define AX_UP_LIMIT_VOLTAGE         13
#define AX_MAX_TORQUE_L             14
#define AX_MAX_TORQUE_H             15
#define AX_RETURN_LEVEL             16
#define AX_ALARM_LED                17
#define AX_ALARM_SHUTDOWN           18
#define AX_OPERATING_MODE           19
#define AX_DOWN_CALIBRATION_L       20
#define AX_DOWN_CALIBRATION_H       21
#define AX_UP_CALIBRATION_L         22
#define AX_UP_CALIBRATION_H         23

// RAM AREA  //////////////////////////////////////////////////////////////
#define AX_TORQUE_ENABLE            24
#define AX_LED                      25
#define AX_CW_COMPLIANCE_MARGIN     26
#define AX_CCW_COMPLIANCE_MARGIN    27
#define AX_CW_COMPLIANCE_SLOPE      28
#define AX_CCW_COMPLIANCE_SLOPE     29
#define AX_GOAL_POSITION_L          30
#define AX_GOAL_POSITION_H          31
#define AX_GOAL_SPEED_L             32
#define AX_GOAL_SPEED_H             33
#define AX_TORQUE_LIMIT_L           34
#define AX_TORQUE_LIMIT_H           35
#define AX_PRESENT_POSITION_L       36
#define AX_PRESENT_POSITION_H       37
#define AX_PRESENT_SPEED_L          38
#define AX_PRESENT_SPEED_H          39
#define AX_PRESENT_LOAD_L           40
#define AX_PRESENT_LOAD_H           41
#define AX_PRESENT_VOLTAGE          42
#define AX_PRESENT_TEMPERATURE      43
#define AX_REGISTERED_INSTRUCTION   44
#define AX_PAUSE_TIME               45
#define AX_MOVING                   46
#define AX_LOCK                     47
#define AX_PUNCH_L                  48
#define AX_PUNCH_H                  49

// Status Return Levels ///////////////////////////////////////////////////////////////
#define AX_RETURN_NONE              0
#define AX_RETURN_READ              1
#define AX_RETURN_ALL               2

// Instruction Set ///////////////////////////////////////////////////////////////
#define AX_PING                     1
#define AX_READ_DATA                2
#define AX_WRITE_DATA               3
#define AX_REG_WRITE                4
#define AX_ACTION                   5
#define AX_RESET                    6
#define AX_SYNC_WRITE               131

// Specials ///////////////////////////////////////////////////////////////
#define OFF                         0
#define ON                          1
#define LEFT						0
#define RIGHT                       1
#define AX_BYTE_READ                1
#define AX_BYTE_READ_POS            2
#define AX_RESET_LENGTH				2
#define AX_ACTION_LENGTH			2
#define AX_ID_LENGTH                4
#define AX_LR_LENGTH                4
#define AX_SRL_LENGTH               4
#define AX_RDT_LENGTH               4
#define AX_LEDALARM_LENGTH          4
#define AX_SALARM_LENGTH            4
#define AX_TL_LENGTH                4
#define AX_VL_LENGTH                6
#define AX_CM_LENGTH                6
#define AX_CS_LENGTH                6
#define AX_CCW_CW_LENGTH            8
#define AX_BD_LENGTH                4
#define AX_TEM_LENGTH               4
#define AX_MOVING_LENGTH            4
#define AX_RWS_LENGTH               4
#define AX_VOLT_LENGTH              4
#define AX_LED_LENGTH               4
#define AX_TORQUE_LENGTH            4
#define AX_POS_LENGTH               4
#define AX_GOAL_LENGTH              5
#define AX_MT_LENGTH                5
#define AX_PUNCH_LENGTH             5
#define AX_SPEED_LENGTH             5
#define AX_GOAL_SP_LENGTH           7
#define AX_ACTION_CHECKSUM			250
#define BROADCAST_ID                254

#define AX_CCW_AL_L                 255
#define AX_CCW_AL_H                 3
#define TIME_OUT                    10

//TX_DELAY TIME HEXAPOD
// 10 -> TERLALU BANYAK, ROBOT LAMBAT
// 5  -> CEPAT
//0   -> SUDUT KACAU,
//#define TX_DELAY_TIME				4  -> Dijadikan variables
#define Tx_MODE                     1
#define Rx_MODE                     0
#define LOCK                        1

//--------------------------------------------------------------
// USART TIMEOUT Defines
//--------------------------------------------------------------
#define   USART_TIMEOUT     500000

#define sendData(args)  (Serial3.write(args))
#define availableData() (Serial3.available())
#define readData()      (Serial3.read())
#define peekData()      (Serial3.peek())
#define beginCom(args)  (Serial3.begin(args))
#define endCom()        (Serial3.end())

#include <inttypes.h>

unsigned char Checksum;
unsigned char Direction_Pin;
unsigned char Time_Counter;
unsigned char Incoming_Byte;
unsigned char Position_High_Byte;
unsigned char Position_Low_Byte;
unsigned char Speed_High_Byte;
unsigned char Speed_Low_Byte;
unsigned char Load_High_Byte;
unsigned char Load_Low_Byte;

extern unsigned char DataBuffer[255];
extern int JumlahData_RT;

int Moving_Byte;
int RWS_Byte;
int Speed_Long_Byte;
int Load_Long_Byte;
int Position_Long_Byte;
int Temperature_Byte;
int Voltage_Byte;
int Error_Byte;
extern int DX_count;
int pos_array[18];
int speed_array[18];

unsigned int DynamixelPos[18];
extern const uint8_t Dynamixel_Pin[];

// DYNAMIXEL SYNCWRITE
unsigned int bufferDataTx[98];
unsigned int jumlahData;
int outServo[18];
int move[18];
int gerak[18];
extern unsigned int GERAK;

int16_t USART_TimeOut(int16_t VALUE);
int Dyna_Actuate(unsigned char Dyna_ID, unsigned int Angle, unsigned int Speed, unsigned int TX_DELAY_TIME);
void Dynamixel_USART2_Init(uint32_t DYNAMIXEL_BAUDRATE);
void Dynamx_Send(USART_TypeDef* USARTx, int DATA);
void Start_Pose_SYNC(void);
void Lock_EEPROM(unsigned char Dyna_ID);
void SetMaxTorque(unsigned char Dyna_ID);
void Data_Send(int JumlahData);
void Dyna_Slope(unsigned char ID, unsigned char cw_slope, unsigned char ccw_slope);
void setPunch(unsigned char ID, int Punch);
#endif
