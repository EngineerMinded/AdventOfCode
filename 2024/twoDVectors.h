// Wayne Mack
// Advent Of Code
// Use this to read file and get 2D vectors

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

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
