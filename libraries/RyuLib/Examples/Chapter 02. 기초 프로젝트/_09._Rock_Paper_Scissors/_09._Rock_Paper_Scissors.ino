#include <MAX7219.h>

MAX7219 max7219(2, 3, 4);

static const unsigned char PROGMEM char_1[] = { 0x81, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x81 };
static const unsigned char PROGMEM char_2[] = { 0x00, 0x00, 0x18, 0x3C, 0x3C, 0x18, 0x00, 0x00 };
static const unsigned char PROGMEM char_3[] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };

void setup() {
  max7219.begin();
  pinMode(6, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(6) == LOW) {
    srand(millis());
    int no = (rand() % 3) + 1;

    if (no == 1) max7219.write(char_1);    
    if (no == 2) max7219.write(char_2);    
    if (no == 3) max7219.write(char_3);    
  }
}