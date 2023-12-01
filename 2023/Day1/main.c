////////////////////////////////////////////////////////////////////////////////
// Wayne Mack                                                                 //
// Advent of Code 2023 - Day 1: Day 1: Trebuchet?!                            //
//----------------------------------------------------------------------------//
// Written in C: GNU/GCC                                                      //
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 100

int parse_part_one ( char*);
int parse_part_two(const char*, int*, int*);

int main( ) {
    
    
    FILE *filePointer;
    char line[MAX_LINE_LENGTH];

    // Open the file in read mode
    filePointer = fopen("day1.data", "r");
    
    if (filePointer == NULL) {
        printf("File cannot be opened or does not exist.\n");
        return 1;
    }
    int sum = 0;
    int sum2 = 0;
    int first, last;
    // Read file line by line and print each line
    while (fgets(line, MAX_LINE_LENGTH, filePointer) != NULL) {
            sum = sum + parse_part_one(line);
            sum2 = sum2 + parse_part_two(line, &first, &last);
    }

    // Close the file
    fclose(filePointer);
    printf("The total sum for part one is %d\n", sum);
    printf("The total sum for part two is %d.\n", sum2);
    return 0;
}

int parse_part_one ( char* str) {
 if (str == NULL) {
        printf("String is empty.\n");
        return 0;
    }
    int sum = 0;
    while (*str != '\0') {
        if (isdigit(*str)) {
            if (sum == 0) {
                sum = (*str - '0') * 11;
            }
            else {
                sum = sum - (sum % 10) + (*str - '0');
            }
        }
        str++;
    }
    return sum;
}

int parse_part_two(const char *input, int *first, int *last) {
    const char *numbers[] = {
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
    };

    int len = strlen(input);
    int firstNumber = -1, lastNumber = -1;
    int firstNumFound = 0, lastNumFound = 0;

    // Finding the first number
    for (int i = 0; i < len; ++i) {
        if (isdigit(input[i])) {
            firstNumber = input[i] - '0';
            firstNumFound = 1;
            break;
        }

        for (int j = 0; j < 10; ++j) {
            int numLen = strlen(numbers[j]);
            if (strncmp(input + i, numbers[j], numLen) == 0) {
                firstNumber = j;
                firstNumFound = 1;
                break;
            }
        }
        if (firstNumFound) {
            break;
        }
    }

    // Finding the last number
    for (int i = len - 1; i >= 0; --i) {
        if (isdigit(input[i])) {
            lastNumber = input[i] - '0';
            lastNumFound = 1;
            break;
        }

        for (int j = 0; j < 10; ++j) {
            int numLen = strlen(numbers[j]);
            if (strncmp(input + i, numbers[j], numLen) == 0) {
                lastNumber = j;
                lastNumFound = 1;
                break;
            }
        }
        if (lastNumFound) {
            break;
        }
    }

    *first = firstNumber;
    *last = lastNumber;

    if (firstNumFound && lastNumFound) {
        return (firstNumber * 10 + lastNumber);
    } else if (firstNumFound) {
        return firstNumber;
    } else if (lastNumFound) {
        return lastNumber;
    }

    return -1; // Return -1 if no numbers are found
}  