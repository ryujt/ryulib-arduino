#include "MAX7219.h"
#include <Arduino.h>


void MAX7219::write_byte(unsigned char DATA)
{
	digitalWrite(_CS, LOW);
	for (int i=8; i>=1; i--) {
		digitalWrite(_CLK, LOW);
		digitalWrite(_DIN, DATA & 0x80);
		DATA = DATA << 1;
		digitalWrite(_CLK, HIGH);
	}
}

void MAX7219::begin()
{
	pinMode(_CLK, OUTPUT);
	pinMode(_CS, OUTPUT);
	pinMode(_DIN, OUTPUT);

	write(0x09, 0x00);
	write(0x0a, 0x03);
	write(0x0b, 0x07);
	write(0x0c, 0x01);
	write(0x0f, 0x00);
}

void MAX7219::write(unsigned char address, unsigned char dat)
{
	digitalWrite(_CS, LOW);
	write_byte(address);
	write_byte(dat);
	digitalWrite(_CS, HIGH);
}
