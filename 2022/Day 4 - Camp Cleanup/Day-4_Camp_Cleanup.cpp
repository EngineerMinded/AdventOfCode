/* Wayne Mack
   Advent of Code 2022 
   Day 4: Camp Cleanup
   -----------------------
   Writtem in: C++
 */
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class SectionAssignments {
public:
	int firstMin;
	int firstMax;
	int secondMin;
	int secondMax;
	SectionAssignments *next;
	SectionAssignments() {
		firstMin = 100;
		firstMax = 200;
		secondMin = 300;
		secondMax = 400;
		next = NULL;
	}
	// Constructor for new add ons
	SectionAssignments(string rawData) {
		string firstPart = rawData.substr(0, rawData.find(","));
		string secondPart = rawData.substr(rawData.find(",") + 1);
		cout << firstPart << " " << secondPart << endl;
		firstMin = stoi(firstPart.substr(0, firstPart.find("-")));
		firstMax = stoi(firstPart.substr(firstPart.find("-")+ 1));
		secondMin = stoi(secondPart.substr(0, secondPart.find("-")));
		secondMax = stoi(secondPart.substr(secondPart.find("-") + 1));
		next = NULL;
	}
	// Add new items to list
	void add(string rawData) {
		if (next == NULL) {
			next = new SectionAssignments(rawData);
		}
		else {
			next->add(rawData);
		}
	}
	// Calculation for one range being inside the other. the logic 
	bool completelyInsideTheOther() {
		return ((firstMin >= secondMin && firstMax <= secondMax) ||
			(secondMin >= firstMin && secondMax <= firstMax));
	}
	// Is one range completely inside the other?
	int completelyInsideOneAnotherTally() {
		int answer = 0;
		if (completelyInsideTheOther()) {
			answer = 1;
		}
		if (next == NULL) {
			return answer;
		}
		else {
			return answer + next->completelyInsideOneAnotherTally();
		}
	}
	// Does it overlap?
	bool testOverlap(int x1, int x2, int y1, int y2) {
		return (x1 >= y1 && x1 <= y2) ||
			(x2 >= y1 && x2 <= y2) ||
			(y1 >= x1 && y1 <= x2) ||
			(y2 >= x1 && y2 <= x2);
	}
	// Do the two variables at least overlap one another?
	int overlapsOneAnother() {
		int answer = 0;
		if (testOverlap (firstMin, firstMax, secondMin, secondMax)) {
			cout << firstMin << "-" << firstMax << " , " << secondMin << " - " << secondMax << endl;		
			answer = 1;
		}
		if (next == NULL) {
			return answer;
		}
		else {
			return answer + next->overlapsOneAnother();
		}
	}
};
class IndividualRanges {
private:
	int min, max;
	IndividualRanges *next;
public:
	IndividualRanges() {
		min = 0;
		max = 0;
		next  = NULL;
	}
	IndividualRanges(int m, int n) {
		min = m;
		max = n;
	}
	void integrate(SectionAssignments toBeEntered) {
		add(toBeEntered.firstMin, toBeEntered.firstMax);
		add(toBeEntered.secondMin, toBeEntered.secondMax);
		if (toBeEntered.next != NULL) {
			integrate(*toBeEntered.next);
		}
	}
	void add(int min, int max) {
		if (next == NULL) {
			next = new IndividualRanges(min, max);
		}
		else {
			next->add(min, max);
		}
	}
};
int main() {
	SectionAssignments list = SectionAssignments();
	// READ FILE CONTENTS
	ifstream File("Day4Data.txt");
	if (!File) {
		cout << "Can't open file!";
		return 1;
	}
	string data;
	while (getline(File, data)) {
		list.add(data);
	}
	/////////////////////////////////////////////////// PART ONE /////////////////////////////////////////////////////////////////////
	cout << "The number of assignment where one is completely inside the other is :" << list.completelyInsideOneAnotherTally() << endl;
	/////////////////////////////////////////////////// PART TWO /////////////////////////////////////////////////////////////////////
	cout << "The number of assignments that at least overlap one another is : " << list.overlapsOneAnother();
	return 0;
}
