#ifndef BOARD_H
#define BOARD_H


#include <RyuGame.h>
#include <digit_image.h>
#include "Globals.h"


static const unsigned char PROGMEM block_image[] =
{ 
        B11100000,
        B10100000,
        B11100000
};


class Board : public GameControlBase
{
private:  
        int _score;

        bool _cells[BOARD_WIDTH][BOARD_HEIGHT];

        bool check_full_line(int ay) 
        {
                bool is_full = true;
                
                for (int x=0; x<BOARD_WIDTH; x++) {
                        if (_cells[x][ay] == false) {
                                is_full = false;
                                break;
                        }
                }

                return is_full;
        }

        void erase_line(int ay) 
        {
                for (int y=ay; y>0; y--) {
                        for (int x=0; x<BOARD_WIDTH; x++) _cells[x][y] = _cells[x][y-1];
                }

                for (int x=0; x<BOARD_WIDTH; x++) _cells[x][0] = false;
        }
public:
        Board ()
        {
                _score = 0;
        }

        void start() 
        {
                memset(_cells, 0, sizeof(_cells));
        }

        void update(unsigned long tick) 
        {
                _LCD->drawRect(0, 0, 60+2, 30+2, BLACK);

                _LCD->drawRect(0, 0, 60+2, 30+2, BLACK);

                draw_number(_LCD, 4, 4, _score);

                for (int y=0; y<BOARD_HEIGHT; y++)
                for (int x=0; x<BOARD_WIDTH; x++)
                        if (_cells[x][y])
                                _LCD->drawBitmap(62 - y*3 - 4, x*3 + 1, block_image, 3, 3, BLACK);                
        }

        bool can_move(int ax, int ay) 
        {
                return (_cells[ax][ay] == false) and can_move_block_to(ax, ay);
        }

        bool setBlock(int ax, int ay) 
        {
                if (_cells[ax][ay]) {
                        return false;
                } else {
                        _cells[ax][ay] = true;
                        return true;
                }
        }

        bool erase_full_line() 
        {
                bool result = false;

                int count = 0;
                for (int y=0; y<BOARD_HEIGHT; y++) {
                        if (check_full_line(y)) {
                                result = true;
                                erase_line(y);
                                count = count + 1;
                        }
                }

                _score = _score + count;

                switch (count) {
                        case 2: _score = _score + 1; break;
                        case 3: _score = _score + 2; break;
                        case 4: _score = _score + 5; break;
                }

                return result;
        }
};


#endif // BOARD_H
