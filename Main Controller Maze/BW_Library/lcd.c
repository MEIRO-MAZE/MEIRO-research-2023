#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "lcd.h"
#include "delay.h"

// Configurasi PIN - PIN1, PIN3 and PIN5 connect to GND
#define RS_PORT GPIOD
#define RS_PIN  GPIO_Pin_0
#define EN_PORT GPIOD
#define EN_PIN  GPIO_Pin_3
#define D4_PORT GPIOD
#define D4_PIN  GPIO_Pin_4
#define D5_PORT GPIOD
#define D5_PIN  GPIO_Pin_5
#define D6_PORT GPIOD
#define D6_PIN  GPIO_Pin_6
#define D7_PORT GPIOD
#define D7_PIN  GPIO_Pin_7
#define RCC_AHB1Periph_GPIOx RCC_AHB1Periph_GPIOD
#define GPIOx GPIOD

#define col_num  16//colom lcd

//---------------------------------------------

#define LCD_DISPLAY_CLEAR          0x01
#define LCD_CURSOR_HOME            0x02
#define LCD_ENTRY_MODE_SET         0x04
#define LCD_ENTRY_INCREMENT        (0x02 | LCD_ENTRY_MODE_SET)
#define LCD_ENTRY_DESCREMENT       (0 | LCD_ENTRY_MODE_SET)
#define LCD_ENTRY_SHIFT            (0x01 | LCD_ENTRY_MODE_SET)
#define LCD_ENTRY_NOTSHIFT         (0 | LCD_ENTRY_MODE_SET)
#define LCD_DISPLAY_ON_OFF          0x08
#define LCD_DISPLAY_ON             (0x04 | LCD_DISPLAY_ON_OFF)
#define LCD_DISPLAY_OFF            (0 | LCD_DISPLAY_ON_OFF)
#define LCD_CURSOR_ON              (0x02 | LCD_DISPLAY_ON_OFF )
#define LCD_CURSOR_OFF             (0 | LCD_DISPLAY_ON_OFF)
#define LCD_POSITION_BLINK         (0x01 | LCD_DISPLAY_OFF)
#define LCD_POSITION_NOTBLINK      (0 | LCD_DISPLAY_ON_OFF)
#define LCD_CURSOR_DISPLAY_SHIFT    0x10
#define lCD_DISPLAY_SHIFT          (0x08 | LCD_CURSOR_DISPLAY_SHIFT)
#define LCD_CURSOR_SHIFT           (0 | LCD_CURSOR_DISPLAY_SHIFT)
#define LCD_RIGHT_SHIFT            (0x04 | LCD_CURSOR_DISPLAY_SHIFT)
#define LCD_LEFT_SHIFT             (0 | LCD_CURSOR_DISPLAY_SHIFT)
#define LCD_FUNCTION_SET            0x28
#define LCD_8BIT                   (0x10 | LCD_FUNCTION_SET)
#define LCD_4BIT                   (0 | LCD_FUNCTION_SET)
#define LCD_CGRAM_ADDR_SET          0x40
#define LCD_DDRAM_ADDR_SET          0x80

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

void lcd_init(void)
{
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOx, ENABLE);

	  GPIO_InitStructure.GPIO_Pin = RS_PIN | EN_PIN | D4_PIN | D5_PIN | D6_PIN | D7_PIN ;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	  GPIO_Init(GPIOx, &GPIO_InitStructure);

	  delay_us(199);

	  lcd_write_cmd_nible( nible_hi(LCD_8BIT) );
	  lcd_write_cmd_nible( nible_hi(LCD_8BIT) );
	  delay_us(199);
	  lcd_write_cmd_nible( nible_hi(LCD_8BIT) );
	  lcd_write_cmd_nible( nible_hi(LCD_4BIT) );
	  delay_us(199);
	  lcd_write_cmd_byte(LCD_4BIT);
	  delay_us(199);
}

void lcd_putch(const char chr)
{
	lcd_write_data_byte(chr);
}

void lcd_putstr(const char* str)
{
	while(*str)
	{
		lcd_putch(*str++);
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
	lcd_write_cmd_byte(LCD_DDRAM_ADDR_SET |\
	                  lcd_row_addr(row) | col );
	delay_us(199);
}

void lcd_display_clear(void)
{
	lcd_write_cmd_byte(LCD_DISPLAY_CLEAR);
	//delay_us(199);
}

void lcd_home(void)
{
	lcd_write_cmd_byte(LCD_CURSOR_HOME);
	delay_us(199);
}

void lcd_cursor_off_blink_off(void)
{
lcd_write_cmd_byte(LCD_DISPLAY_ON | LCD_DISPLAY_OFF\
	                  | LCD_POSITION_NOTBLINK);
delay_us(179);
lcd_display_clear();
}

void lcd_cursor_on_blink_on(void)
{
	lcd_write_cmd_byte(LCD_DISPLAY_ON | LCD_CURSOR_ON \
	                 | LCD_POSITION_BLINK);
	delay_us(179);
	lcd_display_clear();
}

void tampil(int dat)
{
    int data;
    data = dat / 100;    // mencari angka ratusan
        data += 0x30;        // dirubah ke ascii  + 48;
        write_data();
        lcd_write_byte(data);

        dat %= 100;
        data = dat / 10;    //mencari angka puluhan
        data += 0x30;       //
        lcd_write_byte(data);

        dat %= 10;
        data = dat + 0x30;
        lcd_write_byte(data);
}

void tampil1000(int dat)
{
	int data;
    data = dat / 1000;    // mencari angka ribuan
    data += 0x30;        // dirubah ke ascii  + 48;
    write_data();
    lcd_write_byte(data);

    dat %= 1000;          // mencari sisa bagi 1000
    data = dat / 100;    // mencari angka ratusan
    data += 0x30;        // dirubah ke ascii  + 48;
    lcd_write_byte(data);

    dat %= 100;
    data = dat / 10;    //mencari angka puluhan
    data += 0x30;       //
    lcd_write_byte(data);

    dat %= 10;
    data = dat + 0x30;
    lcd_write_byte(data);
}
