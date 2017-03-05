#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>
#include <string>

class Tile : public sf::Drawable {
public:
    void setSprite(std::string filename, int tileNumber);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    sf::Sprite sprite;
    sf::Texture texture;
};

#endif
