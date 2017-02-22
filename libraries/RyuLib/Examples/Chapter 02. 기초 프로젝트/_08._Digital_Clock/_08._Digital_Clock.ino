#include <TM1637Display.h>
#include <Clock.h>

TM1637Display display(2, 3);
Clock clock(5, 6, 7);

void setup() 
{
  pinMode( 9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);

  display.setBrightness(15);

  clock.begin();
}

void loop() 
{
  if (digitalRead(10) == LOW) {
    clock.incHour();
  }

  if (digitalRead(9) == LOW) {
    clock.incMinute();
  }
  
  uint8_t data[] = { 0b00000000, 0b00000000, 0b00000000, 0b00000000 };
  clock.setSegments(data);
  display.setSegments(data);

  delay(100);  
}
