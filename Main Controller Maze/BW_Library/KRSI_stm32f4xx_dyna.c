#include "main.h"

//--------------------------------------------------------------------
//Define
//--------------------------------------------------------------------
//#define INTR		// when sending data, interrupt is turned off
//#define PIN_CONTROL // using pin control, for changing RX/TX

//--------------------------------------------------------------------
//Get lower byte
//--------------------------------------------------------------------
char L_Byte(uint16_t Byte)
{
	char Return;
	Return=(Byte & 0x00FF);
	return Return;
}

//--------------------------------------------------------------------
//Get higher byte
//--------------------------------------------------------------------
char H_Byte(uint16_t Byte)
{
	char Return;
	Return=	((Byte>>8) & 0x00FF);
	return Return;
}

//--------------------------------------------------------------------
// Set the direction pin
//--------------------------------------------------------------------
// EX : setDirPin(GPIOD,GPIO_Pin_7,GPIO_Mode_IN)
// GPIOx = Port that will be used
// DirPin = Pin that will be used
// Mode = As an input or output
//--------------------------------------------------------------------
//void DirPin_Init()
//{
//	RCC_AHB1PeriphClockCmd(RCC_DirPin, ENABLE);
//	GPIO_InitStructure.GPIO_Pin = PIN_DirPin;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
//	GPIO_Init(GPIO_DirPin, &GPIO_InitStructure);
//}

//--------------------------------------------------------------------
// Move the dynamixel in Joint Mode
//--------------------------------------------------------------------
// EX : Dyna_move(5,512)
// Position : 0-1023 , 0.29 degree
//--------------------------------------------------------------------
void Dyna_move(unsigned char ID, int Position)
{
	//length
	XL_LENGTH_L = L_Byte(XL_GOAL_P_LENGTH);
	XL_LENGTH_H = H_Byte(XL_GOAL_P_LENGTH);
	Packet_Length = XL_GOAL_P_LENGTH;
	//address
	XL_ADDRESS_L = L_Byte(XL_GOAL_POSITION);
	XL_ADDRESS_H = H_Byte(XL_GOAL_POSITION);
	//position
	POS_L = L_Byte(Position);
	POS_H = H_Byte(Position);
	//txpacket
	char DataSend[] = { XL_START1,
						XL_START1,
						XL_START2,
						XL_RESERVED,
						ID,
						XL_LENGTH_L,
						XL_LENGTH_H,
						XL_WRITE_DATA,
						XL_ADDRESS_L,
						XL_ADDRESS_H,
						POS_L,
						POS_H,
						CRC_L,
						CRC_H };
	//CRC
	CRC_X = update_crc (CRC_ACCUM, DataSend , (5+Packet_Length) ) ;
	CRC_L = L_Byte(CRC_X);
	CRC_H = H_Byte(CRC_X);
	//Move data
	DataSend[XL_GOAL_P_LENGTH+5]=CRC_L;
	DataSend[XL_GOAL_P_LENGTH+6]=CRC_H;
	GPIO_SetBits(GPIOC, GPIO_Pin_13);
	//Send Data
	for(count=0;count<(XL_GOAL_P_LENGTH+7);count++)
	{
		Dynamx_Send(USART2, DataSend[count]);
	}
	delay_us(150);
	GPIO_ResetBits(GPIOC, GPIO_Pin_13);
//	Delayms(time);
}

