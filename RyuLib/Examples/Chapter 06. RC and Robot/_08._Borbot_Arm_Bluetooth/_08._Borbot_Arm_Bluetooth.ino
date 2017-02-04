#include <SoftwareSerial.h>
#include <Adafruit_PWMServoDriver.h>
#include <Interval.h> 

const int pos0   = 172; // 0°
const int pos180 = 565; // 180°

#define SERVO_COUNT 6

SoftwareSerial bluetooth(2, 3);
Interval interval(20);
Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);

int index = -1;
int angles[SERVO_COUNT] = {254, 325, 528, 446, 222, 200};

void initPosition() {
  int temp[SERVO_COUNT] = {254, 325, 528, 446, 222, 200};  
  
  for (int i = 0; i < SERVO_COUNT; i++) {
    angles[i] = temp[i];
    servos.setPWM(i, 0, angles[i]);
  }
  
  index = -1;
}

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

  servos.begin();  
  servos.setPWMFreq(60); 

  initPosition();
}

char cmd = 0x00;

void loop() {
  if (bluetooth.available() > 0) {  
    cmd = bluetooth.read();
    Serial.println(cmd);
  }

  if (cmd == 'Z') {
    initPosition();
  } else if (cmd == 'S') {
    index = -1;
  } else if ((cmd >= 'A') && (cmd <= 'L')) {
    index = (cmd - 'A') / 2;    
  }

  if (index == -1) return;

  if (interval.onTime() == false) return;
  
  if ((cmd % 2) == 0) angles[index]--;
  else angles[index]++;

  if (angles[index] < pos0) angles[index] = pos0;
  if (angles[index] > pos180) angles[index] = pos180;

  Serial.print("angles - ");
  Serial.print(index);
  Serial.print(": ");
  Serial.println(angles[index]);
  
  servos.setPWM(index, 0, angles[index]);
}
