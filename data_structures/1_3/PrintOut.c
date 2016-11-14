#include <stdio.h>
#include <stdlib.h>

#define PrintDigit(ch)  (putchar((ch) + '0'))

void PrintInt(unsigned int n)
{
    if(n >= 10)
        PrintInt(n / 10);
    PrintDigit(n % 10);
}

void PrintOut(double n)
{
    printf("%f\n", n);
    if(n < 0)
    {
        putchar('-');
        n = -n;
    }

    int i = n;
    if(i < n) /* 小数部分不是0 */
    {
        PrintInt(i);
        putchar('.');

        n -= i;
        i = n * 1000;
        int r = (int)(n * 10000) - i * 10; /* 用来判断是否四舍五入 */
        if(r >= 5)
            i++;

        while(i % 10 == 0)
        {
            i /= 10;
        }
        PrintInt(i);
    }
    else /* 整数或小数部分为0 */
    {
        PrintInt(i);
    }

    putchar('\n');
}

int main(int argc, char* argv[])
{
    PrintOut(123.0);
    PrintOut(-123);
    PrintOut(1/2.0);
    PrintOut(0-2/5.0);
    PrintOut(3/7.0);
    PrintOut(0-3/7.0);

    return 0;
}
