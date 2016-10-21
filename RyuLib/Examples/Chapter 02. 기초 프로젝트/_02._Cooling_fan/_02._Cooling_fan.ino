#include <thermistor.h>

void setup() {
  pinMode(13, OUTPUT); 
}

void loop() {
  int temp;
  temp = analogRead(0);

  if (ThermistorToC(temp) > 30) {
    digitalWrite(13, HIGH); 
  } else {
    digitalWrite(13, LOW); 
  }

  delay(1000);
}

