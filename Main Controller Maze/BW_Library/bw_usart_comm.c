#include "bw_usart_comm.h"

/*
void UART4_Init_Flame(uint32_t baudrate)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4,ENABLE);

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;  // Pins 6 (TX) and 7 (RX) are used
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF; 			// the pins are configured as alternate function so the USART peripheral has access to them
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		// this defines the IO speed and has nothing to do with the baudrate!
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			// this defines the output type as push pull mode (as opposed to open drain)
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			// this activates the pullup resistors on the IO pins
	GPIO_Init(GPIOC, &GPIO_InitStructure);					// now all the values are passed to the GPIO_Init() function which sets the GPIO registers

	GPIO_PinAFConfig(GPIOC, GPIO_PinSource10, GPIO_AF_UART4);
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource11, GPIO_AF_UART4);

	USART_InitStructure.USART_BaudRate = baudrate;				// the baudrate is set to the value we passed into this init function
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;// we want the data frame size to be 8 bits (standard)
	USART_InitStructure.USART_StopBits = USART_StopBits_1;		// we want 1 stop bit (standard)
	USART_InitStructure.USART_Parity = USART_Parity_No;		// we don't want a parity bit (standard)
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // we don't want flow control (standard)
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx; // we want to enable the transmitter and the receiver
	USART_Init(UART4, &USART_InitStructure);					// again all the properties are passed to the USART_Init function which takes care of all the bit setting

	USART_ITConfig(UART4, USART_IT_RXNE, ENABLE); // enable the USART1 receive interrupt

	NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn;		 // we want to configure the USART3 interrupts
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;// this sets the priority group of the USART3 interrupts
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;		 // this sets the subpriority inside the group
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			 // the USART3 interrupts are globally enabled
	NVIC_Init(&NVIC_InitStructure);							 // the properties are passed to the NVIC_Init function which takes care of the low level stuff

	// finally this enables the complete USART6 peripheral
	USART_Cmd(UART4, ENABLE);
}
*/
//void USART6_Init_Flame(uint32_t baudrate)
//{
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART6,ENABLE);
//
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
//
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;  // Pins 6 (TX) and 7 (RX) are used
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF; 			// the pins are configured as alternate function so the USART peripheral has access to them
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		// this defines the IO speed and has nothing to do with the baudrate!
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			// this defines the output type as push pull mode (as opposed to open drain)
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			// this activates the pullup resistors on the IO pins
//	GPIO_Init(GPIOC, &GPIO_InitStructure);					// now all the values are passed to the GPIO_Init() function which sets the GPIO registers
//
//	GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_USART6);
//	GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_USART6);
//
//	USART_InitStructure.USART_BaudRate = baudrate;				// the baudrate is set to the value we passed into this init function
//	USART_InitStructure.USART_WordLength = USART_WordLength_8b;// we want the data frame size to be 8 bits (standard)
//	USART_InitStructure.USART_StopBits = USART_StopBits_1;		// we want 1 stop bit (standard)
//	USART_InitStructure.USART_Parity = USART_Parity_No;		// we don't want a parity bit (standard)
//	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // we don't want flow control (standard)
//	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx; // we want to enable the transmitter and the receiver
//	USART_Init(USART6, &USART_InitStructure);					// again all the properties are passed to the USART_Init function which takes care of all the bit setting
//
//	USART_ITConfig(USART6, USART_IT_RXNE, ENABLE); // enable the USART1 receive interrupt
//
//	NVIC_InitStructure.NVIC_IRQChannel = USART6_IRQn;		 // we want to configure the USART3 interrupts
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;// this sets the priority group of the USART3 interrupts
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;		 // this sets the subpriority inside the group
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			 // the USART6 interrupts are globally enabled
//	NVIC_Init(&NVIC_InitStructure);							 // the properties are passed to the NVIC_Init function which takes care of the low level stuff
//
//	// finally this enables the complete USART6 peripheral
//	USART_Cmd(USART6, ENABLE);
//}

