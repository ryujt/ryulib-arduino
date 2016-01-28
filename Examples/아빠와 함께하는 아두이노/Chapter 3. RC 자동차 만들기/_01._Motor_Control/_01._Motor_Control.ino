int pin_motor = 5;

void setup() {
  pinMode(pin_motor, OUTPUT);
}

void loop() {
  digitalWrite(pin_motor, HIGH);
  delay(4000);

  digitalWrite(pin_motor, LOW);
  delay(4000);
}
