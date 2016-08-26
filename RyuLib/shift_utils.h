#ifndef SHIFT_UTILS_H
#define SHIFT_UTILS_H


#include <Arduino.h>


class ShiftRegister
{
private:
	int _CLK;
	int _LATCH;
	int _DATA;
public:
	ShiftRegister(int clk, int latch, int data)
		: _CLK(clk), _LATCH(latch), _DATA(data)
	{};

	void begin()
	{
		pinMode(_CLK, OUTPUT);
		pinMode(_LATCH, OUTPUT);  
		pinMode(_DATA, OUTPUT);  
  	}

	void writeShift(byte data)
	{
		shiftOut(_DATA, _CLK, MSBFIRST, data);
		digitalWrite( _LATCH, HIGH );
		digitalWrite( _LATCH, LOW );
	}
};


#endif // SHIFT_UTILS_H