void USARTX_Init(void){
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4,ENABLE);
//
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
//
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;  // Pins 6 (TX) and 7 (RX) are used
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF; 			// the pins are configured as alternate function so the USART peripheral has access to them
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		// this defines the IO speed and has nothing to do with the baudrate!
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			// this defines the output type as push pull mode (as opposed to open drain)
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			// this activates the pullup resistors on the IO pins
//	GPIO_Init(GPIOC, &GPIO_InitStructure);					// now all the values are passed to the GPIO_Init() function which sets the GPIO registers
//
//	GPIO_PinAFConfig(GPIOC, GPIO_PinSource10, GPIO_AF_UART4);
//	GPIO_PinAFConfig(GPIOC, GPIO_PinSource11, GPIO_AF_UART4);
//
//	USART_InitStructure.USART_BaudRate = baudrate;				// the baudrate is set to the value we passed into this init function
//	USART_InitStructure.USART_WordLength = USART_WordLength_8b;// we want the data frame size to be 8 bits (standard)
//	USART_InitStructure.USART_StopBits = USART_StopBits_1;		// we want 1 stop bit (standard)
//	USART_InitStructure.USART_Parity = USART_Parity_No;		// we don't want a parity bit (standard)
//	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // we don't want flow control (standard)
//	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx; // we want to enable the transmitter and the receiver
//	USART_Init(UART4, &USART_InitStructure);					// again all the properties are passed to the USART_Init function which takes care of all the bit setting
//
//	USART_ITConfig(UART4, USART_IT_RXNE, ENABLE); // enable the USART1 receive interrupt
//
//	NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn;		 // we want to configure the USART3 interrupts
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;// this sets the priority group of the USART3 interrupts
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;		 // this sets the subpriority inside the group
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			 // the USART3 interrupts are globally enabled
//	NVIC_Init(&NVIC_InitStructure);							 // the properties are passed to the NVIC_Init function which takes care of the low level stuff
//
//	// finally this enables the complete USART6 peripheral
//	USART_Cmd(UART4, ENABLE);
}

void USARTX_IRQHandler(void){
//	if( USART_GetITStatus(UART4, USART_IT_RXNE) )
//	{
//		char t = UART4->DR;
//		char static last_data;
//
//		switch(USARTFlameDigi_Counter)
//		{
//			case  1 : VL_SENSOR[0]= UART4->DR; USARTVL_Counter+=63; break;
//		}
//		if(t==COMMAND_FLAG_B && last_data==COMMAND_FLAG_A) USARTVL_Counter=1;
//		last_data=t;
//	}
}
/*
void UART4_IRQHandler(void)
{
	if( USART_GetITStatus(UART4, USART_IT_RXNE) )
	{
		char t = UART4->DR;
		char static last_data;

		switch(USARTFlameDigi_Counter)
		{
			case  1 : FlameSenseDigi[0]= UART4->DR; USARTFlameDigi_Counter+=1; break;
			case  2 : FlameFrontDigi[0]= UART4->DR; USARTFlameDigi_Counter+=1; break;
			case  3 : Flame_Stat = UART4->DR;USARTFlameDigi_Counter+=63;break;
		}
		if(t==COMMAND_FLAG_B && last_data==COMMAND_FLAG_A) USARTFlameDigi_Counter=1;
		last_data=t;
	}
}
*/

/*
void USART6_IRQHandler(void)
{
	if( USART_GetITStatus(USART6, USART_IT_RXNE) )
	{
		char t = USART6->DR;
		char static last_data;

		switch(USARTFlameDigi_Counter)
		{
			case  1 : FlameSenseDigi[0]= USART6->DR; USARTFlameDigi_Counter+=1; break;
			case  2 : FlameFrontDigi[0]= USART6->DR; USARTFlameDigi_Counter+=1; break;
			case  3 : Flame_Stat = USART6->DR;USARTFlameDigi_Counter+=63;break;
		}
		if(t==COMMAND_FLAG_B && last_data==COMMAND_FLAG_A) USARTFlameDigi_Counter=1;
		last_data=t;
	}
}*/

