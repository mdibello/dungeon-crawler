#ifndef MAP_HPP
#define MAP_HPP

#include "Tile.hpp"
#include "main.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

class Map : public sf::Drawable {
public:
    void setGameProperties(GameProperties properties);
    GameProperties getGameProperties();
    void setGridWidth(int w);
    int getGridWidth();
    Tile* at(int index);
    Tile* at(Coord c);
    void importLayer(std::string mapName, std::string fileName, std::string tilesetName, Resources& r);
    std::vector<int> parseLayerFile(std::string mapName, std::string tilesetName);
    //void set(int index, int value);
    void push_back(Tile* t);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    std::vector<Tile*> grid;
    GameProperties gameProperties;
};

#endif
