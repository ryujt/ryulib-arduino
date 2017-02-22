#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2, 3);

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  while (bluetooth.available() > 0) {
    char ch = bluetooth.read();
    Serial.println(ch);
  }
}
