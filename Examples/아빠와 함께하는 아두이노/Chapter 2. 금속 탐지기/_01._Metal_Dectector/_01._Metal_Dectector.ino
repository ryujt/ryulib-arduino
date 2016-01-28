int pin_sound = 0;
int pin_led = 13;

void setup() {
  Serial.begin(9600);
  
  pinMode(pin_led, OUTPUT);
}

void loop() {
  int volume = analogRead(pin_sound);
  
  Serial.println(volume);
  
  if (volume > 200) {
    digitalWrite(pin_led, HIGH);
  } else {
    digitalWrite(pin_led, LOW);
  }
  
  delay(500);
}

