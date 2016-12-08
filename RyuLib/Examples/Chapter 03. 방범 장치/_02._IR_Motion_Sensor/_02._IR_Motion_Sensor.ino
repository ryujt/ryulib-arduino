void setup() {
  pinMode(12, INPUT);  
  pinMode(13, OUTPUT);   
}

void loop() {
  // TODO: 속도를 빠르게 하고, 라이브러리를 제공하여 쉽게 
  if (digitalRead(12) == HIGH) {       
    tone(13, 1000);
    delay(1000);
    noTone(13);
  }
  
  delay(200);
}
