#include <stdio.h>
#include <string.h>

char findTheDifference(char* s, char* t) {
    int i;
    char c;

    i = 0;
    c = 0;
    while(s[i] != 0) {
        c ^= s[i++];
    }

    i = 0;
    while(t[i] != 0) {
        c ^= t[i++];
    }

    return c;
}

int main(int argc, char* argv[])
{
    char* s = "abcd";
    char* t = "abcde";

    printf("%c\n", findTheDifference(s, t));

    return 0;
}
