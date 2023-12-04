//////////////////////////////////////////////////////
// Wayne Mack                                       //
// Advent Of Code:                                  //
//         --- Day 3: Gear Ratios ---               //
// ------------------------------------------------ //
// Written in C: GNU/GCC                            //
// FIRST STAR EARNED                                //
// SECOND STAR EARNED                               //
//////////////////////////////////////////////////////

#include <stdio.h> // for strlen (string length)
#include <string.h>

#define MAX_ROWS 150
#define MAX_COLS 150

char gearBox[MAX_ROWS][MAX_COLS];
int z, numRows;
int avoidDuplicates = 0;

int currentCharacterIsNumber (char);
int getNumberFromPoint(int, int);
int calculateAsterisk (int, int);

int main() {

    int totalScore = 0, multiplier = 0, currentNumber = 0;
    numRows = 0;
    FILE *file;
    char *filename = "day3.data";

    // Open the file in read mode
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }
    // READ DATA FROM FILE
    // Reading input from the file until EOF (End Of File) is encountered or maximum rows are reached
    while (numRows < MAX_ROWS && fgets(gearBox[numRows], MAX_COLS, file) != NULL) {
        numRows++;
    }
    fclose(file);
    z = (int)(strlen(gearBox[0])); // NOW A GLOBAL VARIABLE
    // PART ONE FUNCTION 
    for (int i = 0; i < numRows; i++) {
        gearBox[i][z + 1] = '.';
        printf ("\n%s\n", gearBox[i]);
        for ( int j = 0; j < z; j++) {
            //printf ("\n");
            if (currentCharacterIsNumber(gearBox[i][j])) {
                //printf("%c, ", gearBox[i][j]);
                currentNumber = (currentNumber * 10) + (gearBox[i][j] - '0');
                if (i > 0 && j > 0) {
                    if (gearBox[i - 1][j - 1] != '.' && !(currentCharacterIsNumber(gearBox[i - 1][j - 1])) ) {
                        multiplier = 1;
                    }
                } if (i > 0 && j < z - 3) {
                    if (gearBox[i - 1][j + 1] != '.' && gearBox[i - 1][j + 1] != 0 && !(currentCharacterIsNumber(gearBox[i - 1][j + 1]))) {
                        multiplier = 1;
                    }
                } if (i < numRows - 1 && j > 0) {
                    if (gearBox[i + 1][j - 1] != '.' && !(currentCharacterIsNumber(gearBox[i + 1][j - 1]))) {
                        multiplier = 1;
                    }
                } 
                if (i < numRows - 1 && j < z - 3) {
                    if (gearBox[i + 1][j + 1] != '.' && gearBox[i +1][j + 1] != 0 && !(currentCharacterIsNumber(gearBox[i + 1][j + 1]))) {
                        multiplier = 1;
                    }

                } if (i > 0) {
                    if (gearBox[i - 1][j] != '.' && !(currentCharacterIsNumber(gearBox[i - 1][j]))) {
                        multiplier = 1;
                    }
                } if (i < numRows -1) {
                    if (gearBox[i + 1][j] != '.' && !(currentCharacterIsNumber(gearBox[i + 1][j]))) {
                        multiplier = 1;
                    }
                } if (j > 0) {
                    if (gearBox[i][j - 1] != '.' && !(currentCharacterIsNumber(gearBox[i][j - 1]))) {
                        multiplier = 1;
                    }
                }if (j < z - 3) {
                    if (gearBox[i][j + 1] != '.' && gearBox[i][j + 1] != 0 && !(currentCharacterIsNumber(gearBox[i][j + 1]))) {
                        multiplier = 1;
                    }
                }
            }
            else {
                // ADD TO THE SCORE AND RESET CURRENT SCORE TALLY TO ZERO
                if (currentNumber != 0 && multiplier != 0) {
                 printf (" %d ", currentNumber);
                }
                //printf ("%d + %d", currentNumber, totalScore);
                totalScore = totalScore + (currentNumber * multiplier);
                currentNumber = 0; multiplier = 0;
            }
        }
    }
    totalScore = totalScore + (currentNumber * multiplier);
    currentNumber = 0; multiplier = 0;
    printf ("\n\nThe total for part one is: %d\n\n", totalScore );

    // PART TWO STARTS HERE
    totalScore = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < z; j++) {
            if (gearBox[i][j] == '*') {
                printf ("\n* -> %d, %d\n", i, j);
                totalScore = totalScore + calculateAsterisk(i,j);
            }
        }
    }
    printf ("\n\nThe total for part to is : %d\n", totalScore);
    return 0;
}

