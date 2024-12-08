// Wayne Mack
// Advent Of Code
// Day 7

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

static string filename = "day7.txt";
unsigned long long getFirstNumber (string InputData) {
    unsigned long long returnMe = 0;
    for (char t : InputData) {
        if (isdigit(t)) {
            returnMe = returnMe * 10;
            returnMe = returnMe + t - '0';
        }
        else if(t == ':') {
            return returnMe;
        }
    }
    return returnMe;
}
vector<unsigned long long>parseNumbers(string InputData) {
    vector<unsigned long long> returnMe;
    bool passedColon = false; unsigned long long currentNumber = 0;
    for (char t : InputData) {
        if (passedColon) {
            if (isdigit(t)) {
                currentNumber = currentNumber * 10;
                currentNumber = currentNumber + t - '0';
            }
            else if (t == ' ') {
                if (currentNumber != 0) {
                    returnMe.push_back(currentNumber);
                    currentNumber = 0;
                }
            }
        }
        if ( t == ':') {
            passedColon = true;
        }
    }
    if (currentNumber != 0) {
        returnMe.push_back(currentNumber);
    }
    return returnMe;
}

unsigned long long concatenate(unsigned long long num1, unsigned long long num2) {
    unsigned long long digits = 0;
    unsigned long long temp = num2;

    while (temp > 0) {
        temp /= 10;
        digits++;
    }

    unsigned long long result = num1 * static_cast<unsigned long long>(pow(10, digits)) + num2;
    return result;
}

void getCombinations(vector<unsigned long long>& resultPointer, vector<unsigned long long>& variables, int location, unsigned long long sofar, bool part2) {
    if (location == variables.size() - 1) {
        resultPointer.push_back(sofar + variables[location]);
        resultPointer.push_back(sofar * variables[location]);
        if (part2)  resultPointer.push_back(concatenate(sofar,variables[location]));
    }
    else {
        unsigned long long sofarMult = 0;
        if (location == 0) {
             sofarMult = 1 * variables[location];
        }
        else {
             sofarMult = sofar * variables[location];
        }
        
        unsigned long long sofarAdd = sofar + variables[location];
        unsigned long long sofarConcatenate = concatenate(sofar,variables[location]);
        getCombinations(resultPointer, variables, location + 1, sofarMult, part2);
        getCombinations(resultPointer, variables, location + 1, sofarAdd, part2);
        if (part2) getCombinations(resultPointer, variables, location + 1, sofarConcatenate, part2);
    }
}

int main() {
    // Open the file
    std::ifstream file(filename);

    // Check if the file was successfully opened
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file " << filename << std::endl;
        return -1;
    }

    std::string line;
    unsigned long long partOne = 0, partTwo = 0;
    // Read the file line by line
    vector<unsigned long long>Answers2OutPut;
    while (std::getline(file, line)) {
        // Line is your data. do something with it
        std::cout << line << std::endl;
        unsigned long long  firstNumber = getFirstNumber(line);
        vector<unsigned long long> varias = parseNumbers(line);
        cout << endl;
        vector<unsigned long long> allAnswersPartOne;
        vector<unsigned long long> allAnswersPartTwo;
        getCombinations(allAnswersPartOne, varias, 0, 0, false);
        getCombinations(allAnswersPartTwo, varias, 0, 0, true);
        for (unsigned long long answer : allAnswersPartOne) {
            //cout << answer << " <- Answer" << endl;
            if (answer == firstNumber) {
                cout << answer << endl;
                partOne = partOne + answer;
                Answers2OutPut.push_back(answer);
                break;
            }
        }
        for (unsigned long long answer : allAnswersPartTwo) {
            //cout << answer << " <- Answer" << endl;
            if (answer == firstNumber) {
                cout << answer << endl;
                partTwo = partTwo + answer;
                Answers2OutPut.push_back(answer);
                break;
            }
        }
    }

    // Close the file
    file.close();
    cout<< "Part One: " << partOne << endl;
    cout<< "Part Two: " << partTwo << endl;
    return 0;
}