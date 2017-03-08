#include "main.hpp"
#include "Tile.hpp"
#include "Map.hpp"

int main() {

    GameProperties gameProperties;
    gameProperties.screenWidth = 800;
    gameProperties.screenHeight = 800;
    gameProperties.tileSize = 32;
    gameProperties.numTiles = (gameProperties.screenWidth / gameProperties.tileSize) *
        (gameProperties.screenHeight / gameProperties.tileSize);
    gameProperties.gridWidth = gameProperties.screenWidth /
        gameProperties.tileSize;
    gameProperties.gridHeight = gameProperties.screenHeight /
        gameProperties.tileSize;

    sf::RenderWindow window(sf::VideoMode(gameProperties.screenWidth,
      gameProperties.screenHeight), "Dungeon Crawler");

    Map map;
    map.setGameProperties(gameProperties);

    Resources resources;
    resources.setGameProperties(gameProperties);
    std::string tilesetName = "mountain_landscape";
    std::string mapName = "test";
    std::string fileName = "test_base";

    map.importLayer(mapName, fileName, tilesetName, resources);

    //for (int i = 0; i < gameProperties.numTiles; i++) {
    //    Tile* t = new Tile;
    //    t->setGameProperties(gameProperties);
    //    t->initializeSprite(tilesetName, 10, i, resources);
    //    map.push_back(t);
    //}

    window.draw(map);
    window.display();

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

Coord indexToPixel(int i, GameProperties p) {
	Coord c = {(i % p.gridWidth) * (p.screenWidth / p.gridWidth),
        (i / p.gridWidth) * (p.screenHeight / p.gridHeight)};
	return c;
}
