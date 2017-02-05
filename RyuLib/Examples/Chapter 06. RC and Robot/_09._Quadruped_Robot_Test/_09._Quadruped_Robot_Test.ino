#include <QadrupedRobot.h>

QadrupedRobot robot;

void setup() {
  int arm_start_angle[] = { 150,  50,   50, 150 };
  int leg_down_angle[]  = { 150,  10,   20, 165 };
  int leg_up_angle[]    = { 130,  30,   40, 145 };
  robot.prepare(arm_start_angle, leg_down_angle, leg_up_angle);

  robot.attach(4);

//  robot.getUp();
//  delay(1000);
}

void down_up_test() {
  robot.sitDown();
  delay(1000);
   
  robot.getUp();
  delay(1000);
}

void loop() {  
//  return;
  
  down_up_test();
  delay(1000);
  
  robot.turnLeft();
  robot.turnLeft();
  delay(1000);
  
  robot.turnRight();
  robot.turnRight();
  delay(1000);

  for (int i=0; i<4; i++) robot.forward();
  delay(1000);

  for (int i=0; i<4; i++) robot.backward();
  delay(1000);
}

