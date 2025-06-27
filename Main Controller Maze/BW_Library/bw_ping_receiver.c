/*==============================================================================================
								  PROJECT BW Ver.1.0
							BW PING RANGEFINDER RECEIVER
==============================================================================================*/

#include "bw_ping_receiver.h"

/*=============================== BW USART COMMUNICATION =====================================*/

void USART3_Init(uint32_t baudrate) //TO RANGEFINDER uCU
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9; // Pins 8 (TX) and 9 (RX) are used
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF; 			// the pins are configured as alternate function so the USART peripheral has access to them
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		// this defines the IO speed and has nothing to do with the baudrate!
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			// this defines the output type as push pull mode (as opposed to open drain)
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			// this activates the pullup resistors on the IO pins
	GPIO_Init(GPIOD, &GPIO_InitStructure);					// now all the values are passed to the GPIO_Init() function which sets the GPIO registers

	GPIO_PinAFConfig(GPIOD, GPIO_PinSource8, GPIO_AF_USART3); //
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource9, GPIO_AF_USART3);

	USART_InitStructure.USART_BaudRate = baudrate;				// the baudrate is set to the value we passed into this init function
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;// we want the data frame size to be 8 bits (standard)
	USART_InitStructure.USART_StopBits = USART_StopBits_1;		// we want 1 stop bit (standard)
	USART_InitStructure.USART_Parity = USART_Parity_No;		// we don't want a parity bit (standard)
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // we don't want flow control (standard)
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx; // we want to enable the transmitter and the receiver
	USART_Init(USART3, &USART_InitStructure);					// again all the properties are passed to the USART_Init function which takes care of all the bit setting

	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE); // enable the USART3 receive interrupt

	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;		 // we want to configure the USART3 interrupts
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;// this sets the priority group of the USART3 interrupts
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;		 // this sets the subpriority inside the group
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			 // the USART3 interrupts are globally enabled
	NVIC_Init(&NVIC_InitStructure);							 // the properties are passed to the NVIC_Init function which takes care of the low level stuff

	USART_Cmd(USART3, ENABLE);
}

void USART3_PutChar(char DATA)
{
//	while(USART_GetFlagStatus(USART3, USART_FLAG_TXE) == RESET); // Wait empty
//	USART_SendData(USART3, DATA); // Send char
//	while (USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET);
}

