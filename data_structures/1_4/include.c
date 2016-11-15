#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*#define MAX_LINE 1000*/
#define MAX_FILENAME 100

/*
int getline(char* line, FILE* filename)
{
    int  i;
    char c;

    i = 0;
    while((c = getc(filename) != EOF && c != '\n')) {
        line[i] = c;
        i++;
    }

    if(c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';

    return i;
}
*/

void get_basename(char* from, char* to, const char end_flag)
{
    int i = 0;
    while((to[i] = from[i]) != end_flag) {
        i++;
    }
    to[i] = '\0';
}

void print(const char* filename)
{
    char c;
    const char* M_READ = "r";
    FILE* f = fopen(filename, M_READ);

    printf("=========== %s ===========\n", filename);
    while((c = getc(f)) != EOF) {
        putchar(c);
    }

    printf("=========== end of %s ============\n", filename);

    fclose(f);
}

void process_file(const char* filename)
{
    char c;
    const char* M_READ = "r";
    char* line = NULL; /* 用于getline */
    size_t len = 0;    /* 用于getline */
    char* full_filename = malloc(MAX_FILENAME * sizeof(char));
    char* basename = malloc(MAX_FILENAME * sizeof(char));
    FILE* f = fopen(filename, M_READ);
    char* s1;
    char* s2;   /* s1表示#号的位置，s2表示include的位置 */

    while(getline(&line, &len, f) != -1) {
        if((s1 = strstr(line, "#")) &&
           (s2 = strstr(line, "include")) &&
           (int)s1 < (int)s2) {
            if((s1 = strchr(line, '<')) &&
               (s2 = strchr(line, '>')) &&
               (int)s1 < (int)s2) {
                strcat(full_filename, "/usr/include/");
                get_basename(++s1, basename, '>');
            }
            else if((s1 = index(line,'"')) &&
                    (s2 = rindex(line, '"')) &&
                    (int)s1 < (int)s2) {
                strcat(full_filename, "./");
                get_basename(++s1, basename, '"');
            }
            else {
                printf("#include语句格式错误\n");
                return; 
            }
            strcat(full_filename, basename);
            process_file(full_filename);
            print(full_filename);
            full_filename[0] = '\0'; /* 清空full_filename内容 */
        }
    }

    fclose(f);
}

int main(int argc, char* argv[])
{
    process_file("include.c");

    return 0;
}
