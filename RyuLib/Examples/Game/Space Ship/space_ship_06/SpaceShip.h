#ifndef SPACESHIP_H
#define SPACESHIP_H


#include <Arduino.h>
#include <RyuGame.h>

static const unsigned char PROGMEM ship_image[] =
{ 
        B10011001,
        B10011001,
        B10111101,
        B11111111,
        B10111101,
        B10011001,
        B10011001
};

class SpaceShip : public GameControlBase
{
private:
public:
	void start() 
	{
		x = 43;
		y = 45;

        _HitSize = 3;
	}

	void update(unsigned long tick) 
	{
		_LCD->drawBitmap(x-3, y-3, ship_image, 8, 7, BLACK);
	}
};


#endif // SPACESHIP_H