/*
void USART3_IRQHandler(void)
{
	if( USART_GetITStatus(USART3, USART_IT_RXNE) )
	{
		char t = USART3->DR; // the character from the USART3 data register is saved in t
		char static last_data;

		switch(USART_Count)
		{
			case  1 : Ping[PING_FRONT]=USART3->DR; USART_Count+=1; break;
			case  2 : SHARP[IR_FRONT]=USART3->DR; USART_Count+=1; break;
			case  3 : Ping[PING_REAR]=USART3->DR; USART_Count+=1; break;
			case  4 : SHARP[IR_STAIRS]=USART3->DR; USART_Count+=1; break;
			case  5: if(ENABLE_UV1 == 1)UV_VARIABLE=USART3->DR;
					 else  if(ENABLE_UV1 == 0)
					 {
						DUMMY_VAR = USART3->DR;
						UV_VARIABLE = 1;
					 }
					USART_Count+=1;break;
			case  6: if(ENABLE_UV2 == 1)UV_VARIABLE2=USART3->DR;
					 else if(ENABLE_UV2 == 0)
					 {
						 DUMMY_VAR = USART3->DR;
						 UV_VARIABLE2 = 1;
					 }
					USART_Count+=1;break;
			case  7 : Ping[PING_ASKEW_RIGHT]=USART3->DR; USART_Count+=1; break;
			case  8 : Ping[PING_ASKEW_LEFT]=USART3->DR; USART_Count+=1; break;
			case  9 : if(ENABLE_UV1 == 1)UV_VARIABLE=USART3->DR;
					 else  if(ENABLE_UV1 == 0)
					 {
						DUMMY_VAR = USART3->DR;
						UV_VARIABLE = 1;
					 }
					USART_Count+=1;break;
			case  10 : if(ENABLE_UV2 == 1)UV_VARIABLE2=USART3->DR;
					 else if(ENABLE_UV2 == 0)
					 {
						 DUMMY_VAR = USART3->DR;
						 UV_VARIABLE2 = 1;
					 }
					USART_Count+=1;break;
			case  11 : Ping[PING_REAR_RIGHT]=USART3->DR; USART_Count+=1; break;
			case  12 : Ping[PING_REAR_LEFT]=USART3->DR; USART_Count+=1; break;
			case  13 : if(ENABLE_UV1 == 1)UV_VARIABLE=USART3->DR;
					 else  if(ENABLE_UV1 == 0)
					 {
						DUMMY_VAR = USART3->DR;
						UV_VARIABLE = 1;
					 }
					USART_Count+=1;break;
			case  14 : if(ENABLE_UV2 == 1)UV_VARIABLE2=USART3->DR;
					 else if(ENABLE_UV2 == 0)
					 {
						 DUMMY_VAR = USART3->DR;
						 UV_VARIABLE2 = 1;
					 }
					USART_Count+=1;break;
			case  15 : Ping[PING_RIGHT]=USART3->DR; USART_Count+=1; break;
			case  16 : Ping[PING_LEFT]=USART3->DR; USART_Count+=1; break;
			case  17 : if(ENABLE_UV1 == 1)UV_VARIABLE=USART3->DR;
					 else  if(ENABLE_UV1 == 0)
					 {
						DUMMY_VAR = USART3->DR;
						UV_VARIABLE = 1;
					 }
					USART_Count+=1;break;
			case  18 : if(ENABLE_UV2 == 1)UV_VARIABLE2=USART3->DR;
					 else if(ENABLE_UV2 == 0)
					 {
						 DUMMY_VAR = USART3->DR;
						 UV_VARIABLE2 = 1;
					 }
					USART_Count+=1;break;
			case  19 : Ping[PING_UP_RIGHT]=USART3->DR; USART_Count+=1; break;
			case  20 : Ping[PING_UP_LEFT]=USART3->DR; USART_Count+=1; break;
			case  21 : if(ENABLE_UV1 == 1)UV_VARIABLE=USART3->DR;
					 else  if(ENABLE_UV1 == 0)
					 {
						DUMMY_VAR = USART3->DR;
						UV_VARIABLE = 1;
					 }
					USART_Count+=1;break;
			case  22 : if(ENABLE_UV2 == 1)UV_VARIABLE2=USART3->DR;
					 else if(ENABLE_UV2 == 0)
					 {
						 DUMMY_VAR = USART3->DR;
						 UV_VARIABLE2 = 1;
					 }
					USART_Count+=63;break;
		}
		if(t==COMMAND_FLAG_B && last_data==COMMAND_FLAG_A) USART_Count=1;
		last_data=t;
	}
}
*/

void USART3_IRQHandler(void)
{
	if( USART_GetITStatus(USART3, USART_IT_RXNE) )
	{
		char t = USART3->DR; // the character from the USART3 data register is saved in t
		char static last_data;

		switch(USART_Count)
		{
			case  1 : Ping[PING_FRONT]=USART3->DR; USART_Count+=1; break;
			case  2 : Ping[PING_REAR]=USART3->DR; USART_Count+=1; break;

			case  3 : Ping[PING_ASKEW_RIGHT]=USART3->DR; USART_Count+=1; break;
			case  4 : Ping[PING_ASKEW_LEFT]=USART3->DR; USART_Count+=1; break;

			case  5 : Ping[PING_REAR_RIGHT]=USART3->DR; USART_Count+=1; break;
			case  6 : Ping[PING_REAR_LEFT]=USART3->DR; USART_Count+=1; break;

			case  7 : Ping[PING_RIGHT]=USART3->DR; USART_Count+=1; break;
			case  8 : Ping[PING_LEFT]=USART3->DR; USART_Count+=1; break;

			case  9 : SHARP_GRIPPER[0]=USART3->DR; USART_Count+=1; break;
			case  10: SHARP[IR_LEFT]=USART3->DR; USART_Count+=1; break;
			case  11: SHARP[IR_RIGHT]=USART3->DR; USART_Count+=63; break;

		}
		if(t==COMMAND_FLAG_B && last_data==COMMAND_FLAG_A) USART_Count=1;
		last_data=t;
	}
}

