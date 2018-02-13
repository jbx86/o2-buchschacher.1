all: runsim

runsim: runsim.c makeargv.c
	gcc -o runsim runsim.c makeargv.c 
#
#testsim.o: testsim.c runsim.h
#	gcc -c testsim.c -I.
#
#runsim.o: runsim.c runsim.h
#	gcc -c runsim.c -I.
