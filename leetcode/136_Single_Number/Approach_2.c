#include <stdio.h>
#include <stdlib.h>
#include <err.h>

int singleNumber(int* nums, int numsSize)
{
    for(int i = 1; i < numsSize; i++) {
        nums[0] ^= nums[i];
    }

    return nums[0];
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
