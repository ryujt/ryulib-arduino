void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(4, OUTPUT);
}

int old_state = 0;

void loop() {
  int state = digitalRead(2);
  
  if (state != old_state) {
    old_state = state;

    for (int i=0; i<10; i++) {
      digitalWrite(4, HIGH);
      delay(500);
      digitalWrite(4, LOW);
      delay(500);
    }
  }
}
