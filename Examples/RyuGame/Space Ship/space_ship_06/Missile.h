#ifndef MISSILE_H
#define MISSILE_H


#include <Arduino.h>
#include <RyuGame.h>
#include "Globals.h"
#include "Enemies.h"


#define Missile_ID 1


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
        Missile(int ax, int ay) 
        {
                _ID = Missile_ID;

                x = ax;
                y = ay;

                _HitSize = 2;
        }

        void start() 
        {
        }

        void update(unsigned long tick) 
        {
                _LCD->drawBitmap(x-2, y-2, missile_image, 5, 4, BLACK);                

                y--;

                if (y < -1) {
                        _IsDeleted = true;
                        return;
                }

                GameControlBase *control = checkCollision();
                if (control != NULL) {
                        if (control->getID() == Enemy_ID) {                                
                                control->setDeleted(true);
                                _IsDeleted = true;

                                sound_effect_bang(_Engine->getAudioTrack());
                        }
                }
        }
};


#endif // MISSILE_H