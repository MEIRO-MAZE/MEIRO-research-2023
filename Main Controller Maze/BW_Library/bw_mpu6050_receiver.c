
//							BW_MPU6050_RECEIVER
//								from ARDUINO
#include "bw_mpu6050_receiver.h"

/*=============================== BW USART COMMUNICATION =====================================*/

//void UART4_Init(uint32_t baudrate)
//{
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
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;		 // this sets the subpriority inside the group
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			 // the USART3 interrupts are globally enabled
//	NVIC_Init(&NVIC_InitStructure);							 // the properties are passed to the NVIC_Init function which takes care of the low level stuff
//
//	// finally this enables the complete USART6 peripheral
//	USART_Cmd(UART4, ENABLE);
//}
//
//void UART4_IRQHandler(void)
//{
//	if( USART_GetITStatus(UART4, USART_IT_RXNE) )
//	{
//		char t = UART4->DR; // the character from the USART3 data register is saved in t
//		char static last_data;
//
//		switch(USART_Count)
//		{
//			case  1 : IMU_SLAVE_DATA[0] = UART4->DR; USART_Count+=1;break;
//			case  2 : {
//						if(IMU_SLAVE_DATA[0] ==	BW_SOUND_ACTIVATED) //SAAT SLAVE ARDUINO BERFUNGSI UNTUK SOUND RECEIVER
//						{
//							USART_Count+=111; break;
//						}
//						else
//						{
//						  	IMU_SLAVE_DATA[1]= UART4->DR; USART_Count+=1; break;
//						}
//					  }
//			case  3 : IMU_SLAVE_DATA[2] = UART4->DR; USART_Count+=1; break;
//			case  4 : IMU_SLAVE_DATA[3] = UART4->DR; USART_Count+=111; break;
//		}
//		if(t==COMMAND_FLAG_B && last_data==COMMAND_FLAG_A) USART_Count=1;
//		last_data=t;
//	}
//}
//
//void Display_IMU_Data(void)
//{
//	YAW_IMU = (IMU_SLAVE_DATA[0]*255)+IMU_SLAVE_DATA[1];
//	if(YAW_IMU>180){	YAW_IMU-=360; }
//	PITCH_IMU = IMU_SLAVE_DATA[2];
//	if(PITCH_IMU>90){	PITCH_IMU=-180;	}
//	ROLL_IMU = IMU_SLAVE_DATA[3];
//	if(ROLL_IMU>90){	ROLL_IMU=-180; }
//
//	lcd_display_clear();
//
//	lcd_gotoxy(0,0);sprintf(lcd,"IMU RAW VAL");lcd_putstr(lcd);
//	lcd_gotoxy(0,1);sprintf(lcd,"YAW   : %d",YAW_IMU);lcd_putstr(lcd);
//	lcd_gotoxy(0,2);sprintf(lcd,"PITCH : %d",PITCH_IMU);lcd_putstr(lcd);
//	lcd_gotoxy(0,3);sprintf(lcd,"ROLL  : %d",ROLL_IMU);lcd_putstr(lcd);
//
//	Sendto_PC(USART1,"\r BW IMU DATA \r");
//	Sendto_PC(USART1,"YAW = %d\t",YAW_IMU);
//	Sendto_PC(USART1,"PITCH = %d\t",PITCH_IMU);
//	Sendto_PC(USART1,"ROLL = %d\t",ROLL_IMU);
//	delay_ms(100);
//}
//
//void IMU_Transmit(USART_TypeDef* USARTx, int DATA)
//{
//  while(USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET); // Wait empty
//  USART_SendData(USARTx, DATA); // Send char
//}



