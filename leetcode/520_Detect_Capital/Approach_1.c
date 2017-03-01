#include <stdio.h>

#define true 1
#define false 0

typedef char bool;

bool detectCapitalUse(char* word)
{
	int i;
	char c;

	/* start_所有字母都是小写 */
	i = 0;
	while((c = word[i]) != '\0' && (c >= 'a' && c <= 'z')) {
		i++;
	}
	if(c == '\0') {
		return true;
	}
	/* end_所有字母都是小写 */

	/* start_所有字母都是大写 */
	i = 0;
	while((c = word[i]) != '\0' && (c >= 'A' && c <= 'Z')) {
		i++;
	}
	if(c == '\0') {
		return true;
	}
	/* end_所有字母都是大写 */

	/* start_第一个字母大写 */
	if(word[0] >= 'A' && word[0] <= 'Z') {
		i = 1;
		while((c = word[i]) != '\0' && (c >= 'a' && c <= 'z')) {
			i++;
		}
		if(c == '\0') {
			return true;
		}
	}
	/* end_第一个字母大写 */

	return false;
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
