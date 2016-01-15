#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <Arduino.h>

class Listener {

protected:
  void on_Interval() = 0;
  void on_Timer() = 0;
  
public:
  void execute() = 0;  
};

class Scheduler {
private:
  // std::Vector<Listener> *_listeners;
public:
  // void addListener(Listener *pListener)
  // {
  //   _listener = pListener;
  // }
  
  // void tick()
  // {
  //   _listener->execute();
  // }
};

#endif // SCHEDULER_H