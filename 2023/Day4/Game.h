/*Game.h*/

#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Game
{
private:
	int gameNumber;
	vector<int> cardNumbers;
	vector<int> winningNumbers;
	int cardInstances;
	Game* next;

	int parseNumber(const string&);
	vector<int> getNumbers(const string&);
	int getWinningNumbersOnlyForThisGame();


public:
	Game();
	void addNew(string);
	void printAll();
	int countMatchingWinningNumbers();
	void handOutCardInstances(int ,int);
	int getCardInstances();
	
};

