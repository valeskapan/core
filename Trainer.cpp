//
//  Trainer.cpp
//  CreatureTrainer
//
//  You may NOT #include any .h files we provide you (Battle, Creature, CreatureType,
//  EECSRandom, Party, PrintHelper)
//  other than the ones name "ClassX.h" and "Trainer.h"
//  You may #include other <> libraries if you wish to
//
//  Created by Jeremy Gibson on 11/4/14.
//  Copyright (c) 2014 Jeremy Richard Gibson. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "Trainer.h"
#include "Class1.h"
#include "Class2.h"
#include "Class3.h"
#include "Class4.h"
#include "Class5.h"

//#include "CreatureType.h"

using namespace std;

string Trainer::makeMove(stringstream& situation) {

    // pull the entire string out of stringStream& situation
    string situationString = situation.str();
    // situationString now includes ALL of the lines that will be sent to cout
    
    // Here's how to use the stringSplit function
    vector<string> lines = splitString(situationString, "\n");
    // This splits situationString into a vector of individual lines.
    // (it splits on the new line character "\n")
    // To access the 3rd line (as in 0, 1, 2, 3), you would use bracket access
    //   as in: lines[3]
    
    // This loop will iterate through all the lines
    int pipeLine = -1;
    // lines.size() tells us how many elements are in the vector<string> lines
    // In this case, it tells us how many lines we pulled in
    for (int i=0; i<lines.size(); i++) {
        // Store each line in the string line
        string line = lines[i];
        // Store the first char of line in the char c
        char c = line[0];
        // If c is a pipe ('|'), then this is the line that tells us about our
        //    party and the health of each Creature we own.
        if (c == '|') {
            // Store which line number this is
            pipeLine = i;
        }
    }
    
    // Now that we know which line has the health, do something with it
    //cout << lines[pipeLine] << "\n"; // Output for testing only
    
    // Split the party health line by pipes "|"
    vector<string> creatureHealthBits = splitString(lines[pipeLine], "|");
    // This gives us something like the vector description below
    /* { "",
         " *Jackal     10/10",
         " Yaminon    17/17",
         " Megapode   13/13",
         " Jackal     10/10",
         "" } */
    // You can see that the first and last pipe caused empty strings
    
    // Now, go through this information and pull out info for each entry
    // We do 1 to <creatureHealthBits.size()-1 because we only need the middle
    //    four elements (and are skipping the empty ones.
	
	int currPokNum = 0;//should use 1,2,3,4 to refer to current Pokemon Number

    for (int i=1; i<creatureHealthBits.size()-1; i++) {
        // cout just for testing
        //cout << creatureHealthBits[i] << "\n";
        
        // We are putting the string into a stringStream so we can use >>
        stringstream ss;
        ss << creatureHealthBits[i];
        
        // For example, we have a stringstream ss containing " *Jackal   10/10 "
        // pull the name as a string
        string name;
        ss >> name; // name = "*Jackal"
        
		int thisPokType = 0;

		if (name[0] == '*'){
			currPokNum = i;
			thisPokType = static_cast<int>(name[0]) - 65;
		}
		else{
			
			thisPokType = static_cast<int>(name[0]) - 65;
		}
		
        // pull the health
        int health;
        ss >> health; // health = 10
        
        // Get rid of the slash char
        char slash;
        ss >> slash; // slash = '/'
        
        // get max health
        int maxHealth;
        ss >> maxHealth; // maxHealth = 10
        
        // cout this info for testing purposes
        //cout << "Name: " << name << " health: " << health << "\n";

		fourKings[i - 1].setHealthCurr(health);
		fourKings[i - 1].setHealthMax(maxHealth);
		fourKings[i - 1].setDifference(maxHealth - health);

    }
    
    // This is something else you can do ONLY for testing.
    // In a previous post, I recommended #including CreatureType.h so that you
    //    can make a Trainer::decide() function that will make the right
    //    decision if you have perfect data about creature types.
    // While developing, you can use the static vector<CreatureType> TYPES to
    //    get that perfect information, though you will eventually need to write
    //    your own function to learn that information from the data that is sent
    //    in via stringstream& situation.
    
/*
    // This makes ct a copy of the CreatureType for Creature 0 (the Axolotyl).
    // All CreatureType and Element names start with a different letter of the
    //    alphabet (CreatureType is A-Z, Element is A-H).
    CreatureType ct = CreatureType::TYPES[0];
    // You can then get the type of ct, which is 0 because it's the Axolotyl
    int type = ct.getType();
    // You can also directly get info from CreatureTypes::TYPES elements.
    int elementalWeakness3 = CreatureType::TYPES[3].getElementalWeakness();
*/
    
    // Output for human player
    // Instead of doing this, you will need to replace the code of Trainer 
    // to parse the input situation and create a proper response,
    // (like "a" for attack or "s3" to swap to the creature in slot 3).
    cout << situationString;
    

    /* 
     * This line is basically what your AI chooses to do
     * When first playing, you may type in your move.
     * For both the core and reach portions, however, you need to
     * comment out "cin >> response" and instead have this function
     * generate a response string.
     */

	string decisionFour[4] = { "s1", "s2", "s3", "s4" };


	if (fourKings[currPokNum - 1].getDifference()>= fourKings[currPokNum - 1].getHealthCurr()){
		currPokNum = currPokNum % 4;
			if (fourKings[currPokNum].getHealthCurr() != 0){ //if next Pokemon is alive
				return decisionFour[currPokNum]; //change to next Pokemon
			}
			else{
				currPokNum++;
				currPokNum = currPokNum % 4;
				if (fourKings[currPokNum].getHealthCurr() != 0){
					return decisionFour[currPokNum];
				}
				else{
					currPokNum++;
					currPokNum = currPokNum % 4;
					if (fourKings[currPokNum].getHealthCurr() != 0){
						return decisionFour[currPokNum];
					}
					else{
						return "a";
					}
				}
			}
		


		return decisionFour[currPokNum];
	}
	else{
		return "a";
	}
	
	string response = "a";
    //cin >> response;
        

    return response;
}


void Trainer::finalSituation(stringstream& situation) {
    cout << situation.str();
    
}



vector<string> Trainer::splitString(string inString, string splitOn) {
    vector<string> elements;
    string substring;
    
    size_t splitIndex = inString.find(splitOn),
    substrStart = 0;
    
    // keep searching until no spaces remain
    while (splitIndex != string::npos) {
        substring = inString.substr(substrStart, splitIndex - substrStart);
        elements.push_back(substring);
        substrStart = splitIndex + 1;
        // start at next character after finding substring
        splitIndex = inString.find(splitOn, substrStart);
    }
    // add last element to vector
    substring = inString.substr(substrStart, inString.length() - substrStart);
    elements.push_back(substring);
    
    return elements;
}