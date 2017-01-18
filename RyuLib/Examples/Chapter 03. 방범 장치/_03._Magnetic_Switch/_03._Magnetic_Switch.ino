#include <sound_effect.h>

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}

void loop() {
  if (digitalRead(2) == HIGH) {
    seSiren(13);
  }

  delay(10);
}
