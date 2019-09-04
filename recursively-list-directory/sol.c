#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <dirent.h>

void list_dir_flat(const char * path) {
    DIR *dp;

    struct dirent *dirp;

    if ((dp = opendir(path)) == NULL) {
        printf("Cannot open directory. Error: %s\n", strerror(errno));
        exit(1);
    }

    while((dirp = readdir(dp)) !=  NULL) {
        printf("%s ", dirp->d_name);
    }

    closedir(dp);
}

int main(int argc, char **argv) {
    DIR *dp;

    struct dirent *dirp;

    if (argc != 2) {
        printf("No args provided!\n");
        exit(1);
    }

    list_dir_flat(argv[1]);

    return 0;
}