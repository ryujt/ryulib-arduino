#include <Compass.h>
#include <Kalman.h>

Compass compass;
Kalman filter(0.125, 32, 1023, 0);

void setup() {
  compass.set_angle_offset(0);
  compass.begin();

  Serial.begin(9600);
}

void loop() {
  int angle = compass.get_angle();
//  Serial.print("angle: ");
//  Serial.println(angle);

  Serial.println( filter.getFilteredValue(angle) );
  
//  delay(200);
}
