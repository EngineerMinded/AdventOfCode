// Wayne Mack
// Advent Of Code
// Day 4

#include "../twoDArray.h" // place in 2024 directory
#include <iostream>
#include <cstring>
using namespace std;

int partOne(char** ,   int, int);
int partTwo(char** ,   int, int);
bool isXMAS_lr(char**,   int, int, int, int);
bool isXMAS_rl(char**,   int, int, int, int);
bool isXMAS_ud(char**,   int, int, int, int);
bool isXMAS_du(char**,   int, int, int, int);
bool isXMAS_uldr(char**, int, int, int, int);
bool isXMAS_urdl(char**, int, int, int, int);
bool isXMAS_drul(char**, int, int, int, int);
bool isXMAS_dlur(char**, int, int, int, int);
bool isX_MAS(char** , int, int, int, int);


int main() {
    std::string filename = "day4.txt";
    int rowCount, colCount;

    char** arr = readFileTo2DArray(filename, rowCount, colCount);
    if (arr == nullptr) {
        return 1; // File reading failed
    }
 
    int cols = strlen(arr[0]); // so long as the grid is squared
    cout << "cols: " << cols << endl;

    cout << "Part One: " << partOne(arr, cols, cols) << endl;
    cout << "Part Two: " << partTwo(arr, cols, cols) << endl;
    return 0;
}


int partOne(char** arr, int rowCount, int colCount) {
    int count = 0;
    
    // Loop through each cell in the 2D array
    for (int row = 0; row < rowCount; row++) {
        for (int col = 0; col < colCount; col++) {
            //cout << arr[row][col]<< endl;
            if (arr[row][col] == 'X') {
                //cout << "search";
                if (isXMAS_lr(arr, row, col, rowCount, colCount)) count++;
                if (isXMAS_rl(arr, row, col, rowCount, colCount)) count++;
                if (isXMAS_ud(arr, row, col, rowCount, colCount)) count++;
                if (isXMAS_du(arr, row, col, rowCount, colCount)) count++;
                if (isXMAS_uldr(arr, row, col, rowCount, colCount)) count++;
                if (isXMAS_urdl(arr, row, col, rowCount, colCount)) count++;
                if (isXMAS_drul(arr, row, col, rowCount, colCount)) count++;
                if (isXMAS_dlur(arr, row, col, rowCount, colCount)) count++;
            }
        }
    }

    return count;
}

int partTwo(char** arr, int rowCount, int colCount) {
    int count = 0;
    
    // Loop through each cell in the 2D array
    for (int row = 0; row < rowCount; row++) {
        for (int col = 0; col < colCount; col++) {
            if (arr[row][col] == 'A') {
                if (isX_MAS(arr,row,col,rowCount,colCount)) count++;
            }
        }
    }

    return count;
}

bool isX_MAS(char** arr, int row, int col, int rowCount, int colCount) {
    // see if it can fit at the (row, col). If not, return false immeadiately
    if ((col + 1 < colCount) && (col - 1 > -1) && (row + 1 < rowCount) && ( row - 1 > -1)) {
        char nw = arr[row - 1][col - 1];
        char ne = arr[row + 1][col - 1];
        char sw = arr[row - 1][col + 1];
        char se = arr[row + 1][col + 1];
        // all the determinations below
        return (((nw == 'M' && se == 'S') || (nw == 'S' && se == 'M')) && ((ne == 'M' && sw == 'S') || (ne == 'S' && sw == 'M')));
    }
    return false;
}

bool isXMAS_lr(char** arr, int row, int col, int rowCount, int colCount) {
    // Check if "XMAS" can fit horizontally at position (row, col)
    if (col + 3 < colCount) {
        return arr[row][col] == 'X' && arr[row][col + 1] == 'M' && arr[row][col + 2] == 'A' && arr[row][col + 3] == 'S';
    }
    return false;
}

bool isXMAS_rl(char** arr, int row, int col, int rowCount, int colCount) {
    // Check if "XMAS" can fit horizontally at position backwarss (row, col)
    if (col - 3 > -1) {
        return arr[row][col] == 'X' && arr[row][col - 1] == 'M' && arr[row][col - 2] == 'A' && arr[row][col - 3] == 'S';
    }
    return false;
}

bool isXMAS_ud(char** arr, int row, int col, int rowCount, int colCount) {
    // Check if "XMAS" can fit vertically at position (row, col)
    if (row + 3 < rowCount) {
        return arr[row][col] == 'X' && arr[row + 1][col] == 'M' && arr[row + 2][col] == 'A' && arr[row + 3][col] == 'S';
    }
    return false;
}
bool isXMAS_du(char** arr, int row, int col, int rowCount, int colCount) {
    // Check if "XMAS" can fit vertically backwards at position (row, col)
    if (row - 3 > -1) {
        return arr[row][col] == 'X' && arr[row - 1][col] == 'M' && arr[row - 2][col] == 'A' && arr[row - 3][col] == 'S';
    }
    return false;
}

bool isXMAS_uldr(char** arr, int row, int col, int rowCount, int colCount) {
    // Check if "XMAS" can fit diagonally from top-left to bottom-right
    if (row + 3 < rowCount && col + 3 < colCount) {
        return arr[row][col] == 'X' && arr[row + 1][col + 1] == 'M' && arr[row + 2][col + 2] == 'A' && arr[row + 3][col + 3] == 'S';
    }
    return false;
}

bool isXMAS_urdl(char** arr, int row, int col, int rowCount, int colCount) {
    // Check if "XMAS" can fit diagonally from top-right to bottom-left
    if (row + 3 < rowCount && col - 3 > -1) {
        return arr[row][col] == 'X' && arr[row + 1][col - 1] == 'M' && arr[row + 2][col - 2] == 'A' && arr[row + 3][col - 3] == 'S';
    }
    return false;
}
bool isXMAS_dlur(char** arr, int row, int col, int rowCount, int colCount) {
    // Check if "XMAS" can fit diagonally from bottom-left to top-right
    if (row - 3 > -1 && col + 3 < colCount) {
        return arr[row][col] == 'X' && arr[row - 1][col + 1] == 'M' && arr[row - 2][col + 2] == 'A' && arr[row - 3][col + 3] == 'S';
    }
    return false;
}
bool isXMAS_drul(char** arr, int row, int col, int rowCount, int colCount) {
    // Check if "XMAS" can fit diagonally from bottom-right to top-left
    if (row - 3 > -1 && col - 3 > -1) {
        return arr[row][col] == 'X' && arr[row - 1][col - 1] == 'M' && arr[row - 2][col - 2] == 'A' && arr[row - 3][col - 3] == 'S';
    }
    return false;
}
