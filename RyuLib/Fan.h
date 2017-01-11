#ifndef FAN_H
#define FAN_H

#include <Arduino.h>
#include <MAX7219.h>


class Fan 
{
private:
	int clk_;
	int cs_;
	int din_;
	int index_;
	MAX7219 *max7219_;

	char images[4][8] = {
		{ 0x08, 0x08, 0x08, 0xF8, 0x1F, 0x10, 0x10, 0x10 },
		{ 0x20, 0x20, 0x27, 0x18, 0x18, 0xE4, 0x04, 0x04 },
		{ 0x81, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x81 },
		{ 0x04, 0x04, 0xC8, 0x38, 0x1C, 0x13, 0x20, 0x20 }
	};
public:
	Fan(int clk, int cs, int din)
		: clk_(clk), cs_(cs), din_(din)
	{
		index_ = 0;
		max7219_ = new MAX7219(clk, cs, din);
	}

	void begin() 
	{
		max7219_->begin();
	}

	void turn() 
	{
		for (int i=0; i<8; i++) max7219_->write(i+1, images[index_][i]);
		index_++;
		if (index_ >= 4) index_ = 0;
	}

	void stop()
	{
		index_ = 0;
		for (int i=0; i<8; i++) max7219_->write(i+1, images[index_][i]);
	}
};


#endif // FAN_H
