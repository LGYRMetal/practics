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
    char** returnArray = malloc(n * sizeof(char*));
    if(returnArray == NULL) {
        err(-1, "malloc: returnArray: out of space!!!");
    }

    for(i = 0; i < n; i++) {
        if((i+1) % 3 == 0 && (i+1) % 5 == 0) {
            returnArray[i] = malloc(sizeof("FizzBuzz"));
            if(returnArray[i] == NULL) {
                err(-1, "malloc: returnArray[i]: out of space!!!");
            }
            strcpy(returnArray[i], "FizzBuzz");
        }
        else if((i+1) % 3 == 0) {
            returnArray[i] = malloc(sizeof("Fizz"));
            if(returnArray[i] == NULL) {
                err(-1, "malloc: returnArray[i]: out of space!!!");
            }
            strcpy(returnArray[i], "Fizz");
        }
        else if((i+1) % 5 == 0) {
            returnArray[i] = malloc(sizeof("Buzz"));
            if(returnArray[i] == NULL) {
                err(-1, "malloc: returnArray[i]: out of space!!!");
            }
            strcpy(returnArray[i], "Buzz");
        }
        else {
            int j = 1; /* digit number of interger */
            int tmp = i + 1;
            while((tmp /= 10) != 0) {
                j++;
            }
            returnArray[i] = malloc(sizeof(char) * (j+1));
            if(returnArray[i] == NULL) {
                err(-1, "malloc: returnArray[i]: out of space!!!");
            }
            sprintf(returnArray[i], "%d", i+1);
        }
    }

    *returnSize = n;
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
    printf("%d\n", returnSize);

    return 0;
}
