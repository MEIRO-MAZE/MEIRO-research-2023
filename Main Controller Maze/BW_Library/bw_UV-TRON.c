/*==============================================================================================
								  	  PROJECT BW Ver.1.0
								  HAMAMATSU UV-TRON SENSOR LIBRARY
==============================================================================================*/
#include "bw_2021_algorithm.h"
#include "bw_UV-TRON.h"


void BW_Display_UV_Stat(void)
{
	Get_UV();
	lcd_display_clear();
	lcd_gotoxy(1,0);sprintf(lcd,"BHATARA WIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,1);sprintf(lcd,"UV TEST");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"UV_State: %d",UV_state);lcd_putstr(lcd);
	lcd_gotoxy(0,3);sprintf(lcd,"UV1: %d",UV_VARIABLE);lcd_putstr(lcd);
	lcd_gotoxy(10,3);sprintf(lcd,"UV2: %d",UV_VARIABLE2);lcd_putstr(lcd);

	if (UV_state == UVSTATE_ACTIVE)
	{
		FIRE_LED_BLINK_ON;
	}
	else
	{
		FIRE_LED_BLINK_OFF;
		FIRE_LED_OFF;
	}
	delay_ms(100);
}

void Get_UV(void)
{
	if((UV_VARIABLE == 0) || (UV_VARIABLE2 == 0))
	{
		UV_state=0;
		UV_Lock=1;
	}
	else UV_state = 1;
}
