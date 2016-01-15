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

static const unsigned char PROGMEM missile_image[] =
{ 
        B00100000,
        B01110000,
        B11111000,
        B01110000
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
                sound_effect_fire(_Engine->getAudioTrack());

                _ID = Missile_ID;

                _X = x;
                _Y = y;

                _HitSize = 2;
        }

        void update(unsigned long tick) 
        {
                _LCD->drawBitmap(_X-2, _Y-2, missile_image, 5, 4, BLACK);                

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

                                sound_effect_bang(_Engine->getAudioTrack());
                        }
                }
        }
};

class SpaceShip : public GameControlBase
{
private: 
        int _FireInterval = 0;

        int _MissileCountTick = 0;
        int _MissileCount = 0;

        void fire() 
        {
                if (_MissileCount <= 0) return;

                _MissileCount--;

                Missile *missile = new Missile();
                _Layer->addControl(missile);
                missile->start(_X, _Y);
        }
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

                // Add missile count on every 5 second.
                if (_MissileCount < 3) _MissileCountTick = _MissileCountTick + tick;
                if (_MissileCountTick >= 5000) {
                        if (_MissileCount < 3) _MissileCount++;
                        _MissileCountTick = 0;
                }

                // Prevent _FireInterval from overflowing.
                if (_FireInterval < 1000) _FireInterval = _FireInterval + tick;

                if (is_fire_down) {
                        if (_FireInterval >= 200) {
                                _FireInterval = 0;
                                fire();
                        }
                }

                if (_X < 4) _X = 4;
                if (_X > 78) _X = 78;    

                _LCD->drawBitmap(_X-3, _Y-3, ship_image, 8, 7, BLACK);

                for (int i=1; i<=_MissileCount; i++) {
                        _LCD->drawBitmap(84 - (6 * i), 0, missile_image, 5, 4, BLACK);                
                }

                GameControlBase *control = checkCollision();
                if (control != NULL) {
                        if (control->getID() == Missile_ID) return;

                        is_game_end = true;
                        control->setIsDeleted(true);
                        _IsDeleted = true;

                        sound_effect_game_end(_Engine->getAudioTrack());
                }
	}
};
