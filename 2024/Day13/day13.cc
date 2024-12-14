// Wayne Mack
// Advent Of Code
// Day 13

// FIRST STAR ACHIEVED

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class ClawMachine{
    public:
    unsigned long long aX, aY, bX, bY;
    unsigned long long prizeX, prizeY;
    public:

    ClawMachine(int _ax, int _ay, int _bx, int _by, unsigned long long _prizeX, unsigned long long _prizeY) {
        aX = _ax; aY = _ay;
        bX = _bx; bY = _by;
        prizeX = _prizeX;
        prizeY = _prizeY;
    }

    void printContents() {
        cout << aX << " " << aY << " " << bX << " " << bY << " " << prizeX << " " << prizeY << endl;
    }

    unsigned long long fewest(bool isPartTwo) {
        unsigned long long aToken = 0, bToken = 0;
        if(isPartTwo){
            prizeX = 10000000000000 + prizeX;                     
            prizeY  =10000000000000 + prizeY;
            
        }
        return getFewest(aToken,bToken, isPartTwo); 
    }

    unsigned long long getFewest(unsigned long long aToken, unsigned long long bToken, bool isPart2) {         
        unsigned long long lowestNumber = 18446744073709551615; 
        for (unsigned long long aToken = 0, aXValue = 0,  aYValue = 0; aXValue <= prizeX && aYValue <= prizeY; aXValue = aXValue + aX, aYValue = aYValue + aY, aToken += 1) {
            for (unsigned long long bToken = 0, bXValue = 0, bYValue = 0; bXValue + aXValue <= prizeX && aYValue + bYValue <= prizeY; bXValue = bXValue + bX, bYValue = bYValue +  bY, bToken += 1) {
                if ((aXValue + bXValue == prizeX) && (aYValue + bYValue == prizeY)) {
                    if ((aToken * 3) + bToken < lowestNumber) {
                        lowestNumber = (aToken * 3) + bToken;
                    }
                }
            }
        }
        return lowestNumber;
    }

};

static vector<string> readFileToArray(const std::string&);
vector<ClawMachine> parseData (vector<string>);

static vector<ClawMachine> clawMachines;


int main() {
    std::string filename = "day13.txt"; 

    // Get the file contents in a vector
    std::vector<std::string> fileContents = readFileToArray(filename);

    // Print the contents (optional, for verification)
    for (const std::string& line : fileContents) {
        std::cout << line << std::endl;
    }

    unsigned long long partOne = 0;
    clawMachines = parseData(fileContents);
    
    for (ClawMachine cm : clawMachines) {
        cm.printContents();
        unsigned long long thisAnswer = cm.fewest(false);
        if (thisAnswer < 18446744073709551615) partOne = partOne + thisAnswer;
    
    }
    
    //partOne = clawMachines[0].fewest();
    cout << "Part One: " << partOne;
    int partTwo = 0;
    for (ClawMachine cm : clawMachines) {
        cm.printContents();
        unsigned long long thisAnswer = cm.fewest(true);
        if (thisAnswer < 18446744073709551615) partOne = partOne + thisAnswer;
    
    }
    
    return 0;
}

vector<ClawMachine> parseData (vector<string> data) {
    vector<ClawMachine> returnThis;
    int newBX = 0, newBY =0, newAX = 0, newAY =0;
    int prizeX = 0, prizeY = 0;

    for (string line: data) {
        if (line.empty()) {
            ClawMachine newClawMachine = ClawMachine (newAX, newAY, newBX, newBY, prizeX, prizeY);
            returnThis.push_back(newClawMachine);
        }
        if (line.find("Button A:") != std::string::npos) {
                bool setUpX = false, setUpY = false; int num = 0;
                for (char a : line) {
                    if (isdigit(a)) { num = num * 10; num = num + a - '0'; }
                    else if (a == 'Y') { setUpY = true; setUpX = false;}
                    else if (a == 'X') { setUpX = true; setUpY = false;}
                    else {
                        if (setUpX && num != 0) { newAX = num; num = 0;}
                        if (setUpY && num != 0) { newAY = num; num = 0;}
                    }
                }
                if ( num != 0) { newAY = num; num = 0;}
            }

        if (line.find("Button B:") != std::string::npos) {
                bool setUpX = false, setUpY = false; int num = 0;
                for (char a : line) {
                    if (isdigit(a)) { num = num * 10; num = num + a - '0'; }
                    else if (a == 'Y') { setUpY = true; setUpX = false;}
                    else if (a == 'X') { setUpX = true; setUpY = false;}
                    else {
                        if (setUpX && num !=0) { newBX = num; num = 0;}
                        if (setUpY && num !=0) { newBY = num; num = 0;}
                    }
                }
                if (num !=0) { newBY = num; num = 0;}
            }
        if (line.find("Prize:") != std::string::npos) {
                bool setUpX = false, setUpY = false; int num = 0;
                for (char a : line) {
                    if (isdigit(a)) { num = num * 10; num = num + a - '0'; }
                    else if (a == 'Y') { setUpY = true; setUpX = false;}
                    else if (a == 'X') { setUpX = true; setUpY = false;}
                    else {
                        if (setUpX && num !=0) { prizeX = num; num = 0;}
                        if (setUpY && num !=0) { prizeY = num; num = 0;}
                    }
                }
                if ( num !=0) { prizeY = num; num = 0;}
            }
        
        
        }

          
        return returnThis;

}

// Function to read the file contents and store each line in a vector
std::vector<std::string> readFileToArray(const std::string& filename) {
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
