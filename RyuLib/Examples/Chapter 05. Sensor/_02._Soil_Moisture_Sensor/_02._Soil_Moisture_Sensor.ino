void setup() {
  Serial.begin(9600);
}

void loop() {
  int humidity;
  humidity = analogRead(0);

  Serial.println(humidity);

  if (humidity > 600) {
    tone(13, 1000);
    delay(1000);
    noTone(13);
  }

  delay(200);
}
