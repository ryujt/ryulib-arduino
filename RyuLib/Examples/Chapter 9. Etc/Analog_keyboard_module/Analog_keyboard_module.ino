#include <analog_keyboard.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  int temp = readKey(0, 168);
  if (temp > 0) Serial.println(temp);

//  Serial.println(analogRead(0));
}
