CC=g++
CFLAGS=-g -Wall -std=c++11 -DDEBUG

main: main.cpp Item.h Pool.h
	$(CC) $(CFLAGS) main.cpp -o main

