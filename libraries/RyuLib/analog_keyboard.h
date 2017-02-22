#ifndef ANALOG_KEYBOARD_H
#define ANALOG_KEYBOARD_H

// LCD4884
#define KEY_FIRE   100
#define KEY_RIGHT  500
#define KEY_DOWN   300
#define KEY_UP     700
#define KEY_LEFT   900 //0

#include <Arduino.h>

int readKey(int pin, int type=4884);

#endif // ANALOG_KEYBOARD_H
