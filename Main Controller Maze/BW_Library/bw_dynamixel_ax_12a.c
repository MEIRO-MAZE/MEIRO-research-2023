/*==============================================================================================
								  PROJECT YUME 3.17 Ver.1.0
								  YUME DYNAMIXEL AX-12A
==============================================================================================*/

#include "bw_dynamixel_ax_12a.h"

void Dynamixel_USART2_Init(uint32_t DYNAMIXEL_BAUDRATE)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;  // Pins 2 (TX) and 3 (RX) are used
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF; 			// the pins are configured as alternate function so the USART peripheral has access to them
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		// this defines the IO speed and has nothing to do with the baudrate!
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			// this defines the output type as push pull mode (as opposed to open drain)
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			// this activates the pullup resistors on the IO pins
	GPIO_Init(GPIOA, &GPIO_InitStructure);					// now all the values are passed to the GPIO_Init() function which sets the GPIO registers

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2); //
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);

	USART_InitStructure.USART_BaudRate = DYNAMIXEL_BAUDRATE;				// the baudrate is set to the value we passed into this init function
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;// we want the data frame size to be 8 bits (standard)
	USART_InitStructure.USART_StopBits = USART_StopBits_1;		// we want 1 stop bit (standard)
	USART_InitStructure.USART_Parity = USART_Parity_No;		// we don't want a parity bit (standard)
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // we don't want flow control (standard)
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx; // we want to enable the transmitter and the receiver
	USART_Init(USART2, &USART_InitStructure);					// again all the properties are passed to the USART_Init function which takes care of all the bit setting

	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE); // enable the USART1 Send interrupt

	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;		 // we want to configure the USART3 interrupts
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;// this sets the priority group of the USART3 interrupts
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;		 // this sets the subpriority inside the group
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			 // the USART3 interrupts are globally enabled
	NVIC_Init(&NVIC_InitStructure);							 // the properties are passed to the NVIC_Init function which takes care of the low level stuff

	// finally this enables the complete USART2 peripheral
	USART_Cmd(USART2, ENABLE);

}

int16_t USART_TimeOut(int16_t VALUE)
{
	int16_t RetVal= VALUE;

// USART De-Init
	USART_DeInit(USART6);

//	USART Re-Init
	Dynamixel_USART2_Init(1000000);

	return(RetVal);
}

// Send USART
void Dynamx_Send(USART_TypeDef* USARTx, int DATA)
{
  uint32_t TimeOut= USART_TIMEOUT;
  USART_ClearFlag(USARTx,USART_FLAG_TXE);

  TimeOut = USART_TIMEOUT;
  while(USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET)
  {
    if(TimeOut!=0) TimeOut--;
    else
    {
    	lcd_display_clear();
    	lcd_gotoxy(0,0);sprintf(lcd,"USART TIMEOUT");lcd_putstr(lcd);
    	return (USART_TimeOut(-1));
    	break;
    }
  }// Wait empty
  USART_SendData(USARTx, DATA); // Send char
  TimeOut = USART_TIMEOUT;
  while(USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET)
  {
	   if(TimeOut!=0) TimeOut--;
	    else
	    {
	    	lcd_display_clear();
	    	lcd_gotoxy(0,0);sprintf(lcd,"USART TIMEOUT");lcd_putstr(lcd);
	    	return (USART_TimeOut(-1));
	    	break;
	    }
  }
}

void Dynamixel_Pin_Config(void)
{
	RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_GPIOC, ENABLE);
	GPIO_InitStructure.GPIO_Pin 	= GPIO_Pin_1 ;
	GPIO_InitStructure.GPIO_Mode 	= GPIO_Mode_OUT;       	// Pin ini memiliki Mode Ouput
	GPIO_InitStructure.GPIO_Speed 	= GPIO_Speed_50MHz; 	// kecepatan clock(2, 25, 50 or 100 MHz)
	GPIO_InitStructure.GPIO_PuPd 	= GPIO_PuPd_NOPULL; 	// pin tidak diberikan pull up
	GPIO_Init(GPIOC, &GPIO_InitStructure); 	// inisialisasi periperal GPIO sesuai parameter typdef diatas
}
//*******************************Dynamixel*************************************//
int Dynamixel_moveSpeed(unsigned char ID, int Position, unsigned int Speed, unsigned int TX_DELAY_TIME)
{
    char Position_H,Position_L,Speed_H,Speed_L;
    Position_H = Position >> 8;
    Position_L = Position;                // 16 bits - 2 x 8 bits variables
    Speed_H = Speed >> 8;
    Speed_L = Speed;                      // 16 bits - 2 x 8 bits variables
    Checksum = (~(ID + AX_GOAL_SP_LENGTH + AX_WRITE_DATA + AX_GOAL_POSITION_L + Position_L + Position_H + Speed_L + Speed_H))&0xFF;


    GPIO_SetBits(GPIOC, GPIO_Pin_1);
//	lcd_display_clear();
//	lcd_gotoxy(0,3);sprintf(lcd,"C1 SETBITS");lcd_putstr(lcd);

    Dynamx_Send(USART6,AX_HEADER); // Send Instructions over Serial
    Dynamx_Send(USART6,AX_HEADER);
    Dynamx_Send(USART6,ID);
    Dynamx_Send(USART6,AX_GOAL_SP_LENGTH);
    Dynamx_Send(USART6,AX_WRITE_DATA);
    Dynamx_Send(USART6,AX_GOAL_POSITION_L);
    Dynamx_Send(USART6,Position_L);
    Dynamx_Send(USART6,Position_H);
    Dynamx_Send(USART6,Speed_L);
    Dynamx_Send(USART6,Speed_H);
    Dynamx_Send(USART6,Checksum);

    delay_ms(TX_DELAY_TIME);

    GPIO_ResetBits(GPIOC, GPIO_Pin_1);

    return -1 ;
}

