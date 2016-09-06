#include <TM1637Display.h>

TM1637Display display(3, 4);

void setup() {
  pinMode(1, INPUT_PULLUP);
  
  display.setBrightness(0xff);
  for (int i=999; i>=0; i--) {
    display.showNumberDec(i);             
        
    if (digitalRead(1) == LOW) {
      return;
    }
  }
  
  uint8_t data[] = { 0b00111111, 0b000011100, 0b01111001, 0b01110010 };
  display.setSegments(data);
}

void loop() {
}
