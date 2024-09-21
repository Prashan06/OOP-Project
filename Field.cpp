#include "Field.h"

Field::Field() : Farm(), wheatCount(0), cornCount(0),wheatGrowthRate(0), cornGrowthRate(0), cropCount(0){}


int Field::getCropCount(){
    cropCount = wheatCount + cornCount;
    return cropCount;
}

void Field::setCropCount(int wheatCount, int cornCount){
    cropCount = wheatCount + cornCount;
} 

int Field::increaseMaxFieldCapacity(){}
void Field::setMaxFieldCapacity(){}