#include <stdio.h>

int findComplement(int num)
{
    /* int i = 2; 当i等于2的31次方的时候，由于最高位是符号位，导致i=0,
     * 这样就造成了无险循环的发生, 所以一定要用unsigned int */
    unsigned int i = 2;

    /* while(i < num) {    wrong*/
    while(i <= num) {
        i *= 2;
    }

    return (num ^ (i - 1));
}

int main()
{
    printf("%d\n", findComplement(2));
    return 0;
}
