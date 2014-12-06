//  Class1.cpp
//  Helper Class1
//
//  These class heaaders are for use in your Trainer class. If you wish to 
//  write helper classes, write them in these 5 classes. 
//  Use of these classes is optional. You may use none or any or all of them. 
//  You still may NOT #include any.h files we provide you
//  (Battle, Creature, CreatureType, EECSRandom, Party, PrintHelper)
//

#include "Class1.h"
#include "Class2.h"

using namespace std;

const string myPokemon::CREATURE_NAMES[] = { "Axolotyl", "Bittern", "C-lacanth",
"Dugong", "Echidna", "Fossa", "Guanaco", "Honeybdgr", "Ibex", "Jackal",
"Kiwi", "Loris", "Megapode", "Narwhal", "Ovenbird", "Pika", "Quagga",
"RockHyrax", "Solenodon", "Tuatara", "Uromastyx", "Vaquita", "Wolverine",
"Xenops", "Yaminon", "Zebu" };

const string myPokemon::ELEMENT_NAMES[] = { "Air", "Bombast", "Cool", "Dark",
"Earth", "Funk", "Gamma", "Hammer" };

std::vector<myPokemon> myPokemon::TYPES = {};


myPokemon::myPokemon() {
	// Do nothing
}


int myPokemon::getType() {
	return type;
}

void myPokemon::setType(int cType) {
	type = cType;
	level = 0;
	healthMax = myPokemon::TYPES[cType].getHealthMaxBase();
	healthCurr = healthMax;
	xp = 0;
}

int myPokemon::getHealthCurr() {
	return healthCurr;
}

void myPokemon::setHealthCurr(int num) {
	healthCurr = num;
}


int myPokemon::getAttackStrength() {

	return attackBase * 2;
}

int myPokemon::getAttackElement() {
	return elementalAttackType;
}

int myPokemon::getElementalWeakness() {
	return elementalWeakness;
}

int myPokemon::getElementalStrength() {
	return elementalStrength;
}

int myPokemon::damage(int amount, int element) {
	if (element == getElementalWeakness()) {
		amount *= 2;
	}
	else if (element == getElementalStrength()) {
		amount /= 2;
	}
	if (amount > healthCurr) amount = healthCurr;
	healthCurr -= amount;
	return amount;
}

int myPokemon::getLevel() {
	return level;
}

void myPokemon::setLevel(int num) {
	level = num;
}
int myPokemon::getXp() {
	return xp;
}

void myPokemon::setXp(int num) {
	xp = num;
}

//below this line is the funtions I added

int myPokemon::getDifference(){
	return difference;
}

void myPokemon::setDifference(int diff){
	difference = diff;
}

int myPokemon::getHealthMax(){
	return healthMax;
}

void myPokemon::setHealthMax(int max){
	healthMax = max;
}


int myPokemon::getHealthMaxBase() {
	return healthMaxBase;
}

void myPokemon::setHealthMaxBase(int num) {
	healthMaxBase = num;
}


int myPokemon::getHealthRestIncrease() {
	return healthRestIncrease;
}

void myPokemon::setHealthRestIncrease(int num) {
	healthRestIncrease = num;
}


int myPokemon::getAttackBase() {
	return attackBase;
}

void myPokemon::setAttackBase(int num) {
	attackBase = num;
}

int myPokemon::getElementalAttackType() {
	return elementalAttackType;
}

void myPokemon::setElementalAttackType(int num) {
	elementalAttackType = num;
}

void myPokemon::setElementalWeakness(int num) {
	elementalWeakness = num;
}

void myPokemon::setElementalStrength(int num) {
	elementalStrength = num;
}


int myPokemon::getHealthMaxPerLevel() {
	return healthMaxPerLevel;
}


void myPokemon::setHealthMaxPerLevel(int num) {
	healthMaxPerLevel = num;
}


int myPokemon::getAttackPerLevel() {
	return attackPerLevel;
}

void myPokemon::setAttackPerLevel(int num) {
	attackPerLevel = num;
}