void Display_Ping_Status (void)
{
	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"PING DATA VALUE!");lcd_putstr(lcd);

//	lcd_gotoxy(11,0);sprintf(lcd,"RE%d",Ping[PING_REAR]);lcd_putstr(lcd);
//	lcd_gotoxy(11,1);sprintf(lcd,"UR%d",Ping[PING_UP_RIGHT]);lcd_putstr(lcd);
//	lcd_gotoxy(6,1);sprintf(lcd,"F%d",Ping[PING_FRONT]);lcd_putstr(lcd);
//	lcd_gotoxy(0,1);sprintf(lcd,"UL%d",Ping[PING_UP_LEFT]);lcd_putstr(lcd);
//
//	lcd_gotoxy(0,2);sprintf(lcd,"FR%d",Ping[PING_ASKEW_RIGHT]);lcd_putstr(lcd);
//	lcd_gotoxy(6,2);sprintf(lcd,"R%d",Ping[PING_RIGHT]);lcd_putstr(lcd);
//	lcd_gotoxy(11,2);sprintf(lcd,"RR%d",Ping[PING_REAR_RIGHT]);lcd_putstr(lcd);
//
//	lcd_gotoxy(0,3);sprintf(lcd,"FL%d",Ping[PING_ASKEW_LEFT]);lcd_putstr(lcd);
//	lcd_gotoxy(6,3);sprintf(lcd,"L%d",Ping[PING_LEFT]);lcd_putstr(lcd);
//	lcd_gotoxy(11,3);sprintf(lcd,"RL%d",Ping[PING_REAR_LEFT]);lcd_putstr(lcd);

	lcd_gotoxy(0,1);sprintf(lcd,"F %d",Ping[PING_FRONT]);lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FR%d",Ping[PING_ASKEW_RIGHT]);lcd_putstr(lcd);
	lcd_gotoxy(0,3);sprintf(lcd,"FL%d",Ping[PING_ASKEW_LEFT]);lcd_putstr(lcd);
	lcd_gotoxy(6,1);sprintf(lcd,"RE%d",Ping[PING_REAR]);lcd_putstr(lcd);
	lcd_gotoxy(6,2);sprintf(lcd,"RL%d",Ping[PING_REAR_LEFT]);lcd_putstr(lcd);
	lcd_gotoxy(6,3);sprintf(lcd,"RR%d",Ping[PING_REAR_RIGHT]);lcd_putstr(lcd);
	lcd_gotoxy(11,1);sprintf(lcd,"SG%d",SHARP_GRIPPER[0]);lcd_putstr(lcd);
	lcd_gotoxy(11,2);sprintf(lcd,"SL%d",SHARP[IR_LEFT]);lcd_putstr(lcd);
	lcd_gotoxy(11,3);sprintf(lcd,"SR%d",SHARP[IR_RIGHT]);lcd_putstr(lcd);

	delay_ms(50);
}

void Display_Sharp_Status (void)
{
	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"SHARP STATUS");lcd_putstr(lcd);

	lcd_gotoxy(0,1);sprintf(lcd,"STAIRS: %d",SHARP[IR_STAIRS]);lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FRONT: %d",SHARP[IR_FRONT]);lcd_putstr(lcd);

	lcd_gotoxy(0,3);sprintf(lcd,"MOSOK GAK AYO");lcd_putstr(lcd);

	delay_ms(100);
}
