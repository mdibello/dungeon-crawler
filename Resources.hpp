#ifndef RESOURCES_H
#define RESOURCES_H

#include <map>
#include <SFML/Graphics.hpp>

class Resources {
public:
    sf::Image extractTile(std::string tilesetName, int tileNumber, int tileIndex);
private:
    std::map<std::string, sf::Image> tilesets;
    std::map<std::string, std::map<int, sf::Image>> tiles;
};

#endif
