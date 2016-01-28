#include "CharliePlexing.h"

void setup() 
{
}

void loop() 
{
  int v = 0;
  for (int i=1; i < 12; i++) {
    light_up(i); 
    v = v + 15;
    delay(200 - v);
  }

  for (int i=12; i > 1; i--) {
    light_up(i);
    v = v - 15;
    delay(200 - v);
  }
}
