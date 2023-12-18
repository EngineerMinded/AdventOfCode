/*Spring.h*/

#ifndef SPRING_H
#define SPRING_H

#include <iostream>
using namespace std;
#include <vector>


class Spring {

private: 
	string metaData;
	int count;
	string listOfNumbers;
	Spring* next;
	vector<int> values;

public:

	Spring();
	void add(string );
	void divideData(const string&, string&, string&);
	vector<int> getNumbers(string&);
	void print();
	int getValue();
};

#endif