//--------------------------------------------------------------------
// Move the dynamixel with speed in Joint Mode
//--------------------------------------------------------------------
// EX : Dyna_movespeed(5,512,500)
// Position : 0-1023
// Speed 	: 0-1023 for CCW
//			  1024-2047 for CW
//			  The unit is about 0.111 rpm
//			  500 -> moving to the CCW direction at a rate of about 55.5 rpm
//--------------------------------------------------------------------
void Dyna_movespeed(unsigned char ID, int Angle,int Speed, int delay_time)
{
	int Position;

	Position= Angle*1024;
	Position= Position/300;

	if(Position!=0) {Position-=1;}

	//length
	XL_LENGTH_L = L_Byte(XL_GOAL_SP_LENGTH);
	XL_LENGTH_H = H_Byte(XL_GOAL_SP_LENGTH);
	Packet_Length = XL_GOAL_SP_LENGTH;
	//address
	XL_ADDRESS_L = L_Byte(XL_GOAL_POSITION);
	XL_ADDRESS_H = H_Byte(XL_GOAL_POSITION);
	//position
	POS_L = L_Byte(Position);
	POS_H = H_Byte(Position);
	//speed
	SPEED_L = L_Byte(Speed);
	SPEED_H = H_Byte(Speed);
	//txpacket
	unsigned char DataSend[] = { XL_START1,
							     XL_START1,
							     XL_START2,
							     XL_RESERVED,
							     ID,
							     XL_LENGTH_L,
							     XL_LENGTH_H,
							     XL_WRITE_DATA,
							     XL_ADDRESS_L,
							     XL_ADDRESS_H,
							     POS_L,
						         POS_H,
							     SPEED_L,
							     SPEED_H,
							     CRC_L,
							     CRC_H };
	//CRC
	CRC_X = update_crc (CRC_ACCUM, DataSend , (5+Packet_Length) ) ;
	CRC_L = L_Byte(CRC_X);
	CRC_H = H_Byte(CRC_X);
	//Move data
	DataSend[XL_GOAL_SP_LENGTH+5]=CRC_L;
	DataSend[XL_GOAL_SP_LENGTH+6]=CRC_H;
	GPIO_SetBits(GPIOC, GPIO_Pin_13);
	//Send Data
	for(count=0;count<(XL_GOAL_SP_LENGTH+7);count++)
	{
	Dynamx_Send(USART2, DataSend[count]);
	}
	delay_us(700/delay_time);
	GPIO_ResetBits(GPIOC, GPIO_Pin_13);
}

//--------------------------------------------------------------------
// Move the dynamixel with speed in Wheel Mode
//--------------------------------------------------------------------
// EX : Dyna_movewheel(5,512)
// Speed 	: 0-1023 for CCW
//			  1024-2047 for CW
//			  The unit is about 0.1% torque
//			  512 -> the torque is controlled by 50% of the maximum torque to the CCW direction
//--------------------------------------------------------------------
void Dyna_movewheel(unsigned char ID, int Speed)
{
	//length
	XL_LENGTH_L = L_Byte(XL_GOAL_S_LENGTH);
	XL_LENGTH_H = H_Byte(XL_GOAL_S_LENGTH);
	Packet_Length = XL_GOAL_S_LENGTH;
	//address
	XL_ADDRESS_L = L_Byte(XL_GOAL_SPEED);
	XL_ADDRESS_H = H_Byte(XL_GOAL_SPEED);
	//speed
	SPEED_L = L_Byte(Speed);
	SPEED_H = H_Byte(Speed);
	//txpacket
	unsigned char DataSend[] = { XL_START1,
							     XL_START1,
							     XL_START2,
							     XL_RESERVED,
							     ID,
							     XL_LENGTH_L,
							     XL_LENGTH_H,
							     XL_WRITE_DATA,
							     XL_ADDRESS_L,
							     XL_ADDRESS_H,
							     SPEED_L,
							     SPEED_H,
							     CRC_L,
							     CRC_H };
	//CRC
	CRC_X = update_crc (CRC_ACCUM, DataSend , (5+Packet_Length) ) ;
	CRC_L = L_Byte(CRC_X);
	CRC_H = H_Byte(CRC_X);
	//Move data
	DataSend[XL_GOAL_S_LENGTH+5]=CRC_L;
	DataSend[XL_GOAL_S_LENGTH+6]=CRC_H;
	//Send Data
	for(count=0;count<(XL_GOAL_S_LENGTH+7);count++)
	{
	Dynamx_Send(USART2, DataSend[count]);
	}
	delay_us(150);
}

