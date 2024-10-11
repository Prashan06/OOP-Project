#ifndef EVENTS_H
#define EVENTS_H

//abstract class
class Events {

    public:
        // overloaded in Cow, Pig, Corn, and Wheat classes.
        virtual void Event(int* count) = 0;

};

#endif