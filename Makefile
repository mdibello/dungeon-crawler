CC=g++
CCFLAGS=--std=c++11 -g
SFMLFLAGS=-lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio
OBJECTS=main.o tile.o map.o resources.o

all: main

main: $(OBJECTS)
	$(CC) $(CFLAGS) -o main $(OBJECTS) $(SFMLFLAGS)

main.o: main.cpp main.hpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o

tile.o: Tile.cpp Tile.hpp main.hpp
	$(CC) $(CFLAGS) -c Tile.cpp -o tile.o

map.o: Map.cpp Map.hpp main.hpp
	$(CC) $(CFLAGS) -c Map.cpp -o map.o

resources.o: Resources.cpp Resources.hpp main.hpp
	$(CC) $(CFLAGS) -c Resources.cpp -o resources.o

clean:
	rm *o main
