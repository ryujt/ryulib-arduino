void setup() {
  pinMode(12, INPUT);  
  pinMode(13, OUTPUT);   
}

void loop() {
  if (digitalRead(12) == HIGH) {       
    for (int i=0; i<10; i++) {
      digitalWrite(13, HIGH);
      delay(500);
      digitalWrite(13, LOW);
      delay(500);
    }
  }
}