//void USART6_IRQHandler(void)
//{
//	if(USART_GetITStatus(USART6, USART_IT_RXNE))
//	{
////		FlameState = 'B';
//		char inChar = USART6->DR;
//		FlameState = inChar;
//	}
//}


void USART1_Init_Tracer(uint32_t baudrate)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;  // Pins 9 (TX) are used
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF; 			// the pins are configured as alternate function so the USART peripheral has access to them
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		// this defines the IO speed and has nothing to do with the baudrate!
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			// this defines the output type as push pull mode (as opposed to open drain)
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			// this activates the pullup resistors on the IO pins
	GPIO_Init(GPIOB, &GPIO_InitStructure);					// now all the values are passed to the GPIO_Init() function which sets the GPIO registers

	GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_USART1); //TX
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_USART1);//RX

	USART_InitStructure.USART_BaudRate = baudrate;				// the baudrate is set to the value we passed into this init function
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;// we want the data frame size to be 8 bits (standard)
	USART_InitStructure.USART_StopBits = USART_StopBits_1;		// we want 1 stop bit (standard)
	USART_InitStructure.USART_Parity = USART_Parity_No;		// we don't want a parity bit (standard)
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // we don't want flow control (standard)
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx; // we want to enable the transmitter and the receiver
	USART_Init(USART1, &USART_InitStructure);					// again all the properties are passed to the USART_Init function which takes care of all the bit setting

	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE); // enable the USART5 receive interrupt

	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;		 // we want to configure the USART3 interrupts
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;// this sets the priority group of the USART3 interrupts
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;		 // this sets the subpriority inside the group
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			 // the USART3 interrupts are globally enabled
	NVIC_Init(&NVIC_InitStructure);							 // the properties are passed to the NVIC_Init function which takes care of the low level stuff
	// finally this enables the complete USART5 peripheral
	USART_Cmd(USART1, ENABLE);
}


