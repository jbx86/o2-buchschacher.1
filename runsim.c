#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_CANON 1024

int main (int argc, char *argv[]) {
	pid_t childpid = 0;
	int n;
	int pr_limit;
	int pr_count = 0;
	char str[MAX_CANON];

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
	pr_limit = atoi(argv[1]);

	int i;
	for (i = 1; i < pr_limit; i++)
		if ((childpid = fork()) <= 0)
			break;

	// Run loop
//	while (fgets(str, MAX_CANON, stdin) != NULL) {
//
//	}


	//if ((childpid = fork()) <= 0)
	//	break;
	//while (pr_count < pr_limit

	fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n", i, (long)getpid(), (long)getppid(), (long)childpid);
	return 0;

}
