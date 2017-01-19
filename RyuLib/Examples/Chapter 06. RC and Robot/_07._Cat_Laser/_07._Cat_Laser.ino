#include <Servo.h> 

Servo servo_01; 
Servo servo_02; 

void setup() {
  pinMode(0, OUTPUT);
  digitalWrite(0, HIGH);
  
  servo_01.attach(9);
  servo_02.attach(8);

  servo_01.write(0); 
  servo_02.write(0); 
}

double angle;

void loop() {
  for(angle = 0; angle < 180; angle++) { 
    servo_01.write(angle); 
    servo_02.write( sin(angle / 10) * 20 + 30 ); 
    delay(40); 
  } 

  for(angle = 180; angle > 0; angle--) { 
    servo_01.write(angle); 
    delay(40); 
  } 
}
