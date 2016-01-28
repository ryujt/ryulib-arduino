#include "motor.h"

void Motor::stop()
{
  analogWrite(a_01, 0);
  analogWrite(a_02, 0);
  analogWrite(b_01, 0);
  analogWrite(b_02, 0);
}

void Motor::forward()
{
  analogWrite(a_01, max_speed);
  analogWrite(a_02, 0);
  analogWrite(b_01, max_speed);
  analogWrite(b_02, 0);
}
  
void Motor::backward()
{
  analogWrite(a_01, 0);
  analogWrite(a_02, max_speed);
  analogWrite(b_01, 0);
  analogWrite(b_02, max_speed);
}
  
void Motor::left()
{
  analogWrite(a_01, max_speed);
  analogWrite(a_02, 0);
  analogWrite(b_01, 0);
  analogWrite(b_02, max_speed);
}
  
void Motor::right()
{
  analogWrite(a_01, 0);
  analogWrite(a_02, max_speed);
  analogWrite(b_01, max_speed);
  analogWrite(b_02, 0);
}
