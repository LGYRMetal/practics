#include <stdio.h>

int findMaxConsecutiveOnes(int* nums, int numsSize)
{
    int max = 0;
    int sum = 0;

    for(int i = 0; i < numsSize; i++) {
        sum = (sum + nums[i]) * nums[i];
        if(max < sum) {
            max = sum;
        }
    }

    return max;
}

int main()
{
    int nums[] = {1, 1, 0, 1, 1, 1};

    printf("%d\n", findMaxConsecutiveOnes(nums, sizeof(nums)/sizeof(int)));
    return 0;
}
