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

    printf("Repeated digit(s): ");
    while(n > 0) {
        digit = n % 10;
        n /= 10;
        switch(digit_seen[digit]) {
            case 0:
                digit_seen[digit]++;
                break;
            case 1:
                printf("%d ", digit);
                digit_seen[digit]++;
                flag = true;
                break;
            default:
                continue;
        }
    }
    if(!flag)
        printf("No Repeated digit");
    putchar('\n');

    return 0;
}
