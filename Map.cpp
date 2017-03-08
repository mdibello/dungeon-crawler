#include "Map.hpp"

void Map::setGameProperties(GameProperties properties) {
    Map::gameProperties = properties;
}

void Map::setGridWidth(int w) {
    Map::gameProperties.gridWidth = w;
}

int Map::getGridWidth() {
    return Map::gameProperties.gridWidth;
}

Tile* Map::at(int index) {
    return Map::grid[index];
}

Tile* Map::at(Coord c) {
    return Map::grid[coordToIndex(c, Map::gameProperties.gridWidth)];
}

//void Map::set(int index, int value) {
//    grid[index] = value;
//}

void Map::importLayer(std::string mapName, std::string fileName, std::string tilesetName, Resources& r) {
    std::ifstream layerFile("assets/maps/" + mapName + "/" + fileName + ".csv");
    for (int i = 0; i < gameProperties.gridHeight; i++) {
        for (int j = 0; j < gameProperties.gridWidth; j++) {
            int tileNumber;
            layerFile >> tileNumber;
            int tileIndex = (i * gameProperties.gridWidth) + j;
            Tile* t = new Tile;
            t->setGameProperties(Map::gameProperties);
            t->initializeSprite(tilesetName, tileNumber, tileIndex, r);
            Map::grid.push_back(t);
        }
    }
    layerFile.close();
}

void Map::push_back(Tile* t) {
    Map::grid.push_back(t);
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (std::vector<Tile*>::const_iterator it = Map::grid.begin(); it != Map::grid.end(); it++) {
        target.draw(**it);
    }
}
