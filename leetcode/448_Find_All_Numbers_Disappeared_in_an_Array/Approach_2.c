#include <stdio.h>
#include <stdlib.h>
#include <err.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize)
{
    int* result;
    int map;

    result = malloc(numsSize * sizeof(int));
    if(result == NULL) {
        err(-1, "findDisappearedNumbers: line 15: malloc: out of space!");
    }

    for(int i = 0; i < numsSize; i++) {
        map = abs(nums[i]) - 1; /* 数组索引从0开始 */
        if(nums[map] > 0) {
            nums[map] = -nums[map];
        }
    }

    for(int i = 0, j = 0; i < numsSize; i++) {
        if(nums[i] > 0) {
            (*returnSize)++;
            result[j++] = i+1;
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
