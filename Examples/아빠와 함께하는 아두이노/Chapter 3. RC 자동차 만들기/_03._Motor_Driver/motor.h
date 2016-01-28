#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

const byte max_speed = 255;

class Motor {
 private:
    int a_01;  
    int a_02; 
    int b_01;
    int b_02;

  public:
    Motor(int a1, int a2, int b1, int b2) {
      a_01 = a1;
      a_02 = a2;
      b_01 = b1;
      b_02 = b2;
      
      pinMode(a_01, OUTPUT);
      pinMode(a_02, OUTPUT);
      pinMode(b_01, OUTPUT);
      pinMode(b_02, OUTPUT);
    }
    
    void stop();
    void forward();
    void backward();
    void left();
    void right();
};

#endif // MOTOR_H
