#ifndef IR_UTILS_H
#define IR_UTILS_H


#include <Arduino.h>
#include <IRremote.h>


class IR
{
private:
	IRrecv irrecv;
	decode_results results;
public:
	IR(int pin) 
		: irrecv(pin)
	{}

	void begin() 
	{
		irrecv.enableIRIn();
	}

	unsigned long read()
	{
		if (irrecv.decode(&results))	{
			unsigned long result = results.value;
			irrecv.resume();
			return result;
		} else {
			return 0;
		}
	}	
};


#endif // IR_UTILS_H