void USART1_IRQHandler(void)
{
	if( USART_GetITStatus(USART1, USART_IT_RXNE) )
	{
		char t = USART1->DR; // the character from the USART3 data register is saved in t
		char static last_data;

		switch(TCS3200_SLV_CNT)
		{
			// FLAG DATA RECIEVED
			case  1 : TCS3200_SLV_BUF[0]= USART1->DR; TCS3200_SLV_CNT+=1; break;

			//TRACER SECTION FRONT_H RECEIVED / TRACER_STAT
			case  2 :
			{
				if(TCS3200_SLV_BUF[0] == STAT_DATA)
				{
					TCS3200_SLV_BUF[1]= USART1->DR; TCS3200_SLV_CNT+=63; break;
				}
				else
				{
					TCS3200_SLV_BUF[1]= USART1->DR; TCS3200_SLV_CNT+=1; break;
				}
			}

			//TRACER SECTION FRONT_L RECEIVED
			case  3 : TCS3200_SLV_BUF[2]= USART1->DR; TCS3200_SLV_CNT+=1; break;

			case  4 : 	{
							//TCS3200 PROCESSOR SENDING RAW VALUE
							if(TCS3200_SLV_BUF[0]==RAW_VAL_FLAG || TCS3200_SLV_BUF[0]==TH_DATA || TCS3200_SLV_BUF[0]==RGB_VAL_FLAG)
							{
								TCS3200_SLV_BUF[3]= USART1->DR; TCS3200_SLV_CNT+=1; break;
							}
							else
							{
								TCS3200_SLV_BUF[3]= USART1->DR; TCS3200_SLV_CNT+=63; break;
							}
						}

			//TRACER SECTION FRONT MID_L RECEIVED
			case  5 : TCS3200_SLV_BUF[4]= USART1->DR; TCS3200_SLV_CNT+=1; break;

			//TRACER SECTION MIDDLE F_H RECEIVED
			case  6 : {

						if(TCS3200_SLV_BUF[0] == RGB_VAL_FLAG || TCS3200_SLV_BUF[0] == TH_DATA)
						{
							TCS3200_SLV_BUF[5]= USART1->DR; TCS3200_SLV_CNT+=1;
						}

						else
						{
							TCS3200_SLV_BUF[5]= USART1->DR; TCS3200_SLV_CNT+=63;
						}

					   }break;

			//TRACER SECTION MIDDLE F_L RECEIVED
			case  7 : TCS3200_SLV_BUF[6]= USART1->DR; TCS3200_SLV_CNT+=1; break;

			//TRACER SECTION MIDDLE R_H RECEIVED
			case  8 : TCS3200_SLV_BUF[7]= USART1->DR; TCS3200_SLV_CNT+=1; break;

			//TRACER SECTION MIDDLE R_L RECEIVED
			case  9 : TCS3200_SLV_BUF[8]= USART1->DR; TCS3200_SLV_CNT+=1; break;

			//TRACER SECTION BACK MID_H RECEIVED
			case  10 : TCS3200_SLV_BUF[9]= USART1->DR; TCS3200_SLV_CNT+=1; break;

			//TRACER SECTION BACK MID_L RECEIVED
			case  11 : TCS3200_SLV_BUF[10]= USART1->DR; TCS3200_SLV_CNT+=1; break;

			//TRACER SECTION BACK_H RECEIVED
			case  12 : TCS3200_SLV_BUF[11]= USART1->DR;	TCS3200_SLV_CNT+=1; break;

			//TRACER SECTION BACK_L RECEIVED
			case  13 : {
				if(TCS3200_SLV_BUF[0] == TH_DATA)
				{
					TCS3200_SLV_BUF[12]= USART1->DR; TCS3200_SLV_CNT+=63;
				}

				else
				{
					TCS3200_SLV_BUF[12]= USART1->DR; TCS3200_SLV_CNT+=1;
				}

			  } break;
//
			//TRACER STAT DATA
			case  14 : TCS3200_SLV_BUF[13]= USART1->DR;	TCS3200_SLV_CNT+=63; break;
		}

		if(t==COMMAND_FLAG_B && last_data==COMMAND_FLAG_A)
			{
				TCS3200_SLV_CNT=1;
				DATA_TRACER_READY = 1;
			}
		last_data=t;

		switch(TCS3200_SLV_BUF[0]) // data processing
		{
			case RAW_VAL_FLAG:
			{
				TCS3200_SLV_DATA[0] = (TCS3200_SLV_BUF[1] << 8 | TCS3200_SLV_BUF[2]);
				TCS3200_SLV_DATA[1] = (TCS3200_SLV_BUF[3] << 8 | TCS3200_SLV_BUF[4]);
				TCS3200_SLV_DATA[2] = (TCS3200_SLV_BUF[5]);
			}break;

			case RGB_VAL_FLAG:
			{
				TCS3200_SLV_DATA[0] = (TCS3200_SLV_BUF[1] << 8 | TCS3200_SLV_BUF[2]);
				TCS3200_SLV_DATA[1] = (TCS3200_SLV_BUF[3] << 8 | TCS3200_SLV_BUF[4]);
				TCS3200_SLV_DATA[2] = (TCS3200_SLV_BUF[5] << 8 | TCS3200_SLV_BUF[6]);
				TCS3200_SLV_DATA[3] = (TCS3200_SLV_BUF[7] << 8 | TCS3200_SLV_BUF[8]);
				TCS3200_SLV_DATA[4] = (TCS3200_SLV_BUF[9] << 8 | TCS3200_SLV_BUF[10]);
				TCS3200_SLV_DATA[5] = (TCS3200_SLV_BUF[11] << 8 | TCS3200_SLV_BUF[12]);
				TCS3200_SLV_DATA[6] = (TCS3200_SLV_BUF[13]);
			}break;

			case STAT_DATA:
			{
				TCS3200_SLV_DATA[1] = TCS3200_SLV_BUF[1];
			}break;

			case TH_DATA:
			{
				TCS3200_SLV_DATA[1] = (TCS3200_SLV_BUF[1] << 8 | TCS3200_SLV_BUF[2]);
				TCS3200_SLV_DATA[2] = (TCS3200_SLV_BUF[3] << 8 | TCS3200_SLV_BUF[4]);
				TCS3200_SLV_DATA[3] = (TCS3200_SLV_BUF[5] << 8 | TCS3200_SLV_BUF[6]);
				TCS3200_SLV_DATA[4] = (TCS3200_SLV_BUF[7] << 8 | TCS3200_SLV_BUF[8]);
				TCS3200_SLV_DATA[5] = (TCS3200_SLV_BUF[9] << 8 | TCS3200_SLV_BUF[10]);
				TCS3200_SLV_DATA[6] = (TCS3200_SLV_BUF[11] << 8 | TCS3200_SLV_BUF[12]);
			}break;
		}


		if	(( (TCS3200_SLV_DATA[1]==TRACER_WHITE) && (TCS3200_SLV_DATA[0]!=COLOUR_WHITE) ) &&(FOLLOWTRACER_FLAG==FOLLOWTRACER_ENABLE)	)
		{
			TRACER_STAT=TRACER_WHITE;
		}
	}
}

