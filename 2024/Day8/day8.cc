// Wayne Mack
// Advent of Code
// Day 8


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

static int partOneCount = 0, partTwoCount = 0;
static vector<pair<int, int>> foundAntiNodes;

bool antiNodeExists(int x, int y) {
    for (pair<int, int> i : foundAntiNodes) {
        if (x == i.first && y==i.second) {
            return true;        
        }
    }
    return false;
}

void findComplimentaries(char** grid, char charToLookfor, int origX, int origY, int xMax, int yMax, bool ispart2) {
    for (int x = 0; x < xMax ; x++) {
        for (int y = 0; y < yMax; y++) {
           if (grid[x][y] == charToLookfor && (x != origX) && (y != origY) ) {
                int xDiff = x - origX;
                int yDiff = y - origY;
                if ((x + xDiff < xMax  && x + xDiff > -1) && (y + yDiff < yMax && y + yDiff > -1) && (xDiff != 0 && yDiff != 0)) {
                    if (!antiNodeExists(x + xDiff, y + yDiff)) {
                        partOneCount++;
                        foundAntiNodes.push_back(make_pair(x + xDiff, y + yDiff));
                    }
                    if (grid[x + xDiff][y + yDiff] == '.' || grid[x + xDiff][y + yDiff] == '#') {
                        grid[x + xDiff][y + yDiff] = '#';
                        if (ispart2) {
                            xDiff = xDiff + xDiff; yDiff = yDiff + xDiff;
                            while ((x + xDiff < xMax  && x + xDiff > -1) && (y + yDiff < yMax && y + yDiff > -1)) {
                                if (!antiNodeExists(x + xDiff, y + yDiff)) {
                                    partOneCount++;
                                    foundAntiNodes.push_back(make_pair(x + xDiff, y + yDiff));
                                }
                                if (grid[x + xDiff][y + yDiff] == '.' || grid[x + xDiff][y + yDiff] == '#') {
                                        grid[x + xDiff][y + yDiff] = '#';
                                }
                                xDiff = xDiff + xDiff; yDiff = yDiff + yDiff;                
                            }
                        }
                    }
                }    
           }
        }
    }
}

void solveSequence (char** grid, int xMax, int yMax, bool isPart2) {
    for (int x = 0; x < xMax; x++) {
        for (int y = 0; y < yMax; y++) {
            if (grid[x][y] != '.' && grid[x][y] != '#') {
                findComplimentaries(grid, grid[x][y], x, y, xMax, yMax, isPart2);
            }
        }
    }

}




// Function to read the file and return its contents in a 2D character array
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


int main() {
    std::string filename = "example.txt"; // Specify your filename here
    int rows, cols;
    
    // Read the file contents into a 2D array
    char** fileContents = readFileTo2DArray(filename, rows, cols);
    
    if (fileContents != nullptr) {
        // Print the contents of the 2D array
        std::cout << "File contents as a 2D array:" << std::endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; j++) {
                std::cout << fileContents[i][j] << " ";
            }
            cout << endl;
        }

        

        cols = strlen(fileContents[0]);
        rows = strlen(fileContents[0]);  
        //cout << rows << " " << cols << endl;

        solveSequence(fileContents, rows, cols, false);

        std::cout << "Revised array:" << std::endl;
        for (int i = 0; i < rows; ++i) {
            std::cout << fileContents[i] << std::endl;
        }

        cout << "Part One: " << partOneCount;
        fileContents = readFileTo2DArray(filename, rows, cols);
        foundAntiNodes.clear();
        partOneCount = 0;
        solveSequence(fileContents, rows, cols, true);

        std::cout << "Revised array:" << std::endl;
        for (int i = 0; i < rows; ++i) {
            std::cout << fileContents[i] << std::endl;
        }

        cout << "Part Two:" << partOneCount;
        

        
    }

    return 0;
}
