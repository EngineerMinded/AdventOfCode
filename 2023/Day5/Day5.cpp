////////////////////////////////////////////////////
// Wayne Mack                                     //
// Advent Of Code                                 //
// --- Day 5: If You Give A Seed A Fertilizer --- //
// -----------------------------------------------//
// Written in C++: Converted to Windows           //
// FIRST STAR EARNED                              //
////////////////////////////////////////////////////

//  Use long long's instead of integers or longs  //



#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <tuple>
#include "Map.h"
using namespace std;
void prog();
vector <long long> getSeeds(const string&);
void printSeeds(const vector<long long>&);
long long partOneAnswer(const vector<long long>&);
vector <tuple < long long, long long >> part2Data(vector <long long>);

int main() {
    prog();
}

void prog() {
    vector<long long > seeds;
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


        // PART ONE

        long long part1Answer = 0;
        for (const long long& num : seeds) {
            long long z = map->getLocationNumber(num);
            if (part1Answer == 0) {
                part1Answer = z;
            }
            else if (part1Answer > z) {
                part1Answer = z;
            }

        }
        
        cout << "The lowest location number is : " << part1Answer << endl;

        // PART TWO

        long long part2Minimun = 0;

        vector<long long> start;
        vector<long long> range;
        int getRange = 0;
  
        for (const long long& num : seeds) {
            if (getRange == 1) {
                range.push_back(num);
                getRange = 0;
            }
            else {
                start.push_back(num);
                getRange = 1;
            }
        }
        
        for (int i = 0; i < start.size(); i++) {
            for (int j = start[i]; j < start[i] + range[i]; j++) {
                if (part2Minimun == 0) {
                    part2Minimun = map->getLocationNumber(j);
                }
                else {
                    if (part2Minimun > map->getLocationNumber(j)) {
                        part2Minimun = map->getLocationNumber(j);
                    }
                }
            }
        }
       
        cout << "\nThe minimum range for part 2 is: " << part2Minimun;
        
    }
    else {
        std::cout << "Unable to open file: " << endl;
    }

}

vector<long long> getSeeds(const std::string& input1) {
    size_t found = input1.find(':');
    string input = input1.substr(found + 1);

    vector<long long> numbers;
    stringstream iss(input);

    long long num;
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
    for (long long num : numbers) {
        std::cout << num << " ";
    }
    return numbers;
}

void printSeeds(const std::vector<long long>& vec) {
    std::cout << "Integer vector: ";
    for (const long long& num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

long long partOneAnswer(const std::vector<long long>& numbers) {
    if (numbers.empty()) {
        std::cerr << "Vector is empty." << std::endl;
        return std::numeric_limits<long long>::max();
    }

    long long lowest = numbers[0];

    for (size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i] < lowest) {
            lowest = numbers[i];
        }
    }

    cout << "the lowest number is:" << lowest;
    return lowest;
}

