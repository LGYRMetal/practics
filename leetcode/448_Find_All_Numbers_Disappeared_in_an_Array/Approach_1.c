#include <stdio.h>
#include <stdlib.h>
#include <err.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize)
{
    int* tmp;
    int* result;

    tmp = malloc((numsSize+1) * sizeof(int));
    if(tmp == NULL) {
        err(-1, "line 14: malloc tmp: out of space!");
    }
    for(int i = 0; i <= numsSize; i++) {
        tmp[i] = 0;
    }

    for(int i = 0; i < numsSize; i++) {
        tmp[nums[i]]++;
    }

    for(int i = 1; i <= numsSize; i++) {
        if(tmp[i] == 0) {
            (*returnSize)++;
        }
    }

    result = malloc((*returnSize) * sizeof(int));
    if(result == NULL) {
        err(-1, "line 33: malloc result: out of space!");
    }
    
    for(int i = 1, j = 0; i <= numsSize; i++) {
        if(tmp[i] == 0) {
            result[j++] = i;
        }
    }

    return result;
}

int main(int argc, char* argv[])
{
    int a[] = {4, 3, 2, 7, 8, 2, 3, 1}; int asize = 8;
    int* returnSize;
    returnSize = malloc(sizeof(int));
    if(returnSize == NULL) {
        err(-1, "line 51: out of space!");
    }

    int* result;
    result = findDisappearedNumbers(a, asize, returnSize);

    printf("[");
    for(int i = 0; i < *returnSize; i++) {
        printf("%d%s", result[i], i == (*returnSize)-1 ? "" : ", ");
    }
    printf("]\n");
    return 0;
}
