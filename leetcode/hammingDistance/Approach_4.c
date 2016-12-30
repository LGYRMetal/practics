/* x % 2相当于求x的二进制位的最后一位是0还是1, x / 2 相当于右移一位 */
#include <stdio.h>

int hammingDistance(int x, int y)
{
    int count = 0;

    while(x || y) {
        count += (x % 2) ^ (y % 2);
        x /= 2;
        y /= 2;
    }

    return count;
}

int main()
{
    printf("%d\n", hammingDistance(1, 4));
    return 0;
}
