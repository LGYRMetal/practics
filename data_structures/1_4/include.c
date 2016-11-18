#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <libgen.h>

/* #define DEBUG 0 */

/*#define MAX_LINE 1000*/
#define MAX_FILENAME 100
#define MAX_SIZE     2000

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
    char* result = NULL;

    strcpy(full_path, top_path);
    /*
    if(strchr(filename, '/')) {
        closedir(d);
        return get_full_path(full_path, basename(strdup(filename)));
    }
    */

    while((namelist = readdir(d))) {

#ifdef DEBUG
        printf("%s\n", namelist->d_name);
#endif

        if(!strcmp(namelist->d_name, filename)) {
            closedir(d);
            return top_path;
        }
    }

    rewinddir(d);

    while((namelist = readdir(d))) {
#ifdef DEBUG
        printf("%s\n", namelist->d_name);
#endif
        if(namelist->d_type == DT_DIR &&
           strcmp(namelist->d_name, ".") &&
           strcmp(namelist->d_name, "..")) {
            strcat(full_path, namelist->d_name);
            strcat(full_path, "/");
            if((result = get_full_path(full_path, filename)) != NULL) {
                return result;
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
    char* mybasename = malloc(MAX_FILENAME * sizeof(char));
    FILE* f = fopen(filename, M_READ);
    char* s1;
    char* s2;   /* s1表示#号的位置，s2表示include的位置 */

    /* 记录处理过得文件，之后如果再出现就不处理了，避免两个文件互相包含的
     * 的情况引起的死循环 */
    static char processed_files[MAX_SIZE];

    while(getline(&line, &len, f) != -1) {
#ifdef DEBUG
        printf("%s\n", line);
#endif
        if((s1 = strstr(line, "#")) &&
           (s2 = strstr(line, "include")) &&
           (int)s1 < (int)s2) {
            if((s1 = strchr(line, '<')) &&
               (s2 = strchr(line, '>')) &&
               (int)s1 < (int)s2) {
                strcpy(full_filename, "/usr/include/");
                get_basename(++s1, mybasename, '>');
            }
            else if((s1 = index(line,'"')) &&
                    (s2 = rindex(line, '"')) &&
                    (int)s1 < (int)s2) {
                strcpy(full_filename, "./");
                get_basename(++s1, mybasename, '"');
            }
            else {
                printf("%s\n不是#include语句\n", line);
                return; 
            }
            mybasename = basename(mybasename);
#ifdef DEBUG
            printf("%s\n", mybasename);
#endif
            if(!strstr(processed_files, mybasename)) {
                full_filename = get_full_path(full_filename, mybasename);
                if(!full_filename) {
                    printf("file %s not found!\n", mybasename);
                    return;
                }

#ifdef DEBUG
                printf("%s\n", full_filename);
#endif

                strcat(full_filename, mybasename);
#ifdef DEBUG
                printf("%s\n", full_filename);
#endif

                strcat(processed_files, basename(strdup(mybasename)));
                strcat(processed_files, ",");
#ifdef DEBUG
                printf("%s\n", processed_files);
#endif

                process_file(full_filename);

                print(full_filename);

            }
/*            full_filename[0] = '\0';*/ /* 清空full_filename内容 */
        }
    }

    /*
    free(line);
    free(full_filename);
    free(mybasename);
    free(s1);
    free(s2);
    */
    fclose(f);
}

int main(int argc, char* argv[])
{
    process_file("test.c");
/*    get_full_path("/usr/include/", "bits"); */

    return 0;
}
