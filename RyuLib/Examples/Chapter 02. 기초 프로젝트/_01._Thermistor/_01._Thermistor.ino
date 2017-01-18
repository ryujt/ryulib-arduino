#include <thermistor.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  int temp;
  temp = analogRead(0);

  Serial.println( ThermistorToC(temp) );

  delay(100);
}
