#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

const int SERVO_INTERVAL = 100;

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);

unsigned int pos0   = 172; // 0°
unsigned int pos180 = 565; // 180°  

void setup() {
  Serial.begin(9600);
  
  servos.begin();  
  servos.setPWMFreq(60); 
}

void loop() {  
  for (int n=0; n<16; n++) {
    for (int i=pos0; i<pos180; i=i+10) {
      servos.setPWM(n, 0, i);
      delay(100);
    }
  }
}

