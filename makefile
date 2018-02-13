prog1: testsim.o
	gcc -o testsim testsim.o 

testsim.o: testsim.c
	gcc -c testsim.c
