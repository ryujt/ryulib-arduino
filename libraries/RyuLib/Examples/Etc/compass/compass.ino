#include <Compass.h>

Compass compass;

void setup() {
  Serial.begin(9600);
  compass.begin();
}

void loop() {
  Serial.println( compass.get_angle() );
  delay(100);
}
