/* Brute Force */

#include <stdio.h>
#include <stdlib.h>
#include <err.h>

int* twoSum(int* nums, int numsSize, int target)
{
    int i, j;
    int* result = malloc(2 * sizeof(int));
    if(result == NULL) {
        err(-1, "out of space!!!");
    }

    for(i = 0; i < numsSize; i++) {
        for(j = i+1; j < numsSize; j++) {
            if(nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                break;
            }
        }
    }

    return result;
}

int main(void)
{
    int nums[] = {2, 7, 12, 15};
    int target = 18;
    int* ar = malloc(sizeof(int) * 2);
    if(ar == NULL) {
        printf("malloc ar error! out of space!~");
        return -1;
    }
    
    ar = twoSum(nums, 4, target);

    putchar('[');
    for(int i = 0; i < 2; i++) {
        printf("%d%s", ar[i], (i == 0 ? ", " : "]\n"));
    }

    free(ar);

    return 0;
}
