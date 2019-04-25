all:
	gcc -c lista.c
	gcc -c grafo.c
	gcc -Wall -lm -O1 -g -o main main.c lista.o grafo.o
