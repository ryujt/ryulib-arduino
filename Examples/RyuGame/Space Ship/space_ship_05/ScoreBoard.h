#ifndef SCOREBOARD_H
#define SCOREBOARD_H


#include <Arduino.h>
#include <RyuGame.h>
#include "Globals.h"

class ScoreBoard : public GameControlBase
{
private:
        bool _Stoped = false;
        int _Score = 0;
        int _ScoreTemp = 0;
public:
	void start() 
	{
	}

	void update(unsigned long tick) 
	{
                if (_Stoped == false) {
                        _ScoreTemp = _ScoreTemp + tick;
                        if (_ScoreTemp >= 100) {
                                _Score = _Score + (_ScoreTemp / 100);
                                _ScoreTemp = _ScoreTemp % 100;
                        }
                }

                _LCD->setTextSize(1);
                _LCD->setCursor(0, 0);
                _LCD->println(_Score);                
	}

        void stop() 
        {
                _Stoped = true;
        }
};


#endif // SCOREBOARD_H