#ifndef EVENTS_H
#define EVENTS_H


class Events {
    public:
    virtual void Event(int &count, Cow** cow, Pig** pig, Corn** corn, Wheat** wheat) = 0;
};

#endif