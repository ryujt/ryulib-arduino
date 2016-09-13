#include <analog_keyboard.h>

#define KEY_FIRE   200
#define KEY_RIGHT  500
#define KEY_DOWN   600
#define KEY_UP     800
#define KEY_LEFT  1000

int readKey(int pin) {
  int temp = analogRead(pin);	

       if (temp > KEY_LEFT)  return KEY_LEFT;
  else if (temp > KEY_UP)    return KEY_UP;
  else if (temp > KEY_DOWN)  return KEY_DOWN;
  else if (temp > KEY_RIGHT) return KEY_RIGHT;
  else if (temp > KEY_FIRE)  return KEY_FIRE;
  else return 0;
} 
