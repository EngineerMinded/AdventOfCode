/* Wayne Mack
    Advent Of Code
    Day 6          */

// FIRST STAR ACHIEVED: LET'S GO FOR THE SECOND

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const string filename = "example.txt";

enum Direction { NORTH, SOUTH, EAST, WEST};

class Guard {
    int x, y;
    Direction direction;
    int xMax, yMax;
    vector<pair<int, int>> trailList;
    int spacesTravelled; int numberOfLoops;

    public:
    Guard() {
        direction = NORTH;
        spacesTravelled = 0;
        numberOfLoops = 0;
    }

    int getPart1Answer() {
        return spacesTravelled;
    }
    void moveSequence (Direction& thisDirection, char** thisMap, int& thisX, int& thisY, bool& thisFinished, int& thisSpacesTravelled , bool& thisSequenceLoops, int& loopNumber) {
        thisSequenceLoops = false;
        int targetLoopNumber = 100;
        if (thisDirection == WEST) {
                if (thisY > 0){
                    if (thisMap[thisX][thisY - 1] == '#') {
                        thisMap[thisX][thisY] = '+';
                        thisDirection = NORTH;
                    }
                    else {
                        if (thisMap[thisX][thisY] == '+' || thisMap[thisX][thisY] == 'X') {
                            loopNumber++;
                            if (loopNumber >= targetLoopNumber) {
                                thisSequenceLoops = true;
                            }
                        }
                        else {
                            loopNumber = 0;
                        }
                        y--;
                        if (thisMap[thisX][thisY] != 'X' && thisMap[x][thisY] != '+') {
                            thisSpacesTravelled++;
                            thisMap[thisX][thisY] = 'X';
                        }
                    } 
                }
                else {
                    thisFinished = true;
                }
            }
            else if (thisDirection == SOUTH) {
                if (x < xMax - 1){
                    if (thisMap[thisX + 1][thisY] == '#') {
                        thisMap[thisX][thisY] = '+';
                        thisDirection = WEST;
                    }
                    else {
                        if (thisMap[thisX][thisY] == '+' || thisMap[thisX][thisY] == 'X') {
                            loopNumber++;
                            if (loopNumber >= targetLoopNumber) {
                                thisSequenceLoops = true;
                            }
                        }
                        else {
                            loopNumber = 0;
                        }
                        x++;
                        if (thisMap[thisX][thisY] != 'X' && thisMap[thisX][thisY] != '+') {
                            thisSpacesTravelled++;
                            thisMap[thisX][thisY] = 'X';
                        }
                    } 
                }
                else {
                    thisFinished = true;
                }
            }
            else if (thisDirection == EAST) {
                if (thisY < yMax - 1){
                    if (thisMap[thisX][thisY + 1] == '#') {
                        thisMap[thisX][thisY] = '+';
                        thisDirection = SOUTH;
                    }
                    else {
                        if (thisMap[thisX][thisY] == '+' || thisMap[thisX][thisY] == 'X') {
                            loopNumber++;
                            if (loopNumber >= targetLoopNumber) {
                                thisSequenceLoops = true;
                            }
                        }
                        else {
                            loopNumber = 0;
                        }
                        y++;
                        if (thisMap[thisX][thisY] != 'X' && thisMap[thisX][thisY] != '+') {
                            thisSpacesTravelled++;
                            thisMap[thisX][thisY] = 'X';
                        }
                    } 
                }
                else {
                    thisFinished = true;
                }
            }
            else if (thisDirection == NORTH) {
                if (x > 0){
                    if (thisMap[thisX - 1][thisY] == '#') {
                        thisMap[thisX][thisY] = '+';
                        thisDirection = EAST;
                    }

                    else {
                        if (thisMap[thisX][thisY] == '+' || thisMap[thisX][thisY] == 'X') {
                            loopNumber++;
                            if (loopNumber >= targetLoopNumber) {
                                thisSequenceLoops = true;
                            }
                        }
                        else {
                            loopNumber = 0;
                        }
                        x--;
                        
                        if (thisMap[thisX][thisY] != 'X' && thisMap[thisX][thisY] != '+') {
                            thisSpacesTravelled++;
                            thisMap[thisX][thisY] = 'X';
                        }
                    } 
                }
                else {
                    thisFinished = true;
                }
            }
        }

