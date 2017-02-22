const int pin_sw = 2;
const int pin_x = 0;
const int pin_y = 1;

void setup() {
  Serial.begin(9600);

  pinMode(pin_sw, INPUT_PULLUP);
}

void loop() {
  int x = analogRead(pin_x);
  int y = analogRead(pin_y);

  Serial.print("x: ");
  Serial.println(x);

  Serial.print("y: ");
  Serial.println(y);

  if (digitalRead(pin_sw) == LOW) {
    Serial.println("Pressed.");
  }

  delay(500);
}
