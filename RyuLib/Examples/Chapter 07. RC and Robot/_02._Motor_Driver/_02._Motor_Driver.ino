const int a_01 = 2;  
const int a_02 = 3; 
const int b_01 = 4;
const int b_02 = 5;

void setup() 
{
  pinMode(a_01, OUTPUT);
  pinMode(a_02, OUTPUT);
  pinMode(b_01, OUTPUT);
  pinMode(b_02, OUTPUT);
}

void loop() 
{
  // forward
  digitalWrite(a_01, HIGH);
  digitalWrite(a_02, LOW);
  digitalWrite(b_01, HIGH);
  digitalWrite(b_02, LOW);
  delay(2000);
  
//  backward
  digitalWrite(a_01, LOW);
  digitalWrite(a_02, HIGH);
  digitalWrite(b_01, LOW);
  digitalWrite(b_02, HIGH);
  delay(2000);
  
//  left
  digitalWrite(a_01, HIGH);
  digitalWrite(a_02, LOW);
  digitalWrite(b_01, LOW);
  digitalWrite(b_02, HIGH);
  delay(2000);
  
//  right
  digitalWrite(a_01, LOW);
  digitalWrite(a_02, HIGH);
  digitalWrite(b_01, HIGH);
  digitalWrite(b_02, LOW);  
  delay(2000);

  // stop
  digitalWrite(a_01, LOW);
  digitalWrite(a_02, LOW);
  digitalWrite(b_01, LOW);
  digitalWrite(b_02, LOW);
  delay(2000);
}
