#include <stdio.h>
#include <stdlib.h>

#define PrintDigit(ch)  (putchar((ch) + '0'))

int power(int x, int y)
{
    int result = 1;
    for(int i = 0; i < y; i++)
    {
        result *= x;
    }

    return result;
}

void PrintInt(unsigned int n)
{
    if(n >= 10)
        PrintInt(n / 10);
    PrintDigit(n % 10);
}

void PrintOut(double n)
{
    int accuracy = 3; /* 精度，希望输出极为小数就改成几 */
    printf("power.....%d\n", power(10, 9));
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
        i = n * power(10, accuracy);
        printf("here.......%d\n", i);
        /* r用来判断是否四舍五入 */
        int r = (int)(n * power(10, accuracy + 1)) - i * 10;
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
