////////////////////////////////////////////////////
// Wayne Mack                                     //
// Advent Of Code                                 //
// --- Day 5: If You Give A Seed A Fertilizer --- //
// -----------------------------------------------//
// Written in C++: Converted to Windows           //
////////////////////////////////////////////////////


//////// FAILED: NUMBER IS TOO LONG ///////////////
//////// MUST USE A DIFFERENT APPROACH ////////////

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Map.h"
using namespace std;

vector <int> getSeeds(const string&);
void printSeeds(const vector<int>& );
int partOneAnswer(const vector<int>&);

int main() {
    vector<int> seeds;
    Map* map = new Map();
    ifstream file("day5.data"); // Open the file

    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            // Process each line here
            size_t foundSeeds = line.find("seeds:");
            size_t foundMap = line.find("map:");
            if (foundSeeds != string::npos) {
                seeds = getSeeds(line);
                cout << "\nFound Seeds!\n";
            }
            else if (foundMap != string::npos) {
                map->addMap(line);
            }
            else if (line != "") {
                map->addMapData(line);
            }
        }
        file.close(); // Close the file after reading

        printSeeds(seeds);
        map->printMap();

        int part1Answer = 0;
        for (const int& num : seeds) {
            long z = map->getLocationNumber(num);
            if (part1Answer == 0) {
                part1Answer = z;
            }
            else if (part1Answer > z) {
                part1Answer = z;
            }
            
        }
        cout << "The lowest location number is : " << part1Answer << endl;
    }
    else {
        std::cout << "Unable to open file: " << endl;
    }

}

vector<int> getSeeds (const std::string& input1) {
    size_t found = input1.find(':');
    string input =  input1.substr(found + 1);

    vector<int> numbers;
    istringstream iss(input); 

   int num;
    while (iss >> num) {
        if (iss.eof()) { 
            numbers.push_back(num); 
            break;
        }
        else if (iss.fail()) {
            iss.clear(); 
            iss.ignore(); 
        }
        else {
            numbers.push_back(num); 
        }
    }
    std::cout << "Extracted numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    return numbers;
}

void printSeeds(const std::vector<int>& vec) {
    std::cout << "Integer vector: ";
    for (const int& num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int partOneAnswer(const std::vector<int>& numbers) {
    if (numbers.empty()) {
        std::cerr << "Vector is empty." << std::endl;
        return std::numeric_limits<int>::max(); 
    }

    int lowest = numbers[0]; 

    for (size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i] < lowest) {
            lowest = numbers[i]; 
        }
    }

    return lowest;
}
