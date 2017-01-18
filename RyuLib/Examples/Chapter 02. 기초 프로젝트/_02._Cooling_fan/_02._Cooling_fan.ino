#include <thermistor.h>

void setup() {
  pinMode(2, OUTPUT); 
}

void loop() {
  int temp;
  temp = analogRead(0);

  if (ThermistorToC(temp) > 30) {
    digitalWrite(2, HIGH); 
  } else {
    digitalWrite(2, LOW); 
  }

  delay(100);
}

