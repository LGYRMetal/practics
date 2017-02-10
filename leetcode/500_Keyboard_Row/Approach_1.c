/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

/*
const char LINE1[20] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
                        'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
const char LINE2[18] = {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
                        'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
const char LINE3[14] = {'Z', 'X', 'C', 'V', 'B', 'N', 'M',
                        'z', 'x', 'c', 'v', 'b', 'n', 'm'};
const char* keyBoard[3] = {LINE1, LINE2, LINE3};
*/

const char* keyBoard[3] = {
    "QWERTYUIOPqwertyuiop",
    "ASDFGHJKLasdfghjkl",
    "ZXCVBNMzxcvbnm"
};

char** findWords(char** words, int wordsSize, int* returnSize)
{
    char** output = NULL;
    *returnSize = 0;

    if(wordsSize > 0) {
        int l = 0; /* index of output */
        output = malloc(wordsSize * sizeof(char*));
        if(output == NULL) {
            err(-1, "malloc: output: out of space!");
        }

        for(int i = 0; i < wordsSize; i++) {
            int k; /* index of keyBoard */
            for(k = 0; k < 3; k++) {
                if(strchr(keyBoard[k], words[i][0])) {
                    break;
                }
            }

            int j = 1; /* index of word[i] */
            char c;
            while((c = words[i][j]) != 0 && strchr(keyBoard[k], c)) {
                j++;
            }

            if(c == 0) {
                (*returnSize)++;
                output[l++] = words[i];
            }
        }
    }

    return output;
}

#define wordsSize 4
int main(int argc, char* argv[])
{
    int* returnSize = malloc(sizeof(int));
    if(returnSize == NULL) printf("main: line 58: malloc: out of space.");
    char* words[wordsSize] = {"Hello", "Alaska", "Dad", "Peace"};
    char** output = findWords(words, wordsSize, returnSize);

    printf("[");
    for(int i = 0; i < *returnSize; i++) {
        printf("%s%s", output[i], (i == (*returnSize)-1 ? "" : ", "));
    }
    printf("]\n");
}
