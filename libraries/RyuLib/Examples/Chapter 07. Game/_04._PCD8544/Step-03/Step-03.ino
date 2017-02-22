#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <cheetah.h>

Adafruit_PCD8544 lcd(2, 3, 4, 5, 6);

void setup() {
  lcd.begin();
  lcd.clearDisplay();
  lcd.display();
}

int index  = 0;

void loop() {
  lcd.clearDisplay();

  lcd.drawBitmap(0, 0, cheetah_image[index], CHEETAH_WIDTH, CHEETAH_HEIGHT, 1);
  
  index++;
  if (index >= CHEETAH_COUNT) {
    index = 0;
  }

  lcd.display();

  delay(100);
}
