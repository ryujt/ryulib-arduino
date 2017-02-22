#include <Servo.h> 

Servo servos[8]; 

void setup() {
  for (int i = 0; i < 8; i++) {
    servos[i].attach(i + 4);
    servos[i].write(0);
  }
}

double angle;

void loop() {
  for (angle = 0; angle < 180; angle++) { 
    for (int i = 0; i < 8; i++) servos[i].write(angle);
    delay(40); 
  } 

  for (angle = 180; angle > 0; angle--) { 
    for (int i = 0; i < 8; i++) servos[i].write(angle);
    delay(40); 
  } 
}
