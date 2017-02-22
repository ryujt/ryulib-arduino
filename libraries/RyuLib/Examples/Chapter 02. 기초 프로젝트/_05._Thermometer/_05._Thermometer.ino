#include <thermistor.h>
#include <TM1637Display.h>

TM1637Display display(2, 3);

void setup() {
  display.setBrightness(15);
}

void loop() {
  int temp;
  temp = analogRead(0);

  display.showNumberDec( ThermistorToC(temp) );

  delay(100);
}
