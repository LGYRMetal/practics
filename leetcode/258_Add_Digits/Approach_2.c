#include <stdio.h>
#include <stdlib.h>

int addDigits(int num)
{
    return 1 + (num - 1) % 9;
}

int main(int argc, char* argv[])
{
    int num = atoi(argv[1]);

    printf("%d\n", addDigits(num));
}
