#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);

int pin_x = 0;
int pin_y = 1;

int pin_a = 2;
int pin_b = 3;
int pin_c = 4;
int pin_d = 5;

int pos0   = 172; // 0°
int pos180 = 565; // 180° 

int waist = 335;
int left_arm = 500;
int right_arm = 300;
int finger = 250;

int motor_speed = 5;

void setup() {
//  Serial.begin(9600);

  pinMode(pin_a, INPUT_PULLUP);
  pinMode(pin_b, INPUT_PULLUP);
  pinMode(pin_c, INPUT_PULLUP);
  pinMode(pin_d, INPUT_PULLUP);
  
  servos.begin();  
  servos.setPWMFreq(60); 
}

void loop() {  
  int x = analogRead(pin_x);
  int y = analogRead(pin_y);

  if (x < 400) waist = waist - motor_speed;
  if (x > 700) waist = waist + motor_speed;

  if (waist < pos0) waist = pos0;
  if (waist > pos180) waist = pos180;
  
  if (y < 400) left_arm = left_arm + motor_speed;
  if (y > 700) left_arm = left_arm - motor_speed;

  if (left_arm < pos0) left_arm = pos0;
  if (left_arm > pos180) left_arm = pos180;

  if (digitalRead(pin_a) == LOW) right_arm = right_arm + motor_speed;
  if (digitalRead(pin_c) == LOW) right_arm = right_arm - motor_speed;
  
  if (right_arm < pos0) right_arm = pos0;
  if (right_arm > pos180) right_arm = pos180;

  if (digitalRead(pin_d) == LOW) finger = finger + motor_speed;
  if (digitalRead(pin_b) == LOW) finger = finger - motor_speed;
  
  if (finger < pos0) finger = pos0;
  if (finger > pos180) finger = pos180;

//  Serial.print("waist: ");
//  Serial.println(waist);
//  
//  Serial.print("left_arm: ");
//  Serial.println(left_arm);
//  
//  Serial.print("right_arm: ");
//  Serial.println(right_arm);
//  
//  Serial.print("finger: ");
//  Serial.println(finger);
  
  servos.setPWM(0, 0, waist);
  servos.setPWM(1, 0, left_arm);
  servos.setPWM(2, 0, right_arm);
  servos.setPWM(3, 0, finger);

  delay(10);
}

