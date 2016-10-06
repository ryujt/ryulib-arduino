#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <analog_keyboard.h>

const uint64_t pipe = 0x12E8F0F0E1LL;

const int pin_sw = 2;
const int pin_x = 0;
const int pin_y = 1;

RF24 radio(7, 8);
int data[2];

void setup() {
  Serial.begin(9600);

  pinMode(pin_sw, INPUT_PULLUP);

  radio.begin();
  radio.openWritingPipe(pipe);
}

void loop() {
  data[0] = 0;
  
  int x = analogRead(pin_x);
  int y = analogRead(pin_y);

  if (x < 400) data[0] = KEY_LEFT;
  if (x > 600) data[0] = KEY_RIGHT;

  if (y < 400) data[0] = KEY_UP;
  if (y > 600) data[0] = KEY_DOWN;

  if (digitalRead(pin_sw) == LOW) data[0] = KEY_FIRE;

  if (data != 0) radio.write(data, sizeof(data));
}
