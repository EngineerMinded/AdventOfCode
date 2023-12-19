//////////////////////////////////////////////////////////
// Wayne Mack                                           //
// Advent Of Code                                       //
//           --- Day 12: Hot Springs ---                //
// ---------------------------------------------------- //
// Written in C++ (GNU / GCC)                           //
// FIRST STAR ACHIEVED                                  //
//////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "spring.h"
using namespace std;

Spring* spring;
Spring* spring2;

string unfold(string);

int main() {
    ifstream file("example1.data"); // Replace with your file name
    spring = new Spring();
    spring2 = new Spring();

    if (!file.is_open()) {
        cerr << "Unable to open the file" << std::endl;
        return 1;
    }
    string line;
    while (getline(file, line)) {
        spring->add(line);
        spring2->add(line);
    }
    file.close();
    vector<int> g;
    spring->print();
    long long part1 = spring->getValue(false);
    long long part2 = spring2->getValue(true);
    cout << "Part One - > " << part1 << endl;
    cout << "Part Two - > " << part2 << endl;
    return 0;
}

string unfold(string original) {
    string front, back;
    stringstream ss(original);
    ss >> front >> back;
    string returnThis = "";
    for (int i = 0; i < 5; i++) {
        returnThis = returnThis + front;
        if (i < 4) {
            returnThis = returnThis + "?";
        }
    }
    returnThis = returnThis + " ";
    for (int i = 0; i < 5; i++) {
        returnThis = returnThis + back;
        if (i < 4) {
            returnThis = returnThis + ",";
        }
    }
    return returnThis;
}