//--------------------------------------------------------------------
// Change the ID of the dynamixel
//--------------------------------------------------------------------
// EX : Dyna_setID(1,2)
// ID : 0-252
// Broadcast ID : 254
//--------------------------------------------------------------------
void Dyna_setID(unsigned char ID, unsigned char newID)
{
	//length
	XL_LENGTH_L = L_Byte(XL_ID_LENGTH);
	XL_LENGTH_H = H_Byte(XL_ID_LENGTH);
	Packet_Length=XL_ID_LENGTH;
	//address
	XL_ADDRESS_L = L_Byte(XL_ID);
	XL_ADDRESS_H = H_Byte(XL_ID);
	//txpacket
	unsigned char DataSend[] = { XL_START1,
							     XL_START1,
							     XL_START2,
							     XL_RESERVED,
							     ID,
							     XL_LENGTH_L,
							     XL_LENGTH_H,
							     XL_WRITE_DATA,
							     XL_ADDRESS_L,
							     XL_ADDRESS_H,
							     newID,
							     CRC_L,
							     CRC_H };
	//CRC
	CRC_X = update_crc (CRC_ACCUM, DataSend , (5+Packet_Length) ) ;
	CRC_L = L_Byte(CRC_X);
	CRC_H = H_Byte(CRC_X);
	//Move data
	DataSend[XL_ID_LENGTH+5]=CRC_L;
	DataSend[XL_ID_LENGTH+6]=CRC_H;
	//Send Data
	for(count=0;count<(XL_ID_LENGTH+7);count++)
	{
	Dynamx_Send(USART2, DataSend[count]);
	}
	delay_us(150);
}

//--------------------------------------------------------------------
// Change the mode of dynamixel
//--------------------------------------------------------------------
// EX : Dyna_setMode(5,WHEEL_MODE)
// WHEEL_MODE : spin infinitely
// JOINT_MODE : controlled with specific angles
//--------------------------------------------------------------------
void Dyna_setmode(unsigned char ID, unsigned char Mode)
{
	//length
	XL_LENGTH_L = L_Byte(XL_MODE_LENGTH);
	XL_LENGTH_H = H_Byte(XL_MODE_LENGTH);
	Packet_Length = XL_MODE_LENGTH;
	//address
	XL_ADDRESS_L = L_Byte(XL_CONTROL_MODE);
	XL_ADDRESS_H = H_Byte(XL_CONTROL_MODE);
	//txpacket
	unsigned char DataSend[] = { XL_START1,
								 XL_START1,
							     XL_START2,
							     XL_RESERVED,
							     ID,
							     XL_LENGTH_L,
							     XL_LENGTH_H,
							     XL_WRITE_DATA,
							     XL_ADDRESS_L,
							     XL_ADDRESS_H,
							     Mode,
							     CRC_L,
							     CRC_H };
	//CRC
	CRC_X = update_crc (CRC_ACCUM, DataSend , (5+Packet_Length) ) ;
	CRC_L = L_Byte(CRC_X);
	CRC_H = H_Byte(CRC_X);
	//Move data
	DataSend[XL_MODE_LENGTH+5]=CRC_L;
	DataSend[XL_MODE_LENGTH+6]=CRC_H;
	//Send Data
	for(count=0;count<(XL_MODE_LENGTH+7);count++)
	{
	Dynamx_Send(USART2, DataSend[count]);
	}
	delay_us(150);
}

//--------------------------------------------------------------------
// Change the dynamixel return delay time
//--------------------------------------------------------------------
// EX : Dyna_delaytime(5,1)
// delaytime 0-254
//--------------------------------------------------------------------
void Dyna_delaytime(unsigned char ID, unsigned char delaytime)
{
	//length
	XL_LENGTH_L = L_Byte(XL_DELAYTIME_LENGTH);
	XL_LENGTH_H = H_Byte(XL_DELAYTIME_LENGTH);
	Packet_Length = XL_DELAYTIME_LENGTH;
	//address
	XL_ADDRESS_L = L_Byte(XL_RETURN_DELAY_TIME);
	XL_ADDRESS_H = H_Byte(XL_RETURN_DELAY_TIME);
	//txpacket
	unsigned char DataSend[] = { XL_START1,
								 XL_START1,
								 XL_START2,
								 XL_RESERVED,
								 ID,
								 XL_LENGTH_L,
								 XL_LENGTH_H,
								 XL_WRITE_DATA,
								 XL_ADDRESS_L,
								 XL_ADDRESS_H,
								 delaytime,
								 CRC_L,
								 CRC_H };
	//CRC
	CRC_X = update_crc (CRC_ACCUM, DataSend , (5+Packet_Length) ) ;
	CRC_L = L_Byte(CRC_X);
	CRC_H = H_Byte(CRC_X);
	//Move data
	DataSend[XL_DELAYTIME_LENGTH+5]=CRC_L;
	DataSend[XL_DELAYTIME_LENGTH+6]=CRC_H;
	//Send Data
	for(count=0;count<(XL_DELAYTIME_LENGTH+7);count++)
	{
	Dynamx_Send(USART2, DataSend[count]);
	}
	delay_us(150);
}

