/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

char** fizzBuzz(int n, int* returnSize)
{
    int i;
    char** returnArray = malloc(*returnSize = n * sizeof(char*));
    if(returnArray == NULL) {
        err(-1, "malloc: returnArray: out of space!!!");
    }

    for(i = 0; i < n; i++) {
        if((i+1) % 3 == 0 && (i+1) % 5 == 0) {
            returnArray[i] = malloc(sizeof("FizzBuzz"));
            strcpy(returnArray[i], "FizzBuzz");
        }
        else if((i+1) % 3 == 0) {
            returnArray[i] = malloc(sizeof("Fizz"));
            strcpy(returnArray[i], "Fizz");
        }
        else if((i+1) % 5 == 0) {
            returnArray[i] = malloc(sizeof("Buzz"));
            strcpy(returnArray[i], "Buzz");
        }
        else {
            returnArray[i] = malloc(sizeof(char[j]));
            sprintf(returnArray[i], "%d", i+1);
        }
    }

    return returnArray;
}

int main()
{
    int i, n = 15;
    int returnSize = 0;
    char** returnArray = fizzBuzz(n, &returnSize);

    printf("Return:\n");
    printf("[\n");
    for(i = 0; i < n-1; i++) {
        printf("\t%s,\n", returnArray[i]);
    }
    printf("\t%s\n", returnArray[i]);
    printf("]\n");

    return 0;
}
