#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIDE_LENGTH 4

const char LETTER[SIDE_LENGTH][SIDE_LENGTH] = {
    {'t', 'h', 'i', 's'},
    {'w', 'a', 't', 's'},
    {'o', 'a', 'h', 'g'},
    {'f', 'g', 'd', 't'},
};

const char* WORDS[] = {"this", "two", "fat", "that", "it", "siht", "gaah", "taht", "taf", "st"};

void exists(const char* word);

void exists(const char* word)
{
    int len = strlen(word);

    /* 横向 */
    /* 如果单词的长度大于字母表边长，不可能存在此单词 */
    if(len <= SIDE_LENGTH)
    {
        for(int i = 0; i < SIDE_LENGTH; i++)
        {
            char* row = malloc((SIDE_LENGTH + 1) * sizeof(char));
            int j;

            /* 正向(从左至右) 开始 */
            for(j = 0; j < SIDE_LENGTH; j++)
            {
                row[j] = LETTER[i][j];
            }
            row[j] = '\0';

            char* start = strstr(row, word);
            if(start)
            {
                /* sir: start index row */
                /* sic: start index col */
                /* eir: end index row */
                /* eic: end index col */
                int sir = i + 1;
                int sic = (int)start - (int)row + 1;
                int eir = i + 1;
                int eic = sic + len - 1;
                printf("%s\t", word);
                printf("start: (%d, %d)\t", sir, sic);
                printf("end: (%d, %d)\n", eir, eic);
            }
            /* 正向 结束 */

            /* 反向(从右至左) 开始 */
            int k;
            for(j--, k = 0; j >= 0, k < SIDE_LENGTH; j--, k++)
            {
                row[k] = LETTER[i][j];
            }

            start = strstr(row, word);
            if(start)
            {
                int eir = i + 1;
                int eic = (int)start - (int)row + 1;
                int sir = i + 1;
                int sic = eic + len - 1;
                printf("%s\t", word);
                printf("start: (%d, %d)\t", sir, sic);
                printf("end: (%d, %d)\n", eir, eic);
            }
            /* 反向 结束 */
        }

        /* 纵向 */
        for(int i = 0; i < SIDE_LENGTH; i++)
        {
            char* col = malloc((SIDE_LENGTH + 1) * sizeof(char));
            /* 正向(从上至下) 开始 */
            int j = 0;
            for(j; j < SIDE_LENGTH; j++)
            {
                col[j] = LETTER[j][i];
            }
            col[j] = '\0';

            char* start = strstr(col, word);
            if(start)
            {
                int sir = (int)start - (int)col + 1;
                int sic = i + 1;
                int eir = sir + len - 1;
                int eic = i + 1;
                printf("%s\t", word);
                printf("start: (%d, %d)\t", sir, sic);
                printf("end: (%d, %d)\n", eir, eic);
            }
            /* 正向 结束 */

            /* 反向(从下至上) 开始 */
            int k;
            for(j--, k = 0; j >= 0, k < SIDE_LENGTH; j--, k++)
            {
                col[k] = LETTER[j][i];
            }

            start = strstr(col, word);
            if(start)
            {
                int eir = (int)start - (int)col + 1;
                int eic = i + 1;
                int sir = eir + len - 1;
                int sic = i + 1;
                printf("%s\t", word);
                printf("start: (%d, %d)\t", sir, sic);
                printf("end: (%d, %d)\n", eir, eic);
            }
            /* 反向 结束 */
        }

        /* 对角线 */
        /* 经过分析如果对角线也有单词的话，迷板的行列数必须相同 */
        /* 所以对角线的长度和行列的长度一样 */

        /* 从上左至右下 开始 */
        int i, j;
        char* diagonal = malloc((SIDE_LENGTH + 1) * sizeof(char));
        for(i = 0, j = 0; i < SIDE_LENGTH, j < SIDE_LENGTH; i++, j++)
        {
            diagonal[i] = LETTER[i][j];
        }
        diagonal[i] = '\0';

        char* start = strstr(diagonal, word);
        if(start)
        {
            int sir, sic, eir, eic;
            sir = sic = (int)start - (int)diagonal + 1;
            eir = eic = sir + len - 1;
            printf("%s\t", word);
            printf("start: (%d, %d)\t", sir, sic);
            printf("end: (%d, %d)\n", eir, eic);
        }
        /* 从左上至右下 结束 */

        /* 从右下至左上 开始 */
        int k;
        for(i--, j--, k = 0; i >= 0, j >= 0, k < SIDE_LENGTH; i--, j--, k++)
        {
            diagonal[k] = LETTER[i][j];
        }

        start = strstr(diagonal, word);
        if(start)
        {
            int sir, sic, eir, eic;
            eir = eic = (int)start - (int)diagonal + 1;
            sir = sic = eir + len - 1;
            printf("%s\t", word);
            printf("start: (%d, %d)\t", sir, sic);
            printf("end: (%d, %d)\n", eir, eic);
        }
        /* 从右下至左上 结束 */

        /* 从左下至右上 开始 */
        for(i = SIDE_LENGTH - 1, j = 0; i >= 0, j < SIDE_LENGTH; i--, j++)
        {
            diagonal[j] = LETTER[i][j];
        }

        start = strstr(diagonal, word);
        if(start)
        {
            int sir = (int)start - (int)diagonal + len + 1;
            int sic = (int)start - (int)diagonal + 1;
            int eir = (int)start - (int)diagonal + 1;
            int eic = (int)start - (int)diagonal + len + 1;
            printf("%s\t", word);
            printf("start: (%d, %d)\t", sir, sic);
            printf("end: (%d, %d)\n", eir, eic);
        }
        /* 从左下至右上 结束 */

        /* 从右上至左下 开始 */
        for(i = 0, j = SIDE_LENGTH - 1; i < SIDE_LENGTH, j >= 0; i++, j--)
        {
            diagonal[i] = LETTER[i][j];
        }

        start = strstr(diagonal, word);
        if(start)
        {
            int sir = (int)start - (int)diagonal + 1;
            int sic = SIDE_LENGTH - ((int)start - (int)diagonal);
            int eir = sir + len - 1;
            int eic = SIDE_LENGTH - ((int)start - (int)diagonal + len - 1);
            printf("%s\t", word);
            printf("start: (%d, %d)\t", sir, sic);
            printf("end: (%d, %d)\n", eir, eic);
        }
        /* 从右上至左下 结束 */
    }
}

int main(int argc, char* argv[])
{
    int words_array_len = sizeof(WORDS) / sizeof(WORDS[0]);
    for(int i = 0; i < words_array_len; i++)
    {
        exists(WORDS[i]);
    }

    return 0;
}
