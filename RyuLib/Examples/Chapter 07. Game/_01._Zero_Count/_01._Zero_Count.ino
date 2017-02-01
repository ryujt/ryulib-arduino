#include <TM1637Display.h>

int count = 1000;
bool is_stopped = false;
TM1637Display display(2, 3);

void setup() {
  pinMode(4, INPUT_PULLUP);
  display.setBrightness(15);
}

void loop() {
  if (is_stopped) return;
  
  if (count >= 0) count = count - 1;
  display.showNumberDec(count);    

  if (digitalRead(4) == LOW) is_stopped = true;

  if (count < 0) display.setBrightness(0);    
}
