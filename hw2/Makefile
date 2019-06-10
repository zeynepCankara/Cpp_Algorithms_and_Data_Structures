# @describe: Compiles the code
CC = g++

CFLAGS= -c -Wall

target: first
	
first: main.o BST.o BSTNode.o
	$(CC) main.o BST.o BSTNode.o   -o hw2
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
BST.o: BST.cpp
	$(CC) $(CFLAGS) BST.cpp
BSTNode.o: BSTNode.cpp
	$(CC) $(CFLAGS) BSTNode.cpp
clean:
	rm *o hw2
