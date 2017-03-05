#include "World.hpp"

void World::setGridWidth(int w) {
    World::gridWidth = w;
}

int World::getGridWidth() {
    return World::gridWidth;
}

int World::at(int index) {
    return World::grid[index];
}

int World::at(Coord c) {
    return World::grid[coordToIndex(c, World::gridWidth)];
}

//void World::set(int index, int value) {
//    grid[index] = value;
//}

void World::push_back(int value) {
    World::grid.push_back(value);
}
