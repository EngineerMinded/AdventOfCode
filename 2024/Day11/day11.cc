// Wayne Mack
// Advent Of Code
// Day 11

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include<tuple>
#define BIGNUM unsigned long long
using namespace std;

static vector<vector<int>> readFileToVectors(const string&);
static vector<pair<BIGNUM, vector<pair<unsigned long,int>>>> knownLengths;

int countDigit(BIGNUM);
void partOneProcedure(BIGNUM& , BIGNUM , int );
vector<vector<int>> readFileToVectors(const string&);
void splitInHalf(BIGNUM, BIGNUM&, BIGNUM&);
BIGNUM spaceMemory (pair<BIGNUM, vector<pair<unsigned long,int>>>);
void addNewMemory(pair<BIGNUM, vector<pair<unsigned long,int>>>, BIGNUM, BIGNUM, int);
vector<vector<BIGNUM>> cache;

int getCache(int depth, int value) {
    for (vector<BIGNUM> info : cache) {
        if (info[0] == depth && info[1] == value ) {
            return info[2];
        }
    }
    return -1;
}

int main() {
    string filename = "day11.txt"; 
    vector<vector<int>> numbers = readFileToVectors(filename);
    BIGNUM partOne = 0;
    int phases = 75;
    int countOf = 0;
    for (int a : numbers[0]) {
        countOf++;
        cout << countOf <<" of " << numbers[0].size() << endl;

        partOneProcedure(partOne,a,phases);
    }
    cout << "Part One: " << partOne << endl;
    return 0;
}

int countDigit(BIGNUM n) {
      // Base case
    if (n == 0)
        return 1;
  
    int count = 0;
  
      // Iterate till n has digits remaining
    while (n != 0) {
      
          // Remove rightmost digit
        n = n / 10;
      
          // Increment digit count by 1
        ++count;
    }
    return count;
}

 void splitInHalf(BIGNUM number, BIGNUM& firstHalf, BIGNUM& secondHalf) {
     int orig = number;
     firstHalf = 0; secondHalf = 0;
     int multiplier = 1;

    int half = countDigit(number) / 2;
    for (int i = 0; i < half; i++) {

        secondHalf = secondHalf + ((number % 10) * multiplier); 
        multiplier = multiplier * 10;
        number = number / 10; 
    }
    firstHalf = number;
    //cout << "Split:" << orig << " " << firstHalf << " " << secondHalf << endl;
}

void partOneProcedure(BIGNUM& partOneValue, BIGNUM value, int depth) {
    int initialDifference = partOneValue;
    //cout << "depth :" <<  depth << endl;
    if (depth == 0) {
        partOneValue = partOneValue + 1;
    }
    else if (getCache(depth, value) != -1) {
        partOneValue += getCache(depth, value);
        cout << "USE -------------------------------------------------" << getCache(depth, value) << endl;
        return;
    }

    else if (value == 0) {
        partOneProcedure(partOneValue, 1, depth - 1);
    }
    else if (countDigit(value) % 2 == 0) {
        BIGNUM first = 0; BIGNUM second = 0;
        splitInHalf(value, first,second);
        partOneProcedure(partOneValue, first, depth - 1);
        partOneProcedure(partOneValue, second, depth - 1);
    }
    else {
        partOneProcedure(partOneValue,value * 2024, depth - 1);

    }
    vector<BIGNUM> pushThis;
    pushThis.push_back(depth);
    pushThis.push_back(value);
    pushThis.push_back(partOneValue - initialDifference);
    cache.push_back(pushThis);
    cout << "Add : " << depth << " " << value << " " << partOneValue - initialDifference << endl;
}

vector<vector<int>> readFileToVectors(const string& filename) {
    vector<vector<int>> result;
    ifstream file(filename);
    // Check if file is open
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return result;  // Return empty result if the file can't be opened
    }
    string line;
    // Read file line by line
    while (getline(file, line)) {
        stringstream ss(line);
        vector<int> lineNumbers;
        int number;
        
        // Read numbers separated by spaces in each line
        while (ss >> number) {
            lineNumbers.push_back(number);
        }
        
        // Add the vector of numbers to the result
        result.push_back(lineNumbers);
    }
    file.close();
    return result;
}
