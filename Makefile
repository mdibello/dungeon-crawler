CC=g++
CCFLAGS=--std=c++11 -g
SFMLFLAGS=-lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio
OBJECTS=main.o tile.o map.o resources.o

all: main

main: $(OBJECTS)
	$(CC) $(CCFLAGS) -o main $(OBJECTS) $(SFMLFLAGS)

main.o: main.cpp main.hpp
	$(CC) $(CCFLAGS) -c main.cpp -o main.o

tile.o: Tile.cpp Tile.hpp main.hpp
	$(CC) $(CCFLAGS) -c Tile.cpp -o tile.o

map.o: Map.cpp Map.hpp main.hpp
	$(CC) $(CCFLAGS) -c Map.cpp -o map.o

resources.o: Resources.cpp Resources.hpp main.hpp
	$(CC) $(CCFLAGS) -c Resources.cpp -o resources.o

clean:
	rm *o main
