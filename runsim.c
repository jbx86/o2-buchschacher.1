#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void perror(const char *s);

int main(int argc, char *argv[]) {
	// int pr_limit = 10;	//Max number of children running at one time
	int pr_count = 0;	//Number of active children

	pid_t childpid = 0;
	int i;

	//check for walid number of command-line arguments
	if (argc != 3) {
		fprintf(stderr, "%s: ", argv[0]);
		perror("Error");
		return 1;
	}
	int n = atoi(argv[2]);
	int pr_limit = atoi(argv[1]);

	//perror("Error");
	fprintf(stderr, "pr_limit:%d n:%d\n", pr_limit, n);

	for (i = 1; i < n; i++)
		if ((childpid = fork()) <= 0)
			break;

	fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n", i, (long)getpid(), (long)getppid(), (long)childpid);
	return 0;
}
