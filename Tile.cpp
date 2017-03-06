#include "Tile.hpp"

void Tile::initializeSprite(std::string tilesetName, int tileNumber, int tileIndex) {
    //load tileset
    sf::Image tileset;
    if (!tileset.loadFromFile("assets/tilesets/" + tilesetName + ".png")) {
        std::cout << "ERROR: Could not load tileset " << tilesetName << "." << std::endl;
        return;
    }
    Coord topLeftPoint = indexToPixel(tileNumber, Tile::gameProperties);
    Tile::texture.loadFromImage(tileset, sf::IntRect(topLeftPoint.x,topLeftPoint.y,32,32));
    Tile::sprite.setTexture(Tile::texture);
    Coord pos = indexToCoord(tileIndex, Tile::gameProperties.gridWidth);
    Tile::sprite.setPosition(sf::Vector2f(pos.x, pos.y));
    Tile::position = tileIndex;
}

void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite);
}

void Tile::setGameProperties(GameProperties properties) {
    Tile::gameProperties = properties;
}
