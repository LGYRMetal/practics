/* each time, n & (n - 1) remove the last 1 bit of n. */
#include <stdio.h>

int hammingDistance(int x, int y)
{
    int n = x ^ y;
    int count = 0;

    while(n != 0) {
        count++;
        n &= n - 1;
    }

    return count;
}

int main()
{
    printf("%d\n", hammingDistance(1, 4));
    return 0;
}
