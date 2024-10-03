#include "Wheat.h"
#include "Events.h"

Wheat::Wheat():Field(){

    this->buyPrice = 10;
    this->sellPrice = 20;
    this->sellTime = 30;

    this->pesticidePrice = 1;
	this->highYieldFactor = 1.1;
    this->highYieldPrice = 1;

}

void Wheat::Event(){

}

void Wheat::applyHighYield(){

}