int currentCharacterIsNumber (char currentCharacter) {
    return (currentCharacter - '0' >= 0 && currentCharacter - '0' <= 9);
}

int getNumberFromPoint(int i, int j) {
    int returnThis = gearBox[i][j] - '0';
    int backwardsNumber = 1;
    while ((j > 0) && (currentCharacterIsNumber(gearBox[i][j - backwardsNumber]))) {
        int backwardsMultiplier = 1;
        for (int k = 0; k < backwardsNumber; k++) {
            backwardsMultiplier = backwardsMultiplier * 10;
        }
        returnThis = returnThis + ((gearBox[i][j - backwardsNumber] - '0') * backwardsMultiplier);
        backwardsNumber++;
    }
    
    int forwardNumber = 1;
    while ((j < z - 3) && (currentCharacterIsNumber(gearBox[i][j + forwardNumber]))) {
        returnThis = (returnThis * 10) + gearBox[i][j + forwardNumber] - '0';
        forwardNumber++;
    }
    printf ("\n %d, %d -> return this: %d", i, j, returnThis);
    return returnThis;
}

int calculateAsterisk (int i, int j) {
    // LOOK AT THE TOP 3 SPACES
    int numfound = 0; int lastWasBlank = 1; int total = 1;
    if (i > 0 && j > 0) {
        if (currentCharacterIsNumber(gearBox[i - 1][j - 1] )) {
            total = getNumberFromPoint (i - 1, j - 1);
            numfound++; lastWasBlank = 0;
        }
        else {
            lastWasBlank = 1;
        }
    }
    if (i > 0) {
        if (currentCharacterIsNumber(gearBox[i - 1][j]))  {
            if (lastWasBlank) {
                numfound ++; lastWasBlank = 0;
                total = total * getNumberFromPoint(i - 1, j);
            }
        }
        else {
            lastWasBlank = 1;
        }
    }
    if (i > 0 && j < z - 3) {

        if (currentCharacterIsNumber(gearBox[i - 1][ j + 1]))  {
            if (lastWasBlank) {
                numfound ++; lastWasBlank = 0;
                total = total * getNumberFromPoint(i - 1, j + 1);
            }
        }
        else {
            lastWasBlank = 1;
        }
    }
    // LOOK AT THE TWO SPACES ON EITHER SIDE
    if (j > 0) {
        if (currentCharacterIsNumber(gearBox[i][ j - 1])) {
            total = total * getNumberFromPoint(i, j - 1);
            numfound ++;
        }
    }
    if (j < z - 3) {
        if (currentCharacterIsNumber(gearBox[i][ j + 1])) {
            total = total * getNumberFromPoint(i, j + 1);
            numfound ++;
        }
    }
    // LOOK AT THE BOTTOM THREE SPACES
    lastWasBlank = 1;
    if (i < numRows - 1 && j > 0) {
        if (currentCharacterIsNumber(gearBox[i + 1][ j - 1] )) {
            total = total * getNumberFromPoint (i + 1, j - 1);
            numfound++; lastWasBlank = 0;
        }
    }
    if (i < numRows - 1) {
        if (currentCharacterIsNumber(gearBox[i + 1][j]))  {
            if (lastWasBlank) {
                numfound ++; lastWasBlank = 0;
                total = total * getNumberFromPoint(i + 1, j);
            }
        }
        else {
            lastWasBlank = 1;
        } 
    }
    if (i < numRows - 1 && j < z - 3) {

        if (currentCharacterIsNumber(gearBox[i + 1][ j + 1]))  {
            if (lastWasBlank) {
                numfound ++; lastWasBlank = 0;
                total = total * getNumberFromPoint(i + 1, j + 1);
            }
        }
        else {
            lastWasBlank = 1;
        }
    }
    printf ("\nnumber found: %d\n" , numfound);
    if (numfound > 1) {
        printf ("\nAdd -> %d\n", total );
        return total;
    }
    return 0;
}