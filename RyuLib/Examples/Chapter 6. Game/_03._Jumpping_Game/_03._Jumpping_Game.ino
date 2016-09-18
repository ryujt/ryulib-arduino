#include <TM1637Display.h>

TM1637Display display(3, 4);

const int interval = 1000 * 30;

unsigned long old_tick;
unsigned long tick;

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);

  display.setBrightness(0x0f);
  
  tone(13, 262, 500);
  delay(550);

  tone(13, 262, 500);
  delay(550);
  
  tone(13, 524, 1000);
  delay(550);
  
  old_tick = millis();
}

int old_state = HIGH;
int count = 0;

bool is_game_end = false;

void loop() {
  int state = digitalRead(2);
  
  if ((is_game_end == false) && (state != old_state)) {
    old_state = state;
    count++;
  }
  
  display.showNumberDec(count);             
  
  tick = millis();
  if ((tick - old_tick) > interval) {
    if (is_game_end == false) {
      is_game_end = true;
      tone(13, 262, 2000);
    }
  }
}
