#include <Encoder.h>

Encoder rotary_encoder(3, 4);

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(2) == LOW) {
    Serial.println("Button is clicked.");
  }

  long new_position = rotary_encoder.read();
  Serial.print("new_position: ");
  Serial.println(new_position);

  delay(100);
}