void USART6_Init_Tracer_Grip(uint32_t baudrate)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART6,ENABLE);

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;  // Pins 6 (TX) are used
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF; 			// the pins are configured as alternate function so the USART peripheral has access to them
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		// this defines the IO speed and has nothing to do with the baudrate!
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			// this defines the output type as push pull mode (as opposed to open drain)
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			// this activates the pullup resistors on the IO pins
	GPIO_Init(GPIOC, &GPIO_InitStructure);					// now all the values are passed to the GPIO_Init() function which sets the GPIO registers

	GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_USART6); //TX
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_USART6);//RX

	USART_InitStructure.USART_BaudRate = baudrate;				// the baudrate is set to the value we passed into this init function
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;// we want the data frame size to be 8 bits (standard)
	USART_InitStructure.USART_StopBits = USART_StopBits_1;		// we want 1 stop bit (standard)
	USART_InitStructure.USART_Parity = USART_Parity_No;		// we don't want a parity bit (standard)
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // we don't want flow control (standard)
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx; // we want to enable the transmitter and the receiver
	USART_Init(USART6, &USART_InitStructure);					// again all the properties are passed to the USART_Init function which takes care of all the bit setting

	USART_ITConfig(USART6, USART_IT_RXNE, ENABLE); // enable the USART5 receive interrupt

	NVIC_InitStructure.NVIC_IRQChannel = USART6_IRQn;		 // we want to configure the USART6 interrupts
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;// this sets the priority group of the USART3 interrupts
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;		 // this sets the subpriority inside the group
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			 // the USART3 interrupts are globally enabled
	NVIC_Init(&NVIC_InitStructure);							 // the properties are passed to the NVIC_Init function which takes care of the low level stuff
	// finally this enables the complete USART6 peripheral
	USART_Cmd(USART6, ENABLE);
}