//--------------------------------------------------------------------
// Change the baudrate of the dynamixel
//--------------------------------------------------------------------
// EX : Dyna_baudrate(5,0)
// 0 : 9600
// 1 : 57600
// 2 : 115200
// 3 : 1000000
//--------------------------------------------------------------------
//void Dyna_baudrate(unsigned char ID, unsigned char baudrate)
//{
//	//length
//	XL_LENGTH_L = L_Byte(XL_BAUDRATE_LENGTH);
//	XL_LENGTH_H = H_Byte(XL_BAUDRATE_LENGTH);
//	Packet_Length = XL_BAUDRATE_LENGTH;
//	//address
//	XL_ADDRESS_L = L_Byte(XL_BAUDRATE);
//	XL_ADDRESS_H = H_Byte(XL_BAUDRATE);
//	//txpacket
//	unsigned char DataSend[] = { XL_START1,
//								 XL_START1,
//								 XL_START2,
//								 XL_RESERVED,
//								 ID,
//								 XL_LENGTH_L,
//								 XL_LENGTH_H,
//								 XL_WRITE_DATA,
//								 XL_ADDRESS_L,
//								 XL_ADDRESS_H,
//								 baudrate,
//								 CRC_L,
//								 CRC_H };
//	//CRC
//	CRC_X = update_crc (CRC_ACCUM, DataSend , (5+Packet_Length) ) ;
//	CRC_L = L_Byte(CRC_X);
//	CRC_H = H_Byte(CRC_X);
//	//Move data
//	DataSend[XL_BAUDRATE_LENGTH+5]=CRC_L;
//	DataSend[XL_BAUDRATE_LENGTH+6]=CRC_H;
//	//Send Data
//	for(count=0;count<(XL_BAUDRATE_LENGTH+7);count++)
//	{
//	Dynamx_Send(DYNAMIXEL, DataSend[count]);
//	}
//	delay_us(150);
//}

//--------------------------------------------------------------------
// Reset the dynamixel to factory setting
//--------------------------------------------------------------------
//void Dyna_reset(unsigned char ID)
//{
//	//length
//	XL_LENGTH_L = L_Byte(XL_RESET_LENGTH);
//	XL_LENGTH_H = H_Byte(XL_RESET_LENGTH);
//	Packet_Length = XL_RESET_LENGTH;
//	//txpacket
//	unsigned char DataSend[] = { XL_START1,
//								 XL_START1,
//								 XL_START2,
//								 XL_RESERVED,
//								 ID,
//								 XL_LENGTH_L,
//								 XL_LENGTH_H,
//								 XL_RESET,
//								 0x02,
//								 CRC_L,
//								 CRC_H };
//	//CRC
//	CRC_X = update_crc (CRC_ACCUM, DataSend , (5+Packet_Length) ) ;
//	CRC_L = L_Byte(CRC_X);
//	CRC_H = H_Byte(CRC_X);
//	//Move data
//	DataSend[XL_RESET_LENGTH+5]=CRC_L;
//	DataSend[XL_RESET_LENGTH+6]=CRC_H;
//	//Send Data
//	for(count=0;count<(XL_RESET_LENGTH+7);count++)
//	{
//	Dynamx_Send(DYNAMIXEL, DataSend[count]);
//	}
//	delay_us(150);
//}

