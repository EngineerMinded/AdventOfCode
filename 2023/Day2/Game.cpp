/* Game.cpp */

#include "Game.h"
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;


// GAME CONSTRUCTOR
Game::Game() {
	Game::number = red = blue = green = 0;
	gameData = "";
	cubeData = "";
}

// ADD NEW STRING DATA TO GAME
void Game::addNew(string new_data) {
	if (cubeData != "") {
		if (next == NULL) {
			next = new Game();
		}
		next->addNew(new_data);
	}
	else {
		size_t delimit = new_data.find(":");
		cubeData = new_data.substr(delimit + 1);
		number = parseNumberData(new_data.substr(0, delimit));
		cubes = splitString(cubeData);
		for (const auto& element : cubes) {
			if (isSubstringIncluded(element, "red")) {
				int foundNumber = parseNumberData(element);
				if (foundNumber > red) {
					red = foundNumber;
				} 
			}
			else if (isSubstringIncluded(element, "green")) {
				int foundNumber = parseNumberData(element);

				if (foundNumber > green) {
					green = foundNumber;
				}
			}
			else if (isSubstringIncluded(element, "blue")) {
				int foundNumber = parseNumberData(element);
				if (foundNumber > blue) {
					blue = foundNumber;
				}
			}
		}
	}

}

// PRINT ALL GAME DATA
void Game::printAllGameData() {
	cout << "Game No:" << number << endl << endl;
	printVector(cubes);
	cout << endl << "red :" << red << " blue: " << blue << " green: " << green << endl;
	if (next != NULL) {
		next->printAllGameData();
	}
	
}

// extract integer numbers from parsed data
int Game::parseNumberData(const std::string & str) {
	std::istringstream iss(str);
	int foundInteger = 0;
	std::string word;

	while (iss >> word) {
		if (std::istringstream(word) >> foundInteger) {
			// If conversion to integer succeeds, return the first found integer
			return foundInteger;
		}
	}

	// Return 0 if no integer is found in the string
	return foundInteger;
}

// SPLIT THE GAME DATA INTO VECTORS THAT WILL BE FURTHER USED
vector<string> Game::splitString(const string& input) {
	string str = input;
	for (size_t i = 0; i < str.length(); ++i) {
		if (str[i] == ';') {
			str[i] = ','; // Replace semicolon with comma
		}
	}
	vector<string> tokens;
	stringstream ss(str);
	string token;

	while (getline(ss, token, ',') || getline(ss, token, ';')) {
		tokens.push_back(token);
	}

	return tokens;
}

// PRINT ALL VECTORS FOR ERROR CHECKING
void Game::printVector(const std::vector<std::string>& data) {
	for (const auto& element : data) {
		std::cout << element << std::endl;
	}
}

// RETURN TRUE IS THE COLOR NAME IN THE ARGUMENTS IS INCLUDED IN THE STRING
bool Game::isSubstringIncluded(const string& mainString, const string& substring) {
	return (mainString.find(substring) != string::npos);
}

// FOR EVERY GAME IN PART ONE THAT HAS ENOUGH OF THE REQUIRED CUBES, ADD UP THE GAME NUMBERS RECURSIVELY
// AND RETURN THE RESULT
int Game::returnGameNumbersForSatisfiedGames(int requiredRed, int requiredGreen, int requiredBlue) {
	int returnThis = 0;
	// cout << red << " " << requiredRed << " " << green << " " << requiredGreen << " " << blue << " " << requiredBlue << endl; // ERROR CHECKING
	if (red <= requiredRed && green <= requiredGreen && blue <= requiredBlue) {
		returnThis = number;
	}
	if (next == NULL) {
		return returnThis;
	}
	else {
		return returnThis + next->returnGameNumbersForSatisfiedGames(requiredRed, requiredGreen, requiredBlue);
	}
}

int Game::getPowers() {
	if (next == NULL) {
		return red * green * blue;
	}
	else {
		return (red * green * blue) + next->getPowers();
	}
}


