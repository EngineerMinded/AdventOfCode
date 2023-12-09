/*cards.cc*/
#include <iostream>
using namespace std;
#include "cards.h"

#define DECK "23456789TJQKA"

Cards::Cards() {
    faceValues = "";
    winValue = 0;
    score = 0;
}
void Cards::add (string cardDeck , int pointValue) {
    Cards* newCard = new Cards();
    newCard->faceValues = sortCards(cardDeck);
    newCard->winValue = determineScore(faceValues);
    newCard->score = pointValue;
    if (faceValues == "") {
        faceValues = newCard->faceValues;
        winValue = newCard->winValue;
        score = newCard->score;
        next = new Cards();
    }
    else if (isGreaterThatCurrentCard(newCard->faceValues, faceValues)) {
        if (next == NULL) {
            next = new Cards();
        }
        next->add(cardDeck,pointValue);
    }
    else {
        
        moveUp(faceValues, winValue, score);
        faceValues = newCard->faceValues;
        winValue = newCard->winValue;
        score = newCard->score;
    }
}

void Cards::moveUp(string newValues, int newWin, int newScore) {
    if (faceValues == "") {
        faceValues = newValues;
        winValue = newWin;
        score = newScore;
    } else {
        /*if (next == NULL) {
            next = new Cards();
        }*/
        string nextV = faceValues;
        int nextW = winValue;
        int nextS = score;
        faceValues = newValues;
        winValue = newWin;
        score = newScore;
        next-> moveUp(nextV, nextW, nextS);
    }
}

string Cards::alphabetizeString (string outOfOrder) {
    string returnThis = "";
    for (char card: DECK) {
        for (char c : outOfOrder) {
            if (c == card) {
                returnThis = returnThis + c;
            }
        }
    }
    return returnThis;
}

string Cards::sortCards (string data) {
    int symbols[14] = {0};
    // ASSIGN A SCORE TO A FACE VALUE FOR RANKING
    for (char suit : data) {
        if (suit == 'A') {  symbols[12] = symbols[12] + 1; } 
        else if (suit == '2') { symbols[0] = symbols[0] + 1; } 
        else if (suit == '3') { symbols[1] = symbols[1] + 1; } 
        else if (suit == '4') { symbols[2] = symbols[2] + 1; } 
        else if (suit == '5') { symbols[3] = symbols[3] + 1; } 
        else if (suit == '6') { symbols[4] = symbols[4] + 1; } 
        else if (suit == '7') { symbols[5] = symbols[5] + 1; } 
        else if (suit == '8') { symbols[6] = symbols[6] + 1; } 
        else if (suit == '9') { symbols[7] = symbols[7] + 1; } 
        else if (suit == 'T') { symbols[8] = symbols[8] + 1; } 
        else if (suit == 'J') { symbols[9] = symbols[9] + 1; } 
        else if (suit == 'Q') { symbols[10] = symbols[10] + 1; } 
        else if (suit == 'K') { symbols[11] = symbols[11] + 1; } 
    }
    string returnThis;
    for (int v = 5; v > 0; v--) {
        for (int u = 12; u >= 0; u-- ) {
            if (symbols[u] == v) {
                for (int z = 0; z < v; z++ ) {
                    returnThis += DECK[u];
                }
            }
        }
    }
    return returnThis;
}

int Cards::determineScore (string cardSet) {
    if (cardSet[1] == cardSet[0]) {
        if (cardSet[2] == cardSet[1]) {
            if (cardSet[3] == cardSet[2]) {
                if (cardSet[4] == cardSet[3] ) {
                    return 7; // FIVE OF A KIND
                } else {
                    return 6; // FOUR OF A KIND
                }
            } else if (cardSet[3] == cardSet[4]) {
                return 5; // FULL HOUSE
            } else {
                return 4; // THREE OF A KIND
            }
       } else  if (cardSet[2] == cardSet[3]){
            return 3; // TWO PAIR
        } else {
            return 2; // ONE PAIR
        }
    } else {
        return 1; // HIGHEST NUMBER
    }
}


bool Cards::isGreaterThatCurrentCard(string newCard, string currentCard) {
    int n = determineScore(newCard), c = determineScore(currentCard);
    if (n != c) {
        return (n > c);
    }
    if (n == 6) {
        return hasHigherValue(newCard[4], currentCard[4]);
    }
    if (n = 5)  {
        if (newCard[0] == currentCard[0]) {
            return (hasHigherValue(newCard[3], currentCard[3]));
        }
        return hasHigherValue(newCard[0], currentCard[0]);
    }
    if (n == 4) {
        if (newCard[0] == currentCard[0]) {
            if (newCard[3] == currentCard[3]) {
                return hasHigherValue(newCard[4],currentCard[4]);
            }
            return (hasHigherValue(newCard[3], currentCard[3]));
        }
        return hasHigherValue(newCard[0], currentCard[0]);
    }
    if (n == 3) {
        if (newCard[0] == currentCard[0]) {
            if (newCard[2] == currentCard[2]) {
                return hasHigherValue(newCard[4],currentCard[4]);
            }
            return (hasHigherValue(newCard[2], currentCard[2]));
        }
        return hasHigherValue(newCard[0], currentCard[0]);
    }
    if (n == 2) {
        if (newCard[0] == currentCard[0]) {
            if (newCard[2] == currentCard[2]) {
                if (newCard[3] == currentCard[3]) {
                    return hasHigherValue(newCard[4],currentCard[4]);
                }
                return hasHigherValue(newCard[3],currentCard[3]);
            }
            return (hasHigherValue(newCard[2], currentCard[2]));
        }
        return hasHigherValue(newCard[0], currentCard[0]);
    }
    if (newCard[0] == currentCard[0]) {
        if (newCard[1] == newCard [1]) {
            if (newCard[2] == currentCard[2]) {
                if (newCard[3] == currentCard[3]) {
                    return hasHigherValue(newCard[4],currentCard[4]);
                }
                return hasHigherValue(newCard[3],currentCard[3]);
            }
            return (hasHigherValue(newCard[2], currentCard[2]));
        }
        return hasHigherValue(newCard[1], currentCard[1]);
    }
    return hasHigherValue(newCard[0], currentCard[0]);

}

bool Cards::hasHigherValue(char newCardChar, char currentCardChar ) {
    for (int u = 12; u >= 0; u-- ) {
        if (DECK[u] == newCardChar) {
            return true;
        } else if (DECK[u] == currentCardChar) {
            return false;
        }
    }
    return true;
}

void Cards::printCards() {
    cout << endl << faceValues << " " << score;
    if (next != NULL && next->faceValues != "") {
        next->printCards();
    }
}

int Cards::part1Tally(int multiplier) {
 if (next->faceValues == "") {
    return multiplier * score;
 }
 return (multiplier * score ) + next->part1Tally(multiplier + 1);
}
