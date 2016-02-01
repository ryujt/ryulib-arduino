#include <MAX7219.h>

MAX7219 max7219(2, 3, 4);

char char_01[8] = { 0x72, 0x8A, 0x8A, 0x73, 0x02, 0x42, 0x40, 0x7E };
char char_02[8] = { 0x81, 0x87, 0x81, 0xF7, 0x01, 0x39, 0x44, 0x38 };
char char_03[8] = { 0x32, 0x02, 0x7A, 0x03, 0x32, 0x4A, 0x4A, 0x32 };
char char_04[8] = { 0x25, 0x25, 0x25, 0x2D, 0x65, 0x95, 0x95, 0x95 };
char char_05[8] = { 0x3C, 0x42, 0x42, 0x3C, 0x00, 0x24, 0x24, 0xFF };
char char_06[8] = { 0x3C, 0x42, 0x42, 0x02, 0x0C, 0x10, 0x00, 0x10 };

void setup() {
  max7219.begin();
}

void loop() {
  for (int i=0; i<8; i++) max7219.write(i+1, char_01[i]);
  delay(500);
  
  for (int i=0; i<8; i++) max7219.write(i+1, char_02[i]);
  delay(500);
  
  for (int i=0; i<8; i++) max7219.write(i+1, char_03[i]);
  delay(500);
  
  for (int i=0; i<8; i++) max7219.write(i+1, char_04[i]);
  delay(500);
  
  for (int i=0; i<8; i++) max7219.write(i+1, char_05[i]);
  delay(500);
  
  for (int i=0; i<8; i++) max7219.write(i+1, char_06[i]);
  delay(500);
}

