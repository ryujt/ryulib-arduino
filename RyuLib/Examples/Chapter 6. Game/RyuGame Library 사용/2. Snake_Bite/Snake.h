#ifndef SNAKE_H
#define SNAKE_H


#include <Arduino.h>
#include <RyuGame.h>
#include "Globals.h"


#define MAX_KNUCKLE_COUNT 128


static const unsigned char PROGMEM snake_head_image[] =
{ 
        B01100000,
        B11110000,
        B11110000,
        B01100000
};

static const unsigned char PROGMEM snake_nuckle_image[] =
{ 
        B01100000,
        B10010000,
        B10010000,
        B01100000
};


struct Points
{
    char x, y;
};


class Snake : public GameControlBase
{
private:
        int tick_count = 0;
        int dx = -1;
        int dy = 0;
        int speed = 400;
        int nuckle_size = 3;
        Points knuckles[MAX_KNUCKLE_COUNT];
public:
        Snake() 
        {
                x = 10;
                y =  5;

                for (int i=0; i<MAX_KNUCKLE_COUNT; i++) knuckles[i] = {255, 255};
        }

        void start() 
        {
        }

        void update(unsigned long tick) 
        {
                _LCD->drawRoundRect(0, 0, 84, 48, 0, BLACK);

                if (is_game_end) {
                        _LCD->fillRoundRect(10, 16, 64, 16, 3, BLACK);

                        _LCD->setTextSize(1);

                        _LCD->setCursor(13, 20);
                        _LCD->setTextColor(WHITE);
                        _LCD->print("GAME OVER!");

                        _LCD->setCursor(4, 4);
                        _LCD->setTextColor(BLACK);
                        _LCD->print("Score: ");
                        _LCD->print(nuckle_size - 3);

                        return;
                }

                tick_count = tick_count + tick;

                if (tick_count >= speed) {
                        for (int i=1; i<nuckle_size; i++) knuckles[nuckle_size-i] = knuckles[nuckle_size-i-1];

                        knuckles[0] = {x, y};

                        x = x + dx;
                        y = y + dy;

                        if (speed > 100) speed--;
                        tick_count = 0;
                }

                _LCD->drawBitmap(x*4, y*4, snake_head_image, 4, 4, BLACK);         

                for (int i=0; i<MAX_KNUCKLE_COUNT; i++) {
                        _LCD->drawBitmap(knuckles[i].x*4, knuckles[i].y*4, snake_nuckle_image, 4, 4, BLACK);         
                        if ((x==knuckles[i].x) &&(y==knuckles[i].y)) is_game_end = true;
                }

                if (x <  0) is_game_end = true;
                if (x > 20) is_game_end = true;
                if (y <  0) is_game_end = true;
                if (y > 11) is_game_end = true;
        }

        void setDX(int value) 
        { 

                if (value == 0) return;

                // 바로 반대 방향으로는 못 감
                if (dx == (-value)) return;

                dy = 0;
                dx = value; 
        }

        void setDY(int value) 
        { 
                if (value == 0) return;

                // 바로 반대 방향으로는 못 감
                if (dy == (-value)) return;

                dx = 0;
                dy = value; 
        }

        void incSize() 
        {
                if (nuckle_size < MAX_KNUCKLE_COUNT) nuckle_size++;
        }
};


#endif // SNAKE_H
