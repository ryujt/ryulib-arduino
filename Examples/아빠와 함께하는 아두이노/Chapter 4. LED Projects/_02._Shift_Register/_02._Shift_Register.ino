int pin_clock = 2;
int pin_latch = 3;
int pin_data = 4; 

void setup() {
  pinMode(pin_clock, OUTPUT);
  pinMode(pin_latch, OUTPUT);  
  pinMode(pin_data, OUTPUT);  
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

  writeShift( 0b01000000 );
  delay(200);

  writeShift( 0b10000000 );
  delay(200);
}

void writeShift(byte data)
{
  shiftOut( pin_data, pin_clock, MSBFIRST, data );
  digitalWrite( pin_latch, HIGH );
  digitalWrite( pin_latch, LOW );
}
