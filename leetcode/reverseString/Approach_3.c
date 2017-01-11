#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

char* substring(const char* s, unsigned int start, unsigned int end)
{
    int len;
    char* s1;
    char* ss;

    if(start > end) {
        err(-1, "start must equal or less then end!");
    }

    len = end - start;
    s1 = (char*) &s[start];
    ss = malloc((len + 1) * sizeof(char));
    if(ss == NULL) {
        err(-1, "malloc: ss: out of space!");
    }
    memset(ss, 0, len+1);

    strncpy(ss, s1, len);

    return ss;
}

char* reverseString(char* s)
{
    int len = strlen(s);
    char* leftStr;
    char* rightStr;
    char* rs;

    if(len <= 1) return s;

    leftStr  = substring(s, 0, len/2);
    rightStr = substring(s, len/2, len);

    rs = malloc((len+1) * sizeof(char));
    if(rs == NULL) {
        err(-1, "malloc: rs: out of space!");
    }
    memset(rs, 0, len+1);

    strcpy(rs, reverseString(rightStr));
    strcat(rs, reverseString(leftStr));

    return rs;
}

int main()
{
    char* s = malloc(sizeof("A new order began, a more Roman age bred Rowena."));
    strcpy(s, "A new order began, a more Roman age bred Rowena.");

    printf("%s\n", s);
    printf("%s\n", reverseString(s));

    return 0;
}
