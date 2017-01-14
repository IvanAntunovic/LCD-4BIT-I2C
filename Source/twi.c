#include "twi.h"


void TWI_init(void)
{
	//set SCL to 50kHz at XTAL = 1MHz
	TWSR = 0x00;
	TWBR = 0x02;
	//enable TWI
	TWCR = (1<<TWEN);
}

uint8_t TWI_start(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while ((TWCR & (1<<TWINT)) == 0);
	if (TWI_getStatus() != 0x08)
		return ERROR;
	return SUCCESS;
}
//send stop signal
void TWI_stop(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
	while (TWCR & (1<<TWSTO));
}

uint8_t TWI_write(uint8_t u8data)
{
	TWDR = u8data;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while ((TWCR & (1<<TWINT)) == 0);
	if (TWI_getStatus() != 0x28)
		return ERROR;
	return SUCCESS;
}

uint8_t TWI_writeAddress(uint8_t address)
{
	/*
	if (address & 0x01)	// address + R(1) = TRUE 
		MASTER_MODE = MASTER_RECIEVER_MODE;		//mode = 0
	else
		MASTER_MODE = MASTER_TRANSMITTER_MODE;	//mode = 1
	*/	
	TWDR = address;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while ((TWCR & (1<<TWINT)) == 0);
	
	if ( (address & 0x01) == MASTER_TRANSMITTER_MODE) //master transmitter
	{
		if (TWI_getStatus() != 0x18)
			return ERROR;
	}
	if ( (address & 0x01) == MASTER_RECIEVER_MODE)	//master receiver
	{
		if (TWI_getStatus() != 0x40)
			return ERROR;
	}
			
	return SUCCESS;
}

uint8_t TWI_readACK(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while ((TWCR & (1<<TWINT)) == 0);
	if (TWI_getStatus() != 0x50)
		readStatus = ERROR;
	else 
		readStatus = SUCCESS;
		
	return TWDR;
}
//read byte with NACK
uint8_t TWI_readNACK(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN);
	while ((TWCR & (1<<TWINT)) == 0);
	if (TWI_getStatus() != 0x58)
		readStatus = ERROR;
	else
		readStatus = SUCCESS;
	
	return TWDR;
}

uint8_t TWI_getStatus(void)
{
	uint8_t status;
	//mask status
	status = TWSR & 0xF8;
	return status;
}

