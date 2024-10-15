#ifndef PIG_H
#define PIG_H

#include "Barn.h"
#include "Events.h"

// This class has attributed and functions that manage the pigs in the farm.
// This class inherits from Barn and Events class.
class Pig : public Barn, public Events {
 protected:
  bool pigEvent;

 public:
  Pig();                            // constructor
  void applyHighYield(int* money);  // modified sellPrice & money(from farmer)
  void Event(int* count);

  // getter & setters for pigEvent
  void setPigEvent(bool pigEvent);
  bool getPigEvent();
};

#endif