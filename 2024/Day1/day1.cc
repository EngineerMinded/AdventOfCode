// advent of Code Day 1
// Wayne Mack

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

pair<vector<double>, vector<double>> readFileToArrays(const string& filename) {
     ifstream file(filename);
     vector<double> column1, column2;

    if (!file) {
         cerr << "Error: Unable to open file " << filename <<  endl;
        return {column1, column2};
    }

     string line;
    double num1, num2;

    while ( getline(file, line)) {
         istringstream iss(line);
        if (iss >> num1 >> num2) {
            column1.push_back(num1);
            column2.push_back(num2);
        } else {
             cerr << "Warning: Skipping invalid line: " << line <<  endl;
        }
    }

    file.close();
    return {column1, column2};
}

int partOne (vector<double>columnOne, vector<double>columnTwo) {
    sort(columnOne.begin(), columnOne.end());
    sort(columnTwo.begin(), columnTwo.end());
    int answer = 0, nextNumber = 0;
    for (int i = 0; i < columnOne.size(); i++) {
        nextNumber = columnOne[i] - columnTwo[i];
        nextNumber < 0 ? answer += nextNumber * -1 : answer += nextNumber;
    }
    return answer;
}

int howManyTimesANumberAppearsInThisList (int searchThisNumber, vector<double>searchThisList) {
    int answer = 0;
    for (int i = 0; i < searchThisList.size(); i++) {
       if  (searchThisNumber == searchThisList[i]) answer++;
    }
    return answer;
}

int partTwo(vector<double>c1, vector<double>c2) {
    int answer = 0;
    for (int i = 0; i < c1.size(); i++) {
       answer += c1[i] * howManyTimesANumberAppearsInThisList(c1[i], c2 );
    }
    return answer;
}

int main() {
    string filename = "data.txt";
    pair<vector<double>,vector<double>> theTwoColumns = readFileToArrays(filename);
    cout << endl << "Part One: " << partOne(theTwoColumns.first, theTwoColumns.second);
    cout << endl << "Part Two  " << partTwo(theTwoColumns.first, theTwoColumns.second) << endl;
    return 0;
}