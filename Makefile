# Do Not Change This File
compile:
	gcc test.c

run: compile
	./a.out

compileerr:
	gcc testerr.c -o testerr.exe

runerr: compileerr
	./testerr.exe

compilert:
	gcc testrt.c -o testrt.exe

runrt: compilert
	./testrt.exe