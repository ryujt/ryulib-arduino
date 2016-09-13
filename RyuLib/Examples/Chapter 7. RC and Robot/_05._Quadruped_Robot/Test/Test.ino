#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

const int SERVO_INTERVAL = 100;

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);

unsigned int pos0   = 172; // 0°
unsigned int pos180 = 565; // 180°  

void leg_down(int n) {
  switch (n) {
    case 0: servos.setPWM(4, 0, pos0 - 80); break;
    case 1: servos.setPWM(5, 0, pos0 + 500); break;
    case 2: servos.setPWM(6, 0, pos0 + 500); break;
    case 3: servos.setPWM(7, 0, pos0 - 80); break;
  }
}

void leg_middle(int n) {
  switch (n) {
    case 0: servos.setPWM(4, 0, pos0 + 0); break;
    case 1: servos.setPWM(5, 0, pos0 + 420); break;
    case 2: servos.setPWM(6, 0, pos0 + 420); break;
    case 3: servos.setPWM(7, 0, pos0 + 0); break;
  }  
}

void leg_up(int n) {
  switch (n) {
    case 0: servos.setPWM(4, 0, pos0 + 390); break;
    case 1: servos.setPWM(5, 0, pos0 + 0); break;
    case 2: servos.setPWM(6, 0, pos0 + 0); break;
    case 3: servos.setPWM(7, 0, pos0 + 390); break;
  }  
}

void arm_position(int n, int angle) {
  switch (n) {
    case 0: servos.setPWM(0, 0, pos0 +  80 - angle); break;
    case 1: servos.setPWM(1, 0, pos0 + 310 - angle); break;
    case 2: servos.setPWM(2, 0, pos0 + 350 - angle); break;
    case 3: servos.setPWM(3, 0, pos0 +  80 - angle); break;
  }
}

void arm_start_position() {
  servos.setPWM(0, 0, pos0 + 80);  
  servos.setPWM(1, 0, pos0 + 320); 
  servos.setPWM(2, 0, pos0 + 350); 
  servos.setPWM(3, 0, pos0 + 80); 
}

void get_up() {
  arm_start_position();
  for (int n=0; n<4; n++) leg_down(n); 
}

void sit_down() {
  arm_start_position();
  for (int n=0; n<4; n++) leg_up(n); 
}

void go_forward() {
  int angle = 100;
  
  leg_middle(0);          
  arm_position(0, angle);  
  delay(SERVO_INTERVAL);
  leg_down(0);
  delay(SERVO_INTERVAL);

  leg_middle(1);          
  arm_position(1, -angle);  
  delay(SERVO_INTERVAL);
  leg_down(1);
  delay(SERVO_INTERVAL);

  leg_middle(2);          
  arm_position(2, angle);  
  delay(SERVO_INTERVAL);
  leg_down(2);
  delay(SERVO_INTERVAL);

  leg_middle(3);          
  arm_position(3, -angle);  
  delay(SERVO_INTERVAL);
  leg_down(3);
  delay(SERVO_INTERVAL);

  arm_start_position();    
  delay(SERVO_INTERVAL);
}

void go_forward_fast() {
  int angle = 100;
  
  leg_middle(1);          
  leg_middle(2);          
  leg_up(0);
  leg_up(3);
  arm_position(0, angle);  
  arm_position(3, -angle);  
  delay(SERVO_INTERVAL);
  leg_down(0);
  leg_down(3);
  delay(SERVO_INTERVAL);
  leg_down(1);
  leg_down(2);
  arm_position(0, 0);  
  arm_position(3, 0);  
  delay(SERVO_INTERVAL);
  
  leg_middle(0);          
  leg_middle(3);          
  leg_up(1);
  leg_up(2);
  arm_position(1, -angle);  
  arm_position(2, angle);  
  delay(SERVO_INTERVAL);
  leg_down(1);
  leg_down(2);
  delay(SERVO_INTERVAL);
  leg_down(0);
  leg_down(3);
  arm_position(1, 0);  
  arm_position(2, 0);  
  delay(SERVO_INTERVAL);
}

void turn_left() {
  int angle = 100;
  
  leg_middle(0);
  leg_middle(3);
  arm_position(0, -angle);  
  arm_position(3, -angle);  
  delay(SERVO_INTERVAL);
  leg_down(0);
  leg_down(3);
  delay(SERVO_INTERVAL);
  
  leg_middle(1);
  leg_middle(2);
  arm_position(0, 0);  
  arm_position(3, 0);  
  delay(SERVO_INTERVAL);
  leg_down(1);
  leg_down(2);
  delay(SERVO_INTERVAL);
}

void turn_right() {
  int angle = 100;
  
  leg_middle(0);
  leg_middle(3);
  arm_position(0, angle);  
  arm_position(3, angle);  
  delay(SERVO_INTERVAL);
  leg_down(0);
  leg_down(3);
  delay(SERVO_INTERVAL);
  
  leg_middle(1);
  leg_middle(2);
  arm_position(0, 0);  
  arm_position(3, 0);  
  delay(SERVO_INTERVAL);
  leg_down(1);
  leg_down(2);
  delay(SERVO_INTERVAL);
}

void setup() {
  Serial.begin(9600);
  
  servos.begin();  
  servos.setPWMFreq(60); 

  get_up();
  delay(SERVO_INTERVAL);

  go_forward_fast();
}

void down_up_test() {
  sit_down();
  delay(SERVO_INTERVAL);
   
  get_up();
  delay(SERVO_INTERVAL);  
}

void leg_test() {
  for (int n=0; n<4; n++) {
    leg_up(n); 
    delay(SERVO_INTERVAL);

    leg_middle(n);
    delay(SERVO_INTERVAL);
    
    leg_down(n);
    delay(SERVO_INTERVAL);
  }  
}

void arm_test() {
  for (int n=0; n<4; n++) {
    leg_up(n); 
    delay(SERVO_INTERVAL);

    arm_position(n, -100);
    delay(SERVO_INTERVAL);
    
    arm_position(n, 100);
    delay(SERVO_INTERVAL);
    
    arm_position(n, 0);
    delay(SERVO_INTERVAL);
    
    leg_down(n);
    delay(SERVO_INTERVAL);
  }    
}

void loop() {  
  down_up_test();
  delay(1000);
  
  leg_test();
  delay(1000);
  
  arm_test();
  delay(1000);
  
//  go_forward();  

  for (int i=0; i<10; i++) go_forward_fast();
  delay(1000);
  
  turn_left();
  turn_left();
  delay(1000);
  
  turn_right();
  turn_right();
  delay(1000);
}

