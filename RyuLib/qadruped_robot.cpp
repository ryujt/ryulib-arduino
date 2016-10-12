#include <qadruped_robot.h>

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);

void qadruped_robot_init() {
  servos.begin();  
  servos.setPWMFreq(60); 
}

void leg_down(int n) {
  servos.setPWM(n+4, 0, pos0 + leg_down_angle[n]);
}

void leg_middle(int n) {
  servos.setPWM(n+4, 0, pos0 + ((leg_down_angle[n] + leg_up_angle[n]) / 2));
}

void leg_up(int n) {
  servos.setPWM(n+4, 0, pos0 + leg_up_angle[n]);
}

void arm_position(int n, int angle) {
  servos.setPWM(n, 0, pos0 + arm_start_angle[n] - angle);
}

void arm_start_position() {
  for (int i=0; i<4; i++) servos.setPWM(i, 0, pos0 + arm_start_angle[i]);  
}

void get_up() {
  arm_start_position();
  for (int n=0; n<4; n++) leg_down(n); 
}

void sit_down() {
  arm_start_position();
  for (int n=0; n<4; n++) leg_up(n); 
}

void forward() {
  int angle = 100;
  
  leg_middle(1);          
  leg_middle(2);          
  leg_up(0);
  leg_up(3);
  arm_position(0, angle);  
  arm_position(3, -angle);  
  delay(SERVO_INTERVAL);
  leg_down(0);
  leg_down(3);
  delay(SERVO_INTERVAL);
  leg_down(1);
  leg_down(2);
  arm_position(0, 0);  
  arm_position(3, 0);  
  delay(SERVO_INTERVAL);
  
  leg_middle(0);          
  leg_middle(3);          
  leg_up(1);
  leg_up(2);
  arm_position(1, -angle);  
  arm_position(2, angle);  
  delay(SERVO_INTERVAL);
  leg_down(1);
  leg_down(2);
  delay(SERVO_INTERVAL);
  leg_down(0);
  leg_down(3);
  arm_position(1, 0);  
  arm_position(2, 0);  
  delay(SERVO_INTERVAL);
}

void backward() {
  int angle = 100;
  
  leg_middle(1);          
  leg_middle(2);          
  leg_up(0);
  leg_up(3);
  arm_position(0, -angle);  
  arm_position(3, angle);  
  delay(SERVO_INTERVAL);
  leg_down(0);
  leg_down(3);
  delay(SERVO_INTERVAL);
  leg_down(1);
  leg_down(2);
  arm_position(0, 0);  
  arm_position(3, 0);  
  delay(SERVO_INTERVAL);
  
  leg_middle(0);          
  leg_middle(3);          
  leg_up(1);
  leg_up(2);
  arm_position(1, angle);  
  arm_position(2, -angle);  
  delay(SERVO_INTERVAL);
  leg_down(1);
  leg_down(2);
  delay(SERVO_INTERVAL);
  leg_down(0);
  leg_down(3);
  arm_position(1, 0);  
  arm_position(2, 0);  
  delay(SERVO_INTERVAL);
}

void turn_left() {
  int angle = 100;
  
  leg_middle(0);
  leg_middle(3);
  arm_position(0, -angle);  
  arm_position(3, -angle);  
  delay(SERVO_INTERVAL);
  leg_down(0);
  leg_down(3);
  delay(SERVO_INTERVAL);
  
  leg_middle(1);
  leg_middle(2);
  arm_position(0, 0);  
  arm_position(3, 0);  
  delay(SERVO_INTERVAL);
  leg_down(1);
  leg_down(2);
  delay(SERVO_INTERVAL);
}

void turn_right() {
  int angle = 100;
  
  leg_middle(0);
  leg_middle(3);
  arm_position(0, angle);  
  arm_position(3, angle);  
  delay(SERVO_INTERVAL);
  leg_down(0);
  leg_down(3);
  delay(SERVO_INTERVAL);
  
  leg_middle(1);
  leg_middle(2);
  arm_position(0, 0);  
  arm_position(3, 0);  
  delay(SERVO_INTERVAL);
  leg_down(1);
  leg_down(2);
  delay(SERVO_INTERVAL);
}
