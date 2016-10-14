#include <sound_effect.h>

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);

  pinMode(13, OUTPUT);

  seR2D2(13);
}

const long int count_interval = 20000;
long int count = count_interval * 6;

bool is_game_end      = false;
bool is_left_pressed  = false;
bool is_right_pressed = false;

bool is_game_end_sound_done = false;

void loop() {
  if (digitalRead(7) == LOW) is_left_pressed  = true;
  if (digitalRead(8) == LOW) is_right_pressed = true;

  if (is_game_end) {
    if (is_game_end_sound_done == false) seChang(13);
    is_game_end_sound_done = true;
    
    return;
  }

  is_game_end = is_left_pressed || is_right_pressed;

  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);

  if (count > (count_interval * 4)) {
    digitalWrite(6, HIGH); 
  } else if (count > (count_interval * 2)) {
    digitalWrite(5, HIGH); 
  } else {
    digitalWrite(4, HIGH); 
    count = 0;
  }

  if (count > 0) count--;

  if (count == 0) {
    if (is_left_pressed)  digitalWrite(2, HIGH);
    if (is_right_pressed) digitalWrite(3, HIGH);
  } else {
    if (is_left_pressed)  digitalWrite(3, HIGH);
    if (is_right_pressed) digitalWrite(2, HIGH);
  }
}
