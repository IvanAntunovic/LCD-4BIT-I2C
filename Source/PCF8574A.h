#ifndef _PCF8574A_H_
#define _PCF8574A_H_

#include <avr/io.h>

#define PCF8574A_ADDRESS		0x3F
#define PCF8574A_READ			( (PCF8574A_ADDRESS << 1) | (0x01) )
#define PCF8574A_WRITE			(PCF8574A_ADDRESS << 1)

uint8_t PCF8574A_read (void);
void PCF8574A_write (uint8_t command);

uint8_t PCF8574A_PORT;
uint8_t PCF8574A_PIN;

typedef struct
{
	uint8_t PORT;
	uint8_t PIN;
	
}pcf8574a;

#endif
