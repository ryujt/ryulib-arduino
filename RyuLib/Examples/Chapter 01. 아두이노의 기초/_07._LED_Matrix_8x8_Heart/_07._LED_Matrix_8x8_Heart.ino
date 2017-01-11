#include <MAX7219.h>

MAX7219 max7219(2, 3, 4);

void setup() {
  max7219.begin();
}

void loop() {
  max7219.write(1, 0b00000000);
  max7219.write(2, 0b01100110);
  max7219.write(3, 0b11111111);
  max7219.write(4, 0b11111111);
  max7219.write(5, 0b01111110);
  max7219.write(6, 0b00111100);
  max7219.write(7, 0b00011000);
  max7219.write(8, 0b00000000);
  delay(300);
  
  max7219.write(1, 0b01100110);
  max7219.write(2, 0b11111111);
  max7219.write(3, 0b11111111);
  max7219.write(4, 0b01111110);
  max7219.write(5, 0b00111100);
  max7219.write(6, 0b00011000);
  max7219.write(7, 0b00000000);
  max7219.write(8, 0b00000000);
  delay(300);

  max7219.write(1, 0b00000000);
  max7219.write(2, 0b01100110);
  max7219.write(3, 0b11111111);
  max7219.write(4, 0b11111111);
  max7219.write(5, 0b01111110);
  max7219.write(6, 0b00111100);
  max7219.write(7, 0b00011000);
  max7219.write(8, 0b00000000);
  delay(300);
  
  max7219.write(1, 0b00000000);
  max7219.write(2, 0b00000000);
  max7219.write(3, 0b01100110);
  max7219.write(4, 0b11111111);
  max7219.write(5, 0b11111111);
  max7219.write(6, 0b01111110);
  max7219.write(7, 0b00111100);
  max7219.write(8, 0b00011000);
  delay(300);
}