void USART6_IRQHandler(void)
{
	if( USART_GetITStatus(USART6, USART_IT_RXNE) )
	{
		char t = USART6->DR; // the character from the USART3 data register is saved in t
		char static last_data;

		switch(TCS34725_SLV_CNT)
		{
			//FLAG DATA RECIEVED
			case  1 : TCS34725_SLV_BUF[0]= USART6->DR; TCS34725_SLV_CNT+=1; break;

			//TRACER SECTION Tracer_front_R_H
			case  2 : TCS34725_SLV_BUF[1]= USART6->DR; TCS34725_SLV_CNT+=1; break;

			//TRACER SECTION Tracer_front_R_L
			case  3 : TCS34725_SLV_BUF[2]= USART6->DR; TCS34725_SLV_CNT+=1; break;

			//TRACER SECTION Tracer_front_G_H
			case  4 : TCS34725_SLV_BUF[3]= USART6->DR; TCS34725_SLV_CNT+=1; break;

			//TRACER SECTION Tracer_front_G_L
			case  5 : TCS34725_SLV_BUF[4]= USART6->DR; TCS34725_SLV_CNT+=1; break;

			//TRACER SECTION Tracer_front_B_H
			case  6 : TCS34725_SLV_BUF[5]= USART6->DR; TCS34725_SLV_CNT+=1; break;

			//TRACER SECTION Tracer_front_B_L
			case  7 : TCS34725_SLV_BUF[6]= USART6->DR; TCS34725_SLV_CNT+=1; break;

			//TRACER STAT DATA
			case  8 : TCS34725_SLV_BUF[13]= USART6->DR;	TCS34725_SLV_CNT+=1; break;

			//VL DATA H
			case  9 : VL_Value[0]= USART6->DR; TCS34725_SLV_CNT+=1;break;

			//VL DATA L
			case  10 : VL_Value[1]= USART6->DR; TCS34725_SLV_CNT+=63;break;

			//SHARP FRONT
//			case 11 : SHARP_FRONT[0] = USART6->DR; TCS34725_SLV_CNT+=63;break;
		}

		if(t==COMMAND_FLAG_B && last_data==COMMAND_FLAG_A)
			{
				TCS34725_SLV_CNT=1;
				DATA_TRACER_GRIP_READY = 1;
			}
		last_data=t;

		//TRACER DATA PROSES
		TCS34725_SLV_DATA[0] = (TCS34725_SLV_BUF[1] << 8 | TCS34725_SLV_BUF[2]);
		TCS34725_SLV_DATA[1] = (TCS34725_SLV_BUF[3] << 8 | TCS34725_SLV_BUF[4]);
		TCS34725_SLV_DATA[2] = (TCS34725_SLV_BUF[5] << 8 | TCS34725_SLV_BUF[6]);
		TCS34725_SLV_DATA[6] = (TCS34725_SLV_BUF[13]);

		VL_SENSOR[0] = (VL_Value[0] << 8 | VL_Value[1]);

	}
}

//fungsi yang dimatikan biar stabil
void Sendto_PC(USART_TypeDef* USARTx, const char *pFormat, ... )
{
//	    va_list ap;
//	    char pStr[100];
//
//	    va_start(ap, pFormat);
//	    vsprintf(pStr, pFormat, ap);
//
//	    int i=0;
//	    va_end(ap);
//	    int n = strlen(pStr);
//	    for(i=0;i<n;i++)
//	    {
//	        USART_SendData(USARTx, (uint8_t)pStr[i]);
//	        while (USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET);
//	    }
}

void TCS3200_Transmit(USART_TypeDef* USARTx, int DATA)
{
	// Langsung Pakai USART1 agar tidak ribet, karena TRANSMIT ada dimana - mana
	// Jika Ganti Pin Langsung Ganti USART1 nya saja

		uint32_t TimeOut= USART_TIMEOUT;
		USART_ClearFlag(USART1,USART_FLAG_TXE);

		TimeOut = USART_TIMEOUT;
		DATA_TRACER_READY = 0;
		while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET)
		{
		    if(TimeOut!=0) TimeOut--;
		    else break;
		}

		USART_SendData(USART1, DATA);
		TimeOut= USART_TIMEOUT;

		while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)
		{
		    if(TimeOut!=0) TimeOut--;
		    else break;
		}
}

void TCS34725_Transmit(USART_TypeDef* USARTx, int DATA)
{
	// Langsung Pakai USART1 agar tidak ribet, karena TRANSMIT ada dimana - mana
	// Jika Ganti Pin Langsung Ganti USART1 nya saja

		uint32_t TimeOut= USART_TIMEOUT;
		USART_ClearFlag(USART6,USART_FLAG_TXE);

		TimeOut = USART_TIMEOUT;
		DATA_TRACER_GRIP_READY = 0;
		while(USART_GetFlagStatus(USART6, USART_FLAG_TXE) == RESET)
		{
		    if(TimeOut!=0) TimeOut--;
		    else break;
		}

		USART_SendData(USART6, DATA);
		TimeOut= USART_TIMEOUT;

		while (USART_GetFlagStatus(USART6, USART_FLAG_TC) == RESET)
		{
		    if(TimeOut!=0) TimeOut--;
		    else break;
		}
}

