const int a_01 = 3;  
const int a_02 = 4; 
const int b_01 = 5;
const int b_02 = 6;

void setup() 
{
  pinMode(a_01, OUTPUT);
  pinMode(a_02, OUTPUT);
  pinMode(b_01, OUTPUT);
  pinMode(b_02, OUTPUT);

  pinMode(9, OUTPUT);
  analogWrite(9, 100);

  pinMode(10, OUTPUT);
  analogWrite(10, 100);
}

void forward()
{
  digitalWrite(a_01, HIGH);
  digitalWrite(a_02, LOW);
  digitalWrite(b_01, HIGH);
  digitalWrite(b_02, LOW); 
}

void backward()
{
  digitalWrite(a_01, LOW);
  digitalWrite(a_02, HIGH);
  digitalWrite(b_01, LOW);
  digitalWrite(b_02, HIGH);
}

void left()
{
  digitalWrite(a_01, HIGH);
  digitalWrite(a_02, LOW);
  digitalWrite(b_01, LOW);
  digitalWrite(b_02, HIGH);
}

void right()
{
  digitalWrite(a_01, LOW);
  digitalWrite(a_02, HIGH);
  digitalWrite(b_01, LOW);
  digitalWrite(b_02, LOW);  
}

void left_only()
{
  digitalWrite(a_01, LOW);
  digitalWrite(a_02, LOW);
  digitalWrite(b_01, LOW);
  digitalWrite(b_02, HIGH);
}

void right_only()
{
  digitalWrite(a_01, LOW);
  digitalWrite(a_02, HIGH);
  digitalWrite(b_01, LOW);
  digitalWrite(b_02, LOW);  
}

void stop()
{
  digitalWrite(a_01, LOW);
  digitalWrite(a_02, LOW);
  digitalWrite(b_01, LOW);
  digitalWrite(b_02, LOW);  
}

void loop() 
{
//  forward();
//  delay(2000);

//  backward();
//  delay(2000);
  
//  left();
//  delay(2000);
  
//  right()
//  delay(2000);

  stop();
  left_only();
  delay(2000);

  stop();
  right_only();
  delay(2000);

  stop();
  delay(2000);
}
