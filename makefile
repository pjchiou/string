#A simple makefile

#declaration
CC=g++
FLAGS=-g -Wall

main.out:main.cpp header.o
	$(CC) -o main.out main.cpp header.o

header.o:header.h header.cpp
	$(CC) -c header.cpp

clean:
	rm -f main.out header.o main.o
