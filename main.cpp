#include "main.hpp"

int main() {

    GameProperties gameProperties;
    gameProperties.screenWidth = 900;
    gameProperties.screenHeight = 900;

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
