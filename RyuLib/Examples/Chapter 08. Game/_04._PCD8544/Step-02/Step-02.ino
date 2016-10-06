#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

Adafruit_PCD8544 lcd(2, 3, 4, 5, 6);

static const unsigned char PROGMEM image[] =
{ 
        0b00011000,
        0b00111100,
        0b01111110,
        0b11011011,
        0b11111111,
        0b01011010,
        0b10000001,
        0b01000010
};

void setup() {
  lcd.begin();
  lcd.clearDisplay();
  lcd.display();
}

void loop() {
  lcd.clearDisplay();

  lcd.drawBitmap(0, 0, image, 8, 8, 1);

  lcd.display();
}
