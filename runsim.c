#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CANON 1024

int main (int argc, char *argv[]) {
	pid_t childpid = 0;
	int pr_limit;	// max number of children allowed to execute at a time
	int pr_count;	// number of active children
	char str[MAX_CANON];
	char delims[] = " \t";
	char **myargv;

	fprintf(stderr, "running\n");

	// 1) take one command-line argument
	if (argc != 2) {
		fprintf(stderr, "Usage: %s processes\n", argv[0]);
		return 1;
	}

	// 2) initialize pr_limit from command line
	pr_limit = atoi(argv[1]);
	if (pr_limit < 1) {
		fprintf(stderr, "Argument must be an int > 0\n");
		return 1;
	}

	fprintf(stderr, "Argument recived: %d\n", pr_limit);
	// 4) initialize pr_count
	pr_count = 0;

	// 5) execute loop until end-of-file, 5b) read a line from stdin...
	while (fgets(str, MAX_CANON, stdin) != NULL) {

		fprintf(stderr, "input from stdin: %s", str);
/*
		// 5a) wait for child to finish and decrament count
		if (pr_count == pr_limit) {
			wait(NULL);
			pr_count--;
		}

		// 5b) ... and execute program corresponding to command
		childpid = fork();
		if (childpid < 0) {
			fprintf(stderr, "creation of child unsuccessful");
			return 1;
		} 
		if (childpid == 0) {
			if (makeargv(str, delims, &myargv) == -1)
				fprintf(stderr, "failed to pass arguments to makeargv");
			else {
				execvp(myargv[0], &myargv[0]);
				fprintf(stderr, "failed to execute command");
			}
			return 1;
		}
		// 5c) increment count to track number of active children
		pr_count++;

		// 5c check to see if any children have finished
		if (waitpid(-1, NULL, WNOHANG) != 0) {
			pr_count--;
		}

		do {
			childpid = wait(NULL);
		} while (1);
		*/
	}

//	fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n", i, (long)getpid(), (long)getppid(), (long)childpid);
	return 0;

}
