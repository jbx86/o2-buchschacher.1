#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CANON 1024

int makeargv(const char *source, const char *delimiters, char ***argvp);

int main (int argc, char *argv[]) {
	pid_t childpid = 0;
	int pr_limit;	// max number of children allowed to execute at a time
	int pr_count;	// number of active children
	int pr_run;	// number of processes run
	char str[MAX_CANON] = "null";
	char delims[] = " \t\n";
	char **myargv;
	int i;
	int c;
	char *nvalue = NULL;
	int n = 0;	// maxx number of processes generated

	// find -n flag
	while ((c = getopt(argc, argv, "n:")) != -1) {
		switch (c) {
			case 'n':
				n = atoi(optarg);
				break;
		}
	}

	// pass n value to pr_limit and check validity
	if (n < 1) {
		fprintf(stderr, "%s: ", argv[0]);
		perror("Invalid parameter entered");
		//fprintf(stderr, "Usage: %s process_limit  -n\t(process_limit > 0)", argv[0]);
		return 1;
	}

	// 4) initialize pr_count
	pr_count = 0;
	pr_run = 0;

	// 5) execute loop until end-of-file, 5b) read a line from stdin...
	while (fgets(str, MAX_CANON, stdin) != NULL) {
		if (pr_run == n) {
			fprintf(stderr, "%s has reached the max number of processes to be generated (%d)\n", argv[0], n);
			return 0;
		}

		// 5a) wait for child to finish and decrament count
		if (pr_count == pr_limit) {
			wait(NULL);
			pr_count--;
		}

		// 5c) increment count to track number of active children
		pr_count++;
		pr_run++;
		// 5b) ... and execute program corresponding to command
		childpid = fork();

		if (childpid < 0) {
			fprintf(stderr, "%s: ", argv[0]);
			perror("Creation of child unsuccessful");
			return 1;
		} 
		if (childpid == 0) {
			if (makeargv(str, delims, &myargv) == -1) {
				fprintf(stderr, "%s: ", argv[0]);
				perror("Failed to pass arguments to makeargv\n");
			}
			else {
				//This bit of code should execute other functions, but I wasn't having any luck getting execvp running
				fprintf(stderr, "process %ld generated\n", (long)getpid());
			}
			return 0;
		}

		// 5d) check to see if any children have finished
		if (waitpid(-1, NULL, WNOHANG) != 0) {
			pr_count--;
		}
	}

	// 6) After encountering end of file, wait for remaining children to finish then exit
	wait(NULL);
	fprintf(stderr, "%s has complete without reaching the max number of processes to be generated (%d)\n", argv[0], n);
	return 0;
}
