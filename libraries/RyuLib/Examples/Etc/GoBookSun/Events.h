#ifndef EVENTS_H

#include <Arduino.h>


typedef void (* VoidEvent) ();
typedef void (* IntegerEvent) (int);
typedef void (* PositionEvent) (double, double);


#endif // EVENTS_H