const int pin_echo = 10;
const int pin_trig = 11;

void setup()
{
  Serial.begin(9600);

  pinMode(pin_echo, INPUT); 
  pinMode(pin_trig, OUTPUT); 
}

void loop()
{
  long duration, cm;

  digitalWrite(pin_trig, HIGH); 
  delay(10); 
  digitalWrite(pin_trig, LOW);

  duration = pulseIn(pin_echo, HIGH); 
  cm = microsecondsToCentimeters(duration); 
  
  Serial.println(cm);

  delay(100);
}

long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
