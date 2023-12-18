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
#include "spring.h"
using namespace std;

Spring* spring;

int main() {
    ifstream file("puzzle.data"); // Replace with your file name
    spring = new Spring();

    if (!file.is_open()) {
        cerr << "Unable to open the file" << std::endl;
        return 1;
    }
    string line;
    while (getline(file, line)) {
        spring->add(line);
    }
    file.close();

    spring->print();
    cout << "Part One - > " << spring->getValue();
    return 0;
}