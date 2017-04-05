#include <MAX7219.h>

MAX7219 max7219(2, 3, 4);

static const char PROGMEM scissors[] 
  = { 0x81, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x81 };
  
static const char PROGMEM rock[] 
  = { 0x00, 0x00, 0x18, 0x3C, 0x3C, 0x18, 0x00, 0x00 };
  
static const char PROGMEM paper[] 
  = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };

void setup() {
  max7219.begin();
  pinMode(6, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(6) == LOW) {
    srand(millis());
    int no = rand() % 3;

    if (no == 0) max7219.write(scissors);    
    if (no == 1) max7219.write(rock);    
    if (no == 2) max7219.write(paper);    
  }
}
