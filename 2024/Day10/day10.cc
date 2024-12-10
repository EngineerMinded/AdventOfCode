// Wayne Mack
// Advent Of Code
// Day 10

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <utility>
using namespace std;

// Function to read a file and return the matrix as a 2D integer vector
std::vector<std::vector<int>> readMatrixFromFile(const std::string& filename) {
    std::vector<std::vector<int>> matrix;
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Error: Unable to open file " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<int> row;
        std::istringstream iss(line);
        char value;

        while (iss >> value) {
            row.push_back(int(value - '0'));
        }

        matrix.push_back(row);
    }

    file.close();
    return matrix;
}

bool trailEndAlreadyExists(int x, int y, vector<pair<int, int>> foundNines) {
    for (pair<int, int> xy : foundNines) {
        if ((xy.first == x) && (xy.second == y)) {
            return true;
        }
    }
    return false;
}

void partOneTrail (int& partOneScore, int& partTwoScore, int x, int y, vector<pair<int,int>>& foundNines, vector<vector<int>> trail) {
    if (trail[x][y] == int(9) && !trailEndAlreadyExists(x,y,foundNines)) {
        pair<int,int> pushThis;  pushThis.first = x ; pushThis.second = y;
        foundNines.push_back(pushThis);
        partOneScore++;
        partTwoScore++;
    }
    else if (trail[x][y] == int(9)) {
        partTwoScore++;
    }
    else {
        if (x < trail.size() - 1 && trail[x + 1][y] == trail[x][y] + 1) {
            partOneTrail(partOneScore,partTwoScore,x + 1,y,foundNines,trail);
        }
        if (x > 0 && trail[x - 1 ][y] == trail[x][y] + 1) {
            partOneTrail(partOneScore,partTwoScore,x - 1,y,foundNines,trail);
        }
        if (y < trail.size() - 1 && trail[x][y + 1] == trail[x][y] + 1) {
            partOneTrail(partOneScore,partTwoScore,x ,y + 1,foundNines,trail);
        }
        if (y > 0  && trail[x][y - 1] == trail[x][y] + 1) {
            partOneTrail(partOneScore,partTwoScore,x ,y - 1,foundNines,trail);
        }
    }   
}

pair<int,int> getAnswer(vector<vector<int>> trail) {
    int max = trail.size();
    int answerPartOne = 0;
    int answerPartTwo = 0;
    vector<pair<int,int>> foundedNines;
    for (int x = 0; x < max; x++) {
        for (int y = 0; y < max; y++){
            if (trail[x][y] == 0) {
                partOneTrail(answerPartOne,answerPartTwo,x,y,foundedNines,trail);
                foundedNines.clear();
            }
        }
    }
    pair<int, int> answer;
    answer.first = answerPartOne;
    answer.second = answerPartTwo;
    return answer;
}


// Example usage
int main() {
    try {
        std::string filename = "day10.txt"; // Replace with your file name
        std::vector<std::vector<int>> matrix = readMatrixFromFile(filename);

        // Print the matrix
        for (const auto& row : matrix) {
            for (int value : row) {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
        pair<int,int> answers = getAnswer(matrix);

        cout << endl << "Part One: " << answers.first;
        cout << endl << "Part Two: " << answers.second << endl;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
