/////////////////////////////////////////////////////
// Wayne Mack                                      //
// Advent of Code: Day 7                           //
// -- Haunted Wasteland ---                        //
//                                                 //
// FIRST STAR ACHIEVED                             //
/////////////////////////////////////////////////////

#include "Map.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

Map* map;
string directions;

int partOne();
int partTwo();
bool allEndsIn(vector<string>, char);

int main(){
    map = new Map();
    std::ifstream file("day8.data"); 

    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            if (line == "") {
                // BLANK STRING
            }
            else if (line.find('=') != std::string::npos) {
                map->add(line);
            }
            else {
                directions = line;
            }
        }
        file.close();
        cout << directions << endl;
        map->print();

        // PART ONE
        cout << " The number of steps to get to part one is: " << partOne();
        // PART TWO
        cout << "The number of cumulative steps in part two is : " << partTwo();
    }
    else {
        std::cout << "Unable to open the file." << std::endl;
    }
}



int partOne() {
    string currentCharacter = "AAA";
    string findCharacter = "ZZZ";
    int count = 0;

    while (currentCharacter != findCharacter) {
        cout << currentCharacter << " " << map->find(currentCharacter, directions, count) << " , ";
        currentCharacter = map->find(currentCharacter, directions, count);
        count++;
        cout << "Count : " << count << endl;
    }
    return count;
}

int partTwo() {

    // NOT COMPLETED

    return 1;
}

bool allEndsIn(vector<string> thisStuff, char letter) {
    for (string lastLetter : thisStuff) {
        if (lastLetter[2] != letter) {
            return false;
        }
    }
    return true;
}