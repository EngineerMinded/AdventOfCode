// Wayne Mack
// Advent Of Code
// Day 3

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctype.h>
using namespace std;


vector<char> readFileToVector(const string& );
int evaluateStatement(vector<char>, int);
int solve(vector<char>, bool);
bool evaluateSwitchCommand(vector<char> , int, bool);

int main() {
    string filename = "day3.txt"; 
    vector<char> content = readFileToVector(filename);

    cout << "Part One: " << solve(content, false) << endl;
    cout << "Part two: " << solve(content, true)  << endl;

    return 0;
}

int solve(vector<char> charList, bool isPart2) {
    bool doThis = true;
    int answer = 0;
    for (int i = 0; i < charList.size(); i++ ) {
        if (charList[i] == 'm' && doThis) {
            answer = answer + evaluateStatement(charList,i);
        }
        else if (charList[i] == 'd' && isPart2) {
            doThis = evaluateSwitchCommand(charList,i,doThis);
        }
    }
    return answer;
}

int evaluateStatement(vector<char> charList, int i) {
    int m1 = 0, m2 = 0;
    int limit = charList.size();
    if (i < limit && charList[i] == 'm') {
        i++;
        if (i < limit && charList[i ] == 'u') {
            i++;
            if (i < limit && charList[i] == 'l') {
                i++;
                if (i< limit && charList[i] == '(') {
                    i++;
                    while (isdigit(charList[i]) ) {
                        m1 = m1 * 10; m1 = m1 + charList[i] - '0';
                        i++;
                    }
                    if (i < limit && charList[i] == ',') {
                        i++;
                        while(isdigit(charList[i])) {
                            m2 = m2 * 10; m2 = m2 + charList[i] - '0';
                            i++;
                        }
                        if (i < limit && charList[i] == ')') {
                            return m1 * m2;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

bool evaluateSwitchCommand(vector<char> charList, int s, bool previousValue) {
    int limit = charList.size();
    string isThisDo = "", isThisDont = "";
    for (int i = s; i < s + 4; i++) {
        isThisDo = isThisDo + charList[i];
        isThisDont = isThisDont + charList[i];
    }
    for (int i = s + 4; i < s + 7; i++) {
        isThisDont = isThisDont + charList[i];
    }
    if (isThisDo == "do()" ) return true;
    if (isThisDont == "don't()") return false;
    return previousValue;
}

vector<char> readFileToVector(const string& filename) {
    vector<char> charVector;
    ifstream file(filename, ios::binary); 

    if (!file) {
        cerr << "Error: Could not open the file " << filename << endl;
        return charVector; // Return an empty vector if the file can't be opened.
    }

    char ch;
    while (file.get(ch)) { // Read each character one by one.
        charVector.push_back(ch);
    }
    file.close();
    return charVector;
}
