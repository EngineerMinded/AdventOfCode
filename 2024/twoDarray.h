// Wayne Mack
// twoDarray.h

// use this when reading files and converting them int 2 Dimensional Vectors

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

char** readFileTo2DArray(const std::string& filename, int& rowCount, int& colCount) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return nullptr;
    }

    std::vector<std::string> lines;
    std::string line;

    // Read all lines into a vector of strings
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    // Determine rowCount and colCount
    rowCount = lines.size();
    colCount = 0;
    for (const auto& l : lines) {
        if (l.length() > colCount) {
            colCount = l.length();
        }
    }

    // Allocate memory for the 2D array
    char** arr = new char*[rowCount];
    for (int i = 0; i < rowCount; ++i) {
        arr[i] = new char[colCount + 1]; // +1 for null terminator
    }

    // Copy the contents of lines into the 2D array
    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < lines[i].length(); ++j) {
            arr[i][j] = lines[i][j];
        }
        // Null-terminate each row
        arr[i][lines[i].length()] = '\0';
    }

    return arr;
}

void delete2DArray(char** arr, int rowCount) {
    for (int i = 0; i < rowCount; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}
