#include "ir_utils.h"

int a_01 = 3;  
int a_02 = 4; 
int b_01 = 5;
int b_02 = 6;

int speed_a = 255;
int speed_b = 255;
    
IR ir(7);

void setup() {
  ir.begin();

  pinMode(a_01, OUTPUT);
  pinMode(a_02, OUTPUT);
  pinMode(b_01, OUTPUT);
  pinMode(b_02, OUTPUT);
}

void loop() {
  unsigned long result = ir.read();
  if (result == 16623703) do_stop();
  if (result == 16615543) forward();
  if (result == 16619623) backward();
  if (result == 16591063) left();
  if (result == 16607383) right();
}

void forward()
{
  analogWrite(a_01, speed_a);
  analogWrite(a_02, 0);
  analogWrite(b_01, speed_b);
  analogWrite(b_02, 0);
}
  
void backward()
{
  analogWrite(a_01, 0);
  analogWrite(a_02, speed_a);
  analogWrite(b_01, 0);
  analogWrite(b_02, speed_b);
}
  
void left()
{
  analogWrite(a_01, speed_a);
  analogWrite(a_02, 0);
  analogWrite(b_01, 0);
  analogWrite(b_02, speed_b);
}
  
void right()
{
  analogWrite(a_01, 0);
  analogWrite(a_02, speed_a);
  analogWrite(b_01, speed_b);
  analogWrite(b_02, 0);
}

void do_stop() {
  analogWrite(a_01, 0);
  analogWrite(a_02, 0);
  analogWrite(b_01, 0);
  analogWrite(b_02, 0);
}
