#include <Arduino.h>


class Satellite
{
private:	
	VoidEvent OnAskPosition_;
	VoidEvent OnClearPosition_;
	VoidEvent OnAddPosition_;
	VoidEvent OnSetPosition_;
public:
	Satellite()
	{

	}	

	void tick()
	{
	}

	void sendPosition(double lat, double lon)
	{

	}

	void setOnAskPosition(VoidEvent event) { OnAskPosition_ = event; } 
	void setOnClearPosition(VoidEvent event) { OnClearPosition_ = event; } 
	void setOnAddPosition(VoidEvent event) { OnAddPosition_ = event; } 
	void setOnSetPosition(VoidEvent event) { OnSetPosition_ = event; } 
};