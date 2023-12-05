#include "Game.h"
#include <string>
#include <sstream>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

Game::Game () {
	gameNumber = 0;
    cardInstances = 1;
}

void Game::addNew(string gameData) {
    size_t delimit = gameData.find(':');
    if (gameNumber == 0) {
        gameNumber = parseNumber(gameData.substr(0, delimit));
        string cardData = gameData.substr(delimit + 2);
        delimit = cardData.find('|');
        cardNumbers = getNumbers(cardData.substr(0, delimit));
        winningNumbers = getNumbers(cardData.substr(delimit + 1));
    }
    else {
        if (next == NULL) {
            next = new Game();
        }
        next->addNew(gameData);
    }
}

void Game::printAll() {
    cout << endl;
    cout << "Game Number: " << gameNumber << endl;

    cout << "Card Numbers : ";
    for (int num : cardNumbers) {
        cout << num << " ";
    }
    std::cout << std::endl;
    cout << "Winning Numbers : ";
    for (int num : winningNumbers) {
        cout << num << " ";
    }
    cout << endl;
    if (next != NULL) {
        next->printAll();
    }
}


int Game::parseNumber(const string& input) {
    stringstream ss;
    ss << input;
    std::string temp;
    int number;
    for (char ch : input) {
        if (isdigit(ch)) {
            temp += ch;
        }
        else if (!temp.empty()) {
            break; 
        }
    }
    ss.str(temp);
    ss >> number;

    return number;
}

vector<int> Game::getNumbers(const std::string& input) {
    std::vector<int> numbers;
    std::stringstream ss(input);
    int number;

    while (ss >> number) {
        numbers.push_back(number);
    }
    return numbers;
}

// PART ONE ANSWER
int Game::countMatchingWinningNumbers() {
    int count = 0;
    for (int num1 : cardNumbers) {
        for (int num2 : winningNumbers) {
            if (num1 == num2) {
                if (count == 0) {
                    count = 1;
                }
                else {
                    count = count * 2;
                }
            }
        }
    }
    if (next != NULL) {
        return count + next->countMatchingWinningNumbers();
    }
    else {
        return count;
    }
}

void Game::handOutCardInstances(int numberOfInstances, int numberOfCards) {
    if (numberOfCards == 0) {
        return;
    }
    cout << "\nGet game card " << gameNumber << endl;
    cardInstances = cardInstances + numberOfInstances;
    if (next != NULL) {
        if (numberOfCards > 1) {
            next->handOutCardInstances(numberOfInstances, numberOfCards - 1);
        }
    }
}

int Game::getCardInstances() {
    cout << "\nGame :" << gameNumber << " Instances: " << cardInstances << " Winnings: " << getWinningNumbersOnlyForThisGame() << endl; // ERROR CHECKING
    if (next != NULL) {
        next->handOutCardInstances(cardInstances, getWinningNumbersOnlyForThisGame());
    }
    if (next == NULL) {
        return cardInstances;
    }
    return cardInstances + next->getCardInstances();
}

int Game::getWinningNumbersOnlyForThisGame() {
    int count = 0;
    for (int num1 : cardNumbers) {
        for (int num2 : winningNumbers) {
            if (num1 == num2) {
                count++;
            }
        }
    }
    return count;
}