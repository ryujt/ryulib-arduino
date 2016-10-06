#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <analog_keyboard.h>

const uint64_t pipe = 0x12E8F0F0E1LL;

RF24 radio(7, 8);
int data[2];

const int a_01 = 2;  
const int a_02 = 3; 
const int b_01 = 4;
const int b_02 = 5;

void setup() {
//  Serial.begin(9600);
//  Serial.println("setup");
  
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();

  pinMode(a_01, OUTPUT);
  pinMode(a_02, OUTPUT);
  pinMode(b_01, OUTPUT);
  pinMode(b_02, OUTPUT);
}

int command = 0;

void loop() {
  while (radio.available()) {
    radio.read(data, sizeof(data));

    command = data[0];
    
//    Serial.println(data[0]);
  }
  
  // forward
  if (command == KEY_UP) {
    digitalWrite(a_01, HIGH);
    digitalWrite(a_02, LOW);
    digitalWrite(b_01, HIGH);
    digitalWrite(b_02, LOW);
  }

  //  backward
  if (command == KEY_DOWN) {
    digitalWrite(a_01, LOW);
    digitalWrite(a_02, HIGH);
    digitalWrite(b_01, LOW);
    digitalWrite(b_02, HIGH);
  }

  //  left
  if (command == KEY_LEFT) {
    digitalWrite(a_01, HIGH);
    digitalWrite(a_02, LOW);
    digitalWrite(b_01, LOW);
    digitalWrite(b_02, HIGH);
  }

  //  right
  if (command == KEY_RIGHT) {
    digitalWrite(a_01, LOW);
    digitalWrite(a_02, HIGH);
    digitalWrite(b_01, HIGH);
    digitalWrite(b_02, LOW);  
  }

  // stop
  if (command == KEY_FIRE) {
    digitalWrite(a_01, LOW);
    digitalWrite(a_02, LOW);
    digitalWrite(b_01, LOW);
    digitalWrite(b_02, LOW);
  } 
}
