#include "Tile.hpp"

void Tile::initializeSprite(std::string tilesetName, int tileNumber, int tileIndex, Resources& r) {
    Tile::texture = r.extractTile(tilesetName, tileIndex);
    Tile::sprite.setTexture(Tile::texture);
    Coord pos = indexToPixel(tileIndex, Tile::gameProperties);
    Tile::sprite.setPosition(sf::Vector2f(pos.x, pos.y));
    Tile::position = tileIndex;
}

void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite);
}

void Tile::setGameProperties(GameProperties properties) {
    Tile::gameProperties = properties;
}
