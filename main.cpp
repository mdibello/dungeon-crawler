#include "main.hpp"
#include "Tile.hpp"

int main() {

    GameProperties gameProperties;
    gameProperties.screenWidth = 800;
    gameProperties.screenHeight = 800;
    gameProperties.tileSize = 32;

    sf::Window window(sf::VideoMode(gameProperties.screenWidth, gameProperties.screenHeight),
                        "Dungeon Crawler");

    

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }

    return 0;
}
