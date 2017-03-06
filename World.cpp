#include "World.hpp"

void World::setGameProperties(GameProperties properties) {
    World::gameProperties = properties;
}

void World::setGridWidth(int w) {
    World::gameProperties.gridWidth = w;
}

int World::getGridWidth() {
    return World::gameProperties.gridWidth;
}

Tile* World::at(int index) {
    return World::grid[index];
}

Tile* World::at(Coord c) {
    return World::grid[coordToIndex(c, World::gameProperties.gridWidth)];
}

//void World::set(int index, int value) {
//    grid[index] = value;
//}

void World::push_back(Tile* t) {
    World::grid.push_back(t);
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (std::vector<Tile*>::const_iterator it = World::grid.begin(); it != World::grid.end(); it++) {
        target.draw(**it);
    }
}
