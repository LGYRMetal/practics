/* Two pass hash table(without uthash.h) */
/* direct use array element value as the hash value */
#include <stdio.h>
#include <string.h>
#include <err.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target) {
    int *returnSize = malloc(sizeof(int)*2);
    returnSize[0]=returnSize[1]=0;
    int maxPosiNum=0;
    int minNegaNum=0;

    for(int i=0;i<numsSize;i++){
        if(nums[i]>maxPosiNum)
            maxPosiNum=nums[i];
        else if(nums[i]<minNegaNum)
            minNegaNum=nums[i];
    }

    int PosiArr[maxPosiNum+1];
    int PosiArr1[maxPosiNum+1]; //if the number appears more than once, then put it in this array
    int NegaArr[-minNegaNum+1];
    int NegaArr1[-minNegaNum+1];
    memset(PosiArr,0,sizeof(int)*(maxPosiNum+1));
    memset(PosiArr1,0,sizeof(int)*(maxPosiNum+1));
    memset(NegaArr,0,sizeof(int)*(-minNegaNum+1));
    memset(NegaArr1,0,sizeof(int)*(-minNegaNum+1));
    for(int j=0;j<numsSize;j++){
        if (nums[j]>=0) {
            /*(PosiArr[nums[j]]>0)?(PosiArr1[nums[j]]=j+1):(PosiArr[nums[j]]=j+1);*/
            if(!(PosiArr[nums[j]]>0)) {
                PosiArr[nums[j]] = j+1;
            }
            else if(!(PosiArr1[nums[j]]>0)) {
                PosiArr1[nums[j]] = j+1;
            }
        }
        else{
            /*(NegaArr[-nums[j]]>0)?(NegaArr1[-nums[j]]=j+1):(NegaArr[-nums[j]]=j+1);*/
            if(!(NegaArr[-nums[j]]>0)) {
                NegaArr[-nums[j]] = j+1;
            }
            else if(!(NegaArr1[-nums[j]]>0)) {
                NegaArr1[-nums[j]] = j+1;
            }
        }
    }
    int lookforNum=0;
    for(int k=0;k<numsSize;k++){
        lookforNum=target-nums[k];
        if(lookforNum>=minNegaNum&&lookforNum<=maxPosiNum){
            if(lookforNum>=0&&PosiArr[lookforNum]>0&&lookforNum!=nums[k]){
                returnSize[0]=k;
                returnSize[1]=PosiArr[lookforNum]-1;
                break;
            }
            else if(lookforNum<0&&NegaArr[-lookforNum]>0&&lookforNum!=nums[k]){
                returnSize[0]=k;
                returnSize[1]=NegaArr[-lookforNum]-1;
                break;
            }
            else if(lookforNum>=0&&PosiArr1[lookforNum]>0&&lookforNum==nums[k]){
                returnSize[0]=k;
                returnSize[1]=PosiArr1[lookforNum]-1;
                break;
            }
            else if(lookforNum<0&&NegaArr1[-lookforNum]>0&&lookforNum==nums[k]){
                returnSize[0]=k;
                returnSize[1]=NegaArr1[-lookforNum]-1;
                break;
            }
        }
    }
    return returnSize;
}

int main()
{
    int nums[] = {2, 1, 9, 4, 4, 56, 90, 3};
    int target = 8;
    int numsSize = 8;
    int* keys = malloc(2 * sizeof(int));
    if(keys == NULL) {
        err(-1, "malloc: keys error! out of space!");
    }

    keys = twoSum(nums, numsSize, target);

    putchar('[');
    printf("%d, %d", keys[0], keys[1]);
    putchar(']');
    putchar('\n');
}
