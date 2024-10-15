#ifndef FARMER_H
#define FARMER_H

#include <chrono>
#include <ctime>
#include <fstream>
#include <string>

#include "Barn.h"
#include "Corn.h"
#include "Cow.h"
#include "Farm.h"
#include "Field.h"
#include "Pig.h"
#include "Wheat.h"

using namespace std;

class Farmer : public Pig, public Corn, public Cow, public Wheat {
 protected:
  int money;
  int cowCount = 0;
  int pigCount = 0;
  int wheatCount = 0;
  int cornCount = 0;
  // arrays
  Wheat** wheat;
  Corn** corn;
  Pig** pig;
  Cow** cow;

  // tracking variables for object creation
  char farmName[21];
  int timesWheatPlanted;
  int timesCornPlanted;
  int timesCowsBought;
  int timesPigsBought;
  string product;
  fstream outputFile;
  fstream inputFile;

 public:
  Farmer();
  ~Farmer();

  // getters & setters
  int* getMoneyCount();
  void setMoneyCount(int money);
  string getFarmName();
  void setFarmName();
  void getStatus();
  int* getCowCount();
  int* getPigCount();
  int* getWheatCount();
  int* getCornCount();
  void setCowCount(int cowCount);
  void setPigCount(int pigCount);
  void setWheatCount(int wheatCount);
  void setCornCount(int cornCount);
  void executeEvent();
  void buyAnimal();
  void buyCrop();
  void sellAnimal();
  void sellCrop();
  // void fieldSpeedGrowthBought();
  void applySpeedGrowCrops();
  // void barnSpeedGrowthBought();
  void applySpeedGrowAnimals();
  // void highYieldBought();
  void applyHighYieldAnimals();
  void applyHighYieldCrops();
  string getProduct();
  void setProduct(string product);
  void appliedPesticide();

  Cow** getCowArray();
  Pig** getPigArray();
  Wheat** getWheatArray();
  Corn** getCornArray();
  Cow* createNewCow();
  Pig* createNewPig();
  Wheat* createNewWheat();
  Corn* createNewCorn();

  void fileWriter(string filename, int* money);
  void fileReader(string filename);
};
#endif