#ifndef IR_UTILS_H
#define IR_UTILS_H

#include <Arduino.h>

void start_ir(int pin);
void stop_ir();
unsigned long get_ir_code();

#endif // IR_UTILS_H