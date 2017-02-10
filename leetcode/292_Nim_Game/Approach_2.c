#include <stdio.h>
#include <stdlib.h>

typedef unsigned short bool;

bool canWinNim(int n)
{
    return n % 4;
}

/*
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
*/
int main(int argc, char* argv[])
{
    for(int i = 1; i < 100; i++) {
        if(!canWinNim(i)) {
            printf("%d\n", i);
        }
    }

    return 0;
}
