#include <MAX7219.h>

MAX7219 max7219(2, 3, 4);

void setup() {
  max7219.begin();
}

void loop() {
  max7219.write(1, 0b10000000);
  max7219.write(2, 0b01000000);
  max7219.write(3, 0b00100000);
  max7219.write(4, 0b00010000);
  max7219.write(5, 0b00001000);
  max7219.write(6, 0b00000100);
  max7219.write(7, 0b00000010);
  max7219.write(8, 0b00000001);
}

