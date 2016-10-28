#include <MAX7219.h>

MAX7219 max7219(2, 3, 4);

char char_1[8] = { 0x00, 0x18, 0x3C, 0x7E, 0xFF, 0x18, 0x18, 0x18 };
char char_2[8] = { 0x18, 0x3C, 0x7E, 0xFF, 0x18, 0x18, 0x18, 0x00 };
char char_3[8] = { 0x3C, 0x7E, 0xFF, 0x18, 0x18, 0x18, 0x00, 0x18 };
char char_4[8] = { 0x7E, 0xFF, 0x18, 0x18, 0x18, 0x00, 0x18, 0x3C };
char char_5[8] = { 0xFF, 0x18, 0x18, 0x18, 0x00, 0x18, 0x3C, 0x7E };
char char_6[8] = { 0x18, 0x18, 0x18, 0x00, 0x18, 0x3C, 0x7E, 0xFF };
char char_7[8] = { 0x18, 0x18, 0x00, 0x18, 0x3C, 0x7E, 0xFF, 0x18 };
char char_8[8] = { 0x18, 0x00, 0x18, 0x3C, 0x7E, 0xFF, 0x18, 0x18 };

void setup() {
  max7219.begin();
}

void loop() {
  for (int i=0; i<8; i++) max7219.write(i+1, char_1[i]);
  delay(200);

  for (int i=0; i<8; i++) max7219.write(i+1, char_2[i]);
  delay(200);

  for (int i=0; i<8; i++) max7219.write(i+1, char_3[i]);
  delay(200);

  for (int i=0; i<8; i++) max7219.write(i+1, char_4[i]);
  delay(200);

  for (int i=0; i<8; i++) max7219.write(i+1, char_5[i]);
  delay(200);

  for (int i=0; i<8; i++) max7219.write(i+1, char_6[i]);
  delay(200);

  for (int i=0; i<8; i++) max7219.write(i+1, char_7[i]);
  delay(200);

  for (int i=0; i<8; i++) max7219.write(i+1, char_8[i]);
  delay(200);
}

