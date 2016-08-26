int pin_input = 2; 
int pin_led = 13;   

void setup() {
  pinMode(pin_input, INPUT);  
  pinMode(pin_led, OUTPUT);   
}

void loop() {
  if (digitalRead(pin_input) == HIGH) {       
    digitalWrite(pin_led, HIGH);
  } else {
    digitalWrite(pin_led, LOW);
  }
}
