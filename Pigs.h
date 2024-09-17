#ifndef PIGS_H
#define PIGS_H

#include "Barn.h"

// This class will contains methods relating to the breeding, selling ,etc of pigs.
// This class inherits from the Barn class.
class Pigs : public Barn {
    protected:
    // The attributes of the function are initialised. 
    int maxPigCapacity;
<<<<<<< HEAD
    int currentPigCount;
    double growthRate;

    public:
    Pigs();
    int setMaxAnimalCapacity();
=======
    int PigCount;
    int PigPrice; 

    public:
    Pigs();
    int getAnimalCount();
    int setMaxAnimalCapacity(int maxPigCapacity);
>>>>>>> f55edfc3412b1362cb69d24c63311fe6890787ae
    int MaxBarnCapacity();
    void increaseBarnCapacity();
    int getPigCount();

    int sellItem();
    double setGrowthRate();
    void setPrice();
    int getPrice();
    int getNumberOfItems(); 
<<<<<<< HEAD
    void BuyPig();
=======
>>>>>>> f55edfc3412b1362cb69d24c63311fe6890787ae
};

#endif