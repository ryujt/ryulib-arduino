#include <TM1637Display.h>

TM1637Display display(1, 2);

const int interval = 1000 * 30;

unsigned long old_tick;
unsigned long tick;

void setup() {
  pinMode(0, INPUT_PULLUP);
  pinMode(3, OUTPUT);

  display.setBrightness(0x0f);
  
  digitalWrite(3, HIGH);
  delay(4000);
  digitalWrite(3, LOW);
  
  old_tick = millis();
}

int old_state = HIGH;
int count = 0;

bool is_game_end = false;

void loop() {
  int state = digitalRead(0);
  
  if ((is_game_end == false) && (state != old_state)) {
    old_state = state;
    count++;
  }
  
  display.showNumberDec(count);             
  
  tick = millis();
  if ((tick - old_tick) > interval) {
    if (is_game_end == false) {
      is_game_end = true;
      digitalWrite(3, HIGH);
      delay(2000);
      digitalWrite(3, LOW);    }
  }
}
