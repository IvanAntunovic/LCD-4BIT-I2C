/*
 * LCD_Test_i2c.c
 *
 * Created: 12/30/2016 6:40:49 PM
 * Author : Ivan Antunovic
 */ 

#include <avr/io.h>
#include "twi.h"
#include "PCF8574A.h"
#include "LCD_4bit.h"
#include "i2cmaster.h"

int main(void)
{
	DDRA = 0xFF;
	i2c_init();
	//TWI_init();
    /* Replace with your application code */
	LCD_init();
	LCD_puts("HELLO");
	LCD_gotoxy(10, 1);
	LCD_puts("WORLD");
	LCD_gotoxy(1, 4);
	LCD_puts("I wish everyone good morning.");
	
    while (1) 
    {
		
    }
}

