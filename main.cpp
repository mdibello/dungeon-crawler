#include "main.hpp"
#include "Tile.hpp"
#include "World.hpp"

int main() {

    GameProperties gameProperties;
    gameProperties.screenWidth = 800;
    gameProperties.screenHeight = 800;
    gameProperties.tileSize = 32;

    sf::Window window(sf::VideoMode(gameProperties.screenWidth,
      gameProperties.screenHeight), "Dungeon Crawler");

    World world;
    world.setGridWidth(gameProperties.screenWidth / gameProperties.tileSize);

    int totalTiles = (gameProperties.screenWidth * gameProperties.screenHeight) /
      (gameProperties.tileSize ^ 2);

    for (int i = 0; i < totalTiles; i++) {
        world.push_back(i);
    }

    Coord c = {10, 10};
    std::cout << "world[100] = " << world.at(100) << std::endl;
    std::cout << "world[(10, 10)] = " << world.at(c) << std::endl;

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

int coordToIndex(Coord c, int gridWidth) {
    return (((gridWidth - 1 - c.y) * gridWidth) + c.x);
}

Coord indexToCoord(int i, int gridWidth) {
    Coord c = {(i % gridWidth), (gridWidth - 1 - (i / gridWidth))};
	return c;
}
