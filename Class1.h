//
//  Class1.h
//  Class1
//
//  These class heaaders are for use in your Trainer class. If you wish to 
//  write helper classes, write them in these 5 classes. 
//  Use of these classes is optional. You may use none or any or all of them. 
//  You still may NOT #include any.h files we provide you
//  (Battle, Creature, CreatureType, EECSRandom, Party, PrintHelper)
//

// for this class, I would like to use this class for information gathering

#ifndef __CreatureTrainer__Class1__
#define __CreatureTrainer__Class1__

// vvvvvv Your implementations go between this line…
#include<iostream>
#include<string>
#include<vector>
#include"Class2.h"

using namespace std;

class myPokemon{
private:
	int type; // Creature's type (first letter of species name)
	int healthCurr; //- Current amount of health. If healthCurr reaches 0, the creature faints.
	int healthMax; // - Max amount of health
	int level; 	// (REACH) The numerical level of the creature. Starts at 0.
	int xp; // (REACH) The amount of experience that this creature has
	int difference;
	int healthMaxBase;	// - The health for a L0 version of this creature
	int healthMaxPerLevel; // - The increase in healthMax for each increase in level (REACH)
	int healthRestIncrease;// - The amount of health that regens for every turn rest() is called
	int attackBase; // The attack strength for a L0 version
	int attackPerLevel; // The increase in attack strength per level (REACH)
	int elementalAttackType; // The elemental type of the attack
	int elementalWeakness; // The elemental type that will do double damage to this creature
	int elementalStrength; // The elemental type that will do half damage to this creature

public:

	const static int    NUM_TYPES = 26; //One for each letter of alphabet
	const static int    NUM_ELEMENTS = 8;
	const static string CREATURE_NAMES[];
	const static string ELEMENT_NAMES[];
	const static int    TYPE_NAME_LENGTH = 9;
	const static int    ELEM_NAME_LENGTH = 7;

	static std::vector<myPokemon> TYPES;

	const static int healthMaxBaseMin = 10;
	const static int healthMaxBaseMax = 20;

	const static int healthMaxPerLevelMin = 2;
	const static int healthMaxPerLevelMax = 6;

	const static int healthRestIncreaseMin = 4;
	const static int healthRestIncreaseMax = 6;

	const static int attackBaseMin = 4;
	const static int attackBaseMax = 6;

	const static int attackPerLevelMin = 2;
	const static int attackPerLevelMax = 4;



	/**
	* Requires: Nothing.
	* Modifies: Nothing.
	* Effects:  Default constructor that does nothing
	*/
	myPokemon();

	/**
	* Requires: cType must be in the range [0, NUM_TYPES).
	* Modifies: CreatureType data.
	* Effects:  Randomizes the various stats for this CreatureType.
	*/
	static myPokemon factory(int cType);

	/**
	* Requires: Nothing.
	* Modifies: Nothing.
	* Effects:  Gets and returns the name of the CreatureType.
	*/
	// Note: int pad below has a default value of -1.
	//       This is called a "default parameter"
	string getTypeName(int pad = -1);



	/**
	* Requires: Nothing.
	* Modifies: Nothing.
	* Effects:  Gets and returns type - int representing index of creature in
	CreatureType::TYPES
	*/
	int getType();


	/**
	* Requires: int must be in the range [0, NUM_TYPES).
	* Modifies: type
	* Effects:  Sets type to int passed in.
	*/
	void setType(int cType);


	/**
	* Requires: Nothing.
	* Modifies: Nothing.
	* Effects:  Gets and returns healthCurr.
	*/
	int getHealthCurr();


	/**
	* Requires: num is in the range [0, healthMax]
	* Modifies: healthCurr
	* Effects:  Sets healthCurr to int passed in
	*/
	void setHealthCurr(int num);


	/**
	* Requires: Nothing.
	* Modifies: Nothing
	* Effects:  returns attack strength (changes with level)
	*/
	int getAttackStrength();


	/**
	* Requires: Nothing.
	* Modifies: Nothing.
	* Effects:  returns creature's elemental attack type
	*/
	int getAttackElement();


	/**
	* Requires: Nothing.
	* Modifies: Nothing.
	* Effects:  returns creature's elemental weakness (element that does extra
	damage to this creature)
	*/
	int getElementalWeakness();


