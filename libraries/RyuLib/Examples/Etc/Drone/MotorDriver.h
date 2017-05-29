#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H

#include <Arduino.h>
#include <MAX7219.h>


class MotorDriver 
{
private:
	int height_;
	int x_;
	int y_;

	int pin_m1;
	int pin_m2;
	int pin_m3;
	int pin_m4; 

	void do_pwm_output() {
		int value = height_;

		// Serial.print(height_, DEC);  Serial.print(" ");
		// Serial.print(x_, DEC);  Serial.print(" ");
		// Serial.print(y_, DEC);  Serial.println(" ");

		int m1 = height_ + x_ + y_;
		int m2 = height_ + x_ - y_;
		int m3 = height_ - x_ - y_;
		int m4 = height_ - x_ + y_;

		if (m1 < 0) m1 = 0;
		if (m2 < 0) m2 = 0;
		if (m3 < 0) m3 = 0;
		if (m4 < 0) m4 = 0;

		if (m1 > 255) m1 = 255;
		if (m2 > 255) m2 = 255;
		if (m3 > 255) m3 = 255;
		if (m4 > 255) m4 = 255;

		analogWrite(pin_m1, m1);
		analogWrite(pin_m2, m2);
		analogWrite(pin_m3, m3);
		analogWrite(pin_m4, m4);

		// Serial.print(m1, DEC);  Serial.print(" ");
		// Serial.print(m2, DEC);  Serial.print(" ");
		// Serial.print(m3, DEC);  Serial.print(" ");
		// Serial.print(m4, DEC);  Serial.println(" ");
	}
public:
	MotorDriver() 
		: height_(0), x_(0), y_(0), pin_m1(3), pin_m2(5), pin_m3(6), pin_m4(9)
	{

	}

	void begin() {
		height_ = 0;
		x_ = 0;
		y_ = 0;

		pinMode(pin_m1, OUTPUT);
		pinMode(pin_m2, OUTPUT);
		pinMode(pin_m3, OUTPUT);
		pinMode(pin_m4, OUTPUT);

		analogWrite(pin_m1, 0);
		analogWrite(pin_m2, 0);
		analogWrite(pin_m3, 0);
		analogWrite(pin_m4, 0);
	}

	void setHeight(int value) {
		height_ = value ;
		do_pwm_output();
	}

	void setX(int value) {
		x_ = (value * height_) / 2000;
		do_pwm_output();
	}

	void setY(int value) {
		y_ = (value * height_) / 2000;
		do_pwm_output();
	}
};


#endif // MOTORDRIVER_H
