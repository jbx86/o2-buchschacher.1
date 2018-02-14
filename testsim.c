#include <stdio.h>
#include <stdlib.h>

int makeargv(const char *source, const char *delimiters, char ***argvp);

int main(int argc, char *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "Usage: %s number\n", argv[0]);
		return 1;
	}
}
