void setup() {
  Serial.begin(9600);
}

void loop() {
  double v = analogRead(0);
  double r = (10230 / v) - 10;
  
  Serial.print(v);
  Serial.print(", ");
  Serial.println(r);
  
  delay(100);
}
