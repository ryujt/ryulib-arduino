void setup() {
  for (int i=0; i<6; i++) {
    pinMode(i+2, OUTPUT);
  }
}

void loop() {
  for (int j=0; j<6; j++) {
    for (int i=0; i<6; i++) {
      digitalWrite(i+2, LOW);
    }
    digitalWrite(j+2, HIGH);
    delay(200);
  }
}
