#ifndef MAX7219_H
#define MAX7219_H


#include <Arduino.h>


class MAX7219
{
private:
	int _CLK;
	int _CS;
	int _DIN;
private:
	void write_byte(unsigned char DATA);
public:
	MAX7219(int clk, int cs, int din)
		: _CLK(clk), _CS(cs), _DIN(din)
	{};

	void begin();
	void write(unsigned char address, unsigned char dat);
};


#endif // MAX7219_H
