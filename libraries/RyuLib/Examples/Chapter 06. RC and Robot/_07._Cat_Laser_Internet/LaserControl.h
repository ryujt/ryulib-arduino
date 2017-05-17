#ifndef LASER_CONTROL_H
#define LASER_CONTROL_H


#include <Arduino.h>


class LaserControl
{
private:
	int pin_;
public:
	LaserControl(int pin)
	{
		pin_ = pin;
		pinMode(pin, OUTPUT);
	}
	
	void execute(char ch)
	{
		switch (ch) {
		    case 'L':
		    case 'A':
		    case 'B':
		    case 'C': digitalWrite(pin_, HIGH); break;
		    case 'S': digitalWrite(pin_, LOW); break;
		}
	}
};


#endif // LASER_CONTROL_H