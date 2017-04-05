#ifndef SOUND_CONTROL_H
#define SOUND_CONTROL_H


#include <Arduino.h>
#include <sound_effect.h>


class SoundControl
{
private:
	int pin_;
public:
	SoundControl(int pin)
	{
		pin_ = pin;
		pinMode(pin, OUTPUT);
	}
	
	void execute(char ch)
	{
		switch (ch) {
		    case '1': seR2D2(pin_); break;
		    case '2': seLaugh(pin_); break;
		    case '3': seSqueak(pin_); break;
		    case '4': seWaka(pin_); break;
		    case '5': seCatcall(pin_); break;
		    case '6': seChang(pin_); break;
		    case '7': seCoo(pin_); break;
		    case '8': seOh(pin_); break;
		    case '9': seSiren(pin_); break;
		    case '0': seTonarkade(pin_); break;
			}
	}
};


#endif // SOUND_CONTROL_H