/* Spring.cpp */

#include "Spring.h"
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;



Spring::Spring() {
	metaData == "";
    data == "";
    next = NULL;
    count = -1;
}

void Spring::add(string rawData) {
    if (metaData == "") {
        metaData = rawData;
        string numberData;
        divideData(rawData, data, numberData);
        values = getNumbers(numberData);
        next = new Spring();
        count = 0;
    }
    else {
        next->add(rawData);
    }
}

void Spring::divideData(const string& input, string& firstPart, string& secondPart) {
    stringstream ss(input);
    ss >> firstPart >> secondPart;
}

void Spring::getCounts() {
    cout <<"\n" << count;
    if (next != NULL) {
        next->getCounts();
    }
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



long long Spring::getValue (bool dynamic) {
    int firstValue = 0; int lastValue =0;
    if (values.size() > 0) {
        firstValue = values[0]; lastValue = values[values.size() - 1];
    }
    
    long long count = 0;
    int address = 0, currentNumber = 0;
    for (int i = 0; i < metaData.length() ; i++ ) {
        if (metaData[i] == '#') {
            currentNumber++;
        } else if (metaData[i] == '.') {
            if(currentNumber > 0) {
                if (address < values.size()) {
                    if ( currentNumber != values[address]) {
                        count = 0;
                        cout << "new Data <<" << metaData << " NO" << endl;
                        if (next != NULL) {
                            count = count + next->getValue(dynamic);
                        }
                        return dynamicCalculation(dynamic,count,firstValue, lastValue,data);
                    } else {
                        currentNumber = 0; address++;
                    }
                } else {
                    cout << endl << "new Data <<" << metaData << " NO" << endl;
                    count = 0;  
                    if (next != NULL) {
                        count =  count + next->getValue(dynamic);
                    }
                    return dynamicCalculation(dynamic,count,firstValue, lastValue,data);
                }
            }
        } else if (metaData[i] == '?') {
            string subMetaData = metaData;
            subMetaData[i] = '.';
            Spring s1 = Spring();
            s1.add(subMetaData);
            subMetaData[i] ='#'; 
            s1.add(subMetaData);
            count = count +  s1.getValue(false);
            if (next != NULL ) {
                count = count + next->getValue(dynamic);
            }
            return dynamicCalculation(dynamic,count,firstValue, lastValue,data);
        } else if (metaData[i] = ' ') {
            if (metaData[i - 1] == '#') {
                if (address == values.size() -1  && currentNumber == values[address]) {
                    cout << endl << "new Data <<" << metaData << " OK" << endl;
                    count = 1;
                } else {
                    cout << endl << "new Data <<" << metaData << " NO" << endl;
                    count = 0;
                }
            } else {
                if (address == values.size()) {
                    cout << endl << "new Data <<" << metaData << " OK" << endl;
                    count = 1;
                }
                else {
                    cout << endl << "new Data <<" << metaData << " NO" << endl;
                    count = 0;
                }
            }
            if (next != NULL) {
                count = count + next->getValue(dynamic);
            }
            return dynamicCalculation(dynamic,count,firstValue, lastValue,data);
        }
    }
    if (next != NULL) {
        return next->getValue(true);
    }
    return dynamicCalculation(dynamic,count,firstValue, lastValue,metaData);
}
// DYNAMIC CALCULATION NEEDS TO BE FIGURED OUT
long long Spring::dynamicCalculation (bool dynamic, long long count, int firstValue, int lastValue, string data) {
    if (dynamic) {
        if ((firstValue == 1 && data[data.length() - 1] != '#') || (lastValue == 1 && data[0] != '#' )) {
            count = count + (count * 4);
        }
/*
        if (data[0] == '#') {
            count = count + (count * 4);
        }

        if (data[data.length() - 1] == '#') {
            count = count + (count * 4);
        }
*/
    }
 
    return count;
}
