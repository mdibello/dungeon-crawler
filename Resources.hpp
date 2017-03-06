#ifndef RESOURCES_H
#define RESOURCES_H

#include "main.hpp"
#include <map>
#include <SFML/Graphics.hpp>

class Resources {
public:
    void setGameProperties(GameProperties properties);
    sf::Texture extractTile(std::string tilesetName, int tileNumber);
private:
    std::map<std::string, sf::Image> tilesets;
    std::map<std::string, std::map<int, sf::Texture>> tiles;
    GameProperties gameProperties;
};

#endif
