#include <stdio.h>
#include <stdlib.h>

#define YSE 1
#define NO  0

typedef unsigned short bool;

bool canWinNim(int n)
{
    if(n <= 3)
        return YSE;
    if((n-4) <= 3) {
        return YES;
    }
    else if()
}

int main(int argc, char* argv[])
{
    int n = atoi(argv[1]);
    int can = canWinNim(n);

    if(can)
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}
