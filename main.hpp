#ifndef MAIN_HPP
#define MAIN_HPP

#include <SFML/Window.hpp>
#include <vector>
#include <iostream>

struct GameProperties {
    int screenWidth;
    int screenHeight;
    int gridWidth;
    int gridHeight;
    int tileSize;
    int numTiles;
};

struct Coord {
    int x;
    int y;
};

int coordToIndex(Coord c, int gridWidth);
Coord indexToCoord(int i, int gridWidth);
Coord indexToPixel(int i, GameProperties gameProperties);

#endif
