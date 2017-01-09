#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

char* reverseString(char* s)
{
    char* head = s;
    char* tail = &s[strlen(s) - 1];
    char tmp;

    while(head < tail) {
        tmp  = *head;
        *head = *tail;
        *tail = tmp;
        head++;
        tail--;
    }

    return s;
}

int main()
{
    char* s = malloc(sizeof("hello"));
    strcpy(s, "hello");

    printf("%s\n", reverseString(s));

    return 0;
}
