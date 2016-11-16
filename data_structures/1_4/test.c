#include <stdio.h>
#include <dirent.h>

int main(void)
{
    DIR *dir;
    dir = opendir("/usr/include/");
    struct dirent *namelist;
    int n;

    while((namelist = readdir(dir))) {
        printf("%s: %d\n", namelist->d_name, namelist->d_type);
    }
    free(namelist);
    closedir(dir);

    char a[] = "abc";

    if(!strcmp(a, "abc"))
        printf("yes\n");
    else
        printf("no\n");
}
