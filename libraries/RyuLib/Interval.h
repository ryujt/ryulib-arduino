#ifndef INTERVAL_H
#define INTERVAL_H

#include <Arduino.h>


class Interval 
{
private:
	long interval_;
	long old_tick_;
	long count_;
public:
	Interval(long interval)
		: interval_(interval), old_tick_(0), count_(0)
	{		
	}

	void restart()
	{
		old_tick_ = 0;
		count_ = 0;
	}

	bool onTime()
	{
		long tick = millis();
		long term;
		if ((tick < old_tick_) || (old_tick_ == 0)) term = 0;
		else term = tick - old_tick_;
		old_tick_ = tick;

		count_ = count_ + term;

		if (count_ >= interval_) {
			count_ = 0;
			// Serial.println("count_ >= interval_");
			return true;
		}

		return false;
	}
};


#endif // INTERVAL_H
