#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <analog_keyboard.h>
#include <qadruped_robot.h>

const uint64_t pipe = 0x0018F0F0E1LL;

RF24 radio(7, 8);
int valarray[2];

int arm_start_angle[] = { 150, 205, 180,  80 };
int leg_down_angle[]  = { 140,   0, 180, 200 };
int leg_up_angle[]    = {  80, 230, 230, 100 };

void setup() {
  Serial.begin(9600);
  Serial.println("begin!!!");
  
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();

  qadruped_robot_init();
  
  get_up();
  delay(SERVO_INTERVAL);
}

int command = 0;

void loop() {  
  if ( radio.available() ) {
    radio.read( valarray, sizeof(valarray) );

    command = valarray[0];
    
    Serial.println(valarray[0]);
  }

  switch (command) {
    case KEY_FIRE: get_up(); break;
    case KEY_LEFT: turn_left(); break;
    case KEY_RIGHT: turn_right(); break;
    case KEY_UP: forward(); break;
    case KEY_DOWN: backward(); break;
  }
}

