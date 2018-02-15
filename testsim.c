#include <stdio.h>
#include <stdlib.h>

int makeargv(const char *source, const char *delimiters, char ***argvp);

int main(int argc, char *argv[]) {
	int i;
	fprintf(stderr, "running \"");
	for (i = 0; i < argc; i++) {
		fprintf(stderr, "%s ", argv[i]);
	}
	fprintf(stderr, "\"\n");

	return 0;
	/*
	if (argc < 2) {
		fprintf(stderr, "Usage: %s number\n", argv[0]);
		return 1;
	}*/
}
