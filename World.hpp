#ifndef WORLD_HPP
#define WORLD_HPP

#include "Tile.hpp"
#include "main.hpp"
#include <vector>

class World {
public:
    void setGridWidth(int w);
    int getGridWidth();
    int at(int index);
    int at(Coord c);
    //void set(int index, int value);
    void push_back(int value);
private:
    std::vector<int> grid;
    int gridWidth;
};

#endif
