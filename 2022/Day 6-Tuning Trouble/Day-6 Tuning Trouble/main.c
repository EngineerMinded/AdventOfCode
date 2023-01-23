/* Wayne Mack
 * Advent of Code 2022
 * Day 6 - Tuning Trouble
 * Written in: C
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool foundFirstMarker (int , char[]);

int main()
{
    FILE *filePointer;
    char ch;
    char compare[14] ;
    int count = 1 ;
    filePointer = fopen("Day6Data.txt", "r");
    if (filePointer == NULL)
    {
        printf("File is not available \n");
    }
    else
    {
        bool foundForPart2 = false;
        while ((ch = fgetc(filePointer)) != EOF)
        {
            for (int i = 1; i < 14; i++) {
                compare[i - 1] = compare [i];
            }
            compare[13] = ch;
            for (int i = 0; i < 14; i++) {
                printf("%c ," , compare[i]);
            }
            printf("\n");
            
            if (((compare [10] != compare[11]) &&
                (compare [10] != compare[12]) &&
                (compare [10] != compare[13]) &&
                (compare [11] != compare[12]) &&
                (compare [11] != compare[13]) &&
                (compare [12] != compare[13])) &&
                (count > 4) && !(foundForPart2)){
                printf("The first marker character is after character %i\n\n" , count);
                foundForPart2 = true;
            }
            if (foundFirstMarker(14, compare)) {
                printf("The second marker character is after character %i\n\n" , count);
                return 0;
            }
            count++;
        }
    }
    printf ("Didn't find it!!!\n");
    fclose(filePointer);
    return 0;
}
bool foundFirstMarker(int amount, char* array) {
    for (int i = 1; i < amount; i++) {
        for (int j = 0; j < i; j++) {
            if (array[j] == array[i]) {
                return false;
            }
        }
    }
    return true;
}


