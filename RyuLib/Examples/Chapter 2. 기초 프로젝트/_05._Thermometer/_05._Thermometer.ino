#include <thermistor.h>
#include <TM1637Display.h>

TM1637Display display(2, 3);

void setup() {
  Serial.begin(9600);
  display.setBrightness(0x0f);
}

void loop() {
  int temp;
  temp = analogRead(0);

  Serial.println( ThermistorToC(temp) );
  display.showNumberDec( ThermistorToC(temp) );

  delay(500);
}
