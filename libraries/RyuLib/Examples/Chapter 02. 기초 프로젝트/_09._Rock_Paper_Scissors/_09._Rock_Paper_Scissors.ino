#include <MAX7219.h>

MAX7219 max7219(2, 3, 4);

char char_1[8] = { 0x81, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x81 };
char char_2[8] = { 0x00, 0x00, 0x18, 0x3C, 0x3C, 0x18, 0x00, 0x00 };
char char_3[8] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };

void setup() {
  max7219.begin();
  pinMode(6, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(6) == LOW) {
    srand(millis());
    int no = (rand() % 3) + 1;

    if (no == 1) {
      for (int i=0; i<8; i++) max7219.write(i+1, char_1[i]);
    }
    
    if (no == 2) {
      for (int i=0; i<8; i++) max7219.write(i+1, char_2[i]);
    }

    if (no == 3) {
      for (int i=0; i<8; i++) max7219.write(i+1, char_3[i]);
    }
  }
}


