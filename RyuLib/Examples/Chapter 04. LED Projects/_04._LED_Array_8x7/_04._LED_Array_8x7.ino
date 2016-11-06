void setup() {
  Serial.begin(9600);
}

void led_on(int plus, int minus) {
  for (int i=2; i<10; i++) pinMode(i, INPUT);

  pinMode(plus, OUTPUT);
  pinMode(minus, OUTPUT);

  digitalWrite(plus, HIGH);
}

void loop() {
  for (int y=2; y<10; y++) {
    for (int x=2; x<10; x++) {
      Serial.print("x: ");
      Serial.print(x);
      Serial.print(", y: ");
      Serial.println(y);
      
      led_on(x, y);
      delay(2000);
    }    
  }
}
