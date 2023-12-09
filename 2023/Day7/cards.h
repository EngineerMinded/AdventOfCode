/* cards.h */
#ifndef CARDS_H
#define CARDS_H

#include <iostream>
using namespace std;

class Cards {

/****************************************
 * WIN Values:                          *
 * High Hand       - 1                  *
 * One Pair        - 2                  *
 * Two Pair        - 3                  *
 * Three of a king - 4                  *
 * Full House      - 5                  *
 * Four Of A kind  - 6                  *
 * Five Of A kind  - 7                  *
 ****************************************/
private:
    string faceValues;
    int score;
    int winValue;
    int highCard;
    Cards* next;
public:
    Cards();
    void add(string, int);
    string alphabetizeString (string );
    string sortCards(string);
    bool isGreaterThatCurrentCard(string, string);
    bool hasHigherValue(char, char );
    void moveUp(string, int , int);
    void printCards();
    int determineScore(string);
    int part1Tally(int);
};

#endif