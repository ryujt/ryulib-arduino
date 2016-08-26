#include "ir_utils.h"

IR ir(2);

void setup()
{
  Serial.begin(9600);
  ir.begin();
}

void loop()
{
  unsigned long result = ir.read();
  if (result != 0) Serial.println(result);
}
