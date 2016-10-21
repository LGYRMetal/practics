#include <stdio.h>
#include <stdlib.h>

#define ARG_ERR     -1     /* 参数错误 */

int selection(int[], int len, int k); /* 返回数组中第k个大的数 */
static void usage(int len);

/*
 * 参数:
 * nums[] - 数组
 * len    - 数组长度
 * k      - 数组中第k大的数
 */
int selection(int nums[], int len, int k)
{
    int tmp;
    
    /*
     * 将nums数组降序排序，那么第几大就是第几个数组元素，但是，
     * 数组下标是从0开始，所以返回nums[k-1]
     */
    for(int i = 0; i < len-1; i++)
    {
        for(int j = 1; j < len; j++)
        {
            int tmp;
            if(nums[j-1] < nums[j])
            {
                tmp       = nums[j];
                nums[j]   = nums[j-1];
                nums[j-1] = tmp;
            }
        }
    }

    return nums[k-1];
}

static void usage(int len)
{
    printf("参数必须大于等于2，最后一个数是k, k必须大于等于1,小于等于%d\n", len);
    return;
}

int main(int argc, char *argv[])
{
    int k = atoi(argv[argc-1]);
    int len = argc - 2;
    int nums[len];

    /*
     * 1. 命令行参数必须大于等于2，不算命令本身，所以argc需要大于等于3
     * 2. 最后一个参数是k，前面的数是items;
     * 3. k必须大于等于1, 小于等于len
     */
    if(argc < 3 || k < 1 || k > len)
    {
        usage(len);
        printf("你的argc = %d\n", argc);
        printf("你的k = %d\n", k);
        return ARG_ERR;
    }
    
    for(int i=0; i<len; i++)
    {
        nums[i] = atoi(argv[i+1]);
    }

    printf("%d\n", selection(nums, len, atoi(argv[argc-1])));

    return 0;
}
