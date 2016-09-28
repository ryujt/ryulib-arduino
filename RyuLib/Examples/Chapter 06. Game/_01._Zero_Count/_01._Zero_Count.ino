#include <TM1637Display.h>

TM1637Display display(2, 3);

void setup() {
  pinMode(4, INPUT_PULLUP);
  
  display.setBrightness(0x0f);
  for (int i=999; i>=0; i--) {
    display.showNumberDec(i);             
        
    if (digitalRead(4) == LOW) {
      return;
    }
  }
  
  uint8_t data[4];
  data[0] = 0b00111111;
  data[1] = 0b000011100;
  data[2] = 0b01111001;
  data[3] = 0b01110010;
  display.setSegments(data);
}

void loop() {
}
