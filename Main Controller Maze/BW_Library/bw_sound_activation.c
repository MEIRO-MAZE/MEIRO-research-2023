/*==============================================================================================
								  	  PROJECT BW Ver.2.0
								  	 BW SOUND ACTIVATION LIBRARY
==============================================================================================*/

#include <bw_sound_activation.h>

void BW_Sound_Activation_Init(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	GPIO_InitStructure.GPIO_Pin   = SOUND_ACT_PIN;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP; //Default input == 1
	GPIO_Init(SOUND_ACT_PORT, &GPIO_InitStructure);
}

void BW_Sound_Activation(void)
{
	BW_Sound_Activate = SOUND_SCAN;

	while ( (SOUND_SCAN!=0)&&(BW_START!=1) )
	{
		BW_Sound_Activate = SOUND_SCAN;
		BW_START=BW_BUTTON_INPUT;

		RotSwitch_Sampling();
		Display_MODE();
	}

	lcd_gotoxy(0,3);sprintf(lcd," BW Activated!");lcd_putstr(lcd);
}
