void setup() {
  pinMode(12, INPUT);  
  pinMode(13, OUTPUT);   
}

void loop() {
  if (digitalRead(12) == HIGH) {
      tone(13, 1000);
  } else {
    noTone(13);    
  }

  delay(50);
}
