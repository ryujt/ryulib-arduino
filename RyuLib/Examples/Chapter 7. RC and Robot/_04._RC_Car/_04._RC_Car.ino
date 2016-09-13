#include "ir_utils.h"

int a_01 = 3;  
int a_02 = 5; 
int b_01 = 6;
int b_02 = 9;

int speed_a = 255;
int speed_b = 255;
    
IR ir(2);

void setup() {
  ir.begin();

  pinMode(a_01, OUTPUT);
  pinMode(a_02, OUTPUT);
  pinMode(b_01, OUTPUT);
  pinMode(b_02, OUTPUT);
}

void loop() {
  unsigned long result = ir.read();
  
  // forward
  if (result == 16615543) {
    analogWrite(a_01, speed_a);
    analogWrite(a_02, 0);
    analogWrite(b_01, speed_b);
    analogWrite(b_02, 0);
  }

  //  backward
  if (result == 16619623) {
    analogWrite(a_01, 0);
    analogWrite(a_02, speed_a);
    analogWrite(b_01, 0);
    analogWrite(b_02, speed_b);
  }

  //  left
  if (result == 16591063) {
    analogWrite(a_01, speed_a);
    analogWrite(a_02, 0);
    analogWrite(b_01, 0);
    analogWrite(b_02, speed_b);
  }

  //  right
  if (result == 16607383) {
    analogWrite(a_01, 0);
    analogWrite(a_02, speed_a);
    analogWrite(b_01, speed_b);
    analogWrite(b_02, 0);  
  }

  // stop
  if (result == 16623703) {
    analogWrite(a_01, 0);
    analogWrite(a_02, 0);
    analogWrite(b_01, 0);
    analogWrite(b_02, 0);
  } 
}
