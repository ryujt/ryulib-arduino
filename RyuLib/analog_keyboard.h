#ifndef ANALOG_KEYBOARD_H
#define ANALOG_KEYBOARD_H

#define KEY_FIRE   200
#define KEY_RIGHT  500
#define KEY_DOWN   600
#define KEY_UP     800
#define KEY_LEFT  1000

#include <Arduino.h>

int readKey(int pin);

#endif // ANALOG_KEYBOARD_H
