#ifndef THERMISTOR_H
#define THERMISTOR_H

#include <Arduino.h>
#include <math.h>

double ThermistorToC(int RawADC);
double ThermistorToF(int RawADC);

#endif // THERMISTOR_H
