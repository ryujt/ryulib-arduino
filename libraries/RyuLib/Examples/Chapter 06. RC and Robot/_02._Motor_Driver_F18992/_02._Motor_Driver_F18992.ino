const int ch_05 = 3; 
const int ch_06 = 5;

const int full_speed = 255;
const int middle_speed = 200;
const int low_speed = 100;

void setup() 
{
  pinMode(ch_05, OUTPUT);
  pinMode(ch_06, OUTPUT);
}

void forward()
{
  analogWrite(ch_05, full_speed);
  analogWrite(ch_06, full_speed);
}

void left()
{
  analogWrite(ch_05, full_speed);
  analogWrite(ch_06, middle_speed);
}

void right()
{
  analogWrite(ch_05, middle_speed);
  analogWrite(ch_06, full_speed);
}

void left_only()
{
  analogWrite(ch_05, low_speed);
  analogWrite(ch_06, 0);
}

void right_only()
{
  analogWrite(ch_05, 0);
  analogWrite(ch_06, low_speed);
}

void stop()
{
  analogWrite(ch_05, 0);
  analogWrite(ch_06, 0);
}

void loop() 
{
  left_only();
//  forward();
}
