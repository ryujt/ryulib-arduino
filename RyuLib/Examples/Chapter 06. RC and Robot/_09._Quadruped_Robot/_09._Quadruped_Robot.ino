#include <SoftwareSerial.h>
#include <QadrupedRobot.h>

QadrupedRobot robot;
SoftwareSerial bluetooth(2, 3);

void setup() {
  Serial.begin(9600);
  
  bluetooth.begin(9600);

  int arm_start_angle[] = { 150,  50,   50, 150 };
  int leg_down_angle[]  = { 150,  10,   20, 165 };
  int leg_up_angle[]    = { 130,  30,   40, 145 };
  robot.prepare(arm_start_angle, leg_down_angle, leg_up_angle);

  robot.attach(4);
  
  robot.getUp();
  delay(SERVO_INTERVAL);
}

char cmd = 0x00;

void loop() {  
  while (bluetooth.available() > 0) {
    cmd = bluetooth.read();
    Serial.println(cmd);
  }

  switch (cmd) {
    case 'U': robot.getUp(); break;
    case 'L': robot.turnLeft(); break;
    case 'R': robot.turnRight(); break;
    case 'F': robot.forward(); break;
    case 'B': robot.backward(); break;
  }
}

