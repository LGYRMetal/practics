#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseString(char* s)
{
    char* head = s;
    char* tail = &s[strlen(s) - 1];

    while(head < tail) {
        *head = (char) (*head ^ *tail);
        *tail = (char) (*head ^ *tail);
        *head = (char) (*head ^ *tail);
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
