#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

typedef char bool;
typedef enum {ALL_CAPITALS, ALL_NOT_CAPITALS, FIRST_CAPITALS} type;

bool detectCapitalUse(char* word)
{
	type t;
	char c, lowerLimit, upperLimit;
	int i;
	int len = strlen(word);
	
	if(len == 1 &&
	   !((word[0] >= 'a' && word[0] <= 'z') ||
		 (word[0] >= 'A' && word[0] <= 'Z'))) {
		return false;
	}

	if(len > 1) {
		if(word[0] >= 'A' && word[0] <= 'Z') { /* 首字母大写 */
			i = 2;
			if(word[1] >= 'A' && word[1] <= 'Z') { /* 第二个字母也大写 */
				t = ALL_CAPITALS; /* 全大写情况 */
				/* 错误值范围 */
				lowerLimit = 'a';
				upperLimit = 'z';
			}
			else if(word[1] >= 'a' && word[1] <= 'z') { /* 第二个字母小写 */
				t = FIRST_CAPITALS; /* 首字母大写情况 */
				/* 错误值范围 */
				lowerLimit = 'A';
				upperLimit = 'Z';
			}
		}
		else if(word[0] >= 'a' && word[0] <= 'z') { /* 全小写情况 */
			i = 1;
			t = ALL_NOT_CAPITALS;
			/* 错误值范围 */
			lowerLimit = 'A';
			upperLimit = 'Z';
		}

		while((c = word[i]) != 0) {
			i++;
			if(c >= lowerLimit && c <= upperLimit)
				return false;
		}
	}

	return true;
}

int main(int argc, char* argv[])
{
	detectCapitalUse("USA") ? printf("True\n") : printf("False\n");
	detectCapitalUse("FlaG") ? printf("True\n") : printf("False\n");
	detectCapitalUse("leetcode") ? printf("True\n") : printf("False\n");
	detectCapitalUse("A") ? printf("True\n") : printf("False\n");
	detectCapitalUse("a") ? printf("True\n") : printf("False\n");

	return 0;
}
