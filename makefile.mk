all: fir.exe sec.exe

fir.o: fir.c
	gcc -c fir.c -o fir.o

fir.exe: fir.o
	gcc fir.o -o fir.exe

sec.o: sec.c
	gcc -c sec.c -o sec.o

sec.exe: sec.o
	gcc sec.o -o sec.exe