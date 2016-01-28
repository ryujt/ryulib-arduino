int pin_light = 0;
int pin_led = 13;

void setup() {
  Serial.begin(9600);

  pinMode(pin_led, OUTPUT);
}

void loop() {
  int brightness = analogRead(pin_light);

  Serial.println(brightness);

  if (brightness < 800) {
    digitalWrite(pin_led, HIGH);
  } else {
    digitalWrite(pin_led, LOW);
  }
  
  delay(100);
}
