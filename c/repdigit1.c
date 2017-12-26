#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    int digit_seen[10];
    int digit;
    bool flag = false;
    long n;

    /* 初始化digit_seen[10] */
    for(int i = 0; i < 10; i++)
        digit_seen[i] = 0;

    printf("Enter a number:");
    scanf("%ld", &n);

    while(n > 0) {
        digit = n % 10;
        digit_seen[digit]++;
        n /= 10;
    }

    printf("Repeated digit(s): ");
    for(int i = 0; i < 10; i++) {
        if(digit_seen[i] > 1) {
            flag = true;
            printf("%d ", i);
        }
    }

    if(!flag)
        printf("No repeated digit");

    putchar('\n');

    return 0;
}