void Dyna_Slope(unsigned char ID, unsigned char cw_slope, unsigned char ccw_slope)
{
	unsigned char CW_SLOPE = cw_slope;
	unsigned char CCW_SLOPE = ccw_slope;

	Checksum = (~(ID + AX_CS_LENGTH +AX_WRITE_DATA+ AX_CW_COMPLIANCE_SLOPE + CW_SLOPE + AX_CCW_COMPLIANCE_SLOPE + CCW_SLOPE))&0xFF;

	GPIO_SetBits(GPIOC, GPIO_Pin_1);
    Dynamx_Send(USART2,AX_HEADER); // Send Instructions over Serial
    Dynamx_Send(USART2,AX_HEADER);
    Dynamx_Send(USART2,ID);
    Dynamx_Send(USART2,AX_CS_LENGTH);
    Dynamx_Send(USART2,AX_WRITE_DATA);
    Dynamx_Send(USART2,AX_CW_COMPLIANCE_SLOPE);
    Dynamx_Send(USART2,CW_SLOPE);
    Dynamx_Send(USART2,AX_CCW_COMPLIANCE_SLOPE);
    Dynamx_Send(USART2,CCW_SLOPE);
    Dynamx_Send(USART2,Checksum);

    delay_us(10);
}

void setPunch(unsigned char ID, int Punch)
{
    char Punch_H,Punch_L;
    Punch_H = Punch >> 8;           // 16 bits - 2 x 8 bits variables
    Punch_L = Punch;
	Checksum = (~(ID + AX_PUNCH_LENGTH + AX_WRITE_DATA + AX_PUNCH_L + Punch_L + Punch_H))&0xFF;

	GPIO_SetBits(GPIOC, GPIO_Pin_1);
    Dynamx_Send(USART2, AX_HEADER);                 // Send Instructions over Serial
    Dynamx_Send(USART2, AX_HEADER);
    Dynamx_Send(USART2, ID);
    Dynamx_Send(USART2, AX_PUNCH_LENGTH);
    Dynamx_Send(USART2, AX_WRITE_DATA);
    Dynamx_Send(USART2, AX_PUNCH_L);
    Dynamx_Send(USART2, Punch_L);
    Dynamx_Send(USART2, Punch_H);
    Dynamx_Send(USART2, Checksum);
	delay_us(10);
}

int Dyna_Actuate(unsigned char Dyna_ID, unsigned int Angle, unsigned int Speed, unsigned int TX_DELAY_TIME)
{
	int Position;
    char Position_H,Position_L,Speed_H,Speed_L;

    //Convert Angle to position value
    Position= Angle*1024;
    Position= Position/300;
    if(Position!=0) {Position-=1;}

    //Break 16 Bit value to two variables of 8 bit each
    Position_H = Position >> 8;
    Position_L = Position;

    //Break 16 Bit value to two variables of 8 bit each
    Speed_H = Speed >> 8;
    Speed_L = Speed;

    Checksum = (~(Dyna_ID + AX_GOAL_SP_LENGTH + AX_WRITE_DATA + AX_GOAL_POSITION_L + Position_L + Position_H + Speed_L + Speed_H))&0xFF;

    GPIO_SetBits(GPIOC, GPIO_Pin_1);

    Dynamx_Send(USART2,AX_HEADER); // Send Instructions over Serial
    Dynamx_Send(USART2,AX_HEADER);
    Dynamx_Send(USART2,Dyna_ID);
    Dynamx_Send(USART2,AX_GOAL_SP_LENGTH);
    Dynamx_Send(USART2,AX_WRITE_DATA);
    Dynamx_Send(USART2,AX_GOAL_POSITION_L);
    Dynamx_Send(USART2,Position_L);
    Dynamx_Send(USART2,Position_H);
    Dynamx_Send(USART2,Speed_L);
    Dynamx_Send(USART2,Speed_H);
    Dynamx_Send(USART2,Checksum);

    delay_us(TX_DELAY_TIME);

    GPIO_ResetBits(GPIOC, GPIO_Pin_1);

    return -1;
}

