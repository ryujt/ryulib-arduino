#include <thermistor.h>
#include <Fan.h>

Fan fan(2, 3, 4);

void setup() {
 fan.begin();
}

void loop() {
  int temp;
  temp = analogRead(0);

  if (ThermistorToC(temp) > 30) {
    fan.turn(); 
  } else {
    fan.stop(); 
  }
  
  delay(100);
}