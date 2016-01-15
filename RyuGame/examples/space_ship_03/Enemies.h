#include <Arduino.h>
#include <RyuGame.h>
#include "Globals.h"


// How offent do enemy appear.  Large number get low chance.
#define chance_enemy 10


class Enemy : public GameControlBase
{
public:
        void start() 
        {
                _X = rand() % 84;
                _Y = -5;

                _HitSize = 4; 
        }

        void update(unsigned long tick) 
        {
                _LCD->fillCircle(_X, _Y, 4, BLACK);

                _Y++;

                if (_Y > 52) _IsDeleted = true;
        }
};


class Enemies : public GameControlBase
{
private:
public:
	void start() 
	{
                srand(analogRead(0));
	}

	void update(unsigned long tick) 
	{
                if ((rand() % chance_enemy) != 0) return;

                Enemy *enemy = new Enemy();
                enemy->start();

                GameLayer *layer = (GameLayer *) _Layer;
                layer->addControl(enemy);
	}
};
