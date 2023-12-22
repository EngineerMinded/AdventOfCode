

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int getHashValue(string);
vector<string> splitString(string&);
string readFileToString(const string& filename);

int main() {
    string filename = "example1.data"; // Replace this with the path to your file

    string fileContents = readFileToString(filename);
    vector<string> listOfInput = splitString(fileContents);
    int part1 = 0;
    for (string here : listOfInput) {
        part1 = part1 + getHashValue(here);
    }
    cout << "Part One -> " << part1;


    if (!fileContents.empty()) {
        //cout << "File contents:\n" << fileContents << endl;
    }
    return 0;
}

int getHashValue (string word) {
    int returnThis = 0;
    for (char c : word) {
        returnThis = returnThis + int (c);
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
    } else {
        cerr << "Unable to open file: " << filename << std::endl;
        return "";
    }
}