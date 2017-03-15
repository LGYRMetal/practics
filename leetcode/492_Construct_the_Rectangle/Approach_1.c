#include <stdio.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructRectangle(int area, int* returnSize)
{
    int L, W;
    int min; /* L 和 W 的最小差值 */
    int lowerLimit;

    min = area;
    lowerLimit = (area % 2 == 0 ? area/2 : 1+area/2);
    for(L = area; L >= lowerLimit; L--) {
        if(area % L != 0) continue;

        W = area / L;
        if(min > L-W) {
            min = L-W;
        }
    }
}
