#include <stdio.h>

int findComplement(int num)
{
    int tmp = num;
    int i = 1;
    while(tmp != 0) {
        i *= 2;
        tmp >>= 1;
    }

    return num ^ (i - 1);
}

int main()
{
    printf("%d\n", findComplement(1));
    return 0;
}
