#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
	pid_t childpid = 0;
	int n;
	int pr_limit;
	int pr_count = 0;

	// verify simrun is being run with one argument
	if (argc != 2) {
		fprintf(stderr, "Usage: %s processes\n", argv[0]);
		return 1;
	}
	// validate argument entered
	n = atoi(argv[1]);
	if (n < 1) {
		fprintf(stderr, "Argument must be an int > 0\n");
		return 1;
	}

	fprintf(stderr, "%s ran with %d arguments\n", argv[0], (argc - 1));
	pr_limit = atoi(argv[1]);
	fprintf(stderr, "pr_limit: %d\n", pr_limit);


	//fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n", (long)getpid(), (long)getppid(), (long)childpid);
	return 0;

}
