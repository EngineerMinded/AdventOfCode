// Wayne Mack
// Advent Of Code
// Day 5

#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void getBothRuleNumbers(const std::string&, int*, int*);
vector<int> parseStringToIntVector(const std::string&);
bool followsRules(vector<pair<int,int>>, int, int);
int getMiddleValue(const vector<int>&);
vector<int>sortCorrectly(vector<int>, vector<pair<int,int>>);


int main() {
    vector<pair<int,int>> rules;
    vector<vector<int>> update;
    string filename = "day5.txt";
    // File reading procedure
    ifstream inputFile(filename); 
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            if (line.find("|") != string::npos) {
                int before, after;
                getBothRuleNumbers(line, &before, &after); 
                rules.push_back({before,after});
            }
            else if (line.find(",") != string::npos) {
                vector<int> newInts = parseStringToIntVector(line);
                update.push_back(newInts);
            }
        }
        inputFile.close();
    } else {
        std::cerr << "Error opening file." << std::endl;
    }

    // Part One Procedure:
    int partOne = 0, partTwo = 0;
    for (vector<int> g : update) {
        bool followTheRules = true;
        for (int i = 0; i < g.size(); i++) {
            for (int j = i + 1; j < g.size(); j++) {
                if (!followsRules(rules,g[i],g[j])){
                    followTheRules = false;
                }
            }
        }
        if (followTheRules) {
            partOne += getMiddleValue(g);
        }
        else {
            partTwo += getMiddleValue(sortCorrectly(g,rules));
        }
    }
    cout << "Part One: " << partOne << endl;
    cout << "Part Two: " << partTwo << endl;
    return 0;
}

vector<int> sortCorrectly(vector<int>l, vector<pair<int,int>>rules ) {
    bool isNowCorrect = false;
    while (!isNowCorrect) {
        isNowCorrect = true;
        for (int i = 0; i < l.size() - 1; i++) {
            if (followsRules(rules, l[i + 1], l[i])) {
                int temp = l[i + 1];
                l[i + 1] = l[i];
                l[i] = temp;
                isNowCorrect = false;
            }
        }
    }
    return l;
}

bool followsRules(vector<pair<int,int>> rules, int before, int after) {
    bool answer = false;
    for (pair<int,int> a : rules) {
        if (before == a.first  &&  after == a.second) answer = true;
    }
    return answer || before == after;
}

int getMiddleValue(const vector<int>& numbers) {
    // Check if the vector is empty
    if (numbers.empty()) {
        throw std::invalid_argument("The vector is empty.");
    }

    // Calculate the middle index
    size_t middleIndex = numbers.size() / 2;

    // Return the middle element
    return numbers[middleIndex];
}
 
void getBothRuleNumbers(const std::string& input, int* before, int* after) {
    static int result[2]; // Static array to return (C-style)
    size_t separator_pos = input.find('|');

    if (separator_pos == std::string::npos) {
        throw std::invalid_argument("Invalid input format. Expected 'number1|number2'.");
    }

    // Extract substrings for the numbers
    std::string part1 = input.substr(0, separator_pos);
    std::string part2 = input.substr(separator_pos + 1);

    // Convert the substrings to integers
    *before = std::stoi(part1);
    *after = std::stoi(part2);

}

vector<int> parseStringToIntVector(const std::string& input) {
    vector<int> result;
    stringstream ss(input);
    string item;

    // Split the string by commas
    while (getline(ss, item, ',')) {
        // Convert each substring to an integer and add to the vector
        result.push_back(std::stoi(item));
    }

    return result;
}

