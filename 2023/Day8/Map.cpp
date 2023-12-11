#include "Map.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

Map::Map() {
	left = "";
	right = "";

	name = "";
	next = NULL;
}

void Map::add(string data) {
	// Place the data here and declare the next one;
	if (name == "") {
		name = data.substr(0, 3);
		left = data.substr(7, 3);
		right = data.substr(12, 3);
		next = new Map();
	}
	// if this data is occupied, place it in the next one
	else {
		if (next == NULL) {
			next = new Map();
		}
		next->add(data);
	}
}

string Map::find(string charactersToFind, string directions, int directionCounter) {
	while (directionCounter >= directions.length()) {
		directionCounter = directionCounter - (int)directions.length();
	}
	if (name != charactersToFind) {
		if (next == NULL && name == "") {
			return "ERROR";
		}
		else {
			return next->find(charactersToFind, directions, directionCounter);
		}
	}
	// if this is the name
	else {
		if (directions[directionCounter] == 'L') {
			
			return left;
		}
		else {
			return right;
		}
	}
}

void Map::print() {
	cout << "Name: " << name << " L: " << left << " R: " << right << endl;
	if (next != NULL) {
		next->print();
	}
}

vector<string>  Map::getValueEndingIn(vector<string> returnThis, char lastLetter) {
	if (name != "" && name[2] == lastLetter) {
		returnThis.push_back(name);
	}
	if (next != NULL) {
		return next->getValueEndingIn(returnThis, lastLetter);
	}
	return returnThis;
}