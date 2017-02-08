#include <stdio.h>

int hammingDistance(int x, int y)
{
    int i;
    int hd = 0;
    int z = x ^ y;

    for(i = 0; i < 8 * sizeof(int) && z != 0; i++) {
        hd += (z & 0x0001 == 1) ? 1 : 0;
        z >>= 1;
    }

    return hd;
}

int main()
{
    printf("%d\n", hammingDistance(1, 4));
    return 0;
}
