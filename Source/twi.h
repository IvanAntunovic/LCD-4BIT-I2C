#ifndef _TWI_H
#define _TWI_H

#include <avr/io.h>

#define ERROR						1
#define SUCCESS						0
#define MASTER_TRANSMITTER_MODE		0
#define MASTER_RECIEVER_MODE		1

static uint8_t readStatus; 

void TWI_init(void);
uint8_t TWI_start(void);
void TWI_stop(void);
uint8_t TWI_write(uint8_t u8data);
uint8_t TWI_writeAddress(uint8_t address);
uint8_t TWI_readACK(void);
uint8_t TWI_readNACK(void);
uint8_t TWI_getStatus(void);

#endif
