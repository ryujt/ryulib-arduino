#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

Adafruit_PCD8544 lcd(2, 3, 4, 5, 6);

void setup() {
  lcd.begin();
  lcd.clearDisplay();
  lcd.display();
}

void loop() {
  lcd.clearDisplay();

  lcd.setTextSize(1);
  lcd.setCursor(0, 0);
  lcd.println("Text");                
  lcd.println(1234);                

  lcd.drawLine(0, 30, 20, 40, 1);
  
  lcd.drawRect(50, 30, 4, 4, 1);
  lcd.fillRect(60, 40, 4, 4, 1);
  
  lcd.drawCircle(30, 30, 4, 1);
  lcd.fillCircle(40, 40, 4, 1);

  lcd.display();
}
