void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  int volume;
  volume = analogRead(0);
  
  Serial.println(volume);
  
  if (volume > 150) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
  
  delay(50);
}

