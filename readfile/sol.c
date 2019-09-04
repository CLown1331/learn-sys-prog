#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv) {
    FILE *fp;
    char *line;
    size_t len;
    ssize_t read;

    fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        printf("%zu:\t", read);
        printf("%s", line);
    }

    if (line) {
        free(line);
    }

    exit(EXIT_SUCCESS);
}