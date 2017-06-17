#include <Arduino.h>
#include "Events.h"

class LocationSensor
{
private:
	VoidEvent OnError_;
	VoidEvent OnPosition_;
public:
	LocationSensor()
	{

	}

	void tick()
	{
	}

	void clearPositions(double lat, double lon)
	{ 
	}

	void addPosition(double lat, double lon)
	{ 
	}

	void getDirection() { }

	void getLat() { }
	void getLon() { }

	void setPosition(double lat, double lon)
	{ 
	}
		
	void setOnError(VoidEvent event) { OnError_ = event; } 
	void setOnPosition_(VoidEvent event) { OnPosition_ = event; } 
};