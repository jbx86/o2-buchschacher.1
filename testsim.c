#include <stdio.h>
#include <stdlib.h>

int makeargv(const char *source, const char *delimiters, char ***argvp);

int main(int argc, char *argv[]) {
	int i, st, rf; // i, sleeptimer, and repeat factor

	// take 2 arguments from command line
	if (argc != 3) {
		fprintf(stderr, "Usage: %s number number");
		return 1;
	}

	// verify arguments
	st = atoi(argv[1]);
	rf = atoi(argv[2]);	
	if ((st < 1) || (rf < 1)) {
		fprintf(stderr, "Invalid data entry, st and rf shout be int > 0");
		return 1;
	}

	// run loop rf times
	for (i = 0; i < rf; i++) {
		sleep(st);
		fprintf(stderr, "%ld\n", (long)getpid());
	}

	return 0;
}
