#include "LCD_4bit.h"
#include "PCF8574A.h"

void LCD_init()
{
	//COMMAND_DDR |= 1 << EN | 1 << RW | 1 << RS;
	//_delay_ms(15);
	
	
	LCD_writeCommand(0x33);
	//_delay_us(100);
	LCD_writeCommand(0x32);
	//_delay_us(100);
	LCD_writeCommand(0x28);
	//_delay_us(100);
	LCD_writeCommand(0x0E);
	//_delay_us(100);
	LCD_writeCommand(0x01);
	//_delay_us(2000);
	LCD_writeCommand(0x06);
	//_delay_us(100);
	LCD_writeCommand(0x80);
}
/*
###################################################################
                 FUNKCIJE ZA SLANJE TEXTA NA LCD
###################################################################
*/
void LCD_putc(unsigned char value)
{

	//PCF8574A 
	//LCD_isBusy();
	
	PCF8574A_PORT = (PCF8574A_PORT & 0x0F) | (value & 0xF0);
	PCF8574A_write(PCF8574A_PORT);

	PCF8574A_PORT |= 1 << RS;
	PCF8574A_PORT &= ~(1 << RW);
	PCF8574A_write(PCF8574A_PORT);

	// Rising bridge for LCD to LATCH data on its pins
	Falling_edge();
	
	//LCD_isBusy();
	
	PCF8574A_PORT = (PCF8574A_PORT & 0x0F) | (value << 4);
	PCF8574A_write(PCF8574A_PORT);
	
	PCF8574A_PORT |= 1 << RS;
	PCF8574A_PORT &= ~(1 << RW);
	PCF8574A_write(PCF8574A_PORT);

	// Rising bridge for LCD to LATCH data on its pins
	Falling_edge();
	
}
void LCD_puts(char* string)
{
	while(*string > '\0')
		LCD_putc(*string++);
		
}
/*
###################################################################
                 FUNKCIJE ZA SLANJE KOMANDI NA LCD
###################################################################
*/
void LCD_writeCommand(unsigned char command)
{
	//PCF8574A
	//LCD_isBusy();
	
	
	PCF8574A_PORT = (PCF8574A_PORT & 0x0F) | (command & 0xF0);
	PCF8574A_write(PCF8574A_PORT);

	PCF8574A_PORT &= ~((1 << RS) | (1 << RW));
	PCF8574A_write(PCF8574A_PORT);
	Falling_edge();
	
	//LCD_isBusy();
	
	PCF8574A_PORT = (PCF8574A_PORT & 0x0F) | (command << 4);
	PCF8574A_write(PCF8574A_PORT);
	PCF8574A_PORT &= ~((1 << RS) | (1 << RW));
	PCF8574A_write(PCF8574A_PORT);

	Falling_edge();
}

void LCD_gotoxy(unsigned char x, unsigned char y)
{
	unsigned char firstCharAdr[] = {0x80, 0xC0, 0x94, 0xD4};
	LCD_writeCommand(firstCharAdr[y-1] + x - 1);
	_delay_us(100);
}

/*
###################################################################
                 FUNKCIJE ZA LATCHANJE TEKSTA/KOMANDI NA LCD
###################################################################
*/

/* sending data to the LCD */
void Falling_edge()
{	
	//PCF8574A
	
	PCF8574A_PORT |= (1 << EN);
	PCF8574A_write(PCF8574A_PORT);
	_delay_us(1);
	PCF8574A_PORT &= ~(1 << EN);
	PCF8574A_write(PCF8574A_PORT);
	
}

/* Getting data from LCD */
void Rising_edge()
{	
	//PCF8574A
	
	PCF8574A_PORT &= ~(1 << EN);
	PCF8574A_write(PCF8574A_PORT);
	_delay_us(1);
	PCF8574A_PORT |= (1 << EN);
	PCF8574A_write(PCF8574A_PORT);
	
}

void LCD_isBusy()
{
	//PCF8574A
	
	PCF8574A_PORT &= ~(1 << RS);
	PCF8574A_PORT |= 1 << RW;
	PCF8574A_write(PCF8574A_PORT);
	
	while ( PCF8574A_read() & (1 << 7) )
		Rising_edge();
	
}


/*
void lcd_int(int num)
{
	int intLen = floor(log10(abs(num))) + 1;
	char* number = lcd_int_to_char(num, intLen);
	while(*number++ > '\0')
		lcd_char(*number);
}*/





