//////////////////////////////////////////////
// Wayne Mack                               //
// Advent Of Code: Day 7                    //
//------------------------------------------//
// Written in: C++                          //
//////////////////////////////////////////////


// GOES INTO INFINITE LOOP SOMEWHERE ON THE ADD CYCLE! //

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "cards.h"
using namespace std;

Cards* cards;

int getNumberFromStringValue(string);

int main() {
    cards = new Cards();

    std::ifstream file("day7.data");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            istringstream iss(line);
            string cardHand, stringValue;
            iss >> cardHand;
            getline(iss, stringValue);
            stringValue = stringValue.substr(stringValue.find_first_not_of(' '));
            cards->add(cardHand, getNumberFromStringValue(stringValue));
            
        }
        cards->printCards();
        //cout << "\n\nPart One: " << cards->part1Tally(1) << endl;
        file.close();
    } else {
        std::cerr << "Unable to open file: " << std::endl;
    }

}

int getNumberFromStringValue (string stringValue) {
    int returnThis = 0;
    for (char num : stringValue) {
        if (num - '0' >= 0 && num - '0' <= 9) {
            returnThis = returnThis * 10;
            returnThis = returnThis + num - '0';
        }
    }
    return returnThis;
} 