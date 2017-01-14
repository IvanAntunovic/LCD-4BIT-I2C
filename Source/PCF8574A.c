#include "PCF8574A.h"
#include "twi.h"

void PCF8574A_write (uint8_t command)
{
	/*
	TWI_start();
	TWI_writeAddress(PCF8574A_WRITE);
	TWI_write(command);
	TWI_stop();
	*/
	i2c_start(PCF8574A_WRITE);
	i2c_write(command);
	i2c_stop();
}

uint8_t PCF8574A_read (void)
{
	uint8_t readData;
	/*
	TWI_start();
	TWI_writeAddress(PCF8574A_READ);
	readData = TWI_readNACK();
	TWI_stop();
	*/
	i2c_start(PCF8574A_READ);
	readData = i2c_readNak();
	i2c_stop();
	return readData;
}


