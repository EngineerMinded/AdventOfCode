// Wayne Mack
// Advent Of Code
// Day 12

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Plot {
	public: char iD; int numberOf; int fence;

	Plot(char newID, int fenceNumber, int numberof) {
		iD = newID;
		numberOf = numberof;
		fence = fenceNumber;
	}
};
vector<Plot>plots;

void  addData(char gardenPlot, int fences, int numberOfPlots, vector<Plot>& plots) {
	for (int x = 0; x < plots.size(); x++ ) {

	}
	plots.push_back(Plot(gardenPlot, numberOfPlots,fences));
}

void findPlots (vector<Plot>& plots, 
		vector<vector<char> >& garden, 
		vector<vector<bool> >& alreadyBeenThere, 
		int x, int y,int& fence, int& numberOfPlots) {
			numberOfPlots++;
			alreadyBeenThere[x][y] = true;
			if (x == 0) fence++;
			if (y == 0) fence++;
			if (y == garden.size() - 1) fence++;
			if (x == garden.size() - 1) fence++;
			if (x > 0 && garden[x - 1][y] != garden[x][y]) {
				fence++;
			}
			else if ( x > 0 && !alreadyBeenThere[x-1][y]) {
				findPlots(plots,garden,alreadyBeenThere,x - 1,y,fence, numberOfPlots);
			}
			if (x < garden.size() - 1 && garden[x + 1][y] != garden[x][y]) {
				fence++;
			}
			else if (x < garden.size() - 1 && !alreadyBeenThere[x+1][y]){
				findPlots(plots,garden,alreadyBeenThere,x + 1,y,fence, numberOfPlots);
			}
			if (y > 0 && garden[x][y - 1] != garden[x][y]) {
				fence++;
			}
			else if (y > 0 && !alreadyBeenThere[x][ y - 1]) {
				findPlots(plots,garden,alreadyBeenThere,x,y - 1,fence, numberOfPlots);
			}
			if (y < garden.size() - 1 && garden[x][y + 1] != garden[x][y]) {
				fence++;
			}
			else if (y < garden.size() - 1 && !alreadyBeenThere[x][ y + 1]) {
				findPlots(plots,garden,alreadyBeenThere,x,y + 1,fence, numberOfPlots);
			}
}

vector<vector<bool> > createClearRegion(int _x, int _y) {
	vector<vector<bool>> newRegion;
	for (int x = 0; x < _x; x++) {
		vector<bool> allFalse;
		for (int y = 0; y < _y; y++) {
			allFalse.push_back(false);
		}
	}
	return newRegion;
}

void countSides(int x, int y, vector<vector<char> >& garden, int fromX, int fromY ,) {

}

void plotMap (vector<Plot>& plots, vector<vector<char> >& garden) {
	vector<vector<bool> > alreadyBeenHere = createClearRegion(garden.size(),garden.size());
	for (int x = 0; x < garden.size(); x++) {
		for (int y = 0; y < garden.size(); y++) {
			int fences = 0; int numberOfPlots = 0;
			vector<vector<bool>> regionCheck = createClearRegion(garden.size(),garden.size());
			if (!alreadyBeenHere[x][y]) {
				findPlots(plots,garden,alreadyBeenHere,x,y,fences, numberOfPlots);
				addData(garden[x][y],fences, numberOfPlots,plots);
			}
		}
	}
}

int partOne(vector<Plot>& plots) {
	int returnThis = 0;
	for (int x = 0; x < plots.size(); x++) {
		returnThis =returnThis + plots[x].fence * plots[x].numberOf;
		cout << plots[x].fence * plots[x].numberOf << " " << plots[x].fence << " " << plots[x].numberOf << " " << plots[x].iD << endl;
	}
	return returnThis;
}

// Function to read a file and return a 2D vector of chars
std::vector<std::vector<char> > readFileTo2DArray(const std::string &filename) {
    std::vector<std::vector<char> > result;
    std::ifstream file(filename);
    
    if (!file) {
        std::cerr << "Error: Unable to open file." << std::endl;
        return result; // Return empty vector if file can't be opened
    }
    
    std::string line;
    while (std::getline(file, line)) {
        std::vector<char> row(line.begin(), line.end()); // Convert string to vector of chars
        result.push_back(row); // Add row to the result
    }

    return result;
}

int main() {
    string filename = "day12.txt";  // Change to your file's path
    vector<vector<char> > garden = readFileTo2DArray(filename);

	vector<Plot> plotsAndFences;

    // Print the 2D array
    for (const auto &row : garden) {
        for (char c : row) {
            std::cout << c;  // Print each character in the row
        }
        std::cout << std::endl;
    }
	
	plotMap(plotsAndFences,garden);
	cout << "Part One : " << partOne(plotsAndFences);

    return 0;
}
