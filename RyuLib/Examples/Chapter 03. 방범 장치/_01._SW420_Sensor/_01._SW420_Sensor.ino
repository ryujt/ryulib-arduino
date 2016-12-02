#include <VibrationSensor.h>

void setup() {
  Serial.begin(9600);
  
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}

VibrationSensor sensor(2);

void loop() {
  if (sensor.isActive()) {
    tone(13, 400);
  } else {
    noTone(13);
  }
}