void Lock_EEPROM(unsigned char Dyna_ID)
{
	Checksum = (~(Dyna_ID + AX_LED_LENGTH + AX_WRITE_DATA + AX_LOCK + 0x01))&0xFF;

	GPIO_SetBits(GPIOC, GPIO_Pin_1);

    Dynamx_Send(USART2,AX_HEADER); // Send Instructions over Serial
    Dynamx_Send(USART2,AX_HEADER);
    Dynamx_Send(USART2,Dyna_ID);
    Dynamx_Send(USART2,AX_LR_LENGTH);
    Dynamx_Send(USART2,AX_WRITE_DATA);
    Dynamx_Send(USART2,AX_LOCK);
    Dynamx_Send(USART2,0x01);
    Dynamx_Send(USART2,Checksum);
    delay_us(250);

    GPIO_ResetBits(GPIOC, GPIO_Pin_1);
}

void SetMaxTorque(unsigned char Dyna_ID)
{
	int TORQUE = 1023;
    char MaxTorque_H,MaxTorque_L;
    MaxTorque_H = TORQUE >> 8;           // 16 bits - 2 x 8 bits variables
    MaxTorque_L = TORQUE;

	Checksum = (~(Dyna_ID + AX_MT_LENGTH + AX_WRITE_DATA + AX_MAX_TORQUE_L + MaxTorque_L + MaxTorque_H))&0xFF;

	GPIO_SetBits(GPIOC, GPIO_Pin_1);

    Dynamx_Send(USART2,AX_HEADER); // Send Instructions over Serial
    Dynamx_Send(USART2,AX_HEADER);
    Dynamx_Send(USART2,Dyna_ID);
    Dynamx_Send(USART2,AX_MT_LENGTH);
    Dynamx_Send(USART2,AX_WRITE_DATA);
    Dynamx_Send(USART2,AX_MAX_TORQUE_L);
    Dynamx_Send(USART2,MaxTorque_L);
    Dynamx_Send(USART2,MaxTorque_H);
    Dynamx_Send(USART2,Checksum);
    delay_us(250);

    GPIO_ResetBits(GPIOC, GPIO_Pin_1);
}


void Start_Pose_SYNC(void)
{
	int counts_send=0;
	int count_buf=7;
	int Checksum_buf = 0;
	unsigned char Length = 94;
    unsigned char Position_H,Position_L,Speed_H,Speed_L;
    int POS = 671;
    int SPD = 1000;

    GPIO_SetBits(GPIOC, GPIO_Pin_1);
    Dynamx_Send(USART2,AX_HEADER); // Send Instructions over Serial
    Dynamx_Send(USART2,AX_HEADER);
    Dynamx_Send(USART2,BROADCAST_ID);
    Dynamx_Send(USART2,Length);
    Dynamx_Send(USART2,SYNC_WRITE);
    Dynamx_Send(USART2,AX_GOAL_POSITION_L);
    Dynamx_Send(USART2,4);
    while(counts_send <= 17)
    {
        Position_H = pos_array[counts_send] >> 8;
        Position_L = pos_array[counts_send]&0xFF;

        Speed_H = speed_array[counts_send] >> 8;
        Speed_L = speed_array[counts_send]&0xFF;

    	Dynamx_Send(USART2,(char)(counts_send+1));
    	Dynamx_Send(USART2,Position_L);
    	Dynamx_Send(USART2,Position_H);
    	Dynamx_Send(USART2,Speed_L);
    	Dynamx_Send(USART2,Speed_H);

    	Checksum_buf += ((counts_send+1) + (Position_L) + (Position_H) + (Speed_L) + (Speed_H));
    	if(counts_send >= 17)break;
    	counts_send++;
    }
    Checksum = (~(BROADCAST_ID + Length + SYNC_WRITE + AX_GOAL_POSITION_L + Checksum_buf + 4))&0xFF;
    Dynamx_Send(USART2,Checksum);
}

void Data_Send(int JumlahData)
{
	if(JumlahData_RT == 0)
	{
		JumlahData_RT = JumlahData;
		USART_ITConfig(USART2, USART_IT_TXE, ENABLE);
	}
}



void USART2_IRQHandler(void)
{
	GPIO_SetBits(GPIOC, GPIO_Pin_1);
	static int dataKe = 0;
	if (USART_GetITStatus(USART2, USART_IT_TXE) != RESET)
	{
		USART_SendData(USART2,DataBuffer[dataKe]);
		dataKe++;
		if(dataKe >= JumlahData_RT + 1)
		{
			JumlahData_RT = 0;
			dataKe = 0;
			USART_ITConfig(USART2, USART_IT_TXE, DISABLE);
		}
	}
}

