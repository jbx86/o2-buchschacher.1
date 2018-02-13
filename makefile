prog1: testsim.c runsim.c
	gcc -o prog testsim.c runsim.c -I. 
#
#testsim.o: testsim.c runsim.h
#	gcc -c testsim.c -I.
#
#runsim.o: runsim.c runsim.h
#	gcc -c runsim.c -I.
