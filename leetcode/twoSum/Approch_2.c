/* Two-pass Hash Table */
#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <uthash.h>

typedef struct _hash_entry* hash_entry;
typedef struct _hash_entry* hash_table;
struct _hash_entry {
    int h_key; /* element of the array nums */
    int h_value; /* index of the array elements */
    UT_hash_handle hh; /* makes this structure hashable */
};
hash_table ht = NULL;

void hash_table_insert(int key, int value)
{
    hash_entry entry = malloc(sizeof(struct _hash_entry));
    if(entry == NULL)
        err(-1, "malloc: entry: out of space!");

    entry->h_key = key;
    entry->h_value = value;
    HASH_ADD_INT(ht, h_key, entry);
}

hash_entry hash_find_key(int key)
{
    hash_entry entry = NULL;
    HASH_FIND_INT(ht, &key, entry);
    return entry;
}

int* twoSum(int* nums, int numsSize, int target)
{
    hash_entry entry = NULL;
    int i, complement;
    int* result = malloc(2 * sizeof(int));
    if(result == NULL)
        err(-1, "malloc: result: out of space!");

    for(i = 0; i < numsSize; i++) {
        hash_table_insert(nums[i], i);
    }

    for(i = 0; i < numsSize; i++) {
        complement = target - nums[i];
        if((entry = hash_find_key(complement)) && entry->h_value != i) {
            result[0] = i;
            result[1] = entry->h_value;
            break;
        }
    }

    return result;
}

int main()
{
    int nums[] = {2, 1, 9, 4, 4, 56, 90, 3};
    int target = 8;
    int numsSize = 8;
    int* keys = malloc(2 * sizeof(int));
    if(keys == NULL) {
        err(-1, "malloc: keys error! out of space!");
    }

    keys = twoSum(nums, numsSize, target);

    putchar('[');
    printf("%d, %d", keys[0], keys[1]);
    putchar(']');
    putchar('\n');
}
