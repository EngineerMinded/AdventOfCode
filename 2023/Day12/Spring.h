/*Spring.h*/

#ifndef SPRING_H
#define SPRING_H

#include <iostream>
using namespace std;
#include <vector>


class Spring {

private: 
	string metaData;
	string data;
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
	long long getValue(bool);
	void getCounts();
	long long dynamicCalculation(bool, long long, int, int , string);
};

#endif