void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  digitalWrite(4, LOW);
  digitalWrite(2, HIGH);
  delay(5000);
  
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  delay(5000);
  
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  delay(5000);
}
