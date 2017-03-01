#include <stdio.h>

int singleNumber(int* nums, int numsSize)
{
	int a = 1;
	int singleOne = 0;

	for(int i = 0; i < numsSize; i++) {
	}

	for(int i = 0; i < numsSize; i++) {
		singleOne += a * nums[i];
		a *= -1;
	}

	return singleOne;
}

int main(int argc, char* argv[])
{
	int a[] = {1}; int asize = 1;
	int b[] = {1, 1, 2}; int bsize = 3;
	int c[] = {1, 2, 3, 2, 1, 3, 4}; int csize = 7;

	printf("%d\n", singleNumber(a, asize));
	printf("%d\n", singleNumber(b, bsize));
	printf("%d\n", singleNumber(c, csize));
}
