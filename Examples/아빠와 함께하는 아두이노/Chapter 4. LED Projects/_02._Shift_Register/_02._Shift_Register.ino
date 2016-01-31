int pinClock = 2;
int pinLatch = 3;
int pinData = 4; 

void setup() {
  pinMode(pinData, OUTPUT);
  pinMode(pinClock, OUTPUT);  
  pinMode(pinLatch, OUTPUT);
  
}

void loop() {
  writeShift( 0b00000001 );
  delay(200);
  
  writeShift( 0b00000010 );
  delay(200);

  writeShift( 0b00000100 );
  delay(200);

  writeShift( 0b00001000 );
  delay(200);

  writeShift( 0b00010000 );
  delay(200);

  writeShift( 0b00100000 );
  delay(200);
}

void writeShift(byte data)
{
  shiftOut( pinData, pinClock, MSBFIRST, data );
  digitalWrite( pinLatch, HIGH );
  digitalWrite( pinLatch, LOW );
}
