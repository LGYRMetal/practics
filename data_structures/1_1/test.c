#include <stdio.h>

int main(void)
{
    int array[] = {23, 34, 42, 432, 21, 43, 543};
    int tmp;

    for(int i=0; i<6; i++)
    {
        for(int j = 1; j < 7; j++)
        {
            if(array[j-1] < array[j])
            {
                tmp = array[j];
                array[j] = array[j-1];
                array[j-1] = tmp;
            }
        }
    }

    for(int i=0; i<7; i++)
    {
        printf("%d\n", array[i]);
    }

    return 0;
}
