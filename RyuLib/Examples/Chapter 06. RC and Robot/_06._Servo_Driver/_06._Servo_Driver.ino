#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);

const int pos0   = 172; // 0°
const int pos180 = 565; // 180°

void setup() {
  Serial.begin(9600);
  
  servos.begin();  
  servos.setPWMFreq(60); 
}

void loop() {  
  for (int n=0; n<16; n++) {
    servos.setPWM(n, 0, pos0);
  }
  delay(2000);

  for (int n=0; n<16; n++) {
    servos.setPWM(n, 0, pos180);
  }
  delay(2000);
}

