#include <stdio.h>

int findMaxConsecutiveOnes(int* nums, int numsSize)
{
    int i;
    int max = 0;
    int counter = 0;
    for(i = 0; i < numsSize; i++) {
        if(nums[i] == 1) {
            counter++;
        }
        else {
            if(counter > max) {
                max = counter;
            }
            counter = 0;
        }
    }

    if(counter > max) {
        max = counter;
    }

    return max;
}

int main()
{
    int nums[] = {1, 1, 0, 1, 1, 1};

    printf("%d\n", findMaxConsecutiveOnes(nums, sizeof(nums)/sizeof(int)));
    return 0;
}
