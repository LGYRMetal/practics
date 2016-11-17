#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <libgen.h>

#define DEBUG 1

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

char* get_full_path(char* top_path, char* filename)
{
    DIR *d = opendir(top_path);
    struct dirent *namelist;
    char* full_path = malloc(MAX_FILENAME * sizeof(char));

    strcpy(full_path, top_path);
    if(strchr(filename, '/')) {
        closedir(d);
        return get_full_path(full_path, dirname(strdup(filename)));
    }

    while((namelist = readdir(d))) {

#if DEBUG
        printf("%s\n", namelist->d_name);
#endif

        if(!strcmp(namelist->d_name, filename)) {
            closedir(d);
            return top_path;
        }
    }

    rewinddir(d);

    while((namelist = readdir(d))) {
#if DEBUG
        printf("%s\n", namelist->d_name);
#endif
        if(namelist->d_type == DT_DIR &&
           strcmp(namelist->d_name, ".") &&
           strcmp(namelist->d_name, "..")) {
            strcat(full_path, namelist->d_name);
            strcat(full_path, "/");
            if(get_full_path(full_path, filename) != NULL) {
                return full_path;
            }
            strcpy(full_path, top_path);
        }
    }

    closedir(d);

    return NULL;
}

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
        printf("%s\n", line);
        if((s1 = strstr(line, "#")) &&
           (s2 = strstr(line, "include")) &&
           (int)s1 < (int)s2) {
            if((s1 = strchr(line, '<')) &&
               (s2 = strchr(line, '>')) &&
               (int)s1 < (int)s2) {
                strcpy(full_filename, "/usr/include/");
                get_basename(++s1, basename, '>');
#if DEBUG
                printf("%s\n", basename);
#endif
                full_filename = get_full_path(full_filename, basename);
                if(!full_filename) {
                    printf("file not found!\n");
                    return;
                }
            }
            else if((s1 = index(line,'"')) &&
                    (s2 = rindex(line, '"')) &&
                    (int)s1 < (int)s2) {
                strcpy(full_filename, "./");
                get_basename(++s1, basename, '"');
            }
            else {
                printf("#include语句格式错误\n");
                return; 
            }
            strcat(full_filename, basename);

#if DEBUG
            printf("%s\n", full_filename);
#endif

            process_file(full_filename);

#if DEBUG
            print(full_filename);
#endif
/*            full_filename[0] = '\0';*/ /* 清空full_filename内容 */
        }
    }

    fclose(f);
}

int main(int argc, char* argv[])
{
    process_file("test.c");

    return 0;
}
