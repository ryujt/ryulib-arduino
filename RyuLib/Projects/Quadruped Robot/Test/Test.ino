#include <qadruped_robot.h>

int arm_start_angle[] = {  70, 230, 180, 180 };
int leg_down_angle[]  = { 300,   0,   0, 300 };
int leg_up_angle[]    = {  50, 350, 350,  50 };

void setup() {
  qadruped_robot_init();

  get_up();
  delay(1000);

//  sit_down();
//  turn_left();
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
  
  leg_test();
  delay(1000);
  
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

