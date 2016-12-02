#include <sound_effect.h>

const int pin_sw = 12;
const int pin_buzzer = 13;

void setup() {
  Serial.begin(9600);

  
  for (int i=2; i<10; i++) pinMode(i, INPUT_PULLUP);

  pinMode(pin_sw, OUTPUT);
  pinMode(pin_buzzer, OUTPUT);
}

int last_index = -1;
int next_index = 2;

void loop() {
  int current_index = -1;
  for (int i=2; i<10; i++) {
    if (digitalRead(i) == LOW) {
      current_index = i;
      break;
    }
  }

  if (current_index == -1) return;

  if (current_index == last_index) return;

  last_index = current_index;

  Serial.print("current: ");
  Serial.println(current_index);
    
  if ((current_index == next_index) || (current_index == 2)) {
    next_index = current_index + 1;

    if (current_index == 9) {
      digitalWrite(pin_sw, HIGH);
      seVictory(pin_buzzer);
      digitalWrite(pin_sw, LOW);
    } else {
      seWaka(pin_buzzer);
    }
  } else {
    Serial.println("Error!");
    seAlarm(pin_buzzer);
    last_index = -1;
    next_index = 2;
  } 

  Serial.print("next_index: ");
  Serial.println(next_index);
  Serial.println("----------------");
}
