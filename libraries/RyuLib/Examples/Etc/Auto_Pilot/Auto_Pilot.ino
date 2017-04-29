#include <GPS.h>

void setup() {
  Serial.begin(9600);

  Serial.print( "get_heading: " );
  Serial.println( get_heading(37.7713545, 128.9575826, 37.2412295, 131.8647985) );
  
  Serial.print( "get_distance: " );
  Serial.println( get_distance(37.7713545, 128.9575826, 37.2412295, 131.8647985) );
}

void loop() {
  // put your main code here, to run repeatedly:

}
