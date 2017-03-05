void Tile::setSprite(std::string spriteFilename, int tileNumber) {
}

void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite);
}
