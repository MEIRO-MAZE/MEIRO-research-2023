/*==============================================================================================
								  PROJECT BW Ver.1.0
								  	  LCD LIBRARY
==============================================================================================*/

#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "bw_lcd.h"
#include "bw_systick_delay.h"
#include "bw_i2c_lcd.h"


GPIO_InitTypeDef  GPIO_InitStructure;

void RS_off()
{
	GPIO_ResetBits(RS_PORT, RS_PIN);
}

void RS_on()
{
	GPIO_SetBits(RS_PORT, RS_PIN);
}

void EN_off()
{
	GPIO_ResetBits(EN_PORT, EN_PIN);
}

void EN_on()
{
	GPIO_SetBits(EN_PORT, EN_PIN);
}

void D4_off()
{
	GPIO_ResetBits(D4_PORT, D4_PIN);
}

void D4_on()
{
	GPIO_SetBits(D4_PORT, D4_PIN);
}

void D5_off()
{
	GPIO_ResetBits(D5_PORT, D5_PIN);
}

void D5_on()
{
	GPIO_SetBits(D5_PORT, D5_PIN);
}

void D6_off()
{
	GPIO_ResetBits(D6_PORT, D6_PIN);
}

void D6_on()
{
	GPIO_SetBits(D6_PORT, D6_PIN);
}

void D7_off()
{
	GPIO_ResetBits(D7_PORT, D7_PIN);
}

void D7_on()
{
	GPIO_SetBits(D7_PORT, D7_PIN);
}

#define nible_hi(byte)     (byte>>4)
#define nible_lo(byte)     (byte & 0x0f)
#define write_command()    RS_off()  //command
#define write_data()       RS_on()   //data

void lcd_write_nible(const uint8_t nible)
{
	EN_on();

	if ((nible & 0b00000001) == 0b00000001) D4_on();
	else                D4_off();
	if ((nible & 0b00000010) == 0b00000010) D5_on();
	else                D5_off();
	if ((nible & 0b00000100) == 0b00000100)	D6_on();
	else                D6_off();
	if ((nible & 0b00001000) == 0b00001000) D7_on();
	else                D7_off();

	EN_off();
}

void lcd_write_byte(const uint8_t byte)
{
	lcd_write_nible(nible_hi(byte));
	lcd_write_nible(nible_lo(byte));
	delay_us(70); //49-69 masih error characternya (range delay terkecil terbaik = 70)
}

void lcd_write_cmd_nible(const uint8_t cmd)
{
	write_command();
	lcd_write_nible(cmd);					//semula lcd_write_cmd_nible
}

void lcd_write_data_byte(const uint8_t data)
{
	write_data();
	lcd_write_byte(data);
}

void lcd_write_cmd_byte(const uint8_t cmd)
{
	write_command();
	lcd_write_byte(cmd);

	if(cmd==LCD_DISPLAY_CLEAR || cmd==LCD_CURSOR_HOME)delay_us(2100); //1000-2000 masih error characternya
}

void BW_LCD_Init(void)
{
	PCF8574_begin_LCD(4,16,0); // Inisialisasi 4x16 dotsize default
	delay_ms(200);
	PCF8574_LCD_CursorOff();
}

void lcd_putch(const char chr)
{
	PCF8574_LCD_putch(chr);
}

void lcd_putstr(const char* str)
{
	while(*str)
	{
		PCF8574_LCD_putch(*str++);
	}
}

void lcd_save_customchar(CustomCharacter *character)
{
	if(character->number <= 7)
	{
        write_command();
		lcd_write_byte(0x40 | (character->number));

		u8 i;
		write_data();
		for(i = 0;i < 8;i++)
		{
			lcd_write_byte(character->line[i]);
		}

	}
}

void lcd_write_customchar(CustomCharacter *character)
{

	write_data();
	lcd_write_byte(character->number);

}

#define lcd_row_addr(row) (row%2? (row>>1)*col_num+0x40:\
                                   (row>>1)*col_num)

void lcd_gotoxy(uint8_t col, uint8_t row)
{
	PCF8574_LCD_gotoxy(col, row);
}

void lcd_display_clear(void)
{
	PCF8574_LCD_Clear();
}


void lcd_cursor_off_blink_off(void)
{
	lcd_write_cmd_byte(LCD_DISPLAY_ON | LCD_DISPLAY_OFF\
	                  | LCD_POSITION_NOTBLINK);
	delay_us(179);
	lcd_display_clear();
}

