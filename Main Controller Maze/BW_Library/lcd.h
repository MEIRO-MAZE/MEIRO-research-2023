#ifndef LCD_H
#define LCD_H

typedef struct
{
	u8 number;
	u8 line[8];
}
CustomCharacter;

void lcd_init(void);
void lcd_putch(const char chr);
void lcd_putstr (const char* str);
void lcd_gotoxy(uint8_t col, uint8_t row);
void lcd_display_clear(void);
void lcd_home (void);
void lcd_cursor_off_blink_off(void);
void lcd_cursor_on_blink_on(void);
void lcd_save_customchar(CustomCharacter *character);
void lcd_write_customchar(CustomCharacter *character);
void tampil1000(int dat);
void tampil(int dat);

#endif
