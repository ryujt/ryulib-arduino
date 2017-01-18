void setup()
{
  Serial.begin(9600);

  pinMode(10, INPUT); 
  pinMode(11, OUTPUT); 
}

void loop()
{
  long duration, cm;

  digitalWrite(11, HIGH); 
  delay(10); 
  digitalWrite(11, LOW);

  duration = pulseIn(10, HIGH); 
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
