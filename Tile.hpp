#ifndef TILE_HPP
#define TILE_HPP

#include "main.hpp"
#include "Resources.hpp"
#include <SFML/Graphics.hpp>
#include <string>

class Tile : public sf::Drawable {
public:
    void setGameProperties(GameProperties properties);
    void initializeSprite(std::string tilesetName, int tileNumber, int tileIndex, Resources r);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    sf::Sprite sprite;
    sf::Texture texture;
    int position; //index in vector
    GameProperties gameProperties;
};

#endif
