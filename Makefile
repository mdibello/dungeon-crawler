CC=g++
CCFLAGS=--std=c++11 -g
SFMLFLAGS=-lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio
OBJECTS=main.o

all: main

main: $(OBJECTS)
	$(CC) $(CFLAGS) -o main $(OBJECTS) $(SFMLFLAGS)

main.o: main.cpp main.hpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o

clean:
	rm *o main
