///////////////////////////////////////////////////
// Wayne Mack                                    //
// Advent Of Code                                //
//      --- Day 11: Cosmic Expansion ---         //
// Written in: C++ (Windows)                     //
// BOTH STARS: COMPLETED                         //
///////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "galaxy.h"

Galaxy* galaxy;

Galaxy* getFileInfo(string, int);

int main()
{
    int part2Multiplier = 999999;
    string fileName = "puzzle.data";
    // PART ONE
	galaxy = getFileInfo(fileName, 1);
    for (int i = 0; i < galaxy->getMaxY(0); i++) {
        if (!galaxy->exists(-1, i)) {
            galaxy->expandY(i,1); i++;
        }
    }
    galaxy->print(); // ERROR CHECKING
    cout << "Part One ->" << galaxy->partOne() << endl;

    // PART TWO
    galaxy = getFileInfo(fileName , part2Multiplier);
    for (int i = 0; i < galaxy->getMaxY(0); i++) {
        if (!galaxy->exists(-1, i)) {
            galaxy->expandY(i, part2Multiplier); i = i + part2Multiplier;
        }
    }
    galaxy->print();
    cout << "Part Two ->" << galaxy->partOne() << endl;
}

Galaxy* getFileInfo(string fileName, int multiplier) {
    Galaxy* returnThis = new Galaxy();
    std::string file_name = fileName; 
    std::ifstream file(file_name);

    if (!file.is_open()) {
        std::cerr << "Unable to open the file " << file_name << std::endl;
        return returnThis;
    }

    std::string line;
    long long lineNumber = 0;
    while (std::getline(file, line)) {
        //std::cout << line << std::endl;
        bool hasGalaxy = false;
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == '#') {
                returnThis->add(lineNumber, i);
                hasGalaxy = true;
            }
        }
        if (!hasGalaxy) { lineNumber = lineNumber + multiplier; }
        lineNumber++;
    }
    file.close();
    return returnThis;
}

