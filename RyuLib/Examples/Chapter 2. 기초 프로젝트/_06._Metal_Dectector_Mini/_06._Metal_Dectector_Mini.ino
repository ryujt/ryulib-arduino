void setup() {
  Serial.begin(9600);
}

void loop() {
  int temp;
  temp = analogRead(0);

  Serial.println(temp);

  delay(10);
}
