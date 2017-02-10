#include <stdio.h>
#include <stdlib.h>

typedef unsigned short bool;

const char true = 1;
const char false = 0;

bool canWinNim(int n)
{
    if(n <= 3)
        return true;
    else if(canWinNim(n-1) && canWinNim(n-2) && canWinNim(n-3))
        /* no matter 1, 2, or 3 strones you remove, you always can't win */
        return false;
    return true;
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
/*
int main(int argc, char* argv[])
{
    for(int i = 1; i < 100; i++) {
        if(!canWinNim(i)) {
            printf("%d\n", i/4);
        }
    }

    return 0;
}
*/
