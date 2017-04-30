#include <GPS.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
#include <Interval.h>

GPS gps;

// 10:TX, 11:RX
SoftwareSerial ss(10, 11);
LiquidCrystal_I2C lcd(0x27, 2, 16); 
Interval interval(1000);

void setup()
{
  Serial.begin(9600);

  ss.begin(9600);
 
  lcd.init();  
  lcd.backlight();
  lcd.print("start");
}

void loop()
{
  while (ss.available()) {
    char ch = ss.read();
    gps.decode(ch);
//    Serial.print(ch );
  }

  if (interval.onTime()) {
    lcd.clear();
    lcd.print(gps.get_lat_str());   lcd.print(", ");
    lcd.print(gps.get_nors());      lcd.print(", ");
    lcd.setCursor(0, 1);
    lcd.print(gps.get_lon_str());
  }
}
