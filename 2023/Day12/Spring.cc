/* Spring.cpp */

#include "Spring.h"
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;



Spring::Spring() {
	metaData == "";
    next = NULL;
}

void Spring::add(string rawData) {
    if (metaData == "") {
        metaData = rawData;
        string numberData;
        string data;
        divideData(rawData, data, numberData);
        values = getNumbers(numberData);
        next = new Spring();
        count = 0;
        //cout << "added: -->" << metaData << endl;
    }
    else {
        next->add(rawData);
    }
}

void Spring::divideData(const string& input, string& firstPart, string& secondPart) {
    stringstream ss(input);
    ss >> firstPart >> secondPart;
}

vector<int> Spring::getNumbers(string& input) {
    vector<int> numbers;
    string currentNumber;

    for (char ch : input) {
        if (std::isdigit(ch)) {
            currentNumber += ch;
        }
        else if (!currentNumber.empty()) {
            numbers.push_back(stoi(currentNumber));
            currentNumber = "";
        }
    }

    if (!currentNumber.empty()) {
        numbers.push_back(stoi(currentNumber));
    }

    return numbers;
}

void Spring::print() {
    cout << endl << metaData << " ";
    for (int a : values) {
        cout << a << " ";
    }
    if (next != NULL) {
        next->print();
    }
}
// PROBLEM: SAMPLE ANSWER IS OFF BY ONE CALCULATIONS ARE NOT CORRECT
int Spring::getValue () {
    cout << endl << "new Data <<" << metaData << endl;
    int count = 0;
    int address = 0, currentNumber = 0;
    for (int i = 0; i < metaData.length() ; i++ ) {
        if (metaData[i] == '#') {
            currentNumber++;
        } else if (metaData[i] == '.') {
            if(currentNumber > 0) {
                if (address < values.size()) {
                    if ( currentNumber != values[address]) {
                        count = 0;
                        if (next != NULL) {
                            return count + next->getValue();
                        }
                        return count;
                    } else {
                        currentNumber = 0; address++;
                    }
                } else {
                    count = 0;
                    if (next != NULL) {
                        return  count + next->getValue();
                    }
                    return count;
                }
            }
        } else if (metaData[i] == '?') {
            string subMetaData = metaData;
            subMetaData[i] = '.';
            Spring s1 = Spring();
            s1.add(subMetaData);
            subMetaData[i] ='#'; 
            s1.add(subMetaData);
            count = count +  s1.getValue();
            if (next != NULL ) {
                return count + next->getValue();
            }
            return count;
        } else if (metaData[i] = ' ') {
            if (metaData[i - 1] == '#') {
                if (currentNumber == values[address]) {
                    count = 1;
                } else {
                    count = 0;
                }
            } else {
                if (address != values.size()) {
                    count = 0;
                }
                else {
                    count = 1;
                }
            }
            if (next != NULL) {
                return count + next->getValue();
            }
            return count;
        }
    }
    cout << "Empty!";
    if (next != NULL) {
        return next->getValue();
    }
    return 0;
}
