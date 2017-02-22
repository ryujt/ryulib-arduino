#include <analog_keyboard.h>

int readKey(int pin, int type) {
  int temp = analogRead(pin);	

  if (type == 168) {
	       if (temp > 1000) return KEY_LEFT;
	  else if (temp >  800) return KEY_UP;
	  else if (temp >  600) return KEY_DOWN;
	  else if (temp >  500) return KEY_RIGHT;
	  else if (temp >  200) return KEY_FIRE;
	  else return 0;
  } else if (type == 328) {
	  if (temp > 900) return 0;

	  else if (temp >  700) return KEY_FIRE;
	  else if (temp >  500) return KEY_RIGHT;
	  else if (temp >  300) return KEY_DOWN;
	  else if (temp >  100) return KEY_UP;
	  else return KEY_LEFT;
  } else {
	  if (temp > 900) return 0;

	       if (temp > KEY_UP)    return KEY_UP;
	  else if (temp > KEY_RIGHT) return KEY_RIGHT;
	  else if (temp > KEY_DOWN)  return KEY_DOWN;
	  else if (temp > KEY_FIRE)  return KEY_FIRE;
	  else return KEY_LEFT;
  }
} 


// // 168
// #define KEY_FIRE   200
// #define KEY_RIGHT  500
// #define KEY_DOWN   600
// #define KEY_UP     800
// #define KEY_LEFT  1000

// // 328
// #define KEY_FIRE   700
// #define KEY_RIGHT  500
// #define KEY_DOWN   300
// #define KEY_UP     100
// #define KEY_LEFT    10

