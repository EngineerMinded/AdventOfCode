#pragma once
#include <iostream>
#include <vector>
using namespace std;


enum Direction  { LEFT, RIGHT };

class Map
{
public:
	bool recursionLeft, recursionRight;
	string name;
	string left;
	string right;
	Map* next;

	Map();
	void add(string);
	string find(string, string, int);

	void print();
	vector<string> getValueEndingIn(vector<string> vectors, char lastLetter);
};





