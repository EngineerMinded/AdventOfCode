/////////////////////////////////////////////////
// Wayne Mack                                  //
// Advent Of Code                              //
// Day 15 : --- Day 15: Lens Library ---       //
// ------------------------------------------- //
// Written in C++ (Windows)                    //
// FIRST STAR ATTAINED                         //
/////////////////////////////////////////////////

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int getHashValue(string, bool);
vector<string> splitString(string&);
string readFileToString(const string& filename);
string formatInsert(string);
string getOnlyCharacters(string);
int getNumbers(const string&);

int main() {
    string filename = "puzzle.data"; // Replace this with the path to your file

    string fileContents = readFileToString(filename);
    vector<string> fileData = splitString(fileContents);

    // PART ONE
    int part1 = 0;
    for (string here : fileData) {
        part1 = part1 + getHashValue(here, false);
    }
    cout << "Part 1: " << part1 << endl;

    // PART TWO
    vector<string> boxes[256];

    for (string here : fileData) {
        if (here.find('=') != std::string::npos) {
            bool found = false;
            for (int x = 0; x < boxes[getHashValue(here, true)].size(); x++) {
                if (boxes[getHashValue(here, true)][x].find(getOnlyCharacters(here)) != std::string::npos) {
                    boxes[getHashValue(here, true)][x] = formatInsert(here);
                    found = true;
                }
            }
            if (!found) {
                boxes[getHashValue(here, true)].push_back(formatInsert(here));
            }
        }
        if (here.find('-') != std::string::npos) {
            for (int x = 0; x < boxes[getHashValue(here, true)].size(); x++) {
                if (boxes[getHashValue(here,true)][x].find(getOnlyCharacters(here)) != std::string::npos) {
                    boxes[getHashValue(here, true)].erase(boxes[getHashValue(here,true)].begin() + x);
                }
            }
        }
    }
    for (int i = 0; i < 256; i++) {
        cout << i;
        for (string u : boxes[i]) {
            cout << " " << u;
        }
        cout << "\n";
    }
    int part2 = 0;
    for (int i = 0; i < 256; i++) {   
        for (int j = 0; j < boxes[i].size(); j++) {
            part2 = part2 + ((i + 1) * (j + 1) * getNumbers(boxes[i][j]));
            cout << ((i + 1) * (j + 1) * getNumbers(boxes[i][j])) << endl;
        }   
    }
    cout << "Part two -> " << part2;
    return 0;
}

// FUNCTIONS 

int getHashValue(string word, bool part2) {
    int returnThis = 0;
    for (char c : word) {
        if (part2 && (c == '=' || c == '-')) {
            return returnThis;
        }
        returnThis = returnThis + int(c);
        returnThis = returnThis * 17;
        returnThis = returnThis % 256;
    }
    return returnThis;

}

vector<string> splitString(string& input) {
    vector<string> result;
    istringstream ss(input);
    string token;

    while (getline(ss, token, ',')) {
        result.push_back(token);
    }

    return result;
}

string readFileToString(const string& filename) {
    ifstream file(filename);
    stringstream buffer;

    if (file.is_open()) {
        buffer << file.rdbuf();
        file.close();
        return buffer.str();
    }
    else {
        cerr << "Unable to open file: " << filename << std::endl;
        return "";
    }
}


string formatInsert(string here) {
    string returnThis = "";
    for (char a : here) {
        if (a == '=' || a == '-') { returnThis = returnThis + ' '; }
        else { returnThis = returnThis + a; }
    }
    return returnThis;
}

string getOnlyCharacters(string here) {
    string returnThis = "";
    for (char b : here) {
        if (b == '-' || b == '=') {
            return returnThis;
        }
        returnThis = returnThis + b;
    }
    return returnThis;
}

int getNumbers(const string& input) {
    string numberString;

    for (char c : input) {
        if (isdigit(c)) {
            numberString += c;
        }
    }
    return stoi(numberString);
}


