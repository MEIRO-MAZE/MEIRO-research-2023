/*============================================================================================
							   PROJECT BW 2016 Ver.1.0
								  BW I2C LCD LIBRARY
==============================================================================================*/

#ifndef BW_I2C_LCD_H
#define BW_I2C_LCD_H

/* D0 -> RS
 * D1 -> RW
 * D2 -> E
 * D3 -> LED
 * D4 -> D4
 * D5 -> D5
 * D6 -> D6
 * D7 -> D7

*/

#include "main.h"


// PCF8574 COMMANDS (TRYING TO CREATE MY OWN SYSTEM) FUCKING SYET

#define RS_ON			0x01
#define RS_OFF			0x00
#define EN_ON			0x04
#define EN_OFF			0x00
#define D4_ON			0x10
#define D4_OFF			0x00
#define D5_ON			0x20
#define D5_OFF			0x00
#define D6_ON			0x40
#define D6_OFF			0x00
#define D7_ON			0x80
#define D7_OFF			0x00

// PCF8574 FROM ARDUINO

// commands
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

uint8_t Addr;        ///< Wire Address of the LCD
uint8_t backlight;   ///< the backlight intensity

uint8_t displayfunction; ///< lines and dots mode
uint8_t displaycontrol;  ///< cursor, display, blink flags
uint8_t displaymode;     ///< left2right, autoscroll

uint8_t numlines;        ///< The number of rows the display supports.

// LCD Functions
void PCF8574_WriteI2C(uint8_t halfByte, uint8_t mode, uint8_t enable);
void PCF8574_Send_Nibble(uint8_t halfbyte, uint8_t mode);
void PCF8574_Send(uint8_t value, uint8_t mode);
void PCF8574_Command(uint8_t value);
void PCF8574_Write(uint8_t value);
void LiquidCrystal_PCF8574(uint8_t addr);
void PCF8574_begin_LCD(uint8_t cols, uint8_t lines, uint8_t dotsize);
void PCF8574_createChar(uint8_t location, uint8_t charmap[]);
void PCF8574_LCD_BlinkCursor(void);
void PCF8574_LCD_noBlinkCursor(void);
void PCF8574_LCD_CursorOn(void);
void PCF8574_LCD_CursorOff(void);
void PCF8574_LCD_DisplayOn(void);
void PCF8574_LCD_DisplayOff(void);
void PCF8574_LCD_gotoxy(uint8_t col, uint8_t row);
void PCF8574_LCD_Home(void);
void PCF8574_LCD_Clear(void);
void PCF8574_LCD_putch(const uint8_t chr);
void PCF8574_LCD_putstr(const char* str);

/// END OF PCF8574 FROM ARDUINO LIB



// OLD NON FUNCTIONAL DEFINITIONS
#define I2C_DISPLAY_CLEAR	0x01
#define I2C_CURSOR_HOME		0x02

#define I2C_DDRAM_ADDR_SET	0x80

//LCD I2C ADDRESS
#define LCD_ADDRESS 	 0x27
#define LCD_ADDRESS_W	 (LCD_ADDRESS << 1)
// commands
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

// flags for backlight control
#define LCD_BACKLIGHT 0x08
#define LCD_NOBACKLIGHT 0x00

#define En B00000100  // Enable bit
#define Rw B00000010  // Read/Write bit
#define Rs B00000001  // Register select bit

#define LCD_FUNCTION_SET            0x28
#define LCD_8BIT                   (0x10 | LCD_FUNCTION_SET)
#define LCD_4BIT                   (0 | LCD_FUNCTION_SET)

int16_t I2C1_TimeOut_LCD(int16_t VALUE);
int16_t I2C1_WriteByte_LCD(uint8_t ADDRESS, uint8_t VALUE);
int16_t I2C1_ReadByte_LCD(uint8_t ADDRESS, uint8_t REGISTER);
void PCF8574_Write_Nible(const uint8_t nible);
void PCF8574_WriteByte(const uint8_t byte);
void PCF8574_WriteDataByte(const uint8_t byte);
void I2C_LCD_Putchar(const char chr);
void I2C_LCD_Putstr(const char *str);
void I2C_LCD_WriteCMD_Byte(const uint8_t cmd);
void I2C_gotoxy(uint8_t col, uint8_t row);
void I2C_Display_Clear(void);
void I2C_LCD_Home(void);
void I2C_LCD_WriteCMD_Nible(const uint8_t cmd);

#define   I2C1_TIMEOUT     0x3000

#endif
