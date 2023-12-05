///////////////////////////////////////////
// Wayne Mack                            //
// Advent Of Code: Day 4                 //
//     --- Day 4: Scratchcards ---       //
// ------------------------------------- //
// Written in C++ (Windows)              //
// EARNED FIRST STAR                     //
// EARNED SECOND GOLD STAR               //
///////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include "Game.h"
using namespace std;

Game* game;
int main() {
	game = new Game();
    ifstream file("day4.data"); // Replace "example.txt" with your file name

    if (file.is_open()) {
        string line;

        // Read and print each line of the file until the end is reached
        while (getline(file, line)) {
            game->addNew(line);
        }

        file.close(); // Close the file after reading
    }
    else {
        std::cerr << "Unable to open the file." << std::endl;
        return 1;
    }

    game->printAll();
    cout << "The total winning numbers in the game stack is :" << game->countMatchingWinningNumbers();
    cout << "The total amount of scratch cards you end up with is : " << game->getCardInstances();
    return 0;
}
