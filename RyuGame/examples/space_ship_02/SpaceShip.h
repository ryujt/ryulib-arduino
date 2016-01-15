#include <Arduino.h>
#include <RyuGame.h>
#include "Globals.h"

class SpaceShip : public GameControlBase
{
private:
public:
	void start() 
	{
                _X = 43;
                _Y = 45;
	}

	void update(unsigned long tick) 
	{
                if (is_left_down) _X++;
                if (is_right_down) _X--;

                if (_X < 2) _X = 2;
                if (_X > 81) _X = 81;    

                _LCD->fillCircle(_X, _Y, 2, BLACK);
	}
};