    Direction loopDirection(Direction original) {
        if (original == WEST) return NORTH;
        if (original == NORTH) return EAST;
        if (original == EAST) return SOUTH;
        return WEST;
    }

    void clearXs(char** map) {
        for (int i = 0; i < strlen(map[0]); ++i) {
            for (int j = 0; j < strlen(map[0]); j++) {
                if (map[i][j] == 'X' || map[i][j] == '+') {
                    map[i][j] = '.';
                } 
            }
        }
    }

    void guardMove(char**  map, bool isPartTwo, int &foundLoop,
                    int part2X, int part2Y, Direction INITIALDIRECTION) {
        direction = INITIALDIRECTION;
        bool thisSequenceLoops = false;
        xMax = strlen(map[0]); yMax = strlen(map[0]);
        for (int x0 = 0; x0 < xMax ; x0++) {
            for (int y0 =0; y0 < yMax; y0++) {
                if (map[x0][y0] == '^') {
                    x = x0; y = y0;
                    
                }
            }
        }
        int moves = 0;
        bool finished = false;
        while (!finished) {
            moves++;
            // Move sequence above
            thisSequenceLoops = false;
            int dumbLoopNumber = 0; // This is used later, not now
            moveSequence (direction, map, x, y, finished, spacesTravelled, thisSequenceLoops, dumbLoopNumber);
            if (isPartTwo) {
                clearXs(map);
                thisSequenceLoops = false;
                int loopX = x, loopY = y,  loopNumber = 0;
                Direction loopdirection = loopDirection(direction);
                bool loopFinished = false;
                while (!loopFinished && !thisSequenceLoops) {
                    moveSequence(loopdirection,map,loopX,loopY,loopFinished,spacesTravelled,thisSequenceLoops, loopNumber);
                    //cout << "Found Loop" << loopNumber << endl;
                }
                
                if (thisSequenceLoops) {
                    foundLoop++;
               }
               clearXs(map);
            }
        }
        cout << "Moves : " << moves;
    }

};

char** readFileTo2DArray(const std::string& filename, int& , int&);
void printMap(char**);
void clearXs(char**);

int main() {

    int rows, cols;
    
    // Read the file contents into a 2D array
    char** fileContents = readFileTo2DArray(filename, rows, cols);
    
    if (fileContents != nullptr) {
        // Print the contents of the 2D array
        //printMap(fileContents);
        int loopsFakeHolder;
        Guard guard = Guard();
        guard.guardMove(fileContents, false, loopsFakeHolder, 0, 0, NORTH);
        int partOne =guard.getPart1Answer();
        printMap(fileContents);
        cout << "PartOne :" << partOne << endl;
        guard.clearXs(fileContents);
        printMap(fileContents);
        int partTwo = 0;
        guard.guardMove(fileContents, true, partTwo,0,0,NORTH);
        cout << "Part Two : " << partTwo;
        
    }
    return 0;
}

void printMap (char** map) {
    for (int i = 0; i < strlen(map[0]); ++i) {
        for (int j = 0; j < strlen(map[0]); j++) {
            std::cout << map[i][j] ;
        }
    cout << endl;
    }

}


char** readFileTo2DArray(const std::string& filename, int& rows, int& cols) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return nullptr;
    }

    std::vector<std::string> lines;
    std::string line;

    // Read all lines from the file
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    // Determine the number of rows and columns
    rows = lines.size();
    cols = 0;

    for (const auto& str : lines) {
        if (str.length() > cols) {
            cols = str.length();
        }
    }

    // Dynamically allocate memory for the 2D character array
    char** arr = new char*[rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new char[cols + 1]; // +1 for the null terminator
        std::fill(arr[i], arr[i] + cols + 1, '\0'); // Initialize with null characters
    }

    // Copy the content of each line into the 2D array
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < lines[i].length(); ++j) {
            arr[i][j] = lines[i][j];
        }
    }

    return arr;
}
