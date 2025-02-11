#!/bin/bash
CC=gcc
CF=-c -Wall
DF=-DDEBUG
output: main.o createInfra.o client_handler.o 
	${CC} -o output main.o createInfra.o client_handler.o

main.o: main.c ../headers.h declarations.h
	${CC} ${CF} ${DF} main.c
createInfra.o: createInfra.c ../headers.h declarations.h
	${CC} ${CF} ${DF} createInfra.c
client_handler.o: client_handler.c ../headers.h declarations.h 
	${CC} ${CF} ${DF} client_handler.c


clean:
	-rm *.o
	-rm -f output
