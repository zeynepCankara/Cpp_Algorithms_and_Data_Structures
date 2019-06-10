# Makefile to compile efficiently Zeynep CANKARA/ 21703381
CC=g++
CFLAGS=-c -Wall
target: first
first: main.o HuffmanHeap.o HuffmanQueue.o HuffmanCode.o MinHeap.o MaxHeap.o MedianHeap.o
	$(CC) main.o HuffmanHeap.o HuffmanQueue.o HuffmanCode.o MinHeap.o MaxHeap.o MedianHeap.o -o hw3
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
HuffmanHeap.o: HuffmanHeap.cpp
	$(CC) $(CFLAGS) HuffmanHeap.cpp
HuffmanQueue.o: HuffmanQueue.cpp
	$(CC) $(CFLAGS) HuffmanQueue.cpp
HuffmanCode.o: HuffmanCode.cpp
	$(CC) $(CFLAGS) HuffmanCode.cpp
MinHeap.o: MinHeap.cpp
	$(CC) $(CFLAGS) MinHeap.cpp
MaxHeap.o: MaxHeap.cpp
	$(CC) $(CFLAGS) MaxHeap.cpp
MedianHeap.o: MedianHeap.cpp
	$(CC) $(CFLAGS) MedianHeap.cpp
clean:
	rm *o hw3
