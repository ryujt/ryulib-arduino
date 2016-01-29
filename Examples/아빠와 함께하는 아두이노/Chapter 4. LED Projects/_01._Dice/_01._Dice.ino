void setup() {
  for (int i=0; i<7; i++) {
    pinMode(i+2, OUTPUT);
    digitalWrite(i+2, LOW);
  }
  
  srand(analogRead(0));
  int no = (rand() % 6) + 1;
  
  if (no == 1) {
    digitalWrite(8, HIGH);
  }

  if (no == 2) {
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  }

  if (no == 3) {
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(8, HIGH);
  }

  if (no == 4) {
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(7, HIGH);
  }

  if (no == 5) {
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
  }

  if (no == 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
  }
}

void loop() {
}
