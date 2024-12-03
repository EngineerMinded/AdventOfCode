// Wayne Mack
// Advent of Code
// Day 2

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> readFileToVectors(const string&);
bool isSafe(vector<int>, int);
int findAnswer(vector<vector<int>>, int);
bool Dampener(vector<int>,int);

int main() {
    string filename = "day2.txt"; 
    vector<vector<int>> numbers = readFileToVectors(filename);
    
    cout << endl << "Part One: " << findAnswer(numbers,1);
    cout << endl << "Part Two: " << findAnswer(numbers,2);
    cout << endl;
    return 0;
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

int findAnswer (vector<vector<int>> numericData, int partNumber) {
    int answer = 0;
    for (const auto&  line : numericData) {
        if (isSafe(line,partNumber)) {
            answer++; 
        }
    }         
    return answer;
}

bool isSafe(vector<int> nums, int partNumber) {
    if (nums.size() < 2) {
        return false;
    }
    bool isIncreasing = true;
    bool isDecreasing = true;

    for (size_t i = 1; i < nums.size(); ++i) {
        int diff = nums[i] - nums[i - 1];

        if (diff == 0 || diff > 3 || diff < -3) {
            if (partNumber == 1) {
                return false;            
            } else {
                for (int x = 0; x < nums.size(); x++) {
                    if (Dampener(nums,x)) {
                        return true;
                    }
                }
                return false;  
            }
        }
        if (diff < 0) {
            isIncreasing = false;  
        }
        if (diff > 0) {
            isDecreasing = false; 
        }
        if ((!isDecreasing && !isIncreasing) && (partNumber == 2)) {
           for (int x = 0; x < nums.size(); x++) {
                if (Dampener(nums,x)) {
                        return true;
                }
            }
            return false;  
        }
    }
    // Return true if the sequence is either strictly increasing or strictly decreasing
    return  isIncreasing || isDecreasing;
}

bool Dampener(vector<int> original, int atNumber){
    original.erase(original.begin() + atNumber);
    return isSafe(original,1);
}
