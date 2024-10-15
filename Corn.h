#ifndef CORN_H
#define CORN_H

#include "Events.h"
#include "Field.h"

// This class has functions for the corns in the farm. This class inherits from
// Field and Events.
class Corn : public Field, public Events {
 protected:
  bool cornEvent;

 public:
  Corn();  // constructor
  void Event(int* count);
  void applyHighYield(int* money);  // modifies sellPrice & money (in farmer)

  // getters and setters fo cornEvent
  void setCornEvent(bool cornEvent);
  bool getCornEvent();
};

#endif
