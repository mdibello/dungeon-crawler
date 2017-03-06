#ifndef RESOURCES_H
#define RESOURCES_H

#include <map>
#include <SFML/Graphics.hpp>

class Resources {
public:
private:
    //std::map<std::string, pair<sf::Image, std::map<int, sf::Image>>> resources;
    std::map<std::string, sf::Image> tilesets;
    std::map<std::string, std::map<int, sf::Image>> tiles;
};

#endif
