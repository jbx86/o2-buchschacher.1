#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <runsim.h>

int main (int argc, char *argv[]) {
	printf("Test Run\n");
	runsim(3);
	printf("Test complete\n");
	return 0;
}
