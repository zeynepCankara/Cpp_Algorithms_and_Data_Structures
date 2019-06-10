# Make file to compile source code

CC=g++

CFLAGS=-c -Wall

all: hw

hw: main.o sorting.o
	$(CC) main.o sorting.o -o 21703381_hw1


main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp



sorting.o: sorting.cpp
	$(CC) $(CFLAGS) sorting.cpp


clean:
	rm *o 21703381_hw1