void Display_FlameSense(void)
{
	Get_UV();
	lcd_display_clear();
	lcd_gotoxy(1,0);sprintf(lcd,"FLAME State: %c",FlameState);lcd_putstr(lcd);
	lcd_gotoxy(0,1);sprintf(lcd,"%c | %c | %c",FlameValueNew[0],FlameValueNew[1],FlameValueNew[2]);lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"%c | %c | %c",FlameValueNew[3],FlameValueNew[4],FlameValueNew[5]);lcd_putstr(lcd);
	lcd_gotoxy(0,3);sprintf(lcd,"UV_state: %d",UV_state);lcd_putstr(lcd);
	delay_ms(100);

//	if( (FlameSense[0]!=0) || (UV_state==0))
//	{
//		FIRE_LED_BLINK_ON;
//
//		if(FlameSense[0]==0)
//		{
//			lcd_display_clear();
//			lcd_gotoxy(1,0);sprintf(lcd,"FLM: %d %d ",FlameSenseDigi[0],FlameFrontDigi[0]);lcd_putstr(lcd);
//			lcd_gotoxy(0,1);sprintf(lcd,"UV_state: %d",UV_state);lcd_putstr(lcd);
//			lcd_gotoxy(0,2);sprintf(lcd,"FLM MALFUNC");lcd_putstr(lcd);
//			lcd_gotoxy(0,3);sprintf(lcd,"FLM_AN: %d",FLAME_SENSOR[FLM_ANALOG]);lcd_putstr(lcd);
//			delay_ms(100);
//		}
//		if(UV_state==1)
//		{
//			lcd_display_clear();
//			lcd_gotoxy(1,0);sprintf(lcd,"FLM: %d %d ",FlameSenseDigi[0],FlameFrontDigi[0]);lcd_putstr(lcd);
//			lcd_gotoxy(0,1);sprintf(lcd,"UV MALFUNC");lcd_putstr(lcd);
//			lcd_gotoxy(0,2);sprintf(lcd,"FlameSense[0]: %d",FlameSense[0]);lcd_putstr(lcd);
//			lcd_gotoxy(0,3);sprintf(lcd,"FLM_AN: %d",FLAME_SENSOR[FLM_ANALOG]);lcd_putstr(lcd);
//			delay_ms(100);
//		}
//		else
//		{
//			lcd_display_clear();
//			lcd_gotoxy(1,0);sprintf(lcd,"FLM: %d %d ",FlameSenseDigi[0],FlameFrontDigi[0]);lcd_putstr(lcd);
//			lcd_gotoxy(0,1);sprintf(lcd,"UV_state: %d",UV_state);lcd_putstr(lcd);
//			lcd_gotoxy(0,2);sprintf(lcd,"FlameSense[0]: %d",FlameSense[0]);lcd_putstr(lcd);
//			lcd_gotoxy(0,3);sprintf(lcd,"FLM_AN: %d",FLAME_SENSOR[FLM_ANALOG]);lcd_putstr(lcd);
//			delay_ms(100);
//
//		}
//	}
//
//	else if(FlameSense[0]==0)
//	{
//		lcd_display_clear();
//		lcd_gotoxy(1,0);sprintf(lcd,"FLM: %d %d ",FlameSenseDigi[0],FlameFrontDigi[0]);lcd_putstr(lcd);
//		lcd_gotoxy(0,1);sprintf(lcd,"UV_state: %d",UV_state);lcd_putstr(lcd);
//		lcd_gotoxy(0,2);sprintf(lcd,"FlameSense[0]: %d",FlameSense[0]);lcd_putstr(lcd);
//		lcd_gotoxy(0,3);sprintf(lcd,"FLM_AN: %d",FLAME_SENSOR[FLM_ANALOG]);lcd_putstr(lcd);
//
//		delay_ms(100);
//
//		FIRE_LED_OFF;
//		FIRE_LED_BLINK_OFF;
//		FIRE_LED_OFF;
//	}
//
//	FIRE_LED_OFF;
//	FIRE_LED_BLINK_OFF;
//	FIRE_LED_OFF;
}



