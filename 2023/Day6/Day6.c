//////////////////////////////////////////////////////
// Wayne Mack                                       //
// Advent Of Code : Day 6                           //
// --- Day 6: Wait For It ---                       //
// ------------------------------------------------ //
// Written in C: GNU                                //
//////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>

long long boatDistanceCalculation (long long holdTime, long long totalTime, long long boatDistance);
long long getOneBigNumber(const char*);
void  getNumbers(const char*, long long* ,long long* ,long long* ,long long* );

int main () {
    FILE *file = fopen("day6.data", "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }
    long long distance[4], time[4];
    long long part2Distance = 0;
    long long part2Time = 0;

    char line[100];
    int getDistance = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        // Remove the newline character if present
        if (getDistance == 1) {
            part2Distance = getOneBigNumber(line);
        } else {
            part2Time = getOneBigNumber(line);
        }
        printf ("Line: %s", line);
        char *newline = strchr(line, '\n');
        if (newline != NULL) {
            *newline = '\0';
        }

        // Process the line using the provided function
        if (getDistance == 1) {
            getNumbers(line, &distance[0], &distance[1], &distance[2], &distance[3]);
        } else {
            getNumbers(line, &time[0], &time[1], &time[2], &time[3]);
            getDistance = 1;
        }
    }

    fclose(file);
    printf ("%lld %lld %lld %lld \n%lld %lld %lld %lld", time[0], time[1], time[2], time[3], distance[0], distance[1], distance[2], distance[3]);

    long long AnswerOne = 1;

    for (int i = 0; i < 4; i++) {
        int totalDistance = 0;
        for (int j = 0; j < time[i]; j++) {
            long long boatDistance = boatDistanceCalculation(j, time[i], distance[i]);
            if (boatDistance > distance[i]) {
                totalDistance++;
            }
        }
        if (totalDistance == 0) {totalDistance = 1;}
        AnswerOne = AnswerOne * totalDistance;
       
    }
    printf ("\nThe total of all distances is : %lld\n", AnswerOne );
    printf ("\nPart 2 : %lld %lld", part2Time, part2Distance);
    int AnswerTwo = 0;
    for (int j = 0; j < part2Time; j++) {
        long long boatDistance = boatDistanceCalculation(j, part2Time, part2Distance);
        if (boatDistance > part2Distance) {
            AnswerTwo++;
         }
    }
    printf ("\nThe total distance for Part 2 is : %d" , AnswerTwo);
    return 0;
}

long long boatDistanceCalculation (long long holdTime, long long totalTime, long long boatDistance) {
    //printf ("\n%lld %lld %lld", holdTime, totalTime , boatDistance);
    return holdTime * (totalTime - holdTime);
}

void getNumbers(const char *str, long long *num1, long long *num2, long long *num3, long long *num4) {
    int count = 0;
    *num1 = *num2 = *num3 = *num4 = 0; // Initialize variables

    while (*str) {
        if (count == 4) {
            break; // Break if four numbers are found
        }
        if (*str >= '0' && *str <= '9') {
            long long num = 0;
            while (*str >= '0' && *str <= '9') {
                num = num * 10 + (*str - '0');
                str++;
            }
            switch (count) {
                case 0:
                    *num1 = num;
                    break;
                case 1:
                    *num2 = num;
                    break;
                case 2:
                    *num3 = num;
                    break;
                case 3:
                    *num4 = num;
                    break;
            }
            count++;
        } else {
            str++;
        }
    }
}

long long getOneBigNumber(const char *str) {
    long long result = 0;
    int len = strlen(str);
    printf ("\n%d\n", len);
    int foundDigit = 0; // Flag to track if a digit is found
    int i;

    for (i = 0; i < len; i++) {
        if ((str[i] != ' ') && isdigit(str[i])) {
            result = result * 10 + (str[i] - '0');
            foundDigit = 1; // Set the flag as a digit is found
        } else {
            if (foundDigit) {
                // If a digit was found but current character is not a digit, break the loop
                //break;
            }
        }
    }

    return result;
}
