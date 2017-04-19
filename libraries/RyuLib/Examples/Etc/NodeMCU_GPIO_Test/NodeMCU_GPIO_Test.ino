int gpio[] = {0, 2, 4, 5, 12, 13, 14, 15, 16};

int size = sizeof(gpio) / sizeof(int);

void setup() {
  Serial.begin(9600);
  
  for (int i=0; i<size; i++) pinMode(gpio[i], OUTPUT);
}

void loop() {
  Serial.println("HIGH");
  for (int i=0; i<size; i++) digitalWrite(gpio[i], HIGH);
  delay(500);

  Serial.println("LOW");
  for (int i=0; i<size; i++) digitalWrite(gpio[i], LOW);
  delay(500);
}
