#ifndef FIELD_H
#define FIELD_H

#include <iostream>
#include "Farm.h"
#include "Farmer.h"

class Field : public Farm, public Farmer {
    protected:
    int FertilisationPrice;
    int PesticidePrice;

    public:
    Field();
    virtual void Fertilzation();
    virtual void Pesticide();
    int getCropCount();
    void setCropCount(int wheatCount, int cornCount );    
    virtual int increaseMaxFieldCapacity();
    virtual void setMaxFieldCapacity();
};

#endif