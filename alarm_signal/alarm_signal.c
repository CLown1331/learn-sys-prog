#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void sig_handler(int signum) {
	printf("Received Signal Number: %d\n", signum);
	system("/bin/ls");
	exit(0);
}

int main() {
	alarm(5);
	signal(SIGALRM, sig_handler);
	for(;;)
		sleep(1);

	return 0;
}
