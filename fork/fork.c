#include <stdio.h>
#include <unistd.h>

int GLOBAL = 10;

int main() {
    
    pid_t pid;

    if ((pid = vfork()) > 0) {
        printf("Before modified\n");
        printf("Parent: global %d\n", GLOBAL);
        GLOBAL = 124;
        printf("After modified\n");
        printf("Parent: global %d\n", GLOBAL);
    } else {
        printf("Before modified\n");
        printf("Child: global %d\n", GLOBAL);
        GLOBAL = 234535;
        printf("After modified\n");
        printf("Child: global %d\n", GLOBAL);
    }

    sleep(1);

    return 0;
}
