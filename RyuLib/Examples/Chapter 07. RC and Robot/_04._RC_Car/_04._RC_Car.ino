#include "ir_utils.h"

const int a_01 = 2;  
const int a_02 = 3; 
const int b_01 = 4;
const int b_02 = 5;

IR ir(9);

void setup() {
  Serial.begin(9600);
  
  ir.begin();

  pinMode(a_01, OUTPUT);
  pinMode(a_02, OUTPUT);
  pinMode(b_01, OUTPUT);
  pinMode(b_02, OUTPUT);
}

void loop() {
  unsigned long result = ir.read();

  if (result == 0) return;

  Serial.println(result);
  
  // forward
  if (result == 16736925) {
    digitalWrite(a_01, HIGH);
    digitalWrite(a_02, LOW);
    digitalWrite(b_01, HIGH);
    digitalWrite(b_02, LOW);
  }

  //  backward
  if (result == 16754775) {
    digitalWrite(a_01, LOW);
    digitalWrite(a_02, HIGH);
    digitalWrite(b_01, LOW);
    digitalWrite(b_02, HIGH);
  }

  //  left
  if (result == 16720605) {
    digitalWrite(a_01, HIGH);
    digitalWrite(a_02, LOW);
    digitalWrite(b_01, LOW);
    digitalWrite(b_02, HIGH);
  }

  //  right
  if (result == 16761405) {
    digitalWrite(a_01, LOW);
    digitalWrite(a_02, HIGH);
    digitalWrite(b_01, HIGH);
    digitalWrite(b_02, LOW);  
  }

  // stop
  if (result == 16712445) {
    digitalWrite(a_01, LOW);
    digitalWrite(a_02, LOW);
    digitalWrite(b_01, LOW);
    digitalWrite(b_02, LOW);
  } 
}
