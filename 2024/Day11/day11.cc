// Wayne Mack
// Advent Of Code
// Day 11

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

static vector<vector<int>> readFileToVectors(const string&);

int countDigit(unsigned long long);
void partOneProcedure(unsigned long long& , unsigned long long , int );
vector<vector<int>> readFileToVectors(const string&);
void splitInHalf(unsigned long long, unsigned long long&, unsigned long long&);

int main() {
    string filename = "day11.txt"; 
    vector<vector<int>> numbers = readFileToVectors(filename);
    unsigned long long partOne = 0;
    int phases = 75;
    
    for (int a : numbers[0]) {
        cout << a << endl;
        partOneProcedure(partOne,a,phases);
    }
    cout << "Part One: " << partOne << endl;
    return 0;
}

int countDigit(unsigned long long n) {
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

 void splitInHalf(unsigned long long number, unsigned long long& firstHalf, unsigned long long& secondHalf) {
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

void partOneProcedure(unsigned long long& partOneValue, unsigned long long value, int depth) {
    cout << "depth :" <<  depth << endl;
    if (depth == 0) {
        partOneValue = partOneValue + 1;
    }
    else if (value == 0) {
        partOneProcedure(partOneValue, 1, depth - 1);
    }
    else if (countDigit(value) % 2 == 0) {
        unsigned long long first = 0; unsigned long long second = 0;
        splitInHalf(value, first,second);
        partOneProcedure(partOneValue, first, depth - 1);
        partOneProcedure(partOneValue, second, depth - 1);
    }
    else {
        partOneProcedure(partOneValue,value * 2024, depth - 1);

    }
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
