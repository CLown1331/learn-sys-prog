#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char **argv) {
    DIR *dp;

    struct dirent *dirp;

    if (argc != 2) {
        printf("No args provided!\n");
        exit(1);
    }

    if ((dp = opendir(argv[1])) == NULL) {
        printf("Cannot open directory. Error: %s\n", strerror(errno));
        exit(1);
    }

    while((dirp = readdir(dp)) !=  NULL) {
        printf("%s ", dirp->d_name);
    }

    closedir(dp);
    return 0;
}