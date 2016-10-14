#include <qadruped_robot.h>

int arm_start_angle[] = { 150, 205, 180,  80 };
int leg_down_angle[]  = { 140,   0, 180, 200 };
int leg_up_angle[]    = {  80, 230, 230, 100 };

void setup() {
  qadruped_robot_init();

  get_up();
  delay(1000);
}

void down_up_test() {
  sit_down();
  delay(1000);
   
  get_up();
  delay(1000);
}

void leg_test() {
  for (int n=0; n<4; n++) {
    get_up(); 
    delay(SERVO_INTERVAL);

    sit_down();
    delay(SERVO_INTERVAL);
  }  
}

void loop() {  
  down_up_test();
  delay(1000);
  
//  leg_test();
//  delay(1000);
//  
  turn_left();
  turn_left();
  delay(1000);
  
  turn_right();
  turn_right();
  delay(1000);

  for (int i=0; i<4; i++) forward();
  delay(1000);

  for (int i=0; i<4; i++) backward();
  delay(1000);
}

