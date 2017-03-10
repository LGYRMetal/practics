#include <stdio.h>
#include <stdlib.h>

int addDigits(int num)
{
    int result = 0;
    if(num == 0) {
        return 0;
    }
    return (result = num % 9) == 0 ? 9 : result;
}

int main(int argc, char* argv[])
{
    int num = atoi(argv[1]);

    printf("%d\n", addDigits(num));
}