//--------------------------------------------------------------------
// Get the CRC value
//--------------------------------------------------------------------
unsigned short update_crc(unsigned short crc_accum, unsigned char *data_blk_ptr, unsigned short data_blk_size)
{
	unsigned short i, j;
	unsigned short crc_table[256] = {0x0000,
	                                0x8005, 0x800F, 0x000A, 0x801B, 0x001E, 0x0014, 0x8011,
	                                0x8033, 0x0036, 0x003C, 0x8039, 0x0028, 0x802D, 0x8027,
	                                0x0022, 0x8063, 0x0066, 0x006C, 0x8069, 0x0078, 0x807D,
	                                0x8077, 0x0072, 0x0050, 0x8055, 0x805F, 0x005A, 0x804B,
	                                0x004E, 0x0044, 0x8041, 0x80C3, 0x00C6, 0x00CC, 0x80C9,
	                                0x00D8, 0x80DD, 0x80D7, 0x00D2, 0x00F0, 0x80F5, 0x80FF,
	                                0x00FA, 0x80EB, 0x00EE, 0x00E4, 0x80E1, 0x00A0, 0x80A5,
	                                0x80AF, 0x00AA, 0x80BB, 0x00BE, 0x00B4, 0x80B1, 0x8093,
	                                0x0096, 0x009C, 0x8099, 0x0088, 0x808D, 0x8087, 0x0082,
	                                0x8183, 0x0186, 0x018C, 0x8189, 0x0198, 0x819D, 0x8197,
	                                0x0192, 0x01B0, 0x81B5, 0x81BF, 0x01BA, 0x81AB, 0x01AE,
	                                0x01A4, 0x81A1, 0x01E0, 0x81E5, 0x81EF, 0x01EA, 0x81FB,
	                                0x01FE, 0x01F4, 0x81F1, 0x81D3, 0x01D6, 0x01DC, 0x81D9,
	                                0x01C8, 0x81CD, 0x81C7, 0x01C2, 0x0140, 0x8145, 0x814F,
	                                0x014A, 0x815B, 0x015E, 0x0154, 0x8151, 0x8173, 0x0176,
	                                0x017C, 0x8179, 0x0168, 0x816D, 0x8167, 0x0162, 0x8123,
	                                0x0126, 0x012C, 0x8129, 0x0138, 0x813D, 0x8137, 0x0132,
	                                0x0110, 0x8115, 0x811F, 0x011A, 0x810B, 0x010E, 0x0104,
	                                0x8101, 0x8303, 0x0306, 0x030C, 0x8309, 0x0318, 0x831D,
	                                0x8317, 0x0312, 0x0330, 0x8335, 0x833F, 0x033A, 0x832B,
	                                0x032E, 0x0324, 0x8321, 0x0360, 0x8365, 0x836F, 0x036A,
	                                0x837B, 0x037E, 0x0374, 0x8371, 0x8353, 0x0356, 0x035C,
	                                0x8359, 0x0348, 0x834D, 0x8347, 0x0342, 0x03C0, 0x83C5,
	                                0x83CF, 0x03CA, 0x83DB, 0x03DE, 0x03D4, 0x83D1, 0x83F3,
	                                0x03F6, 0x03FC, 0x83F9, 0x03E8, 0x83ED, 0x83E7, 0x03E2,
	                                0x83A3, 0x03A6, 0x03AC, 0x83A9, 0x03B8, 0x83BD, 0x83B7,
	                                0x03B2, 0x0390, 0x8395, 0x839F, 0x039A, 0x838B, 0x038E,
	                                0x0384, 0x8381, 0x0280, 0x8285, 0x828F, 0x028A, 0x829B,
	                                0x029E, 0x0294, 0x8291, 0x82B3, 0x02B6, 0x02BC, 0x82B9,
	                                0x02A8, 0x82AD, 0x82A7, 0x02A2, 0x82E3, 0x02E6, 0x02EC,
	                                0x82E9, 0x02F8, 0x82FD, 0x82F7, 0x02F2, 0x02D0, 0x82D5,
	                                0x82DF, 0x02DA, 0x82CB, 0x02CE, 0x02C4, 0x82C1, 0x8243,
	                                0x0246, 0x024C, 0x8249, 0x0258, 0x825D, 0x8257, 0x0252,
	                                0x0270, 0x8275, 0x827F, 0x027A, 0x826B, 0x026E, 0x0264,
	                                0x8261, 0x0220, 0x8225, 0x822F, 0x022A, 0x823B, 0x023E,
	                                0x0234, 0x8231, 0x8213, 0x0216, 0x021C, 0x8219, 0x0208,
	                                0x820D, 0x8207, 0x0202 };

	for(j = 0; j < data_blk_size; j++)
	{
		i = ((unsigned short)(crc_accum >> 8) ^ *data_blk_ptr++) & 0xFF;
		crc_accum = (crc_accum << 8) ^ crc_table[i];
	}

	return crc_accum;
}