	/**
	* Requires: Nothing.
	* Modifies: Increases health.
	* Effects:  returns creature's elemental strength (element that this
	creature will do extra damage to)
	*/
	int getElementalStrength();


	/**
	* Requires: Nothing.
	* Modifies: healthCurr
	* Effects:  Returns amount of damage this creature takes, given the enemy
	attack damage and enemy attack element as well as the amount
	of health that this Creature has remaining.
	Also applies damage to creature's health.
	*/
	int damage(int amount, int element);


	//below the line is the functions I added
	int getDifference();

	void setDifference(int diff);

	int getHealthMax();

	void setHealthMax(int max);



	/**
	* Requires: Nothing.
	* Modifies: Nothing.
	* Effects:  returns healthMaxBase.
	*/
	int getHealthMaxBase();


	/**
	* Requires: num is in the range [healthMaxBaseMin, healthMaxBaseMax]
	* Modifies: healthMaxBase
	* Effects:  Sets healthMaxBase.
	*/
	void setHealthMaxBase(int num);

	/**
	* Requires: Nothing.
	* Modifies: Nothing.
	* Effects:  returns healthRestIncrease.
	*/
	int getHealthRestIncrease();


	/**
	* Requires: num is in the range [healthRestIncreaseMin, healthRestIncreaseMax]
	* Modifies: healthRestIncrease
	* Effects:  Sets healthRestIncrease
	*/
	void setHealthRestIncrease(int num);


	/**
	* Requires: Nothing.
	* Modifies: Nothing.
	* Effects:  returns attackBase.
	*/
	int getAttackBase();


	/**
	* Requires: num is in the range [attackBaseMin, attackBaseMax]]
	* Modifies: attackBase
	* Effects:  Sets attackBase.
	*/
	void setAttackBase(int num);


	/**
	* Requires: Nothing.
	* Modifies: Nothing.
	* Effects:  returns elementalAttackType.
	*/
	int getElementalAttackType();


	/**
	* Requires: num is in the range [0, NUM_ELEMENTS).
	* Modifies: elementalAttackType
	* Effects:  Sets elementalAttackType.
	*/
	void setElementalAttackType(int num);


	/**
	* Requires: num is in the range [0, NUM_ELEMENTS).
	* Modifies: elementalWeakness
	* Effects:  Sets elementalWeakness.
	*/
	void setElementalWeakness(int num);

	/**
	* Requires: num is in the range [0, NUM_ELEMENTS).
	* Modifies: elementalStrength
	* Effects:  Sets elementalStrength.
	*/
	void setElementalStrength(int);

	//--------------Reach----------------
	/**
	* Requires: Nothing.
	* Modifies: Nothing.
	* Effects:  returns healthMaxPerLevel.
	*/
	int getHealthMaxPerLevel();


	/**
	* Requires: num is in the range [healthMaxPerLevelMin, healthMaxPerLevelMax]
	* Modifies: healthMaxPerLevel
	* Effects:  Sets healthMaxPerLevel.
	*/
	void setHealthMaxPerLevel(int num);


	/**
	* Requires: Nothing.
	* Modifies: Nothing.
	* Effects:  returns attackPerLevel.
	*/
	int getAttackPerLevel();


	/**
	* Requires: num is in the range [attackPerLevelMin, attackPerLevelMax]
	* Modifies: attackPerLevel
	* Effects:  Sets attackPerLevel.
	*/
	void setAttackPerLevel(int num);
	//--------------Reach----------------
	/**
	* Requires: Nothing.
	* Modifies: Nothing.
	* Effects:  Gets and returns level.
	*/
	int getLevel();


	/**
	* Requires: num >= 0
	* Modifies: Sets level.
	* Effects:  Nothing.
	*/
	void setLevel(int num);


	/**
	* Requires: Nothing.
	* Modifies: Nothing.
	* Effects:  Returns xp.
	*/
	int getXp();

	/**
	* Requires: num >= 0.
	* Modifies: Sets xp.
	* Effects:  Nothing.
	*/
	void setXp(int num);

};







// ^^^^^^ And this line. That's it!

#endif /* defined(__CreatureTrainer__Class1__) */
