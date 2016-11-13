#include <stdio.h>
#include <stdlib.h>

#define ARG_ERR     -1     /* 参数错误 */

static void usage(int len);
static void descend_sort(int nums[], int len);

static void usage(int len)
{
    printf("参数必须大于等于2，最后一个数是k, k必须大于等于1,小于等于%d\n", len);
    return;
}

static void descend_sort(int nums[], int len)
{
    for(int i = 0; i < len - 1; i++)
    {
        for(int j = 1; j < len; j++)
        {
            int tmp;
            if(nums[j-1] < nums[j])
            {
                tmp       = nums[j-1];
                nums[j-1] = nums[j];
                nums[j]   = tmp;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int k = atoi(argv[argc-1]);
    int len = argc - 2;
    int nums[k];

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
    
    /* 先让前k个元素进入数组 */
    for(int i = 0; i < k; i++)
    {
        nums[i] = atoi(argv[i+1]);
    }
    descend_sort(nums, k);

    for(int i = k+1; i < argc-1; i++)
    {
        if(nums[k-1] < atoi(argv[i]))
        {
            nums[k-1] = atoi(argv[i]);
            descend_sort(nums, k);
        }
    }

    printf("%d\n", nums[k-1]);

    return 0;
}
