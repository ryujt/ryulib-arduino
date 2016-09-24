int a_01 = 3;  
int a_02 = 6; 
int b_01 = 6;
int b_02 = 9;

int speed_a = 255;
int speed_b = 255;

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
  analogWrite(a_01, speed_a);
  analogWrite(a_02, 0);
  analogWrite(b_01, speed_b);
  analogWrite(b_02, 0);
  delay(2000);
  
//  backward
  analogWrite(a_01, 0);
  analogWrite(a_02, speed_a);
  analogWrite(b_01, 0);
  analogWrite(b_02, speed_b);
  delay(2000);
  
//  left
  analogWrite(a_01, speed_a);
  analogWrite(a_02, 0);
  analogWrite(b_01, 0);
  analogWrite(b_02, speed_b);
  delay(2000);
  
//  right
  analogWrite(a_01, 0);
  analogWrite(a_02, speed_a);
  analogWrite(b_01, speed_b);
  analogWrite(b_02, 0);
  delay(2000);

  // stop
  analogWrite(a_01, 0);
  analogWrite(a_02, 0);
  analogWrite(b_01, 0);
  analogWrite(b_02, 0);
  delay(2000);
}
