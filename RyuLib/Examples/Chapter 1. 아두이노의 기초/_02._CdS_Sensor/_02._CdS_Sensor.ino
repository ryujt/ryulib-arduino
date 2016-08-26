void setup() {
  pinMode(2, OUTPUT);
}

void loop() {
  int brightness;
  brightness = analogRead(0);

  if (brightness < 800) {
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(2, LOW);
  }
}