#include <stdio.h>
#include <stdlib.h>

/*
int getSum(int a, int b)
{
    int carry, add;  
    do {  
        add = a ^ b; //该操作得到本位的加法结果  
        carry = (a & b) << 1; //该操作得到该位对高位的进位值  
        a = add;  
        b = carry;  
    } while (carry != 0); //循环直到某次运算没有进位，运算结束  
    return add;
}
*/
int getSum(int a, int b)
{
    /* be careful about the terminating condition; */
    return b==0 ? a : getSum(a^b, (a&b)<<1);
}

int main(int argc, char* argv[])
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    printf("%d\n", getSum(a, b));

    return 0;
}
