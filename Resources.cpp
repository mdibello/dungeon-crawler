#include "Resources.hpp"
#include <iostream>

void Resources::setGameProperties(GameProperties properties) {
    Resources::gameProperties = properties;
}

sf::Texture Resources::extractTile(std::string tilesetName, int tileNumber) {
    sf::Image tileset;
    sf::Texture tile;
    std::map<std::string, sf::Image>::iterator it = Resources::tilesets.find(tilesetName);
    if (it == Resources::tilesets.end()) { // tileset is not stored in Resources
        if (!tileset.loadFromFile("assets/tilesets/" + tilesetName + ".png")) {
            std::cout << "ERROR: Could not load tileset " << tilesetName << "." << std::endl;
            return tile;
        }
        Resources::tilesets.insert(std::pair<std::string, sf::Image>(tilesetName, tileset));
        std::map<int, sf::Texture> t;
        Resources::tiles.insert(std::pair<std::string, std::map<int, sf::Texture>>(tilesetName, t));
    }
    std::map<int, sf::Texture>::iterator it2 = Resources::tiles.at(tilesetName).find(tileNumber);
    if (it2 == Resources::tiles.at(tilesetName).end()) { // tile is not stored in Resources
        Coord topLeftPoint = indexToPixel(tileNumber, Resources::gameProperties);
        tile.loadFromImage(tileset, sf::IntRect(topLeftPoint.x,topLeftPoint.y,
            Resources::gameProperties.tileSize, Resources::gameProperties.tileSize));
        Resources::tiles.at(tilesetName).insert(std::pair<int, sf::Texture>(tileNumber, tile));
    }
    else { // the tile is stored in resources already
        tile = Resources::tiles.at(tilesetName).at(tileNumber);
    }
    return tile;
}
