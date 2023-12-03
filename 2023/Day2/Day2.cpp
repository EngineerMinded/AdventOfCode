///////////////////////////////////////////////////////////
// Wayne Mack                                            //
// Advent Of Code                                        //
//          --- Day 2: Cube Conundrum ---                //
//-------------------------------------------------------//
// Written in : C++ (Windows)                            //
// BOTH STARS ACHIEVED                                   //
///////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Game.h"


Game* game;
void partOne();
void partTwo();

int main() {
	game = new Game();

    ifstream inputFile("day2.data");

    if (!inputFile.is_open()) {
        std::cerr << "Unable to open the file." << std::endl;
        return 1;
    }

    // PUT GAME DATA INTO GAME FILES
    string line;
    while (getline(inputFile, line)) {
        game->addNew(line);      
    }

    //game->printAllGameData(); // ERROR CHECKING
    partOne();
    partTwo();

    inputFile.close(); // Close the file

    return 0;

}

void partOne() {
    cout << "The sum of the satisfied gameNumbers is: " << game->returnGameNumbersForSatisfiedGames(12, 13, 14) << endl;
}

void partTwo() {
    cout << "The sum of all the powers for all of the games is : " << game->getPowers();
}