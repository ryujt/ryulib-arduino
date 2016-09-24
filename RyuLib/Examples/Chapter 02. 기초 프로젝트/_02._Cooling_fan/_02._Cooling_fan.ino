#include <thermistor.h>

void setup() {
  pinMode(2, OUTPUT); 
}

void loop() {
  int temp;
  temp = analogRead(0);

  if (ThermistorToC(temp) > 33) {
    digitalWrite(2, HIGH); 
  } else {
    digitalWrite(2, LOW); 
  }

  delay(1000);
}

