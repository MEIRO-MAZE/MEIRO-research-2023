/*==============================================================================================
								  PROJECT BW Ver.1.0
								  	  LCD LIBRARY
==============================================================================================*/
#ifndef BW_LCD_H
#define BW_LCD_H

/*
 * BW LCD MACRO DEFINITIONS
 */
// Konfigurasi PIN - PIN1, PIN3 and PIN5 connect to GND
//#define RS_PORT GPIOE
//#define RS_PIN  GPIO_Pin_9
//#define EN_PORT GPIOE
//#define EN_PIN  GPIO_Pin_10
//#define D4_PORT GPIOE
//#define D4_PIN  GPIO_Pin_11
//#define D5_PORT GPIOE
//#define D5_PIN  GPIO_Pin_12
//#define D6_PORT GPIOE
//#define D6_PIN  GPIO_Pin_13
//#define D7_PORT GPIOE
//#define D7_PIN  GPIO_Pin_14
//#define RCC_AHB1Periph_GPIOx RCC_AHB1Periph_GPIOE
//#define GPIOx GPIOE

/*
 * BW 2016 PIN MAPPING
 */
#define RS_PORT GPIOE
#define RS_PIN  GPIO_Pin_10
#define EN_PORT GPIOE
#define EN_PIN  GPIO_Pin_11
#define D4_PORT GPIOE
#define D4_PIN  GPIO_Pin_12
#define D5_PORT GPIOE
#define D5_PIN  GPIO_Pin_13
#define D6_PORT GPIOE
#define D6_PIN  GPIO_Pin_14
#define D7_PORT GPIOE
#define D7_PIN  GPIO_Pin_15
#define RCC_AHB1Periph_LCD RCC_AHB1Periph_GPIOE
#define LCD_PORT GPIOE


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

typedef struct
{
	u8 number;
	u8 line[8];
}
CustomCharacter;

/*
 * BW LCD VARIABLES
 */
char lcd[16];

/*
 * BW LCD FUNCTION PROTOTYPE
 */
void BW_LCD_Init(void);
void lcd_putch(const char chr);
void lcd_putstr (const char* str);
void lcd_gotoxy(uint8_t col, uint8_t row);
void lcd_display_clear(void);
void lcd_cursor_off_blink_off(void);
void lcd_save_customchar(CustomCharacter *character);
void lcd_write_customchar(CustomCharacter *character);

#endif
