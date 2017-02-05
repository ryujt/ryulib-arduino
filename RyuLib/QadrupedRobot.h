#ifndef QADRUPED_ROBOT_H
#define QADRUPED_ROBOT_H


#include <Arduino.h>
#include <Servo.h> 


#define SERVO_INTERVAL 150

// 위 아래로 다리가 움직이는 정도
#define ANGLE_SIZE 20


class QadrupedRobot
{
private:
	Servo servos[8]; 

	int arm_start_angle[4];
	int leg_down_angle[4];
	int leg_up_angle[4];

public:
	QadrupedRobot()
		: servos()
	{
	}

	void prepare(int a[], int b[], int c[])
	{
		for (int i=0; i<4; i++) {
			arm_start_angle[i] = a[i];
			leg_down_angle[i]  = b[i];
			leg_up_angle[i]    = c[i];
		}
	}

	void attach(int pin_from)
	{
		for (int i=0; i<8; i++) {
			servos[i].attach(i + pin_from);
		}
	}

	void detach()
	{
		for (int i=0; i<8; i++) {
			servos[i].detach();
		}		
	}

	void legUp(int n)
	{
		servos[n+4].write(leg_up_angle[n]);
	}

	void legDown(int n)
	{
		servos[n+4].write(leg_down_angle[n]);
	}

	void setArmPosition(int n, int angle)
	{
		servos[n].write(arm_start_angle[n] - angle);
	}

	void SetArmStartPosition()
	{
		for (int i=0; i<4; i++) servos[i].write(arm_start_angle[i]);  
	}

	void getUp()
	{
		SetArmStartPosition();
		for (int n=0; n<4; n++) legDown(n); 
	}

	void sitDown()
	{
		SetArmStartPosition();
		for (int n=0; n<4; n++) legUp(n); 
	}

	void forward()
	{
		legDown(1);          
		legDown(2);          
		legUp(0);
		legUp(3);
		setArmPosition(0, ANGLE_SIZE);  
		setArmPosition(3, -ANGLE_SIZE);  
		delay(SERVO_INTERVAL);
		legDown(0);
		legDown(3);
		delay(SERVO_INTERVAL);
		legDown(1);
		legDown(2);
		setArmPosition(0, 0);  
		setArmPosition(3, 0);  
		delay(SERVO_INTERVAL);

		legDown(0);          
		legDown(3);          
		legUp(1);
		legUp(2);
		setArmPosition(1, -ANGLE_SIZE);  
		setArmPosition(2, ANGLE_SIZE);  
		delay(SERVO_INTERVAL);
		legDown(1);
		legDown(2);
		delay(SERVO_INTERVAL);
		legDown(0);
		legDown(3);
		setArmPosition(1, 0);  
		setArmPosition(2, 0);  
		delay(SERVO_INTERVAL);
	}

	void backward()
	{
		legDown(1);          
		legDown(2);          
		legUp(0);
		legUp(3);
		setArmPosition(0, -ANGLE_SIZE);  
		setArmPosition(3, ANGLE_SIZE);  
		delay(SERVO_INTERVAL);
		legDown(0);
		legDown(3);
		delay(SERVO_INTERVAL);
		legDown(1);
		legDown(2);
		setArmPosition(0, 0);  
		setArmPosition(3, 0);  
		delay(SERVO_INTERVAL);

		legDown(0);          
		legDown(3);          
		legUp(1);
		legUp(2);
		setArmPosition(1, ANGLE_SIZE);  
		setArmPosition(2, -ANGLE_SIZE);  
		delay(SERVO_INTERVAL);
		legDown(1);
		legDown(2);
		delay(SERVO_INTERVAL);
		legDown(0);
		legDown(3);
		setArmPosition(1, 0);  
		setArmPosition(2, 0);  
		delay(SERVO_INTERVAL);
	}

	void turnLeft()
	{
		legDown(1);
		legDown(2);
		legUp(0);
		legUp(3);
		setArmPosition(0, -ANGLE_SIZE);  
		setArmPosition(3, -ANGLE_SIZE);  
		delay(SERVO_INTERVAL);
		legDown(0);
		legDown(3);
		delay(SERVO_INTERVAL);

		legUp(1);
		legUp(2);
		setArmPosition(1, -ANGLE_SIZE);  
		setArmPosition(2, -ANGLE_SIZE);  
		delay(SERVO_INTERVAL);
		legDown(1);
		legDown(2);
		delay(SERVO_INTERVAL);

		setArmPosition(0, 0);  
		setArmPosition(1, 0);  
		setArmPosition(2, 0);  
		setArmPosition(3, 0);  
	}

	void turnRight()
	{
		legDown(1);
		legDown(2);
		legUp(0);
		legUp(3);
		setArmPosition(0, ANGLE_SIZE);  
		setArmPosition(3, ANGLE_SIZE);  
		delay(SERVO_INTERVAL);
		legDown(0);
		legDown(3);
		delay(SERVO_INTERVAL);

		legUp(1);
		legUp(2);
		setArmPosition(1, ANGLE_SIZE);  
		setArmPosition(2, ANGLE_SIZE);  
		delay(SERVO_INTERVAL);
		legDown(1);
		legDown(2);
		delay(SERVO_INTERVAL);

		setArmPosition(0, 0);  
		setArmPosition(1, 0);  
		setArmPosition(2, 0);  
		setArmPosition(3, 0);  		
	}
};

#endif // QADRUPED_ROBOT_H
