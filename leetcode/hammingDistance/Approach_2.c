#include <stdio.h>

int hammingDistance(int x, int y)
{
    return __builtin_popcount(x ^ y);
}

int main()
{
    printf("%d\n", hammingDistance(1, 4));
    return 0;
}
