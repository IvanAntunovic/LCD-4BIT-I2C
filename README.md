# LCD-4BIT-I2C

This program uses I2C adapter PCF8574/PCF8574A with a LCD in 4 bit mode.
I2C communication was tested with both my code for I2C and Peter Fluery's I2C library:
http://homepage.hispeed.ch/peterfleury/doxygen/avr-gcc-libraries/group__pfleury__ic2master.html

I2c library written myself is TWI.h/TWI.c and you have to uncomment TWI functions in PCF8574A.h and delete i2c functions in order to use it.

Code written by Ivan Antunovic, 
and it can be freely used and shared.
