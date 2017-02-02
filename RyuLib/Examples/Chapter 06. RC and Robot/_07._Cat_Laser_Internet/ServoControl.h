#ifndef SERVOCONTROL_H
#define SERVOCONTROL_H


#define SPEED 10


#include <Arduino.h>
#include <Servo.h> 


class ServoControl 
{
private:
	bool is_started_;
	long old_tick_;
	int count_;

	double x_;
	double y_;
	double dx_;
	double dy_;
	double speed_x_;
	double speed_y_;

	int range_x_min_;
	int range_x_max_;
	int range_y_min_;
	int range_y_max_;

	int pin_x_;
	int pin_y_;
	Servo servo_x_;
	Servo servo_y_;
public:
	ServoControl(int pin_x, int pin_y)
		: is_started_(false), old_tick_(0), count_(0),
		  x_(0), y_(0), dx_(0), dy_(0), speed_x_(0), speed_y_(0), 
		  range_x_min_(0), range_x_max_(1800), range_y_min_(0), range_y_max_(1800),
		  pin_x_(pin_x), pin_y_(pin_y), servo_x_(), servo_y_()
	{
	}

	void attach()
	{
		servo_x_.attach(pin_x_);
		servo_y_.attach(pin_y_);
	}

	void detach()
	{
		servo_x_.detach();
		servo_y_.detach();
	}

	void start()
	{
		is_started_ = true;
		old_tick_ = 0;

    attach();

  		srand( millis() );
  		dx_ = 1;
  		dy_ = 1;
		speed_x_ = (rand() % SPEED) + 3;
		speed_y_ = (rand() % SPEED) + 3;
	}

	void stop()
	{
		is_started_ = false;
    detach();    
	}

	void execute()
	{
		if (is_started_ == false) return;

		long tick = millis();
		long term;
		if ((tick > old_tick_) && (old_tick_ != 0)) count_ = count_ + (tick - old_tick_);
		old_tick_ = tick;
		
		if (count_ < 10) return;
		count_ = 0;

		x_ = x_ + (speed_x_ * dx_);
		if (x_ < range_x_min_) {
			x_ = range_x_min_;
	  		dx_ = dx_ * (-1);
			speed_x_ = (rand() % SPEED) + 3;
		}
		if (x_ > range_x_max_) {
			x_ = range_x_max_;
	  		dx_ = dx_ * (-1);
			speed_x_ = (rand() % SPEED) + 3;
		}

		y_ = y_ + (speed_y_ * dy_);
		if (y_ < range_y_min_) {
			y_ = range_y_min_;
	  		dy_ = dy_ * (-1);
			speed_y_ = (rand() % SPEED) + 3;
		}
		if (y_ > range_y_max_) {
			y_ = range_y_max_;
	  		dy_ = dy_ * (-1);
			speed_y_ = (rand() % SPEED) + 3;
		}

		servo_x_.write(x_ / 10);
		servo_y_.write(y_ / 10);
	}

	void setRangeX(int min, int max)
	{
		if (min < 0) min = 0;
		if (min > 180) min = 180;

		if (max < 0) max = 0;
		if (max > 180) max = 180;

		// 내부적으로는 각도를 0..1800의 범위로 다뤄서 움직임을 부드럽게 한다.
		range_x_min_ = min * 10;
		range_x_max_ = max * 10;
	}

	void setRangeY(int min, int max)
	{
		if (min < 0) min = 0;
		if (min > 180) min = 180;

		if (max < 0) max = 0;
		if (max > 180) max = 180;

		range_y_min_ = min * 10;
		range_y_max_ = max * 10;
	}
};


#endif // SERVOCONTROL_H
