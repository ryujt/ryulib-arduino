#ifndef FOOODS_H
#define FOOODS_H


#include <Arduino.h>
#include <RyuGame.h>
#include "Globals.h"


// 21 x 12 cells
#define MAX_FOOD_COUNT 252


static const unsigned char PROGMEM food_image[] =
{ 
    B00000000,
    B01100000,
    B01100000,
    B00000000
};

class Foods : public GameControlBase
{
private:
        int tick_count = 0;
        bool has_food[MAX_FOOD_COUNT];
public:
        Foods() 
        {
            for (int i=0; i<MAX_FOOD_COUNT; i++) has_food[i] = false;
        }

        void start() 
        {
        }

        void update(unsigned long tick) 
        {
                if (is_game_end) return;

                tick_count = tick_count + tick;

                if (tick_count >= 2000) {
                    srand(millis());
                    has_food[rand() % MAX_FOOD_COUNT] = true;

                    tick_count = 0;
                }

                for (int i=0; i<MAX_FOOD_COUNT; i++) 
                    if (has_food[i]) 
                        _LCD->drawBitmap((i % 21) * 4, (i / 21) * 4, food_image, 4, 4, BLACK);         
        }

        bool eat(int x, int y)
        {
            int index = (y * 21) + x;
            bool result = has_food[index];
            has_food[index] = false;
            return result;
        }
};


#endif // FOOODS_H
