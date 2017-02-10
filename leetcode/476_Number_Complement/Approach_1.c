#include <stdio.h>

int findComplement(int num)
{
    int tmp = num;
    int i = 0;
    while(tmp != 0) {
        i++;
        tmp >>= 1;
    }

    tmp = 1;
    while(i > 0) {
        tmp *= 2;
        i--;
    }

    return num ^ (tmp - 1);
}

int main()
{
    printf("%d\n", findComplement(1));
    return 0;
}
