/* Wayne Mack
 * Advent Of Code
 * DAY 14
 */


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//#include <conio.h> 
using namespace std;

// PART ONE STAR AND FIND THE TREE


class Robot{
    public:
    int positionX, positionY;
    int moveX, moveY;

    // Constructor
    Robot(int x1, int y1, int x2, int y2) {
        positionX = x1;
        positionY = y1;
        moveX = x2;
        moveY = y2; 
    }

    void move(int numberOfMoves, int maxX, int maxY) {
        for (int u = 0; u < numberOfMoves; u++) {
            move(maxX, maxY);
        }
    }

    void move(int maxX, int maxY) {
        positionX +=  moveX; 
        
        while (positionX < 0 ){
            positionX  += maxX ;
        }
        while (positionX >= maxX ) {
            positionX -= maxX ;        
        }
        positionY += moveY;
        while (positionY < 0 ){
            positionY  += maxY ;
        }        
        while (positionY >= maxY ) {
            positionY -= maxY;
        }
    }

    void printContents() {
        cout  << positionX << " " << positionY << " " << moveX << " " << moveY << endl;
    }

    int whatQuadrantIsRobotIn(int x, int y) {
        //cout << "Quadrant: " << positionX << " " << positionY << endl;
        int halfWayX = (x - 1) / 2;
        int halfWayY = (y - 1) / 2;
   
        if (positionX < halfWayX  && positionY < halfWayY) return 1;
        if (positionX > halfWayX  && positionY < halfWayY) return 2;
        if (positionX < halfWayX  && positionY > halfWayY) return 3;
        if (positionX > halfWayX  && positionY > halfWayY) return 4;
        return 0;
    }
};

vector<string> readFileToArray(const string&);
vector<Robot> parseData(vector<string>);
void seeIfChristmasTree(int seconds, int xMax, int yMax, vector<Robot>& robots);

int main() {
    std::string filename = "day14.txt"; 

    // Get the file contents in a vector
    std::vector<std::string> fileContents = readFileToArray(filename);

    vector<Robot> robots = parseData(fileContents);

    // Part One Sequence:
    int maxX = 101;
    int maxY = 103;
    int numberOfSeconds = 100;
    
    for (int x = 0; x <= robots.size(); x++) {
        cout << "Before :" << endl;
        robots[x].printContents();
        robots[x].move(numberOfSeconds, maxX, maxY);
        cout << "After :" << endl;
        robots[x].printContents();
        cout << endl;
    }

    int partOne[4] = {0, 0, 0, 0};

    for (Robot g : robots) {
        int nextQuad = g.whatQuadrantIsRobotIn(maxX,maxY);
        cout << nextQuad << "QUAD" << endl;
        if (nextQuad != 0) partOne[nextQuad - 1]++;
    }
    cout << partOne[0] << " " << partOne[1] << " " << partOne[2] << " " << partOne[3] << endl;
    cout << "PartOne: " << partOne[0] * partOne[1] * partOne[2] * partOne[3] <<endl ;

    vector<Robot> part2Robots = parseData(fileContents);
    int seconds = 0;
    while (true) {  
        seeIfChristmasTree(seconds,maxX,maxY,part2Robots);
        cin.get();
        seconds++;
        for (int i = 0; i < part2Robots.size(); i++) {
            part2Robots[i].move(1,maxX,maxY);
        }
    }

    return 0;
}
/* NOTE: PRESS ANY KEY AND OBSERVE UNTIL YOU FIND THE TREE! THIS
 *       PROGRAM DOES NOT PROVIDE THE ANSWER. 
 *       FIND IT YOUR DAMN SELF :)
 */
void seeIfChristmasTree(int seconds, int xMax, int yMax, vector<Robot>& robots) {
    vector<vector<char>> grid;
    vector<char> line;
    
    for (int x = 0; x < xMax; x++) {
        for (int y = 0; y < yMax; y++) {
           line.push_back('.');
        }
        grid.push_back(line); 
    }
    for (Robot r : robots) {
        grid[r.positionX][r.positionY] = '#';
    }
    for (int x = 0; x < xMax; x++) {
        for (int y = 0; y < yMax; y++){
            cout << grid[x][y];
        }
        cout << endl;
    }
    cout << "Seconds :" << seconds << endl;

}

vector<Robot> parseData(vector<string> data) {
    vector<Robot> returnThis;

    for (string robotData : data) {
        //cout << endl << " STRING: " << robotData << endl;
        int allAnswers[4] = {0,0,0,0};
        int addressCount = 0;
        bool isInverted = false, insertedNumber = false;
        for (char i : robotData) {
            if (isdigit(i)) {
                insertedNumber = true;
                allAnswers[addressCount] *= 10;
                isInverted ? allAnswers[addressCount] -= i - '0': allAnswers[addressCount] += i - '0';
            }
            else if ( i == '-') {
                isInverted = true;
            }
            else {
            
                if (insertedNumber) {
                    isInverted = false;
                    insertedNumber = false;
                    addressCount ++;
                }
            }
        }
        Robot newRobot = Robot(allAnswers[0], allAnswers[1], allAnswers[2], allAnswers[3]);
        returnThis.push_back(newRobot);
    }
    returnThis.pop_back();
    return returnThis;
}

vector<string> readFileToArray(const string& filename) {
    std::vector<std::string> lines; // To store the lines of the file
    std::ifstream file(filename);   // Open the file for reading

    // Check if the file is open
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return lines; // Return an empty vector if the file cannot be opened
    }

    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line ); // Add each line to the vector
    }
    lines.push_back("");

    file.close(); // Close the file
    return lines;
}
