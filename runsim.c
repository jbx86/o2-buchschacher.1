#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
	pid_t childpid = 0;
	int n;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s processes\n", argv[0]);
		return 1;
	}
	n = atoi(argv[1]);
	fprintf(stderr, "%s ran with %d arguments\n", argv[0], argc);


	//fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n", (long)getpid(), (long)getppid(), (long)childpid);
	return 0;

}
