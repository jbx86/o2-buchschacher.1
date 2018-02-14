all: runsim

runsim: runsim.c makeargv.c
	gcc -o runsim runsim.c makeargv.c 

testsim: testsim.c makeargv.c
	gcc -o testsim testsim.c makeargv.c
#
#runsim.o: runsim.c runsim.h
#	gcc -c runsim.c -I.
