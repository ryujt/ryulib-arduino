#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;

unsigned long old_tick;

void setup()
{
  old_tick = millis();
  
//  Serial.begin(9600);  
//  if (!driver.init()) Serial.println("init failed");
}


void loop()
{
  unsigned long tick = millis();

  if ((tick - old_tick) > 3000) {
      tone(4, 400);
//      Serial.println("Bepp!!!!!!!!");
  } else {
    noTone(4);
  }
      
    char buf[12];
    uint8_t buflen = sizeof(buf);
    if (driver.recv((uint8_t *)buf, &buflen)) {
      if (strncmp(buf, "Hi", 2) == 0) {
        old_tick = tick;
      }
      
//      Serial.print("Message: ");
//      Serial.println((char*)buf);         
    }
}
