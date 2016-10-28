void setup() {
  pinMode(12, INPUT);  
  pinMode(13, OUTPUT);   
}

void loop() {
  if (digitalRead(12) == HIGH) {       
    tone(13, 1000);
    delay(1000);
    noTone(13);
  }
  
  delay(200);
}
