#include <TM1637Display.h>

TM1637Display display(2, 3);

void setup() {
  Serial.begin(9600);

  pinMode(4, INPUT); 
  pinMode(13, INPUT); 

  display.setBrightness(0);
}

int max = 0;

void loop() {
  int value = analogRead(0);
  bool is_detected = digitalRead(4) == 0;
  
  Serial.println(value); 

  if (is_detected) {
    if (value > max) max = value;
    display.setBrightness(15);
    display.showNumberDec(max);
    tone(13, 400);
  } else {
    max = 0;
    display.setBrightness(0);
    display.showNumberDec(0);
    noTone(13);
  }
  
  delay(10);
}
