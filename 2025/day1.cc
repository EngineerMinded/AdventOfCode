// Wayne Mack
// Advent of Code
// Day 2025 day 1

// TWO STARS

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;

#define START_NUMBER 50
#define FILENAME "2025Day1.txt"

int totalZeroesForPart2 = 0;

int nextNumber(int originalNum, string &nextMove) {

    char letter = nextMove[0];
    int parsedNumber = stoi(nextMove.substr(1));
    parsedNumber = parsedNumber % 100;
    
    if (letter == 'L') {
        originalNum = originalNum - parsedNumber;
    }
    else {
        originalNum = originalNum + parsedNumber;
    }
    if (originalNum < 0) {     
        originalNum += 100;    
    }
    else if (originalNum > 99) {
        originalNum -= 100;  
    }
    return originalNum;
}

int part2 (int originalNum, string &next) {
    int zeroes = 0;
    int number = originalNum;
    char letter = next[0];
    int parsedNumber = stoi(next.substr(1));
    
    for (int g = 0; g < parsedNumber; g++) {
        letter == 'L' ? number -=1 : number +=1;
        number <= -1 ? number = 99 : number >= 100 ? number = 0: number +=0;
        if (number == 0) zeroes++;
    }
    return zeroes;
}

void readFileLineByLine(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Error opening file: " + filename + ". Please check the file path.");
    }
    std::string line;
    int numberOfZeros = 0;
    int combination = START_NUMBER;
    
    while (std::getline(inputFile, line)) {
        int origCom = combination;
        combination = nextNumber(combination,line);
        if (combination == 0) {
            numberOfZeros++;
        }
        totalZeroesForPart2 += part2(origCom,line);
    }

    inputFile.close();
    
    if (inputFile.bad()) {
        throw std::runtime_error("An irrecoverable I/O error occurred while reading the file.");
    }

    cout << "The first Answer is " << numberOfZeros<< endl;
    cout << "The Second Answer is " << totalZeroesForPart2;
}

int main() {
    string filename = FILENAME;

    try {
        readFileLineByLine(filename);
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1; // Return non-zero to indicate error
    }

    return 0; // Return zero to indicate successful execution
}