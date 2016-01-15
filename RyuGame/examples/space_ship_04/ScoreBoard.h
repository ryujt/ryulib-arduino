#include <Arduino.h>
#include <RyuGame.h>
#include "Globals.h"

class ScoreBoard : public GameControlBase
{
private:
        int _ScoreTemp = 0;
        int _Score = 0;
public:
	void start() 
	{
	}

	void update(unsigned long tick) 
	{
                if (is_game_end == false) {
                        _ScoreTemp = _ScoreTemp + tick;
                        if (_ScoreTemp >= 100) {
                                _Score = _Score + (_ScoreTemp / 100);
                                _ScoreTemp = _ScoreTemp % 100;
                        }
                }

                _LCD->setTextSize(1);
                _LCD->setCursor(0,0);
                _LCD->println(_Score);                
	}
};
