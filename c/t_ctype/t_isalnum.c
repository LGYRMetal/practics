#include <ctype.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    for(char c = 0; c < 127; c++) {
        if(isalnum(c)) {
            printf("%d: ", c);
            putchar(c);
            putchar('\n');
            /*
            printf(": ");
            printf("%s\n", isalnum(c) ? "true" : "false");
            */
        }
    }

    return 0;
}
