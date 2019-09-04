#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <dirent.h>

void list_dir_flat(const char * pathname) {
    DIR *dp;

    struct dirent *dirp;

    if ((dp = opendir(pathname)) == NULL) {
        printf("Cannot open directory. Error: %s\n", strerror(errno));
        exit(1);
    }

    while((dirp = readdir(dp)) !=  NULL) {
        printf("%s ", dirp->d_name);
    }

    closedir(dp);
}

void list_dir_recur(const char * pathname) {
    DIR *dp;
    struct dirent *dirp;
    char PATH[259];
    
    memset(PATH, 0, sizeof PATH);

    if ((dp = opendir(pathname)) == NULL) {
        return;
    }

    while((dirp = readdir(dp)) !=  NULL) {
        if (dirp->d_type == DT_DIR) {
            if (strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0) {
                continue;
            }
            printf("%s/%s\n", pathname, dirp->d_name);
            snprintf(PATH, sizeof(PATH) - 1, "%s/%s", pathname, dirp->d_name);
            list_dir_recur(PATH);
        } else {
            printf("%s/%s\n", pathname, dirp->d_name);
        }
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

    list_dir_recur(argv[1]);

    return 0;
}