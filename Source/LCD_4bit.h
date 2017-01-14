#ifndef _LCD_4BIT_H_
#define _LCD_4BIT_H_

#ifndef F_CPU
#define F_CPU 1000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <math.h>

#define RS 0
#define RW 1
#define EN 2

void LCD_putc(unsigned char value);
void LCD_writeCommand(unsigned char command);
void LCD_puts(char* string);
void Falling_edge();
void Rising_edge();
void LCD_isBusy();
void LCD_gotoxy(unsigned char x, unsigned char y);
void LCD_init();

char LCD_int_to_char(int, int);
void LCD_int(int);

#endif

