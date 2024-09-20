#ifndef FIELD_H
#define FIELD_H

#include "Farm.h"
#include "Farmer.h"

class Field : public Farm, public Farmer {
    protected:
    int FertilizationPrice;
    int PesticidePrice;

    public:
    virtual void Fertilzation();
    virtual void Pesticide();
    void setPrice();
    int getPrice();
    virtual int maxFieldCapacity();
    virtual int increaseMaxFieldCapacity();
    virtual int getMaxFieldCapacity();
};

#endif