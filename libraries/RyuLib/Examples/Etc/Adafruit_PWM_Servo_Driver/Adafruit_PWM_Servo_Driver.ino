#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

const unsigned int pos0   = 172; // 0°
const unsigned int pos180 = 565; // 180°  

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);

void setup() {
  servos.begin();  
  servos.setPWMFreq(60); 

  for (int i=0; i<16; i++) {
    servos.setPWM(i, 0, pos0);
  }

}

void loop() {
  for (int i=pos0; i<pos180; i++) {
    servos.setPWM(8, 0, i);
    delay(10);
  }

  for (int i=pos180; i>pos0; i--) {
    servos.setPWM(8, 0, i);
    delay(10);
  }
}
