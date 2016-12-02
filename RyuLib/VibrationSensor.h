#ifndef VIBRATIONSENSOR_H
#define VIBRATIONSENSOR_H

#include <Arduino.h>


class VibrationSensor 
{
private:
	unsigned long old_tick_;
	int old_state_;
	int pin_;
	int active_count_;
	int capacity_;
public:
	VibrationSensor(int pin)
	{
		old_tick_ = 0;
		active_count_ = 0;
		capacity_ = 1000;		
		pin_ = pin;
	}

	bool isActive() {
		int state = digitalRead(2);

		if (state != old_state_) {
			old_state_ = state;
			unsigned long old_tick_ = millis();
			active_count_ = capacity_;
		}

		if (active_count_ > 0) {
			unsigned long tick = millis();
			if (tick > old_tick_) active_count_ = active_count_ - (tick - old_tick_);
			old_tick_ = tick;
		}

		return active_count_ > 0;
	}

	void setCapacity(int capacity) { capacity_ = capacity; }
};


#endif // VIBRATIONSENSOR_H
