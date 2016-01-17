#include <Arduino.h>
#include <RyuGame.h>
#include "Globals.h"


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

class Missile : public GameControlBase
{
private:
public:
        void start() 
        {
        }

        void start(int x, int y) 
        {
                _ID = Missile_ID;

                _X = x;
                _Y = y;

                _HitSize = 2;
        }

        void update(unsigned long tick) 
        {
                _LCD->fillCircle(_X, _Y, 2, BLACK);

                _Y--;

                if (_Y < -1) {
                        _IsDeleted = true;
                        return;
                }

                GameControlBase *control = checkCollision();
                if (control != NULL) {
                        if (control->getID() == Enemy_ID) {                                
                                control->setIsDeleted(true);
                                _IsDeleted = true;
                        }
                }
        }
};

class SpaceShip : public GameControlBase
{
private:
        int _MissileCount = 0;
public:
	void start() 
	{
                _X = 43;
                _Y = 45;

                _HitSize = 3; 
	}

	void update(unsigned long tick) 
	{
                if (is_left_down) _X++;
                if (is_right_down) _X--;

                if (_MissileCount < 1000) _MissileCount = _MissileCount + tick;

                if (is_fire_down && (_MissileCount >= 100) && (score >= 100)) {
                        _MissileCount = 0;
                        score = score - 100;

                        Missile *missile = new Missile();
                        missile->start(_X, _Y);

                        _Layer->addControl(missile);
                }

                if (_X < 4) _X = 4;
                if (_X > 78) _X = 78;    

                _LCD->drawBitmap(_X-3, _Y-3, ship_image, 8, 7, BLACK);                

                GameControlBase *control = checkCollision();
                if (control != NULL) {
                        if (control->getID() == Missile_ID) return;

                        is_game_end = true;
                        control->setIsDeleted(true);
                        _IsDeleted = true;
                }
	}
};
