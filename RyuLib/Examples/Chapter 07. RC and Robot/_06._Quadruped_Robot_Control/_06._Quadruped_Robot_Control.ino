#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <analog_keyboard.h>

const uint64_t pipe = 0x0018F0F0E1LL;

RF24 radio(7, 8);
int valarray[2];

void setup() {
  Serial.begin(9600);
  
  radio.begin();
  radio.openWritingPipe(pipe);

  valarray[0] = 0;
}

int command = 0;

void loop() {
  command = analogRead(0);

  if (command > 1000) return;

       if (command > 700) command = KEY_FIRE;
  else if (command > 500) command = KEY_RIGHT;
  else if (command > 300) command = KEY_DOWN;
  else if (command > 100) command = KEY_UP;
  else command = KEY_LEFT;  

  if (command > 0) {
    Serial.println(command);
    valarray[0] = command; 
  }
  radio.write( valarray, sizeof(valarray) );
}
