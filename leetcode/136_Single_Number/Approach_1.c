#include <stdio.h>
#include <stdlib.h>
#include <err.h>

int singleNumber(int* nums, int numsSize)
{
    int i = 0;
    int max = 0;
    int min = 0;
    int* tmpPositive = NULL;
    int* tmpNegative = NULL;

    if(numsSize == 1) {
        return nums[0];
    }

    for(i = 0; i < numsSize; i++) {
        if(max < nums[i]) {
            max = nums[i];
        }
        if(min > nums[i]) {
            min = nums[i];
        }
    }

    {
        tmpPositive = malloc((max+1) * sizeof(int));
        if(tmpPositive == NULL) {
            err(-1, "line 27: singleNumber(): malloc: tmpPositive: out of space!");
        }

        for(i = 0; i < (max+1); i++) {
            tmpPositive[i] = 0;
        }
    }

    {
        min = abs(min);
        tmpNegative = malloc((min+1) * sizeof(int));
        if(tmpNegative == NULL) {
            err(-1, "line 35: singleNumber(): malloc: tmpNegative: out of space!");
        }

        for(i = 0; i < (min+1); i++) {
            tmpNegative[i] = 0;
        }
   }

    for(i = 0; i < numsSize; i++) {
        if(nums[i] >= 0) {
            tmpPositive[nums[i]]++;
        }
        if(nums[i] < 0) {
            tmpNegative[-nums[i]]++;
        }
    }

    for(i = 0; i < (max+1) && tmpPositive[i] != 1; i++);
    if(i < (max+1)) {
        return i;
    }
    for(i = 0; i < (min+1) && tmpNegative[i] != 1; i++);
    if(i < (min+1)) {
        return -i;
    }
    return 0;
}

int main(int argc, char* argv[])
{
    int a[] = {1}; int asize = 1;
    int b[] = {1, 1, 2}; int bsize = 3;
    int c[] = {1, 2, 3, 2, 1, 3, 4}; int csize = 7;
    int d[] = {}; int dsize = 0;

    printf("%d\n", singleNumber(a, asize));
    printf("%d\n", singleNumber(b, bsize));
    printf("%d\n", singleNumber(c, csize));
    printf("%d\n", singleNumber(d, dsize));
}
