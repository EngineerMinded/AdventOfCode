/* Wayne Mack
 * Advent Of Code
 * Day 15
 * FIRST STAR ACHIEVED!!!
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring> // For strcpy
using namespace std;

#define DATA vector<vector<char>>
#define LINE vector<char>
#define BIGNUM unsigned long long
#define FILENAME "day15.txt"

DATA getData( DATA metadata, bool trueForMapDataFalseForInstructionalData) {
	DATA map;
	for (vector<char> lines : metadata) {
		if  ((trueForMapDataFalseForInstructionalData) && (find(lines.begin(), lines.end(), '#') != lines.end())) {
			map.push_back(lines);
		} 
		else if ((!trueForMapDataFalseForInstructionalData) && ((find(lines.begin(), lines.end(), 'v') != lines.end()) ||
		                                                        (find(lines.begin(), lines.end(), '^') != lines.end()) ||
									(find(lines.begin(), lines.end(), '<') != lines.end()) ||
									(find(lines.begin(), lines.end(), '>') != lines.end()))) {
			map.push_back(lines);
		} 
	}
	return map;

}

void printContents(DATA printMe) {
	for (LINE line : printMe) {
		for (char c : line) {
			cout << c;
		}
		cout << endl;
	}
}
bool isMoveableCharacter (char test) {
	//cout << "\nCharacter :" << test << endl;
	return test == '@' || test == 'O';
}
void move (DATA& map, DATA instructions) {
	int robotX = 0, robotY = 0;
	for (LINE line : instructions) {
		for (char c : line) {
			// UPDATE ROBOTS COORDINATES
			for (int x = 0; x < map.size(); x++) {
				for (int y =0; y < map[0].size(); y++) {
					if (map[x][y] == '@') {
						robotX = x; robotY = y;
					}
				}
			}	
			switch (c) {
				case '<':{ 
					//cout << "\nLEFT: " << endl;
					int itemsToMove = 0;
					for (int y = robotY; y >= 0; y-- ) {
						if (isMoveableCharacter(map[robotX][y])) {
							itemsToMove++;
						}
						else if (map[robotX][y] == '#') {
							goto no_action_left;
						}
						else {
							goto finish_left;
						}
					}
					finish_left:
					//cout << "\nItems to move:"<< itemsToMove << "\n"; 
					for (int y = itemsToMove; y >= 0; y--) {
						map[robotX][robotY - y] = map[robotX][robotY - y + 1];
					}
					map[robotX][robotY] = '.';
					no_action_left:
					break;
				}
				case '>':{
					//cout << "\nRIGHT: " << endl;
					int itemsToMove = 0;
					for (int y = robotY; y < map[0].size(); y++ ) {
						if (isMoveableCharacter(map[robotX][y])) {
							itemsToMove++;
						}
						else if (map[robotX][y] == '#') {
							goto no_action_right;
						}
						else {
							goto finish_right;
						}
					}
					finish_right:
					//cout << "\nItems to move:"<< itemsToMove << "\n"; 
					for (int y = itemsToMove; y >= 0; y--) {
						map[robotX][robotY + y] = map[robotX][robotY + y - 1];
					}
					map[robotX][robotY] = '.';
					no_action_right:
					break;
				}
				case '^':{
					//cout << "\nUP: " << endl;
					int itemsToMove = 0;
					for (int x = robotX; x >= 0; x-- ) {
						if (isMoveableCharacter(map[x][robotY])) {
							itemsToMove++;
						}
						else if (map[x][robotY] == '#') {
							goto no_action_up;
						}
						else {
							goto finish_up;
						}
					}
					finish_up:
					//cout << "\nItems to move:"<< itemsToMove << "\n"; 
					for (int x = itemsToMove; x >= 0; x--) {
						map[robotX - x][robotY] = map[robotX - x + 1][robotY];
					}
					map[robotX][robotY] = '.';
					no_action_up:
					break;
				}
				case 'v':{
					//cout << "\nDOWN: " << endl;
					int itemsToMove = 0;
					for (int x = robotX; x < map.size(); x++ ) {
						if (isMoveableCharacter(map[x][robotY])) {
							itemsToMove++;
						}
						else if (map[x][robotY] == '#') {
							goto no_action_down;
						}
						else {
							goto finish_down;
						}
						}
					finish_down:
					//cout << "\nItems to move:"<< itemsToMove << "\n"; 
					for (int x = itemsToMove; x >= 0; x--) {
						map[robotX + x][robotY] = map[robotX + x - 1][robotY];
					}
					map[robotX][robotY] = '.';
					no_action_down:
					break;
				}
			}
		//printContents(map);
		}
	}
}

 BIGNUM getBoxCoordinates(DATA map) {
	BIGNUM returnThis = 0;
	for (int x = 0; x < map.size(); x++) {
		for (int y = 0; y < map[0].size(); y++) {
			if (map[x][y] == 'O') {
				returnThis += (100 * x) + y;
			}
		}
	}
	return returnThis;
}
DATA readFileToCharVector(const std::string& filename) {
    DATA charVector;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return charVector; // Return an empty vector on error
    }

    std::string line;
    while (std::getline(file, line)) {
        // Convert each line into a vector of characters and add it to the 2D vector
        std::vector<char> lineVector(line.begin(), line.end());
        charVector.push_back(lineVector);
    }

    file.close();
    return charVector;
}
DATA mapData, instructions;
// Example usage
int main() {
    std::string filename = FILENAME;
    
    DATA fileContents = readFileToCharVector(filename);
	mapData = getData(fileContents, true);
	instructions = getData(fileContents, false);
	cout << "MAP: " << endl;
    printContents(mapData);
	cout << endl<< "Instructions: " << endl; 
	printContents(instructions);
	BIGNUM partOne = 0;
	move(mapData,instructions);
	partOne += getBoxCoordinates(mapData);
	//mapData = getData(fileContents, true); // refresh back to original for next instruction set
	

	cout << "Part One: " << partOne;

    return 0;
}
