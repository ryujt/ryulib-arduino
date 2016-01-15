#include <Arduino.h>
#include <RyuGame.h>

class Control : public GameControlBase
{
private:
public:
	void start() 
	{

	}

	void update(unsigned long tick) 
	{
    	_LCD->fillCircle(10, 10, 5, BLACK);
	}
};
