#include <SoftwareSerial.h>
#include <Servo.h> 

SoftwareSerial bluetooth(2, 3);
Servo servo_left; 
Servo servo_right; 

void setup() {
  Serial.begin(9600);

  bluetooth.begin(9600);

  servo_left.attach(4);
  servo_right.attach(5);

  servo_left.write(90);
  servo_right.write(90);
}

char cmd = 0x00;

void loop() {
  if (bluetooth.available() > 0) {  
    cmd = bluetooth.read();
    Serial.println(cmd);
  }

  if (cmd == 'S') {
    servo_left.write(90);
    servo_right.write(90);
  } else if (cmd == 'F') {
    servo_left.write(0);
    servo_right.write(180);
  } else if (cmd == 'B') {
    servo_left.write(180);
    servo_right.write(0);
  } else if (cmd == 'L') {
    servo_left.write(0);
    servo_right.write(0);
  } else if (cmd == 'R') {
    servo_left.write(180);
    servo_right.write(180);
  }
}
