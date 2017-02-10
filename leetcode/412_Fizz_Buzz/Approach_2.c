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
    int i, step3, step5;
    char* fizz = "Fizz";
    char* buzz = "Buzz";
    char* fizzbuzz = "FizzBuzz";
    char** returnArray = malloc(n * sizeof(char*));
    if(returnArray == NULL) {
        err(-1, "malloc: returnArray: out of space!");
    }

    step3 = step5 = 1;
    for(i = 1; i <= n; i++) {
        if(step3 == 3 && step5 == 5) {
            returnArray[i-1] = fizzbuzz;
            step3 = step5 = 1;
        }
        else if(step3 == 3) {
            returnArray[i-1] = fizz;
            step3 = 1;
            step5++;
        }
        else if(step5 == 5) {
            returnArray[i-1] = buzz;
            step5 = 1;
            step3++;
        }
        else {
            int j = 1;
            int tmp = i;
            while((tmp /= 10) != 0) {
                j++;
            }
            returnArray[i-1] = malloc((j+1) * sizeof(char));
            if(returnArray[i-1] == NULL) {
                err(-1, "malloc: returnArray[i]: out of space!");
            }
            sprintf(returnArray[i-1], "%d", i);
            step3++;
            step5++;
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
