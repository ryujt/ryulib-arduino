#include "CharliePlexing.h"

int pin_1 = 2;
int pin_2 = 3;
int pin_3 = 4;
int pin_4 = 5;

void ch_flex(int w1, int w2, int w3, int w4)
{
  if (w1 == 0) pinMode(pin_1, INPUT);
  else pinMode(pin_1, OUTPUT);
  
  if (w2 == 0) pinMode(pin_2, INPUT);
  else pinMode(pin_2, OUTPUT);

  if (w3 == 0) pinMode(pin_3, INPUT);
  else pinMode(pin_3, OUTPUT);

  if (w4 == 0) pinMode(pin_4, INPUT);
  else pinMode(pin_4, OUTPUT);

  if (w1 == 1) digitalWrite(pin_1, HIGH);
  else digitalWrite(pin_1, LOW);
  
  if (w2 == 1) digitalWrite(pin_2, HIGH);
  else digitalWrite(pin_2, LOW);
  
  if (w3 == 1) digitalWrite(pin_3, HIGH);
  else digitalWrite(pin_3, LOW);
  
  if (w4 == 1) digitalWrite(pin_4, HIGH);
  else digitalWrite(pin_4, LOW);
}

void light_up(int no)
{
  switch(no) {
    case  0: ch_flex(0, 0, 0, 0); break;
    case  1: ch_flex(0, 1, -1, 0); break;
    case  2: ch_flex(0, -1, 1, 0); break;
    case  3: ch_flex(1, 0, -1, 0); break;
    case  4: ch_flex(-1, 0, 1, 0); break;
    case  5: ch_flex(0, 1, 0, -1); break;
    case  6: ch_flex(0, -1, 0, 1); break;
    case  7: ch_flex(1, 0, 0, -1); break;
    case  8: ch_flex(-1, 0, 0, 1); break;
    case  9: ch_flex(0, 0, -1, 1); break;
    case 10: ch_flex(0, 0, 1, -1); break;
    case 11: ch_flex(-1, 1, 0, 0); break;
    case 12: ch_flex(1, -1, 0, 0); break;
  }
}
