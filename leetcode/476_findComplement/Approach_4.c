#include <stdio.h>

int findComplement(int num)
{
    unsigned int mask = ~0;
    while(num & mask) mask <<= 1;
    return ~mask & ~num;
}

int main()
{
    printf("%d\n", findComplement(2));
    return 0;
}
