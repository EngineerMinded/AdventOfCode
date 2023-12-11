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
long long gcd(long long , long long);
long long lcm(long long, long long);
long long lcmOfVector(const vector<long long>&);



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
    vector<string> numerals = map->getValueEndingIn(numerals,'A');
    vector<long long> smallCalculations;
    for (string a : numerals) {
        long long m = 0;
        while (a[2] != 'Z') {
            a = map->find(a, directions, (int) m);
            m++;
        }
        cout << endl << m;
        smallCalculations.push_back(m);
    }

    return lcmOfVector(smallCalculations);
}

bool allEndsIn(vector<string> thisStuff, char letter) {
    for (string lastLetter : thisStuff) {
        if (lastLetter[2] != letter) {
            return false;
        }
    }
    return true;
}

long long lcmOfVector(const vector<long long>& nums) {
    if (nums.empty()) {
        return 0;
    }

    long long result = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        result = lcm(result, nums[i]);
    }

    return result;
}

long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}