#include "Corn.h"
#include "Events.h"

Corn::Corn():Field(){

    this->buyPrice = 20;
    this->sellPrice = 30;
    this->sellTime = 40;

    this->pesticidePrice = 2;
	this->highYieldFactor = 1.2;
    this->highYieldPrice = 2;

}

void Corn::Event(){

}

void Corn::applyHighYield(){

}