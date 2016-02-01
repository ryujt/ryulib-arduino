#include <shift_utils.h>

ShiftRegister shiftRegister(2, 3, 4);

void setup() {
  shiftRegister.begin();
}

void loop() {
  shiftRegister.writeShift( 0b00000001 );
  delay(200);
  
  shiftRegister.writeShift( 0b00000010 );
  delay(200);

  shiftRegister.writeShift( 0b00000100 );
  delay(200);

  shiftRegister.writeShift( 0b00001000 );
  delay(200);

  shiftRegister.writeShift( 0b00010000 );
  delay(200);

  shiftRegister.writeShift( 0b00100000 );
  delay(200);

  shiftRegister.writeShift( 0b01000000 );
  delay(200);

  shiftRegister.writeShift( 0b10000000 );
  delay(200);
}
