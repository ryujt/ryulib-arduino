int pin_sw = 2;
int pin_led = 13;

void setup() {
  pinMode(pin_sw, INPUT_PULLUP);
  pinMode(pin_led, OUTPUT);
}

int old_state = 0;

void loop() {
  int state = digitalRead(pin_sw);
  
  if (state != old_state) {
    old_state = state;

    digitalWrite(pin_led, HIGH);
    delay(1000);
    digitalWrite(pin_led, LOW);
  }
}
