#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Game {
public:
	int number, red, blue, green;
	Game* next;
	string gameData;
	string cubeData;
	vector<string> cubes;

	// FUNCTIONS
	Game();
	void addNew(std::string new_data);
	void printAllGameData();
	int parseNumberData(const std::string& str);

	// PART ONE FUNCTIONS
	vector<string> splitString(const std::string& str);
	void printVector(const vector<string>& data);
	bool isSubstringIncluded(const string& mainString, const string& substring);
	int returnGameNumbersForSatisfiedGames(int requiredRed, int requiredGreen, int requiredBlue);

	// PART TWO FUNCTIONS
	int getPowers();

};


