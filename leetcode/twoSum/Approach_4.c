/* One-pass hash table */
/* Open addressing hashing 开放定址法 */
/* 平方探测法 */
/* 定理: 如果使用平方探测，且表的大小是素数，那么当表至少有一半是空的 */
/* 时候， 总能够插入一个新的元素. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

#define NOTFOUND -1

typedef char bool;
typedef unsigned int position;
struct hashTbl;
typedef struct hashTbl *hashTable;

const int minTableSize = 1;
const bool true = 1;
const bool false = 0;
enum kindOfEntry {LEGITIMATE, EMPTY, DELETED};

struct hashEntry {
    int key;
    unsigned int value;
    enum kindOfEntry info;
};

typedef struct hashEntry cell;
struct hashTbl {
    int tableSize;
    cell *theCells;
};

bool isPrime(unsigned int n)
{
    if(n <= 3) {
        return n > 1;
    }
    else if(n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    else {
        for(unsigned short i = 5; i * i <= n; i += 6) {
            if(n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
}

unsigned int nextPrime(unsigned int n)
{
    return isPrime(n) ? n : nextPrime(++n);
}

position hash(int key, unsigned int tableSize)
{
    return abs(key) % tableSize;
}

hashTable initializeTable(unsigned int tableSize)
{
    hashTable h;
    int i;

    if(tableSize < minTableSize) {
        printf("Table size too small\n");
        return NULL;
    }

    /* Allocate table */
    h = malloc(sizeof(struct hashTbl));
    if(h == NULL)
        err(-1, "malloc: h: out of space!!!");

    h->tableSize = nextPrime(tableSize);

    /* Allocate array of Cells */
    h->theCells = malloc(sizeof(cell) * h->tableSize);
    if(h->theCells == NULL)
        err(-1, "malloc: h->theCells: out of space!!!");

    for(i = 0; i < h->tableSize; i++)
        h->theCells[i].info = EMPTY;

    return h;
}

position find(int key, hashTable h)
{
    position currentPos = NOTFOUND;
    int collisionNum = 0;

    currentPos = hash(key, h->tableSize);
    while(h->theCells[currentPos].info != EMPTY &&
          h->theCells[currentPos].key != key) {
        currentPos += 2 * ++collisionNum - 1;
        if(currentPos >= h->tableSize) {
            currentPos -= h->tableSize;
        }
    }

    return currentPos;
}

void insert(int key, int value, hashTable h)
{
    position pos;

    pos = find(key, h);
    if(h->theCells[pos].info != LEGITIMATE) {
        h->theCells[pos].info = LEGITIMATE;
        h->theCells[pos].key = key;
        h->theCells[pos].value = value;
    }
}

int* twoSum(int* nums, int numsSize, int target) {
    int complement;
    position p;
    int* result = malloc(2 * sizeof(int));
    result[0] = result[1] = 0;
    int tableSize = nextPrime(2 * numsSize); /* 定理: 至少一半是空的时候 */
    hashTable h = initializeTable(tableSize);

    /* insert the first element first */
    insert(nums[0], 0, h);
    for(int i = 1; i < numsSize; i++) {
        complement = target - nums[i];
        if((p = find(complement, h)) == NOTFOUND) {
            insert(nums[i], i, h);
        }
        else {
            result[0] = h->theCells[p].value;
            result[1] = i;
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
