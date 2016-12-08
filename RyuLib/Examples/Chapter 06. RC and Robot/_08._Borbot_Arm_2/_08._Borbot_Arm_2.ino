#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <analog_keyboard.h>
#include <Servo.h> 

Adafruit_PCD8544 lcd(2, 3, 4, 5, 6);

int index = 0;
int count = 0;

int angles[4] = {10, 10, 10, 10};
Servo motors[4];

void setup() {
  lcd.begin();
  lcd.clearDisplay();
  lcd.display();

  for (int i=0; i<4; i++) {
    motors[i].attach(i+8); 
  }   
}

void loop() {
  if (count > 0) count = count - 1;

  if (count <= 0) {
    int key = readKey(0);
  
    if (key == KEY_LEFT) {
      index = index - 1;
      if (index < 0) index = 0;
      count = 10;
    }
    
    if (key == KEY_RIGHT) {
      index = index + 1;
      if (index >= 4) index = 3;    
      count = 10;
    }

    if (key == KEY_UP) {
      angles[index] = angles[index] + 1;
      if (angles[index] > 170) angles[index] = 170;
      count = 2;
    }

    if (key == KEY_DOWN) {
      angles[index] = angles[index] - 1;
      if (angles[index] < 10) angles[index] = 10;
      count = 2;
    }
  }
  
  lcd.clearDisplay();

  lcd.setTextSize(2);

  for (int i=0; i<4; i++) {
    lcd.drawRect(2 + index * 20, 2, 14, 18, 1);
    
    lcd.setCursor(4 + i * 20, 4);
    lcd.println(i + 1);  
  }              
  
  lcd.setCursor(4, 24);
  lcd.print("-> ");  
  lcd.println(angles[index]);  
  
  lcd.display();

  for (int i=0; i<4; i++) {
    motors[i].write(angles[i]); 
  }   
  
  delay(10);
}

