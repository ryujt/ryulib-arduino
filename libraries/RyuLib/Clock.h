#ifndef CLOCK_H
#define CLOCK_H

#include <Arduino.h>
#include <DS1302.h>

const uint8_t TM1637_Segment[] = {
	// XGFEDCBA
	0b00111111,    // 0
	0b00000110,    // 1
	0b01011011,    // 2
	0b01001111,    // 3
	0b01100110,    // 4
	0b01101101,    // 5
	0b01111101,    // 6
	0b00000111,    // 7
	0b01111111,    // 8
	0b01101111,    // 9
	0b01110111,    // A
	0b01111100,    // b
	0b00111001,    // C
	0b01011110,    // d
	0b01111001,    // E
	0b01110001     // F
};

class Clock 
{
private:
	DS1302 rtc;
	long old_tick;
	long tick_count;

public:
	Clock(int ce, int io, int clk)
		: rtc(ce, io, clk), old_tick(0), tick_count(0) 
	{
	}

	void begin()
	{
  		rtc.writeProtect(false);
  		rtc.halt(false);
	}

	void incHour()
	{
		Time time = rtc.time();
		time.hr++;
		if (time.hr > 23) time.hr = 0;		
		rtc.time(time);
	}

	void decHour()
	{
		Time time = rtc.time();
		time.hr--;
		if (time.hr < 0) time.hr = 23;		
		rtc.time(time);
	}

	void incMinute()
	{
		Time time = rtc.time();
		time.min++;
		if (time.min > 59) time.min = 0;		
		rtc.time(time);
	}

	void decMinute()
	{
		Time time = rtc.time();
		time.min--;
		if (time.min < 0) time.min = 59;				
		rtc.time(time);
	}

	int getHour() 
	{
		Time time = rtc.time();
		return time.hr;
	}

	int getMinute() 
	{
		Time time = rtc.time();
		return time.min;
	}


	int getSecond()
	{
		Time time = rtc.time();
		return time.sec;
	}

	void set(int hour, int minute, int second) 
	{
		Time time = rtc.time();
		time.hr  = hour;
		time.min = minute;
		time.sec = second;
		rtc.time(time);
	}

	void setSegments(uint8_t data[])
	{
		Time time = rtc.time();

		int hr_lo = time.hr % 10;
		int hr_hi = (time.hr - hr_lo) / 10;

		if (hr_hi < 1) data[0] = TM1637_Segment[0];
		else data[0] = TM1637_Segment[hr_hi];

		if (hr_lo < 1) data[1] = TM1637_Segment[0];
		else data[1] = TM1637_Segment[hr_lo];

		int min_lo = time.min % 10;
		int min_hi = (time.min - min_lo) / 10;

		if (min_hi < 1) data[2] = TM1637_Segment[0];
		else data[2] = TM1637_Segment[min_hi];

		if (min_lo < 1) data[3] = TM1637_Segment[0];
		else data[3] = TM1637_Segment[min_lo];

		long tick = millis();
		tick_count = tick_count + tick - old_tick;
		old_tick = tick;

		if (tick_count < 500) data[1] = data[1] | 0b10000000;

		if (tick_count > 1000) tick_count = 0;
	}
};


#endif // CLOCK_H