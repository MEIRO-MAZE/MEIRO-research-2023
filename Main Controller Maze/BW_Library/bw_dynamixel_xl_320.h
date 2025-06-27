#include "main.h"

#ifndef BW_DYNAMIXEL_XL_320_H
#define BW_DYNAMIXEL_XL_320_H

/*
 * INSTRUCTION PACKET STRUCTURE
 *
 * [HEADER] [RESERVED] [ID] [PACKET_LENGTH] [INSTRUCTION] [PARAMETER] [16BIT CRC]
 * HEADER       : 0xFF 0xFF 0xFD   	// FIELD INDICATING START OF PACKET
 * RESERVED     : 0x00             	// RESERVED (CANNOT USE 0xFD)
 * ID           :					// Dynamixel ID designated for instruction packet processing
 * 									// Value Range: 0 ~ 255 (0x00 ~ 0xFC) 253 unique value
 * 									// 253(0xFD), 255(0xFF) in Header prohibited use
 * 									// 254(0xFE): broadcast ID, ALL connected Dynamixels controlled by instruction packet
 * PACKET LENGTH: LEN_L LEN_H       // Packet length after packet length field
 * 									// [instruction][parameter][CRC_L][CRC_H], Parameter length+3
 * INSTRUCTION  : INST				// Individual packet's command field
 * PARAMETER    : PARAM_1 ... PARAM_N //Used when auxiliary data is required. Depends on the instruction
 * 16BIT CRC    : CRC_L CRC_H         // CRC-16 values can be used against packet communications to check for damages on data
 */


/*
 * DYNAMIXEL XL-320 INSTRUCTION COMMAND
 */

#define HEADER_A 0xFF
#define HEADER_B 0xFF
#define HEADER_C 0xFD
#define RESERVED 0x00
#define DYNAMIXEL_ID 0x01

//unsigned int HEADER_A     = 0xFF;
//unsigned int HEADER_B     = 0xFF;
//unsigned int HEADER_C     = 0xFD;
//unsigned int RESERVED     = 0x00;
//unsigned int DYNAMIXEL_ID = 0x01;


/*
 * DYNAMIXEL XL-320 INDIVIDUAL PACKET COMMAND
 */
#define PING        	0x01 //Corresponding device ID command to check if packet reaches
#define READ  			0x02 //Data read command
#define WRITE 			0x03 //Data write command
#define REG_WRITE 		0x04 //When receiving a write command packet data is not immediately written instead it goes into standby momentarily until action command arrives
#define ACTION        	0x05 //Go command for REG_WRITE
#define FACTORY_RESET 	0x06 //All data to factory default settings
#define REBOOT 			0x08 //Reboot device
#define STATUS 			0x55 //Instruction packet response
#define SYNC_READ 		0x82 //Read data from the same location and same size for multiple devices simultaneously
#define SYNC_WRITE 		0x83 //Write data from the same size for multiple devices simultaneously
#define BULK_READ  		0x92 // Read data from the different locations and different sizes for multiple devices simultaneously
#define BULK_WRITE 		0x93 // Write data from the different locations and different sizes for multiple devices simultaneously


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

int Moving_Byte;
int RWS_Byte;
int Speed_Long_Byte;
int Load_Long_Byte;
int Position_Long_Byte;
int Temperature_Byte;
int Voltage_Byte;
int Error_Byte;

/*
 * FUNCTION PROTOTYPE
 */
unsigned short update_crc(unsigned short crc_accum, unsigned char *data_blk_ptr, unsigned short data_blk_size);

#endif
